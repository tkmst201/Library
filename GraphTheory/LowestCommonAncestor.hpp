#ifndef INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP
#define INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP

#include <vector>
#include <cassert>
#include <utility>

/*
last-updated: 2020/08/27

木グラフでの最近共通祖先を求める
木グラフではないとバグるので注意

おまけで木の任意の 2 頂点間のパスの長さを返す機能がついている

# 仕様
LowestCommonAncestor(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを作成する

LowestCommonAncestor(std::vector<std::vector<size_type>> g) :
	時間計算量: Θ(n + m)
	グラフ g で初期化する
	build() を呼ぶ必要があることに注意

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type s, size_type t)
	時間計算量: Θ(1)
	頂点 u -> 頂点 v に辺を張る

void clear() :
	時間計算量: Θ(n)
	グラフを削除する

void build(size_type rootNode = 0)
	時間計算量: Θ(N log N)
	LCA 計算のための事前計算を行う

size_type find(size_type a, size_type b) const
	時間計算量: Θ(log N)
	頂点 a , 頂点 b の LCA を求める

size_type query(size_type a, size_type b) const :
	時間計算量: Θ(log N)
	パス a - b の長さを求める
*/

#include <vector>
#include <cassert>
#include <utility>

struct LowestCommonAncestor {
	using size_type = std::size_t;
	
private:
	size_type logsize;
	std::vector<std::vector<size_type> > g, par;
	std::vector<size_type> depth;
	bool isbuilt;
	
public:
	LowestCommonAncestor(size_type n) {
		g.resize(n);
		isbuilt = false;
	}
	
	LowestCommonAncestor(std::vector<std::vector<size_type>> g) : g(g) {
		isbuilt = false;
	};
	
	size_type size() const noexcept {
		return g.size();
	}
	
	void add_edge(size_type s, size_type t) {
		assert(s < size());
		assert(t < size());
		g[s].push_back(t);
		isbuilt = false;
	}
	
	void clear() {
		g.clear();
		par.clear();
		depth.clear();
		isbuilt = false;
	}
	
	void build(size_type rootNode = 0) {
		assert(rootNode < size());
		logsize = 1;
		while (1 << logsize < size()) ++logsize;
		depth.assign(size(), size());
		par.assign(logsize, std::vector<size_type>(size(), size()));
		
		depth[rootNode] = 0;
		dfs(rootNode, size());
		for (size_type i = 1; i < logsize; ++i) {
			for (size_type j = 0; j < size(); ++j) {
				if (par[i - 1][j] != size()) par[i][j] = par[i - 1][ par[i - 1][j] ];
			}
		}
		isbuilt = true;
	}
	
	size_type find(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		if (depth[a] < depth[b]) std::swap(a, b);
		
		size_type up = depth[a] - depth[b];
		for (size_type i = 0; i < logsize; ++i) if (up >> i & 1) a = par[i][a];
		if (a == b) return a;
		for (size_type i = logsize; i > 0; --i) {
			if (par[i - 1][a] != par[i - 1][b]) {
				a = par[i - 1][a];
				b = par[i - 1][b];
			}
		}
		return par[0][a];
	}
	
	size_type query(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		return depth[a] + depth[b] - 2 * depth[find(a, b)];
	}
	
private:
	void dfs(size_type u, size_type p) {
		for (size_type v : g[u]) {
			if (v == p) continue;
			depth[v] = depth[u] + 1;
			par[0][v] = u;
			dfs(v, u);
		}
	}
};

#endif // INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP