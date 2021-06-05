---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PotentializedUnionFind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"Test/PotentializedUnionFind.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\r\n\r\n#line\
    \ 1 \"DataStructure/PotentializedUnionFind.hpp\"\n\n\n\r\n#include <cassert>\r\
    \n#include <vector>\r\n#include <functional>\r\n#include <utility>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PotentializedUnionFind {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\tusing G = std::function<value_type (const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tG g;\r\n\tstd::vector<int>\
    \ dat;\r\n\tstd::vector<value_type> val;\r\n\t\r\npublic:\r\n\tPotentializedUnionFind(size_type\
    \ n, const_reference id_elem, const F & f, const G & g = [](const_reference x)\
    \ { return -x; })\r\n\t\t: n(n), id_elem(id_elem), f(f), g(g), dat(n, -1), val(n,\
    \ id_elem) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type find(size_type\
    \ x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return x;\r\n\t\t\
    const size_type p = dat[x];\r\n\t\tdat[x] = find(p);\r\n\t\tval[x] = f(val[x],\
    \ val[p]);\r\n\t\treturn dat[x];\r\n\t}\r\n\t\r\n\tvoid merge(size_type x, size_type\
    \ y, const_reference w) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\
    \n\t\tsize_type rx = find(x), ry = find(y);\r\n\t\tassert(rx != ry);\r\n\t\tvalue_type\
    \ v = f(val[y], g(f(val[x], w)));\r\n\t\tif (dat[rx] < dat[ry]) {\r\n\t\t\tstd::swap(rx,\
    \ ry);\r\n\t\t\tv = g(v);\r\n\t\t}\r\n\t\tdat[ry] += dat[rx];\r\n\t\tdat[rx] =\
    \ ry;\r\n\t\tval[rx] = std::move(v);\r\n\t}\r\n\t\r\n\tvalue_type diff(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tconst size_type rx = find(x), ry = find(y);\r\n\t\tassert(rx == ry);\r\n\t\t\
    return f(val[y], g(val[x]));\r\n\t}\r\n\t\r\n\tbool issame(size_type x, size_type\
    \ y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x)\
    \ == find(y);\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/PotentializedUnionFind.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, M;\r\n\twhile(scanf(\"\
    %d %d\", &N, &M), N || M) {\r\n\t\tPotentializedUnionFind<int> puf(N, 0, [](int\
    \ a, int b){ return a + b; });\r\n\t\tfor (int i = 0; i < M; ++i) {\r\n\t\t\t\
    char c;\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\" %c %d %d\", &c, &a, &b);\r\n\t\t\t\
    --a; --b;\r\n\t\t\t\r\n\t\t\tif (c == '!') {\r\n\t\t\t\tint w;\r\n\t\t\t\tscanf(\"\
    %d\", &w);\r\n\t\t\t\tif (!puf.issame(a, b)) puf.merge(a, b, w);\r\n\t\t\t}\r\n\
    \t\t\telse {\r\n\t\t\t\tif (puf.issame(a, b)) printf(\"%d\\n\", puf.diff(a, b));\r\
    \n\t\t\t\telse puts(\"UNKNOWN\");\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \r\n\r\n#include \"DataStructure/PotentializedUnionFind.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\n\r\nint main() {\r\n\tint N, M;\r\n\twhile(scanf(\"%d %d\", &N,\
    \ &M), N || M) {\r\n\t\tPotentializedUnionFind<int> puf(N, 0, [](int a, int b){\
    \ return a + b; });\r\n\t\tfor (int i = 0; i < M; ++i) {\r\n\t\t\tchar c;\r\n\t\
    \t\tint a, b;\r\n\t\t\tscanf(\" %c %d %d\", &c, &a, &b);\r\n\t\t\t--a; --b;\r\n\
    \t\t\t\r\n\t\t\tif (c == '!') {\r\n\t\t\t\tint w;\r\n\t\t\t\tscanf(\"%d\", &w);\r\
    \n\t\t\t\tif (!puf.issame(a, b)) puf.merge(a, b, w);\r\n\t\t\t}\r\n\t\t\telse\
    \ {\r\n\t\t\t\tif (puf.issame(a, b)) printf(\"%d\\n\", puf.diff(a, b));\r\n\t\t\
    \t\telse puts(\"UNKNOWN\");\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n"
  dependsOn:
  - DataStructure/PotentializedUnionFind.hpp
  isVerificationFile: true
  path: Test/PotentializedUnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-03-09 20:19:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PotentializedUnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/PotentializedUnionFind.test.cpp
- /verify/Test/PotentializedUnionFind.test.cpp.html
title: Test/PotentializedUnionFind.test.cpp
---
