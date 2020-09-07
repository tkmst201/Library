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


# :x: DataStructure/UnionFind.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :x: <a href="../../verify/Test/UnionFind.test.cpp.html">Test/UnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_UNION_FIND_HPP
#define INCLUDE_GUARD_UNION_FIND_HPP

#include <vector>
#include <numeric>
#include <utility>
#include <cassert>

/*
last-updated: 2020/04/22

size() verify : https://atcoder.jp/contests/abc157/submissions/12223429

# 仕様
UnionFind(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

size_type size(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの要素数を返す

size_type find(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの代表番号を返す

void unite(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y がそれぞれ属するグループを併合する

bool issame(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y が同一グループに属するかを返す

# 参考
https://en.wikipedia.org/wiki/Disjoint-set_data_structure, 2020/04/22
https://qiita.com/kopricky/items/3e5847ab1451fe990367, 2020/04/22
*/

struct UnionFind {
public:
	using size_type = std::size_t;
	
	UnionFind(size_type n) : n(n), size_(n, 1) {
		par.resize(n);
		std::iota(par.begin(), par.end(), 0);
	}
	
	size_type size(size_type x) { return size_[find(x)]; }
	
	size_type find(size_type x) {
		assert(x < n);
		while (par[x] != x) {
			par[x] = par[par[x]];
			x = par[x];
		}
		return x;
	}
	
	void unite(size_type x, size_type y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (size(x) > size(y)) std::swap(x, y);
		par[x] = y;
		size_[y] += size_[x];
	}
	
	bool issame(size_type x, size_type y) { return find(x) == find(y); }
	
private:
	size_type n;
	std::vector<size_type> size_, par;
};


#endif // INCLUDE_GUARD_UNION_FIND_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind.hpp"



#include <vector>
#include <numeric>
#include <utility>
#include <cassert>

/*
last-updated: 2020/04/22

size() verify : https://atcoder.jp/contests/abc157/submissions/12223429

# 仕様
UnionFind(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

size_type size(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの要素数を返す

size_type find(size_type x) :
	時間計算量: O(α(n))
	要素 x が属するグループの代表番号を返す

void unite(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y がそれぞれ属するグループを併合する

bool issame(size_type x, size_type y) :
	時間計算量: O(α(n))
	要素 x, y が同一グループに属するかを返す

# 参考
https://en.wikipedia.org/wiki/Disjoint-set_data_structure, 2020/04/22
https://qiita.com/kopricky/items/3e5847ab1451fe990367, 2020/04/22
*/

struct UnionFind {
public:
	using size_type = std::size_t;
	
	UnionFind(size_type n) : n(n), size_(n, 1) {
		par.resize(n);
		std::iota(par.begin(), par.end(), 0);
	}
	
	size_type size(size_type x) { return size_[find(x)]; }
	
	size_type find(size_type x) {
		assert(x < n);
		while (par[x] != x) {
			par[x] = par[par[x]];
			x = par[x];
		}
		return x;
	}
	
	void unite(size_type x, size_type y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (size(x) > size(y)) std::swap(x, y);
		par[x] = y;
		size_[y] += size_[x];
	}
	
	bool issame(size_type x, size_type y) { return find(x) == find(y); }
	
private:
	size_type n;
	std::vector<size_type> size_, par;
};




```
{% endraw %}

<a href="../../index.html">Back to top page</a>

