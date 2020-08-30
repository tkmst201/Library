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


# :warning: Mathematics/Combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#540b21ecdb276f5087ee585cedd6d5d0">Mathematics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/Combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 21:49:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <cassert>
#include <algorithm>

/*
last-updated: 2020/01/15

# 仕様
template引数 には ModInt を渡す。(require get_mod())

Construct : Amortized Θ(max k + (logM)^2 ) ??
Query : Amortized Θ(1) ?? 謎

Comination(size_type sz = 1) :
	sz! を計算できるだけ前計算

T fact(size_type k) :
	k! を求める

T finv(size_type k) :
	(k!)^-1 を求める

T inv(size_type k) :
	k^-1 を求める

:private:
void build(size_type k) :
	k! が計算できるように確保
*/

template<typename T>
struct Combination {
public:
	using size_type = std::size_t;
	
	Combination(size_type sz = 1) : _fact(1, 1), _finv(1, 1), _inv(1, 1) { build(sz); }
	
	T fact(size_type k) { if (k >= T::get_mod()) return 0; build(k); return _fact[k]; }
	T finv(size_type k) { assert(k < T::get_mod()); build(k); return _finv[k]; }
	T inv(size_type k) { assert(k > 0 && k < T::get_mod()); build(k); return _inv[k]; }
	
	T operator ()(int n, int r) { return c(n, r); }
	T c(int n, int r) {
		if (r < 0 || n < r) return 0;
		return fact(n) * finv(r) * finv(n - r);
	}
	
private:
	std::vector<T> _fact, _finv, _inv;
	static constexpr size_type MAX_LIMIT = 50000000;
	
	void build(size_type k) {
		if (_fact.size() > k) return;
		assert(k < MAX_LIMIT);
		size_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::get_mod()), std::max(_fact.size() * 2, k + 1)});
		size_type presz = _fact.size();
		_fact.resize(sz);
		_finv.resize(sz);
		_inv.resize(sz);
		
		for (size_type i = presz; i < sz; ++i) _fact[i] = _fact[i - 1] * i;
		_finv[sz - 1] = T(_fact[sz - 1]).inverse();
		for (size_type i = sz - 1; i > presz; --i) {
			_finv[i - 1] = _finv[i] * i;
			_inv[i] = _fact[i - 1] * _finv[i];
		}
		_inv[presz] = _fact[presz - 1] * _finv[presz];
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/Combination.cpp"
#include <vector>
#include <cassert>
#include <algorithm>

/*
last-updated: 2020/01/15

# 仕様
template引数 には ModInt を渡す。(require get_mod())

Construct : Amortized Θ(max k + (logM)^2 ) ??
Query : Amortized Θ(1) ?? 謎

Comination(size_type sz = 1) :
	sz! を計算できるだけ前計算

T fact(size_type k) :
	k! を求める

T finv(size_type k) :
	(k!)^-1 を求める

T inv(size_type k) :
	k^-1 を求める

:private:
void build(size_type k) :
	k! が計算できるように確保
*/

template<typename T>
struct Combination {
public:
	using size_type = std::size_t;
	
	Combination(size_type sz = 1) : _fact(1, 1), _finv(1, 1), _inv(1, 1) { build(sz); }
	
	T fact(size_type k) { if (k >= T::get_mod()) return 0; build(k); return _fact[k]; }
	T finv(size_type k) { assert(k < T::get_mod()); build(k); return _finv[k]; }
	T inv(size_type k) { assert(k > 0 && k < T::get_mod()); build(k); return _inv[k]; }
	
	T operator ()(int n, int r) { return c(n, r); }
	T c(int n, int r) {
		if (r < 0 || n < r) return 0;
		return fact(n) * finv(r) * finv(n - r);
	}
	
private:
	std::vector<T> _fact, _finv, _inv;
	static constexpr size_type MAX_LIMIT = 50000000;
	
	void build(size_type k) {
		if (_fact.size() > k) return;
		assert(k < MAX_LIMIT);
		size_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::get_mod()), std::max(_fact.size() * 2, k + 1)});
		size_type presz = _fact.size();
		_fact.resize(sz);
		_finv.resize(sz);
		_inv.resize(sz);
		
		for (size_type i = presz; i < sz; ++i) _fact[i] = _fact[i - 1] * i;
		_finv[sz - 1] = T(_fact[sz - 1]).inverse();
		for (size_type i = sz - 1; i > presz; --i) {
			_finv[i - 1] = _finv[i] * i;
			_inv[i] = _fact[i - 1] * _finv[i];
		}
		_inv[presz] = _fact[presz - 1] * _finv[presz];
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

