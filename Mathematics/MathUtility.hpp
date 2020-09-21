#ifndef INCLUDE_GUARD_MATH_UTILITY_HPP
#define INCLUDE_GUARD_MATH_UTILITY_HPP

/*
last-updated: 2020/09/21

# 仕様
T gcd(T a, T b)
	時間計算量: O(log max{a, b})
	非負整数 a と b の最大公約数を返す
	一方の値が 0 のときはもう一方の値を返す

T lcm(T a, T b)
	時間計算量: O(log max{a, b})
	非負整数 a と b の最小公倍数を返す
	a = 0 または b = 0 のときは 0 を返す

T ext_gcd(const T & a, T & x, const T & b, T & y)
	時間計算量: O(log b)
	a > 0 かつ b > 0
	一次不定方程式 ax + by = gcd(x, y) の解 (x, y) を求める
	gcd(a, b) を返す

T mod_pow(T x, T n, const T & mod)
	時間計算量: Θ(log n)
	a^n (modulo. mod) を返す
	計算過程で O(mod^2) 程度まで値が大きくなるので注意

T mod_inv(const T & x, const T & mod)
	時間計算量: O(log max{x, mod})
	modulo. mod 上の x の逆元を返す
	gcd(x, mod) = 1 である必要がある(逆元が存在するための必要十分条件)

std::pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2)
	時間計算量: O(log max{m1, m2})
	次の条件を満たす最小の非負整数 x を求める(0 \leq x < lcm(m1, m2))
		x \equiv b1 (mod. m1)
		x \equiv b2 (mod. m2)
	戻り値: { x, lcm(m1, m2) }
	上の条件を満たす x は周期 lcm(m1, m2)
	x が存在しない場合は {0, 0} を返す

# 参考
AC Library, 2020/09/21
https://noshi91.hatenablog.com/entry/2019/04/01/184957, 2020/01/14
*/

#include <cassert>
#include <utility>

namespace tk {
template<typename T>
T gcd(T a, T b) {
	assert(a >= 0);
	assert(b >= 0);
	while (b != 0) {
		T t = a % b;
		a = b; b = t;
	}
	return a;
}

template<typename T>
T lcm(T a, T b) {
	assert(a >= 0);
	assert(b >= 0);
	if (a == 0 || b == 0) return 0;
	return a / gcd(a, b) * b;
}

template<typename T>
T ext_gcd(const T & a, T & x, const T & b, T & y) {
	assert(a > 0);
	assert(b > 0);
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
	assert(mod > 0);
	assert(n >= 0);
	x = (x % mod + mod) % mod;
	T res = 1 % mod;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

template<typename T>
T mod_inv(const T & x, const T & mod) {
	assert(x > 0);
	assert(mod > 0);
	T a, b;
	T g = ext_gcd(x, a, mod, b);
	assert(g == 1);
	return (a % mod + mod) % mod;
}

template<typename T>
std::pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2) {
	assert(m1 > 0);
	assert(m2 > 0);
	if (m1 < m2) { std::swap(b1, b2); std::swap(m1, m2); }
	b1 = (b1 % m1 + m1) % m1;
	b2 = (b2 % m2 + m2) % m2;
	
	T x, y;
	T g = ext_gcd(m1, x, m2, y);
	const T pm2 = m2 / g;
	x = (x % pm2 + pm2) % pm2;
	
	if ((b2 - b1) % g != 0) return {0, 0};
	const T t = ((b2 - b1) / g % pm2 + pm2) % pm2 * x % pm2;
	return {b1 + t * m1, m1 * pm2};
}
} // namespace tk

#endif // INCLUDE_GUARD_MATH_UTILITY_HPP