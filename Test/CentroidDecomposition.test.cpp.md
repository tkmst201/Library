---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/CentroidDecomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"Test/CentroidDecomposition.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\r\n\r\n#line 1 \"GraphTheory/CentroidDecomposition.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp\r\
    \n */\r\nstruct CentroidDecomposition {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<bool> done_;\r\n\tstd::vector<int>\
    \ sz;\r\n\t\r\npublic:\r\n\texplicit CentroidDecomposition(const Graph & g) :\
    \ n(g.size()), done_(size(), false), sz(size(), 0) {\r\n\t\tfor (int i = 0; i\
    \ < size(); ++i) for (int j : g[i]) assert(0 <= j && j < size());\r\n\t}\r\n\t\
    \r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool exist(int\
    \ u) const noexcept {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn !done_[u];\r\
    \n\t}\r\n\t\r\n\tstd::vector<int> centroids(const Graph & g, int root) {\r\n\t\
    \tassert(0 <= root && root < size());\r\n\t\tassert(exist(root));\r\n\t\tauto\
    \ dfs = [&](auto self, int u, int p) -> void {\r\n\t\t\tsz[u] = 1;\r\n\t\t\tfor\
    \ (auto v : g[u]) if (v != p && exist(v)) self(self, v, u), sz[u] += sz[v];\r\n\
    \t\t};\r\n\t\tdfs(dfs, root, -1);\r\n\t\tint u = root, p = -1;\r\n\t\tstd::vector<int>\
    \ res;\r\n\t\twhile (true) {\r\n\t\t\tbool update = false;\r\n\t\t\tfor (auto\
    \ v : g[u]) {\r\n\t\t\t\tif (v == p || !exist(v)) continue;\r\n\t\t\t\tif (sz[v]\
    \ * 2 > sz[root]) { p = u; u = v; update = true; break; }\r\n\t\t\t\tif (sz[v]\
    \ * 2 == sz[root]) res.emplace_back(v);\r\n\t\t\t}\r\n\t\t\tif (update) continue;\r\
    \n\t\t\tres.emplace_back(u);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tvoid done(int v) noexcept {\r\n\t\tassert(0 <= v && v < size());\r\
    \n\t\tdone_[v] = true;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tstd::fill(begin(done_),\
    \ end(done_), false);\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/CentroidDecomposition.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 8 \"Test/CentroidDecomposition.test.cpp\"\n\r\
    \nstd::pair<long long, std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<int,\
    \ int>>> & wg) {\r\n\tassert(!wg.empty());\r\n\tusing CD = CentroidDecomposition;\r\
    \n\tusing ll = long long;\r\n\tconst int n = wg.size();\r\n\tCD::Graph g(n);\r\
    \n\tfor (int i = 0; i < n; ++i) {\r\n\t\tg[i].reserve(wg[i].size());\r\n\t\tfor\
    \ (const auto & e : wg[i]) {\r\n\t\t\tconst int v = e.first;\r\n\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\tg[i].emplace_back(v);\r\n\t\t}\r\n\t}\r\n\tCD cd(g);\r\
    \n\tstruct Data { ll dist; int u, v; };\r\n\tauto dfs = [&](auto self, int centroid)\
    \ -> Data {\r\n\t\tcd.done(centroid);\r\n\t\tData res{0, centroid, centroid};\r\
    \n\t\tstd::pair<ll, int> top[2];\r\n\t\tstd::fill(top, top + 2, std::make_pair(0,\
    \ centroid));\r\n\t\tfor (const auto [v, d] : wg[centroid]) {\r\n\t\t\tif (!cd.exist(v))\
    \ continue;\r\n\t\t\tauto dfs2 = [&](auto self, int u, int p) -> std::pair<ll,\
    \ int> {\r\n\t\t\t\tstd::pair<ll, int> res{0, u};\r\n\t\t\t\tfor (const auto &\
    \ e : wg[u]) { // auto [v, d] internal compiler error\r\n\t\t\t\t\tconst int v\
    \ = e.first;\r\n\t\t\t\t\tconst ll d = e.second;\r\n\t\t\t\t\tif (v == p || !cd.exist(v))\
    \ continue;\r\n\t\t\t\t\tauto [mxd, mxu] = self(self, v, u);\r\n\t\t\t\t\tif (res.first\
    \ < mxd + d) res = {mxd + d, mxu};\r\n\t\t\t\t}\r\n\t\t\t\treturn res;\r\n\t\t\
    \t};\r\n\t\t\tauto pred = dfs2(dfs2, v, -1);\r\n\t\t\tpred.first += d;\r\n\t\t\
    \tif (top[0] < pred) top[1] = std::move(top[0]), top[0] = pred;\r\n\t\t\telse\
    \ if (top[1] < pred) top[1] = std::move(pred);\r\n\t\t\tauto pred2 = self(self,\
    \ cd.centroids(g, v)[0]);\r\n\t\t\tif (res.dist < pred2.dist) res = pred2;\r\n\
    \t\t}\r\n\t\tif (top[0].first + top[1].first > res.dist) return {top[0].first\
    \ + top[1].first, top[0].second, top[1].second};\r\n\t\treturn res;\r\n\t};\r\n\
    \tData dat = dfs(dfs, cd.centroids(g, 0)[0]);\r\n\tstd::vector<int> par(n, -1);\r\
    \n\tauto dfs3 = [&](auto self, int u) -> void {\r\n\t\tfor (auto v : g[u]) if\
    \ (v != par[u]) par[v] = u, self(self, v);\r\n\t};\r\n\tdfs3(dfs3, dat.u);\r\n\
    \tstd::vector<int> path;\r\n\tpath.emplace_back(dat.v);\r\n\twhile (par[path.back()]\
    \ != -1) path.emplace_back(par[path.back()]);\r\n\treturn {dat.dist, path};\r\n\
    }\r\n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\t\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> g(N);\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tint a, b, c;\r\n\t\
    \tscanf(\"%d %d %d\", &a, &b, &c);\r\n\t\tg[a].emplace_back(b, c);\r\n\t\tg[b].emplace_back(a,\
    \ c);\r\n\t}\r\n\t\r\n\tauto [ans, path] = tree_diameter(g);\r\n\tprintf(\"%lld\
    \ %d\\n\", ans, (int)path.size());\r\n\tfor (int i = 0; i < path.size(); ++i)\
    \ printf(\"%d%c\", path[i], \" \\n\"[i + 1 == path.size()]);\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\r\n\r\n\
    #include \"GraphTheory/CentroidDecomposition.hpp\"\r\n\r\n#include <cstdio>\r\n\
    #include <vector>\r\n#include <cassert>\r\n\r\nstd::pair<long long, std::vector<int>>\
    \ tree_diameter(const std::vector<std::vector<std::pair<int, int>>> & wg) {\r\n\
    \tassert(!wg.empty());\r\n\tusing CD = CentroidDecomposition;\r\n\tusing ll =\
    \ long long;\r\n\tconst int n = wg.size();\r\n\tCD::Graph g(n);\r\n\tfor (int\
    \ i = 0; i < n; ++i) {\r\n\t\tg[i].reserve(wg[i].size());\r\n\t\tfor (const auto\
    \ & e : wg[i]) {\r\n\t\t\tconst int v = e.first;\r\n\t\t\tassert(0 <= v && v <\
    \ n);\r\n\t\t\tg[i].emplace_back(v);\r\n\t\t}\r\n\t}\r\n\tCD cd(g);\r\n\tstruct\
    \ Data { ll dist; int u, v; };\r\n\tauto dfs = [&](auto self, int centroid) ->\
    \ Data {\r\n\t\tcd.done(centroid);\r\n\t\tData res{0, centroid, centroid};\r\n\
    \t\tstd::pair<ll, int> top[2];\r\n\t\tstd::fill(top, top + 2, std::make_pair(0,\
    \ centroid));\r\n\t\tfor (const auto [v, d] : wg[centroid]) {\r\n\t\t\tif (!cd.exist(v))\
    \ continue;\r\n\t\t\tauto dfs2 = [&](auto self, int u, int p) -> std::pair<ll,\
    \ int> {\r\n\t\t\t\tstd::pair<ll, int> res{0, u};\r\n\t\t\t\tfor (const auto &\
    \ e : wg[u]) { // auto [v, d] internal compiler error\r\n\t\t\t\t\tconst int v\
    \ = e.first;\r\n\t\t\t\t\tconst ll d = e.second;\r\n\t\t\t\t\tif (v == p || !cd.exist(v))\
    \ continue;\r\n\t\t\t\t\tauto [mxd, mxu] = self(self, v, u);\r\n\t\t\t\t\tif (res.first\
    \ < mxd + d) res = {mxd + d, mxu};\r\n\t\t\t\t}\r\n\t\t\t\treturn res;\r\n\t\t\
    \t};\r\n\t\t\tauto pred = dfs2(dfs2, v, -1);\r\n\t\t\tpred.first += d;\r\n\t\t\
    \tif (top[0] < pred) top[1] = std::move(top[0]), top[0] = pred;\r\n\t\t\telse\
    \ if (top[1] < pred) top[1] = std::move(pred);\r\n\t\t\tauto pred2 = self(self,\
    \ cd.centroids(g, v)[0]);\r\n\t\t\tif (res.dist < pred2.dist) res = pred2;\r\n\
    \t\t}\r\n\t\tif (top[0].first + top[1].first > res.dist) return {top[0].first\
    \ + top[1].first, top[0].second, top[1].second};\r\n\t\treturn res;\r\n\t};\r\n\
    \tData dat = dfs(dfs, cd.centroids(g, 0)[0]);\r\n\tstd::vector<int> par(n, -1);\r\
    \n\tauto dfs3 = [&](auto self, int u) -> void {\r\n\t\tfor (auto v : g[u]) if\
    \ (v != par[u]) par[v] = u, self(self, v);\r\n\t};\r\n\tdfs3(dfs3, dat.u);\r\n\
    \tstd::vector<int> path;\r\n\tpath.emplace_back(dat.v);\r\n\twhile (par[path.back()]\
    \ != -1) path.emplace_back(par[path.back()]);\r\n\treturn {dat.dist, path};\r\n\
    }\r\n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\t\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> g(N);\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tint a, b, c;\r\n\t\
    \tscanf(\"%d %d %d\", &a, &b, &c);\r\n\t\tg[a].emplace_back(b, c);\r\n\t\tg[b].emplace_back(a,\
    \ c);\r\n\t}\r\n\t\r\n\tauto [ans, path] = tree_diameter(g);\r\n\tprintf(\"%lld\
    \ %d\\n\", ans, (int)path.size());\r\n\tfor (int i = 0; i < path.size(); ++i)\
    \ printf(\"%d%c\", path[i], \" \\n\"[i + 1 == path.size()]);\r\n}"
  dependsOn:
  - GraphTheory/CentroidDecomposition.hpp
  isVerificationFile: true
  path: Test/CentroidDecomposition.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 15:29:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/CentroidDecomposition.test.cpp
layout: document
redirect_from:
- /verify/Test/CentroidDecomposition.test.cpp
- /verify/Test/CentroidDecomposition.test.cpp.html
title: Test/CentroidDecomposition.test.cpp
---
