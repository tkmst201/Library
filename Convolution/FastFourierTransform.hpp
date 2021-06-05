#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP
#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP

#include <vector>
#include <complex>
#include <algorithm>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp
 */
struct FastFourierTransform {
	using value_type = double;
	using complex_type = std::complex<value_type>;
	
private:
	using uint32 = std::uint32_t;
	constexpr static value_type pi = 3.1415926535897932384626433832795028841972;
	constexpr static complex_type ie{0, 1};
	
	uint32 mlog_n;
	std::vector<complex_type> zeta;
	
public:
	explicit FastFourierTransform(uint32 max_n) : mlog_n(calc_l2(max_n)), zeta(zeta_(mlog_n)) {}
	
	template<typename T>
	std::vector<value_type> operator ()(const std::vector<T> & a, const std::vector<T> & b) const {
		if (a.empty() || b.empty()) return {};
		if (a.size() == 1 && b.size() == 1) return {static_cast<value_type>(a.front()) * b.front()};
		assert((a.size() + b.size() - 1) <= (1u << mlog_n));
		return multiply_sub(a, b, zeta, mlog_n);
	}
	
	template<typename T>
	static std::vector<value_type> multiply(const std::vector<T> & a, const std::vector<T> & b) {
		if (a.empty() || b.empty()) return {};
		if (a.size() == 1 && b.size() == 1) return {static_cast<value_type>(a.front()) * b.front()};
		const uint32 log_n = calc_l2(a.size() + b.size() - 1);
		const std::vector<complex_type> zeta = zeta_(log_n);
		return multiply_sub(a, b, zeta, log_n);
	}
	
private:
	template<typename T>
	static std::vector<value_type> multiply_sub(const std::vector<T> & a, const std::vector<T> & b, const std::vector<complex_type> & zeta, uint32 log_z) {
		const uint32 n_ = a.size() + b.size() - 1;
		const uint32 log_n = calc_l2(n_), n = 1u << log_n, m = n >> 1;
		std::vector<complex_type> h(n);
		for (uint32 i = 0; i < a.size(); ++i) h[i].real(a[i]);
		for (uint32 i = 0; i < b.size(); ++i) h[i].imag(b[i]);
		fft(h, log_n, zeta, log_z);
		
		std::vector<complex_type> p(m);
		{
			const value_type cf = h[0].real() * h[0].imag();
			const value_type cb = h[m].real() * h[m].imag();
			p[0] = complex_type(cf + cb, -(cf - cb)) / 2.0;
		}
		for (uint32 i = 1; i <= (m >> 1); ++i) {
			const complex_type cf = -(h[i] + std::conj(h[n - i])) * (h[i] - std::conj(h[n - i])) * ie;
			const complex_type cb = -(h[m - i] + std::conj(h[m + i])) * (h[m - i] - std::conj(h[m + i])) * ie;
			p[i] = std::conj((cf + std::conj(cb) + (cf - std::conj(cb)) * std::conj(zeta_f(log_n, i, zeta, log_z)) * ie)) / 8.0;
			if (i != m / 2) p[m - i] = std::conj((cb + std::conj(cf)) + (cb - std::conj(cf)) * std::conj(zeta_f(log_n, m - i, zeta, log_z)) * ie) / 8.0;
		}
		fft(p, log_n - 1, zeta, log_z);
		
		std::vector<value_type> res;
		res.reserve(n_);
		for (uint32 i = 0; i < m; ++i) {
			if ((i << 1) < n_) res.emplace_back(p[i].real() / static_cast<value_type>(m));
			if ((i << 1 | 1) < n_) res.emplace_back(-p[i].imag() / static_cast<value_type>(m));
		}
		return res;
	}
	
	static void fft(std::vector<complex_type> & a, uint32 log_n, const std::vector<complex_type> & zeta, uint32 log_z) {
		const uint32 n = a.size(), m = n >> 1;
		bit_reverse(a);
		for (uint32 w = 4, c = 2; w <= n; w <<= 2, c += 2) {
			const uint32 s = w >> 2;
			for (uint32 p = 0; p < n; p += w) {
				for (uint32 i = 0; i < s; ++i) {
					const uint32 pos = p + i;
					const complex_type a0 = a[pos], a2 = a[pos + s] * zeta_f(c - 1, i, zeta, log_z);
					const complex_type a1 = a[pos + (s << 1)] * zeta_f(c, i, zeta, log_z), a3 = a[pos + w - s] * zeta_f(c, 3 * i, zeta, log_z);
					const complex_type lp = a0 + a2, rp = a1 + a3, ln = a0 - a2, rn = a1 - a3;
					a[pos] = lp + rp;
					a[pos + (s << 1)] = lp - rp;
					a[pos + s] = ln + rn * ie;
					a[pos + w - s] = ln - rn * ie;
				}
			}
		}
		if (~log_n & 1) return;
		for (uint32 i = 0; i < m; ++i) {
			const complex_type x = a[i], y = a[i + m] * zeta_f(log_n, i, zeta, log_z);
			a[i] = x + y;
			a[i + m] = x - y;
		}
	}
	
	static uint32 calc_l2(uint32 n_) noexcept {
		uint32 log_n = 0;
		for (uint32 n = 1; n < n_; n <<= 1) ++log_n;
		return log_n;
	}
	
	static void bit_reverse(std::vector<complex_type> & a) noexcept {
		const uint32 N = a.size();
		for (uint32 i = 1, j = 0; i < N - 1; ++i) {
			for (uint32 k = N >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(a[i], a[j]);
		}
	}
	
	static std::vector<complex_type> zeta_(uint32 log_n) {
		if (log_n == 0) return {};
		std::vector<complex_type> zeta;
		zeta.reserve(1 << (log_n - 1));
		zeta.emplace_back(1, 0);
		for (uint32 i = 0; i < (log_n - 1); ++i) {
			const complex_type t = std::polar<value_type>(1, 2.0 * pi / static_cast<value_type>(1 << (log_n - i)));
			zeta.emplace_back(t);
			for (uint32 j = 1; j < (1u << i); ++j) zeta.emplace_back(zeta[j] * t);
		}
		return zeta;
	}
	
	static complex_type zeta_f(uint32 d, uint32 p, const std::vector<complex_type> & zeta, uint32 log_z) noexcept {
		const uint32 idx = p << (log_z - d);
		return idx < zeta.size() ? zeta[idx] : -zeta[idx - zeta.size()];
	}
};

#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_HPP