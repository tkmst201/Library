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
	EulerTour<false>::Graph g(N);
	for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
	std::vector<int> edge(N - 1);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &edge[i - 1]);
		// par[i] = p;
		g[edge[i - 1]].emplace_back(i);
	}
	
	EulerTour<false> et(g, 0);
	
	std::vector<ll> tv(et.size());
	for (int i = 0; i < N; ++i) tv[et.in(i)] = A[i];
	SegmentTree<ll> seg(tv, 0, [](ll x, ll y) { return x + y; });
	
	while (Q--) {
		int q;
		scanf("%d", &q);
		if (q == 0) {
			int u, x;
			scanf("%d %d", &u, &x);
			const int idx = et.in(u);
			seg.set(idx, seg.get(idx) + x);
		}
		else {
			int u;
			scanf("%d", &u);
			printf("%lld\n", seg.fold(et.in(u), et.out(u)));
		}
	}
	
	// par* test
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			assert(et.par(i) == -1);
			assert(et.par_from(i) == std::make_pair(-1, -1));
			assert(et.par_to(i) == -1);
		}
		else {
			const int p = et.par(i);
			auto [p1, pfidx] = et.par_from(i);
			assert(p == p1);
			assert(pfidx < g[p].size());
			assert(g[p][pfidx] == i);
			assert(et.par_to(i) == -1);
		}
	}
	
	for (int i = 1; i < N; ++i) g[i].emplace_back(edge[i - 1]);
	et = EulerTour<false>(g);
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			assert(et.par(i) == -1);
			assert(et.par_from(i) == std::make_pair(-1, -1));
			assert(et.par_to(i) == -1);
		}
		else {
			const int p = et.par(i);
			auto [p1, pfidx] = et.par_from(i);
			assert(p == p1);
			assert(pfidx < g[p].size());
			assert(g[p][pfidx] == i);
			auto ptidx = et.par_to(i);
			assert(ptidx < g[i].size());
			assert(g[i][ptidx] == p);
		}
	}
}