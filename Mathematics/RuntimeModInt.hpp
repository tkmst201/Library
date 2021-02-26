#ifndef INCLUDE_GUARD_RUNTIME_MOD_INT_HPP
#define INCLUDE_GUARD_RUNTIME_MOD_INT_HPP


#include <cassert>
#include <iostream>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/RuntimeModInt.hpp
 */
template<int ID>
struct RuntimeModInt {
	using value_type = int;
	using calc_type = std::int_fast64_t;
	
private:
	value_type val_;
	static int & mod_() noexcept { static int M = 2; return M; }
	
public:
	RuntimeModInt(calc_type val = 0) : val_(val < 0 ? (val % mod() + mod()) % mod() : val % mod()) {}
	const value_type val() const noexcept { return val_; }
	static void set_mod(int M) noexcept { assert(M > 0); mod_() = M; }
	static int mod() noexcept { return mod_(); }
	
	explicit operator bool() const noexcept { return val_; }
	bool operator !() const noexcept { return !static_cast<bool>(*this); }
	RuntimeModInt operator +() const noexcept { return *this; }
	RuntimeModInt operator -() const noexcept { return RuntimeModInt(-val_); }
	RuntimeModInt operator ++(int) noexcept { RuntimeModInt res = *this; ++*this; return res; }
	RuntimeModInt operator --(int) noexcept { RuntimeModInt res = *this; --*this; return res; }
	RuntimeModInt & operator ++() noexcept { val_ = val_ + 1 == mod() ? 0 : val_ + 1; return *this; }
	RuntimeModInt & operator --() noexcept { val_ = val_ == 0 ? mod() - 1 : val_ - 1; return *this; }
	RuntimeModInt & operator +=(const RuntimeModInt & rhs) noexcept { val_ += val_ < mod() - rhs.val_ ? rhs.val_ : rhs.val_ - mod(); return *this; }
	RuntimeModInt & operator -=(const RuntimeModInt & rhs) noexcept { val_ += val_ >= rhs.val_ ? -rhs.val_ : mod() - rhs.val_; return *this; }
	RuntimeModInt & operator *=(const RuntimeModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_ % mod(); return *this; }
	RuntimeModInt & operator /=(const RuntimeModInt & rhs) noexcept { return *this *= rhs.inv(); }
	friend RuntimeModInt operator +(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) += rhs; }
	friend RuntimeModInt operator -(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) -= rhs; }
	friend RuntimeModInt operator *(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) *= rhs; }
	friend RuntimeModInt operator /(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return RuntimeModInt(lhs) /= rhs; }
	friend bool operator ==(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return lhs.val_ == rhs.val_; }
	friend bool operator !=(const RuntimeModInt & lhs, const RuntimeModInt & rhs) noexcept { return !(lhs == rhs); }
	friend std::ostream & operator <<(std::ostream & os, const RuntimeModInt & rhs) { return os << rhs.val_; }
	friend std::istream & operator >>(std::istream & is, RuntimeModInt & rhs) { calc_type x; is >> x; rhs = RuntimeModInt(x); return is; }
	
	RuntimeModInt pow(calc_type n) const noexcept {
		RuntimeModInt res = 1, x = val_;
		if (n < 0) { x = x.inv(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	RuntimeModInt inv() const noexcept {
		value_type a = val_, a1 = 1, b = mod(), b1 = 0;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1;
			a = b; b = r;
			a1 = b1; b1 = nb1;
		}
		assert(a == 1);
		return a1;
	}
};

#endif // INCLUDE_GUARD_RUNTIME_MOD_INT_HPP