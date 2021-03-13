#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "GraphTheory/StronglyConnectedComponents.hpp"

#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	StronglyConnectedComponents::Graph g(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
	}
	StronglyConnectedComponents scc(g);
	printf("%d\n", scc.scc_size());
	
	for (int i = 0; i < scc.scc_size(); ++i) {
		auto & lis = scc.rank_list(i);
		printf("%d ", lis.size());
		for (int j = 0; j < lis.size(); ++j) printf("%d%c", lis[j], " \n"[j + 1 == lis.size()]);
	}
}