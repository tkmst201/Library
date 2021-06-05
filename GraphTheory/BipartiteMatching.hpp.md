---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BipartiteMatching.test.cpp
    title: Test/BipartiteMatching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp
  bundledCode: "#line 1 \"GraphTheory/BipartiteMatching.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <utility>\r\n#include <queue>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp\r\
    \n */\r\nstruct BipartiteMatching {\r\nprivate:\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\tGraph g;\r\n\tint x, y;\r\n\tbool isswap;\r\n\tint max_maching_;\r\n\tstd::vector<int>\
    \ match_x, match_y;\r\n\tbool isbuilt = false;\r\n\t\r\npublic:\r\n\tBipartiteMatching(int\
    \ x, int y)\r\n\t\t: g(std::min(x, y)), x(std::min(x, y)), y(std::max(x, y)),\
    \ isswap(x > y) {}\r\n\t\r\n\tBipartiteMatching(int n) : BipartiteMatching(n,\
    \ n) {}\r\n\t\r\n\tvoid add_edge(int a, int b) {\r\n\t\tif (isswap) std::swap(a,\
    \ b);\r\n\t\tassert(0 <= a && a < x);\r\n\t\tassert(0 <= b && b < y);\r\n\t\t\
    g[a].emplace_back(b);\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tvoid build() {\r\
    \n\t\tmatch_y.assign(y, -1);\r\n\t\tmatch_x.assign(x, -1);\r\n\t\tmax_maching_\
    \ = 0;\r\n\t\tint c = 1;\r\n\t\tstd::vector<int> visited(x, 0);\r\n\t\tbool update\
    \ = false;\r\n\t\tauto dfs = [&](auto self, int u) -> bool {\r\n\t\t\tvisited[u]\
    \ = c;\r\n\t\t\tfor (int v : g[u]) if (match_y[v] == -1) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tfor (int v : g[u]) if (visited[match_y[v]] >= 0\
    \ && visited[match_y[v]] != c && self(self, match_y[v])) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tif (!update) visited[u] = -1;\r\n\t\t\treturn false;\r\
    \n\t\t};\r\n\t\tstd::queue<int> que;\r\n\t\tfor (int i = 0; i < x; ++i) {\r\n\t\
    \t\tif (dfs(dfs, i)) ++max_maching_, update = true;\r\n\t\t\telse if (update)\
    \ que.emplace(i);\r\n\t\t}\r\n\t\twhile (!que.empty()) {\r\n\t\t\t++c;\r\n\t\t\
    \tconst int n = que.size();\r\n\t\t\tupdate = false;\r\n\t\t\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\t\t\tconst int u = que.front();\r\n\t\t\t\tque.pop();\r\n\
    \t\t\t\tif (match_x[u] == -1 && visited[u] != c && dfs(dfs, u)) {\r\n\t\t\t\t\t\
    ++max_maching_;\r\n\t\t\t\t\tupdate = true;\r\n\t\t\t\t}\r\n\t\t\t\telse if (update)\
    \ que.emplace(u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t}\r\n\t\r\n\t\
    int max_matching() const noexcept {\r\n\t\tassert(isbuilt);\r\n\t\treturn max_maching_;\r\
    \n\t}\r\n\t\r\n\tstd::vector<std::pair<int, int>> matching() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tstd::vector<std::pair<int, int>> res;\r\n\t\tfor (int i = 0; i < x; ++i)\
    \ {\r\n\t\t\tif (match_x[i] == -1) continue;\r\n\t\t\tif (isswap) res.emplace_back(match_x[i],\
    \ i);\r\n\t\t\telse res.emplace_back(i, match_x[i]);\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tint matching_x(int k) const noexcept {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(0 <= k && k < (isswap ? y : x));\r\n\t\treturn isswap ? match_y[k]\
    \ : match_x[k];\r\n\t}\r\n\t\r\n\tint matching_y(int k) const noexcept {\r\n\t\
    \tassert(isbuilt);\r\n\t\tassert(0 <= k && k < (isswap ? x : y));\r\n\t\treturn\
    \ isswap ? match_x[k] : match_y[k];\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_BIPARTITE_MATCHING_HPP\r\n#define INCLUDE_GUARD_BIPARTITE_MATCHING_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <utility>\r\n#include\
    \ <queue>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp\r\
    \n */\r\nstruct BipartiteMatching {\r\nprivate:\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\tGraph g;\r\n\tint x, y;\r\n\tbool isswap;\r\n\tint max_maching_;\r\n\tstd::vector<int>\
    \ match_x, match_y;\r\n\tbool isbuilt = false;\r\n\t\r\npublic:\r\n\tBipartiteMatching(int\
    \ x, int y)\r\n\t\t: g(std::min(x, y)), x(std::min(x, y)), y(std::max(x, y)),\
    \ isswap(x > y) {}\r\n\t\r\n\tBipartiteMatching(int n) : BipartiteMatching(n,\
    \ n) {}\r\n\t\r\n\tvoid add_edge(int a, int b) {\r\n\t\tif (isswap) std::swap(a,\
    \ b);\r\n\t\tassert(0 <= a && a < x);\r\n\t\tassert(0 <= b && b < y);\r\n\t\t\
    g[a].emplace_back(b);\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tvoid build() {\r\
    \n\t\tmatch_y.assign(y, -1);\r\n\t\tmatch_x.assign(x, -1);\r\n\t\tmax_maching_\
    \ = 0;\r\n\t\tint c = 1;\r\n\t\tstd::vector<int> visited(x, 0);\r\n\t\tbool update\
    \ = false;\r\n\t\tauto dfs = [&](auto self, int u) -> bool {\r\n\t\t\tvisited[u]\
    \ = c;\r\n\t\t\tfor (int v : g[u]) if (match_y[v] == -1) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tfor (int v : g[u]) if (visited[match_y[v]] >= 0\
    \ && visited[match_y[v]] != c && self(self, match_y[v])) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tif (!update) visited[u] = -1;\r\n\t\t\treturn false;\r\
    \n\t\t};\r\n\t\tstd::queue<int> que;\r\n\t\tfor (int i = 0; i < x; ++i) {\r\n\t\
    \t\tif (dfs(dfs, i)) ++max_maching_, update = true;\r\n\t\t\telse if (update)\
    \ que.emplace(i);\r\n\t\t}\r\n\t\twhile (!que.empty()) {\r\n\t\t\t++c;\r\n\t\t\
    \tconst int n = que.size();\r\n\t\t\tupdate = false;\r\n\t\t\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\t\t\tconst int u = que.front();\r\n\t\t\t\tque.pop();\r\n\
    \t\t\t\tif (match_x[u] == -1 && visited[u] != c && dfs(dfs, u)) {\r\n\t\t\t\t\t\
    ++max_maching_;\r\n\t\t\t\t\tupdate = true;\r\n\t\t\t\t}\r\n\t\t\t\telse if (update)\
    \ que.emplace(u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t}\r\n\t\r\n\t\
    int max_matching() const noexcept {\r\n\t\tassert(isbuilt);\r\n\t\treturn max_maching_;\r\
    \n\t}\r\n\t\r\n\tstd::vector<std::pair<int, int>> matching() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tstd::vector<std::pair<int, int>> res;\r\n\t\tfor (int i = 0; i < x; ++i)\
    \ {\r\n\t\t\tif (match_x[i] == -1) continue;\r\n\t\t\tif (isswap) res.emplace_back(match_x[i],\
    \ i);\r\n\t\t\telse res.emplace_back(i, match_x[i]);\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tint matching_x(int k) const noexcept {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(0 <= k && k < (isswap ? y : x));\r\n\t\treturn isswap ? match_y[k]\
    \ : match_x[k];\r\n\t}\r\n\t\r\n\tint matching_y(int k) const noexcept {\r\n\t\
    \tassert(isbuilt);\r\n\t\tassert(0 <= k && k < (isswap ? x : y));\r\n\t\treturn\
    \ isswap ? match_x[k] : match_y[k];\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BIPARTITE_MATCHING_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2021-03-14 12:24:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BipartiteMatching.test.cpp
