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


# :x: Test/PrimeNumber.enumerate_primes.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/PrimeNumber.enumerate_primes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/enumerate_primes">https://judge.yosupo.jp/problem/enumerate_primes</a>


## Depends on

* :x: <a href="../../library/Mathematics/PrimeNumber/enumerate_primes.hpp.html">Mathematics/PrimeNumber/enumerate_primes.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "Mathematics/PrimeNumber/enumerate_primes.hpp"

#include <cstdio>

int main() {
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	
	auto primes = tk::enumerate_primes(N);
	
	std::vector<int> ans;
	for (int i = 0, idx = B; idx < primes.size() && primes[idx] <= N; ++i, idx += A)
		ans.emplace_back(primes[idx]);
	
	printf("%d %d\n", primes.size(), ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/PrimeNumber.enumerate_primes.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

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


#line 4 "Test/PrimeNumber.enumerate_primes.test.cpp"

#include <cstdio>

int main() {
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	
	auto primes = tk::enumerate_primes(N);
	
	std::vector<int> ans;
	for (int i = 0, idx = B; idx < primes.size() && primes[idx] <= N; ++i, idx += A)
		ans.emplace_back(primes[idx]);
	
	printf("%d %d\n", primes.size(), ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

