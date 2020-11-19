#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP
#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP

/*
last-updated: 2020/11/19

# 解説
A, B それぞれの要素の最大値を M として、max(|A|, |B|) * M^2 \leq \prod mods となるように mod を選ぶ必要がある

NumberTheoreticTransform<998'244'353, 3> // 2^23 | (mod - 1)
NumberTheoreticTransform<1'224'736'769, 3> // 2^24 | (mod - 1)
NumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)
NumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)

# 仕様
template 引数:
	int MOD: mod を取りたい値

static std::vector<T> multiply(const std::vector<T> & A, const std::vector<T> & B)
	時間計算量: Θ(N log N) (N := |A| + |B| - 1 以上の最小の 2 冪)
	A, B の法 mod の元での畳み込み(サイズ |A| + |B| - 1) を返す
	
	制約は NumberTheoreticTransform と同じ
*/

#include "Mathematics/Convolution/NumberTheoreticTransform.hpp"
#include "Mathematics/Garner.hpp"

#include <vector>
#include <cstdint>
#include <vector>

template<int MOD>
struct NumberTheoreticTransform_AnyMod {
public:
	using value_type = long long;
	using size_type = std::uint_fast32_t;
	static_assert(MOD > 0);
	
	template<typename T>
	static std::vector<T> multiply(const std::vector<T> & A, const std::vector<T> & B) {
		std::vector<value_type> m;
		auto ntt1_res = NumberTheoreticTransform<1'224'736'769, 3>::multiply(A, B);
		m.emplace_back(1'224'736'769);
		auto ntt2_res = NumberTheoreticTransform<469'762'049, 3>::multiply(A, B);
		m.emplace_back(469'762'049);
		auto ntt3_res = NumberTheoreticTransform<167'772'161, 3>::multiply(A, B);
		m.emplace_back(167'772'161);
		// auto ntt4_res = NumberTheoreticTransform<998'244'353, 3>::multiply(A, B);
		// m.emplace_back(998'244'353);
		
		std::vector<value_type> b(m.size());
		std::vector<T> res(ntt1_res.size());
		for (size_type i = 0; i < res.size(); ++i) {
			b[0] = ntt1_res[i];
			b[1] = ntt2_res[i];
			b[2] = ntt3_res[i];
			// b[3] = ntt4_res[i];
			res[i] = Garner::garner<value_type>(b, m, MOD);
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_ANY_MOD_HPP