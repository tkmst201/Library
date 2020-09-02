#include <vector>
#include <cassert>

/*
last-updated: 2020/09/02

コンストラクタで渡した g は変更してはいけない
used フラグの変更は set を通して行う

# 仕様

CentroidDecomposition(const Graph & g) :
	時間計算量: Θ(n)
	重心分解を行うグラフ g で初期化する

bool operator [](size_type v) const :
	時間計算量: Θ(1)
	used フラグの値を返す

bool operator at(size_type v) const :
	時間計算量: Θ(1)
	used フラグの値を返す
	assert チェックあり

std::vector<size_type> get_centroid(size_type root) :
	時間計算量: Θ(k)
	used フラグが立っている頂点を取り除いた森上で頂点 root が属する木(頂点数を k とする) の重心を求める

void set(size_type v) :
	時間計算量: Θ(1)
	頂点 v の used フラグを true に変更する

void clear() :
	時間計算量: Θ(n)
	used フラグをリセットする

# 使用例
size_type get_centroid_decomposition_tree(const Graph & g, Graph & cdg) :
	時間計算量: Θ(n log n)
	重心分解を再帰的に行い、各部分木の重心に辺を張ったグラフを cdg に格納する
	根の index(g の重心の 1 つ) を返す
	
	verified(2020/09/02) : https://codeforces.com/contest/321/submission/91621846

long long get_tree_diameter(
		const std::vector<std::vector<std::pair<size_type, int>>> & wg,
		std::vector<size_type> & path
	)
	時間計算量: Θ(n log n)
	重み付きグラフ上で最遠頂点対を求める
	最遠頂点対 (u, v) の長さを返し、そのパスを path に格納する
	定数倍がすごく重い(
		提出: https://judge.yosupo.jp/submission/20914
		手元では line グラフの処理が max_random に比べて 4 倍程度遅いが library-checker 上でははやかった(なぜ?)
	)。
	
	負辺でも正しく動作しそう(unverified)
	全方位木 dp を用いれば Θ(n) で求めることができそう
	重みが正の場合は double-sweap で Θ(n) で求まる
	これは verify 用

# 参考
https://ferin-tech.hatenablog.com/entry/2020/03/06/162311, 2020/09/02
https://qiita.com/drken/items/4b4c3f1824339b090202, 2020/09/02
*/

class CentroidDecomposition {
public:
	using size_type = std::size_t;
	using Graph = std::vector<std::vector<size_type>>;
	
private:
	const Graph & g;
	std::vector<bool> used;
	std::vector<size_type> sz;
	
public:
	CentroidDecomposition() = delete;
	CentroidDecomposition(const Graph & g) : g(g) {
		used.resize(size(), false);
		sz.resize(size());
	}
	
	size_type size() const noexcept {
		return g.size();
	}
	
	bool operator [](size_type v) const {
		return used[v];
	}
	
	bool at(size_type v) const {
		assert(v < size());
		return used[v];
	}
	
	std::vector<size_type> get_centroid(size_type root) {
		assert(root < size());
		
		auto szdfs = [this](auto &&self, size_type v, size_type par) -> size_type {
			sz[v] = 1;
			for (auto to : g[v]) {
				if (to == par || used[to]) continue;
				sz[v] += self(self, to, v);
			}
			return sz[v];
		};
		szdfs(szdfs, root, size());
		
		size_type v = root, par = size();
		std::vector<size_type> res;
		while (true) {
			bool updated = false;
			for (auto to : g[v]) {
				if (to == par || used[to]) continue;
				if (sz[to] * 2 > sz[root]) {
					par = v;
					v = to;
					updated = true;
					break;
				}
				if (sz[to] * 2 == sz[root]) res.emplace_back(to);
			}
			if (updated) continue;
			res.emplace_back(v);
			break;
		}
		return res;
	}
	
	void set(size_type v) {
		assert(v < size());
		used[v] = true;
	}
	
	void clear() {
		used.assign(size(), false);
	}
};


// おまけ その１
CentroidDecomposition::size_type get_centroid_decomposition_tree(
		const CentroidDecomposition::Graph & g,
		CentroidDecomposition::Graph & cdg
	) {
	assert(!g.empty());
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	CD cd(g);
	
	cdg.assign(g.size(), {});
	
	auto dfs = [&](auto && self, size_type centroid) -> void {
		cd.set(centroid);
		for (auto r : g[centroid]) {
			if (cd[r]) continue;
			auto nex_cent = cd.get_centroid(r);
			
			cdg[centroid].emplace_back(nex_cent[0]);
			
			self(self, nex_cent[0]);
		}
	};
	
	size_type root = cd.get_centroid(0)[0];
	dfs(dfs, root);
	return root;
}

// おまけ その２
long long get_tree_diameter(
		const std::vector<std::vector<std::pair<CentroidDecomposition::size_type, int>>> & wg,
		std::vector<CentroidDecomposition::size_type> & path
	) {
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	using ll = long long;
	
	CD::Graph g(wg.size());
	for (CD::size_type i = 0; i < wg.size(); ++i) {
		for (auto v : wg[i]) g[i].emplace_back(v.first);
	}
	CD cd(g);
	
	struct Data {
		ll dist;
		size_type u, v;
		Data(ll dist, size_type u, size_type v) : dist(dist), u(u), v(v) {} 
		bool operator <(const Data & rhs) const {
			return dist < rhs.dist;
		}
	};
	
	auto dfs = [&](auto && self, size_type centroid) -> Data {
		cd.set(centroid);
		Data res{0, centroid, centroid};
		
		Data top = res, top2 = res;
		for (auto e : wg[centroid]) {
			size_type r = e.first;
			if (cd[r]) continue;
			
			auto dfs2 = [&](auto && self, size_type u, size_type par, ll c) -> Data {
				Data res{c, centroid, u};
				for (auto e : wg[u]) {
					size_type to = e.first;
					if (to == par || cd[to]) continue;
					Data nexd = self(self, to, u, c + e.second);
					if (res < nexd) res = nexd;
				}
				return res;
			};
			
			Data pred = dfs2(dfs2, r, wg.size(), e.second);
			if (top < pred) { top2 = top; top = pred; }
			else if (top2 < pred) { top2 = pred; }
			
			pred = self(self, cd.get_centroid(r)[0]);
			if (res < pred) res = pred;
		}
		
		if (top.dist + top2.dist > res.dist) return {top.dist + top2.dist, top.v, top2.v};
		return res;
	};
	
	size_type root = cd.get_centroid(0)[0];
	Data dat = dfs(dfs, root);
	
	std::vector<size_type> par(g.size(), g.size());
	auto dfs3 = [&](auto && self, size_type u) -> void {
		for (auto v : g[u]) {
			if (v == par[u]) continue;
			par[v] = u;
			self(self, v);
		}
	};
	
	dfs3(dfs3, dat.u);
	
	path.emplace_back(dat.v);
	while (par[path.back()] != g.size()) path.emplace_back(par[path.back()]);
	return dat.dist;
}