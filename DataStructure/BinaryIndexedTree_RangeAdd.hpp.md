---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree_RangeAdd.test.cpp
    title: Test/BinaryIndexedTree_RangeAdd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\n\n\r\n\
    #line 1 \"DataStructure/BinaryIndexedTree.hpp\"\n\n\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n#include <functional>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\
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
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \n\r\n#line 8 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree_RangeAdd {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\t\r\n\tusing bit_type = BinaryIndexedTree<T>;\r\n\tusing value_type\
    \ = typename bit_type::value_type;\r\n\tusing size_type = typename bit_type::size_type;\r\
    \n\t\r\nprivate:\r\n\tstd::vector<bit_type> bit;\r\n\t\r\npublic:\r\n\texplicit\
    \ BinaryIndexedTree_RangeAdd(size_type n)\r\n\t\t: bit(2, bit_type{n, 0, [](value_type\
    \ x, value_type y) { return x + y; }}) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn bit[0].size();\r\n\t}\r\n\t\r\n\tvoid add(size_type l, size_type\
    \ r, value_type x) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return;\r\n\t\tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\
    \n\t\tbit[1].add(l, -x * l);\r\n\t\tbit[1].add(r - 1, x * r);\r\n\t}\r\n\t\r\n\
    \tvalue_type sum(size_type i) noexcept {\r\n\t\tassert(i <= size());\r\n\t\treturn\
    \ bit[0].sum(i) * i + bit[1].sum(i);\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type\
    \ l, size_type r) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return 0;\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n};\r\n\r\n\
    \n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP\r\
    \n\r\n#include \"DataStructure/BinaryIndexedTree.hpp\"\r\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree_RangeAdd {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\t\r\n\tusing bit_type = BinaryIndexedTree<T>;\r\n\tusing value_type\
    \ = typename bit_type::value_type;\r\n\tusing size_type = typename bit_type::size_type;\r\
    \n\t\r\nprivate:\r\n\tstd::vector<bit_type> bit;\r\n\t\r\npublic:\r\n\texplicit\
    \ BinaryIndexedTree_RangeAdd(size_type n)\r\n\t\t: bit(2, bit_type{n, 0, [](value_type\
    \ x, value_type y) { return x + y; }}) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn bit[0].size();\r\n\t}\r\n\t\r\n\tvoid add(size_type l, size_type\
    \ r, value_type x) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return;\r\n\t\tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\
    \n\t\tbit[1].add(l, -x * l);\r\n\t\tbit[1].add(r - 1, x * r);\r\n\t}\r\n\t\r\n\
    \tvalue_type sum(size_type i) noexcept {\r\n\t\tassert(i <= size());\r\n\t\treturn\
    \ bit[0].sum(i) * i + bit[1].sum(i);\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type\
    \ l, size_type r) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return 0;\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n};\r\n\r\n\
    #endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP"
  dependsOn:
  - DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree_RangeAdd.hpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree_RangeAdd.test.cpp
documentation_of: DataStructure/BinaryIndexedTree_RangeAdd.hpp
layout: document
title: "\u533A\u9593\u52A0\u7B97 Binary Indexed Tree"
---

# 概要

[Binary Indexed Tree](https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp) を用いた配列の区間和を扱うデータ構造です。  
要素数 $N$ の配列に対し、区間一樣加算や任意の区間和の計算を $\Theta(\log{N})$ で行うことができます。  
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

- `T` は `int`, `long long`, [`ModInt`](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)

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
#include "DataStructure/BinaryIndexedTree_RangeAdd.hpp"
using namespace std;

int main() {
	BinaryIndexedTree_RangeAdd<int> bit(5);
	cout << "N = " << bit.size() << endl; // 5
	
	bit.add(1, 3, 2);
	// 0 2 2 0 0
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i, i + 1) << " \n"[i + 1 == bit.size()];
	
	bit.add(0, 2, -1);
	// -1 1 2 0 0
	for (int i = 0; i < bit.size(); ++i) cout << bit.sum(i, i + 1) << " \n"[i + 1 == bit.size()];
	
	cout << "sum = " << bit.sum(bit.size()) << endl; // 2
}
```

<br>

# 参考

2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>