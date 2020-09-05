#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>

/*
last-updated: 2020/09/04

使用する前に必ず build() を呼ぶ
高速化のために assert チェックを入れていないので注意

TODO: O(1) select を調べる
TODO: 改善した select 二分探索が正しく動作するかどうかの確認とどれだけ速くなるのかの検証
TODO: 改善した select 二分探索で、select0, select1 に対応(現在 select 1 のみの動作)

# 仕様
n = 2^16 ~ 10^4.8 で計算量が保証されている実装
空間計算量: n + o(n)

SuccintBitVector(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

SuccintBitVector(const std::vector<uint64> & v) :
	時間計算量: Θ(n)
	bit 配列 v で初期化

size_type size() const noexcept :
	時間計算量: O(1)
	要素数 n を返す

void set(size_type i) :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットを立てる

bool access(size_type i) const :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットの値を返す

size_type rank1(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 1 になっているビットの数を返す

size_type rank0(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 0 になっているビットの数を返す

size_type select1(size_type k) const :
	時間計算量: O(log n)
	rank1(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 1 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

size_type select0(size_type k) const :
	時間計算量: O(log n)
	rank0(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 0 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

# 参考
https://misteer.hatenablog.com/entry/bit-vector, 2020/09/03
https://miti-7.hatenablog.com/entry/2018/04/15/155638, 2020/09/03
*/

struct SuccintBitVector {
	using size_type = std::size_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
	
private:
	// optimized n = 2^16
	static constexpr size_type LARGE = 8; // bits, log^2 n
	static constexpr size_type SMALL = 3; // bits, (log n) / 2
	static constexpr size_type DAT_B = 6; // bits (2^6 = 64 bit)
	static constexpr size_type SMALL_S = 1ull << (1ull << SMALL);
	
private:
	size_type n;
	std::vector<uint64> bits;
	std::vector<uint32> large;
	std::vector<uint16> small;
	
	static const uint16 table[SMALL_S];
	
public:
	SuccintBitVector(size_type n) {
		assert(n > 0);
		n = (n + (1u << LARGE) - 1) >> LARGE << LARGE;
		this->n = n;
		bits.resize((n >> DAT_B) + 1);
	}
	
	SuccintBitVector(const std::vector<uint64> & v) {
		assert(!v.empty());
		n = ((v.size() << DAT_B) + (1u << LARGE) - 1) >> LARGE << LARGE;
		bits.resize((n >> DAT_B) + 1);
		std::copy(std::begin(v), std::end(v), std::begin(bits));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i) {
		bits[i >> DAT_B] |= 1ull << (i & ((1u << DAT_B) - 1));
	}
	
	bool access(size_type i) const {
		return bits[i >> DAT_B] >> (i & ((1u << DAT_B) - 1)) & 1;
	}
	
	size_type rank1(size_type i) const {
		return large[i >> LARGE] + small[i >> SMALL]
			+ pop_count(
				get_val(bits[i >> DAT_B], (i & ((1u << DAT_B) - 1)) >> SMALL)
					& ((1u << (i & ((1u << SMALL) - 1))) - 1) );
		// (i >> DAT_B) < bits.size() となるように +1 余分に確保
	}
	
	size_type rank0(size_type i) const {
		return i - rank1(i);
	}
	
	size_type select1(size_type k) const {
		return select(k, &SuccintBitVector::rank1);
	}
	
	size_type select0(size_type k) const {
		return select(k, &SuccintBitVector::rank0);
	}
	
	void build() {
		large.assign((n >> LARGE) + 1, 0);
		small.assign((n >> SMALL) + 1, 0);
		
		for (size_type i = 0, small_idx = 1; i < bits.size() - 1; ++i) {
			if ((i & ((1u << (LARGE - DAT_B)) - 1)) == 0) small[small_idx] = pop_count(get_val(bits[i], 0));
			else small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], 0));
			++small_idx;
			
			for (size_type j = 1; j < (1u << (DAT_B - SMALL)); ++j, ++small_idx)
				small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], j));
		}
		
		for (size_type i = 1; i < large.size(); ++i) {
			large[i] = large[i - 1] + small[i << (LARGE - SMALL)];
			small[i << (LARGE - SMALL)] = 0;
		}
	}
	
private:
	uint16 get_val(uint64 x, size_type i) const {
		return x >> ((1u << SMALL) * i) & (SMALL_S - 1);
	}
	
	uint16 pop_count(uint16 x) const {
		return table[x];
	}
	
	size_type select(size_type k, size_type (SuccintBitVector::*count)(size_type) const) const {
		if (k == 0) return 0;
		if (k > (this->*count)(size())) return size() + 1;
		size_type l = 0, r = size();
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			if ((this->*count)(m) >= k) r = m;
			else l = m;
		}
		return r;
		// if (k == 0) return 0;
		// if (k > (this->*count)(size())) return size() + 1;
		
		// size_type l = 0, r = large.size() - 1; // (l, r]
		// while (r - l > 1) {
		// 	size_type m = (l + r) >> 1;
		// 	if (large[m] >= k) r = m;
		// 	else l = m;
		// }
		
		// size_type res = (r - 1) << LARGE;
		// k -= large[r - 1];
		// size_type base = (r - 1) << (LARGE - SMALL);
		// l = 0; r = 1u << (LARGE - SMALL);
		// while (r - l > 1) {
		// 	size_type m = (l + r) >> 1;
		// 	if (small[base + m] >= k) r = m;
		// 	else l = m;
		// }
		
		// res += (r - 1) << SMALL;
		// base += r - 1;
		// k -= small[base];
		// base >>= DAT_B - SMALL;
		// size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL;
		
		// // bits[base][idx] を調べる
		// // std::cout << "k = " << k << ", idx = " << idx << ", res = " << res << ", idx = " << idx << std::endl;
		// while (k) {
		// 	if (bits[base] >> idx & 1) --k;
		// 	++idx;
		// 	++res;
		// }
		
		// return res;
	}
};

constexpr SuccintBitVector::uint16 SuccintBitVector::table[256] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
};