---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.hpp
    title: "\u5B8C\u5168\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentUnionFind.hpp
    title: "\u5B8C\u5168\u6C38\u7D9A Union Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"Test/PersistentUnionFind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\r\n#line 1 \"DataStructure/PersistentUnionFind.hpp\"\
    \n\n\n\r\n#line 1 \"DataStructure/PersistentArray.hpp\"\n\n\n\r\n#include <memory>\r\
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
    \t}\r\n\t\treturn k == 0 && node ? node->val : def_val;\r\n\t}\r\n};\r\n\r\n\n\
    #line 5 \"DataStructure/PersistentUnionFind.hpp\"\n\r\n#include <cstdint>\r\n\
    #line 8 \"DataStructure/PersistentUnionFind.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PersistentUnionFind.hpp\r\
    \n */\r\ntemplate<int M>\r\nstruct PersistentUnionFind {\r\n\tstatic_assert(M\
    \ > 1);\r\n\t\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tusing\
    \ parray_type = PersistentArray<int, M>;\r\n\tparray_type dat;\r\n\t\r\npublic:\r\
    \n\tPersistentUnionFind() : dat(-1) {}\r\n\t\r\nprivate:\r\n\tPersistentUnionFind(const\
    \ parray_type & dat) : dat(dat) {}\r\n\t\r\npublic:\r\n\tsize_type find(size_type\
    \ x) const noexcept {\r\n\t\treturn find_sub(x).first;\r\n\t}\r\n\t\r\n\tsize_type\
    \ size(size_type x) const noexcept {\r\n\t\treturn find_sub(x).second;\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tstd::pair<size_type, int> find_sub(size_type x) const noexcept\
    \ {\r\n\t\tint d;\r\n\t\tfor (d = dat.get(x); d >= 0; d = dat.get(x)) x = d;\r\
    \n\t\treturn {x, -d};\r\n\t}\r\n\t\r\npublic:\r\n\tPersistentUnionFind unite(size_type\
    \ x, size_type y) const {\r\n\t\tif (x == y) return *this;\r\n\t\tauto px = find_sub(x),\
    \ py = find_sub(y);\r\n\t\tif (px.first == py.first) return *this;\r\n\t\tif (px.second\
    \ > py.second) std::swap(px, py);\r\n\t\treturn dat.set(px.first, py.first).set(py.first,\
    \ -(px.second + py.second));\r\n\t}\r\n\t\r\n\tvoid destructive_unite(size_type\
    \ x, size_type y) {\r\n\t\tif (x == y) return;\r\n\t\tauto px = find_sub(x), py\
    \ = find_sub(y);\r\n\t\tif (px.first == py.first) return;\r\n\t\tif (px.second\
    \ > py.second) std::swap(px, py);\r\n\t\tdat.destructive_set(px.first, py.first);\r\
    \n\t\tdat.destructive_set(py.first, -(px.second + py.second));\r\n\t}\r\n\t\r\n\
    \tbool issame(size_type x, size_type y) const noexcept {\r\n\t\treturn x == y\
    \ ? true : find(x) == find(y);\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/PersistentUnionFind.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\
    \n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing PUF = PersistentUnionFind<6>;\r\
    \n\tstd::vector<PUF> hist(Q + 1);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\
    \t\tint t, k, u, v;\r\n\t\tscanf(\"%d %d %d %d\", &t, &k, &u, &v);\r\n\t\t++k;\r\
    \n\t\tif (t == 0) hist[i + 1] = (hist[k].unite(u, v));\r\n\t\telse printf(\"%d\\\
    n\", hist[k].issame(u, v));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n\r\n#include \"DataStructure/PersistentUnionFind.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N,\
    \ &Q);\r\n\t\r\n\tusing PUF = PersistentUnionFind<6>;\r\n\tstd::vector<PUF> hist(Q\
    \ + 1);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tint t, k, u, v;\r\n\t\t\
    scanf(\"%d %d %d %d\", &t, &k, &u, &v);\r\n\t\t++k;\r\n\t\tif (t == 0) hist[i\
    \ + 1] = (hist[k].unite(u, v));\r\n\t\telse printf(\"%d\\n\", hist[k].issame(u,\
    \ v));\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/PersistentUnionFind.hpp
  - DataStructure/PersistentArray.hpp
  isVerificationFile: true
  path: Test/PersistentUnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PersistentUnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/PersistentUnionFind.test.cpp
- /verify/Test/PersistentUnionFind.test.cpp.html
title: Test/PersistentUnionFind.test.cpp
---
