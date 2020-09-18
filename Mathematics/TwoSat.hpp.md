---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.hpp
    title: GraphTheory/StronglyConnectedComponents.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/TwoSat.test.cpp
    title: Test/TwoSat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/posts/517m,
  bundledCode: "#line 1 \"Mathematics/TwoSat.hpp\"\n\n\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n\r\n/*\r\nlast-updated: 2020/09/10\r\n\r\n# \u4ED5\u69D8\
    \r\nTwoSat(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\
    n \u5909\u6570\u3092\u5BFE\u8C61\u3068\u3057\u3066\u69CB\u7BC9\r\n\r\nvoid add_clause(size_type\
    \ x, bool xb, size_type y, bool yb) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t(x = xb) v (y = yb) \u3092\u52A0\u3048\u308B\r\n\r\nvoid add_clause(size_type\
    \ x, bool xb) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\tx = xb \u3092\
    \u52A0\u3048\u308B\r\n\r\nbool build() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ \u0398(n)\r\n\t\u5168\u3066\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\
    \u306A\u5909\u6570\u306E\u5024\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u6C42\
    \u3081\u308B\r\n\t\u305D\u306E\u3088\u3046\u306A\u7D44\u307F\u5408\u308F\u305B\
    \u304C\u5B58\u5728\u3059\u308B\u306A\u3089\u3070 true, \u5B58\u5728\u3057\u306A\
    \u3044\u306E\u306A\u3089\u3070 false \u3092\u8FD4\u3059\r\n\r\nconst std::vector<bool>\
    \ & get_answer() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5168\
    \u3066\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u5909\u6570\
    \u306E\u771F\u507D\u5024\u304C\u5165\u3063\u3066\u3044\u308B\u30C6\u30FC\u30D6\
    \u30EB\u3092\u8FD4\u3059\r\n\r\nbool get(size_type i) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u5168\u3066\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306A\u5909\u6570\u306E\u5024\u306E\u7D44\u307F\u5408\u308F\u305B\
    \u3067\u3001\u5909\u6570 i \u306E\u771F\u507D\u5024\u3092\u8FD4\u3059\r\n\r\n\
    # \u53C2\u8003\r\n\"AC Library\" https://atcoder.jp/posts/517m, 2020/09/10\r\n\
    */\r\n\r\n#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\n\n\n\r\n#line\
    \ 6 \"GraphTheory/StronglyConnectedComponents.hpp\"\n#include <algorithm>\r\n\r\
    \n/*\r\nlast-updated: 2020/08/27\r\n\r\n# \u4ED5\u69D8\r\nStronglyConnectedComponents(size_type\
    \ n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u9802\u70B9\u6570\u304C\
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
    \ 2020/08/27\r\n*/\r\n\r\nstruct StronglyConnectedComponents {\r\n\tusing size_type\
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
    \n#line 41 \"Mathematics/TwoSat.hpp\"\n\r\nstruct TwoSat {\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tStronglyConnectedComponents\
    \ scc;\r\n\tstd::vector<bool> ans;\r\n\tbool isbuilt, satisfiability;\r\n\t\r\n\
    public:\r\n\tTwoSat(size_type n) : n(n), scc(2 * n + 2) {}\r\n\t\r\n\tvoid add_clause(size_type\
    \ x, bool xb, size_type y, bool yb) {\r\n\t\tassert(x < n);\r\n\t\tassert(y <\
    \ n);\r\n\t\tscc.add_edge(x + (xb ? n : 0), y + ((yb^1) ? n : 0));\r\n\t\tscc.add_edge(y\
    \ + (yb ? n : 0), x + ((xb^1) ? n : 0));\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\
    \n\tvoid add_clause(size_type x, bool xb) {\r\n\t\tassert(x < n);\r\n\t\tscc.add_edge(x\
    \ + (xb ? n : 0), 2*n);\r\n\t\tscc.add_edge(x + (xb ? n : 0), 2*n + 1);\r\n\t\t\
    scc.add_edge(2*n, x + ((xb^1) ? n : 0));\r\n\t\tscc.add_edge(2*n + 1, x + ((xb^1)\
    \ ? n : 0));\r\n\t}\r\n\t\r\n\tbool build() {\r\n\t\tscc.build(false);\r\n\t\t\
    ans.assign(n, false);\r\n\t\tsatisfiability = false;\r\n\t\tif (scc.get_rank(2*n)\
    \ == scc.get_rank(2*n + 1)) return false;\r\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) {\r\n\t\t\tif (scc.get_rank(i) == scc.get_rank(i + n)) return false;\r\n\
    \t\t\tif (scc.get_rank(i) > scc.get_rank(i + n)) ans[i] = true;\r\n\t\t}\r\n\t\
    \tisbuilt = true;\r\n\t\tsatisfiability = true;\r\n\t\treturn true;\r\n\t}\r\n\
    \t\r\n\tconst std::vector<bool> & get_answer() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(satisfiability);\r\n\t\treturn ans;\r\n\t}\r\n\t\r\n\tbool get(size_type\
    \ i) const {\r\n\t\tassert(isbuilt);\r\n\t\tassert(satisfiability);\r\n\t\tassert(i\
    \ < n);\r\n\t\treturn ans[i];\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_TWO_SAT_HPP\r\n#define INCLUDE_GUARD_TWO_SAT_HPP\r\n\
    \r\n#include <vector>\r\n#include <cassert>\r\n\r\n/*\r\nlast-updated: 2020/09/10\r\
    \n\r\n# \u4ED5\u69D8\r\nTwoSat(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(n)\r\n\tn \u5909\u6570\u3092\u5BFE\u8C61\u3068\u3057\u3066\u69CB\u7BC9\
    \r\n\r\nvoid add_clause(size_type x, bool xb, size_type y, bool yb) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t(x = xb) v (y = yb) \u3092\u52A0\u3048\
    \u308B\r\n\r\nvoid add_clause(size_type x, bool xb) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\tx = xb \u3092\u52A0\u3048\u308B\r\n\r\nbool build() :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u5168\u3066\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u5909\u6570\u306E\u5024\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u3092\u6C42\u3081\u308B\r\n\t\u305D\u306E\u3088\u3046\
    \u306A\u7D44\u307F\u5408\u308F\u305B\u304C\u5B58\u5728\u3059\u308B\u306A\u3089\
    \u3070 true, \u5B58\u5728\u3057\u306A\u3044\u306E\u306A\u3089\u3070 false \u3092\
    \u8FD4\u3059\r\n\r\nconst std::vector<bool> & get_answer() const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5168\u3066\u306E\u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306A\u5909\u6570\u306E\u771F\u507D\u5024\u304C\u5165\
    \u3063\u3066\u3044\u308B\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\r\n\r\nbool\
    \ get(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5168\
    \u3066\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u5909\u6570\
    \u306E\u5024\u306E\u7D44\u307F\u5408\u308F\u305B\u3067\u3001\u5909\u6570 i \u306E\
    \u771F\u507D\u5024\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\n\"AC Library\" https://atcoder.jp/posts/517m,\
    \ 2020/09/10\r\n*/\r\n\r\n#include \"GraphTheory/StronglyConnectedComponents.hpp\"\
    \r\n\r\nstruct TwoSat {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tStronglyConnectedComponents scc;\r\n\tstd::vector<bool>\
    \ ans;\r\n\tbool isbuilt, satisfiability;\r\n\t\r\npublic:\r\n\tTwoSat(size_type\
    \ n) : n(n), scc(2 * n + 2) {}\r\n\t\r\n\tvoid add_clause(size_type x, bool xb,\
    \ size_type y, bool yb) {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\t\
    scc.add_edge(x + (xb ? n : 0), y + ((yb^1) ? n : 0));\r\n\t\tscc.add_edge(y +\
    \ (yb ? n : 0), x + ((xb^1) ? n : 0));\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\
    \tvoid add_clause(size_type x, bool xb) {\r\n\t\tassert(x < n);\r\n\t\tscc.add_edge(x\
    \ + (xb ? n : 0), 2*n);\r\n\t\tscc.add_edge(x + (xb ? n : 0), 2*n + 1);\r\n\t\t\
    scc.add_edge(2*n, x + ((xb^1) ? n : 0));\r\n\t\tscc.add_edge(2*n + 1, x + ((xb^1)\
    \ ? n : 0));\r\n\t}\r\n\t\r\n\tbool build() {\r\n\t\tscc.build(false);\r\n\t\t\
    ans.assign(n, false);\r\n\t\tsatisfiability = false;\r\n\t\tif (scc.get_rank(2*n)\
    \ == scc.get_rank(2*n + 1)) return false;\r\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) {\r\n\t\t\tif (scc.get_rank(i) == scc.get_rank(i + n)) return false;\r\n\
    \t\t\tif (scc.get_rank(i) > scc.get_rank(i + n)) ans[i] = true;\r\n\t\t}\r\n\t\
    \tisbuilt = true;\r\n\t\tsatisfiability = true;\r\n\t\treturn true;\r\n\t}\r\n\
    \t\r\n\tconst std::vector<bool> & get_answer() const {\r\n\t\tassert(isbuilt);\r\
    \n\t\tassert(satisfiability);\r\n\t\treturn ans;\r\n\t}\r\n\t\r\n\tbool get(size_type\
    \ i) const {\r\n\t\tassert(isbuilt);\r\n\t\tassert(satisfiability);\r\n\t\tassert(i\
    \ < n);\r\n\t\treturn ans[i];\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_TWO_SAT_HPP"
  dependsOn:
  - GraphTheory/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: Mathematics/TwoSat.hpp
  requiredBy: []
  timestamp: '2020-09-10 10:57:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/TwoSat.test.cpp
documentation_of: Mathematics/TwoSat.hpp
layout: document
redirect_from:
- /library/Mathematics/TwoSat.hpp
- /library/Mathematics/TwoSat.hpp.html
title: Mathematics/TwoSat.hpp
---
