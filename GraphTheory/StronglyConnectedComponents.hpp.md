---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mathematics/TwoSat.hpp
    title: Mathematics/TwoSat.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/StronglyConnectedComponents.test.cpp
    title: Test/StronglyConnectedComponents.test.cpp
  - icon: ':x:'
    path: Test/TwoSat.test.cpp
    title: Test/TwoSat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://mathtrain.jp/kyorenketsu,
  bundledCode: "#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\n\n\n\r\n\
    /*\r\nlast-updated: 2020/08/27\r\n\r\nTODO: SCC: \u975E\u518D\u5E30\u306B\u3059\
    \u308B\r\n\r\n# \u4ED5\u69D8\r\nStronglyConnectedComponents(size_type n) :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u9802\u70B9\u6570\u304C n \u306E\
    \u30B0\u30E9\u30D5\u3092\u6E96\u5099\r\n\r\nStronglyConnectedComponentx(std::vector<std::vector<size_type>>\
    \ g) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n + m)\r\n\t\u30B0\u30E9\u30D5\
    \ g \u3067\u521D\u671F\u5316\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\
    \n\r\nvoid add_edge(size_type u, size_type v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u9802\u70B9 u \u304B\u3089 \u9802\u70B9 v \u3078\u8FBA\u3092\
    \u5F35\u308B\r\n\r\nsize_type build(bool build_idx_map = true)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n + m)\r\n\t\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u3092\u884C\u3046\r\n\t\u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\r\n\tbuild_idx_map \u304C false \u306E\u3068\u304D\u306F idx_map\
    \ \u30C6\u30FC\u30D6\u30EB\u3092\u69CB\u7BC9\u3057\u306A\u3044(get_map \u3084\
    \ get_graph \u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9)\r\n\r\nsize_type get_rank(size_type\
    \ i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 i \u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\u3059\r\n\r\nconst std::vetor<size_type>\
    \ & get_map(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C i \u3067\u3042\u308B\u5F37\
    \u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u3092\u8FD4\u3059(\u6607\u9806)\r\n\r\nstd::vector<std::vector<size_type>>\
    \ get_graph() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n + m log m)\r\n\t\
    \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u5F8C\u306E\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u6210\u3057\u3066\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://mathtrain.jp/kyorenketsu,\
    \ 2020/08/27\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <algorithm>\r\n\r\nstruct StronglyConnectedComponents {\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\nprivate:\r\n\tstd::vector<std::vector<size_type>> g,\
    \ rg;\r\n\tstd::vector<size_type> rank; // [i] := \u9802\u70B9 i \u304C\u5C5E\u3059\
    \u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\r\n\tstd::vector<std::vector<size_type>> idx_map; // [i][j] := \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C i \u306E\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u5C5E\u3059\u308B j \u756A\u76EE\u306E\u9802\u70B9\u306E\u756A\u53F7\
    (\u6607\u9806)\r\n\tbool isbuilt = false;\r\n\t\r\npublic:\r\n\tStronglyConnectedComponents(size_type\
    \ n) {\r\n\t\tg.resize(n);\r\n\t\trg.resize(n);\r\n\t}\r\n\t\r\n\tStronglyConnectedComponents(std::vector<std::vector<size_type>>\
    \ g) : g(g) {\r\n\t\trg.resize(size());\r\n\t\tfor (size_type i = 0; i < size();\
    \ ++i) {\r\n\t\t\tfor (size_type j : g[i]) rg[j].emplace_back(i);\r\n\t\t}\r\n\
    \t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn g.size();\r\n\t\
    }\r\n\t\r\n\tvoid add_edge(size_type u, size_type v) {\r\n\t\tassert(u < size());\r\
    \n\t\tassert(v < size());\r\n\t\tg[u].emplace_back(v);\r\n\t\trg[v].emplace_back(u);\r\
    \n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tsize_type build(bool build_idx_map =\
    \ true) {\r\n\t\tstd::vector<bool> visited;\r\n\t\tstd::vector<size_type> back_num;\
    \ // [i] := \u5E30\u308A\u304C\u3051\u9806\u304C i \u3067\u3042\u308B\u9802\u70B9\
    \r\n\t\t\r\n\t\tauto dfs = [&](auto &&self, size_type u) -> void {\r\n\t\t\tvisited[u]\
    \ = true;\r\n\t\t\tfor (size_type v : g[u]) if (!visited[v]) self(self, v);\r\n\
    \t\t\tsize_type c = back_num.size();\r\n\t\t\tback_num.emplace_back(u);\r\n\t\t\
    };\r\n\t\t\r\n\t\tvisited.assign(size(), false);\r\n\t\tback_num.reserve(size());\r\
    \n\t\tfor (size_type i = 0; i < size(); ++i) if (!visited[i]) dfs(dfs, i);\r\n\
    \t\t\r\n\t\tsize_type c = 0;\r\n\t\tauto rdfs = [&](auto &&self, size_type u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank[u] = c;\r\n\t\t\tfor (size_type\
    \ v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\t\r\n\t\trank.resize(size());\r\
    \n\t\tvisited.assign(size(), false);\r\n\t\tfor (size_type i = size(); i > 0;\
    \ --i) {\r\n\t\t\tconst size_type u = back_num[i - 1];\r\n\t\t\tif (visited[u])\
    \ continue;\r\n\t\t\trdfs(rdfs, u);\r\n\t\t\t++c;\r\n\t\t}\r\n\t\t\r\n\t\tif (build_idx_map)\
    \ {\r\n\t\t\tidx_map.assign(c, {});\r\n\t\t\tfor (size_type i = 0; i < size();\
    \ ++i) idx_map[rank[i]].emplace_back(i);\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t\
    \treturn c;\r\n\t}\r\n\t\r\n\tsize_type get_rank(size_type i) {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(i < size());\r\n\t\treturn rank[i];\r\n\t}\r\n\t\r\n\tconst std::vector<size_type>\
    \ & get_map(size_type i) {\r\n\t\tassert(isbuilt);\r\n\t\tassert(i < idx_map.size());\r\
    \n\t\treturn idx_map[i];\r\n\t}\r\n\t\r\n\tstd::vector<std::vector<size_type>>\
    \ get_graph() const {\r\n\t\tassert(isbuilt);\r\n\t\tstd::vector<std::vector<size_type>>\
    \ res(idx_map.size());\r\n\t\tfor (size_type i = 0; i < idx_map.size(); ++i) {\r\
    \n\t\t\tfor (size_type j : idx_map[i]) {\r\n\t\t\t\tfor (size_type v : g[j]) res[i].emplace_back(v);\r\
    \n\t\t\t}\r\n\t\t\tstd::sort(begin(res[i]), end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]),\
    \ end(res[i])), end(res[i]));\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\
    \n"
  code: "#ifndef INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP\r\n#define INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/27\r\n\r\nTODO: SCC: \u975E\u518D\u5E30\u306B\
    \u3059\u308B\r\n\r\n# \u4ED5\u69D8\r\nStronglyConnectedComponents(size_type n)\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u9802\u70B9\u6570\u304C\
    \ n \u306E\u30B0\u30E9\u30D5\u3092\u6E96\u5099\r\n\r\nStronglyConnectedComponentx(std::vector<std::vector<size_type>>\
    \ g) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n + m)\r\n\t\u30B0\u30E9\u30D5\
    \ g \u3067\u521D\u671F\u5316\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\
    \n\r\nvoid add_edge(size_type u, size_type v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u9802\u70B9 u \u304B\u3089 \u9802\u70B9 v \u3078\u8FBA\u3092\
    \u5F35\u308B\r\n\r\nsize_type build(bool build_idx_map = true)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n + m)\r\n\t\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u3092\u884C\u3046\r\n\t\u5F37\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\r\n\tbuild_idx_map \u304C false \u306E\u3068\u304D\u306F idx_map\
    \ \u30C6\u30FC\u30D6\u30EB\u3092\u69CB\u7BC9\u3057\u306A\u3044(get_map \u3084\
    \ get_graph \u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9)\r\n\r\nsize_type get_rank(size_type\
    \ i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 i \u304C\
    \u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\u3059\r\n\r\nconst std::vetor<size_type>\
    \ & get_map(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C i \u3067\u3042\u308B\u5F37\
    \u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u3092\u8FD4\u3059(\u6607\u9806)\r\n\r\nstd::vector<std::vector<size_type>>\
    \ get_graph() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n + m log m)\r\n\t\
    \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u5F8C\u306E\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u6210\u3057\u3066\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://mathtrain.jp/kyorenketsu,\
    \ 2020/08/27\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <algorithm>\r\n\r\nstruct StronglyConnectedComponents {\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\nprivate:\r\n\tstd::vector<std::vector<size_type>> g,\
    \ rg;\r\n\tstd::vector<size_type> rank; // [i] := \u9802\u70B9 i \u304C\u5C5E\u3059\
    \u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u9806\u5E8F\r\n\tstd::vector<std::vector<size_type>> idx_map; // [i][j] := \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C i \u306E\u5F37\u9023\u7D50\u6210\
    \u5206\u306B\u5C5E\u3059\u308B j \u756A\u76EE\u306E\u9802\u70B9\u306E\u756A\u53F7\
    (\u6607\u9806)\r\n\tbool isbuilt = false;\r\n\t\r\npublic:\r\n\tStronglyConnectedComponents(size_type\
    \ n) {\r\n\t\tg.resize(n);\r\n\t\trg.resize(n);\r\n\t}\r\n\t\r\n\tStronglyConnectedComponents(std::vector<std::vector<size_type>>\
    \ g) : g(g) {\r\n\t\trg.resize(size());\r\n\t\tfor (size_type i = 0; i < size();\
    \ ++i) {\r\n\t\t\tfor (size_type j : g[i]) rg[j].emplace_back(i);\r\n\t\t}\r\n\
    \t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn g.size();\r\n\t\
    }\r\n\t\r\n\tvoid add_edge(size_type u, size_type v) {\r\n\t\tassert(u < size());\r\
    \n\t\tassert(v < size());\r\n\t\tg[u].emplace_back(v);\r\n\t\trg[v].emplace_back(u);\r\
    \n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tsize_type build(bool build_idx_map =\
    \ true) {\r\n\t\tstd::vector<bool> visited;\r\n\t\tstd::vector<size_type> back_num;\
    \ // [i] := \u5E30\u308A\u304C\u3051\u9806\u304C i \u3067\u3042\u308B\u9802\u70B9\
    \r\n\t\t\r\n\t\tauto dfs = [&](auto &&self, size_type u) -> void {\r\n\t\t\tvisited[u]\
    \ = true;\r\n\t\t\tfor (size_type v : g[u]) if (!visited[v]) self(self, v);\r\n\
    \t\t\tsize_type c = back_num.size();\r\n\t\t\tback_num.emplace_back(u);\r\n\t\t\
    };\r\n\t\t\r\n\t\tvisited.assign(size(), false);\r\n\t\tback_num.reserve(size());\r\
    \n\t\tfor (size_type i = 0; i < size(); ++i) if (!visited[i]) dfs(dfs, i);\r\n\
    \t\t\r\n\t\tsize_type c = 0;\r\n\t\tauto rdfs = [&](auto &&self, size_type u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank[u] = c;\r\n\t\t\tfor (size_type\
    \ v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\t\r\n\t\trank.resize(size());\r\
    \n\t\tvisited.assign(size(), false);\r\n\t\tfor (size_type i = size(); i > 0;\
    \ --i) {\r\n\t\t\tconst size_type u = back_num[i - 1];\r\n\t\t\tif (visited[u])\
    \ continue;\r\n\t\t\trdfs(rdfs, u);\r\n\t\t\t++c;\r\n\t\t}\r\n\t\t\r\n\t\tif (build_idx_map)\
    \ {\r\n\t\t\tidx_map.assign(c, {});\r\n\t\t\tfor (size_type i = 0; i < size();\
    \ ++i) idx_map[rank[i]].emplace_back(i);\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t\
    \treturn c;\r\n\t}\r\n\t\r\n\tsize_type get_rank(size_type i) {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(i < size());\r\n\t\treturn rank[i];\r\n\t}\r\n\t\r\n\tconst std::vector<size_type>\
    \ & get_map(size_type i) {\r\n\t\tassert(isbuilt);\r\n\t\tassert(i < idx_map.size());\r\
    \n\t\treturn idx_map[i];\r\n\t}\r\n\t\r\n\tstd::vector<std::vector<size_type>>\
    \ get_graph() const {\r\n\t\tassert(isbuilt);\r\n\t\tstd::vector<std::vector<size_type>>\
    \ res(idx_map.size());\r\n\t\tfor (size_type i = 0; i < idx_map.size(); ++i) {\r\
    \n\t\t\tfor (size_type j : idx_map[i]) {\r\n\t\t\t\tfor (size_type v : g[j]) res[i].emplace_back(v);\r\
    \n\t\t\t}\r\n\t\t\tstd::sort(begin(res[i]), end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]),\
    \ end(res[i])), end(res[i]));\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\
    #endif // INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/StronglyConnectedComponents.hpp
  requiredBy:
  - Mathematics/TwoSat.hpp
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/StronglyConnectedComponents.test.cpp
  - Test/TwoSat.test.cpp
documentation_of: GraphTheory/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/GraphTheory/StronglyConnectedComponents.hpp
- /library/GraphTheory/StronglyConnectedComponents.hpp.html
title: GraphTheory/StronglyConnectedComponents.hpp
---
