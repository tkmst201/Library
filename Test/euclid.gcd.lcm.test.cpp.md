---
data:
  _extendedDependsOn:
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
    PROBLEM: https://yukicoder.me/problems/no/415
    links:
    - https://yukicoder.me/problems/no/415
  bundledCode: "#line 1 \"Test/euclid.gcd.lcm.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/415\"\
    \r\n\r\n#line 1 \"Mathematics/euclid.hpp\"\n\n\n\r\n#include <cassert>\r\n#include\
    \ <utility>\r\n#include <tuple>\r\n#include <type_traits>\r\n#include <cmath>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\
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
    return {a, a1, a2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 4 \"Test/euclid.gcd.lcm.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 7 \"Test/euclid.gcd.lcm.test.cpp\"\n\r\nint main()\
    \ {\r\n\tint N, D;\r\n\tscanf(\"%d %d\", &N, &D);\r\n\tlong long lcm = tk::lcm<long\
    \ long>(N, D);\r\n\tassert(lcm / D - 1 == N / tk::gcd(N, D) - 1);\r\n\tprintf(\"\
    %d\\n\", N / tk::gcd(N, D) - 1);\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/415\"\r\n\r\n#include\
    \ \"Mathematics/euclid.hpp\"\r\n\r\n#include <cstdio>\r\n#include <cassert>\r\n\
    \r\nint main() {\r\n\tint N, D;\r\n\tscanf(\"%d %d\", &N, &D);\r\n\tlong long\
    \ lcm = tk::lcm<long long>(N, D);\r\n\tassert(lcm / D - 1 == N / tk::gcd(N, D)\
    \ - 1);\r\n\tprintf(\"%d\\n\", N / tk::gcd(N, D) - 1);\r\n}"
  dependsOn:
  - Mathematics/euclid.hpp
  isVerificationFile: true
  path: Test/euclid.gcd.lcm.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 14:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/euclid.gcd.lcm.test.cpp
layout: document
redirect_from:
- /verify/Test/euclid.gcd.lcm.test.cpp
- /verify/Test/euclid.gcd.lcm.test.cpp.html
title: Test/euclid.gcd.lcm.test.cpp
---
