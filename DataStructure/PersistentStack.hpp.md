---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/PersistentStack.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/PersistentStack.hpp
  bundledCode: "#line 1 \"DataStructure/PersistentStack.hpp\"\n\n\n\r\n#include <memory>\r\
    \n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentStack.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PersistentStack {\r\npublic:\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type\
    \ = std::shared_ptr<Node>;\r\n\tstruct Node {\r\n\t\tvalue_type value;\r\n\t\t\
    sptr_type prev;\r\n\t\tsize_type sz;\r\n\t\tNode(const_reference value, const\
    \ sptr_type & prev, size_type sz) : value(value), prev(prev), sz(sz) {}\r\n\t\
    };\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tPersistentStack(const sptr_type\
    \ & prev) : top_node(prev) {}\r\n\t\r\npublic:\r\n\tPersistentStack() = default;\r\
    \n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn !static_cast<bool>(top_node);\r\
    \n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\tif (empty()) return\
    \ 0;\r\n\t\treturn top_node->sz;\r\n\t}\r\n\t\r\n\tPersistentStack push(const_reference\
    \ x) const {\r\n\t\treturn PersistentStack{std::make_shared<Node>(x, top_node,\
    \ size() + 1)};\r\n\t}\r\n\t\r\n\tPersistentStack pop() const noexcept {\r\n\t\
    \tassert(!empty());\r\n\t\treturn PersistentStack{top_node->prev};\r\n\t}\r\n\t\
    \r\n\tconst_reference top() const noexcept {\r\n\t\tassert(!empty());\r\n\t\t\
    return top_node->value;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_STACK_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_STACK_HPP\r\
    \n\r\n#include <memory>\r\n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentStack.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PersistentStack {\r\npublic:\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type\
    \ = std::shared_ptr<Node>;\r\n\tstruct Node {\r\n\t\tvalue_type value;\r\n\t\t\
    sptr_type prev;\r\n\t\tsize_type sz;\r\n\t\tNode(const_reference value, const\
    \ sptr_type & prev, size_type sz) : value(value), prev(prev), sz(sz) {}\r\n\t\
    };\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tPersistentStack(const sptr_type\
    \ & prev) : top_node(prev) {}\r\n\t\r\npublic:\r\n\tPersistentStack() = default;\r\
    \n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn !static_cast<bool>(top_node);\r\
    \n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\tif (empty()) return\
    \ 0;\r\n\t\treturn top_node->sz;\r\n\t}\r\n\t\r\n\tPersistentStack push(const_reference\
    \ x) const {\r\n\t\treturn PersistentStack{std::make_shared<Node>(x, top_node,\
    \ size() + 1)};\r\n\t}\r\n\t\r\n\tPersistentStack pop() const noexcept {\r\n\t\
    \tassert(!empty());\r\n\t\treturn PersistentStack{top_node->prev};\r\n\t}\r\n\t\
    \r\n\tconst_reference top() const noexcept {\r\n\t\tassert(!empty());\r\n\t\t\
    return top_node->value;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_STACK_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentStack.hpp
  requiredBy: []
  timestamp: '2021-03-04 18:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentStack.hpp
layout: document
title: "\u5B8C\u5168\u6C38\u7D9A Stack"
---

# 概要

完全永続 Stack です。  
過去の任意の状態の参照や更新が $\Theta(1)$ で行えます。  

- `PersistentStack()`
	- $\Theta(1)$ 空の Stack を作成
- `bool empty()`
	- $\Theta(1)$ Stack が空であるか判定
- `PersistentStack push(const T & x)`
	- $\Theta(1)$ データ $x$ を push する
- `PersistentStack pop()`
	- $\Theta(1)$ データを pop する
- `const T & top()`
	- $\Theta(1)$ 一番最後に push したデータを返す

<br>

# コンストラクタ

### PersistentStack()

空の Stack を作成します。
$T$ には保持したい値の型を指定します。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

### bool empty()

Stack が空なら $true$ を返します。
それ以外は $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

Stack に入っている要素数を返します。  

**計算量**

- $\Theta(1)$

---

### PersistentStack push(const T & x)

データ $x$ を push した Stack を返します。  

**計算量**

- $\Theta(1)$

---

### PersistentStack pop()

一番最後に push したデータを取り除いた Stack を返します。  

**制約**

- Stack は空ではない

**計算量**

- $\Theta(1)$

---

### const T & top()

一番最後に push したデータを返します。  

**制約**

- Stack は空ではない

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PersistentStack.hpp"
using namespace std;

int main() {
	using ps = PersistentStack<int>;
	
	ps stk1;
	cout << stk1.size() << endl; // 0
	ps stk2 = stk1.push(1);
	ps stk3 = stk2.push(2);
	cout << stk2.size() << ", " << stk2.top() << endl; // 1, 1
	cout << stk3.size() << ", " << stk3.top() << endl; // 2, 2
	
	cout << stk3.pop().top() << endl; // 1
	
	ps stk4 = stk2.push(3);
	cout << stk2.top() << ", " << stk3.top() << ", " << stk4.top() << endl; // 1, 2, 3
	cout << stk4.size() << endl; // 2
	
	ps stk5 = stk2.pop();
	ps stk6 = stk5.push(4);
	
	cout << stk6.top() << endl; // 4
	cout << stk6.pop().size() << endl; // 0
}
```

<br>

# 参考

2020/04/10: [http://noshi91.hatenablog.com/entry/2019/02/04/175100](http://noshi91.hatenablog.com/entry/2019/02/04/175100)  

<br>