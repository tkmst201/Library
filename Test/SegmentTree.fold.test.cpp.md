---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':question:'
    path: Mathematics/ModInt.hpp
    title: Mathematics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Test/SegmentTree.fold.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
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
    \n\t\t}\r\n\t\treturn r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/ModInt.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/02/26\r\n\r\n# \u4ED5\u69D8\r\nModInt(long\
    \ long val = 0) : \u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nModInt pow(long long n) const\
    \ : O(log n) n \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059(\u8CA0\u306E\u6574\u6570\
    \u3082\u5BFE\u5FDC)\r\nModInt inverse() const : O(log n) \u6CD5 M \u306E\u5143\
    \u3067\u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\r\nconst value_type & get() const\
    \ noexcept\r\nvalue_type & get() noexcept : \u5024\u3092\u8FD4\u3059\r\n\r\nstatic\
    \ decltype(M) get_mod() noexcept : \u6CD5 M \u3092\u8FD4\u3059\r\n\r\nexplicit\
    \ operator bool() const noexcept : bool\u3078\u578B\u5909\u63DB 0\u4EE5\u5916\u306E\
    \u3068\u304DTrue\r\noperator ==() const noexcept\r\noperator !=() const noexcept\r\
    \noperator +() const noexept\r\noperator -() const noexept\r\noperator +(const\
    \ ModInt & rhs) const noexept\r\noperator -(const ModInt & rhs) const noexept\r\
    \noperator *(const ModInt & rhs) const noexept\r\noperator /(const ModInt & rhs)\
    \ const noexept\r\nModInt & operator +=(const ModInt & rhs) const noexept\r\n\
    ModInt & operator +=(const ModInt & rhs) const noexept :\r\n\r\nfriend std::ostream\
    \ & operator <<(std::ostream & os, const ModInt & rhs)\r\nfriend std::istream\
    \ & operator >>(std::istream & is, ModInt & rhs) :\r\n\t\u5165\u51FA\u529B\u7528\
    \r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#line 39 \"Mathematics/ModInt.hpp\"\n#include <iostream>\r\n\r\ntemplate<int\
    \ M>\r\nstruct ModInt {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\
    \tModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}\r\
    \n\t\r\n\texplicit operator bool() const noexcept { return val; }\r\n\tbool operator\
    \ ==(const ModInt & rhs) const noexcept { return val == rhs.val; }\r\n\tbool operator\
    \ !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }\r\n\tModInt\
    \ operator +() const noexcept { return ModInt(*this); }\r\n\tModInt operator -()\
    \ const noexcept { return ModInt(0) -= *this; }\r\n\tModInt operator +(const ModInt\
    \ & rhs) const noexcept { return ModInt(*this) += rhs; }\r\n\tModInt operator\
    \ -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }\r\n\t\
    ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *=\
    \ rhs; }\r\n\tModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this)\
    \ /= rhs; }\r\n\t\r\n\tModInt & operator +=(const ModInt & rhs) noexcept {\r\n\
    \t\tval += rhs.val;\r\n\t\tif (val >= M) val -= M;\r\n\t\treturn *this;\r\n\t\
    }\r\n\tModInt & operator -=(const ModInt & rhs) noexcept {\r\n\t\tif (val < rhs.val)\
    \ val += M;\r\n\t\tval -= rhs.val;\r\n\t\treturn *this;\r\n\t}\r\n\tModInt & operator\
    \ *=(const ModInt & rhs) noexcept {\r\n\t\tval = val * rhs.val % M;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tModInt & operator /=(const ModInt & rhs) noexcept {\r\n\t\
    \t*this *= rhs.inverse();\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tModInt pow(value_type\
    \ n) const {\r\n\t\tModInt res = 1, x = val;\r\n\t\tif (n < 0) { x = x.inverse();\
    \ n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\t\
    return res;\r\n\t}\r\n\t\r\n\tModInt inverse() const {\r\n\t\tlong long a = val,\
    \ a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type\
    \ q = a / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q *\
    \ b2;\r\n\t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2\
    \ = nb2;\r\n\t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n\t\r\n\t\
    const value_type & get() const noexcept { return val; }\r\n\tstatic decltype(M)\
    \ get_mod() noexcept { return M; }\r\n\t\r\n\tfriend std::ostream & operator <<(std::ostream\
    \ & os, const ModInt & rhs) { return os << rhs.val; }\r\n\tfriend std::istream\
    \ & operator >>(std::istream & is, ModInt & rhs) {\r\n\t\tvalue_type x;\r\n\t\t\
    is >> x;\r\n\t\trhs = ModInt(x);\r\n\t\treturn is;\r\n\t}\r\nprivate:\r\n\tvalue_type\
    \ val;\r\n};\r\n\r\n\n#line 5 \"Test/SegmentTree.fold.test.cpp\"\n\r\n#include\
    \ <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\
    \n\t\r\n\tusing mint = ModInt<998244353>;\r\n\tusing pmm = std::pair<mint, mint>;\r\
    \n\t\r\n\tSegmentTree<pmm> seg(N, pmm(1, 0), [](const pmm & a, const pmm & b)\
    \ -> pmm {\r\n\t\treturn {a.first * b.first, b.first * a.second + b.second};\r\
    \n\t});\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\tseg.set(i, {a, b});\r\n\t}\r\n\t\r\n\twhile (Q--) {\r\
    \n\t\tint q, a, b, c;\r\n\t\tscanf(\"%d %d %d %d\", &q, &a, &b, &c);\r\n\t\tif\
    \ (q == 0) {\r\n\t\t\tseg.set(a, {b, c});\r\n\t\t}\r\n\t\telse {\r\n\t\t\tpmm\
    \ v = seg.fold(a, b);\r\n\t\t\tmint ans = v.first * c + v.second;\r\n\t\t\tprintf(\"\
    %lld\\n\", ans.get());\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include \"DataStructure/SegmentTree.hpp\"\r\n#include \"Mathematics/ModInt.hpp\"\
    \r\n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\"\
    , &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\n\tusing pmm = std::pair<mint,\
    \ mint>;\r\n\t\r\n\tSegmentTree<pmm> seg(N, pmm(1, 0), [](const pmm & a, const\
    \ pmm & b) -> pmm {\r\n\t\treturn {a.first * b.first, b.first * a.second + b.second};\r\
    \n\t});\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\tseg.set(i, {a, b});\r\n\t}\r\n\t\r\n\twhile (Q--) {\r\
    \n\t\tint q, a, b, c;\r\n\t\tscanf(\"%d %d %d %d\", &q, &a, &b, &c);\r\n\t\tif\
    \ (q == 0) {\r\n\t\t\tseg.set(a, {b, c});\r\n\t\t}\r\n\t\telse {\r\n\t\t\tpmm\
    \ v = seg.fold(a, b);\r\n\t\t\tmint ans = v.first * c + v.second;\r\n\t\t\tprintf(\"\
    %lld\\n\", ans.get());\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/SegmentTree.fold.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:14:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/SegmentTree.fold.test.cpp
layout: document
redirect_from:
- /verify/Test/SegmentTree.fold.test.cpp
- /verify/Test/SegmentTree.fold.test.cpp.html
title: Test/SegmentTree.fold.test.cpp
---
