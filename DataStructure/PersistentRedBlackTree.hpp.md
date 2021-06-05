---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/PersistentRedBlackTree.test.cpp
    title: Test/PersistentRedBlackTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/PersistentRedBlackTree.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/PersistentRedBlackTree.hpp
  bundledCode: "#line 1 \"DataStructure/PersistentRedBlackTree.hpp\"\n\n\n\r\n#include\
    \ <cassert>\r\n#include <memory>\r\n#include <utility>\r\n#include <vector>\r\n\
    #include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentRedBlackTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PersistentRedBlackTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\n\tstatic constexpr bool red = true;\r\n\tstatic constexpr\
    \ bool black = false;\r\n\tstruct Node;\r\n\tusing node_ptr = std::shared_ptr<Node>;\r\
    \n\tusing node_ref = const node_ptr &;\r\n\tusing raw_ptr = Node *;\r\n\tstruct\
    \ Node {\r\n\t\tvalue_type val;\r\n\t\tbool color;\r\n\t\tsize_type size, rank;\r\
    \n\t\tnode_ptr l, r;\r\n\t\tNode(bool color, node_ref l, node_ref r)\r\n\t\t\t\
    : color(color), size(l->size + r->size), rank(l->rank + (l->color == black)),\
    \ l(l), r(r) {}\r\n\t\tNode(const_reference val) : val(val), color(black), size(1),\
    \ rank(0), l(nullptr), r(nullptr) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tnode_ptr root\
    \ = nullptr;\r\n\t\r\n\tPersistentRedBlackTree(node_ref root) : root(root) {}\r\
    \n\t\r\n\tstatic node_ptr create(bool color, node_ref l, node_ref r) {\r\n\t\t\
    return std::make_shared<Node>(color, l, r);\r\n\t}\r\n\t\r\n\tstatic node_ptr\
    \ create(const_reference val) {\r\n\t\treturn std::make_shared<Node>(val);\r\n\
    \t}\r\n\t\r\npublic:\r\n\tPersistentRedBlackTree() = default;\r\n\t\r\n\tPersistentRedBlackTree(const\
    \ std::vector<value_type> & v)\r\n\t\t: root(v.empty() ? nullptr : build(std::begin(v),\
    \ std::end(v), 30)) {}\r\n\t\r\n\tPersistentRedBlackTree(size_type n, const_reference\
    \ x)\r\n\t\t: root(n == 0 ? nullptr : buildn(n, x, 30)) {}\r\n\t\r\n\tbool empty()\
    \ const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tsize_type size()\
    \ const noexcept {\r\n\t\treturn root ? root->size : 0;\r\n\t}\r\n\t\r\n\tvoid\
    \ clear() {\r\n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tstd::vector<value_type> enumerate()\
    \ const {\r\n\t\tstd::vector<value_type> elements;\r\n\t\tstd::stack<raw_ptr>\
    \ stk;\r\n\t\tstk.emplace(root.get());\r\n\t\twhile (!stk.empty()) {\r\n\t\t\t\
    raw_ptr q = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (q->l) {\r\n\t\t\t\tstk.emplace(q->r.get());\r\
    \n\t\t\t\tstk.emplace(q->l.get());\r\n\t\t\t}\r\n\t\t\telse elements.emplace_back(q->val);\r\
    \n\t\t}\r\n\t\treturn elements;\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree merge(const\
    \ PersistentRedBlackTree & a) const {\r\n\t\treturn merge(root, a.root);\r\n\t\
    }\r\n\t\r\n\tstd::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type\
    \ k) const {\r\n\t\tassert(k <= size());\r\n\t\tconst auto sp = split(root, k);\r\
    \n\t\treturn {sp.first, sp.second};\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree insert(size_type\
    \ k, const_reference x) const {\r\n\t\tassert(k <= size());\r\n\t\treturn insert(root,\
    \ k, x);\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree erase(size_type k) const {\r\
    \n\t\tassert(k < size());\r\n\t\treturn erase(root, k);\r\n\t}\r\n\t\r\n\tconst_reference\
    \ get(size_type k) const noexcept {\r\n\t\tassert(k < size());\r\n\t\traw_ptr\
    \ q = root.get();\r\n\t\twhile (q->l) {\r\n\t\t\tif (k < q->l->size) q = (q->l).get();\r\
    \n\t\t\telse k -= q->l->size, q = (q->r).get();\r\n\t\t}\r\n\t\treturn q->val;\r\
    \n\t}\r\n\t\r\nprivate:\r\n\ttemplate<class InputIterator>\r\n\tnode_ptr build(InputIterator\
    \ first, InputIterator last, int k) const {\r\n\t\tif (first + 1 == last) return\
    \ create(*first);\r\n\t\tconst auto n = last - first;\r\n\t\tconst unsigned int\
    \ m = 1u << k;\r\n\t\tif (n > m) return merge(build(first, first + m, k - 1),\
    \ build(first + m, last, k - 1));\r\n\t\treturn build(first, last, k - 1);\r\n\
    \t}\r\n\t\r\n\tnode_ptr buildn(size_type n, const_reference x, int k) const {\r\
    \n\t\tif (n == 1) return create(x);\r\n\t\tconst unsigned int m = 1u << k;\r\n\
    \t\tif (n > m) return merge(buildn(m, x, k - 1), buildn(n - m, x, k - 1));\r\n\
    \t\treturn buildn(n, x, k - 1);\r\n\t}\r\n\t\r\n\tnode_ptr as_root(const node_ptr\
    \ & q) const {\r\n\t\tif (!q) return nullptr;\r\n\t\tif (q->color == red) return\
    \ create(black, q->l, q->r);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr merge(const\
    \ node_ptr & a, const node_ptr & b) const {\r\n\t\tif (!a) return b;\r\n\t\tif\
    \ (!b) return a;\r\n\t\tnode_ptr res = merge_sub(a, b);\r\n\t\tres->color = black;\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tnode_ptr merge_sub(const node_ptr & a, const\
    \ node_ptr & b) const {\r\n\t\tif (a->rank < b->rank) {\r\n\t\t\tnode_ptr c =\
    \ merge_sub(a, b->l);\r\n\t\t\tif (b->color == black && c->color == red && c->l->color\
    \ == red) {\r\n\t\t\t\tif (b->r->color == black) return create(black, c->l, create(red,\
    \ c->r, b->r));\r\n\t\t\t\tc->color = black;\r\n\t\t\t\treturn create(red, c,\
    \ create(black, b->r->l, b->r->r));\r\n\t\t\t}\r\n\t\t\treturn create(b->color,\
    \ c, b->r);\r\n\t\t}\r\n\t\telse if (a->rank > b->rank) {\r\n\t\t\tconst node_ptr\
    \ c = merge_sub(a->r, b);\r\n\t\t\tif (a->color == black && c->color == red &&\
    \ c->r->color == red) {\r\n\t\t\t\tif (a->l->color == black) return create(black,\
    \ create(red, a->l, c->l), c->r);\r\n\t\t\t\tc->color = black;\r\n\t\t\t\treturn\
    \ create(red, create(black, a->l->l, a->l->r), c);\r\n\t\t\t}\r\n\t\t\treturn\
    \ create(a->color, a->l, c);\r\n\t\t}\r\n\t\treturn create(red, a, b);\r\n\t}\r\
    \n\t\r\n\tstd::pair<node_ptr, node_ptr> split(const node_ptr & a, size_type k)\
    \ const {\r\n\t\tif (!a) return {nullptr, nullptr};\r\n\t\tif (k == 0) return\
    \ {nullptr, as_root(a)};\r\n\t\tif (k == a->size) return {as_root(a), nullptr};\r\
    \n\t\tif (k < a->l->size) {\r\n\t\t\tconst auto sp = split(a->l, k);\r\n\t\t\t\
    return {as_root(sp.first), merge(sp.second, as_root(a->r))};\r\n\t\t}\r\n\t\t\
    if (k > a->l->size) {\r\n\t\t\tconst auto sp = split(a->r, k - a->l->size);\r\n\
    \t\t\treturn {merge(as_root(a->l), sp.first), as_root(sp.second)};\r\n\t\t}\r\n\
    \t\treturn {as_root(a->l), as_root(a->r)};\r\n\t}\r\n\t\r\n\tnode_ptr insert(const\
    \ node_ptr & a, size_type k, const_reference x) const {\r\n\t\tif (!a) return\
    \ create(x);\r\n\t\tconst auto sp = split(a, k);\r\n\t\treturn merge(sp.first,\
    \ merge(create(x), sp.second));\r\n\t}\r\n\t\r\n\tnode_ptr erase(const node_ptr\
    \ & a, size_type k) const {\r\n\t\tconst auto sp = split(a, k + 1);\r\n\t\treturn\
    \ merge(split(sp.first, k).first, sp.second);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP\r\
    \n\r\n#include <cassert>\r\n#include <memory>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n#include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentRedBlackTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PersistentRedBlackTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\n\tstatic constexpr bool red = true;\r\n\tstatic constexpr\
    \ bool black = false;\r\n\tstruct Node;\r\n\tusing node_ptr = std::shared_ptr<Node>;\r\
    \n\tusing node_ref = const node_ptr &;\r\n\tusing raw_ptr = Node *;\r\n\tstruct\
    \ Node {\r\n\t\tvalue_type val;\r\n\t\tbool color;\r\n\t\tsize_type size, rank;\r\
    \n\t\tnode_ptr l, r;\r\n\t\tNode(bool color, node_ref l, node_ref r)\r\n\t\t\t\
    : color(color), size(l->size + r->size), rank(l->rank + (l->color == black)),\
    \ l(l), r(r) {}\r\n\t\tNode(const_reference val) : val(val), color(black), size(1),\
    \ rank(0), l(nullptr), r(nullptr) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tnode_ptr root\
    \ = nullptr;\r\n\t\r\n\tPersistentRedBlackTree(node_ref root) : root(root) {}\r\
    \n\t\r\n\tstatic node_ptr create(bool color, node_ref l, node_ref r) {\r\n\t\t\
    return std::make_shared<Node>(color, l, r);\r\n\t}\r\n\t\r\n\tstatic node_ptr\
    \ create(const_reference val) {\r\n\t\treturn std::make_shared<Node>(val);\r\n\
    \t}\r\n\t\r\npublic:\r\n\tPersistentRedBlackTree() = default;\r\n\t\r\n\tPersistentRedBlackTree(const\
    \ std::vector<value_type> & v)\r\n\t\t: root(v.empty() ? nullptr : build(std::begin(v),\
    \ std::end(v), 30)) {}\r\n\t\r\n\tPersistentRedBlackTree(size_type n, const_reference\
    \ x)\r\n\t\t: root(n == 0 ? nullptr : buildn(n, x, 30)) {}\r\n\t\r\n\tbool empty()\
    \ const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tsize_type size()\
    \ const noexcept {\r\n\t\treturn root ? root->size : 0;\r\n\t}\r\n\t\r\n\tvoid\
    \ clear() {\r\n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tstd::vector<value_type> enumerate()\
    \ const {\r\n\t\tstd::vector<value_type> elements;\r\n\t\tstd::stack<raw_ptr>\
    \ stk;\r\n\t\tstk.emplace(root.get());\r\n\t\twhile (!stk.empty()) {\r\n\t\t\t\
    raw_ptr q = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (q->l) {\r\n\t\t\t\tstk.emplace(q->r.get());\r\
    \n\t\t\t\tstk.emplace(q->l.get());\r\n\t\t\t}\r\n\t\t\telse elements.emplace_back(q->val);\r\
    \n\t\t}\r\n\t\treturn elements;\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree merge(const\
    \ PersistentRedBlackTree & a) const {\r\n\t\treturn merge(root, a.root);\r\n\t\
    }\r\n\t\r\n\tstd::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type\
    \ k) const {\r\n\t\tassert(k <= size());\r\n\t\tconst auto sp = split(root, k);\r\
    \n\t\treturn {sp.first, sp.second};\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree insert(size_type\
    \ k, const_reference x) const {\r\n\t\tassert(k <= size());\r\n\t\treturn insert(root,\
    \ k, x);\r\n\t}\r\n\t\r\n\tPersistentRedBlackTree erase(size_type k) const {\r\
    \n\t\tassert(k < size());\r\n\t\treturn erase(root, k);\r\n\t}\r\n\t\r\n\tconst_reference\
    \ get(size_type k) const noexcept {\r\n\t\tassert(k < size());\r\n\t\traw_ptr\
    \ q = root.get();\r\n\t\twhile (q->l) {\r\n\t\t\tif (k < q->l->size) q = (q->l).get();\r\
    \n\t\t\telse k -= q->l->size, q = (q->r).get();\r\n\t\t}\r\n\t\treturn q->val;\r\
    \n\t}\r\n\t\r\nprivate:\r\n\ttemplate<class InputIterator>\r\n\tnode_ptr build(InputIterator\
    \ first, InputIterator last, int k) const {\r\n\t\tif (first + 1 == last) return\
    \ create(*first);\r\n\t\tconst auto n = last - first;\r\n\t\tconst unsigned int\
    \ m = 1u << k;\r\n\t\tif (n > m) return merge(build(first, first + m, k - 1),\
    \ build(first + m, last, k - 1));\r\n\t\treturn build(first, last, k - 1);\r\n\
    \t}\r\n\t\r\n\tnode_ptr buildn(size_type n, const_reference x, int k) const {\r\
    \n\t\tif (n == 1) return create(x);\r\n\t\tconst unsigned int m = 1u << k;\r\n\
    \t\tif (n > m) return merge(buildn(m, x, k - 1), buildn(n - m, x, k - 1));\r\n\
    \t\treturn buildn(n, x, k - 1);\r\n\t}\r\n\t\r\n\tnode_ptr as_root(const node_ptr\
    \ & q) const {\r\n\t\tif (!q) return nullptr;\r\n\t\tif (q->color == red) return\
    \ create(black, q->l, q->r);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr merge(const\
    \ node_ptr & a, const node_ptr & b) const {\r\n\t\tif (!a) return b;\r\n\t\tif\
    \ (!b) return a;\r\n\t\tnode_ptr res = merge_sub(a, b);\r\n\t\tres->color = black;\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tnode_ptr merge_sub(const node_ptr & a, const\
    \ node_ptr & b) const {\r\n\t\tif (a->rank < b->rank) {\r\n\t\t\tnode_ptr c =\
    \ merge_sub(a, b->l);\r\n\t\t\tif (b->color == black && c->color == red && c->l->color\
    \ == red) {\r\n\t\t\t\tif (b->r->color == black) return create(black, c->l, create(red,\
    \ c->r, b->r));\r\n\t\t\t\tc->color = black;\r\n\t\t\t\treturn create(red, c,\
    \ create(black, b->r->l, b->r->r));\r\n\t\t\t}\r\n\t\t\treturn create(b->color,\
    \ c, b->r);\r\n\t\t}\r\n\t\telse if (a->rank > b->rank) {\r\n\t\t\tconst node_ptr\
    \ c = merge_sub(a->r, b);\r\n\t\t\tif (a->color == black && c->color == red &&\
    \ c->r->color == red) {\r\n\t\t\t\tif (a->l->color == black) return create(black,\
    \ create(red, a->l, c->l), c->r);\r\n\t\t\t\tc->color = black;\r\n\t\t\t\treturn\
    \ create(red, create(black, a->l->l, a->l->r), c);\r\n\t\t\t}\r\n\t\t\treturn\
    \ create(a->color, a->l, c);\r\n\t\t}\r\n\t\treturn create(red, a, b);\r\n\t}\r\
    \n\t\r\n\tstd::pair<node_ptr, node_ptr> split(const node_ptr & a, size_type k)\
    \ const {\r\n\t\tif (!a) return {nullptr, nullptr};\r\n\t\tif (k == 0) return\
    \ {nullptr, as_root(a)};\r\n\t\tif (k == a->size) return {as_root(a), nullptr};\r\
    \n\t\tif (k < a->l->size) {\r\n\t\t\tconst auto sp = split(a->l, k);\r\n\t\t\t\
    return {as_root(sp.first), merge(sp.second, as_root(a->r))};\r\n\t\t}\r\n\t\t\
    if (k > a->l->size) {\r\n\t\t\tconst auto sp = split(a->r, k - a->l->size);\r\n\
    \t\t\treturn {merge(as_root(a->l), sp.first), as_root(sp.second)};\r\n\t\t}\r\n\
    \t\treturn {as_root(a->l), as_root(a->r)};\r\n\t}\r\n\t\r\n\tnode_ptr insert(const\
    \ node_ptr & a, size_type k, const_reference x) const {\r\n\t\tif (!a) return\
    \ create(x);\r\n\t\tconst auto sp = split(a, k);\r\n\t\treturn merge(sp.first,\
    \ merge(create(x), sp.second));\r\n\t}\r\n\t\r\n\tnode_ptr erase(const node_ptr\
    \ & a, size_type k) const {\r\n\t\tconst auto sp = split(a, k + 1);\r\n\t\treturn\
    \ merge(split(sp.first, k).first, sp.second);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentRedBlackTree.hpp
  requiredBy: []
  timestamp: '2021-03-09 15:27:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/PersistentRedBlackTree.test.cpp
