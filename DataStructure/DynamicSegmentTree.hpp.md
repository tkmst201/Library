---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DynamicSegmentTree.swap.test.cpp
    title: Test/DynamicSegmentTree.swap.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DynamicSegmentTree.test.cpp
    title: Test/DynamicSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp
  bundledCode: "#line 1 \"DataStructure/DynamicSegmentTree.hpp\"\n\n\n\r\n#include\
    \ <functional>\r\n#include <cassert>\r\n#include <stack>\r\n#include <cstdint>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct DynamicSegmentTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tnode_ptr\
    \ child[2] {nullptr, nullptr};\r\n\t\tNode() = default;\r\n\t\tNode(const_reference\
    \ val) : val(val) {}\r\n\t};\r\n\t\r\n\ttemplate<typename U>\r\n\tstruct Data\
    \ {\r\n\t\tU node;\r\n\t\tsize_type l, r;\r\n\t\tData(U node, size_type l, size_type\
    \ r) : node(node), l(l), r(r) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tsize_type n, n_;\r\
    \n\tint log_n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tnode_ptr root = nullptr;\r\
    \n\t\r\npublic:\r\n\tDynamicSegmentTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), root(nullptr) {\r\n\t\t\
    n_ = 1;\r\n\t\tlog_n = 0;\r\n\t\twhile (n_ < n) n_ <<= 1, ++log_n;\r\n\t}\r\n\t\
    \r\n\tDynamicSegmentTree(const DynamicSegmentTree & rhs) {\r\n\t\t*this = rhs;\r\
    \n\t}\r\n\t\r\n\tDynamicSegmentTree(DynamicSegmentTree && rhs) {\r\n\t\t*this\
    \ = std::forward<DynamicSegmentTree>(rhs);\r\n\t}\r\n\t\r\n\t~DynamicSegmentTree()\
    \ {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\tDynamicSegmentTree & operator =(const DynamicSegmentTree\
    \ & rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\n\
    \t\t\tn_ = rhs.n_;\r\n\t\t\tlog_n = rhs.log_n;\r\n\t\t\tid_elem = rhs.id_elem;\r\
    \n\t\t\tf = rhs.f;\r\n\t\t\troot = copy_dfs(rhs.root, nullptr);\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\t\r\n\tDynamicSegmentTree & operator =(DynamicSegmentTree\
    \ && rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\
    \n\t\t\tn_ = rhs.n_;\r\n\t\t\tlog_n = rhs.log_n;\r\n\t\t\tid_elem = rhs.id_elem;\r\
    \n\t\t\tf = rhs.f;\r\n\t\t\troot = rhs.root;\r\n\t\t\trhs.root = nullptr;\r\n\t\
    \t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tclear_subtree(root);\r\
    \n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tvoid clear(size_type l, size_type r) {\r\
    \n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif ((l == 0 && r == n_)\
    \ || n_ == 1) { clear(); return; }\r\n\t\tif (l == r || !root) return;\r\n\t\t\
    std::stack<Data<node_ptr>> stk;\r\n\t\tstk.emplace(root, 0, n_);\r\n\t\twhile\
    \ (!stk.empty()) {\r\n\t\t\tauto [node, cl, cr] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (cl == cr) {\r\n\t\t\t\tnode->val = f(node->child[0] ? node->child[0]->val\
    \ : id_elem, node->child[1] ? node->child[1]->val : id_elem);\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tconst size_type m = cl + ((cr - cl) >> 1);\r\n\t\t\tstk.emplace(node,\
    \ 0, 0);\r\n\t\t\tif (m < r && node->child[1]) {\r\n\t\t\t\tif (l <= m && cr <=\
    \ r) {\r\n\t\t\t\t\tclear_subtree(node->child[1]);\r\n\t\t\t\t\tnode->child[1]\
    \ = nullptr;\r\n\t\t\t\t}\r\n\t\t\t\telse stk.emplace(node->child[1], m, cr);\r\
    \n\t\t\t}\r\n\t\t\tif (l < m && node->child[0]) {\r\n\t\t\t\tif (l <= cl && m\
    \ <= r) {\r\n\t\t\t\t\tclear_subtree(node->child[0]);\r\n\t\t\t\t\tnode->child[0]\
    \ = nullptr;\r\n\t\t\t\t}\r\n\t\t\t\telse stk.emplace(node->child[0], cl, m);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type k, const_reference x) {\r\n\t\t\
    assert(k < size());\r\n\t\tif (!root) root = new Node;\r\n\t\tnode_ptr node =\
    \ root;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tfor (int i = log_n - 1; i >= 0;\
    \ --i) {\r\n\t\t\tstk.emplace(node);\r\n\t\t\tconst bool r = k >> i & 1;\r\n\t\
    \t\tif (!node->child[r]) node->child[r] = new Node;\r\n\t\t\tnode = node->child[r];\r\
    \n\t\t}\r\n\t\tnode->val = x;\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tnode = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\tnode->val = f(node->child[0] ? node->child[0]->val\
    \ : id_elem, node->child[1] ? node->child[1]->val : id_elem);\r\n\t\t}\r\n\t}\r\
    \n\t\r\n\tvalue_type get(size_type k) const noexcept {\r\n\t\tassert(k < size());\r\
    \n\t\tif (!root) return id_elem;\r\n\t\tnode_ptr node = root;\r\n\t\tfor (int\
    \ i = log_n - 1; i >= 0; --i) {\r\n\t\t\tconst bool r = k >> i & 1;\r\n\t\t\t\
    if (!node->child[r]) return id_elem;\r\n\t\t\tnode = node->child[r];\r\n\t\t}\r\
    \n\t\treturn node->val;\r\n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\
    \tif (l == r || !root) return id_elem;\r\n\t\tvalue_type res = id_elem;\r\n\t\t\
    std::stack<Data<node_ptr>> stk;\r\n\t\tstk.emplace(root, 0, n_);\r\n\t\twhile\
    \ (!stk.empty()) {\r\n\t\t\tauto [node, cl, cr] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (l <= cl && cr <= r) res = f(res, node->val);\r\n\t\t\telse {\r\n\t\
    \t\t\tconst size_type m = cl + ((cr - cl) >> 1);\r\n\t\t\t\tif (m < r && node->child[1])\
    \ stk.emplace(node->child[1], m, cr);\r\n\t\t\t\tif (l < m && node->child[0])\
    \ stk.emplace(node->child[0], cl, m);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tvalue_type fold_all() const noexcept {\r\n\t\tif (!root) return\
    \ id_elem;\r\n\t\treturn root->val;\r\n\t}\r\n\t\r\n\tvoid swap(DynamicSegmentTree\
    \ & rhs, size_type l, size_type r) {\r\n\t\tassert(size() == rhs.size());\r\n\t\
    \tassert(id_elem == rhs.id_elem);\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (this == &rhs) return;\r\n\t\tif (l == r) return;\r\n\t\tif ((l == 0\
    \ && r == n_) || n_ == 1) { std::swap(root, rhs.root); return; }\r\n\t\tif (!root\
    \ && !rhs.root) return;\r\n\t\tif (!root) root = new Node{id_elem};\r\n\t\tif\
    \ (!rhs.root) rhs.root = new Node{id_elem};\r\n\t\tstd::stack<Data<std::pair<node_ptr,\
    \ node_ptr>>> stk;\r\n\t\tstk.emplace(std::make_pair(root, rhs.root), 0, n_);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tauto [nodes, cl, cr] = stk.top();\r\n\t\t\
    \tauto [node1, node2] = nodes;\r\n\t\t\tstk.pop();\r\n\t\t\tif (cl == cr) {\r\n\
    \t\t\t\tnode1->val = f(node1->child[0] ? node1->child[0]->val : id_elem, node1->child[1]\
    \ ? node1->child[1]->val : id_elem);\r\n\t\t\t\tnode2->val = f(node2->child[0]\
    \ ? node2->child[0]->val : id_elem, node2->child[1] ? node2->child[1]->val : id_elem);\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tconst size_type m = cl + ((cr - cl) >>\
    \ 1);\r\n\t\t\tstk.emplace(nodes, 0, 0);\r\n\t\t\tif (m < r && (node1->child[1]\
    \ || node2->child[1])) {\r\n\t\t\t\tif (l <= m && cr <= r) std::swap(node1->child[1],\
    \ node2->child[1]);\r\n\t\t\t\telse {\r\n\t\t\t\t\tif (!node1->child[1]) node1->child[1]\
    \ = new Node;\r\n\t\t\t\t\telse if (!node2->child[1]) node2->child[1] = new Node;\r\
    \n\t\t\t\t\tstk.emplace(std::make_pair(node1->child[1], node2->child[1]), m, cr);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (l < m && (node1->child[0] || node2->child[0]))\
    \ {\r\n\t\t\t\tif (l <= cl && m <= r) std::swap(node1->child[0], node2->child[0]);\r\
    \n\t\t\t\telse {\r\n\t\t\t\t\tif (!node1->child[0]) node1->child[0] = new Node;\r\
    \n\t\t\t\t\telse if (!node2->child[0]) node2->child[0] = new Node;\r\n\t\t\t\t\
    \tstk.emplace(std::make_pair(node1->child[0], node2->child[0]), cl, m);\r\n\t\t\
    \t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\nprivate:\r\n\tnode_ptr copy_dfs(const_ptr\
    \ q, node_ptr r) {\r\n\t\tif (!q) return nullptr;\r\n\t\tnode_ptr res = new Node{q->val};\r\
    \n\t\tres->child[0] = copy_dfs(q->child[0], res);\r\n\t\tres->child[1] = copy_dfs(q->child[1],\
    \ res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tvoid clear_subtree(node_ptr r) {\r\
    \n\t\tif (!r) return;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tstk.emplace(r);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (node->child[0]) stk.emplace(node->child[0]);\r\n\t\t\tif (node->child[1])\
    \ stk.emplace(node->child[1]);\r\n\t\t\tdelete node;\r\n\t\t}\r\n\t}\r\n};\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP\r\n#define INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP\r\
    \n\r\n#include <functional>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct DynamicSegmentTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tnode_ptr\
    \ child[2] {nullptr, nullptr};\r\n\t\tNode() = default;\r\n\t\tNode(const_reference\
    \ val) : val(val) {}\r\n\t};\r\n\t\r\n\ttemplate<typename U>\r\n\tstruct Data\
    \ {\r\n\t\tU node;\r\n\t\tsize_type l, r;\r\n\t\tData(U node, size_type l, size_type\
    \ r) : node(node), l(l), r(r) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tsize_type n, n_;\r\
    \n\tint log_n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tnode_ptr root = nullptr;\r\
    \n\t\r\npublic:\r\n\tDynamicSegmentTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), root(nullptr) {\r\n\t\t\
    n_ = 1;\r\n\t\tlog_n = 0;\r\n\t\twhile (n_ < n) n_ <<= 1, ++log_n;\r\n\t}\r\n\t\
    \r\n\tDynamicSegmentTree(const DynamicSegmentTree & rhs) {\r\n\t\t*this = rhs;\r\
    \n\t}\r\n\t\r\n\tDynamicSegmentTree(DynamicSegmentTree && rhs) {\r\n\t\t*this\
    \ = std::forward<DynamicSegmentTree>(rhs);\r\n\t}\r\n\t\r\n\t~DynamicSegmentTree()\
    \ {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\tDynamicSegmentTree & operator =(const DynamicSegmentTree\
    \ & rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\n\
    \t\t\tn_ = rhs.n_;\r\n\t\t\tlog_n = rhs.log_n;\r\n\t\t\tid_elem = rhs.id_elem;\r\
    \n\t\t\tf = rhs.f;\r\n\t\t\troot = copy_dfs(rhs.root, nullptr);\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\t\r\n\tDynamicSegmentTree & operator =(DynamicSegmentTree\
    \ && rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\
    \n\t\t\tn_ = rhs.n_;\r\n\t\t\tlog_n = rhs.log_n;\r\n\t\t\tid_elem = rhs.id_elem;\r\
    \n\t\t\tf = rhs.f;\r\n\t\t\troot = rhs.root;\r\n\t\t\trhs.root = nullptr;\r\n\t\
    \t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tclear_subtree(root);\r\
    \n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tvoid clear(size_type l, size_type r) {\r\
    \n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif ((l == 0 && r == n_)\
    \ || n_ == 1) { clear(); return; }\r\n\t\tif (l == r || !root) return;\r\n\t\t\
    std::stack<Data<node_ptr>> stk;\r\n\t\tstk.emplace(root, 0, n_);\r\n\t\twhile\
    \ (!stk.empty()) {\r\n\t\t\tauto [node, cl, cr] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (cl == cr) {\r\n\t\t\t\tnode->val = f(node->child[0] ? node->child[0]->val\
    \ : id_elem, node->child[1] ? node->child[1]->val : id_elem);\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tconst size_type m = cl + ((cr - cl) >> 1);\r\n\t\t\tstk.emplace(node,\
    \ 0, 0);\r\n\t\t\tif (m < r && node->child[1]) {\r\n\t\t\t\tif (l <= m && cr <=\
    \ r) {\r\n\t\t\t\t\tclear_subtree(node->child[1]);\r\n\t\t\t\t\tnode->child[1]\
    \ = nullptr;\r\n\t\t\t\t}\r\n\t\t\t\telse stk.emplace(node->child[1], m, cr);\r\
    \n\t\t\t}\r\n\t\t\tif (l < m && node->child[0]) {\r\n\t\t\t\tif (l <= cl && m\
    \ <= r) {\r\n\t\t\t\t\tclear_subtree(node->child[0]);\r\n\t\t\t\t\tnode->child[0]\
    \ = nullptr;\r\n\t\t\t\t}\r\n\t\t\t\telse stk.emplace(node->child[0], cl, m);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type k, const_reference x) {\r\n\t\t\
    assert(k < size());\r\n\t\tif (!root) root = new Node;\r\n\t\tnode_ptr node =\
    \ root;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tfor (int i = log_n - 1; i >= 0;\
    \ --i) {\r\n\t\t\tstk.emplace(node);\r\n\t\t\tconst bool r = k >> i & 1;\r\n\t\
    \t\tif (!node->child[r]) node->child[r] = new Node;\r\n\t\t\tnode = node->child[r];\r\
    \n\t\t}\r\n\t\tnode->val = x;\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tnode = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\tnode->val = f(node->child[0] ? node->child[0]->val\
    \ : id_elem, node->child[1] ? node->child[1]->val : id_elem);\r\n\t\t}\r\n\t}\r\
    \n\t\r\n\tvalue_type get(size_type k) const noexcept {\r\n\t\tassert(k < size());\r\
    \n\t\tif (!root) return id_elem;\r\n\t\tnode_ptr node = root;\r\n\t\tfor (int\
    \ i = log_n - 1; i >= 0; --i) {\r\n\t\t\tconst bool r = k >> i & 1;\r\n\t\t\t\
    if (!node->child[r]) return id_elem;\r\n\t\t\tnode = node->child[r];\r\n\t\t}\r\
    \n\t\treturn node->val;\r\n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\
    \tif (l == r || !root) return id_elem;\r\n\t\tvalue_type res = id_elem;\r\n\t\t\
    std::stack<Data<node_ptr>> stk;\r\n\t\tstk.emplace(root, 0, n_);\r\n\t\twhile\
    \ (!stk.empty()) {\r\n\t\t\tauto [node, cl, cr] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (l <= cl && cr <= r) res = f(res, node->val);\r\n\t\t\telse {\r\n\t\
    \t\t\tconst size_type m = cl + ((cr - cl) >> 1);\r\n\t\t\t\tif (m < r && node->child[1])\
    \ stk.emplace(node->child[1], m, cr);\r\n\t\t\t\tif (l < m && node->child[0])\
    \ stk.emplace(node->child[0], cl, m);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tvalue_type fold_all() const noexcept {\r\n\t\tif (!root) return\
    \ id_elem;\r\n\t\treturn root->val;\r\n\t}\r\n\t\r\n\tvoid swap(DynamicSegmentTree\
    \ & rhs, size_type l, size_type r) {\r\n\t\tassert(size() == rhs.size());\r\n\t\
    \tassert(id_elem == rhs.id_elem);\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (this == &rhs) return;\r\n\t\tif (l == r) return;\r\n\t\tif ((l == 0\
    \ && r == n_) || n_ == 1) { std::swap(root, rhs.root); return; }\r\n\t\tif (!root\
    \ && !rhs.root) return;\r\n\t\tif (!root) root = new Node{id_elem};\r\n\t\tif\
    \ (!rhs.root) rhs.root = new Node{id_elem};\r\n\t\tstd::stack<Data<std::pair<node_ptr,\
    \ node_ptr>>> stk;\r\n\t\tstk.emplace(std::make_pair(root, rhs.root), 0, n_);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tauto [nodes, cl, cr] = stk.top();\r\n\t\t\
    \tauto [node1, node2] = nodes;\r\n\t\t\tstk.pop();\r\n\t\t\tif (cl == cr) {\r\n\
    \t\t\t\tnode1->val = f(node1->child[0] ? node1->child[0]->val : id_elem, node1->child[1]\
    \ ? node1->child[1]->val : id_elem);\r\n\t\t\t\tnode2->val = f(node2->child[0]\
    \ ? node2->child[0]->val : id_elem, node2->child[1] ? node2->child[1]->val : id_elem);\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tconst size_type m = cl + ((cr - cl) >>\
    \ 1);\r\n\t\t\tstk.emplace(nodes, 0, 0);\r\n\t\t\tif (m < r && (node1->child[1]\
    \ || node2->child[1])) {\r\n\t\t\t\tif (l <= m && cr <= r) std::swap(node1->child[1],\
    \ node2->child[1]);\r\n\t\t\t\telse {\r\n\t\t\t\t\tif (!node1->child[1]) node1->child[1]\
    \ = new Node;\r\n\t\t\t\t\telse if (!node2->child[1]) node2->child[1] = new Node;\r\
    \n\t\t\t\t\tstk.emplace(std::make_pair(node1->child[1], node2->child[1]), m, cr);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (l < m && (node1->child[0] || node2->child[0]))\
    \ {\r\n\t\t\t\tif (l <= cl && m <= r) std::swap(node1->child[0], node2->child[0]);\r\
    \n\t\t\t\telse {\r\n\t\t\t\t\tif (!node1->child[0]) node1->child[0] = new Node;\r\
    \n\t\t\t\t\telse if (!node2->child[0]) node2->child[0] = new Node;\r\n\t\t\t\t\
    \tstk.emplace(std::make_pair(node1->child[0], node2->child[0]), cl, m);\r\n\t\t\
    \t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\nprivate:\r\n\tnode_ptr copy_dfs(const_ptr\
    \ q, node_ptr r) {\r\n\t\tif (!q) return nullptr;\r\n\t\tnode_ptr res = new Node{q->val};\r\
    \n\t\tres->child[0] = copy_dfs(q->child[0], res);\r\n\t\tres->child[1] = copy_dfs(q->child[1],\
    \ res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tvoid clear_subtree(node_ptr r) {\r\
    \n\t\tif (!r) return;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tstk.emplace(r);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (node->child[0]) stk.emplace(node->child[0]);\r\n\t\t\tif (node->child[1])\
    \ stk.emplace(node->child[1]);\r\n\t\t\tdelete node;\r\n\t\t}\r\n\t}\r\n};\r\n\
    \r\n#endif // INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2021-03-07 13:12:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DynamicSegmentTree.test.cpp
  - Test/DynamicSegmentTree.swap.test.cpp
