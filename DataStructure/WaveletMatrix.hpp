#ifndef INCLUDE_GUARD_WAVELET_MATRIX_HPP
#define INCLUDE_GUARD_WAVELET_MATRIX_HPP

#include "DataStructure/SuccintBitVector.hpp"

#include <vector>
#include <cstdint>
#include <cassert>
#include <tuple>
#include <stack>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp
 */
template<typename T, int BITS>
struct WaveletMatrix {
	static_assert(std::is_integral<T>::value == true);
	static_assert(BITS > 0);
	static_assert(BITS <= 64);
	static_assert(BITS <= 8 * sizeof(T));
	
	using size_type = std::size_t;
	using value_type = T;
	using const_reference = const value_type &;
	using bv_type = SuccintBitVector;
	
private:
	using uint32 = std::uint32_t;
	
	size_type n;
	std::vector<bv_type> bit_vector;
	std::vector<uint32> zero;
	
public:
	explicit WaveletMatrix(const std::vector<value_type> & v) {
		build(v);
	}
	
private:
	void build(const std::vector<value_type> & v) {
		assert(!v.empty());
		n = v.size();
		for (uint32 i = 0; i < n; ++i) assert((v[i] >> BITS) == 0);
		bit_vector.assign(BITS, bv_type(n));
		zero.assign(BITS, 0);
		std::vector<value_type> ord(n), nex_ord(n);
		ord = v;
		for (int i = BITS - 1; i >= 0; --i) {
			for (uint32 j = 0; j < n; ++j) {
				if (ord[j] >> i & 1) bit_vector[i].set(j);
				else nex_ord[zero[i]++] = ord[j];
			}
			bit_vector[i].build();
			if (i == 0) break;
			uint32 p1 = zero[i];
			for (uint32 j = 0; j < n; ++j) if (ord[j] >> i & 1) nex_ord[p1++] = ord[j];
			std::swap(ord, nex_ord);
		}
	}
	
public:
	size_type size() const noexcept {
		return n;
	}
	
	value_type access(size_type k) const noexcept {
		assert(k < n);
		value_type res = 0;
		for (int i = BITS - 1; i >= 0; --i) {
			if (bit_vector[i].access(k)) {
				res |= 1ull << i;
				k = bit_vector[i].rank1(k) + zero[i];
			}
			else k = bit_vector[i].rank0(k);
		}
		return res;
	}
	
	std::tuple<uint32, uint32, uint32> rank_all(size_type l, size_type r, const_reference x) const noexcept {
		assert(l <= r);
		assert(r <= n);
		assert((x >> BITS) == 0);
		if (l == r) return {0, 0, 0};
		uint32 rank_lt = 0, rank_mt = 0;
		for (int i = BITS - 1; i >= 0; --i) {
			const uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);
			if (x >> i & 1) {
				rank_lt += (r - l) - (r1 - l1);
				l = l1 + zero[i];
				r = r1 + zero[i];
			}
			else {
				rank_mt += r1 - l1;
				l -= l1;
				r -= r1;
			}
		}
		return {rank_lt, r - l, rank_mt};
	}
	
	uint32 rank_less_than(size_type l, size_type r, const_reference x) const noexcept {
		assert(l <= r);
		assert(r <= n);
		assert((x >> BITS) == 0);
		return std::get<0>(rank_all(l, r, x));
	}
	
	uint32 rank(size_type l, size_type r, const_reference x) const noexcept {
		assert(l <= r);
		assert(r <= n);
		assert((x >> BITS) == 0);
		return std::get<1>(rank_all(l, r, x));
	}
	
	uint32 rank_more_than(size_type l, size_type r, const_reference x) const noexcept {
		assert(l <= r);
		assert(r <= n);
		assert((x >> BITS) == 0);
		return std::get<2>(rank_all(l, r, x));
	}
	
	size_type select(uint32 k, const_reference x) const noexcept {
		assert((x >> BITS) == 0);
		if (k == 0 || k > size()) return size() + 1;
		uint32 pos = 0;
		for (int i = BITS - 1; i >= 0; --i) {
			if (x >> i & 1) pos = bit_vector[i].rank1(pos) + zero[i];
			else pos = bit_vector[i].rank0(pos);
		}
		pos += k;
		if (pos > size()) return size() + 1;
		for (int i = 0; i < BITS; ++i) {
			if (x >> i & 1) {
				if (pos <= zero[i]) return size() + 1;
				pos = bit_vector[i].select1(pos - zero[i]);
			}
			else pos = bit_vector[i].select0(pos);
			if (pos > size()) return size() + 1;
		}
		return pos;
	}
	
	value_type quantile(size_type l, size_type r, uint32 k) const noexcept {
		assert(l < r);
		assert(r <= size());
		assert(0 < k);
		assert(k <= r - l);
		value_type res = 0;
		for (int i = BITS - 1; i >= 0; --i) {
			const uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);
			const uint32 c = (r - l) - (r1 - l1);
			if (k <= c) {
				l -= l1;
				r -= r1;
			}
			else {
				l = l1 + zero[i];
				r = r1 + zero[i];
				k -= c;
				res |= 1ull << i;
			}
		}
		return res;
	}
	
	size_type range_frequency(size_type l, size_type r, value_type val_l, value_type val_r) const noexcept {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r) return 0;
		return rank_less_than(l, r, val_r) - rank_less_than(l, r, val_l);
	}
	
