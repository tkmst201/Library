#define PROBLEM "https://yukicoder.me/problems/no/1094"

#include "GraphTheory/EulerTour.hpp"
#include "DataStructure/BinaryIndexedTree.hpp"
#include "GraphTheory/LowestCommonAncestor.hpp"

#include <cstdio>
#include <utility>

int main() {
	int N;
	scanf("%d", &N);
	
	EulerTour<true>::Graph g(N);
	std::vector<int> A(N - 1), B(N - 1), C(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		--A[i]; --B[i];
		g[A[i]].emplace_back(B[i]);
		g[B[i]].emplace_back(A[i]);
	}
	EulerTour<true> et(g);
	
	using ll = long long;
	BinaryIndexedTree<ll> bit(et.size(), 0, [](auto x, auto y) { return x + y; });
	for (int i = 0; i < N - 1; ++i) {
		if (et.par(A[i]) != B[i]) std::swap(A[i], B[i]);
		bit.add(et.in(A[i]), C[i]);
		bit.add(et.out(A[i]), -C[i]);
	}
	LowestCommonAncestor lca(g);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int s, t;
		scanf("%d %d", &s, &t);
		--s; --t;
		const int l = lca.find(s, t);
		auto func = [&](int a) {
			return bit.sum(et.in(a) + 1) - bit.sum(et.in(l) + 1);
		};
		printf("%lld\n", func(s) + func(t));
	}
}