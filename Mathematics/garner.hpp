#ifndef INCLUDE_GUARD_GARNER_HPP
#define INCLUDE_GUARD_GARNER_HPP

#include <vector>
#include <cassert>
#include <type_traits>

#include "Mathematics/euclid.hpp"
#include "Mathematics/mod_pow_inv.hpp"

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/garner.hpp
 */
namespace tk {
template<typename T>
bool pre_garner(std::vector<T> & b, std::vector<T> & m) noexcept {
	static_assert(std::is_integral<T>::value);
	static_assert(std::is_signed<T>::value);
	for (int i = 0; i < static_cast<int>(b.size()); ++i) {
		b[i] = b[i] % m[i] + (b[i] >= 0 ? 0 : m[i]);
		for (int j = 0; j < i; ++j) {
			T g = gcd(m[i], m[j]);
			if ((b[i] - b[j]) % g != 0) return false;
			m[i] /= g; m[j] /= g;
			T gi = gcd(g, m[i]), gj = g / gi;
			do {
				g = gcd(gi, gj);
				gi *= g; gj /= g;
			} while (g != 1);
			m[i] *= gi; m[j] *= gj;
			b[i] %= m[i]; b[j] %= m[j];
		}
	}
	return true;
}

template<typename T, typename U>
T garner(const std::vector<T> & b, const std::vector<T> & m, const T M) {
	static_assert(std::is_integral<T>::value);
	assert(b.size() == m.size());
	const int n = b.size();
	assert(n > 0);
	{
		T g = 0;
		for (auto v : m) {
			assert(v > 0);
			g = gcd(g, v);
		}
		assert(n == 1 || g == 1);
	}
	assert(M > 0);
	std::vector<T> sum(n + 1, 0), ip(n + 1, 1);
	for (int i = 0; i < n; ++i) {
		if (m[i] == 1) continue;
		U t = (b[i] % m[i] + static_cast<U>(2) * m[i] - sum[i]) % m[i] * mod_inv(ip[i], m[i]) % m[i];
		for (int j = i + 1; j < n; ++j) {
			sum[j] = (sum[j] + ip[j] * t) % m[j];
			ip[j] = static_cast<U>(ip[j]) * m[i] % m[j];
		}
		sum[n] = (sum[n] + ip[n] * t % M) % M;
		ip[n] = static_cast<U>(ip[n]) * m[i] % M; 
	}
	return sum.back();
}
} // namespace tk

#endif // INCLUDE_GUARD_GARNER_HPP