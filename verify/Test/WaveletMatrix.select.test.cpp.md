---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Test/WaveletMatrix.select.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/WaveletMatrix.select.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 21:36:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SuccintBitVector.hpp.html">DataStructure/SuccintBitVector.hpp</a>
* :heavy_check_mark: <a href="../../library/DataStructure/WaveletMatrix.hpp.html">DataStructure/WaveletMatrix.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C"

#include "DataStructure/SuccintBitVector.hpp"
#include "DataStructure/WaveletMatrix.hpp"

#include <cstdio>
#include <vector>

constexpr int INF = 1'000'000'001;

int main() {
	int N;
	scanf("%d", &N);
	
	std::vector<int> x(N), y(N), cx, cy;
	for (int i = 0; i < N; ++i) scanf("%d %d", &x[i], &y[i]);
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		cv.emplace_back(INF);
		cv.emplace_back(-INF);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	compress(x, cx);
	compress(y, cy);
	
	// 同じ x 座標でも wavelet matrix 上では異なる index になるように修正する必要がある
	std::vector<int> sum(cx.size()); // [i] := x[j] が i 以下であるような j の個数
	for (int i = 0; i < x.size(); ++i) ++sum[x[i]];
	for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
	
	std::vector<int> cnt(cx.size()), sy(N); // sy[i] := x 座標が i 番目に小さい点の y 座標(x 座標が同一の場合にも差をつける)
	std::vector<int> idx_map(N);
	
	for (int i = 0; i < x.size(); ++i) {
		sy[sum[x[i] - 1] + cnt[x[i]]] = y[i];
		idx_map[sum[x[i] - 1] + cnt[x[i]]] = i;
		++cnt[x[i]];
	}
	
	WaveletMatrix<19, int, SuccintBitVector> wm(sy);
	
	auto compress_get = [](auto &&cv, auto &&x) {
		return std::lower_bound(std::begin(cv), std::end(cv), x) - std::begin(cv);
	};
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int sty, stx, edy, edx;
		scanf("%d %d %d %d", &stx, &edx, &sty, &edy);
		++edx; ++edy;
		sty = compress_get(cy, sty);
		stx = compress_get(cx, stx); stx = sum[stx - 1];
		edy = compress_get(cy, edy);
		edx = compress_get(cx, edx); edx = sum[edx - 1];

		auto points = wm.get_rect(stx, edx, sty, edy);
		std::vector<int> ans;
		for (auto &p : points) ans.emplace_back(idx_map[p.first]);
		std::sort(begin(ans), end(ans));
		for (int j = 0; j < ans.size(); ++j) printf("%d\n", ans[j], " \n"[j + 1 == ans.size()]);
		putchar('\n');
	}
	
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/WaveletMatrix.select.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C"

#line 1 "DataStructure/SuccintBitVector.hpp"



#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>

