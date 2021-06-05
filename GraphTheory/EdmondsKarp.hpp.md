---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/EdmondsKarp.test.cpp
    title: Test/EdmondsKarp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp
  bundledCode: "#line 1 \"GraphTheory/EdmondsKarp.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <queue>\r\n#include <utility>\r\n#include <type_traits>\r\
    \n#include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct EdmondsKarp {\r\n\tusing cap_type = T;\r\
    \n\t\r\nprivate:\r\n\tstatic constexpr cap_type EPS = std::is_floating_point<cap_type>()\
    \ ? 1e-8 : 0;\r\n\tstruct Edge {\r\n\t\tint to, rev;\r\n\t\tcap_type c;\r\n\t\t\
    Edge(int to, int rev, const cap_type & c) : to(to), rev(rev), c(c) {}\r\n\t};\r\
    \n\tusing Graph = std::vector<std::vector<Edge>>;\r\n\tGraph g;\r\n\t\r\npublic:\r\
    \n\texplicit EdmondsKarp(int n) : g(n) {}\r\n\t\r\n\tint size() const noexcept\
    \ {\r\n\t\treturn g.size();\r\n\t}\r\n\t\r\n\tvoid add_edge(int u, int v, const\
    \ cap_type & cap) {\r\n\t\tassert(0 <= u && u < size());\r\n\t\tassert(0 <= v\
    \ && v < size());\r\n\t\tassert(cap >= 0);\r\n\t\tg[u].emplace_back(v, g[v].size(),\
    \ cap);\r\n\t\tg[v].emplace_back(u, g[u].size() - 1, 0);\r\n\t}\r\n\t\r\n\tcap_type\
    \ max_flow(int s, int t) {\r\n\t\tassert(0 <= s && s < size());\r\n\t\tassert(0\
    \ <= t && t < size());\r\n\t\tassert(s != t);\r\n\t\tcap_type res = 0;\r\n\t\t\
    std::vector<std::pair<int, int>> prv(size(), std::make_pair(-1, -1));\r\n\t\t\
    while (true) {\r\n\t\t\tstd::vector<int> visited;\r\n\t\t\tstd::queue<int> que;\r\
    \n\t\t\tprv[s].first = s;\r\n\t\t\tvisited.emplace_back(s);\r\n\t\t\tque.emplace(s);\r\
    \n\t\t\twhile (!que.empty() && prv[t].first == -1) {\r\n\t\t\t\tconst int u =\
    \ que.front();\r\n\t\t\t\tque.pop();\r\n\t\t\t\tfor (int i = 0; i < static_cast<int>(g[u].size());\
    \ ++i) {\r\n\t\t\t\t\tconst int to = g[u][i].to;\r\n\t\t\t\t\tif (prv[to].first\
    \ != -1 || g[u][i].c <= EPS) continue;\r\n\t\t\t\t\tprv[to] = {u, i};\r\n\t\t\t\
    \t\tvisited.emplace_back(to);\r\n\t\t\t\t\tif (to == t) break;\r\n\t\t\t\t\tque.emplace(to);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (prv[t].first == -1) break;\r\n\t\t\tcap_type\
    \ flow = g[prv[t].first][prv[t].second].c;\r\n\t\t\tfor (int u = prv[t].first;\
    \ u != prv[u].first; u = prv[u].first) {\r\n\t\t\t\tflow = std::min(flow, g[prv[u].first][prv[u].second].c);\r\
    \n\t\t\t}\r\n\t\t\tfor (int u = t; u != prv[u].first; u = prv[u].first) {\r\n\t\
    \t\t\tconst auto [v, eidx] = prv[u];\r\n\t\t\t\tg[v][eidx].c -= flow;\r\n\t\t\t\
    \tg[u][g[v][eidx].rev].c += flow;\r\n\t\t\t}\r\n\t\t\tfor (int u : visited) prv[u]\
    \ = {-1, -1};\r\n\t\t\tres += flow;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\
    \n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_EDMONDS_KARP_HPP\r\n#define INCLUDE_GUARD_EDMONDS_KARP_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <queue>\r\n#include\
    \ <utility>\r\n#include <type_traits>\r\n#include <algorithm>\r\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp\r\n */\r\
    \ntemplate<typename T>\r\nstruct EdmondsKarp {\r\n\tusing cap_type = T;\r\n\t\r\
    \nprivate:\r\n\tstatic constexpr cap_type EPS = std::is_floating_point<cap_type>()\
    \ ? 1e-8 : 0;\r\n\tstruct Edge {\r\n\t\tint to, rev;\r\n\t\tcap_type c;\r\n\t\t\
    Edge(int to, int rev, const cap_type & c) : to(to), rev(rev), c(c) {}\r\n\t};\r\
    \n\tusing Graph = std::vector<std::vector<Edge>>;\r\n\tGraph g;\r\n\t\r\npublic:\r\
    \n\texplicit EdmondsKarp(int n) : g(n) {}\r\n\t\r\n\tint size() const noexcept\
    \ {\r\n\t\treturn g.size();\r\n\t}\r\n\t\r\n\tvoid add_edge(int u, int v, const\
    \ cap_type & cap) {\r\n\t\tassert(0 <= u && u < size());\r\n\t\tassert(0 <= v\
    \ && v < size());\r\n\t\tassert(cap >= 0);\r\n\t\tg[u].emplace_back(v, g[v].size(),\
    \ cap);\r\n\t\tg[v].emplace_back(u, g[u].size() - 1, 0);\r\n\t}\r\n\t\r\n\tcap_type\
    \ max_flow(int s, int t) {\r\n\t\tassert(0 <= s && s < size());\r\n\t\tassert(0\
    \ <= t && t < size());\r\n\t\tassert(s != t);\r\n\t\tcap_type res = 0;\r\n\t\t\
    std::vector<std::pair<int, int>> prv(size(), std::make_pair(-1, -1));\r\n\t\t\
    while (true) {\r\n\t\t\tstd::vector<int> visited;\r\n\t\t\tstd::queue<int> que;\r\
    \n\t\t\tprv[s].first = s;\r\n\t\t\tvisited.emplace_back(s);\r\n\t\t\tque.emplace(s);\r\
    \n\t\t\twhile (!que.empty() && prv[t].first == -1) {\r\n\t\t\t\tconst int u =\
    \ que.front();\r\n\t\t\t\tque.pop();\r\n\t\t\t\tfor (int i = 0; i < static_cast<int>(g[u].size());\
    \ ++i) {\r\n\t\t\t\t\tconst int to = g[u][i].to;\r\n\t\t\t\t\tif (prv[to].first\
    \ != -1 || g[u][i].c <= EPS) continue;\r\n\t\t\t\t\tprv[to] = {u, i};\r\n\t\t\t\
    \t\tvisited.emplace_back(to);\r\n\t\t\t\t\tif (to == t) break;\r\n\t\t\t\t\tque.emplace(to);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (prv[t].first == -1) break;\r\n\t\t\tcap_type\
    \ flow = g[prv[t].first][prv[t].second].c;\r\n\t\t\tfor (int u = prv[t].first;\
    \ u != prv[u].first; u = prv[u].first) {\r\n\t\t\t\tflow = std::min(flow, g[prv[u].first][prv[u].second].c);\r\
    \n\t\t\t}\r\n\t\t\tfor (int u = t; u != prv[u].first; u = prv[u].first) {\r\n\t\
    \t\t\tconst auto [v, eidx] = prv[u];\r\n\t\t\t\tg[v][eidx].c -= flow;\r\n\t\t\t\
    \tg[u][g[v][eidx].rev].c += flow;\r\n\t\t\t}\r\n\t\t\tfor (int u : visited) prv[u]\
    \ = {-1, -1};\r\n\t\t\tres += flow;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\
    \n\r\n#endif // INCLUDE_GUARD_EDMONDS_KARP_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/EdmondsKarp.hpp
  requiredBy: []
  timestamp: '2021-03-16 16:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/EdmondsKarp.test.cpp
documentation_of: GraphTheory/EdmondsKarp.hpp
layout: document
title: "\u6700\u5927\u6D41 (Edmonds-Karp)"
---

# 概要

容量付きの有向グラフにおいて、任意の $2$ 頂点 $s, t$ に対する $s-t$ フローの最大値を求めます。  
計算量は、頂点数を $N$ 、辺の数を $M$ として $\mathcal{O}(NM^2)$ です。  
より高速で使い勝手の良い [AC Library](https://github.com/atcoder/ac-library) の `maxflow` を使用したほうが良いです。  

- `EdmondsKarp(int n)`
	- $\Theta(n)$ 頂点数 $n$ のグラフで初期化する
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `void add_edge(int u, int v const T & cap)`
	- ならし $\Theta(1)$ 頂点 $u$ から頂点 $v$ へ容量 $cap$ の有向辺を張る
- `T max_flow(int s, int t)`
	- $\mathcal{O}(NM^2)$ $s-t$ フローの最大値を返す

<br>

# コンストラクタ

### EdmondsKarp(int n)

頂点数 $n$ のグラフで初期化します。
`T` には容量の型を指定してください。  

**制約**

- $0 \leq n$
- `T` は `int`, `unsigned int`, `long long int`, `unsigned long long`, `float`, `double`

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、頂点数を $N$ 、辺の数を $M$ とします。  

---

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void add_edge(int u, int v const T & cap)

頂点 $u$ から頂点 $v$ へ容量 $cap$ の有向辺を張ります。  

**制約**

- $0 \leq u, v < N$
- $0 \leq cap$

**計算量**

- ならし $\Theta(1)$

### T max_flow(int s, int t)

$s-t$ フローの最大値を返します。
この関数を $2$ 回以上呼んだ場合の動作は未定義です。  

**制約**

- $0 \leq u, v < N$
- $u \neq v$

**計算量**

- $\mathcal{O}(NM^2)$

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/EdmondsKarp.hpp"
using namespace std;

int main() {
	EdmondsKarp<int> ek(5);
	cout << "size() = " << ek.size() << endl; // 5
	ek.add_edge(0, 1, 2);
	ek.add_edge(0, 2, 3);
	ek.add_edge(1, 2, 2);
	ek.add_edge(1, 4, 1);
	ek.add_edge(2, 4, 3);
	cout << "max_flow(0, 4) = " << ek.max_flow(0, 4) << endl; // 4
}
```

<br>

# 参考

2020/02/27: [http://hos.ac/slides/20150319_flow.pdf](http://hos.ac/slides/20150319_flow.pdf)  

<br>