---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/euclid.hpp
    title: "\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Mathematics/garner.hpp
    title: "Garner (\u9023\u7ACB\u4E00\u6B21\u5408\u540C\u5F0F mod M)"
  - icon: ':heavy_check_mark:'
    path: Mathematics/mod_pow_inv.hpp
    title: "$\\mod{m}$ \u3067\u306E\u51AA\u3068\u9006\u5143"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/187
    links:
    - https://yukicoder.me/problems/no/187
  bundledCode: "#line 1 \"Test/garner.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/187\"\
    \r\n\r\n#line 1 \"Mathematics/garner.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <type_traits>\r\n\r\n#line 1 \"Mathematics/euclid.hpp\"\
    \n\n\n\r\n#line 5 \"Mathematics/euclid.hpp\"\n#include <utility>\r\n#include <tuple>\r\
    \n#line 8 \"Mathematics/euclid.hpp\"\n#include <cmath>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\n */\r\nnamespace\
    \ tk {\r\ntemplate<typename T>\r\nconstexpr T gcd(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tconst T\
    \ t = a % b;\r\n\t\ta = b; b = t;\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nconstexpr T lcm(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\
    \n\treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr std::tuple<T,\
    \ T, T> ext_gcd(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tassert(a != 0);\r\n\tassert(b\
    \ != 0);\r\n\tT a1 = (a > 0) * 2 - 1, a2 = 0, b1 = 0, b2 = (b > 0) * 2 - 1;\r\n\
    \ta = std::abs(a);\r\n\tb = std::abs(b);\r\n\twhile (b > 0) {\r\n\t\tconst T q\
    \ = a / b;\r\n\t\tT tmp = a - q * b; a = b; b = tmp;\r\n\t\ttmp = a1 - q * b1;\
    \ a1 = b1; b1 = tmp;\r\n\t\ttmp = a2 - q * b2; a2 = b2; b2 = tmp;\r\n\t}\r\n\t\
    return {a, a1, a2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 1 \"Mathematics/mod_pow_inv.hpp\"\
    \n\n\n\r\n#line 6 \"Mathematics/mod_pow_inv.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nconstexpr T mod_pow(T x, T\
    \ n, T m) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(m\
    \ > 0);\r\n\tassert(n >= 0);\r\n\tx = x % m + (x >= 0 ? 0 : m);\r\n\tT res = 1\
    \ % m;\r\n\twhile (n > 0) {\r\n\t\tif (n & 1) res = res * x % m;\r\n\t\tx = x\
    \ * x % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nconstexpr T mod_inv(T x, T m) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tassert(m > 0);\r\n\tx = x %\
    \ m + (x >= 0 ? 0 : m);\r\n\tT x1 = 1, y = m, y1 = 0;\r\n\twhile (y > 0) {\r\n\
    \t\tconst T q = x / y;\r\n\t\tT tmp = x - q * y; x = y; y = tmp;\r\n\t\ttmp =\
    \ x1 - q * y1; x1 = y1; y1 = tmp;\r\n\t}\r\n\tassert(x == 1);\r\n\tif (x1 == m)\
    \ x1 = 0;\r\n\tif (x1 < 0) x1 += m;\r\n\treturn x1;\r\n}\r\n} // namespace tk\r\
    \n\r\n\n#line 10 \"Mathematics/garner.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/garner.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nbool pre_garner(std::vector<T>\
    \ & b, std::vector<T> & m) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tfor (int i = 0; i < static_cast<int>(b.size());\
    \ ++i) {\r\n\t\tb[i] = b[i] % m[i] + (b[i] >= 0 ? 0 : m[i]);\r\n\t\tfor (int j\
    \ = 0; j < i; ++j) {\r\n\t\t\tT g = gcd(m[i], m[j]);\r\n\t\t\tif ((b[i] - b[j])\
    \ % g != 0) return false;\r\n\t\t\tm[i] /= g; m[j] /= g;\r\n\t\t\tT gi = gcd(g,\
    \ m[i]), gj = g / gi;\r\n\t\t\tdo {\r\n\t\t\t\tg = gcd(gi, gj);\r\n\t\t\t\tgi\
    \ *= g; gj /= g;\r\n\t\t\t} while (g != 1);\r\n\t\t\tm[i] *= gi; m[j] *= gj;\r\
    \n\t\t\tb[i] %= m[i]; b[j] %= m[j];\r\n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\
    \r\ntemplate<typename T, typename U>\r\nT garner(const std::vector<T> & b, const\
    \ std::vector<T> & m, const T M) {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tassert(b.size() == m.size());\r\n\tconst int n = b.size();\r\n\tassert(n >\
    \ 0);\r\n\t{\r\n\t\tT g = 0;\r\n\t\tfor (auto v : m) {\r\n\t\t\tassert(v > 0);\r\
    \n\t\t\tg = gcd(g, v);\r\n\t\t}\r\n\t\tassert(n == 1 || g == 1);\r\n\t}\r\n\t\
    assert(M > 0);\r\n\tstd::vector<T> sum(n + 1, 0), ip(n + 1, 1);\r\n\tfor (int\
    \ i = 0; i < n; ++i) {\r\n\t\tif (m[i] == 1) continue;\r\n\t\tU t = (b[i] % m[i]\
    \ + static_cast<U>(2) * m[i] - sum[i]) % m[i] * mod_inv(ip[i], m[i]) % m[i];\r\
    \n\t\tfor (int j = i + 1; j < n; ++j) {\r\n\t\t\tsum[j] = (sum[j] + ip[j] * t)\
    \ % m[j];\r\n\t\t\tip[j] = static_cast<U>(ip[j]) * m[i] % m[j];\r\n\t\t}\r\n\t\
    \tsum[n] = (sum[n] + ip[n] * t % M) % M;\r\n\t\tip[n] = static_cast<U>(ip[n])\
    \ * m[i] % M; \r\n\t}\r\n\treturn sum.back();\r\n}\r\n} // namespace tk\r\n\r\n\
    \n#line 4 \"Test/garner.test.cpp\"\n\r\n#include <cstdio>\r\n#line 7 \"Test/garner.test.cpp\"\
    \n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\tstd::vector<int> b(N),\
    \ m(N);\r\n\tbool zero = true;\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d %d\"\
    , &b[i], &m[i]), zero &= b[i] == 0;\r\n\t\r\n\tconstexpr int mod = 1000000007;\r\
    \n\tif (!tk::pre_garner(b, m)) puts(\"-1\");\r\n\telse if (zero) {\r\n\t\tlong\
    \ long ans = 1;\r\n\t\tfor (auto c : m) ans = ans * c % mod;\r\n\t\tprintf(\"\
    %lld\\n\", ans);\r\n\t}\r\n\telse printf(\"%d\\n\", tk::garner<int, long long>(b,\
    \ m, mod));\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/187\"\r\n\r\n#include\
    \ \"Mathematics/garner.hpp\"\r\n\r\n#include <cstdio>\r\n#include <vector>\r\n\
    \r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\tstd::vector<int> b(N),\
    \ m(N);\r\n\tbool zero = true;\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d %d\"\
    , &b[i], &m[i]), zero &= b[i] == 0;\r\n\t\r\n\tconstexpr int mod = 1000000007;\r\
    \n\tif (!tk::pre_garner(b, m)) puts(\"-1\");\r\n\telse if (zero) {\r\n\t\tlong\
    \ long ans = 1;\r\n\t\tfor (auto c : m) ans = ans * c % mod;\r\n\t\tprintf(\"\
    %lld\\n\", ans);\r\n\t}\r\n\telse printf(\"%d\\n\", tk::garner<int, long long>(b,\
    \ m, mod));\r\n}"
  dependsOn:
  - Mathematics/garner.hpp
  - Mathematics/euclid.hpp
  - Mathematics/mod_pow_inv.hpp
  isVerificationFile: true
  path: Test/garner.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/garner.test.cpp
layout: document
redirect_from:
- /verify/Test/garner.test.cpp
- /verify/Test/garner.test.cpp.html
title: Test/garner.test.cpp
---
