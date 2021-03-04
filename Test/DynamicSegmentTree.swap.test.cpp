#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/Hupc/2871?year=2018"

#include "GraphTheory/EulerTour.hpp"
#include "DataStructure/DynamicSegmentTree.hpp"

#include <cstdio>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	EulerTour::Tree tree(N);
	for (int i = 1; i < N; ++i) {
		int p;
		scanf("%d", &p);
		tree[p - 1].emplace_back(i);
	}
	
	EulerTour et(tree, 0);
	DynamicSegmentTree<int> seg(et.size(), 0, [](int x, int y) { return x + y; });
	auto segr = seg;
	
	for (int i = 0; i < N; ++i) {
		char c;
		scanf(" %c", &c);
		if (c == 'G') seg.set(et.in(i), 1);
		else segr.set(et.in(i), 1);
	}
	
	while (Q--) {
		int v;
		scanf("%d", &v);
		--v;
		seg.swap(segr, et.in(v), et.out(v));
		const int x = seg.fold_all();
		const int y = N - x;
		puts(x > y ? "broccoli" : "cauliflower");
	}
}