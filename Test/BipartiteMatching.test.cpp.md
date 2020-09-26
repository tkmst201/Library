---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/BipartiteMatching.hpp
    title: GraphTheory/BipartiteMatching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Test/BipartiteMatching.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \r\n\r\n#line 1 \"GraphTheory/BipartiteMatching.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/08/26\r\n\r\n\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306E\u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u3092\u6C42\u3081\u308B\r\n\u30AA\u30FC\u30C0\u30FC\u304C\
    \u602A\u3057\u3044\u304C\u5B9F\u969B\u306B\u306F\u9AD8\u901F\u306B\u52D5\u304F\
    \r\n\r\nN \\leq 10^5, M \\leq 2 \\times 10^5 \u3067\u3082\u9AD8\u901F\r\n\r\n\
    TODO: \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0 \u9802\u70B9 or \u8FBA \u306E\
    \u8FFD\u52A0\u3084\u524A\u9664\r\n\r\n# \u4ED5\u69D8\r\nBipartiteMatching(size_type\
    \ x, size_type y)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(x + y)\r\n\t\u96C6\
    \u5408 X, Y \u306E\u4E8C\u90E8\u30B0\u30E9\u30D5\u3092\u6E96\u5099\r\n\t|X| =\
    \ x, |Y| = y\r\n\r\nBipartiteMatching(size_type n)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n)\r\n\t|X| = |Y| = y \u306E\u4E8C\u90E8\u30B0\u30E9\u30D5\u3092\
    \u6E96\u5099\r\n\r\nvoid add_edge(size_type a, size_type b) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 a, \u9802\u70B9 b \u9593\u306B\
    \u8FBA\u3092\u5F35\u308B\r\n\r\nsize_type build() :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(NE) ?? \u8B0E\u3060\u3051\u3069\u9AD8\u901F\r\n\t\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u6C42\u3081\u308B\r\n\t\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059\r\n\r\nstd::vector<std::pair<size_type,\
    \ size_type>> get_match() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (min{x, y})\r\n\t\u8A08\u7B97\u6E08\u307F\u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\
    \u30DA\u30A2\u3092\u8FD4\u3059 (X \u306E\u8981\u7D20, Y \u306E\u8981\u7D20)\r\n\
    \r\nstd::vector<size_type> get_match_x() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(x)\r\n\tX \u306E\u5404\u8981\u7D20\u306E\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u5148\u3092\u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059(\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408 y)\r\n\
    \r\nstd::vector<size_type> get_match_y() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(y)\r\n\tY \u306E\u5404\u8981\u7D20\u306E\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u5148\u3092\u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059(\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408 x)\r\n\
    \r\n# \u53C2\u8003\r\nhttps://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching,\
    \ 2020/03/05\r\nhttps://snuke.hatenablog.com/entry/2019/05/07/013609, 2020/08/26\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <utility>\r\n\r\
    \nstruct BipartiteMatching {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type x, y;\r\n\tstd::vector<std::vector<size_type>> g;\r\n\tsize_type\
    \ match_;\r\n\tstd::vector<size_type> match_x, match_y;\r\n\tstd::vector<size_type>\
    \ visited;\r\n\tbool isbuilt;\r\n\t\r\npublic:\r\n\tBipartiteMatching(size_type\
    \ x, size_type y) : x(x), y(y), g(x + y, std::vector<size_type>()), isbuilt(false)\
    \ {}\r\n\tBipartiteMatching(size_type n) : BipartiteMatching(n, n) {}\r\n\t\r\n\
    \tvoid add_edge(size_type a, size_type b) {\r\n\t\tassert(a < x && b < y);\r\n\
    \t\tg[a].push_back(b);\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tsize_type build()\
    \ {\r\n\t\tmatch_y.assign(y, x);\r\n\t\tmatch_x.assign(x, y);\r\n\t\tmatch_ =\
    \ 0;\r\n\t\tsize_type c = 0;\r\n\t\tvisited.assign(x, 0);\r\n\t\tbool updated;\r\
    \n\t\tdo {\r\n\t\t\tupdated = false;\r\n\t\t\t++c;\r\n\t\t\tfor (size_type i =\
    \ 0; i < x; ++i) {\r\n\t\t\t\tif (match_x[i] == y && dfs(i, c)) {\r\n\t\t\t\t\t\
    ++match_;\r\n\t\t\t\t\tupdated = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t} while\
    \ (updated);\r\n\t\tisbuilt = true;\r\n\t\treturn match_;\r\n\t}\r\n\t\r\n\tsize_type\
    \ match() const {\r\n\t\tassert(isbuilt);\r\n\t\treturn match_;\r\n\t}\r\n\t\r\
    \n\tstd::vector<std::pair<size_type, size_type>> get_match() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tstd::vector<std::pair<size_type, size_type>> res;\r\n\t\tif (x < y) {\r\n\
    \t\t\tfor (size_type i = 0; i < x; ++i) {\r\n\t\t\t\tif (match_x[i] != y) res.emplace_back(i,\
    \ match_x[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\telse {\r\n\t\t\tfor (size_type i = 0;\
    \ i < y; ++i) {\r\n\t\t\t\tif (match_y[i] != x) res.emplace_back(match_y[i], i);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::vector<size_type>\
    \ get_match_x() const {\r\n\t\tassert(isbuilt);\r\n\t\treturn match_x;\r\n\t}\r\
    \n\t\r\n\tstd::vector<size_type> get_match_y() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\treturn match_y;\r\n\t}\r\n\t\r\nprivate:\r\n\tbool dfs(size_type u, size_type\
    \ c) {\r\n\t\tif (visited[u] == c) return false;\r\n\t\tvisited[u] = c;\r\n\t\t\
    \r\n\t\tfor (size_type v: g[u]) {\r\n\t\t\tif (match_y[v] == x || dfs(match_y[v],\
    \ c)) {\r\n\t\t\t\tmatch_y[v] = u;\r\n\t\t\t\tmatch_x[u] = v;\r\n\t\t\t\treturn\
    \ true;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn false;\r\n\t}\r\n};\r\n\r\n\n#line 4\
    \ \"Test/BipartiteMatching.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint L, R, M;\r\n\tscanf(\"%d %d %d\", &L, &R, &M);\r\n\t\r\n\tBipartiteMatching\
    \ bm(L, R);\r\n\tfor (int i = 0; i < M; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\tbm.add_edge(a, b);\r\n\t}\r\n\tbm.build();\r\n\t\r\n\t\
    auto match = bm.get_match();\r\n\tprintf(\"%d\\n\", match.size());\r\n\tfor (int\
    \ i = 0; i < match.size(); ++i) printf(\"%d %d\\n\", match[i].first, match[i].second);\r\
    \n\t\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\
    \r\n#include \"GraphTheory/BipartiteMatching.hpp\"\r\n\r\n#include <cstdio>\r\n\
    \r\nint main() {\r\n\tint L, R, M;\r\n\tscanf(\"%d %d %d\", &L, &R, &M);\r\n\t\
    \r\n\tBipartiteMatching bm(L, R);\r\n\tfor (int i = 0; i < M; ++i) {\r\n\t\tint\
    \ a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tbm.add_edge(a, b);\r\n\t}\r\n\t\
    bm.build();\r\n\t\r\n\tauto match = bm.get_match();\r\n\tprintf(\"%d\\n\", match.size());\r\
    \n\tfor (int i = 0; i < match.size(); ++i) printf(\"%d %d\\n\", match[i].first,\
    \ match[i].second);\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/BipartiteMatching.hpp
  isVerificationFile: true
  path: Test/BipartiteMatching.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BipartiteMatching.test.cpp
layout: document
redirect_from:
- /verify/Test/BipartiteMatching.test.cpp
- /verify/Test/BipartiteMatching.test.cpp.html
title: Test/BipartiteMatching.test.cpp
---
