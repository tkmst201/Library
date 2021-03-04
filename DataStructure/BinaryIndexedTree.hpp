#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP
#define INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP

#include <vector>
#include <cassert>
#include <functional>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp
 */
template<typename T>
struct BinaryIndexedTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type (const_reference, const_reference)>;
	using size_type = std::size_t;
	
private:
	size_type n;
	F f;
	value_type id_elem;
	std::vector<value_type> node;
	
public:
	BinaryIndexedTree(size_type n, const F & f, const_reference id_elem)
		: n(n), f(f), id_elem(id_elem), node(n + 1, id_elem) {}
	
	size_type size() const noexcept {
		return n;
	}
	
	void add(size_type i, const_reference x) noexcept {
		assert(i < size());
		++i;
		for (; i <= size(); i += i & -i) node[i] = f(node[i], x);
	}
	
	value_type sum(size_type i) const noexcept {
		assert(i <= size());
		value_type res = id_elem;
		for (; i > 0; i -= i & -i) res = f(node[i], res);
		return res;
	}
	
	size_type lower_bound(const_reference x) const noexcept {
		size_type res = 0;
		size_type s = id_elem, w = 1;
		while (w < size()) w <<= 1;
		for (; w > 0; w >>= 1) {
			if (res + w <= size()) {
				value_type cur = f(s, node[res + w]);
				if (cur < x) {
					res += w;
					s = cur;
				}
			}
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP