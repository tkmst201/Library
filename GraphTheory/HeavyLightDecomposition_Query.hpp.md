---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    document_title: https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp
  bundledCode: "#line 1 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\n\n\n\r\n\
    #line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp\r\n\
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
    \ r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"GraphTheory/HeavyLightDecomposition.hpp\"\
    \n\n\n\r\n#line 6 \"GraphTheory/HeavyLightDecomposition.hpp\"\n#include <stack>\r\
    \n#include <utility>\r\n#line 9 \"GraphTheory/HeavyLightDecomposition.hpp\"\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp\r\
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
    \ y);\r\n\t\treturn in_[a] < in_[b] ? a : b;\r\n\t}\r\n};\r\n\r\n\n#line 6 \"\
    GraphTheory/HeavyLightDecomposition_Query.hpp\"\n\r\n#line 11 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct HeavyLightDecomposition_Query {\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ seg_type = SegmentTree<value_type>;\r\n\tusing hld_type = HeavyLightDecomposition;\r\
    \n\tusing size_type = std::size_t;\r\n\tusing Graph = typename hld_type::Graph;\r\
    \n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\n\
    \t\r\nprivate:\r\n\tbool VERTEX;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\thld_type\
    \ hld;\r\n\tseg_type seg, rseg;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, bool VERTEX, const value_type & id_elem, const F & f)\r\n\t\t: HeavyLightDecomposition_Query(g,\
    \ VERTEX, -1, id_elem, f) {}\r\n\t\r\n\tHeavyLightDecomposition_Query(const Graph\
    \ & g, bool VERTEX, int root, const value_type & id_elem, const F & f)\r\n\t\t\
    : VERTEX(VERTEX), id_elem(id_elem), f(f), hld(g, root, false) {\r\n\t\tseg = seg_type{static_cast<size_type>(hld.size()),\
    \ id_elem, f};\r\n\t\trseg = seg_type{static_cast<size_type>(hld.size()), id_elem,\
    \ f};\r\n\t}\r\n\t\r\n\ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\
    \n\t\t: HeavyLightDecomposition_Query(g, -1, v, id_elem, f) {}\r\n\t\r\n\ttemplate<typename\
    \ U>\r\n\tHeavyLightDecomposition_Query(const Graph & g, int root, const std::vector<U>\
    \ & v, const value_type & id_elem, const F & f)\r\n\t\t: VERTEX(true), id_elem(id_elem),\
    \ f(f), hld(g, root, false) {\r\n\t\tassert(hld.size() == v.size());\r\n\t\tstd::vector<value_type>\
    \ init(hld.size());\r\n\t\tfor (int i = 0; i < hld.size(); ++i) init[hld.in(i)]\
    \ = v[i];\r\n\t\tseg = seg_type{init, id_elem, f};\r\n\t\tfor (int i = 0; i <\
    \ hld.heavy_size(); ++i) {\r\n\t\t\tconst int offset = hld.in(hld.head(i));\r\n\
    \t\t\tstd::reverse(begin(init) + offset, begin(init) + offset + hld.heavy_size(i));\r\
    \n\t\t}\r\n\t\trseg = seg_type{init, id_elem, f};\r\n\t}\r\n\t\r\n\tconst hld_type\
    \ & get_hld() const noexcept {\r\n\t\treturn get_hld;\r\n\t}\r\n\t\r\n\tvoid set(int\
    \ v, const_reference x) noexcept {\r\n\t\tassert(VERTEX);\r\n\t\tassert(0 <= v\
    \ && v < hld.size());\r\n\t\tset_(v, x);\r\n\t}\r\n\t\r\n\tvalue_type get(int\
    \ v) const noexcept {\r\n\t\tassert(VERTEX);\r\n\t\tassert(0 <= v && v < hld.size());\r\
    \n\t\treturn get_(v);\r\n\t}\r\n\t\r\n\tvoid set(int u, int v, const_reference\
    \ x) noexcept {\r\n\t\tassert(!VERTEX);\r\n\t\tassert(0 <= u && u < hld.size());\r\
    \n\t\tassert(0 <= v && v < hld.size());\r\n\t\tassert(hld.par(u) == v || hld.par(v)\
    \ == u);\r\n\t\tset_(hld.par(u) == v ? u : v, x);\r\n\t}\r\n\t\r\n\tvalue_type\
    \ get(int u, int v) const noexcept {\r\n\t\tassert(!VERTEX);\r\n\t\tassert(0 <=\
    \ u && u < hld.size());\r\n\t\tassert(0 <= v && v < hld.size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\treturn get_(hld.par(u) == v ? u : v);\r\n\t\
    }\r\n\t\r\nprivate:\r\n\tvoid set_(int v, const_reference x) noexcept {\r\n\t\t\
    seg.set(hld.in(v), x);\r\n\t\trseg.set(reverse_idx(v), x);\r\n\t}\r\n\t\r\n\t\
    value_type get_(int v) const noexcept {\r\n\t\treturn seg.get(hld.in(v));\r\n\t\
    }\r\n\t\r\n\tint reverse_idx(int v) const noexcept {\r\n\t\tconst int id = hld.heavy(v);\r\
    \n\t\treturn (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;\r\
    \n\t}\r\n\t\r\npublic:\r\n\tvalue_type fold(int u, int v) const noexcept {\r\n\
    \t\tassert(0 <= u && u < hld.size());\r\n\t\tassert(0 <= v && v < hld.size());\r\
    \n\t\tassert(hld.tree_id(u) == hld.tree_id(v));\r\n\t\tvalue_type lv = id_elem,\
    \ rv = id_elem;\r\n\t\twhile (hld.heavy(u) != hld.heavy(v)) {\r\n\t\t\tif (hld.heavy_depth(hld.heavy(u))\
    \ >= hld.heavy_depth(hld.heavy(v))) {\r\n\t\t\t\tconst int head = hld.head(hld.heavy(u));\r\
    \n\t\t\t\tlv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));\r\n\t\t\
    \t\tu = hld.par(head);\r\n\t\t\t}\r\n\t\t\tif (hld.heavy(u) == hld.heavy(v)) break;\r\
    \n\t\t\tif (hld.heavy_depth(hld.heavy(u)) <= hld.heavy_depth(hld.heavy(v))) {\r\
    \n\t\t\t\tconst int head = hld.head(hld.heavy(v));\r\n\t\t\t\trv = f(seg.fold(hld.in(head),\
    \ hld.in(v) + 1), rv);\r\n\t\t\t\tv = hld.par(head);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif (hld.in(u) < hld.in(v)) rv = f(seg.fold(hld.in(u) + !VERTEX, hld.in(v) +\
    \ 1), rv);\r\n\t\telse lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + VERTEX));\r\
    \n\t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type subtree_sum(int v) const\
    \ noexcept {\r\n\t\tassert(0 <= v && v < hld.size());\r\n\t\treturn seg.fold(hld.in(v)\
    \ + !VERTEX, hld.out(v));\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP\r\n#define\
    \ INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP\r\n\r\n#include \"DataStructure/SegmentTree.hpp\"\
    \r\n#include \"GraphTheory/HeavyLightDecomposition.hpp\"\r\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <functional>\r\n#include <algorithm>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct HeavyLightDecomposition_Query {\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ seg_type = SegmentTree<value_type>;\r\n\tusing hld_type = HeavyLightDecomposition;\r\
    \n\tusing size_type = std::size_t;\r\n\tusing Graph = typename hld_type::Graph;\r\
    \n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\n\
    \t\r\nprivate:\r\n\tbool VERTEX;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\thld_type\
    \ hld;\r\n\tseg_type seg, rseg;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, bool VERTEX, const value_type & id_elem, const F & f)\r\n\t\t: HeavyLightDecomposition_Query(g,\
    \ VERTEX, -1, id_elem, f) {}\r\n\t\r\n\tHeavyLightDecomposition_Query(const Graph\
    \ & g, bool VERTEX, int root, const value_type & id_elem, const F & f)\r\n\t\t\
    : VERTEX(VERTEX), id_elem(id_elem), f(f), hld(g, root, false) {\r\n\t\tseg = seg_type{static_cast<size_type>(hld.size()),\
    \ id_elem, f};\r\n\t\trseg = seg_type{static_cast<size_type>(hld.size()), id_elem,\
    \ f};\r\n\t}\r\n\t\r\n\ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\
    \n\t\t: HeavyLightDecomposition_Query(g, -1, v, id_elem, f) {}\r\n\t\r\n\ttemplate<typename\
    \ U>\r\n\tHeavyLightDecomposition_Query(const Graph & g, int root, const std::vector<U>\
    \ & v, const value_type & id_elem, const F & f)\r\n\t\t: VERTEX(true), id_elem(id_elem),\
    \ f(f), hld(g, root, false) {\r\n\t\tassert(hld.size() == v.size());\r\n\t\tstd::vector<value_type>\
    \ init(hld.size());\r\n\t\tfor (int i = 0; i < hld.size(); ++i) init[hld.in(i)]\
    \ = v[i];\r\n\t\tseg = seg_type{init, id_elem, f};\r\n\t\tfor (int i = 0; i <\
    \ hld.heavy_size(); ++i) {\r\n\t\t\tconst int offset = hld.in(hld.head(i));\r\n\
    \t\t\tstd::reverse(begin(init) + offset, begin(init) + offset + hld.heavy_size(i));\r\
    \n\t\t}\r\n\t\trseg = seg_type{init, id_elem, f};\r\n\t}\r\n\t\r\n\tconst hld_type\
    \ & get_hld() const noexcept {\r\n\t\treturn get_hld;\r\n\t}\r\n\t\r\n\tvoid set(int\
    \ v, const_reference x) noexcept {\r\n\t\tassert(VERTEX);\r\n\t\tassert(0 <= v\
    \ && v < hld.size());\r\n\t\tset_(v, x);\r\n\t}\r\n\t\r\n\tvalue_type get(int\
    \ v) const noexcept {\r\n\t\tassert(VERTEX);\r\n\t\tassert(0 <= v && v < hld.size());\r\
    \n\t\treturn get_(v);\r\n\t}\r\n\t\r\n\tvoid set(int u, int v, const_reference\
    \ x) noexcept {\r\n\t\tassert(!VERTEX);\r\n\t\tassert(0 <= u && u < hld.size());\r\
    \n\t\tassert(0 <= v && v < hld.size());\r\n\t\tassert(hld.par(u) == v || hld.par(v)\
    \ == u);\r\n\t\tset_(hld.par(u) == v ? u : v, x);\r\n\t}\r\n\t\r\n\tvalue_type\
    \ get(int u, int v) const noexcept {\r\n\t\tassert(!VERTEX);\r\n\t\tassert(0 <=\
    \ u && u < hld.size());\r\n\t\tassert(0 <= v && v < hld.size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\treturn get_(hld.par(u) == v ? u : v);\r\n\t\
    }\r\n\t\r\nprivate:\r\n\tvoid set_(int v, const_reference x) noexcept {\r\n\t\t\
    seg.set(hld.in(v), x);\r\n\t\trseg.set(reverse_idx(v), x);\r\n\t}\r\n\t\r\n\t\
    value_type get_(int v) const noexcept {\r\n\t\treturn seg.get(hld.in(v));\r\n\t\
    }\r\n\t\r\n\tint reverse_idx(int v) const noexcept {\r\n\t\tconst int id = hld.heavy(v);\r\
    \n\t\treturn (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;\r\
    \n\t}\r\n\t\r\npublic:\r\n\tvalue_type fold(int u, int v) const noexcept {\r\n\
    \t\tassert(0 <= u && u < hld.size());\r\n\t\tassert(0 <= v && v < hld.size());\r\
    \n\t\tassert(hld.tree_id(u) == hld.tree_id(v));\r\n\t\tvalue_type lv = id_elem,\
    \ rv = id_elem;\r\n\t\twhile (hld.heavy(u) != hld.heavy(v)) {\r\n\t\t\tif (hld.heavy_depth(hld.heavy(u))\
    \ >= hld.heavy_depth(hld.heavy(v))) {\r\n\t\t\t\tconst int head = hld.head(hld.heavy(u));\r\
    \n\t\t\t\tlv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));\r\n\t\t\
    \t\tu = hld.par(head);\r\n\t\t\t}\r\n\t\t\tif (hld.heavy(u) == hld.heavy(v)) break;\r\
    \n\t\t\tif (hld.heavy_depth(hld.heavy(u)) <= hld.heavy_depth(hld.heavy(v))) {\r\
    \n\t\t\t\tconst int head = hld.head(hld.heavy(v));\r\n\t\t\t\trv = f(seg.fold(hld.in(head),\
    \ hld.in(v) + 1), rv);\r\n\t\t\t\tv = hld.par(head);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif (hld.in(u) < hld.in(v)) rv = f(seg.fold(hld.in(u) + !VERTEX, hld.in(v) +\
    \ 1), rv);\r\n\t\telse lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + VERTEX));\r\
    \n\t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type subtree_sum(int v) const\
    \ noexcept {\r\n\t\tassert(0 <= v && v < hld.size());\r\n\t\treturn seg.fold(hld.in(v)\
    \ + !VERTEX, hld.out(v));\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - GraphTheory/HeavyLightDecomposition.hpp
  isVerificationFile: false
  path: GraphTheory/HeavyLightDecomposition_Query.hpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
documentation_of: GraphTheory/HeavyLightDecomposition_Query.hpp
layout: document
title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3) \u30AF\u30A8\u30EA"
---

# 概要

頂点数 $N$ の木に対し、[重軽分解 ( HL 分解)](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) と [セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) を用いて、$1$ 点更新 $\Theta(\log{N})$ 、パスクエリを $\mathcal{O}((\log{N})^2)$ 、部分木クエリを $\Theta(\log{N})$ で処理します。  
[1 点更新パス Fold](https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp) でも同様な処理ができます。$\log$ が 1 つ少ないのでより高速な(はず)です。  
詳しくは`使用例`をご覧ください。  

- `HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, const T & id_elem, const F & f)`
	- $\Theta(N)$ グラフ `g` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, int root, const T & id_elem, const F & f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, std::vector<U> & v, const T & id_elem, const F & f)`
	- $\Theta(N)$ グラフ `g` と初期値 `v` で初期化
- `HeavyLightDecomposition_Query(const Graph & g, int root, std::vector<U> & v, const T & id_elem, const F & f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` と初期値 `v` で初期化
- `const HLD & get_hld()`
	- $\Theta(1)$ 内部で保持している HLD を返す
- `void set(int v, const T & x)`
	- $\Theta(\log{N})$ 頂点 $v$ に値 $x$ をセットする
- `T get(int v)`
	- $\Theta(1)$ 頂点 $v$ の値を返す
- `void set(int u, int v, const T & x)`
	- $\Theta(\log{N})$ 辺 $u-v$ に値 $x$ をセットする
- `T get(int u, int v)`
	- $\Theta(1)$ 辺 $u-v$ の値を返す
- `T fold(int u, int v)`
	- $\mathcal{O}((\log{N})^2)$ $u-v$ パスを畳み込んだ結果を返す
- `T subtree_sum(int v)`
	- $\mathcal{O}(\log{N})$ 部分木の総和を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  
`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- $(T, f,$ `id_elem`$)$ はモノイド
- 頂点に値を持つ場合は `VERTEX` $= true$
- 辺に値を持つ場合は `VERTEX` $= false$

---

### HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, const T & id_elem, const F & f)

グラフ `g` で初期化します。
はじめ、すべての値は単位元です。  

**制約**

- `g` は木

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, bool VERTEX, int root, const T & id_elem, const F & f)

