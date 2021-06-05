---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/BipartiteMatching.hpp
    title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Test/BipartiteMatching.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \r\n\r\n#line 1 \"GraphTheory/BipartiteMatching.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <utility>\r\n#include <queue>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp\r\
    \n */\r\nstruct BipartiteMatching {\r\nprivate:\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\tGraph g;\r\n\tint x, y;\r\n\tbool isswap;\r\n\tint max_maching_;\r\n\tstd::vector<int>\
    \ match_x, match_y;\r\n\tbool isbuilt = false;\r\n\t\r\npublic:\r\n\tBipartiteMatching(int\
    \ x, int y)\r\n\t\t: g(std::min(x, y)), x(std::min(x, y)), y(std::max(x, y)),\
    \ isswap(x > y) {}\r\n\t\r\n\tBipartiteMatching(int n) : BipartiteMatching(n,\
    \ n) {}\r\n\t\r\n\tvoid add_edge(int a, int b) {\r\n\t\tif (isswap) std::swap(a,\
    \ b);\r\n\t\tassert(0 <= a && a < x);\r\n\t\tassert(0 <= b && b < y);\r\n\t\t\
    g[a].emplace_back(b);\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tvoid build() {\r\
    \n\t\tmatch_y.assign(y, -1);\r\n\t\tmatch_x.assign(x, -1);\r\n\t\tmax_maching_\
    \ = 0;\r\n\t\tint c = 1;\r\n\t\tstd::vector<int> visited(x, 0);\r\n\t\tbool update\
    \ = false;\r\n\t\tauto dfs = [&](auto self, int u) -> bool {\r\n\t\t\tvisited[u]\
    \ = c;\r\n\t\t\tfor (int v : g[u]) if (match_y[v] == -1) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tfor (int v : g[u]) if (visited[match_y[v]] >= 0\
    \ && visited[match_y[v]] != c && self(self, match_y[v])) { match_y[v] = u; match_x[u]\
    \ = v; return true; }\r\n\t\t\tif (!update) visited[u] = -1;\r\n\t\t\treturn false;\r\
    \n\t\t};\r\n\t\tstd::queue<int> que;\r\n\t\tfor (int i = 0; i < x; ++i) {\r\n\t\
    \t\tif (dfs(dfs, i)) ++max_maching_, update = true;\r\n\t\t\telse if (update)\
    \ que.emplace(i);\r\n\t\t}\r\n\t\twhile (!que.empty()) {\r\n\t\t\t++c;\r\n\t\t\
    \tconst int n = que.size();\r\n\t\t\tupdate = false;\r\n\t\t\tfor (int i = 0;\
    \ i < n; ++i) {\r\n\t\t\t\tconst int u = que.front();\r\n\t\t\t\tque.pop();\r\n\
    \t\t\t\tif (match_x[u] == -1 && visited[u] != c && dfs(dfs, u)) {\r\n\t\t\t\t\t\
    ++max_maching_;\r\n\t\t\t\t\tupdate = true;\r\n\t\t\t\t}\r\n\t\t\t\telse if (update)\
    \ que.emplace(u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t}\r\n\t\r\n\t\
    int max_matching() const noexcept {\r\n\t\tassert(isbuilt);\r\n\t\treturn max_maching_;\r\
    \n\t}\r\n\t\r\n\tstd::vector<std::pair<int, int>> matching() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tstd::vector<std::pair<int, int>> res;\r\n\t\tfor (int i = 0; i < x; ++i)\
    \ {\r\n\t\t\tif (match_x[i] == -1) continue;\r\n\t\t\tif (isswap) res.emplace_back(match_x[i],\
    \ i);\r\n\t\t\telse res.emplace_back(i, match_x[i]);\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tint matching_x(int k) const noexcept {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(0 <= k && k < (isswap ? y : x));\r\n\t\treturn isswap ? match_y[k]\
    \ : match_x[k];\r\n\t}\r\n\t\r\n\tint matching_y(int k) const noexcept {\r\n\t\
    \tassert(isbuilt);\r\n\t\tassert(0 <= k && k < (isswap ? x : y));\r\n\t\treturn\
    \ isswap ? match_x[k] : match_y[k];\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/BipartiteMatching.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <map>\r\n\r\nint main() {\r\n\tint L, R, M;\r\
    \n\tscanf(\"%d %d %d\", &L, &R, &M);\r\n\t\r\n\tBipartiteMatching bm(L, R);\r\n\
    \tfor (int i = 0; i < M; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\
    \n\t\tbm.add_edge(a, b);\r\n\t}\r\n\tbm.build();\r\n\t\r\n\tprintf(\"%d\\n\",\
    \ bm.max_matching());\r\n\t\r\n\tstd::map<int, int> mtl, mtr;\r\n\tfor (auto [a,\
    \ b] : bm.matching()) {\r\n\t\tprintf(\"%d %d\\n\", a, b);\r\n\t\tmtl[a] = b;\r\
    \n\t\tmtr[b] = a;\r\n\t}\r\n\t\r\n\t// [match_*] test\r\n\tfor (int i = 0; i <\
    \ L; ++i) assert(mtl.count(i) ? mtl[i] == bm.matching_x(i) : -1);\r\n\tfor (int\
    \ i = 0; i < R; ++i) assert(mtr.count(i) ? mtr[i] == bm.matching_y(i) : -1);\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\
    \r\n#include \"GraphTheory/BipartiteMatching.hpp\"\r\n\r\n#include <cstdio>\r\n\
    #include <map>\r\n\r\nint main() {\r\n\tint L, R, M;\r\n\tscanf(\"%d %d %d\",\
    \ &L, &R, &M);\r\n\t\r\n\tBipartiteMatching bm(L, R);\r\n\tfor (int i = 0; i <\
    \ M; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tbm.add_edge(a,\
    \ b);\r\n\t}\r\n\tbm.build();\r\n\t\r\n\tprintf(\"%d\\n\", bm.max_matching());\r\
    \n\t\r\n\tstd::map<int, int> mtl, mtr;\r\n\tfor (auto [a, b] : bm.matching())\
    \ {\r\n\t\tprintf(\"%d %d\\n\", a, b);\r\n\t\tmtl[a] = b;\r\n\t\tmtr[b] = a;\r\
    \n\t}\r\n\t\r\n\t// [match_*] test\r\n\tfor (int i = 0; i < L; ++i) assert(mtl.count(i)\
    \ ? mtl[i] == bm.matching_x(i) : -1);\r\n\tfor (int i = 0; i < R; ++i) assert(mtr.count(i)\
    \ ? mtr[i] == bm.matching_y(i) : -1);\r\n}"
  dependsOn:
  - GraphTheory/BipartiteMatching.hpp
  isVerificationFile: true
  path: Test/BipartiteMatching.test.cpp
  requiredBy: []
  timestamp: '2021-03-14 12:24:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BipartiteMatching.test.cpp
layout: document
redirect_from:
- /verify/Test/BipartiteMatching.test.cpp
- /verify/Test/BipartiteMatching.test.cpp.html
title: Test/BipartiteMatching.test.cpp
---
