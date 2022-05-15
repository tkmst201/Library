---
title: 最近共通祖先 (LCA)
documentation_of: //GraphTheory/LowestCommonAncestor.hpp
---

# 概要

頂点数 $N$ の木で任意の $2$ 頂点の最近共通祖先を事前計算 $\Theta(N \log{N})$ クエリ $\Theta(\log{N})$ で求めることのできるライブラリです。  
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
- $0 \le N$
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