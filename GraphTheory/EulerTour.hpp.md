---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DynamicSegmentTree.swap.test.cpp
    title: Test/DynamicSegmentTree.swap.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.path.test.cpp
    title: Test/EulerTour.path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.subtree.test.cpp
    title: Test/EulerTour.subtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp
  bundledCode: "#line 1 \"GraphTheory/EulerTour.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <stack>\r\n#include <utility>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp\r\n */\r\
    \ntemplate<bool EDGE>\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\
    \n\tusing Graph = std::vector<std::vector<int>>;\r\n\t\r\nprivate:\r\n\tint n,\
    \ root;\r\n\tstd::vector<int> in_, out_, par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const\
    \ Graph & g, int root = 0)\r\n\t\t: n(g.size()), root(root), in_(size(), -1),\
    \ out_(size(), -1), par_(n, -1), g_idx(n << 1, -1) {\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tint num = 0;\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root,\
    \ 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, i] = stk.top();\r\n\
    \t\t\tstk.pop();\r\n\t\t\tif (i < g[u].size()) {\r\n\t\t\t\tconst int v = g[u][i];\r\
    \n\t\t\t\tassert(0 <= v && v < n);\r\n\t\t\t\tassert(v != u);\r\n\t\t\t\tstk.emplace(u,\
    \ i + 1);\r\n\t\t\t\tif (v == par_[u]) g_idx[u << 1 | 1] = i;\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tin_[v] = num++;\r\n\t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tg_idx[v\
    \ << 1] = i;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\t\
    else {\r\n\t\t\t\tout_[u] = num;\r\n\t\t\t\tif (EDGE) ++num;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn EDGE ? n <<\
    \ 1 : n;\r\n\t}\r\n\t\r\n\tint par(int k) const noexcept {\r\n\t\tassert(0 <=\
    \ k && k < n);\r\n\t\treturn par_[k];\r\n\t}\r\n\t\r\n\tint in(int k) const noexcept\
    \ {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn in_[k];\r\n\t}\r\n\t\r\n\tint\
    \ out(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn out_[k];\r\
    \n\t}\r\n\t\r\n\tstd::pair<int, int> par_from(int k) const noexcept {\r\n\t\t\
    assert(0 <= k && k < n);\r\n\t\treturn {par_[k], g_idx[k << 1]};\r\n\t}\r\n\t\r\
    \n\tint par_to(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\t\
    return g_idx[k << 1 | 1];\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_EULER_TOUR_HPP\r\n#define INCLUDE_GUARD_EULER_TOUR_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp\r\
    \n */\r\ntemplate<bool EDGE>\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\
    \n\tusing Graph = std::vector<std::vector<int>>;\r\n\t\r\nprivate:\r\n\tint n,\
    \ root;\r\n\tstd::vector<int> in_, out_, par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const\
    \ Graph & g, int root = 0)\r\n\t\t: n(g.size()), root(root), in_(size(), -1),\
    \ out_(size(), -1), par_(n, -1), g_idx(n << 1, -1) {\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tint num = 0;\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root,\
    \ 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, i] = stk.top();\r\n\
    \t\t\tstk.pop();\r\n\t\t\tif (i < g[u].size()) {\r\n\t\t\t\tconst int v = g[u][i];\r\
    \n\t\t\t\tassert(0 <= v && v < n);\r\n\t\t\t\tassert(v != u);\r\n\t\t\t\tstk.emplace(u,\
    \ i + 1);\r\n\t\t\t\tif (v == par_[u]) g_idx[u << 1 | 1] = i;\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tin_[v] = num++;\r\n\t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tg_idx[v\
    \ << 1] = i;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\t\
    else {\r\n\t\t\t\tout_[u] = num;\r\n\t\t\t\tif (EDGE) ++num;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn EDGE ? n <<\
    \ 1 : n;\r\n\t}\r\n\t\r\n\tint par(int k) const noexcept {\r\n\t\tassert(0 <=\
    \ k && k < n);\r\n\t\treturn par_[k];\r\n\t}\r\n\t\r\n\tint in(int k) const noexcept\
    \ {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn in_[k];\r\n\t}\r\n\t\r\n\tint\
    \ out(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn out_[k];\r\
    \n\t}\r\n\t\r\n\tstd::pair<int, int> par_from(int k) const noexcept {\r\n\t\t\
    assert(0 <= k && k < n);\r\n\t\treturn {par_[k], g_idx[k << 1]};\r\n\t}\r\n\t\r\
    \n\tint par_to(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\t\
    return g_idx[k << 1 | 1];\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_EULER_TOUR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/EulerTour.hpp
  requiredBy: []
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DynamicSegmentTree.swap.test.cpp
  - Test/EulerTour.subtree.test.cpp
  - Test/EulerTour.path.test.cpp
