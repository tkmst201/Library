#ifndef INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP
#define INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP

#include <utility>
#include <cassert>
#include <type_traits>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp
 */
namespace tk {
template<typename T>
T sum_of_floor_of_linear(T n, T m, T a, T b) {
	static_assert(std::is_integral<T>::value);
	assert(n >= 0);
	assert(m > 0);
	assert(a >= 0);
	assert(b >= 0);
	if (n == 0) return 0;
	const T qa = a / m, qb = b / m;
	T res = n * (n - 1) / 2 * qa + n * qb;
	a -= qa * m;
	b -= qb * m;
	if (a == 0) return res;
	const T q = (a * n + b) / m, r = (a * n + b) - q * m;
	return res + sum_of_floor_of_linear(q, a, m, r);
}
} // namespace tk

#endif // INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP