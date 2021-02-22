---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/EdmondsKarp.test.cpp
    title: Test/EdmondsKarp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://hos.ac/slides/20150319_flow.pdf,
  bundledCode: "#line 1 \"GraphTheory/EdmondsKarp.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/02/28\r\n\r\n\u8FBA\u306E\u5BB9\u91CF\u306F\u975E\u8CA0\u306E\u5B9F\u6570\
    \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\
    \nEdmondsKarp(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\
    \t\u9802\u70B9\u6570\u304C n \u306E\u30B0\u30E9\u30D5\u3092\u6E96\u5099\r\n\r\n\
    size_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\n\r\n\
    void add_edge(size_type i, size_type j, value_type c) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\tu -> v \u3078\u5BB9\u91CF c \u306E\u8FBA\u3092\u5F35\
    \u308B\r\n\r\nvalue_type max_flow(size_type s, size_type t) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(VE^2)\r\n\ts -> t \u306E\u6700\u5927\u30D5\u30ED\u30FC\u3092\
    \u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://hos.ac/slides/20150319_flow.pdf,\
    \ 2020/02/27\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <queue>\r\n#include <utility>\r\n#include <type_traits>\r\n#include <algorithm>\r\
    \n\r\ntemplate<typename T>\r\nstruct EdmondsKarp {\r\npublic:\r\n\tusing value_type\
    \ = T;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tEdmondsKarp(size_type n)\
    \ : g(std::vector<std::vector<Edge>>(n)) {}\r\n\t\r\n\tsize_type size() const\
    \ noexcept { return g.size(); }\r\n\t\r\n\tvoid add_edge(size_type i, size_type\
    \ j, value_type c) {\r\n\t\tassert(i < size() && j < size() && c >= 0);\r\n\t\t\
    g[i].push_back({j, g[j].size(), c});\r\n\t\tg[j].push_back({i, g[i].size() - 1,\
    \ 0});\r\n\t}\r\n\t\r\n\tvalue_type max_flow(size_type s, size_type t) {\r\n\t\
    \tassert(s < size() && t < size());\r\n\t\tvalue_type res = 0;\r\n\t\tstd::vector<std::pair<size_type,\
    \ size_type>> prv(size(), std::make_pair(-1, -1));\r\n\t\t\r\n\t\twhile (true)\
    \ {\r\n\t\t\tstd::vector<size_type> visited;\r\n\t\t\tstd::queue<size_type> que;\r\
    \n\t\t\tprv[s].first = s;\r\n\t\t\tvisited.push_back(s);\r\n\t\t\tque.push(s);\r\
    \n\t\t\twhile (!que.empty() && !~prv[t].first) {\r\n\t\t\t\tsize_type u = que.front();\
    \ que.pop();\r\n\t\t\t\tfor (size_type i = 0; i < g[u].size(); ++i) {\r\n\t\t\t\
    \t\tsize_type to = g[u][i].to;\r\n\t\t\t\t\tif (~prv[to].first || g[u][i].c <=\
    \ EPS) continue;\r\n\t\t\t\t\tprv[to] = std::make_pair(u, i);\r\n\t\t\t\t\tvisited.push_back(to);\r\
    \n\t\t\t\t\tif (to == t) break;\r\n\t\t\t\t\tque.push(to);\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t\tif (!~prv[t].first) break;\r\n\t\t\tvalue_type flow = g[prv[t].first][prv[t].second].c;\r\
    \n\t\t\tfor (size_type u = prv[t].first; u != prv[u].first; u = prv[u].first)\r\
    \n\t\t\t\tflow = std::min(flow, g[prv[u].first][prv[u].second].c);\r\n\t\t\tfor\
    \ (size_type u = t; u != prv[u].first; u = prv[u].first) {\r\n\t\t\t\tg[prv[u].first][prv[u].second].c\
    \ -= flow;\r\n\t\t\t\tg[u][g[prv[u].first][prv[u].second].rev].c += flow;\r\n\t\
    \t\t}\r\n\t\t\tfor (size_type u : visited) prv[u] = std::make_pair(-1, -1);\r\n\
    \t\t\tres += flow;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\t\
    struct Edge { size_type to, rev; value_type c; };\r\n\tstd::vector<std::vector<Edge>>\
    \ g;\r\n\tstatic constexpr value_type EPS = std::is_floating_point<value_type>()\
    \ ? 1e-6 : 0;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_EDMONDS_KARP_HPP\r\n#define INCLUDE_GUARD_EDMONDS_KARP_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/02/28\r\n\r\n\u8FBA\u306E\u5BB9\u91CF\u306F\u975E\
    \u8CA0\u306E\u5B9F\u6570\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \r\n\r\n# \u4ED5\u69D8\r\nEdmondsKarp(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n)\r\n\t\u9802\u70B9\u6570\u304C n \u306E\u30B0\u30E9\u30D5\u3092\
    \u6E96\u5099\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\
    \r\n\r\nvoid add_edge(size_type i, size_type j, value_type c) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\tu -> v \u3078\u5BB9\u91CF c \u306E\u8FBA\u3092\
    \u5F35\u308B\r\n\r\nvalue_type max_flow(size_type s, size_type t) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(VE^2)\r\n\ts -> t \u306E\u6700\u5927\u30D5\u30ED\u30FC\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://hos.ac/slides/20150319_flow.pdf,\
    \ 2020/02/27\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <queue>\r\n#include <utility>\r\n#include <type_traits>\r\n#include <algorithm>\r\
    \n\r\ntemplate<typename T>\r\nstruct EdmondsKarp {\r\npublic:\r\n\tusing value_type\
    \ = T;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tEdmondsKarp(size_type n)\
    \ : g(std::vector<std::vector<Edge>>(n)) {}\r\n\t\r\n\tsize_type size() const\
    \ noexcept { return g.size(); }\r\n\t\r\n\tvoid add_edge(size_type i, size_type\
    \ j, value_type c) {\r\n\t\tassert(i < size() && j < size() && c >= 0);\r\n\t\t\
    g[i].push_back({j, g[j].size(), c});\r\n\t\tg[j].push_back({i, g[i].size() - 1,\
    \ 0});\r\n\t}\r\n\t\r\n\tvalue_type max_flow(size_type s, size_type t) {\r\n\t\
    \tassert(s < size() && t < size());\r\n\t\tvalue_type res = 0;\r\n\t\tstd::vector<std::pair<size_type,\
    \ size_type>> prv(size(), std::make_pair(-1, -1));\r\n\t\t\r\n\t\twhile (true)\
    \ {\r\n\t\t\tstd::vector<size_type> visited;\r\n\t\t\tstd::queue<size_type> que;\r\
    \n\t\t\tprv[s].first = s;\r\n\t\t\tvisited.push_back(s);\r\n\t\t\tque.push(s);\r\
    \n\t\t\twhile (!que.empty() && !~prv[t].first) {\r\n\t\t\t\tsize_type u = que.front();\
    \ que.pop();\r\n\t\t\t\tfor (size_type i = 0; i < g[u].size(); ++i) {\r\n\t\t\t\
    \t\tsize_type to = g[u][i].to;\r\n\t\t\t\t\tif (~prv[to].first || g[u][i].c <=\
    \ EPS) continue;\r\n\t\t\t\t\tprv[to] = std::make_pair(u, i);\r\n\t\t\t\t\tvisited.push_back(to);\r\
    \n\t\t\t\t\tif (to == t) break;\r\n\t\t\t\t\tque.push(to);\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t\tif (!~prv[t].first) break;\r\n\t\t\tvalue_type flow = g[prv[t].first][prv[t].second].c;\r\
    \n\t\t\tfor (size_type u = prv[t].first; u != prv[u].first; u = prv[u].first)\r\
    \n\t\t\t\tflow = std::min(flow, g[prv[u].first][prv[u].second].c);\r\n\t\t\tfor\
    \ (size_type u = t; u != prv[u].first; u = prv[u].first) {\r\n\t\t\t\tg[prv[u].first][prv[u].second].c\
    \ -= flow;\r\n\t\t\t\tg[u][g[prv[u].first][prv[u].second].rev].c += flow;\r\n\t\
    \t\t}\r\n\t\t\tfor (size_type u : visited) prv[u] = std::make_pair(-1, -1);\r\n\
    \t\t\tres += flow;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\t\
    struct Edge { size_type to, rev; value_type c; };\r\n\tstd::vector<std::vector<Edge>>\
    \ g;\r\n\tstatic constexpr value_type EPS = std::is_floating_point<value_type>()\
    \ ? 1e-6 : 0;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_EDMONDS_KARP_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/EdmondsKarp.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/EdmondsKarp.test.cpp
documentation_of: GraphTheory/EdmondsKarp.hpp
layout: document
redirect_from:
- /library/GraphTheory/EdmondsKarp.hpp
- /library/GraphTheory/EdmondsKarp.hpp.html
title: GraphTheory/EdmondsKarp.hpp
---
