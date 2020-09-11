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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Test/PrimeNumber.counting_primes.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/PrimeNumber.counting_primes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 16:59:22+09:00


* see: <a href="https://judge.yosupo.jp/problem/counting_primes">https://judge.yosupo.jp/problem/counting_primes</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Mathematics/ModInt.hpp.html">Mathematics/ModInt.hpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/PrimeNumber/counting_primes.hpp.html">Mathematics/PrimeNumber/counting_primes.hpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/PrimeNumber/enumerate_primes.hpp.html">Mathematics/PrimeNumber/enumerate_primes.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "Mathematics/ModInt.hpp"
#include "Mathematics/PrimeNumber/counting_primes.hpp"

#include <cstdio>

int main() {
	long long N;
	scanf("%lld", &N);
	printf("%lld\n", tk::counting_primes(N));
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/PrimeNumber.counting_primes.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#line 1 "Mathematics/ModInt.hpp"



#include <cassert>
#include <iostream>

/*
last-updated: 2020/02/26

# 仕様
ModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

ModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
ModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static decltype(M) get_mod() noexcept : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const ModInt & rhs) const noexept
operator -(const ModInt & rhs) const noexept
operator *(const ModInt & rhs) const noexept
operator /(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs)
friend std::istream & operator >>(std::istream & is, ModInt & rhs) :
	入出力用

# 参考
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

template<int M>
struct ModInt {
public:
	using value_type = long long;
	
	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }
	ModInt operator +() const noexcept { return ModInt(*this); }
	ModInt operator -() const noexcept { return ModInt(0) -= *this; }
	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }
	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }
	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }
	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }
	
	ModInt & operator +=(const ModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= M) val -= M;
		return *this;
	}
	ModInt & operator -=(const ModInt & rhs) noexcept {
		if (val < rhs.val) val += M;
		val -= rhs.val;
		return *this;
	}
	ModInt & operator *=(const ModInt & rhs) noexcept {
		val = val * rhs.val % M;
		return *this;
	}
	ModInt & operator /=(const ModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	ModInt pow(value_type n) const {
		ModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	ModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;
			a = b; b = r;
			a1 = b1; b1 = nb1;
			a2 = b2; b2 = nb2;
		}
		assert(a == 1);
		return a1;
	}
	
	const value_type & get() const noexcept { return val; }
	static decltype(M) get_mod() noexcept { return M; }
	
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {
		value_type x;
		is >> x;
		rhs = ModInt(x);
		return is;
	}
private:
	value_type val;
};


#line 1 "Mathematics/PrimeNumber/counting_primes.hpp"



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


#line 9 "Mathematics/PrimeNumber/counting_primes.hpp"

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


#line 5 "Test/PrimeNumber.counting_primes.test.cpp"

#include <cstdio>

int main() {
	long long N;
	scanf("%lld", &N);
	printf("%lld\n", tk::counting_primes(N));
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

