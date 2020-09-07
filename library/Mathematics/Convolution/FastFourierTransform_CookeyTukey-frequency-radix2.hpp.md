---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#637dbc1fa2c49b2df4202c454476276a">Mathematics/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/Test/FastFourierTransform_CookeyTukey-frequency-radix2.test.cpp.html">Test/FastFourierTransform_CookeyTukey-frequency-radix2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP
#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP

#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

基数 2 周波数間引き Cooley-Tukey

# 解説
N を 2 冪として f[0], f[1], \ldots, f[N - 1] が既知

\omega_N := 1 の原始 N 乗根

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-i}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-ki}
で i の偶奇で分ける。

0 \leq i < N/2 として
F[\omega_N^{-2i}]       = \Sum_{k = 0}^{N/2 - 1} (f[k] + f[k + N/2]) \omega_{N/2}^{-ki}
F[\omega_N^{-(2i + 1)}] = \Sum_{k = 0}^{N/2 - 1} (f[k] - f[k + N/2]) \omega_{N/2}^{-ki}

計算結果はビット反転した位置になっているので最後に修正する。

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

# 参考
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/05/02
*/

struct FastFourierTransform {
public:
	using value_type = double;
	using size_type = std::size_t;
	using complex_type = std::complex<value_type>;
	
	template<typename T>
	static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) {
		if (A.empty() || B.empty()) return {};
		size_type n_ = A.size() + B.size() - 1;
		size_type n = 1, ni = 0;
		while (n < n_) n <<= 1, ++ni;
		const std::vector<complex_type> zeta = _zeta(ni);
		
		std::vector<complex_type> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i], 0);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);
		a.resize(n); fft(a, zeta);
		b.resize(n); fft(b, zeta);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));
		fft(c, zeta);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));
		return res;
	}
	
private:
	static void fft(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 1;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		size_type ni = zi;
		while (1 << ni > A.size()) --ni;
		
		for (size_type n = N; n > 1; n >>= 1, --ni) {
			const size_type m = n >> 1;
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					const complex_type a = A[i], b = A[i + m];
					A[i] = a + b;
					A[i + m] = (a - b) * zeta[(i - p) << (zi - ni)];
				}
			}
		}
		bit_reverse(A);
	}
	
	static void bit_reverse(std::vector<complex_type> &A) {
		const size_type N = A.size();
		for (size_type i = 1, j = 0; i < N - 1; ++i) {
			for (size_type k = N >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(A[i], A[j]);
		}
	}
	
	static std::vector<complex_type> _zeta(size_type max_p) {
		const value_type PI = std::acos(static_cast<value_type>(-1));
		// zeta[j] := \omega_{2^max_p}^j (0 \leq j < 2^(max_p - 1))
		std::vector<complex_type> zeta;
		zeta.reserve(1 << max_p - 1);
		zeta.emplace_back(1, 0);
		for (size_type i = 0; i < max_p - 1; ++i) {
			const value_type rad = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);
			zeta.emplace_back(std::polar<value_type>(1, rad));
			for (size_type j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {
				zeta.emplace_back(zeta[1 << i ^ j] * zeta[1 << i]);
			}
		}
		return zeta;
	}
};

#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp"



#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

基数 2 周波数間引き Cooley-Tukey

# 解説
N を 2 冪として f[0], f[1], \ldots, f[N - 1] が既知

\omega_N := 1 の原始 N 乗根

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-i}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-ki}
で i の偶奇で分ける。

0 \leq i < N/2 として
F[\omega_N^{-2i}]       = \Sum_{k = 0}^{N/2 - 1} (f[k] + f[k + N/2]) \omega_{N/2}^{-ki}
F[\omega_N^{-(2i + 1)}] = \Sum_{k = 0}^{N/2 - 1} (f[k] - f[k + N/2]) \omega_{N/2}^{-ki}

計算結果はビット反転した位置になっているので最後に修正する。

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

# 参考
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/05/02
*/

struct FastFourierTransform {
public:
	using value_type = double;
	using size_type = std::size_t;
	using complex_type = std::complex<value_type>;
	
	template<typename T>
	static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) {
		if (A.empty() || B.empty()) return {};
		size_type n_ = A.size() + B.size() - 1;
		size_type n = 1, ni = 0;
		while (n < n_) n <<= 1, ++ni;
		const std::vector<complex_type> zeta = _zeta(ni);
		
		std::vector<complex_type> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i], 0);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);
		a.resize(n); fft(a, zeta);
		b.resize(n); fft(b, zeta);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));
		fft(c, zeta);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));
		return res;
	}
	
private:
	static void fft(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 1;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		size_type ni = zi;
		while (1 << ni > A.size()) --ni;
		
		for (size_type n = N; n > 1; n >>= 1, --ni) {
			const size_type m = n >> 1;
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					const complex_type a = A[i], b = A[i + m];
					A[i] = a + b;
					A[i + m] = (a - b) * zeta[(i - p) << (zi - ni)];
				}
			}
		}
		bit_reverse(A);
	}
	
	static void bit_reverse(std::vector<complex_type> &A) {
		const size_type N = A.size();
		for (size_type i = 1, j = 0; i < N - 1; ++i) {
			for (size_type k = N >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(A[i], A[j]);
		}
	}
	
	static std::vector<complex_type> _zeta(size_type max_p) {
		const value_type PI = std::acos(static_cast<value_type>(-1));
		// zeta[j] := \omega_{2^max_p}^j (0 \leq j < 2^(max_p - 1))
		std::vector<complex_type> zeta;
		zeta.reserve(1 << max_p - 1);
		zeta.emplace_back(1, 0);
		for (size_type i = 0; i < max_p - 1; ++i) {
			const value_type rad = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);
			zeta.emplace_back(std::polar<value_type>(1, rad));
			for (size_type j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {
				zeta.emplace_back(zeta[1 << i ^ j] * zeta[1 << i]);
			}
		}
		return zeta;
	}
};



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
