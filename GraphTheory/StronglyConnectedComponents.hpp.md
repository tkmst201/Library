---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mathematics/TwoSat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/StronglyConnectedComponents.test.cpp
    title: Test/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/TwoSat.test.cpp
    title: Test/TwoSat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp
  bundledCode: "#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\n\n\n\r\n\
    #include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp\r\
    \n */\r\nstruct StronglyConnectedComponents {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<int> rank_;\r\n\tstd::vector<std::vector<int>>\
    \ rank_list_;\r\n\t\r\npublic:\r\n\texplicit StronglyConnectedComponents(const\
    \ Graph & g) : n(g.size()) {\r\n\t\tGraph rg(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\t\tfor (int j : g[i]) {\r\n\t\t\t\tassert(0 <= j && j < n);\r\n\
    \t\t\t\trg[j].emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool> visited(n,\
    \ false);\r\n\t\tstd::vector<int> num;\r\n\t\tauto dfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\tfor (int v : g[u]) if (!visited[v])\
    \ self(self, v);\r\n\t\t\tnum.emplace_back(u);\r\n\t\t};\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) if (!visited[i]) dfs(dfs, i);\r\n\t\tint cnt = 0;\r\n\t\tvisited.assign(n,\
    \ false);\r\n\t\trank_.assign(n, -1);\r\n\t\tauto rdfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank_[u] = cnt;\r\n\t\t\tfor\
    \ (int v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\tfor (int i\
    \ = n - 1; i >= 0; --i) if (!visited[num[i]]) rdfs(rdfs, num[i]), ++cnt;\r\n\t\
    \trank_list_.assign(cnt, {});\r\n\t\tfor (int i = 0; i < n; ++i) rank_list_[rank_[i]].emplace_back(i);\r\
    \n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\
    \tint scc_size() const noexcept {\r\n\t\treturn rank_list_.size();\r\n\t}\r\n\t\
    \r\n\tint scc_size(int k) const noexcept {\r\n\t\tassert(0 <= k && k < scc_size());\r\
    \n\t\treturn rank_list_[k].size();\r\n\t}\r\n\t\r\n\tint rank(int u) const noexcept\
    \ {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn rank_[u];\r\n\t}\r\n\t\r\
    \n\tconst std::vector<int> & rank_list(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < scc_size());\r\n\t\treturn rank_list_[k];\r\n\t}\r\n\t\r\n\tGraph\
    \ get_graph(const Graph & g) const {\r\n\t\tGraph res(scc_size());\r\n\t\tfor\
    \ (int i = 0; i < scc_size(); ++i) {\r\n\t\t\tfor (int j : rank_list_[i]) for\
    \ (int v : g[j]) if (rank(v) != i) res[i].emplace_back(rank(v));\r\n\t\t\tstd::sort(begin(res[i]),\
    \ end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP\r\n#define INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp\r\
    \n */\r\nstruct StronglyConnectedComponents {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<int> rank_;\r\n\tstd::vector<std::vector<int>>\
    \ rank_list_;\r\n\t\r\npublic:\r\n\texplicit StronglyConnectedComponents(const\
    \ Graph & g) : n(g.size()) {\r\n\t\tGraph rg(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\t\tfor (int j : g[i]) {\r\n\t\t\t\tassert(0 <= j && j < n);\r\n\
    \t\t\t\trg[j].emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool> visited(n,\
    \ false);\r\n\t\tstd::vector<int> num;\r\n\t\tauto dfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\tfor (int v : g[u]) if (!visited[v])\
    \ self(self, v);\r\n\t\t\tnum.emplace_back(u);\r\n\t\t};\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) if (!visited[i]) dfs(dfs, i);\r\n\t\tint cnt = 0;\r\n\t\tvisited.assign(n,\
    \ false);\r\n\t\trank_.assign(n, -1);\r\n\t\tauto rdfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank_[u] = cnt;\r\n\t\t\tfor\
    \ (int v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\tfor (int i\
    \ = n - 1; i >= 0; --i) if (!visited[num[i]]) rdfs(rdfs, num[i]), ++cnt;\r\n\t\
    \trank_list_.assign(cnt, {});\r\n\t\tfor (int i = 0; i < n; ++i) rank_list_[rank_[i]].emplace_back(i);\r\
    \n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\
    \tint scc_size() const noexcept {\r\n\t\treturn rank_list_.size();\r\n\t}\r\n\t\
    \r\n\tint scc_size(int k) const noexcept {\r\n\t\tassert(0 <= k && k < scc_size());\r\
    \n\t\treturn rank_list_[k].size();\r\n\t}\r\n\t\r\n\tint rank(int u) const noexcept\
    \ {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn rank_[u];\r\n\t}\r\n\t\r\
    \n\tconst std::vector<int> & rank_list(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < scc_size());\r\n\t\treturn rank_list_[k];\r\n\t}\r\n\t\r\n\tGraph\
    \ get_graph(const Graph & g) const {\r\n\t\tGraph res(scc_size());\r\n\t\tfor\
    \ (int i = 0; i < scc_size(); ++i) {\r\n\t\t\tfor (int j : rank_list_[i]) for\
    \ (int v : g[j]) if (rank(v) != i) res[i].emplace_back(rank(v));\r\n\t\t\tstd::sort(begin(res[i]),\
    \ end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/StronglyConnectedComponents.hpp
  requiredBy:
  - Mathematics/TwoSat.hpp
  timestamp: '2021-03-13 10:43:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/StronglyConnectedComponents.test.cpp
  - Test/TwoSat.test.cpp
documentation_of: GraphTheory/StronglyConnectedComponents.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
---

# 概要

有向グラフを強連結成分分解します。  
強連結成分分解についてはページ下部にある参考リンク先を参照してください。  

- `StronglyConnectedComponents(const Graph & g)`
	- $\Theta(N + M)$ グラフ `g` で初期化
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `int scc_size()`
	- $\Theta(1)$ 強連結成分の個数を返す
- `int scc_size(int k)`
	- $\Theta(1)$ トポロジカル順序 $k$ の強連結成分に含まれる頂点数を返す
- `int rank(int u)`
	- $\Theta(1)$ 頂点 $u$ が含まれる強連結成分のトポロジカル順序を返す
- `const std::vector<int> & rank_list(int k)`
	- $\Theta(1)$ トポロジカル順序 $k$ の強連結成分に含まれる頂点番号を昇順に格納した配列を返す
- `Graph get_graph(const Graph & g)`
	- $\mathcal{O}((N + M) \log{(N + M)})$ 強連結成分を $1$ つの頂点に縮約したグラフを返す


<br>

# コンストラクタ

以下、頂点数を $N$ 、辺の数を $M$ とします。

### StronglyConnectedComponents(const Graph & g)

グラフ `g` で初期化します。  

**計算量**

- $\Theta(N + M)$

---

<br>

# メンバ関数

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int scc_size()

強連結成分の個数を返します。  

**計算量**

- $\Theta(1)$

---

### int scc_size(int k)

トポロジカル順序 $k$ の強連結成分に含まれる頂点数を返します。
トポロジカル順序は $0$ からカウントされます。  

**制約**

- $0 \leq k <$ `scc_size()`

**計算量**

- $\Theta(1)$

---

### int rank(int u)

頂点 $u$ が含まれる強連結成分のトポロジカル順序を返します。  

**制約**

- $0 \leq u < N$

**計算量**

- $\Theta(1)$

---

### const std::vector&lt;int&gt; & rank_list(int k)

トポロジカル順序 $k$ の強連結成分に含まれる頂点番号を昇順に格納した配列を返します。  

**制約**

- $0 \leq k <$ `scc_size()`

**計算量**

- $\Theta(1)$

---

### Graph get_graph(const Graph & g)

強連結成分を $1$ つの頂点に縮約したグラフを返します。
各頂点の番号はその強連結成分のトポロジカル順序と一致します。  

**制約**

- `g` はコンストラクタに渡したものと同一

**計算量**

- $\mathcal{O}((N + M) \log{(N + M)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/StronglyConnectedComponents.hpp"
using namespace std;

int main() {
	StronglyConnectedComponents::Graph g(7);
	g[1].emplace_back(2);
	g[2].emplace_back(3);
	g[3].emplace_back(1);
	g[3].emplace_back(4);
	g[0].emplace_back(4);
	g[4].emplace_back(5);
	g[5].emplace_back(6);
	g[6].emplace_back(5);
	StronglyConnectedComponents scc(g);
	
	cout << "size() = " << scc.size() << endl; // 7
	cout << "scc_size() = " << scc.scc_size() << endl; // 4
	
	/*
		topological order 0 : 1 2 3
		topological order 1 : 0
		topological order 2 : 4
		topological order 3 : 5 6
	*/
	for (int i = 0; i < scc.scc_size(); ++i) {
		cout << "topological order " << i << " : ";
		for (int j = 0; j < scc.scc_size(i); ++j) cout << scc.rank_list(i)[j] << " \n"[j + 1 == scc.scc_size(i)];
	}
	
	cout << "rank : ";
	// 1 0 0 0 2 3 3
	for (int i = 0; i < scc.size(); ++i) cout << scc.rank(i) << " \n"[i + 1 == scc.size()];
	
	auto sccg = scc.get_graph(g);
	cout << "size = " << sccg.size() << endl; // 4
	/*
		i = 0 : 2
		i = 1 : 2
		i = 2 : 3
		i = 3 :
	*/
	for (int i = 0; i < sccg.size(); ++i) {
		cout << "i = " << i << " : ";
		for (int j = 0; j < sccg[i].size(); ++j) cout << sccg[i][j] << " \n"[j + 1 == sccg[i].size()];
	}
}
```

<br>

# TODO

TODO: low-link を用いたより速そうな処理に変更する

# 参考

2020/08/27: [https://mathtrain.jp/kyorenketsu](https://mathtrain.jp/kyorenketsu)  

<br>