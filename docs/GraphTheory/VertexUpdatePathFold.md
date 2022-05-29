---
title: 1 点更新 パス Fold
documentation_of: //GraphTheory/VertexUpdatePathFold.hpp
---

# 概要

頂点数 $N$ の木に対し、[重軽分解 ( HL 分解)](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) と [セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) とマージテクを用いて、$1$ 点更新とパスクエリを $\Theta(N)$ space $\mathcal(\log{N})$ time/query で処理します。  
[重軽分解 ( HL 分解) クエリ](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp) でも同様な処理ができますが、こちらの方が $\log$ が $1$ つ少ないです。  
詳しくは`使用例`をご覧ください。  

- `VertexUpdatePathFold(const Graph &g, int root, bool VERTEX, const T &id_elem, const F &f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` で初期化
- `template<typename U> VertexUpdatePathFold(const Graph &g, int root, const std::vector&lt;U&gt; &dat, bool VERTEX, const T &id_elem, const F &f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` と初期値 `dat` で初期化
- `int size()`
	- $\Theta(1)$ 頂点数 $N$ を返す
- `int par(int v)`
	- $\Theta(1)$ 頂点 $v$ の親を返す
- `int depth(int v)`
	- $\Theta(1)$ 頂点 $v$ の深さを返す
- `void set(int v, const T & x)`
	- $\Theta(\log{N})$ 頂点 $v$ に値 $x$ をセットする
- `T get(int v)`
	- $\Theta(1)$ 頂点 $v$ の値を返す
- `void set(int u, int v, const T & x)`
	- $\Theta(\log{N})$ 辺 $u-v$ に値 $x$ をセットする
- `T get(int u, int v)`
	- $\Theta(1)$ 辺 $u-v$ の値を返す
- `T fold(int u, int v)`
	- $\mathcal{O}(\log{N})$ $u-v$ パスを畳み込んだ結果を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  
`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- $(T, f,$ `id_elem`$)$ はモノイド
- 頂点に値を持つ場合は `VERTEX` $= true$
- 辺に値を持つ場合は `VERTEX` $= false$

---


### VertexUpdatePathFold(const Graph &g, int root, bool VERTEX, const T &id_elem, const F &f)

根が `root` の木 `g` で初期化します。
はじめ、すべての値は単位元です。  

**制約**

- $0 \le$ `root` $< N$
- `g` は `root` を根とした根付き木または木

**計算量**

- $\Theta(N)$

---

### template<typename U> VertexUpdatePathFold(const Graph &g, int root, const std::vector&lt;U&gt; &dat, bool VERTEX, const T &id_elem, const F &f)

各頂点または辺の値を `dat` として根 `root` の木 `g` で初期化します。  
辺 $u-v$ の値は $u$ と $v$ で深さが深い方の頂点の index に入れてください。  

**制約**

- $0 \le$ `root` $< N$
- `g` は `root` を根とした根付き木または木

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数


### int size()

頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int par(int v)

頂点 $v$ の親を返します。  
親が存在しない場合ば $-1$ を返します。  

**計算量**

- $\Theta(1)$

---

### int depth(int v)

頂点 $v$ の深さ(`root` から $v$ までの単純パスに含まれる辺の数) を返します。

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

### T get(int v)

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

### T get(int u, int v)

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

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

頂点に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/VertexUpdatePathFold.hpp"
using namespace std;

int main() {
	using VUPF = VertexUpdatePathFold<int>;
	VUPF::Graph g(6);
	//         1(10)
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	vector<int> A{1, 10, 100, 1000, 10000, 100000};
	VUPF vupf(g, 1, A, true, 0, [](auto x, auto y) { return x + y; });
	
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 1010
	// 4 -> 5 パス上の頂点 [4, 2, 1, 3, 5] の総和
	cout << "fold(4, 5) = " << vupf.fold(4, 5) << endl; // 111110
	// 3 -> 3 パス上の頂点 [3] の総和
	cout << "fold(3, 3) = " << vupf.fold(3, 3) << endl; // 1000
	
	// 頂点 3 の値の変更
	vupf.set(3, 2000);
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 2010
	
	cout << "size() = " << vupf.size() << endl; // 6
	cout << "depth(3) = " << vupf.depth(3) << endl; // 1
	cout << "depth(1) = " << vupf.depth(1) << endl; // 0
	cout << "par(5) = " << vupf.par(5) << endl; // 3
	cout << "par(1) = " << vupf.par(1) << endl; // -1
}
```

辺に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/VertexUpdatePathFold.hpp"
using namespace std;

int main() {
	using VUPF = VertexUpdatePathFold<int>;
	VUPF::Graph g(6);
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
	VUPF vupf(g, 1, A, false, 0, [](auto x, auto y) { return x + y; });
	vupf.set(1, 2, 100);
	vupf.set(1, 3, 1000);
	vupf.set(2, 0, 1);
	vupf.set(2, 4, 10000);
	vupf.set(3, 5, 100000);
	
	// 1 -> 3 パス上の辺 [1-3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 1000
	// 4 -> 5 パス上の辺 [4-2, 2-1, 1-3, 3-5] の総和
	cout << "fold(4, 5) = " << vupf.fold(4, 5) << endl; // 111100
	// 3 -> 3 パス上の辺 [] の総和
	cout << "fold(3, 3) = " << vupf.fold(3, 3) << endl; // 0
}
```

<br>

# 解説

### セグメントのマージテク

各 heavy-path (heavy-edge をつなげたパス) を二分木にすることを考える。  
このとき、完全二分木ではなく、頂点の子孫に含まれるもとの木の頂点の数を重みとしてマージテクを行って作成する。  
これにより、任意の頂点から根までの辺の本数は (light-edge の本数) + sum(heavy_path の木で上る辺) となる。  
light-edge の辺の合計は HL 分解により $\mathcal{O}(\log{N})$ 本であり、第 2 項はマージテクにより打ち消し合って最終的に $\mathcal{O}(\log{N})$ になる。  
詳しくは参考リンク先を読んで下さい。  

### 実装メモ

実装の方針は、

1. 各部分木の頂点数を計算 `sz[i]` に格納
2. DFS の帰りがけ順で heavy-path をセグメント木に変形していく。

その他細かいテクニック  

- `sz[i]` を用いて heavy-edge の index を計算したら一旦 `nodes[i].par` に保存しておく
- heavy-edge の index を計算し終えたら `sz[i]` は light-edge 以下の部分木の頂点数の合計を表すようにしている
- `heavy_stk` は作成中の heavy-path を表していて、負になった index が先頭を表している (つまり、light-edge を下りるときに負の index を追加し、heavy-edge を通るときに非負の index を入れている)
- `merge_stk` では、`(l, r, p)` で `heavy_stk[l + st, r + st)` の頂点のマージで全体の親を `p` とするように処理する。新たに作成された頂点の値は各部分木の値が確定したから計算されるようになっている
- `uup`, `vup` では、`step=-1` のとき頂点が heavy-path セグメント木の葉にいることを仮定している (葉にいることと頂点がもとの木に含まれていることが同値)
- `heavy[i]` はもとの木に含まれる頂点 $i$ が属する heavy-path の番号を格納してあり、`fold` で同一のセグメント木にいるかの判定に使用している
- `depth_[i]` は `fold` で同一のセグメント木にいるときに、どちらの方向に heavy-path の値を回収すれば良いかの判定に使用している

<br>

# デバッグ用メモ

各ノードの情報が正しいかおおまかにチェックします。  

```cpp
void tree_check() const noexcept {
	int top = 0;
	while (nodes[top].par < nodes.size()) top = nodes[top].par;
	std::vector<std::pair<int, int>> chd(nodes.size(), {-1, -1});
	for (int i = 0; i < n; ++i) {
		assert(nodes[i].childs[0] == -1);
		assert(nodes[i].childs[1] == -1);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (nodes[p].childs[0] == i) chd[p].first = i;
		else if (nodes[p].childs[1] == i) chd[p].second = i;
		else chd[p].first = i;
	}
	for (int i = n; i < nodes.size(); ++i) {
		assert(nodes[i].childs[0] != -1);
		assert(nodes[i].childs[1] != -1);
		assert(f(nodes[nodes[i].childs[0]].val, nodes[nodes[i].childs[1]].val) == nodes[i].val);
		assert(f(nodes[nodes[i].childs[1]].rval, nodes[nodes[i].childs[0]].rval) == nodes[i].rval);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (nodes[p].childs[0] == i) chd[p].first = i;
		else if (nodes[p].childs[1] == i) chd[p].second = i;
		else chd[p].first = i;
	}
	for (int i = n; i < nodes.size(); ++i) {
		assert(chd[i].first != -1);
		assert(chd[i].second != -1);
		auto [l, r] = nodes[i].childs;
		assert(l == chd[i].first);
		assert(r == chd[i].second);
		
		assert(nodes[l].decomp_dep() == nodes[r].decomp_dep());
		assert(nodes[l].decomp_dep().second == nodes[i].decomp_dep().second);
		assert(nodes[l].decomp_dep().first == nodes[i].decomp_dep().first + 1);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (p < n) {
			assert(nodes[i].decomp_dep().first == 0);
			assert(nodes[p].decomp_dep().second == nodes[i].decomp_dep().second - 1);
		}
	}
	int mxd = 0;
	for (int i = 0; i < n; ++i) {
		int u = i;
		int cnt = 0;
		for (; nodes[u].par < nodes.size(); u = nodes[u].par, ++cnt);
		if (mxd < cnt) mxd = cnt;
	}
	
	int lgn = 1;
	while ((1 << lgn) < n) ++lgn;
	assert(mxd < 5 * lgn);
}
```

<br>


# TODO

- TODO: 辺に値を載せた場合の verify

<br>

# 参考

2022/05/28: [https://www.mathenachia.blog/mergetech-and-logn/](https://www.mathenachia.blog/mergetech-and-logn/)  
2022/05/28: [https://yosupo.hatenablog.com/entry/2015/10/02/233244](https://yosupo.hatenablog.com/entry/2015/10/02/233244)  
2022/05/28: 計算量解析 [https://noshi91.hatenablog.com/entry/2022/03/27/042143](https://noshi91.hatenablog.com/entry/2022/03/27/042143)   

<br>