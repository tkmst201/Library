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


# :heavy_check_mark: DataStructure/SegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/HeavyLightDecomposition.test.cpp.html">Test/HeavyLightDecomposition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/SegmentTree_fold.test.cpp.html">Test/SegmentTree_fold.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
last-updated: 2020/04/22

SegmentTree(size_type n_, const F & f, const_reference id_elem) : 要素数 n_, 二項演算 f, 単位元 id_elem
void set(size_type i, const_reference x) : Θ(log n) i 番目の要素に x を代入
void add(size_type i, const_reference x) : Θ(lon n) i 番目の要素に x を演算する
value_type fold(size_type l, size_type r) const : Θ(log n) [l, r) を fold した結果を返す
size_type lower_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す
size_type upper_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

参考 :
https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf, 2020/04/08
*/

template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	SegmentTree(size_type n_, const F & f, const_reference id_elem) : f(f), id_elem(id_elem) {
		n = 1;
		while (n < n_) n <<= 1;
		node.resize(2 * n, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += n] = x;
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += n;
		node[i] = f(node[i], x);
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex < x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
	size_type upper_bound(const_reference x) const {
		if (node[1] <= x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex <= x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
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
#line 1 "DataStructure/SegmentTree.cpp"
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
last-updated: 2020/04/22

SegmentTree(size_type n_, const F & f, const_reference id_elem) : 要素数 n_, 二項演算 f, 単位元 id_elem
void set(size_type i, const_reference x) : Θ(log n) i 番目の要素に x を代入
void add(size_type i, const_reference x) : Θ(lon n) i 番目の要素に x を演算する
value_type fold(size_type l, size_type r) const : Θ(log n) [l, r) を fold した結果を返す
size_type lower_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す
size_type upper_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

参考 :
https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf, 2020/04/08
*/

template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	SegmentTree(size_type n_, const F & f, const_reference id_elem) : f(f), id_elem(id_elem) {
		n = 1;
		while (n < n_) n <<= 1;
		node.resize(2 * n, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += n] = x;
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += n;
		node[i] = f(node[i], x);
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex < x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
	size_type upper_bound(const_reference x) const {
		if (node[1] <= x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex <= x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
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

