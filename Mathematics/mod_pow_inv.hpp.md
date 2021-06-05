---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/NumberTheoreticTransform.hpp
    title: "\u6570\u8AD6\u5909\u63DB (NTT)"
  - icon: ':heavy_check_mark:'
    path: Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: "\u4EFB\u610F mod \u6570\u8AD6\u5909\u63DB (\u4EFB\u610F mod NTT)"
  - icon: ':heavy_check_mark:'
    path: Mathematics/garner.hpp
    title: "Garner (\u9023\u7ACB\u4E00\u6B21\u5408\u540C\u5F0F mod M)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform.test.cpp
    title: Test/NumberTheoreticTransform.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform_AnyMod.test.cpp
    title: Test/NumberTheoreticTransform_AnyMod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/garner.test.cpp
    title: Test/garner.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp
  bundledCode: "#line 1 \"Mathematics/mod_pow_inv.hpp\"\n\n\n\r\n#include <cassert>\r\
    \n#include <type_traits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp\r\
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
    \n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_MOD_POW_INV_HPP\r\n#define INCLUDE_GUARD_MOD_POW_INV_HPP\r\
    \n\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp\r\
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
    \n\r\n#endif // INCLUDE_GUARD_MOD_POW_INV_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/mod_pow_inv.hpp
  requiredBy:
  - Convolution/NumberTheoreticTransform.hpp
  - Convolution/NumberTheoreticTransform_AnyMod.hpp
  - Mathematics/garner.hpp
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
  - Test/garner.test.cpp
  - Test/NumberTheoreticTransform.test.cpp
documentation_of: Mathematics/mod_pow_inv.hpp
layout: document
title: "$\\mod{m}$ \u3067\u306E\u51AA\u3068\u9006\u5143"
---

# 概要

整数 $a, x, m$ に対して $a^x \pmod{m}$ や $a^{-1} \pmod{m}$ を求めます。  

<br>

# 関数

### T mod_pow(T x, T n, T m)

整数 $x, n, m$ に対して $x^n \pmod{m}$ を返します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- $m^2$ が `T` で表現可能
- $0 \leq n$
- $0 < m$

**計算量**

- $\Theta(\log{n})$

---

### T mod_inv(T x, T m)

整数 $x, m$ に対して $x^{-1} \pmod{m}$ を返します。  

**制約**

- `T` は `int`, `long long`
- $0 < m$
- $x$ と $m$ は互いに素

**計算量**

- $\mathcal{O}(\log{\min(x, m)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/mod_pow_inv.hpp"
using namespace std;

int main() {
	cout << "mod_pow(2, 3, 3) = " << tk::mod_pow(2, 3, 3) << endl; // 2 (2^3 = 8)
	cout << "mod_pow(5, 0, 10) = " << tk::mod_pow(2, 3, 3) << endl; // 1 (5^0 = 1)
	cout << "mod_pow(10, 2, 10000) = " << tk::mod_pow(10, 2, 10000) << endl; // 100 (10^2 = 100)
	
	cout << "mod_inv(10, 7) = " << tk::mod_inv(10, 7) << endl; // -2 (10*(-2) = -20 = 7*(-3) + 1)
	cout << "mod_inv(4, 3) = " << tk::mod_inv(4, 3) << endl; // 1 (4*1 = 3*1 + 1)
	cout << "mod_inv(-5, 8) = " << tk::mod_inv(-5, 8) << endl; // 3 (-5*3 = 8*(-2) + 1)
}
```

<br>

# 参考

2020/01/14: [https://noshi91.hatenablog.com/entry/2019/04/01/184957](https://noshi91.hatenablog.com/entry/2019/04/01/184957)  

<br>