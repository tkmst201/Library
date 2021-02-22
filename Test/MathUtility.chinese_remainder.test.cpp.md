---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/MathUtility.hpp
    title: Mathematics/MathUtility.hpp
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
  bundledCode: "#line 1 \"Test/MathUtility.chinese_remainder.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/186\"\r\n\r\n#line 1 \"Mathematics/MathUtility.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/09/21\r\n\r\n# \u4ED5\u69D8\r\nT gcd(T a, T\
    \ b)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{a, b})\r\n\t\u975E\u8CA0\u6574\
    \u6570 a \u3068 b \u306E\u6700\u5927\u516C\u7D04\u6570\u3092\u8FD4\u3059\r\n\t\
    \u4E00\u65B9\u306E\u5024\u304C 0 \u306E\u3068\u304D\u306F\u3082\u3046\u4E00\u65B9\
    \u306E\u5024\u3092\u8FD4\u3059\r\n\r\nT lcm(T a, T b)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(log max{a, b})\r\n\t\u975E\u8CA0\u6574\u6570 a \u3068 b \u306E\u6700\
    \u5C0F\u516C\u500D\u6570\u3092\u8FD4\u3059\r\n\ta = 0 \u307E\u305F\u306F b = 0\
    \ \u306E\u3068\u304D\u306F 0 \u3092\u8FD4\u3059\r\n\r\nT ext_gcd(const T & a,\
    \ T & x, const T & b, T & y)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\
    \ta > 0 \u304B\u3064 b > 0\r\n\t\u4E00\u6B21\u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax\
    \ + by = gcd(x, y) \u306E\u89E3 (x, y) \u3092\u6C42\u3081\u308B\r\n\tgcd(a, b)\
    \ \u3092\u8FD4\u3059\r\n\r\nT mod_pow(T x, T n, const T & mod)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(log n)\r\n\ta^n (modulo. mod) \u3092\u8FD4\u3059\r\n\
    \t\u8A08\u7B97\u904E\u7A0B\u3067 O(mod^2) \u7A0B\u5EA6\u307E\u3067\u5024\u304C\
    \u5927\u304D\u304F\u306A\u308B\u306E\u3067\u6CE8\u610F\r\n\r\nT mod_inv(const\
    \ T & x, const T & mod)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{x, mod})\r\
    \n\tmodulo. mod \u4E0A\u306E x \u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\tgcd(x,\
    \ mod) = 1 \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B(\u9006\u5143\u304C\
    \u5B58\u5728\u3059\u308B\u305F\u3081\u306E\u5FC5\u8981\u5341\u5206\u6761\u4EF6\
    )\r\n\r\nstd::pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log max{m1, m2})\r\n\t\u6B21\u306E\u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570 x \u3092\u6C42\u3081\
    \u308B(0 \\leq x < lcm(m1, m2))\r\n\t\tx \\equiv b1 (mod. m1)\r\n\t\tx \\equiv\
    \ b2 (mod. m2)\r\n\t\u623B\u308A\u5024: { x, lcm(m1, m2) }\r\n\t\u4E0A\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059 x \u306F\u5468\u671F lcm(m1, m2)\r\n\tx \u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F {0, 0} \u3092\u8FD4\u3059\r\n\r\n#\
    \ \u53C2\u8003\r\nAC Library, 2020/09/21\r\nhttps://noshi91.hatenablog.com/entry/2019/04/01/184957,\
    \ 2020/01/14\r\n*/\r\n\r\n#include <cassert>\r\n#include <utility>\r\n\r\nnamespace\
    \ tk {\r\ntemplate<typename T>\r\nT gcd(T a, T b) {\r\n\tassert(a >= 0);\r\n\t\
    assert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tT t = a % b;\r\n\t\ta = b; b = t;\r\
    \n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nT lcm(T a, T b) {\r\n\
    \tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\n\
    \treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nT ext_gcd(const\
    \ T & a, T & x, const T & b, T & y) {\r\n\tassert(a > 0);\r\n\tassert(b > 0);\r\
    \n\tT a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;\r\n\twhile (b0 > 0) {\r\n\
    \t\tT q = a0 / b0, r = a0 % b0;\r\n\t\tT nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\ta0 = b0; b0 = r;\r\n\t\ta1 = b1; b1 = nb1;\r\n\t\ta2 = b2; b2 = nb2;\r\n\
    \t}\r\n\tx = a1;\r\n\ty = a2;\r\n\treturn a0;\r\n}\r\n\r\ntemplate<typename T>\r\
    \nT mod_pow(T x, T n, const T & mod) {\r\n\tassert(mod > 0);\r\n\tassert(n >=\
    \ 0);\r\n\tx = (x % mod + mod) % mod;\r\n\tT res = 1 % mod;\r\n\twhile (n > 0)\
    \ {\r\n\t\tif (n & 1) res = res * x % mod;\r\n\t\tx = x * x % mod;\r\n\t\tn >>=\
    \ 1;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\nT mod_inv(const\
    \ T & x, const T & mod) {\r\n\tassert(x > 0);\r\n\tassert(mod > 0);\r\n\tT a,\
    \ b;\r\n\tT g = ext_gcd(x, a, mod, b);\r\n\tassert(g == 1);\r\n\treturn (a % mod\
    \ + mod) % mod;\r\n}\r\n\r\ntemplate<typename T>\r\nstd::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2) {\r\n\tassert(m1 > 0);\r\n\tassert(m2 > 0);\r\n\tif (m1\
    \ < m2) { std::swap(b1, b2); std::swap(m1, m2); }\r\n\tb1 = (b1 % m1 + m1) % m1;\r\
    \n\tb2 = (b2 % m2 + m2) % m2;\r\n\t\r\n\tT x, y;\r\n\tT g = ext_gcd(m1, x, m2,\
    \ y);\r\n\tconst T pm2 = m2 / g;\r\n\tx = (x % pm2 + pm2) % pm2;\r\n\t\r\n\tif\
    \ ((b2 - b1) % g != 0) return {0, 0};\r\n\tconst T t = ((b2 - b1) / g % pm2 +\
    \ pm2) % pm2 * x % pm2;\r\n\treturn {b1 + t * m1, m1 * pm2};\r\n}\r\n} // namespace\
    \ tk\r\n\r\n\n#line 4 \"Test/MathUtility.chinese_remainder.test.cpp\"\n\r\n#include\
    \ <cstdio>\r\n#line 7 \"Test/MathUtility.chinese_remainder.test.cpp\"\n\r\nint\
    \ main() {\r\n\tusing ll = long long;\r\n\tll X[3], Y[3];\r\n\tfor (int i = 0;\
    \ i < 3; ++i) scanf(\"%lld %lld\", X + i, Y + i);\r\n\t\r\n\tstd::pair<ll, ll>\
    \ res {0, 1};\r\n\t\r\n\tfor (int i = 0; i < 3; ++i) {\r\n\t\tres = tk::chinese_remainder(res.first,\
    \ res.second, X[i], Y[i]);\r\n\t\tif (res.second == 0) {\r\n\t\t\tputs(\"-1\"\
    );\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\t\r\n\tll ans = res.first;\r\n\tif (ans\
    \ == 0) ans += res.second;\r\n\tprintf(\"%lld\\n\", ans);\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include\
    \ \"Mathematics/MathUtility.hpp\"\r\n\r\n#include <cstdio>\r\n#include <utility>\r\
    \n\r\nint main() {\r\n\tusing ll = long long;\r\n\tll X[3], Y[3];\r\n\tfor (int\
    \ i = 0; i < 3; ++i) scanf(\"%lld %lld\", X + i, Y + i);\r\n\t\r\n\tstd::pair<ll,\
    \ ll> res {0, 1};\r\n\t\r\n\tfor (int i = 0; i < 3; ++i) {\r\n\t\tres = tk::chinese_remainder(res.first,\
    \ res.second, X[i], Y[i]);\r\n\t\tif (res.second == 0) {\r\n\t\t\tputs(\"-1\"\
    );\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\t\r\n\tll ans = res.first;\r\n\tif (ans\
    \ == 0) ans += res.second;\r\n\tprintf(\"%lld\\n\", ans);\r\n\treturn 0;\r\n}"
  dependsOn:
  - Mathematics/MathUtility.hpp
  isVerificationFile: true
  path: Test/MathUtility.chinese_remainder.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 16:44:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/MathUtility.chinese_remainder.test.cpp
layout: document
redirect_from:
- /verify/Test/MathUtility.chinese_remainder.test.cpp
- /verify/Test/MathUtility.chinese_remainder.test.cpp.html
title: Test/MathUtility.chinese_remainder.test.cpp
---
