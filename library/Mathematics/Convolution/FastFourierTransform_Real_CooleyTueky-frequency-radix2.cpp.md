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


# :warning: Mathematics/Convolution/FastFourierTransform_Real_CooleyTueky-frequency-radix2.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#637dbc1fa2c49b2df4202c454476276a">Mathematics/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/Convolution/FastFourierTransform_Real_CooleyTueky-frequency-radix2.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-02 15:48:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

実数の畳み込み
基数 2 周波数間引き Cooley-Tukey

# 解説
## 実数値関数の畳み込み
N を 2 冪として
 f[0], f[1], \ldots, f[N - 1], g[0], g[1], \ldots, g[N - 1] が既知で "実数"

\omega_N := 1 の原始 N 乗根

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-j}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-kj}

conj(z) は z の複素共役を表す。

f[j] は実数なので conj(f[j]) = f[j] より、
F[\omega_N^{-(N - j)}] = conj(F[\omega_N^{-j}])

h[k] := f[k] + g[k] i ( i は虚数単位) (0 \leq k < N)

H[\omega_N^{-j}] = F[\omega_N^{-j}] + G[\omega_N^{-j}] i
H[\omega_N^{N - j}] = conj(F[\omega_N^{-j}]) - conj(G[\omega_N^{-j}]) i
を連立させて解くと、

F[\omega_N^{-j}] = (H[\omega_N^{-j}] + conj(H[\omega_N^{N - j}]) / 2
G[\omega_N^{-j}] = (H[\omega_N^{-j}] - conj(H[\omega_N^{N - j}]) / 2i
が得られる。( j = 0 のとき \omega_N^N が現れることに注意)

## 実数値関数の離散フーリエ変換
実数値関数の畳み込みは実数値であることを用いて、そのフーリエ変換から畳み込みの値を復元する。

N を 2 冪として f[0], f[1], \ldots, f[N - 1] が "実数"
F[z] を f[k] の離散フーリエ変換とし、F[\omega_N^{-j}] (0 \leq j < N) が既知の場合を考える。

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-j}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-kj}

0 \leq i < N/2 として
F[\omega_N^{-i}]         = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} + \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}
F[\omega_N^{-(i + N/2)}] = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} - \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}
であるので f の次数の偶奇で分けた離散フーリエ変換から求めることができる(時間間引き)

h[k] := f[2k] + f[2k + 1] i (i は虚数単位) (0 \leq k < N/2)
H[z] := \Sum_{k = 0}^{N - 1} h[k] z^k = F[2z] + F[2z + 1] i

連立させて H[\omega_N^{-i}] を F[\omega_N^{-2i}], F[\omega_N^{-(2i + 1)}] から計算し離散逆フーリエ変換を行う。
f[2k], f[2k + 1] は実数なので h[k] の実部と虚部から f[0], f[1], \ldots, f[N - 1] が求まる。

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

# 参考
https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79, 2020/05/01
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/08/01
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
		const size_type m = n >> 1;
		const std::vector<complex_type> zeta = _zeta(ni);
		
		std::vector<complex_type> a;
		a.resize(n);
		for (size_type i = 0; i < A.size(); ++i) a[i].real(A[i]);
		for (size_type i = 0; i < B.size(); ++i) a[i].imag(B[i]);
		fft_frequency(a, zeta);
		
		std::vector<complex_type> c;
		c.reserve(m + 1);
		c.emplace_back(a[0].real() * a[0].imag(), 0);
		for (size_type i = 1; i != m; ++i) {
			const complex_type a_conj = std::conj(a[n - i]);
			const complex_type prod = (a[i] + a_conj) * (a[i] - a_conj) / 4.0;
			c.emplace_back(prod.imag(), -prod.real());
		}
		c.emplace_back(a[m].real() * a[m].imag(), 0);
		
		a.resize(m);
		for (size_type i = 0; i < m; ++i) {
			const complex_type c_conj = std::conj(c[m - i]);
			const complex_type e = (c[i] + c_conj) / 2.0;
			const complex_type o = (c[i] - c_conj) * std::conj(zeta[i]) / 2.0;
			a[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());
		}
		fft_frequency(a, zeta);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < m; ++i) {
			res.emplace_back(a[i].real() / static_cast<value_type>(m));
			res.emplace_back(-a[i].imag() / static_cast<value_type>(m));
		}
		return res;
	}
	
