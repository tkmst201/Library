---
title: 重軽分解 ( HL 分解) クエリ
documentation_of: //GraphTheory/HeavyLightDecomposition_Query.hpp
---

# 概要

[重軽分解 ( HL 分解)](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) と [セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) を用いて森上で 頂点数を $N$ として、$1$ 点更新を $\Theta(\log{N})$ 、パスクエリを $\mathcal{O}((\log{N})^2)$ 、部分木クエリを $\Theta(\log{N})$ で処理します。
詳しくは`使用例`をご覧ください。  

- `HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, const T & id_elem, const F & f)`
	- $\Theta(N)$ グラフ `g` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, int root, const T & id_elem, const F & f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, std::vector<U> & v, const T & id_elem, const F & f)`
	- $\Theta(N)$ グラフ `g` と初期値 `v` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, int root, std::vector<U> & v, const T & id_elem, const F & f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` と初期値 `v` で初期化
- `const HLD & get_hld()`
	- $\Theta(1)$ 内部で保持している HLD を返す
- `void set(int v, const T & x)`
	- $\Theta(\log{N})$ 頂点 $v$ に値 $x$ をセットする
- `void get(int v)`
	- $\Theta(1)$ 頂点 $v$ の値を返す
- `void set(int u, int v, const T & x)`
	- $\Theta(\log{N})$ 辺 $u-v$ に値 $x$ をセットする
- `void get(int u, int v)`
	- $\Theta(1)$ 辺 $u-v$ の値を返す
- `T fold(int u, int v)`
	- $\mathcal{O}((\log{N})^2)$ $u-v$ パスを畳み込んだ結果を返す
- `T subtree_sum(int v)`
	- $\mathcal{O}(\log{N})$ 部分木の総和を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  
`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `HLD` は [HeavyLightDecomposition](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp)
- `SEG` は [SegmentTree](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp)
- $(T, f,$ `id_elem`$)$ はモノイド
- `g` は森
- 頂点に値を持つ場合は `VERTEX` $= true$
- 辺に値を持つ場合は `VERTEX` $= false$

---

### HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, const T & id_elem, const F & f)

グラフ `g` で初期化します。
はじめ、すべての値は単位元です。  

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, int root, const T & id_elem, const F & f)

根 `root` の根付き木 `g` で初期化します。
はじめ、すべての値は単位元です。  

**制約**

- `g` は木

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, std::vector&lt;U&gt; & v, const T & id_elem, const F & f)

グラフ `g` と初期値 `v` で初期化します。
はじめ、頂点 $i$ の値は $v[i]$ です。  

**制約**

- $\|$`v`$\| = N$

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, int root, std::vector&lt;U&gt; & v, const T & id_elem, const F & f)

根 `root` の根付き木 `g` と初期値 `v` で初期化します。
はじめ、頂点 $i$ の値は $v[i]$ です。  

**制約**

- $\|$`v`$\| = N$

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

### const HLD & get_hld()

内部で保持している HLD を返します。  

**計算量**

- $\Theta(1)$

---

### void set(int v, const T & x)

頂点 $v$ に値 $x$ をセットします。  

**制約**

- `VERTEX` $= true$
- $0 \leq v < N$

**計算量**

- $\Theta(\log{N})$

---

### void get(int v)

頂点 $v$ の値を返します。  

**制約**

- `VERTEX` $= true$
- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### void set(int u, int v, const T & x)

辺 $u-v$ に値 $x$ をセットします。  

**制約**

- `VERTEX` $= false$
- $0 \leq u, v < N$

**計算量**

- $\Theta(\log{N})$

---

### void get(int u, int v)

辺 $u-v$ の値を返します。  

**制約**

- `VERTEX` $= false$
- $0 \leq u, v < N$

**計算量**

- $\Theta(1)$

---

### T fold(int u, int v)

頂点 $u$ から頂点 $v$ へのパス上の頂点または辺を順にその値を並べたものを $a_1, a_2, \ldots, a_k$ として、$f(a_1, f(a_2, f(\ldots, f(a_{k-2}, a_{k-1}))\ldots)$ を返します。  

**制約**

- $0 \leq u, v < N$

**計算量**

- $\mathcal{O}((\log{N})^2)$

---

### T subtree_sum(int v)

頂点 $u$ の部分木に含まれる頂点または辺の値をそれぞれ $a_1, a_2, \ldots, a_k$ として、$f(a_1, a_2, \ldots, a_{k-1})$ を返します。  

**制約**

- $(T, f,$ `id_elem`$)$ は可換モノイド
- $0 \leq u, v < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

頂点に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include <GraphTheory/HeavyLightDecomposition.hpp>
#include <GraphTheory/HeavyLightDecomposition_Query.hpp>
#include <DataStructure/SegmentTree.hpp>
using namespace std;

int main() {
	using HLDQ = HeavyLightDecomposition_Query<HeavyLightDecomposition, int, SegmentTree>;
	HLDQ::Graph g(6);
	//         1(10)
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	vector<int> A({1, 10, 100, 1000, 10000, 100000});
	HLDQ hld(g, 1, A, 0, [](auto x, auto y) { return x + y; });
	
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << hld.fold(1, 3) << endl; // 1010
	// 4 -> 5 パス上の頂点 [4, 2, 1, 3, 5] の総和
	cout << "fold(4, 5) = " << hld.fold(4, 5) << endl; // 111110
	// 3 -> 3 パス上の頂点 [3] の総和
	cout << "fold(3, 3) = " << hld.fold(3, 3) << endl; // 1000
	
	// 頂点 1 の部分木の頂点 [0, 1, 2, 3, 4, 5] の値の総和
	cout << "subtree_sum(1) = " << hld.subtree_sum(1) << endl; // 111111
	// 頂点 2 の部分木の頂点 [0, 2, 4] の値の総和
	cout << "subtree_sum(2) = " << hld.subtree_sum(2) << endl; // 10101
	// 頂点 5 の部分木の頂点 [5] の値の総和
	cout << "subtree_sum(5) = " << hld.subtree_sum(5) << endl; // 100000
}
```

辺に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include <GraphTheory/HeavyLightDecomposition.hpp>
#include <GraphTheory/HeavyLightDecomposition_Query.hpp>
#include <DataStructure/SegmentTree.hpp>
using namespace std;

int main() {
	using HLDQ = HeavyLightDecomposition_Query<HeavyLightDecomposition, int, SegmentTree>;
	HLDQ::Graph g(6);
	// 辺の値は葉側の頂点に書いてある
	//         1
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い

	HLDQ hld(g, false, 1, 0, [](auto x, auto y) { return x + y; });
	hld.set(1, 2, 100);
	hld.set(1, 3, 1000);
	hld.set(2, 0, 1);
	hld.set(2, 4, 10000);
	hld.set(3, 5, 100000);
	
	// 1 -> 3 パス上の辺 [1-3] の総和
	cout << "fold(1, 3) = " << hld.fold(1, 3) << endl; // 1000
	// 4 -> 5 パス上の辺 [4-2, 2-1, 1-3, 3-5] の総和
	cout << "fold(4, 5) = " << hld.fold(4, 5) << endl; // 111100
	// 3 -> 3 パス上の辺 [] の総和
	cout << "fold(3, 3) = " << hld.fold(3, 3) << endl; // 0
	
	// 頂点 1 の部分木の辺 [1-2, 2-0, 2-4, 1-3, 3-5] の値の総和
	cout << "subtree_sum(1) = " << hld.subtree_sum(1) << endl; // 111101
	// 頂点 2 の部分木の辺 [2-1, 2-4] の値の総和
	cout << "subtree_sum(2) = " << hld.subtree_sum(2) << endl; // 10001
	// 頂点 5 の部分木の辺 [] の値の総和
	cout << "subtree_sum(5) = " << hld.subtree_sum(5) << endl; // 0
}
```

<br>

# 参考

2020/04/19: [https://qiita.com/ageprocpp/items/8dfe768218da83314989](https://qiita.com/ageprocpp/items/8dfe768218da83314989)  
2020/04/19: [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)  
2020/09/18: [https://codeforces.com/blog/entry/53170](https://codeforces.com/blog/entry/53170)  

<br>