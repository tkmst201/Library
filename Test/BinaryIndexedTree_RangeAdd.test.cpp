#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "DataStructure/BinaryIndexedTree.hpp"
#include "DataStructure/BinaryIndexedTree_RangeAdd.hpp"

#include <cstdio>
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	using ll = long long;
	
	BinaryIndexedTree_RangeAdd<ll, BinaryIndexedTree> bit(n);
	while (q--) {
		int query, s, t;
		scanf("%d %d %d", &query, &s, &t);
		--s;
		if (query == 0) {
			int x;
			scanf("%d", &x);
			bit.add(s, t, x);
		}
		else {
			printf("%lld\n", bit.sum(s, t));
		}
	}
	return 0;
}