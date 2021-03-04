#ifndef INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP

#include <vector>
#include <cassert>
#include <functional>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/LazySegmentTree.hpp
 */

template<typename T, typename E>
struct LazySegmentTree {
	using value_type = T;
	using lazy_type = E;
	using size_type = std::size_t;
	using F = std::function<value_type (const value_type &, const value_type &)>;
	using G = std::function<value_type (const value_type &, const lazy_type &)>;
	using H = std::function<lazy_type (const lazy_type &, const lazy_type &)>;
	using P = std::function<lazy_type (const lazy_type &, size_type)>;
	
private:
	size_type n, n_, n_log;
	value_type id_node;
	lazy_type id_lazy;
	F f;
	G g;
	H h;
	P p;
	std::vector<value_type> node;
	std::vector<lazy_type> lazy;

public:
	LazySegmentTree(size_type n, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & e, size_type k) { return e; })
			: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h), p(p) {
		n_ = 1;
		n_log = 0;
		while (n_ < n) n_ <<= 1, ++n_log;
		node.assign(2 * n_, id_node);
		lazy.assign(2 * n_, id_lazy);
	}
	
	LazySegmentTree(const std::vector<value_type> & v, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
			: LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {
		for (size_type i = 0; i < v.size(); ++i) node[i + n_] = v[i];
		for (size_type i = n_ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type k, const value_type & x) noexcept {
		assert(k < size());
		k += n_;
		thrust(k);
		node[k] = x;
		lazy[k] = id_lazy;
		recalc(k);
	}
	
	value_type get(size_type k) noexcept {
		assert(k < size());
		k += n_;
		thrust(k);
		return reflect(k, 1);
	}
	
	void update(size_type l, size_type r, const lazy_type & x) noexcept {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return;
		l += n_;
		r += n_;
		thrust(l);
		thrust(r - 1);
		for (size_type cl = l, cr = r; cl < cr; cl >>= 1, cr >>= 1) {
			if (cl & 1) lazy[cl] = h(lazy[cl], x), ++cl;
			if (cr & 1) --cr, lazy[cr] = h(lazy[cr], x);
		}
		recalc(l);
		recalc(r - 1);
	}
	
	value_type fold(size_type l, size_type r) noexcept {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return id_node;
		l += n_;
		r += n_;
		thrust(l);
		thrust(r - 1);
		value_type vl = id_node, vr = id_node;
		for (size_type w = 1; l < r; l >>= 1, r >>= 1, w <<= 1) {
			if (l & 1) vl = f(vl, reflect(l, w)), ++l;
			if (r & 1) --r, vr = f(reflect(r, w), vr);
		}
		return f(vl, vr);
	}
	
	value_type fold_all() const {
		return reflect(1, n_);
	}
	
private:
	value_type reflect(size_type k, size_type w) const noexcept {
		return lazy[k] == id_lazy ? node[k] : g(node[k], p(lazy[k], w));
	}
	
	void propagate(size_type k, size_type w) noexcept {
		if (lazy[k] == id_lazy) return;
		if ((k << 1) < node.size()) {
			lazy[k << 1] = h(lazy[k << 1], lazy[k]);
			lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
		}
		node[k] = reflect(k, w);
		lazy[k] = id_lazy;
	}
	
	void recalc(size_type k) noexcept {
		for (size_type i = k >> 1, cw = 1; i > 0; i >>= 1, cw <<= 1)
			node[i] = f(reflect(i << 1, cw), reflect(i << 1 | 1, cw));
	}
	
	void thrust(size_type k) noexcept {
		for (size_type i = n_log, w = n_; i > 0; --i, w >>= 1) propagate(k >> i, w);
	}
};

#endif // INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP