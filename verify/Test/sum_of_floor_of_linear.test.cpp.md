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


# :heavy_check_mark: Test/sum_of_floor_of_linear.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/sum_of_floor_of_linear.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 08:54:48+09:00


* see: <a href="https://judge.yosupo.jp/problem/sum_of_floor_of_linear">https://judge.yosupo.jp/problem/sum_of_floor_of_linear</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Mathematics/sum_of_floor_of_linear.hpp.html">Mathematics/sum_of_floor_of_linear.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "Mathematics/sum_of_floor_of_linear.hpp"

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	
	using ll = long long;
	
	while (T--) {
		ll n, m, a, b;
		scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
		printf("%lld\n", tk::sum_of_floor_of_linear<ll>(n, m, a, b));
	}
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/sum_of_floor_of_linear.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#line 1 "Mathematics/sum_of_floor_of_linear.hpp"



#include <utility>
#include <cassert>

/*
last-updated: 2020/09/11

# 仕様
template<typename T>
T sum_of_floor_of_linear(T N, T M, T A, T B) :
	時間計算量: O(log min{M, A})
	\Sum_{i = 0}^{N - 1} floor((A \times i + B) / M) を求める

# 参考
https://twitter.com/kyopro_friends/status/1304063876019793921?s=20, 2020/09/11
https://qiita.com/HNJ/items/564f15316719209df73c, 2020/09/10
*/

namespace tk {
template<typename T>
T sum_of_floor_of_linear(T N, T M, T A, T B) {
	using value_type = T;
	value_type res = 0;
	assert(N >= 0);
	assert(M > 0);
	assert(A >= 0);
	assert(B >= 0);
	
	if (B >= M) {
		value_type d = B / M;
		res += d * N;
		B -= d * M;
	}
	if (N == 0) return res;
	
	while (true) {
		if (A >= M) {
			value_type d = A / M;
			res += N * (N - 1) / 2 * d;
			A -= d * M;
		}
		if (A == 0) break;
		
		value_type ymax = (A * N + B) / M;
		if (ymax == 0) break;
		
		value_type t = M * ymax - B;
		res += ymax * (N - (t + A - 1) / A);
		B = A - t % A;
		if (B == A) B -= A;
		N = ymax;
		std::swap(A, M);
	}
	return res;
}
} // namespace tk


#line 4 "Test/sum_of_floor_of_linear.test.cpp"

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	
	using ll = long long;
	
	while (T--) {
		ll n, m, a, b;
		scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
		printf("%lld\n", tk::sum_of_floor_of_linear<ll>(n, m, a, b));
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

