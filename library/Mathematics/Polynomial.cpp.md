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


# :warning: Mathematics/Polynomial.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#540b21ecdb276f5087ee585cedd6d5d0">Mathematics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/Polynomial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>

// poly / (x - d) を返す
template<typename T>
std::vector<T> div_by_linear(const std::vector<T> & poly, T d) {
	assert(poly.size() >= 2);
	using size_t = std::size_t;
	std::vector<T> res(poly.size() - 1);
	T r = 0;
	for (size_t i = poly.size() - 1; i > 0; --i) {
		res[i - 1] = r + poly[i];
		r = res[i - 1] * d;
	}
	r += poly[0];
	assert(r == 0);
	return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/Polynomial.cpp"
#include <vector>

// poly / (x - d) を返す
template<typename T>
std::vector<T> div_by_linear(const std::vector<T> & poly, T d) {
	assert(poly.size() >= 2);
	using size_t = std::size_t;
	std::vector<T> res(poly.size() - 1);
	T r = 0;
	for (size_t i = poly.size() - 1; i > 0; --i) {
		res[i - 1] = r + poly[i];
		r = res[i - 1] * d;
	}
	r += poly[0];
	assert(r == 0);
	return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