private:
	static void fft_frequency(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 1;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		size_type ni = zi;
		while (1 << ni > N) --ni;
		
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/Convolution/FastFourierTransform_Real_CooleyTueky-frequency-radix2.cpp"
#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

実数の畳み込み
基数 2 周波数間引き Cooley-Tukey

# 解説
## 実数値関数の畳み込み
N を 2 冪として
 f[0], f[1], \ldots, f[N - 1], g[0], g[1], \ldots, g[N - 1] が既知で "実数"

\omega_N := 1 の原始 N 乗根

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-j}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-kj}

conj(z) は z の複素共役を表す。

f[j] は実数なので conj(f[j]) = f[j] より、
F[\omega_N^{-(N - j)}] = conj(F[\omega_N^{-j}])

h[k] := f[k] + g[k] i ( i は虚数単位) (0 \leq k < N)

H[\omega_N^{-j}] = F[\omega_N^{-j}] + G[\omega_N^{-j}] i
H[\omega_N^{N - j}] = conj(F[\omega_N^{-j}]) - conj(G[\omega_N^{-j}]) i
を連立させて解くと、

F[\omega_N^{-j}] = (H[\omega_N^{-j}] + conj(H[\omega_N^{N - j}]) / 2
G[\omega_N^{-j}] = (H[\omega_N^{-j}] - conj(H[\omega_N^{N - j}]) / 2i
が得られる。( j = 0 のとき \omega_N^N が現れることに注意)

## 実数値関数の離散フーリエ変換
実数値関数の畳み込みは実数値であることを用いて、そのフーリエ変換から畳み込みの値を復元する。

N を 2 冪として f[0], f[1], \ldots, f[N - 1] が "実数"
F[z] を f[k] の離散フーリエ変換とし、F[\omega_N^{-j}] (0 \leq j < N) が既知の場合を考える。

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-j}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-kj}

0 \leq i < N/2 として
F[\omega_N^{-i}]         = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} + \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}
F[\omega_N^{-(i + N/2)}] = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} - \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}
であるので f の次数の偶奇で分けた離散フーリエ変換から求めることができる(時間間引き)

h[k] := f[2k] + f[2k + 1] i (i は虚数単位) (0 \leq k < N/2)
H[z] := \Sum_{k = 0}^{N - 1} h[k] z^k = F[2z] + F[2z + 1] i

連立させて H[\omega_N^{-i}] を F[\omega_N^{-2i}], F[\omega_N^{-(2i + 1)}] から計算し離散逆フーリエ変換を行う。
f[2k], f[2k + 1] は実数なので h[k] の実部と虚部から f[0], f[1], \ldots, f[N - 1] が求まる。

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

# 参考
https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79, 2020/05/01
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/08/01
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
		const size_type m = n >> 1;
		const std::vector<complex_type> zeta = _zeta(ni);
		
		std::vector<complex_type> a;
		a.resize(n);
		for (size_type i = 0; i < A.size(); ++i) a[i].real(A[i]);
		for (size_type i = 0; i < B.size(); ++i) a[i].imag(B[i]);
		fft_frequency(a, zeta);
		
		std::vector<complex_type> c;
		c.reserve(m + 1);
		c.emplace_back(a[0].real() * a[0].imag(), 0);
		for (size_type i = 1; i != m; ++i) {
			const complex_type a_conj = std::conj(a[n - i]);
			const complex_type prod = (a[i] + a_conj) * (a[i] - a_conj) / 4.0;
			c.emplace_back(prod.imag(), -prod.real());
		}
		c.emplace_back(a[m].real() * a[m].imag(), 0);
		
		a.resize(m);
		for (size_type i = 0; i < m; ++i) {
			const complex_type c_conj = std::conj(c[m - i]);
			const complex_type e = (c[i] + c_conj) / 2.0;
			const complex_type o = (c[i] - c_conj) * std::conj(zeta[i]) / 2.0;
			a[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());
		}
		fft_frequency(a, zeta);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < m; ++i) {
			res.emplace_back(a[i].real() / static_cast<value_type>(m));
			res.emplace_back(-a[i].imag() / static_cast<value_type>(m));
		}
		return res;
	}
	
private:
	static void fft_frequency(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 1;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		size_type ni = zi;
		while (1 << ni > N) --ni;
		
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

