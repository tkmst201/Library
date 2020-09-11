#ifndef INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP

#include <vector>
#include <cassert>
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

#endif // INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP