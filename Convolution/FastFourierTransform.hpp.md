---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform.test.cpp
    title: Test/FastFourierTransform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp
    links:
    - https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp
  bundledCode: "#line 1 \"Convolution/FastFourierTransform.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <complex>\r\n#include <algorithm>\r\n#include <cstdint>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp\r\
    \n */\r\nstruct FastFourierTransform {\r\n\tusing value_type = double;\r\n\tusing\
    \ complex_type = std::complex<value_type>;\r\n\t\r\nprivate:\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\tconstexpr static value_type pi = 3.1415926535897932384626433832795028841972;\r\
    \n\tconstexpr static complex_type ie{0, 1};\r\n\t\r\n\tuint32 mlog_n;\r\n\tstd::vector<complex_type>\
    \ zeta;\r\n\t\r\npublic:\r\n\texplicit FastFourierTransform(uint32 max_n) : mlog_n(calc_l2(max_n)),\
    \ zeta(zeta_(mlog_n)) {}\r\n\t\r\n\ttemplate<typename T>\r\n\tstd::vector<value_type>\
    \ operator ()(const std::vector<T> & a, const std::vector<T> & b) const {\r\n\t\
    \tif (a.empty() || b.empty()) return {};\r\n\t\tif (a.size() == 1 && b.size()\
    \ == 1) return {static_cast<value_type>(a.front()) * b.front()};\r\n\t\tassert((a.size()\
    \ + b.size() - 1) <= (1u << mlog_n));\r\n\t\treturn multiply_sub(a, b, zeta, mlog_n);\r\
    \n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tif (a.empty() || b.empty())\
    \ return {};\r\n\t\tif (a.size() == 1 && b.size() == 1) return {static_cast<value_type>(a.front())\
    \ * b.front()};\r\n\t\tconst uint32 log_n = calc_l2(a.size() + b.size() - 1);\r\
    \n\t\tconst std::vector<complex_type> zeta = zeta_(log_n);\r\n\t\treturn multiply_sub(a,\
    \ b, zeta, log_n);\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename T>\r\n\tstatic\
    \ std::vector<value_type> multiply_sub(const std::vector<T> & a, const std::vector<T>\
    \ & b, const std::vector<complex_type> & zeta, uint32 log_z) {\r\n\t\tconst uint32\
    \ n_ = a.size() + b.size() - 1;\r\n\t\tconst uint32 log_n = calc_l2(n_), n = 1u\
    \ << log_n, m = n >> 1;\r\n\t\tstd::vector<complex_type> h(n);\r\n\t\tfor (uint32\
    \ i = 0; i < a.size(); ++i) h[i].real(a[i]);\r\n\t\tfor (uint32 i = 0; i < b.size();\
    \ ++i) h[i].imag(b[i]);\r\n\t\tfft(h, log_n, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<complex_type>\
    \ p(m);\r\n\t\t{\r\n\t\t\tconst value_type cf = h[0].real() * h[0].imag();\r\n\
    \t\t\tconst value_type cb = h[m].real() * h[m].imag();\r\n\t\t\tp[0] = complex_type(cf\
    \ + cb, -(cf - cb)) / 2.0;\r\n\t\t}\r\n\t\tfor (uint32 i = 1; i <= (m >> 1); ++i)\
    \ {\r\n\t\t\tconst complex_type cf = -(h[i] + std::conj(h[n - i])) * (h[i] - std::conj(h[n\
    \ - i])) * ie;\r\n\t\t\tconst complex_type cb = -(h[m - i] + std::conj(h[m + i]))\
    \ * (h[m - i] - std::conj(h[m + i])) * ie;\r\n\t\t\tp[i] = std::conj((cf + std::conj(cb)\
    \ + (cf - std::conj(cb)) * std::conj(zeta_f(log_n, i, zeta, log_z)) * ie)) / 8.0;\r\
    \n\t\t\tif (i != m / 2) p[m - i] = std::conj((cb + std::conj(cf)) + (cb - std::conj(cf))\
    \ * std::conj(zeta_f(log_n, m - i, zeta, log_z)) * ie) / 8.0;\r\n\t\t}\r\n\t\t\
    fft(p, log_n - 1, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\
    \t\tres.reserve(n_);\r\n\t\tfor (uint32 i = 0; i < m; ++i) {\r\n\t\t\tif ((i <<\
    \ 1) < n_) res.emplace_back(p[i].real() / static_cast<value_type>(m));\r\n\t\t\
    \tif ((i << 1 | 1) < n_) res.emplace_back(-p[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic void fft(std::vector<complex_type>\
    \ & a, uint32 log_n, const std::vector<complex_type> & zeta, uint32 log_z) {\r\
    \n\t\tconst uint32 n = a.size(), m = n >> 1;\r\n\t\tbit_reverse(a);\r\n\t\tfor\
    \ (uint32 w = 4, c = 2; w <= n; w <<= 2, c += 2) {\r\n\t\t\tconst uint32 s = w\
    \ >> 2;\r\n\t\t\tfor (uint32 p = 0; p < n; p += w) {\r\n\t\t\t\tfor (uint32 i\
    \ = 0; i < s; ++i) {\r\n\t\t\t\t\tconst uint32 pos = p + i;\r\n\t\t\t\t\tconst\
    \ complex_type a0 = a[pos], a2 = a[pos + s] * zeta_f(c - 1, i, zeta, log_z);\r\
    \n\t\t\t\t\tconst complex_type a1 = a[pos + (s << 1)] * zeta_f(c, i, zeta, log_z),\
    \ a3 = a[pos + w - s] * zeta_f(c, 3 * i, zeta, log_z);\r\n\t\t\t\t\tconst complex_type\
    \ lp = a0 + a2, rp = a1 + a3, ln = a0 - a2, rn = a1 - a3;\r\n\t\t\t\t\ta[pos]\
    \ = lp + rp;\r\n\t\t\t\t\ta[pos + (s << 1)] = lp - rp;\r\n\t\t\t\t\ta[pos + s]\
    \ = ln + rn * ie;\r\n\t\t\t\t\ta[pos + w - s] = ln - rn * ie;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tif (~log_n & 1) return;\r\n\t\tfor (uint32 i = 0; i <\
    \ m; ++i) {\r\n\t\t\tconst complex_type x = a[i], y = a[i + m] * zeta_f(log_n,\
    \ i, zeta, log_z);\r\n\t\t\ta[i] = x + y;\r\n\t\t\ta[i + m] = x - y;\r\n\t\t}\r\
    \n\t}\r\n\t\r\n\tstatic uint32 calc_l2(uint32 n_) noexcept {\r\n\t\tuint32 log_n\
    \ = 0;\r\n\t\tfor (uint32 n = 1; n < n_; n <<= 1) ++log_n;\r\n\t\treturn log_n;\r\
    \n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> & a) noexcept\
    \ {\r\n\t\tconst uint32 N = a.size();\r\n\t\tfor (uint32 i = 1, j = 0; i < N -\
    \ 1; ++i) {\r\n\t\t\tfor (uint32 k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\t\
    if (i < j) std::swap(a[i], a[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ zeta_(uint32 log_n) {\r\n\t\tif (log_n == 0) return {};\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << (log_n - 1));\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (uint32 i = 0; i < (log_n - 1); ++i) {\r\n\t\t\tconst complex_type t\
    \ = std::polar<value_type>(1, 2.0 * pi / static_cast<value_type>(1 << (log_n -\
    \ i)));\r\n\t\t\tzeta.emplace_back(t);\r\n\t\t\tfor (uint32 j = 1; j < (1u <<\
    \ i); ++j) zeta.emplace_back(zeta[j] * t);\r\n\t\t}\r\n\t\treturn zeta;\r\n\t\
    }\r\n\t\r\n\tstatic complex_type zeta_f(uint32 d, uint32 p, const std::vector<complex_type>\
    \ & zeta, uint32 log_z) noexcept {\r\n\t\tconst uint32 idx = p << (log_z - d);\r\
    \n\t\treturn idx < zeta.size() ? zeta[idx] : -zeta[idx - zeta.size()];\r\n\t}\r\
    \n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP\r\n#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP\r\
    \n\r\n#include <vector>\r\n#include <complex>\r\n#include <algorithm>\r\n#include\
    \ <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp\r\
    \n */\r\nstruct FastFourierTransform {\r\n\tusing value_type = double;\r\n\tusing\
    \ complex_type = std::complex<value_type>;\r\n\t\r\nprivate:\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\tconstexpr static value_type pi = 3.1415926535897932384626433832795028841972;\r\
    \n\tconstexpr static complex_type ie{0, 1};\r\n\t\r\n\tuint32 mlog_n;\r\n\tstd::vector<complex_type>\
    \ zeta;\r\n\t\r\npublic:\r\n\texplicit FastFourierTransform(uint32 max_n) : mlog_n(calc_l2(max_n)),\
    \ zeta(zeta_(mlog_n)) {}\r\n\t\r\n\ttemplate<typename T>\r\n\tstd::vector<value_type>\
    \ operator ()(const std::vector<T> & a, const std::vector<T> & b) const {\r\n\t\
    \tif (a.empty() || b.empty()) return {};\r\n\t\tif (a.size() == 1 && b.size()\
    \ == 1) return {static_cast<value_type>(a.front()) * b.front()};\r\n\t\tassert((a.size()\
    \ + b.size() - 1) <= (1u << mlog_n));\r\n\t\treturn multiply_sub(a, b, zeta, mlog_n);\r\
    \n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tif (a.empty() || b.empty())\
    \ return {};\r\n\t\tif (a.size() == 1 && b.size() == 1) return {static_cast<value_type>(a.front())\
    \ * b.front()};\r\n\t\tconst uint32 log_n = calc_l2(a.size() + b.size() - 1);\r\
    \n\t\tconst std::vector<complex_type> zeta = zeta_(log_n);\r\n\t\treturn multiply_sub(a,\
    \ b, zeta, log_n);\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename T>\r\n\tstatic\
    \ std::vector<value_type> multiply_sub(const std::vector<T> & a, const std::vector<T>\
    \ & b, const std::vector<complex_type> & zeta, uint32 log_z) {\r\n\t\tconst uint32\
    \ n_ = a.size() + b.size() - 1;\r\n\t\tconst uint32 log_n = calc_l2(n_), n = 1u\
    \ << log_n, m = n >> 1;\r\n\t\tstd::vector<complex_type> h(n);\r\n\t\tfor (uint32\
    \ i = 0; i < a.size(); ++i) h[i].real(a[i]);\r\n\t\tfor (uint32 i = 0; i < b.size();\
    \ ++i) h[i].imag(b[i]);\r\n\t\tfft(h, log_n, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<complex_type>\
    \ p(m);\r\n\t\t{\r\n\t\t\tconst value_type cf = h[0].real() * h[0].imag();\r\n\
    \t\t\tconst value_type cb = h[m].real() * h[m].imag();\r\n\t\t\tp[0] = complex_type(cf\
    \ + cb, -(cf - cb)) / 2.0;\r\n\t\t}\r\n\t\tfor (uint32 i = 1; i <= (m >> 1); ++i)\
    \ {\r\n\t\t\tconst complex_type cf = -(h[i] + std::conj(h[n - i])) * (h[i] - std::conj(h[n\
    \ - i])) * ie;\r\n\t\t\tconst complex_type cb = -(h[m - i] + std::conj(h[m + i]))\
    \ * (h[m - i] - std::conj(h[m + i])) * ie;\r\n\t\t\tp[i] = std::conj((cf + std::conj(cb)\
    \ + (cf - std::conj(cb)) * std::conj(zeta_f(log_n, i, zeta, log_z)) * ie)) / 8.0;\r\
    \n\t\t\tif (i != m / 2) p[m - i] = std::conj((cb + std::conj(cf)) + (cb - std::conj(cf))\
    \ * std::conj(zeta_f(log_n, m - i, zeta, log_z)) * ie) / 8.0;\r\n\t\t}\r\n\t\t\
    fft(p, log_n - 1, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\
    \t\tres.reserve(n_);\r\n\t\tfor (uint32 i = 0; i < m; ++i) {\r\n\t\t\tif ((i <<\
    \ 1) < n_) res.emplace_back(p[i].real() / static_cast<value_type>(m));\r\n\t\t\
    \tif ((i << 1 | 1) < n_) res.emplace_back(-p[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic void fft(std::vector<complex_type>\
    \ & a, uint32 log_n, const std::vector<complex_type> & zeta, uint32 log_z) {\r\
    \n\t\tconst uint32 n = a.size(), m = n >> 1;\r\n\t\tbit_reverse(a);\r\n\t\tfor\
    \ (uint32 w = 4, c = 2; w <= n; w <<= 2, c += 2) {\r\n\t\t\tconst uint32 s = w\
    \ >> 2;\r\n\t\t\tfor (uint32 p = 0; p < n; p += w) {\r\n\t\t\t\tfor (uint32 i\
    \ = 0; i < s; ++i) {\r\n\t\t\t\t\tconst uint32 pos = p + i;\r\n\t\t\t\t\tconst\
    \ complex_type a0 = a[pos], a2 = a[pos + s] * zeta_f(c - 1, i, zeta, log_z);\r\
    \n\t\t\t\t\tconst complex_type a1 = a[pos + (s << 1)] * zeta_f(c, i, zeta, log_z),\
    \ a3 = a[pos + w - s] * zeta_f(c, 3 * i, zeta, log_z);\r\n\t\t\t\t\tconst complex_type\
    \ lp = a0 + a2, rp = a1 + a3, ln = a0 - a2, rn = a1 - a3;\r\n\t\t\t\t\ta[pos]\
    \ = lp + rp;\r\n\t\t\t\t\ta[pos + (s << 1)] = lp - rp;\r\n\t\t\t\t\ta[pos + s]\
    \ = ln + rn * ie;\r\n\t\t\t\t\ta[pos + w - s] = ln - rn * ie;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tif (~log_n & 1) return;\r\n\t\tfor (uint32 i = 0; i <\
    \ m; ++i) {\r\n\t\t\tconst complex_type x = a[i], y = a[i + m] * zeta_f(log_n,\
    \ i, zeta, log_z);\r\n\t\t\ta[i] = x + y;\r\n\t\t\ta[i + m] = x - y;\r\n\t\t}\r\
    \n\t}\r\n\t\r\n\tstatic uint32 calc_l2(uint32 n_) noexcept {\r\n\t\tuint32 log_n\
    \ = 0;\r\n\t\tfor (uint32 n = 1; n < n_; n <<= 1) ++log_n;\r\n\t\treturn log_n;\r\
    \n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> & a) noexcept\
    \ {\r\n\t\tconst uint32 N = a.size();\r\n\t\tfor (uint32 i = 1, j = 0; i < N -\
    \ 1; ++i) {\r\n\t\t\tfor (uint32 k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\t\
    if (i < j) std::swap(a[i], a[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ zeta_(uint32 log_n) {\r\n\t\tif (log_n == 0) return {};\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << (log_n - 1));\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (uint32 i = 0; i < (log_n - 1); ++i) {\r\n\t\t\tconst complex_type t\
    \ = std::polar<value_type>(1, 2.0 * pi / static_cast<value_type>(1 << (log_n -\
    \ i)));\r\n\t\t\tzeta.emplace_back(t);\r\n\t\t\tfor (uint32 j = 1; j < (1u <<\
    \ i); ++j) zeta.emplace_back(zeta[j] * t);\r\n\t\t}\r\n\t\treturn zeta;\r\n\t\
    }\r\n\t\r\n\tstatic complex_type zeta_f(uint32 d, uint32 p, const std::vector<complex_type>\
    \ & zeta, uint32 log_z) noexcept {\r\n\t\tconst uint32 idx = p << (log_z - d);\r\
    \n\t\treturn idx < zeta.size() ? zeta[idx] : -zeta[idx - zeta.size()];\r\n\t}\r\
    \n};\r\n\r\n#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/FastFourierTransform.hpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform.test.cpp
