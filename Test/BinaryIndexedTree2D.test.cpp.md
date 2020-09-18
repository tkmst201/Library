---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree2D.hpp
    title: DataStructure/BinaryIndexedTree2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
  bundledCode: "#line 1 \"Test/BinaryIndexedTree2D.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\r\n\r\n#line 1\
    \ \"DataStructure/BinaryIndexedTree2D.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <functional>\r\n\r\n/*\r\nlast-updated: 2020/08/15\r\n\
    \r\n# \u4ED5\u69D8\r\nBinaryIndexedTree2D(size_type h, size_type w) :\r\n\th \\\
    times w \u306E\u8868\u3092\u69CB\u7BC9\r\n\r\nvoid add(size_type i, size_type\
    \ j, const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log h log\
    \ w)\r\n\t\u70B9 (i, j) \u306B\u5024 x \u3092\u52A0\u7B97\r\n\r\nvalue_type sum(size_type\
    \ i, size_type j) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log h log\
    \ w)\r\n\t[0, i) \\times [0, j) \u306E\u5408\u8A08\u3092\u8FD4\u3059\r\n\r\n\t\
    // [i1, i2) x [j1, j2)\r\nvalue_type sum(size_type i1, size_type j1, size_type\
    \ i2, size_type j2) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log h\
    \ log w)\r\n\t[i1, i2) \\times [j1, j2) \u306E\u5408\u8A08\u3092\u8FD4\u3059\r\
    \n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/, 2020/08/15\r\
    \n*/\r\n\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree2D {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\n\tBinaryIndexedTree2D(size_type h, size_type w) : h(h),\
    \ w(w) {\r\n\t\tnode.resize(h + 1, std::vector<value_type>(w + 1));\r\n\t}\r\n\
    \t\r\n\tvoid add(size_type i, size_type j, const_reference x) {\r\n\t\tassert(i\
    \ < h);\r\n\t\tassert(j < w);\r\n\t\t++i; ++j;\r\n\t\tfor (; i <= h; i += i &\
    \ -i) {\r\n\t\t\tfor (size_type k = j; k <= w; k += k & -k) {\r\n\t\t\t\tnode[i][k]\
    \ += x;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\t// [0, i) x [0, j)\r\n\tvalue_type\
    \ sum(size_type i, size_type j) const {\r\n\t\tassert(i <= h);\r\n\t\tassert(j\
    \ <= w);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (; i > 0; i -= i & -i) {\r\n\t\t\
    \tfor (size_type k = j; k > 0; k -= k & -k) {\r\n\t\t\t\tres += node[i][k];\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t// [i1, i2) x [j1, j2)\r\
    \n\tvalue_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const\
    \ {\r\n\t\tassert(i1 < i2);\r\n\t\tassert(j1 < j2);\r\n\t\tassert(i2 <= h);\r\n\
    \t\tassert(j2 <= w);\r\n\t\treturn sum(i2, j2) - sum(i2, j1) - sum(i1, j2) + sum(i1,\
    \ j1);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ node;\r\n};\r\n\r\n\n#line 4 \"Test/BinaryIndexedTree2D.test.cpp\"\n\r\n#include\
    \ <cstdio>\r\n#line 7 \"Test/BinaryIndexedTree2D.test.cpp\"\n#include <queue>\r\
    \n#include <utility>\r\n\r\nint main() {\r\n\tint H, W, T, Q;\r\n\tscanf(\"%d\
    \ %d %d %d\", &H, &W, &T, &Q);\r\n\tstd::vector<int> t(Q), c(Q), h1(Q), w1(Q),\
    \ h2(Q), w2(Q);\r\n\t\r\n\tusing pii = std::pair<int, int>;\r\n\t\r\n\tstd::queue<pii>\
    \ que; // \u713C\u304D\u4E0A\u304C\u308A\u306E\u6642\u523B, \u30A4\u30D9\u30F3\
    \u30C8ID\r\n\tBinaryIndexedTree2D<int> bit1(H, W), bit2(H, W); // bit1: \u713C\
    \u304D\u4E0A\u304C\u3063\u305F, bit2: \u307E\u3060\u713C\u304D\u4E0A\u304C\u3063\
    \u3066\u3044\u306A\u3044\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tscanf(\"\
    %d %d %d %d\", &t[i], &c[i], &h1[i], &w1[i]);\r\n\t\t--h1[i]; --w1[i];\r\n\t\t\
    \r\n\t\twhile (!que.empty() && que.front().first <= t[i]) {\r\n\t\t\tint idx =\
    \ que.front().second; que.pop();\r\n\t\t\tbit2.add(h1[idx], w1[idx], -1);\r\n\t\
    \t\tbit1.add(h1[idx], w1[idx], 1);\r\n\t\t}\r\n\t\t\r\n\t\tif (c[i] == 0) { //\
    \ \u30BB\u30C3\u30C8\r\n\t\t\tbit2.add(h1[i], w1[i], 1);\r\n\t\t\tque.emplace(t[i]\
    \ + T, i);\r\n\t\t}\r\n\t\telse if (c[i] == 1) { // \u3064\u307E\u307F\u98DF\u3044\
    \r\n\t\t\tif (bit1.sum(h1[i], w1[i], h1[i] + 1, w1[i] + 1) == 1) bit1.add(h1[i],\
    \ w1[i], -1);\r\n\t\t}\r\n\t\telse { // \u30AB\u30A6\u30F3\u30C8\r\n\t\t\tscanf(\"\
    %d %d\", &h2[i], &w2[i]);\r\n\t\t\tprintf(\"%d %d\\n\", bit1.sum(h1[i], w1[i],\
    \ h2[i], w2[i]), bit2.sum(h1[i], w1[i], h2[i], w2[i]));\r\n\t\t}\r\n\t}\r\n\t\r\
    \n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \r\n\r\n#include \"DataStructure/BinaryIndexedTree2D.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n#include <queue>\r\n#include <utility>\r\n\r\nint main()\
    \ {\r\n\tint H, W, T, Q;\r\n\tscanf(\"%d %d %d %d\", &H, &W, &T, &Q);\r\n\tstd::vector<int>\
    \ t(Q), c(Q), h1(Q), w1(Q), h2(Q), w2(Q);\r\n\t\r\n\tusing pii = std::pair<int,\
    \ int>;\r\n\t\r\n\tstd::queue<pii> que; // \u713C\u304D\u4E0A\u304C\u308A\u306E\
    \u6642\u523B, \u30A4\u30D9\u30F3\u30C8ID\r\n\tBinaryIndexedTree2D<int> bit1(H,\
    \ W), bit2(H, W); // bit1: \u713C\u304D\u4E0A\u304C\u3063\u305F, bit2: \u307E\u3060\
    \u713C\u304D\u4E0A\u304C\u3063\u3066\u3044\u306A\u3044\r\n\t\r\n\tfor (int i =\
    \ 0; i < Q; ++i) {\r\n\t\tscanf(\"%d %d %d %d\", &t[i], &c[i], &h1[i], &w1[i]);\r\
    \n\t\t--h1[i]; --w1[i];\r\n\t\t\r\n\t\twhile (!que.empty() && que.front().first\
    \ <= t[i]) {\r\n\t\t\tint idx = que.front().second; que.pop();\r\n\t\t\tbit2.add(h1[idx],\
    \ w1[idx], -1);\r\n\t\t\tbit1.add(h1[idx], w1[idx], 1);\r\n\t\t}\r\n\t\t\r\n\t\
    \tif (c[i] == 0) { // \u30BB\u30C3\u30C8\r\n\t\t\tbit2.add(h1[i], w1[i], 1);\r\
    \n\t\t\tque.emplace(t[i] + T, i);\r\n\t\t}\r\n\t\telse if (c[i] == 1) { // \u3064\
    \u307E\u307F\u98DF\u3044\r\n\t\t\tif (bit1.sum(h1[i], w1[i], h1[i] + 1, w1[i]\
    \ + 1) == 1) bit1.add(h1[i], w1[i], -1);\r\n\t\t}\r\n\t\telse { // \u30AB\u30A6\
    \u30F3\u30C8\r\n\t\t\tscanf(\"%d %d\", &h2[i], &w2[i]);\r\n\t\t\tprintf(\"%d %d\\\
    n\", bit1.sum(h1[i], w1[i], h2[i], w2[i]), bit2.sum(h1[i], w1[i], h2[i], w2[i]));\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree2D.hpp
  isVerificationFile: true
  path: Test/BinaryIndexedTree2D.test.cpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BinaryIndexedTree2D.test.cpp
layout: document
redirect_from:
- /verify/Test/BinaryIndexedTree2D.test.cpp
- /verify/Test/BinaryIndexedTree2D.test.cpp.html
title: Test/BinaryIndexedTree2D.test.cpp
---
