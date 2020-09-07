#ifndef INCLUDE_GUARD_MOD_INT_HPP
#define INCLUDE_GUARD_MOD_INT_HPP

#include <cassert>
#include <iostream>

/*
last-updated: 2020/02/26

# 仕様
ModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

ModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
ModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static decltype(M) get_mod() noexcept : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const ModInt & rhs) const noexept
operator -(const ModInt & rhs) const noexept
operator *(const ModInt & rhs) const noexept
operator /(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs)
friend std::istream & operator >>(std::istream & is, ModInt & rhs) :
	入出力用

# 参考
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

template<int M>
struct ModInt {
public:
	using value_type = long long;
	
	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }
	ModInt operator +() const noexcept { return ModInt(*this); }
	ModInt operator -() const noexcept { return ModInt(0) -= *this; }
	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }
	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }
	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }
	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }
	
	ModInt & operator +=(const ModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= M) val -= M;
		return *this;
	}
	ModInt & operator -=(const ModInt & rhs) noexcept {
		if (val < rhs.val) val += M;
		val -= rhs.val;
		return *this;
	}
	ModInt & operator *=(const ModInt & rhs) noexcept {
		val = val * rhs.val % M;
		return *this;
	}
	ModInt & operator /=(const ModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	ModInt pow(value_type n) const {
		ModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	ModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;
			a = b; b = r;
			a1 = b1; b1 = nb1;
			a2 = b2; b2 = nb2;
		}
		assert(a == 1);
		return a1;
	}
	
	const value_type & get() const noexcept { return val; }
	static decltype(M) get_mod() noexcept { return M; }
	
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {
		value_type x;
		is >> x;
		rhs = ModInt(x);
		return is;
	}
private:
	value_type val;
};

#endif // INCLUDE_GUARD_MOD_INT_HPP