---
title: セグメント木
documentation_of: //DataStructure/SegmentTree.hpp
---

# 概要

配列を扱うデータ構造です。  
要素数 $N$ の配列に対し、1 点更新や区間に対する演算をそれぞれ $\Theta(\log{N})$、1 点取得を $\Theta(1)$ で行うことができます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような演算が扱えます。例: `+`, `xor`, `min`, `gcd`, `関数の合成` など。  
区間更新を行いたい場合は、[遅延伝搬セグメント木](https://tkmst201.github.io/Library/DataStructure/LazySegmentTree.hpp)を使用してください。  

- `SegmentTree(size_t n, const T & id_elem, const F & f)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `SegmentTree(const vector<T> & v, const T & id_elem, const F & f)`
	- $\Theta(\|v\|)$ v で初期化
- `size_t size()`
	- $\Theta(1)$ 要素数を返す
- `void set(size_t i, const T & x)`
	- $\Theta(\log{N})$ $i$ 番目に $x$ を代入
- `const T & get(size_t i)`
	- $\Theta(1)$ $i$ 番目の要素を返す
- `T fold(size_t l, size_t r)`
	- $\Theta(\log{N})$ $[l, r)$ を畳み込んだ結果を返す
- `const T & fold_all()`
	- $\Theta(1)$ $fold(0, size())$ を返す
- `max_right(size_t l, std::function<bool (const T &)> g)`
	- $\Theta(\log{N})$ $g(fold(l, r)) = true$ となる最大の $r$ を返す
- `size_t min_left(size_t r, std::function<bool (const T &)> g)`
	- $\Theta(\log{N})$ $g(fold(l, r)) = true$ となる最小の $l$ を返す

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, f,$ `id_elem`$)$ はモノイド

---

### SegmentTree(size_t n, const T & id_elem, const F & f)

要素数 $n$ で初期化します。初期値は単位元 `id_elem` です。  

**計算量**

- $\Theta(n)$

---

### SegmentTree(const vector<T> & v, const T & id_elem, const F & f)

配列 `v` で初期化します。  

**計算量**

- $\Theta(\|v\|)$

---

### SegmentTree()

エラーは出ませんが、初期化しないまま使用した場合の動作は保証されていません。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

以下、要素数 $N$ の配列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。二項演算は $f$ です。  

---

### size_t size()

配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void set(size_t i, const T & x)

$A_i$ を $x$ に変更します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(\log{N})$

---

### const T & get(size_t i)

$A_i$ を返します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### T fold(size_t l, size_t r)

半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返します。$l = r$ のときは単位元を返します。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\Theta(\log N)$

---

### const T & fold_all()

$fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返します。  

**計算量**

- $\Theta(1)$

---

### :warning: size_t max_right(size_t l, std::function&lt; bool (const T &amp;)&gt; g)

$g(fold(l, r)) = true$ となるような最小の $r$ を返します。$g(fold(l, N)) = true$ または $l = N$ のときは $N$ を返します。  


**制約**

- $0 \leq l \leq N$
- $g$ は単調な関数
- $g($`id_elem`$) = true$

**計算量**

- $\Theta(\log N)$


**Verified**

- 2020/09/13 [https://atcoder.jp/contests/practice2/submissions/16664880](https://atcoder.jp/contests/practice2/submissions/16664880)
- 2021/01/24 [https://atcoder.jp/contests/abc189/submissions/19661857](https://atcoder.jp/contests/abc189/submissions/19661857)

---

### :warning: size_t min_left(size_t r, std::function&lt; bool (const T &amp;)&gt; g)

$g(fold(l, r)) = true$ となるような最大の $l$ を返します。$g(fold(0, r)) = true$ または $l = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq r \leq N$
- $g$ は単調な関数
- $g($`id_elem`$) = true$

**計算量**

- $\Theta(\log N)$

**Verified**

- 2021/01/24 [https://atcoder.jp/contests/abc189/submissions/19661857](https://atcoder.jp/contests/abc189/submissions/19661857)

---

<br>

# 使用例

和を扱うセグメント木の例です。オーバーフローには注意してください。総和が $2^{31}$ 以上になる場合は `long long` を使いましょう。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SegmentTree.hpp>
using namespace std;

int main() {
	const vector<int> A {1, 2, 3, 0, 0, 0, 4, 5};
	
	// 和を扱うセグメント木
	SegmentTree<int> seg(A, 0, [](int x, int y) { return x + y; });
	cout << "N = " << seg.size() << endl; // 8 (= N)
	cout << "sum = " << seg.fold_all() << endl; // 15
	cout << "sum[0, 2) = " << seg.fold(0, 2) << endl; // 3
	cout << "sum[0, 0) = " << seg.fold(0, 0) << endl; // 0 (= id_elem)
	
	// A[0..] で合計が 6 以下となるような最大の index を求める (index = r - 1)
	int r = seg.max_right(0, [](int x) { return x <= 6; });
	cout << "r = " << r << endl; // 6
	cout << "sum[0, r) = " << seg.fold(0, r) << " (<= 6)" << endl; // 6
	
	// A[..4] で合計が 4 以下となるような最小の index を求める (index = l)
	int l = seg.min_left(5, [](int x) { return x <= 4; });
	cout << "l = " << l << endl; // 2
	cout << "sum[l, 5) = " << seg.fold(l, 5) << " (<= 4)" << endl; // 3
	
	cout << "seg[2] = " << seg.get(2) << endl; // 3
	cout << "seg.set(2, 5)" << endl;
	seg.set(2, 5);
	cout << "seg[2] = " << seg.get(2) << endl; // 5
	cout << "sum = " << seg.fold_all() << endl; // 17
}
```

最小値を扱うセグメント木の例です。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SegmentTree.hpp>
using namespace std;

constexpr int INF = 1<<30;

int main() {
	// 最小値を扱うセグメント木
	SegmentTree<int> seg(5, INF, [](int x, int y) { return min(x, y); });
	seg.set(0, 1);
	seg.set(1, 5);
	seg.set(2, 3);
	seg.set(3, 7);
	seg.set(4, 0);
	// [1, 5, 3, 7, 0]
	
	cout << "N = " << seg.size() << endl; // 5 (= N)
	cout << "min = " << seg.fold_all() << endl; // 0
	cout << "min[2, 4) = " << seg.fold(2, 4) << endl; // 3
	cout << "min[3, 3) = " << seg.fold(3, 3) << endl; // INF (= id_elem)
	
	// A[1..] の中で 2 以下の値でもっとも左側の index を求める (index = r)
	int r = seg.max_right(1, [](int x) { return x > 2; });
	cout << "r = " << r << endl; // 4
	cout << "sum[1, r) = " << seg.fold(1, r) << " (> 2)" << endl; // 3
	
	// A[..4] で最小値が 0 以上の最小の index を求める (index = l)
	int l = seg.min_left(5, [](int x) { return x >= 0; });
	cout << "l = " << l << endl; // 0
	cout << "sum[l, 5) = " << seg.fold(l, 5) << " (>= 0)" << endl; // 0
}
```

よく使いそうなセグメント木の定義をいくつか載せておきます。  

`xor` セグメント木  

```cpp
SegmentTree<int> seg(N, 0, [](int x, int y) { return x ^ y; });
```

一次関数セグメント木。`mint` は `ModInt` 構造体の略記です。$Ax+B$ の $A$ が `first` に、$B$ が `second` に対応しています。演算は一次関数の合成です。  

```cpp
using pmm = std::pair<mint, mint>;
SegmentTree<pmm> seg(N, pmm(1, 0), [](const pmm & a, const pmm & b) -> pmm {
	return {a.first * b.first, b.first * a.second + b.second};
});
```

<br>

# 解説

内部で扱っているノードの数を `n_` とし、ノードは 1-indexed で管理しています。  

#### max_right

`min_left` も同様なので `max_right` についてのみ書きます。  
$A_l, (\ldots)$ を含むノード ($A_{l-1}$ は含まない) 最も根側のノードまで上りその値を加えて右上の部分木に移動することを繰り返すことにより $g(fold(l, r)) = false$ となるような $r$ を求めることが可能です。  
上っている途中で $g(fold(l, r))$ が満たさなくなったら $r$ の部分木の中に解が存在するはずです。$g(fold(l, r の左部分木の右端 + 1))$ が $false$ ならば左部分木中に、 $true$ ならば右部分木中に解があると分かります。  

`(l & -l)` で $l$ の最下位ビットを取り出すことができます。これを利用して $2$ べきであるかの判定を行っています。  

<br>

# TODO

TODO: `max_right`, `min_left` の test を追加する  
TODO: `InputIterator` コンストラクタに変更  

<br>

# 参考
2020/04/08: [https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)  
2020/09/13: [AC Library](https://github.com/atcoder/ac-library)  

<br>