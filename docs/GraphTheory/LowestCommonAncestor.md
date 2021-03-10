---
title: 最近共通祖先 (LCA)
documentation_of: //GraphTheory/LowestCommonAncestor.hpp
---

# 概要

頂点数を $N$ の木で任意の $2$ 点の最近共通祖先を事前計算 $\Theta(N \log{N})$ クエリ $\Theta(\log{N})$ で求めることのできるライブラリです。  
実は [HL 分解](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) を用いた LCA の方が高速です(事前計算 $\Theta(N\log{\log{N}})$ クエリ $\Theta(\log{\log{N}})$ )。  

- `LowestCommonAncestor(size_t n)`
	- $\Theta(n)$ $n$ 頂点のグラフで初期化
- `LowestCommonAncestor(const Graph & g)`
	- $\Theta(\|$`g`$\|)$ グラフ $g$ で初期化
- `size_t size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `const Graph & get_graph()`
	- $\Theta(1)$ グラフを返す
- `void add_edge(int u, int v)`
	- ならし $\Theta(1)$ 頂点 $u$ と頂点 $v$ の間に無向辺を張る
- `void add_directed_edge(int u, int v)`
	- ならし $\Theta(1)$ 頂点 $u$ から頂点 $v$ に有向辺を張る
- `void clear()`
	- $\Theta(N \log{N})$ グラフや事前計算テーブルを削除
- `void build(int root = 0)`
	- 時間/空間 $\Theta(N \log{N})$ `root` を根とした根付き木として事前計算を行う
- `int find(int a, int b)`
	- $\Theta(\log{N})$ 頂点 $a$, $b$ の最近共通祖先を返す
- `int parent(int u, int k = 1)`
	- $\Theta(\log{N})$ 頂点 $u$ の $k$ 回根方向に辺をたどった頂点を返す
- `int depth(int u)`
	- $\Theta(1)$ 頂点 $u$ から根までのパス上にある辺の個数を返す

<br>

# コンストラクタ

### LowestCommonAncestor(size_t n)

$n$ 頂点のグラフで初期化します。  

**計算量**

- $\Theta(n)$

---

### LowestCommonAncestor(const Graph & g)

グラフ $g$ で初期化します。  

**計算量**

- $\Theta(\|$`g`$\|)$

---

<br>

# メンバ関数

以下、グラフの頂点数を $N$ とします。  

---

### size_t size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### const Graph & get_graph()

グラフを返します。  

**計算量**

- $\Theta(1)$

---

### void add_edge(int u, int v)

頂点 $u$ と頂点 $v$ の間に無向辺を張ります。  

**制約**

- $0 \leq u, v < N$

**計算量**

- ならし $\Theta(1)$

---

### void add_directed_edge(int u, int v)

頂点 $u$ から頂点 $v$ に有向辺を張ります。  

**制約**

- $0 \leq u, v < N$

**計算量**

- ならし $\Theta(1)$

---

### void clear()

グラフや事前計算テーブルを削除します。  

**計算量**

- $\Theta(N \log{N})$

---

### void build(int root = 0)

`root` を根とした根付き木として事前計算を行います。  

**制約**

- $0 \leq$ `root` $< size()$
- グラフは木

**計算量**

- 時間/空間 $\Theta(N \log{N})$

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
#include <GraphTheory/LowestCommonAncestor.hpp>
using namespace std;

int main() {
	LowestCommonAncestor lca(6);
	//         1
	//    2        3
	// 0    4          5
	lca.add_edge(1, 2);
	lca.add_edge(2, 0);
	lca.add_edge(4, 2);
	lca.add_edge(1, 3);
	lca.add_edge(3, 5);
	
	lca.build(1); // 必ず呼ぶ
	
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
	
	
	lca.clear();
	cout << "size() = " << lca.size() << endl; // 0
}
```

<br>