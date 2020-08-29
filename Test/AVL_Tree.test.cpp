#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/AVL_Tree.cpp"

#include <cstdio>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	using pll = std::pair<ll, ll>;
	
	AVL_Tree<pll> avl;
	
	while (Q--) {
		int q;
		ll k, v;
		scanf("%d %lld", &q, &k);
		auto it = avl.lower_bound(pll{k, 0});
		
		if (q == 0) {
			scanf("%lld", &v);
			if (it != avl.end() && it->value.first == k) avl.erase(it);
			avl.insert(pll{k, v});
		}
		else {
			printf("%lld\n", it == avl.end() || it->value.first != k ? 0 : it->value.second);
		}
	}
	return 0;
}