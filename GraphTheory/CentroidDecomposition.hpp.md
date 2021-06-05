---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CentroidDecomposition.test.cpp
    title: Test/CentroidDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform.test.cpp
    title: Test/FastFourierTransform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp
  bundledCode: "#line 1 \"GraphTheory/CentroidDecomposition.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp\r\n\
    \ */\r\nstruct CentroidDecomposition {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<bool> done_;\r\n\tstd::vector<int>\
    \ sz;\r\n\t\r\npublic:\r\n\texplicit CentroidDecomposition(const Graph & g) :\
    \ n(g.size()), done_(size(), false), sz(size(), 0) {\r\n\t\tfor (int i = 0; i\
    \ < size(); ++i) for (int j : g[i]) assert(0 <= j && j < size());\r\n\t}\r\n\t\
    \r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool exist(int\
    \ u) const noexcept {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn !done_[u];\r\
    \n\t}\r\n\t\r\n\tstd::vector<int> centroids(const Graph & g, int root) {\r\n\t\
    \tassert(0 <= root && root < size());\r\n\t\tassert(exist(root));\r\n\t\tauto\
    \ dfs = [&](auto self, int u, int p) -> void {\r\n\t\t\tsz[u] = 1;\r\n\t\t\tfor\
    \ (auto v : g[u]) if (v != p && exist(v)) self(self, v, u), sz[u] += sz[v];\r\n\
    \t\t};\r\n\t\tdfs(dfs, root, -1);\r\n\t\tint u = root, p = -1;\r\n\t\tstd::vector<int>\
    \ res;\r\n\t\twhile (true) {\r\n\t\t\tbool update = false;\r\n\t\t\tfor (auto\
    \ v : g[u]) {\r\n\t\t\t\tif (v == p || !exist(v)) continue;\r\n\t\t\t\tif (sz[v]\
    \ * 2 > sz[root]) { p = u; u = v; update = true; break; }\r\n\t\t\t\tif (sz[v]\
    \ * 2 == sz[root]) res.emplace_back(v);\r\n\t\t\t}\r\n\t\t\tif (update) continue;\r\
    \n\t\t\tres.emplace_back(u);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tvoid done(int v) noexcept {\r\n\t\tassert(0 <= v && v < size());\r\
    \n\t\tdone_[v] = true;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tstd::fill(begin(done_),\
    \ end(done_), false);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP\r\n#define INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp\r\
    \n */\r\nstruct CentroidDecomposition {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<bool> done_;\r\n\tstd::vector<int>\
    \ sz;\r\n\t\r\npublic:\r\n\texplicit CentroidDecomposition(const Graph & g) :\
    \ n(g.size()), done_(size(), false), sz(size(), 0) {\r\n\t\tfor (int i = 0; i\
    \ < size(); ++i) for (int j : g[i]) assert(0 <= j && j < size());\r\n\t}\r\n\t\
    \r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool exist(int\
    \ u) const noexcept {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn !done_[u];\r\
    \n\t}\r\n\t\r\n\tstd::vector<int> centroids(const Graph & g, int root) {\r\n\t\
    \tassert(0 <= root && root < size());\r\n\t\tassert(exist(root));\r\n\t\tauto\
    \ dfs = [&](auto self, int u, int p) -> void {\r\n\t\t\tsz[u] = 1;\r\n\t\t\tfor\
    \ (auto v : g[u]) if (v != p && exist(v)) self(self, v, u), sz[u] += sz[v];\r\n\
    \t\t};\r\n\t\tdfs(dfs, root, -1);\r\n\t\tint u = root, p = -1;\r\n\t\tstd::vector<int>\
    \ res;\r\n\t\twhile (true) {\r\n\t\t\tbool update = false;\r\n\t\t\tfor (auto\
    \ v : g[u]) {\r\n\t\t\t\tif (v == p || !exist(v)) continue;\r\n\t\t\t\tif (sz[v]\
    \ * 2 > sz[root]) { p = u; u = v; update = true; break; }\r\n\t\t\t\tif (sz[v]\
    \ * 2 == sz[root]) res.emplace_back(v);\r\n\t\t\t}\r\n\t\t\tif (update) continue;\r\
    \n\t\t\tres.emplace_back(u);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tvoid done(int v) noexcept {\r\n\t\tassert(0 <= v && v < size());\r\
    \n\t\tdone_[v] = true;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tstd::fill(begin(done_),\
    \ end(done_), false);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/CentroidDecomposition.hpp
  requiredBy: []
  timestamp: '2021-03-15 16:06:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform.test.cpp
  - Test/CentroidDecomposition.test.cpp
documentation_of: GraphTheory/CentroidDecomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3"
---

# 概要

木の重心を、頂点数を $N$ として $\mathcal{O}(N)$ で求めます。
木の重心についてはページ下部にある参考リンク先を参照してください。  

- `CentroidDecomposition(const Graph & g)`
	- $\Theta(N)$ 木 `g` で初期化
