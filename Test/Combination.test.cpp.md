---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B $_nC_r$"
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
    PROBLEM: https://yukicoder.me/problems/no/1181
    links:
    - https://yukicoder.me/problems/no/1181
  bundledCode: "#line 1 \"Test/Combination.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1181\"\
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
    #line 1 \"Mathematics/Combination.hpp\"\n\n\n\r\n#include <vector>\r\n#line 6\
    \ \"Mathematics/Combination.hpp\"\n#include <algorithm>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/Mathematics/Combination.hpp\r\n */\r\ntemplate<typename\
    \ T>\r\nstruct Combination {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tstd::vector<T> fact_, finv_, inv_;\r\n\tstatic constexpr size_type MAX_LIMIT\
    \ = 50000000;\r\n\t\r\npublic:\r\n\texplicit Combination(size_type sz = 1) : fact_(1,\
    \ 1), finv_(1, 1), inv_(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type k) {\
    \ if (k >= T::mod()) return 0; build(k); return fact_[k]; }\r\n\tT finv(size_type\
    \ k) { assert(k < T::mod()); build(k); return finv_[k]; }\r\n\tT inv(size_type\
    \ k) { assert(k > 0 && k < T::mod()); build(k); return inv_[k]; }\r\n\tT operator\
    \ ()(int n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r <\
    \ 0 || n < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tvoid build(size_type k) {\r\n\t\tif (fact_.size() > k) return;\r\
    \n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::mod()),\
    \ std::max(fact_.size() * 2, k + 1)});\r\n\t\tsize_type presz = fact_.size();\r\
    \n\t\tfact_.resize(sz);\r\n\t\tfinv_.resize(sz);\r\n\t\tinv_.resize(sz);\r\n\t\
    \tfor (size_type i = presz; i < sz; ++i) fact_[i] = fact_[i - 1] * i;\r\n\t\t\
    finv_[sz - 1] = fact_[sz - 1].inv();\r\n\t\tfor (size_type i = sz - 1; i > presz;\
    \ --i) {\r\n\t\t\tfinv_[i - 1] = finv_[i] * i;\r\n\t\t\tinv_[i] = fact_[i - 1]\
    \ * finv_[i];\r\n\t\t}\r\n\t\tinv_[presz] = fact_[presz - 1] * finv_[presz];\r\
    \n\t}\r\n};\r\n\r\n\n#line 5 \"Test/Combination.test.cpp\"\n\r\n#include <cstdio>\r\
    \n#line 8 \"Test/Combination.test.cpp\"\n\r\nconstexpr int MOD = 1000000007;\r\
    \nusing mint = ModInt<MOD>;\r\nCombination<mint> comb;\r\nusing ll = long long;\r\
    \n\r\nint main() {\r\n\tint N;\r\n\tll K;\r\n\tscanf(\"%d %lld\", &N, &K);\r\n\
    \tK %= MOD;\r\n\t\r\n\tmint sum = mint(1 + K) * K / 2;\r\n\tstd::vector<mint>\
    \ powk(N + 1);\r\n\tpowk[0] = 1;\r\n\tfor (int i = 1; i < N; ++i) powk[i] = powk[i\
    \ - 1] * K;\r\n\tmint ans = mint(K).pow(N), p = 1;\r\n\tfor (int i = 0; i < N;\
    \ ++i) {\r\n\t\tmint pat = comb(N, i) * powk[N - i];\r\n\t\tans += pat * p;\r\n\
    \t\tp *= sum;\r\n\t}\r\n\tprintf(\"%d\\n\", ans.val());\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1181\"\r\n\r\n#include\
    \ \"Mathematics/ModInt.hpp\"\r\n#include \"Mathematics/Combination.hpp\"\r\n\r\
    \n#include <cstdio>\r\n#include <vector>\r\n\r\nconstexpr int MOD = 1000000007;\r\
    \nusing mint = ModInt<MOD>;\r\nCombination<mint> comb;\r\nusing ll = long long;\r\
    \n\r\nint main() {\r\n\tint N;\r\n\tll K;\r\n\tscanf(\"%d %lld\", &N, &K);\r\n\
    \tK %= MOD;\r\n\t\r\n\tmint sum = mint(1 + K) * K / 2;\r\n\tstd::vector<mint>\
    \ powk(N + 1);\r\n\tpowk[0] = 1;\r\n\tfor (int i = 1; i < N; ++i) powk[i] = powk[i\
    \ - 1] * K;\r\n\tmint ans = mint(K).pow(N), p = 1;\r\n\tfor (int i = 0; i < N;\
    \ ++i) {\r\n\t\tmint pat = comb(N, i) * powk[N - i];\r\n\t\tans += pat * p;\r\n\
    \t\tp *= sum;\r\n\t}\r\n\tprintf(\"%d\\n\", ans.val());\r\n}"
  dependsOn:
  - Mathematics/ModInt.hpp
  - Mathematics/Combination.hpp
  isVerificationFile: true
  path: Test/Combination.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Combination.test.cpp
layout: document
redirect_from:
- /verify/Test/Combination.test.cpp
- /verify/Test/Combination.test.cpp.html
title: Test/Combination.test.cpp
---
