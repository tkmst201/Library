---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LazySegmentTree.test.cpp
    title: Test/LazySegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Matrix_Determinant.test.cpp
    title: Test/Matrix_Determinant.test.cpp
  - icon: ':x:'
    path: Test/PrimeNumber.counting_primes.test.cpp
    title: Test/PrimeNumber.counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DynamicSegmentTree.test.cpp
    title: Test/DynamicSegmentTree.test.cpp
  - icon: ':x:'
    path: Test/SlidingWindowAggregation.test.cpp
    title: Test/SlidingWindowAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SegmentTree.fold.test.cpp
    title: Test/SegmentTree.fold.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/02/26\r\
    \n\r\n# \u4ED5\u69D8\r\nModInt(long long val = 0) : \u8CA0\u306E\u6574\u6570\u306B\
    \u3082\u5BFE\u5FDC\u3057\u305F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\
    \nModInt pow(long long n) const : O(log n) n \u4E57\u3057\u305F\u5024\u3092\u8FD4\
    \u3059(\u8CA0\u306E\u6574\u6570\u3082\u5BFE\u5FDC)\r\nModInt inverse() const :\
    \ O(log n) \u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\
    \r\nconst value_type & get() const noexcept\r\nvalue_type & get() noexcept : \u5024\
    \u3092\u8FD4\u3059\r\n\r\nstatic decltype(M) get_mod() noexcept : \u6CD5 M \u3092\
    \u8FD4\u3059\r\n\r\nexplicit operator bool() const noexcept : bool\u3078\u578B\
    \u5909\u63DB 0\u4EE5\u5916\u306E\u3068\u304DTrue\r\noperator ==() const noexcept\r\
    \noperator !=() const noexcept\r\noperator +() const noexept\r\noperator -() const\
    \ noexept\r\noperator +(const ModInt & rhs) const noexept\r\noperator -(const\
    \ ModInt & rhs) const noexept\r\noperator *(const ModInt & rhs) const noexept\r\
    \noperator /(const ModInt & rhs) const noexept\r\nModInt & operator +=(const ModInt\
    \ & rhs) const noexept\r\nModInt & operator +=(const ModInt & rhs) const noexept\
    \ :\r\n\r\nfriend std::ostream & operator <<(std::ostream & os, const ModInt &\
    \ rhs)\r\nfriend std::istream & operator >>(std::istream & is, ModInt & rhs) :\r\
    \n\t\u5165\u51FA\u529B\u7528\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n\r\ntemplate<int M>\r\
    \nstruct ModInt {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\tModInt(value_type\
    \ val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}\r\n\t\r\n\texplicit\
    \ operator bool() const noexcept { return val; }\r\n\tbool operator ==(const ModInt\
    \ & rhs) const noexcept { return val == rhs.val; }\r\n\tbool operator !=(const\
    \ ModInt & rhs) const noexcept { return !(*this == rhs); }\r\n\tModInt operator\
    \ +() const noexcept { return ModInt(*this); }\r\n\tModInt operator -() const\
    \ noexcept { return ModInt(0) -= *this; }\r\n\tModInt operator +(const ModInt\
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
    \ val;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_MOD_INT_HPP\r\n#define INCLUDE_GUARD_MOD_INT_HPP\r\n\
    \r\n/*\r\nlast-updated: 2020/02/26\r\n\r\n# \u4ED5\u69D8\r\nModInt(long long val\
    \ = 0) : \u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nModInt pow(long long n) const : O(log n)\
    \ n \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059(\u8CA0\u306E\u6574\u6570\u3082\u5BFE\
    \u5FDC)\r\nModInt inverse() const : O(log n) \u6CD5 M \u306E\u5143\u3067\u306E\
    \u9006\u5143\u3092\u8FD4\u3059\r\n\r\nconst value_type & get() const noexcept\r\
    \nvalue_type & get() noexcept : \u5024\u3092\u8FD4\u3059\r\n\r\nstatic decltype(M)\
    \ get_mod() noexcept : \u6CD5 M \u3092\u8FD4\u3059\r\n\r\nexplicit operator bool()\
    \ const noexcept : bool\u3078\u578B\u5909\u63DB 0\u4EE5\u5916\u306E\u3068\u304D\
    True\r\noperator ==() const noexcept\r\noperator !=() const noexcept\r\noperator\
    \ +() const noexept\r\noperator -() const noexept\r\noperator +(const ModInt &\
    \ rhs) const noexept\r\noperator -(const ModInt & rhs) const noexept\r\noperator\
    \ *(const ModInt & rhs) const noexept\r\noperator /(const ModInt & rhs) const\
    \ noexept\r\nModInt & operator +=(const ModInt & rhs) const noexept\r\nModInt\
    \ & operator +=(const ModInt & rhs) const noexept :\r\n\r\nfriend std::ostream\
    \ & operator <<(std::ostream & os, const ModInt & rhs)\r\nfriend std::istream\
    \ & operator >>(std::istream & is, ModInt & rhs) :\r\n\t\u5165\u51FA\u529B\u7528\
    \r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n\r\ntemplate<int M>\r\
    \nstruct ModInt {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\tModInt(value_type\
    \ val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}\r\n\t\r\n\texplicit\
    \ operator bool() const noexcept { return val; }\r\n\tbool operator ==(const ModInt\
    \ & rhs) const noexcept { return val == rhs.val; }\r\n\tbool operator !=(const\
    \ ModInt & rhs) const noexcept { return !(*this == rhs); }\r\n\tModInt operator\
    \ +() const noexcept { return ModInt(*this); }\r\n\tModInt operator -() const\
    \ noexcept { return ModInt(0) -= *this; }\r\n\tModInt operator +(const ModInt\
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
    \ val;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_MOD_INT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/ModInt.hpp
  requiredBy: []
  timestamp: '2020-09-17 16:57:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/LazySegmentTree.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - Test/Matrix_Determinant.test.cpp
  - Test/PrimeNumber.counting_primes.test.cpp
  - Test/DynamicSegmentTree.test.cpp
  - Test/SlidingWindowAggregation.test.cpp
  - Test/SegmentTree.fold.test.cpp
documentation_of: Mathematics/ModInt.hpp
layout: document
redirect_from:
- /library/Mathematics/ModInt.hpp
- /library/Mathematics/ModInt.hpp.html
title: Mathematics/ModInt.hpp
---
