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


# :heavy_check_mark: Test/LazySegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/LazySegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 13:51:33+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/LazySegmentTree.hpp.html">DataStructure/LazySegmentTree.hpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/ModInt.hpp.html">Mathematics/ModInt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "Mathematics/ModInt.hpp"
#include "DataStructure/LazySegmentTree.hpp"

#include <cstdio>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	
	std::vector<mint> A(N);
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		A[i] = a;
	}
	
	using P = std::pair<mint, mint>; // {first} x + {second}
	
	P id_lazy(1, 0);
	LazySegmentTree<mint, P> seg(A, 0, id_lazy,
		[](auto && a, auto && b) { return a + b; },
		[](auto && a, auto && b) { return b.first * a + b.second; },
		[](auto && a, auto && b) { return std::make_pair(a.first * b.first, a.second * b.first + b.second); },
		[](auto && a, auto && k) { return std::make_pair(a.first, a.second * k); });
	
	while (Q--) {
		int q, l, r;
		scanf("%d %d %d", &q, &l, &r);
		if (q == 0) {
			int b, c;
			scanf("%d %d", &b, &c);
			seg.update(l, r, {b, c});
		}
		else printf("%lld\n", seg.fold(l, r).get());
	}
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/LazySegmentTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#line 1 "Mathematics/ModInt.hpp"



#include <cassert>
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


#line 1 "DataStructure/LazySegmentTree.hpp"



#include <vector>
#line 6 "DataStructure/LazySegmentTree.hpp"
#include <functional>

/*
last-updated: 2020/09/11

遅延伝搬セグメント木

# 仕様
LazySegmentTree(size_type n_, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
	時間計算量: Θ(n)
	要素、作用素の単位元をそれぞれ id_node, id_lazy とし、{n_ 以上の最小の 2 冪} 個の単位元で初期化
	
	関数 f, g, h, p はそれぞれ
		f: 要素の merge
		g: 要素に作用素を作用
		h: 作用素の merge
		p: 区間への作用がその区間の大きさ(k) に比例して変化するとき p(a, k) := g(a, a, \ldots, a) (k 個)
	を表す
	
	g, h, p に関しては必ず伝搬する値が存在するとき(id_lazy ではない) ときのみ呼ばれる。
	
	これらの関数が満たすべき性質は参考欄のリンク先を参照

LazySegmentTree(const std::vector<value_type> & v, const value_type & id_elem, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
	時間計算量: Θ(n)
	配列 v で初期化
	他の引数については上述の通り

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数 n を返す(\neq 内部の要素数)

void update(size_type l, size_type r, const lazy_type & x) :
	時間計算量: O(n)
	[l, r) 内の要素に x を作用させる(遅延)
	l = r のときは何もしない

value_type fold(size_type l, size_type r) :
	時間計算量: O(n)
	[l, r) 内の各要素について fold 演算した結果を返す
	l = r のときは単位元を返す

# 参考
https://beet-aizu.hatenablog.com/entry/2017/12/01/225955, 2020/09/11
*/

template<typename T, typename E>
struct LazySegmentTree {
	using value_type = T;
	using lazy_type = E;
	using size_type = std::size_t;
	using F = std::function<value_type(const value_type &, const value_type &)>; // 要素の merge
	using G = std::function<value_type(const value_type &, const lazy_type &)>; // 要素に作用素を作用
	using H = std::function<lazy_type(const lazy_type &, const lazy_type &)>; // 作用素の merge
	using P = std::function<lazy_type(const lazy_type &, size_type)>; // 区間への作用がその区間の大きさ(k) に比例して変化するとき p(a, k) := g(a, a, ..., a) (k 個)
	
private:
	size_type n;
	F f;
	G g;
	H h;
	P p;
	value_type id_node;
	lazy_type id_lazy;
	std::vector<value_type> node;
	std::vector<lazy_type> lazy;

public:
	LazySegmentTree(size_type n_, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
			: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h), p(p) {
		n = 1;
		while (n < n_) n <<= 1;
		node.resize(2 * n, id_node);
		lazy.resize(2 * n, id_lazy);
	}
	
	LazySegmentTree(const std::vector<value_type> & v, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
			: LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {
		for (size_type i = 0; i < v.size(); ++i) node[i + size()] = v[i];
		for (size_type i = size() - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void update(size_type l, size_type r, const lazy_type & x) {
		if (l == r) return;
		assert(l < r);
		assert(r <= size());
		update(l, r, x, 1, 0, size());
	}
	
	value_type fold(size_type l, size_type r) {
		if (l == r) return id_node;
		assert(l < r);
		assert(r <= size());
		return fold(l, r, 1, 0, size());
	}
	
private:
	void eval(size_type k, size_type l) {
		if (lazy[k] == id_lazy) return;
		if ((k << 1 | 1) < node.size()) {
			lazy[k << 1] = h(lazy[k << 1], lazy[k]);
			lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
		}
		node[k] = g(node[k], p(lazy[k], l));
		lazy[k] = id_lazy;
	}
	
	value_type update(size_type a, size_type b, const lazy_type & x, size_type k, size_type l, size_type r) {
		eval(k, r - l);
		if (l >= b || r <= a) return node[k];
		if (a <= l && r <= b) {
			lazy[k] = h(lazy[k], x);
			return g(node[k], p(lazy[k], r - l));
		}
		return node[k] = f(update(a, b, x, k << 1, l, (l + r) >> 1), update(a, b, x, k << 1 | 1, (l + r) >> 1, r));
	}
	
	value_type fold(size_type a, size_type b, size_type k, size_type l, size_type r) {
		eval(k, r - l);
		if (l >= b || r <= a) return id_node;
		if (a <= l && r <= b) return node[k];
		return f(fold(a, b, k << 1, l, (l + r) >> 1), fold(a, b, k << 1 | 1, (l + r) >> 1, r));
	}
};


#line 5 "Test/LazySegmentTree.test.cpp"

#include <cstdio>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	
	std::vector<mint> A(N);
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		A[i] = a;
	}
	
	using P = std::pair<mint, mint>; // {first} x + {second}
	
	P id_lazy(1, 0);
	LazySegmentTree<mint, P> seg(A, 0, id_lazy,
		[](auto && a, auto && b) { return a + b; },
		[](auto && a, auto && b) { return b.first * a + b.second; },
		[](auto && a, auto && b) { return std::make_pair(a.first * b.first, a.second * b.first + b.second); },
		[](auto && a, auto && k) { return std::make_pair(a.first, a.second * k); });
	
	while (Q--) {
		int q, l, r;
		scanf("%d %d %d", &q, &l, &r);
		if (q == 0) {
			int b, c;
			scanf("%d %d", &b, &c);
			seg.update(l, r, {b, c});
		}
		else printf("%lld\n", seg.fold(l, r).get());
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

