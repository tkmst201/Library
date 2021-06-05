---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Test/SegmentTree.fold.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SegmentTree.hpp\r\
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
    \ r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\
    \n#line 5 \"Mathematics/ModInt.hpp\"\n#include <iostream>\r\n#include <cstdint>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
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
    #line 5 \"Test/SegmentTree.fold.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\tusing pmm = std::pair<mint, mint>;\r\n\t\r\n\tSegmentTree<pmm> seg(N, pmm(1,\
    \ 0), [](const pmm & a, const pmm & b) -> pmm {\r\n\t\treturn {a.first * b.first,\
    \ b.first * a.second + b.second};\r\n\t});\r\n\t\r\n\tfor (int i = 0; i < N; ++i)\
    \ {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tseg.set(i, {a, b});\r\
    \n\t}\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q, a, b, c;\r\n\t\tscanf(\"%d %d %d\
    \ %d\", &q, &a, &b, &c);\r\n\t\tif (q == 0) {\r\n\t\t\tseg.set(a, {b, c});\r\n\
    \t\t}\r\n\t\telse {\r\n\t\t\tpmm v = seg.fold(a, b);\r\n\t\t\tmint ans = v.first\
    \ * c + v.second;\r\n\t\t\tprintf(\"%d\\n\", ans.val());\r\n\t\t}\r\n\t}\r\n}\n"
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
    %d\\n\", ans.val());\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/SegmentTree.fold.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/SegmentTree.fold.test.cpp
layout: document
redirect_from:
- /verify/Test/SegmentTree.fold.test.cpp
- /verify/Test/SegmentTree.fold.test.cpp.html
title: Test/SegmentTree.fold.test.cpp
---
