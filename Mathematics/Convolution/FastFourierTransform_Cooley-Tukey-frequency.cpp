#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/05/02

基数 2 周波数間引き Cooley-Tuley のアルゴリズム (非再帰)

template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

参考 :
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
		size_type n = 1;
		while (n < n_) n <<= 1;
		std::vector<complex_type> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i], 0);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);
		a.resize(n); fft(a);
		b.resize(n); fft(b);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));
		fft(c);
		
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));
		return res;
	}
	
private:
	static void fft(std::vector<complex_type> &A) {
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
				for (size_type i = p, ei = p + m; i < ei; ++i) {
					const complex_type a = A[i], b = A[i + m];
					A[i] = a + b;
					A[i + m] = (a - b) * zeta[i - p];
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
};