#include <vector>
#include <cassert>

/*
last-updated: 2020/07/27

b: ( b_0, \ldots, b_{k-1} ), m: ( m_0, \ldots, m_{k-1} ) に対して、
x \equiv b_i (mod. m_i) (\forall i) となる x を [0, lcm(m_0, \ldots, m_{k-1})) の範囲で求める。
このような x は、b_0 \equiv \dots \equiv b_{k-1} (mod. gcd(m_0, \ldots, m_{k-1})) であるときのみ存在し、一意である。

template<typename T>
static bool preprocess(std::vector<T> &b, std::vector<T> &m) :
	O(k^2 log m (loglog m)) ? これより小さい気がするが分からず
	m が互いに素でないときに連立合同式の同値変形を行い、互いに素に変形する。
	解が存在しない場合は false を返す

template<typename T>
static T garner(const std::vector<T> & b, std::vector<T> m, const T &mod) :
	O(k(k + log m))
	m は互いに素であることが必要
	(x \equiv b_i (mod. m_i) (\forall i) となる x) modulo. mod を返す(m は互いに素より必ず存在する)

仕様
- T は符号付き整数。

参考 :
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