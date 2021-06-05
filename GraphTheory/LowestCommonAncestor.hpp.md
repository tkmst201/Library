---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.path.test.cpp
    title: Test/EulerTour.path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LowestCommonAncestor.test.cpp
    title: Test/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp
  bundledCode: "#line 1 \"GraphTheory/LowestCommonAncestor.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <utility>\r\n#include <cstdint>\r\
    \n#include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp\r\
    \n */\r\nstruct LowestCommonAncestor {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n, logn;\r\n\tstd::vector<std::vector<int>> par;\r\n\
    \tstd::vector<int> depth_;\r\n\t\r\npublic:\r\n\tLowestCommonAncestor(const Graph\
    \ & g, int root = 0) : n(g.size()) {\r\n\t\tassert(0 <= root && root < n);\r\n\
    \t\tlogn = 1;\r\n\t\twhile ((1 << logn) + 1 <= n) ++logn;\r\n\t\tpar.assign(logn,\
    \ std::vector<int>(n, -1));\r\n\t\tdepth_.assign(n, 0);\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tpar[0][root] = root;\r\n\t\tstk.emplace(root, root);\r\n\t\
    \twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, p] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tfor (int v : g[u]) {\r\n\t\t\t\tif (v == p) continue;\r\n\t\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\t\tpar[0][v] = u;\r\n\t\t\t\tdepth_[v] = depth_[u] +\
    \ 1;\r\n\t\t\t\tstk.emplace(v, u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 1;\
    \ i < logn; ++i) {\r\n\t\t\tfor (int j = 0; j < n; ++j) par[i][j] = par[i - 1][par[i\
    \ - 1][j]];\r\n\t\t}\r\n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tint find(int a, int b) const noexcept {\r\n\t\tassert(0\
    \ <= a && a < size());\r\n\t\tassert(0 <= b && b < size());\r\n\t\tassert(par[0][a]\
    \ != -1);\r\n\t\tassert(par[0][b] != -1);\r\n\t\tif (depth_[a] < depth_[b]) std::swap(a,\
    \ b);\r\n\t\ta = parent(a, depth_[a] - depth_[b]);\r\n\t\tif (a == b) return a;\r\
    \n\t\tfor (int i = logn - 1; i >= 0; --i) {\r\n\t\t\tif (par[i][a] != par[i][b])\
    \ a = par[i][a], b = par[i][b]; \r\n\t\t}\r\n\t\treturn par[0][a];\r\n\t}\r\n\t\
    \r\n\tint parent(int u, int k = 1) const noexcept {\r\n\t\tassert(0 <= u && u\
    \ < size());\r\n\t\tassert(k <= depth_[u]);\r\n\t\tassert(par[0][u] != -1);\r\n\
    \t\tfor (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];\r\n\t\treturn\
    \ u;\r\n\t}\r\n\t\r\n\tint depth(int u) const noexcept {\r\n\t\tassert(0 <= u\
    \ && u < size());\r\n\t\tassert(par[0][u] != -1);\r\n\t\treturn depth_[u];\r\n\
    \t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP\r\n#define INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <utility>\r\n#include\
    \ <cstdint>\r\n#include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp\r\
    \n */\r\nstruct LowestCommonAncestor {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n, logn;\r\n\tstd::vector<std::vector<int>> par;\r\n\
    \tstd::vector<int> depth_;\r\n\t\r\npublic:\r\n\tLowestCommonAncestor(const Graph\
    \ & g, int root = 0) : n(g.size()) {\r\n\t\tassert(0 <= root && root < n);\r\n\
    \t\tlogn = 1;\r\n\t\twhile ((1 << logn) + 1 <= n) ++logn;\r\n\t\tpar.assign(logn,\
    \ std::vector<int>(n, -1));\r\n\t\tdepth_.assign(n, 0);\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tpar[0][root] = root;\r\n\t\tstk.emplace(root, root);\r\n\t\
    \twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, p] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tfor (int v : g[u]) {\r\n\t\t\t\tif (v == p) continue;\r\n\t\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\t\tpar[0][v] = u;\r\n\t\t\t\tdepth_[v] = depth_[u] +\
    \ 1;\r\n\t\t\t\tstk.emplace(v, u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 1;\
    \ i < logn; ++i) {\r\n\t\t\tfor (int j = 0; j < n; ++j) par[i][j] = par[i - 1][par[i\
    \ - 1][j]];\r\n\t\t}\r\n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tint find(int a, int b) const noexcept {\r\n\t\tassert(0\
    \ <= a && a < size());\r\n\t\tassert(0 <= b && b < size());\r\n\t\tassert(par[0][a]\
    \ != -1);\r\n\t\tassert(par[0][b] != -1);\r\n\t\tif (depth_[a] < depth_[b]) std::swap(a,\
    \ b);\r\n\t\ta = parent(a, depth_[a] - depth_[b]);\r\n\t\tif (a == b) return a;\r\
    \n\t\tfor (int i = logn - 1; i >= 0; --i) {\r\n\t\t\tif (par[i][a] != par[i][b])\
    \ a = par[i][a], b = par[i][b]; \r\n\t\t}\r\n\t\treturn par[0][a];\r\n\t}\r\n\t\
    \r\n\tint parent(int u, int k = 1) const noexcept {\r\n\t\tassert(0 <= u && u\
    \ < size());\r\n\t\tassert(k <= depth_[u]);\r\n\t\tassert(par[0][u] != -1);\r\n\
    \t\tfor (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];\r\n\t\treturn\
    \ u;\r\n\t}\r\n\t\r\n\tint depth(int u) const noexcept {\r\n\t\tassert(0 <= u\
    \ && u < size());\r\n\t\tassert(par[0][u] != -1);\r\n\t\treturn depth_[u];\r\n\
    \t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2021-03-13 10:43:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/EulerTour.path.test.cpp
  - Test/LowestCommonAncestor.test.cpp
