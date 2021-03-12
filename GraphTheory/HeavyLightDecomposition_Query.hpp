#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP

#include <vector>
#include <cassert>
#include <functional>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp
 */
template<class HLD, typename T, template<typename> class SEG>
struct HeavyLightDecomposition_Query {
	using value_type = T;
	using const_reference = const value_type &;
	using seg_type = SEG<value_type>;
	using hld_type = HLD;
	using size_type = std::size_t;
	using Graph = typename hld_type::Graph;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	bool VERTEX;
	value_type id_elem;
	F f;
	hld_type hld;
	seg_type seg, rseg;
	
public:
	HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, const value_type & id_elem, const F & f)
		: HeavyLightDecomposition_Query(g, VERTEX, -1, id_elem, f) {}
	
	HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, int root, const value_type & id_elem, const F & f)
		: VERTEX(VERTEX), id_elem(id_elem), f(f), hld(g, root, false) {
		seg = seg_type{static_cast<size_type>(hld.size()), id_elem, f};
		rseg = seg_type{static_cast<size_type>(hld.size()), id_elem, f};
	}
	
	template<typename U>
	HeavyLightDecomposition_Query(const Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)
		: HeavyLightDecomposition_Query(g, -1, v, id_elem, f) {}
	
	template<typename U>
	HeavyLightDecomposition_Query(const Graph & g, int root, const std::vector<U> & v, const value_type & id_elem, const F & f)
		: VERTEX(true), id_elem(id_elem), f(f), hld(g, root, false) {
		assert(hld.size() == v.size());
		std::vector<value_type> init(hld.size());
		for (int i = 0; i < hld.size(); ++i) init[hld.in(i)] = v[i];
		seg = seg_type{init, id_elem, f};
		for (int i = 0; i < hld.heavy_size(); ++i) {
			const int offset = hld.in(hld.head(i));
			std::reverse(begin(init) + offset, begin(init) + offset + hld.heavy_size(i));
		}
		rseg = seg_type{init, id_elem, f};
	}
	
	const hld_type & get_hld() const noexcept {
		return get_hld;
	}
	
	void set(int v, const_reference x) noexcept {
		assert(VERTEX);
		assert(0 <= v && v < hld.size());
		set_(v, x);
	}
	
	value_type get(int v) const noexcept {
		assert(VERTEX);
		assert(0 <= v && v < hld.size());
		return get_(v);
	}
	
	void set(int u, int v, const_reference x) noexcept {
		assert(!VERTEX);
		assert(0 <= u && u < hld.size());
		assert(0 <= v && v < hld.size());
		assert(hld.par(u) == v || hld.par(v) == u);
		set_(hld.par(u) == v ? u : v, x);
	}
	
	value_type get(int u, int v) const noexcept {
		assert(!VERTEX);
		assert(0 <= u && u < hld.size());
		assert(0 <= v && v < hld.size());
		assert(hld.par(u) == v || hld.par(v) == u);
		return get_(hld.par(u) == v ? u : v);
	}
	
private:
	void set_(int v, const_reference x) noexcept {
		seg.set(hld.in(v), x);
		rseg.set(reverse_idx(v), x);
	}
	
	value_type get_(int v) const noexcept {
		return seg.get(hld.in(v));
	}
	
	int reverse_idx(int v) const noexcept {
		const int id = hld.heavy(v);
		return (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;
	}
	
public:
	value_type fold(int u, int v) const noexcept {
		assert(0 <= u && u < hld.size());
		assert(0 <= v && v < hld.size());
		assert(hld.tree_id(u) == hld.tree_id(v));
		value_type lv = id_elem, rv = id_elem;
		while (hld.heavy(u) != hld.heavy(v)) {
			if (hld.heavy_depth(hld.heavy(u)) >= hld.heavy_depth(hld.heavy(v))) {
				const int head = hld.head(hld.heavy(u));
				lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));
				u = hld.par(head);
			}
			if (hld.heavy(u) == hld.heavy(v)) break;
			if (hld.heavy_depth(hld.heavy(u)) <= hld.heavy_depth(hld.heavy(v))) {
				const int head = hld.head(hld.heavy(v));
				rv = f(seg.fold(hld.in(head), hld.in(v) + 1), rv);
				v = hld.par(head);
			}
		}
		if (hld.in(u) < hld.in(v)) rv = f(seg.fold(hld.in(u) + !VERTEX, hld.in(v) + 1), rv);
		else lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + VERTEX));
		return f(lv, rv);
	}
	
	value_type subtree_sum(int v) const noexcept {
		assert(0 <= v && v < hld.size());
		return seg.fold(hld.in(v) + !VERTEX, hld.out(v));
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP