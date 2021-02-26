---
title: 遅延伝搬セグメント木
documentation_of: //DataStructure/LazySegmentTree.hpp
---

# 概要

配列を扱うデータ構造です。  
要素数 $N$ の配列に対し、区間更新や区間に対する演算を $\Theta(\log{N})$ で行うことができます。  
使用できる代表的な演算の例は`使用例`をご覧ください。  

- `LazySegmentTree(size_t n, const T & id_node, const E & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const E e, size_t k) { return e; })`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `LazySegmentTree(const vector<T> & v, const T & id_node, const E & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const E e, size_t k) { return e; })`
	- $\Theta(\|v\|)$ 配列 `v` で初期化
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返します。
- `void set(size_t k, const T & x)`
	- $\Theta(\log{N})$ $A_k$ を $x$ に変更
- `T get(size_t k)`
	- $\Theta(\log{N})$ $A_k$ を返します。
- `void update(size_t l, size_t r, const E & x)`
	- $\Theta(\log{N})$ $[l, r)$ に $x$ を作用させます。
- `T fold(size_t l, size_t r)`
	- $\Theta(\log{N})$ $[l, r)$ を畳み込んだ結果を返す
- `T fold_all()`
	- $\Theta(1)$ $fold(0,N)$ を返す

<br>

# コンストラクタ

配列の型と作用素の型をそれぞれ `T`、`E` としています。作用については [こちらの記事](https://beet-aizu.hatenablog.com/entry/2017/12/01/225955)を参照してください。  

- $f(T\ x, T\ y)$ : 要素 $x, y$ のマージ
- $g(T\ x, E\ e)$ : 要素 $x$ に作用素 $e$ を作用
- $h(E\ e1, E\ e2)$ : 作用素 $e1, e2$ のマージ
- $p(E\ e, size_t\ k)$ : 作用素 $e$ を $k$ 個マージ $g(e, e, \ldots, e)$

関数 `g`, `h`, `p` は伝搬する値が存在する(単位元 `id_lazy` ではない)ときに呼ばれます。   

**制約**

- `E` は `T` への作用である
- `F` の単位元は `id_node`
- $(T, f,$ `id_node`$)$ はモノイド
- `G` の単位元は `id_lazy`
- $(E, g,$ `id_lazy`$)$ はモノイド

---

### LazySegmentTree(size_t n, const T &amp; id_node, const E &amp; id_lazy, const F &amp; f, const G &amp; g, const H &amp; h, const P &amp; p = &#91;&#93;(const E e, size_t k) { return e; })

要素数 $n$ で初期化します。初期値は単位元 `id_node` です。  
作用が作用する区間の大きさに依存しない場合は $p$ を省略することができます。  

**計算量**

- $\Theta(n)$

---

### LazySegmentTree(const vector<T> &amp; v, const T &amp; id_node, const E &amp; id_lazy, const F &amp; f, const G &amp; g, const H &amp; h, const P &amp; p = &#91;&#93;(const E e, size_t k) { return e; })

配列 `v` で初期化します。  
作用が作用する区間の大きさに依存しない場合は $p$ を省略することができます。  

**計算量**

- $\Theta(\|v\|)$

---

<br>

# メンバ関数

以下、要素数 $N$ の配列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。    

---

### size_t size()

配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### :warning: void set(size_t k, const T & x)

$A_k$ を $x$ に変更します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(\log{N})$

---

### :warning: T get(size_t k)

$A_k$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(\log{N})$

---

### void update(size_t l, size_t r, const E & x)

半開区間 $[l, r)$ に作用素 $x$ を作用させます。$l = r$ のときは何も行いません。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\Theta(\log{N})$

---

### T fold(size_t l, size_t r)

半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返します。$l = r$ のときは単位元を返します。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\Theta(\log{N})$

---

### T fold_all()

$fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返します。  

**計算量**

- $\Theta(1)$

--- 

<br>

# 使用例

区間加算 & 区間 `min` のセグメント木の例です。オーバーフローに注意してください。総和が $2^{31}$ 以上になる場合は `long long` を使いましょう。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/LazySegmentTree.hpp>
using namespace std;

int main() {
	const vector<int> A {1, 5, 3, 2, 6, 8, 7, 4};
	constexpr int INF = numeric_limits<int>::max();
	// 区間加算, 区間 min
	LazySegmentTree<int, int> seg(A, INF, 0,
		[](auto x, auto y) { return min(x, y); },
		[](auto x, auto e) { return x + e; },
		[](auto e1, auto e2) { return e1 + e2; });
	
	cout << "N = " << seg.size() << endl; // 8 (= N)
	cout << "min = " << seg.fold_all() << endl; // 1
	cout << "min[0, 2) = " << seg.fold(0, 2) << endl; // 2
	cout << "min[0, 0) = " << seg.fold(0, 0) << endl; // INF (= id_node)
	cout << "get(3) = " << seg.get(3) << endl; // 2
	
	seg.update(1, 5, 10);
	// [1 15 13 12 16 8 7 4]
	for (int i = 0; i < seg.size(); ++i) printf("%d%c", seg.get(i), " \n"[i + 1 == seg.size()]);
	
	cout << "min[1, 4) = " << seg.fold(1, 4) << endl; // 12
	cout << "min[4, 7) = " << seg.fold(4, 7) << endl; // 7
}
```

区間更新 & 区間 `sum` を扱うセグメント木の例です。オーバーフローに注意してください。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/LazySegmentTree.hpp>
using namespace std;

int main() {
	const vector<int> A {1, 5, 3, 2, 6, 8, 7, 4};
	constexpr int INF = numeric_limits<int>::max();
	// 区間更新, 区間 sum
	LazySegmentTree<int, int> seg(A, 0, INF,
		[](auto x, auto y) { return x + y; },
		[](auto x, auto e) { return e; },
		[](auto e1, auto e2) { return e2; },
		[](auto e, auto k) { return e * k; });
	
	cout << "sum = " << seg.fold_all() << endl; // 36
	cout << "sum[0, 2) = " << seg.fold(0, 2) << endl; // 6
	cout << "sum[0, 0) = " << seg.fold(0, 0) << endl; // 0 (= id_node)
	cout << "get(3) = " << seg.get(3) << endl; // 2
	
	seg.update(1, 5, 10);
	for (int i = 0; i < seg.size(); ++i) printf("%d%c", seg.get(i), " \n"[i + 1 == seg.size()]);
	// [1 10 10 10 10 8 7 4]
	
	cout << "sum[1, 4) = " << seg.fold(1, 4) << endl; // 30
	cout << "sum[4, 7) = " << seg.fold(4, 7) << endl; // 25
}
```

よく使いそうな定義をいくつか載せておきます。  

- 区間加算, 区間 `sum`

```cpp
LazySegmentTree<ll, ll> seg(N, 0, 0,
	[](auto x, auto y) { return x + y; },
	[](auto x, auto e) { return x + e; },
	[](auto e1, auto e2) { return e1 + e2; },
	[](auto e, auto k) { return e * k; });
```

- 区間加算, 区間 `min`

```cpp
LazySegmentTree<ll, int> seg(N, numeric_limits<ll>::max(), 0,
	[](auto x, auto y) { return std::min(x, y); },
	[](auto x, auto e) { return x + e; },
	[](auto e1, auto e2) { return e1 + e2; });
```

- 区間更新, 区間 `sum`

```cpp
LazySegmentTree<ll, int> seg(N, 0, std::numeric_limits<int>::max(),
	[](auto x, auto y) { return x + y; },
	[](auto x, auto e) { return e; },
	[](auto e1, auto e2) { return e2; },
	[](auto e, auto k) { return e * k; });
```

- 区間更新, 区間 `min`
```cpp
LazySegmentTree<int, int> seg(N, std::numeric_limits<int>:max(), std::numeric_limits<int>:max(),
	[](auto x, auto y) { return std::min(x, y); },
	[](auto x, auto e) { return e; },
	[](auto e1, auto e2) { return e2; });
```

- 区間一次変換, 区間 `sum`

`mint` は `ModInt` 構造体の略記です。

```cpp
using P = std::pair<mint, mint>;
LazySegmentTree<mint, P> seg(A, 0, {1, 0},
	[](const auto & x, const auto & y) { return x + y; },
	[](const auto & x, const auto & e) { return e.first * x + e.second; },
	[](const auto & e1, const auto & e2) { return std::make_pair(e1.first * e2.first, e1.second * e2.first + e2.second); },
	[](const auto & e, auto k) { return std::make_pair(e.first, e.second * k); });
```

<br>

# 解説

### T reflect(size_t k, size_t w)

ノード $k$ (対応する区間の大きさを $w$ ) に作用素を作用させた後の値を返します。  

**制約**

- $0 < k < 2N$

**計算量**

- $\Theta(1)$

---

### void propagate(size_t k, size_t w)

ノード $k$ (対応する区間の大きさを $w$ ) に作用素を作用させ、子に作用素を伝搬します。  
ノードの数を $2$ 冪で確保していることを前提としています。これにより左の子の存在から右の子の存在が保証されます。  

**制約**

- $0 < k < 2N$

**計算量**

- $\Theta(1)$

---

### void recalc(size_t k)

ノード $k$ の先祖の作用が伝搬済みだと仮定して先祖の値を再計算します。ノード $k$ の値は変化しません。

**制約**

- $0 < k < 2N$

**計算量**

- $\Theta(\log{N})$

---

### void thrust(size_t k)

根からノード $k$ まで作用を伝搬します。ノード $k$ の値は変化しません。  

**制約**

- $N \leq k < 2N$

**計算量**

- $\Theta(1)$

---

<br>

# TODO

TODO: `set`, `get` の test を追加
TODO: `max_right`, `min_left` の追加  

<br>

# 参考
2020/09/11: [https://beet-aizu.hatenablog.com/entry/2017/12/01/225955](https://beet-aizu.hatenablog.com/entry/2017/12/01/225955)  
2020/09/16: [https://smijake3.hatenablog.com/entry/2018/11/03/100133](https://smijake3.hatenablog.com/entry/2018/11/03/100133)  
2020/09/16: [https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html](https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html)  

<br>