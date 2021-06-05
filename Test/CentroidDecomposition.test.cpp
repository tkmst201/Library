#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "GraphTheory/CentroidDecomposition.hpp"

#include <cstdio>
#include <vector>
#include <cassert>

std::pair<long long, std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<int, int>>> & wg) {
	assert(!wg.empty());
	using CD = CentroidDecomposition;
	using ll = long long;
	const int n = wg.size();
	CD::Graph g(n);
	for (int i = 0; i < n; ++i) {
		g[i].reserve(wg[i].size());
		for (const auto & e : wg[i]) {
			const int v = e.first;
			assert(0 <= v && v < n);
			g[i].emplace_back(v);
		}
	}
	CD cd(g);
	struct Data { ll dist; int u, v; };
	auto dfs = [&](auto self, int centroid) -> Data {
		cd.done(centroid);
		Data res{0, centroid, centroid};
		std::pair<ll, int> top[2];
		std::fill(top, top + 2, std::make_pair(0, centroid));
		for (const auto [v, d] : wg[centroid]) {
			if (!cd.exist(v)) continue;
			auto dfs2 = [&](auto self, int u, int p) -> std::pair<ll, int> {
				std::pair<ll, int> res{0, u};
				for (const auto & e : wg[u]) { // auto [v, d] internal compiler error
					const int v = e.first;
					const ll d = e.second;
					if (v == p || !cd.exist(v)) continue;
					auto [mxd, mxu] = self(self, v, u);
					if (res.first < mxd + d) res = {mxd + d, mxu};
				}
				return res;
			};
			auto pred = dfs2(dfs2, v, -1);
			pred.first += d;
			if (top[0] < pred) top[1] = std::move(top[0]), top[0] = pred;
			else if (top[1] < pred) top[1] = std::move(pred);
			auto pred2 = self(self, cd.centroids(g, v)[0]);
			if (res.dist < pred2.dist) res = pred2;
		}
		if (top[0].first + top[1].first > res.dist) return {top[0].first + top[1].first, top[0].second, top[1].second};
		return res;
	};
	Data dat = dfs(dfs, cd.centroids(g, 0)[0]);
	std::vector<int> par(n, -1);
	auto dfs3 = [&](auto self, int u) -> void {
		for (auto v : g[u]) if (v != par[u]) par[v] = u, self(self, v);
	};
	dfs3(dfs3, dat.u);
	std::vector<int> path;
	path.emplace_back(dat.v);
	while (par[path.back()] != -1) path.emplace_back(par[path.back()]);
	return {dat.dist, path};
}

int main() {
	int N;
	scanf("%d", &N);
	
	std::vector<std::vector<std::pair<int, int>>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	auto [ans, path] = tree_diameter(g);
	printf("%lld %d\n", ans, (int)path.size());
	for (int i = 0; i < path.size(); ++i) printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
}