#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"

#include "GraphTheory/EdmondsKarp.hpp"

#include <cstdio>

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	EdmondsKarp<int> ek(V);
	while (E--) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		ek.add_edge(u, v, c);
	}
	printf("%d\n", ek.max_flow(0, V - 1));
	return 0;
}