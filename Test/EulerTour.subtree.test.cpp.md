---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/EulerTour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Test/EulerTour.subtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#line 1 \"GraphTheory/EulerTour.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <stack>\r\n#include <utility>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp\r\n */\r\ntemplate<bool\
    \ EDGE>\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\n\tusing Graph\
    \ = std::vector<std::vector<int>>;\r\n\t\r\nprivate:\r\n\tint n, root;\r\n\tstd::vector<int>\
    \ in_, out_, par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const Graph & g, int\
    \ root = 0)\r\n\t\t: n(g.size()), root(root), in_(size(), -1), out_(size(), -1),\
    \ par_(n, -1), g_idx(n << 1, -1) {\r\n\t\tstd::stack<std::pair<int, int>> stk;\r\
    \n\t\tint num = 0;\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root, 0);\r\n\t\
    \twhile (!stk.empty()) {\r\n\t\t\tconst auto [u, i] = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (i < g[u].size()) {\r\n\t\t\t\tconst int v = g[u][i];\r\n\t\t\t\tassert(0\
    \ <= v && v < n);\r\n\t\t\t\tassert(v != u);\r\n\t\t\t\tstk.emplace(u, i + 1);\r\
    \n\t\t\t\tif (v == par_[u]) g_idx[u << 1 | 1] = i;\r\n\t\t\t\telse {\r\n\t\t\t\
    \t\tin_[v] = num++;\r\n\t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tg_idx[v << 1] = i;\r\
    \n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\
    \t\tout_[u] = num;\r\n\t\t\t\tif (EDGE) ++num;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\
    \r\n\tsize_type size() const noexcept {\r\n\t\treturn EDGE ? n << 1 : n;\r\n\t\
    }\r\n\t\r\n\tint par(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\
    \n\t\treturn par_[k];\r\n\t}\r\n\t\r\n\tint in(int k) const noexcept {\r\n\t\t\
    assert(0 <= k && k < n);\r\n\t\treturn in_[k];\r\n\t}\r\n\t\r\n\tint out(int k)\
    \ const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn out_[k];\r\n\t\
    }\r\n\t\r\n\tstd::pair<int, int> par_from(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < n);\r\n\t\treturn {par_[k], g_idx[k << 1]};\r\n\t}\r\n\t\r\n\tint\
    \ par_to(int k) const noexcept {\r\n\t\tassert(0 <= k && k < n);\r\n\t\treturn\
    \ g_idx[k << 1 | 1];\r\n\t}\r\n};\r\n\r\n\n#line 1 \"DataStructure/SegmentTree.hpp\"\
    \n\n\n\r\n#line 5 \"DataStructure/SegmentTree.hpp\"\n#include <algorithm>\r\n\
    #line 7 \"DataStructure/SegmentTree.hpp\"\n#include <functional>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp\r\n\
    \ */\r\ntemplate<typename T>\r\nstruct SegmentTree {\r\n\tusing value_type = T;\r\
    \n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n, n_;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\t\
    std::vector<value_type> node;\r\n\t\r\npublic:\r\n\tSegmentTree() = default;\r\
    \n\t\r\n\tSegmentTree(size_type n, const_reference id_elem, const F & f)\r\n\t\
    \t: n(n), id_elem(id_elem), f(f) {\r\n\t\tn_ = 1;\r\n\t\twhile (n_ < n) n_ <<=\
    \ 1;\r\n\t\tnode.assign(2 * n_, id_elem);\r\n\t}\r\n\t\r\n\tSegmentTree(const\
    \ std::vector<value_type> & v, const_reference id_elem, const F & f)\r\n\t\t:\
    \ SegmentTree(v.size(), id_elem, f) {\r\n\t\tfor (size_type i = 0; i < v.size();\
    \ ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_ - 1; i > 0; --i) node[i]\
    \ = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\n\tsize_type size() const\
    \ noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i, const_reference\
    \ x) noexcept {\r\n\t\tassert(i < size());\r\n\t\tnode[i += n_] = x;\r\n\t\twhile\
    \ (i > 1) {\r\n\t\t\ti >>= 1;\r\n\t\t\tnode[i] = f(node[i << 1], node[i << 1 |\
    \ 1]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tconst_reference get(size_type i) const noexcept\
    \ {\r\n\t\tassert(i < size());\r\n\t\treturn node[i + n_];\r\n\t}\r\n\t\r\n\t\
    value_type fold(size_type l, size_type r) const noexcept {\r\n\t\tassert(l <=\
    \ r);\r\n\t\tassert(r <= size());\r\n\t\tvalue_type lv = id_elem, rv = id_elem;\r\
    \n\t\tfor (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif (l & 1) lv\
    \ = f(lv, node[l++]);\r\n\t\t\tif (r & 1) rv = f(node[r - 1], rv);\r\n\t\t}\r\n\
    \t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type fold_all() const noexcept {\r\
    \n\t\treturn node[1];\r\n\t}\r\n\t\r\n\tsize_type max_right(size_type l, std::function<bool\
    \ (const_reference)> g) const noexcept {\r\n\t\tassert(l <= size());\r\n\t\tassert(g(id_elem));\r\
    \n\t\tif (l == size()) return size();\r\n\t\tl += n_;\r\n\t\tvalue_type sum =\
    \ id_elem;\r\n\t\twhile (true) {\r\n\t\t\twhile (~l & 1) l >>= 1;\r\n\t\t\tconst\
    \ value_type nex_sum = f(sum, node[l]);\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum;\
    \ ++l; }\r\n\t\t\telse break;\r\n\t\t\tif ((l & -l) == l) return size();\r\n\t\
    \t}\r\n\t\twhile (l < n_) {\r\n\t\t\tconst value_type nex_sum = f(sum, node[l\
    \ << 1]);\r\n\t\t\tl <<= 1;\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; l |= 1;\
    \ }\r\n\t\t}\r\n\t\treturn l - n_;\r\n\t}\r\n\t\r\n\tsize_type min_left(size_type\
    \ r, std::function<bool (const_reference)> g) const noexcept {\r\n\t\tassert(r\
    \ <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif (r == 0) return 0;\r\n\t\t\
    r += n_;\r\n\t\tvalue_type sum = id_elem;\r\n\t\twhile (true) {\r\n\t\t\t--r;\r\
    \n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\r\n\t\t\tconst value_type nex_sum =\
    \ f(node[r], sum);\r\n\t\t\tif (g(nex_sum)) sum = nex_sum;\r\n\t\t\telse break;\r\
    \n\t\t\tif ((r & -r) == r) return 0;\r\n\t\t}\r\n\t\twhile (r < n_) {\r\n\t\t\t\
    const value_type nex_sum = f(node[r << 1 | 1], sum);\r\n\t\t\tr <<= 1;\r\n\t\t\
    \tif (!g(nex_sum)) r |= 1;\r\n\t\t\telse sum = nex_sum;\r\n\t\t}\r\n\t\treturn\
    \ r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/EulerTour.subtree.test.cpp\"\
    \n\r\n#line 7 \"Test/EulerTour.subtree.test.cpp\"\n#include <cstdio>\r\n\r\nint\
    \ main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing ll =\
    \ long long;\r\n\tstd::vector<ll> A(N);\r\n\tEulerTour<false>::Graph g(N);\r\n\
    \tfor (int i = 0; i < N; ++i) scanf(\"%lld\", &A[i]);\r\n\tstd::vector<int> edge(N\
    \ - 1);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tscanf(\"%d\", &edge[i - 1]);\r\
    \n\t\t// par[i] = p;\r\n\t\tg[edge[i - 1]].emplace_back(i);\r\n\t}\r\n\t\r\n\t\
    EulerTour<false> et(g, 0);\r\n\t\r\n\tstd::vector<ll> tv(et.size());\r\n\tfor\
    \ (int i = 0; i < N; ++i) tv[et.in(i)] = A[i];\r\n\tSegmentTree<ll> seg(tv, 0,\
    \ [](ll x, ll y) { return x + y; });\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\
    \t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint u, x;\r\n\t\t\tscanf(\"\
    %d %d\", &u, &x);\r\n\t\t\tconst int idx = et.in(u);\r\n\t\t\tseg.set(idx, seg.get(idx)\
    \ + x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\
    \t\t\tprintf(\"%lld\\n\", seg.fold(et.in(u), et.out(u)));\r\n\t\t}\r\n\t}\r\n\t\
    \r\n\t// par* test\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tif (i == 0) {\r\n\
    \t\t\tassert(et.par(i) == -1);\r\n\t\t\tassert(et.par_from(i) == std::make_pair(-1,\
    \ -1));\r\n\t\t\tassert(et.par_to(i) == -1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\t\
    const int p = et.par(i);\r\n\t\t\tauto [p1, pfidx] = et.par_from(i);\r\n\t\t\t\
    assert(p == p1);\r\n\t\t\tassert(pfidx < g[p].size());\r\n\t\t\tassert(g[p][pfidx]\
    \ == i);\r\n\t\t\tassert(et.par_to(i) == -1);\r\n\t\t}\r\n\t}\r\n\t\r\n\tfor (int\
    \ i = 1; i < N; ++i) g[i].emplace_back(edge[i - 1]);\r\n\tet = EulerTour<false>(g);\r\
    \n\tfor (int i = 0; i < N; ++i) {\r\n\t\tif (i == 0) {\r\n\t\t\tassert(et.par(i)\
    \ == -1);\r\n\t\t\tassert(et.par_from(i) == std::make_pair(-1, -1));\r\n\t\t\t\
    assert(et.par_to(i) == -1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tconst int p = et.par(i);\r\
    \n\t\t\tauto [p1, pfidx] = et.par_from(i);\r\n\t\t\tassert(p == p1);\r\n\t\t\t\
    assert(pfidx < g[p].size());\r\n\t\t\tassert(g[p][pfidx] == i);\r\n\t\t\tauto\
    \ ptidx = et.par_to(i);\r\n\t\t\tassert(ptidx < g[i].size());\r\n\t\t\tassert(g[i][ptidx]\
    \ == p);\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#include \"GraphTheory/EulerTour.hpp\"\r\n#include \"DataStructure/SegmentTree.hpp\"\
    \r\n\r\n#include <vector>\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing ll = long long;\r\n\tstd::vector<ll>\
    \ A(N);\r\n\tEulerTour<false>::Graph g(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"\
    %lld\", &A[i]);\r\n\tstd::vector<int> edge(N - 1);\r\n\tfor (int i = 1; i < N;\
    \ ++i) {\r\n\t\tscanf(\"%d\", &edge[i - 1]);\r\n\t\t// par[i] = p;\r\n\t\tg[edge[i\
    \ - 1]].emplace_back(i);\r\n\t}\r\n\t\r\n\tEulerTour<false> et(g, 0);\r\n\t\r\n\
    \tstd::vector<ll> tv(et.size());\r\n\tfor (int i = 0; i < N; ++i) tv[et.in(i)]\
    \ = A[i];\r\n\tSegmentTree<ll> seg(tv, 0, [](ll x, ll y) { return x + y; });\r\
    \n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\tif (q ==\
    \ 0) {\r\n\t\t\tint u, x;\r\n\t\t\tscanf(\"%d %d\", &u, &x);\r\n\t\t\tconst int\
    \ idx = et.in(u);\r\n\t\t\tseg.set(idx, seg.get(idx) + x);\r\n\t\t}\r\n\t\telse\
    \ {\r\n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\t\t\tprintf(\"%lld\\n\", seg.fold(et.in(u),\
    \ et.out(u)));\r\n\t\t}\r\n\t}\r\n\t\r\n\t// par* test\r\n\tfor (int i = 0; i\
    \ < N; ++i) {\r\n\t\tif (i == 0) {\r\n\t\t\tassert(et.par(i) == -1);\r\n\t\t\t\
    assert(et.par_from(i) == std::make_pair(-1, -1));\r\n\t\t\tassert(et.par_to(i)\
    \ == -1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tconst int p = et.par(i);\r\n\t\t\tauto\
    \ [p1, pfidx] = et.par_from(i);\r\n\t\t\tassert(p == p1);\r\n\t\t\tassert(pfidx\
    \ < g[p].size());\r\n\t\t\tassert(g[p][pfidx] == i);\r\n\t\t\tassert(et.par_to(i)\
    \ == -1);\r\n\t\t}\r\n\t}\r\n\t\r\n\tfor (int i = 1; i < N; ++i) g[i].emplace_back(edge[i\
    \ - 1]);\r\n\tet = EulerTour<false>(g);\r\n\tfor (int i = 0; i < N; ++i) {\r\n\
    \t\tif (i == 0) {\r\n\t\t\tassert(et.par(i) == -1);\r\n\t\t\tassert(et.par_from(i)\
    \ == std::make_pair(-1, -1));\r\n\t\t\tassert(et.par_to(i) == -1);\r\n\t\t}\r\n\
    \t\telse {\r\n\t\t\tconst int p = et.par(i);\r\n\t\t\tauto [p1, pfidx] = et.par_from(i);\r\
    \n\t\t\tassert(p == p1);\r\n\t\t\tassert(pfidx < g[p].size());\r\n\t\t\tassert(g[p][pfidx]\
    \ == i);\r\n\t\t\tauto ptidx = et.par_to(i);\r\n\t\t\tassert(ptidx < g[i].size());\r\
    \n\t\t\tassert(g[i][ptidx] == p);\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/EulerTour.hpp
  - DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: Test/EulerTour.subtree.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/EulerTour.subtree.test.cpp
layout: document
redirect_from:
- /verify/Test/EulerTour.subtree.test.cpp
- /verify/Test/EulerTour.subtree.test.cpp.html
title: Test/EulerTour.subtree.test.cpp
---
