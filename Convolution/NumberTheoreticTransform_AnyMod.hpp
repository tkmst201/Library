#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP
#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP

#include "Convolution/NumberTheoreticTransform.hpp"
#include "Mathematics/garner.hpp"

#include <vector>
#include <cstdint>
#include <vector>
#include <type_traits>

/**
 * @brief https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform_AnyMod.hpp
 */
template<int MOD>
struct NumberTheoreticTransform_AnyMod {
	static_assert(MOD > 0);
	
private:
	using calc_type = long long;
	using uint32 = std::uint32_t;
	
public:
	template<typename T>
	static std::vector<T> multiply(const std::vector<T> & a, const std::vector<T> & b) {
		static_assert(std::is_integral<T>::value);
		static_assert(std::is_signed<T>::value);
		for (uint32 i = 0; i < a.size(); ++i) assert(a[i] >= 0);
		for (uint32 i = 0; i < b.size(); ++i) assert(b[i] >= 0);
		std::vector<T> m;
		auto ntt1_res = NumberTheoreticTransform<1'224'736'769, 3>::multiply(a, b);
		m.emplace_back(1'224'736'769);
		auto ntt2_res = NumberTheoreticTransform<469'762'049, 3>::multiply(a, b);
		m.emplace_back(469'762'049);
		auto ntt3_res = NumberTheoreticTransform<167'772'161, 3>::multiply(a, b);
		m.emplace_back(167'772'161);
		// auto ntt4_res = NumberTheoreticTransform<998'244'353, 3>::multiply(a, b);
		// m.emplace_back(998'244'353);
		
		std::vector<T> c(m.size());
		std::vector<T> res(ntt1_res.size());
		for (uint32 i = 0; i < res.size(); ++i) {
			c[0] = ntt1_res[i];
			c[1] = ntt2_res[i];
			c[2] = ntt3_res[i];
			// c[3] = ntt4_res[i];
			res[i] = tk::garner<T, calc_type>(c, m, MOD);
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP