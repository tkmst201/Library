---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LazySegmentTree.test.cpp
    title: Test/LazySegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://beet-aizu.hatenablog.com/entry/2017/12/01/225955,
    - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html,
    - https://smijake3.hatenablog.com/entry/2018/11/03/100133,
  bundledCode: "#line 1 \"DataStructure/LazySegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/16\r\n\r\n\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \r\n\r\nTODO: \u4E00\u822C\u5316\u3055\u308C\u305F\u4E8C\u5206\u63A2\u7D22\u306E\
    \u8FFD\u52A0(verify \u7528\u554F\u984C is \u3069\u3053)\r\n\r\n# \u4ED5\u69D8\r\
    \nLazySegmentTree(\r\n\tsize_type n, const value_type & id_node, const lazy_type\
    \ & id_lazy,\r\n\tconst F & f, const G & g, const H & h, const P & p = [](const\
    \ lazy_type & a, size_type l) { return a; })\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(n)\r\n\t\u8981\u7D20\u3001\u4F5C\u7528\u7D20\u306E\u5358\u4F4D\u5143\u3092\
    \u305D\u308C\u305E\u308C id_node, id_lazy \u3068\u3057\u3001{n_ \u4EE5\u4E0A\u306E\
    \u6700\u5C0F\u306E 2 \u51AA} \u500B\u306E\u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\
    \r\n\t\r\n\t\u95A2\u6570 f, g, h, p \u306F\u305D\u308C\u305E\u308C\r\n\t\tf: \u8981\
    \u7D20\u306E merge\r\n\t\tg: \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u4F5C\u7528\
    \r\n\t\th: \u4F5C\u7528\u7D20\u306E merge\r\n\t\tp: \u533A\u9593\u3078\u306E\u4F5C\
    \u7528\u304C\u305D\u306E\u533A\u9593\u306E\u5927\u304D\u3055(k) \u306B\u6BD4\u4F8B\
    \u3057\u3066\u5909\u5316\u3059\u308B\u3068\u304D p(a, k) := g(a, a, \\ldots, a)\
    \ (k \u500B)\r\n\t\u3092\u8868\u3059\r\n\t\r\n\tg, h, p \u306B\u95A2\u3057\u3066\
    \u306F\u5FC5\u305A\u4F1D\u642C\u3059\u308B\u5024\u304C\u5B58\u5728\u3059\u308B\
    \u3068\u304D(id_lazy \u3067\u306F\u306A\u3044) \u3068\u304D\u306E\u307F\u547C\u3070\
    \u308C\u308B\u3002\r\n\t\r\n\t\u3053\u308C\u3089\u306E\u95A2\u6570\u304C\u6E80\
    \u305F\u3059\u3079\u304D\u6027\u8CEA\u306F\u53C2\u8003\u6B04\u306E\u30EA\u30F3\
    \u30AF\u5148\u3092\u53C2\u7167\r\n\r\nLazySegmentTree(const std::vector<value_type>\
    \ & v, const value_type & id_elem, const F & f, const G & g, const H & h, const\
    \ P & p = [](const lazy_type & a, size_type l) { return a; })\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u914D\u5217 v \u3067\u521D\u671F\u5316\r\n\
    \t\u4ED6\u306E\u5F15\u6570\u306B\u3064\u3044\u3066\u306F\u4E0A\u8FF0\u306E\u901A\
    \u308A\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u8981\u7D20\u6570 n \u3092\u8FD4\u3059(\\neq \u5185\u90E8\u306E\
    \u8981\u7D20\u6570)\r\n\r\nvoid set(size_type k, const_reference x)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tk \u756A\u76EE(0 \\leq k < n) \u306E\u8981\
    \u7D20\u306B x \u3092\u4EE3\u5165\u3059\u308B\r\n\tTODO: verify LazySegmentTree\
    \ set()\r\n\r\nvalue_type get(size_type k)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\tk \u756A\u76EE(0 \\leq k < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \r\n\tTODO: verify LazySegmentTree get()\r\n\r\nvoid update(size_type l, size_type\
    \ r, const lazy_type & x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\
    [l, r) \u5185(0 \\leq l \\leq r \\leq n) \u306E\u8981\u7D20\u306B x \u3092\u4F5C\
    \u7528\u3055\u305B\u308B(\u9045\u5EF6)\r\n\tl = r \u306E\u3068\u304D\u306F\u4F55\
    \u3082\u3057\u306A\u3044\r\n\r\nvalue_type fold(size_type l, size_type r)\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t[l, r) \u5185(0 \\leq l \\leq r\
    \ \\leq n) \u306E\u5404\u8981\u7D20\u306B\u3064\u3044\u3066 fold \u6F14\u7B97\u3057\
    \u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\tl = r \u306E\u3068\u304D\u306F\u5358\
    \u4F4D\u5143\u3092\u8FD4\u3059\r\n\r\nvalue_type fold_all() const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\tfold(0, n) \u3092\u8FD4\u3059\r\n\tTODO: verify\
    \ LazySegmentTree fold_all()\r\n\r\nprivate:\r\nvalue_type reflect(size_type k,\
    \ size_type w)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CE\u30FC\
    \u30C9 k (\u5BFE\u5FDC\u3059\u308B\u533A\u9593\u306E\u5927\u304D\u3055\u3092 w)\
    \ \u306B\u4F5C\u7528\u7D20\u3092\u4F5C\u7528\u3055\u305B\u305F\u5F8C\u306E\u5024\
    \u3092\u8FD4\u3059\r\n\r\nvoid propagate(size_type k, size_type w)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CE\u30FC\u30C9 k (\u5BFE\u5FDC\u3059\
    \u308B\u533A\u9593\u306E\u5927\u304D\u3055\u3092 w) \u306E\u5B50\u306B\u4F5C\u7528\
    \u7D20\u3092\u4F1D\u642C\u3057\u3001\u81EA\u8EAB\u306B\u4F5C\u7528\u3055\u305B\
    \u3066\u66F4\u65B0\r\n\r\nvoid recalc(size_type k)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(log n)\r\n\t\u8981\u7D20 k \u306E\u5148\u7956\u304C\u4F1D\u642C\
    \u6E08\u307F\u3060\u3068\u4EEE\u5B9A\u3057\u3066\u5148\u7956\u306E\u5024\u3092\
    \u518D\u8A08\u7B97\u3059\u308B\r\n\t\u8981\u7D20 k \u306E\u5024\u306F\u5909\u5316\
    \u3057\u306A\u3044\r\n\r\nvoid thrust(size_type k)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(log n)\r\n\t\u6839\u304B\u3089\u8981\u7D20 k \u307E\u3067\u4F5C\
    \u7528\u3092\u4F1D\u642C\u3057\u3066\u304F\u308B\r\n\t\u8981\u7D20 k \u306E\u5024\
    \u306F\u5909\u5316\u3057\u306A\u3044\r\n\r\n# \u53C2\u8003\r\nhttps://beet-aizu.hatenablog.com/entry/2017/12/01/225955,\
    \ 2020/09/11\r\nhttps://smijake3.hatenablog.com/entry/2018/11/03/100133, 2020/09/16\r\
    \nhttps://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html, 2020/09/16\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\
    \n\r\ntemplate<typename T, typename E>\r\nstruct LazySegmentTree {\r\n\tusing\
    \ value_type = T;\r\n\tusing lazy_type = E;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing F = std::function<value_type(const value_type &, const value_type &)>;\
    \ // \u8981\u7D20\u306E merge\r\n\tusing G = std::function<value_type(const value_type\
    \ &, const lazy_type &)>; // \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u4F5C\u7528\
    \r\n\tusing H = std::function<lazy_type(const lazy_type &, const lazy_type &)>;\
    \ // \u4F5C\u7528\u7D20\u306E merge\r\n\tusing P = std::function<lazy_type(const\
    \ lazy_type &, size_type)>; // \u533A\u9593\u3078\u306E\u4F5C\u7528\u304C\u305D\
    \u306E\u533A\u9593\u306E\u5927\u304D\u3055(k) \u306B\u6BD4\u4F8B\u3057\u3066\u5909\
    \u5316\u3059\u308B\u3068\u304D p(a, k) := g(a, a, ..., a) (k \u500B)\r\n\t\r\n\
    private:\r\n\tsize_type n, n_, n_log;\r\n\tvalue_type id_node;\r\n\tlazy_type\
    \ id_lazy;\r\n\tF f;\r\n\tG g;\r\n\tH h;\r\n\tP p;\r\n\tstd::vector<value_type>\
    \ node;\r\n\tstd::vector<lazy_type> lazy;\r\n\r\npublic:\r\n\tLazySegmentTree(size_type\
    \ n, const value_type & id_node, const lazy_type & id_lazy, const F & f, const\
    \ G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return\
    \ a; })\r\n\t\t\t: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h),\
    \ p(p) {\r\n\t\tn_ = 1;\r\n\t\tn_log = 0;\r\n\t\twhile (n_ < n) n_ <<= 1, ++n_log;\r\
    \n\t\tnode.resize(2 * n_, id_node);\r\n\t\tlazy.resize(2 * n_, id_lazy);\r\n\t\
    }\r\n\t\r\n\tLazySegmentTree(const std::vector<value_type> & v, const value_type\
    \ & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h,\
    \ const P & p = [](const lazy_type & a, size_type l) { return a; })\r\n\t\t\t\
    : LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type k, const value_type & x) {\r\n\t\tassert(k < size());\r\n\t\t\
    k += n_;\r\n\t\tthrust(k);\r\n\t\tnode[k] = x;\r\n\t\tlazy[k] = id_lazy;\r\n\t\
    \trecalc(k);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type k) {\r\n\t\tassert(k <\
    \ size());\r\n\t\tk += n_;\r\n\t\tthrust(k);\r\n\t\treturn reflect(k, 1);\r\n\t\
    }\r\n\t\r\n\tvoid update(size_type l, size_type r, const lazy_type & x) {\r\n\t\
    \tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif (l == r) return;\r\n\t\
    \tl += n_;\r\n\t\tr += n_;\r\n\t\tthrust(l);\r\n\t\tthrust(r - 1);\r\n\t\tfor(size_type\
    \ cl = l, cr = r; cl < cr; cl >>= 1, cr >>= 1) {\r\n\t\t\tif (cl & 1) lazy[cl]\
    \ = h(lazy[cl], x), ++cl;\r\n\t\t\tif (cr & 1) --cr, lazy[cr] = h(lazy[cr], x);\r\
    \n\t\t}\r\n\t\trecalc(l);\r\n\t\trecalc(r - 1);\r\n\t\treturn;\r\n\t}\r\n\t\r\n\
    \tvalue_type fold(size_type l, size_type r) {\r\n\t\tassert(l <= r);\r\n\t\tassert(r\
    \ <= size());\r\n\t\tif (l == r) return id_node;\r\n\t\tl += n_;\r\n\t\tr += n_;\r\
    \n\t\tthrust(l);\r\n\t\tthrust(r - 1);\r\n\t\tvalue_type vl = id_node, vr = id_node;\r\
    \n\t\tfor (size_type w = 1; l < r; l >>= 1, r >>= 1, w <<= 1) {\r\n\t\t\tif (l\
    \ & 1) vl = f(vl, reflect(l, w)), ++l;\r\n\t\t\tif (r & 1) --r, vr = f(reflect(r,\
    \ w), vr);\r\n\t\t}\r\n\t\treturn f(vl, vr);\r\n\t}\r\n\t\r\n\tvalue_type fold_all()\
    \ const {\r\n\t\treturn node[1];\r\n\t}\r\n\t\r\nprivate:\r\n\tvalue_type reflect(size_type\
    \ k, size_type w) {\r\n\t\treturn lazy[k] == id_lazy ? node[k] : g(node[k], p(lazy[k],\
    \ w));\r\n\t}\r\n\t\r\n\tvoid propagate(size_type k, size_type w) {\r\n\t\tif\
    \ (lazy[k] == id_lazy) return;\r\n\t\tif ((k << 1 | 1) < node.size()) {\r\n\t\t\
    \tlazy[k << 1] = h(lazy[k << 1], lazy[k]);\r\n\t\t\tlazy[k << 1 | 1] = h(lazy[k\
    \ << 1 | 1], lazy[k]);\r\n\t\t}\r\n\t\tnode[k] = reflect(k, w); // g(node[k],\
    \ p(lazy[k], l));\r\n\t\tlazy[k] = id_lazy;\r\n\t}\r\n\t\r\n\tvoid recalc(size_type\
    \ k) {\r\n\t\tfor (size_type i = k >> 1, cw = 1; i > 0; i >>= 1, cw <<= 1)\r\n\
    \t\t\tnode[i] = f(reflect(i << 1, cw), reflect(i << 1 | 1, cw));\r\n\t}\r\n\t\r\
    \n\tvoid thrust(size_type k) {\r\n\t\tfor (size_type i = n_log, w = n_; i > 0;\
    \ --i, w >>= 1) propagate(k >> i, w);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP\r\n#define INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/16\r\n\r\n\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\r\n\r\nTODO: \u4E00\u822C\u5316\u3055\u308C\u305F\u4E8C\
    \u5206\u63A2\u7D22\u306E\u8FFD\u52A0(verify \u7528\u554F\u984C is \u3069\u3053\
    )\r\n\r\n# \u4ED5\u69D8\r\nLazySegmentTree(\r\n\tsize_type n, const value_type\
    \ & id_node, const lazy_type & id_lazy,\r\n\tconst F & f, const G & g, const H\
    \ & h, const P & p = [](const lazy_type & a, size_type l) { return a; })\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u8981\u7D20\u3001\u4F5C\u7528\u7D20\
    \u306E\u5358\u4F4D\u5143\u3092\u305D\u308C\u305E\u308C id_node, id_lazy \u3068\
    \u3057\u3001{n_ \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA} \u500B\u306E\u5358\
    \u4F4D\u5143\u3067\u521D\u671F\u5316\r\n\t\r\n\t\u95A2\u6570 f, g, h, p \u306F\
    \u305D\u308C\u305E\u308C\r\n\t\tf: \u8981\u7D20\u306E merge\r\n\t\tg: \u8981\u7D20\
    \u306B\u4F5C\u7528\u7D20\u3092\u4F5C\u7528\r\n\t\th: \u4F5C\u7528\u7D20\u306E\
    \ merge\r\n\t\tp: \u533A\u9593\u3078\u306E\u4F5C\u7528\u304C\u305D\u306E\u533A\
    \u9593\u306E\u5927\u304D\u3055(k) \u306B\u6BD4\u4F8B\u3057\u3066\u5909\u5316\u3059\
    \u308B\u3068\u304D p(a, k) := g(a, a, \\ldots, a) (k \u500B)\r\n\t\u3092\u8868\
    \u3059\r\n\t\r\n\tg, h, p \u306B\u95A2\u3057\u3066\u306F\u5FC5\u305A\u4F1D\u642C\
    \u3059\u308B\u5024\u304C\u5B58\u5728\u3059\u308B\u3068\u304D(id_lazy \u3067\u306F\
    \u306A\u3044) \u3068\u304D\u306E\u307F\u547C\u3070\u308C\u308B\u3002\r\n\t\r\n\
    \t\u3053\u308C\u3089\u306E\u95A2\u6570\u304C\u6E80\u305F\u3059\u3079\u304D\u6027\
    \u8CEA\u306F\u53C2\u8003\u6B04\u306E\u30EA\u30F3\u30AF\u5148\u3092\u53C2\u7167\
    \r\n\r\nLazySegmentTree(const std::vector<value_type> & v, const value_type &\
    \ id_elem, const F & f, const G & g, const H & h, const P & p = [](const lazy_type\
    \ & a, size_type l) { return a; })\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (n)\r\n\t\u914D\u5217 v \u3067\u521D\u671F\u5316\r\n\t\u4ED6\u306E\u5F15\u6570\
    \u306B\u3064\u3044\u3066\u306F\u4E0A\u8FF0\u306E\u901A\u308A\r\n\r\nsize_type\
    \ size() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\
    \u7D20\u6570 n \u3092\u8FD4\u3059(\\neq \u5185\u90E8\u306E\u8981\u7D20\u6570)\r\
    \n\r\nvoid set(size_type k, const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\tk \u756A\u76EE(0 \\leq k < n) \u306E\u8981\u7D20\u306B x \u3092\
    \u4EE3\u5165\u3059\u308B\r\n\tTODO: verify LazySegmentTree set()\r\n\r\nvalue_type\
    \ get(size_type k)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tk \u756A\
    \u76EE(0 \\leq k < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\tTODO: verify LazySegmentTree\
    \ get()\r\n\r\nvoid update(size_type l, size_type r, const lazy_type & x)\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t[l, r) \u5185(0 \\leq l \\leq r\
    \ \\leq n) \u306E\u8981\u7D20\u306B x \u3092\u4F5C\u7528\u3055\u305B\u308B(\u9045\
    \u5EF6)\r\n\tl = r \u306E\u3068\u304D\u306F\u4F55\u3082\u3057\u306A\u3044\r\n\r\
    \nvalue_type fold(size_type l, size_type r)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\t[l, r) \u5185(0 \\leq l \\leq r \\leq n) \u306E\u5404\u8981\u7D20\
    \u306B\u3064\u3044\u3066 fold \u6F14\u7B97\u3057\u305F\u7D50\u679C\u3092\u8FD4\
    \u3059\r\n\tl = r \u306E\u3068\u304D\u306F\u5358\u4F4D\u5143\u3092\u8FD4\u3059\
    \r\n\r\nvalue_type fold_all() const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\tfold(0, n) \u3092\u8FD4\u3059\r\n\tTODO: verify LazySegmentTree fold_all()\r\
    \n\r\nprivate:\r\nvalue_type reflect(size_type k, size_type w)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CE\u30FC\u30C9 k (\u5BFE\u5FDC\u3059\u308B\
    \u533A\u9593\u306E\u5927\u304D\u3055\u3092 w) \u306B\u4F5C\u7528\u7D20\u3092\u4F5C\
    \u7528\u3055\u305B\u305F\u5F8C\u306E\u5024\u3092\u8FD4\u3059\r\n\r\nvoid propagate(size_type\
    \ k, size_type w)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CE\u30FC\
    \u30C9 k (\u5BFE\u5FDC\u3059\u308B\u533A\u9593\u306E\u5927\u304D\u3055\u3092 w)\
    \ \u306E\u5B50\u306B\u4F5C\u7528\u7D20\u3092\u4F1D\u642C\u3057\u3001\u81EA\u8EAB\
    \u306B\u4F5C\u7528\u3055\u305B\u3066\u66F4\u65B0\r\n\r\nvoid recalc(size_type\
    \ k)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20 k \u306E\
    \u5148\u7956\u304C\u4F1D\u642C\u6E08\u307F\u3060\u3068\u4EEE\u5B9A\u3057\u3066\
    \u5148\u7956\u306E\u5024\u3092\u518D\u8A08\u7B97\u3059\u308B\r\n\t\u8981\u7D20\
    \ k \u306E\u5024\u306F\u5909\u5316\u3057\u306A\u3044\r\n\r\nvoid thrust(size_type\
    \ k)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u6839\u304B\u3089\
    \u8981\u7D20 k \u307E\u3067\u4F5C\u7528\u3092\u4F1D\u642C\u3057\u3066\u304F\u308B\
    \r\n\t\u8981\u7D20 k \u306E\u5024\u306F\u5909\u5316\u3057\u306A\u3044\r\n\r\n\
    # \u53C2\u8003\r\nhttps://beet-aizu.hatenablog.com/entry/2017/12/01/225955, 2020/09/11\r\
    \nhttps://smijake3.hatenablog.com/entry/2018/11/03/100133, 2020/09/16\r\nhttps://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html,\
    \ 2020/09/16\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T, typename E>\r\nstruct LazySegmentTree\
    \ {\r\n\tusing value_type = T;\r\n\tusing lazy_type = E;\r\n\tusing size_type\
    \ = std::size_t;\r\n\tusing F = std::function<value_type(const value_type &, const\
    \ value_type &)>; // \u8981\u7D20\u306E merge\r\n\tusing G = std::function<value_type(const\
    \ value_type &, const lazy_type &)>; // \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\
    \u4F5C\u7528\r\n\tusing H = std::function<lazy_type(const lazy_type &, const lazy_type\
    \ &)>; // \u4F5C\u7528\u7D20\u306E merge\r\n\tusing P = std::function<lazy_type(const\
    \ lazy_type &, size_type)>; // \u533A\u9593\u3078\u306E\u4F5C\u7528\u304C\u305D\
    \u306E\u533A\u9593\u306E\u5927\u304D\u3055(k) \u306B\u6BD4\u4F8B\u3057\u3066\u5909\
    \u5316\u3059\u308B\u3068\u304D p(a, k) := g(a, a, ..., a) (k \u500B)\r\n\t\r\n\
    private:\r\n\tsize_type n, n_, n_log;\r\n\tvalue_type id_node;\r\n\tlazy_type\
    \ id_lazy;\r\n\tF f;\r\n\tG g;\r\n\tH h;\r\n\tP p;\r\n\tstd::vector<value_type>\
    \ node;\r\n\tstd::vector<lazy_type> lazy;\r\n\r\npublic:\r\n\tLazySegmentTree(size_type\
    \ n, const value_type & id_node, const lazy_type & id_lazy, const F & f, const\
    \ G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return\
    \ a; })\r\n\t\t\t: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h),\
    \ p(p) {\r\n\t\tn_ = 1;\r\n\t\tn_log = 0;\r\n\t\twhile (n_ < n) n_ <<= 1, ++n_log;\r\
    \n\t\tnode.resize(2 * n_, id_node);\r\n\t\tlazy.resize(2 * n_, id_lazy);\r\n\t\
    }\r\n\t\r\n\tLazySegmentTree(const std::vector<value_type> & v, const value_type\
    \ & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h,\
    \ const P & p = [](const lazy_type & a, size_type l) { return a; })\r\n\t\t\t\
    : LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type k, const value_type & x) {\r\n\t\tassert(k < size());\r\n\t\t\
    k += n_;\r\n\t\tthrust(k);\r\n\t\tnode[k] = x;\r\n\t\tlazy[k] = id_lazy;\r\n\t\
    \trecalc(k);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type k) {\r\n\t\tassert(k <\
    \ size());\r\n\t\tk += n_;\r\n\t\tthrust(k);\r\n\t\treturn reflect(k, 1);\r\n\t\
    }\r\n\t\r\n\tvoid update(size_type l, size_type r, const lazy_type & x) {\r\n\t\
    \tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif (l == r) return;\r\n\t\
    \tl += n_;\r\n\t\tr += n_;\r\n\t\tthrust(l);\r\n\t\tthrust(r - 1);\r\n\t\tfor(size_type\
    \ cl = l, cr = r; cl < cr; cl >>= 1, cr >>= 1) {\r\n\t\t\tif (cl & 1) lazy[cl]\
    \ = h(lazy[cl], x), ++cl;\r\n\t\t\tif (cr & 1) --cr, lazy[cr] = h(lazy[cr], x);\r\
    \n\t\t}\r\n\t\trecalc(l);\r\n\t\trecalc(r - 1);\r\n\t\treturn;\r\n\t}\r\n\t\r\n\
    \tvalue_type fold(size_type l, size_type r) {\r\n\t\tassert(l <= r);\r\n\t\tassert(r\
    \ <= size());\r\n\t\tif (l == r) return id_node;\r\n\t\tl += n_;\r\n\t\tr += n_;\r\
    \n\t\tthrust(l);\r\n\t\tthrust(r - 1);\r\n\t\tvalue_type vl = id_node, vr = id_node;\r\
    \n\t\tfor (size_type w = 1; l < r; l >>= 1, r >>= 1, w <<= 1) {\r\n\t\t\tif (l\
    \ & 1) vl = f(vl, reflect(l, w)), ++l;\r\n\t\t\tif (r & 1) --r, vr = f(reflect(r,\
    \ w), vr);\r\n\t\t}\r\n\t\treturn f(vl, vr);\r\n\t}\r\n\t\r\n\tvalue_type fold_all()\
    \ const {\r\n\t\treturn node[1];\r\n\t}\r\n\t\r\nprivate:\r\n\tvalue_type reflect(size_type\
    \ k, size_type w) {\r\n\t\treturn lazy[k] == id_lazy ? node[k] : g(node[k], p(lazy[k],\
    \ w));\r\n\t}\r\n\t\r\n\tvoid propagate(size_type k, size_type w) {\r\n\t\tif\
    \ (lazy[k] == id_lazy) return;\r\n\t\tif ((k << 1 | 1) < node.size()) {\r\n\t\t\
    \tlazy[k << 1] = h(lazy[k << 1], lazy[k]);\r\n\t\t\tlazy[k << 1 | 1] = h(lazy[k\
    \ << 1 | 1], lazy[k]);\r\n\t\t}\r\n\t\tnode[k] = reflect(k, w); // g(node[k],\
    \ p(lazy[k], l));\r\n\t\tlazy[k] = id_lazy;\r\n\t}\r\n\t\r\n\tvoid recalc(size_type\
    \ k) {\r\n\t\tfor (size_type i = k >> 1, cw = 1; i > 0; i >>= 1, cw <<= 1)\r\n\
    \t\t\tnode[i] = f(reflect(i << 1, cw), reflect(i << 1 | 1, cw));\r\n\t}\r\n\t\r\
    \n\tvoid thrust(size_type k) {\r\n\t\tfor (size_type i = n_log, w = n_; i > 0;\
    \ --i, w >>= 1) propagate(k >> i, w);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2020-09-16 10:53:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LazySegmentTree.test.cpp
documentation_of: DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.hpp
- /library/DataStructure/LazySegmentTree.hpp.html
title: DataStructure/LazySegmentTree.hpp
---
