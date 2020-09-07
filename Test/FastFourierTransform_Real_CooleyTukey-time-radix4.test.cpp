#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "GraphTheory/CentroidDecomposition.hpp"
#include "Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	CD::Graph g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	auto table = get_dist_frequency_table<FastFourierTransform>(g);
	for (size_type i = 1; i < N; ++i) printf("%lld%c", table[i], " \n"[i + 1 == N]);
	return 0;
}