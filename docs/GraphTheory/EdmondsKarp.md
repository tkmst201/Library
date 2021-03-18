---
title: 最大流 (Edmonds-Karp)
documentation_of: //GraphTheory/EdmondsKarp.hpp
---

# 概要

容量付きの有向グラフにおいて、任意の $2$ 頂点 $s, t$ に対する $s-t$ フローの最大値を求めます。  
計算量は、頂点数を $N$ 、辺の数を $M$ として $\mathcal{O}(NM^2)$ です。  
より高速で使い勝手の良い [AC Library](https://github.com/atcoder/ac-library) の `maxflow` を使用したほうが良いです。  

- `EdmondsKarp(int n)`
	- $\Theta(n)$ 頂点数 $n$ のグラフで初期化する
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `void add_edge(int u, int v const T & cap)`
	- ならし $\Theta(1)$ 頂点 $u$ から頂点 $v$ へ容量 $cap$ の有向辺を張る
- `T max_flow(int s, int t)`
	- $\mathcal{O}(NM^2)$ $s-t$ フローの最大値を返す

<br>

# コンストラクタ

### EdmondsKarp(int n)

頂点数 $n$ のグラフで初期化します。
`T` には容量の型を指定してください。  

**制約**

- $0 \leq n$
- `T` は `int`, `unsigned int`, `long long int`, `unsigned long long`, `float`, `double`

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、頂点数を $N$ 、辺の数を $M$ とします。  

---

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void add_edge(int u, int v const T & cap)

頂点 $u$ から頂点 $v$ へ容量 $cap$ の有向辺を張ります。  

**制約**

- $0 \leq u, v < N$
- $0 \leq cap$

**計算量**

- ならし $\Theta(1)$

### T max_flow(int s, int t)

$s-t$ フローの最大値を返します。
この関数を $2$ 回以上呼んだ場合の動作は未定義です。  

**制約**

- $0 \leq u, v < N$
- $u \neq v$

**計算量**

- $\mathcal{O}(NM^2)$

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/EdmondsKarp.hpp"
using namespace std;

int main() {
	EdmondsKarp<int> ek(5);
	cout << "size() = " << ek.size() << endl; // 5
	ek.add_edge(0, 1, 2);
	ek.add_edge(0, 2, 3);
	ek.add_edge(1, 2, 2);
	ek.add_edge(1, 4, 1);
	ek.add_edge(2, 4, 3);
	cout << "max_flow(0, 4) = " << ek.max_flow(0, 4) << endl; // 4
}
```

<br>

# 参考

2020/02/27: [http://hos.ac/slides/20150319_flow.pdf](http://hos.ac/slides/20150319_flow.pdf)  

<br>