documentation_of: DataStructure/PersistentRedBlackTree.hpp
layout: document
title: "\u5B8C\u5168\u6C38\u7D9A\u8D64\u9ED2\u6728 (\u5E73\u8861\u4E8C\u5206\u6728\
  )"
---

# 概要

完全永続赤黒木です。
可変配列を扱います。大きさ $N$ の配列の過去の任意の状態に対し、`split`、 `merge`、データの挿入、削除が $\mathcal{O}(\log{N})$ で行うことができます。
各操作 $\mathcal{O}(\log{N})$ の空間を消費します。    

- `PersistentRedBlackTree()`
	- $\Theta(1)$ 要素数 $0$ の可変配列で初期化
- `PersistentRedBlackTree(std::vector<T> v)`
	- 時間/空間 $\Theta($`v`$)$ $v$ で初期化
- `PersistentRedBlackTree(size_t n, const T & x)`
	- 時間/空間 $\Theta(n)$ すべての値が $x$ の要素数 $n$ の可変配列で初期化
- `bool empty()`
	- $\Theta(1)$ 可変配列が空なら $true$ を返す
- `size_t size()`
	- $\Theta(1)$ 可変配列の要素数 $N$ を返す
- `void clear()`
	- $\mathcal{O}(N)$ 可変配列のすべての要素を削除
