/*
last-updated: 2020/01/14

# 仕様
(boost の gcd が動いて遅くなるかも)
T gcd(const T & a, const T & b) :
	時間計算量: O(log b)
	a と b の greatest common divisor を求める

T lcm(const T & a, const T &b) :
	時間計算量: O(log b)
	a と b の least common multiple を求める

T extgcd(const T & a, const T & b, T &x, T &y) :
	時間計算量: O(log b)
	一次不定方程式 ax + by = gcd(x, y) の解 (x, y) を求める

# 参考
https://noshi91.hatenablog.com/entry/2019/04/01/184957, 2020/01/14
*/

template<typename T>
T gcd(const T & a, const T &b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

template<typename T>
T lcm(const T & a, const T & b) {
	return a / gcd(a, b) * b;
}

template<typename T>
T extgcd(const T & a, const T & b, T &x, T &y) {
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