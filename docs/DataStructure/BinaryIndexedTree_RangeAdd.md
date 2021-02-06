---
title: 区間加算 Binary Indexed Tree
documentation_of: //DataStructure/BinaryIndexedTree_RangeAdd.hpp
---

# 概要
[Binary Indexed Tree](https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp) を用いた配列の区間和を扱うデータ構造です。  
大きさ $N$ の配列に対し、区間一樣加算や任意の区間和の計算を $\Theta(\log{N})$ で行うことができます。  
[遅延セグメント木](https://tkmst201.github.io/Library/DataStructure/LazySegmentTree.hpp) に比べ、より省メモリで定数倍が良いです。  

- `BinaryIndexedTree(size_t n)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返す
- `void add(size_t l, size_t r, T x)`
	- $\mathcal{O}(\log{N})$ 区間 $[l, r)$ に $x$ を一様加算する
- `T sum(size_t i)`
	- $\mathcal{O}(\log{N})$ $\sum_{k=0}^{i-1} A_k$ を返す
- `T sum(size_t l, size_t r)`
	- $\mathcal{O}(\log{N})$ $\sum_{k=l}^{r-1} A_k$ を返す

<br>

# コンストラクタ

**制約**

- `T` は `int`, `long long`
- `U` は `BinaryIndexedTree`

---

### BinaryIndexedTree_RagneAdd(size_t n)

要素数 $n$ で初期化します。
初期値は $0$ です。  

**計算量**

- $\Theta(n)$

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

### void add(size_t l, size_t r, T x)

$i = l, l+1, \ldots, r-1$ に対して $A_i$ += $x$ をします。
$l = r$ のときは何も行いません。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T sum(size_t i)

$\sum_{k=0}^{i-1} A_k$ を返します。
$i = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T sum(size_t l, szie_t r)

$\sum_{k=l}^{r-1} A_k$ を返します。
$l = r$ のときは $0$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

オーバーフローに注意してください。総和が $2^{31}$ 以上になる場合は `long long` を使いましょう。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/BinaryIndexedTree.hpp>
#include <DataStructure/BinaryIndexedTree_RangeAdd.hpp>
using namespace std;

int main() {
	BinaryIndexedTree_RangeAdd<int, BinaryIndexedTree> bit(5);
	cout << "N = " << bit.size() << endl; // 5
	
	bit.add(1, 3, 2);
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i, i + 1) << " \n"[i + 1 == bit.size()];
	// 0 2 2 0 0
	
	bit.add(0, 2, -1);
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i, i + 1) << " \n"[i + 1 == bit.size()];
	// -1 1 2 0 0
	
	cout << "sum = " << bit.sum(bit.size()) << endl; // 2
}
```

<br>

# 参考
2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>