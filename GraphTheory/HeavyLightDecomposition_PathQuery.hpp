#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP

/*
last-updated: 2020/09/17

森上で 1 点更新, パスクエリを HL 分解を用いて解いてくれる便利データ構造
頂点属性(頂点に値を持つ), 辺属性(辺に値を持つ) どちらにも対応
演算が非可換でも ok (セグ木も非可換に対応している必要がある)

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
	class HLD: HeavyLightDecomposition(Library 内の lca 関連を除く機能を要求, heavy-path では index が大きいほど根側)
	typename T: 扱う値の型
	template<typename> class SEG>: T を template 引数に持つ SegmentTree(set, get, fold を要求)

HeavyLightDecomposition_PathQuery(
	const Graph & g: グラフ
	const value_type & id_elem: 単位元
	const F & f : 二項演算
	bool value_on_vertex : 頂点属性かどうか(true - 頂点属性, false - 辺属性) )
	時間計算量: Θ(n)
	HL 分解を行い各(頂点 or 辺) の値を単位元 id_elem で初期化

HeavyLightDecomposition_PathQuery(
	const Graph & g: グラフ
	const std::vector<value_type> & v: 各頂点の値の初期値
	const value_type & id_elem: 単位元
	const F & f : 二項演算 )
	時間計算量: Θ(n)
	HL 分解を行い、全ての頂点の値を v で初期化する
	辺属性でコンストラクタ初期化には対応していない

const hld_type & get_hld() const
	時間計算量: Θ(1)
	内部で扱っている HeavyLightDecomposition 結果を返す

- 頂点属性
	void set(size_type k, const_reference x)
		時間計算量: O(log n)
		頂点 k の値を x に変更する

	value_type get(size_type k) const
		時間計算量: Θ(1)
		頂点 k の値を返す

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

# 参考
辺属性 verify(2020/09/17): https://atcoder.jp/contests/abc133/submissions/16798090
*/

#include <vector>
#include <cassert>
#include <functional>
#include <utility>
#include <algorithm>
#include <cstdint>

template<class HLD, typename T, template<typename> class SEG>
struct HeavyLightDecomposition_PathQuery {
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
	std::vector<seg_type> seg, rseg;
	bool value_on_vertex;
	
public:
	HeavyLightDecomposition_PathQuery(const Graph & g, const value_type & id_elem, const F & f, bool value_on_vertex)
		: id_elem(id_elem), f(f), hld(g), value_on_vertex(value_on_vertex) {
		seg.reserve(hld.af_size());
		rseg.reserve(hld.af_size());
		for (size_type i = 0; i < hld.af_size(); ++i) {
			seg.emplace_back(hld.heavy_size(i), id_elem, f);
			rseg.emplace_back(hld.heavy_size(i), id_elem, f);
		}
	}
	
	HeavyLightDecomposition_PathQuery(const Graph & g, const std::vector<value_type> & v, const value_type & id_elem, const F & f)
		: id_elem(id_elem), f(f), hld(g), value_on_vertex(true) {
		seg.reserve(hld.af_size());
		rseg.reserve(hld.af_size());
		for (size_type i = 0; i < hld.af_size(); ++i) {
			std::vector<value_type> init;
			init.reserve(hld.heavy_size(i));
			for (size_type j = 0; j < hld.heavy_size(i); ++j) init.emplace_back(v[hld[i][j]]);
			seg.emplace_back(init, id_elem, f);
			std::reverse(begin(init), end(init));
			rseg.emplace_back(init, id_elem, f);
		}
	}
	
	const hld_type & get_hld() const {
		return hld;
	}
	
	void set(size_type k, const_reference x) {
		assert(value_on_vertex);
		assert(k < hld.bf_size());
		set_(k, x);
	}
	
	void set(size_type u, size_type v, const_reference x) {
		assert(!value_on_vertex);
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.par(u) == v || hld.par(v) == u);
		set_(hld.par(u) == v ? u : v, x);
	}
	
	value_type get(size_type k) const {
		assert(value_on_vertex);
		assert(k < hld.bf_size());
		return seg[hld.heavy_map(k)].get(hld.idx_map(k));
	}
	
	value_type get(size_type u, size_type v) const {
		assert(!value_on_vertex);
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.par(u) == v || hld.par(v) == u);
		return get_(hld.par(u) == v ? u : v);
	}
	
private:
	void set_(size_type k, const_reference x) {
		const size_type heavy_id = hld.heavy_map(k);
		const size_type heavy_idx = hld.idx_map(k);
		seg[heavy_id].set(heavy_idx, x);
		rseg[heavy_id].set(hld.heavy_size(heavy_id) - 1 - heavy_idx, x);
	}
	
	value_type get_(size_type k) const {
		return seg[hld.heavy_map(k)].get(hld.idx_map(k));
	}
	
public:
	value_type fold(size_type u, size_type v) const {
		assert(u < hld.bf_size());
		assert(v < hld.bf_size());
		assert(hld.tree_id(u) == hld.tree_id(v));
		value_type lv = id_elem, rv = id_elem;
		
		while (hld.heavy_map(u) != hld.heavy_map(v)) {
			if (hld.heavy_depth(hld.heavy_map(u)) >= hld.heavy_depth(hld.heavy_map(v))) {
				const size_type heavy_id = hld.heavy_map(u);
				const size_type heavy_size = hld.heavy_size(heavy_id);
				lv = f(lv, seg[heavy_id].fold(hld.idx_map(u), heavy_size));
				u = hld.par(hld[heavy_id][heavy_size - 1]);
			}
			if (hld.heavy_map(u) == hld.heavy_map(v)) break;
			if (hld.heavy_depth(hld.heavy_map(u)) <= hld.heavy_depth(hld.heavy_map(v))) {
				const size_type heavy_id = hld.heavy_map(v);
				const size_type heavy_size = hld.heavy_size(heavy_id);
				rv = f(rseg[heavy_id].fold(0, heavy_size - hld.idx_map(v)), rv);
				v = hld.par(hld[heavy_id][heavy_size - 1]);
			}
		}
		
		const size_type heavy_id = hld.heavy_map(u);
		if (hld.idx_map(u) < hld.idx_map(v)) lv = f(lv, seg[heavy_id].fold(hld.idx_map(u), hld.idx_map(v) + value_on_vertex));
		else rv = f(rseg[heavy_id].fold(hld.heavy_size(heavy_id) - hld.idx_map(u) - value_on_vertex, hld.heavy_size(heavy_id) - hld.idx_map(v)), rv);
		return f(lv, rv);
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_PATH_QUERY_HPP