#ifndef INCLUDE_GUARD_UNION_FIND_HPP
#define INCLUDE_GUARD_UNION_FIND_HPP

#include <vector>
#include <utility>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp
 */
struct UnionFind {
public:
	using size_type = std::size_t;
	
private:
	size_type n;
	std::vector<int> dat;
	
public:
	explicit UnionFind(size_type n) : n(n), dat(n, -1) {}
	
	size_type size(size_type x) {
		assert(x < n);
		return -dat[find(x)];
	}
	
	size_type find(size_type x) {
		assert(x < n);
		if (dat[x] < 0) return x;
		return dat[x] = find(dat[x]);
	}
	
	void unite(size_type x, size_type y) {
		assert(x < n);
		assert(y < n);
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (dat[x] < dat[y]) std::swap(x, y);
		dat[x] += dat[y];
		dat[y] = x;
	}
	
	bool issame(size_type x, size_type y) {
		assert(x < n);
		assert(y < n);
		return find(x) == find(y);
	}
};

#endif // INCLUDE_GUARD_UNION_FIND_HPP