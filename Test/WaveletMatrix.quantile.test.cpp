#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "DataStructure/WaveletMatrix.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	WaveletMatrix<int, 30> wm(a);
	while (Q--) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", wm.quantile(l, r, k + 1));
	}
}