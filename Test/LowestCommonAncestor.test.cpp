#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "GraphTheory/LowestCommonAncestor.hpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	LowestCommonAncestor::Graph g(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		g[p].emplace_back(i);
	}
	LowestCommonAncestor lca(g, 0);
	
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca.find(u, v));
	}
}