---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentUnionFind.hpp
    title: "\u5B8C\u5168\u6C38\u7D9A Union Find"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/PersistentUnionFind.test.cpp
    title: Test/PersistentUnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/PersistentArray.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/PersistentArray.hpp
  bundledCode: "#line 1 \"DataStructure/PersistentArray.hpp\"\n\n\n\r\n#include <memory>\r\
    \n#include <utility>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentArray.hpp\r\
    \n */\r\ntemplate<typename T, int M>\r\nstruct PersistentArray {\r\n\tstatic_assert(M\
    \ > 1);\r\n\t\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type\
    \ &;\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\
    \n\tusing sptr_type = std::shared_ptr<Node>;\r\n\tusing node_ptr = Node *;\r\n\
    \tusing const_ptr = const Node *;\r\n\tstruct Node {\r\n\t\tsptr_type childs[M];\r\
    \n\t\tvalue_type val;\r\n\t\tNode(const_reference val) : val(val) {}\r\n\t};\r\
    \n\t\r\nprivate:\r\n\tsptr_type root;\r\n\tvalue_type def_val;\r\n\t\r\nprivate:\r\
    \n\tPersistentArray(const sptr_type & root, const_reference def_val) : root(root),\
    \ def_val(def_val) {}\r\n\t\r\npublic:\r\n\texplicit PersistentArray(const_reference\
    \ def_val = 0) : root(nullptr), def_val(def_val) {}\r\n\t\r\n\tPersistentArray\
    \ set(size_type k, const_reference x) const {\r\n\t\tconst_ptr node = root.get();\r\
    \n\t\tsptr_type new_root = std::make_shared<Node>(k == 0 ? x : (node ? node->val\
    \ : def_val));\r\n\t\tnode_ptr new_node = new_root.get();\r\n\t\tfor (; k > 0;\
    \ k /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (node) {\r\n\t\t\t\
    \tfor (size_type i = 0; i < M; ++i) if (i != m) new_node->childs[i] = node->childs[i];\r\
    \n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k < M ? x : (node->childs[m]\
    \ ? node->childs[m]->val : def_val));\r\n\t\t\t\tnode = node->childs[m].get();\r\
    \n\t\t\t}\r\n\t\t\telse new_node->childs[m] = std::make_shared<Node>(k < M ? x\
    \ : def_val);\r\n\t\t\tnew_node = new_node->childs[m].get();\r\n\t\t}\r\n\t\t\
    if (node) for (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];\r\
    \n\t\treturn {std::move(new_root), def_val};\r\n\t}\r\n\t\r\n\tvoid destructive_set(size_type\
    \ k, const_reference x) {\r\n\t\tif (!root) root = std::make_shared<Node>(k ==\
    \ 0 ? x : def_val);\r\n\t\tnode_ptr node = root.get();\r\n\t\tfor (; k >= M; k\
    \ /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (!node->childs[m]) node->childs[m]\
    \ = std::make_shared<Node>(def_val);\r\n\t\t\tnode = node->childs[m].get();\r\n\
    \t\t}\r\n\t\tif (node->childs[k]) node->childs[k]->val = x;\r\n\t\telse node->childs[k]\
    \ = std::make_shared<Node>(x);\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ k) const noexcept {\r\n\t\tconst_ptr node = root.get();\r\n\t\twhile (k > 0\
    \ && node) {\r\n\t\t\tnode = node->childs[k % M].get();\r\n\t\t\tk /= M;\r\n\t\
    \t}\r\n\t\treturn k == 0 && node ? node->val : def_val;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\
    \n\r\n#include <memory>\r\n#include <utility>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentArray.hpp\r\
    \n */\r\ntemplate<typename T, int M>\r\nstruct PersistentArray {\r\n\tstatic_assert(M\
    \ > 1);\r\n\t\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type\
    \ &;\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\
    \n\tusing sptr_type = std::shared_ptr<Node>;\r\n\tusing node_ptr = Node *;\r\n\
    \tusing const_ptr = const Node *;\r\n\tstruct Node {\r\n\t\tsptr_type childs[M];\r\
    \n\t\tvalue_type val;\r\n\t\tNode(const_reference val) : val(val) {}\r\n\t};\r\
    \n\t\r\nprivate:\r\n\tsptr_type root;\r\n\tvalue_type def_val;\r\n\t\r\nprivate:\r\
    \n\tPersistentArray(const sptr_type & root, const_reference def_val) : root(root),\
    \ def_val(def_val) {}\r\n\t\r\npublic:\r\n\texplicit PersistentArray(const_reference\
    \ def_val = 0) : root(nullptr), def_val(def_val) {}\r\n\t\r\n\tPersistentArray\
    \ set(size_type k, const_reference x) const {\r\n\t\tconst_ptr node = root.get();\r\
    \n\t\tsptr_type new_root = std::make_shared<Node>(k == 0 ? x : (node ? node->val\
    \ : def_val));\r\n\t\tnode_ptr new_node = new_root.get();\r\n\t\tfor (; k > 0;\
    \ k /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (node) {\r\n\t\t\t\
    \tfor (size_type i = 0; i < M; ++i) if (i != m) new_node->childs[i] = node->childs[i];\r\
    \n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k < M ? x : (node->childs[m]\
    \ ? node->childs[m]->val : def_val));\r\n\t\t\t\tnode = node->childs[m].get();\r\
    \n\t\t\t}\r\n\t\t\telse new_node->childs[m] = std::make_shared<Node>(k < M ? x\
    \ : def_val);\r\n\t\t\tnew_node = new_node->childs[m].get();\r\n\t\t}\r\n\t\t\
    if (node) for (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];\r\
    \n\t\treturn {std::move(new_root), def_val};\r\n\t}\r\n\t\r\n\tvoid destructive_set(size_type\
    \ k, const_reference x) {\r\n\t\tif (!root) root = std::make_shared<Node>(k ==\
    \ 0 ? x : def_val);\r\n\t\tnode_ptr node = root.get();\r\n\t\tfor (; k >= M; k\
    \ /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (!node->childs[m]) node->childs[m]\
    \ = std::make_shared<Node>(def_val);\r\n\t\t\tnode = node->childs[m].get();\r\n\
    \t\t}\r\n\t\tif (node->childs[k]) node->childs[k]->val = x;\r\n\t\telse node->childs[k]\
    \ = std::make_shared<Node>(x);\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ k) const noexcept {\r\n\t\tconst_ptr node = root.get();\r\n\t\twhile (k > 0\
    \ && node) {\r\n\t\t\tnode = node->childs[k % M].get();\r\n\t\t\tk /= M;\r\n\t\
    \t}\r\n\t\treturn k == 0 && node ? node->val : def_val;\r\n\t}\r\n};\r\n\r\n#endif\
    \ // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentArray.hpp
  requiredBy:
  - DataStructure/PersistentUnionFind.hpp
  timestamp: '2021-03-04 18:57:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/PersistentUnionFind.test.cpp
