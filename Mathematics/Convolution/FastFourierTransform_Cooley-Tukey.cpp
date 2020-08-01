#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/01

基数 2 Cooley-Tuley

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
		size_type n = 1;
		while (n < n_) n <<= 1;
		std::vector<complex_type> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i], 0);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);
		a.resize(n); fft_frequency(a);
		b.resize(n); fft_frequency(b);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));
		fft_time(c);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));
		return res;
	}
	
private:
	static void fft_frequency(std::vector<complex_type> &A) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		for (size_type n = N; n > 1; n >>= 1) {
			const size_type m = n >> 1;
			std::vector<complex_type> zeta;
			zeta.reserve(m);
			zeta.emplace_back(1);
			const complex_type zeta0 = std::polar<value_type>(1, static_cast<value_type>(-2) * PI / static_cast<value_type>(n));
			for (size_type i = 1; i < m; ++i) zeta.emplace_back(zeta.back() * zeta0);
			
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					const complex_type a = A[i], b = A[i + m];
					A[i] = a + b;
					A[i + m] = (a - b) * zeta[i - p];
				}
			}
		}
	}
	
	static void fft_time(std::vector<complex_type> &A) {
		const size_type N = A.size();
		const value_type PI = std::acos(static_cast<value_type>(-1));
		
		for (size_type n = 2; n <= N; n <<= 1) {
			const size_type m = n >> 1;
			std::vector<complex_type> zeta;
			zeta.reserve(m);
			zeta.emplace_back(1);
			const complex_type zeta0 = std::polar<value_type>(1, static_cast<value_type>(-2) * PI / static_cast<value_type>(n));
			for (size_type i = 1; i < m; ++i) zeta.emplace_back(zeta.back() * zeta0);
			
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					const complex_type a = A[i], b = A[i + m] * zeta[i - p];
					A[i] = a + b;
					A[i + m] = a - b;
				}
			}
		}
	}
};