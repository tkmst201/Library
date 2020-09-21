#define PROBLEM "https://yukicoder.me/problems/no/186"

#include "Mathematics/MathUtility.hpp"

#include <cstdio>
#include <utility>

int main() {
	using ll = long long;
	ll X[3], Y[3];
	for (int i = 0; i < 3; ++i) scanf("%lld %lld", X + i, Y + i);
	
	std::pair<ll, ll> res {0, 1};
	
	for (int i = 0; i < 3; ++i) {
		res = tk::chinese_remainder(res.first, res.second, X[i], Y[i]);
		if (res.second == 0) {
			puts("-1");
			return 0;
		}
	}
	
	ll ans = res.first;
	if (ans == 0) ans += res.second;
	printf("%lld\n", ans);
	return 0;
}