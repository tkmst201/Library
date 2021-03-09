#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP
#define INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP

#include <vector>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree2D.hpp
 */
template<typename T>
struct BinaryIndexedTree2D {
	static_assert(std::is_integral<T>::value == true);
	
	using value_type = T;
	using size_type = std::size_t;
	
private:
	size_type h, w;
	std::vector<std::vector<value_type>> node;
	
public:
	BinaryIndexedTree2D(size_type h, size_type w)
		: h(h), w(w), node(h + 1, std::vector<value_type>(w + 1)) {}
	
	std::pair<size_type, size_type> size() const noexcept {
		return {h, w};
	}
	
	void add(size_type i, size_type j, value_type x) noexcept {
		assert(i < h);
		assert(j < w);
		++i; ++j;
		for (; i <= h; i += i & -i) {
			for (size_type k = j; k <= w; k += k & -k) {
				node[i][k] += x;
			}
		}
	}
	
	value_type sum(size_type i, size_type j) const noexcept {
		assert(i <= h);
		assert(j <= w);
		value_type res = 0;
		for (; i > 0; i -= i & -i) {
			for (size_type k = j; k > 0; k -= k & -k) {
				res += node[i][k];
			}
		}
		return res;
	}
	
	value_type sum(size_type i1, size_type i2, size_type j1, size_type j2) const noexcept {
		assert(i1 <= i2);
		assert(j1 <= j2);
		assert(i2 <= h);
		assert(j2 <= w);
		if (i1 == i2 || j1 == j2) return 0;
		return sum(i2, j2) - sum(i2, j1) + sum(i1, j1) - sum(i1, j2);
	}
};

#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP