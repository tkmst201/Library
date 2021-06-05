---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"Test/SlidingWindowAggregation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\r\n\r\n#line\
    \ 1 \"DataStructure/SlidingWindowAggregation.hpp\"\n\n\n\r\n#include <cassert>\r\
    \n#include <vector>\r\n#include <functional>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SlidingWindowAggregation {\r\n\tusing\
    \ value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\t\
    std::vector<value_type> lstack, rstack;\r\n\tvalue_type rsum;\r\n\t\r\npublic:\r\
    \n\tSlidingWindowAggregation(const_reference id_elem, const F & f)\r\n\t\t: id_elem(id_elem),\
    \ f(f), lstack(1, id_elem), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const\
    \ noexcept {\r\n\t\treturn lstack.size() - 1 + rstack.size();\r\n\t}\r\n\t\r\n\
    \tvoid push(const_reference x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum =\
    \ f(rsum, x);\r\n\t}\r\n\t\r\n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\t\
    if (lstack.size() == 1) {\r\n\t\t\twhile (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(f(rstack.back(),\
    \ lstack.back()));\r\n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\
    \n\t\t\trsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\
    \n\tvalue_type fold_all() const {\r\n\t\treturn f(lstack.back(), rsum);\r\n\t\
    }\r\n};\r\n\r\n\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n#line 5 \"Mathematics/ModInt.hpp\"\
    \n#include <iostream>\r\n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
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
    #line 5 \"Test/SlidingWindowAggregation.test.cpp\"\n\r\n#include <cstdio>\r\n\
    #include <utility>\r\n\r\nint main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\
    \t\r\n\tusing mint = ModInt<998244353>;\r\n\tusing P = std::pair<mint, mint>;\r\
    \n\t\r\n\tSlidingWindowAggregation<P> swag({1, 0}, [](const auto & x, const auto\
    \ & y) -> P {\r\n\t\treturn {x.first * y.first, x.second * y.first + y.second};\r\
    \n\t});\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\
    \tif (q == 0) {\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\"%d %d\", &a, &b);\r\n\t\t\t\
    swag.push({a, b});\r\n\t\t}\r\n\t\telse if (q == 1) swag.pop();\r\n\t\telse {\r\
    \n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\n\t\t\tauto res = swag.fold_all();\r\
    \n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\n\t\t}\r\n\t\
    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include \"DataStructure/SlidingWindowAggregation.hpp\"\r\n#include \"\
    Mathematics/ModInt.hpp\"\r\n\r\n#include <cstdio>\r\n#include <utility>\r\n\r\n\
    int main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\tusing P = std::pair<mint, mint>;\r\n\t\r\n\tSlidingWindowAggregation<P> swag({1,\
    \ 0}, [](const auto & x, const auto & y) -> P {\r\n\t\treturn {x.first * y.first,\
    \ x.second * y.first + y.second};\r\n\t});\r\n\t\r\n\twhile (Q--) {\r\n\t\tint\
    \ q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint a, b;\r\n\t\t\
    \tscanf(\"%d %d\", &a, &b);\r\n\t\t\tswag.push({a, b});\r\n\t\t}\r\n\t\telse if\
    \ (q == 1) swag.pop();\r\n\t\telse {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\
    \n\t\t\tauto res = swag.fold_all();\r\n\t\t\tprintf(\"%d\\n\", (res.first * x\
    \ + res.second).val());\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/SlidingWindowAggregation.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/Test/SlidingWindowAggregation.test.cpp
- /verify/Test/SlidingWindowAggregation.test.cpp.html
title: Test/SlidingWindowAggregation.test.cpp
---