根 `root` の根付き木 `g` で初期化します。
はじめ、すべての値は単位元です。  

**制約**

- `g` は `root` を根とした根付き木または木

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, std::vector&lt;U&gt; & v, const T & id_elem, const F & f)

グラフ `g` と初期値 `v` で初期化します。
はじめ、頂点 $i$ の値は $v[i]$ です。  

**制約**

- `g` は木
- $\|$`v`$\| = N$

**計算量**

- $\Theta(N)$

---

### HeavyLightDecomposition_Query(const Graph & g, int root, std::vector&lt;U&gt; & v, const T & id_elem, const F & f)

根 `root` の根付き木 `g` と初期値 `v` で初期化します。
はじめ、頂点 $i$ の値は $v[i]$ です。  

**制約**

- `g` は `root` を根とした根付き木または木
- $\|$`v`$\| = N$

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

### const HLD & get_hld()

内部で保持している HLD を返します。  

**計算量**

- $\Theta(1)$

---

### void set(int v, const T & x)

頂点 $v$ に値 $x$ をセットします。  

**制約**

- `VERTEX` $= true$
- $0 \leq v < N$

**計算量**

- $\Theta(\log{N})$

---

### T get(int v)

頂点 $v$ の値を返します。  

**制約**

- `VERTEX` $= true$
- $0 \leq v < N$

