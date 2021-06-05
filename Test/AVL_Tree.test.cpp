#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "DataStructure/AVL_Tree.hpp"

#include <cstdio>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::string T;
	std::cin >> T;
	AVL_Tree<int> avl;
	for (int i = 0; i < T.size(); ++i) if (T[i] == '1') avl.insert(i);
	
	while (Q--) {
		int c, k;
		scanf("%d %d", &c, &k);
		if (c <= 1) {
			auto it = avl.find(k);
			if (c == 0 && it == avl.end()) avl.insert(k);
			else if (c == 1 && it != avl.end()) avl.erase(it);
		}
		else if (c == 2) {
			assert(avl.count(k) == (avl.find(k) != avl.end()));
			printf("%d\n", avl.find(k) != avl.end());
		}
		else if (c == 3) {
			auto it = avl.lower_bound(k);
			int ans1 = it == avl.end() ? -1 : it->val;
			
			
			auto cnt = avl.count_greater_equal(k);
			int ans2 = cnt == 0 ? -1 : avl.k_th_largest(cnt)->val;
			
			assert(ans1 == ans2);
			printf("%d\n", ans1);
		}
		else {
			auto it = avl.upper_bound(k);
			int ans1 = it == avl.begin() ? -1 : avl.prev(it)->val;
			
			auto cnt = avl.count_less_equal(k);
			int ans2 = cnt == 0 ? -1 : avl.k_th_smallest(cnt)->val;
			
			assert(ans1 == ans2);
			printf("%d\n", ans1);
		}
	}
}