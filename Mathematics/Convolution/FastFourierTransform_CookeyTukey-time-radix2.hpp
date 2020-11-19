#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_TIME_RADIX2_HPP
#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_TIME_RADIX2_HPP

/*
last-updated: 2020/11/19

基数 2 時間間引き Cooley-Tukey

# 解説
N を 2 冪として f[0], f[1], \ldots, f[N - 1] が既知

\omega_N := 1 の原始 N 乗根

F[z] := \Sum_{k = 0}^{N - 1} f[k] z^k
F[\omega_N^{-i}] = \Sum_{k = 0}^{N - 1} f[k] \omega_N^{-ki}
で偶数次数、奇数次数で多項式を分ける

0 \leq i < N/2 として
F[\omega_N^{-i}]         = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} + \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}
F[\omega_N^{-(i + N/2)}] = \Sum_{k = 0}^{N/2 - 1} f[2k] \omega_{N/2}^{-ki} - \Sum_{k = 0}^{N/2 - 1} f[2k + 1] \omega_{N/2}^{-ki}

ビット反転を行った状態から N が小さい順に計算を行えば in-place で計算可能


# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B)
	時間計算量: Θ(N log N) (N := |A| + |B| - 1 以上の最小の 2 冪)
	2 つの多項式の乗算を行う。
	制約:
		T: int | double
		戻り値は double 型の配列(サイズ |A| + |B| - 1)

# 参考
https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79, 2020/05/01
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/08/01
*/

#include <vector>
#include <complex>
#include <algorithm>

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
		res.resize(A.size() + B.size() - 1);
		return res;
	}
	
private:
	static void fft(std::vector<complex_type> &A, const std::vector<complex_type> &zeta) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		size_type zi = 0;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		
		bit_reverse(A);
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

#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_TIME_RADIX2_HPP