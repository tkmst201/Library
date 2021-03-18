#define PROBLEM "https://yukicoder.me/problems/no/186"

#include "Mathematics/chinese_remainder.hpp"

#include <cstdio>
#include <utility>

int main() {
	using ll = long long;
	ll X[3], Y[3];
	for (int i = 0; i < 3; ++i) scanf("%lld %lld", X + i, Y + i);
	
	ll ans = 0, lcm = 1;
	for (int i = 0; i < 3; ++i) {
		auto [a, l] = tk::chinese_remainder(ans, lcm, X[i], Y[i]);
		if (l == 0) { puts("-1"); return 0; }
		ans = a; lcm = l;
	}
	
	printf("%lld\n", ans == 0 ? lcm : ans);
}