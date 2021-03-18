#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP
#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP

/*
last-updated: 2020/11/19

# 解説
代表的な mod とその原始根
NumberTheoreticTransform<998'244'353, 3> // 2^23 | (mod - 1)
NumberTheoreticTransform<1'224'736'769, 3> // 2^24 | (mod - 1)
NumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)
NumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)

# 仕様
template 引数:
	int MOD: mod を取りたい値
	int PRIMITIVE_ROOT: 原始根

static std::vector<T> multiply(const std::vector<T> & A, const std::vector<T> & B)
	時間計算量: Θ(N log N) (N := |A| + |B| - 1 以上の最小の 2 冪)
	A, B の法 mod の元での畳み込み(サイズ |A| + |B| - 1) を返す
	
	制約:
		two_exp := (mod - 1) に含まれる素因数 2 の個数
		N \leq 2^min(two_exp) ( N 乗根を求めるため)
		T: int | long long int | unsigned int | unsigned long long など (TODO: ModInt に対応する)

# 参考
https://math314.hateblo.jp/entry/2015/05/07/014908, 2020/07/27
https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0, 2020/07/27
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/07/27
*/

#include "Mathematics/mod_pow_inv.hpp"

#include <vector>
#include <utility>
#include <cassert>
#include <cstdint>

template<int MOD, int PRIMITIVE_ROOT>
struct NumberTheoreticTransform {
public:
	using value_type = long long;
	using size_type = std::uint_fast32_t;
	static_assert(MOD > 0);
	
	template<typename T>
	static std::vector<T> multiply(const std::vector<T> & A, const std::vector<T> & B) {
		if (A.empty() || B.empty()) return {};
		size_type n_ = A.size() + B.size() - 1;
		size_type n = 1;
		while (n < n_) n <<= 1;
		
		{
			size_type two_exp = 0;
			size_type tm = MOD - 1;
			while (tm > 0 && (~tm & 1)) ++two_exp, tm >>= 1;
			assert(1 << two_exp >= n);
		}
		
		std::vector<T> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back((static_cast<value_type>(A[i]) % MOD + MOD) % MOD);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back((static_cast<value_type>(B[i]) % MOD + MOD) % MOD);
		a.resize(n, 0); ntt(a);
		b.resize(n, 0); ntt(b);
		
		const value_type ninv = tk::mod_inv<value_type>(n, MOD);
		for (size_type i = 0; i < n; ++i) a[i] = static_cast<value_type>(a[i]) * static_cast<value_type>(b[i]) % MOD * ninv % MOD;
		b.clear();
		ntt(a, true);
		a.resize(A.size() + B.size() - 1);
		return a;
	}
	
private:
	template<typename T>
	static void ntt(std::vector<T> &A, const bool inv = false) {
		const size_type N = A.size();
		value_type nroot = tk::mod_pow<value_type>(PRIMITIVE_ROOT, (MOD - 1) / N, MOD);
		if (inv) nroot = tk::mod_inv<value_type>(nroot, MOD);
		
		for (size_type n = N; n > 1; n >>= 1) {
			const size_type m = n >> 1;
			std::vector<T> omega;
			omega.reserve(m);
			omega.emplace_back(1);
			for (size_type i = 0; i < m; ++i) omega.emplace_back(static_cast<value_type>(omega.back()) * nroot % MOD);
			value_type half = tk::mod_pow<value_type>(nroot, m, MOD);
			
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i < ei; ++i) {
					const value_type a = A[i], b = A[i + m];
					A[i] = (a + b) % MOD;
					A[i + m] = (a + b * half % MOD) % MOD * static_cast<value_type>(omega[i - p]) % MOD;
				}
			}
			nroot = nroot * nroot % MOD;
		}
		
		bit_reverse(A);
	}
	
	template<typename T>
	static void bit_reverse(std::vector<T> &A) {
		const size_type N = A.size();
		for (size_type i = 1, j = 0; i < N - 1; ++i) {
			for (size_type k = N >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(A[i], A[j]);
		}
	}
};

#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP