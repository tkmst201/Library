---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/bit_operation.hpp
    title: "bit \u64CD\u4F5C"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DisjointSparseTable.test.cpp
    title: Test/DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp
  bundledCode: "#line 1 \"DataStructure/DisjointSparseTable.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <functional>\r\n#include <algorithm>\r\
    \n#include <utility>\r\n\r\n#include <Mathematics/bit_operation.hpp>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp\r\
    \n */\r\ntemplate <typename T>\r\nstruct DisjointSparseTable {\r\npublic:\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>>\
    \ table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\n\tDisjointSparseTable(InputIterator\
    \ first, InputIterator last, const F & f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\
    \n\t\treturn table.empty() ? 0 : table.front().size();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold(size_type l, size_type r) const noexcept {\r\n\t\tassert(l < r);\r\n\t\t\
    assert(r <= size());\r\n\t\t--r;\r\n\t\tif (l == r) return table.front()[l];\r\
    \n\t\tsize_type level = 31 - tk::count_leading_zeros(l ^ r);\r\n\t\treturn f(table[level][l\
    \ ^ ~(~0 << level)], table[level][r]);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build()\
    \ {\r\n\t\tif (size() <= 2) return;\r\n\t\ttable.reserve(32 - tk::count_leading_zeros(size()\
    \ - 1));\r\n\t\tfor (size_type level = 1; (1 << level) + 1 <= size(); ++level)\
    \ {\r\n\t\t\tstd::vector<value_type> dat;\r\n\t\t\tconst size_type cnt = size()\
    \ & (~0 << (level + 1));\r\n\t\t\tdat.reserve(cnt + (1 << level) + 1 <= size()\
    \ ? size() : cnt);\r\n\t\t\tfor (size_type i = 0; i < size(); i += 1 << (level\
    \ + 1)) {\r\n\t\t\t\tsize_type k = i + (1 << level);\r\n\t\t\t\tif (k >= size())\
    \ continue;\r\n\t\t\t\tdat.emplace_back(table.front()[k - 1]);\r\n\t\t\t\tfor\
    \ (size_type j = k - 1; j != i; --j) {\r\n\t\t\t\t\tdat.emplace_back(f(table.front()[j\
    \ - 1], dat.back()));\r\n\t\t\t\t}\r\n\t\t\t\tdat.emplace_back(table.front()[k]);\r\
    \n\t\t\t\tfor (size_type j = k + 1, ej = std::min(k + (1 << level), size()); j\
    \ != ej; ++j) {\r\n\t\t\t\t\tdat.emplace_back(f(dat.back(), table.front()[j]));\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\ttable.emplace_back(std::move(dat));\r\n\t\t}\r\
    \n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP\r\n#define INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n#include\
    \ <algorithm>\r\n#include <utility>\r\n\r\n#include <Mathematics/bit_operation.hpp>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp\r\
    \n */\r\ntemplate <typename T>\r\nstruct DisjointSparseTable {\r\npublic:\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>>\
    \ table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\n\tDisjointSparseTable(InputIterator\
    \ first, InputIterator last, const F & f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\
    \n\t\treturn table.empty() ? 0 : table.front().size();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold(size_type l, size_type r) const noexcept {\r\n\t\tassert(l < r);\r\n\t\t\
    assert(r <= size());\r\n\t\t--r;\r\n\t\tif (l == r) return table.front()[l];\r\
    \n\t\tsize_type level = 31 - tk::count_leading_zeros(l ^ r);\r\n\t\treturn f(table[level][l\
    \ ^ ~(~0 << level)], table[level][r]);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build()\
    \ {\r\n\t\tif (size() <= 2) return;\r\n\t\ttable.reserve(32 - tk::count_leading_zeros(size()\
    \ - 1));\r\n\t\tfor (size_type level = 1; (1 << level) + 1 <= size(); ++level)\
    \ {\r\n\t\t\tstd::vector<value_type> dat;\r\n\t\t\tconst size_type cnt = size()\
    \ & (~0 << (level + 1));\r\n\t\t\tdat.reserve(cnt + (1 << level) + 1 <= size()\
    \ ? size() : cnt);\r\n\t\t\tfor (size_type i = 0; i < size(); i += 1 << (level\
    \ + 1)) {\r\n\t\t\t\tsize_type k = i + (1 << level);\r\n\t\t\t\tif (k >= size())\
    \ continue;\r\n\t\t\t\tdat.emplace_back(table.front()[k - 1]);\r\n\t\t\t\tfor\
    \ (size_type j = k - 1; j != i; --j) {\r\n\t\t\t\t\tdat.emplace_back(f(table.front()[j\
    \ - 1], dat.back()));\r\n\t\t\t\t}\r\n\t\t\t\tdat.emplace_back(table.front()[k]);\r\
    \n\t\t\t\tfor (size_type j = k + 1, ej = std::min(k + (1 << level), size()); j\
    \ != ej; ++j) {\r\n\t\t\t\t\tdat.emplace_back(f(dat.back(), table.front()[j]));\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\ttable.emplace_back(std::move(dat));\r\n\t\t}\r\
    \n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP"
  dependsOn:
  - Mathematics/bit_operation.hpp
  isVerificationFile: false
  path: DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2021-03-18 11:48:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DisjointSparseTable.test.cpp
documentation_of: DataStructure/DisjointSparseTable.hpp
layout: document
title: Disjoint Sparse Table
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