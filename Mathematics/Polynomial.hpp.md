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
    - https://atcoder.jp/contests/hhkb2020/submissions/17832420
  bundledCode: "#line 1 \"Mathematics/Polynomial.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/11/02\r\n\r\n# \u4ED5\u69D8\r\npoly[i] := x^i \u306E\u4FC2\u6570\r\npoly\
    \ \u306E\u6700\u9AD8\u6B21\u6570\u3092 n \u3068\u3059\u308B\u3002\r\n\r\nstd::vector<T>\
    \ linear_prod(const std::vector<T> & poly, T d)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(n)\r\n\t\u591A\u9805\u5F0F poly * (x - d) \u3092\u8FD4\u3059\r\n\r\n\
    std::vector<T> linear_div(const std::vector<T> & poly, T d)\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(n)\r\n\t\u591A\u9805\u5F0F poly / (x - d) \u3092\u8FD4\u3059\
    \r\n\t\u5FC5\u305A poly \u306E\u56E0\u6570\u306B (x - d) \u304C\u542B\u307E\u308C\
    \u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\r\n# verify\r\nHHKB \u30D7\
    \u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u30B3\u30F3\u30C6\u30B9\u30C8 2020\u300E\
    F - Random Max\u300Fhttps://atcoder.jp/contests/hhkb2020/submissions/17832420\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace tk {\r\ntemplate<typename T>\r\n\
    std::vector<T> linear_prod(const std::vector<T> & poly, T d) {\r\n\tassert(!poly.empty());\r\
    \n\tusing size_type = std::size_t;\r\n\tstd::vector<T> res;\r\n\tres.reserve(poly.size()\
    \ + 1);\r\n\tres.emplace_back(poly[0] * (static_cast<mint>(0) - d));\r\n\tfor\
    \ (size_type i = 1; i < poly.size(); ++i)\r\n\t\tres.emplace_back(poly[i - 1]\
    \ + poly[i] * (static_cast<mint>(0) - d));\r\n\tres.emplace_back(poly.back());\r\
    \n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\nstd::vector<T> linear_div(const\
    \ std::vector<T> & poly, T d) {\r\n\tassert(poly.size() >= 2);\r\n\tusing size_type\
    \ = std::size_t;\r\n\tstd::vector<T> res(poly.size() - 1);\r\n\tT r = 0;\r\n\t\
    for (size_type i = poly.size() - 1; i > 0; --i) {\r\n\t\tres[i - 1] = r + poly[i];\r\
    \n\t\tr = res[i - 1] * d;\r\n\t}\r\n\tr += poly[0];\r\n\tassert(r == 0);\r\n\t\
    return res;\r\n}\r\n} // namespace tk\r\n\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_POLYNOMINAL_HPP\r\n#define INCLUDE_GUARD_POLYNOMINAL_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/02\r\n\r\n# \u4ED5\u69D8\r\npoly[i] := x^i \u306E\
    \u4FC2\u6570\r\npoly \u306E\u6700\u9AD8\u6B21\u6570\u3092 n \u3068\u3059\u308B\
    \u3002\r\n\r\nstd::vector<T> linear_prod(const std::vector<T> & poly, T d)\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u591A\u9805\u5F0F poly * (x\
    \ - d) \u3092\u8FD4\u3059\r\n\r\nstd::vector<T> linear_div(const std::vector<T>\
    \ & poly, T d)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u591A\u9805\
    \u5F0F poly / (x - d) \u3092\u8FD4\u3059\r\n\t\u5FC5\u305A poly \u306E\u56E0\u6570\
    \u306B (x - d) \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\r\n\r\n# verify\r\nHHKB \u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u30B3\
    \u30F3\u30C6\u30B9\u30C8 2020\u300EF - Random Max\u300Fhttps://atcoder.jp/contests/hhkb2020/submissions/17832420\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace tk {\r\ntemplate<typename T>\r\n\
    std::vector<T> linear_prod(const std::vector<T> & poly, T d) {\r\n\tassert(!poly.empty());\r\
    \n\tusing size_type = std::size_t;\r\n\tstd::vector<T> res;\r\n\tres.reserve(poly.size()\
    \ + 1);\r\n\tres.emplace_back(poly[0] * (static_cast<mint>(0) - d));\r\n\tfor\
    \ (size_type i = 1; i < poly.size(); ++i)\r\n\t\tres.emplace_back(poly[i - 1]\
    \ + poly[i] * (static_cast<mint>(0) - d));\r\n\tres.emplace_back(poly.back());\r\
    \n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\nstd::vector<T> linear_div(const\
    \ std::vector<T> & poly, T d) {\r\n\tassert(poly.size() >= 2);\r\n\tusing size_type\
    \ = std::size_t;\r\n\tstd::vector<T> res(poly.size() - 1);\r\n\tT r = 0;\r\n\t\
    for (size_type i = poly.size() - 1; i > 0; --i) {\r\n\t\tres[i - 1] = r + poly[i];\r\
    \n\t\tr = res[i - 1] * d;\r\n\t}\r\n\tr += poly[0];\r\n\tassert(r == 0);\r\n\t\
    return res;\r\n}\r\n} // namespace tk\r\n\r\n\r\n#endif // INCLUDE_POLYNOMINAL_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Polynomial.hpp
  requiredBy: []
  timestamp: '2020-11-02 12:32:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/Polynomial.hpp
layout: document
redirect_from:
- /library/Mathematics/Polynomial.hpp
- /library/Mathematics/Polynomial.hpp.html
title: Mathematics/Polynomial.hpp
---
