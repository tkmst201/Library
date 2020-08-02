#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/08/02

実数の畳み込み
基数 4 周波数間引き Cooley-Tukey

定数倍で基数 2 時間間引き Cookey-Tukey と差が無い

# 仕様
template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

# 参考
基数 4 の時間間引き FFT
実数の畳み込み
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
		
		size_type zi = 0;
		for (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);
		
		bit_reverse(A);
		for (size_type n = 4; n <= N; n <<= 2) {
			zi -= 2;
			size_type m = n >> 2;
			// \omega_n^k = zeta[k << zi]
			size_type p;
			for (p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i != ei; ++i) {
					complex_type a0 = A[i], a2 = A[i + m] * zeta[(i - p) << (zi + 1)];
					complex_type a1 = A[i + (m << 1)] * zeta[(i - p) << zi], a3 = A[i + n - m] * zeta[3 * (i - p) << zi];
					
					complex_type lp = a0 + a2, ln = a0 - a2;
					complex_type rp = a1 + a3, rn = a1 - a3;
					A[i] = lp + rp;
					A[i + m] = complex_type(ln.real() + rn.imag(), ln.imag() - rn.real());
					A[i + (m << 1)] = lp - rp;
					A[i + n - m] = complex_type(ln.real() - rn.imag(), ln.imag() + rn.real());
				}
			}
			if (p > N) {
				p -= n;
				m = n >> 1;
				for (size_type i = p; i != N; ++i) {
					const complex_type a = A[i], b = A[i + m] * zeta[(i - p) << (zi - 1)];
					A[i] = a + b;
					A[i + m] = a - b;
				}
			}
		}
		
		if (zi > 0) {
			--zi;
			for (size_type i = 0, m = N >> 1; i != m; ++i) {
				const complex_type a = A[i], b = A[i + m] * zeta[i << zi];
				A[i] = a + b;
				A[i + m] = a - b;
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
		// zeta[j] := \omega_{2^max_p}^j
		std::vector<complex_type> zeta;
		zeta.reserve(1 << max_p);
		zeta.emplace_back(1, 0);
		for (size_type i = 0; i < max_p; ++i) {
			const value_type rad = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);
			zeta.emplace_back(std::polar<value_type>(1, rad));
			for (size_type j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {
				zeta.emplace_back(zeta[1 << i ^ j] * zeta[1 << i]);
			}
		}
		return zeta;
	}
};
