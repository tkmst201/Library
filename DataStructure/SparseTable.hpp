#ifndef INCLUDE_GUARD_SPARSE_TABLE_HPP
#define INCLUDE_GUARD_SPARSE_TABLE_HPP

/*
last-updated: 2020/04/30

build θ(n log n), fold θ(1)

# 仕様
template<class InputIterator>
DisjointSparseTable(InputIterator first, InputIterator last, const F &f) :
	時間計算量: Θ(n log n)
	[farst, last) でテーブルを作成する
	冪等な二項演算 f

size_type empty() const noexcept :
	時間計算量: Θ(1)
	要素が空であるかを判定する

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数を返す

value_type fold(size_type l, size_type r) const :
	θ(1)
	[l, r) を fold した結果を返す

# 参考
http://tookunn.hatenablog.com/entry/2016/07/13/211148, 2020/04/30
*/

#include <vector>
#include <cassert>
#include <functional>

template<typename T>
struct SparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	template<class InputIterator>
	SparseTable(InputIterator first, InputIterator last, const F &f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	bool empty() const noexcept { return size() == 0; }
	size_type size() const noexcept { return table.empty() ? 0 : table.front().size(); }
	
	value_type fold(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		size_type diff = r - l;
		return f(table[log_table[diff] - 1][l], table[log_table[diff] - 1][r - (1 << log_table[diff] - 1)]);
	}
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	std::vector<size_type> log_table;
	
	void build() {
		log_table.reserve(size() + 1);
		log_table.emplace_back(0);
		for (size_type i = 1; i <= size(); ++i) log_table.emplace_back(log_table[i >> 1] + 1);
		
		table.reserve(log_table[size()]);
		for (size_type i = 1; i < log_table[size()]; ++i) {
			table.emplace_back();
			table[i].reserve(size() - (1 << i) + 1);
			for (size_type j = 0; j + (1 << i) <= size(); ++j)
				table[i].emplace_back(f(table[i - 1][j], table[i - 1][j + (1 << i - 1)]));
		}
	}
};

#endif // INCLUDE_GUARD_SPARSE_TABLE_HPP