documentation_of: GraphTheory/EulerTour.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---

# 概要

木の頂点や辺を良い性質を持つような列に並べます。  
[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) や [最近共通祖先 (LCA)](https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp) を組み合わせることよって部分木クエリやパスクエリを効率的に処理することが可能です。
詳しくは`使用例`をご覧ください。  

- `EulerTour(const Graph & g, int root = )`
	- $\Theta(N)$ 根 `root` の根付き木 `g` (頂点数 $N$ ) で初期化
- `size_t size()`
	- $\Theta(1)$ 最大時刻 $+ 1$ を返す
- `int par(int k)`
	- $\Theta(1)$ 頂点 $k$ の親を返す
- `int in(int k)`
	- $\Theta(1)$ 頂点 $k$ に入ったときの時刻を返す
- `int out(int k)`
	- $\Theta(1)$ 頂点 $k$ から出たときの時刻を返す
- `std::pair<int, int> par_from(int k)`
	- $\Theta(1)$ 頂点 $k$ の親 $p$ と、頂点 $p$ の隣接リストに含まれる頂点 $k$ の index の組を返す
- `int par_to(int k)`
	- $\Theta(1)$ 頂点 $k$ の隣接リストに含まれる親 $p$ の index を返す

<br>

# コンストラクタ

### EulerTour(const Graph & g, int root = 0)

根 `root` の根付き木 `g` (頂点数 $N$ ) で初期化します。
時刻の経過地点を辺にするときは `EDGE` $= true$ を、頂点にするときは `EDGE` $= false$ を指定してください。  

**制約**

- `g` は `root` を根とした根付き木または木
- $0 \leq$ `root` $< N$

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

以下、グラフの頂点数を $N$ とします。  

---

### size_t size()

最大時刻 $+ 1$ を返します。  

**計算量**

- $\Theta(1)$

---

### int par(int k)

頂点 $k$ の親を返します。
ただし、親が存在しない場合は $-1$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(1)$

---

### int in(int k)

頂点 $k$ に入ったときの時刻を返します。
ただし、$k$ が根のときは $0$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(1)$

---

### int out(int k)

頂点 $k$ から出たときの時刻を返します。
ただし、$k$ が根のときは $0$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(1)$

---

### std::pair<int, int> par_from(int k)

頂点 $k$ の親 $p$ と、頂点 $p$ の隣接リストに含まれる頂点 $k$ の index の組を返します。
ただし、親が存在しない場合は $(-1, -1)$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(1)$

---

### int par_to(int k)

頂点 $k$ の隣接リストに含まれる親 $p$ の index を返します。
そのような index が存在しない場合は $-1$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/EulerTour.hpp"
using namespace std;

