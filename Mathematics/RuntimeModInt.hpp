#ifndef INCLUDE_GUARD_RUNTIME_MOD_INT_HPP
#define INCLUDE_GUARD_RUNTIME_MOD_INT_HPP

#include <cassert>
#include <iostream>

/*
last-updated: 2020/02/26

# 仕様
RuntimeModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

RuntimeModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
RuntimeModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static void set_mod(int M) noexcept { mod() = M; } : 法 M をセットする
static int get_mod() noexcept { return mod(); } : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const RuntimeModInt & rhs) const noexept
operator -(const RuntimeModInt & rhs) const noexept
operator *(const RuntimeModInt & rhs) const noexept
operator /(const RuntimeModInt & rhs) const noexept
RuntimeModInt & operator +=(const RuntimeModInt & rhs) const noexept
RuntimeModInt & operator +=(const RuntimeModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const RuntimeModInt & rhs)
friend std::istream & operator >>(std::istream & is, RuntimeModInt & rhs) :
	入出力用

# 参考
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

struct RuntimeModInt {
public:
	using value_type = long long;
	
	RuntimeModInt(value_type val = 0) : val(val < 0 ? (mod() - (-val % mod())) % mod() : val % mod()) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const RuntimeModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const RuntimeModInt & rhs) const noexcept { return !(*this == rhs); }
	RuntimeModInt operator +() const noexcept { return RuntimeModInt(*this); }
	RuntimeModInt operator -() const noexcept { return RuntimeModInt(0) -= *this; }
	RuntimeModInt operator +(const RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) += rhs; }
	RuntimeModInt operator -(const RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) -= rhs; }
	RuntimeModInt operator *(const RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) *= rhs; }
	RuntimeModInt operator /(const RuntimeModInt & rhs) const noexcept { return RuntimeModInt(*this) /= rhs; }
	
	RuntimeModInt & operator +=(const RuntimeModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= mod()) val -= mod();
		return *this;
	}
	RuntimeModInt & operator -=(const RuntimeModInt & rhs) noexcept {
		if (val < rhs.val) val += mod();
		val -= rhs.val;
		return *this;
	}
	RuntimeModInt & operator *=(const RuntimeModInt & rhs) noexcept {
		val = val * rhs.val % mod();
		return *this;
	}
	RuntimeModInt & operator /=(const RuntimeModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	RuntimeModInt pow(value_type n) const {
		RuntimeModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	RuntimeModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = mod(), b1 = 0, b2 = 1;
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
	static void set_mod(int M) noexcept { mod() = M; }
	static int get_mod() noexcept { return mod(); }
	
	friend std::ostream & operator <<(std::ostream & os, const RuntimeModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, RuntimeModInt & rhs) {
		value_type x;
		is >> x;
		rhs = RuntimeModInt(x);
		return is;
	}
private:
	value_type val;
	
	static int & mod() {
		static int M = 2;
		return M;
	}
};

#endif // INCLUDE_GUARD_RUNTIME_MOD_INT_HPP