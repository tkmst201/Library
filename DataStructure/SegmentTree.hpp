#ifndef INCLUDE_GUARD_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_SEGMENT_TREE_HPP

#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp
 */
template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type (const_reference, const_reference)>;
	using size_type = std::size_t;
	
private:
	size_type n, n_;
	value_type id_elem;
	F f;
	std::vector<value_type> node;
	
public:
	SegmentTree() = default;
	
	SegmentTree(size_type n, const_reference id_elem, const F & f)
		: n(n), id_elem(id_elem), f(f) {
		n_ = 1;
		while (n_ < n) n_ <<= 1;
		node.resize(2 * n_, id_elem);
	}
	
	SegmentTree(const std::vector<value_type> & v, const_reference id_elem, const F & f)
		: SegmentTree(v.size(), id_elem, f) {
		for (size_type i = 0; i < v.size(); ++i) node[i + n_] = v[i];
		for (size_type i = n_ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += n_] = x;
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	const_reference get(size_type i) const {
		assert(i < size());
		return node[i + n_];
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= r);
		assert(r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	const_reference fold_all() const {
		return node[1];
	}
	
	size_type max_right(size_type l, std::function<bool (const_reference)> g) const {
		assert(l <= size());
		assert(g(id_elem));
		if (l == size()) return size();
		l += n_;
		value_type sum = id_elem;
		while (true) {
			while (~l & 1) l >>= 1;
			const value_type nex_sum = f(sum, node[l]);
			if (g(nex_sum)) { sum = nex_sum; ++l; }
			else break;
			if ((l & -l) == l) return size();
		}
		while (l < n_) {
			const value_type nex_sum = f(sum, node[l << 1]);
			l <<= 1;
			if (g(nex_sum)) { sum = nex_sum; l |= 1; }
		}
		return l - n_;
	}
	
	size_type min_left(size_type r, std::function<bool (const_reference)> g) const {
		assert(r <= size());
		assert(g(id_elem));
		if (r == 0) return 0;
		r += n_;
		value_type sum = id_elem;
		while (true) {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			const value_type nex_sum = f(node[r], sum);
			if (g(nex_sum)) sum = nex_sum;
			else break;
			if ((r & -r) == r) return 0;
		}
		while (r < n_) {
			const value_type nex_sum = f(node[r << 1 | 1], sum);
			r <<= 1;
			if (!g(nex_sum)) r |= 1;
			else sum = nex_sum;
		}
		return r + 1 - n_;
	}
};

#endif // INCLUDE_GUARD_SEGMENT_TREE_HPP