#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP
#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP

#include "Mathematics/mod_pow_inv.hpp"

#include <vector>
#include <utility>
#include <cassert>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp
 */
template<int MOD, int PRIMITIVE_ROOT>
struct NumberTheoreticTransform {
	static_assert(MOD > 0);
	static_assert(PRIMITIVE_ROOT > 0);
	
private:
	using uint32 = std::uint32_t;
	using calc_type = long long;
	
public:
	template<typename T>
	static std::vector<T> multiply(const std::vector<T> & a, const std::vector<T> & b) {
		static_assert(std::is_integral<T>::value);
		if (a.empty() || b.empty()) return {};
		const uint32 n_ = a.size() + b.size() - 1;
		uint32 n = 1;
		while (n < n_) n <<= 1;
		{
			uint32 two_exp = 0;
			int tm = MOD - 1;
			while (tm > 0 && (~tm & 1)) ++two_exp, tm >>= 1;
			assert((1u << two_exp) >= n);
		}
		std::vector<T> c(n, 0);
		for (uint32 i = 0; i < a.size(); ++i) c[i] = a[i] % MOD + (a[i] >= 0 ? 0 : MOD);
		ntt(c);
		std::vector<T> d(n, 0);
		for (uint32 i = 0; i < b.size(); ++i) d[i] = b[i] % MOD + (b[i] >= 0 ? 0 : MOD);
		ntt(d);
		const int ninv = tk::mod_inv<int>(n, MOD);
		for (uint32 i = 0; i < n; ++i) c[i] = static_cast<calc_type>(c[i]) * d[i] % MOD * ninv % MOD;
		d.clear();
		ntt(c, true);
		c.resize(a.size() + b.size() - 1);
		return c;
	}
	
private:
	template<typename T>
	static void ntt(std::vector<T> & a, bool inv = false) {
		const uint32 n = a.size();
		int nroot = tk::mod_pow<calc_type>(PRIMITIVE_ROOT, (MOD - 1) / n, MOD);
		if (inv) nroot = tk::mod_inv(nroot, MOD);
		for (uint32 w = n; w > 1; w >>= 1) {
			const uint32 m = w >> 1;
			std::vector<int> omega(m, 0);
			omega[0] = 1;
			for (uint32 i = 1; i < m; ++i) omega[i] = static_cast<calc_type>(omega[i - 1]) * nroot % MOD;
			const int half = static_cast<calc_type>(omega.back()) * nroot % MOD;
			for (uint32 p = 0; p < n; p += w) {
				for (uint32 i = p; i < p + m; ++i) {
					const calc_type x = a[i], y = a[i + m];
					a[i] = (x + y) % MOD;
					a[i + m] = (x + y * half % MOD) % MOD * omega[i - p] % MOD;
				}
			}
			nroot = static_cast<calc_type>(nroot) * nroot % MOD;
		}
		bit_reverse(a);
	}
	
	template<typename T>
	static void bit_reverse(std::vector<T> & a) noexcept {
		const uint32 n = a.size();
		for (uint32 i = 1, j = 0; i < n - 1; ++i) {
			for (uint32 k = n >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(a[i], a[j]);
		}
	}
};

#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP