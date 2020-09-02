#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "GraphTheory/CentroidDecomposition.cpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	
	std::vector<std::vector<std::pair<size_type, int>>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	using ll = long long;
	std::vector<size_type> path;
	ll X = get_tree_diameter(g, path);
	
	printf("%lld %d\n", X, path.size());
	for (int i = 0; i < path.size(); ++i) printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
	return 0;
}