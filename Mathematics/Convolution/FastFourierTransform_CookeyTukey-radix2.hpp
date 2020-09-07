#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HPP
#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HPP

#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

基数 2 Cooley-Tukey

# 解説
周波数間引きで FFT を行ったあとはビット反転した位置になっている。
そのまま時間間引きで FFT を行うことでビット反転の処理が不要になる。

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。
	
# 参考
周波数間引き FFT と 時間間引き FFT それぞれ参照
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
		a.resize(n); fft_frequency(a, zeta);
		b.resize(n); fft_frequency(b, zeta);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));
		fft_time(c, zeta);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));
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
	}
	
	static void fft_time(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 0;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		
		for (size_type n = 2; n <= N; n <<= 1, --zi) {
			const size_type m = n >> 1;
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					const complex_type a = A[i], b = A[i + m] * zeta[(i - p) << zi];
					A[i] = a + b;
					A[i + m] = a - b;
				}
			}
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

#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HP