---
title: Binary Indexed Tree
documentation_of: //DataStructure/BinaryIndexedTree.hpp
---

# 概要

配列の累積和を扱うデータ構造です。  
要素数 $N$ の配列に対し、1 点更新や先頭からの和の計算を $\mathcal{O}(\log{N})$ で行うことができます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような**可換**な演算が扱えます。例: `+`, `xor`, `min`, `gcd` など。  
逆元を持つ場合は任意の区間和の計算が可能です。  
[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) に比べ、より省メモリで定数倍が良いです。  

- `BinaryIndexedTree(size_t n, const F & f, const T & id_elem)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `size_t size()`
	- $\Theta(1)$ 配列の要素数を返す
- `void add(size_t i, const T & x)`
	- $\mathcal{O}(\log{N})$ $A_i = f(A_i, x)$
- `T sum(size_t i)`
	- $\mathcal{O}(\log{N})$ 半開区間 $[0, i)$ の和を返す
- `size_t lower_bound(const T & x)`
	- $\Theta(\log{N})$ 累積和が $x$ 以上となる最も先頭の index を返す

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, F,$ `id_elem`$)$ は可換モノイド

---

### BinaryIndexedTree(size_t n, const F & f, const T & id_elem)

要素数 $n$ で初期化します。
初期値は単位元 `id_elem` です。  

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、要素数 $N$ の配列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。
二項演算は $f$ です。  

---

### size_t size()

配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void add(size_t i, const T & x)

$A_i = f(A_i, x)$ をします。  

**制約**

- $0 \leq i < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T sum(size_t i)

半開区間 $[0, i)$ の和 $f(A_0, A_1, \ldots, A_{i-1})$ を返します。
計算順序は不定です。
$i = 0$ のときは `id_elem` を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### :warning: size_t lower_bound(const T & x)

先頭からの和が $x$ 以上となる最小の index $r$ を返します。$sum(r) < x$ が成り立ちます。
もしそのような index が存在しない場合は $N$ を返します。  

**制約**

- 先頭からの和が単調増加

**計算量**

- $\Theta(\log{N})$

**Verified**

- 2020/08/15 [https://atcoder.jp/contests/arc033/submissions/15899920](https://atcoder.jp/contests/arc033/submissions/15899920)

<br>

# 使用例

和を載せました。
和には逆元 (負の数) が存在するので任意の区間の総和を求めることができます。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/BinaryIndexedTree.hpp>
using namespace std;

int main() {
	BinaryIndexedTree<int> bit(10, [](int x, int y) { return x + y; }, 0);
	int A[10] {1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
	for (int i = 0; i < 10; ++i) bit.add(i, A[i]);
	
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i + 1) - bit.sum(i) << " \n"[i + 1 == bit.size()];
	// 1 1 0 0 1 0 0 0 1 0
	
	cout << bit.sum(0) << endl; // 0
	for (int i = 1; i <= bit.size(); ++i)  cout << bit.sum(i) << " \n"[i + 1 > bit.size()];
	// 1 2 2 2 3 3 3 3 4 4
	
	for (int i = 0; i <= 5; ++i) cout << "x = " << i << ", idx = " << bit.lower_bound(i) << endl;
	/*
		x = 0, idx = 0
		x = 1, idx = 0
		x = 2, idx = 1
		x = 3, idx = 4
		x = 4, idx = 8
		x = 5, idx = 10
	*/
	
	cout << "A_2 + A_3 + A_4 + A_5 = " << bit.sum(6) - bit.sum(2) << endl; // 1
}
```

xor を載せました。
xor にも逆元が存在するので任意の区間 xor の計算が可能です。
この場合 `lower_bound` を使用したときの動作は不定です。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/BinaryIndexedTree.hpp>
using namespace std;

int main() {
	BinaryIndexedTree<int> bit(6, [](int x, int y) { return x ^ y; }, 0);
	int A[6] {2, 7, 5, 1, 0, 2};
	for (int i = 0; i < 6; ++i) bit.add(i, A[i]);
	
	for (int i = 0; i < bit.size(); ++i) cout << (bit.sum(i + 1) ^ bit.sum(i)) << " \n"[i + 1 == bit.size()];
	// 2 7 5 1 0 2
	
	cout << bit.sum(0) << endl; // 0
	for (int i = 1; i <= bit.size(); ++i)  cout << bit.sum(i) << " \n"[i + 1 > bit.size()];
	// 2 5 0 1 1 3
	
	cout << "A_2 xor A_3 xor A_4 xor A_5 = " << (bit.sum(6) ^ bit.sum(2)) << endl; // 6
	
	bit.add(1, 7);
	cout << "A_1 = " << (bit.sum(2) ^ bit.sum(1)) << endl; // 0
}
```

<br>

# TODO

TODO: コンストラクタの `f` と `id_elem` の定義の順番を逆にする  
TODO: `lower_bound` の test を追加する  

<br>

# 参考
2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>