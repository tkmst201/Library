#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP
#define INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP

#include <vector>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp
 */
template<typename T, template<typename> class U>
struct BinaryIndexedTree_RangeAdd {
	static_assert(std::is_integral<T>::value == true);
	
	using bit_type = U<T>;
	using value_type = typename bit_type::value_type;
	using size_type = typename bit_type::size_type;
	
private:
	std::vector<bit_type> bit;
	
public:
	BinaryIndexedTree_RangeAdd(size_type n)
		: bit(2, bit_type{n, [](value_type x, value_type y) { return x + y; }, 0}) {}
	
	size_type size() const noexcept {
		return bit[0].size();
	}
	
	void add(size_type l, size_type r, value_type x) {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return;
		bit[0].add(l, x);
		bit[0].add(r - 1, -x);
		bit[1].add(l, -x * l);
		bit[1].add(r - 1, x * r);
	}
	
	value_type sum(size_type i) {
		assert(i <= size());
		return bit[0].sum(i) * i + bit[1].sum(i);
	}
	
	value_type sum(size_type l, size_type r) {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return 0;
		return sum(r) - sum(l);
	}
};

#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP