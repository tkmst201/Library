#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "Mathematics/ModInt.hpp"
#include "GraphTheory/VertexUpdatePathFold.hpp"

#include <cstdio>
#include <vector>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using P = std::pair<mint, mint>;
	using VUPF = VertexUpdatePathFold<P>;
	
	std::vector<P> init(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		init[i] = {a, b};
	}
	
	VUPF::Graph g(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	VUPF vupf(g, 0, init, true, {1, 0}, [](auto && x, auto && y) -> P { return {x.first * y.first, x.second * y.first + y.second}; });
	while (Q--) {
		int q;
		scanf("%d", &q);
		if (q == 0) {
			int p, c, d;
			scanf("%d %d %d", &p, &c, &d);
			vupf.set(p, {c, d});
		}
		else {
			int u, v, x;
			scanf("%d %d %d", &u, &v, &x);
			auto res = vupf.fold(u, v);
			printf("%d\n", (res.first * x + res.second).val());
		}
	}
}