---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/Dinic.hpp
    title: "\u6700\u5927\u6D41 (Dinic)"
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
  bundledCode: "#line 1 \"Test/Dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \r\n\r\n#line 1 \"GraphTheory/Dinic.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <queue>\r\n#include <type_traits>\r\n#include <algorithm>\r\
    \n#include <limits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/Dinic.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct Dinic {\r\n\tusing cap_type = T;\r\n\t\
    \r\nprivate:\r\n\tstatic constexpr cap_type EPS = std::is_floating_point<cap_type>()\
    \ ? 1e-8 : 0;\r\n\tstatic constexpr cap_type INF = std::numeric_limits<cap_type>::max();\r\
    \n\tstruct Edge {\r\n\t\tint to, rev;\r\n\t\tcap_type c;\r\n\t\tEdge(int to, int\
    \ rev, const cap_type & c) : to(to), rev(rev), c(c) {}\r\n\t};\r\n\tusing Graph\
    \ = std::vector<std::vector<Edge>>;\r\n\tGraph g;\r\n\t\r\npublic:\r\n\tDinic(int\
    \ n) : g(n) {}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn g.size();\r\
    \n\t}\r\n\t\r\n\tvoid add_edge(int u, int v, const cap_type & cap) {\r\n\t\tassert(0\
    \ <= u && u < size());\r\n\t\tassert(0 <= v && v < size());\r\n\t\tassert(cap\
    \ >= 0);\r\n\t\tg[u].emplace_back(v, g[v].size(), cap);\r\n\t\tg[v].emplace_back(u,\
    \ g[u].size() - 1, 0);\r\n\t}\r\n\t\r\n\tcap_type max_flow(int s, int t) {\r\n\
    \t\tassert(0 <= s && s < size());\r\n\t\tassert(0 <= t && t < size());\r\n\t\t\
    assert(s != t);\r\n\t\tcap_type res = 0;\r\n\t\tstd::vector<int> iter, level;\r\
    \n\t\twhile (true) {\r\n\t\t\tlevel.assign(size(), -1);\r\n\t\t\tstd::queue<int>\
    \ que;\r\n\t\t\tlevel[s] = 0;\r\n\t\t\tque.emplace(s);\r\n\t\t\twhile (!que.empty()\
    \ && level[t] == -1) {\r\n\t\t\t\tconst int u = que.front();\r\n\t\t\t\tque.pop();\r\
    \n\t\t\t\tfor (const auto & e : g[u]) {\r\n\t\t\t\t\tif (e.c <= EPS || level[e.to]\
    \ != -1) continue;\r\n\t\t\t\t\tlevel[e.to] = level[u] + 1;\r\n\t\t\t\t\tif (e.to\
    \ == t) break;\r\n\t\t\t\t\tque.emplace(e.to);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\
    \tif (level[t] == -1) break;\r\n\t\t\titer.assign(size(), 0);\r\n\t\t\tauto dfs\
    \ = [&](auto self, int u, cap_type f) -> cap_type {\r\n\t\t\t\tif (u == t) return\
    \ f;\r\n\t\t\t\tif (level[u] >= level[t]) return 0;\r\n\t\t\t\tfor (int & i =\
    \ iter[u]; i < static_cast<int>(g[u].size()); ++i) {\r\n\t\t\t\t\tauto & e = g[u][i];\r\
    \n\t\t\t\t\tif (e.c <= EPS || level[u] >= level[e.to]) continue;\r\n\t\t\t\t\t\
    const cap_type cur = self(self, e.to, std::min(f, e.c));\r\n\t\t\t\t\tif (cur\
    \ > EPS) {\r\n\t\t\t\t\t\te.c -= cur;\r\n\t\t\t\t\t\tg[e.to][e.rev].c += cur;\r\
    \n\t\t\t\t\t\treturn cur;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\treturn 0;\r\n\
    \t\t\t};\r\n\t\t\tcap_type f;\r\n\t\t\twhile ((f = dfs(dfs, s, INF)) > EPS) res\
    \ += f;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/Dinic.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint V, E;\r\n\tscanf(\"%d %d\"\
    , &V, &E);\r\n\tDinic<int> dinic(V);\r\n\twhile (E--) {\r\n\t\tint u, v, c;\r\n\
    \t\tscanf(\"%d %d %d\", &u, &v, &c);\r\n\t\tdinic.add_edge(u, v, c);\r\n\t}\r\n\
    \tprintf(\"%d\\n\", dinic.max_flow(0, V - 1));\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\r\n\
    \r\n#include \"GraphTheory/Dinic.hpp\"\r\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint V, E;\r\n\tscanf(\"%d %d\", &V, &E);\r\n\tDinic<int> dinic(V);\r\n\
    \twhile (E--) {\r\n\t\tint u, v, c;\r\n\t\tscanf(\"%d %d %d\", &u, &v, &c);\r\n\
    \t\tdinic.add_edge(u, v, c);\r\n\t}\r\n\tprintf(\"%d\\n\", dinic.max_flow(0, V\
    \ - 1));\r\n}"
  dependsOn:
  - GraphTheory/Dinic.hpp
  isVerificationFile: true
  path: Test/Dinic.test.cpp
  requiredBy: []
  timestamp: '2021-03-16 16:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Dinic.test.cpp
layout: document
redirect_from:
- /verify/Test/Dinic.test.cpp
- /verify/Test/Dinic.test.cpp.html
title: Test/Dinic.test.cpp
---
