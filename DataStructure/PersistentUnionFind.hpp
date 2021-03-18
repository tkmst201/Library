#ifndef INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP
#define INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP

#include "DataStructure/PersistentArray.hpp"

#include <cstdint>
#include <utility>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/PersistentUnionFind.hpp
 */
template<int M>
struct PersistentUnionFind {
	static_assert(M > 1);
	
	using size_type = std::size_t;
	
private:
	using parray_type = PersistentArray<int, M>;
	parray_type dat;
	
public:
	PersistentUnionFind() : dat(-1) {}
	
private:
	PersistentUnionFind(const parray_type & dat) : dat(dat) {}
	
public:
	size_type find(size_type x) const noexcept {
		return find_sub(x).first;
	}
	
	size_type size(size_type x) const noexcept {
		return find_sub(x).second;
	}
	
private:
	std::pair<size_type, int> find_sub(size_type x) const noexcept {
		int d;
		for (d = dat.get(x); d >= 0; d = dat.get(x)) x = d;
		return {x, -d};
	}
	
public:
	PersistentUnionFind unite(size_type x, size_type y) const {
		if (x == y) return *this;
		auto px = find_sub(x), py = find_sub(y);
		if (px.first == py.first) return *this;
		if (px.second > py.second) std::swap(px, py);
		return dat.set(px.first, py.first).set(py.first, -(px.second + py.second));
	}
	
	void destructive_unite(size_type x, size_type y) {
		if (x == y) return;
		auto px = find_sub(x), py = find_sub(y);
		if (px.first == py.first) return;
		if (px.second > py.second) std::swap(px, py);
		dat.destructive_set(px.first, py.first);
		dat.destructive_set(py.first, -(px.second + py.second));
	}
	
	bool issame(size_type x, size_type y) const noexcept {
		return x == y ? true : find(x) == find(y);
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP