---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/Dinic.hpp
    title: GraphTheory/Dinic.hpp
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
    \r\n\r\n#line 1 \"GraphTheory/Dinic.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/03/03\r\
    \n\r\n\u8FBA\u306E\u5BB9\u91CF\u306F\u975E\u8CA0\u306E\u5B9F\u6570\u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\nDinic(size_type\
    \ n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B0\u30E9\u30D5\u306E\
    \u9802\u70B9\u6570\u3092 n \u3068\u3059\u308B\r\n\r\nsize_type size() const noexcept\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30B0\u30E9\u30D5\u306E\
    \u9802\u70B9\u6570\u3092\u8FD4\u3059\r\n\r\nvoid add_edge(size_type i, size_type\
    \ j, value_type c) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\
    \u70B9 i -> \u9802\u70B9 j \u3078\u5BB9\u91CF c \u306E\u8FBA\u3092\u5F35\u308B\
    \r\n\r\nvalue_type max_flow(size_type s, size_type t) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(V^2 E)\r\n\t\u9802\u70B9 s -> \u9802\u70B9 t \u306E\u6700\u5927\
    \u30D5\u30ED\u30FC\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://hos.ac/slides/20150319_flow.pdf,\
    \ 2020/03/03\r\nhttp://vartkw.hatenablog.com/entry/2016/12/02/002703, 2020/03/03\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <queue>\r\n#include\
    \ <utility>\r\n#include <type_traits>\r\n#include <algorithm>\r\n\r\ntemplate<typename\
    \ T>\r\nstruct Dinic {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\n\tDinic(size_type n) : g(std::vector<std::vector<Edge>>(n))\
    \ {}\r\n\t\r\n\tsize_type size() const noexcept { return g.size(); }\r\n\t\r\n\
    \tvoid add_edge(size_type i, size_type j, value_type c) {\r\n\t\tassert(i < size()\
    \ && j < size() && c >= 0);\r\n\t\tg[i].push_back({j, g[j].size(), c});\r\n\t\t\
    g[j].push_back({i, g[i].size() - 1, 0});\r\n\t}\r\n\t\r\n\tvalue_type max_flow(size_type\
    \ s, size_type t) {\r\n\t\tvalue_type res = 0;\r\n\t\twhile (bfs(s), ~level[t])\
    \ {\r\n\t\t\titer.assign(size(), 0);\r\n\t\t\tvalue_type f;\r\n\t\t\twhile ((f\
    \ = dfs(s, t, INF)) > EPS) res += f;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tstruct Edge { size_type to, rev; value_type c; };\r\n\tstd::vector<std::vector<Edge>>\
    \ g;\r\n\tstatic constexpr value_type EPS = std::is_floating_point<value_type>()\
    \ ? 1e-6 : 0;\r\n\tstatic constexpr value_type INF = 1e9 + 100;\r\n\tstd::vector<size_type>\
    \ iter, level;\r\n\t\r\n\tvoid bfs(size_type s) {\r\n\t\tlevel.assign(size(),\
    \ -1);\r\n\t\tstd::queue<size_type> que;\r\n\t\tque.push(s);\r\n\t\tlevel[s] =\
    \ 0;\r\n\t\twhile (!que.empty()) {\r\n\t\t\tsize_type u = que.front(); que.pop();\r\
    \n\t\t\tfor (Edge & e : g[u]) {\r\n\t\t\t\tif (e.c <= EPS || ~level[e.to]) continue;\r\
    \n\t\t\t\tque.push(e.to);\r\n\t\t\t\tlevel[e.to] = level[u] + 1;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t}\r\n\t\r\n\tvalue_type dfs(size_type u, size_type t, value_type f)\
    \ {\r\n\t\tif (u == t) return f;\r\n\t\tfor (size_type & i = iter[u]; i < g[u].size();\
    \ ++i) {\r\n\t\t\tconst Edge & e = g[u][i];\r\n\t\t\tif (e.c <= EPS || level[u]\
    \ >= level[e.to]) continue;\r\n\t\t\tvalue_type cur = dfs(e.to, t, std::min(f,\
    \ e.c));\r\n\t\t\tif (cur > EPS) {\r\n\t\t\t\tg[u][i].c -= cur;\r\n\t\t\t\tg[e.to][e.rev].c\
    \ += cur;\r\n\t\t\t\treturn cur;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn 0;\r\n\t}\r\
    \n};\r\n\r\n\n#line 4 \"Test/Dinic.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint\
    \ main() {\r\n\tint V, E;\r\n\tscanf(\"%d %d\", &V, &E);\r\n\tDinic<int> dinic(V);\r\
    \n\twhile (E--) {\r\n\t\tint u, v, c;\r\n\t\tscanf(\"%d %d %d\", &u, &v, &c);\r\
    \n\t\tdinic.add_edge(u, v, c);\r\n\t}\r\n\tprintf(\"%d\\n\", dinic.max_flow(0,\
    \ V - 1));\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\r\n\
    \r\n#include \"GraphTheory/Dinic.hpp\"\r\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint V, E;\r\n\tscanf(\"%d %d\", &V, &E);\r\n\tDinic<int> dinic(V);\r\n\
    \twhile (E--) {\r\n\t\tint u, v, c;\r\n\t\tscanf(\"%d %d %d\", &u, &v, &c);\r\n\
    \t\tdinic.add_edge(u, v, c);\r\n\t}\r\n\tprintf(\"%d\\n\", dinic.max_flow(0, V\
    \ - 1));\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/Dinic.hpp
  isVerificationFile: true
  path: Test/Dinic.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Dinic.test.cpp
layout: document
redirect_from:
- /verify/Test/Dinic.test.cpp
- /verify/Test/Dinic.test.cpp.html
title: Test/Dinic.test.cpp
---
