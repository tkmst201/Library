---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/SparseTable.test.cpp
    title: Test/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp
  bundledCode: "#line 1 \"DataStructure/SparseTable.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <functional>\r\n#include <cstdint>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SparseTable {\r\npublic:\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>> table;\r\n\
    \tstd::vector<std::uint8_t> log_table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\
    \n\tSparseTable(InputIterator first, InputIterator last, const F & f) : f(f) {\r\
    \n\t\ttable.emplace_back(first, last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn table.empty() ? 0 : table.front().size();\r\
    \n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type r) const noexcept {\r\n\
    \t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\tconst size_type k = log_table[r\
    \ - l];\r\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\r\n\t}\r\n\t\r\n\
    private:\r\n\tvoid build() {\r\n\t\tlog_table.reserve(size() + 1);\r\n\t\tlog_table.emplace_back(0);\r\
    \n\t\tlog_table.emplace_back(0);\r\n\t\tfor (size_type i = 2; i <= size(); ++i)\
    \ log_table.emplace_back(log_table[i >> 1] + 1);\r\n\t\t\r\n\t\ttable.reserve(log_table[size()]\
    \ + 1);\r\n\t\tfor (size_type i = 1; i <= log_table[size()]; ++i) {\r\n\t\t\t\
    table.emplace_back();\r\n\t\t\ttable[i].reserve(size() - (1 << i) + 1);\r\n\t\t\
    \tfor (size_type j = 0; j + (1 << i) <= size(); ++j) {\r\n\t\t\t\ttable[i].emplace_back(f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]));\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SPARSE_TABLE_HPP\r\n#define INCLUDE_GUARD_SPARSE_TABLE_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n#include\
    \ <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SparseTable {\r\npublic:\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>> table;\r\n\
    \tstd::vector<std::uint8_t> log_table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\
    \n\tSparseTable(InputIterator first, InputIterator last, const F & f) : f(f) {\r\
    \n\t\ttable.emplace_back(first, last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn table.empty() ? 0 : table.front().size();\r\
    \n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type r) const noexcept {\r\n\
    \t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\tconst size_type k = log_table[r\
    \ - l];\r\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\r\n\t}\r\n\t\r\n\
    private:\r\n\tvoid build() {\r\n\t\tlog_table.reserve(size() + 1);\r\n\t\tlog_table.emplace_back(0);\r\
    \n\t\tlog_table.emplace_back(0);\r\n\t\tfor (size_type i = 2; i <= size(); ++i)\
    \ log_table.emplace_back(log_table[i >> 1] + 1);\r\n\t\t\r\n\t\ttable.reserve(log_table[size()]\
    \ + 1);\r\n\t\tfor (size_type i = 1; i <= log_table[size()]; ++i) {\r\n\t\t\t\
    table.emplace_back();\r\n\t\t\ttable[i].reserve(size() - (1 << i) + 1);\r\n\t\t\
    \tfor (size_type j = 0; j + (1 << i) <= size(); ++j) {\r\n\t\t\t\ttable[i].emplace_back(f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]));\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_SPARSE_TABLE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2021-03-04 18:57:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/SparseTable.test.cpp
documentation_of: DataStructure/SparseTable.hpp
layout: document
title: Sparse Table
---

# 概要

配列を扱う静的データ構造です。  
要素数 $N$ の配列に対し、任意の区間の最小値や最大値の計算を、事前計算 $\Theta(N\log{N})$ クエリ $\Theta(1)$ で行うことができます。  
値の変更を行いたい場合は、[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp)を使用してください。  

- `SparseTable(InputIterator first, InputIterator last, const F & f)`
	- 時間/空間 $\Theta(N\log{N})$ $[first, last)$ でテーブルを構築  
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
#include "DataStructure/SparseTable.hpp"
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

2020/04/30: [http://tookunn.hatenablog.com/entry/2016/07/13/211148](http://tookunn.hatenablog.com/entry/2016/07/13/211148)  

<br>