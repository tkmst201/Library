#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "DataStructure/RedBlackTree.hpp"

#include <cstdio>
#include <iostream>
#include <string>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::string T;
	std::cin >> T;
	RedBlackTree<int> rbt;
	for (int i = 0; i < T.size(); ++i) if (T[i] == '1') rbt.insert(i);
	
	while (Q--) {
		int c, k;
		scanf("%d %d", &c, &k);
		if (c <= 1) {
			auto it = rbt.find(k);
			if (c == 0 && it == rbt.end()) rbt.insert(k);
			else if (c == 1 && it != rbt.end()) rbt.erase(it);
		}
		else if (c == 2) printf("%d\n", rbt.find(k) != rbt.end());
		else if (c == 3) {
			auto it = rbt.lower_bound(k);
			printf("%d\n", it == rbt.end() ? -1 : it->val);
		}
		else {
			auto it = rbt.upper_bound(k);
			printf("%d\n", it == rbt.begin() ? -1 : rbt.prev(it)->val);
		}
	}
}