documentation_of: Convolution/FastFourierTransform.hpp
layout: document
title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (FFT)"
---

# 概要

$2$ つの実数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x)$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  
基数 $4$ の時間間引き Cooley-Tukey 型アルゴリズムを用いています。  

<br>

# コンストラクタ

# FastFourierTransform(uint32_t max_n)

計算を行う多項式積の最大次数 $N$ が分かっている場合、`max_n` に $N + 1$ を指定します。
事前に計算テーブルを構築することにより少しだけ高速になります。  
実装の都合上、事前計算テーブルを使用した積の計算には `()` 演算子を使用して下さい。  

**制約**

- `T` は `int`, `long long int`, `float`, `double`

**計算量**

- $N := \|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# メンバ関数

### std::vector&lt;double&gt; operator ()(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

静的メンバ関数 `multiply(...)` と仕様は同じです。
事前計算テーブルを使用することによって少しだけ高速になります。  

**制約**

- `T` は `int`, `long long int`, `float`, `double`

**計算量**

- $N := \|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# 静的メンバ関数

### std::vector&lt;double&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i$ として、
積 $f(x)g(x) = \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i]$ を `double` 型で返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- `T` は `int`, `long long int`, `float`, `double`

**計算量**

- $N := \|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Convolution/FastFourierTransform.hpp"
using namespace std;

