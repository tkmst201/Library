#ifndef INCLUDE_GUARD_PRIME_SUM_HPP
#define INCLUDE_GUARD_PRIME_SUM_HPP

/*
last-updated: 2020/09/07

unverified だが、ほとんど実装が同じ counting_primes を verify しているのでほぼ正しい(と思う)

# 仕様
template<typename T>
T prime_sum(std::uint64_t n) :
template T: n 以下の素数の合計を入れる型
時間計算量: O(n^(3/4))
空間計算量: Θ(n^(1/2))

n 以下の素数の合計を返す
n \leq 10^11 なら 1 sec 以内に求まる

# 解説
任意の非負整数 a, b, c に対し、floor(floor(a / b) / c) = floor(a / (bc)) となる。
お気持ち:
	a / b を小数で考えると floor((a / b) / c) は c \times k \leq a / b となる最大の整数 k と一致するため、小数部分は無視できる。
	したがって、floor(floor(a / b) / c) = floor((a / b) / c) = floor(a / (bc))

floor(n / i) (1 \leq i \ leq n) の取りうる値を降順に列挙する話
	floor(n / i) = floor(n / j) となる最大の j は floor(n / floor(n / i)) である。
	これは、n = p_1 i + q_1 (0 \leq q_1 < i), q_1 = p_2 p_1 + q_2 (0 \leq q_2 < p_1, q_2 \leq q_1) と変形して計算することによって分かる。
	↑ もっと直感的な証明がほしい

以下 s := floor(sqrt(n)) とする。

整数 i (1 \leq i < s) では floor(n / i) - 1 \geq floor(n / (i + 1)) である。
	n / i - (n / (i + 1)) = n / i(i + 1) ...(1) であるが、 i(i + 1) < s^2 \leq n なので (1) 式は 1 以上である。
	差が 1 以上あれば floor を取っても 1 以上の差がでることから分かる。

1 \leq a \leq s のとき、b = floor(n / a) とおくと b \geq s であり、a = floor(n / b) となる。
	b \leq s と仮定すると ab \leq n は必ず成り立つので b \geq s と分かる。
	b は ai \leq n となる最大の整数 i であることから a(b + 1) > n <=> n - ab < a が成り立つ。
	先程の結果より a \leq b と分かるので n - ab < b である。
	ab \leq n と併せて a = floor(n / b) と分かる。

floor(n / i) (1 \leq i \leq n) が取る値
	s < a \leq n のとき、floor(n / a) < s であるので先程の結果を用いると、
	1 \leq j \leq s について、j と floor(n / j) を集めた集合が floor(n / i) (1 \leq i \leq n) が取る値の集合と一致する。
↑ この取る値の集合を div とする

div の要素から div の index を求める方法
	これまでの結果を用いると次のように求めることができる。
	k \in div のとき、
		k \leq s なら div[k - 1] = k
		k > s なら div[div.size() - n / k] = k
	
# 参考
https://math314.hateblo.jp/entry/2016/06/05/004332, 2020/09/07
*/

#include "Mathematics/PrimeNumber/enumerate_primes.hpp"

#include <cstdint>
#include <vector>
#include <algorithm>

namespace tk {
template<typename T>
T prime_sum(std::uint64_t n) {
	if (n == 0) return 0;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
	
	uint32 s = 0; // floor(sqrt(n))
	for (uint32 i = 32; i > 0; --i) {
		uint64 x = s + (1u << (i - 1));
		if (x * x <= n) s |= 1u << (i - 1);
	}
	
	std::vector<uint64> div;
	div.reserve(2 * s);
	{
		uint64 l = 1;
		while (l <= n) {
			div.emplace_back(n / l);
			l = n / div.back() + 1;
		}
	}
	std::reverse(begin(div), end(div));
	
	auto primes = enumerate_primes(s);
	std::vector<T> sum(primes.size() + 1, 0);
	for (uint32 i = 0; i < primes.size(); ++i) sum[i + 1] += primes[i];
	
	std::vector<T> dp; // [i]([j]) := S(div[i], j)
	for (auto d : div) {
		if (d & 1) dp.emplace_back(static_cast<T>(d) * ((d + 1) / 2) - 1);
		else dp.emplace_back(static_cast<T>(d / 2) * (d + 1) - 1);
	}
	
	for (uint32 j = 0; j < primes.size(); ++j) {
		for (uint32 i = div.size(); i > 0; --i) {
			const uint64 m = div[i - 1];
			if (static_cast<uint64>(primes[j]) * primes[j] > m) break;
			const uint64 d = m / primes[j];
			const uint32 idx = d <= s ? d - 1 : div.size() - n / d;
			dp[i - 1] -= (dp[idx] - sum[j]) * primes[j];
		}
	}
	
	return dp.back();
}
} // namespace tk

#endif // INCLUDE_GUARD_PRIME_SUM_HPP