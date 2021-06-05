#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"

#include "GraphTheory/Dinic.hpp"

#include <cstdio>

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	Dinic<int> dinic(V);
	while (E--) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		dinic.add_edge(u, v, c);
	}
	printf("%d\n", dinic.max_flow(0, V - 1));
}