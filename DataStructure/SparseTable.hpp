#ifndef INCLUDE_GUARD_SPARSE_TABLE_HPP
#define INCLUDE_GUARD_SPARSE_TABLE_HPP

#include <vector>
#include <cassert>
#include <functional>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp
 */
template<typename T>
struct SparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	std::vector<std::uint8_t> log_table;
	
public:
	template<class InputIterator>
	SparseTable(InputIterator first, InputIterator last, const F & f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	size_type size() const noexcept {
		return table.empty() ? 0 : table.front().size();
	}
	
	value_type fold(size_type l, size_type r) const noexcept {
		assert(l < r);
		assert(r <= size());
		const size_type k = log_table[r - l];
		return f(table[k][l], table[k][r - (1 << k)]);
	}
	
private:
	void build() {
		log_table.reserve(size() + 1);
		log_table.emplace_back(0);
		log_table.emplace_back(0);
		for (size_type i = 2; i <= size(); ++i) log_table.emplace_back(log_table[i >> 1] + 1);
		
		table.reserve(log_table[size()] + 1);
		for (size_type i = 1; i <= log_table[size()]; ++i) {
			table.emplace_back();
			table[i].reserve(size() - (1 << i) + 1);
			for (size_type j = 0; j + (1 << i) <= size(); ++j) {
				table[i].emplace_back(f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]));
			}
		}
	}
};

#endif // INCLUDE_GUARD_SPARSE_TABLE_HPP