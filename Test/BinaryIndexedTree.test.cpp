#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "DataStructure/BinaryIndexedTree.hpp"

#include <cstdio>
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	BinaryIndexedTree<int> bit(n, 0, [](auto &&x, auto &&y) { return x + y; });
	
	while (q--) {
		int com, x, y;
		scanf("%d %d %d", &com, &x, &y);
		if (com == 0) bit.add(x - 1, y);
		else printf("%d\n", bit.sum(y) - bit.sum(x - 1));
	}
}