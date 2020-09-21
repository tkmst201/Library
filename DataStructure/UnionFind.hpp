#ifndef INCLUDE_GUARD_UNION_FIND_HPP
#define INCLUDE_GUARD_UNION_FIND_HPP

/*
last-updated: 2020/04/22

size() verify : https://atcoder.jp/contests/abc157/submissions/12223429

# 仕様
UnionFind(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

size_type size(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの要素数を返す

size_type find(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの代表番号を返す

void unite(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y がそれぞれ属するグループを併合する

bool issame(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y が同一グループに属するかを返す

# 参考
https://en.wikipedia.org/wiki/Disjoint-set_data_structure, 2020/04/22
https://qiita.com/kopricky/items/3e5847ab1451fe990367, 2020/04/22
*/

#include <vector>
#include <numeric>
#include <utility>
#include <cassert>

struct UnionFind {
public:
	using size_type = std::size_t;
	
	UnionFind(size_type n) : n(n), size_(n, 1) {
		par.resize(n);
		std::iota(par.begin(), par.end(), 0);
	}
	
	size_type size(size_type x) { return size_[find(x)]; }
	
	size_type find(size_type x) {
		assert(x < n);
		while (par[x] != x) {
			par[x] = par[par[x]];
			x = par[x];
		}
		return x;
	}
	
	void unite(size_type x, size_type y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (size(x) > size(y)) std::swap(x, y);
		par[x] = y;
		size_[y] += size_[x];
	}
	
	bool issame(size_type x, size_type y) { return find(x) == find(y); }
	
private:
	size_type n;
	std::vector<size_type> size_, par;
};


#endif // INCLUDE_GUARD_UNION_FIND_HPP