- `int size()`
	- $\Theta(1)$ 木の頂点数 $N$ を返す
- `bool exist(int u)`
	- $\Theta(1)$ 頂点 $u$ が存在しているなら $true$ 、削除されているなら $false$ を返す
- `std::vector<int> centroids(const Graph & g, int root)`
	- 頂点 `root` を根とした木に含まれる頂点数を $n$ として $\mathcal{O}(n)$ 頂点 `root` を根とした木の重心を返す
- `void done(int v)`
	- $\Theta(1)$ 頂点 $v$ を削除
- `void clear()`
	- $\Theta(1)$ 削除した頂点をすべて元に戻す

<br>

# コンストラクタ

木の頂点数を $N$ とします。  

---

### CentroidDecomposition(const Graph & g)

木 `g` で初期化します。  

**制約**

- `g` は木

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

### int size()

木の頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### bool exist(int u)

頂点 $u$ が存在しているなら $true$ 、削除されているなら $false$ を返します。  

**制約**

- $0 \leq u < N$

**計算量**

- $\Theta(1)$

---

### std::vector&lt;int&gt; centroids(const Graph & g, int root)

頂点 `root` を根とした木の重心を返します。

**制約**

- `g` はコンストラクタで渡したものと同一
- $0 \leq$ `root` $< N$
- `root` は削除されていない

**計算量**

- 頂点 `root` を根とした木に含まれる頂点数を $n$ として $\mathcal{O}(n)$

---

### void done(int v)

頂点 $v$ を削除します。

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### void clear()

削除した頂点をすべて元に戻します。

**計算量**

- $\Theta(1)$

---

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/CentroidDecomposition.hpp"
using namespace std;

int main() {
	CentroidDecomposition::Graph g(8);
	auto add_edge = [&](int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	};
	
	//         0
	//    1        4
	// 2    3         5
	//              6   7
	add_edge(0, 1);
	add_edge(0, 4);
	add_edge(1, 2);
	add_edge(1, 3);
	add_edge(4, 5);
	add_edge(5, 6);
	add_edge(5, 7);
	
	CentroidDecomposition cd(g);
	
	auto output_centroids = [&](int root) {
		auto centroids = cd.centroids(g, root);
		cout << "centroids = ";
		for (int i = 0; i < centroids.size(); ++i) cout << centroids[i] << " \n"[i + 1 == centroids.size()];
	};
	
	output_centroids(0); // 4 0
	cd.done(0);
	output_centroids(4); // 5
	output_centroids(1); // 1
	output_centroids(3); // 1
	cd.done(1);
	output_centroids(3); // 3
	
	cd.clear();
	output_centroids(3); // 4 0
}
```

重心分解を再帰的に行い、重心を頂点として各部分木の重心に辺を張ったグラフを作成する実装例です。
計算量は $\mathcal{O}(N\log{N})$ です。  

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/CentroidDecomposition.hpp"
using namespace std;

#include <utility>
#include <cassert>

namespace tk {
template<typename CD>
std::pair<int, typename CD::Graph> centroid_decomposition_tree(const typename CD::Graph & g) {
	assert(!g.empty());
	CD cd(g);
	typename CD::Graph res(g.size());
	auto dfs = [&](auto self, int centroid) -> void {
		cd.done(centroid);
		for (auto r : g[centroid]) {
			if (!cd.exist(r)) continue;
			auto nex_cent = cd.centroids(g, r)[0];
			res[centroid].emplace_back(nex_cent);
			self(self, nex_cent);
		}
	};
	int root = cd.centroids(g, 0)[0];
	dfs(dfs, root);
	return {root, res};
}
} // namespace tk

int main() {
	CentroidDecomposition::Graph g(8);
	auto add_edge = [&](int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	};
	
	//         0
	//    1        4
	// 2    3         5
	//              6   7
	add_edge(0, 1);
	add_edge(0, 4);
	add_edge(1, 2);
	add_edge(1, 3);
	add_edge(4, 5);
	add_edge(5, 6);
	add_edge(5, 7);
	
	auto [root, cdg] = tk::centroid_decomposition_tree<CentroidDecomposition>(g);
	cout << "root = " << root << endl; // 4
	/*
		i = 0 : 
		i = 1 : 0 2 3 
		i = 2 :
		i = 3 :
		i = 4 : 1 5
		i = 5 : 6 7
		i = 6 :
		i = 7 :
	*/
	//         4
	//    1        5
	// 2  3  0    6  7
	for (int i = 0; i < cdg.size(); ++i) {
		cout << "i = " << i << " : ";
		for (int j : cdg[i]) cout << j << " ";
		cout << '\n';
	}
}
```

<br>

# 参考

2020/09/02: [https://ferin-tech.hatenablog.com/entry/2020/03/06/162311](https://ferin-tech.hatenablog.com/entry/2020/03/06/162311)  
2020/09/02: [https://qiita.com/drken/items/4b4c3f1824339b090202](https://qiita.com/drken/items/4b4c3f1824339b090202)  

<br>