#ifndef INCLUDE_GUARD_ENUMERATE_PRIMES_HPP
#define INCLUDE_GUARD_ENUMERATE_PRIMES_HPP

/*
last-updated: 2020/09/08

# 仕様
std::vector<std::uint32_t> enumerate_primes(std::uint32_t n) :
時間計算量: O(n / loglog n)
空間計算量: 素数の個数 + Θ(n^(1/2))

n 以下の素数を昇順に並べた配列を返す
エラトステネスの篩の {2, 3, 5} の倍数を除いた高速化版


# 参考
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes, 2020/09/07
https://qiita.com/peria/items/a4ff4ddb3336f7b81d50, 2020/09/08
*/

#include <vector>
#include <cstdint>
#include <algorithm>

namespace tk {
std::vector<std::uint32_t> enumerate_primes(std::uint32_t n) {
	if (n < 2) return {};
	using byte = std::uint8_t;
	using uint32 = std::uint32_t;
	
	constexpr byte m[8] = {1, 7, 11, 13, 17, 19, 23, 29};
	constexpr byte diff[8] = {6, 4, 2, 4, 2, 4, 6, 2}; // [i] := m[i + 1] - m[i]
	constexpr byte plus_byte[8][8] = {
		{0,0,0,0,0,0,0,1},{1,1,1,0,1,1,1,1},{2,2,0,2,0,2,2,1},{3,1,1,2,1,1,3,1},
		{3,3,1,2,1,3,3,1},{4,2,2,2,2,2,4,1},{5,3,1,4,1,3,5,1},{6,4,2,4,2,4,6,1},
	}; // [i][j] := floor(m_i m_{j+1} / 30) - floor(m_i m_j / 30)
	constexpr byte bit_mask[8][8] = {
		{254,253,251,247,239,223,191,127},{253,223,239,254,127,247,251,191},
		{251,239,254,191,253,127,247,223},{247,254,191,223,251,253,127,239},
		{239,127,253,251,223,191,254,247},{223,247,127,253,191,254,239,251},
		{191,251,247,127,254,239,223,253},{127,191,223,239,247,251,253,254},
	}; // [i][j] := ((1<<8)-1) - (1 << to_m_idx(m[i]m[j] (mod. 30))) (mod. 8))
	
	auto pop_count = [](byte x) {
		byte res = (x & 0x55) + (x >> 1 & 0x55);
		res = (res & 0x33) + (res >> 2 & 0x33);
		res = (res + (res >> 4)) & 0xf;
		return res;
	};
	
	auto sqrt = [](uint32 n) {
		uint32 res = 0;
		for (uint32 i = sizeof(n) << 2; i > 0; --i) {
			uint32 x = res + (1u << (i - 1));
			if (x * x <= n) res |= 1u << (i - 1);
		}
		return res;
	};
	
	byte b_idx[129]; // [1 << i] = i
	for (uint32 i = 0; i < 8; ++i) b_idx[1 << i] = i;
	
	auto get_prime_pos = [&](uint32 n) {
		uint32 s = sqrt(n); // floor(sqrt(n))
		const uint32 s30 = s / 30 + (s % 30 != 0);
		const uint32 n30 = n / 30 + (n % 30 != 0);
		
		std::vector<byte> isprime(n30, 255);
		isprime[0] = 254;
		for (uint32 i = 0; i < s30; ++i) {
			for (byte j = isprime[i]; j; j &= j - 1) {
				const byte mi = b_idx[j & -j];
				byte k = mi;
				for (uint32 b = (30*i + 2*m[mi])*i + m[mi]*m[mi]/30; b < n30; b += i*diff[k] + plus_byte[mi][k], k = (k + 1) & 7)
					isprime[b] &= bit_mask[mi][k];
			}
		}
		
		for (uint32 i = 8; i > 0; --i) {
			if ((n30 - 1) * 30 + m[i - 1] <= n) break;
			isprime.back() &= ~(1 << (i - 1));
		}
		
		uint32 cnt = 0;
		std::vector<uint32> prime_pos; // {byte} << 3 | {bit}
		for (uint32 i = 0; i < n30; ++i) {
			for (uint32 j = isprime[i]; j; j &= j - 1) {
				prime_pos.emplace_back(i << 3 | b_idx[j & -j]);
			}
		}
		return prime_pos;
	};
	
	auto prime_pos = get_prime_pos(sqrt(n));
	constexpr uint32 segment = 1 << 18;
	std::vector<uint32> pos;
	pos.reserve(prime_pos.size());
	for (uint32 i = 0; i < prime_pos.size(); ++i) {
		const uint32 pb = prime_pos[i] >> 3;
		const byte mi = prime_pos[i] & 7;
		pos.emplace_back(((30*pb + 2*m[mi])*pb + m[mi]*m[mi]/30) << 3 | mi);
	}
	
	std::vector<uint32> primes;
	if (2 <= n) primes.emplace_back(2);
	if (3 <= n) primes.emplace_back(3);
	if (5 <= n) primes.emplace_back(5);
	
	const uint32 n30 = n / 30 + (n % 30 != 0);
	std::vector<uint32> isprime;
	for (uint32 l = 0; l < n30; l += segment) {
		const uint32 d = std::min(segment, n30 - l);
		const uint32 r = l + d;
		
		isprime.assign(d, 255);
		if (l == 0) isprime[0] = 254;
		
		for (uint32 i = 0; i < prime_pos.size(); ++i) {
			const uint32 pb = prime_pos[i] >> 3;
			const byte mi = prime_pos[i] & 7;
			uint32 b = pos[i] >> 3;
			byte k = pos[i] & 7;
			while (b < d) {
				isprime[b] &= bit_mask[mi][k];
				b += pb*diff[k] + plus_byte[mi][k];
				k = (k + 1) & 7;
			}
			pos[i] = (b - d) << 3 | k;
		}
		
		for (uint32 i = 8; i > 0; --i) {
			if ((r - 1) * 30 + m[i - 1] <= n) break;
			isprime.back() &= ~(1 << (i - 1));
		}
		
		for (uint32 i = 0; i < d; ++i) {
			for (uint32 j = isprime[i]; j; j &= j - 1) primes.emplace_back((l + i) * 30 + m[b_idx[j & -j]]);
		}
	}
	return primes;
}
} // namespace tk

#endif // INCLUDE_GUARD_ENUMERATE_PRIMES_HPP