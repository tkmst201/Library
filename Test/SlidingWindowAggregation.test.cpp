#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "DataStructure/SlidingWindowAggregation.hpp"
#include "Mathematics/ModInt.hpp"

#include <cstdio>
#include <utility>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using mint = ModInt<998244353>;
	using P = std::pair<mint, mint>;
	
	SlidingWindowAggregation<P> swag({1, 0}, [](const auto & x, const auto & y) -> P {
		return {x.first * y.first, x.second * y.first + y.second};
	});
	
	while (Q--) {
		int q;
		scanf("%d", &q);
		if (q == 0) {
			int a, b;
			scanf("%d %d", &a, &b);
			swag.push({a, b});
		}
		else if (q == 1) swag.pop();
		else {
			int x;
			scanf("%d", &x);
			auto res = swag.fold_all();
			printf("%d\n", (res.first * x + res.second).val());
		}
	}
}