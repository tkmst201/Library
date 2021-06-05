---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3)"
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
  bundledCode: "#line 1 \"Test/HeavyLightDecomposition.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#line 1 \"GraphTheory/HeavyLightDecomposition.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n#include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp\r\
    \n */\r\nstruct HeavyLightDecomposition {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<int> par_;\r\n\tstd::vector<int>\
    \ heavy_, head_, heavy_size_, heavy_depth_;\r\n\tstd::vector<int> tree_id_, roots_;\r\
    \n\tstd::vector<int> in_, out_;\r\n\tstd::vector<std::vector<int>> par_dblng_;\r\
    \n\tbool LCA;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition(const Graph & g, bool\
    \ LCA = false)\r\n\t\t: HeavyLightDecomposition(g, -1, LCA) {}\r\n\t\r\n\tHeavyLightDecomposition(const\
    \ Graph & g, int root, bool LCA)\r\n\t\t: n(g.size()), par_(n, -1), heavy_(n,\
    \ -1), tree_id_(n, -1), in_(n, -1), out_(n, -1), LCA(LCA) {\r\n\t\tstd::vector<int>\
    \ sub_size(n, 0), next(n, -1);\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\t\
    if (tree_id_[i] != -1) continue;\r\n\t\t\tif (root != -1 && i != root) continue;\r\
    \n\t\t\ttree_id_[i] = roots_.size();\r\n\t\t\tstd::stack<int> stk;\r\n\t\t\tstk.emplace(i);\r\
    \n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\tconst int u = stk.top();\r\n\t\t\t\t\
    stk.pop();\r\n\t\t\t\tif (sub_size[u]) {\r\n\t\t\t\t\tint mx_size = 0;\r\n\t\t\
    \t\t\tfor (int v : g[u]) {\r\n\t\t\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\
    \t\t\tsub_size[u] += sub_size[v];\r\n\t\t\t\t\t\tif (mx_size < sub_size[v]) mx_size\
    \ = sub_size[v], next[u] = v;\r\n\t\t\t\t\t}\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t\
    }\r\n\t\t\t\tsub_size[u] = 1;\r\n\t\t\t\tstk.emplace(u);\r\n\t\t\t\tfor (int v\
    \ : g[u]) {\r\n\t\t\t\t\tassert(0 <= v && v < n);\r\n\t\t\t\t\tassert(v != u);\r\
    \n\t\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\t\
    tree_id_[v] = roots_.size();\r\n\t\t\t\t\tstk.emplace(v);\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t\troots_.emplace_back(i);\r\n\t\t}\r\n\t\tint euc = 0;\r\n\t\tfor (int\
    \ r : roots_) {\r\n\t\t\theavy_[r] = head_.size();\r\n\t\t\thead_.emplace_back(r);\r\
    \n\t\t\theavy_size_.emplace_back(1);\r\n\t\t\theavy_depth_.emplace_back(0);\r\n\
    \t\t\tstd::stack<std::pair<int, int>> stk;\r\n\t\t\tstk.emplace(r, 0);\r\n\t\t\
    \twhile (!stk.empty()) {\r\n\t\t\t\tconst auto [u, i] = stk.top();\r\n\t\t\t\t\
    stk.pop();\r\n\t\t\t\tif (i < static_cast<int>(g[u].size())) {\r\n\t\t\t\t\tstk.emplace(u,\
    \ i + 1);\r\n\t\t\t\t\tconst int v = g[u][i];\r\n\t\t\t\t\tif (v != par_[u] &&\
    \ v != next[u]) {\r\n\t\t\t\t\t\theavy_[v] = head_.size();\r\n\t\t\t\t\t\thead_.emplace_back(v);\r\
    \n\t\t\t\t\t\theavy_size_.emplace_back(1);\r\n\t\t\t\t\t\theavy_depth_.emplace_back(heavy_depth_[heavy_[u]]\
    \ + 1);\r\n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    \tif (i == 0) {\r\n\t\t\t\t\tin_[u] = euc++;\r\n\t\t\t\t\tconst int v = next[u];\r\
    \n\t\t\t\t\tif (v != -1) {\r\n\t\t\t\t\t\theavy_[v] = heavy_[u];\r\n\t\t\t\t\t\
    \t++heavy_size_[heavy_[u]];\r\n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\
    \n\t\t\t\t}\r\n\t\t\t\tif (i == static_cast<int>(g[u].size())) out_[u] = euc;\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (!LCA) return;\r\n\t\tint max_depth = *std::max_element(begin(heavy_depth_),\
    \ end(heavy_depth_));\r\n\t\tint lglg_n = 0;\r\n\t\twhile ((1 << lglg_n) <= max_depth)\
    \ ++lglg_n;\r\n\t\tpar_dblng_.assign(lglg_n + 1, std::vector<int>(heavy_size(),\
    \ -1));\r\n\t\tfor (int i = 0; i < heavy_size(); ++i) par_dblng_[0][i] = par_[head_[i]]\
    \ == -1 ? head_[i] : par_[head_[i]];\r\n\t\tfor (int i = 0; i < lglg_n; ++i) {\r\
    \n\t\t\tfor (int j = 0; j < heavy_size(); ++j) {\r\n\t\t\t\tpar_dblng_[i + 1][j]\
    \ = par_dblng_[i][heavy_[par_dblng_[i][j]]];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\
    \n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tint par(int\
    \ v) const noexcept {\r\n\t\tassert(0 <= v && v < size());\r\n\t\treturn par_[v];\r\
    \n\t}\r\n\t\r\n\tint tree_id(int v) const noexcept {\r\n\t\tassert(0 <= v && v\
    \ < size());\r\n\t\treturn tree_id_[v];\r\n\t}\r\n\t\r\n\tint tree_cnt() const\
    \ noexcept {\r\n\t\treturn roots_.size();\r\n\t}\r\n\t\r\n\tconst std::vector<int>\
    \ & trees() const noexcept {\r\n\t\treturn roots_;\r\n\t}\r\n\t\r\n\tint heavy(int\
    \ v) const noexcept {\r\n\t\tassert(0 <= v && v < size());\r\n\t\treturn heavy_[v];\r\
    \n\t}\r\n\t\r\n\tint head(int k) const noexcept {\r\n\t\tassert(0 <= k && k <\
    \ heavy_size());\r\n\t\treturn head_[k];\r\n\t}\r\n\t\r\n\tint heavy_size() const\
    \ noexcept {\r\n\t\treturn head_.size();\r\n\t}\r\n\t\r\n\tint heavy_size(int\
    \ k) const noexcept {\r\n\t\tassert(0 <= k && k < heavy_size());\r\n\t\treturn\
    \ heavy_size_[k];\r\n\t}\r\n\t\r\n\tint heavy_depth(int k) const noexcept {\r\n\
    \t\tassert(0 <= k && k < heavy_size());\r\n\t\treturn heavy_depth_[k];\r\n\t}\r\
    \n\t\r\n\tint in(int v) const noexcept {\r\n\t\tassert(0 <= v && v < size());\r\
    \n\t\treturn in_[v];\r\n\t}\r\n\t\r\n\tint out(int v) const noexcept {\r\n\t\t\
    assert(0 <= v && v < size());\r\n\t\treturn out_[v];\r\n\t}\r\n\t\r\n\tconst std::vector<std::vector<int>>\
    \ & par_dblng() const noexcept {\r\n\t\tassert(LCA);\r\n\t\treturn par_dblng_;\r\
    \n\t}\r\n\t\r\n\tstd::pair<int, int> lca_heavy(int x, int y) const noexcept {\r\
    \n\t\tassert(LCA);\r\n\t\tassert(0 <= x && x < size());\r\n\t\tassert(0 <= y &&\
    \ y < size());\r\n\t\tassert(tree_id_[x] == tree_id_[y]);\r\n\t\tif (heavy_[x]\
    \ == heavy_[y]) return {x, y};\r\n\t\tconst bool isswap = heavy_depth_[heavy_[x]]\
    \ < heavy_depth_[heavy_[y]];\r\n\t\tif (isswap) std::swap(x, y);\r\n\t\tconst\
    \ int diff = heavy_depth_[heavy_[x]] - heavy_depth_[heavy_[y]];\r\n\t\tfor (int\
    \ i = 0; i < static_cast<int>(par_dblng_.size()); ++i) if (diff >> i & 1) x =\
    \ par_dblng_[i][heavy_[x]];\r\n\t\tif (heavy_[x] == heavy_[y]) return isswap ?\
    \ std::make_pair(y, x) : std::make_pair(x, y);\r\n\t\tfor (int i = par_dblng_.size()\
    \ - 1; i >= 0; --i) {\r\n\t\t\tconst int p1 = par_dblng_[i][heavy_[x]], p2 = par_dblng_[i][heavy_[y]];\r\
    \n\t\t\tif (heavy_[p1] != heavy_[p2]) x = p1, y = p2;\r\n\t\t}\r\n\t\tx = par_dblng_[0][heavy_[x]];\r\
    \n\t\ty = par_dblng_[0][heavy_[y]];\r\n\t\treturn isswap ? std::make_pair(y, x)\
    \ : std::make_pair(x, y);\r\n\t}\r\n\t\r\n\tint lca(int x, int y) {\r\n\t\tassert(LCA);\r\
    \n\t\tassert(0 <= x && x < size());\r\n\t\tassert(0 <= y && y < size());\r\n\t\
    \tassert(tree_id_[x] == tree_id_[y]);\r\n\t\tconst auto [a, b] = lca_heavy(x,\
    \ y);\r\n\t\treturn in_[a] < in_[b] ? a : b;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"\
    Test/HeavyLightDecomposition.test.cpp\"\n\r\n#include <cstdio>\r\n#line 7 \"Test/HeavyLightDecomposition.test.cpp\"\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tHeavyLightDecomposition::Graph\
    \ g(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\",\
    \ &p);\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\tHeavyLightDecomposition hld(g,\
    \ true);\r\n\t\r\n\twhile (Q--) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u,\
    \ &v);\r\n\t\tprintf(\"%d\\n\", hld.lca(u, v));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    GraphTheory/HeavyLightDecomposition.hpp\"\r\n\r\n#include <cstdio>\r\n#include\
    \ <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\
    \n\t\r\n\tHeavyLightDecomposition::Graph g(N);\r\n\tfor (int i = 1; i < N; ++i)\
    \ {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\tg[p].emplace_back(i);\r\n\t\
    }\r\n\tHeavyLightDecomposition hld(g, true);\r\n\t\r\n\twhile (Q--) {\r\n\t\t\
    int u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tprintf(\"%d\\n\", hld.lca(u,\
    \ v));\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/HeavyLightDecomposition.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/HeavyLightDecomposition.test.cpp
layout: document
redirect_from:
- /verify/Test/HeavyLightDecomposition.test.cpp
- /verify/Test/HeavyLightDecomposition.test.cpp.html
title: Test/HeavyLightDecomposition.test.cpp
---
