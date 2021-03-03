#define PROBLEM "https://yukicoder.me/problems/no/1115"

#include "DataStructure/AVL_Tree.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	std::vector<int> A(N), table(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]), --A[i];
	for (int i = 0; i < N; ++i) {
		int b;
		scanf("%d", &b);
		table[b - 1] = i;
	}
	for (int i = 0; i < N; ++i) A[i] = table[A[i]];
	
	long long ans = 0;
	AVL_Tree<int> avl;
	for (int i = 0; i < N; ++i) {
		ans += avl.count_more_than(A[i]);
		avl.insert(A[i]);
	}
	printf("%lld\n", ans);
}