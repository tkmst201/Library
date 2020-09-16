#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "GraphTheory/EulerTour.hpp"
#include "DataStructure/SegmentTree.hpp"

#include <vector>
#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using ll = long long;
	std::vector<ll> A(N);
	EulerTour::Tree g(N);
	for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		// par[i] = p;
		g[p].emplace_back(i);
	}
	
	EulerTour et(g, 0);
	
	std::vector<ll> tv(et.size());
	for (int i = 0; i < N; ++i) tv[et.in(i)] = A[i];
	SegmentTree<ll> seg(tv, 0, [](ll x, ll y) { return x + y; });
	
	while (Q--) {
		int q;
		scanf("%d", &q);
		if (q == 0) {
			int u, x;
			scanf("%d %d", &u, &x);
			int idx = et.in(u);
			seg.set(idx, seg.get(idx) + x);
		}
		else {
			int u;
			scanf("%d", &u);
			printf("%ld\n", seg.fold(et.in(u), et.out(u)));
		}
	}
	return 0;
}