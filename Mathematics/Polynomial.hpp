#ifndef INCLUDE_GUARD_POLYNOMINAL_HPP
#define INCLUDE_GUARD_POLYNOMINAL_HPP

/*
last-updated: 2020/11/02

# 仕様
poly[i] := x^i の係数
poly の最高次数を n とする。

std::vector<T> linear_prod(const std::vector<T> & poly, T d)
	時間計算量: Θ(n)
	多項式 poly * (x - d) を返す

std::vector<T> linear_div(const std::vector<T> & poly, T d)
	時間計算量: Θ(n)
	多項式 poly / (x - d) を返す
	必ず poly の因数に (x - d) が含まれている必要がある

# verify
HHKB プログラミングコンテスト 2020『F - Random Max』https://atcoder.jp/contests/hhkb2020/submissions/17832420
*/

#include <vector>

namespace tk {
template<typename T>
std::vector<T> linear_prod(const std::vector<T> & poly, T d) {
	assert(!poly.empty());
	using size_type = std::size_t;
	std::vector<T> res;
	res.reserve(poly.size() + 1);
	res.emplace_back(poly[0] * (static_cast<mint>(0) - d));
	for (size_type i = 1; i < poly.size(); ++i)
		res.emplace_back(poly[i - 1] + poly[i] * (static_cast<mint>(0) - d));
	res.emplace_back(poly.back());
	return res;
}

template<typename T>
std::vector<T> linear_div(const std::vector<T> & poly, T d) {
	assert(poly.size() >= 2);
	using size_type = std::size_t;
	std::vector<T> res(poly.size() - 1);
	T r = 0;
	for (size_type i = poly.size() - 1; i > 0; --i) {
		res[i - 1] = r + poly[i];
		r = res[i - 1] * d;
	}
	r += poly[0];
	assert(r == 0);
	return res;
}
} // namespace tk


#endif // INCLUDE_POLYNOMINAL_HPP