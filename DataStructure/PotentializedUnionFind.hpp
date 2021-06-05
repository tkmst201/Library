#ifndef INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP
#define INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP

#include <cassert>
#include <vector>
#include <functional>
#include <utility>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp
 */
template<typename T>
struct PotentializedUnionFind {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type (const_reference, const_reference)>;
	using G = std::function<value_type (const_reference)>;
	
private:
	size_type n;
	value_type id_elem;
	F f;
	G g;
	std::vector<int> dat;
	std::vector<value_type> val;
	
public:
	PotentializedUnionFind(size_type n, const_reference id_elem, const F & f, const G & g = [](const_reference x) { return -x; })
		: n(n), id_elem(id_elem), f(f), g(g), dat(n, -1), val(n, id_elem) {}
	
	size_type size(size_type x) noexcept {
		assert(x < n);
		return -dat[find(x)];
	}
	
	size_type find(size_type x) noexcept {
		assert(x < n);
		if (dat[x] < 0) return x;
		const size_type p = dat[x];
		dat[x] = find(p);
		val[x] = f(val[x], val[p]);
		return dat[x];
	}
	
	void merge(size_type x, size_type y, const_reference w) noexcept {
		assert(x < n);
		assert(y < n);
		size_type rx = find(x), ry = find(y);
		assert(rx != ry);
		value_type v = f(val[y], g(f(val[x], w)));
		if (dat[rx] < dat[ry]) {
			std::swap(rx, ry);
			v = g(v);
		}
		dat[ry] += dat[rx];
		dat[rx] = ry;
		val[rx] = std::move(v);
	}
	
	value_type diff(size_type x, size_type y) noexcept {
		assert(x < n);
		assert(y < n);
		const size_type rx = find(x), ry = find(y);
		assert(rx == ry);
		return f(val[y], g(val[x]));
	}
	
	bool issame(size_type x, size_type y) noexcept {
		assert(x < n);
		assert(y < n);
		return find(x) == find(y);
	}
};

#endif // INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP