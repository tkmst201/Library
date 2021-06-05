#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "GraphTheory/BipartiteMatching.hpp"

#include <cstdio>
#include <map>

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
	
	printf("%d\n", bm.max_matching());
	
	std::map<int, int> mtl, mtr;
	for (auto [a, b] : bm.matching()) {
		printf("%d %d\n", a, b);
		mtl[a] = b;
		mtr[b] = a;
	}
	
	// [match_*] test
	for (int i = 0; i < L; ++i) assert(mtl.count(i) ? mtl[i] == bm.matching_x(i) : -1);
	for (int i = 0; i < R; ++i) assert(mtr.count(i) ? mtr[i] == bm.matching_y(i) : -1);
}