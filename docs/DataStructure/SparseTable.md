---
title: Sparse Table
documentation_of: //DataStructure/SparseTable.hpp
---

# 概要

配列を扱う静的データ構造です。  
大きさ $N$ の配列に対し、任意の区間の最小値や最大値の計算を、事前計算 $\Theta(N\log{N})$ クエリ $\Theta(1)$ で行うことができます。  
値の変更を行いたい場合は、[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp)を使用してください。  

- `SparseTable(InputIterator first, InputIterator last, const F & f)`
	- $\Theta(N\log{N})$ $[first, last)$ でテーブルを構築  
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返す  
- `T fold(size_t l, size_t r)`
	- $\Theta(N\log{N})$ $f(A_l, A_{l+1}, \ldots, A_{r-1})$ を返す  

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

---

### SparseTable(InputIterator first, InputIterator last, const F & f)

$[first, last)$ でテーブルを構築します。  

**制約**

- $(T, f)$ は半群
- べき等律(任意の $x \in T$ について $f(x, x) = x$) が成り立つ。

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

$f(A_l, A_{l+1}, \ldots, A_{r-1})$ を返します。  

**制約**

- $0 \leq l < r \leq N$

**計算量**

- $\Theta(N\log{N})$

---

<br>

# 使用例

`min`, `max` を載せました。`gcd` も載せることができます。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SparseTable.hpp>
using namespace std;

int main() {
{
	int A[5] = {1, 2, 3, 1, 5};
	SparseTable<int> spt(begin(A), end(A), [](int x, int y) { return min(x, y); });
	
	cout << "min = " << spt.fold(0, spt.size()) << endl; // 1
	cout << "min[1, 3) = " << spt.fold(1, 3) << endl; // 2
	cout << "min[2, 5) = " << spt.fold(2, 5) << endl; // 1
	cout << "min[0, 4) = " << spt.fold(0, 4) << endl; // 1
}
{
	vector<int> A = {2, 5, 3, 1, 6};
	SparseTable<int> spt(begin(A), end(A), [](int x, int y) { return max(x, y); });
	cout << "max = " << spt.fold(0, spt.size()) << endl; // 6
	cout << "max[1, 3) = " << spt.fold(1, 3) << endl; // 5
	cout << "max[2, 5) = " << spt.fold(2, 5) << endl; // 6
	cout << "max[0, 4) = " << spt.fold(0, 4) << endl; // 5
	cout << "max[0, 1) = " << spt.fold(0, 1) << endl; // 2
}
}
```

<br>

# 解説

### fold

 $f(A_l, A_{l+1}, \ldots, A_{r-1})$ を求めることを考えます。  
diff $:= r - l$ とし、diff の二進表記で最も大きい桁を $2^k$ とします。
$k$ のとり方から、$l + 2^k \leq r$ と $l + 2^k > r - 2^k$ が成り立ちます。  
つまり、&#123;$A_l, \ldots, A_{l + 2^k}$&#125; と &#123;$A_{r - 2^k}, \ldots, \ldots A_{r-1}$&#125; の和集合は、&#123;$A_l, \ldots, A_{r-1}$&#125; と一致します。  
$f$ は冪等性がある演算で可換なので、  

- $f(A_l, A_{l+1}, \ldots, A_{r-1}) = f(f(A_l, \ldots, A_{l + 2^k}), f(A_{r - 2^k}, \ldots, A_{r-1}))$

です。  

上記の計算を $\Theta(1)$ で行えるように次の 2 つの事前計算を `build` で行っています。  

- 二進表記で最も大きい桁を事前に計算 `(log_table[i] := i における上記の k + 1)`
- すべての位置において、$2$ のべき乗個連続する要素に対する $f$ の計算結果のテーブルの作成 (`table[i][j] := )

<br>

# 参考
2020/04/30: http://tookunn.hatenablog.com/entry/2016/07/13/211148  

<br>