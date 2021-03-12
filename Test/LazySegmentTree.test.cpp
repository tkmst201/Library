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
	
	LazySegmentTree<mint, P> seg(A, 0, {1, 0},
		[](const auto & x, const auto & y) { return x + y; },
		[](const auto & x, const auto & e) { return e.first * x + e.second; },
		[](const auto & e1, const auto & e2) { return std::make_pair(e1.first * e2.first, e1.second * e2.first + e2.second); },
		[](const auto & e, auto k) { return std::make_pair(e.first, e.second * k); });
	
	while (Q--) {
		int q, l, r;
		scanf("%d %d %d", &q, &l, &r);
		if (q == 0) {
			int b, c;
			scanf("%d %d", &b, &c);
			seg.update(l, r, {b, c});
		}
		else printf("%d\n", seg.fold(l, r).val());
	}
}