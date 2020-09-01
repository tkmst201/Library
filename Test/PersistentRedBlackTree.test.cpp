#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/PersistentRedBlackTree.cpp"

#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	
	std::vector<int> q(Q);
	std::vector<ll> k(Q), v(Q);
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %lld", &q[i], &k[i]);
		if (q[i] == 0) scanf("%lld", &v[i]);
	}
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	std::vector<ll> cv;
	compress(k, cv);
	PersistentRedBlackTree<ll> tree(cv.size(), 0);
	
	for (int i = 0; i < Q; ++i) {
		if (q[i] == 0) {
			tree.erase(k[i]);
			tree.insert(k[i], v[i]);
		}
		else {
			printf("%lld\n", tree.get(k[i]));
		}
	}
	
	return 0;
}