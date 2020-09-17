#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP

/*
last-updated: 2020/09/17

HL 分解
単純な森に対応(自己ループ, 多重辺なし)
lca: 最近共通祖先のこと

# 仕様
HeavyLightDecomposition(const Graph & g, bool use_lca = false)
	時間計算量:
		use_lca = false : Θ(n)
		use_lca = true: Θ(n loglog n)
	
	グラフ g を HL 分解する
	一度渡した g は変更してはいけない
	use_lca = false のときは lca 関連の機能が使えない

size_type bf_size() const noexcept
	時間計算量: Θ(1)
	分解前のグラフの頂点数を返す

size_type af_size() const noexcept
	時間計算量: Θ(1)
	分解後のグラフの頂点数を返す

size_type heavy_size(size_type k) const
	時間計算量: Θ(1)
	heavy-path k に属する頂点数を返す

size_type tree_cnt() const noexcept
	時間計算量: Θ(1)
	分解前のグラフに含まれている木の個数を返す

const std::vector<size_type> & trees() const noexcept
	時間計算量: Θ(1)
	分解前のグラフに含まれている木の根のリストを返す

const std::vector<size_type> & operator [](size_type k) const noexcept
	時間計算量: Θ(1)
	分解後のグラフで heavy-path k に属する、分解前のグラフの頂点のリストを返す
	添字の out-of-range 判定は行わない

size_type at(size_type i, size_type j) const
	時間計算量: Θ(1)
	分解前のグラフで heavy-path i の index j の頂点を返す

size_type par(size_type k) const
	時間計算量: Θ(1)
	分解前のグラフで頂点 k の親を返す(k が根なら k を返す)

size_type heavy_map(size_type k) const
	時間計算量: Θ(1)
	分解前のグラフの頂点 k が属する heavy-path id

size_type idx_map(size_type k) const
	時間計算量: Θ(1)
	分解前のグラフの頂点 k が属する heavy-path 内の index を返す

size_type tree_id(size_type k) const
	時間計算量: Θ(1)
	分解前のグラフで頂点 k が属する木の id を返す

size_type heavy_depth(size_type k) const
	時間計算量: Θ(1)
	分解後のグラフで heavy-path k の根からの深さ(0-indexed, \leq log n) を返す

const std::vector<std::vector<size_type>> & par_dblng() const
	時間計算量: Θ(1)
	use_lca = true である必要がある
	次のような 2 次元配列を返す
	[k][i] := 分解前のグラフで heavy-path i から2^k 回 heavy-path を上ったとき、最初に到達する頂点番号

std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const
	時間計算量: O(loglog n)
	use_lca = true である必要がある
	分解前のグラフの頂点 x, y が属する分解後の列の lca 列を L とする
	x, y が分解前のグラフで列 L に属する頂点に到達するまで上ったときに初めて到達する列 L の頂点の組を返す

size_type get_lca(size_type x, size_type y) const
	時間計算量: O(loglog n)
	use_lca = true である必要がある
	分解前のグラフで頂点 x, y の lca を返す

# 参考
https://qiita.com/ageprocpp/items/8dfe768218da83314989, 2020/04/19
https://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19
*/

#include <vector>
#include <utility>
#include <cassert>
#include <stack>
#include <algorithm>
#include <cstdint>

