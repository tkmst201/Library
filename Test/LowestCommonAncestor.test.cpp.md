---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/LowestCommonAncestor.hpp
    title: "\u6700\u8FD1\u5171\u901A\u7956\u5148 (LCA)"
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
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <utility>\r\n#include\
    \ <cstdint>\r\n#include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp\r\
    \n */\r\nstruct LowestCommonAncestor {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n, logn;\r\n\tstd::vector<std::vector<int>> par;\r\n\
    \tstd::vector<int> depth_;\r\n\t\r\npublic:\r\n\tLowestCommonAncestor(const Graph\
    \ & g, int root = 0) : n(g.size()) {\r\n\t\tassert(0 <= root && root < n);\r\n\
    \t\tlogn = 1;\r\n\t\twhile ((1 << logn) + 1 <= n) ++logn;\r\n\t\tpar.assign(logn,\
    \ std::vector<int>(n, -1));\r\n\t\tdepth_.assign(n, 0);\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tpar[0][root] = root;\r\n\t\tstk.emplace(root, root);\r\n\t\
    \twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, p] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tfor (int v : g[u]) {\r\n\t\t\t\tif (v == p) continue;\r\n\t\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\t\tpar[0][v] = u;\r\n\t\t\t\tdepth_[v] = depth_[u] +\
    \ 1;\r\n\t\t\t\tstk.emplace(v, u);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int i = 1;\
    \ i < logn; ++i) {\r\n\t\t\tfor (int j = 0; j < n; ++j) par[i][j] = par[i - 1][par[i\
    \ - 1][j]];\r\n\t\t}\r\n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tint find(int a, int b) const noexcept {\r\n\t\tassert(0\
    \ <= a && a < size());\r\n\t\tassert(0 <= b && b < size());\r\n\t\tassert(par[0][a]\
    \ != -1);\r\n\t\tassert(par[0][b] != -1);\r\n\t\tif (depth_[a] < depth_[b]) std::swap(a,\
    \ b);\r\n\t\ta = parent(a, depth_[a] - depth_[b]);\r\n\t\tif (a == b) return a;\r\
    \n\t\tfor (int i = logn - 1; i >= 0; --i) {\r\n\t\t\tif (par[i][a] != par[i][b])\
    \ a = par[i][a], b = par[i][b]; \r\n\t\t}\r\n\t\treturn par[0][a];\r\n\t}\r\n\t\
    \r\n\tint parent(int u, int k = 1) const noexcept {\r\n\t\tassert(0 <= u && u\
    \ < size());\r\n\t\tassert(0 <= k && k <= depth_[u]);\r\n\t\tassert(par[0][u]\
    \ != -1);\r\n\t\tfor (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];\r\
    \n\t\treturn u;\r\n\t}\r\n\t\r\n\tint depth(int u) const noexcept {\r\n\t\tassert(0\
    \ <= u && u < size());\r\n\t\tassert(par[0][u] != -1);\r\n\t\treturn depth_[u];\r\
    \n\t}\r\n};\r\n\r\n\n#line 4 \"Test/LowestCommonAncestor.test.cpp\"\n\r\n#include\
    \ <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\
    \n\t\r\n\tLowestCommonAncestor::Graph g(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\
    \n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\
    \tLowestCommonAncestor lca(g, 0);\r\n\t\r\n\twhile (Q--) {\r\n\t\tint u, v;\r\n\
    \t\tscanf(\"%d %d\", &u, &v);\r\n\t\tprintf(\"%d\\n\", lca.find(u, v));\r\n\t\
    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    GraphTheory/LowestCommonAncestor.hpp\"\r\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tLowestCommonAncestor::Graph\
    \ g(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\",\
    \ &p);\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\tLowestCommonAncestor lca(g, 0);\r\
    \n\t\r\n\twhile (Q--) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\
    \tprintf(\"%d\\n\", lca.find(u, v));\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: Test/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2022-05-15 21:01:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/LowestCommonAncestor.test.cpp
- /verify/Test/LowestCommonAncestor.test.cpp.html
title: Test/LowestCommonAncestor.test.cpp
---