**計算量**

- $\Theta(1)$

---

### void set(int u, int v, const T & x)

辺 $u-v$ に値 $x$ をセットします。  

**制約**

- `VERTEX` $= false$
- $0 \leq u, v < N$

**計算量**

- $\Theta(\log{N})$

---

### T get(int u, int v)

辺 $u-v$ の値を返します。  

**制約**

- `VERTEX` $= false$
- $0 \leq u, v < N$

**計算量**

- $\Theta(1)$

---

### T fold(int u, int v)

頂点 $u$ から頂点 $v$ へのパス上の頂点または辺を順にその値を並べたものを $a_1, a_2, \ldots, a_k$ として、$f(a_1, f(a_2, f(\ldots, f(a_{k-2}, a_{k-1}))\ldots)$ を返します。  

**制約**

- $0 \leq u, v < N$

**計算量**

- $\mathcal{O}((\log{N})^2)$

---

### T subtree_sum(int v)

頂点 $u$ の部分木に含まれる頂点または辺の値をそれぞれ $a_1, a_2, \ldots, a_k$ として、$f(a_1, a_2, \ldots, a_{k-1})$ を返します。  

**制約**

- $(T, f,$ `id_elem`$)$ は可換モノイド
- $0 \leq u, v < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

頂点に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/HeavyLightDecomposition_Query.hpp"
using namespace std;

int main() {
	using HLD = HeavyLightDecomposition_Query<int>;
	HLD::Graph g(6);
	//         1(10)
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	vector<int> A{1, 10, 100, 1000, 10000, 100000};
	HLD hld(g, 1, A, 0, [](auto x, auto y) { return x + y; });
	
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << hld.fold(1, 3) << endl; // 1010
	// 4 -> 5 パス上の頂点 [4, 2, 1, 3, 5] の総和
	cout << "fold(4, 5) = " << hld.fold(4, 5) << endl; // 111110
	// 3 -> 3 パス上の頂点 [3] の総和
	cout << "fold(3, 3) = " << hld.fold(3, 3) << endl; // 1000
	
	// 頂点 1 の部分木の頂点 [0, 1, 2, 3, 4, 5] の値の総和
	cout << "subtree_sum(1) = " << hld.subtree_sum(1) << endl; // 111111
	// 頂点 2 の部分木の頂点 [0, 2, 4] の値の総和
	cout << "subtree_sum(2) = " << hld.subtree_sum(2) << endl; // 10101
	// 頂点 5 の部分木の頂点 [5] の値の総和
	cout << "subtree_sum(5) = " << hld.subtree_sum(5) << endl; // 100000
}
```

辺に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/HeavyLightDecomposition_Query.hpp"
using namespace std;

int main() {
	using HLD = HeavyLightDecomposition_Query<int>;
	HLD::Graph g(6);
	// 辺の値は葉側の頂点に書いてある
	//         1
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い

	HLD hld(g, false, 1, 0, [](auto x, auto y) { return x + y; });
	hld.set(1, 2, 100);
	hld.set(1, 3, 1000);
	hld.set(2, 0, 1);
	hld.set(2, 4, 10000);
	hld.set(3, 5, 100000);
	
	// 1 -> 3 パス上の辺 [1-3] の総和
	cout << "fold(1, 3) = " << hld.fold(1, 3) << endl; // 1000
	// 4 -> 5 パス上の辺 [4-2, 2-1, 1-3, 3-5] の総和
	cout << "fold(4, 5) = " << hld.fold(4, 5) << endl; // 111100
	// 3 -> 3 パス上の辺 [] の総和
	cout << "fold(3, 3) = " << hld.fold(3, 3) << endl; // 0
	
	// 頂点 1 の部分木の辺 [1-2, 2-0, 2-4, 1-3, 3-5] の値の総和
	cout << "subtree_sum(1) = " << hld.subtree_sum(1) << endl; // 111101
	// 頂点 2 の部分木の辺 [2-1, 2-4] の値の総和
	cout << "subtree_sum(2) = " << hld.subtree_sum(2) << endl; // 10001
	// 頂点 5 の部分木の辺 [] の値の総和
	cout << "subtree_sum(5) = " << hld.subtree_sum(5) << endl; // 0
}
```

<br>

# 参考

2020/04/19: [https://qiita.com/ageprocpp/items/8dfe768218da83314989](https://qiita.com/ageprocpp/items/8dfe768218da83314989)  
2020/04/19: [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)  
2020/09/18: [https://codeforces.com/blog/entry/53170](https://codeforces.com/blog/entry/53170)  

<br>