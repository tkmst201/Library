#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "DataStructure/DisjointSparseTable.hpp"
// これは可換の場合でのテスト

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	using ll = long long;
	DisjointSparseTable<ll> dst(A.begin(), A.end(), [](ll x, ll y) {
		return x + y;
	});
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", dst.fold(l, r));
	}
	return 0;
}