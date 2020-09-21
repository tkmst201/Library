#ifndef INCLUDE_GUARD_COUNTING_PRIMES_HPP
#define INCLUDE_GUARD_COUNTING_PRIMES_HPP

/*
last-updated: 2020/09/07

# 仕様
std::uint64_t counting_primes(std::uint64_t n) :
時間計算量: O(n^(3/4))
空間計算量: Θ(n^(1/2))

n 以下の素数の個数を返す
n \leq 10^11 なら 1 sec 以内に求まる

# 解説
prime_sum を少しいじると素数の個数に変更できる

# 参考
https://math314.hateblo.jp/entry/2016/06/05/004332, 2020/09/07
*/

#include "Mathematics/PrimeNumber/enumerate_primes.hpp"

#include <cstdint>
#include <vector>
#include <algorithm>

namespace tk {
std::uint64_t counting_primes(std::uint64_t n) {
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
	
	std::vector<uint64> dp; // [i]([j]) := S(div[i], j)
	dp.reserve(div.size());
	for (auto d : div) dp.emplace_back(d - 1);
	
	for (uint32 j = 0; j < primes.size(); ++j) {
		for (uint32 i = div.size(); i > 0; --i) {
			const uint64 m = div[i - 1];
			if (static_cast<uint64>(primes[j]) * primes[j] > m) break;
			const uint64 d = m / primes[j];
			const uint32 idx = d <= s ? d - 1 : div.size() - n / d;
			dp[i - 1] -= dp[idx] - j;
		}
	}
	
	return dp.back();
}
} // namespace tk

#endif // INCLUDE_GUARD_COUNTING_PRIMES_HPP