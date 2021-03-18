#ifndef INCLUDE_GUARD_CHINESE_REMAINDER_HPP
#define INCLUDE_GUARD_CHINESE_REMAINDER_HPP

#include "Mathematics/euclid.hpp"

#include <cassert>
#include <utility>
#include <type_traits>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp
 */
namespace tk {
template<typename T>
constexpr std::pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2) noexcept {
	static_assert(std::is_integral<T>::value);
	assert(m1 > 0);
	assert(m2 > 0);
	if (m1 < m2) { std::swap(b1, b2); std::swap(m1, m2); }
	b1 = (b1 % m1 + m1) % m1;
	b2 = (b2 % m2 + m2) % m2;
	auto [g, x, _] = ext_gcd(m1, m2);
	if ((b2 - b1) % g != 0) return {0, 0};
	const T pm2 = m2 / g;
	if (x < 0) x += pm2;
	const T t = ((b2 - b1) / g % pm2 + pm2) % pm2 * x % pm2;
	return {b1 + t * m1, m1 * pm2};
}
} // namespace tk

#endif // INCLUDE_GUARD_CHINESE_REMAINDER_HPP