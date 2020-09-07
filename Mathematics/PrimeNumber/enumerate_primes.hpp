#ifndef INCLUDE_GUARD_ENUMERATE_PRIMES_HPP
#define INCLUDE_GUARD_ENUMERATE_PRIMES_HPP

#include <vector>
#include <cstdint>
#include <algorithm>

/*
last-updated: 2020/09/07

# 仕様
std::vector<std::uint32_t> enumerate_primes(std::uint32_t n) :
時間計算量: Θ(n)
空間計算量: Θ(n^(1/2))

n 以下の素数を昇順に並べた配列を返す
エラトステネスの篩

# 参考
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes, 2020/09/07
*/

namespace tk {
std::vector<std::uint32_t> enumerate_primes(std::uint32_t n) {
	if (n < 2) return {};
	using uint32 = std::uint32_t;
	uint32 s = 0; // floor(sqrt(n)) + 1
	for (uint32 i = 16; i > 0; --i) {
		uint32 x = s + (1u << (i - 1));
		if (x * x <= n) s |= 1u << (i - 1);
	}
	if (s < 3) s = 2;
	++s;
	
	std::vector<uint32> primes, pos;
	std::vector<bool> isprime(s, true);
	for (uint32 i = 2; i < s; ++i) {
		if (!isprime[i]) continue;
		primes.emplace_back(i);
		uint32 j = i;
		for(; j < s; j += i) isprime[j] = false;
		pos.emplace_back(j - s);
	}
	
	uint32 sq_size = primes.size();
	for (uint32 l = s; l <= n; l += s) {
		const uint32 r = std::min(l + s, n + 1);
		const uint32 seg = r - l;
		isprime.assign(seg, true);
		for (uint32 i = 0; i < sq_size; ++i) {
			uint32 j = pos[i];
			for (; j < seg; j += primes[i]) isprime[j] = false;
			pos[i] = j - seg;
		}
		for (uint32 i = 0; i < seg; ++i) if (isprime[i]) primes.emplace_back(i + l);
	}
	
	return primes;
}
}

#endif // INCLUDE_GUARD_ENUMERATE_PRIMES_HPP