/*
last-updated: 2020/09/07

使用する前に必ず build() を呼ぶ
高速化のために assert チェックを入れていないので注意

TODO: O(1) select を調べる

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
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (bits[base] >> idx & 1) --k;
		}
		return res;
	}
	
	size_type select0(size_type k) const {
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << LARGE) * m - large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= (1u << LARGE) * (r - 1) - large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << SMALL) * m - small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= (1u << SMALL) * (r - 1) - small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (~bits[base] >> idx & 1) --k;
		}
		return res;
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


#line 1 "DataStructure/WaveletMatrix.hpp"



#line 7 "DataStructure/WaveletMatrix.hpp"
#include <numeric>
#include <tuple>
#include <stack>

/*
last-updated: 2020/09/07

非負整数列を扱う静的なデータ構造

# 仕様
BitVector において select の計算量を α とする。

WaveletMatrix(const std::vector<value_type> &v) :
	時間計算量: Θ(n log BITS)
	v の値で WaveletMatrix を構築する

value_type access(size_type k) const :
	時間計算量: Θ(log BITS)
	i 番目[0-indexed] の要素を返す

std::tuple<size_type, size_type, size_type> rank_all(size_type l, size_type r, const_reference x) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって ({x より小さい要素の個数}, {x と等しい要素の個数}, {x より大きい要素の個数}) を返す
	l \geq r の場合は {0, 0, 0} を返す

size_type rank(size_type l, size_type r, const_reference x) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって値が x と等しい要素の個数を返す
	l \geq r の場合は 0 を返す

size_type rank_less_than(size_type l, size_type r, const_reference x) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって値が x より小さい要素の個数を返す
	l \geq r の場合は 0 を返す

size_type rank_more_than(size_type l, size_type r, const_reference x) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって値が x より大きい要素の個数を返す
	l \geq r の場合は 0 を返す

size_type select(size_type k, const_reference x) const :
	時間計算量: Θ(α log BITS)
	rank(i, x) = k を満たす最小の i を返す (k > 0 のとき、k 番目[1-indexed] の x の出現位置[1-indexed])
	存在しなければ size() + 1 を返す

value_type quantile(size_type l, size_type r, size_type k) const :
	時間計算量: Θ(log BITS)
	[l, r) 内で k 番目[1-indexed] に小さい要素を返す
	l < r \leq n かつ 0 < k \leq r - l である必要がある

size_type range_frequency(size_type l, size_type r, value_type val_l, value_type val_r) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) の範囲に入っているような要素の個数を返す
	l \geq または val_l \geq r の場合は 0 を返す

std::vector<std::pair<value_type, size_type>> range_min_k
	(size_type l, size_type r, value_type val_l, value_type val_r, size_type k) const :
	時間計算量: Θ(k log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) 内に含まれているものから、
	同じ値はまとめて小さい値から順に k 個以下の組 (値, 出現回数) の配列にして返す

std::vector<std::pair<value_type, size_type>> range_max_k
	(size_type l, size_type r, value_type val_l, value_type val_r, size_type k) const :
	時間計算量: Θ(k log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) 内に含まれているものから、
	同じ値はまとめて大きい値から順に k 個以下の組 (値, 出現回数) の配列にして返す

std::pair<value_type, bool> next_value(size_type l, size_type r, value_type val_l, value_type val_r) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) の範囲に入るような要素の最小値を返す
	( 最小値, 最小値が存在するかどうか(true: 存在する, false: 存在しない) )

std::pair<value_type, bool> prev_value(size_type l, size_type r, value_type val_l, value_type val_r) const :
	時間計算量: Θ(log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) の範囲に入るような要素の最大値を返す
	( 最大値, 最大値が存在するかどうか(true: 存在する, false: 存在しない) )

std::vector<std::pair<size_type, value_type>> get_rect(size_type l, size_type r, value_type val_l, value_type val_r) const :
	時間計算量: Θ(D log BITS)
	[l, r) 内の要素であって、値が [val_l, val_r) の範囲に入るような要素を (index, 値) の組の配列にして返す
	対象の要素の個数を D とする。

# 参考
https://www.slideshare.net/pfi/ss-15916040, 2020/09/03
https://miti-7.hatenablog.com/entry/2018/04/28/152259, 2020/09/04
http://algoogle.hadrori.jp/algorithm/wavelet.html, 2020/09/07
*/

template<std::size_t BITS, typename T, class BV>
struct WaveletMatrix {
	static_assert(BITS > 0, "BITS > 0");
	
	using size_type = std::size_t;
	using value_type = T;
	using bv_type = BV;
	using const_reference = const value_type &;
	
private:
	size_type n;
	std::vector<bv_type> bit_vector;
	std::vector<size_type> zero;
	
public:
	WaveletMatrix(const std::vector<value_type> &v) {
		build(v);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	value_type access(size_type k) const {
		assert(k < size());
		
		value_type res = 0;
		for (size_type i = BITS; i > 0; --i) {
			const size_type b = i - 1;
			if (bit_vector[b].access(k)) {
				res |= 1ull << b;
				k = bit_vector[b].rank1(k) + zero[b];
			}
			else k = bit_vector[b].rank0(k);
		}
		return res;
	}
	
	std::tuple<size_type, size_type, size_type> rank_all(size_type l, size_type r, const_reference x) const {
		assert(r <= size());
		assert((x >> BITS) == 0);
		if (l >= r) return std::make_tuple(0, 0, 0);
		
		size_type rank_lt = 0, rank_mt = 0;
		for (size_type i = BITS; i > 0; --i) {
			size_type b = i - 1;
			const size_type l1 = bit_vector[b].rank1(l), r1 = bit_vector[b].rank1(r);
			if (x >> b & 1) {
				rank_lt += (r - r1) - (l - l1);
				l = l1 + zero[b];
				r = r1 + zero[b];
			}
			else {
				rank_mt += r1 - l1;
				l -= l1;
				r -= r1;
			}
		}
		return std::make_tuple(rank_lt, r - l, rank_mt);
	}
	
	size_type rank_less_than(size_type l, size_type r, const_reference x) const {
		return std::get<0>(rank_all(l, r, x));
	}
	
	size_type rank(size_type l, size_type r, const_reference x) const {
		return std::get<1>(rank_all(l, r, x));
	}
	
	size_type rank_more_than(size_type l, size_type r, const_reference x) const {
		return std::get<2>(rank_all(l, r, x));
	}
	
	size_type select(size_type k, const_reference x) const {
		assert(k <= size());
		assert((x >> BITS) == 0);
		if (k == 0) return 0;
		
		size_type pos = 0;
		for (size_type i = BITS; i > 0; --i) {
			const size_type b = i - 1;
			if (x >> b & 1) pos = bit_vector[b].rank1(pos) + zero[b];
			else pos = bit_vector[b].rank0(pos);
		}
		pos += k - 1;
		if (pos >= size()) return size() + 1;
		
		for (size_type i = 0; i < BITS; ++i) {
			size_type npos;
			if (x >> i & 1) {
				if (pos < zero[i]) return size() + 1;
				npos = bit_vector[i].select1(pos - zero[i] + 1);
			}
			else npos = bit_vector[i].select0(pos + 1);
			
			if (npos > size()) return size() + 1;
			pos = npos - 1;
		}
		return pos + 1;
	}
	
	value_type quantile(size_type l, size_type r, size_type k) const {
		assert(l < r);
		assert(r <= size());
		assert(0 < k);
		assert(k <= r - l);
		
		value_type res = 0;
		for (size_type i = BITS; i > 0; --i) {
			const size_type b = i - 1;
			const size_type l1 = bit_vector[b].rank1(l), r1 = bit_vector[b].rank1(r);
			const size_type c = (r - r1) - (l - l1);
			
			if (k <= c) {
				l -= l1;
				r -= r1;
			}
			else {
				l = l1 + zero[b];
				r = r1 + zero[b];
				k -= c;
				res |= 1ull << b;
			}
		}
		return res;
	}
	
	size_type range_frequency(size_type l, size_type r, value_type val_l, value_type val_r) const {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r) return 0;
		return rank_less_than(l, r, val_r) - rank_less_than(l, r, val_l);
	}
	
