#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "DataStructure/SegmentTree.hpp"
#include "GraphTheory/HeavyLightDecomposition.hpp"
#include "GraphTheory/HeavyLightDecomposition_Query.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	HeavyLightDecomposition::Graph g(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		g[p].emplace_back(i);
	}
	
	using ll = long long;
	HeavyLightDecomposition_Query<HeavyLightDecomposition, ll, SegmentTree> hld(g, A, 0, [](ll a, ll b) { return a + b; });
	
	while (Q--) {
		int q;
		scanf("%d", &q);
		if (q == 0) {
			int u, x;
			scanf("%d %d", &u, &x);
			hld.set(u, hld.get(u) + x);
		}
		else {
			int u;
			scanf("%d", &u);
			printf("%lld\n", hld.subtree_sum(u));
		}
	}
	return 0;
}