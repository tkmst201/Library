#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "DataStructure/SparseTable.hpp"

#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	SparseTable<int> st(A.begin(), A.end(), [](int x, int y) {
		return std::min(x, y);
	});
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", st.fold(l, r));
	}
	return 0;
}