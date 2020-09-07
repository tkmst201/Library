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


# :heavy_check_mark: DataStructure/BinaryIndexedTree_RangeAdd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryIndexedTree_RangeAdd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/BinaryIndexedTree_RangeAdd.test.cpp.html">Test/BinaryIndexedTree_RangeAdd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP
#define INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP

#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

BIT を用いた区間加算が行えるデータ構造

# 仕様
template<typename T, template<typename> class U> :
	T: 各要素のデータ型
	U: BinaryIndexedTree
	ex. BinaryIndexedTree_RangeAdd<long long, BinaryIndexedTree> bit(...)

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数を取得

void add(size_type l, size_type r, const_reference x) :
	時間計算量: Θ(log n)
	区間 [l, r) に一様に値 x を加算

value_type sum(size_type i) :
	時間計算量: Θ(log n)
	区間 [0, i) の合計を取得

value_type sum(size_type l, size_type r) :
	時間計算量: Θ(log n)
	区間 [l, r) の合計を取得

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T, template<typename> class U>
struct BinaryIndexedTree_RangeAdd {
	using bit_type = U<T>;
	using value_type = typename bit_type::value_type;
	using const_reference = typename bit_type::const_reference;
	using size_type = typename bit_type::size_type;
	
	BinaryIndexedTree_RangeAdd(size_type n) : n(n) {
		bit.resize(2, bit_type(n, [](auto && x, auto && y) { return x + y; }, 0));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	// [l, r) += x
	void add(size_type l, size_type r, const_reference x) {
		assert(l < r);
		assert(r <= size());
		bit[0].add(l, x);
		bit[0].add(r - 1, -x);
		bit[1].add(l, -x * (static_cast<value_type>(l) - 1));
		bit[1].add(r - 1, x * (r - 1));
	}
	
	// \Sum_{ k = [0, i) } a_k
	value_type sum(size_type i) {
		assert(i <= size());
		return bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);
	}
	
	// \Sum_{ k = [l, r) } a_k
	value_type sum(size_type l, size_type r) {
		assert(l < r);
		assert(r <= size());
		return sum(r) - sum(l);
	}
	
private:
	size_type n;
	std::vector<bit_type> bit;
};

#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryIndexedTree_RangeAdd.hpp"



#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

BIT を用いた区間加算が行えるデータ構造

# 仕様
template<typename T, template<typename> class U> :
	T: 各要素のデータ型
	U: BinaryIndexedTree
	ex. BinaryIndexedTree_RangeAdd<long long, BinaryIndexedTree> bit(...)

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数を取得

void add(size_type l, size_type r, const_reference x) :
	時間計算量: Θ(log n)
	区間 [l, r) に一様に値 x を加算

value_type sum(size_type i) :
	時間計算量: Θ(log n)
	区間 [0, i) の合計を取得

value_type sum(size_type l, size_type r) :
	時間計算量: Θ(log n)
	区間 [l, r) の合計を取得

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T, template<typename> class U>
struct BinaryIndexedTree_RangeAdd {
	using bit_type = U<T>;
	using value_type = typename bit_type::value_type;
	using const_reference = typename bit_type::const_reference;
	using size_type = typename bit_type::size_type;
	
	BinaryIndexedTree_RangeAdd(size_type n) : n(n) {
		bit.resize(2, bit_type(n, [](auto && x, auto && y) { return x + y; }, 0));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	// [l, r) += x
	void add(size_type l, size_type r, const_reference x) {
		assert(l < r);
		assert(r <= size());
		bit[0].add(l, x);
		bit[0].add(r - 1, -x);
		bit[1].add(l, -x * (static_cast<value_type>(l) - 1));
		bit[1].add(r - 1, x * (r - 1));
	}
	
	// \Sum_{ k = [0, i) } a_k
	value_type sum(size_type i) {
		assert(i <= size());
		return bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);
	}
	
	// \Sum_{ k = [l, r) } a_k
	value_type sum(size_type l, size_type r) {
		assert(l < r);
		assert(r <= size());
		return sum(r) - sum(l);
	}
	
private:
	size_type n;
	std::vector<bit_type> bit;
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

