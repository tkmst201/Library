#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "GraphTheory/LowestCommonAncestor.hpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	LowestCommonAncestor lca(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		lca.add_edge(p, i);
	}
	lca.build();
	
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca.find(u, v));
	}
	
	return 0;
}