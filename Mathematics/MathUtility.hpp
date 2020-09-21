#ifndef INCLUDE_GUARD_MATH_UTILITY_HPP
#define INCLUDE_GUARD_MATH_UTILITY_HPP

/*
last-updated: 2020/09/21

# 仕様
T gcd(T a, T b)
	時間計算量: O(log max{a, b})
	a と b の最大公約数を返す

T lcm(T a, T b)
	時間計算量: O(log max{a, b})
	a と b の最小公倍数を返す

T ext_gcd(const T & a, T & x, const T & b, T & y)
	時間計算量: O(log b)
	一次不定方程式 ax + by = gcd(x, y) の解 (x, y) を求める
	gcd(x, y) を返す

T mod_pow(T x, T n, const T & mod)
	時間計算量: Θ(log n)
	a^n (modulo. mod) を返す
	計算過程で O(mod^2) 程度まで値が大きくなるので注意

T mod_inv(T x, const T & mod)
	時間計算量: O(log max{x, mod})
	modulo. mod 上の x の逆元を返す
	gcd(x, mod) = 1 である必要がある(逆元が存在するための必要十分条件)

# 参考
https://noshi91.hatenablog.com/entry/2019/04/01/184957, 2020/01/14
*/

#include <cassert>

namespace tk {
template<typename T>
T gcd(T a, T b) {
	while (b != 0) {
		T t = a % b;
		a = b; b = t;
	}
	return a;
}

template<typename T>
T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

template<typename T>
T ext_gcd(const T & a, T & x, const T & b, T & y) {
	T a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;
	while (b0 > 0) {
		T q = a0 / b0, r = a0 % b0;
		T nb1 = a1 - q * b1, nb2 = a2 - q * b2;
		a0 = b0; b0 = r;
		a1 = b1; b1 = nb1;
		a2 = b2; b2 = nb2;
	}
	x = a1;
	y = a2;
	return a0;
}

template<typename T>
T mod_pow(T x, T n, const T & mod) {
	T res = 1 % mod;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

template<typename T>
T mod_inv(T x, const T & mod) {
	T a, b;
	T g = ext_gcd(x, a, mod, b);
	assert(g == 1);
	return (a % mod + mod) % mod;
}
}

#endif // INCLUDE_GUARD_MATH_UTILITY_HPP