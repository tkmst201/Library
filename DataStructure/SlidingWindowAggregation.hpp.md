---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/SlidingWindowAggregation.test.cpp
    title: Test/SlidingWindowAggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.hpp\"\n\n\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n#include <functional>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SlidingWindowAggregation {\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\t\
    std::vector<value_type> lstack, rstack;\r\n\tvalue_type rsum;\r\n\t\r\npublic:\r\
    \n\tSlidingWindowAggregation(const_reference id_elem, const F & f)\r\n\t\t: id_elem(id_elem),\
    \ f(f), lstack(1, id_elem), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const\
    \ noexcept {\r\n\t\treturn lstack.size() - 1 + rstack.size();\r\n\t}\r\n\t\r\n\
    \tvoid push(const_reference x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum =\
    \ f(rsum, x);\r\n\t}\r\n\t\r\n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\t\
    if (lstack.size() == 1) {\r\n\t\t\twhile (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(f(rstack.back(),\
    \ lstack.back()));\r\n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\
    \n\t\t\trsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\
    \n\tvalue_type fold_all() const {\r\n\t\treturn f(lstack.back(), rsum);\r\n\t\
    }\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\n#define INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\
    \n\r\n#include <cassert>\r\n#include <vector>\r\n#include <functional>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SlidingWindowAggregation {\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\t\
    std::vector<value_type> lstack, rstack;\r\n\tvalue_type rsum;\r\n\t\r\npublic:\r\
    \n\tSlidingWindowAggregation(const_reference id_elem, const F & f)\r\n\t\t: id_elem(id_elem),\
    \ f(f), lstack(1, id_elem), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const\
    \ noexcept {\r\n\t\treturn lstack.size() - 1 + rstack.size();\r\n\t}\r\n\t\r\n\
    \tvoid push(const_reference x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum =\
    \ f(rsum, x);\r\n\t}\r\n\t\r\n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\t\
    if (lstack.size() == 1) {\r\n\t\t\twhile (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(f(rstack.back(),\
    \ lstack.back()));\r\n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\
    \n\t\t\trsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\
    \n\tvalue_type fold_all() const {\r\n\t\treturn f(lstack.back(), rsum);\r\n\t\
    }\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2021-02-26 17:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/SlidingWindowAggregation.test.cpp
documentation_of: DataStructure/SlidingWindowAggregation.hpp
layout: document
title: Sliding Window Aggregation (SWAG)
---

# 概要

数列を扱うデータ構造です。  
キューの `enqueue` 、`dequeue` 操作をならし $\Theta(1)$ で、キューに入っている要素全体の `fold` 演算を $\Theta(1)$ でできます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような演算が扱えます。例: `+`, `xor`, `min`, `gcd`, `関数の合成` など。  

- ` SlidingWindowAggregation(const T & id_elem, const F & f)`
	- $\Theta(1)$ 単位元 `id_elem` 、二項演算 $f$ で初期化
- ` size_t size()`
	- $\Theta(1)$ 現在キューに入っている要素数を返す
- ` void push(const T & x)`
	- ならし $\Theta(1)$ 値 $x$ をキューに追加
- ` void pop()`
	- ならし $\Theta(1)$ キューの先頭要素を削除
- ` T fold_all()`
	- $\Theta(1)$ キューに入っている要素を追加した順に $f$ で畳み込んだ結果を返す。

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, f,$ `id_elem`$)$ はモノイド

---

### SlidingWindowAggregation(const T & id_elem, const F & f)

単位元 `id_elem` 、二項演算 $f$ で初期化します。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

### size_t size()

現在キューに入っている要素数を返します。  

**計算量**

- $\Theta(1)$

---

### void push(const T & x)

値 $x$ をキューに追加します。  

**計算量**

- ならし $\Theta(1)$

---

### void pop()

キューの先頭要素を削除します。

**制約**

- キューが空でない

**計算量**

- ならし $\Theta(1)$

---

### T fold_all()

キューに入っている要素の個数を $N$ 、キューに入っている要素を追加した順に $A_1, A_2, \ldots, A_N$ として、$f(A_1, f(A_2, f(\ldots, A_N)\ldots))$ を返します。  
キューに何も入っていない場合は単位元を返します。  

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

`min` を載せました。  

```cpp
#include <bits/stdc++.h>
#include "DataStructure/SlidingWindowAggregation.hpp"
using namespace std;

int main() {
	SlidingWindowAggregation<int> swag(numeric_limits<int>::max(),
		[](auto x, auto y) { return min(x, y); });
	
	cout << "size() = " << swag.size() << endl; // 0
	cout << "fold_all() = " << swag.fold_all() << endl; // INF
	swag.push(10);
	cout << "fold_all() = " << swag.fold_all() << endl; // 10
	swag.push(9);
	swag.push(12);
	swag.push(13);
	cout << "size() = " << swag.size() << endl; // 4
	cout << "fold_all() = " << swag.fold_all() << endl; // 9
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 9
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 12
	cout << "size() = " << swag.size() << endl; // 2
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 13
	swag.pop();
	cout << "size() = " << swag.size() << endl; // 0
	cout << "fold_all() = " << swag.fold_all() << endl; // INF
}
```

<br>

# 参考

2020/09/22: [https://scrapbox.io/data-structures/Sliding_Window_Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)  
2020/09/22: [https://snuke.hatenablog.com/entry/2018/09/18/135640](https://snuke.hatenablog.com/entry/2018/09/18/135640)  

<br>