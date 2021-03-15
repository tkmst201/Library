---
title: Disjoint Sparse Table
documentation_of: //DataStructure/DisjointSparseTable.hpp
---

# 概要

配列を扱う静的データ構造です。  
要素数 $N$ の配列に対し、任意の区間の最小値や総和などの計算を、事前計算 $\Theta(N\log{N})$ クエリ $\Theta(1)$ で行うことができます。  
[Sparse Table](https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp) で必要だった可換性や冪等性が要求されません。  

- `DisjointSparseTable(InputIterator first, InputIterator last, const F & f)`
	- 時間/空間 $\Theta(N\log{N})$ $[first, last)$ でテーブルを構築
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返す
- `T fold(size_t l, size_t r)`
	- $\Theta(N\log{N})$ $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-1}, A_{r-1}))\ldots)$ を返す

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

---

### DisjointSparseTable(InputIterator first, InputIterator last, const F & f)

$[first, last)$ でテーブルを構築します。  

**制約**

- $(T, f)$ は半群

**計算量**

- 時間/空間 $\Theta(N\log{N})$

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

### T fold(size_t l, size_t r)

$f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-1}, A_{r-1}))\ldots)$ を返します。  

**制約**

- $0 \leq l < r \leq N$

**計算量**

- $\Theta(N\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/DisjointSparseTable.hpp"
using namespace std;

int main() {
	vector<int> A{1, 10, 100, 1000, 10000};
	
	DisjointSparseTable<int> dst(begin(A), end(A), [](int x, int y) { return x + y; });
	cout << dst.fold(0, 5) << endl; // 11111
	cout << dst.fold(0, 2) << endl; // 11
	cout << dst.fold(1, 3) << endl; // 110
	cout << dst.fold(4, 5) << endl; // 10000
}
```

<br>

# 解説

### build

$level$ は 1 つの累積和のサイズが $2^{level}$ 個であることを表します。  
実装の都合上、左側に伸びる累積和は配列の格納順序が逆になっているので `fold` の `l ^ ~(~0 << level)` のように index を修正する必要があります。  

<br>

# 参考

2020/04/30: [https://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b](https://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b)  

<br>