	std::vector<std::pair<value_type, size_type>> range_min_k
		(size_type l, size_type r, value_type val_l, value_type val_r, size_type k) const {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r || k == 0) return {};
		
		std::vector<std::pair<value_type, size_type>> res;
		struct Data {
			size_type i, l, r;
			bool ismin;
			value_type val;
			Data(size_type i, size_type l, size_type r, bool ismin, value_type val)
				: i(i), l(l), r(r), ismin(ismin), val(val) {}
		};
		
		std::stack<Data> stk;
		stk.emplace(BITS, l, r, true, 0);
		
		while (!stk.empty()) {
			const Data dat = stk.top(); stk.pop();
			if (dat.i == 0) {
				if (dat.val < val_r) {
					res.emplace_back(dat.val, dat.r - dat.l);
					if (res.size() == k) break;
					continue;
				}
				else break;
			}
			const size_type b = dat.i - 1;
			const size_type l1 = bit_vector[b].rank1(dat.l), r1 = bit_vector[b].rank1(dat.r);
			
			const bool bit = val_l >> b & 1;
			if (l1 != r1) stk.emplace(b, l1 + zero[b], r1 + zero[b], dat.ismin & bit, dat.val | (1ull << b));
			if (!(dat.ismin && bit)) {
				const size_type l0 = dat.l - l1, r0 = dat.r - r1;
				if (l0 != r0) stk.emplace(b, l0, r0, dat.ismin, dat.val);
			}
		}
		return res;
	}
	
	std::vector<std::pair<value_type, size_type>> range_max_k
		(size_type l, size_type r, value_type val_l, value_type val_r, size_type k) const {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r || k == 0) return {};
		--val_r;
		
		std::vector<std::pair<value_type, size_type>> res;
		struct Data {
			size_type i, l, r;
			bool ismax;
			value_type val;
			Data(size_type i, size_type l, size_type r, bool ismax, value_type val)
				: i(i), l(l), r(r), ismax(ismax), val(val) {}
		};
		
		std::stack<Data> stk;
		stk.emplace(BITS, l, r, true, 0);
		
		while (!stk.empty()) {
			const Data dat = stk.top(); stk.pop();
			if (dat.i == 0) {
				if (dat.val >= val_l) {
					res.emplace_back(dat.val, dat.r - dat.l);
					if (res.size() == k) break;
					continue;
				}
				else break;
			}
			const size_type b = dat.i - 1;
			const size_type l1 = bit_vector[b].rank1(dat.l), r1 = bit_vector[b].rank1(dat.r);
			
			const bool bit = val_r >> b & 1;
			const size_type l0 = dat.l - l1, r0 = dat.r - r1;
			if (l0 != r0) stk.emplace(b, l0, r0, dat.ismax & !bit, dat.val);
			if (!(dat.ismax & !bit) && l1 != r1) stk.emplace(b, l1 + zero[b], r1 + zero[b], dat.ismax, dat.val | (1ull << b));
		}
		return res;
	}
	
	std::pair<value_type, bool> next_value(size_type l, size_type r, value_type val_l, value_type val_r) const {
		const auto res = range_min_k(l, r, val_l, val_r, 1);
		if (res.empty()) return {0, false};
		return {res[0].first, true};
	}
	
	std::pair<value_type, bool> prev_value(size_type l, size_type r, value_type val_l, value_type val_r) const {
		const auto res = range_max_k(l, r, val_l, val_r, 1);
		if (res.empty()) return {0, false};
		return {res[0].first, true};
	}
	
	std::vector<std::pair<size_type, value_type>> get_rect(size_type l, size_type r, value_type val_l, value_type val_r) const {
		auto points = range_min_k(l, r, val_l, val_r, r - l);
		std::vector<std::pair<size_type, value_type>> res;
		for (auto &p : points) {
			const size_type c = rank(0, l, p.first);
			for (size_type i = 0; i < p.second; ++i) res.emplace_back(select(c + i + 1, p.first) - 1, p.first);
		}
		return res;
	}
	
