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
		if (i % 2 == 0) lca.add_edge(p, i);
		else lca.add_directed_edge(p, i);
	}
	lca.build();
	
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca.find(u, v));
	}
}