int main() {
	vector<int> a({0, 1, 2, 3}), b({2, 3, 4});
	auto c = FastFourierTransform::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 16 17 12
	// 0 0 0
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	// c は double 型であることに注意
	
	vector<int> d{};
	cout << "size = " << FastFourierTransform::multiply(a, d).size() << endl; // 0
	
	vector<double> ad({1.5, 2}), bd({2, 5.5, 4});
	auto cd = FastFourierTransform::multiply(ad, bd);
	cout << "size = " << cd.size() << endl; // 4
	for (int i = 0; i < cd.size(); ++i) cout << cd[i] << " "; cout << endl; // 3 12.25 17 8
	// 3 8.25  6
	//   4     11 8
	// ==============
	// 3 12.25 17 8
	
	auto fft = FastFourierTransform(6); // zeta 配列を使い回す
	auto pc = fft(a, b);
	auto pcd = fft(ad, bd);
	cout << "c == pc : " << boolalpha << (c == pc) << endl; // true
	cout << "cd == pcd : " << boolalpha << (cd == pcd) << endl; // true
}
```

<br>

# 解説

離散フーリエ変換の基礎については既知であるとします。    

### 記法

多項式 $f(x)$ の $i$ 次の係数を $f[k]$ と書きます。
つまり、$f(x)$ の次数を $d$ とすると、 $f(x) = \sum_{i=0}^d f[i]x^i$ です。  
$\zeta_N$ は $1$ の $N$ 乗根を表します。
また、複素数 $z$ の複素共役を $\overline{z}$ 、虚数単位を $j$ と表します。  
以下 $N$ が $2$ の冪として次数 $N-1$ の多項式を扱います。  

<br>

### 離散フーリエ変換

$N-1$ 次多項式 $f(x)$ の離散フーリエ変換 $F(X)$ を $F(X) = \sum_{i=0}^{N-1} f(\zeta_N^i) X^i$ で定義します。  

$f[k] = \frac{1}{N} F(\zeta_N^{-k})$ です(逆離散フーリエ変換)。詳しく知りたい方は参考欄のサイトを参照してください。  

$F(\zeta_N^{-k}) = \sum_{i=0}^{N-1} F[i] \zeta_N^{-ki} = \overline{\sum_{i=0}^{N-1} \overline{F[i]} \zeta_N^{ki}}$ より、$F(X)$ の係数の複素共役を取った後で離散フーリエ変換を行い $N$ で割ることにより $f(x)$ が復元できます。  

<br>

### $2$ つの実数係数多項式の離散フーリエ変換を $1$ 回の離散フーリエ変換で行うテク

$2$ つの実数係数多項式 $f(x), g(x)$ のフーリエ変換 $F(X), G(X)$ を $1$ 回の離散フーリエ変換で求めることができます。  

まず、$F[N] = F[0]$ として、$F[N-t] = \overline{F[t]}$ が成り立ちます。  
これは、$f(x)$ が実数係数であることから $f[k] = \overline{f[k]}$ が成り立ち、$F[N-t] = \sum_{i=0}^{N-1} f[i] \zeta_N^{N-t} = \overline{\sum_{i=0}^{N-1} \overline{f[i] \zeta_N^{-t}}} = \overline{\sum_{i=0}^{N-1} f[i] \zeta_N^t} = F[t]$ より分かります。  

ここで、$h(x) := f(x) + j g(x)$ として多項式 $h(x)$ を定義します。$h(x)$ の離散フーリエ変換 $H(X)$ に関して $H(X) = F(X) + j G(X)$ です。  

一方、$\overline{H[N-t]} = \overline{F(N-t)} - \overline{G[N-t]} j = F[t] - j G[t]$ も成り立ちます。  

これら $2$ つの等式を連立して解くことにより次の式が得られます。  

$$F[t] = \frac{1}{2} (H[t] + \overline{H[N-t]})$$

$$G[t] = \frac{1}{2i} (H[t] - \overline{H[N-t]})$$

これより、$C[t] := F[t] G[t]$ とすると、$C[t] = \frac{1}{4i} (H[t] + \overline{H[N-t]})(H[t] - \overline{H[N-t]})$ です。  

$C[t]$ に対して逆離散フーリエ変換を行うことにより積 $c(x) = f(x) g(x)$ が計算できます。  

### 実数係数多項式の離散フーリエ変換

周波数間引きにより、$2$ つの $N/2 - 1$ 次の多項式 $c_e, c_o$ を $c_e[k] = c[2k], c_o[k] = c[2k+1]$ として定めると、

$$C[t] = C_e[t] + \zeta_N^t C_o[t]$$

$$C[t + N/2] = C_e[t] - \zeta_N^t C_o[t]$$

です。  

これらを $C_e[t], C_o[t]$ について解くことにより、

$$C_e[t] = \frac{1}{2} (C[t] + C[t + N/2])$$

$$C_o[t] = \frac{1}{2} \overline{\zeta_N^{t}} (C[t] - C[t + N/2])$$

が得られ、$C(X)$ から $C_o(X), C_e(X)$ が求まることが分かります。  

ここで、$p(x) := c_e(x) + j c_o(x)$ として多項式 $p(x)$ を定義します。  
$p(x)$ の離散フーリエ変換 $P(X) = C_e(X) + j C_o(X)$ を逆離散フーリエ変換することにより $p(x) = c_e(x) + j c_o(x)$ が復元できることと、$c_e(x), c_o(x)$ は実数係数多項式なので $p[i]$ の実部、虚部がそれぞれ $c_e[i], c_o[i]$  に対応することに注意しておきます。  

$C(X)$ は先程の "$2$ つの実数係数多項式の離散フーリエ変換を $1$ 回の離散フーリエ変換で行うテク" で求めることができるので、$C_e(X), C_o(X)$ は計算が可能です。$C_e(X), C_o(X)$ から $P(X)$ を構築して逆離散フーリエ変換を行うことにより $c_e(x), c_o(x)$ すなわち、$c(x)$ が計算できます。  

したがって、長さが $N$ の離散フーリエ変換と長さが半分($N/2$) の逆離散フーリエ変換を $1$ 回ずつ行うことにより積 $f(x) g(x)$ が得られました。  


### 実装

$\overline{C[N-t]} = \overline{F[N-t]G[N-t]} = F[t]G[t] = C[t]$ より、 $\overline{C[t + N/2]} = C[N - (t + N/2)] = C[N/2 - t]$ です。  

これを代入することにより、

$$C_e[t] = \frac{1}{2} (C[t] + \overline{C[N/2 - t]})$$

$$C_o[t] = \frac{1}{2} \overline{\zeta_N^{t}} (C[t] - \overline{C[N/2 - t]})$$

が得られます。  

最後に、実装を読むときのためのメモを以下に記しておきます。  

- $C[t], C[N/2 - t]$ をそれぞれ $cf, cb$ という名前で管理している
- $F[0] = H[0].real(), G[0] = H[0].imag(), F[N/2] = H[N/2].real(), G[N/2] = H[N/2].imag()$ より、
$C[0] = H[0].real() \times H[0].imag(), C[N/2] = H[N/2].real() \times H[N/2].imag()$
- $zeta[i] := \zeta_N^i\ (0 \leq i < N / 2)$
- $zeta_f(d, p) := \zeta_{2^d}^p$
- $cf, cb$ に掛けるべき $\frac{1}{4}$ を後の $p$ への代入時の計算にまとめている

<br>

# おまけ

基数 $4$ の周波数間引き Cooley-Tukey 型アルゴリズムの実装も書いたので載せておきます。  

```cpp
static void fft(std::vector<complex_type> & a, uint32 log_n, const std::vector<complex_type> & zeta, uint32 log_z) {
	const uint32 n = a.size();
	auto zeta_f = [&](uint32 d, uint32 p) {
		return zeta[p << (log_z - d)];
	};
	for (uint32 w = n, c = log_n; w >= 4; w >>= 2, c -= 2) {
		const uint32 s = w >> 2;
		for (uint32 p = 0; p < n; p += w) {
			for (uint32 i = 0; i < s; ++i) {
				const uint32 pos = p + i;
				const complex_type a0 = a[pos], a2 = a[pos + (s << 1)];
				const complex_type ep = a0 + a2, en = (a0 - a2) * zeta_f(c, i, zeta, log_z);
				const complex_type a1 = a[pos + s], a3 = a[pos + w - s];
				const complex_type op = a1 + a3, on = ie * (a1 - a3) * zeta_f(c, i, zeta, log_z);
				a[pos] = ep + op;
				a[pos + s] = (ep - op) * zeta_f(c - 1, i, zeta, log_z);
				a[pos + (s << 1)] = en + on;
				a[pos + w - s] = (en - on) * zeta_f(c - 1, i, zeta, log_z);
			}
		}
	}
	if (log_n & 1) {
		for (uint32 i = 0; i < n; i += 2) {
			const complex_type x = a[i], y = a[i + 1];
			a[i] = x + y;
			a[i + 1] = x - y;
		}
	}
	bit_reverse(a);
}
```

<br>

# TODO

TODO: 周波数間引きを用いて bit_reverese を消せるか考えてみる  
TODO: zeta 配列を線形に見るように上手く変形する  


# 参考

2020/05/01: [https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79](https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79)  
2020/08/01: [http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html](http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html)  
2021/04/16: [http://www.ocw.titech.ac.jp/index.php?module=General&action=T0300&JWC=202002382&lang=JA&vid=03](http://www.ocw.titech.ac.jp/index.php?module=General&action=T0300&JWC=202002382&lang=JA&vid=03)  

<br>