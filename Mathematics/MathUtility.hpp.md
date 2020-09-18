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
    - https://noshi91.hatenablog.com/entry/2019/04/01/184957,
  bundledCode: "#line 1 \"Mathematics/MathUtility.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/01/14\r\n\r\n# \u4ED5\u69D8\r\n(boost \u306E gcd \u304C\u52D5\u3044\u3066\
    \u9045\u304F\u306A\u308B\u304B\u3082)\r\nT gcd(const T & a, const T & b) :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta \u3068 b \u306E greatest common\
    \ divisor \u3092\u6C42\u3081\u308B\r\n\r\nT lcm(const T & a, const T &b) :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta \u3068 b \u306E least common\
    \ multiple \u3092\u6C42\u3081\u308B\r\n\r\nT extgcd(const T & a, const T & b,\
    \ T &x, T &y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\t\u4E00\u6B21\
    \u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax + by = gcd(x, y) \u306E\u89E3 (x, y) \u3092\u6C42\
    \u3081\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/04/01/184957,\
    \ 2020/01/14\r\n*/\r\n\r\ntemplate<typename T>\r\nT gcd(const T & a, const T &b)\
    \ {\r\n\tif (b == 0) return a;\r\n\treturn gcd(b, a % b);\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nT lcm(const T & a, const T & b) {\r\n\treturn a / gcd(a, b) * b;\r\n}\r\
    \n\r\ntemplate<typename T>\r\nT extgcd(const T & a, const T & b, T &x, T &y) {\r\
    \n\tT a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;\r\n\twhile (b0 > 0) {\r\n\
    \t\tT q = a0 / b0, r = a0 % b0;\r\n\t\tT nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\ta0 = b0; b0 = r;\r\n\t\ta1 = b1; b1 = nb1;\r\n\t\ta2 = b2; b2 = nb2;\r\n\
    \t}\r\n\tx = a1;\r\n\ty = a2;\r\n\treturn a0;\r\n}\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_MATH_UTILITY_HPP\r\n#define INCLUDE_GUARD_MATH_UTILITY_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/01/14\r\n\r\n# \u4ED5\u69D8\r\n(boost \u306E gcd\
    \ \u304C\u52D5\u3044\u3066\u9045\u304F\u306A\u308B\u304B\u3082)\r\nT gcd(const\
    \ T & a, const T & b) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta \u3068\
    \ b \u306E greatest common divisor \u3092\u6C42\u3081\u308B\r\n\r\nT lcm(const\
    \ T & a, const T &b) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta \u3068\
    \ b \u306E least common multiple \u3092\u6C42\u3081\u308B\r\n\r\nT extgcd(const\
    \ T & a, const T & b, T &x, T &y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log\
    \ b)\r\n\t\u4E00\u6B21\u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax + by = gcd(x, y) \u306E\
    \u89E3 (x, y) \u3092\u6C42\u3081\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/04/01/184957,\
    \ 2020/01/14\r\n*/\r\n\r\ntemplate<typename T>\r\nT gcd(const T & a, const T &b)\
    \ {\r\n\tif (b == 0) return a;\r\n\treturn gcd(b, a % b);\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nT lcm(const T & a, const T & b) {\r\n\treturn a / gcd(a, b) * b;\r\n}\r\
    \n\r\ntemplate<typename T>\r\nT extgcd(const T & a, const T & b, T &x, T &y) {\r\
    \n\tT a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;\r\n\twhile (b0 > 0) {\r\n\
    \t\tT q = a0 / b0, r = a0 % b0;\r\n\t\tT nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\ta0 = b0; b0 = r;\r\n\t\ta1 = b1; b1 = nb1;\r\n\t\ta2 = b2; b2 = nb2;\r\n\
    \t}\r\n\tx = a1;\r\n\ty = a2;\r\n\treturn a0;\r\n}\r\n\r\n#endif // INCLUDE_GUARD_MATH_UTILITY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/MathUtility.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/MathUtility.hpp
layout: document
redirect_from:
- /library/Mathematics/MathUtility.hpp
- /library/Mathematics/MathUtility.hpp.html
title: Mathematics/MathUtility.hpp
---
