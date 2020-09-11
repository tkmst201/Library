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


# :heavy_check_mark: Test/SegmentTree.fold.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SegmentTree.fold.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SegmentTree.hpp.html">DataStructure/SegmentTree.hpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/ModInt.hpp.html">Mathematics/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "DataStructure/SegmentTree.hpp"
#include "Mathematics/ModInt.hpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	
	SegmentTree<pmm> seg(N, [](const pmm & a, const pmm & b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0));
	
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seg.set(i, {a, b});
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			seg.set(a, {b, c});
		}
		else {
			pmm v = seg.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SegmentTree.fold.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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


#line 1 "Mathematics/ModInt.hpp"



#line 5 "Mathematics/ModInt.hpp"
#include <iostream>

/*
last-updated: 2020/02/26

# 仕様
ModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

ModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
ModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static decltype(M) get_mod() noexcept : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const ModInt & rhs) const noexept
operator -(const ModInt & rhs) const noexept
operator *(const ModInt & rhs) const noexept
operator /(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs)
friend std::istream & operator >>(std::istream & is, ModInt & rhs) :
	入出力用

# 参考
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

template<int M>
struct ModInt {
public:
	using value_type = long long;
	
	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }
	ModInt operator +() const noexcept { return ModInt(*this); }
	ModInt operator -() const noexcept { return ModInt(0) -= *this; }
	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }
	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }
	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }
	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }
	
	ModInt & operator +=(const ModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= M) val -= M;
		return *this;
	}
	ModInt & operator -=(const ModInt & rhs) noexcept {
		if (val < rhs.val) val += M;
		val -= rhs.val;
		return *this;
	}
	ModInt & operator *=(const ModInt & rhs) noexcept {
		val = val * rhs.val % M;
		return *this;
	}
	ModInt & operator /=(const ModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	ModInt pow(value_type n) const {
		ModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	ModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;
			a = b; b = r;
			a1 = b1; b1 = nb1;
			a2 = b2; b2 = nb2;
		}
		assert(a == 1);
		return a1;
	}
	
	const value_type & get() const noexcept { return val; }
	static decltype(M) get_mod() noexcept { return M; }
	
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {
		value_type x;
		is >> x;
		rhs = ModInt(x);
		return is;
	}
private:
	value_type val;
};


#line 5 "Test/SegmentTree.fold.test.cpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	
	SegmentTree<pmm> seg(N, [](const pmm & a, const pmm & b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0));
	
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seg.set(i, {a, b});
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			seg.set(a, {b, c});
		}
		else {
			pmm v = seg.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

