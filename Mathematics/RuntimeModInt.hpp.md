---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 1 \"Mathematics/RuntimeModInt.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/11/21\r\n\r\n\u81EA\u52D5\u3067 mod \u3092\u53D6\u3063\u3066\u304F\u308C\
    \u308B\u4FBF\u5229\u306A\u3082\u306E\r\n\u5B9F\u884C\u6642\u306B mod \u3092\u6307\
    \u5B9A\u3067\u304D\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\n\u57FA\u672C\u7684\u306A\
    \u6F14\u7B97\u306F\u3060\u3044\u305F\u3044\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    \u3002\r\n\u6A19\u6E96\u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0 std::cin,\
    \ std::cout \u306B\u3082\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\r\ntemplate\
    \ \u5F15\u6570\u306E ID \u306B\u3088\u308A\u305D\u308C\u305E\u308C\u7570\u306A\
    \u308B mod \u3092\u53D6\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\r\n\r\n\
    constexpr ModInt(std::int_fast64_t val = 0)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nstatic void set_mod(int M) noexcept\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M \u306B\u5909\u66F4\
    (default \u306F 2)\r\n\t\u5FC5\u305A\u4F7F\u7528\u524D\u306B set_mod \u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u3002\r\n\r\nstatic int mod() noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M \u3092\u8FD4\u3059\r\n\r\nconstexpr\
    \ const value_type & val() noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u5024\u3092 int \u3067\u8FD4\u3059\r\n\r\nconstexpr ModInt pow(std::int_fast64_t\
    \ n) const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5236\u7D04\
    : n < 0 \u306E\u3068\u304D\u3001inv() \u306E\u5236\u7D04\u306B\u5F93\u3046\u3002\
    \r\n\tn \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059(n < 0 \u306B\u3082\u5BFE\u5FDC\
    )\r\n\r\nconstexpr ModInt inv() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log M)\r\n\t\u5236\u7D04: \u5024\u3068 M \u304C\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B(M \u304C\u7D20\u6570\u306A\u3089\u554F\
    \u984C\u306F\u306A\u3044)\u3002\r\n\t\u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n#include <cstdint>\r\n\
    \r\ntemplate<int ID>\r\nstruct RuntimeModInt {\r\npublic:\r\n\tusing value_type\
    \ = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\nprivate:\r\n\tvalue_type\
    \ val_;\r\n\tstatic int & mod_() noexcept { static int M = 2; return M; }\r\n\t\
    \r\npublic:\r\n\tRuntimeModInt(calc_type val = 0) : val_(val < 0 ? (val % mod()\
    \ + mod()) % mod() : val % mod()) {}\r\n\tconst value_type & val() const noexcept\
    \ { return val_; }\r\n\tstatic void set_mod(int M) noexcept { assert(M > 0); mod_()\
    \ = M; }\r\n\tstatic int mod() noexcept { return mod_(); }\r\n\t\r\n\texplicit\
    \ operator bool() const noexcept { return val_; }\r\n\tbool operator !() const\
    \ noexcept { return !static_cast<bool>(*this); }\r\n\tRuntimeModInt operator +()\
    \ const noexcept { return RuntimeModInt(*this); }\r\n\tRuntimeModInt operator\
    \ -() const noexcept { return RuntimeModInt(-val_); }\r\n\tRuntimeModInt operator\
    \ ++(int) noexcept { RuntimeModInt res = *this; ++*this; return res; }\r\n\tRuntimeModInt\
    \ operator --(int) noexcept { RuntimeModInt res = *this; --*this; return res;\
    \ }\r\n\tRuntimeModInt & operator ++() noexcept { val_ = val_ + 1 == mod() ? 0\
    \ : val_ + 1; return *this; }\r\n\tRuntimeModInt & operator --() noexcept { val_\
    \ = val_ == 0 ? mod() - 1 : val_ - 1; return *this; }\r\n\tRuntimeModInt & operator\
    \ +=(const RuntimeModInt & rhs) noexcept { val_ += val_ < mod() - rhs.val_ ? rhs.val_\
    \ : rhs.val_ - mod(); return *this; }\r\n\tRuntimeModInt & operator -=(const RuntimeModInt\
    \ & rhs) noexcept { val_ += val_ >= rhs.val_ ? -rhs.val_ : mod() - rhs.val_; return\
    \ *this; }\r\n\tRuntimeModInt & operator *=(const RuntimeModInt & rhs) noexcept\
    \ { val_ = static_cast<calc_type>(val_) * rhs.val_ % mod(); return *this; }\r\n\
    \tRuntimeModInt & operator /=(const RuntimeModInt & rhs) noexcept { return *this\
    \ *= rhs.inv(); }\r\n\tfriend RuntimeModInt operator +(const RuntimeModInt & lhs,\
    \ const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) += rhs; }\r\n\
    \tfriend RuntimeModInt operator -(const RuntimeModInt & lhs, const RuntimeModInt\
    \ & rhs) noexcept { return RuntimeModInt(lhs) -= rhs; }\r\n\tfriend RuntimeModInt\
    \ operator *(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept {\
    \ return RuntimeModInt(lhs) *= rhs; }\r\n\tfriend RuntimeModInt operator /(const\
    \ RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs)\
    \ /= rhs; }\r\n\tfriend bool operator ==(const RuntimeModInt & lhs, const RuntimeModInt\
    \ & rhs) noexcept { return lhs.val_ == rhs.val_; }\r\n\tfriend bool operator !=(const\
    \ RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return !(lhs == rhs);\
    \ }\r\n\tfriend std::ostream & operator <<(std::ostream & os, const RuntimeModInt\
    \ & rhs) { return os << rhs.val_; }\r\n\tfriend std::istream & operator >>(std::istream\
    \ & is, RuntimeModInt & rhs) { calc_type x; is >> x; rhs = RuntimeModInt(x); return\
    \ is; }\r\n\t\r\n\tRuntimeModInt pow(calc_type n) const noexcept {\r\n\t\tRuntimeModInt\
    \ res = 1, x = val_;\r\n\t\tif (n < 0) { x = x.inv(); n = -n; }\r\n\t\twhile (n)\
    \ { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    \tRuntimeModInt inv() const noexcept {\r\n\t\tvalue_type a = val_, a1 = 1, a2\
    \ = 0, b = mod(), b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q\
    \ = a / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\
    \n\t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_RUNTIME_MOD_INT_HPP\r\n#define INCLUDE_GUARD_RUNTIME_MOD_INT_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/21\r\n\r\n\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u3063\u3066\u304F\u308C\u308B\u4FBF\u5229\u306A\u3082\u306E\r\n\u5B9F\u884C\u6642\
    \u306B mod \u3092\u6307\u5B9A\u3067\u304D\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\n\
    \u57FA\u672C\u7684\u306A\u6F14\u7B97\u306F\u3060\u3044\u305F\u3044\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\u3002\r\n\u6A19\u6E96\u5165\u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0 std::cin, std::cout \u306B\u3082\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    \u3002\r\ntemplate \u5F15\u6570\u306E ID \u306B\u3088\u308A\u305D\u308C\u305E\u308C\
    \u7570\u306A\u308B mod \u3092\u53D6\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \r\n\r\nconstexpr ModInt(std::int_fast64_t val = 0)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nstatic void set_mod(int M) noexcept\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M \u306B\u5909\u66F4\
    (default \u306F 2)\r\n\t\u5FC5\u305A\u4F7F\u7528\u524D\u306B set_mod \u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u3002\r\n\r\nstatic int mod() noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M \u3092\u8FD4\u3059\r\n\r\nconstexpr\
    \ const value_type & val() noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u5024\u3092 int \u3067\u8FD4\u3059\r\n\r\nconstexpr ModInt pow(std::int_fast64_t\
    \ n) const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5236\u7D04\
    : n < 0 \u306E\u3068\u304D\u3001inv() \u306E\u5236\u7D04\u306B\u5F93\u3046\u3002\
    \r\n\tn \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059(n < 0 \u306B\u3082\u5BFE\u5FDC\
    )\r\n\r\nconstexpr ModInt inv() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log M)\r\n\t\u5236\u7D04: \u5024\u3068 M \u304C\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B(M \u304C\u7D20\u6570\u306A\u3089\u554F\
    \u984C\u306F\u306A\u3044)\u3002\r\n\t\u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n#include <cstdint>\r\n\
    \r\ntemplate<int ID>\r\nstruct RuntimeModInt {\r\npublic:\r\n\tusing value_type\
    \ = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\nprivate:\r\n\tvalue_type\
    \ val_;\r\n\tstatic int & mod_() noexcept { static int M = 2; return M; }\r\n\t\
    \r\npublic:\r\n\tRuntimeModInt(calc_type val = 0) : val_(val < 0 ? (val % mod()\
    \ + mod()) % mod() : val % mod()) {}\r\n\tconst value_type & val() const noexcept\
    \ { return val_; }\r\n\tstatic void set_mod(int M) noexcept { assert(M > 0); mod_()\
    \ = M; }\r\n\tstatic int mod() noexcept { return mod_(); }\r\n\t\r\n\texplicit\
    \ operator bool() const noexcept { return val_; }\r\n\tbool operator !() const\
    \ noexcept { return !static_cast<bool>(*this); }\r\n\tRuntimeModInt operator +()\
    \ const noexcept { return RuntimeModInt(*this); }\r\n\tRuntimeModInt operator\
    \ -() const noexcept { return RuntimeModInt(-val_); }\r\n\tRuntimeModInt operator\
    \ ++(int) noexcept { RuntimeModInt res = *this; ++*this; return res; }\r\n\tRuntimeModInt\
    \ operator --(int) noexcept { RuntimeModInt res = *this; --*this; return res;\
    \ }\r\n\tRuntimeModInt & operator ++() noexcept { val_ = val_ + 1 == mod() ? 0\
    \ : val_ + 1; return *this; }\r\n\tRuntimeModInt & operator --() noexcept { val_\
    \ = val_ == 0 ? mod() - 1 : val_ - 1; return *this; }\r\n\tRuntimeModInt & operator\
    \ +=(const RuntimeModInt & rhs) noexcept { val_ += val_ < mod() - rhs.val_ ? rhs.val_\
    \ : rhs.val_ - mod(); return *this; }\r\n\tRuntimeModInt & operator -=(const RuntimeModInt\
    \ & rhs) noexcept { val_ += val_ >= rhs.val_ ? -rhs.val_ : mod() - rhs.val_; return\
    \ *this; }\r\n\tRuntimeModInt & operator *=(const RuntimeModInt & rhs) noexcept\
    \ { val_ = static_cast<calc_type>(val_) * rhs.val_ % mod(); return *this; }\r\n\
    \tRuntimeModInt & operator /=(const RuntimeModInt & rhs) noexcept { return *this\
    \ *= rhs.inv(); }\r\n\tfriend RuntimeModInt operator +(const RuntimeModInt & lhs,\
    \ const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) += rhs; }\r\n\
    \tfriend RuntimeModInt operator -(const RuntimeModInt & lhs, const RuntimeModInt\
    \ & rhs) noexcept { return RuntimeModInt(lhs) -= rhs; }\r\n\tfriend RuntimeModInt\
    \ operator *(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept {\
    \ return RuntimeModInt(lhs) *= rhs; }\r\n\tfriend RuntimeModInt operator /(const\
    \ RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs)\
    \ /= rhs; }\r\n\tfriend bool operator ==(const RuntimeModInt & lhs, const RuntimeModInt\
    \ & rhs) noexcept { return lhs.val_ == rhs.val_; }\r\n\tfriend bool operator !=(const\
    \ RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return !(lhs == rhs);\
    \ }\r\n\tfriend std::ostream & operator <<(std::ostream & os, const RuntimeModInt\
    \ & rhs) { return os << rhs.val_; }\r\n\tfriend std::istream & operator >>(std::istream\
    \ & is, RuntimeModInt & rhs) { calc_type x; is >> x; rhs = RuntimeModInt(x); return\
    \ is; }\r\n\t\r\n\tRuntimeModInt pow(calc_type n) const noexcept {\r\n\t\tRuntimeModInt\
    \ res = 1, x = val_;\r\n\t\tif (n < 0) { x = x.inv(); n = -n; }\r\n\t\twhile (n)\
    \ { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    \tRuntimeModInt inv() const noexcept {\r\n\t\tvalue_type a = val_, a1 = 1, a2\
    \ = 0, b = mod(), b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q\
    \ = a / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\
    \n\t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n#endif //\
    \ INCLUDE_GUARD_RUNTIME_MOD_INT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/RuntimeModInt.hpp
  requiredBy: []
  timestamp: '2020-11-21 12:26:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/RuntimeModInt.hpp
layout: document
redirect_from:
- /library/Mathematics/RuntimeModInt.hpp
- /library/Mathematics/RuntimeModInt.hpp.html
title: Mathematics/RuntimeModInt.hpp
---