documentation_of: DataStructure/PersistentArray.hpp
layout: document
title: "\u5B8C\u5168\u6C38\u7D9A\u914D\u5217"
---

# 概要

完全永続配列です。  
内部を $M$ 分木、アクセスする添字を $k$ とすると、過去の任意の状態の参照を $\mathcal{O}(\log_M{k})$ 、更新を $\mathcal{O}(M \log_M{k})$ で行えます。  

- `PersistentArray(const T & def_val = 0)`
	- $\Theta(1)$ 要素数無限の Array を作成
- `PersistentArray set(size_t k, const T & x)`
	- $時間/空間 \mathcal{O}(M \log_M{k})$ $A_k$ に $x$ を代入
- `void destructive_set(size_t k, const T & x)`
	- $時間/空間 \mathcal{O}(M \log_M{k})$ $A_k$ に $x$ を破壊的に代入
- `const T & get(size_t k)`
	- $\mathcal{O}(\log_M{k})$ $A_k$ を返す

<br>

# コンストラクタ

保持したい値の型を $T$ とし、内部を $M$ 分木で管理します。  

**制約**

- $M > 1$

---

### PersistentArray(const T & def_val = 0)

要素数無限の Array を作成します。
初期値は `def_val` です。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

以下、配列 $A_0, A_1, \ldots$ を対象とします。

---

### PersistentArray set(size_t k, const T & x)

$A_k$ に $x$ を代入した Array を返します。  

**制約**

- $0 \leq k$

**時間/空間計算量**

- $\mathcal{O}(M \log_M{k})$

---

### void destructive_set(size_t k, const T & x)

$A_k$ に $x$ を破壊的に代入します。
`set` よりも高速に動作します。  
この関数を呼んだ後で同一の履歴ツリーに含まれる別の状態にアクセスしたときの動作は未定義です。  

**制約**

- $0 \leq k$

**時間/空間計算量**

- $\mathcal{O}(M \log_M{k})$

---

### const T & get(size_t k)

$A_k$ を返す。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log_M{k})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PersistentArray.hpp"
using namespace std;

int main() {
	using pa = PersistentArray<int, 3>;
	
	pa ary1;
	cout << ary1.get(10) << endl; // 0
	
	pa ary2 = ary1.set(1, 5);
	pa ary3 = ary1.set(1, 6);
	cout << ary1.get(1) << ", " << ary2.get(1) << ", " << ary3.get(1) << endl; // 0, 5, 6
	
	pa ary4 = ary3.set(3, 7);
	cout << ary1.get(3) << ", " << ary3.get(3) << ", " << ary4.get(3) << endl; // 0, 0, 7
	
	cout << ary1.get(1) << ", " << ary3.get(1) << ", " << ary4.get(1) << endl; // 0, 6, 6
	ary4.destructive_set(1, -100);
	// undefined, undefined, -100
	cout << ary1.get(1) << ", " << ary3.get(1) << ", " << ary4.get(1) << endl;
}
```

<br>

# 解説

添字の大きさ順にノードを並べる必要はないので、添字を m 進表記したときの下の桁から見ていき要素を並べるようにしています。  
これにより要素数を事前に指定する必要が無くなっています。

<br>

# 参考

2020/04/10: [https://trap.jp/post/663/](https://trap.jp/post/663/)  
2020/09/25: [https://qiita.com/hotman78/items/9c643feae1de087e6fc5](https://qiita.com/hotman78/items/9c643feae1de087e6fc5)  

<br>