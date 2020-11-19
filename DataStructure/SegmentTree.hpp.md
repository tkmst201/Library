---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.test.cpp
    title: Test/EulerTour.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SegmentTree.fold.test.cpp
    title: Test/SegmentTree.fold.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/16664880)
    - https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf,
  bundledCode: "#line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
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
    \ 2020/04/08\r\nAC Library, 2020/09/13\r\n*/\r\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\r\ntemplate<typename\
    \ T>\r\nstruct SegmentTree {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\
    \tsize_type n, n_;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tSegmentTree() = default;\r\n\t\r\n\tSegmentTree(size_type\
    \ n, const_reference id_elem, const F & f) : n(n), id_elem(id_elem), f(f) {\r\n\
    \t\tn_ = 1;\r\n\t\twhile (n_ < n) n_ <<= 1;\r\n\t\tnode.resize(2 * n_, id_elem);\r\
    \n\t}\r\n\t\r\n\tSegmentTree(std::vector<value_type> v, const_reference id_elem,\
    \ const F & f) :\r\n\t\t\tSegmentTree(v.size(), id_elem, f) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type i, const_reference x) {\r\n\t\tassert(i < size());\r\n\t\tnode[i\
    \ += n_] = x;\r\n\t\twhile (i > 1) {\r\n\t\t\ti >>= 1;\r\n\t\t\tnode[i] = f(node[i\
    \ << 1], node[i << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ i) const {\r\n\t\tassert(i < size());\r\n\t\treturn node[i + n_];\r\n\t}\r\n\
    \t\r\n\tvalue_type fold(size_type l, size_type r) const {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= size());\r\n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\
    \tfor (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif (l & 1) lv = f(lv,\
    \ node[l++]);\r\n\t\t\tif (r & 1) rv = f(node[r - 1], rv);\r\n\t\t}\r\n\t\treturn\
    \ f(lv, rv);\r\n\t}\r\n\t\r\n\tconst_reference fold_all() const {\r\n\t\treturn\
    \ node[1];\r\n\t}\r\n\t\r\n\tsize_type max_right(size_type l, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(l <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (l == size()) return size();\r\n\t\tl += n_;\r\n\t\tvalue_type sum = id_elem;\r\
    \n\t\twhile (true) {\r\n\t\t\twhile (~l & 1) l >>= 1;\r\n\t\t\tconst value_type\
    \ nex_sum = f(sum, node[l]);\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; ++l; }\r\
    \n\t\t\telse break;\r\n\t\t\tif ((l & -l) == l) return size();\r\n\t\t}\r\n\t\t\
    while (l < n_) {\r\n\t\t\tconst value_type nex_sum = f(sum, node[l << 1]);\r\n\
    \t\t\tl <<= 1;\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; l |= 1; }\r\n\t\t}\r\n\
    \t\treturn l - n_;\r\n\t}\r\n\t\r\n\tsize_type min_left(size_type r, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (r == 0) return 0;\r\n\t\tr += n_;\r\n\t\tvalue_type sum = id_elem;\r\n\t\t\
    while (true) {\r\n\t\t\t--r;\r\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\r\n\t\t\
    \tconst value_type nex_sum = f(node[r], sum);\r\n\t\t\tif (g(nex_sum)) sum = nex_sum;\r\
    \n\t\t\telse break;\r\n\t\t\tif ((r & -r) == r) return 0;\r\n\t\t}\r\n\t\twhile\
    \ (r < n_) {\r\n\t\t\tconst value_type nex_sum = f(node[r << 1 | 1], sum);\r\n\
    \t\t\tr <<= 1;\r\n\t\t\tif (!g(nex_sum)) r |= 1;\r\n\t\t\telse sum = nex_sum;\r\
    \n\t\t}\r\n\t\treturn r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SEGMENT_TREE_HPP\r\n#define INCLUDE_GUARD_SEGMENT_TREE_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/18\r\n\r\nmax_right: verified(https://atcoder.jp/contests/practice2/submissions/16664880)\r\
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
    \ 2020/04/08\r\nAC Library, 2020/09/13\r\n*/\r\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\r\ntemplate<typename\
    \ T>\r\nstruct SegmentTree {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\
    \tsize_type n, n_;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tSegmentTree() = default;\r\n\t\r\n\tSegmentTree(size_type\
    \ n, const_reference id_elem, const F & f) : n(n), id_elem(id_elem), f(f) {\r\n\
    \t\tn_ = 1;\r\n\t\twhile (n_ < n) n_ <<= 1;\r\n\t\tnode.resize(2 * n_, id_elem);\r\
    \n\t}\r\n\t\r\n\tSegmentTree(std::vector<value_type> v, const_reference id_elem,\
    \ const F & f) :\r\n\t\t\tSegmentTree(v.size(), id_elem, f) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type i, const_reference x) {\r\n\t\tassert(i < size());\r\n\t\tnode[i\
    \ += n_] = x;\r\n\t\twhile (i > 1) {\r\n\t\t\ti >>= 1;\r\n\t\t\tnode[i] = f(node[i\
    \ << 1], node[i << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ i) const {\r\n\t\tassert(i < size());\r\n\t\treturn node[i + n_];\r\n\t}\r\n\
    \t\r\n\tvalue_type fold(size_type l, size_type r) const {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= size());\r\n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\
    \tfor (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif (l & 1) lv = f(lv,\
    \ node[l++]);\r\n\t\t\tif (r & 1) rv = f(node[r - 1], rv);\r\n\t\t}\r\n\t\treturn\
    \ f(lv, rv);\r\n\t}\r\n\t\r\n\tconst_reference fold_all() const {\r\n\t\treturn\
    \ node[1];\r\n\t}\r\n\t\r\n\tsize_type max_right(size_type l, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(l <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (l == size()) return size();\r\n\t\tl += n_;\r\n\t\tvalue_type sum = id_elem;\r\
    \n\t\twhile (true) {\r\n\t\t\twhile (~l & 1) l >>= 1;\r\n\t\t\tconst value_type\
    \ nex_sum = f(sum, node[l]);\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; ++l; }\r\
    \n\t\t\telse break;\r\n\t\t\tif ((l & -l) == l) return size();\r\n\t\t}\r\n\t\t\
    while (l < n_) {\r\n\t\t\tconst value_type nex_sum = f(sum, node[l << 1]);\r\n\
    \t\t\tl <<= 1;\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; l |= 1; }\r\n\t\t}\r\n\
    \t\treturn l - n_;\r\n\t}\r\n\t\r\n\tsize_type min_left(size_type r, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (r == 0) return 0;\r\n\t\tr += n_;\r\n\t\tvalue_type sum = id_elem;\r\n\t\t\
    while (true) {\r\n\t\t\t--r;\r\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\r\n\t\t\
    \tconst value_type nex_sum = f(node[r], sum);\r\n\t\t\tif (g(nex_sum)) sum = nex_sum;\r\
    \n\t\t\telse break;\r\n\t\t\tif ((r & -r) == r) return 0;\r\n\t\t}\r\n\t\twhile\
    \ (r < n_) {\r\n\t\t\tconst value_type nex_sum = f(node[r << 1 | 1], sum);\r\n\
    \t\t\tr <<= 1;\r\n\t\t\tif (!g(nex_sum)) r |= 1;\r\n\t\t\telse sum = nex_sum;\r\
    \n\t\t}\r\n\t\treturn r + 1 - n_;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SEGMENT_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2020-09-18 18:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  - Test/EulerTour.test.cpp
  - Test/SegmentTree.fold.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
documentation_of: DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.hpp
- /library/DataStructure/SegmentTree.hpp.html
title: DataStructure/SegmentTree.hpp
---