documentation_of: GraphTheory/LowestCommonAncestor.hpp
layout: document
title: "\u6700\u8FD1\u5171\u901A\u7956\u5148 (LCA)"
---

# 概要

頂点数を $N$ の木で任意の $2$ 頂点の最近共通祖先を事前計算 $\Theta(N \log{N})$ クエリ $\Theta(\log{N})$ で求めることのできるライブラリです。  
実は [重軽分解 ( HL 分解)](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) を用いた LCA の方が高速かつ使用メモリも少ないです(事前計算 $\Theta(N\log{\log{N}})$ クエリ $\Theta(\log{\log{N}})$ )、森にも対応しています。  

- `LowestCommonAncestor(const Graph & g, int root = 0)`
	- 時間/空間 $\Theta(N \log{N})$ 根 `root` の根付き木 $g$ (頂点数 $N$) で初期化
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `int find(int a, int b)`
	- $\Theta(\log{N})$ 頂点 $a$, $b$ の最近共通祖先を返す
- `int parent(int u, int k = 1)`
	- $\Theta(\log{N})$ 頂点 $u$ の $k$ 回根方向に辺をたどった頂点を返す
- `int depth(int u)`
	- $\Theta(1)$ 頂点 $u$ から根までのパス上にある辺の個数を返す

<br>

# コンストラクタ

### LowestCommonAncestor(const Graph & g, int root = 0)

根 `root` の根付き木 $g$ (頂点数 $N$ ) で初期化します。  

**制約**

- $0 \leq$ `root` $< N$
- `g` は根付き木または木

**計算量**

- 時間/空間 $\Theta(N \log{N})$

---

<br>

# メンバ関数

以下、グラフの頂点数を $N$ とします。  

---

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int find(int a, int b)

頂点 $a$, $b$ の最近共通祖先を返します。  

**制約**

- $0 \leq a, b < N$

**計算量**

- $\Theta(\log{N})$

---

### int parent(int u, int k = 1)

頂点 $u$ の $k$ 回根方向に辺をたどった頂点を返します。  

**制約**

- $0 \leq u < N$
- 頂点 $u$ から根までのパス上にある辺の個数は $k$ 個以下

**計算量**

- $\Theta(\log{N})$

---

### int depth(int u)

頂点 $u$ から根までのパス上にある辺の個数を返します。  

**制約**

- $0 \leq u < N$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/LowestCommonAncestor.hpp"
using namespace std;

int main() {
	LowestCommonAncestor::Graph g(6);
	//         1
	//    2        3
	// 0    4          5
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	LowestCommonAncestor lca(g, 1);
	
	cout << "size() = " << lca.size() << endl; // 6
	
	cout << "find(2, 3) = " << lca.find(2, 3) << endl; // 1
	cout << "find(2, 5) = " << lca.find(2, 5) << endl; // 1
	cout << "find(1, 3) = " << lca.find(1, 3) << endl; // 1
	cout << "find(0, 4) = " << lca.find(0, 4) << endl; // 2
	cout << "find(0, 2) = " << lca.find(0, 2) << endl; // 2
	cout << "find(0, 0) = " << lca.find(0, 0) << endl; // 0
	cout << "find(0, 5) = " << lca.find(0, 5) << endl; // 1
	
	cout << "parent(4) = " << lca.parent(4) << endl; // 2
	cout << "parent(4, 2) = " << lca.parent(4, 2) << endl; // 1
	cout << "parent(3, 0) = " << lca.parent(3, 0) << endl; // 3
	
	cout << "depth(1) = " << lca.depth(1) << endl; // 0
	cout << "depth(2) = " << lca.depth(2) << endl; // 1
	cout << "depth(0) = " << lca.depth(0) << endl; // 2
	cout << "depth(5) = " << lca.depth(5) << endl; // 2
}
```

<br>