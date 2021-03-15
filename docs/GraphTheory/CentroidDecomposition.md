---
title: 重心分解
documentation_of: //GraphTheory/CentroidDecomposition.hpp
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

namespace tk {
template<typename CD>
std::pair<int, typename CD::Graph> centroid_decomposition_tree(const typename CD::Graph & g) {
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