int main() {
	EulerTour<false>::Graph g(6);
	//         1
	//    2        3
	// 0    4          5
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	// EDGE = false の各頂点の入出時刻
	puts("EDGE = false");
	EulerTour<false> etf(g, 1);
	cout << "size() = " << etf.size() << endl; // 6
	/*
	i = 0, in = 2, out = 3
	i = 1, in = 0, out = 6
	i = 2, in = 1, out = 4
	i = 3, in = 4, out = 6
	i = 4, in = 3, out = 4
	i = 5, in = 5, out = 6
	頂点 u の部分木は区間 [ in(u), out(u) )
	*/
	for (int i = 0; i < 6; ++i) cout << "i = " << i << ", in = " << etf.in(i) << ", out = " << etf.out(i) << endl;
	
	puts("EDGE = true");
	EulerTour<true> ett(g, 1);
	cout << "size() = " << ett.size() << endl; // 12
	/*
	i = 0, in = 2, out = 3
	i = 1, in = 0, out = 11
	i = 2, in = 1, out = 6
	i = 3, in = 7, out = 10
	i = 4, in = 4, out = 5
	i = 5, in = 8, out = 9
	頂点 u の部分木は区間 [ in(u), out(u) )
	*/
	for (int i = 0; i < 6; ++i) cout << "i = " << i << ", in = " << ett.in(i) << ", out = " << ett.out(i) << endl;
	
	
	//         1
	//    2        3
	// 0    4          5
	cout << "par(4) = " << etf.par(4) << endl; // 2
	cout << "par(3) = " << etf.par(3) << endl; // 1
	cout << "par(1) = " << etf.par(1) << endl; // -1
	
	auto [p, pfidx] = etf.par_from(2);
	cout << "par_from(2) = (" << p << ", " << pfidx << "), (" << g[p][pfidx] << ")" << endl; // (1, 0) (2)
	cout << "par_from(1) = (" << etf.par_from(1).first << ", " << etf.par_from(1).second << ")" << endl; // (-1, -1)
	
	cout << "par_to(5) = " << etf.par_to(5) << " (" << g[5][etf.par_to(5)] << ")" << endl; // 0, 3
}
```

頂点 $u$ の部分木の頂点は区間 $[$ in$[u],$ out$[u]\ )$ にあることに注意すると可環モノイドに対する部分木クエリは次のように処理することができます。  

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/EulerTour.hpp"
#include "DataStructure/SegmentTree.hpp"
#include "DataStructure/LazySegmentTree.hpp"
using namespace std;

int main() {
	EulerTour<false>::Graph g(6);
	//         1(10)
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	EulerTour<false> et(g, 1);
	
	SegmentTree<int> seg(et.size(), 0, [](auto x, auto y) { return x + y; });
	constexpr int A[6] {1, 10, 100, 1000, 10000, 100000};
	for (int i = 0; i < 6; ++i) seg.set(et.in(i), A[i]); // in(i) に値をセット
	
	// 頂点 1 の部分木の頂点の値の総和
	cout << "subtree sum(1) = " << seg.fold(et.in(1), et.out(1)) << endl; // 111111
	// 頂点 2 の部分木の頂点の値の総和
	cout << "subtree sum(2) = " << seg.fold(et.in(2), et.out(2)) << endl; // 10101
	// 頂点 5 の部分木の頂点の値の総和
	cout << "subtree sum(5) = " << seg.fold(et.in(5), et.out(5)) << endl; // 100000
	
	// 遅延セグメント木を使用すると部分木の頂点全体に対する操作が可能
	LazySegmentTree<int, int> lseg(et.size(), 0, 0,
		[](auto x, auto y) { return x + y; },
		[](auto x, auto e) { return x + e; },
		[](auto e1, auto e2) { return e1 + e2; },
		[](auto e, auto k) { return e * k; });
	for (int i = 0; i < 6; ++i) lseg.set(et.in(i), A[i]); // in(i) に値をセット
	
	// 頂点 2 の部分木の頂点の値の総和
	cout << "subtree sum(2) = " << lseg.fold(et.in(2), et.out(2)) << endl; // 10101
	
	// 頂点 3 の部分木に含まれる頂点の値を 1000000 増やす
	lseg.update(et.in(3), et.out(3), 1000000);
	// 頂点 3 の部分木の頂点の値の総和
	cout << "subtree sum(3) = " << lseg.fold(et.in(3), et.out(3)) << endl; // 2101000
	// 頂点 2 の部分木の頂点の値の総和
	cout << "subtree sum(2) = " << lseg.fold(et.in(2), et.out(2)) << endl; // 10101
}
```

アーベル群に対するパスクエリは、頂点から出る時刻に逆元をセットすることによって処理することが可能です。
また、[重軽分解 ( HL 分解) クエリ](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp)を用いれば、$\log$ が付きますがモノイドに対するパスクエリを処理することが可能です。  

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/EulerTour.hpp"
#include "DataStructure/SegmentTree.hpp"
#include "GraphTheory/LowestCommonAncestor.hpp"
using namespace std;

int main() {
	EulerTour<true>::Graph g(6);
	// 辺の値は葉側の頂点に持たせている
	//         1
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	EulerTour<true> et(g, 1);
	
	SegmentTree<int> seg(et.size(), 0, [](auto x, auto y) { return x + y; });
	constexpr int A[6] {1, 0, 100, 1000, 10000, 100000};
	for (int i = 0; i < 6; ++i) {
		seg.set(et.in(i), A[i]); // in(i) に値をセット
		seg.set(et.out(i), -A[i]); // out(i) に逆元をセット
	}
	LowestCommonAncestor lca(g, 1);
	
	// u-v パスに含まれる辺の値の総和を返す
	auto func = [&](int u, int v) {
		const int l = lca.find(u, v); // lca(u, v)
		// l-a パスに含まれる辺の値の総和を返す
		// l-a パスに含まれない辺の値は逆元に打ち消される
		auto sub = [&](int a) {
			return seg.fold(et.in(l) + 1, et.in(a) + 1);
		};
		return sub(u) + sub(v);
	};
	
	cout << "1-3 path sum = " << func(1, 3) << endl; // 1000
	cout << "1-4 path sum = " << func(1, 4) << endl; // 10100
	cout << "0-5 path sum = " << func(0, 5) << endl; // 101101
	cout << "4-4 path sum = " << func(4, 4) << endl; // 0
}
```

<br>

# 参考

2020/09/16: [https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7](https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7)  
2020/09/16: [https://beet-aizu.hatenablog.com/entry/2019/07/08/174727](https://beet-aizu.hatenablog.com/entry/2019/07/08/174727)  

<br>