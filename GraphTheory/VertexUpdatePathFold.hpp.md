---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/VertexUpdatePathFold.vertex.test.cpp
    title: Test/VertexUpdatePathFold.vertex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp
  bundledCode: "#line 1 \"GraphTheory/VertexUpdatePathFold.hpp\"\n\n\n\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n#include <stack>\r\
    \n#include <tuple>\r\n#include <utility>\r\n#include <vector>\r\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp\r\
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
    \ noexcept {\r\n\t\treturn nodes[v].val;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP\r\n#define INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP\r\
    \n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\
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
    \ noexcept {\r\n\t\treturn nodes[v].val;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/VertexUpdatePathFold.hpp
  requiredBy: []
  timestamp: '2022-05-29 18:12:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/VertexUpdatePathFold.vertex.test.cpp
documentation_of: GraphTheory/VertexUpdatePathFold.hpp
layout: document
title: "1 \u70B9\u66F4\u65B0 \u30D1\u30B9 Fold"
---

# 概要

頂点数 $N$ の木に対し、[重軽分解 ( HL 分解)](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp) と [セグメント木](https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp) とマージテクを用いて、$1$ 点更新とパスクエリを $\Theta(N)$ space $\mathcal(\log{N})$ time/query で処理します。  
[重軽分解 ( HL 分解) クエリ](https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition_Query.hpp) でも同様な処理ができますが、こちらの方が $\log$ が $1$ つ少ないです。  
詳しくは`使用例`をご覧ください。  

- `VertexUpdatePathFold(const Graph &g, int root, bool VERTEX, const T &id_elem, const F &f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` で初期化
- `template<typename U> VertexUpdatePathFold(const Graph &g, int root, const std::vector&lt;U&gt; &dat, bool VERTEX, const T &id_elem, const F &f)`
	- $\Theta(N)$ 根 `root` の根付き木 `g` と初期値 `dat` で初期化
- `int size()`
	- $\Theta(1)$ 頂点数 $N$ を返す
- `int par(int v)`
	- $\Theta(1)$ 頂点 $v$ の親を返す
- `int depth(int v)`
	- $\Theta(1)$ 頂点 $v$ の深さを返す
- `void set(int v, const T & x)`
	- $\Theta(\log{N})$ 頂点 $v$ に値 $x$ をセットする
- `T get(int v)`
	- $\Theta(1)$ 頂点 $v$ の値を返す
- `void set(int u, int v, const T & x)`
	- $\Theta(\log{N})$ 辺 $u-v$ に値 $x$ をセットする
- `T get(int u, int v)`
	- $\Theta(1)$ 辺 $u-v$ の値を返す
- `T fold(int u, int v)`
	- $\mathcal{O}(\log{N})$ $u-v$ パスを畳み込んだ結果を返す

<br>

# コンストラクタ

以下、グラフの頂点数を $N$ とします。  
`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- $(T, f,$ `id_elem`$)$ はモノイド
- 頂点に値を持つ場合は `VERTEX` $= true$
- 辺に値を持つ場合は `VERTEX` $= false$

---


### VertexUpdatePathFold(const Graph &g, int root, bool VERTEX, const T &id_elem, const F &f)

根が `root` の木 `g` で初期化します。
はじめ、すべての値は単位元です。  

**制約**

- $0 \le$ `root` $< N$
- `g` は `root` を根とした根付き木または木

**計算量**

- $\Theta(N)$

---

### template<typename U> VertexUpdatePathFold(const Graph &g, int root, const std::vector&lt;U&gt; &dat, bool VERTEX, const T &id_elem, const F &f)

各頂点または辺の値を `dat` として根 `root` の木 `g` で初期化します。  
辺 $u-v$ の値は $u$ と $v$ で深さが深い方の頂点の index に入れてください。  

**制約**

- $0 \le$ `root` $< N$
- `g` は `root` を根とした根付き木または木

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数


### int size()

頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int par(int v)

頂点 $v$ の親を返します。  
親が存在しない場合ば $-1$ を返します。  

**計算量**

- $\Theta(1)$

---

### int depth(int v)

頂点 $v$ の深さ(`root` から $v$ までの単純パスに含まれる辺の数) を返します。

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

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

頂点に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/VertexUpdatePathFold.hpp"
using namespace std;

int main() {
	using VUPF = VertexUpdatePathFold<int>;
	VUPF::Graph g(6);
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
	VUPF vupf(g, 1, A, true, 0, [](auto x, auto y) { return x + y; });
	
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 1010
	// 4 -> 5 パス上の頂点 [4, 2, 1, 3, 5] の総和
	cout << "fold(4, 5) = " << vupf.fold(4, 5) << endl; // 111110
	// 3 -> 3 パス上の頂点 [3] の総和
	cout << "fold(3, 3) = " << vupf.fold(3, 3) << endl; // 1000
	
	// 頂点 3 の値の変更
	vupf.set(3, 2000);
	// 1 -> 3 パス上の頂点 [1, 3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 2010
	
	cout << "size() = " << vupf.size() << endl; // 6
	cout << "depth(3) = " << vupf.depth(3) << endl; // 1
	cout << "depth(1) = " << vupf.depth(1) << endl; // 0
	cout << "par(5) = " << vupf.par(5) << endl; // 3
	cout << "par(1) = " << vupf.par(1) << endl; // -1
}
```

辺に値を持つ例です。

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/VertexUpdatePathFold.hpp"
using namespace std;

int main() {
	using VUPF = VertexUpdatePathFold<int>;
	VUPF::Graph g(6);
	//         1(10)
	//    2(100)    3(1000)
	// 0(1)  4(10000)    5(100000)
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	
	g[5].emplace_back(3); // 逆辺があっても良い
	
	vector<int> A({1, 10, 100, 1000, 10000, 100000});
	VUPF vupf(g, 1, A, false, 0, [](auto x, auto y) { return x + y; });
	vupf.set(1, 2, 100);
	vupf.set(1, 3, 1000);
	vupf.set(2, 0, 1);
	vupf.set(2, 4, 10000);
	vupf.set(3, 5, 100000);
	
	// 1 -> 3 パス上の辺 [1-3] の総和
	cout << "fold(1, 3) = " << vupf.fold(1, 3) << endl; // 1000
	// 4 -> 5 パス上の辺 [4-2, 2-1, 1-3, 3-5] の総和
	cout << "fold(4, 5) = " << vupf.fold(4, 5) << endl; // 111100
	// 3 -> 3 パス上の辺 [] の総和
	cout << "fold(3, 3) = " << vupf.fold(3, 3) << endl; // 0
}
```

<br>

# 解説

### セグメントのマージテク

各 heavy-path (heavy-edge をつなげたパス) を二分木にすることを考える。  
このとき、完全二分木ではなく、頂点の子孫に含まれるもとの木の頂点の数を重みとしてマージテクを行って作成する。  
これにより、任意の頂点から根までの辺の本数は (light-edge の本数) + sum(heavy_path の木で上る辺) となる。  
light-edge の辺の合計は HL 分解により $\mathcal{O}(\log{N})$ 本であり、第 2 項はマージテクにより打ち消し合って最終的に $\mathcal{O}(\log{N})$ になる。  
詳しくは参考リンク先を読んで下さい。  

### 実装メモ

実装の方針は、

1. 各部分木の頂点数を計算 `sz[i]` に格納
2. DFS の帰りがけ順で heavy-path をセグメント木に変形していく。

その他細かいテクニック  

- `sz[i]` を用いて heavy-edge の index を計算したら一旦 `nodes[i].par` に保存しておく
- heavy-edge の index を計算し終えたら `sz[i]` は light-edge 以下の部分木の頂点数の合計を表すようにしている
- `heavy_stk` は作成中の heavy-path を表していて、負になった index が先頭を表している (つまり、light-edge を下りるときに負の index を追加し、heavy-edge を通るときに非負の index を入れている)
- `merge_stk` では、`(l, r, p)` で `heavy_stk[l + st, r + st)` の頂点のマージで全体の親を `p` とするように処理する。新たに作成された頂点の値は各部分木の値が確定したから計算されるようになっている
- `uup`, `vup` では、`step=-1` のとき頂点が heavy-path セグメント木の葉にいることを仮定している (葉にいることと頂点がもとの木に含まれていることが同値)
- `heavy[i]` はもとの木に含まれる頂点 $i$ が属する heavy-path の番号を格納してあり、`fold` で同一のセグメント木にいるかの判定に使用している
- `depth_[i]` は `fold` で同一のセグメント木にいるときに、どちらの方向に heavy-path の値を回収すれば良いかの判定に使用している

<br>

# デバッグ用メモ

各ノードの情報が正しいかおおまかにチェックします。  

```cpp
void tree_check() const noexcept {
	int top = 0;
	while (nodes[top].par < nodes.size()) top = nodes[top].par;
	std::vector<std::pair<int, int>> chd(nodes.size(), {-1, -1});
	for (int i = 0; i < n; ++i) {
		assert(nodes[i].childs[0] == -1);
		assert(nodes[i].childs[1] == -1);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (nodes[p].childs[0] == i) chd[p].first = i;
		else if (nodes[p].childs[1] == i) chd[p].second = i;
		else chd[p].first = i;
	}
	for (int i = n; i < nodes.size(); ++i) {
		assert(nodes[i].childs[0] != -1);
		assert(nodes[i].childs[1] != -1);
		assert(f(nodes[nodes[i].childs[0]].val, nodes[nodes[i].childs[1]].val) == nodes[i].val);
		assert(f(nodes[nodes[i].childs[1]].rval, nodes[nodes[i].childs[0]].rval) == nodes[i].rval);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (nodes[p].childs[0] == i) chd[p].first = i;
		else if (nodes[p].childs[1] == i) chd[p].second = i;
		else chd[p].first = i;
	}
	for (int i = n; i < nodes.size(); ++i) {
		assert(chd[i].first != -1);
		assert(chd[i].second != -1);
		auto [l, r] = nodes[i].childs;
		assert(l == chd[i].first);
		assert(r == chd[i].second);
		
		assert(nodes[l].decomp_dep() == nodes[r].decomp_dep());
		assert(nodes[l].decomp_dep().second == nodes[i].decomp_dep().second);
		assert(nodes[l].decomp_dep().first == nodes[i].decomp_dep().first + 1);
		if (i == top) continue;
		const int p = nodes[i].par;
		if (p < n) {
			assert(nodes[i].decomp_dep().first == 0);
			assert(nodes[p].decomp_dep().second == nodes[i].decomp_dep().second - 1);
		}
	}
	int mxd = 0;
	for (int i = 0; i < n; ++i) {
		int u = i;
		int cnt = 0;
		for (; nodes[u].par < nodes.size(); u = nodes[u].par, ++cnt);
		if (mxd < cnt) mxd = cnt;
	}
	
	int lgn = 1;
	while ((1 << lgn) < n) ++lgn;
	assert(mxd < 5 * lgn);
}
```

<br>


# TODO

- TODO: 辺に値を載せた場合の verify

<br>

# 参考

2022/05/28: [https://www.mathenachia.blog/mergetech-and-logn/](https://www.mathenachia.blog/mergetech-and-logn/)  
2022/05/28: [https://yosupo.hatenablog.com/entry/2015/10/02/233244](https://yosupo.hatenablog.com/entry/2015/10/02/233244)  
2022/05/28: 計算量解析 [https://noshi91.hatenablog.com/entry/2022/03/27/042143](https://noshi91.hatenablog.com/entry/2022/03/27/042143)   

<br>