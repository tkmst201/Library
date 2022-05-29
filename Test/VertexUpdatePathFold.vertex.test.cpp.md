---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/VertexUpdatePathFold.hpp
    title: "1 \u70B9\u66F4\u65B0 \u30D1\u30B9 Fold"
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
  bundledCode: "#line 1 \"Test/VertexUpdatePathFold.vertex.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\r\n\r\n#line 1\
    \ \"Mathematics/ModInt.hpp\"\n\n\n\r\n#include <cassert>\r\n#include <iostream>\r\
    \n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
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
    #line 1 \"GraphTheory/VertexUpdatePathFold.hpp\"\n\n\n\r\n#include <algorithm>\r\
    \n#line 6 \"GraphTheory/VertexUpdatePathFold.hpp\"\n#include <functional>\r\n\
    #include <stack>\r\n#include <tuple>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct VertexUpdatePathFold {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\n\
    \t\r\nprivate:\r\n\tusing int3 = std::tuple<int, int, int>;\r\n\tstruct Node {\r\
    \n\t\tvalue_type val, rval;\r\n\t\tint par;\r\n\t\tint dep; // 16bits(seg depth)\
    \ 16bits(heavy-path depth)\r\n\t\tint childs[2];\r\n\t\tNode() = default;\r\n\t\
    \tNode(value_type val) : val(val), rval(val), par(-1), childs{-1, -1} {};\r\n\t\
    \tNode(int par, int seg_dep, int heavy_dep) : par(par), dep(comp_dep(seg_dep,\
    \ heavy_dep)) {}\r\n\t\tNode(int par, int seg_dep, int heavy_dep, int lcld, int\
    \ rcld)\r\n\t\t\t: par(par), dep(comp_dep(seg_dep, heavy_dep)), childs{lcld, rcld}\
    \ {}\r\n\t\tstatic int comp_dep(int seg_dep, int heavy_dep) noexcept {\r\n\t\t\
    \treturn seg_dep << 16 | heavy_dep;\r\n\t\t}\r\n\t\tstd::pair<int, int> decomp_dep()\
    \ const noexcept {\r\n\t\t\treturn {dep >> 16, dep & ((1 << 16) - 1)};\r\n\t\t\
    }\r\n\t\tvoid set_dep(int seg_dep, int heavy_dep) noexcept {\r\n\t\t\tdep = comp_dep(seg_dep,\
    \ heavy_dep);\r\n\t\t}\r\n\t\tvoid set_prop(int par, int seg_dep, int heavy_dep)\
    \ noexcept {\r\n\t\t\tthis->par = par;\r\n\t\t\tset_dep(seg_dep, heavy_dep);\r\
    \n\t\t}\r\n\t};\r\n\t\r\n\tint n;\r\n\tconst bool VERTEX;\r\n\tvalue_type id_elem;\r\
    \n\tF f;\r\n\tstd::vector<Node> nodes;\r\n\tstd::vector<int> par_, depth_, heavy;\r\
    \n\t\r\n\tvoid node_calc(int u) {\r\n\t\tnodes[u].val = f(nodes[nodes[u].childs[0]].val,\
    \ nodes[nodes[u].childs[1]].val);\r\n\t\tnodes[u].rval = f(nodes[nodes[u].childs[1]].rval,\
    \ nodes[nodes[u].childs[0]].rval);\r\n\t}\r\n\t\r\npublic:\r\n\tVertexUpdatePathFold(const\
    \ Graph &g, int root, bool VERTEX, const_reference d_elem, const F &f)\r\n\t\t\
    : n(g.size()), VERTEX(VERTEX), id_elem(id_elem), f(f) {\r\n\t\tnodes.reserve(2\
    \ * n);\r\n\t\tnodes.assign(n, {id_elem});\r\n\t\tbuild(g, root);\r\n\t}\r\n\t\
    \r\n\ttemplate<typename U>\r\n\tVertexUpdatePathFold(const Graph &g, int root,\
    \ const std::vector<U> &dat, bool VERTEX, const_reference id_elem, const F &f)\r\
    \n\t\t: n(g.size()), VERTEX(VERTEX), id_elem(id_elem), f(f) {\r\n\t\tnodes.reserve(2\
    \ * n);\r\n\t\tfor (int i = 0; i < n; ++i) nodes.emplace_back(dat[i]);\r\n\t\t\
    build(g, root);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build(const Graph &g, int root)\
    \ {\r\n\t\tpar_.assign(n, -1);\r\n\t\tdepth_.assign(n, 0);\r\n\t\theavy.assign(n,\
    \ -1);\r\n\t\tstd::vector<int> siz(n, 0);\r\n\t\tstd::stack<std::pair<int, int>>\
    \ stk;\r\n\t\tstk.emplace(root, 0);\r\n\t\tsiz[root] = 0;\r\n\t\twhile (stk.size())\
    \ {\r\n\t\t\tauto [u, idx] = stk.top(); stk.pop();\r\n\t\t\tif (idx == g[u].size())\
    \ {\r\n\t\t\t\tif (par_[u] != -1) siz[par_[u]] += ++siz[u];\r\n\t\t\t}\r\n\t\t\
    \telse {\r\n\t\t\t\tstk.emplace(u, idx + 1);\r\n\t\t\t\tconst int v = g[u][idx];\r\
    \n\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\
    par_[v] = u;\r\n\t\t\t\tdepth_[v] = depth_[u] + 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    int heavy_num = 0;\r\n\t\tstd::vector<int> heavy_stk;\r\n\t\theavy_stk.emplace_back(-(root\
    \ + 1));\r\n\t\tnodes[root].dep = 0;\r\n\t\tstk.emplace(root, 0);\r\n\t\twhile\
    \ (stk.size()) {\r\n\t\t\tauto [u, idx] = stk.top(); stk.pop();\r\n\t\t\tif (idx\
    \ == g[u].size()) {\r\n\t\t\t\tif (nodes[u].par != -1) {\r\n\t\t\t\t\tconst int\
    \ v = g[u][nodes[u].par];\r\n\t\t\t\t\theavy_stk.emplace_back(v);\r\n\t\t\t\t\t\
    nodes[v].dep = nodes[u].dep;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\tif (g[u].size() == 0) siz[u] = 1;\r\n\t\t\t\tint st = static_cast<int>(heavy_stk.size())\
    \ - 1;\r\n\t\t\t\twhile (heavy_stk[st] >= 0) --st;\r\n\t\t\t\theavy_stk[st] =\
    \ -heavy_stk[st] - 1;\r\n\t\t\t\tconst int rootnum = n << 1;\r\n\t\t\t\tconst\
    \ int heavy_par = st == 0 ? rootnum : (heavy_stk[st - 1] >= 0 ? heavy_stk[st -\
    \ 1] : -heavy_stk[st - 1] - 1);\r\n\t\t\t\tconst int hs = static_cast<int>(heavy_stk.size())\
    \ - st;\r\n\t\t\t\tconst int heavy_dep = nodes[heavy_stk[st]].dep;\r\n\t\t\t\t\
    for (int i = 0; i < hs; ++i) heavy[heavy_stk[st + i]] = heavy_num;\r\n\t\t\t\t\
    ++heavy_num;\r\n\t\t\t\tstd::vector<int> sum(hs + 1);\r\n\t\t\t\tsum[0] = 0;\r\
    \n\t\t\t\tfor (int i = 0; i < hs; ++i) sum[i + 1] = sum[i] + siz[heavy_stk[st\
    \ + i]];\r\n\t\t\t\tstd::stack<int3> merge_stk;\r\n\t\t\t\tmerge_stk.emplace(0,\
    \ hs, heavy_par);\r\n\t\t\t\twhile (merge_stk.size()) {\r\n\t\t\t\t\tauto [l,\
    \ r, p] = merge_stk.top(); merge_stk.pop();\r\n\t\t\t\t\tif (l == -1) { node_calc(p);\
    \ continue; }\r\n\t\t\t\t\tconst bool rchild = p < 0;\r\n\t\t\t\t\tif (p < 0)\
    \ p = -p - 1;\r\n\t\t\t\t\tconst int seg_dep = (p == heavy_par) ? 0 : nodes[p].decomp_dep().first\
    \ + 1;\r\n\t\t\t\t\tauto merge = [&](int u, int v, int p, bool rchild, int seg_dep)\
    \ -> int {\r\n\t\t\t\t\t\tconst int self = nodes.size();\r\n\t\t\t\t\t\tnodes.emplace_back(p,\
    \ seg_dep, heavy_dep, u, v);\r\n\t\t\t\t\t\tif (u != -1) nodes[u].set_prop(self,\
    \ seg_dep + 1, heavy_dep);\r\n\t\t\t\t\t\tif (v != -1) nodes[v].set_prop(self,\
    \ seg_dep + 1, heavy_dep);\r\n\t\t\t\t\t\tif (p != heavy_par) nodes[p].childs[rchild]\
    \ = self;\r\n\t\t\t\t\t\tif (u != -1 && v != -1) node_calc(self);\r\n\t\t\t\t\t\
    \telse merge_stk.emplace(-1, -1, self);\r\n\t\t\t\t\t\treturn self;\r\n\t\t\t\t\
    \t};\r\n\t\t\t\t\tif (r - l <= 2) {\r\n\t\t\t\t\t\tif (r - l == 1) {\r\n\t\t\t\
    \t\t\t\tconst int v = heavy_stk[l + st];\r\n\t\t\t\t\t\t\tnodes[v].set_prop(p,\
    \ seg_dep, heavy_dep);\r\n\t\t\t\t\t\t\tif (p != heavy_par) nodes[p].childs[rchild]\
    \ = v;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t\telse merge(heavy_stk[l + st], heavy_stk[l\
    \ + st + 1], p, rchild, seg_dep);\r\n\t\t\t\t\t\tcontinue;\r\n\t\t\t\t\t}\r\n\t\
    \t\t\t\tconst int m = lower_bound(sum.begin() + l + 1, sum.begin() + r + 1, (sum[r]\
    \ + sum[l]) >> 1) - sum.begin() - 1;\r\n\t\t\t\t\tconst int v = heavy_stk[m +\
    \ st];\r\n\t\t\t\t\tconst int top = nodes.size();\r\n\t\t\t\t\tif (m == l) {\r\
    \n\t\t\t\t\t\tmerge(v, -1, p, rchild, seg_dep);\r\n\t\t\t\t\t\tmerge_stk.emplace(m\
    \ + 1, r, -top - 1);\r\n\t\t\t\t\t}\r\n\t\t\t\t\telse if (m + 1 == r) {\r\n\t\t\
    \t\t\t\tmerge(-1, v, p, rchild, seg_dep);\r\n\t\t\t\t\t\tmerge_stk.emplace(l,\
    \ m, top);\r\n\t\t\t\t\t}\r\n\t\t\t\t\telse {\r\n\t\t\t\t\t\tif (sum[m] - sum[l]\
    \ < sum[r] - sum[m + 1]) {\r\n\t\t\t\t\t\t\tmerge(-1, -1, p, rchild, seg_dep);\r\
    \n\t\t\t\t\t\t\tmerge_stk.emplace(m + 1, r, -top - 1);\r\n\t\t\t\t\t\t\tmerge(-1,\
    \ v, top, false, seg_dep + 1);\r\n\t\t\t\t\t\t\tmerge_stk.emplace(l, m, top +\
    \ 1);\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t\telse {\r\n\t\t\t\t\t\t\tmerge(-1, -1, p,\
    \ rchild, seg_dep);\r\n\t\t\t\t\t\t\tmerge_stk.emplace(l, m, top);\r\n\t\t\t\t\
    \t\t\tmerge(v, -1, top, true, seg_dep + 1);\r\n\t\t\t\t\t\t\tmerge_stk.emplace(m\
    \ + 1, r, -(top + 1) - 1);\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\
    \t\twhile (heavy_stk.size() > st) heavy_stk.pop_back();\r\n\t\t\t\tif (heavy_par\
    \ != rootnum) siz[heavy_par] += hs;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tif (idx\
    \ == 0) {\r\n\t\t\t\t\tsiz[u] = 1;\r\n\t\t\t\t\tint mxc = 0;\r\n\t\t\t\t\tfor\
    \ (int i = 0; i < static_cast<int>(g[u].size()); ++i) {\r\n\t\t\t\t\t\tconst int\
    \ v = g[u][i];\r\n\t\t\t\t\t\tif (v != par_[u] && mxc < siz[v]) {\r\n\t\t\t\t\t\
    \t\tnodes[u].par = i;\r\n\t\t\t\t\t\t\tmxc = siz[v];\r\n\t\t\t\t\t\t}\r\n\t\t\t\
    \t\t}\r\n\t\t\t\t}\r\n\t\t\t\tstk.emplace(u, idx + 1);\r\n\t\t\t\tconst int v\
    \ = g[u][idx];\r\n\t\t\t\tif (v == par_[u] || idx == nodes[u].par) continue;\r\
    \n\t\t\t\theavy_stk.emplace_back(-(v + 1));\r\n\t\t\t\tnodes[v].dep = nodes[u].dep\
    \ + 1;\r\n\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\npublic:\r\
    \n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tint par(int\
    \ v) const noexcept {\r\n\t\tassert(0 <= v && v < n);\r\n\t\treturn par_[v];\r\
    \n\t}\r\n\t\r\n\tint depth(int v) const noexcept {\r\n\t\tassert(0 <= v && v <\
    \ n);\r\n\t\treturn depth_[v];\r\n\t}\r\n\t\r\n\tvoid set(int v, const_reference\
    \ x) noexcept {\r\n\t\tassert(VERTEX);\r\n\t\tassert(0 <= v && v < n);\r\n\t\t\
    set_impl(v, x);\r\n\t}\r\n\t\r\n\tvalue_type get(int v) const noexcept {\r\n\t\
    \tassert(VERTEX);\r\n\t\tassert(0 <= v && v < n);\r\n\t\treturn get_impl(v);\r\
    \n\t}\r\n\t\r\n\tvoid set(int u, int v, const_reference x) noexcept {\r\n\t\t\
    assert(!VERTEX);\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\
    \n\t\tset_impl(par_[u] == v ? u : v, x);\r\n\t}\r\n\t\r\n\tvalue_type get(int\
    \ u, int v) const noexcept {\r\n\t\tassert(!VERTEX);\r\n\t\tassert(0 <= u && u\
    \ < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\treturn get_impl(par_[u] == v ?\
    \ u : v);\r\n\t}\r\n\t\r\n\tvalue_type fold(int u, int v) const noexcept {\r\n\
    \t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tvalue_type\
    \ lv = id_elem, rv = id_elem;\r\n\t\tauto uup = [&](int step = -1, bool lret =\
    \ true) {\r\n\t\t\tif (step == -1) {\r\n\t\t\t\tlv = f(lv, nodes[u].rval);\r\n\
    \t\t\t\tstep = nodes[u].decomp_dep().first + 1;\r\n\t\t\t}\r\n\t\t\twhile (step--)\
    \ {\r\n\t\t\t\tconst int p = nodes[u].par;\r\n\t\t\t\tif (lret && nodes[p].childs[1]\
    \ == u) lv = f(lv, nodes[nodes[p].childs[0]].rval);\r\n\t\t\t\tif (!lret && nodes[p].childs[0]\
    \ == u) lv = f(lv, nodes[nodes[p].childs[1]].val);\r\n\t\t\t\tu = p;\r\n\t\t\t\
    }\r\n\t\t};\r\n\t\tauto vup = [&](int step = -1, bool lret = true) {\r\n\t\t\t\
    if (step == -1) {\r\n\t\t\t\trv = f(nodes[v].val, rv);\r\n\t\t\t\tstep = nodes[v].decomp_dep().first\
    \ + 1;\r\n\t\t\t}\r\n\t\t\twhile(step--) {\r\n\t\t\t\tconst int p = nodes[v].par;\r\
    \n\t\t\t\tif (lret && nodes[p].childs[1] == v) rv = f(nodes[nodes[p].childs[0]].val,\
    \ rv);\r\n\t\t\t\tif (!lret && nodes[p].childs[0] == v) rv = f(nodes[nodes[p].childs[1]].rval,\
    \ rv);\r\n\t\t\t\tv = p;\r\n\t\t\t}\r\n\t\t};\r\n\t\twhile (nodes[u].decomp_dep().second\
    \ > nodes[v].decomp_dep().second) uup();\r\n\t\twhile (nodes[u].decomp_dep().second\
    \ < nodes[v].decomp_dep().second) vup();\r\n\t\twhile (heavy[u] != heavy[v]) uup(),\
    \ vup();\r\n\t\tbool lright = depth_[u] > depth_[v];\r\n\t\tif (u == v) return\
    \ VERTEX ? f(f(lv, nodes[u].val), rv) : f(lv, rv);\r\n\t\tif (VERTEX || lright)\
    \ lv = f(lv, nodes[u].val);\r\n\t\tif (VERTEX || !lright) rv = f(nodes[v].val,\
    \ rv);\r\n\t\tconst int udep = nodes[u].decomp_dep().first, vdep = nodes[v].decomp_dep().first;\r\
    \n\t\tif (udep > vdep) uup(udep - vdep, lright);\r\n\t\tif (udep < vdep) vup(vdep\
    \ - udep, !lright);\r\n\t\twhile (nodes[u].par != nodes[v].par) uup(1, lright),\
    \ vup(1, !lright);\r\n\t\treturn f(lv, rv);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid\
    \ set_impl(int v, const_reference x) noexcept {\r\n\t\tnodes[v].val = x;\r\n\t\
    \tnodes[v].rval = x;\r\n\t\tfor (int i = nodes[v].decomp_dep().first; i > 0; --i)\
    \ node_calc(v = nodes[v].par);\r\n\t}\r\n\t\r\n\tvalue_type get_impl(int v) const\
    \ noexcept {\r\n\t\treturn nodes[v].val;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/VertexUpdatePathFold.vertex.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 9 \"Test/VertexUpdatePathFold.vertex.test.cpp\"\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing\
    \ mint = ModInt<998244353>;\r\n\tusing P = std::pair<mint, mint>;\r\n\tusing VUPF\
    \ = VertexUpdatePathFold<P>;\r\n\t\r\n\tstd::vector<P> init(N);\r\n\tfor (int\
    \ i = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\
    \tinit[i] = {a, b};\r\n\t}\r\n\t\r\n\tVUPF::Graph g(N);\r\n\tfor (int i = 0; i\
    \ < N - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tg[u].emplace_back(v);\r\
    \n\t\tg[v].emplace_back(u);\r\n\t}\r\n\t\r\n\tVUPF vupf(g, 0, init, true, {1,\
    \ 0}, [](auto && x, auto && y) -> P { return {x.first * y.first, x.second * y.first\
    \ + y.second}; });\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\
    \n\t\tif (q == 0) {\r\n\t\t\tint p, c, d;\r\n\t\t\tscanf(\"%d %d %d\", &p, &c,\
    \ &d);\r\n\t\t\tvupf.set(p, {c, d});\r\n\t\t}\r\n\t\telse {\r\n\t\t\tint u, v,\
    \ x;\r\n\t\t\tscanf(\"%d %d %d\", &u, &v, &x);\r\n\t\t\tauto res = vupf.fold(u,\
    \ v);\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\n\t\t\
    }\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include \"Mathematics/ModInt.hpp\"\r\n#include \"GraphTheory/VertexUpdatePathFold.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n#include <utility>\r\n\r\nint\
    \ main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing mint\
    \ = ModInt<998244353>;\r\n\tusing P = std::pair<mint, mint>;\r\n\tusing VUPF =\
    \ VertexUpdatePathFold<P>;\r\n\t\r\n\tstd::vector<P> init(N);\r\n\tfor (int i\
    \ = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\t\
    init[i] = {a, b};\r\n\t}\r\n\t\r\n\tVUPF::Graph g(N);\r\n\tfor (int i = 0; i <\
    \ N - 1; ++i) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tg[u].emplace_back(v);\r\
    \n\t\tg[v].emplace_back(u);\r\n\t}\r\n\t\r\n\tVUPF vupf(g, 0, init, true, {1,\
    \ 0}, [](auto && x, auto && y) -> P { return {x.first * y.first, x.second * y.first\
    \ + y.second}; });\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\
    \n\t\tif (q == 0) {\r\n\t\t\tint p, c, d;\r\n\t\t\tscanf(\"%d %d %d\", &p, &c,\
    \ &d);\r\n\t\t\tvupf.set(p, {c, d});\r\n\t\t}\r\n\t\telse {\r\n\t\t\tint u, v,\
    \ x;\r\n\t\t\tscanf(\"%d %d %d\", &u, &v, &x);\r\n\t\t\tauto res = vupf.fold(u,\
    \ v);\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\n\t\t\
    }\r\n\t}\r\n}"
  dependsOn:
  - Mathematics/ModInt.hpp
  - GraphTheory/VertexUpdatePathFold.hpp
  isVerificationFile: true
  path: Test/VertexUpdatePathFold.vertex.test.cpp
  requiredBy: []
  timestamp: '2022-05-29 18:12:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/VertexUpdatePathFold.vertex.test.cpp
layout: document
redirect_from:
- /verify/Test/VertexUpdatePathFold.vertex.test.cpp
- /verify/Test/VertexUpdatePathFold.vertex.test.cpp.html
title: Test/VertexUpdatePathFold.vertex.test.cpp
---
