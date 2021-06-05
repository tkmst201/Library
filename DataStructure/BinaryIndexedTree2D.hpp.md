---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree2D.test.cpp
    title: Test/BinaryIndexedTree2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree2D.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree2D.hpp
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree2D.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree2D.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree2D {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\t\r\n\tusing value_type = T;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree2D(size_type h, size_type w)\r\n\
    \t\t: h(h), w(w), node(h + 1, std::vector<value_type>(w + 1)) {}\r\n\t\r\n\tstd::pair<size_type,\
    \ size_type> size() const noexcept {\r\n\t\treturn {h, w};\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, size_type j, value_type x) noexcept {\r\n\t\tassert(i <\
    \ h);\r\n\t\tassert(j < w);\r\n\t\t++i; ++j;\r\n\t\tfor (; i <= h; i += i & -i)\
    \ {\r\n\t\t\tfor (size_type k = j; k <= w; k += k & -k) {\r\n\t\t\t\tnode[i][k]\
    \ += x;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type i, size_type\
    \ j) const noexcept {\r\n\t\tassert(i <= h);\r\n\t\tassert(j <= w);\r\n\t\tvalue_type\
    \ res = 0;\r\n\t\tfor (; i > 0; i -= i & -i) {\r\n\t\t\tfor (size_type k = j;\
    \ k > 0; k -= k & -k) {\r\n\t\t\t\tres += node[i][k];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \treturn res;\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type i1, size_type i2, size_type\
    \ j1, size_type j2) const noexcept {\r\n\t\tassert(i1 <= i2);\r\n\t\tassert(j1\
    \ <= j2);\r\n\t\tassert(i2 <= h);\r\n\t\tassert(j2 <= w);\r\n\t\tif (i1 == i2\
    \ || j1 == j2) return 0;\r\n\t\treturn sum(i2, j2) - sum(i2, j1) + sum(i1, j1)\
    \ - sum(i1, j2);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree2D.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree2D {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\t\r\n\tusing value_type = T;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree2D(size_type h, size_type w)\r\n\
    \t\t: h(h), w(w), node(h + 1, std::vector<value_type>(w + 1)) {}\r\n\t\r\n\tstd::pair<size_type,\
    \ size_type> size() const noexcept {\r\n\t\treturn {h, w};\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, size_type j, value_type x) noexcept {\r\n\t\tassert(i <\
    \ h);\r\n\t\tassert(j < w);\r\n\t\t++i; ++j;\r\n\t\tfor (; i <= h; i += i & -i)\
    \ {\r\n\t\t\tfor (size_type k = j; k <= w; k += k & -k) {\r\n\t\t\t\tnode[i][k]\
    \ += x;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type i, size_type\
    \ j) const noexcept {\r\n\t\tassert(i <= h);\r\n\t\tassert(j <= w);\r\n\t\tvalue_type\
    \ res = 0;\r\n\t\tfor (; i > 0; i -= i & -i) {\r\n\t\t\tfor (size_type k = j;\
    \ k > 0; k -= k & -k) {\r\n\t\t\t\tres += node[i][k];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \treturn res;\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type i1, size_type i2, size_type\
    \ j1, size_type j2) const noexcept {\r\n\t\tassert(i1 <= i2);\r\n\t\tassert(j1\
    \ <= j2);\r\n\t\tassert(i2 <= h);\r\n\t\tassert(j2 <= w);\r\n\t\tif (i1 == i2\
    \ || j1 == j2) return 0;\r\n\t\treturn sum(i2, j2) - sum(i2, j1) + sum(i1, j1)\
    \ - sum(i1, j2);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree2D.hpp
  requiredBy: []
  timestamp: '2021-03-09 16:44:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree2D.test.cpp
documentation_of: DataStructure/BinaryIndexedTree2D.hpp
layout: document
title: "\u4E8C\u6B21\u5143 Binary Indexed Tree"
---

# 概要

二次元になった Binary Indexed Tree です。  
大きさ $H \times W$ の二次元グリッド上で $1$ 点加算と任意の矩形領域和の計算が $\mathcal{O}(\log{H} \log{W})$ で行えます。  

- `BinaryIndexedTree_Ragne2d(size_t h, size_t w)`
	- $\Theta(hw)$ $h \times w$ のテーブルで初期化
- `pair<size_t, size_t> size()`
	- $\Theta(1)$ テーブルの型 $(H, W)$ を返す
- `void add(size_t i, size_t j, T x)`
	- $\mathcal{O}(\log{H} \log{W})$ $A_{ij}$ += $x$ をする
- `T sum(size_t i, size_t j)`
	- $\mathcal{O}(\log{H} \log{W})$ $\sum_{y=0}^{i-1} \sum_{x=0}^{j-1} A_{yx}$ を返す
- `T sum(size_t i1, size_t i2, size_t j1, size_t j2)`
	- $\mathcal{O}(\log{H} \log{W})$ $\sum_{y=i1}^{i2-1} \sum_{x=j1}^{j2-1} A_{yx}$ を返す

<br>

# コンストラクタ

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`, [`ModInt`](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)

---

### BinaryIndexedTree_Ragne2d(size_t h, size_t w)

$h \times w$ のテーブルで初期化します。
初期値は $0$ です。  

**計算量**

- $\Theta(hw)$

---

<br>

# メンバ関数

以下、$H \times W$ のテーブル $A_{ij}\ (0 \leq i < H,\ 0 \leq j < W)$ を対象とします。

---

### pair<size_t, size_t> size()

テーブルの型 $(H, W)$ を返します。  

**計算量**

- $\Theta(1)$

---

### void add(size_t i, size_t j, T x)

$A_{ij}$ += $x$ をします。  

**制約**

- $0 \leq i < H$
- $0 \leq j < W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

### T sum(size_t i, size_t j)

$\sum_{y=0}^{i-1} \sum_{x=0}^{j-1} A_{yx}$ を返します。
$i = 0$ または $j = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq H$
- $0 \leq j \leq W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

### T sum(size_t i1, size_t i2, size_t j1, size_t j2)

$\sum_{y=i1}^{i2-1} \sum_{x=j1}^{j2-1} A_{yx}$ を返します。
$i1 = i2$ または $j1 = j2$ のときは $0$ を返します。  

**制約**

- $0 \leq i1 \leq i2 \leq H$
- $0 \leq j1 \leq j2 \leq W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

<br>

# 使用例

オーバーフローに注意してください。総和が $2^{31}$ 以上になる場合は `long long` を使いましょう。  

```cpp
#include <bits/stdc++.h>
#include "DataStructure/BinaryIndexedTree2D.hpp"
using namespace std;

int main() {
	BinaryIndexedTree2D<int> bit(3, 4);
	
	auto [h, w] = bit.size();
	cout << "h = " << h << ", " << "w = " << w << endl; // 3, 4
	
	bit.add(0, 2, -2);
	bit.add(1, 0, 5);
	bit.add(2, 1, 4);
	bit.add(2, 3, 1);
	
	/*
		0 0 -2 0
		5 0 0 0
		0 4 0 1
	*/
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << bit.sum(i, i + 1, j, j + 1) << " \n"[j + 1 == w];
		}
	}
	
	cout << "sum = " << bit.sum(1, 3, 1, 4) << endl; // 5
	cout << "sum = " << bit.sum(0, 1, 0, 3) << endl; // -2
	cout << "sum = " << bit.sum(3, 3) << endl; // 7
}
```

<br>

# 参考

2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>