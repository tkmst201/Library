---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentRedBlackTree.hpp
    title: "\u5B8C\u5168\u6C38\u7D9A\u8D64\u9ED2\u6728 (\u5E73\u8861\u4E8C\u5206\u6728\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Test/PersistentRedBlackTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\r\n\r\n#line 1 \"DataStructure/PersistentRedBlackTree.hpp\"\
    \n\n\n\r\n#include <cassert>\r\n#include <memory>\r\n#include <utility>\r\n#include\
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
    \ merge(split(sp.first, k).first, sp.second);\r\n\t}\r\n};\r\n\r\n\n#line 4 \"\
    Test/PersistentRedBlackTree.test.cpp\"\n\r\n#include <cstdio>\r\n#line 7 \"Test/PersistentRedBlackTree.test.cpp\"\
    \n#include <algorithm>\r\n\r\nint main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\
    \n\t\r\n\tusing ll = long long;\r\n\t\r\n\tstd::vector<int> q(Q);\r\n\tstd::vector<ll>\
    \ k(Q), v(Q);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tscanf(\"%d %lld\"\
    , &q[i], &k[i]);\r\n\t\tif (q[i] == 0) scanf(\"%lld\", &v[i]);\r\n\t}\r\n\t\r\n\
    \tauto compress = [](auto &&v, auto &&cv) -> void {\r\n\t\tfor (auto &&u : v)\
    \ cv.emplace_back(u);\r\n\t\tstd::sort(std::begin(cv), std::end(cv));\r\n\t\t\
    cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\n\t\tfor\
    \ (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);\r\
    \n\t};\r\n\t\r\n\tstd::vector<ll> cv;\r\n\tcompress(k, cv);\r\n\tPersistentRedBlackTree<ll>\
    \ tree(cv.size(), 0);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tif (q[i]\
    \ == 0) {\r\n\t\t\ttree = tree.erase(k[i]);\r\n\t\t\ttree = tree.insert(k[i],\
    \ v[i]);\r\n\t\t}\r\n\t\telse printf(\"%lld\\n\", tree.get(k[i]));\r\n\t}\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    \r\n#include \"DataStructure/PersistentRedBlackTree.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n#include <algorithm>\r\n\r\nint main() {\r\n\tint Q;\r\n\
    \tscanf(\"%d\", &Q);\r\n\t\r\n\tusing ll = long long;\r\n\t\r\n\tstd::vector<int>\
    \ q(Q);\r\n\tstd::vector<ll> k(Q), v(Q);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i)\
    \ {\r\n\t\tscanf(\"%d %lld\", &q[i], &k[i]);\r\n\t\tif (q[i] == 0) scanf(\"%lld\"\
    , &v[i]);\r\n\t}\r\n\t\r\n\tauto compress = [](auto &&v, auto &&cv) -> void {\r\
    \n\t\tfor (auto &&u : v) cv.emplace_back(u);\r\n\t\tstd::sort(std::begin(cv),\
    \ std::end(cv));\r\n\t\tcv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\
    \n\t\tfor (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u)\
    \ - std::begin(cv);\r\n\t};\r\n\t\r\n\tstd::vector<ll> cv;\r\n\tcompress(k, cv);\r\
    \n\tPersistentRedBlackTree<ll> tree(cv.size(), 0);\r\n\t\r\n\tfor (int i = 0;\
    \ i < Q; ++i) {\r\n\t\tif (q[i] == 0) {\r\n\t\t\ttree = tree.erase(k[i]);\r\n\t\
    \t\ttree = tree.insert(k[i], v[i]);\r\n\t\t}\r\n\t\telse printf(\"%lld\\n\", tree.get(k[i]));\r\
    \n\t}\r\n}"
  dependsOn:
  - DataStructure/PersistentRedBlackTree.hpp
  isVerificationFile: true
  path: Test/PersistentRedBlackTree.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 15:29:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PersistentRedBlackTree.test.cpp
layout: document
redirect_from:
- /verify/Test/PersistentRedBlackTree.test.cpp
- /verify/Test/PersistentRedBlackTree.test.cpp.html
title: Test/PersistentRedBlackTree.test.cpp
---
