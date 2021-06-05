---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"Test/BinaryIndexedTree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \r\n\r\n#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <functional>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), node(n + 1, id_elem) {}\r\
    \n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, const_reference x) noexcept {\r\n\t\tassert(i < size());\r\
    \n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i], x);\r\n\
    \t}\r\n\t\r\n\tvalue_type sum(size_type i) const noexcept {\r\n\t\tassert(i <=\
    \ size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ res = f(node[i], res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem,\
    \ w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\
    \t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\
    \n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/BinaryIndexedTree.test.cpp\"\
    \n\r\n#include <cstdio>\r\nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\", &n,\
    \ &q);\r\n\tBinaryIndexedTree<int> bit(n, 0, [](auto &&x, auto &&y) { return x\
    \ + y; });\r\n\t\r\n\twhile (q--) {\r\n\t\tint com, x, y;\r\n\t\tscanf(\"%d %d\
    \ %d\", &com, &x, &y);\r\n\t\tif (com == 0) bit.add(x - 1, y);\r\n\t\telse printf(\"\
    %d\\n\", bit.sum(y) - bit.sum(x - 1));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \r\n\r\n#include \"DataStructure/BinaryIndexedTree.hpp\"\r\n\r\n#include <cstdio>\r\
    \nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\", &n, &q);\r\n\tBinaryIndexedTree<int>\
    \ bit(n, 0, [](auto &&x, auto &&y) { return x + y; });\r\n\t\r\n\twhile (q--)\
    \ {\r\n\t\tint com, x, y;\r\n\t\tscanf(\"%d %d %d\", &com, &x, &y);\r\n\t\tif\
    \ (com == 0) bit.add(x - 1, y);\r\n\t\telse printf(\"%d\\n\", bit.sum(y) - bit.sum(x\
    \ - 1));\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: Test/BinaryIndexedTree.test.cpp
  requiredBy: []
  timestamp: '2021-03-09 16:44:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/Test/BinaryIndexedTree.test.cpp
- /verify/Test/BinaryIndexedTree.test.cpp.html
title: Test/BinaryIndexedTree.test.cpp
---