documentation_of: DataStructure/DynamicSegmentTree.hpp
layout: document
title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# 概要

配列を扱うデータ構造で、[セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp)の亜種です。  
必要なノードのみ動的に作成することで、要素数 $N$ の配列、$M$ 回の更新に対して、空間計算量 $\mathcal{O}(\min(N, M \log{M}))$ で、1 点更新や区間畳み込み、区間の単位元初期化、他の動的セグメント木との区間スワップを $\mathcal{O}(\log{N})$ で行うことができます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような演算が扱えます。例: `+`, `xor`, `min`, `gcd`, `関数の合成` など。  

- `DynamicSegmentTree(size_t n, const T & id_elem, const F & f)`
	- $\Theta(1)$ 要素数 $n$ で初期化
- `DynamicSegmentTree(const DynamicSegmentTree & rhs)`
	- `this` 、`rhs` の単位元ではない要素の個数をそれぞれ $M_1, M_2$ として $\mathcal{O}(\min(\|$`this`$\|, M_1\log \|$`this`$\|) + \min(\|$`rhs`$\|, M_2\log \|$`rhs`$\|))$ `rhs` をコピー
- `DynamicSegmentTree(DynamicSegmentTree && rhs)`
	- `this` の単位元ではない要素の個数を $M$ として $\mathcal{O}(\min(\|$`this`$\|, M\log \|$`this`$\|))$ `rhs` をムーブ
- `void clear()`
	- 単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(N, M\log{N}))$ メモリを解法し、すべての要素の値を単位元で初期化
- `void clear(size_t l, size_t r)`
	- 対象に含まれる単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(r - l + \log{N}, M\log{N}))$ $A_l, \ldots, A_{r-1}$ のメモリを解法し、単位元で初期化
- `size_t size()`
	- $\Theta(1)$ 配列の要素数 $N$ を返す
- `void set(size_t k, const T & x)`
	- $\Theta(\log{N})$ $A_k = x$
- `T get(size_t k)`
	- $\mathcal{O}(\log{N})$ $A_k$ を返す
- `T fold(size_t l, size_t r)`
	- $\mathcal{O}(\log{N})$ 半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返す
- `T fold_all()`
	- $\Theta(1)$ $fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返す
- `void swap(DynamicSegmentTree & rhs, size_t l, size_t r)`
	- $\mathcal{O}(\log{N})$ `rhs` と区間 $[l, r)$ をスワップ

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, f,$ `id_elem`$)$ はモノイド

---

### DynamicSegmentTree(size_t n, const T & id_elem, const F & f)

要素数 $n$ で初期化します。
初期値は単位元 `id_elem` です。  

**計算量**

- $\Theta(1)$

---

### DynamicSegmentTree(const DynamicSegmentTree & rhs)

動的セグメント木 `rhs` をコピーします。  

**計算量**

- `this` 、`rhs` の単位元ではない要素の個数をそれぞれ $M_1, M_2$ として $\mathcal{O}(\min(\|$`this`$\|, M_1\log \|$`this`$\|) + \min(\|$`rhs`$\|, M_2\log \|$`rhs`$\|))$

---

### DynamicSegmentTree(DynamicSegmentTree && rhs)

動的セグメント木 `rhs` をムーブします。
ムーブ後の `rhs` はすべての要素の値は単位元で初期化されます。  

**計算量**

- `this` の単位元ではない要素の個数を $M$ として $\mathcal{O}(\min(\|$`this`$\|, M\log \|$`this`$\|))$

---

<br>

# メンバ関数

以下、要素数 $N$ の配列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。
二項演算は $f$ です。  

---

### void clear()

メモリを解法し、すべての要素の値を単位元で初期化します。  

**計算量**

- 単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(N, M\log{N}))$

---

### :warning: void clear(size_t l, size_t r)

$A_l, \ldots, A_{r-1}$ のメモリを解法し、単位元で初期化します。
$l = r$ のときは何も行いません。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- 対象に含まれる単位元では無い要素の個数を $M$ として $\mathcal{O}(\min(r - l + \log{N}, M\log{N}))$

---

### size_t size()

配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void set(size_t k, const T & x)

$A_k$ を $x$ に変更します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\Theta(\log{N})$

---

### T get(size_t k)

$A_k$ を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T fold(size_t l, size_t r)

半開区間 $[l, r)$ の演算結果 $f(A_l, f(A_{l+1}, f(\ldots, f(A_{r-2}, A_{r-1}))\ldots)$ を返します。
$l = r$ のときは単位元を返します。  

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $\mathcal{O}(\log{N})$

---

### T fold_all()

$fold(0,N)$ の計算結果 $f(A_0, f(A_1, f(\ldots, f(A_{N-2}, A_{N-1}))\ldots))$ を返します。  

**計算量**

- $\Theta(1)$

---

### void swap(DynamicSegmentTree & rhs, size_t l, size_t r)

`rhs` が扱う配列を $B_0, B_1, \ldots, B_{N-1}$ として、$A_l, \ldots, A_{r-1}$ と $B_l, \ldots, B_{r-1}$ の部分をスワップします。  


**制約**

- $N =$ $\|$`rhs`$\|$
- `rhs` と代数構造が等しい

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/DynamicSegmentTree.hpp"
using namespace std;

int main() {
	DynamicSegmentTree<int> seg(10, 0, [](auto x, auto y) { return x + y; });
	
	cout << "size() = " << seg.size() << endl; // 10
	
	seg.set(0, 1);
	seg.set(1, 2);
	seg.set(3, 3);
	seg.set(5, 4);
	seg.set(6, 5);
	seg.set(7, 6);
	seg.set(9, 7);
	// idx 0 1 2 3 4 5 6 7 8 9
	//     1 2 0 3 0 4 5 6 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	
	cout << "fold_all() = " << seg.fold_all() << endl; // 28 ( = 1+2+...+7 )
	cout << "fold(1, 6) = " << seg.fold(1, 6) << endl; // 9 ([2, 0, 3, 0, 4])
	
	seg.clear(5, 7);
	cout << "seg.clear(5, 7)" << endl;
	// 1 2 0 3 0 0 0 6 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	
	DynamicSegmentTree<int> seg2(10, 0, [](auto x, auto y) { return x + y; });
	seg2.set(1, -4);
	seg2.set(3, -5);
	seg2.set(5, -8);
	seg2.set(6, -9);
	// 0 -4 0 -5 0 -8 -9 0 0 0
	for (int i = 0; i < seg2.size(); ++i) cout << seg2.get(i) << " \n"[i + 1 == seg2.size()];
	
	cout << "swap(2, 8)" << endl;
	seg.swap(seg2, 2, 8);
	// 1  2 0 -5 0 -8 -9 0 0 7
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	// 0 -4 0  3 0  0  0 6 0 0
	for (int i = 0; i < seg2.size(); ++i) cout << seg2.get(i) << " \n"[i + 1 == seg2.size()];
	
	
	/*
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		1 2 0 -5 0 -8 -9 0 0 7
		0 0 0 0 0 0 0 0 0 0
	*/
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	{
		auto segt = seg;
		for (int i = 0; i < segt.size(); ++i) cout << segt.get(i) << " \n"[i + 1 == segt.size()];
	}
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
	{
		auto segt = std::move(seg);
		for (int i = 0; i < segt.size(); ++i) cout << segt.get(i) << " \n"[i + 1 == segt.size()];
	}
	for (int i = 0; i < seg.size(); ++i) cout << seg.get(i) << " \n"[i + 1 == seg.size()];
}
```

<br>

# TODO

TODO: `clear(l, r)` の test の追加  

# 参考

2021/03/04: [https://kazuma8128.hatenablog.com/entry/2018/11/29/093827](https://kazuma8128.hatenablog.com/entry/2018/11/29/093827)  

<br>