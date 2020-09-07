#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP
#define INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP

#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

# 仕様
BinaryIndexedTree2D(size_type h, size_type w) :
	h \times w の表を構築

void add(size_type i, size_type j, const_reference x) :
	時間計算量: Θ(log h log w)
	点 (i, j) に値 x を加算

value_type sum(size_type i, size_type j) const :
	時間計算量: Θ(log h log w)
	[0, i) \times [0, j) の合計を返す

	// [i1, i2) x [j1, j2)
value_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const :
	時間計算量: Θ(log h log w)
	[i1, i2) \times [j1, j2) の合計を返す

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T>
struct BinaryIndexedTree2D {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
	BinaryIndexedTree2D(size_type h, size_type w) : h(h), w(w) {
		node.resize(h + 1, std::vector<value_type>(w + 1));
	}
	
	void add(size_type i, size_type j, const_reference x) {
		assert(i < h);
		assert(j < w);
		++i; ++j;
		for (; i <= h; i += i & -i) {
			for (size_type k = j; k <= w; k += k & -k) {
				node[i][k] += x;
			}
		}
	}
	
	// [0, i) x [0, j)
	value_type sum(size_type i, size_type j) const {
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
	
	// [i1, i2) x [j1, j2)
	value_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const {
		assert(i1 < i2);
		assert(j1 < j2);
		assert(i2 <= h);
		assert(j2 <= w);
		return sum(i2, j2) - sum(i2, j1) - sum(i1, j2) + sum(i1, j1);
	}
	
private:
	size_type h, w;
	std::vector<std::vector<value_type>> node;
};

#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP