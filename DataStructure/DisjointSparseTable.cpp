#include <vector>
#include <cassert>
#include <functional>
#include <algorithm>

/*
last-updated: 2020/04/30

※非可換の場合は unverified
T は半群

template<class InputIterator>
DisjointSparseTable(InputIterator first, InputIterator last, const F &f) :
	θ(n log n)
	[farst, last) でテーブルを作成する
	二項演算 f

size_type empty() const noexcept : θ(1) 要素が空であるかを判定する
size_type size() const noexcept : θ(1) 要素数を返す

value_type fold(size_type l, size_type r) const :
	θ(loglog n)
	[l, r) を fold した結果を返す

参考 :
https://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b, 2020/04/30
*/

template <typename T>
struct DisjointSparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	template<class InputIterator>
	DisjointSparseTable(InputIterator first, InputIterator last, const F &f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	size_type empty() const noexcept { return size() == 0; }
	size_type size() const noexcept { return table.empty() ? 0 : table.front().size(); }
	
	value_type fold(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		--r;
		if (l == r) return table.front()[l];
		int level = msb(l ^ r) + 1;
		return f(table[level][l ^ (1 << level - 1) - 1], table[level][r]);
	}
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	
	void build() {
		assert(table.size() == 1);
		table.reserve(size() > 1 ? msb(size() - 1) + 2: 1);
		for (size_type level = 1; 1 << level - 1 <= size(); ++level) {
			size_type rest = size() % (1 << level);
			table.emplace_back();
			table.reserve(rest > 1 << level - 1 ? size() : size() - rest);
			
			for (size_type i = 0; i < size(); i += 1 << level) {
				size_type k = std::min(i + (1 << level - 1), size());
				if (k == size()) continue;
				
				table.back().emplace_back(table.front()[k - 1]);
				for (size_type j = k - 1; j > i; --j)
					table.back().emplace_back(f(table.front()[j - 1], table.back().back()));
				
				table.back().emplace_back(table.front()[k]);
				for (size_type j = k + 1, ej = std::min(i + (1 << level), size()); j < ej; ++j)
					table.back().emplace_back(f(table.back().back(), table.front()[j]));
			}
		}
	}
	
	size_type msb(size_type n) const {
		size_type l = 0, r = table.size();
		while (r - l > 1) {
			size_type m = (l + r) / 2;
			if (1 << m <= n) l = m;
			else r = m;
		}
		return l;
	}
};