#ifndef INCLUDE_GUARD_MOD_INT_HPP
#define INCLUDE_GUARD_MOD_INT_HPP

#include <cassert>
#include <iostream>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp
 */
template<int M>
struct ModInt {
	static_assert(M > 0);
	
	using value_type = int;
	using calc_type = std::int_fast64_t;
	
private:
	value_type val_;
	
public:
	constexpr ModInt(calc_type val = 0) : val_(val < 0 ? (val % M + M) % M : val % M) {}
	constexpr value_type val() const noexcept { return val_; }
	constexpr static decltype(M) mod() noexcept { return M; }
	
	explicit constexpr operator bool() const noexcept { return val_; }
	constexpr bool operator !() const noexcept { return !static_cast<bool>(*this); }
	constexpr ModInt operator +() const noexcept { return ModInt(*this); }
	constexpr ModInt operator -() const noexcept { return ModInt(-val_); }
	constexpr ModInt operator ++(int) noexcept { ModInt res = *this; ++*this; return res; }
	constexpr ModInt operator --(int) noexcept { ModInt res = *this; --*this; return res; }
	constexpr ModInt & operator ++() noexcept { val_ = val_ + 1 == M ? 0 : val_ + 1; return *this; }
	constexpr ModInt & operator --() noexcept { val_ = val_ == 0 ? M - 1 : val_ - 1; return *this; }
	constexpr ModInt & operator +=(const ModInt & rhs) noexcept { val_ += val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ - M; return *this; }
	constexpr ModInt & operator -=(const ModInt & rhs) noexcept { val_ += val_ >= rhs.val_ ? -rhs.val_ : M - rhs.val_; return *this; }
	constexpr ModInt & operator *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_ % M; return *this; }
	constexpr ModInt & operator /=(const ModInt & rhs) noexcept { return *this *= rhs.inv(); }
	friend constexpr ModInt operator +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) += rhs; }
	friend constexpr ModInt operator -(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) -= rhs; }
	friend constexpr ModInt operator *(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) *= rhs; }
	friend constexpr ModInt operator /(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) /= rhs; }
	friend constexpr bool operator ==(const ModInt & lhs, const ModInt & rhs) noexcept { return lhs.val_ == rhs.val_; }
	friend constexpr bool operator !=(const ModInt & lhs, const ModInt & rhs) noexcept { return !(lhs == rhs); }
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val_; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) { calc_type x; is >> x; rhs = ModInt(x); return is; }
	
	constexpr ModInt pow(calc_type n) const noexcept {
		ModInt res = 1, x = val_;
		if (n < 0) { x = x.inv(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	constexpr ModInt inv() const noexcept {
		value_type a = val_, a1 = 1, b = M, b1 = 0;
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

#endif // INCLUDE_GUARD_MOD_INT_HPP