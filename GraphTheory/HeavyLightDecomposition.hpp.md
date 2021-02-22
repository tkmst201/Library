---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
    links:
    - https://codeforces.com/blog/entry/53170,
    - https://math314.hateblo.jp/entry/2014/06/24/220107,
    - https://qiita.com/ageprocpp/items/8dfe768218da83314989,
  bundledCode: "#line 1 \"GraphTheory/HeavyLightDecomposition.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/09/18\r\n\r\nHL \u5206\u89E3 + EulerTour\r\n\u5358\u7D14\u306A\
    \u68EE\u306B\u5BFE\u5FDC(\u81EA\u5DF1\u30EB\u30FC\u30D7, \u591A\u91CD\u8FBA\u306A\
    \u3057)\r\n\r\n# \u7528\u8A9E\r\nlca: \u6700\u8FD1\u5171\u901A\u7956\u5148\r\n\
    heavy-path: heavy-edge \u306E\u307F\u901A\u3063\u3066\u79FB\u52D5\u53EF\u80FD\u306A\
    \u9802\u70B9\u96C6\u5408\r\n\r\n# \u89E3\u8AAC\r\ndfs \u3059\u308B\u969B\u306B\
    \ heavy-edge \u3092\u512A\u5148\u3057\u3066\u901A\u308B\u3088\u3046\u306B\u3059\
    \u308B\u3068\u3001\u540C\u4E00 heavy-path \u5185\u306E\u9802\u70B9\u306E EulerTour\
    \ \u9806\u304C\u9023\u7D9A\u3059\u308B\r\n\r\n\u9802\u70B9 v \u304B\u3089\u540C\
    \u4E00 heavy-path \u5185\u3067\u6839\u306B\u4E0A\u3063\u305F\u3068\u304D\u306B\
    \u901A\u308B\u9802\u70B9\u306F \u533A\u9593 [ in[head[heavy_map[v]], in[v] ] \u306B\
    \u5BFE\u5FDC\r\n\u90E8\u5206\u6728 v \u5185\u306E\u9802\u70B9\u306F [in[v], out[v])\
    \ \u306B\u5BFE\u5FDC\r\n\r\nHL \u5206\u89E3\u3067\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u3001\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306E\u4E21\u65B9\u3092\u634C\u3051\
    \u308B\u3088\u3046\u306B\u306A\u308B\r\n\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\u3067\
    \u30A2\u30FC\u30D9\u30EB\u7FA4\u306A\u3089 EulerTour \u5358\u4F53\u3092\u4F7F\u304A\
    \u3046( HL \u5206\u89E3\u3067\u306F log \u304C 1 \u3064\u591A\u3044)\r\n\r\n#\
    \ \u4ED5\u69D8\r\nHeavyLightDecomposition(const Graph & g, bool use_lca = false)\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF:\r\n\t\tuse_lca = false : \u0398(n)\r\n\t\t\
    use_lca = true: \u0398(n loglog n)\r\n\t\r\n\t\u30B0\u30E9\u30D5 g \u3092 HL \u5206\
    \u89E3\u3059\u308B\r\n\t\u4E00\u5EA6\u6E21\u3057\u305F g \u306F\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\r\n\tuse_lca = false \u306E\u3068\u304D\u306F\
    \ lca \u95A2\u9023\u306E\u6A5F\u80FD\u304C\u4F7F\u3048\u306A\u3044\r\n\r\nHeavyLightDecomposition(const\
    \ Graph & g, size_type root, bool use_lca)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u4E0A\u3068\u540C\u4E00\r\n\t\u30B0\u30E9\u30D5 g \u304C\u6728\u3067\u3042\u308B\
    \u3068\u304D\u3001\u6839\u3092 root \u3068\u3057\u3066 HL \u5206\u89E3\u3092\u884C\
    \u3046\r\n\t\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3057\u305F\
    \u3044\u3068\u304D\u306B\u5FC5\u8981\r\n\r\nstd::pair<size_type, size_type> get_lca_path(size_type\
    \ x, size_type y) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(loglog n)\r\n\t\
    use_lca = true \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u5206\u89E3\
    \u524D\u306E\u30B0\u30E9\u30D5\u306E\u9802\u70B9 x, y \u304C\u5C5E\u3059\u308B\
    \ heavy-path \u306E lca heavy-path \u3092 L \u3068\u3059\u308B\r\n\t\u9802\u70B9\
    \ x, y \u304C heavy-path L \u306B\u5C5E\u3059\u308B\u9802\u70B9\u306B\u5230\u9054\
    \u3059\u308B\u307E\u3067\u4E0A\u3063\u305F\u3068\u304D\u306B\u521D\u3081\u3066\
    \u5230\u9054\u3059\u308B\u9802\u70B9\u306E\u7D44\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ get_lca(size_type x, size_type y) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(loglog n)\r\n\tuse_lca = true \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \r\n\t\u9802\u70B9 x, y \u306E lca \u3092\u8FD4\u3059\r\n\r\n\u4EE5\u4E0B\u3001\
    \u5168\u3066 \u6642\u9593\u8A08\u7B97\u91CF \u0398(1)\r\n\r\nsize_type bf_size()\
    \ const noexcept: \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\
    \r\nsize_type af_size() const noexcept: heavy-path \u306E\u500B\u6570\u3092\u8FD4\
    \u3059\r\n\r\nsize_type par(size_type v) const: \u9802\u70B9 v \u306E\u89AA\u3092\
    \u8FD4\u3059(k \u304C\u6839\u306A\u3089 k \u3092\u8FD4\u3059)\r\nsize_type sub_size(size_type\
    \ v) const: \u9802\u70B9 v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\
    \u5C5E\u3059\u308B\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type depth(size_type\
    \ v) const: \u9802\u70B9 v \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2(0-indexed)\u3092\
    \u8FD4\u3059\r\n\r\nsize_type tree_id(size_type v) const: \u9802\u70B9 v \u304C\
    \u5C5E\u3059\u308B\u6728\u306E id \u3092\u8FD4\u3059\r\nsize_type tree_cnt() const\
    \ noexcept: \u30B0\u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u6728\
    \u306E\u500B\u6570\u3092\u8FD4\u3059\r\nconst std::vector<size_type> & trees()\
    \ const noexcept: \u30B0\u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\
    \u6728\u306E\u6839\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ heavy_map(size_type v) const: \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path\
    \ id \u3092\u8FD4\u3059\r\nsize_type head(size_type k) const: heavy-path k \u5185\
    \u306E\u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\u70B9(= EulerTour \u9806\u3067\
    \u6700\u5C0F) \u3092\u8FD4\u3059\r\nsize_type heavy_size(size_type k) const: heavy-path\
    \ k \u306B\u5C5E\u3059\u308B\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type\
    \ heavy_depth(size_type k) const: heavy-path k \u304B\u3089\u6839\u307E\u3067\u306B\
    \u901A\u308B light-edge \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ in(size_type v) const: \u9802\u70B9 v \u306E EulerTour \u9806\u5E8F(\u540C\u4E00\
    \ heavy-path \u5185\u3067\u306F\u9023\u7D9A) \u3092\u8FD4\u3059\r\nsize_typsize_type\
    \ out(size_type v) conste in(size_type v) const: \u9802\u70B9 v \u304B\u3089\u51FA\
    \u308B\u3068\u304D\u306E EulerTour \u9806\u5E8F\r\nsize_type euler_map(size_type\
    \ k) const: EulerTour \u9806\u5E8F\u304C i \u3067\u3042\u308B\u3088\u3046\u306A\
    \u9802\u70B9\u3092\u8FD4\u3059\r\n\r\nconst std::vector<std::vector<size_type>>\
    \ & par_dblng() const\r\n\tuse_lca = true \u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\r\n\t\u6B21\u306E\u3088\u3046\u306A 2 \u6B21\u5143\u914D\u5217\u3092\
    \u8FD4\u3059\r\n\t[k][i] := heavy-path i \u304B\u3089 2^k \u56DE light-edge \u3092\
    \u4E0A\u3063\u305F\u3068\u304D\u3001\u6700\u521D\u306B\u5230\u9054\u3059\u308B\
    \u9802\u70B9\r\n\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/ageprocpp/items/8dfe768218da83314989,\
    \ 2020/04/19\r\nhttps://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19\r\
    \nhttps://codeforces.com/blog/entry/53170, 2020/09/18\r\n*/\r\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <cstdint>\r\n#include <stack>\r\n#include <utility>\r\
    \n#include <algorithm>\r\n\r\nstruct HeavyLightDecomposition {\r\n\tusing size_type\
    \ = std::uint_fast32_t;\r\n\tusing Graph = std::vector<std::vector<size_type>>;\r\
    \n\t\r\nprivate:\r\n\tsize_type bf_n; // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\
    \r\n\t\r\n\tstd::vector<size_type> par_; // [v] := \u9802\u70B9 v \u306E\u89AA\
    \u306E\u9802\u70B9\u756A\u53F7(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u81EA\
    \u5206\u81EA\u8EAB)\r\n\tstd::vector<size_type> sub_size_; // [v] := \u9802\u70B9\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\r\
    \n\tstd::vector<size_type> depth_; // [v] := \u9802\u70B9 v \u306E\u5143\u306E\
    \u30B0\u30E9\u30D5\u3067\u306E\u6DF1\u3055\r\n\t\r\n\tstd::vector<size_type> tree_id_;\
    \ // [v] := \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u6728\u306E id\r\n\tstd::vector<size_type>\
    \ roots_; // [i] := i \u756A\u76EE\u306E\u6728\u306E root\r\n\t\r\n\tstd::vector<size_type>\
    \ heavy_map_; // [v] := \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path id\r\
    \n\tstd::vector<size_type> head_; // [i] := heavy-path i \u306E\u6700\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9\u756A\u53F7\r\n\tstd::vector<size_type> heavy_size_\
    \ ; // [i] := heavy-path i \u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u500B\u6570\
    \r\n\tstd::vector<size_type> heavy_depth_; // [i] := heavy-path i \u304B\u3089\
    \u6839\u307E\u3067\u306B\u901A\u308B light-edge \u306E\u500B\u6570\r\n\t\r\n\t\
    // euler-tour\r\n\tstd::vector<size_type> in_; // [v] := \u9802\u70B9 v \u306E\
    \ EulerTour \u9806\u5E8F(\u540C\u4E00 heavy-path \u5185\u3067\u306F\u9023\u7D9A\
    )\r\n\tstd::vector<size_type> out_; // [v] := \u9802\u70B9 v \u304B\u3089\u51FA\
    \u308B\u3068\u304D\u306E EulerTour \u9806\u5E8F\r\n\tstd::vector<size_type> euler_map_;\
    \ // [i] := EulerTour \u9806\u5E8F\u304C i \u3067\u3042\u308B\u3088\u3046\u306A\
    \u9802\u70B9\r\n\t\r\n\t// heavy-path doubling\r\n\tstd::vector<std::vector<size_type>>\
    \ par_dblng_; // [k][i] := heavy-path i \u304B\u3089 2^k \u56DE light-edge \u3092\
    \u4E0A\u3063\u305F\u5148\u306E\u9802\u70B9\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition(const\
    \ Graph & g, bool use_lca = false) : HeavyLightDecomposition(g, g.size(), use_lca)\
    \ {}\r\n\tHeavyLightDecomposition(const Graph & g, size_type root, bool use_lca)\
    \ : bf_n(g.size()) {\r\n\t\tpar_.resize(bf_size());\r\n\t\tsub_size_.resize(bf_size());\r\
    \n\t\tdepth_.resize(bf_size());\r\n\t\ttree_id_.assign(bf_size(), bf_size());\r\
    \n\t\tstd::vector<size_type> next(bf_size()); // [v] := \u9802\u70B9 v \u3068\u540C\
    \u4E00 heavy-path \u5185\u3067 v \u3088\u308A 1 \u3064\u8449\u5074\u306E\u9802\
    \u70B9(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u81EA\u5206\u81EA\u8EAB)\r\n\
    \t\t\r\n\t\tfor (size_type i = 0; i < bf_size(); ++i) {\r\n\t\t\tif (tree_id_[i]\
    \ != bf_size()) continue;\r\n\t\t\tif (root != bf_size() && i != root) continue;\r\
    \n\t\t\t\r\n\t\t\tstd::stack<std::pair<size_type, size_type>> stk;\r\n\t\t\tpar_[i]\
    \ = i;\r\n\t\t\tdepth_[i] = 0;\r\n\t\t\ttree_id_[i] = roots_.size();\r\n\t\t\t\
    stk.emplace(i, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\tconst\
    \ size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\t\t\
    if (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\t\t\
    par_[v] = u;\r\n\t\t\t\t\tdepth_[v] = depth_[u] + 1;\r\n\t\t\t\t\ttree_id_[v]\
    \ = roots_.size();\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tsize_type mx = 0;\r\n\t\t\t\t\tnext[u] = u;\r\n\t\t\t\t\tsub_size_[u]\
    \ = 1;\r\n\t\t\t\t\tfor (size_type v : g[u]) {\r\n\t\t\t\t\t\tif (v == par_[u])\
    \ continue;\r\n\t\t\t\t\t\tsub_size_[u] += sub_size_[v];\r\n\t\t\t\t\t\tif (mx\
    \ < sub_size_[v]) {\r\n\t\t\t\t\t\t\tmx = sub_size_[v];\r\n\t\t\t\t\t\t\tnext[u]\
    \ = v;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\troots_.emplace_back(i);\r\
    \n\t\t}\r\n\t\t\r\n\t\theavy_map_.resize(bf_size());\r\n\t\tin_.resize(bf_size());\r\
    \n\t\tout_.resize(bf_size());\r\n\t\teuler_map_.reserve(bf_size());\r\n\t\t\r\n\
    \t\tfor (size_type root : roots_) {\r\n\t\t\tstd::stack<std::pair<size_type, size_type>>\
    \ stk;\r\n\t\t\t\r\n\t\t\theavy_map_[root] = head_.size();\r\n\t\t\thead_.emplace_back(root);\r\
    \n\t\t\theavy_size_.emplace_back(1);\r\n\t\t\theavy_depth_.emplace_back(0);\r\n\
    \t\t\tstk.emplace(root, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\
    \tconst size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\
    \t\tif (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v != par_[u] && v != next[u]) {\r\n\t\
    \t\t\t\t\theavy_map_[v] = head_.size();\r\n\t\t\t\t\t\thead_.emplace_back(v);\r\
    \n\t\t\t\t\t\theavy_size_.emplace_back(1);\r\n\t\t\t\t\t\theavy_depth_.emplace_back(heavy_depth_[heavy_map_[u]]\
    \ + 1);\r\n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    \tif (i == 0) {\r\n\t\t\t\t\tin_[u] = euler_map_.size();\r\n\t\t\t\t\teuler_map_.emplace_back(u);\r\
    \n\t\t\t\t\tconst size_type v = next[u];\r\n\t\t\t\t\tif (v != u) {\r\n\t\t\t\t\
    \t\theavy_map_[v] = heavy_map_[u];\r\n\t\t\t\t\t\t++heavy_size_[heavy_map_[u]];\r\
    \n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (i\
    \ == g[u].size()) out_[u] = euler_map_.size();\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\
    \t\tif (!use_lca) return;\r\n\t\tsize_type max_depth = *std::max_element(begin(heavy_depth_),\
    \ end(heavy_depth_));\r\n\t\tsize_type lglg_n = 0;\r\n\t\twhile ((1 << lglg_n)\
    \ < max_depth) ++lglg_n;\r\n\t\t\r\n\t\tpar_dblng_.assign(lglg_n + 1, std::vector<size_type>(af_size()));\r\
    \n\t\tfor (size_type i = 0; i < af_size(); ++i) par_dblng_[0][i] = par_[head_[i]];\r\
    \n\t\tfor (size_type i = 0; i < lglg_n; ++i) {\r\n\t\t\tfor (size_type j = 0;\
    \ j < af_size(); ++j) {\r\n\t\t\t\tpar_dblng_[i + 1][j] = par_dblng_[i][heavy_map_[par_dblng_[i][j]]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type bf_size() const noexcept { return\
    \ bf_n; }\r\n\tsize_type af_size() const noexcept { return head_.size(); }\r\n\
    \t\r\n\tsize_type par(size_type v) const { assert(v < bf_size()); return par_[v];\
    \ }\r\n\tsize_type sub_size(size_type v) const { assert(v < bf_size()); return\
    \ sub_size_[v]; }\r\n\tsize_type depth(size_type v) const { assert(v < bf_size());\
    \ return depth_[v]; }\r\n\t\r\n\tsize_type tree_id(size_type v) const { assert(v\
    \ < bf_size()); return tree_id_[v]; }\r\n\tsize_type tree_cnt() const noexcept\
    \ { return roots_.size(); }\r\n\tconst std::vector<size_type> & trees() const\
    \ noexcept { return roots_; }\r\n\t\r\n\tsize_type heavy_map(size_type v) const\
    \ { assert(v < bf_size()); return heavy_map_[v]; }\r\n\tsize_type head(size_type\
    \ k) const { assert(k < af_size()); return head_[k]; }\r\n\tsize_type heavy_size(size_type\
    \ k) const { assert(k < af_size()); return heavy_size_[k]; }\r\n\tsize_type heavy_depth(size_type\
    \ k) const { assert(k < af_size()); return heavy_depth_[k]; }\r\n\t\r\n\tsize_type\
    \ in(size_type v) const { assert(v < bf_size()); return in_[v]; }\r\n\tsize_type\
    \ out(size_type v) const { assert(v < bf_size()); return out_[v]; }\r\n\tsize_type\
    \ euler_map(size_type k) const { assert(k < bf_size()); return euler_map_[k];\
    \ }\r\n\t\r\n\tconst std::vector<std::vector<size_type>> & par_dblng() const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\treturn par_dblng_;\r\n\t}\r\n\t\r\n\t\
    std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\tassert(x < bf_size());\r\n\t\tassert(y\
    \ < bf_size());\r\n\t\tassert(tree_id_[x] == tree_id_[y]);\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return {x, y};\r\n\t\t\r\n\t\tbool isswap = heavy_depth_[heavy_map_[x]]\
    \ < heavy_depth_[heavy_map_[y]];\r\n\t\tif (isswap) std::swap(x, y);\r\n\t\t\r\
    \n\t\tconst size_type diff = heavy_depth_[heavy_map_[x]] - heavy_depth_[heavy_map_[y]];\r\
    \n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tif (diff >>\
    \ (i - 1) & 1) x = par_dblng_[i - 1][heavy_map_[x]];\r\n\t\t}\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\
    \n\t\t\r\n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tconst\
    \ size_type p1 = par_dblng_[i - 1][heavy_map_[x]], p2 = par_dblng_[i - 1][heavy_map_[y]];\r\
    \n\t\t\tif (heavy_map_[p1] != heavy_map_[p2]) x = p1, y = p2;\r\n\t\t}\r\n\t\t\
    x = par_dblng_[0][heavy_map_[x]];\r\n\t\ty = par_dblng_[0][heavy_map_[y]];\r\n\
    \t\treturn isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\n\t}\r\n\t\r\
    \n\tsize_type get_lca(size_type x, size_type y) {\r\n\t\tassert(!par_dblng_.empty());\r\
    \n\t\tassert(x < bf_size());\r\n\t\tassert(y < bf_size());\r\n\t\tstd::pair<size_type,\
    \ size_type> res = get_lca_path(x, y);\r\n\t\treturn in_[res.first] < in_[res.second]\
    \ ? res.first : res.second;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP\r\n#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/18\r\n\r\nHL \u5206\u89E3 + EulerTour\r\n\u5358\
    \u7D14\u306A\u68EE\u306B\u5BFE\u5FDC(\u81EA\u5DF1\u30EB\u30FC\u30D7, \u591A\u91CD\
    \u8FBA\u306A\u3057)\r\n\r\n# \u7528\u8A9E\r\nlca: \u6700\u8FD1\u5171\u901A\u7956\
    \u5148\r\nheavy-path: heavy-edge \u306E\u307F\u901A\u3063\u3066\u79FB\u52D5\u53EF\
    \u80FD\u306A\u9802\u70B9\u96C6\u5408\r\n\r\n# \u89E3\u8AAC\r\ndfs \u3059\u308B\
    \u969B\u306B heavy-edge \u3092\u512A\u5148\u3057\u3066\u901A\u308B\u3088\u3046\
    \u306B\u3059\u308B\u3068\u3001\u540C\u4E00 heavy-path \u5185\u306E\u9802\u70B9\
    \u306E EulerTour \u9806\u304C\u9023\u7D9A\u3059\u308B\r\n\r\n\u9802\u70B9 v \u304B\
    \u3089\u540C\u4E00 heavy-path \u5185\u3067\u6839\u306B\u4E0A\u3063\u305F\u3068\
    \u304D\u306B\u901A\u308B\u9802\u70B9\u306F \u533A\u9593 [ in[head[heavy_map[v]],\
    \ in[v] ] \u306B\u5BFE\u5FDC\r\n\u90E8\u5206\u6728 v \u5185\u306E\u9802\u70B9\u306F\
    \ [in[v], out[v]) \u306B\u5BFE\u5FDC\r\n\r\nHL \u5206\u89E3\u3067\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3001\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306E\u4E21\u65B9\u3092\
    \u634C\u3051\u308B\u3088\u3046\u306B\u306A\u308B\r\n\r\n\u30D1\u30B9\u30AF\u30A8\
    \u30EA\u3067\u30A2\u30FC\u30D9\u30EB\u7FA4\u306A\u3089 EulerTour \u5358\u4F53\u3092\
    \u4F7F\u304A\u3046( HL \u5206\u89E3\u3067\u306F log \u304C 1 \u3064\u591A\u3044\
    )\r\n\r\n# \u4ED5\u69D8\r\nHeavyLightDecomposition(const Graph & g, bool use_lca\
    \ = false)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\r\n\t\tuse_lca = false : \u0398\
    (n)\r\n\t\tuse_lca = true: \u0398(n loglog n)\r\n\t\r\n\t\u30B0\u30E9\u30D5 g\
    \ \u3092 HL \u5206\u89E3\u3059\u308B\r\n\t\u4E00\u5EA6\u6E21\u3057\u305F g \u306F\
    \u5909\u66F4\u3057\u3066\u306F\u3044\u3051\u306A\u3044\r\n\tuse_lca = false \u306E\
    \u3068\u304D\u306F lca \u95A2\u9023\u306E\u6A5F\u80FD\u304C\u4F7F\u3048\u306A\u3044\
    \r\n\r\nHeavyLightDecomposition(const Graph & g, size_type root, bool use_lca)\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u4E0A\u3068\u540C\u4E00\r\n\t\u30B0\u30E9\
    \u30D5 g \u304C\u6728\u3067\u3042\u308B\u3068\u304D\u3001\u6839\u3092 root \u3068\
    \u3057\u3066 HL \u5206\u89E3\u3092\u884C\u3046\r\n\t\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA\u3092\u51E6\u7406\u3057\u305F\u3044\u3068\u304D\u306B\u5FC5\u8981\r\n\r\
    \nstd::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: O(loglog n)\r\n\tuse_lca = true \u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u5206\u89E3\u524D\u306E\u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9 x, y \u304C\u5C5E\u3059\u308B heavy-path \u306E lca heavy-path\
    \ \u3092 L \u3068\u3059\u308B\r\n\t\u9802\u70B9 x, y \u304C heavy-path L \u306B\
    \u5C5E\u3059\u308B\u9802\u70B9\u306B\u5230\u9054\u3059\u308B\u307E\u3067\u4E0A\
    \u3063\u305F\u3068\u304D\u306B\u521D\u3081\u3066\u5230\u9054\u3059\u308B\u9802\
    \u70B9\u306E\u7D44\u3092\u8FD4\u3059\r\n\r\nsize_type get_lca(size_type x, size_type\
    \ y) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(loglog n)\r\n\tuse_lca = true\
    \ \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u9802\u70B9 x, y \u306E\
    \ lca \u3092\u8FD4\u3059\r\n\r\n\u4EE5\u4E0B\u3001\u5168\u3066 \u6642\u9593\u8A08\
    \u7B97\u91CF \u0398(1)\r\n\r\nsize_type bf_size() const noexcept: \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type af_size() const\
    \ noexcept: heavy-path \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type par(size_type\
    \ v) const: \u9802\u70B9 v \u306E\u89AA\u3092\u8FD4\u3059(k \u304C\u6839\u306A\
    \u3089 k \u3092\u8FD4\u3059)\r\nsize_type sub_size(size_type v) const: \u9802\u70B9\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u5C5E\u3059\u308B\u9802\
    \u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type depth(size_type v) const: \u9802\u70B9\
    \ v \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2(0-indexed)\u3092\u8FD4\u3059\r\n\
    \r\nsize_type tree_id(size_type v) const: \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\
    \u6728\u306E id \u3092\u8FD4\u3059\r\nsize_type tree_cnt() const noexcept: \u30B0\
    \u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u6728\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\r\nconst std::vector<size_type> & trees() const noexcept: \u30B0\
    \u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u6728\u306E\u6839\u306E\
    \u30EA\u30B9\u30C8\u3092\u8FD4\u3059\r\n\r\nsize_type heavy_map(size_type v) const:\
    \ \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path id \u3092\u8FD4\u3059\r\n\
    size_type head(size_type k) const: heavy-path k \u5185\u306E\u6700\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9(= EulerTour \u9806\u3067\u6700\u5C0F) \u3092\u8FD4\
    \u3059\r\nsize_type heavy_size(size_type k) const: heavy-path k \u306B\u5C5E\u3059\
    \u308B\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type heavy_depth(size_type\
    \ k) const: heavy-path k \u304B\u3089\u6839\u307E\u3067\u306B\u901A\u308B light-edge\
    \ \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type in(size_type v) const:\
    \ \u9802\u70B9 v \u306E EulerTour \u9806\u5E8F(\u540C\u4E00 heavy-path \u5185\u3067\
    \u306F\u9023\u7D9A) \u3092\u8FD4\u3059\r\nsize_typsize_type out(size_type v) conste\
    \ in(size_type v) const: \u9802\u70B9 v \u304B\u3089\u51FA\u308B\u3068\u304D\u306E\
    \ EulerTour \u9806\u5E8F\r\nsize_type euler_map(size_type k) const: EulerTour\
    \ \u9806\u5E8F\u304C i \u3067\u3042\u308B\u3088\u3046\u306A\u9802\u70B9\u3092\u8FD4\
    \u3059\r\n\r\nconst std::vector<std::vector<size_type>> & par_dblng() const\r\n\
    \tuse_lca = true \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u6B21\u306E\
    \u3088\u3046\u306A 2 \u6B21\u5143\u914D\u5217\u3092\u8FD4\u3059\r\n\t[k][i] :=\
    \ heavy-path i \u304B\u3089 2^k \u56DE light-edge \u3092\u4E0A\u3063\u305F\u3068\
    \u304D\u3001\u6700\u521D\u306B\u5230\u9054\u3059\u308B\u9802\u70B9\r\n\r\n\r\n\
    # \u53C2\u8003\r\nhttps://qiita.com/ageprocpp/items/8dfe768218da83314989, 2020/04/19\r\
    \nhttps://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19\r\nhttps://codeforces.com/blog/entry/53170,\
    \ 2020/09/18\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <cstdint>\r\n#include <stack>\r\n#include <utility>\r\n#include <algorithm>\r\
    \n\r\nstruct HeavyLightDecomposition {\r\n\tusing size_type = std::uint_fast32_t;\r\
    \n\tusing Graph = std::vector<std::vector<size_type>>;\r\n\t\r\nprivate:\r\n\t\
    size_type bf_n; // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\r\n\t\r\n\tstd::vector<size_type>\
    \ par_; // [v] := \u9802\u70B9 v \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7(\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070\u81EA\u5206\u81EA\u8EAB)\r\n\tstd::vector<size_type>\
    \ sub_size_; // [v] := \u9802\u70B9 v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\
    \u6728\u306E\u30B5\u30A4\u30BA\r\n\tstd::vector<size_type> depth_; // [v] := \u9802\
    \u70B9 v \u306E\u5143\u306E\u30B0\u30E9\u30D5\u3067\u306E\u6DF1\u3055\r\n\t\r\n\
    \tstd::vector<size_type> tree_id_; // [v] := \u9802\u70B9 v \u304C\u5C5E\u3059\
    \u308B\u6728\u306E id\r\n\tstd::vector<size_type> roots_; // [i] := i \u756A\u76EE\
    \u306E\u6728\u306E root\r\n\t\r\n\tstd::vector<size_type> heavy_map_; // [v] :=\
    \ \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path id\r\n\tstd::vector<size_type>\
    \ head_; // [i] := heavy-path i \u306E\u6700\u3082\u6839\u306B\u8FD1\u3044\u9802\
    \u70B9\u756A\u53F7\r\n\tstd::vector<size_type> heavy_size_ ; // [i] := heavy-path\
    \ i \u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u500B\u6570\r\n\tstd::vector<size_type>\
    \ heavy_depth_; // [i] := heavy-path i \u304B\u3089\u6839\u307E\u3067\u306B\u901A\
    \u308B light-edge \u306E\u500B\u6570\r\n\t\r\n\t// euler-tour\r\n\tstd::vector<size_type>\
    \ in_; // [v] := \u9802\u70B9 v \u306E EulerTour \u9806\u5E8F(\u540C\u4E00 heavy-path\
    \ \u5185\u3067\u306F\u9023\u7D9A)\r\n\tstd::vector<size_type> out_; // [v] :=\
    \ \u9802\u70B9 v \u304B\u3089\u51FA\u308B\u3068\u304D\u306E EulerTour \u9806\u5E8F\
    \r\n\tstd::vector<size_type> euler_map_; // [i] := EulerTour \u9806\u5E8F\u304C\
    \ i \u3067\u3042\u308B\u3088\u3046\u306A\u9802\u70B9\r\n\t\r\n\t// heavy-path\
    \ doubling\r\n\tstd::vector<std::vector<size_type>> par_dblng_; // [k][i] := heavy-path\
    \ i \u304B\u3089 2^k \u56DE light-edge \u3092\u4E0A\u3063\u305F\u5148\u306E\u9802\
    \u70B9\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition(const Graph & g, bool use_lca\
    \ = false) : HeavyLightDecomposition(g, g.size(), use_lca) {}\r\n\tHeavyLightDecomposition(const\
    \ Graph & g, size_type root, bool use_lca) : bf_n(g.size()) {\r\n\t\tpar_.resize(bf_size());\r\
    \n\t\tsub_size_.resize(bf_size());\r\n\t\tdepth_.resize(bf_size());\r\n\t\ttree_id_.assign(bf_size(),\
    \ bf_size());\r\n\t\tstd::vector<size_type> next(bf_size()); // [v] := \u9802\u70B9\
    \ v \u3068\u540C\u4E00 heavy-path \u5185\u3067 v \u3088\u308A 1 \u3064\u8449\u5074\
    \u306E\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u81EA\u5206\u81EA\
    \u8EAB)\r\n\t\t\r\n\t\tfor (size_type i = 0; i < bf_size(); ++i) {\r\n\t\t\tif\
    \ (tree_id_[i] != bf_size()) continue;\r\n\t\t\tif (root != bf_size() && i !=\
    \ root) continue;\r\n\t\t\t\r\n\t\t\tstd::stack<std::pair<size_type, size_type>>\
    \ stk;\r\n\t\t\tpar_[i] = i;\r\n\t\t\tdepth_[i] = 0;\r\n\t\t\ttree_id_[i] = roots_.size();\r\
    \n\t\t\tstk.emplace(i, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\
    \tconst size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\
    \t\tif (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\t\t\
    par_[v] = u;\r\n\t\t\t\t\tdepth_[v] = depth_[u] + 1;\r\n\t\t\t\t\ttree_id_[v]\
    \ = roots_.size();\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tsize_type mx = 0;\r\n\t\t\t\t\tnext[u] = u;\r\n\t\t\t\t\tsub_size_[u]\
    \ = 1;\r\n\t\t\t\t\tfor (size_type v : g[u]) {\r\n\t\t\t\t\t\tif (v == par_[u])\
    \ continue;\r\n\t\t\t\t\t\tsub_size_[u] += sub_size_[v];\r\n\t\t\t\t\t\tif (mx\
    \ < sub_size_[v]) {\r\n\t\t\t\t\t\t\tmx = sub_size_[v];\r\n\t\t\t\t\t\t\tnext[u]\
    \ = v;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\troots_.emplace_back(i);\r\
    \n\t\t}\r\n\t\t\r\n\t\theavy_map_.resize(bf_size());\r\n\t\tin_.resize(bf_size());\r\
    \n\t\tout_.resize(bf_size());\r\n\t\teuler_map_.reserve(bf_size());\r\n\t\t\r\n\
    \t\tfor (size_type root : roots_) {\r\n\t\t\tstd::stack<std::pair<size_type, size_type>>\
    \ stk;\r\n\t\t\t\r\n\t\t\theavy_map_[root] = head_.size();\r\n\t\t\thead_.emplace_back(root);\r\
    \n\t\t\theavy_size_.emplace_back(1);\r\n\t\t\theavy_depth_.emplace_back(0);\r\n\
    \t\t\tstk.emplace(root, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\
    \tconst size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\
    \t\tif (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v != par_[u] && v != next[u]) {\r\n\t\
    \t\t\t\t\theavy_map_[v] = head_.size();\r\n\t\t\t\t\t\thead_.emplace_back(v);\r\
    \n\t\t\t\t\t\theavy_size_.emplace_back(1);\r\n\t\t\t\t\t\theavy_depth_.emplace_back(heavy_depth_[heavy_map_[u]]\
    \ + 1);\r\n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    \tif (i == 0) {\r\n\t\t\t\t\tin_[u] = euler_map_.size();\r\n\t\t\t\t\teuler_map_.emplace_back(u);\r\
    \n\t\t\t\t\tconst size_type v = next[u];\r\n\t\t\t\t\tif (v != u) {\r\n\t\t\t\t\
    \t\theavy_map_[v] = heavy_map_[u];\r\n\t\t\t\t\t\t++heavy_size_[heavy_map_[u]];\r\
    \n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (i\
    \ == g[u].size()) out_[u] = euler_map_.size();\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\
    \t\tif (!use_lca) return;\r\n\t\tsize_type max_depth = *std::max_element(begin(heavy_depth_),\
    \ end(heavy_depth_));\r\n\t\tsize_type lglg_n = 0;\r\n\t\twhile ((1 << lglg_n)\
    \ < max_depth) ++lglg_n;\r\n\t\t\r\n\t\tpar_dblng_.assign(lglg_n + 1, std::vector<size_type>(af_size()));\r\
    \n\t\tfor (size_type i = 0; i < af_size(); ++i) par_dblng_[0][i] = par_[head_[i]];\r\
    \n\t\tfor (size_type i = 0; i < lglg_n; ++i) {\r\n\t\t\tfor (size_type j = 0;\
    \ j < af_size(); ++j) {\r\n\t\t\t\tpar_dblng_[i + 1][j] = par_dblng_[i][heavy_map_[par_dblng_[i][j]]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type bf_size() const noexcept { return\
    \ bf_n; }\r\n\tsize_type af_size() const noexcept { return head_.size(); }\r\n\
    \t\r\n\tsize_type par(size_type v) const { assert(v < bf_size()); return par_[v];\
    \ }\r\n\tsize_type sub_size(size_type v) const { assert(v < bf_size()); return\
    \ sub_size_[v]; }\r\n\tsize_type depth(size_type v) const { assert(v < bf_size());\
    \ return depth_[v]; }\r\n\t\r\n\tsize_type tree_id(size_type v) const { assert(v\
    \ < bf_size()); return tree_id_[v]; }\r\n\tsize_type tree_cnt() const noexcept\
    \ { return roots_.size(); }\r\n\tconst std::vector<size_type> & trees() const\
    \ noexcept { return roots_; }\r\n\t\r\n\tsize_type heavy_map(size_type v) const\
    \ { assert(v < bf_size()); return heavy_map_[v]; }\r\n\tsize_type head(size_type\
    \ k) const { assert(k < af_size()); return head_[k]; }\r\n\tsize_type heavy_size(size_type\
    \ k) const { assert(k < af_size()); return heavy_size_[k]; }\r\n\tsize_type heavy_depth(size_type\
    \ k) const { assert(k < af_size()); return heavy_depth_[k]; }\r\n\t\r\n\tsize_type\
    \ in(size_type v) const { assert(v < bf_size()); return in_[v]; }\r\n\tsize_type\
    \ out(size_type v) const { assert(v < bf_size()); return out_[v]; }\r\n\tsize_type\
    \ euler_map(size_type k) const { assert(k < bf_size()); return euler_map_[k];\
    \ }\r\n\t\r\n\tconst std::vector<std::vector<size_type>> & par_dblng() const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\treturn par_dblng_;\r\n\t}\r\n\t\r\n\t\
    std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\tassert(x < bf_size());\r\n\t\tassert(y\
    \ < bf_size());\r\n\t\tassert(tree_id_[x] == tree_id_[y]);\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return {x, y};\r\n\t\t\r\n\t\tbool isswap = heavy_depth_[heavy_map_[x]]\
    \ < heavy_depth_[heavy_map_[y]];\r\n\t\tif (isswap) std::swap(x, y);\r\n\t\t\r\
    \n\t\tconst size_type diff = heavy_depth_[heavy_map_[x]] - heavy_depth_[heavy_map_[y]];\r\
    \n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tif (diff >>\
    \ (i - 1) & 1) x = par_dblng_[i - 1][heavy_map_[x]];\r\n\t\t}\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\
    \n\t\t\r\n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tconst\
    \ size_type p1 = par_dblng_[i - 1][heavy_map_[x]], p2 = par_dblng_[i - 1][heavy_map_[y]];\r\
    \n\t\t\tif (heavy_map_[p1] != heavy_map_[p2]) x = p1, y = p2;\r\n\t\t}\r\n\t\t\
    x = par_dblng_[0][heavy_map_[x]];\r\n\t\ty = par_dblng_[0][heavy_map_[y]];\r\n\
    \t\treturn isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\n\t}\r\n\t\r\
    \n\tsize_type get_lca(size_type x, size_type y) {\r\n\t\tassert(!par_dblng_.empty());\r\
    \n\t\tassert(x < bf_size());\r\n\t\tassert(y < bf_size());\r\n\t\tstd::pair<size_type,\
    \ size_type> res = get_lca_path(x, y);\r\n\t\treturn in_[res.first] < in_[res.second]\
    \ ? res.first : res.second;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2020-09-18 18:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/HeavyLightDecomposition.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
documentation_of: GraphTheory/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/GraphTheory/HeavyLightDecomposition.hpp
- /library/GraphTheory/HeavyLightDecomposition.hpp.html
title: GraphTheory/HeavyLightDecomposition.hpp
---
