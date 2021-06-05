---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/NumberTheoreticTransform.hpp
    title: "\u6570\u8AD6\u5909\u63DB (NTT)"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform_AnyMod.test.cpp
    title: Test/NumberTheoreticTransform_AnyMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform_AnyMod.hpp
    links:
    - https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform_AnyMod.hpp
  bundledCode: "#line 1 \"Convolution/NumberTheoreticTransform_AnyMod.hpp\"\n\n\n\r\
    \n#line 1 \"Convolution/NumberTheoreticTransform.hpp\"\n\n\n\r\n#line 1 \"Mathematics/mod_pow_inv.hpp\"\
    \n\n\n\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp\r\n */\r\nnamespace\
    \ tk {\r\ntemplate<typename T>\r\nconstexpr T mod_pow(T x, T n, T m) noexcept\
    \ {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(m > 0);\r\n\t\
    assert(n >= 0);\r\n\tx = x % m + (x >= 0 ? 0 : m);\r\n\tT res = 1 % m;\r\n\twhile\
    \ (n > 0) {\r\n\t\tif (n & 1) res = res * x % m;\r\n\t\tx = x * x % m;\r\n\t\t\
    n >>= 1;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr\
    \ T mod_inv(T x, T m) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tassert(m > 0);\r\n\tx = x %\
    \ m + (x >= 0 ? 0 : m);\r\n\tT x1 = 1, y = m, y1 = 0;\r\n\twhile (y > 0) {\r\n\
    \t\tconst T q = x / y;\r\n\t\tT tmp = x - q * y; x = y; y = tmp;\r\n\t\ttmp =\
    \ x1 - q * y1; x1 = y1; y1 = tmp;\r\n\t}\r\n\tassert(x == 1);\r\n\tif (x1 == m)\
    \ x1 = 0;\r\n\tif (x1 < 0) x1 += m;\r\n\treturn x1;\r\n}\r\n} // namespace tk\r\
    \n\r\n\n#line 5 \"Convolution/NumberTheoreticTransform.hpp\"\n\r\n#include <vector>\r\
    \n#include <utility>\r\n#line 9 \"Convolution/NumberTheoreticTransform.hpp\"\n\
    #include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp\r\
    \n */\r\ntemplate<int MOD, int PRIMITIVE_ROOT>\r\nstruct NumberTheoreticTransform\
    \ {\r\n\tstatic_assert(MOD > 0);\r\n\tstatic_assert(PRIMITIVE_ROOT > 0);\r\n\t\
    \r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\n\tusing calc_type = long long;\r\
    \n\t\r\npublic:\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T> multiply(const\
    \ std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tstatic_assert(std::is_integral<T>::value);\r\
    \n\t\tif (a.empty() || b.empty()) return {};\r\n\t\tconst uint32 n_ = a.size()\
    \ + b.size() - 1;\r\n\t\tuint32 n = 1;\r\n\t\twhile (n < n_) n <<= 1;\r\n\t\t\
    {\r\n\t\t\tuint32 two_exp = 0;\r\n\t\t\tint tm = MOD - 1;\r\n\t\t\twhile (tm >\
    \ 0 && (~tm & 1)) ++two_exp, tm >>= 1;\r\n\t\t\tassert((1u << two_exp) >= n);\r\
    \n\t\t}\r\n\t\tstd::vector<T> c(n, 0);\r\n\t\tfor (uint32 i = 0; i < a.size();\
    \ ++i) c[i] = a[i] % MOD + (a[i] >= 0 ? 0 : MOD);\r\n\t\tntt(c);\r\n\t\tstd::vector<T>\
    \ d(n, 0);\r\n\t\tfor (uint32 i = 0; i < b.size(); ++i) d[i] = b[i] % MOD + (b[i]\
    \ >= 0 ? 0 : MOD);\r\n\t\tntt(d);\r\n\t\tconst int ninv = tk::mod_inv<int>(n,\
    \ MOD);\r\n\t\tfor (uint32 i = 0; i < n; ++i) c[i] = static_cast<calc_type>(c[i])\
    \ * d[i] % MOD * ninv % MOD;\r\n\t\td.clear();\r\n\t\tntt(c, true);\r\n\t\tc.resize(a.size()\
    \ + b.size() - 1);\r\n\t\treturn c;\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename\
    \ T>\r\n\tstatic void ntt(std::vector<T> & a, bool inv = false) {\r\n\t\tconst\
    \ uint32 n = a.size();\r\n\t\tint nroot = tk::mod_pow<calc_type>(PRIMITIVE_ROOT,\
    \ (MOD - 1) / n, MOD);\r\n\t\tif (inv) nroot = tk::mod_inv(nroot, MOD);\r\n\t\t\
    for (uint32 w = n; w > 1; w >>= 1) {\r\n\t\t\tconst uint32 m = w >> 1;\r\n\t\t\
    \tstd::vector<int> omega(m, 0);\r\n\t\t\tomega[0] = 1;\r\n\t\t\tfor (uint32 i\
    \ = 1; i < m; ++i) omega[i] = static_cast<calc_type>(omega[i - 1]) * nroot % MOD;\r\
    \n\t\t\tconst int half = static_cast<calc_type>(omega.back()) * nroot % MOD;\r\
    \n\t\t\tfor (uint32 p = 0; p < n; p += w) {\r\n\t\t\t\tfor (uint32 i = p; i <\
    \ p + m; ++i) {\r\n\t\t\t\t\tconst calc_type x = a[i], y = a[i + m];\r\n\t\t\t\
    \t\ta[i] = (x + y) % MOD;\r\n\t\t\t\t\ta[i + m] = (x + y * half % MOD) % MOD *\
    \ omega[i - p] % MOD;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnroot = static_cast<calc_type>(nroot)\
    \ * nroot % MOD;\r\n\t\t}\r\n\t\tbit_reverse(a);\r\n\t}\r\n\t\r\n\ttemplate<typename\
    \ T>\r\n\tstatic void bit_reverse(std::vector<T> & a) noexcept {\r\n\t\tconst\
    \ uint32 n = a.size();\r\n\t\tfor (uint32 i = 1, j = 0; i < n - 1; ++i) {\r\n\t\
    \t\tfor (uint32 k = n >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\tif (i < j) std::swap(a[i],\
    \ a[j]);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/garner.hpp\"\n\n\
    \n\r\n#line 7 \"Mathematics/garner.hpp\"\n\r\n#line 1 \"Mathematics/euclid.hpp\"\
    \n\n\n\r\n#line 6 \"Mathematics/euclid.hpp\"\n#include <tuple>\r\n#line 8 \"Mathematics/euclid.hpp\"\
    \n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\
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
    return {a, a1, a2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 10 \"Mathematics/garner.hpp\"\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/garner.hpp\r\
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
    \n#line 6 \"Convolution/NumberTheoreticTransform_AnyMod.hpp\"\n\r\n#line 11 \"\
    Convolution/NumberTheoreticTransform_AnyMod.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform_AnyMod.hpp\r\
    \n */\r\ntemplate<int MOD>\r\nstruct NumberTheoreticTransform_AnyMod {\r\n\tstatic_assert(MOD\
    \ > 0);\r\n\t\r\nprivate:\r\n\tusing calc_type = long long;\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\t\r\npublic:\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T>\
    \ multiply(const std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tstatic_assert(std::is_integral<T>::value);\r\
    \n\t\tstatic_assert(std::is_signed<T>::value);\r\n\t\tfor (uint32 i = 0; i < a.size();\
    \ ++i) assert(a[i] >= 0);\r\n\t\tfor (uint32 i = 0; i < b.size(); ++i) assert(b[i]\
    \ >= 0);\r\n\t\tstd::vector<T> m;\r\n\t\tauto ntt1_res = NumberTheoreticTransform<1'224'736'769,\
    \ 3>::multiply(a, b);\r\n\t\tm.emplace_back(1'224'736'769);\r\n\t\tauto ntt2_res\
    \ = NumberTheoreticTransform<469'762'049, 3>::multiply(a, b);\r\n\t\tm.emplace_back(469'762'049);\r\
    \n\t\tauto ntt3_res = NumberTheoreticTransform<167'772'161, 3>::multiply(a, b);\r\
    \n\t\tm.emplace_back(167'772'161);\r\n\t\t// auto ntt4_res = NumberTheoreticTransform<998'244'353,\
    \ 3>::multiply(a, b);\r\n\t\t// m.emplace_back(998'244'353);\r\n\t\t\r\n\t\tstd::vector<T>\
    \ c(m.size());\r\n\t\tstd::vector<T> res(ntt1_res.size());\r\n\t\tfor (uint32\
    \ i = 0; i < res.size(); ++i) {\r\n\t\t\tc[0] = ntt1_res[i];\r\n\t\t\tc[1] = ntt2_res[i];\r\
    \n\t\t\tc[2] = ntt3_res[i];\r\n\t\t\t// c[3] = ntt4_res[i];\r\n\t\t\tres[i] =\
    \ tk::garner<T, calc_type>(c, m, MOD);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP\r\n#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP\r\
    \n\r\n#include \"Convolution/NumberTheoreticTransform.hpp\"\r\n#include \"Mathematics/garner.hpp\"\
    \r\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <vector>\r\n#include\
    \ <type_traits>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform_AnyMod.hpp\r\
    \n */\r\ntemplate<int MOD>\r\nstruct NumberTheoreticTransform_AnyMod {\r\n\tstatic_assert(MOD\
    \ > 0);\r\n\t\r\nprivate:\r\n\tusing calc_type = long long;\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\t\r\npublic:\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T>\
    \ multiply(const std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tstatic_assert(std::is_integral<T>::value);\r\
    \n\t\tstatic_assert(std::is_signed<T>::value);\r\n\t\tfor (uint32 i = 0; i < a.size();\
    \ ++i) assert(a[i] >= 0);\r\n\t\tfor (uint32 i = 0; i < b.size(); ++i) assert(b[i]\
    \ >= 0);\r\n\t\tstd::vector<T> m;\r\n\t\tauto ntt1_res = NumberTheoreticTransform<1'224'736'769,\
    \ 3>::multiply(a, b);\r\n\t\tm.emplace_back(1'224'736'769);\r\n\t\tauto ntt2_res\
    \ = NumberTheoreticTransform<469'762'049, 3>::multiply(a, b);\r\n\t\tm.emplace_back(469'762'049);\r\
    \n\t\tauto ntt3_res = NumberTheoreticTransform<167'772'161, 3>::multiply(a, b);\r\
    \n\t\tm.emplace_back(167'772'161);\r\n\t\t// auto ntt4_res = NumberTheoreticTransform<998'244'353,\
    \ 3>::multiply(a, b);\r\n\t\t// m.emplace_back(998'244'353);\r\n\t\t\r\n\t\tstd::vector<T>\
    \ c(m.size());\r\n\t\tstd::vector<T> res(ntt1_res.size());\r\n\t\tfor (uint32\
    \ i = 0; i < res.size(); ++i) {\r\n\t\t\tc[0] = ntt1_res[i];\r\n\t\t\tc[1] = ntt2_res[i];\r\
    \n\t\t\tc[2] = ntt3_res[i];\r\n\t\t\t// c[3] = ntt4_res[i];\r\n\t\t\tres[i] =\
    \ tk::garner<T, calc_type>(c, m, MOD);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP"
  dependsOn:
  - Convolution/NumberTheoreticTransform.hpp
  - Mathematics/mod_pow_inv.hpp
  - Mathematics/garner.hpp
  - Mathematics/euclid.hpp
  isVerificationFile: false
  path: Convolution/NumberTheoreticTransform_AnyMod.hpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
documentation_of: Convolution/NumberTheoreticTransform_AnyMod.hpp
layout: document
title: "\u4EFB\u610F mod \u6570\u8AD6\u5909\u63DB (\u4EFB\u610F mod NTT)"
---

# 概要

[数論変換 (NTT)](https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp) に [Garner](https://tkmst201.github.io/Library/Mathematics/garner.hpp) を組み合わせて、法 $M$ が任意に取れるようになったものです。ただし、積の各係数において $\bmod{M}$ を取る前の値がある値以下に収まっている必要があります。  
$2$ つの整数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x) \bmod{M}$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  

<br>

# 静的メンバ関数

### std::vector&lt;T&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i \bmod{MOD}$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i \bmod{MOD}$ として、
積 $f(x)g(x) \equiv \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i \pmod{MOD}$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i] \bmod{MOD}$ 返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- `MOD` $> 0$
- $a_i, b_j \geq 0$
- 多項式 $a, b$ の係数の最大値を $Q$ として、$\max(\|A\|, \|B\|) * Q^2 < \prod_i m_i$ となるように $m$ が選ばれている
- `T` は `int`, `long long int`

**計算量**

法 $m$ の個数を $K$ 、$N$ を $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪とします。
- $\mathcal{O}(N\log{N} + (\|a\| + \|b\|) K(K + \log{\max{m_i}}))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Convolution/NumberTheoreticTransform_AnyMod.hpp"
using namespace std;

int main() {
	vector<int> a({0, 1, 2, 3}), b({2, 3, 4});
	auto c = NumberTheoreticTransform_AnyMod<14>::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 2 3 12
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	// 0 2 7  2  3 12
	
	vector<int> a2({4}), b2({3, 2});
	auto c2 = NumberTheoreticTransform_AnyMod<7>::multiply(a2, b2);
	cout << "size = " << c2.size() << endl; // 2
	for (int i = 0; i < c2.size(); ++i) cout << c2[i] << " "; cout << endl; // 5 1
	// 12 
	//    8
	// ==============
	// 12 8
	//  5 1
	
	vector<int> a3, b3({1, 2, 3});
	auto c3 = NumberTheoreticTransform_AnyMod<100>::multiply(a3, b3);
	cout << "size = " << c3.size() << endl; // 0
}
```

<br>

# 参考

2020/07/27: [https://math314.hateblo.jp/entry/2015/05/07/014908](https://math314.hateblo.jp/entry/2015/05/07/014908)  

<br>