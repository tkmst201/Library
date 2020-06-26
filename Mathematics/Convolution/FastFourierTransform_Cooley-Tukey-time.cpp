#include <vector>
#include <complex>
#include <algorithm>

/*
last-updated: 2020/05/01

偶数次数、奇数次数を係数に持つ多項式をそれぞれ離散フーリエ変換してマージする方法
基数 2 時間引き Cooley-Tuley のアルゴリズム(recurive) ?(あまり分かっていない)
詳しくは参考 URL
recursive & out-of-place で遅め

template<typename T>
static std::vector<value_type> multiply(const std::vector<T> &A, const std::vector<T> &B) :
	θ(n log n)
	2 つの多項式の乗算を行う。

参考 :
https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79, 2020/05/01
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
		a.resize(n); dft(a, 1);
		b.resize(n); dft(b, 1);
		
		std::vector<complex_type> c;
		c.reserve(n);
		for (size_type i = 0; i < n; ++i) c.emplace_back(a[i] * b[i]);
		dft(c, -1);
		std::vector<value_type> res;
		res.reserve(n);
		for (size_type i = 0; i < n; ++i) res.emplace_back(c[i].real() / static_cast<value_type>(n));
		return res;
	}
	
private:
	static void dft(std::vector<complex_type> &A, int inverse) {
		size_type n = A.size();
		if (n == 1) return;
		std::vector<complex_type> a, b;
		a.reserve(n / 2);
		b.reserve(n / 2);
		for(size_type i = 0; i < n / 2; ++i) {
			a.emplace_back(A[i * 2]);
			b.emplace_back(A[i * 2 + 1]);
		}
		
		dft(a, inverse);
		dft(b, inverse);
		
		complex_type zeta = 1, base = std::polar<value_type>(1, static_cast<value_type>(inverse * 2) * acos(static_cast<value_type>(-1)) / static_cast<value_type>(n));
		for (size_type i = 0; i < n; ++i) {
			A[i] = a[i % (n / 2)] + zeta * b[i % (n / 2)];
			zeta *= base;
		}
	}
};