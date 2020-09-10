#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "Mathematics/sum_of_floor_of_linear.hpp"

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	
	using ll = long long;
	
	while (T--) {
		ll n, m, a, b;
		scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
		printf("%lld\n", tk::sum_of_floor_of_linear<ll>(n, m, a, b));
	}
	
	return 0;
}