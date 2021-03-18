#ifndef INCLUDE_GUARD_EUCLID_HPP
#define INCLUDE_GUARD_EUCLID_HPP

#include <cassert>
#include <utility>
#include <tuple>
#include <type_traits>
#include <cmath>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp
 */
namespace tk {
template<typename T>
constexpr T gcd(T a, T b) noexcept {
	static_assert(std::is_integral<T>::value);
	assert(a >= 0);
	assert(b >= 0);
	while (b != 0) {
		T t = a % b;
		a = b; b = t;
	}
	return a;
}

template<typename T>
constexpr T lcm(T a, T b) noexcept {
	static_assert(std::is_integral<T>::value);
	assert(a >= 0);
	assert(b >= 0);
	if (a == 0 || b == 0) return 0;
	return a / gcd(a, b) * b;
}

template<typename T>
constexpr std::tuple<T, T, T> ext_gcd(T a, T b) noexcept {
	static_assert(std::is_integral<T>::value);
	assert(a != 0);
	assert(b != 0);
	T a1 = (a > 0) * 2 - 1, a2 = 0, b1 = 0, b2 = (b > 0) * 2 - 1;
	a = std::abs(a);
	b = std::abs(b);
	while (b > 0) {
		const T q = a / b;
		T tmp = a - q * b; a = b; b = tmp;
		tmp = a1 - q * b1; a1 = b1; b1 = tmp;
		tmp = a2 - q * b2; a2 = b2; b2 = tmp;
	}
	return {a, a1, a2};
}
} // namespace tk

#endif // INCLUDE_GUARD_EUCLID_HPP