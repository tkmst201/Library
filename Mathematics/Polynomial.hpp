#ifndef INCLUDE_GUARD_POLYNOMINAL_HPP
#define INCLUDE_GUARD_POLYNOMINAL_HPP

#include <vector>

// poly / (x - d) を返す
template<typename T>
std::vector<T> div_by_linear(const std::vector<T> & poly, T d) {
	assert(poly.size() >= 2);
	using size_t = std::size_t;
	std::vector<T> res(poly.size() - 1);
	T r = 0;
	for (size_t i = poly.size() - 1; i > 0; --i) {
		res[i - 1] = r + poly[i];
		r = res[i - 1] * d;
	}
	r += poly[0];
	assert(r == 0);
	return res;
}

#endif // INCLUDE_POLYNOMINAL_HPP