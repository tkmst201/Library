#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "GraphTheory/HeavyLightDecomposition.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	HeavyLightDecomposition::Graph g(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		g[p].emplace_back(i);
	}
	HeavyLightDecomposition hld(g, true);
	
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", hld.get_lca(u, v));
	}
	return 0;
}