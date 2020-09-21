#ifndef INCLUDE_GUARD_WAVELET_MATRIX_HPP
#define INCLUDE_GUARD_WAVELET_MATRIX_HPP

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

#include <vector>
#include <cstdint>
#include <cassert>
#include <numeric>
#include <tuple>
#include <stack>

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

#endif // INCLUDE_GUARD_WAVELET_MATRIX_HPP