struct HeavyLightDecomposition {
	using size_type = std::uint_fast32_t;
	using Graph = std::vector<std::vector<size_type>>;
	
private:
	size_type bf_n; // 分解前の頂点数
	std::vector<size_type> roots; // 各木の根
	std::vector<size_type> par_; // 分解前の頂点 i の親頂点(頂点 i が根の場合は自分自身)
	std::vector<std::vector<size_type>> ver_info; // i 番目の heavy-path に含まれる分解前の頂点番号(index が大きいほど根側)
	std::vector<size_type> heavy_map_; // 分解後において、分解前の頂点 i が属する heavy-path
	std::vector<size_type> idx_map_; // 分解後において、分解前の頂点 i が属する heavy-path 内の index
	std::vector<size_type> tree_id_; // 分解前の頂点 i が属する木の番号
	std::vector<size_type> heavy_depth_; // [i] := heavy-path i の根からの深さ(0-indexed)
	std::vector<std::vector<size_type>> par_dblng_; // [k][i] := 分解前で heavy-path i から2^k 回 heavy-path を上ったとき、最初に到達する頂点番号
	
public:
	HeavyLightDecomposition(const Graph & g, bool use_lca = false) : bf_n(g.size()) {
		par_.assign(bf_size(), bf_size());
		heavy_map_.assign(bf_size(), bf_size());
		idx_map_.assign(bf_size(), bf_size());
		tree_id_.assign(bf_size(), bf_size());
		
		std::vector<size_type> sub_size(bf_size());
		size_type tree_cnt = 0;
		for (size_type i = 0; i < bf_size(); ++i) {
			if (tree_id_[i] != bf_size()) continue;
			std::stack<std::pair<size_type, size_type>> stk;
			stk.emplace(i, 0);
			par_[i] = i;
			tree_id_[i] = roots.size();
			
			while (!stk.empty()) {
				const size_type u = stk.top().first;
				const size_type j = stk.top().second;
				stk.pop();
				
				if (j < g[u].size()) {
					const size_type v = g[u][j];
					stk.emplace(u, j + 1);
					if (v == par_[u]) continue;
					par_[v] = u;
					tree_id_[v] = tree_cnt;
					stk.emplace(v, 0);
				}
				else {
					sub_size[u] = 1;
					size_type mx_size = 0, mx_idx = u;
					for (size_type v : g[u]) {
						if (v == par_[u]) continue;
						sub_size[u] += sub_size[v];
						if (mx_size < sub_size[v]) {
							mx_size = sub_size[v];
							mx_idx = v;
						}
					}
					if (sub_size[u] == 1) {
						heavy_map_[u] = ver_info.size();
						idx_map_[u] = 0;
						ver_info.emplace_back();
						heavy_depth_.emplace_back();
					}
					else {
						heavy_map_[u] = heavy_map_[mx_idx];
						idx_map_[u] = idx_map_[mx_idx] + 1;
					}
					ver_info[heavy_map_[mx_idx]].emplace_back(u);
				}
			}
			
			stk.emplace(i, 0);
			heavy_depth_[heavy_map_[i]] = 0;
			while (!stk.empty()) {
				const size_type u = stk.top().first;
				const size_type j = stk.top().second;
				stk.pop();
				if (j < g[u].size()) {
					stk.emplace(u, j + 1);
					const size_type v = g[u][j];
					if (v == par_[u]) continue;
					if (heavy_map_[u] != heavy_map_[v]) heavy_depth_[heavy_map_[v]] = heavy_depth_[heavy_map_[u]] + 1;
					stk.emplace(v, 0);
				}
			}
			roots.emplace_back(i);
		}
		sub_size.clear();
		
		if (!use_lca) return;
		size_type max_depth = *std::max_element(begin(heavy_depth_), end(heavy_depth_));
		size_type lglg_n = 0;
		while ((1 << lglg_n) < max_depth) ++lglg_n;
		
		par_dblng_.assign(lglg_n + 1, std::vector<size_type>(ver_info.size(), bf_size()));
		for (size_type i = 0; i < ver_info.size(); ++i) par_dblng_[0][i] = par_[ver_info[i].back()];
		
		for (size_type i = 0; i < lglg_n; ++i) {
			for (size_type j = 0; j < ver_info.size(); ++j) {
				par_dblng_[i + 1][j] = par_dblng_[i][heavy_map_[par_dblng_[i][j]]];
			}
		}
	}
	
	size_type bf_size() const noexcept { return bf_n; }
	size_type af_size() const noexcept { return ver_info.size(); }
	size_type heavy_size(size_type k) const { assert(k < af_size()); return ver_info[k].size(); }
	size_type tree_cnt() const noexcept { return roots.size(); }
	const std::vector<size_type> & trees() const noexcept { return roots; }
	const std::vector<size_type> & operator [](size_type k) const noexcept { return ver_info[k]; }
	size_type at(size_type i, size_type j) const {
		assert(i < af_size());
		assert(j < ver_info[i].size());
		return ver_info[i][j];
	}
	size_type par(size_type k) const { assert(k < bf_size()); return par_[k]; }
	size_type heavy_map(size_type k) const { assert(k < bf_size()); return heavy_map_[k]; }
	size_type idx_map(size_type k) const { assert(k < bf_size()); return idx_map_[k]; }
	size_type tree_id(size_type k) const { assert(k < bf_size()); return tree_id_[k]; }
	size_type heavy_depth(size_type k) const { assert(k < af_size()); return heavy_depth_[k]; }
	const std::vector<std::vector<size_type>> & par_dblng() const {
		assert(!par_dblng_.empty());
		return par_dblng_;
	}
	
	std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const {
		assert(!par_dblng_.empty());
		assert(x < bf_size());
		assert(y < bf_size());
		assert(tree_id_[x] == tree_id_[y]);
		if (heavy_map_[x] == heavy_map_[y]) return {x, y};
		
		bool isswap = heavy_depth_[heavy_map_[x]] < heavy_depth_[heavy_map_[y]];
		if (isswap) std::swap(x, y);
		
		const size_type diff = heavy_depth_[heavy_map_[x]] - heavy_depth_[heavy_map_[y]];
		for (size_type i = par_dblng_.size(); i > 0; --i) {
			if (diff >> (i - 1) & 1) x = par_dblng_[i - 1][heavy_map_[x]];
		}
		if (heavy_map_[x] == heavy_map_[y]) return isswap ? std::make_pair(y, x) : std::make_pair(x, y);
		
		for (size_type i = par_dblng_.size(); i > 0; --i) {
			const size_type p1 = par_dblng_[i - 1][heavy_map_[x]], p2 = par_dblng_[i - 1][heavy_map_[y]];
			if (heavy_map_[p1] != heavy_map_[p2]) x = p1, y = p2;
		}
		x = par_dblng_[0][heavy_map_[x]];
		y = par_dblng_[0][heavy_map_[y]];
		return isswap ? std::make_pair(y, x) : std::make_pair(x, y);
	}
	
	size_type get_lca(size_type x, size_type y) const {
		assert(!par_dblng_.empty());
		assert(x < bf_size());
		assert(y < bf_size());
		std::pair<size_type, size_type> res = get_lca_path(x, y);
		return ver_info[heavy_map_[res.first]][std::max(idx_map_[res.first], idx_map_[res.second])];
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP