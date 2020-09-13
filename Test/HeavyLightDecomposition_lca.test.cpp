#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "GraphTheory/HeavyLightDecomposition.hpp"

#include <cstdio>
#include <functional>

template<typename T>
struct Dummy {
	Dummy(int n_, const int & id_elem, const std::function<int(int, int)> f) {}
	
	int fold(int l, int r) {
		return 0;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	
	using HLD = HeavyLightDecomposition<int, Dummy>;
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int c;
			scanf("%d", &c);
			g[i].emplace_back(c);
			g[c].emplace_back(i);
		}
	}
	
	HLD hld(g, 0, 0, [](int a, int b) { return a + b; }, true);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", hld.lca(u, v));
	}
}
