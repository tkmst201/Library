---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/Combination.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/11/20\r\n\r\n# \u4ED5\u69D8\r\ntemplate\u5F15\u6570 \u306B\u306F ModInt\
    \ \u3092\u6E21\u3059\u3002(require mod())\r\n\r\nTODO: r or n - r \u304C\u5C0F\
    \u3055\u3044\u3068\u304D\u306E \u0398(min(r, n - r)) \u611A\u76F4\u8A08\u7B97\u306E\
    \u8FFD\u52A0\r\n\r\nConstruct : Amortized \u0398(max k + (logM)^2 ) ??\r\nQuery\
    \ : Amortized \u0398(1) ?? \u8B0E\r\n\r\nComination(size_type sz = 1) :\r\n\t\
    sz! \u3092\u8A08\u7B97\u3067\u304D\u308B\u3060\u3051\u524D\u8A08\u7B97\r\n\r\n\
    T fact(size_type k) :\r\n\tk! \u3092\u6C42\u3081\u308B\r\n\r\nT finv(size_type\
    \ k) :\r\n\t(k!)^-1 \u3092\u6C42\u3081\u308B\r\n\r\nT inv(size_type k) :\r\n\t\
    k^-1 \u3092\u6C42\u3081\u308B\r\n\r\n:private:\r\nvoid build(size_type k) :\r\n\
    \tk! \u304C\u8A08\u7B97\u3067\u304D\u308B\u3088\u3046\u306B\u78BA\u4FDD\r\n*/\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n\
    template<typename T>\r\nstruct Combination {\r\npublic:\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\n\tCombination(size_type sz = 1) : fact_(1, 1), finv_(1,\
    \ 1), inv_(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type k) { if (k >= T::mod())\
    \ return 0; build(k); return fact_[k]; }\r\n\tT finv(size_type k) { assert(k <\
    \ T::mod()); build(k); return finv_[k]; }\r\n\tT inv(size_type k) { assert(k >\
    \ 0 && k < T::mod()); build(k); return inv_[k]; }\r\n\t\r\n\tT operator ()(int\
    \ n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r < 0 || n\
    \ < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tstd::vector<T> fact_, finv_, inv_;\r\n\tstatic constexpr size_type\
    \ MAX_LIMIT = 50000000;\r\n\t\r\n\tvoid build(size_type k) {\r\n\t\tif (fact_.size()\
    \ > k) return;\r\n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz = std::min({MAX_LIMIT,\
    \ static_cast<size_type>(T::mod()), std::max(fact_.size() * 2, k + 1)});\r\n\t\
    \tsize_type presz = fact_.size();\r\n\t\tfact_.resize(sz);\r\n\t\tfinv_.resize(sz);\r\
    \n\t\tinv_.resize(sz);\r\n\t\t\r\n\t\tfor (size_type i = presz; i < sz; ++i) fact_[i]\
    \ = fact_[i - 1] * i;\r\n\t\tfinv_[sz - 1] = T(fact_[sz - 1]).inv();\r\n\t\tfor\
    \ (size_type i = sz - 1; i > presz; --i) {\r\n\t\t\tfinv_[i - 1] = finv_[i] *\
    \ i;\r\n\t\t\tinv_[i] = fact_[i - 1] * finv_[i];\r\n\t\t}\r\n\t\tinv_[presz] =\
    \ fact_[presz - 1] * finv_[presz];\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_COMBINATION_HPP\r\n#define INCLUDE_GUARD_COMBINATION_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/20\r\n\r\n# \u4ED5\u69D8\r\ntemplate\u5F15\u6570\
    \ \u306B\u306F ModInt \u3092\u6E21\u3059\u3002(require mod())\r\n\r\nTODO: r or\
    \ n - r \u304C\u5C0F\u3055\u3044\u3068\u304D\u306E \u0398(min(r, n - r)) \u611A\
    \u76F4\u8A08\u7B97\u306E\u8FFD\u52A0\r\n\r\nConstruct : Amortized \u0398(max k\
    \ + (logM)^2 ) ??\r\nQuery : Amortized \u0398(1) ?? \u8B0E\r\n\r\nComination(size_type\
    \ sz = 1) :\r\n\tsz! \u3092\u8A08\u7B97\u3067\u304D\u308B\u3060\u3051\u524D\u8A08\
    \u7B97\r\n\r\nT fact(size_type k) :\r\n\tk! \u3092\u6C42\u3081\u308B\r\n\r\nT\
    \ finv(size_type k) :\r\n\t(k!)^-1 \u3092\u6C42\u3081\u308B\r\n\r\nT inv(size_type\
    \ k) :\r\n\tk^-1 \u3092\u6C42\u3081\u308B\r\n\r\n:private:\r\nvoid build(size_type\
    \ k) :\r\n\tk! \u304C\u8A08\u7B97\u3067\u304D\u308B\u3088\u3046\u306B\u78BA\u4FDD\
    \r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\
    \n\r\ntemplate<typename T>\r\nstruct Combination {\r\npublic:\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\n\tCombination(size_type sz = 1) : fact_(1, 1), finv_(1,\
    \ 1), inv_(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type k) { if (k >= T::mod())\
    \ return 0; build(k); return fact_[k]; }\r\n\tT finv(size_type k) { assert(k <\
    \ T::mod()); build(k); return finv_[k]; }\r\n\tT inv(size_type k) { assert(k >\
    \ 0 && k < T::mod()); build(k); return inv_[k]; }\r\n\t\r\n\tT operator ()(int\
    \ n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r < 0 || n\
    \ < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tstd::vector<T> fact_, finv_, inv_;\r\n\tstatic constexpr size_type\
    \ MAX_LIMIT = 50000000;\r\n\t\r\n\tvoid build(size_type k) {\r\n\t\tif (fact_.size()\
    \ > k) return;\r\n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz = std::min({MAX_LIMIT,\
    \ static_cast<size_type>(T::mod()), std::max(fact_.size() * 2, k + 1)});\r\n\t\
    \tsize_type presz = fact_.size();\r\n\t\tfact_.resize(sz);\r\n\t\tfinv_.resize(sz);\r\
    \n\t\tinv_.resize(sz);\r\n\t\t\r\n\t\tfor (size_type i = presz; i < sz; ++i) fact_[i]\
    \ = fact_[i - 1] * i;\r\n\t\tfinv_[sz - 1] = T(fact_[sz - 1]).inv();\r\n\t\tfor\
    \ (size_type i = sz - 1; i > presz; --i) {\r\n\t\t\tfinv_[i - 1] = finv_[i] *\
    \ i;\r\n\t\t\tinv_[i] = fact_[i - 1] * finv_[i];\r\n\t\t}\r\n\t\tinv_[presz] =\
    \ fact_[presz - 1] * finv_[presz];\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_COMBINATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Combination.hpp
  requiredBy: []
  timestamp: '2020-11-20 23:55:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/Combination.hpp
layout: document
redirect_from:
- /library/Mathematics/Combination.hpp
- /library/Mathematics/Combination.hpp.html
title: Mathematics/Combination.hpp
---
