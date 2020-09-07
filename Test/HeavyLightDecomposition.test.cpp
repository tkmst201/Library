#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "Mathematics/ModInt.hpp"
#include "DataStructure/SegmentTree.hpp"
#include "GraphTheory/HeavyLightDecomposition.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	using HLD = HeavyLightDecomposition<pmm, SegmentTree>;
	
	std::vector<pmm> val(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		val[i] = {a, b};
	}
	
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	HLD hld(g, 0, [](const pmm &a, const pmm &b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0), true);
	
	for (int i = 0; i < N; ++i) {
		hld.set(i, val[i]);
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			hld.set(a, {b, c});
		}
		else {
			pmm v = hld.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
	
	return 0;
}