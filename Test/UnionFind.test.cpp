#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "DataStructure/UnionFind.cpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	UnionFind uf(N);
	while (Q--) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 0) uf.unite(u, v);
		else printf("%d\n", uf.issame(u, v));
	}
}