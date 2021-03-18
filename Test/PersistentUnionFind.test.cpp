#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "DataStructure/PersistentUnionFind.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using PUF = PersistentUnionFind<6>;
	std::vector<PUF> hist(Q + 1);
	
	for (int i = 0; i < Q; ++i) {
		int t, k, u, v;
		scanf("%d %d %d %d", &t, &k, &u, &v);
		++k;
		if (t == 0) hist[i + 1] = (hist[k].unite(u, v));
		else printf("%d\n", hist[k].issame(u, v));
	}
}