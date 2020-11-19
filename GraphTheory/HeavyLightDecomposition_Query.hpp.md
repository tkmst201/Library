---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc133/submissions/16817431
  bundledCode: "#line 1 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\n\n\n\r\n\
    /*\r\nlast-updated: 2020/09/18\r\n\r\n\u68EE\u4E0A\u3067 1 \u70B9\u66F4\u65B0\
    , \u30D1\u30B9\u30AF\u30A8\u30EA\u3084\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u3092\
    \ HL \u5206\u89E3\u3092\u7528\u3044\u3066\u89E3\u3044\u3066\u304F\u308C\u308B\u4FBF\
    \u5229\u30C7\u30FC\u30BF\u69CB\u9020\r\n\u9802\u70B9\u5C5E\u6027(\u9802\u70B9\u306B\
    \u5024\u3092\u6301\u3064), \u8FBA\u5C5E\u6027(\u8FBA\u306B\u5024\u3092\u6301\u3064\
    ) \u3069\u3061\u3089\u306B\u3082\u5BFE\u5FDC\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u306E\u5834\u5408\u3001\u6F14\u7B97\u304C\u975E\u53EF\u63DB\u3067\u3082 ok (\u30BB\
    \u30B0\u6728\u3082\u975E\u53EF\u63DB\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    \u5FC5\u8981\u304C\u3042\u308B)\r\n\r\n\u30D1\u30B9\u66F4\u65B0\u306E\u5834\u5408\
    \u306F\u5C11\u3057\u5909\u66F4\u3059\u308B\u3053\u3068\u3067 LazySegmentTree \u3092\
    \u7528\u3044\u3066\u89E3\u3051\u308B(\u30CF\u30BA)\r\n\r\n# \u4ED5\u69D8\r\n\u6B21\
    \u306E\u8A08\u7B97\u91CF\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\r\n- HeavyLightDecomposition\
    \ \u306E\u69CB\u7BC9\u3092 \u0398(n)\r\n- \u5024\u306E\u6F14\u7B97\u3092 \u0398\
    (1)\r\n- SegmentTree:\r\n-- \u521D\u671F\u5024\u6307\u5B9A\u521D\u671F\u5316:\
    \ \u0398(n)\r\n-- set, fold: O(log n)\r\n-- get \u304C \u0398(1)\r\n\r\ntemplate\
    \ \u5F15\u6570:\r\n\tclass HLD: HeavyLightDecomposition(Library \u5185\u306E lca\
    \ \u95A2\u9023\u3092\u9664\u304F\u6A5F\u80FD\u3092\u8981\u6C42)\r\n\ttypename\
    \ T: \u6271\u3046\u5024\u306E\u578B\r\n\ttemplate<typename> class SEG>: T \u3092\
    \ template \u5F15\u6570\u306B\u6301\u3064 SegmentTree(set, get, fold \u3092\u8981\
    \u6C42)\r\n\r\nHeavyLightDecomposition_Query(\r\n\tconst Graph & g: \u30B0\u30E9\
    \u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\u304C\u6728\u3067\u3042\u308B\u3068\
    \u304D\u3001\u305D\u306E\u6839(\u7701\u7565\u53EF)\r\n\tconst value_type & id_elem:\
    \ \u5358\u4F4D\u5143\r\n\tconst F & f : \u4E8C\u9805\u6F14\u7B97\r\n\tbool value_on_vertex\
    \ : \u9802\u70B9\u5C5E\u6027\u304B\u3069\u3046\u304B(true - \u9802\u70B9\u5C5E\
    \u6027, false - \u8FBA\u5C5E\u6027) )\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (n)\r\n\t\u30B0\u30E9\u30D5 g \u3092 HL \u5206\u89E3\u3057\u3001\u5404(\u9802\u70B9\
    \ or \u8FBA) \u306E\u5024\u3092\u5358\u4F4D\u5143 id_elem \u3067\u521D\u671F\u5316\
    \r\n\r\ntemplate<typename U>\r\nHeavyLightDecomposition_Query(\r\n\tconst Graph\
    \ & g: \u30B0\u30E9\u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\u304C\u6728\u3067\
    \u3042\u308B\u3068\u304D\u3001\u305D\u306E\u6839(\u7701\u7565\u53EF)\r\n\tconst\
    \ std::vector<U> & v: \u5404\u9802\u70B9\u306E\u5024\u306E\u521D\u671F\u5024\r\
    \n\tconst value_type & id_elem: \u5358\u4F4D\u5143\r\n\tconst F & f : \u4E8C\u9805\
    \u6F14\u7B97 )\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B0\u30E9\
    \u30D5 g \u3092 HL \u5206\u89E3\u3057\u3001\u5168\u3066\u306E\u9802\u70B9\u306E\
    \u5024\u3092 v \u3067\u521D\u671F\u5316\u3059\u308B\r\n\t\u8FBA\u5C5E\u6027\u306E\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u521D\u671F\u5316\u306B\u306F\u5BFE\
    \u5FDC\u3057\u3066\u3044\u306A\u3044\r\n\r\nconst hld_type & get_hld() const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5185\u90E8\u3067\u6271\u3063\
    \u3066\u3044\u308B HeavyLightDecomposition \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\
    \u3092\u8FD4\u3059\r\n\r\n- \u9802\u70B9\u5C5E\u6027\r\n\tvoid set(size_type v,\
    \ const_reference x)\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\t\u9802\
    \u70B9 v \u306E\u5024\u3092 x \u306B\u5909\u66F4\u3059\u308B\r\n\r\n\tvalue_type\
    \ get(size_type v) const\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \t\u9802\u70B9 v \u306E\u5024\u3092\u8FD4\u3059\r\n\r\n- \u8FBA\u5C5E\u6027\r\n\
    \tvoid set(size_type u, size_type v, const_reference x)\r\n\t\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\r\n\t\t\u8FBA u-v \u306E\u5024\u3092 x \u306B\u5909\u66F4\
    \u3059\u308B\r\n\r\n\tvalue_type get(size_type u, size_type v) const\r\n\t\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\t\u8FBA u-v \u306E\u5024\u3092\u8FD4\
    \u3059\r\n\r\nvalue_type fold(size_type u, size_type v) const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O((log n)^2)\r\n\t\u9802\u70B9\u5C5E\u6027\u306E\u5834\u5408\
    \u306F u-v \u30D1\u30B9\u4E0A\u306E\u9802\u70B9(\u7AEF\u70B9\u542B\u3080)\u306E\
    \u5024\u306E fold \u3057\u305F\u5024\u3092\u8FD4\u3059\r\n\t\u8FBA\u5C5E\u6027\
    \u306E\u5834\u5408\u306F u-v \u30D1\u30B9\u4E0A\u306E\u8FBA\u306E\u5024\u306E\
    \ fold \u3057\u305F\u5024\u3092\u8FD4\u3059\r\n\r\nvalue_type subtree_sum(size_type\
    \ v) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u9802\u70B9 v \u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u5185\u306E\u5024\u306E\u5408\u8A08\
    \u3092\u6C42\u3081\u308B\r\n\r\n# \u53C2\u8003\r\n\u8FBA\u5C5E\u6027 verify(2020/09/18):\
    \ https://atcoder.jp/contests/abc133/submissions/16817431\r\n*/\r\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <functional>\r\n#include <utility>\r\
    \n#include <algorithm>\r\n#include <cstdint>\r\n\r\ntemplate<class HLD, typename\
    \ T, template<typename> class SEG>\r\nstruct HeavyLightDecomposition_Query {\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing seg_type = SEG<value_type>;\r\n\tusing hld_type = HLD;\r\n\tusing size_type\
    \ = std::uint_fast32_t;\r\n\tusing Graph = typename hld_type::Graph;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\thld_type hld;\r\n\tseg_type seg, rseg;\r\
    \n\tbool value_on_vertex;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\
    \t\t: HeavyLightDecomposition_Query(g, g.size(), id_elem, f, value_on_vertex)\
    \ {}\r\n\t\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type root,\
    \ const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\t\t: id_elem(id_elem),\
    \ f(f), hld(g, root, false), value_on_vertex(value_on_vertex) {\r\n\t\tseg = seg_type{\
    \ hld.bf_size(), id_elem, f };\r\n\t\trseg = seg_type{ hld.bf_size(), id_elem,\
    \ f };\r\n\t}\r\n\t\r\n\ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\
    \n\t\t: HeavyLightDecomposition_Query(g, g.size(), v, id_elem, f) {}\r\n\t\r\n\
    \ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type\
    \ root, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\n\
    \t\t: id_elem(id_elem), f(f), hld(g, root, false), value_on_vertex(true) {\r\n\
    \t\tstd::vector<value_type> init(hld.bf_size());\r\n\t\tfor (size_type i = 0;\
    \ i < hld.bf_size(); ++i) init[i] = v[hld.euler_map(i)];\r\n\t\tseg = seg_type{\
    \ init, id_elem, f };\r\n\t\t\r\n\t\tfor (size_type i = 0; i < hld.af_size();\
    \ ++i) {\r\n\t\t\tconst size_type fidx = hld.in(hld.head(i));\r\n\t\t\tstd::reverse(begin(init)\
    \ + fidx, begin(init) + fidx + hld.heavy_size(i));\r\n\t\t}\r\n\t\trseg = seg_type{\
    \ init, id_elem, f };\r\n\t}\r\n\t\r\n\tconst hld_type & get_hld() const {\r\n\
    \t\treturn hld;\r\n\t}\r\n\t\r\n\tvoid set(size_type v, const_reference x) {\r\
    \n\t\tassert(value_on_vertex);\r\n\t\tassert(v < hld.bf_size());\r\n\t\tset_(v,\
    \ x);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type v) const {\r\n\t\tassert(value_on_vertex);\r\
    \n\t\tassert(v < hld.bf_size());\r\n\t\treturn get_(v);\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type u, size_type v, const_reference x) {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\tset_(hld.par(u) == v ? u : v, x);\r\n\t}\r\n\
    \t\r\n\tvalue_type get(size_type u, size_type v) const {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\treturn get_(hld.par(u) == v ? u : v);\r\n\t\
    }\r\n\t\r\nprivate:\r\n\tvoid set_(size_type v, const_reference x) {\r\n\t\tseg.set(hld.in(v),\
    \ x);\r\n\t\trseg.set(reverse_idx(v), x);\r\n\t}\r\n\t\r\n\tvalue_type get_(size_type\
    \ v) const {\r\n\t\treturn seg.get(hld.in(v));\r\n\t}\r\n\t\r\npublic:\r\n\tvalue_type\
    \ fold(size_type u, size_type v) const {\r\n\t\tassert(u < hld.bf_size());\r\n\
    \t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.tree_id(u) == hld.tree_id(v));\r\
    \n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\t\r\n\t\twhile (hld.heavy_map(u)\
    \ != hld.heavy_map(v)) {\r\n\t\t\tif (hld.heavy_depth(hld.heavy_map(u)) >= hld.heavy_depth(hld.heavy_map(v)))\
    \ {\r\n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(u));\r\n\t\t\t\t\
    lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));\r\n\t\t\t\tu = hld.par(head);\r\
    \n\t\t\t}\r\n\t\t\tif (hld.heavy_map(u) == hld.heavy_map(v)) break;\r\n\t\t\t\
    if (hld.heavy_depth(hld.heavy_map(u)) <= hld.heavy_depth(hld.heavy_map(v))) {\r\
    \n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(v));\r\n\t\t\t\trv = f(seg.fold(hld.in(head),\
    \ hld.in(v) + 1), rv);\r\n\t\t\t\tv = hld.par(head);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \t\r\n\t\tconst size_type id = hld.heavy_map(u);\r\n\t\tif (hld.in(u) < hld.in(v))\
    \ rv = f(seg.fold(hld.in(u) + !value_on_vertex, hld.in(v) + 1), rv);\r\n\t\telse\
    \ lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + value_on_vertex));\r\n\
    \t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type subtree_sum(size_type v) const\
    \ {\r\n\t\treturn seg.fold(hld.in(v), hld.out(v));\r\n\t}\r\n\t\r\nprivate:\r\n\
    \tsize_type reverse_idx(size_type v) const {\r\n\t\tconst size_type id = hld.heavy_map(v);\r\
    \n\t\treturn (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;\r\
    \n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP\r\n#define\
    \ INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP\r\n\r\n/*\r\nlast-updated:\
    \ 2020/09/18\r\n\r\n\u68EE\u4E0A\u3067 1 \u70B9\u66F4\u65B0, \u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3084\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u3092 HL \u5206\u89E3\u3092\
    \u7528\u3044\u3066\u89E3\u3044\u3066\u304F\u308C\u308B\u4FBF\u5229\u30C7\u30FC\
    \u30BF\u69CB\u9020\r\n\u9802\u70B9\u5C5E\u6027(\u9802\u70B9\u306B\u5024\u3092\u6301\
    \u3064), \u8FBA\u5C5E\u6027(\u8FBA\u306B\u5024\u3092\u6301\u3064) \u3069\u3061\
    \u3089\u306B\u3082\u5BFE\u5FDC\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u5834\u5408\
    \u3001\u6F14\u7B97\u304C\u975E\u53EF\u63DB\u3067\u3082 ok (\u30BB\u30B0\u6728\u3082\
    \u975E\u53EF\u63DB\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u5FC5\u8981\u304C\
    \u3042\u308B)\r\n\r\n\u30D1\u30B9\u66F4\u65B0\u306E\u5834\u5408\u306F\u5C11\u3057\
    \u5909\u66F4\u3059\u308B\u3053\u3068\u3067 LazySegmentTree \u3092\u7528\u3044\u3066\
    \u89E3\u3051\u308B(\u30CF\u30BA)\r\n\r\n# \u4ED5\u69D8\r\n\u6B21\u306E\u8A08\u7B97\
    \u91CF\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\r\n- HeavyLightDecomposition\
    \ \u306E\u69CB\u7BC9\u3092 \u0398(n)\r\n- \u5024\u306E\u6F14\u7B97\u3092 \u0398\
    (1)\r\n- SegmentTree:\r\n-- \u521D\u671F\u5024\u6307\u5B9A\u521D\u671F\u5316:\
    \ \u0398(n)\r\n-- set, fold: O(log n)\r\n-- get \u304C \u0398(1)\r\n\r\ntemplate\
    \ \u5F15\u6570:\r\n\tclass HLD: HeavyLightDecomposition(Library \u5185\u306E lca\
    \ \u95A2\u9023\u3092\u9664\u304F\u6A5F\u80FD\u3092\u8981\u6C42)\r\n\ttypename\
    \ T: \u6271\u3046\u5024\u306E\u578B\r\n\ttemplate<typename> class SEG>: T \u3092\
    \ template \u5F15\u6570\u306B\u6301\u3064 SegmentTree(set, get, fold \u3092\u8981\
    \u6C42)\r\n\r\nHeavyLightDecomposition_Query(\r\n\tconst Graph & g: \u30B0\u30E9\
    \u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\u304C\u6728\u3067\u3042\u308B\u3068\
    \u304D\u3001\u305D\u306E\u6839(\u7701\u7565\u53EF)\r\n\tconst value_type & id_elem:\
    \ \u5358\u4F4D\u5143\r\n\tconst F & f : \u4E8C\u9805\u6F14\u7B97\r\n\tbool value_on_vertex\
    \ : \u9802\u70B9\u5C5E\u6027\u304B\u3069\u3046\u304B(true - \u9802\u70B9\u5C5E\
    \u6027, false - \u8FBA\u5C5E\u6027) )\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (n)\r\n\t\u30B0\u30E9\u30D5 g \u3092 HL \u5206\u89E3\u3057\u3001\u5404(\u9802\u70B9\
    \ or \u8FBA) \u306E\u5024\u3092\u5358\u4F4D\u5143 id_elem \u3067\u521D\u671F\u5316\
    \r\n\r\ntemplate<typename U>\r\nHeavyLightDecomposition_Query(\r\n\tconst Graph\
    \ & g: \u30B0\u30E9\u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\u304C\u6728\u3067\
    \u3042\u308B\u3068\u304D\u3001\u305D\u306E\u6839(\u7701\u7565\u53EF)\r\n\tconst\
    \ std::vector<U> & v: \u5404\u9802\u70B9\u306E\u5024\u306E\u521D\u671F\u5024\r\
    \n\tconst value_type & id_elem: \u5358\u4F4D\u5143\r\n\tconst F & f : \u4E8C\u9805\
    \u6F14\u7B97 )\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B0\u30E9\
    \u30D5 g \u3092 HL \u5206\u89E3\u3057\u3001\u5168\u3066\u306E\u9802\u70B9\u306E\
    \u5024\u3092 v \u3067\u521D\u671F\u5316\u3059\u308B\r\n\t\u8FBA\u5C5E\u6027\u306E\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u521D\u671F\u5316\u306B\u306F\u5BFE\
    \u5FDC\u3057\u3066\u3044\u306A\u3044\r\n\r\nconst hld_type & get_hld() const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5185\u90E8\u3067\u6271\u3063\
    \u3066\u3044\u308B HeavyLightDecomposition \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\
    \u3092\u8FD4\u3059\r\n\r\n- \u9802\u70B9\u5C5E\u6027\r\n\tvoid set(size_type v,\
    \ const_reference x)\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\t\u9802\
    \u70B9 v \u306E\u5024\u3092 x \u306B\u5909\u66F4\u3059\u308B\r\n\r\n\tvalue_type\
    \ get(size_type v) const\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \t\u9802\u70B9 v \u306E\u5024\u3092\u8FD4\u3059\r\n\r\n- \u8FBA\u5C5E\u6027\r\n\
    \tvoid set(size_type u, size_type v, const_reference x)\r\n\t\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\r\n\t\t\u8FBA u-v \u306E\u5024\u3092 x \u306B\u5909\u66F4\
    \u3059\u308B\r\n\r\n\tvalue_type get(size_type u, size_type v) const\r\n\t\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\t\u8FBA u-v \u306E\u5024\u3092\u8FD4\
    \u3059\r\n\r\nvalue_type fold(size_type u, size_type v) const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O((log n)^2)\r\n\t\u9802\u70B9\u5C5E\u6027\u306E\u5834\u5408\
    \u306F u-v \u30D1\u30B9\u4E0A\u306E\u9802\u70B9(\u7AEF\u70B9\u542B\u3080)\u306E\
    \u5024\u306E fold \u3057\u305F\u5024\u3092\u8FD4\u3059\r\n\t\u8FBA\u5C5E\u6027\
    \u306E\u5834\u5408\u306F u-v \u30D1\u30B9\u4E0A\u306E\u8FBA\u306E\u5024\u306E\
    \ fold \u3057\u305F\u5024\u3092\u8FD4\u3059\r\n\r\nvalue_type subtree_sum(size_type\
    \ v) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u9802\u70B9 v \u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u5185\u306E\u5024\u306E\u5408\u8A08\
    \u3092\u6C42\u3081\u308B\r\n\r\n# \u53C2\u8003\r\n\u8FBA\u5C5E\u6027 verify(2020/09/18):\
    \ https://atcoder.jp/contests/abc133/submissions/16817431\r\n*/\r\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <functional>\r\n#include <utility>\r\
    \n#include <algorithm>\r\n#include <cstdint>\r\n\r\ntemplate<class HLD, typename\
    \ T, template<typename> class SEG>\r\nstruct HeavyLightDecomposition_Query {\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing seg_type = SEG<value_type>;\r\n\tusing hld_type = HLD;\r\n\tusing size_type\
    \ = std::uint_fast32_t;\r\n\tusing Graph = typename hld_type::Graph;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\thld_type hld;\r\n\tseg_type seg, rseg;\r\
    \n\tbool value_on_vertex;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\
    \t\t: HeavyLightDecomposition_Query(g, g.size(), id_elem, f, value_on_vertex)\
    \ {}\r\n\t\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type root,\
    \ const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\t\t: id_elem(id_elem),\
    \ f(f), hld(g, root, false), value_on_vertex(value_on_vertex) {\r\n\t\tseg = seg_type{\
    \ hld.bf_size(), id_elem, f };\r\n\t\trseg = seg_type{ hld.bf_size(), id_elem,\
    \ f };\r\n\t}\r\n\t\r\n\ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\
    \n\t\t: HeavyLightDecomposition_Query(g, g.size(), v, id_elem, f) {}\r\n\t\r\n\
    \ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type\
    \ root, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\n\
    \t\t: id_elem(id_elem), f(f), hld(g, root, false), value_on_vertex(true) {\r\n\
    \t\tstd::vector<value_type> init(hld.bf_size());\r\n\t\tfor (size_type i = 0;\
    \ i < hld.bf_size(); ++i) init[i] = v[hld.euler_map(i)];\r\n\t\tseg = seg_type{\
    \ init, id_elem, f };\r\n\t\t\r\n\t\tfor (size_type i = 0; i < hld.af_size();\
    \ ++i) {\r\n\t\t\tconst size_type fidx = hld.in(hld.head(i));\r\n\t\t\tstd::reverse(begin(init)\
    \ + fidx, begin(init) + fidx + hld.heavy_size(i));\r\n\t\t}\r\n\t\trseg = seg_type{\
    \ init, id_elem, f };\r\n\t}\r\n\t\r\n\tconst hld_type & get_hld() const {\r\n\
    \t\treturn hld;\r\n\t}\r\n\t\r\n\tvoid set(size_type v, const_reference x) {\r\
    \n\t\tassert(value_on_vertex);\r\n\t\tassert(v < hld.bf_size());\r\n\t\tset_(v,\
    \ x);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type v) const {\r\n\t\tassert(value_on_vertex);\r\
    \n\t\tassert(v < hld.bf_size());\r\n\t\treturn get_(v);\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type u, size_type v, const_reference x) {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\tset_(hld.par(u) == v ? u : v, x);\r\n\t}\r\n\
    \t\r\n\tvalue_type get(size_type u, size_type v) const {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\treturn get_(hld.par(u) == v ? u : v);\r\n\t\
    }\r\n\t\r\nprivate:\r\n\tvoid set_(size_type v, const_reference x) {\r\n\t\tseg.set(hld.in(v),\
    \ x);\r\n\t\trseg.set(reverse_idx(v), x);\r\n\t}\r\n\t\r\n\tvalue_type get_(size_type\
    \ v) const {\r\n\t\treturn seg.get(hld.in(v));\r\n\t}\r\n\t\r\npublic:\r\n\tvalue_type\
    \ fold(size_type u, size_type v) const {\r\n\t\tassert(u < hld.bf_size());\r\n\
    \t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.tree_id(u) == hld.tree_id(v));\r\
    \n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\t\r\n\t\twhile (hld.heavy_map(u)\
    \ != hld.heavy_map(v)) {\r\n\t\t\tif (hld.heavy_depth(hld.heavy_map(u)) >= hld.heavy_depth(hld.heavy_map(v)))\
    \ {\r\n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(u));\r\n\t\t\t\t\
    lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));\r\n\t\t\t\tu = hld.par(head);\r\
    \n\t\t\t}\r\n\t\t\tif (hld.heavy_map(u) == hld.heavy_map(v)) break;\r\n\t\t\t\
    if (hld.heavy_depth(hld.heavy_map(u)) <= hld.heavy_depth(hld.heavy_map(v))) {\r\
    \n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(v));\r\n\t\t\t\trv = f(seg.fold(hld.in(head),\
    \ hld.in(v) + 1), rv);\r\n\t\t\t\tv = hld.par(head);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \t\r\n\t\tconst size_type id = hld.heavy_map(u);\r\n\t\tif (hld.in(u) < hld.in(v))\
    \ rv = f(seg.fold(hld.in(u) + !value_on_vertex, hld.in(v) + 1), rv);\r\n\t\telse\
    \ lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + value_on_vertex));\r\n\
    \t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type subtree_sum(size_type v) const\
    \ {\r\n\t\treturn seg.fold(hld.in(v), hld.out(v));\r\n\t}\r\n\t\r\nprivate:\r\n\
    \tsize_type reverse_idx(size_type v) const {\r\n\t\tconst size_type id = hld.heavy_map(v);\r\
    \n\t\treturn (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;\r\
    \n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/HeavyLightDecomposition_Query.hpp
  requiredBy: []
  timestamp: '2020-09-18 18:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
documentation_of: GraphTheory/HeavyLightDecomposition_Query.hpp
layout: document
redirect_from:
- /library/GraphTheory/HeavyLightDecomposition_Query.hpp
- /library/GraphTheory/HeavyLightDecomposition_Query.hpp.html
title: GraphTheory/HeavyLightDecomposition_Query.hpp
---
