#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include "DataStructure/BinaryIndexedTree2D.hpp"

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

int main() {
	int H, W, T, Q;
	scanf("%d %d %d %d", &H, &W, &T, &Q);
	std::vector<int> t(Q), c(Q), h1(Q), w1(Q), h2(Q), w2(Q);
	
	using pii = std::pair<int, int>;
	
	std::queue<pii> que; // 焼き上がりの時刻, イベントID
	BinaryIndexedTree2D<int> bit1(H, W), bit2(H, W); // bit1: 焼き上がった, bit2: まだ焼き上がっていない
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %d %d %d", &t[i], &c[i], &h1[i], &w1[i]);
		--h1[i]; --w1[i];
		
		while (!que.empty() && que.front().first <= t[i]) {
			int idx = que.front().second; que.pop();
			bit2.add(h1[idx], w1[idx], -1);
			bit1.add(h1[idx], w1[idx], 1);
		}
		
		if (c[i] == 0) { // セット
			bit2.add(h1[i], w1[i], 1);
			que.emplace(t[i] + T, i);
		}
		else if (c[i] == 1) { // つまみ食い
			if (bit1.sum(h1[i], h1[i] + 1, w1[i], w1[i] + 1) == 1) bit1.add(h1[i], w1[i], -1);
		}
		else { // カウント
			scanf("%d %d", &h2[i], &w2[i]);
			printf("%d %d\n", bit1.sum(h1[i], h2[i], w1[i], w2[i]), bit2.sum(h1[i], h2[i], w1[i], w2[i]));
		}
	}
}