- `std::vector<T> enumerate()`
	- $\Theta(N)$ 現在の可変配列を返す  
- `PersistentRedBlackTree merge(const PersistentRedBlackTree & a)`
	- 時間/空間 $\Theta(\|$`rank` $-$ `a.rank`$\|)$ 可変配列の末尾に `a` を追加した可変配列を返す
- `pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_t k)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 可変配列の先頭 $k$ 個の要素と $k + 1$ 個目の要素以降の $2$ つの可変配列に分けてこの順で返す
- `PersistentRedBlackTree insert(size_t k, const T & x)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 前に $k$ 個の要素がある位置に $x$ を挿入した可変配列を返す
- `PersistentRedBlackTree erase(size_t k)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 先頭から `0-indexed` で $k$ 番目の要素を削除した可変配列を返す
- `const T & get(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から `0-indexed` で $k$ 番目の要素を返す

<br>

# コンストラクタ

### PersistentRedBlackTree()

要素数 $0$ の可変配列で初期化します。  
$T$ には保持したい値の型を指定します。  

**計算量**

- $\Theta(1)$

---

### PersistentRedBlackTree(std::vector&lt;T&gt; v)

$v$ で初期化します。  

**制約**

- `InputIterator` は `Random Access Iterator`

**計算量**

- $\Theta($`v`$)$

---

<br>

### PersistentRedBlackTree(size_t n, const T & x)

すべての値が $x$ の要素数 $n$ の可変配列で初期化します。  

**制約**

- `InputIterator` は `Random Access Iterator`

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

可変配列の要素数を $N$ とします。  
根から葉までのパス上 (根含まない) にある黒ノードの個数を `rank` とします。  

### bool empty()

可変配列が空なら $true$ を返します。
それ以外は $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

可変配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void clear()

可変配列のすべての要素を削除します。  

**計算量**

- $\mathcal{O}(N)$

### std::vector<T> enumerate()

現在の可変配列を返します。  

**計算量**

- $\Theta(N)$

### PersistentRedBlackTree merge(const PersistentRedBlackTree & a)

可変配列の末尾に `a` を追加した可変配列を返します。  

**計算量**

- 時間/空間 $\Theta(\|$`rank` $-$ `a.rank`$\|)$

### pair&lt;PersistentRedBlackTree, PersistentRedBlackTree&gt; split(size_t k)

可変配列の先頭 $k$ 個の要素と $k + 1$ 個目の要素以降の $2$ つの可変配列に分けてこの順で返します。  

**制約**

- $0 \leq k \leq N$

**計算量**

- 時間/空間 $\mathcal{O}(\log{N})$

### PersistentRedBlackTree insert(size_t k, const T & x)

前に $k$ 個の要素がある位置に $x$ を挿入した可変配列を返します。  

**制約**

- $0 \leq k \leq N$

**計算量**

- 時間/空間 $\mathcal{O}(\log{N})$

### PersistentRedBlackTree erase(size_t k)

先頭から `0-indexed` で $k$ 番目の要素を削除した可変配列を返します。  

**制約**

- 時間/空間 $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

### const T & get(size_t k)

先頭から `0-indexed` で $k$ 番目の要素を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PersistentRedBlackTree.hpp"
using namespace std;

int main() {
	PersistentRedBlackTree<int> rbt({0, 1, 2, 3, 4, 5, 6});
	
	cout << "empty() = " << boolalpha << rbt.empty() << endl; // false
	cout << "size = " << rbt.size() << endl; // 7
	// 0 1 2 3 4 5 6
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n';
	
	auto rbt2 = rbt.insert(0, 100);
	auto rbt3 = rbt.insert(3, 100);
	auto rbt4 = rbt.insert(7, 100);
	// 0 1 2 3 4 5 6
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n';
	// 100 0 1 2 3 4 5 6
	for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n';
	// 0 1 2 100 3 4 5 6
	for (int i : rbt3.enumerate()) cout << i << " "; cout << '\n';
	// 0 1 2 3 4 5 6 100
	for (int i : rbt4.enumerate()) cout << i << " "; cout << '\n';
	
	auto rbtm = rbt3.merge(rbt4);
	// 0 1 2 100 3 4 5 6 0 1 2 3 4 5 6 100
	for (int i : rbtm.enumerate()) cout << i << " "; cout << '\n';
	
	// 100 3 4 5 6 0 ( [3, 9) )
	auto rbts = rbtm.split(9).first.split(3).second;
	for (int i : rbts.enumerate()) cout << i << " "; cout << '\n';
	
	cout << "get(3) = " << rbts.get(3) << endl; // 5
	
	auto rbte = rbts.erase(3);
	// 100 3 4 6 0
	for (int i : rbte.enumerate()) cout << i << " "; cout << '\n';
	
	rbt = PersistentRedBlackTree<int>();
	cout << "empty() = " << boolalpha << rbt.empty() << endl; // true
	
	// 5 5 5
	for (int i : PersistentRedBlackTree<int>(3, 5).enumerate()) cout << i << " "; cout << '\n';
}
```

<br>

# TODO

TODO: メモリプールを使って高速化  

<br>

# 参考

2020/08/30: [https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf](https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf)  
2020/08/30: [http://blog.mitaki28.info/1447078746296/](http://blog.mitaki28.info/1447078746296/)  
2020/08/30: [http://algoogle.hadrori.jp/algorithm/rbtree_merge.html](http://algoogle.hadrori.jp/algorithm/rbtree_merge.html)  

<br>