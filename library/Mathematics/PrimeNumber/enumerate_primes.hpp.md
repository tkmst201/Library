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


# :x: Mathematics/PrimeNumber/enumerate_primes.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#52bd1cf97062cf16ea4e1de9a8338397">Mathematics/PrimeNumber</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/PrimeNumber/enumerate_primes.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Required by

* :x: <a href="counting_primes.hpp.html">Mathematics/PrimeNumber/counting_primes.hpp</a>


## Verified with

* :x: <a href="../../../verify/Test/PrimeNumber.counting_primes.test.cpp.html">Test/PrimeNumber.counting_primes.test.cpp</a>
* :x: <a href="../../../verify/Test/PrimeNumber.enumerate_primes.test.cpp.html">Test/PrimeNumber.enumerate_primes.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/PrimeNumber/enumerate_primes.hpp"



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



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

