#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP

/*
last-updated: 2020/09/18

HL 分解 + EulerTour
単純な森に対応(自己ループ, 多重辺なし)

# 用語
lca: 最近共通祖先
heavy-path: heavy-edge のみ通って移動可能な頂点集合

# 解説
dfs する際に heavy-edge を優先して通るようにすると、同一 heavy-path 内の頂点の EulerTour 順が連続する

頂点 v から同一 heavy-path 内で根に上ったときに通る頂点は 区間 [ in[head[heavy_map[v]], in[v] ] に対応
部分木 v 内の頂点は [in[v], out[v]) に対応

HL 分解でパスクエリ、部分木クエリの両方を捌けるようになる

パスクエリでアーベル群なら EulerTour 単体を使おう( HL 分解では log が 1 つ多い)

# 仕様
HeavyLightDecomposition(const Graph & g, bool use_lca = false)
	時間計算量:
		use_lca = false : Θ(n)
		use_lca = true: Θ(n loglog n)
	
	グラフ g を HL 分解する
	一度渡した g は変更してはいけない
	use_lca = false のときは lca 関連の機能が使えない

HeavyLightDecomposition(const Graph & g, size_type root, bool use_lca)
	時間計算量: 上と同一
	グラフ g が木であるとき、根を root として HL 分解を行う
	部分木クエリを処理したいときに必要

std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const
	時間計算量: O(loglog n)
	use_lca = true である必要がある
	分解前のグラフの頂点 x, y が属する heavy-path の lca heavy-path を L とする
	頂点 x, y が heavy-path L に属する頂点に到達するまで上ったときに初めて到達する頂点の組を返す

size_type get_lca(size_type x, size_type y) const
	時間計算量: O(loglog n)
	use_lca = true である必要がある
	頂点 x, y の lca を返す

以下、全て 時間計算量 Θ(1)

size_type bf_size() const noexcept: グラフの頂点数を返す
size_type af_size() const noexcept: heavy-path の個数を返す

size_type par(size_type v) const: 頂点 v の親を返す(k が根なら k を返す)
size_type sub_size(size_type v) const: 頂点 v を根とする部分木に属する頂点数を返す
size_type depth(size_type v) const: 頂点 v の根からの距離(0-indexed)を返す

size_type tree_id(size_type v) const: 頂点 v が属する木の id を返す
size_type tree_cnt() const noexcept: グラフ g に含まれている木の個数を返す
const std::vector<size_type> & trees() const noexcept: グラフ g に含まれている木の根のリストを返す

size_type heavy_map(size_type v) const: 頂点 v が属する heavy-path id を返す
size_type head(size_type k) const: heavy-path k 内の最も根に近い頂点(= EulerTour 順で最小) を返す
size_type heavy_size(size_type k) const: heavy-path k に属する頂点数を返す
size_type heavy_depth(size_type k) const: heavy-path k から根までに通る light-edge の個数を返す

size_type in(size_type v) const: 頂点 v の EulerTour 順序(同一 heavy-path 内では連続) を返す
size_typsize_type out(size_type v) conste in(size_type v) const: 頂点 v から出るときの EulerTour 順序
size_type euler_map(size_type k) const: EulerTour 順序が i であるような頂点を返す

const std::vector<std::vector<size_type>> & par_dblng() const
	use_lca = true である必要がある
	次のような 2 次元配列を返す
	[k][i] := heavy-path i から 2^k 回 light-edge を上ったとき、最初に到達する頂点


# 参考
https://qiita.com/ageprocpp/items/8dfe768218da83314989, 2020/04/19
https://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19
https://codeforces.com/blog/entry/53170, 2020/09/18
*/

#include <vector>
#include <cassert>
#include <cstdint>
#include <stack>
#include <utility>
#include <algorithm>

struct HeavyLightDecomposition {
	using size_type = std::uint_fast32_t;
	using Graph = std::vector<std::vector<size_type>>;
	
private:
	size_type bf_n; // グラフの頂点数
	
	std::vector<size_type> par_; // [v] := 頂点 v の親の頂点番号(存在しなければ自分自身)
	std::vector<size_type> sub_size_; // [v] := 頂点 v を根とする部分木のサイズ
	std::vector<size_type> depth_; // [v] := 頂点 v の元のグラフでの深さ
	
	std::vector<size_type> tree_id_; // [v] := 頂点 v が属する木の id
	std::vector<size_type> roots_; // [i] := i 番目の木の root
	
	std::vector<size_type> heavy_map_; // [v] := 頂点 v が属する heavy-path id
	std::vector<size_type> head_; // [i] := heavy-path i の最も根に近い頂点番号
	std::vector<size_type> heavy_size_ ; // [i] := heavy-path i に属する頂点の個数
	std::vector<size_type> heavy_depth_; // [i] := heavy-path i から根までに通る light-edge の個数
	
	// euler-tour
	std::vector<size_type> in_; // [v] := 頂点 v の EulerTour 順序(同一 heavy-path 内では連続)
	std::vector<size_type> out_; // [v] := 頂点 v から出るときの EulerTour 順序
	std::vector<size_type> euler_map_; // [i] := EulerTour 順序が i であるような頂点
	
