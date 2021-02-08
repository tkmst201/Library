#ifndef INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP
#define INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP

#include <vector>
#include <cassert>
#include <functional>
#include <algorithm>
#include <utility>

#include <Mathematics/bit_operation.hpp>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp
 */
template <typename T>
struct DisjointSparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	
public:
	template<class InputIterator>
	DisjointSparseTable(InputIterator first, InputIterator last, const F & f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	size_type size() const noexcept {
		return table.empty() ? 0 : table.front().size();
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		--r;
		if (l == r) return table.front()[l];
		size_type level = 31 - tk::count_leading_zeros(l ^ r);
		return f(table[level][l ^ ~(~0 << level)], table[level][r]);
	}
	
private:
	void build() {
		if (size() <= 2) return;
		table.reserve(32 - tk::count_leading_zeros(size() - 1));
		for (size_type level = 1; (1 << level) + 1 <= size(); ++level) {
			std::vector<value_type> dat;
			const size_type cnt = size() & (~0 << (level + 1));
			dat.reserve(cnt + (1 << level) + 1 <= size() ? size() : cnt);
			for (size_type i = 0; i < size(); i += 1 << (level + 1)) {
				size_type k = i + (1 << level);
				if (k >= size()) continue;
				dat.emplace_back(table.front()[k - 1]);
				for (size_type j = k - 1; j != i; --j) {
					dat.emplace_back(f(table.front()[j - 1], dat.back()));
				}
				dat.emplace_back(table.front()[k]);
				for (size_type j = k + 1, ej = std::min(k + (1 << level), size()); j != ej; ++j) {
					dat.emplace_back(f(dat.back(), table.front()[j]));
				}
			}
			table.emplace_back(std::move(dat));
		}
	}
};

#endif // INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP