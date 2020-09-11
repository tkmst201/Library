#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "Mathematics/ModInt.hpp"
#include "DataStructure/LazySegmentTree.hpp"

#include <cstdio>
#include <utility>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	
	std::vector<mint> A(N);
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		A[i] = a;
	}
	
	using P = std::pair<mint, mint>; // {first} x + {second}
	
	P id_lazy(1, 0);
	LazySegmentTree<mint, P> seg(A, 0, id_lazy,
		[](auto && a, auto && b) { return a + b; },
		[](auto && a, auto && b) { return b.first * a + b.second; },
		[](auto && a, auto && b) { return std::make_pair(a.first * b.first, a.second * b.first + b.second); },
		[](auto && a, auto && k) { return std::make_pair(a.first, a.second * k); });
	
	while (Q--) {
		int q, l, r;
		scanf("%d %d %d", &q, &l, &r);
		if (q == 0) {
			int b, c;
			scanf("%d %d", &b, &c);
			seg.update(l, r, {b, c});
		}
		else printf("%lld\n", seg.fold(l, r).get());
	}
	
	return 0;
}