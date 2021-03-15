---
title: 動的セグメント木
documentation_of: //DataStructure/DynamicSegmentTree.hpp
---

# 概要

配列を扱うデータ構造で、[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp)の亜種です。  
必要なノードのみ動的に作成することで、要素数 $N$ の配列、$M$ 回の更新に対して、空間計算量 $\mathcal{O}(\min(N, M \log{M}))$ で、1 点更新や区間畳み込み、区間の単位元初期化、他の動的セグメント木との区間スワップを $\mathcal{O}(\log{N})$ で行うことができます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような演算が扱えます。例: `+`, `xor`, `min`, `gcd`, `関数の合成` など。  

- `DynamicSegmentTree(size_t n, const T & id_elem, const F & f)`
	- $\Theta(1)$ 要素数 $n$ で初期化
- `DynamicSegmentTree(const DynamicSegmentTree & rhs)`
	- `this` 、`rhs` の単位元ではない要素の個数をそれぞれ $M_1, M_2$ として $\mathcal{O}(\min(\|$`this`$\|, M_1\log \|$`this`$\|) + \min(\|$`rhs`$\|, M_2\log \|$`rhs`$\|))$ `rhs` をコピー
- `DynamicSegmentTree(DynamicSegmentTree && rhs)`
	- `this` の単位元ではない要素の個数を $M$ として $\mathcal{O}(\min(\|$`this`$\|, M\log \|$`this`$\|))$ `rhs` をムーブ
- `void clear()`
	- 単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(N, M\log{N}))$ メモリを解法し、すべての要素の値を単位元で初期化
- `void clear(size_t l, size_t r)`
	- 対象に含まれる単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(r - l + \log{N}, M\log{N}))$ $A_l, \ldots, A_{r-1}$ のメモリを解法し、単位元で初期化
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返す
- `void set(size_t k, const T & x)`
	- $\Theta(\log{N})$ $A_k = x$
- `T get(size_t k)`
	- $\mathcal{O}(\log{N})$ $A_k$ を返す
- `T fold(size_t l, size_t r)`
	- $\mathcal{O}(\log{N})$ 半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返す
- `T fold_all()`
	- $\Theta(1)$ $fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返す
- `void swap(DynamicSegmentTree & rhs, size_t l, size_t r)`
	- $\mathcal{O}(\log{N})$ `rhs` と区間 $[l, r)$ をスワップ

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, f,$ `id_elem`$)$ はモノイド

---

### DynamicSegmentTree(size_t n, const T & id_elem, const F & f)

要素数 $n$ で初期化します。
初期値は単位元 `id_elem` です。  

**計算量**

- $\Theta(1)$

---

### DynamicSegmentTree(const DynamicSegmentTree & rhs)

動的セグメント木 `rhs` をコピーします。  

**計算量**

- `this` 、`rhs` の単位元ではない要素の個数をそれぞれ $M_1, M_2$ として $\mathcal{O}(\min(\|$`this`$\|, M_1\log \|$`this`$\|) + \min(\|$`rhs`$\|, M_2\log \|$`rhs`$\|))$

---

### DynamicSegmentTree(DynamicSegmentTree && rhs)

動的セグメント木 `rhs` をムーブします。
ムーブ後の `rhs` はすべての要素の値は単位元で初期化されます。  

**計算量**

- `this` の単位元ではない要素の個数を $M$ として $\mathcal{O}(\min(\|$`this`$\|, M\log \|$`this`$\|))$

---

<br>

# メンバ関数

以下、要素数 $N$ の配列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。
二項演算は $f$ です。  

---

### void clear()

メモリを解法し、すべての要素の値を単位元で初期化します。  

**計算量**

- 単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(N, M\log{N}))$

---

### :warning: void clear(size_t l, size_t r)

$A_l, \ldots, A_{r-1}$ のメモリを解法し、単位元で初期化します。
$l = r$ のときは何も行いません。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- 対象に含まれる単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(r - l + \log{N}, M\log{N}))$

---

### size_t size()

配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void set(size_t k, const T & x)

$A_k$ を $x$ に変更します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(\log{N})$

---

### T get(size_t k)

$A_k$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T fold(size_t l, size_t r)

半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返します。
$l = r$ のときは単位元を返します。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T fold_all()

$fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返します。  

**計算量**

- $\Theta(1)$

---

### void swap(DynamicSegmentTree & rhs, size_t l, size_t r)

`rhs` が扱う配列を $B_0, B_1, \ldots, B_{N-1}$ として、$A_l, \ldots, A_{r-1}$ と $B_l, \ldots, B_{r-1}$ の部分をスワップします。  


**制約**

- $N =$ $\|$`rhs`$\|$
- `rhs` と代数構造が等しい

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/DynamicSegmentTree.hpp"
using namespace std;

int main() {
	DynamicSegmentTree<int> seg(10, 0, [](auto x, auto y) { return x + y; });
	
	cout << "size() = " << seg.size() << endl; // 10
	
	seg.set(0, 1);
	seg.set(1, 2);
	seg.set(3, 3);
	seg.set(5, 4);
	seg.set(6, 5);
	seg.set(7, 6);
	seg.set(9, 7);
	// idx 0 1 2 3 4 5 6 7 8 9
	//     1 2 0 3 0 4 5 6 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	
	cout << "fold_all() = " << seg.fold_all() << endl; // 28 ( = 1+2+...+7 )
	cout << "fold(1, 6) = " << seg.fold(1, 6) << endl; // 9 ([2, 0, 3, 0, 4])
	
	seg.clear(5, 7);
	cout << "seg.clear(5, 7)" << endl;
	// 1 2 0 3 0 0 0 6 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	
	DynamicSegmentTree<int> seg2(10, 0, [](auto x, auto y) { return x + y; });
	seg2.set(1, -4);
	seg2.set(3, -5);
	seg2.set(5, -8);
	seg2.set(6, -9);
	// 0 -4 0 -5 0 -8 -9 0 0 0
	for (int i = 0; i < seg2.size(); ++i) cout << seg2.get(i) << " \n"[i + 1 == seg2.size()];
	
	cout << "swap(2, 8)" << endl;
	seg.swap(seg2, 2, 8);
	// 1  2 0 -5 0 -8 -9 0 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	// 0 -4 0  3 0  0  0 6 0 0
	for (int i = 0; i < seg2.size(); ++i) cout << seg2.get(i) << " \n"[i + 1 == seg2.size()];
	
	
	/*
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		0 0 0 0 0 0 0 0 0 0
	*/
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	{
		auto segt = seg;
		for (int i = 0; i < segt.size(); ++i) cout << segt.get(i) << " \n"[i + 1 == segt.size()];
	}
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	{
		auto segt = std::move(seg);
		for (int i = 0; i < segt.size(); ++i) cout << segt.get(i) << " \n"[i + 1 == segt.size()];
	}
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
}
```

<br>

# TODO

TODO: `clear(l, r)` の test の追加  

# 参考

2021/03/04: [https://kazuma8128.hatenablog.com/entry/2018/11/29/093827](https://kazuma8128.hatenablog.com/entry/2018/11/29/093827)  

<br>