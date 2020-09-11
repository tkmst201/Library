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


# :heavy_check_mark: DataStructure/SegmentTree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/HeavyLightDecomposition.test.cpp.html">Test/HeavyLightDecomposition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/SegmentTree.fold.test.cpp.html">Test/SegmentTree.fold.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_SEGMENT_TREE_HPP

#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

TODO: 二分探索の一般化

# 仕様
SegmentTree(size_type n_, const F & f, const_reference id_elem) :
	時間計算量: Θ(n)
	要素数 n_, 二項演算 f, 単位元 id_elem で初期化

void set(size_type i, const_reference x) :
	時間計算量: Θ(log n)
	i 番目の要素に x を代入

void add(size_type i, const_reference x) :
	時間計算量: Θ(lon n)
	i 番目の要素に x を演算する

value_type fold(size_type l, size_type r) const :
	時間計算量: Θ(log n)
	[l, r) を fold した結果を返す

size_type lower_bound(const_reference x) const :
	時間計算量: Θ(log n)
	単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す

size_type upper_bound(const_reference x) const :
	時間計算量: Θ(log n)
	単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

# 参考
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
		node[i += size()] = x;
		update_(i);
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += size();
		node[i] = f(node[i], x);
		update_(i);
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += size(), r += size(); l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
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
		if (node[1] <= x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
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
	
	void update_(size_type i) {
		assert(size() <= i && i < node.size());
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
};

#endif // INCLUDE_GUARD_SEGMENT_TREE_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree.hpp"



#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

TODO: 二分探索の一般化

# 仕様
SegmentTree(size_type n_, const F & f, const_reference id_elem) :
	時間計算量: Θ(n)
	要素数 n_, 二項演算 f, 単位元 id_elem で初期化

void set(size_type i, const_reference x) :
	時間計算量: Θ(log n)
	i 番目の要素に x を代入

void add(size_type i, const_reference x) :
	時間計算量: Θ(lon n)
	i 番目の要素に x を演算する

value_type fold(size_type l, size_type r) const :
	時間計算量: Θ(log n)
	[l, r) を fold した結果を返す

size_type lower_bound(const_reference x) const :
	時間計算量: Θ(log n)
	単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す

size_type upper_bound(const_reference x) const :
	時間計算量: Θ(log n)
	単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

# 参考
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
		node[i += size()] = x;
		update_(i);
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += size();
		node[i] = f(node[i], x);
		update_(i);
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += size(), r += size(); l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
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
		if (node[1] <= x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
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
	
	void update_(size_type i) {
		assert(size() <= i && i < node.size());
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

