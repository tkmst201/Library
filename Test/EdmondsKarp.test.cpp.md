---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/EdmondsKarp.hpp
    title: "\u6700\u5927\u6D41 (Edmonds-Karp)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"Test/EdmondsKarp.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \r\n\r\n#line 1 \"GraphTheory/EdmondsKarp.hpp\"\n\n\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n#include <queue>\r\n#include <utility>\r\n#include <type_traits>\r\
    \n#include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct EdmondsKarp {\r\n\tusing cap_type = T;\r\
    \n\t\r\nprivate:\r\n\tstatic constexpr cap_type EPS = std::is_floating_point<cap_type>()\
    \ ? 1e-8 : 0;\r\n\tstruct Edge {\r\n\t\tint to, rev;\r\n\t\tcap_type c;\r\n\t\t\
    Edge(int to, int rev, const cap_type & c) : to(to), rev(rev), c(c) {}\r\n\t};\r\
    \n\tusing Graph = std::vector<std::vector<Edge>>;\r\n\tGraph g;\r\n\t\r\npublic:\r\
    \n\texplicit EdmondsKarp(int n) : g(n) {}\r\n\t\r\n\tint size() const noexcept\
    \ {\r\n\t\treturn g.size();\r\n\t}\r\n\t\r\n\tvoid add_edge(int u, int v, const\
    \ cap_type & cap) {\r\n\t\tassert(0 <= u && u < size());\r\n\t\tassert(0 <= v\
    \ && v < size());\r\n\t\tassert(cap >= 0);\r\n\t\tg[u].emplace_back(v, g[v].size(),\
    \ cap);\r\n\t\tg[v].emplace_back(u, g[u].size() - 1, 0);\r\n\t}\r\n\t\r\n\tcap_type\
    \ max_flow(int s, int t) {\r\n\t\tassert(0 <= s && s < size());\r\n\t\tassert(0\
    \ <= t && t < size());\r\n\t\tassert(s != t);\r\n\t\tcap_type res = 0;\r\n\t\t\
    std::vector<std::pair<int, int>> prv(size(), std::make_pair(-1, -1));\r\n\t\t\
    while (true) {\r\n\t\t\tstd::vector<int> visited;\r\n\t\t\tstd::queue<int> que;\r\
    \n\t\t\tprv[s].first = s;\r\n\t\t\tvisited.emplace_back(s);\r\n\t\t\tque.emplace(s);\r\
    \n\t\t\twhile (!que.empty() && prv[t].first == -1) {\r\n\t\t\t\tconst int u =\
    \ que.front();\r\n\t\t\t\tque.pop();\r\n\t\t\t\tfor (int i = 0; i < static_cast<int>(g[u].size());\
    \ ++i) {\r\n\t\t\t\t\tconst int to = g[u][i].to;\r\n\t\t\t\t\tif (prv[to].first\
    \ != -1 || g[u][i].c <= EPS) continue;\r\n\t\t\t\t\tprv[to] = {u, i};\r\n\t\t\t\
    \t\tvisited.emplace_back(to);\r\n\t\t\t\t\tif (to == t) break;\r\n\t\t\t\t\tque.emplace(to);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (prv[t].first == -1) break;\r\n\t\t\tcap_type\
    \ flow = g[prv[t].first][prv[t].second].c;\r\n\t\t\tfor (int u = prv[t].first;\
    \ u != prv[u].first; u = prv[u].first) {\r\n\t\t\t\tflow = std::min(flow, g[prv[u].first][prv[u].second].c);\r\
    \n\t\t\t}\r\n\t\t\tfor (int u = t; u != prv[u].first; u = prv[u].first) {\r\n\t\
    \t\t\tconst auto [v, eidx] = prv[u];\r\n\t\t\t\tg[v][eidx].c -= flow;\r\n\t\t\t\
    \tg[u][g[v][eidx].rev].c += flow;\r\n\t\t\t}\r\n\t\t\tfor (int u : visited) prv[u]\
    \ = {-1, -1};\r\n\t\t\tres += flow;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\
    \n\r\n\n#line 4 \"Test/EdmondsKarp.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint\
    \ main() {\r\n\tint V, E;\r\n\tscanf(\"%d %d\", &V, &E);\r\n\tEdmondsKarp<int>\
    \ ek(V);\r\n\twhile (E--) {\r\n\t\tint u, v, c;\r\n\t\tscanf(\"%d %d %d\", &u,\
    \ &v, &c);\r\n\t\tek.add_edge(u, v, c);\r\n\t}\r\n\tprintf(\"%d\\n\", ek.max_flow(0,\
    \ V - 1));\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\r\n\
    \r\n#include \"GraphTheory/EdmondsKarp.hpp\"\r\n\r\n#include <cstdio>\r\n\r\n\
    int main() {\r\n\tint V, E;\r\n\tscanf(\"%d %d\", &V, &E);\r\n\tEdmondsKarp<int>\
    \ ek(V);\r\n\twhile (E--) {\r\n\t\tint u, v, c;\r\n\t\tscanf(\"%d %d %d\", &u,\
    \ &v, &c);\r\n\t\tek.add_edge(u, v, c);\r\n\t}\r\n\tprintf(\"%d\\n\", ek.max_flow(0,\
    \ V - 1));\r\n}"
  dependsOn:
  - GraphTheory/EdmondsKarp.hpp
  isVerificationFile: true
  path: Test/EdmondsKarp.test.cpp
  requiredBy: []
  timestamp: '2021-03-16 16:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/EdmondsKarp.test.cpp
layout: document
redirect_from:
- /verify/Test/EdmondsKarp.test.cpp
- /verify/Test/EdmondsKarp.test.cpp.html
title: Test/EdmondsKarp.test.cpp
---
