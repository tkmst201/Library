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


# :warning: Mathematics/MathUtility.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#540b21ecdb276f5087ee585cedd6d5d0">Mathematics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mathematics/MathUtility.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 21:49:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
last-updated: 2020/01/14

# 仕様
(boost の gcd が動いて遅くなるかも)
T gcd(const T & a, const T & b) :
	時間計算量: O(log b)
	a と b の greatest common divisor を求める

T lcm(const T & a, const T &b) :
	時間計算量: O(log b)
	a と b の least common multiple を求める

T extgcd(const T & a, const T & b, T &x, T &y) :
	時間計算量: O(log b)
	一次不定方程式 ax + by = gcd(x, y) の解 (x, y) を求める

# 参考
https://noshi91.hatenablog.com/entry/2019/04/01/184957, 2020/01/14
*/

template<typename T>
T gcd(const T & a, const T &b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

template<typename T>
T lcm(const T & a, const T & b) {
	return a / gcd(a, b) * b;
}

template<typename T>
T extgcd(const T & a, const T & b, T &x, T &y) {
	T a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;
	while (b0 > 0) {
		T q = a0 / b0, r = a0 % b0;
		T nb1 = a1 - q * b1, nb2 = a2 - q * b2;
		a0 = b0; b0 = r;
		a1 = b1; b1 = nb1;
		a2 = b2; b2 = nb2;
	}
	x = a1;
	y = a2;
	return a0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Mathematics/MathUtility.cpp"
/*
last-updated: 2020/01/14

# 仕様
(boost の gcd が動いて遅くなるかも)
T gcd(const T & a, const T & b) :
	時間計算量: O(log b)
	a と b の greatest common divisor を求める

T lcm(const T & a, const T &b) :
	時間計算量: O(log b)
	a と b の least common multiple を求める

T extgcd(const T & a, const T & b, T &x, T &y) :
	時間計算量: O(log b)
	一次不定方程式 ax + by = gcd(x, y) の解 (x, y) を求める

# 参考
https://noshi91.hatenablog.com/entry/2019/04/01/184957, 2020/01/14
*/

template<typename T>
T gcd(const T & a, const T &b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

template<typename T>
T lcm(const T & a, const T & b) {
	return a / gcd(a, b) * b;
}

template<typename T>
T extgcd(const T & a, const T & b, T &x, T &y) {
	T a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;
	while (b0 > 0) {
		T q = a0 / b0, r = a0 % b0;
		T nb1 = a1 - q * b1, nb2 = a2 - q * b2;
		a0 = b0; b0 = r;
		a1 = b1; b1 = nb1;
		a2 = b2; b2 = nb2;
	}
	x = a1;
	y = a2;
	return a0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

