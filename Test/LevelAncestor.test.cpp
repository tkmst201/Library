#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "GraphTheory/LevelAncestor.hpp"

#include <cstdio>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using LA = LevelAncestor<5, 3>;
	LA::Graph g(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		g[p].emplace_back(i);
	}
	
	LevelAncestor<5, 3> la(g);
	
	/* verify */
	for (int i = 0; i < N; ++i) {
		assert(la.up(i, 0) == i);
		assert(la.up(i, la.depth(i)) == 0);
	}
	//
	
	int logn = 1;
	while ((1 << logn) < N) ++logn;
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (la.depth(u) < la.depth(v)) std::swap(u, v);
		// depth(u) >= depth(v)
		u = la.up(u, la.depth(u) - la.depth(v));
		if (u == v) { printf("%d\n", u); continue; }
		int up = 0;
		for (int i = logn - 1; i >= 0; --i) {
			const int cur = up + (1 << i);
			if (cur > la.depth(u)) continue;
			if (la.up(u, cur) != la.up(v, cur)) up += 1 << i;
		}
		int ans = la.up(u, up);
		if (la.depth(ans)) ans = la.up(ans, 1);
		printf("%d\n", ans);
	}
}