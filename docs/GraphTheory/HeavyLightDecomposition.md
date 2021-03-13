---
title: 重軽分解 ( HL 分解)
documentation_of: //GraphTheory/HeavyLightDecomposition.hpp
---

# 概要

森に含まれる各木に対して重軽分解とオイラーツアーを行います。
おまけで任意の $2$ 頂点の LCA を空間 $\Theta(N\log{\log{N}})$ クエリ $\mathcal{O}(\log{\log{N}})$ で求めることもできます。  
重軽分解についてはページ下部にある参考リンク先を参照してください。  

- `HeavyLightDecomposition(const Graph & g, bool LCA = false)`
	- `LCA` $= false$ : $\Theta(N)$, `LCA` $= true$ : $\mathcal{O}(N \log{\log{N}})$ `g` の各木に対して重軽分解とオイラーツアーを行う
- `HeavyLightDecomposition(const Graph & g, int root, bool LCA = false)`
	- `LCA` $= false$ : $\Theta(N)$, `LCA` $= true$ : $\mathcal{O}(N \log{\log{N}})$  頂点 `root` を根とした根付き木 `g` に対して重軽分解とオイラーツアーを行う
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `int par(int v)`
	- $\Theta(1)$ 頂点 $v$ の親を返す
- `int tree_id(int v)`
	- $\Theta(1)$ 頂点 $v$ が属する木の ID を返す
- `int tree_cnt()`
	- $\Theta(1)$ グラフ `g` に含まれる木の個数を返す
- `int trees()`
	- $\Theta(1)$ グラフ `g` に含まれる木の根を ID の昇順に返す
- `int heavy(int v)`
	- $\Theta(1)$ 頂点 `v` が属する heavy-edge の ID を返す
- `int head(int k)`
	- $\Theta(1)$ heavy-edge `k` に含まれる頂点の内、最も根側の頂点番号を返す
- `int heavy_size()`
	- $\Theta(1)$ heavy-edge の本数を返す
- `int heavy_size(int k)`
	- $\Theta(1)$ heavy-edge `k` に含まれるの頂点数を返す
- `int heavy_depth(int k)`
	- $\Theta(1)$ heavy-edge `k` から根が属する heavy-edge 間のパス上に含まれる heavy-edge の個数 $-1$ を返す
- `int in(int v)`
	- $\Theta(1)$ 頂点 `v` に入ったときの時刻を返す
- `int out(int v)`
	- $\Theta(1)$ 頂点 `v` から出たときの時刻を返す
- `const std::vector<std::vector<int>> & par_dblng()`
	- $\Theta(1)$ $[i][j] :=$ heavy-edge $j$ から $2^i$ 回根方向に heavy-edge を登ったすぐの頂点番号(存在しなければ根の番号)
- `std::pair<int, int> lca_heavy(int x, int y)`
	- $\mathcal{O}(\log{\log{N}})$ 頂点 $x, y$ から根側に移動して同じ heavy-edge 内となるような最も移動回数の和が小さい頂点位置の組を返す
- `lca(int x, int y)`
	- $\mathcal{O}(\log{\log{N}})$ 頂点 $x, y$ の最近共通祖先を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  

---

### HeavyLightDecomposition(const Graph & g, bool LCA = false)

根を指定せずに `g` の各木に対して重軽分解とオイラーツアーを行います。
根はその木に含まれる最小の番号の頂点となります。
LCA を求めたい場合は、`LCA` $= true$ を指定してください。  

**制約**

- `g` は森

**計算量**

- `LCA` $= false$ : $\Theta(N)$
- `LCA` $= true$  : $\mathcal{O}(N \log{\log{N}})$

---

### HeavyLightDecomposition(const Graph & g, int root, bool LCA = false)

頂点 `root` を根とした根付き木 `g` に対して重軽分解とオイラーツアーを行います。
LCA を求めたい場合は、`LCA` $= true$ を指定してください。  

**制約**

- `g` は木

**計算量**

- `LCA` $= false$ : $\Theta(N)$
- `LCA` $= true$  : $\mathcal{O}(N \log{\log{N}})$

---

<br>

# メンバ関数

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int par(int v)

頂点 $v$ の親を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int tree_id(int v)

頂点 $v$ が属する木の ID を返します。
ID は各木に対して $0$ から順に割り振られます。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int tree_cnt()

グラフ `g` に含まれる木の個数を返します。  

**計算量**

- $\Theta(1)$

---

### int trees()

グラフ `g` に含まれる木の根を ID の昇順に返します。  

**計算量**

- $\Theta(1)$

---

### int heavy(int v)

頂点 `v` が属する heavy-edge の ID を返します。  
ID は各 heavy-edge に対して $0$ から順に割り振られます。  

**計算量**

- $\Theta(1)$

---

### int head(int k)

heavy-edge `k` に含まれる頂点の内、最も根側の頂点番号を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int heavy_size()

heavy-edge の本数を返します。  

**計算量**

- $\Theta(1)$

---

### int heavy_size(int k)

heavy-edge `k` に含まれるの頂点数を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int heavy_depth(int k)

heavy-edge `k` から根が属する heavy-edge 間のパス上に含まれる heavy-edge の個数 $-1$ を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int in(int v)

頂点 `v` に入ったときの時刻を返します。
ただし、時刻は頂点に到達した際に増加します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int out(int v)

頂点 `v` から出たときの時刻を返します。
ただし、時刻は頂点に到達した際に増加します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### const std::vector&lt;std::vector&lt;int&gt;&gt; & par_dblng()

次のようなテーブルを返します。

- $[i][j] :=$ heavy-edge $j$ から $2^i$ 回根方向に heavy-edge を登ったすぐの頂点番号(存在しなければ根の番号)

**制約**

- `LCA` $= true$

**計算量**

- $\Theta(1)$

---

### std::pair&lt;int, int&gt; lca_heavy(int x, int y)

頂点 $x, y$ から根側に移動して同じ heavy-edge 内となるような最も移動回数の和が小さい頂点位置の組を返します。  

**制約**

- `LCA` $= true$
- $0 \leq x, y < N$
- $x, y$ は同じ木に属する

**計算量**

- $\mathcal{O}(\log{\log{N}})$

---

### lca(int x, int y)

頂点 $x, y$ の最近共通祖先を返します。  

**制約**

- `LCA` $= true$
- $0 \leq x, y < N$
- $x, y$ は同じ木に属する

**計算量**

- $\mathcal{O}(\log{\log{N}})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <GraphTheory/HeavyLightDecomposition.hpp>
using namespace std;

int main() {
	HeavyLightDecomposition::Graph g(9);
	//            1
	//       2        3
	//    0     4         5
	// 6       7 8
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[0].emplace_back(6);
	g[4].emplace_back(7);
	g[4].emplace_back(8);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	HeavyLightDecomposition hld(g, 1, true);
	
	cout << "size() = " << hld.size() << endl; // 9
	cout << "heavy_size() = " << hld.heavy_size() << endl; // 4
	cout << "par: ";
	// 2 -1 1 1 2 3 0 4 4
	for (int i = 0; i < hld.size(); ++i) cout << hld.par(i) << " \n"[i + 1 == hld.size()];
	
	cout << "heavy: ";
	// 1 0 0 3 0 3 1 0 2
	for (int i = 0; i < hld.size(); ++i) cout << hld.heavy(i) << " \n"[i + 1 == hld.size()];
	// heavy 0 : [1, 2, 4, 8]
	// heavy 1 : [0, 6]
	// heavy 2 : [8]
	// heavy 3 : [3, 5]
	//           heavy-0
	// heavy-1   heavy-2   heavy-3
	cout << "head: ";
	// 1 0 8 3
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.head(i) << " \n"[i + 1 == hld.heavy_size()];
	cout << "heavy_size: ";
	// 4 2 1 2
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.heavy_size(i) << " \n"[i + 1 == hld.heavy_size()];
	cout << "heavy_size: ";
	// 0 1 1 1
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.heavy_depth(i) << " \n"[i + 1 == hld.heavy_size()];
	
	cout << "in: ";
	// 5 0 1 7 2 8 6 3 4
	for (int i = 0; i < hld.size(); ++i) cout << hld.in(i) << " \n"[i + 1 == hld.size()];
	cout << "out: ";
	// 7 9 7 9 5 9 7 4 5
	for (int i = 0; i < hld.size(); ++i) cout << hld.out(i) << " \n"[i + 1 == hld.size()];
	
	{
		auto [x, y] = hld.lca_heavy(1, 4);
		cout << "lca_heavy(1, 4) = (" << x << ", " << y << ")\n"; // (1, 4)
	}
	{
		auto [x, y] = hld.lca_heavy(2, 6);
		cout << "lca_heavy(2, 6) = (" << x << ", " << y << ")\n"; // (2, 2)
	}
	{
		auto [x, y] = hld.lca_heavy(6, 5);
		cout << "lca_heavy(6, 5) = (" << x << ", " << y << ")\n"; // (2, 1)
	}
	
	cout << "lca(2, 3) = " << hld.lca(2, 3) << endl; // 1
	cout << "lca(6, 8) = " << hld.lca(6, 8) << endl; // 2
	cout << "lca(4, 8) = " << hld.lca(4, 8) << endl; // 4
}
```

<br>

# 参考

2020/04/19: [https://qiita.com/ageprocpp/items/8dfe768218da83314989](https://qiita.com/ageprocpp/items/8dfe768218da83314989)  
2020/04/19: [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)  
2020/09/18: [https://codeforces.com/blog/entry/53170](https://codeforces.com/blog/entry/53170)  

<br>