private:
	struct Data {
		int i;
		uint32 l, r;
		bool f;
		value_type val;
		Data(int i, uint32 l, uint32 r, bool f, const value_type & val)
			: i(i), l(l), r(r), f(f), val(val) {}
	};
	
public:
	std::vector<std::pair<value_type, uint32>> range_min_k(
		size_type l, size_type r, value_type val_l, value_type val_r, uint32 k) const {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r || k == 0) return {};
		std::vector<std::pair<value_type, uint32>> res;
		std::stack<Data> stk;
		stk.emplace(BITS - 1, l, r, true, 0);
		while (!stk.empty()) {
			const Data dat = stk.top();
			stk.pop();
			if (dat.i == -1) {
				if (dat.val < val_r) {
					res.emplace_back(dat.val, dat.r - dat.l);
					if (res.size() == k) break;
					continue;
				}
				break;
			}
			const uint32 l1 = bit_vector[dat.i].rank1(dat.l), r1 = bit_vector[dat.i].rank1(dat.r);
			const uint32 l0 = dat.l - l1, r0 = dat.r - r1;
			const bool bit = val_l >> dat.i & 1;
			if (l1 != r1) stk.emplace(dat.i - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f & bit, dat.val | (1ull << dat.i));
			if (!(dat.f && bit) && l0 != r0) stk.emplace(dat.i - 1, l0, r0, dat.f, dat.val);
		}
		return res;
	}
	
	std::vector<std::pair<value_type, size_type>> range_max_k(
		size_type l, size_type r, value_type val_l, value_type val_r, uint32 k) const {
		assert(r <= size());
		assert(((val_r - 1) >> BITS) == 0);
		if (l >= r || val_l >= val_r || k == 0) return {};
		--val_r;
		std::vector<std::pair<value_type, size_type>> res;
		std::stack<Data> stk;
		stk.emplace(BITS - 1, l, r, true, 0);
		while (!stk.empty()) {
			const Data dat = stk.top();
			stk.pop();
			if (dat.i == -1) {
				if (dat.val >= val_l) {
					res.emplace_back(dat.val, dat.r - dat.l);
					if (res.size() == k) break;
					continue;
				}
				break;
			}
			const uint32 l1 = bit_vector[dat.i].rank1(dat.l), r1 = bit_vector[dat.i].rank1(dat.r);
			const uint32 l0 = dat.l - l1, r0 = dat.r - r1;
			const bool bit = val_r >> dat.i & 1;
			if (l0 != r0) stk.emplace(dat.i - 1, l0, r0, dat.f & !bit, dat.val);
			if (!(dat.f && !bit) && l1 != r1) stk.emplace(dat.i - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f, dat.val | (1ull << dat.i));
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
	
	std::vector<std::pair<value_type, size_type>> get_rect(size_type l, size_type r, value_type val_l, value_type val_r) const {
		auto points = range_min_k(l, r, val_l, val_r, r - l);
		std::vector<std::pair<value_type, size_type>> res;
		for (const auto & p : points) {
			const uint32 c = rank(0, l, p.first);
			for (uint32 i = 0; i < p.second; ++i) res.emplace_back(p.first, select(c + i + 1, p.first) - 1);
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_WAVELET_MATRIX_HPP