	// heavy-path doubling
	std::vector<std::vector<size_type>> par_dblng_; // [k][i] := heavy-path i から 2^k 回 light-edge を上った先の頂点
	
public:
	HeavyLightDecomposition(const Graph & g, bool use_lca = false) : HeavyLightDecomposition(g, g.size(), use_lca) {}
	HeavyLightDecomposition(const Graph & g, size_type root, bool use_lca) : bf_n(g.size()) {
		par_.resize(bf_size());
		sub_size_.resize(bf_size());
		depth_.resize(bf_size());
		tree_id_.assign(bf_size(), bf_size());
		std::vector<size_type> next(bf_size()); // [v] := 頂点 v と同一 heavy-path 内で v より 1 つ葉側の頂点(存在しなければ自分自身)
		
		for (size_type i = 0; i < bf_size(); ++i) {
			if (tree_id_[i] != bf_size()) continue;
			if (root != bf_size() && i != root) continue;
			
			std::stack<std::pair<size_type, size_type>> stk;
			par_[i] = i;
			depth_[i] = 0;
			tree_id_[i] = roots_.size();
			stk.emplace(i, 0);
			
			while (!stk.empty()) {
				const size_type u = stk.top().first, i = stk.top().second; stk.pop();
				if (i < g[u].size()) {
					stk.emplace(u, i + 1);
					const size_type v = g[u][i];
					if (v == par_[u]) continue;
					par_[v] = u;
					depth_[v] = depth_[u] + 1;
					tree_id_[v] = roots_.size();
					stk.emplace(v, 0);
				}
				else {
					size_type mx = 0;
					next[u] = u;
					sub_size_[u] = 1;
					for (size_type v : g[u]) {
						if (v == par_[u]) continue;
						sub_size_[u] += sub_size_[v];
						if (mx < sub_size_[v]) {
							mx = sub_size_[v];
							next[u] = v;
						}
					}
				}
			}
			roots_.emplace_back(i);
		}
		
		heavy_map_.resize(bf_size());
		in_.resize(bf_size());
		out_.resize(bf_size());
		euler_map_.reserve(bf_size());
		
		for (size_type root : roots_) {
			std::stack<std::pair<size_type, size_type>> stk;
			
			heavy_map_[root] = head_.size();
			head_.emplace_back(root);
			heavy_size_.emplace_back(1);
			heavy_depth_.emplace_back(0);
			stk.emplace(root, 0);
			
			while (!stk.empty()) {
				const size_type u = stk.top().first, i = stk.top().second; stk.pop();
				if (i < g[u].size()) {
					stk.emplace(u, i + 1);
					const size_type v = g[u][i];
					if (v != par_[u] && v != next[u]) {
						heavy_map_[v] = head_.size();
						head_.emplace_back(v);
						heavy_size_.emplace_back(1);
						heavy_depth_.emplace_back(heavy_depth_[heavy_map_[u]] + 1);
						stk.emplace(v, 0);
					}
				}
				if (i == 0) {
					in_[u] = euler_map_.size();
					euler_map_.emplace_back(u);
					const size_type v = next[u];
					if (v != u) {
						heavy_map_[v] = heavy_map_[u];
						++heavy_size_[heavy_map_[u]];
						stk.emplace(v, 0);
					}
				}
				if (i == g[u].size()) out_[u] = euler_map_.size();
			}
		}
		
		if (!use_lca) return;
		size_type max_depth = *std::max_element(begin(heavy_depth_), end(heavy_depth_));
		size_type lglg_n = 0;
		while ((1 << lglg_n) < max_depth) ++lglg_n;
		
		par_dblng_.assign(lglg_n + 1, std::vector<size_type>(af_size()));
		for (size_type i = 0; i < af_size(); ++i) par_dblng_[0][i] = par_[head_[i]];
		for (size_type i = 0; i < lglg_n; ++i) {
			for (size_type j = 0; j < af_size(); ++j) {
				par_dblng_[i + 1][j] = par_dblng_[i][heavy_map_[par_dblng_[i][j]]];
			}
		}
	}
	
	size_type bf_size() const noexcept { return bf_n; }
	size_type af_size() const noexcept { return head_.size(); }
	
	size_type par(size_type v) const { assert(v < bf_size()); return par_[v]; }
	size_type sub_size(size_type v) const { assert(v < bf_size()); return sub_size_[v]; }
	size_type depth(size_type v) const { assert(v < bf_size()); return depth_[v]; }
	
	size_type tree_id(size_type v) const { assert(v < bf_size()); return tree_id_[v]; }
	size_type tree_cnt() const noexcept { return roots_.size(); }
	const std::vector<size_type> & trees() const noexcept { return roots_; }
	
	size_type heavy_map(size_type v) const { assert(v < bf_size()); return heavy_map_[v]; }
	size_type head(size_type k) const { assert(k < af_size()); return head_[k]; }
	size_type heavy_size(size_type k) const { assert(k < af_size()); return heavy_size_[k]; }
	size_type heavy_depth(size_type k) const { assert(k < af_size()); return heavy_depth_[k]; }
	
	size_type in(size_type v) const { assert(v < bf_size()); return in_[v]; }
	size_type out(size_type v) const { assert(v < bf_size()); return out_[v]; }
	size_type euler_map(size_type k) const { assert(k < bf_size()); return euler_map_[k]; }
	
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
	
	size_type get_lca(size_type x, size_type y) {
		assert(!par_dblng_.empty());
		assert(x < bf_size());
		assert(y < bf_size());
		std::pair<size_type, size_type> res = get_lca_path(x, y);
		return in_[res.first] < in_[res.second] ? res.first : res.second;
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP