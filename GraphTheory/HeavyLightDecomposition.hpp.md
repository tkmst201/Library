---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition_Query.hpp
    title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3) \u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition.test.cpp
    title: Test/HeavyLightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp
  bundledCode: "#line 1 \"GraphTheory/HeavyLightDecomposition.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include <utility>\r\n\
    #include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp\r\
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
    \ y);\r\n\t\treturn in_[a] < in_[b] ? a : b;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP\r\n#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
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
    \ y);\r\n\t\treturn in_[a] < in_[b] ? a : b;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/HeavyLightDecomposition.hpp
  requiredBy:
  - GraphTheory/HeavyLightDecomposition_Query.hpp
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - Test/HeavyLightDecomposition.test.cpp
documentation_of: GraphTheory/HeavyLightDecomposition.hpp
layout: document
title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3)"
---

# 概要

森に含まれる各木に対して重軽分解とオイラーツアーを行います。
おまけで任意の $2$ 頂点の LCA を空間 $\Theta(N\log{\log{N}})$ クエリ $\mathcal{O}(\log{\log{N}})$ で求めることもできます。  
重軽分解についてはページ下部にある参考リンク先を参照してください。  

- `HeavyLightDecomposition(const Graph & g, bool LCA = false)`
	- `LCA` $= false$ : $\Theta(N)$, `LCA` $= true$ : $\mathcal{O}(N \log{\log{N}})$ `g` の各木に対して重軽分解とオイラーツアーを行う
- `HeavyLightDecomposition(const Graph & g, int root, bool LCA = false)`
	- `LCA` $= false$ : $\Theta(N)$, `LCA` $= true$ : $\mathcal{O}(N \log{\log{N}})$  頂点 `root` を根とした根付き木 `g` に対して重軽分解とオイラーツアーを行う
- `int size()`
	- $\Theta(1)$ グラフの頂点数 $N$ を返す
- `int par(int v)`
	- $\Theta(1)$ 頂点 $v$ の親を返す
- `int tree_id(int v)`
	- $\Theta(1)$ 頂点 $v$ が属する木の ID を返す
- `int tree_cnt()`
	- $\Theta(1)$ グラフ `g` に含まれる木の個数を返す
- `int trees()`
	- $\Theta(1)$ グラフ `g` に含まれる木の根を ID の昇順に返す
- `int heavy(int v)`
	- $\Theta(1)$ 頂点 `v` が属する heavy-edge の ID を返す
- `int head(int k)`
	- $\Theta(1)$ heavy-edge `k` に含まれる頂点の内、最も根側の頂点番号を返す
- `int heavy_size()`
	- $\Theta(1)$ heavy-edge の本数を返す
- `int heavy_size(int k)`
	- $\Theta(1)$ heavy-edge `k` に含まれるの頂点数を返す
- `int heavy_depth(int k)`
	- $\Theta(1)$ heavy-edge `k` から根が属する heavy-edge 間のパス上に含まれる heavy-edge の個数 $-1$ を返す
- `int in(int v)`
	- $\Theta(1)$ 頂点 `v` に入ったときの時刻を返す
- `int out(int v)`
	- $\Theta(1)$ 頂点 `v` から出たときの時刻を返す
- `const std::vector<std::vector<int>> & par_dblng()`
	- $\Theta(1)$ $[i][j] :=$ heavy-edge $j$ から $2^i$ 回根方向に heavy-edge を登ったすぐの頂点番号(存在しなければ根の番号)
- `std::pair<int, int> lca_heavy(int x, int y)`
	- $\mathcal{O}(\log{\log{N}})$ 頂点 $x, y$ から根側に移動して同じ heavy-edge 内となるような最も移動回数の和が小さい頂点位置の組を返す
- `lca(int x, int y)`
	- $\mathcal{O}(\log{\log{N}})$ 頂点 $x, y$ の最近共通祖先を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  

---

### HeavyLightDecomposition(const Graph & g, bool LCA = false)

根を指定せずに `g` の各木に対して重軽分解とオイラーツアーを行います。
根はその木に含まれる最小の番号の頂点となります。
LCA を求めたい場合は、`LCA` $= true$ を指定してください。  

**制約**

- `g` は森

**計算量**

- `LCA` $= false$ : $\Theta(N)$
- `LCA` $= true$  : $\mathcal{O}(N \log{\log{N}})$

---

### HeavyLightDecomposition(const Graph & g, int root, bool LCA = false)

頂点 `root` を根とした根付き木 `g` に対して重軽分解とオイラーツアーを行います。
LCA を求めたい場合は、`LCA` $= true$ を指定してください。  

**制約**

- `g` は `root` を根とした根付き木または木

**計算量**

- `LCA` $= false$ : $\Theta(N)$
- `LCA` $= true$  : $\mathcal{O}(N \log{\log{N}})$

---

<br>

# メンバ関数

### int size()

グラフの頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int par(int v)

頂点 $v$ の親を返します。
存在しなければ $-1$ を返します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int tree_id(int v)

頂点 $v$ が属する木の ID を返します。
ID は各木に対して $0$ から順に割り振られます。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int tree_cnt()

グラフ `g` に含まれる木の個数を返します。  

**計算量**

- $\Theta(1)$

---

### int trees()

グラフ `g` に含まれる木の根を ID の昇順に返します。  

**計算量**

- $\Theta(1)$

---

### int heavy(int v)

頂点 `v` が属する heavy-edge の ID を返します。  
ID は各 heavy-edge に対して $0$ から順に割り振られます。  

**計算量**

- $\Theta(1)$

---

### int head(int k)

heavy-edge `k` に含まれる頂点の内、最も根側の頂点番号を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int heavy_size()

heavy-edge の本数を返します。  

**計算量**

- $\Theta(1)$

---

### int heavy_size(int k)

heavy-edge `k` に含まれるの頂点数を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int heavy_depth(int k)

heavy-edge `k` から根が属する heavy-edge 間のパス上に含まれる heavy-edge の個数 $-1$ を返します。  

**制約**

- $0 \leq k <$ `heavy_size()`

**計算量**

- $\Theta(1)$

---

### int in(int v)

頂点 `v` に入ったときの時刻を返します。
ただし、時刻は頂点に到達した際に増加します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### int out(int v)

頂点 `v` から出たときの時刻を返します。
ただし、時刻は頂点に到達した際に増加します。  

**制約**

- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### const std::vector&lt;std::vector&lt;int&gt;&gt; & par_dblng()

次のようなテーブルを返します。

- $[i][j] :=$ heavy-edge $j$ から $2^i$ 回根方向に heavy-edge を登ったすぐの頂点番号(存在しなければ根の番号)

**制約**

- `LCA` $= true$

**計算量**

- $\Theta(1)$

---

### std::pair&lt;int, int&gt; lca_heavy(int x, int y)

頂点 $x, y$ から根側に移動して同じ heavy-edge 内となるような最も移動回数の和が小さい頂点位置の組を返します。  

**制約**

- `LCA` $= true$
- $0 \leq x, y < N$
- $x, y$ は同じ木に属する

**計算量**

- $\mathcal{O}(\log{\log{N}})$

---

### lca(int x, int y)

頂点 $x, y$ の最近共通祖先を返します。  

**制約**

- `LCA` $= true$
- $0 \leq x, y < N$
- $x, y$ は同じ木に属する

**計算量**

- $\mathcal{O}(\log{\log{N}})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/HeavyLightDecomposition.hpp"
using namespace std;

int main() {
	HeavyLightDecomposition::Graph g(9);
	//            1
	//       2        3
	//    0     4         5
	// 6       7 8
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[0].emplace_back(6);
	g[4].emplace_back(7);
	g[4].emplace_back(8);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	HeavyLightDecomposition hld(g, 1, true);
	
	cout << "size() = " << hld.size() << endl; // 9
	cout << "heavy_size() = " << hld.heavy_size() << endl; // 4
	cout << "par: ";
	// 2 -1 1 1 2 3 0 4 4
	for (int i = 0; i < hld.size(); ++i) cout << hld.par(i) << " \n"[i + 1 == hld.size()];
	
	cout << "heavy: ";
	// 1 0 0 3 0 3 1 0 2
	for (int i = 0; i < hld.size(); ++i) cout << hld.heavy(i) << " \n"[i + 1 == hld.size()];
	// heavy 0 : [1, 2, 4, 8]
	// heavy 1 : [0, 6]
	// heavy 2 : [8]
	// heavy 3 : [3, 5]
	//           heavy-0
	// heavy-1   heavy-2   heavy-3
	cout << "head: ";
	// 1 0 8 3
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.head(i) << " \n"[i + 1 == hld.heavy_size()];
	cout << "heavy_size: ";
	// 4 2 1 2
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.heavy_size(i) << " \n"[i + 1 == hld.heavy_size()];
	cout << "heavy_size: ";
	// 0 1 1 1
	for (int i = 0; i < hld.heavy_size(); ++i) cout << hld.heavy_depth(i) << " \n"[i + 1 == hld.heavy_size()];
	
	cout << "in: ";
	// 5 0 1 7 2 8 6 3 4
	for (int i = 0; i < hld.size(); ++i) cout << hld.in(i) << " \n"[i + 1 == hld.size()];
	cout << "out: ";
	// 7 9 7 9 5 9 7 4 5
	for (int i = 0; i < hld.size(); ++i) cout << hld.out(i) << " \n"[i + 1 == hld.size()];
	
	{
		auto [x, y] = hld.lca_heavy(1, 4);
		cout << "lca_heavy(1, 4) = (" << x << ", " << y << ")\n"; // (1, 4)
	}
	{
		auto [x, y] = hld.lca_heavy(2, 6);
		cout << "lca_heavy(2, 6) = (" << x << ", " << y << ")\n"; // (2, 2)
	}
	{
		auto [x, y] = hld.lca_heavy(6, 5);
		cout << "lca_heavy(6, 5) = (" << x << ", " << y << ")\n"; // (2, 1)
	}
	
	cout << "lca(2, 3) = " << hld.lca(2, 3) << endl; // 1
	cout << "lca(6, 8) = " << hld.lca(6, 8) << endl; // 2
	cout << "lca(4, 8) = " << hld.lca(4, 8) << endl; // 4
}
```

<br>

# 参考

2020/04/19: [https://qiita.com/ageprocpp/items/8dfe768218da83314989](https://qiita.com/ageprocpp/items/8dfe768218da83314989)  
2020/04/19: [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)  
2020/09/18: [https://codeforces.com/blog/entry/53170](https://codeforces.com/blog/entry/53170)  

<br>