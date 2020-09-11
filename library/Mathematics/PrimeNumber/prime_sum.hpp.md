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


# :warning: Mathematics/PrimeNumber/prime_sum.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#52bd1cf97062cf16ea4e1de9a8338397">Mathematics/PrimeNumber</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/PrimeNumber/prime_sum.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 16:59:22+09:00




## Depends on

* :heavy_check_mark: <a href="enumerate_primes.hpp.html">Mathematics/PrimeNumber/enumerate_primes.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_PRIME_SUM_HPP
#define INCLUDE_GUARD_PRIME_SUM_HPP

#include <cstdint>
#include <vector>
#include <algorithm>

#include "Mathematics/PrimeNumber/enumerate_primes.hpp"

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/PrimeNumber/prime_sum.hpp"



#include <cstdint>
#include <vector>
#include <algorithm>

#line 1 "Mathematics/PrimeNumber/enumerate_primes.hpp"



#line 7 "Mathematics/PrimeNumber/enumerate_primes.hpp"

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


#line 9 "Mathematics/PrimeNumber/prime_sum.hpp"

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



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

