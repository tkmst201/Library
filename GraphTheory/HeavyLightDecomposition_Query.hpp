#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP

/*
last-updated: 2020/09/18

森上で 1 点更新, パスクエリや部分木クエリを HL 分解を用いて解いてくれる便利データ構造
頂点属性(頂点に値を持つ), 辺属性(辺に値を持つ) どちらにも対応
パスクエリの場合、演算が非可換でも ok (セグ木も非可換に対応している必要がある)

パス更新の場合は少し変更することで LazySegmentTree を用いて解ける(ハズ)

# 仕様
次の計算量を仮定している
- HeavyLightDecomposition の構築を Θ(n)
- 値の演算を Θ(1)
- SegmentTree:
-- 初期値指定初期化: Θ(n)
-- set, fold: O(log n)
-- get が Θ(1)

template 引数:
	class HLD: HeavyLightDecomposition(Library 内の lca 関連を除く機能を要求)
	typename T: 扱う値の型
	template<typename> class SEG>: T を template 引数に持つ SegmentTree(set, get, fold を要求)

HeavyLightDecomposition_Query(
	const Graph & g: グラフ
	size_type root: グラフが木であるとき、その根(省略可)
	const value_type & id_elem: 単位元
	const F & f : 二項演算
	bool value_on_vertex : 頂点属性かどうか(true - 頂点属性, false - 辺属性) )
	時間計算量: Θ(n)
	グラフ g を HL 分解し、各(頂点 or 辺) の値を単位元 id_elem で初期化

template<typename U>
HeavyLightDecomposition_Query(
	const Graph & g: グラフ
	size_type root: グラフが木であるとき、その根(省略可)
	const std::vector<U> & v: 各頂点の値の初期値
	const value_type & id_elem: 単位元
	const F & f : 二項演算 )
	時間計算量: Θ(n)
	グラフ g を HL 分解し、全ての頂点の値を v で初期化する
	辺属性のコンストラクタ初期化には対応していない

const hld_type & get_hld() const
	時間計算量: Θ(1)
	内部で扱っている HeavyLightDecomposition インスタンスを返す

- 頂点属性
	void set(size_type v, const_reference x)
		時間計算量: O(log n)
		頂点 v の値を x に変更する

	value_type get(size_type v) const
		時間計算量: Θ(1)
		頂点 v の値を返す

- 辺属性
	void set(size_type u, size_type v, const_reference x)
		時間計算量: O(log n)
		辺 u-v の値を x に変更する

	value_type get(size_type u, size_type v) const
		時間計算量: Θ(1)
		辺 u-v の値を返す

value_type fold(size_type u, size_type v) const
	時間計算量: O((log n)^2)
	頂点属性の場合は u-v パス上の頂点(端点含む)の値の fold した値を返す
	辺属性の場合は u-v パス上の辺の値の fold した値を返す

value_type subtree_sum(size_type v) const
	時間計算量: O(log n)
	頂点 v を根とする部分木内の値の合計を求める

# 参考
辺属性 verify(2020/09/18): https://atcoder.jp/contests/abc133/submissions/16817431
*/

#include <vector>
#include <cassert>
#include <functional>
#include <utility>
#include <algorithm>
#include <cstdint>

template<class HLD, typename T, template<typename> class SEG>
struct HeavyLightDecomposition_Query {
	using value_type = T;
	using const_reference = const value_type &;
	using seg_type = SEG<value_type>;
	using hld_type = HLD;
	using size_type = std::uint_fast32_t;
	using Graph = typename hld_type::Graph;
	using F = std::function<value_type(const_reference, const_reference)>;
	
private:
	value_type id_elem;
	F f;
	hld_type hld;
	seg_type seg, rseg;
	bool value_on_vertex;
	
public:
	HeavyLightDecomposition_Query(const Graph & g, const value_type & id_elem, const F & f, bool value_on_vertex)
		: HeavyLightDecomposition_Query(g, g.size(), id_elem, f, value_on_vertex) {}
	
	HeavyLightDecomposition_Query(const Graph & g, size_type root, const value_type & id_elem, const F & f, bool value_on_vertex)
		: id_elem(id_elem), f(f), hld(g, root, false), value_on_vertex(value_on_vertex) {
		seg = seg_type{ hld.bf_size(), id_elem, f };
		rseg = seg_type{ hld.bf_size(), id_elem, f };
	}
	
	template<typename U>
	HeavyLightDecomposition_Query(const Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)
		: HeavyLightDecomposition_Query(g, g.size(), v, id_elem, f) {}
	
	template<typename U>
	HeavyLightDecomposition_Query(const Graph & g, size_type root, const std::vector<U> & v, const value_type & id_elem, const F & f)
		: id_elem(id_elem), f(f), hld(g, root, false), value_on_vertex(true) {
		std::vector<value_type> init(hld.bf_size());
		for (size_type i = 0; i < hld.bf_size(); ++i) init[i] = v[hld.euler_map(i)];
		seg = seg_type{ init, id_elem, f };
		
		for (size_type i = 0; i < hld.af_size(); ++i) {
			const size_type fidx = hld.in(hld.head(i));
			std::reverse(begin(init) + fidx, begin(init) + fidx + hld.heavy_size(i));
		}
		rseg = seg_type{ init, id_elem, f };
	}
	
	const hld_type & get_hld() const {
		return hld;
	}
	
	void set(size_type v, const_reference x) {
		assert(value_on_vertex);
		assert(v < hld.bf_size());
		set_(v, x);
	}
	
	value_type get(size_type v) const {
		assert(value_on_vertex);
		assert(v < hld.bf_size());
		return get_(v);
	}
	
	void set(size_type u, size_type v, const_reference x) {
		assert(!value_on_vertex);
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.par(u) == v || hld.par(v) == u);
		set_(hld.par(u) == v ? u : v, x);
	}
	
	value_type get(size_type u, size_type v) const {
		assert(!value_on_vertex);
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.par(u) == v || hld.par(v) == u);
		return get_(hld.par(u) == v ? u : v);
	}
	
private:
	void set_(size_type v, const_reference x) {
		seg.set(hld.in(v), x);
		rseg.set(reverse_idx(v), x);
	}
	
	value_type get_(size_type v) const {
		return seg.get(hld.in(v));
	}
	
public:
	value_type fold(size_type u, size_type v) const {
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.tree_id(u) == hld.tree_id(v));
		value_type lv = id_elem, rv = id_elem;
		
		while (hld.heavy_map(u) != hld.heavy_map(v)) {
			if (hld.heavy_depth(hld.heavy_map(u)) >= hld.heavy_depth(hld.heavy_map(v))) {
				const size_type head = hld.head(hld.heavy_map(u));
				lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));
				u = hld.par(head);
			}
			if (hld.heavy_map(u) == hld.heavy_map(v)) break;
			if (hld.heavy_depth(hld.heavy_map(u)) <= hld.heavy_depth(hld.heavy_map(v))) {
				const size_type head = hld.head(hld.heavy_map(v));
				rv = f(seg.fold(hld.in(head), hld.in(v) + 1), rv);
				v = hld.par(head);
			}
		}
		
		const size_type id = hld.heavy_map(u);
		if (hld.in(u) < hld.in(v)) rv = f(seg.fold(hld.in(u) + !value_on_vertex, hld.in(v) + 1), rv);
		else lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + value_on_vertex));
		return f(lv, rv);
	}
	
	value_type subtree_sum(size_type v) const {
		return seg.fold(hld.in(v), hld.out(v));
	}
	
private:
	size_type reverse_idx(size_type v) const {
		const size_type id = hld.heavy_map(v);
		return (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP