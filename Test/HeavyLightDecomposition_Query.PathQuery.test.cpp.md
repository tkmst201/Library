---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition_Query.hpp
    title: "\u91CD\u8EFD\u5206\u89E3 ( HL \u5206\u89E3) \u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: Mathematics/ModInt.hpp
    title: "ModInt \u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"Test/HeavyLightDecomposition_Query.PathQuery.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\r\
    \n\r\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n#include <cassert>\r\n#include\
    \ <iostream>\r\n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
    \n */\r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\
    \n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\n\
    private:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val % M + (val >= 0 ? 0 : M)) {}\r\n\tconstexpr value_type val()\
    \ const noexcept { return val_; }\r\n\tconstexpr static decltype(M) mod() noexcept\
    \ { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const noexcept {\
    \ return val_; }\r\n\tconstexpr bool operator !() const noexcept { return !static_cast<bool>(*this);\
    \ }\r\n\tconstexpr ModInt operator +() const noexcept { return *this; }\r\n\t\
    constexpr ModInt operator -() const noexcept { return ModInt(val_ == 0 ? 0 : M\
    \ - val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept { ModInt res = *this;\
    \ ++*this; return res; }\r\n\tconstexpr ModInt operator --(int) noexcept { ModInt\
    \ res = *this; --*this; return res; }\r\n\tconstexpr ModInt & operator ++() noexcept\
    \ { val_ = val_ + 1 == M ? 0 : val_ + 1; return *this; }\r\n\tconstexpr ModInt\
    \ & operator --() noexcept { val_ = val_ == 0 ? M - 1 : val_ - 1; return *this;\
    \ }\r\n\tconstexpr ModInt & operator +=(const ModInt & rhs) noexcept { val_ +=\
    \ val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ - M; return *this; }\r\n\tconstexpr\
    \ ModInt & operator -=(const ModInt & rhs) noexcept { val_ += val_ >= rhs.val_\
    \ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\tconstexpr ModInt & operator\
    \ *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_\
    \ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt & rhs)\
    \ noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt operator\
    \ +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) += rhs;\
    \ }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr ModInt operator\
    \ *(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) *= rhs;\
    \ }\r\n\tfriend constexpr ModInt operator /(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend constexpr bool operator\
    \ ==(const ModInt & lhs, const ModInt & rhs) noexcept { return lhs.val_ == rhs.val_;\
    \ }\r\n\tfriend constexpr bool operator !=(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val_; }\r\n\tfriend\
    \ std::istream & operator >>(std::istream & is, ModInt & rhs) { calc_type x; is\
    \ >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr ModInt pow(calc_type\
    \ n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\t\tif (n < 0) { x =\
    \ x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1;\
    \ }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv() const noexcept\
    \ {\r\n\t\tvalue_type a = val_, a1 = 1, b = M, b1 = 0;\r\n\t\twhile (b > 0) {\r\
    \n\t\t\tconst value_type q = a / b;\r\n\t\t\tvalue_type tmp = a - q * b; a = b;\
    \ b = tmp;\r\n\t\t\ttmp = a1 - q * b1; a1 = b1; b1 = tmp;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\tif (a1 < 0) a1 += M;\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n\
    #line 1 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\n\n\n\r\n#line 1 \"\
    DataStructure/SegmentTree.hpp\"\n\n\n\r\n#include <vector>\r\n#include <algorithm>\r\
    \n#line 7 \"DataStructure/SegmentTree.hpp\"\n#include <functional>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SegmentTree {\r\n\tusing value_type =\
    \ T;\r\n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
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
    \ + !VERTEX, hld.out(v));\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/HeavyLightDecomposition_Query.PathQuery.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 9 \"Test/HeavyLightDecomposition_Query.PathQuery.test.cpp\"\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing\
    \ mint = ModInt<998244353>;\r\n\tusing P = std::pair<mint, mint>;\r\n\tusing HLD\
    \ = HeavyLightDecomposition_Query<P>;\r\n\t\r\n\tstd::vector<P> init(N);\r\n\t\
    for (int i = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\
    \n\t\tinit[i] = {a, b};\r\n\t}\r\n\t\r\n\tHLD::Graph g(N);\r\n\tfor (int i = 0;\
    \ i < N - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\t\
    g[u].emplace_back(v);\r\n\t\tg[v].emplace_back(u);\r\n\t}\r\n\t\r\n\tHLD hld(g,\
    \ init, {1, 0},\r\n\t\t[](auto && x, auto && y) -> P { return {x.first * y.first,\
    \ x.second * y.first + y.second}; });\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\
    \n\t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint p, c, d;\r\n\t\t\t\
    scanf(\"%d %d %d\", &p, &c, &d);\r\n\t\t\thld.set(p, {c, d});\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\tint u, v, x;\r\n\t\t\tscanf(\"%d %d %d\", &u, &v, &x);\r\n\t\t\
    \tauto res = hld.fold(u, v);\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\
    \n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include \"Mathematics/ModInt.hpp\"\r\n#include \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n#include <utility>\r\n\r\nint\
    \ main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing mint\
    \ = ModInt<998244353>;\r\n\tusing P = std::pair<mint, mint>;\r\n\tusing HLD =\
    \ HeavyLightDecomposition_Query<P>;\r\n\t\r\n\tstd::vector<P> init(N);\r\n\tfor\
    \ (int i = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\
    \n\t\tinit[i] = {a, b};\r\n\t}\r\n\t\r\n\tHLD::Graph g(N);\r\n\tfor (int i = 0;\
    \ i < N - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\t\
    g[u].emplace_back(v);\r\n\t\tg[v].emplace_back(u);\r\n\t}\r\n\t\r\n\tHLD hld(g,\
    \ init, {1, 0},\r\n\t\t[](auto && x, auto && y) -> P { return {x.first * y.first,\
    \ x.second * y.first + y.second}; });\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\
    \n\t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint p, c, d;\r\n\t\t\t\
    scanf(\"%d %d %d\", &p, &c, &d);\r\n\t\t\thld.set(p, {c, d});\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\tint u, v, x;\r\n\t\t\tscanf(\"%d %d %d\", &u, &v, &x);\r\n\t\t\
    \tauto res = hld.fold(u, v);\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\
    \n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - Mathematics/ModInt.hpp
  - GraphTheory/HeavyLightDecomposition_Query.hpp
  - DataStructure/SegmentTree.hpp
  - GraphTheory/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
layout: document
redirect_from:
- /verify/Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
- /verify/Test/HeavyLightDecomposition_Query.PathQuery.test.cpp.html
title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
---
