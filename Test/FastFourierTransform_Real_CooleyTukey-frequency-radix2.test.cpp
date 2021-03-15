#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "GraphTheory/CentroidDecomposition.hpp"
#include "Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp"
#include "Algorithm/frequency_table_of_tree_distance.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	CentroidDecomposition::Graph g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	auto table = tk::frequency_table_of_tree_distance<CentroidDecomposition, FastFourierTransform>(g);
	for (int i = 1; i < N; ++i) printf("%lld%c", i < table.size() ? table[i] : 0, " \n"[i + 1 == N]);
	return 0;
}