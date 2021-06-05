---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/sum_of_floor_of_linear.hpp
    title: Sum of Floor of Linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Test/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line 1 \"\
    Mathematics/sum_of_floor_of_linear.hpp\"\n\n\n\r\n#include <utility>\r\n#include\
    \ <cassert>\r\n#include <type_traits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nT sum_of_floor_of_linear(T\
    \ n, T m, T a, T b) {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(n\
    \ >= 0);\r\n\tassert(m > 0);\r\n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif\
    \ (n == 0) return 0;\r\n\tconst T qa = a / m, qb = b / m;\r\n\tT res = n * (n\
    \ - 1) / 2 * qa + n * qb;\r\n\ta -= qa * m;\r\n\tb -= qb * m;\r\n\tif (a == 0)\
    \ return res;\r\n\tconst T q = (a * n + b) / m, r = (a * n + b) - q * m;\r\n\t\
    return res + sum_of_floor_of_linear(q, a, m, r);\r\n}\r\n} // namespace tk\r\n\
    \r\n\n#line 4 \"Test/sum_of_floor_of_linear.test.cpp\"\n\r\n#include <cstdio>\r\
    \n\r\nint main() {\r\n\tint T;\r\n\tscanf(\"%d\", &T);\r\n\tusing ll = long long;\r\
    \n\twhile (T--) {\r\n\t\tint n, m, a, b;\r\n\t\tscanf(\"%d %d %d %d\", &n, &m,\
    \ &a, &b);\r\n\t\tprintf(\"%lld\\n\", tk::sum_of_floor_of_linear<ll>(n, m, a,\
    \ b));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include \"Mathematics/sum_of_floor_of_linear.hpp\"\r\n\r\n#include <cstdio>\r\
    \n\r\nint main() {\r\n\tint T;\r\n\tscanf(\"%d\", &T);\r\n\tusing ll = long long;\r\
    \n\twhile (T--) {\r\n\t\tint n, m, a, b;\r\n\t\tscanf(\"%d %d %d %d\", &n, &m,\
    \ &a, &b);\r\n\t\tprintf(\"%lld\\n\", tk::sum_of_floor_of_linear<ll>(n, m, a,\
    \ b));\r\n\t}\r\n}"
  dependsOn:
  - Mathematics/sum_of_floor_of_linear.hpp
  isVerificationFile: true
  path: Test/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2021-04-13 10:29:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/Test/sum_of_floor_of_linear.test.cpp
- /verify/Test/sum_of_floor_of_linear.test.cpp.html
title: Test/sum_of_floor_of_linear.test.cpp
---
