#ifndef INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP

/*
last-updated: 2020/09/16

遅延伝搬セグメント木

TODO: 一般化された二分探索の追加(verify 用問題 is どこ)

# 仕様
LazySegmentTree(
	size_type n, const value_type & id_node, const lazy_type & id_lazy,
	const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
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

size_type size() const noexcept
	時間計算量: Θ(1)
	要素数 n を返す(\neq 内部の要素数)

void set(size_type k, const_reference x)
	時間計算量: O(log n)
	k 番目(0 \leq k < n) の要素に x を代入する
	TODO: verify LazySegmentTree set()

value_type get(size_type k)
	時間計算量: O(log n)
	k 番目(0 \leq k < n) の要素を返す
	TODO: verify LazySegmentTree get()

void update(size_type l, size_type r, const lazy_type & x)
	時間計算量: O(log n)
	[l, r) 内(0 \leq l \leq r \leq n) の要素に x を作用させる(遅延)
	l = r のときは何もしない

value_type fold(size_type l, size_type r)
	時間計算量: O(log n)
	[l, r) 内(0 \leq l \leq r \leq n) の各要素について fold 演算した結果を返す
	l = r のときは単位元を返す

value_type fold_all() const
	時間計算量: Θ(1)
	fold(0, n) を返す
	TODO: verify LazySegmentTree fold_all()

private:
value_type reflect(size_type k, size_type w)
	時間計算量: Θ(1)
	ノード k (対応する区間の大きさを w) に作用素を作用させた後の値を返す

void propagate(size_type k, size_type w)
	時間計算量: Θ(1)
	ノード k (対応する区間の大きさを w) の子に作用素を伝搬し、自身に作用させて更新

void recalc(size_type k)
	時間計算量: Θ(log n)
	要素 k の先祖が伝搬済みだと仮定して先祖の値を再計算する
	要素 k の値は変化しない

void thrust(size_type k)
	時間計算量: Θ(log n)
	根から要素 k まで作用を伝搬してくる
	要素 k の値は変化しない

# 参考
https://beet-aizu.hatenablog.com/entry/2017/12/01/225955, 2020/09/11
https://smijake3.hatenablog.com/entry/2018/11/03/100133, 2020/09/16
https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html, 2020/09/16
*/

#include <vector>
#include <cassert>
#include <functional>

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
	size_type n, n_, n_log;
	value_type id_node;
	lazy_type id_lazy;
	F f;
	G g;
	H h;
	P p;
	std::vector<value_type> node;
	std::vector<lazy_type> lazy;

public:
	LazySegmentTree(size_type n, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
			: n(n), id_node(id_node), id_lazy(id_lazy), f(f), g(g), h(h), p(p) {
		n_ = 1;
		n_log = 0;
		while (n_ < n) n_ <<= 1, ++n_log;
		node.resize(2 * n_, id_node);
		lazy.resize(2 * n_, id_lazy);
	}
	
	LazySegmentTree(const std::vector<value_type> & v, const value_type & id_node, const lazy_type & id_lazy, const F & f, const G & g, const H & h, const P & p = [](const lazy_type & a, size_type l) { return a; })
			: LazySegmentTree(v.size(), id_node, id_lazy, f, g, h, p) {
		for (size_type i = 0; i < v.size(); ++i) node[i + n_] = v[i];
		for (size_type i = n_ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type k, const value_type & x) {
		assert(k < size());
		k += n_;
		thrust(k);
		node[k] = x;
		lazy[k] = id_lazy;
		recalc(k);
	}
	
	value_type get(size_type k) {
		assert(k < size());
		k += n_;
		thrust(k);
		return reflect(k, 1);
	}
	
	void update(size_type l, size_type r, const lazy_type & x) {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return;
		l += n_;
		r += n_;
		thrust(l);
		thrust(r - 1);
		for(size_type cl = l, cr = r; cl < cr; cl >>= 1, cr >>= 1) {
			if (cl & 1) lazy[cl] = h(lazy[cl], x), ++cl;
			if (cr & 1) --cr, lazy[cr] = h(lazy[cr], x);
		}
		recalc(l);
		recalc(r - 1);
		return;
	}
	
	value_type fold(size_type l, size_type r) {
		assert(l <= r);
		assert(r <= size());
		if (l == r) return id_node;
		l += n_;
		r += n_;
		thrust(l);
		thrust(r - 1);
		value_type vl = id_node, vr = id_node;
		for (size_type w = 1; l < r; l >>= 1, r >>= 1, w <<= 1) {
			if (l & 1) vl = f(vl, reflect(l, w)), ++l;
			if (r & 1) --r, vr = f(reflect(r, w), vr);
		}
		return f(vl, vr);
	}
	
	value_type fold_all() const {
		return node[1];
	}
	
private:
	value_type reflect(size_type k, size_type w) {
		return lazy[k] == id_lazy ? node[k] : g(node[k], p(lazy[k], w));
	}
	
	void propagate(size_type k, size_type w) {
		if (lazy[k] == id_lazy) return;
		if ((k << 1 | 1) < node.size()) {
			lazy[k << 1] = h(lazy[k << 1], lazy[k]);
			lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
		}
		node[k] = reflect(k, w); // g(node[k], p(lazy[k], l));
		lazy[k] = id_lazy;
	}
	
	void recalc(size_type k) {
		for (size_type i = k >> 1, cw = 1; i > 0; i >>= 1, cw <<= 1)
			node[i] = f(reflect(i << 1, cw), reflect(i << 1 | 1, cw));
	}
	
	void thrust(size_type k) {
		for (size_type i = n_log, w = n_; i > 0; --i, w >>= 1) propagate(k >> i, w);
	}
};

#endif // INCLUDE_GUARD_LAZY_SEGMENT_TREE_HPP