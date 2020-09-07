#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/RedBlackTree.hpp"

#include <cstdio>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	using pll = std::pair<ll, ll>;
	
	RedBlackTree<pll> rbt;
	
	while (Q--) {
		int q;
		ll k, v;
		scanf("%d %lld", &q, &k);
		auto it = rbt.lower_bound(pll{k, 0});
		
		if (q == 0) {
			scanf("%lld", &v);
			if (it != rbt.end() && it->val.first == k) rbt.erase(it);
			rbt.insert(pll{k, v});
		}
		else {
			printf("%lld\n", it == rbt.end() || it->val.first != k ? 0 : it->val.second);
		}
	}
	return 0;
}