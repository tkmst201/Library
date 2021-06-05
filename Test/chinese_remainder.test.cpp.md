---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/chinese_remainder.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: Mathematics/euclid.hpp
    title: "\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"Test/chinese_remainder.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\
    \r\n\r\n#line 1 \"Mathematics/chinese_remainder.hpp\"\n\n\n\r\n#line 1 \"Mathematics/euclid.hpp\"\
    \n\n\n\r\n#include <cassert>\r\n#include <utility>\r\n#include <tuple>\r\n#include\
    \ <type_traits>\r\n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nconstexpr T gcd(T a, T b) noexcept\
    \ {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(a >= 0);\r\n\t\
    assert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tconst T t = a % b;\r\n\t\ta = b;\
    \ b = t;\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr T\
    \ lcm(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\
    \tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\n\
    \treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr std::tuple<T,\
    \ T, T> ext_gcd(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tassert(a != 0);\r\n\tassert(b\
    \ != 0);\r\n\tT a1 = (a > 0) * 2 - 1, a2 = 0, b1 = 0, b2 = (b > 0) * 2 - 1;\r\n\
    \ta = std::abs(a);\r\n\tb = std::abs(b);\r\n\twhile (b > 0) {\r\n\t\tconst T q\
    \ = a / b;\r\n\t\tT tmp = a - q * b; a = b; b = tmp;\r\n\t\ttmp = a1 - q * b1;\
    \ a1 = b1; b1 = tmp;\r\n\t\ttmp = a2 - q * b2; a2 = b2; b2 = tmp;\r\n\t}\r\n\t\
    return {a, a1, a2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 5 \"Mathematics/chinese_remainder.hpp\"\
    \n\r\n#line 9 \"Mathematics/chinese_remainder.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nconstexpr std::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tassert(m1 > 0);\r\n\tassert(m2 > 0);\r\n\tif (m1 < m2) { std::swap(b1, b2);\
    \ std::swap(m1, m2); }\r\n\tb1 = b1 % m1 + (b1 >= 0 ? 0 : m1);\r\n\tb2 = b2 %\
    \ m2 + (b2 >= 0 ? 0 : m2);\r\n\tauto [g, x, _] = ext_gcd(m1, m2);\r\n\tif ((b2\
    \ - b1) % g != 0) return {0, 0};\r\n\tconst T pm2 = m2 / g;\r\n\tif (x < 0) x\
    \ += pm2;\r\n\tconst T t = ((b2 - b1) / g % pm2 + pm2) % pm2 * x % pm2;\r\n\t\
    return {b1 + t * m1, m1 * pm2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 4 \"\
    Test/chinese_remainder.test.cpp\"\n\r\n#include <cstdio>\r\n#line 7 \"Test/chinese_remainder.test.cpp\"\
    \n\r\nint main() {\r\n\tusing ll = long long;\r\n\tll X[3], Y[3];\r\n\tfor (int\
    \ i = 0; i < 3; ++i) scanf(\"%lld %lld\", X + i, Y + i);\r\n\t\r\n\tll ans = 0,\
    \ lcm = 1;\r\n\tfor (int i = 0; i < 3; ++i) {\r\n\t\tauto [a, l] = tk::chinese_remainder(ans,\
    \ lcm, X[i], Y[i]);\r\n\t\tif (l == 0) { puts(\"-1\"); return 0; }\r\n\t\tans\
    \ = a; lcm = l;\r\n\t}\r\n\t\r\n\tprintf(\"%lld\\n\", ans == 0 ? lcm : ans);\r\
    \n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include\
    \ \"Mathematics/chinese_remainder.hpp\"\r\n\r\n#include <cstdio>\r\n#include <utility>\r\
    \n\r\nint main() {\r\n\tusing ll = long long;\r\n\tll X[3], Y[3];\r\n\tfor (int\
    \ i = 0; i < 3; ++i) scanf(\"%lld %lld\", X + i, Y + i);\r\n\t\r\n\tll ans = 0,\
    \ lcm = 1;\r\n\tfor (int i = 0; i < 3; ++i) {\r\n\t\tauto [a, l] = tk::chinese_remainder(ans,\
    \ lcm, X[i], Y[i]);\r\n\t\tif (l == 0) { puts(\"-1\"); return 0; }\r\n\t\tans\
    \ = a; lcm = l;\r\n\t}\r\n\t\r\n\tprintf(\"%lld\\n\", ans == 0 ? lcm : ans);\r\
    \n}"
  dependsOn:
  - Mathematics/chinese_remainder.hpp
  - Mathematics/euclid.hpp
  isVerificationFile: true
  path: Test/chinese_remainder.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/chinese_remainder.test.cpp
layout: document
redirect_from:
- /verify/Test/chinese_remainder.test.cpp
- /verify/Test/chinese_remainder.test.cpp.html
title: Test/chinese_remainder.test.cpp
---
