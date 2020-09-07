---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Mathematics/Convolution/NumberTheoreticTransform.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#637dbc1fa2c49b2df4202c454476276a">Mathematics/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/Convolution/NumberTheoreticTransform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Depends on

* :heavy_check_mark: <a href="../Garner.hpp.html">Mathematics/Garner.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/Test/NumberTheoreticTransform.test.cpp.html">Test/NumberTheoreticTransform.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP
#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP

#include <vector>
#include <utility>
#include <cassert>

#include "Mathematics/Garner.hpp"

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

#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/Convolution/NumberTheoreticTransform.hpp"



#include <vector>
#include <utility>
#include <cassert>

#line 1 "Mathematics/Garner.hpp"



#line 6 "Mathematics/Garner.hpp"

/*
last-updated: 2020/07/27

# 解説
b: ( b_0, \ldots, b_{k-1} ), m: ( m_0, \ldots, m_{k-1} ) に対して、
x \equiv b_i (mod. m_i) (\forall i) となる x を [0, lcm(m_0, \ldots, m_{k-1})) の範囲で求める。
このような x は、b_0 \equiv \dots \equiv b_{k-1} (mod. gcd(m_0, \ldots, m_{k-1})) であるときのみ存在し、一意である。

# 仕様
template<typename T>
static bool preprocess(std::vector<T> &b, std::vector<T> &m) :
	時間計算量: O(k^2 log m (loglog m)) ? これより小さい気がするが分からず
	m が互いに素でないときに連立合同式の同値変形を行い、互いに素に変形する。
	解が存在しない場合は false を返す

template<typename T>
static T garner(const std::vector<T> & b, std::vector<T> m, const T &mod) :
	時間計算量: O(k(k + log m))
	m は互いに素であることが必要
	(x \equiv b_i (mod. m_i) (\forall i) となる x) modulo. mod を返す(m は互いに素より必ず存在する)

仕様
- T は符号付き整数。

# 参考
https://qiita.com/drken/items/ae02240cd1f8edfc86fd, 2020/05/05
*/

struct Garner {
public:
	using size_type = std::size_t;
	
	template<typename T>
	static bool preprocess(std::vector<T> &b, std::vector<T> &m) {
		for (size_type i = 0; i < b.size(); ++i) {
			for (size_type j = 0; j < i; ++j) {
				T g = gcd(m[i], m[j]);
				if ((b[i] - b[j]) % g) return false;
				m[i] /= g; m[j] /= g;
				
				T gi = gcd(g, m[i]), gj = g / gi;
				do {
					g = gcd(gi, gj);
					gi *= g; gj /= g;
				} while (g != 1);
				
				m[i] *= gi; m[j] *= gj;
				b[i] %= m[i]; b[j] %= m[j];
			}
		}
		return true;
	}
	
	template<typename T>
	static T garner(const std::vector<T> &b, std::vector<T> m, const T mod) {
		assert(b.size() == m.size());
		assert(!b.empty());
		T tg = m[0];
		for (size_type i = 0; i < b.size(); ++i) {
			assert(m[i] > 0);
			tg = gcd(tg, m[i]);
		}
		assert(mod > 0);
		assert(b.size() == 1 || tg == 1);
		
		m.emplace_back(mod);
		std::vector<T> sum(m.size()), ip(m.size(), 1);
		for (size_type i = 0; i < b.size(); ++i) {
			/*
				ip[j] := m_0 m_1 \ldots m_{i-1} (mod. m_j)
				sum[j] := t_0 ip[0]  t_1 ip[1]  \ldots  t_{i-1} ip[i-1] (mod. m_j)
			*/
			T t = ((b[i] % m[i] + m[i]) % m[i] - sum[i] + m[i]) % m[i] % m[i] * inverse(ip[i], m[i]) % m[i];
			for (size_type j = i + 1; j < m.size(); ++j) {
				sum[j] = (sum[j] + ip[j] * t) % m[j];
				ip[j] = (ip[j] * m[i] % m[j]);
			}
		}
		return sum.back();
	}
	
private:
	template<typename T>
	static T gcd(T a, T b) {
		while (b > 0) {
			T nb = a % b;
			a = b;
			b = nb;
		}
		return a;
	}
	
	template<typename T>
	static T inverse(const T &a, const T &mod) {
		T a0 = (a % mod + mod) % mod, a1 = 1, a2 = 0;
		T b0 = mod, b1 = 0, b2 = 1;
		while (b0 > 0) {
			T q = a0 / b0;
			T nb0 = a0 % b0, nb1 = a1 - b1 * q, nb2 = a2 - b2 * q;
			a0 = b0; a1 = b1; a2 = b2;
			b0 = nb0; b1 = nb1; b2 = nb2;
		}
		assert(a0 == 1);
		return (a1 % mod + mod) % mod;
	}
};


#line 9 "Mathematics/Convolution/NumberTheoreticTransform.hpp"

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



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

