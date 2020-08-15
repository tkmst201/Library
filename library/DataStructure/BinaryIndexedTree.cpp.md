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


# :heavy_check_mark: DataStructure/BinaryIndexedTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryIndexedTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 15:59:39+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/BinaryIndexedTree.test.cpp.html">Test/BinaryIndexedTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

BinaryIndexedTree(size_type n_, const F & f, const_reference id_elem) :
	要素数 n_, 二項演算 f, 単位元 id_elem

# 仕様
SegmentTree(size_type n_, const F & f, const_reference id_elem) :
	要素数 n_, 二項演算 f, 単位元 id_elem


void add(size_type i, const_reference x) :
	時間計算量 Θ(lon n)
	i 番目の要素に x を加える

value_type sum(size_type i) const :
	時間計算量 Θ(log n)
	[0, i) の合計を返す

size_type lower_bound(const_reference x) const {
	時間計算量 Θ(log n)
	sum[0, r] \leq x を満たす最小の r を返す (存在しなければ size())
	各要素は非負である必要がある

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T>
struct BinaryIndexedTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	BinaryIndexedTree(size_type n_, const F & f, const_reference id_elem) : n(n_), f(f), id_elem(id_elem) {
		node.resize(n + 1, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	void add(size_type i, const_reference x) {
		assert(i < size());
		++i;
		for (; i <= size(); i += i & -i) node[i] = f(node[i], x);
	}
	
	// [0, i)
	value_type sum(size_type i) const {
		assert(i <= size());
		value_type res = id_elem;
		for (; i > 0; i -= i & -i) res = f(res, node[i]);
		return res;
	}
	
	// sum[0, r] \leq x を満たす最小の r を返す (存在しなければ size())
	size_type lower_bound(const_reference x) const {
		size_type res = 0;
		size_type s = id_elem, w = 1;
		while (w < size()) w <<= 1;
		for (; w > 0; w >>= 1) {
			if (res + w <= size()) {
				value_type cur = f(s, node[res + w]);
				if (cur < x) {
					res += w;
					s = cur;
				}
			}
		}
		return res;
	}
	
private:
	size_type n;
	F f;
	value_type id_elem;
	std::vector<value_type> node;
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryIndexedTree.cpp"
#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

BinaryIndexedTree(size_type n_, const F & f, const_reference id_elem) :
	要素数 n_, 二項演算 f, 単位元 id_elem

# 仕様
SegmentTree(size_type n_, const F & f, const_reference id_elem) :
	要素数 n_, 二項演算 f, 単位元 id_elem


void add(size_type i, const_reference x) :
	時間計算量 Θ(lon n)
	i 番目の要素に x を加える

value_type sum(size_type i) const :
	時間計算量 Θ(log n)
	[0, i) の合計を返す

size_type lower_bound(const_reference x) const {
	時間計算量 Θ(log n)
	sum[0, r] \leq x を満たす最小の r を返す (存在しなければ size())
	各要素は非負である必要がある

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T>
struct BinaryIndexedTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	BinaryIndexedTree(size_type n_, const F & f, const_reference id_elem) : n(n_), f(f), id_elem(id_elem) {
		node.resize(n + 1, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	void add(size_type i, const_reference x) {
		assert(i < size());
		++i;
		for (; i <= size(); i += i & -i) node[i] = f(node[i], x);
	}
	
	// [0, i)
	value_type sum(size_type i) const {
		assert(i <= size());
		value_type res = id_elem;
		for (; i > 0; i -= i & -i) res = f(res, node[i]);
		return res;
	}
	
	// sum[0, r] \leq x を満たす最小の r を返す (存在しなければ size())
	size_type lower_bound(const_reference x) const {
		size_type res = 0;
		size_type s = id_elem, w = 1;
		while (w < size()) w <<= 1;
		for (; w > 0; w >>= 1) {
			if (res + w <= size()) {
				value_type cur = f(s, node[res + w]);
				if (cur < x) {
					res += w;
					s = cur;
				}
			}
		}
		return res;
	}
	
private:
	size_type n;
	F f;
	value_type id_elem;
	std::vector<value_type> node;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

