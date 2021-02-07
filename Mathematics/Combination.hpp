#ifndef INCLUDE_GUARD_COMBINATION_HPP
#define INCLUDE_GUARD_COMBINATION_HPP

#include <vector>
#include <cassert>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/Combination.hpp
 */
template<typename T>
struct Combination {
	using size_type = std::size_t;
	
private:
	std::vector<T> fact_, finv_, inv_;
	static constexpr size_type MAX_LIMIT = 50000000;
	
public:
	Combination(size_type sz = 1) : fact_(1, 1), finv_(1, 1), inv_(1, 1) { build(sz); }
	
	T fact(size_type k) { if (k >= T::mod()) return 0; build(k); return fact_[k]; }
	T finv(size_type k) { assert(k < T::mod()); build(k); return finv_[k]; }
	T inv(size_type k) { assert(k > 0 && k < T::mod()); build(k); return inv_[k]; }
	T operator ()(int n, int r) { return c(n, r); }
	T c(int n, int r) {
		if (r < 0 || n < r) return 0;
		return fact(n) * finv(r) * finv(n - r);
	}
	
private:
	void build(size_type k) {
		if (fact_.size() > k) return;
		assert(k < MAX_LIMIT);
		size_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::mod()), std::max(fact_.size() * 2, k + 1)});
		size_type presz = fact_.size();
		fact_.resize(sz);
		finv_.resize(sz);
		inv_.resize(sz);
		for (size_type i = presz; i < sz; ++i) fact_[i] = fact_[i - 1] * i;
		finv_[sz - 1] = fact_[sz - 1].inv();
		for (size_type i = sz - 1; i > presz; --i) {
			finv_[i - 1] = finv_[i] * i;
			inv_[i] = fact_[i - 1] * finv_[i];
		}
		inv_[presz] = fact_[presz - 1] * finv_[presz];
	}
};

#endif // INCLUDE_GUARD_COMBINATION_HPP