documentation_of: GraphTheory/BipartiteMatching.hpp
layout: document
title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
---

# 概要

二部グラフ上の最大マッチングを求めます。  
計算量は、$2$ つの頂点集合をそれぞれ $S$, $T$ 、辺の数を $M$ として $\mathcal{O}(\min(\|S\|, \|T\|) M)$ です。  
実際はかなり高速です。  

- `BipartiteMatching(int x, int y)`
	- $\Theta(x + y)$ $\|S\| = x, \|T\| = y$ で初期化
- `BipartiteMatching(int n)`
	- $\Theta(n)$ $\|S\| = \|T\| = n$ で初期化
- `void add_edge(int a, int b)`
	- ならし $\Theta(1)$ $S$ の頂点 $a$ と $T$ の頂点 $b$ の間に辺を張る
- `void build()`
	- $\mathcal{O}(\min(\|S\|, \|T\|) M)$ $S, T$ の最大マッチングを求める
- `int max_matching()`
	- $\Theta(1)$ $S, T$ の最大マッチングでのマッチング数を返す
- `std::vector<std::pair<int, int>> matching()`
	- $\Theta(\min(\|S\|, \|T\|))$ $S, T$ の最大マッチングでのそれぞれのマッチングの組 ($S, T$ の順) を返す
- `int matching_x(int k)`
	- $\Theta(1)$ $S, T$ の最大マッチングでの $S$ の頂点 $k$ のマッチング先を返す
- `int matching_y(int k)`
	- $\Theta(1)$ $S, T$ の最大マッチングでの $T$ の頂点 $k$ のマッチング先を返す

<br>

# コンストラクタ

以下、$2$ つの頂点集合をそれぞれ $S$, $T$ 、辺の数を $M$ とします。  

---

### BipartiteMatching(int x, int y)

$\|S\| = x, \|T\| = y$ で初期化します。  

**制約**

- $0 \leq x, y$

**計算量**

- $\Theta(x + y)$

---

### BipartiteMatching(int n)

$\|S\| = \|T\| = n$ で初期化します。  

**制約**

- $0 \leq n$

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数


### void add_edge(int a, int b)

$S$ の頂点 $a$ と $T$ の頂点 $b$ の間に辺を張ります。  

**計算量**

- ならし $\Theta(1)$

---

### void build()

$S, T$ の最大マッチングを求めます。
必ず事前に呼んでください。  

**計算量**

- $\mathcal{O}(\min(\|S\|, \|T\|) M)$

---

### int max_matching()

$S, T$ の最大マッチングでのマッチング数を返します。  

**計算量**

- $\Theta(1)$

### std::vector&lt;std::pair&lt;int, int&gt;&gt; matching()

$S, T$ の最大マッチングでのそれぞれのマッチングの組 ($S, T$ の順) を返します。  

**計算量**

- $\Theta(\min(\|S\|, \|T\|))$

---

### int matching_x(int k)

$S, T$ の最大マッチングでの $S$ の頂点 $k$ のマッチング先を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq k < \|S\|$

**計算量**

- $\Theta(1)$

---

### int matching_y(int k)

$S, T$ の最大マッチングでの $T$ の頂点 $k$ のマッチング先を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq k < \|T\|$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/BipartiteMatching.hpp"
using namespace std;

int main() {
	BipartiteMatching bm(3, 4);
	// S -> T
	// 0 -> 0 1
	// 1 -> 1
	// 2 -> 1 3
	bm.add_edge(0, 0);
	bm.add_edge(0, 1);
	bm.add_edge(1, 1);
	bm.add_edge(2, 1);
	bm.add_edge(2, 3);
	bm.build(); // 必ず呼ぶ
	
	cout << "max_matching() = " << bm.max_matching() << endl; // 3
	/*
		matching : 0 - 0
		matching : 1 - 1
		matching : 2 - 3
	*/
	for (auto [x, y] : bm.matching()) cout << "matching : " << x << " - " << y << endl;
	
	/*
		S: x = 0 - 0
		S: x = 1 - 1
		S: x = 2 - 3
		
		T: y = 0 - 0
		T: y = 1 - 1
		T: y = 2 - -1
		T: y = 3 - 2
	*/
	for (int i = 0; i < 3; ++i) cout << "S: x = " << i << " - " << bm.matching_x(i) << endl;
	for (int i = 0; i < 4; ++i) cout << "T: y = " << i << " - " << bm.matching_y(i) << endl;
}
```

<br>

# 参考

2021/03/13: [https://manabitimes.jp/math/1147](https://manabitimes.jp/math/1147)  
2020/03/05: [https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching](https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching)  
2020/08/26: [https://snuke.hatenablog.com/entry/2019/05/07/013609](https://snuke.hatenablog.com/entry/2019/05/07/013609)  

<br>