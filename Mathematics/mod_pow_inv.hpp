#ifndef INCLUDE_GUARD_MOD_POW_INV_HPP
#define INCLUDE_GUARD_MOD_POW_INV_HPP

#include <cassert>
#include <type_traits>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/mod_pow_inv.hpp
 */
namespace tk {
template<typename T>
constexpr T mod_pow(T x, T n, T m) noexcept {
	static_assert(std::is_integral<T>::value);
	assert(m > 0);
	assert(n >= 0);
	x = x % m + (x >= 0 ? 0 : m);
	T res = 1 % m;
	while (n > 0) {
		if (n & 1) res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

template<typename T>
constexpr T mod_inv(T x, T m) noexcept {
	static_assert(std::is_integral<T>::value);
	static_assert(std::is_signed<T>::value);
	assert(m > 0);
	x = x % m + (x >= 0 ? 0 : m);
	T x1 = 1, y = m, y1 = 0;
	while (y > 0) {
		const T q = x / y;
		T tmp = x - q * y; x = y; y = tmp;
		tmp = x1 - q * y1; x1 = y1; y1 = tmp;
	}
	assert(x == 1);
	if (x1 == m) x1 = 0;
	if (x1 < 0) x1 += m;
	return x1;
}
} // namespace tk

#endif // INCLUDE_GUARD_MOD_POW_INV_HPP