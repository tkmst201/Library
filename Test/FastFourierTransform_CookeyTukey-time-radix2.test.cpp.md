---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/CentroidDecomposition.hpp
    title: GraphTheory/CentroidDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp
    title: Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#line 1 \"GraphTheory/CentroidDecomposition.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n\r\n/*\r\nlast-updated: 2020/09/03\r\n\r\n\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u6E21\u3057\u305F g \u306F\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\r\nused \u30D5\u30E9\u30B0\u306E\u5909\u66F4\
    \u306F set \u3092\u901A\u3057\u3066\u884C\u3046\r\n\r\n# \u4ED5\u69D8\r\n\r\n\
    CentroidDecomposition(const Graph & g) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ \u0398(n)\r\n\t\u91CD\u5FC3\u5206\u89E3\u3092\u884C\u3046\u30B0\u30E9\u30D5\
    \ g \u3067\u521D\u671F\u5316\u3059\u308B\r\n\r\nbool operator [](size_type v)\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\tused \u30D5\u30E9\
    \u30B0\u306E\u5024\u3092\u8FD4\u3059\r\n\r\nbool operator at(size_type v) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\tused \u30D5\u30E9\u30B0\
    \u306E\u5024\u3092\u8FD4\u3059\r\n\tassert \u30C1\u30A7\u30C3\u30AF\u3042\u308A\
    \r\n\r\nstd::vector<size_type> get_centroid(size_type root) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(k)\r\n\tused \u30D5\u30E9\u30B0\u304C\u7ACB\u3063\u3066\
    \u3044\u308B\u9802\u70B9\u3092\u53D6\u308A\u9664\u3044\u305F\u68EE\u4E0A\u3067\
    \u9802\u70B9 root \u304C\u5C5E\u3059\u308B\u6728(\u9802\u70B9\u6570\u3092 k \u3068\
    \u3059\u308B) \u306E\u91CD\u5FC3\u3092\u6C42\u3081\u308B\r\n\r\nvoid set(size_type\
    \ v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 v \u306E\
    \ used \u30D5\u30E9\u30B0\u3092 true \u306B\u5909\u66F4\u3059\u308B\r\n\r\nvoid\
    \ clear() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\tused \u30D5\u30E9\
    \u30B0\u3092\u30EA\u30BB\u30C3\u30C8\u3059\u308B\r\n\r\n# \u4F7F\u7528\u4F8B\r\
    \nsize_type get_centroid_decomposition_tree(const Graph & g, Graph & cdg) :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n log n)\r\n\t\u91CD\u5FC3\u5206\u89E3\
    \u3092\u518D\u5E30\u7684\u306B\u884C\u3044\u3001\u5404\u90E8\u5206\u6728\u306E\
    \u91CD\u5FC3\u306B\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\u3092 cdg \u306B\
    \u683C\u7D0D\u3059\u308B\r\n\t\u6839\u306E index(g \u306E\u91CD\u5FC3\u306E 1\
    \ \u3064) \u3092\u8FD4\u3059\r\n\t\r\n\tverified(2020/09/02) : https://codeforces.com/contest/321/submission/91621846\r\
    \n\r\nlong long get_tree_diameter(\r\n\t\tconst std::vector<std::vector<std::pair<size_type,\
    \ int>>> & wg,\r\n\t\tstd::vector<size_type> & path\r\n\t)\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(n log n)\r\n\t\u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u4E0A\
    \u3067\u6700\u9060\u9802\u70B9\u5BFE\u3092\u6C42\u3081\u308B\r\n\t\u6700\u9060\
    \u9802\u70B9\u5BFE (u, v) \u306E\u9577\u3055\u3092\u8FD4\u3057\u3001\u305D\u306E\
    \u30D1\u30B9\u3092 path \u306B\u683C\u7D0D\u3059\u308B\r\n\t\u5B9A\u6570\u500D\
    \u304C\u3059\u3054\u304F\u91CD\u3044(\r\n\t\t\u63D0\u51FA: https://judge.yosupo.jp/submission/20914\r\
    \n\t\t\u624B\u5143\u3067\u306F line \u30B0\u30E9\u30D5\u306E\u51E6\u7406\u304C\
    \ max_random \u306B\u6BD4\u3079\u3066 4 \u500D\u7A0B\u5EA6\u9045\u3044\u304C library-checker\
    \ \u4E0A\u3067\u306F\u306F\u3084\u304B\u3063\u305F(\u306A\u305C?)\r\n\t)\u3002\
    \r\n\t\r\n\t\u8CA0\u8FBA\u3067\u3082\u6B63\u3057\u304F\u52D5\u4F5C\u3057\u305D\
    \u3046(unverified)\r\n\t\u5168\u65B9\u4F4D\u6728 dp \u3092\u7528\u3044\u308C\u3070\
    \ \u0398(n) \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\u305D\u3046\
    \r\n\t\u91CD\u307F\u304C\u6B63\u306E\u5834\u5408\u306F double-sweap \u3067 \u0398\
    (n) \u3067\u6C42\u307E\u308B\r\n\t\u3053\u308C\u306F verify \u7528\r\n\r\nstd::vector<long\
    \ long> get_dist_frequency_table(const Graph & g) :\r\n\t\u8981\u6C42\u30E9\u30A4\
    \u30D6\u30E9\u30EA: FastFourierTransform(multiply \u3092\u5B9F\u88C5\u6E08)\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n log^2 n)\r\n\tn \u9802\u70B9\u306E\u6728\
    \u306B\u304A\u3044\u3066\u6B21\u306E\u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\
    \u3059\u308B\r\n\t\ttable[i] = u \\leq v \u3067 dist(u, v) = i \u3068\u306A\u308B\
    \u3088\u3046\u306A (u, v) \u306E\u500B\u6570\r\n\t\r\n\t# \u89E3\u8AAC\r\n\t\t\
    u < v \u3067 (u, v), (v, u) \u3068\u91CD\u8907\u3057\u3066\u6570\u3048\u3042\u3052\
    \u3066\u6700\u5F8C\u306B 2 \u3067\u5272\u308B\r\n\t\t\r\n\t\tcentroid \u3092\u901A\
    \u308B\u30D1\u30B9\u3092\u8003\u3048\u308B\u3002\r\n\t\t\u90E8\u5206\u6728\u3054\
    \u3068\u306B centroid \u304B\u3089\u306E\u8DDD\u96E2\u3092 d \u3068\u3057\u3066\
    \ table[d]++ \u3057\u305F table \u3092\u7528\u610F\r\n\t\t\u5168\u3066\u306E table\
    \ \u306E\u548C\u3092\u53D6\u308B\r\n\t\t\u3053\u306E table \u3092 2 \u4E57\u3059\
    \u308B\u3068 (\u7570\u306A\u308B\u90E8\u5206\u6728\u3092\u7D50\u5408\u3057\u305F\
    \ table) + (\u540C\u4E00\u90E8\u5206\u6728\u3092\u7D50\u5408\u3057\u305F table)\
    \ \u304C\u5F97\u3089\u308C\u308B\r\n\t\t\u3053\u306E\u3068\u304D\u3001\u4E21\u65B9\
    \u306E table \u3067 [0] = 1 \u3068\u3057\u3066\u304A\u304F\u3068 centroid - *\
    \ \u306E\u30D1\u30B9\u3092\u6570\u3048\u308B\u3053\u3068\u304C\u53EF\u80FD\r\n\
    \t\t((centroid, *) \u304C\u91CD\u8907\u3057\u3066\u3061\u3087\u3046\u3069 2 \u56DE\
    \u6570\u3048\u4E0A\u3052\u3089\u308C\u308B)\r\n\t\t\r\n\t\t(\u540C\u4E00\u90E8\
    \u5206\u6728\u3092\u7D50\u5408\u3057\u305F table) \u3067\u306F (centroid, *) \u306F\
    \u6B63\u3057\u3044\u304C (*, *) \u306E\u72B6\u614B\u306F\u6D88\u3059\u5FC5\u8981\
    \u304C\u3042\u308B\u306E\u3067\r\n\t\t[0] = 0 \u3068\u3057\u3066\u90E8\u5206\u6728\
    \u306E\u30C6\u30FC\u30D6\u30EB\u3092 2 \u4E57\u3057\u3066\u5F15\u304F\r\n\t\t\r\
    \n\t\t1 \u3064\u306E\u968E\u5C64\u3067\u5168\u4F53\u3067 O(n log n) \u306E\u7573\
    \u307F\u8FBC\u307F\r\n\t\t\u5168 O(log n) \u5C64\u306A\u306E\u3067\u5168\u4F53\
    \u3067 O(n log^2 n)\r\n\r\n# \u53C2\u8003\r\nhttps://ferin-tech.hatenablog.com/entry/2020/03/06/162311,\
    \ 2020/09/02\r\nhttps://qiita.com/drken/items/4b4c3f1824339b090202, 2020/09/02\r\
    \n*/\r\n\r\nclass CentroidDecomposition {\r\npublic:\r\n\tusing size_type = std::size_t;\r\
    \n\tusing Graph = std::vector<std::vector<size_type>>;\r\n\t\r\nprivate:\r\n\t\
    const Graph & g;\r\n\tstd::vector<bool> used;\r\n\tstd::vector<size_type> sz;\r\
    \n\t\r\npublic:\r\n\tCentroidDecomposition() = delete;\r\n\tCentroidDecomposition(const\
    \ Graph & g) : g(g) {\r\n\t\tused.resize(size(), false);\r\n\t\tsz.resize(size());\r\
    \n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn g.size();\r\n\
    \t}\r\n\t\r\n\tbool operator [](size_type v) const {\r\n\t\treturn used[v];\r\n\
    \t}\r\n\t\r\n\tbool at(size_type v) const {\r\n\t\tassert(v < size());\r\n\t\t\
    return used[v];\r\n\t}\r\n\t\r\n\tstd::vector<size_type> get_centroid(size_type\
    \ root) {\r\n\t\tassert(root < size());\r\n\t\t\r\n\t\tauto szdfs = [this](auto\
    \ &&self, size_type v, size_type par) -> size_type {\r\n\t\t\tsz[v] = 1;\r\n\t\
    \t\tfor (auto to : g[v]) {\r\n\t\t\t\tif (to == par || used[to]) continue;\r\n\
    \t\t\t\tsz[v] += self(self, to, v);\r\n\t\t\t}\r\n\t\t\treturn sz[v];\r\n\t\t\
    };\r\n\t\tszdfs(szdfs, root, size());\r\n\t\t\r\n\t\tsize_type v = root, par =\
    \ size();\r\n\t\tstd::vector<size_type> res;\r\n\t\twhile (true) {\r\n\t\t\tbool\
    \ updated = false;\r\n\t\t\tfor (auto to : g[v]) {\r\n\t\t\t\tif (to == par ||\
    \ used[to]) continue;\r\n\t\t\t\tif (sz[to] * 2 > sz[root]) {\r\n\t\t\t\t\tpar\
    \ = v;\r\n\t\t\t\t\tv = to;\r\n\t\t\t\t\tupdated = true;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t\tif (sz[to] * 2 == sz[root]) res.emplace_back(to);\r\n\t\
    \t\t}\r\n\t\t\tif (updated) continue;\r\n\t\t\tres.emplace_back(v);\r\n\t\t\t\
    break;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tvoid set(size_type v) {\r\
    \n\t\tassert(v < size());\r\n\t\tused[v] = true;\r\n\t}\r\n\t\r\n\tvoid clear()\
    \ {\r\n\t\tused.assign(size(), false);\r\n\t}\r\n};\r\n\r\n\r\n// \u304A\u307E\
    \u3051 \u305D\u306E\uFF11\r\nCentroidDecomposition::size_type get_centroid_decomposition_tree(\r\
    \n\t\tconst CentroidDecomposition::Graph & g,\r\n\t\tCentroidDecomposition::Graph\
    \ & cdg\r\n\t) {\r\n\tassert(!g.empty());\r\n\tusing CD = CentroidDecomposition;\r\
    \n\tusing size_type = CD::size_type;\r\n\tCD cd(g);\r\n\t\r\n\tcdg.assign(g.size(),\
    \ {});\r\n\t\r\n\tauto dfs = [&](auto && self, size_type centroid) -> void {\r\
    \n\t\tcd.set(centroid);\r\n\t\tfor (auto r : g[centroid]) {\r\n\t\t\tif (cd[r])\
    \ continue;\r\n\t\t\tauto nex_cent = cd.get_centroid(r);\r\n\t\t\t\r\n\t\t\tcdg[centroid].emplace_back(nex_cent[0]);\r\
    \n\t\t\t\r\n\t\t\tself(self, nex_cent[0]);\r\n\t\t}\r\n\t};\r\n\t\r\n\tsize_type\
    \ root = cd.get_centroid(0)[0];\r\n\tdfs(dfs, root);\r\n\treturn root;\r\n}\r\n\
    \r\n// \u304A\u307E\u3051 \u305D\u306E\uFF12\r\nlong long get_tree_diameter(\r\
    \n\t\tconst std::vector<std::vector<std::pair<CentroidDecomposition::size_type,\
    \ int>>> & wg,\r\n\t\tstd::vector<CentroidDecomposition::size_type> & path\r\n\
    \t) {\r\n\tusing CD = CentroidDecomposition;\r\n\tusing size_type = CD::size_type;\r\
    \n\tusing ll = long long;\r\n\t\r\n\tCD::Graph g(wg.size());\r\n\tfor (CD::size_type\
    \ i = 0; i < wg.size(); ++i) {\r\n\t\tfor (auto v : wg[i]) g[i].emplace_back(v.first);\r\
    \n\t}\r\n\tCD cd(g);\r\n\t\r\n\tstruct Data {\r\n\t\tll dist;\r\n\t\tsize_type\
    \ u, v;\r\n\t\tData(ll dist, size_type u, size_type v) : dist(dist), u(u), v(v)\
    \ {} \r\n\t\tbool operator <(const Data & rhs) const {\r\n\t\t\treturn dist <\
    \ rhs.dist;\r\n\t\t}\r\n\t};\r\n\t\r\n\tauto dfs = [&](auto && self, size_type\
    \ centroid) -> Data {\r\n\t\tcd.set(centroid);\r\n\t\tData res{0, centroid, centroid};\r\
    \n\t\t\r\n\t\tData top = res, top2 = res;\r\n\t\tfor (auto e : wg[centroid]) {\r\
    \n\t\t\tsize_type r = e.first;\r\n\t\t\tif (cd[r]) continue;\r\n\t\t\t\r\n\t\t\
    \tauto dfs2 = [&](auto && self, size_type u, size_type par, ll c) -> Data {\r\n\
    \t\t\t\tData res{c, centroid, u};\r\n\t\t\t\tfor (auto e : wg[u]) {\r\n\t\t\t\t\
    \tsize_type to = e.first;\r\n\t\t\t\t\tif (to == par || cd[to]) continue;\r\n\t\
    \t\t\t\tData nexd = self(self, to, u, c + e.second);\r\n\t\t\t\t\tif (res < nexd)\
    \ res = nexd;\r\n\t\t\t\t}\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\t\r\n\t\t\
    \tData pred = dfs2(dfs2, r, wg.size(), e.second);\r\n\t\t\tif (top < pred) { top2\
    \ = top; top = pred; }\r\n\t\t\telse if (top2 < pred) { top2 = pred; }\r\n\t\t\
    \t\r\n\t\t\tpred = self(self, cd.get_centroid(r)[0]);\r\n\t\t\tif (res < pred)\
    \ res = pred;\r\n\t\t}\r\n\t\t\r\n\t\tif (top.dist + top2.dist > res.dist) return\
    \ {top.dist + top2.dist, top.v, top2.v};\r\n\t\treturn res;\r\n\t};\r\n\t\r\n\t\
    size_type root = cd.get_centroid(0)[0];\r\n\tData dat = dfs(dfs, root);\r\n\t\r\
    \n\tstd::vector<size_type> par(g.size(), g.size());\r\n\tauto dfs3 = [&](auto\
    \ && self, size_type u) -> void {\r\n\t\tfor (auto v : g[u]) {\r\n\t\t\tif (v\
    \ == par[u]) continue;\r\n\t\t\tpar[v] = u;\r\n\t\t\tself(self, v);\r\n\t\t}\r\
    \n\t};\r\n\t\r\n\tdfs3(dfs3, dat.u);\r\n\t\r\n\tpath.emplace_back(dat.v);\r\n\t\
    while (par[path.back()] != g.size()) path.emplace_back(par[path.back()]);\r\n\t\
    return dat.dist;\r\n}\r\n\r\n// \u304A\u307E\u3051 \u305D\u306E\uFF13\r\n#include\
    \ <cmath>\r\n#include <algorithm>\r\n\r\ntemplate<class FFT>\r\nstd::vector<long\
    \ long> get_dist_frequency_table(const CentroidDecomposition::Graph & g) {\r\n\
    \tusing CD = CentroidDecomposition;\r\n\tusing value_type = long long;\r\n\tusing\
    \ size_type = CD::size_type;\r\n\tCD cd(g);\r\n\t\r\n\tsize_type n = g.size();\r\
    \n\tstd::vector<size_type> depth(n);\r\n\t\r\n\tauto dfs = [&](auto && self, size_type\
    \ centroid) -> std::vector<value_type> {\r\n\t\tcd.set(centroid);\r\n\t\t\r\n\t\
    \tbool iso = true;\r\n\t\tfor (auto r : g[centroid]) if (!cd[r]) { iso = false;\
    \ break; }\r\n\t\tif (iso) return {0};\r\n\t\t\r\n\t\tstd::vector<value_type>\
    \ res;\r\n\t\tstd::vector<value_type> sum_table;\r\n\t\tfor (auto r : g[centroid])\
    \ {\r\n\t\t\tif (cd[r]) continue;\r\n\t\t\t\r\n\t\t\tstd::vector<size_type> dvec;\r\
    \n\t\t\tauto dfs2 = [&](auto && self, size_type u, size_type par) -> size_type\
    \ {\r\n\t\t\t\tsize_type res = depth[u];\r\n\t\t\t\tdvec.emplace_back(depth[u]);\r\
    \n\t\t\t\tfor (auto v : g[u]) {\r\n\t\t\t\t\tif (v == par || cd[v]) continue;\r\
    \n\t\t\t\t\tdepth[v] = depth[u] + 1;\r\n\t\t\t\t\tsize_type pred = self(self,\
    \ v, u);\r\n\t\t\t\t\tif (res < pred) res = pred;\r\n\t\t\t\t}\r\n\t\t\t\treturn\
    \ res;\r\n\t\t\t};\r\n\t\t\t\r\n\t\t\tdepth[r] = 1;\r\n\t\t\tsize_type mx_depth\
    \ = dfs2(dfs2, r, n);\r\n\t\t\tstd::vector<value_type> table(mx_depth + 1, 0);\r\
    \n\t\t\tfor (auto i : dvec) ++table[i];\r\n\t\t\tif (sum_table.size() < mx_depth\
    \ + 1) sum_table.resize(mx_depth + 1);\r\n\t\t\tfor (size_type i = 1; i < table.size();\
    \ ++i) sum_table[i] += table[i];\r\n\t\t\t\r\n\t\t\tauto mul = FFT::multiply(table,\
    \ table);\r\n\t\t\tif (mul.size() > n) mul.resize(n);\r\n\t\t\tif (res.size()\
    \ < mul.size()) res.resize(mul.size());\r\n\t\t\tfor (size_type i = 1; i < mul.size();\
    \ ++i) res[i] -= static_cast<value_type>(std::round(mul[i]));\r\n\t\t\t\r\n\t\t\
    \ttable = self(self, cd.get_centroid(r)[0]);\r\n\t\t\tif (res.size() < table.size())\
    \ res.resize(table.size());\r\n\t\t\tfor (size_type i = 1; i < table.size(); ++i)\
    \ res[i] += table[i];\r\n\t\t}\r\n\t\t\r\n\t\tsum_table[0] = 1;\r\n\t\tauto prod\
    \ = FFT::multiply(sum_table, sum_table);\r\n\t\tif (prod.size() > n) prod.resize(n);\r\
    \n\t\tif (res.size() < prod.size()) res.resize(prod.size());\r\n\t\tfor (size_type\
    \ i = 1; i < prod.size(); ++i) res[i] += static_cast<value_type>(std::round(prod[i]));\r\
    \n\t\treturn res;\r\n\t};\r\n\t\r\n\tauto res = dfs(dfs, cd.get_centroid(0)[0]);\r\
    \n\tfor (size_type i = 1; i < res.size(); ++i) res[i] >>= 1;\r\n\tif (res.size()\
    \ < n) res.resize(n);\r\n\tres[0] = n;\r\n\treturn res;\r\n}\r\n\r\n\n#line 1\
    \ \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp\"\
    \n\n\n\r\n#line 5 \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp\"\
    \n#include <complex>\r\n#line 7 \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp\"\
    \n\r\n/*\r\nlast-updated: 2020/08/02\r\n\r\n\u57FA\u6570 2 \u6642\u9593\u9593\u5F15\
    \u304D Cooley-Tukey\r\n\r\n# \u89E3\u8AAC\r\nN \u3092 2 \u51AA\u3068\u3057\u3066\
    \ f[0], f[1], \\ldots, f[N - 1] \u304C\u65E2\u77E5\r\n\r\n\\omega_N := 1 \u306E\
    \u539F\u59CB N \u4E57\u6839\r\n\r\nF[z] := \\Sum_{k = 0}^{N - 1} f[k] z^k\r\n\
    F[\\omega_N^{-i}] = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-ki}\r\n\u3067\u5076\
    \u6570\u6B21\u6570\u3001\u5947\u6570\u6B21\u6570\u3067\u591A\u9805\u5F0F\u3092\
    \u5206\u3051\u308B\r\n\r\n0 \\leq i < N/2 \u3068\u3057\u3066\r\nF[\\omega_N^{-i}]\
    \         = \\Sum_{k = 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki} + \\Sum_{k = 0}^{N/2\
    \ - 1} f[2k + 1] \\omega_{N/2}^{-ki}\r\nF[\\omega_N^{-(i + N/2)}] = \\Sum_{k =\
    \ 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki} - \\Sum_{k = 0}^{N/2 - 1} f[2k + 1] \\\
    omega_{N/2}^{-ki}\r\n\r\n\u30D3\u30C3\u30C8\u53CD\u8EE2\u3092\u884C\u3063\u305F\
    \u72B6\u614B\u304B\u3089 N \u304C\u5C0F\u3055\u3044\u9806\u306B\u8A08\u7B97\u3092\
    \u884C\u3048\u3070 in-place \u3067\u8A08\u7B97\u53EF\u80FD\r\n\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log n)\r\n\t2 \u3064\
    \u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\u3002\r\n\r\n# \u53C2\
    \u8003\r\nhttps://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79, 2020/05/01\r\
    \nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/08/01\r\n\
    */\r\n\r\nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type = double;\r\
    \n\tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a, b;\r\n\t\ta.reserve(n),\
    \ b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i],\
    \ 0);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);\r\
    \n\t\ta.resize(n); fft(a, zeta);\r\n\t\tb.resize(n); fft(b, zeta);\r\n\t\t\r\n\
    \t\tstd::vector<complex_type> c;\r\n\t\tc.reserve(n);\r\n\t\tfor (size_type i\
    \ = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));\r\n\t\tfft(c, zeta);\r\
    \n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type>\
    \ &A, const std::vector<complex_type> &zeta) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\t\r\n\
    \t\tsize_type zi = 0;\r\n\t\tfor (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);\r\
    \n\t\t\r\n\t\tbit_reverse(A);\r\n\t\tfor (size_type n = 2; n <= N; n <<= 1, --zi)\
    \ {\r\n\t\t\tconst size_type m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N;\
    \ p += n) {\r\n\t\t\t\tfor (size_type i = p, ei = p + m; i != ei; ++i) {\r\n\t\
    \t\t\t\tconst complex_type a = A[i], b = A[i + m] * zeta[(i - p) << zi];\r\n\t\
    \t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = a - b;\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> &A)\
    \ {\r\n\t\tconst size_type N = A.size();\r\n\t\tfor (size_type i = 1, j = 0; i\
    \ < N - 1; ++i) {\r\n\t\t\tfor (size_type k = N >> 1; k > (j ^= k); k >>= 1);\r\
    \n\t\t\tif (i < j) std::swap(A[i], A[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ _zeta(size_type max_p) {\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t// zeta[j] := \\omega_{2^max_p}^j (0 \\leq j < 2^(max_p - 1))\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << max_p - 1);\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (size_type i = 0; i < max_p - 1; ++i) {\r\n\t\t\tconst value_type rad\
    \ = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);\r\
    \n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\n\t\t\tfor (size_type\
    \ j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\t\t\tzeta.emplace_back(zeta[1\
    \ << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn zeta;\r\n\t}\r\n\
    };\r\n\r\n\n#line 5 \"Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 8 \"Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp\"\
    \n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\t\r\n\tusing CD = CentroidDecomposition;\r\
    \n\tusing size_type = CD::size_type;\r\n\tCD::Graph g(N);\r\n\tfor (int i = 0;\
    \ i < N - 1; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\t\
    g[a].emplace_back(b);\r\n\t\tg[b].emplace_back(a);\r\n\t}\r\n\t\r\n\tauto table\
    \ = get_dist_frequency_table<FastFourierTransform>(g);\r\n\tfor (size_type i =\
    \ 1; i < N; ++i) printf(\"%lld%c\", table[i], \" \\n\"[i + 1 == N]);\r\n\treturn\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include \"GraphTheory/CentroidDecomposition.hpp\"\r\n#include \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N;\r\
    \n\tscanf(\"%d\", &N);\r\n\t\r\n\tusing CD = CentroidDecomposition;\r\n\tusing\
    \ size_type = CD::size_type;\r\n\tCD::Graph g(N);\r\n\tfor (int i = 0; i < N -\
    \ 1; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tg[a].emplace_back(b);\r\
    \n\t\tg[b].emplace_back(a);\r\n\t}\r\n\t\r\n\tauto table = get_dist_frequency_table<FastFourierTransform>(g);\r\
    \n\tfor (size_type i = 1; i < N; ++i) printf(\"%lld%c\", table[i], \" \\n\"[i\
    \ + 1 == N]);\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/CentroidDecomposition.hpp
  - Mathematics/Convolution/FastFourierTransform_CookeyTukey-time-radix2.hpp
  isVerificationFile: true
  path: Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 15:23:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp
layout: document
redirect_from:
- /verify/Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp
- /verify/Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp.html
title: Test/FastFourierTransform_CookeyTukey-time-radix2.test.cpp
---
