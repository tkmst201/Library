---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/euclid.hpp
    title: "\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Mathematics/mod_pow_inv.hpp
    title: "$\\mod{m}$ \u3067\u306E\u51AA\u3068\u9006\u5143"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: "\u4EFB\u610F mod \u6570\u8AD6\u5909\u63DB (\u4EFB\u610F mod NTT)"
  _extendedVerifiedWith:
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
    document_title: https://tkmst201.github.io/Library/Mathematics/garner.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/garner.hpp
  bundledCode: "#line 1 \"Mathematics/garner.hpp\"\n\n\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n#include <type_traits>\r\n\r\n#line 1 \"Mathematics/euclid.hpp\"\
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
    \n"
  code: "#ifndef INCLUDE_GUARD_GARNER_HPP\r\n#define INCLUDE_GUARD_GARNER_HPP\r\n\r\
    \n#include <vector>\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\n#include\
    \ \"Mathematics/euclid.hpp\"\r\n#include \"Mathematics/mod_pow_inv.hpp\"\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/garner.hpp\r\
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
    #endif // INCLUDE_GUARD_GARNER_HPP"
  dependsOn:
  - Mathematics/euclid.hpp
  - Mathematics/mod_pow_inv.hpp
  isVerificationFile: false
  path: Mathematics/garner.hpp
  requiredBy:
  - Convolution/NumberTheoreticTransform_AnyMod.hpp
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/garner.test.cpp
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
documentation_of: Mathematics/garner.hpp
layout: document
title: "Garner (\u9023\u7ACB\u4E00\u6B21\u5408\u540C\u5F0F mod M)"
---

# 概要

連立一次合同式の解 $\pmod M$ を求めます。  
似たような問題として、[中国剰余定理](https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp)があります。  

<br>

# 関数

### bool T pre_garner(const vector&lt;T&gt; & b, const vector&lt;T&gt; & m)

連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

$$\vdots$$

$$x \equiv b_K \pmod{m_K}$$

と同値な連立一次合同式であって、$m_i, m_j$ が互いに素、$0 \leq b_i < m_i$ となるように書き換えます。  
この合同式に解が存在するならば $true$ を、存在しないのならば $false$ を返します。  
連立一次合同式の解の存在条件や一意性については [中国剰余定理](https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp)を参照してください。  

**制約**

- `T` は `int`, `long long`
- $0 < m_i$

**計算量**

- $\mathcal{O}(K^2 \log{\max{m_i}} \log{\log{\max{m_i}}}))$

---

### template&lt;typename T, typename U&gt; T garner(const vector&lt;T&gt; & b, const vector&lt;T&gt; & m, const T M)

$m_i, m_j (i \neq j)$ が互いに素な連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

$$\vdots$$

$$x \equiv b_K \pmod{m_K}$$

の解 $x \pmod lcm(m_1, m_2, \ldots, m_K)$ に対して、 $x \pmod M$ を返します。  
内部の計算で使用する型を `U` に指定してください。  

**制約**

- `T`, `U` は `int` または `long long`
- $\max(m_i, M)^2$ が `U` で表現可能
- $0 < m_i, M$

**計算量**

- $\mathcal{O}(K(K + \log{\max{m_i}}))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/garner.hpp"
using namespace std;

int main() {
	// 17
	cout << "garner({3, 6}, {7, 11}, 10000) = " << tk::garner<int, int>({3, 6}, {7, 11}, 10000) << endl;
	// 2
	cout << "garner({3, 6}, {7, 11}, 5) = " << tk::garner<int, int>({3, 6}, {7, 11}, 5) << endl;
	
	vector<int> b{2, 3, 4}, m{10, 20, 30};
	if (!tk::pre_garner(b, m)) cout << "no" << endl; // no
	
	b = {2, 12, 22};
	if (tk::pre_garner(b, m)) {
		for (int i = 0; i < 3; ++i) cout << "b[i] = " << b[i] << ", m[i] = " << m[i] << endl;
		// 52
		cout << "garner(b, m, 1000000) = " << tk::garner<int, long long>(b, m, 1000000) << endl;
		// 2
		cout << "garner(b, m, 10) = " << tk::garner<int, int>(b, m, 10) << endl;
	}
}
```

<br>

# 参考

2020/05/05: [https://qiita.com/drken/items/ae02240cd1f8edfc86fd](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)  

<br>