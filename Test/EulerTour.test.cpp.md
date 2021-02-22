---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: GraphTheory/EulerTour.hpp
    title: GraphTheory/EulerTour.hpp
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
  bundledCode: "#line 1 \"Test/EulerTour.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#line 1 \"GraphTheory/EulerTour.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/09/16\r\
    \n\r\n\u8FBA\u306B\u756A\u53F7\u3092\u4ED8\u3051\u308B\u30BF\u30A4\u30D7\u306E\
    \ EulerTour\r\n\u5358\u7D14\u306A\u6728\u306E\u307F\u5BFE\u5FDC(\u81EA\u5DF1\u30EB\
    \u30FC\u30D7, \u591A\u91CD\u8FBA, \u68EE\u306B\u306F\u975E\u5BFE\u5FDC)\r\n\u30B0\
    \u30E9\u30D5\u306B\u306F\u5B64\u7ACB\u70B9\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u3068\u4EEE\u5B9A\u3059\u308B\r\n\r\n# \u89E3\u8AAC\r\n\u90E8\u5206\u6728\u30AF\
    \u30A8\u30EA\u306E\u51E6\u7406\r\n\t(i) \u9802\u70B9\u306B\u5024\u304C\u5B58\u5728\
    \u3059\u308B\u3068\u304D\r\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3001\
    in[u] \u306B\u9802\u70B9 u \u306E\u5024\u3092\u6301\u305F\u305B\u308B\u3002\r\n\
    \t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\u306F [in[u], out[u])\
    \ \u306E\u7DCF\u548C\r\n\t(ii) \u8FBA\u306B\u5024\u304C\u5B58\u5728\u3059\u308B\
    \u3068\u304D\r\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3001\u89AA p \u304B\
    \u3089\u306E\u8FBA\u306E\u5024\u3092 in[u] \u306B\u6301\u305F\u305B\u308B\u3002\
    \r\n\t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\u306F [in[u] + 1,\
    \ out[u]) \u306E\u7DCF\u548C\r\n\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u51E6\
    \u7406\r\n\t\u9802\u70B9\u306B\u5024\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306E\u307F\u8003\u3048\u308B(\u8FBA\u3082\u540C\u69D8)\r\n\t\u5404\u9802\u70B9\
    \ u \u306B\u5BFE\u3057\u3001\r\n\t\tin[u] \u306B\u9802\u70B9 u \u306E\u5024\r\n\
    \t\tout[u] \u306B\u9802\u70B9 u \u306E\u5024\u306E\u9006\u5143\r\n\t\u3092\u3082\
    \u305F\u305B\u308B\u3002\r\n\t\u8449\u3078\u4E0B\u308B\u65B9\u5411\u306B\u3057\
    \u304B\u8A08\u7B97\u3067\u304D\u306A\u3044\u305F\u3081\u3001lca \u3092\u6C42\u3081\
    \u3066 2 \u3064\u306E\u30D1\u30B9\u306B\u5206\u3051\u3066\u8A08\u7B97\u3059\u308B\
    \u3002\r\n\t\u3053\u306E\u3068\u304D\u3001\u53EF\u63DB\u3067\u306A\u3044\u5834\
    \u5408\u306F\u30D1\u30B9\u306E\u4E0A\u308A\u4E0B\u308A\u3067\u8A08\u7B97\u306E\
    \u4ED5\u65B9\u3092\u5DE5\u592B\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \r\n\r\n# \u4ED5\u69D8\r\nEulerTour(const Tree & tree, size_type root)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u6728 g, \u6839\u3092 root \u3068\u3057\
    \u3066 EulerTour \u3067\u756A\u53F7\u3092\u632F\u308B\r\n\t\u3053\u3053\u3067\u6E21\
    \u3057\u305F tree \u306E\u53C2\u7167\u5143\u306F\u5909\u66F4\u3057\u3066\u306F\
    \u3044\u3051\u306A\u3044\u3002\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5272\u308A\u632F\u3063\u305F\u8FBA\u306E\
    \u756A\u53F7\u306E\u7DCF\u6570(2n) \u3092\u8FD4\u3059\r\n\r\nsize_type par(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ in(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\
    \u70B9 k \u306B\u5165\u3063\u305F\u3068\u304D\u306E\u8FBA\u756A\u53F7(EulerTour\
    \ \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\u306E\u5834\u5408\u306F 0\r\n\
    \r\nsize_type out(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u9802\u70B9 k \u304B\u3089\u51FA\u305F\u3068\u304D\u306E\u8FBA\u756A\
    \u53F7(EulerTour \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\u306E\u5834\u5408\
    \u306F 2n\r\n\r\nstd::pair<size_type, size_type> par_from(size_type k) const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k \u306E\u89AA\
    \u304B\u3089\u9802\u70B9 k \u3078\u306E\u8FBA e \u306E\u60C5\u5831 ( {\u9802\u70B9\
    \ k \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7}, {tree \u4E0A\u306E\u8FBA e \u306E\
    \ index}) \u3092\u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[par[k]][e-index]\
    \ = k\r\n\tk \u304C\u6839\u306E\u5834\u5408\u306F (n, n)\r\n\r\nsize_type par_to(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u304B\u3089\u89AA\u3078\u306E\u8FBA e \u306E tree \u4E0A\u306E index \u3092\
    \u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[k][e-index] = par[k]\r\n\tk \u304C\
    \u6839\u3082\u3057\u304F\u306F tree \u304C\u9006\u8FBA\u3092\u6301\u3063\u3066\
    \u3044\u306A\u3044\u5834\u5408\u306F n\r\n\r\n# \u53C2\u8003\r\nhttps://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7,\
    \ 2020/09/16\r\nhttps://beet-aizu.hatenablog.com/entry/2019/07/08/174727, 2020/09/16\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\n\t\
    using Tree = std::vector<std::vector<size_type>>;\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tconst Tree & tree;\r\n\tsize_type root;\r\n\tstd::vector<size_type>\
    \ in_, out_;\r\n\tstd::vector<size_type> par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const\
    \ Tree & tree, size_type root) : n(tree.size()), tree(tree), root(root) {\r\n\t\
    \tin_.assign(size(), size());\r\n\t\tout_.assign(size(), size());\r\n\t\tpar_.assign(n,\
    \ n);\r\n\t\tg_idx.assign(size(), n);\r\n\t\t\r\n\t\tstd::stack<std::pair<size_type,\
    \ size_type>> stk;\r\n\t\tstd::vector<size_type> par_edge(n, n);\r\n\t\tsize_type\
    \ num = 0;\r\n\t\t\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root, 0);\r\n\t\
    \t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst size_type u = stk.top().first;\r\
    \n\t\t\tconst size_type i = stk.top().second;\r\n\t\t\tstk.pop();\r\n\t\t\t\r\n\
    \t\t\tif (i < tree[u].size()) {\r\n\t\t\t\tconst size_type v = tree[u][i];\r\n\
    \t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (v == par_[u]) par_edge[u] = i;\r\
    \n\t\t\t\telse {\r\n\t\t\t\t\tg_idx[num] = i;\r\n\t\t\t\t\tin_[v] = num++;\r\n\
    \t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\telse out_[u] = num++;\r\n\t\t}\r\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) g_idx[out_[i]] = par_edge[i];\r\n\t}\r\n\t\r\n\tsize_type size() const\
    \ noexcept { return n << 1; }\r\n\tsize_type par(size_type k) const { assert(k\
    \ < size()); return par_[k]; }\r\n\tsize_type in(size_type k) const { assert(k\
    \ < size()); return in_[k]; }\r\n\tsize_type out(size_type k) const { assert(k\
    \ < size()); return out_[k]; }\r\n\tstd::pair<size_type, size_type> par_from(size_type\
    \ k) const { assert(k < size()); return {par_[k], g_idx[in_[k]]}; }\r\n\tsize_type\
    \ par_to(size_type k) const { assert(k < size()); return g_idx[out_[k]]; }\r\n\
    };\r\n\r\n\n#line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/18\r\n\r\nmax_right: verified(https://atcoder.jp/contests/practice2/submissions/16664880)\r\
    \nmin_left: unverified\r\n\r\n# \u4ED5\u69D8\r\nSegmentTree()\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u306E\u30BB\u30B0\u6728\u3092\u4F5C\u6210\
    \r\n\t\u4F55\u304B\u64CD\u4F5C\u3092\u884C\u3063\u305F\u5834\u5408\u306E\u52D5\
    \u4F5C\u306F\u672A\u5B9A\u7FA9\r\n\r\nSegmentTree(size_type n, const_reference\
    \ id_elem, const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u8981\
    \u7D20\u6570 n, \u5358\u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3067\u521D\
    \u671F\u5316\r\n\r\nSegmentTree(std::vector<value_type> v, const_reference id_elem,\
    \ const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u914D\u5217\
    \ v \u3067\u521D\u671F\u5316\r\n\t\u4ED6\u306E\u5F15\u6570\u306B\u3064\u3044\u3066\
    \u306F\u4E0A\u8A18\u306E\u901A\u308A\r\n\r\nsize_type size() const noexcept\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\
    \u3059(\\neq \u5185\u90E8\u306E\u30CE\u30FC\u30C9\u6570)\r\n\r\nvoid set(size_type\
    \ i, const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\
    \ti \u756A\u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u306B x \u3092\u4EE3\u5165\r\
    \n\r\nconst_reference get(size_type i) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\ti \u756A\u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \r\n\r\nvalue_type fold(size_type l, size_type r) const\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\r\n\t[l, r) (0 \\leq l \\leq r \\leq n) \u3092 fold \u3057\
    \u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\tl = r \u306E\u3068\u304D\u306F id_elem\
    \ \u3092\u8FD4\u3059\r\n\r\nconst_reference fold_all() const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\tfold(0, n) \u306E\u7D50\u679C\u3092\u8FD4\u3059\
    \r\n\r\nsize_type max_right(size_type l, std::function<bool(const_reference)>\
    \ g) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t0 \\leq l \\leq\
    \ n\r\n\tg \u306F\u5358\u8ABF\u306A\u95A2\u6570\r\n\t\u6B21\u306E\u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\u8FD4\u3059\r\n\t\tl \\leq i \\\
    leq r \u3067\u306F g(fold(l, i)) = true\r\n\t\tg(fold(l, r + 1)) = false\r\n\t\
    g(fold(l, n)) = true \u306E\u3068\u304D\u306F r = n\r\n\r\nsize_type min_left(size_type\
    \ r, std::function<bool(const_reference)> g) const\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(log n)\r\n\t0 \\leq r \\leq n\r\n\tg \u306F\u5358\u8ABF\u306A\u95A2\u6570\
    \r\n\t\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5927\u306E l \u3092\
    \u8FD4\u3059\r\n\t\tl \\leq i \\leq r \u3067\u306F g(fold(i, r)) = true\r\n\t\t\
    g(fold(l - 1, r)) = false\r\n\tg(fold(0, r)) = true \u306E\u3068\u304D\u306F l\
    \ = 0\r\n\r\n# \u53C2\u8003\r\nhttps://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf,\
    \ 2020/04/08\r\nAC Library, 2020/09/13\r\n*/\r\n\r\n#line 70 \"DataStructure/SegmentTree.hpp\"\
    \n#include <algorithm>\r\n#line 72 \"DataStructure/SegmentTree.hpp\"\n#include\
    \ <functional>\r\n\r\ntemplate<typename T>\r\nstruct SegmentTree {\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tsize_type n, n_;\r\n\tvalue_type\
    \ id_elem;\r\n\tF f;\r\n\tstd::vector<value_type> node;\r\n\t\r\npublic:\r\n\t\
    SegmentTree() = default;\r\n\t\r\n\tSegmentTree(size_type n, const_reference id_elem,\
    \ const F & f) : n(n), id_elem(id_elem), f(f) {\r\n\t\tn_ = 1;\r\n\t\twhile (n_\
    \ < n) n_ <<= 1;\r\n\t\tnode.resize(2 * n_, id_elem);\r\n\t}\r\n\t\r\n\tSegmentTree(std::vector<value_type>\
    \ v, const_reference id_elem, const F & f) :\r\n\t\t\tSegmentTree(v.size(), id_elem,\
    \ f) {\r\n\t\tfor (size_type i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\
    \t\tfor (size_type i = n_ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i <<\
    \ 1 | 1]);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\
    \n\t}\r\n\t\r\n\tvoid set(size_type i, const_reference x) {\r\n\t\tassert(i <\
    \ size());\r\n\t\tnode[i += n_] = x;\r\n\t\twhile (i > 1) {\r\n\t\t\ti >>= 1;\r\
    \n\t\t\tnode[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\t\r\n\
    \tconst_reference get(size_type i) const {\r\n\t\tassert(i < size());\r\n\t\t\
    return node[i + n_];\r\n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tvalue_type\
    \ lv = id_elem, rv = id_elem;\r\n\t\tfor (l += n_, r += n_; l < r; l >>= 1, r\
    \ >>= 1) {\r\n\t\t\tif (l & 1) lv = f(lv, node[l++]);\r\n\t\t\tif (r & 1) rv =\
    \ f(node[r - 1], rv);\r\n\t\t}\r\n\t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tconst_reference\
    \ fold_all() const {\r\n\t\treturn node[1];\r\n\t}\r\n\t\r\n\tsize_type max_right(size_type\
    \ l, std::function<bool(const_reference)> g) const {\r\n\t\tassert(l <= size());\r\
    \n\t\tassert(g(id_elem));\r\n\t\tif (l == size()) return size();\r\n\t\tl += n_;\r\
    \n\t\tvalue_type sum = id_elem;\r\n\t\twhile (true) {\r\n\t\t\twhile (~l & 1)\
    \ l >>= 1;\r\n\t\t\tconst value_type nex_sum = f(sum, node[l]);\r\n\t\t\tif (g(nex_sum))\
    \ { sum = nex_sum; ++l; }\r\n\t\t\telse break;\r\n\t\t\tif ((l & -l) == l) return\
    \ size();\r\n\t\t}\r\n\t\twhile (l < n_) {\r\n\t\t\tconst value_type nex_sum =\
    \ f(sum, node[l << 1]);\r\n\t\t\tl <<= 1;\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum;\
    \ l |= 1; }\r\n\t\t}\r\n\t\treturn l - n_;\r\n\t}\r\n\t\r\n\tsize_type min_left(size_type\
    \ r, std::function<bool(const_reference)> g) const {\r\n\t\tassert(r <= size());\r\
    \n\t\tassert(g(id_elem));\r\n\t\tif (r == 0) return 0;\r\n\t\tr += n_;\r\n\t\t\
    value_type sum = id_elem;\r\n\t\twhile (true) {\r\n\t\t\t--r;\r\n\t\t\twhile (r\
    \ > 1 && (r & 1)) r >>= 1;\r\n\t\t\tconst value_type nex_sum = f(node[r], sum);\r\
    \n\t\t\tif (g(nex_sum)) sum = nex_sum;\r\n\t\t\telse break;\r\n\t\t\tif ((r &\
    \ -r) == r) return 0;\r\n\t\t}\r\n\t\twhile (r < n_) {\r\n\t\t\tconst value_type\
    \ nex_sum = f(node[r << 1 | 1], sum);\r\n\t\t\tr <<= 1;\r\n\t\t\tif (!g(nex_sum))\
    \ r |= 1;\r\n\t\t\telse sum = nex_sum;\r\n\t\t}\r\n\t\treturn r + 1 - n_;\r\n\t\
    }\r\n};\r\n\r\n\n#line 5 \"Test/EulerTour.test.cpp\"\n\r\n#line 7 \"Test/EulerTour.test.cpp\"\
    \n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N,\
    \ &Q);\r\n\t\r\n\tusing ll = long long;\r\n\tstd::vector<ll> A(N);\r\n\tEulerTour::Tree\
    \ g(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%lld\", &A[i]);\r\n\tfor (int\
    \ i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\t// par[i]\
    \ = p;\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\t\r\n\tEulerTour et(g, 0);\r\n\t\
    \r\n\tstd::vector<ll> tv(et.size());\r\n\tfor (int i = 0; i < N; ++i) tv[et.in(i)]\
    \ = A[i];\r\n\tSegmentTree<ll> seg(tv, 0, [](ll x, ll y) { return x + y; });\r\
    \n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\tif (q ==\
    \ 0) {\r\n\t\t\tint u, x;\r\n\t\t\tscanf(\"%d %d\", &u, &x);\r\n\t\t\tint idx\
    \ = et.in(u);\r\n\t\t\tseg.set(idx, seg.get(idx) + x);\r\n\t\t}\r\n\t\telse {\r\
    \n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\t\t\tprintf(\"%ld\\n\", seg.fold(et.in(u),\
    \ et.out(u)));\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#include \"GraphTheory/EulerTour.hpp\"\r\n#include \"DataStructure/SegmentTree.hpp\"\
    \r\n\r\n#include <vector>\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing ll = long long;\r\n\tstd::vector<ll>\
    \ A(N);\r\n\tEulerTour::Tree g(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%lld\"\
    , &A[i]);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\"\
    , &p);\r\n\t\t// par[i] = p;\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\t\r\n\tEulerTour\
    \ et(g, 0);\r\n\t\r\n\tstd::vector<ll> tv(et.size());\r\n\tfor (int i = 0; i <\
    \ N; ++i) tv[et.in(i)] = A[i];\r\n\tSegmentTree<ll> seg(tv, 0, [](ll x, ll y)\
    \ { return x + y; });\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\"\
    , &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint u, x;\r\n\t\t\tscanf(\"%d %d\", &u, &x);\r\
    \n\t\t\tint idx = et.in(u);\r\n\t\t\tseg.set(idx, seg.get(idx) + x);\r\n\t\t}\r\
    \n\t\telse {\r\n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\t\t\tprintf(\"%ld\\\
    n\", seg.fold(et.in(u), et.out(u)));\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/EulerTour.hpp
  - DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: Test/EulerTour.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:14:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/EulerTour.test.cpp
layout: document
redirect_from:
- /verify/Test/EulerTour.test.cpp
- /verify/Test/EulerTour.test.cpp.html
title: Test/EulerTour.test.cpp
---
