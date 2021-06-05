---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Test/LazySegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n#include <cassert>\r\n#include\
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
    #line 1 \"DataStructure/LazySegmentTree.hpp\"\n\n\n\r\n#include <vector>\r\n#line\
    \ 6 \"DataStructure/LazySegmentTree.hpp\"\n#include <functional>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/DataStructure/LazySegmentTree.hpp\r\
    \n */\r\ntemplate<typename T, typename E>\r\nstruct LazySegmentTree {\r\n\tusing\
    \ value_type = T;\r\n\tusing lazy_type = E;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing F = std::function<value_type (const value_type &, const value_type &)>;\r\
    \n\tusing G = std::function<value_type (const value_type &, const lazy_type &)>;\r\
    \n\tusing H = std::function<lazy_type (const lazy_type &, const lazy_type &)>;\r\
    \n\tusing P = std::function<lazy_type (const lazy_type &, size_type)>;\r\n\t\r\
    \nprivate:\r\n\tsize_type n, n_, n_log;\r\n\tvalue_type id_node;\r\n\tlazy_type\
    \ id_lazy;\r\n\tF f;\r\n\tG g;\r\n\tH h;\r\n\tP p;\r\n\tstd::vector<value_type>\
    \ node;\r\n\tstd::vector<lazy_type> lazy;\r\n\r\npublic:\r\n\tLazySegmentTree(size_type\
    \ n, const value_type & id_node, const lazy_type & id_lazy, const F & f, const\
    \ G & g, const H & h, const P & p = [](const lazy_type & e, size_type k) { return\
    \ e; })\r\n\t\t\t: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h),\
    \ p(p) {\r\n\t\tn_ = 1;\r\n\t\tn_log = 0;\r\n\t\twhile (n_ < n) n_ <<= 1, ++n_log;\r\
    \n\t\tnode.assign(2 * n_, id_node);\r\n\t\tlazy.assign(2 * n_, id_lazy);\r\n\t\
    }\r\n\t\r\n\tLazySegmentTree(const std::vector<value_type> & v, const value_type\
    \ & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h,\
    \ const P & p = [](const lazy_type & a, size_type l) { return a; })\r\n\t\t\t\
    : LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type k, const value_type & x) noexcept {\r\n\t\tassert(k < size());\r\
    \n\t\tk += n_;\r\n\t\tthrust(k);\r\n\t\tnode[k] = x;\r\n\t\tlazy[k] = id_lazy;\r\
    \n\t\trecalc(k);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type k) noexcept {\r\n\t\
    \tassert(k < size());\r\n\t\tk += n_;\r\n\t\tthrust(k);\r\n\t\treturn reflect(k,\
    \ 1);\r\n\t}\r\n\t\r\n\tvoid update(size_type l, size_type r, const lazy_type\
    \ & x) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif\
    \ (l == r) return;\r\n\t\tl += n_;\r\n\t\tr += n_;\r\n\t\tthrust(l);\r\n\t\tthrust(r\
    \ - 1);\r\n\t\tfor (size_type cl = l, cr = r; cl < cr; cl >>= 1, cr >>= 1) {\r\
    \n\t\t\tif (cl & 1) lazy[cl] = h(lazy[cl], x), ++cl;\r\n\t\t\tif (cr & 1) --cr,\
    \ lazy[cr] = h(lazy[cr], x);\r\n\t\t}\r\n\t\trecalc(l);\r\n\t\trecalc(r - 1);\r\
    \n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type r) noexcept {\r\n\t\t\
    assert(l <= r);\r\n\t\tassert(r <= size());\r\n\t\tif (l == r) return id_node;\r\
    \n\t\tl += n_;\r\n\t\tr += n_;\r\n\t\tthrust(l);\r\n\t\tthrust(r - 1);\r\n\t\t\
    value_type vl = id_node, vr = id_node;\r\n\t\tfor (size_type w = 1; l < r; l >>=\
    \ 1, r >>= 1, w <<= 1) {\r\n\t\t\tif (l & 1) vl = f(vl, reflect(l, w)), ++l;\r\
    \n\t\t\tif (r & 1) --r, vr = f(reflect(r, w), vr);\r\n\t\t}\r\n\t\treturn f(vl,\
    \ vr);\r\n\t}\r\n\t\r\n\tvalue_type fold_all() const {\r\n\t\treturn reflect(1,\
    \ n_);\r\n\t}\r\n\t\r\nprivate:\r\n\tvalue_type reflect(size_type k, size_type\
    \ w) const noexcept {\r\n\t\treturn lazy[k] == id_lazy ? node[k] : g(node[k],\
    \ p(lazy[k], w));\r\n\t}\r\n\t\r\n\tvoid propagate(size_type k, size_type w) noexcept\
    \ {\r\n\t\tif (lazy[k] == id_lazy) return;\r\n\t\tif ((k << 1) < node.size())\
    \ {\r\n\t\t\tlazy[k << 1] = h(lazy[k << 1], lazy[k]);\r\n\t\t\tlazy[k << 1 | 1]\
    \ = h(lazy[k << 1 | 1], lazy[k]);\r\n\t\t}\r\n\t\tnode[k] = reflect(k, w);\r\n\
    \t\tlazy[k] = id_lazy;\r\n\t}\r\n\t\r\n\tvoid recalc(size_type k) noexcept {\r\
    \n\t\tfor (size_type i = k >> 1, cw = 1; i > 0; i >>= 1, cw <<= 1)\r\n\t\t\tnode[i]\
    \ = f(reflect(i << 1, cw), reflect(i << 1 | 1, cw));\r\n\t}\r\n\t\r\n\tvoid thrust(size_type\
    \ k) noexcept {\r\n\t\tfor (size_type i = n_log, w = n_; i > 0; --i, w >>= 1)\
    \ propagate(k >> i, w);\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/LazySegmentTree.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <utility>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\t\r\n\tstd::vector<mint> A(N);\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint\
    \ a;\r\n\t\tscanf(\"%d\", &a);\r\n\t\tA[i] = a;\r\n\t}\r\n\t\r\n\tusing P = std::pair<mint,\
    \ mint>; // {first} x + {second}\r\n\t\r\n\tLazySegmentTree<mint, P> seg(A, 0,\
    \ {1, 0},\r\n\t\t[](const auto & x, const auto & y) { return x + y; },\r\n\t\t\
    [](const auto & x, const auto & e) { return e.first * x + e.second; },\r\n\t\t\
    [](const auto & e1, const auto & e2) { return std::make_pair(e1.first * e2.first,\
    \ e1.second * e2.first + e2.second); },\r\n\t\t[](const auto & e, auto k) { return\
    \ std::make_pair(e.first, e.second * k); });\r\n\t\r\n\twhile (Q--) {\r\n\t\t\
    int q, l, r;\r\n\t\tscanf(\"%d %d %d\", &q, &l, &r);\r\n\t\tif (q == 0) {\r\n\t\
    \t\tint b, c;\r\n\t\t\tscanf(\"%d %d\", &b, &c);\r\n\t\t\tseg.update(l, r, {b,\
    \ c});\r\n\t\t}\r\n\t\telse printf(\"%d\\n\", seg.fold(l, r).val());\r\n\t}\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include \"Mathematics/ModInt.hpp\"\r\n#include \"DataStructure/LazySegmentTree.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <utility>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\t\r\n\tstd::vector<mint> A(N);\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint\
    \ a;\r\n\t\tscanf(\"%d\", &a);\r\n\t\tA[i] = a;\r\n\t}\r\n\t\r\n\tusing P = std::pair<mint,\
    \ mint>; // {first} x + {second}\r\n\t\r\n\tLazySegmentTree<mint, P> seg(A, 0,\
    \ {1, 0},\r\n\t\t[](const auto & x, const auto & y) { return x + y; },\r\n\t\t\
    [](const auto & x, const auto & e) { return e.first * x + e.second; },\r\n\t\t\
    [](const auto & e1, const auto & e2) { return std::make_pair(e1.first * e2.first,\
    \ e1.second * e2.first + e2.second); },\r\n\t\t[](const auto & e, auto k) { return\
    \ std::make_pair(e.first, e.second * k); });\r\n\t\r\n\twhile (Q--) {\r\n\t\t\
    int q, l, r;\r\n\t\tscanf(\"%d %d %d\", &q, &l, &r);\r\n\t\tif (q == 0) {\r\n\t\
    \t\tint b, c;\r\n\t\t\tscanf(\"%d %d\", &b, &c);\r\n\t\t\tseg.update(l, r, {b,\
    \ c});\r\n\t\t}\r\n\t\telse printf(\"%d\\n\", seg.fold(l, r).val());\r\n\t}\r\n\
    }"
  dependsOn:
  - Mathematics/ModInt.hpp
  - DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: Test/LazySegmentTree.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LazySegmentTree.test.cpp
layout: document
redirect_from:
- /verify/Test/LazySegmentTree.test.cpp
- /verify/Test/LazySegmentTree.test.cpp.html
title: Test/LazySegmentTree.test.cpp
---
