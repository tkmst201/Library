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


# :heavy_check_mark: Test/BinaryIndexedTree_RangeAdd.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/BinaryIndexedTree_RangeAdd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 23:22:28+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/BinaryIndexedTree.cpp.html">DataStructure/BinaryIndexedTree.cpp</a>
* :heavy_check_mark: <a href="../../library/DataStructure/BinaryIndexedTree_RangeAdd.cpp.html">DataStructure/BinaryIndexedTree_RangeAdd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "DataStructure/BinaryIndexedTree.cpp"
#include "DataStructure/BinaryIndexedTree_RangeAdd.cpp"

#include <cstdio>
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	using ll = long long;
	
	BinaryIndexedTree_RangeAdd<ll, BinaryIndexedTree> bit(n);
	while (q--) {
		int query, s, t;
		scanf("%d %d %d", &query, &s, &t);
		--s;
		if (query == 0) {
			int x;
			scanf("%d", &x);
			bit.add(s, t, x);
		}
		else {
			printf("%lld\n", bit.sum(s, t));
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/BinaryIndexedTree_RangeAdd.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#line 1 "DataStructure/BinaryIndexedTree.cpp"
#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

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
	
	BinaryIndexedTree(size_type n, const F & f, const_reference id_elem) : n(n), f(f), id_elem(id_elem) {
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
	
	// sum[0, r] <= x を満たす最小の r を返す (存在しなければ size())
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
#line 4 "DataStructure/BinaryIndexedTree_RangeAdd.cpp"

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
#line 5 "Test/BinaryIndexedTree_RangeAdd.test.cpp"

#include <cstdio>
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	using ll = long long;
	
	BinaryIndexedTree_RangeAdd<ll, BinaryIndexedTree> bit(n);
	while (q--) {
		int query, s, t;
		scanf("%d %d %d", &query, &s, &t);
		--s;
		if (query == 0) {
			int x;
			scanf("%d", &x);
			bit.add(s, t, x);
		}
		else {
			printf("%lld\n", bit.sum(s, t));
		}
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