private:
	void build(const std::vector<value_type> &v) {
		assert(!v.empty());
		n = v.size();
		for (size_type i = 0; i < n; ++i) assert((v[i] >> BITS) == 0);
		
		bit_vector.resize(BITS, bv_type{n});
		zero.resize(BITS, 0);
		
		std::vector<size_type> ord(n), nex_ord;
		std::iota(std::begin(ord), std::end(ord), 0);
		
		for (size_type i = BITS - 1; i >= 0; --i) {
			nex_ord.assign(n, 0);
			for (size_type j = 0; j < n; ++j) {
				if (v[ord[j]] >> i & 1) bit_vector[i].set(j);
				else ++zero[i];
			}
			if (i == 0) break; // 最後は sort しない
			
			size_type p0 = 0, p1 = zero[i];
			for (size_type j = 0; j < n; ++j) {
				if (v[ord[j]] >> i & 1) nex_ord[p1++] = ord[j];
				else nex_ord[p0++] = ord[j];
			}
			std::swap(ord, nex_ord);
		}
		
		for (size_type i = 0; i < BITS; ++i) bit_vector[i].build();
	}
};


#line 5 "Test/WaveletMatrix.select.test.cpp"

#include <cstdio>
#line 8 "Test/WaveletMatrix.select.test.cpp"

constexpr int INF = 1'000'000'001;

int main() {
	int N;
	scanf("%d", &N);
	
	std::vector<int> x(N), y(N), cx, cy;
	for (int i = 0; i < N; ++i) scanf("%d %d", &x[i], &y[i]);
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		cv.emplace_back(INF);
		cv.emplace_back(-INF);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	compress(x, cx);
	compress(y, cy);
	
	// 同じ x 座標でも wavelet matrix 上では異なる index になるように修正する必要がある
	std::vector<int> sum(cx.size()); // [i] := x[j] が i 以下であるような j の個数
	for (int i = 0; i < x.size(); ++i) ++sum[x[i]];
	for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
	
	std::vector<int> cnt(cx.size()), sy(N); // sy[i] := x 座標が i 番目に小さい点の y 座標(x 座標が同一の場合にも差をつける)
	std::vector<int> idx_map(N);
	
	for (int i = 0; i < x.size(); ++i) {
		sy[sum[x[i] - 1] + cnt[x[i]]] = y[i];
		idx_map[sum[x[i] - 1] + cnt[x[i]]] = i;
		++cnt[x[i]];
	}
	
	WaveletMatrix<19, int, SuccintBitVector> wm(sy);
	
	auto compress_get = [](auto &&cv, auto &&x) {
		return std::lower_bound(std::begin(cv), std::end(cv), x) - std::begin(cv);
	};
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int sty, stx, edy, edx;
		scanf("%d %d %d %d", &stx, &edx, &sty, &edy);
		++edx; ++edy;
		sty = compress_get(cy, sty);
		stx = compress_get(cx, stx); stx = sum[stx - 1];
		edy = compress_get(cy, edy);
		edx = compress_get(cx, edx); edx = sum[edx - 1];

		auto points = wm.get_rect(stx, edx, sty, edy);
		std::vector<int> ans;
		for (auto &p : points) ans.emplace_back(idx_map[p.first]);
		std::sort(begin(ans), end(ans));
		for (int j = 0; j < ans.size(); ++j) printf("%d\n", ans[j], " \n"[j + 1 == ans.size()]);
		putchar('\n');
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

