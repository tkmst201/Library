---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: "\u533A\u9593\u52A0\u7B97 Binary Indexed Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree.test.cpp
    title: Test/BinaryIndexedTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree_RangeAdd.test.cpp
    title: Test/BinaryIndexedTree_RangeAdd.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.path.test.cpp
    title: Test/EulerTour.path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\n */\r\
    \ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type = T;\r\
    \n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), node(n + 1, id_elem) {}\r\
    \n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, const_reference x) noexcept {\r\n\t\tassert(i < size());\r\
    \n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i], x);\r\n\
    \t}\r\n\t\r\n\tvalue_type sum(size_type i) const noexcept {\r\n\t\tassert(i <=\
    \ size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ res = f(node[i], res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem,\
    \ w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\
    \t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\
    \n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), node(n + 1, id_elem) {}\r\
    \n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, const_reference x) noexcept {\r\n\t\tassert(i < size());\r\
    \n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i], x);\r\n\
    \t}\r\n\t\r\n\tvalue_type sum(size_type i) const noexcept {\r\n\t\tassert(i <=\
    \ size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ res = f(node[i], res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem,\
    \ w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\
    \t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\
    \n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.hpp
  requiredBy:
  - DataStructure/BinaryIndexedTree_RangeAdd.hpp
  timestamp: '2021-03-09 16:44:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree_RangeAdd.test.cpp
  - Test/EulerTour.path.test.cpp
  - Test/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.hpp
layout: document
title: Binary Indexed Tree
---

# 概要

配列の累積和を扱うデータ構造です。  
要素数 $N$ の配列に対し、1 点更新や先頭からの和の計算を $\mathcal{O}(\log{N})$ で行うことができます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような**可換**な演算が扱えます。例: `+`, `xor`, `min`, `gcd` など。  
逆元を持つ場合は任意の区間和の計算が可能です。  
[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) に比べ、より省メモリで定数倍が良いです。  

- `BinaryIndexedTree(size_t n, const T & id_elem, const F & f)`
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

### BinaryIndexedTree(size_t n, const T & id_elem, const F & f)

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
#include "DataStructure/BinaryIndexedTree.hpp"
using namespace std;

int main() {
	BinaryIndexedTree<int> bit(10, 0, [](int x, int y) { return x + y; });
	int A[10] {1, 1, 0, 0, 1, 0, 0, 0, 1, 0};
	for (int i = 0; i < 10; ++i) bit.add(i, A[i]);
	
	// 1 1 0 0 1 0 0 0 1 0
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i + 1) - bit.sum(i) << " \n"[i + 1 == bit.size()];
	
	cout << bit.sum(0) << endl; // 0
	// 1 2 2 2 3 3 3 3 4 4
	for (int i = 1; i <= bit.size(); ++i)  cout << bit.sum(i) << " \n"[i + 1 > bit.size()];
	
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
#include "DataStructure/BinaryIndexedTree.hpp"
using namespace std;

int main() {
	BinaryIndexedTree<int> bit(6, 0, [](int x, int y) { return x ^ y; });
	int A[6] {2, 7, 5, 1, 0, 2};
	for (int i = 0; i < 6; ++i) bit.add(i, A[i]);
	
	// 2 7 5 1 0 2
	for (int i = 0; i < bit.size(); ++i) cout << (bit.sum(i + 1) ^ bit.sum(i)) << " \n"[i + 1 == bit.size()];
	
	cout << bit.sum(0) << endl; // 0
	// 2 5 0 1 1 3
	for (int i = 1; i <= bit.size(); ++i)  cout << bit.sum(i) << " \n"[i + 1 > bit.size()];
	
	cout << "A_2 xor A_3 xor A_4 xor A_5 = " << (bit.sum(6) ^ bit.sum(2)) << endl; // 6
	
	bit.add(1, 7);
	cout << "A_1 = " << (bit.sum(2) ^ bit.sum(1)) << endl; // 0
}
```

<br>

# TODO

TODO: `lower_bound` の test を追加する  

<br>

# 参考

2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>