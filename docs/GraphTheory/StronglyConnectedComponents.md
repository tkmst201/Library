---
title: 強連結成分分解 (SCC)
documentation_of: //GraphTheory/StronglyConnectedComponents.hpp
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