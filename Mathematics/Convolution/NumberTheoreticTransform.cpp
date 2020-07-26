#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <vector>
#include <utility>
#include <cassert>

#include "Mathematics/Garner.cpp"

/*
last-updated: 2020/07/27

static std::vector<value_type> multiply(
	const std::vector<value_type> &A,
	const std::vector<value_type> &B,
	value_type mod) : 
	
	A, B の畳み込み modulo. mod を返す
	
	N = |A| + |B| 以上の最小の 2 冪
	時間計算量: Θ(N log N)
	制約:
		N \leq 2^min(two_exps) ( N 乗根を求めるため)
		各要素の最大値を M として、max(|A|, |B|) * M^2 \leq \prod mods (Garger のアルゴリズムで復元するため)

参考 :
https://math314.hateblo.jp/entry/2015/05/07/014908, 2020/07/27
https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0, 2020/07/27
http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html, 2020/07/27
*/

struct NumberTheoreticTransform {
public:
	using value_type = long long;
	using size_type = std::size_t;
	
	static std::vector<value_type> multiply(const std::vector<value_type> &A, const std::vector<value_type> &B, value_type mod) {
		std::vector<value_type> mods;
		std::vector<value_type> primitive_roots;
		std::vector<size_type> two_exps;
		// mods.emplace_back(998'244'353); primitive_roots.emplace_back(3); two_exps.emplace_back(23);
		mods.emplace_back(1'224'736'769); primitive_roots.emplace_back(3); two_exps.emplace_back(24);
		mods.emplace_back(469'762'049); primitive_roots.emplace_back(3); two_exps.emplace_back(26);
		mods.emplace_back(167'772'161); primitive_roots.emplace_back(3); two_exps.emplace_back(25);
		
		std::vector<std::vector<value_type>> ntt_result;
		ntt_result.reserve(mods.size());
		for (size_type i = 0; i < mods.size(); ++i) ntt_result.emplace_back(_multiply(A, B, mods[i], primitive_roots[i], two_exps[i]));
		
		std::vector<value_type> res;
		res.reserve(ntt_result[0].size());
		std::vector<value_type> gar_b(mods.size());
		for (size_type i = 0; i < ntt_result[0].size(); ++i) {
			for(size_type j = 0; j < mods.size(); ++j) gar_b[j] = ntt_result[j][i];
			res.emplace_back(Garner::garner(gar_b, mods, mod));
		}
		return res;
	}
	
private:
	static value_type mod_pow(value_type x, value_type n, value_type mod) {
		value_type res = 1;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	
	static value_type mod_inv(value_type x, value_type mod) {
		return mod_pow(x, mod - 2, mod);
	}
	
	static std::vector<value_type> _multiply(const std::vector<value_type> &A, const std::vector<value_type> &B, const value_type mod, const value_type primitive_root, const size_type two_exp) {
		if (A.empty() || B.empty()) return {};
		size_type n_ = A.size() + B.size() - 1;
		size_type n = 1;
		while (n < n_) n <<= 1;
		assert(1 << two_exp >= n);
		std::vector<value_type> a, b;
		a.reserve(n), b.reserve(n);
		for (size_type i = 0; i < A.size(); ++i) a.emplace_back((A[i] % mod + mod) % mod);
		for (size_type i = 0; i < B.size(); ++i) b.emplace_back((B[i] % mod + mod) % mod);
		a.resize(n); ntt(a, mod, primitive_root);
		b.resize(n); ntt(b, mod, primitive_root);
		
		const value_type ninv = mod_inv(n, mod);
		for (size_type i = 0; i < n; ++i) a[i] = a[i] * b[i] % mod * ninv % mod;
		ntt(a, mod, primitive_root, true);
		return a;
	}
	
	static void ntt(std::vector<value_type> &A, const value_type mod, const value_type primitive_root, const bool inv = false) {
		const size_type N = A.size();
		
		value_type nroot = mod_pow(primitive_root, (mod - 1) / N, mod);
		if (inv) nroot = mod_inv(nroot, mod);
		
		for (size_type n = N; n > 1; n >>= 1) {
			const size_type m = n >> 1;
			std::vector<value_type> omega;
			omega.reserve(m);
			omega.emplace_back(1);
			for (size_type i = 0; i < m; ++i) omega.emplace_back(omega.back() * nroot % mod);
			value_type half = mod_pow(nroot, m, mod);
			
			for (size_type p = 0; p < N; p += n) {
				for (size_type i = p, ei = p + m; i < ei; ++i) {
					const value_type a = A[i], b = A[i + m];
					A[i] = (a + b) % mod;
					A[i + m] = (a + b * half % mod + mod) * omega[i - p] % mod;
				}
			}
			nroot = nroot * nroot % mod;
		}
		
		bit_reverse(A);
	}
	
	static void bit_reverse(std::vector<value_type> &A) {
		const size_type N = A.size();
		for (size_type i = 1, j = 0; i < N - 1; ++i) {
			for (size_type k = N >> 1; k > (j ^= k); k >>= 1);
			if (i < j) std::swap(A[i], A[j]);
		}
	}
};