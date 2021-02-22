---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/LowestCommonAncestor.hpp
    title: GraphTheory/LowestCommonAncestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/LowestCommonAncestor.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\r\n\r\n#line 1 \"GraphTheory/LowestCommonAncestor.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/08/27\r\n\r\n\u6728\u30B0\u30E9\u30D5\u3067\
    \u306E\u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\r\n\u6728\u30B0\
    \u30E9\u30D5\u3067\u306F\u306A\u3044\u3068\u30D0\u30B0\u308B\u306E\u3067\u6CE8\
    \u610F\r\n\r\n\u304A\u307E\u3051\u3067\u6728\u306E\u4EFB\u610F\u306E 2 \u9802\u70B9\
    \u9593\u306E\u30D1\u30B9\u306E\u9577\u3055\u3092\u8FD4\u3059\u6A5F\u80FD\u304C\
    \u3064\u3044\u3066\u3044\u308B\r\nHeavy Light Decomposition \u3092\u4F7F\u3063\
    \u305F \u69CB\u7BC9 O(n loglog n) \u30AF\u30A8\u30EA O(loglog n) \u306E\u65B9\u304C\
    \u65E9\u3044\u306E\u3067\u305D\u3063\u3061\u3092\u4F7F\u304A\u3046\r\n\r\n# \u4ED5\
    \u69D8\r\nLowestCommonAncestor(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(n)\r\n\t\u9802\u70B9\u6570\u304C n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u6210\u3059\u308B\r\n\r\nLowestCommonAncestor(std::vector<std::vector<size_type>>\
    \ g) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n + m)\r\n\t\u30B0\u30E9\u30D5\
    \ g \u3067\u521D\u671F\u5316\u3059\u308B\r\n\tbuild() \u3092\u547C\u3076\u5FC5\
    \u8981\u304C\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\r\n\r\nsize_type size()\
    \ const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\n\r\nvoid add_edge(size_type\
    \ s, size_type t)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9\
    \ u -> \u9802\u70B9 v \u306B\u8FBA\u3092\u5F35\u308B\r\n\r\nvoid clear() :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B0\u30E9\u30D5\u3092\u524A\
    \u9664\u3059\u308B\r\n\r\nvoid build(size_type rootNode = 0)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(N log N)\r\n\tLCA \u8A08\u7B97\u306E\u305F\u3081\u306E\
    \u4E8B\u524D\u8A08\u7B97\u3092\u884C\u3046\r\n\r\nsize_type find(size_type a,\
    \ size_type b) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log N)\r\n\t\u9802\
    \u70B9 a , \u9802\u70B9 b \u306E LCA \u3092\u6C42\u3081\u308B\r\n\r\nsize_type\
    \ query(size_type a, size_type b) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log N)\r\n\t\u30D1\u30B9 a - b \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\
    \r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <utility>\r\n\
    \r\nstruct LowestCommonAncestor {\r\n\tusing size_type = std::size_t;\r\n\t\r\n\
    private:\r\n\tsize_type logsize;\r\n\tstd::vector<std::vector<size_type> > g,\
    \ par;\r\n\tstd::vector<size_type> depth;\r\n\tbool isbuilt;\r\n\t\r\npublic:\r\
    \n\tLowestCommonAncestor(size_type n) {\r\n\t\tg.resize(n);\r\n\t\tisbuilt = false;\r\
    \n\t}\r\n\t\r\n\tLowestCommonAncestor(std::vector<std::vector<size_type>> g) :\
    \ g(g) {\r\n\t\tisbuilt = false;\r\n\t};\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn g.size();\r\n\t}\r\n\t\r\n\tvoid add_edge(size_type s, size_type\
    \ t) {\r\n\t\tassert(s < size());\r\n\t\tassert(t < size());\r\n\t\tg[s].push_back(t);\r\
    \n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tg.clear();\r\n\t\
    \tpar.clear();\r\n\t\tdepth.clear();\r\n\t\tisbuilt = false;\r\n\t}\r\n\t\r\n\t\
    void build(size_type rootNode = 0) {\r\n\t\tassert(rootNode < size());\r\n\t\t\
    logsize = 1;\r\n\t\twhile (1 << logsize < size()) ++logsize;\r\n\t\tdepth.assign(size(),\
    \ size());\r\n\t\tpar.assign(logsize, std::vector<size_type>(size(), size()));\r\
    \n\t\t\r\n\t\tdepth[rootNode] = 0;\r\n\t\tdfs(rootNode, size());\r\n\t\tfor (size_type\
    \ i = 1; i < logsize; ++i) {\r\n\t\t\tfor (size_type j = 0; j < size(); ++j) {\r\
    \n\t\t\t\tif (par[i - 1][j] != size()) par[i][j] = par[i - 1][ par[i - 1][j] ];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tisbuilt = true;\r\n\t}\r\n\t\r\n\tsize_type find(size_type\
    \ a, size_type b) const {\r\n\t\tassert(isbuilt);\r\n\t\tassert(a < size());\r\
    \n\t\tassert(b < size());\r\n\t\tif (depth[a] < depth[b]) std::swap(a, b);\r\n\
    \t\t\r\n\t\tsize_type up = depth[a] - depth[b];\r\n\t\tfor (size_type i = 0; i\
    \ < logsize; ++i) if (up >> i & 1) a = par[i][a];\r\n\t\tif (a == b) return a;\r\
    \n\t\tfor (size_type i = logsize; i > 0; --i) {\r\n\t\t\tif (par[i - 1][a] !=\
    \ par[i - 1][b]) {\r\n\t\t\t\ta = par[i - 1][a];\r\n\t\t\t\tb = par[i - 1][b];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn par[0][a];\r\n\t}\r\n\t\r\n\tsize_type query(size_type\
    \ a, size_type b) const {\r\n\t\tassert(isbuilt);\r\n\t\tassert(a < size());\r\
    \n\t\tassert(b < size());\r\n\t\treturn depth[a] + depth[b] - 2 * depth[find(a,\
    \ b)];\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid dfs(size_type u, size_type p) {\r\n\t\
    \tfor (size_type v : g[u]) {\r\n\t\t\tif (v == p) continue;\r\n\t\t\tdepth[v]\
    \ = depth[u] + 1;\r\n\t\t\tpar[0][v] = u;\r\n\t\t\tdfs(v, u);\r\n\t\t}\r\n\t}\r\
    \n};\r\n\r\n\n#line 4 \"Test/LowestCommonAncestor.test.cpp\"\n\r\n#include <cstdio>\r\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tLowestCommonAncestor\
    \ lca(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\"\
    , &p);\r\n\t\tlca.add_edge(p, i);\r\n\t}\r\n\tlca.build();\r\n\t\r\n\twhile (Q--)\
    \ {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tprintf(\"%d\\n\"\
    , lca.find(u, v));\r\n\t}\r\n\t\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    GraphTheory/LowestCommonAncestor.hpp\"\r\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tLowestCommonAncestor\
    \ lca(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\"\
    , &p);\r\n\t\tlca.add_edge(p, i);\r\n\t}\r\n\tlca.build();\r\n\t\r\n\twhile (Q--)\
    \ {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tprintf(\"%d\\n\"\
    , lca.find(u, v));\r\n\t}\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: Test/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 16:57:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/LowestCommonAncestor.test.cpp
- /verify/Test/LowestCommonAncestor.test.cpp.html
title: Test/LowestCommonAncestor.test.cpp
---
