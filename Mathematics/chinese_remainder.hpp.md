---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/euclid.hpp
    title: "\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/chinese_remainder.test.cpp
    title: Test/chinese_remainder.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp
  bundledCode: "#line 1 \"Mathematics/chinese_remainder.hpp\"\n\n\n\r\n#line 1 \"\
    Mathematics/euclid.hpp\"\n\n\n\r\n#include <cassert>\r\n#include <utility>\r\n\
    #include <tuple>\r\n#include <type_traits>\r\n#include <cmath>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\n */\r\n\
    namespace tk {\r\ntemplate<typename T>\r\nconstexpr T gcd(T a, T b) noexcept {\r\
    \n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(a >= 0);\r\n\tassert(b\
    \ >= 0);\r\n\twhile (b != 0) {\r\n\t\tconst T t = a % b;\r\n\t\ta = b; b = t;\r\
    \n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr T lcm(T a,\
    \ T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(a\
    \ >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\n\treturn\
    \ a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr std::tuple<T,\
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
    return {b1 + t * m1, m1 * pm2};\r\n}\r\n} // namespace tk\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_CHINESE_REMAINDER_HPP\r\n#define INCLUDE_GUARD_CHINESE_REMAINDER_HPP\r\
    \n\r\n#include \"Mathematics/euclid.hpp\"\r\n\r\n#include <cassert>\r\n#include\
    \ <utility>\r\n#include <type_traits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nconstexpr std::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tassert(m1 > 0);\r\n\tassert(m2 > 0);\r\n\tif (m1 < m2) { std::swap(b1, b2);\
    \ std::swap(m1, m2); }\r\n\tb1 = b1 % m1 + (b1 >= 0 ? 0 : m1);\r\n\tb2 = b2 %\
    \ m2 + (b2 >= 0 ? 0 : m2);\r\n\tauto [g, x, _] = ext_gcd(m1, m2);\r\n\tif ((b2\
    \ - b1) % g != 0) return {0, 0};\r\n\tconst T pm2 = m2 / g;\r\n\tif (x < 0) x\
    \ += pm2;\r\n\tconst T t = ((b2 - b1) / g % pm2 + pm2) % pm2 * x % pm2;\r\n\t\
    return {b1 + t * m1, m1 * pm2};\r\n}\r\n} // namespace tk\r\n\r\n#endif // INCLUDE_GUARD_CHINESE_REMAINDER_HPP"
  dependsOn:
  - Mathematics/euclid.hpp
  isVerificationFile: false
  path: Mathematics/chinese_remainder.hpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/chinese_remainder.test.cpp
documentation_of: Mathematics/chinese_remainder.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---

# 概要

中国剰余定理です。連立一次合同式を解きます。  
解 $x \pmod M$ を求めたい場合は [Garner](https://tkmst201.github.io/Library/Mathematics/garner.hpp) を使用してください。  

<br>

# 関数

### pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2)

連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

の解の一つを $0 \leq x < lcm(m_1, m_2)$ の範囲で求め、$(x, lcm(m_1, m_2))$ を返します。  
解が存在しない場合は $(0, 0)$ を返します。  
また、この合同式の解は、$b_1 \equiv b_2 \pmod{gcd(m_1, m_2)}$ であるときに限り存在し、周期 $lcm(m_1, m_2)$ の中で一意です。  

**制約**

- `T` は `int`, `long long`
- $lcm(m_1, m_2)$ が `T` で表現可能
- $0 < m_1, m_2$

**計算量**

- $\mathcal{O}(\log{\min(m1, m2)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/chinese_remainder.hpp"
using namespace std;

int main() {
	auto [a, l] = tk::chinese_remainder(2, 3, 5, 12);
	cout << "chinese_remainder(2, 3, 5, 12) = (" << a << ", " << l << ")" << endl; // (5, 12)
	
	tie(a, l) = tk::chinese_remainder(3, 7, 6, 11);
	cout << "chinese_remainder(3, 7, 6, 11) = (" << a << ", " << l << ")" << endl; // (17, 77)
	
	tie(a, l) = tk::chinese_remainder(0, 10, 0, 4);
	cout << "chinese_remainder(0, 10, 0, 4) = (" << a << ", " << l << ")" << endl; // (0, 20)
	
	tie(a, l) = tk::chinese_remainder(2, 10, 1, 8);
	cout << "chinese_remainder(2, 10, 1, 8) = (" << a << ", " << l << ")" << endl; // (0, 0)
}
```

<br>

# 参考

2021/03/18: [https://qiita.com/drken/items/ae02240cd1f8edfc86fd](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)  
2020/09/21: [AC Library](https://github.com/atcoder/ac-library)  

<br>