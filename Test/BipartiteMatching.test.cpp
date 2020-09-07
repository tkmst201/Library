#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "GraphTheory/BipartiteMatching.hpp"

#include <cstdio>

int main() {
	int L, R, M;
	scanf("%d %d %d", &L, &R, &M);
	
	BipartiteMatching bm(L, R);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		bm.add_edge(a, b);
	}
	bm.build();
	
	auto match = bm.get_match();
	printf("%d\n", match.size());
	for (int i = 0; i < match.size(); ++i) printf("%d %d\n", match[i].first, match[i].second);
	
	return 0;
}