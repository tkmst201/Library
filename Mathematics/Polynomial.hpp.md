---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/Polynomial.hpp\"\n\n\n\r\n#include <vector>\r\
    \n\r\n// poly / (x - d) \u3092\u8FD4\u3059\r\ntemplate<typename T>\r\nstd::vector<T>\
    \ div_by_linear(const std::vector<T> & poly, T d) {\r\n\tassert(poly.size() >=\
    \ 2);\r\n\tusing size_t = std::size_t;\r\n\tstd::vector<T> res(poly.size() - 1);\r\
    \n\tT r = 0;\r\n\tfor (size_t i = poly.size() - 1; i > 0; --i) {\r\n\t\tres[i\
    \ - 1] = r + poly[i];\r\n\t\tr = res[i - 1] * d;\r\n\t}\r\n\tr += poly[0];\r\n\
    \tassert(r == 0);\r\n\treturn res;\r\n}\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_POLYNOMINAL_HPP\r\n#define INCLUDE_GUARD_POLYNOMINAL_HPP\r\
    \n\r\n#include <vector>\r\n\r\n// poly / (x - d) \u3092\u8FD4\u3059\r\ntemplate<typename\
    \ T>\r\nstd::vector<T> div_by_linear(const std::vector<T> & poly, T d) {\r\n\t\
    assert(poly.size() >= 2);\r\n\tusing size_t = std::size_t;\r\n\tstd::vector<T>\
    \ res(poly.size() - 1);\r\n\tT r = 0;\r\n\tfor (size_t i = poly.size() - 1; i\
    \ > 0; --i) {\r\n\t\tres[i - 1] = r + poly[i];\r\n\t\tr = res[i - 1] * d;\r\n\t\
    }\r\n\tr += poly[0];\r\n\tassert(r == 0);\r\n\treturn res;\r\n}\r\n\r\n#endif\
    \ // INCLUDE_POLYNOMINAL_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Polynomial.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/Polynomial.hpp
layout: document
redirect_from:
- /library/Mathematics/Polynomial.hpp
- /library/Mathematics/Polynomial.hpp.html
title: Mathematics/Polynomial.hpp
---
