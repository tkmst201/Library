---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 1 \"Mathematics/RuntimeModInt.hpp\"\n\n\n\r\n#include <cassert>\r\
    \n#include <iostream>\r\n\r\n/*\r\nlast-updated: 2020/02/26\r\n\r\n# \u4ED5\u69D8\
    \r\nRuntimeModInt(long long val = 0) : \u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\
    \u5FDC\u3057\u305F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nRuntimeModInt\
    \ pow(long long n) const : O(log n) n \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059\
    (\u8CA0\u306E\u6574\u6570\u3082\u5BFE\u5FDC)\r\nRuntimeModInt inverse() const\
    \ : O(log n) \u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\u3092\u8FD4\u3059\r\
    \n\r\nconst value_type & get() const noexcept\r\nvalue_type & get() noexcept :\
    \ \u5024\u3092\u8FD4\u3059\r\n\r\nstatic void set_mod(int M) noexcept { mod()\
    \ = M; } : \u6CD5 M \u3092\u30BB\u30C3\u30C8\u3059\u308B\r\nstatic int get_mod()\
    \ noexcept { return mod(); } : \u6CD5 M \u3092\u8FD4\u3059\r\n\r\nexplicit operator\
    \ bool() const noexcept : bool\u3078\u578B\u5909\u63DB 0\u4EE5\u5916\u306E\u3068\
    \u304DTrue\r\noperator ==() const noexcept\r\noperator !=() const noexcept\r\n\
    operator +() const noexept\r\noperator -() const noexept\r\noperator +(const RuntimeModInt\
    \ & rhs) const noexept\r\noperator -(const RuntimeModInt & rhs) const noexept\r\
    \noperator *(const RuntimeModInt & rhs) const noexept\r\noperator /(const RuntimeModInt\
    \ & rhs) const noexept\r\nRuntimeModInt & operator +=(const RuntimeModInt & rhs)\
    \ const noexept\r\nRuntimeModInt & operator +=(const RuntimeModInt & rhs) const\
    \ noexept :\r\n\r\nfriend std::ostream & operator <<(std::ostream & os, const\
    \ RuntimeModInt & rhs)\r\nfriend std::istream & operator >>(std::istream & is,\
    \ RuntimeModInt & rhs) :\r\n\t\u5165\u51FA\u529B\u7528\r\n\r\n# \u53C2\u8003\r\
    \nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n*/\r\n\r\nstruct RuntimeModInt\
    \ {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\tRuntimeModInt(value_type\
    \ val = 0) : val(val < 0 ? (mod() - (-val % mod())) % mod() : val % mod()) {}\r\
    \n\t\r\n\texplicit operator bool() const noexcept { return val; }\r\n\tbool operator\
    \ ==(const RuntimeModInt & rhs) const noexcept { return val == rhs.val; }\r\n\t\
    bool operator !=(const RuntimeModInt & rhs) const noexcept { return !(*this ==\
    \ rhs); }\r\n\tRuntimeModInt operator +() const noexcept { return RuntimeModInt(*this);\
    \ }\r\n\tRuntimeModInt operator -() const noexcept { return RuntimeModInt(0) -=\
    \ *this; }\r\n\tRuntimeModInt operator +(const RuntimeModInt & rhs) const noexcept\
    \ { return RuntimeModInt(*this) += rhs; }\r\n\tRuntimeModInt operator -(const\
    \ RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) -= rhs; }\r\
    \n\tRuntimeModInt operator *(const RuntimeModInt & rhs) const noexcept { return\
    \ RuntimeModInt(*this) *= rhs; }\r\n\tRuntimeModInt operator /(const RuntimeModInt\
    \ & rhs) const noexcept { return RuntimeModInt(*this) /= rhs; }\r\n\t\r\n\tRuntimeModInt\
    \ & operator +=(const RuntimeModInt & rhs) noexcept {\r\n\t\tval += rhs.val;\r\
    \n\t\tif (val >= mod()) val -= mod();\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt\
    \ & operator -=(const RuntimeModInt & rhs) noexcept {\r\n\t\tif (val < rhs.val)\
    \ val += mod();\r\n\t\tval -= rhs.val;\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt\
    \ & operator *=(const RuntimeModInt & rhs) noexcept {\r\n\t\tval = val * rhs.val\
    \ % mod();\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt & operator /=(const\
    \ RuntimeModInt & rhs) noexcept {\r\n\t\t*this *= rhs.inverse();\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\tRuntimeModInt pow(value_type n) const {\r\n\t\tRuntimeModInt\
    \ res = 1, x = val;\r\n\t\tif (n < 0) { x = x.inverse(); n = -n; }\r\n\t\twhile\
    \ (n) { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tRuntimeModInt inverse() const {\r\n\t\tlong long a = val, a1 = 1, a2 = 0,\
    \ b = mod(), b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q = a\
    \ / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\n\
    \t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\n\
    \t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n\t\r\n\tconst value_type\
    \ & get() const noexcept { return val; }\r\n\tstatic void set_mod(int M) noexcept\
    \ { mod() = M; }\r\n\tstatic int get_mod() noexcept { return mod(); }\r\n\t\r\n\
    \tfriend std::ostream & operator <<(std::ostream & os, const RuntimeModInt & rhs)\
    \ { return os << rhs.val; }\r\n\tfriend std::istream & operator >>(std::istream\
    \ & is, RuntimeModInt & rhs) {\r\n\t\tvalue_type x;\r\n\t\tis >> x;\r\n\t\trhs\
    \ = RuntimeModInt(x);\r\n\t\treturn is;\r\n\t}\r\nprivate:\r\n\tvalue_type val;\r\
    \n\t\r\n\tstatic int & mod() {\r\n\t\tstatic int M = 2;\r\n\t\treturn M;\r\n\t\
    }\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_RUNTIME_MOD_INT_HPP\r\n#define INCLUDE_GUARD_RUNTIME_MOD_INT_HPP\r\
    \n\r\n#include <cassert>\r\n#include <iostream>\r\n\r\n/*\r\nlast-updated: 2020/02/26\r\
    \n\r\n# \u4ED5\u69D8\r\nRuntimeModInt(long long val = 0) : \u8CA0\u306E\u6574\u6570\
    \u306B\u3082\u5BFE\u5FDC\u3057\u305F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \r\n\r\nRuntimeModInt pow(long long n) const : O(log n) n \u4E57\u3057\u305F\u5024\
    \u3092\u8FD4\u3059(\u8CA0\u306E\u6574\u6570\u3082\u5BFE\u5FDC)\r\nRuntimeModInt\
    \ inverse() const : O(log n) \u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\u3092\
    \u8FD4\u3059\r\n\r\nconst value_type & get() const noexcept\r\nvalue_type & get()\
    \ noexcept : \u5024\u3092\u8FD4\u3059\r\n\r\nstatic void set_mod(int M) noexcept\
    \ { mod() = M; } : \u6CD5 M \u3092\u30BB\u30C3\u30C8\u3059\u308B\r\nstatic int\
    \ get_mod() noexcept { return mod(); } : \u6CD5 M \u3092\u8FD4\u3059\r\n\r\nexplicit\
    \ operator bool() const noexcept : bool\u3078\u578B\u5909\u63DB 0\u4EE5\u5916\u306E\
    \u3068\u304DTrue\r\noperator ==() const noexcept\r\noperator !=() const noexcept\r\
    \noperator +() const noexept\r\noperator -() const noexept\r\noperator +(const\
    \ RuntimeModInt & rhs) const noexept\r\noperator -(const RuntimeModInt & rhs)\
    \ const noexept\r\noperator *(const RuntimeModInt & rhs) const noexept\r\noperator\
    \ /(const RuntimeModInt & rhs) const noexept\r\nRuntimeModInt & operator +=(const\
    \ RuntimeModInt & rhs) const noexept\r\nRuntimeModInt & operator +=(const RuntimeModInt\
    \ & rhs) const noexept :\r\n\r\nfriend std::ostream & operator <<(std::ostream\
    \ & os, const RuntimeModInt & rhs)\r\nfriend std::istream & operator >>(std::istream\
    \ & is, RuntimeModInt & rhs) :\r\n\t\u5165\u51FA\u529B\u7528\r\n\r\n# \u53C2\u8003\
    \r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n*/\r\n\r\nstruct\
    \ RuntimeModInt {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\tRuntimeModInt(value_type\
    \ val = 0) : val(val < 0 ? (mod() - (-val % mod())) % mod() : val % mod()) {}\r\
    \n\t\r\n\texplicit operator bool() const noexcept { return val; }\r\n\tbool operator\
    \ ==(const RuntimeModInt & rhs) const noexcept { return val == rhs.val; }\r\n\t\
    bool operator !=(const RuntimeModInt & rhs) const noexcept { return !(*this ==\
    \ rhs); }\r\n\tRuntimeModInt operator +() const noexcept { return RuntimeModInt(*this);\
    \ }\r\n\tRuntimeModInt operator -() const noexcept { return RuntimeModInt(0) -=\
    \ *this; }\r\n\tRuntimeModInt operator +(const RuntimeModInt & rhs) const noexcept\
    \ { return RuntimeModInt(*this) += rhs; }\r\n\tRuntimeModInt operator -(const\
    \ RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) -= rhs; }\r\
    \n\tRuntimeModInt operator *(const RuntimeModInt & rhs) const noexcept { return\
    \ RuntimeModInt(*this) *= rhs; }\r\n\tRuntimeModInt operator /(const RuntimeModInt\
    \ & rhs) const noexcept { return RuntimeModInt(*this) /= rhs; }\r\n\t\r\n\tRuntimeModInt\
    \ & operator +=(const RuntimeModInt & rhs) noexcept {\r\n\t\tval += rhs.val;\r\
    \n\t\tif (val >= mod()) val -= mod();\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt\
    \ & operator -=(const RuntimeModInt & rhs) noexcept {\r\n\t\tif (val < rhs.val)\
    \ val += mod();\r\n\t\tval -= rhs.val;\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt\
    \ & operator *=(const RuntimeModInt & rhs) noexcept {\r\n\t\tval = val * rhs.val\
    \ % mod();\r\n\t\treturn *this;\r\n\t}\r\n\tRuntimeModInt & operator /=(const\
    \ RuntimeModInt & rhs) noexcept {\r\n\t\t*this *= rhs.inverse();\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\tRuntimeModInt pow(value_type n) const {\r\n\t\tRuntimeModInt\
    \ res = 1, x = val;\r\n\t\tif (n < 0) { x = x.inverse(); n = -n; }\r\n\t\twhile\
    \ (n) { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tRuntimeModInt inverse() const {\r\n\t\tlong long a = val, a1 = 1, a2 = 0,\
    \ b = mod(), b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q = a\
    \ / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\n\
    \t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\n\
    \t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n\t\r\n\tconst value_type\
    \ & get() const noexcept { return val; }\r\n\tstatic void set_mod(int M) noexcept\
    \ { mod() = M; }\r\n\tstatic int get_mod() noexcept { return mod(); }\r\n\t\r\n\
    \tfriend std::ostream & operator <<(std::ostream & os, const RuntimeModInt & rhs)\
    \ { return os << rhs.val; }\r\n\tfriend std::istream & operator >>(std::istream\
    \ & is, RuntimeModInt & rhs) {\r\n\t\tvalue_type x;\r\n\t\tis >> x;\r\n\t\trhs\
    \ = RuntimeModInt(x);\r\n\t\treturn is;\r\n\t}\r\nprivate:\r\n\tvalue_type val;\r\
    \n\t\r\n\tstatic int & mod() {\r\n\t\tstatic int M = 2;\r\n\t\treturn M;\r\n\t\
    }\r\n};\r\n\r\n#endif // INCLUDE_GUARD_RUNTIME_MOD_INT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/RuntimeModInt.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/RuntimeModInt.hpp
layout: document
redirect_from:
- /library/Mathematics/RuntimeModInt.hpp
- /library/Mathematics/RuntimeModInt.hpp.html
title: Mathematics/RuntimeModInt.hpp
---
