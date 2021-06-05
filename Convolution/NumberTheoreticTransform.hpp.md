---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/mod_pow_inv.hpp
    title: "$\\mod{m}$ \u3067\u306E\u51AA\u3068\u9006\u5143"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: "\u4EFB\u610F mod \u6570\u8AD6\u5909\u63DB (\u4EFB\u610F mod NTT)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform.test.cpp
    title: Test/NumberTheoreticTransform.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform_AnyMod.test.cpp
    title: Test/NumberTheoreticTransform_AnyMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp
    links:
    - https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp
  bundledCode: "#line 1 \"Convolution/NumberTheoreticTransform.hpp\"\n\n\n\r\n#line\
    \ 1 \"Mathematics/mod_pow_inv.hpp\"\n\n\n\r\n#include <cassert>\r\n#include <type_traits>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp\r\
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
    \ a[j]);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\n#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\
    \n\r\n#include \"Mathematics/mod_pow_inv.hpp\"\r\n\r\n#include <vector>\r\n#include\
    \ <utility>\r\n#include <cassert>\r\n#include <cstdint>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp\r\
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
    \ a[j]);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP"
  dependsOn:
  - Mathematics/mod_pow_inv.hpp
  isVerificationFile: false
  path: Convolution/NumberTheoreticTransform.hpp
  requiredBy:
  - Convolution/NumberTheoreticTransform_AnyMod.hpp
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
  - Test/NumberTheoreticTransform.test.cpp
documentation_of: Convolution/NumberTheoreticTransform.hpp
layout: document
title: "\u6570\u8AD6\u5909\u63DB (NTT)"
---

# 概要

特殊な整数 $M$ と $2$ つの整数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x) \bmod{M}$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  
基数 $2$ の時間間引き Cooley-Tukey 型アルゴリズムを用いています。  

<br>

# 静的メンバ関数

### std::vector&lt;T&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i \bmod{M}$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i \bmod{M}$ として、
積 $f(x)g(x) \equiv \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i \pmod{M}$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i] \bmod{M}$ 返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- $M > 0$
- 適当な整数 $p$ を用いて $M - 1 = Np$ ($N$ は $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪) と表すことが可能
- `PRIMITIVE_ROOT` は $M$ の原始根
- `T` は `int`, `unsigned int`, `long long int`, `unsigned long long`

**計算量**

- $N$ を $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# 使用例

代表的な `MOD` とその原始根の組み合わせの例を下に載せておきます。

```cpp
NumberTheoreticTransform<998'244'353, 3> // 2^23 | (mod - 1)
NumberTheoreticTransform<1'224'736'769, 3> // 2^24 | (mod - 1)
NumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)
NumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)
```

```cpp
#include <bits/stdc++.h>
#include "Convolution/NumberTheoreticTransform.hpp"
using namespace std;

int main() {
	vector<int> a({0, 1, 2, 3}), b({2, 3, 4});
	auto c = NumberTheoreticTransform<998244353, 3>::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 16 17 12
	// 0 0 0
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	
	vector<int> a2({4}), b2({3, 2});
	auto c2 = NumberTheoreticTransform<167772161, 3>::multiply(a2, b2);
	cout << "size = " << c2.size() << endl; // 2
	for (int i = 0; i < c2.size(); ++i) cout << c2[i] << " "; cout << endl; // 12 8
	// 12 
	//    8
	// ==============
	// 12 8
	
	vector<int> a3({-3, 1}), b3({-2, -9});
	auto c3 = NumberTheoreticTransform<5, 3>::multiply(a3, b3);
	cout << "size = " << c3.size() << endl; // 3
	for (int i = 0; i < c3.size(); ++i) cout << c3[i] << " "; cout << endl; // 1 0 1
	// 1(6) 3(-2)
	//      2(27) 1(-9)
	// ==============
	// 1    0     1
	
	vector<int> a4, b4({1, 2, 3});
	auto c4 = NumberTheoreticTransform<469'762'049, 3>::multiply(a4, b4);
	cout << "size = " << c4.size() << endl; // 0
}
```

<br>

# 参考

2020/07/27: [https://math314.hateblo.jp/entry/2015/05/07/014908](https://math314.hateblo.jp/entry/2015/05/07/014908)  
2020/07/27: [https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0](https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0)  
2020/07/27: [http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html](http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html)  

<br>