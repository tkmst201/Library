#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/1549?year=2014"

#include "DataStructure/SuccintBitVector.hpp"
#include "DataStructure/WaveletMatrix.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	
	const int bias = 1'000'000;
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]), A[i] += bias;
	
	WaveletMatrix<21, int, SuccintBitVector> wm(A);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);
		++r;
		d += bias;
		
		int ans = 1'000'001;
		auto res = wm.prev_value(l, r, 0, d + 1);
		if (res.second) ans = d - res.first;
		
		res = wm.next_value(l, r, d, 2'000'001);
		if (res.second && res.first - d < ans) ans = res.first - d;
		
		printf("%d\n", ans);
	}
	
	return 0;
}