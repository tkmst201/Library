#ifndef INCLUDE_GUARD_GARNER_HPP
#define INCLUDE_GUARD_GARNER_HPP

/*
last-updated: 2020/09/21

# 解説
b: ( b_0, \ldots, b_{k-1} ), m: ( m_0, \ldots, m_{k-1} ) に対して、
x \equiv b_i (mod. m_i) (\forall i) となる x を [0, lcm(m_0, \ldots, m_{k-1})) の範囲で求める。
このような x は、b_0 \equiv \dots \equiv b_{k-1} (mod. gcd(m_0, \ldots, m_{k-1})) であるときのみ存在し、一意である。

garner の計算途中は O(m^2) 程度まで値が大きくなるので overflow に注意

# 仕様
template<typename T>
static bool preprocess(std::vector<T> &b, std::vector<T> &m) :
	時間計算量: O(k^2 log m (loglog m)) ? これより小さい気がするが分からず
	m が互いに素でないときに連立合同式の同値変形を行い、互いに素に変形する。
	解が存在しない場合は false を返す
	計算過程では m は小さくなる方向にしか変化しないため overflow することはない

template<typename T>
static T garner(const std::vector<T> & b, std::vector<T> m, const T &mod) :
	時間計算量: O(k(k + log m))
	m は互いに素であることが必要
	(x \equiv b_i (mod. m_i) (\forall i) となる x) modulo. mod を返す(m は互いに素より必ず存在する)
	計算過程で m^2 程度まで値が大きくなる

仕様
- T は符号付き整数。

# 参考
https://qiita.com/drken/items/ae02240cd1f8edfc86fd, 2020/05/05
*/

#include <vector>
#include <cassert>

#include <Mathematics/MathUtility.hpp>

struct Garner {
public:
	using size_type = std::size_t;
	
	template<typename T>
	static bool preprocess(std::vector<T> &b, std::vector<T> &m) {
		for (size_type i = 0; i < b.size(); ++i) {
			for (size_type j = 0; j < i; ++j) {
				T g = tk::gcd(m[i], m[j]);
				if ((b[i] - b[j]) % g) return false;
				m[i] /= g; m[j] /= g;
				
				T gi = tk::gcd(g, m[i]), gj = g / gi;
				do {
					g = tk::gcd(gi, gj);
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
			tg = tk::gcd(tg, m[i]);
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
			if (m[i] == 1) continue;
			T t = ((b[i] % m[i] + m[i]) % m[i] - sum[i] + m[i]) % m[i] * tk::mod_inv(ip[i], m[i]) % m[i];
			for (size_type j = i + 1; j < m.size(); ++j) {
				sum[j] = (sum[j] + ip[j] * t) % m[j];
				ip[j] = (ip[j] * m[i] % m[j]);
			}
		}
		return sum.back();
	}
};

#endif // INCLUDE_GUARD_GARNER_HPP