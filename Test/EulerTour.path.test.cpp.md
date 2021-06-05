---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: GraphTheory/EulerTour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
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
    PROBLEM: https://yukicoder.me/problems/no/1094
    links:
    - https://yukicoder.me/problems/no/1094
  bundledCode: "#line 1 \"Test/EulerTour.path.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1094\"\
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
    \ g_idx[k << 1 | 1];\r\n\t}\r\n};\r\n\r\n\n#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\
    \n\n\n\r\n#line 6 \"DataStructure/BinaryIndexedTree.hpp\"\n#include <functional>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), node(n + 1, id_elem) {}\r\
    \n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, const_reference x) noexcept {\r\n\t\tassert(i < size());\r\
    \n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i], x);\r\n\
    \t}\r\n\t\r\n\tvalue_type sum(size_type i) const noexcept {\r\n\t\tassert(i <=\
    \ size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ res = f(node[i], res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem,\
    \ w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\
    \t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\
    \n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"GraphTheory/LowestCommonAncestor.hpp\"\
    \n\n\n\r\n#line 7 \"GraphTheory/LowestCommonAncestor.hpp\"\n#include <cstdint>\r\
    \n#line 9 \"GraphTheory/LowestCommonAncestor.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp\r\
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
    \ < size());\r\n\t\tassert(k <= depth_[u]);\r\n\t\tassert(par[0][u] != -1);\r\n\
    \t\tfor (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];\r\n\t\treturn\
    \ u;\r\n\t}\r\n\t\r\n\tint depth(int u) const noexcept {\r\n\t\tassert(0 <= u\
    \ && u < size());\r\n\t\tassert(par[0][u] != -1);\r\n\t\treturn depth_[u];\r\n\
    \t}\r\n};\r\n\r\n\n#line 6 \"Test/EulerTour.path.test.cpp\"\n\r\n#include <cstdio>\r\
    \n#line 9 \"Test/EulerTour.path.test.cpp\"\n\r\nint main() {\r\n\tint N;\r\n\t\
    scanf(\"%d\", &N);\r\n\t\r\n\tEulerTour<true>::Graph g(N);\r\n\tstd::vector<int>\
    \ A(N - 1), B(N - 1), C(N - 1);\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\t\
    scanf(\"%d %d %d\", &A[i], &B[i], &C[i]);\r\n\t\t--A[i]; --B[i];\r\n\t\tg[A[i]].emplace_back(B[i]);\r\
    \n\t\tg[B[i]].emplace_back(A[i]);\r\n\t}\r\n\tEulerTour<true> et(g);\r\n\t\r\n\
    \tusing ll = long long;\r\n\tBinaryIndexedTree<ll> bit(et.size(), 0, [](auto x,\
    \ auto y) { return x + y; });\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tif\
    \ (et.par(A[i]) != B[i]) std::swap(A[i], B[i]);\r\n\t\tbit.add(et.in(A[i]), C[i]);\r\
    \n\t\tbit.add(et.out(A[i]), -C[i]);\r\n\t}\r\n\tLowestCommonAncestor lca(g);\r\
    \n\t\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\twhile (Q--) {\r\n\t\tint s, t;\r\
    \n\t\tscanf(\"%d %d\", &s, &t);\r\n\t\t--s; --t;\r\n\t\tconst int l = lca.find(s,\
    \ t);\r\n\t\tauto func = [&](int a) {\r\n\t\t\treturn bit.sum(et.in(a) + 1) -\
    \ bit.sum(et.in(l) + 1);\r\n\t\t};\r\n\t\tprintf(\"%lld\\n\", func(s) + func(t));\r\
    \n\t}\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1094\"\r\n\r\n#include\
    \ \"GraphTheory/EulerTour.hpp\"\r\n#include \"DataStructure/BinaryIndexedTree.hpp\"\
    \r\n#include \"GraphTheory/LowestCommonAncestor.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <utility>\r\n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\
    \n\t\r\n\tEulerTour<true>::Graph g(N);\r\n\tstd::vector<int> A(N - 1), B(N - 1),\
    \ C(N - 1);\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tscanf(\"%d %d %d\",\
    \ &A[i], &B[i], &C[i]);\r\n\t\t--A[i]; --B[i];\r\n\t\tg[A[i]].emplace_back(B[i]);\r\
    \n\t\tg[B[i]].emplace_back(A[i]);\r\n\t}\r\n\tEulerTour<true> et(g);\r\n\t\r\n\
    \tusing ll = long long;\r\n\tBinaryIndexedTree<ll> bit(et.size(), 0, [](auto x,\
    \ auto y) { return x + y; });\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tif\
    \ (et.par(A[i]) != B[i]) std::swap(A[i], B[i]);\r\n\t\tbit.add(et.in(A[i]), C[i]);\r\
    \n\t\tbit.add(et.out(A[i]), -C[i]);\r\n\t}\r\n\tLowestCommonAncestor lca(g);\r\
    \n\t\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\twhile (Q--) {\r\n\t\tint s, t;\r\
    \n\t\tscanf(\"%d %d\", &s, &t);\r\n\t\t--s; --t;\r\n\t\tconst int l = lca.find(s,\
    \ t);\r\n\t\tauto func = [&](int a) {\r\n\t\t\treturn bit.sum(et.in(a) + 1) -\
    \ bit.sum(et.in(l) + 1);\r\n\t\t};\r\n\t\tprintf(\"%lld\\n\", func(s) + func(t));\r\
    \n\t}\r\n}"
  dependsOn:
  - GraphTheory/EulerTour.hpp
  - DataStructure/BinaryIndexedTree.hpp
  - GraphTheory/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: Test/EulerTour.path.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/EulerTour.path.test.cpp
layout: document
redirect_from:
- /verify/Test/EulerTour.path.test.cpp
- /verify/Test/EulerTour.path.test.cpp.html
title: Test/EulerTour.path.test.cpp
---
