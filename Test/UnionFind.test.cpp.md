---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.hpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020 (Union-Find)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \r\n\r\n#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp\r\
    \n */\r\nstruct UnionFind {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tstd::vector<int> dat;\r\n\t\r\npublic:\r\n\texplicit UnionFind(size_type\
    \ n) : n(n), dat(n, -1) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\
    \n\t\tassert(x < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type\
    \ find(size_type x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return\
    \ x;\r\n\t\treturn dat[x] = find(dat[x]);\r\n\t}\r\n\t\r\n\tvoid unite(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y) return;\r\n\t\tif (dat[x]\
    \ < dat[y]) std::swap(x, y);\r\n\t\tdat[y] += dat[x];\r\n\t\tdat[x] = y;\r\n\t\
    }\r\n\t\r\n\tbool issame(size_type x, size_type y) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\
    \n\r\n\n#line 4 \"Test/UnionFind.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint\
    \ main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\tUnionFind uf(N);\r\
    \n\twhile (Q--) {\r\n\t\tint t, u, v;\r\n\t\tscanf(\"%d %d %d\", &t, &u, &v);\r\
    \n\t\tif (t == 0) uf.unite(u, v);\r\n\t\telse printf(\"%d\\n\", uf.issame(u, v));\r\
    \n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"DataStructure/UnionFind.hpp\"\r\n\r\n#include <cstdio>\r\n\r\nint main() {\r\
    \n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\tUnionFind uf(N);\r\n\twhile\
    \ (Q--) {\r\n\t\tint t, u, v;\r\n\t\tscanf(\"%d %d %d\", &t, &u, &v);\r\n\t\t\
    if (t == 0) uf.unite(u, v);\r\n\t\telse printf(\"%d\\n\", uf.issame(u, v));\r\n\
    \t}\r\n}"
  dependsOn:
  - DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: Test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-03-09 18:26:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/UnionFind.test.cpp
- /verify/Test/UnionFind.test.cpp.html
title: Test/UnionFind.test.cpp
---
