---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DynamicSegmentTree.hpp
    title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/EulerTour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Hupc/2871?year=2018
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Hupc/2871?year=2018
  bundledCode: "#line 1 \"Test/DynamicSegmentTree.swap.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Hupc/2871?year=2018\"\
    \r\n\r\n#line 1 \"GraphTheory/EulerTour.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <stack>\r\n#include <utility>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp\r\n */\r\ntemplate<bool\
    \ EDGE>\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\n\tusing Graph\
    \ = std::vector<std::vector<int>>;\r\n\t\r\nprivate:\r\n\tint n, root;\r\n\tstd::vector<int>\
    \ in_, out_, par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const Graph & g, int\
    \ root = 0)\r\n\t\t: n(g.size()), root(root), in_(size(), -1), out_(size(), -1),\
    \ par_(n, -1), g_idx(n << 1, -1) {\r\n\t\tstd::stack<std::pair<int, int>> stk;\r\
    \n\t\tint num = 0;\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root, 0);\r\n\t\
    \twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, i] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (i < g[u].size()) {\r\n\t\t\t\tconst int v = g[u][i];\r\n\t\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\t\tassert(v != u);\r\n\t\t\t\tstk.emplace(u, i + 1);\r\
    \n\t\t\t\tif (v == par_[u]) g_idx[u << 1 | 1] = i;\r\n\t\t\t\telse {\r\n\t\t\t\
    \t\tin_[v] = num++;\r\n\t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tg_idx[v << 1] = i;\r\
    \n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\
    \t\tout_[u] = num;\r\n\t\t\t\tif (EDGE) ++num;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\
    \r\n\tsize_type size() const noexcept {\r\n\t\treturn EDGE ? n << 1 : n;\r\n\t\
    }\r\n\t\r\n\tint par(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\
    \n\t\treturn par_[k];\r\n\t}\r\n\t\r\n\tint in(int k) const noexcept {\r\n\t\t\
    assert(0 <= k && k < n);\r\n\t\treturn in_[k];\r\n\t}\r\n\t\r\n\tint out(int k)\
    \ const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn out_[k];\r\n\t\
    }\r\n\t\r\n\tstd::pair<int, int> par_from(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < n);\r\n\t\treturn {par_[k], g_idx[k << 1]};\r\n\t}\r\n\t\r\n\tint\
    \ par_to(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn\
    \ g_idx[k << 1 | 1];\r\n\t}\r\n};\r\n\r\n\n#line 1 \"DataStructure/DynamicSegmentTree.hpp\"\
    \n\n\n\r\n#include <functional>\r\n#line 7 \"DataStructure/DynamicSegmentTree.hpp\"\
    \n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp\r\
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
    \r\n\n#line 5 \"Test/DynamicSegmentTree.swap.test.cpp\"\n\r\n#include <cstdio>\r\
    \n#line 8 \"Test/DynamicSegmentTree.swap.test.cpp\"\n\r\nint main() {\r\n\tint\
    \ N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tEulerTour<false>::Graph g(N);\r\
    \n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\
    \tg[p - 1].emplace_back(i);\r\n\t}\r\n\t\r\n\tEulerTour<false> et(g, 0);\r\n\t\
    DynamicSegmentTree<int> seg(et.size(), 0, [](auto x, auto y) { return x + y; });\r\
    \n\tauto segr = seg;\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tchar c;\r\
    \n\t\tscanf(\" %c\", &c);\r\n\t\tif (c == 'G') seg.set(et.in(i), 1);\r\n\t\telse\
    \ segr.set(et.in(i), 1);\r\n\t}\r\n\t\r\n\twhile (Q--) {\r\n\t\tint v;\r\n\t\t\
    scanf(\"%d\", &v);\r\n\t\t--v;\r\n\t\tseg.swap(segr, et.in(v), et.out(v));\r\n\
    \t\tconst int x = seg.fold_all();\r\n\t\tconst int y = N - x;\r\n\t\tputs(x >\
    \ y ? \"broccoli\" : \"cauliflower\");\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Hupc/2871?year=2018\"\
    \r\n\r\n#include \"GraphTheory/EulerTour.hpp\"\r\n#include \"DataStructure/DynamicSegmentTree.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <utility>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tEulerTour<false>::Graph g(N);\r\
    \n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\
    \tg[p - 1].emplace_back(i);\r\n\t}\r\n\t\r\n\tEulerTour<false> et(g, 0);\r\n\t\
    DynamicSegmentTree<int> seg(et.size(), 0, [](auto x, auto y) { return x + y; });\r\
    \n\tauto segr = seg;\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tchar c;\r\
    \n\t\tscanf(\" %c\", &c);\r\n\t\tif (c == 'G') seg.set(et.in(i), 1);\r\n\t\telse\
    \ segr.set(et.in(i), 1);\r\n\t}\r\n\t\r\n\twhile (Q--) {\r\n\t\tint v;\r\n\t\t\
    scanf(\"%d\", &v);\r\n\t\t--v;\r\n\t\tseg.swap(segr, et.in(v), et.out(v));\r\n\
    \t\tconst int x = seg.fold_all();\r\n\t\tconst int y = N - x;\r\n\t\tputs(x >\
    \ y ? \"broccoli\" : \"cauliflower\");\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/EulerTour.hpp
  - DataStructure/DynamicSegmentTree.hpp
  isVerificationFile: true
  path: Test/DynamicSegmentTree.swap.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DynamicSegmentTree.swap.test.cpp
layout: document
redirect_from:
- /verify/Test/DynamicSegmentTree.swap.test.cpp
- /verify/Test/DynamicSegmentTree.swap.test.cpp.html
title: Test/DynamicSegmentTree.swap.test.cpp
---
