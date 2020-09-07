#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"

#include "DataStructure/PotentializedUnionFind.hpp"

#include <cstdio>

int main() {
	int N, M;
	while(scanf("%d %d", &N, &M), N && M) {
		PotentializedUnionFind<int> puf(N, [](int a, int b){ return a + b; }, 0);
		for (int i = 0; i < M; ++i) {
			char c;
			int a, b;
			scanf(" %c %d %d", &c, &a, &b);
			--a; --b;
			
			if (c == '!') {
				int w;
				scanf("%d", &w);
				if (!puf.issame(a, b)) {
					int u = puf.add(w - puf.get(b));
					puf.link(a, u);
					puf.link(u, puf.find(b));
				}
			}
			else {
				if (puf.issame(a, b)) printf("%d\n", puf.get(b) - puf.get(a));
				else puts("UNKNOWN");
			}
		}
	}
	return 0;
}
