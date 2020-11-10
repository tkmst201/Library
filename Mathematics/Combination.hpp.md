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
    \ 2020/01/15\r\n\r\n# \u4ED5\u69D8\r\ntemplate\u5F15\u6570 \u306B\u306F ModInt\
    \ \u3092\u6E21\u3059\u3002(require get_mod())\r\n\r\nTODO: r or n - r \u304C\u5C0F\
    \u3055\u3044\u3068\u304D\u306E\u611A\u76F4\u8A08\u7B97\u306E\u8FFD\u52A0\r\n\r\
    \nConstruct : Amortized \u0398(max k + (logM)^2 ) ??\r\nQuery : Amortized \u0398\
    (1) ?? \u8B0E\r\n\r\nComination(size_type sz = 1) :\r\n\tsz! \u3092\u8A08\u7B97\
    \u3067\u304D\u308B\u3060\u3051\u524D\u8A08\u7B97\r\n\r\nT fact(size_type k) :\r\
    \n\tk! \u3092\u6C42\u3081\u308B\r\n\r\nT finv(size_type k) :\r\n\t(k!)^-1 \u3092\
    \u6C42\u3081\u308B\r\n\r\nT inv(size_type k) :\r\n\tk^-1 \u3092\u6C42\u3081\u308B\
    \r\n\r\n:private:\r\nvoid build(size_type k) :\r\n\tk! \u304C\u8A08\u7B97\u3067\
    \u304D\u308B\u3088\u3046\u306B\u78BA\u4FDD\r\n*/\r\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n#include <algorithm>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ Combination {\r\npublic:\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tCombination(size_type\
    \ sz = 1) : _fact(1, 1), _finv(1, 1), _inv(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type\
    \ k) { if (k >= T::get_mod()) return 0; build(k); return _fact[k]; }\r\n\tT finv(size_type\
    \ k) { assert(k < T::get_mod()); build(k); return _finv[k]; }\r\n\tT inv(size_type\
    \ k) { assert(k > 0 && k < T::get_mod()); build(k); return _inv[k]; }\r\n\t\r\n\
    \tT operator ()(int n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\
    \t\tif (r < 0 || n < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\
    \n\t}\r\n\t\r\nprivate:\r\n\tstd::vector<T> _fact, _finv, _inv;\r\n\tstatic constexpr\
    \ size_type MAX_LIMIT = 50000000;\r\n\t\r\n\tvoid build(size_type k) {\r\n\t\t\
    if (_fact.size() > k) return;\r\n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz\
    \ = std::min({MAX_LIMIT, static_cast<size_type>(T::get_mod()), std::max(_fact.size()\
    \ * 2, k + 1)});\r\n\t\tsize_type presz = _fact.size();\r\n\t\t_fact.resize(sz);\r\
    \n\t\t_finv.resize(sz);\r\n\t\t_inv.resize(sz);\r\n\t\t\r\n\t\tfor (size_type\
    \ i = presz; i < sz; ++i) _fact[i] = _fact[i - 1] * i;\r\n\t\t_finv[sz - 1] =\
    \ T(_fact[sz - 1]).inverse();\r\n\t\tfor (size_type i = sz - 1; i > presz; --i)\
    \ {\r\n\t\t\t_finv[i - 1] = _finv[i] * i;\r\n\t\t\t_inv[i] = _fact[i - 1] * _finv[i];\r\
    \n\t\t}\r\n\t\t_inv[presz] = _fact[presz - 1] * _finv[presz];\r\n\t}\r\n};\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_COMBINATION_HPP\r\n#define INCLUDE_GUARD_COMBINATION_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/01/15\r\n\r\n# \u4ED5\u69D8\r\ntemplate\u5F15\u6570\
    \ \u306B\u306F ModInt \u3092\u6E21\u3059\u3002(require get_mod())\r\n\r\nTODO:\
    \ r or n - r \u304C\u5C0F\u3055\u3044\u3068\u304D\u306E\u611A\u76F4\u8A08\u7B97\
    \u306E\u8FFD\u52A0\r\n\r\nConstruct : Amortized \u0398(max k + (logM)^2 ) ??\r\
    \nQuery : Amortized \u0398(1) ?? \u8B0E\r\n\r\nComination(size_type sz = 1) :\r\
    \n\tsz! \u3092\u8A08\u7B97\u3067\u304D\u308B\u3060\u3051\u524D\u8A08\u7B97\r\n\
    \r\nT fact(size_type k) :\r\n\tk! \u3092\u6C42\u3081\u308B\r\n\r\nT finv(size_type\
    \ k) :\r\n\t(k!)^-1 \u3092\u6C42\u3081\u308B\r\n\r\nT inv(size_type k) :\r\n\t\
    k^-1 \u3092\u6C42\u3081\u308B\r\n\r\n:private:\r\nvoid build(size_type k) :\r\n\
    \tk! \u304C\u8A08\u7B97\u3067\u304D\u308B\u3088\u3046\u306B\u78BA\u4FDD\r\n*/\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n\
    template<typename T>\r\nstruct Combination {\r\npublic:\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\n\tCombination(size_type sz = 1) : _fact(1, 1), _finv(1,\
    \ 1), _inv(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type k) { if (k >= T::get_mod())\
    \ return 0; build(k); return _fact[k]; }\r\n\tT finv(size_type k) { assert(k <\
    \ T::get_mod()); build(k); return _finv[k]; }\r\n\tT inv(size_type k) { assert(k\
    \ > 0 && k < T::get_mod()); build(k); return _inv[k]; }\r\n\t\r\n\tT operator\
    \ ()(int n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r <\
    \ 0 || n < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tstd::vector<T> _fact, _finv, _inv;\r\n\tstatic constexpr\
    \ size_type MAX_LIMIT = 50000000;\r\n\t\r\n\tvoid build(size_type k) {\r\n\t\t\
    if (_fact.size() > k) return;\r\n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz\
    \ = std::min({MAX_LIMIT, static_cast<size_type>(T::get_mod()), std::max(_fact.size()\
    \ * 2, k + 1)});\r\n\t\tsize_type presz = _fact.size();\r\n\t\t_fact.resize(sz);\r\
    \n\t\t_finv.resize(sz);\r\n\t\t_inv.resize(sz);\r\n\t\t\r\n\t\tfor (size_type\
    \ i = presz; i < sz; ++i) _fact[i] = _fact[i - 1] * i;\r\n\t\t_finv[sz - 1] =\
    \ T(_fact[sz - 1]).inverse();\r\n\t\tfor (size_type i = sz - 1; i > presz; --i)\
    \ {\r\n\t\t\t_finv[i - 1] = _finv[i] * i;\r\n\t\t\t_inv[i] = _fact[i - 1] * _finv[i];\r\
    \n\t\t}\r\n\t\t_inv[presz] = _fact[presz - 1] * _finv[presz];\r\n\t}\r\n};\r\n\
    \r\n#endif // INCLUDE_GUARD_COMBINATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Combination.hpp
  requiredBy: []
  timestamp: '2020-11-10 21:09:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/Combination.hpp
layout: document
redirect_from:
- /library/Mathematics/Combination.hpp
- /library/Mathematics/Combination.hpp.html
title: Mathematics/Combination.hpp
---
