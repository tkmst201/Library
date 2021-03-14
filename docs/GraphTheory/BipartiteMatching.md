---
title: 二部マッチング
documentation_of: //GraphTheory/BipartiteMatching.hpp
---

# 概要

二部グラフ上の最大マッチングを求めます。  
計算量は、$2$ つの頂点集合をそれぞれ $S$, $T$ 、辺の数を $M$ として $\mathcal{O}(\min(\|S\|, \|T\|) M)$ です。  
実際はかなり高速です。  

- `BipartiteMatching(int x, int y)`
	- $\Theta(x + y)$ $\|S\| = x, \|T\| = y$ で初期化
- `BipartiteMatching(int n)`
	- $\Theta(n)$ $\|S\| = \|T\| = n$ で初期化
- `void add_edge(int a, int b)`
	- ならし $\Theta(1)$ $S$ の頂点 $a$ と $T$ の頂点 $b$ の間に辺を張る
- `void build()`
	- $\mathcal{O}(\min(\|S\|, \|T\|) M)$ $S, T$ の最大マッチングを求める
- `int max_matching()`
	- $\Theta(1)$ $S, T$ の最大マッチングでのマッチング数を返す
- `std::vector<std::pair<int, int>> matching()`
	- $\Theta(\min(\|S\|, \|T\|))$ $S, T$ の最大マッチングでのそれぞれのマッチングの組 ($S, T$ の順) を返す
- `int matching_x(int k)`
	- $\Theta(1)$ $S, T$ の最大マッチングでの $S$ の頂点 $k$ のマッチング先を返す
- `int matching_y(int k)`
	- $\Theta(1)$ $S, T$ の最大マッチングでの $T$ の頂点 $k$ のマッチング先を返す

<br>

# コンストラクタ

以下、$2$ つの頂点集合をそれぞれ $S$, $T$ 、辺の数を $M$ とします。  

---

### BipartiteMatching(int x, int y)

$\|S\| = x, \|T\| = y$ で初期化します。  

**制約**

- $0 \leq x, y$

**計算量**

- $\Theta(x + y)$

---

### BipartiteMatching(int n)

$\|S\| = \|T\| = n$ で初期化します。  

**制約**

- $0 \leq n$

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数


### void add_edge(int a, int b)

$S$ の頂点 $a$ と $T$ の頂点 $b$ の間に辺を張ります。  

**計算量**

- ならし $\Theta(1)$

---

### void build()

$S, T$ の最大マッチングを求めます。
必ず事前に呼んでください。  

**計算量**

- $\mathcal{O}(\min(\|S\|, \|T\|) M)$

---

### int max_matching()

$S, T$ の最大マッチングでのマッチング数を返します。  

**計算量**

- $\Theta(1)$

### std::vector&lt;std::pair&lt;int, int&gt;&gt; matching()

$S, T$ の最大マッチングでのそれぞれのマッチングの組 ($S, T$ の順) を返します。  

**計算量**

- $\Theta(\min(\|S\|, \|T\|))$

---

### int matching_x(int k)

$S, T$ の最大マッチングでの $S$ の頂点 $k$ のマッチング先を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq k < \|S\|$

**計算量**

- $\Theta(1)$

---

### int matching_y(int k)

$S, T$ の最大マッチングでの $T$ の頂点 $k$ のマッチング先を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq k < \|T\|$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <GraphTheory/BipartiteMatching.hpp>
using namespace std;

int main() {
	BipartiteMatching bm(3, 4);
	// S -> T
	// 0 -> 0 1
	// 1 -> 1
	// 2 -> 1 3
	bm.add_edge(0, 0);
	bm.add_edge(0, 1);
	bm.add_edge(1, 1);
	bm.add_edge(2, 1);
	bm.add_edge(2, 3);
	bm.build(); // 必ず呼ぶ
	
	cout << "max_matching() = " << bm.max_matching() << endl; // 3
	/*
		matching : 0 - 0
		matching : 1 - 1
		matching : 2 - 3
	*/
	for (auto [x, y] : bm.matching()) cout << "matching : " << x << " - " << y << endl;
	
	/*
		S: x = 0 - 0
		S: x = 1 - 1
		S: x = 2 - 3
		
		T: y = 0 - 0
		T: y = 1 - 1
		T: y = 2 - -1
		T: y = 3 - 2
	*/
	for (int i = 0; i < 3; ++i) cout << "S: x = " << i << " - " << bm.matching_x(i) << endl;
	for (int i = 0; i < 4; ++i) cout << "T: y = " << i << " - " << bm.matching_y(i) << endl;
}
```

<br>

# 参考

2021/03/13: [https://manabitimes.jp/math/1147](https://manabitimes.jp/math/1147)  
2020/03/05: [https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching](https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching)  
2020/08/26: [https://snuke.hatenablog.com/entry/2019/05/07/013609](https://snuke.hatenablog.com/entry/2019/05/07/013609)  

<br>