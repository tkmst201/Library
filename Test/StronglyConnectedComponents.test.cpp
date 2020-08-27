#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "GraphTheory/StronglyConnectedComponents.cpp"

#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	StronglyConnectedComponents scc(N);
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	
	int sz = scc.build();
	printf("%d\n", sz);
	
	for (int i = 0; i < sz; ++i) {
		auto &lis = scc.get_map(i);
		printf("%d ", lis.size());
		for (int j = 0; j < lis.size(); ++j) printf("%d%c", lis[j], " \n"[j + 1 == lis.size()]);
	}
	return 0;
}