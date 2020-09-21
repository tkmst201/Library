#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "Mathematics/Garner.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	std::vector<long long> b(N), m(N);
	bool zero = true;
	for (int i = 0; i < N; ++i) scanf("%lld %lld", &b[i], &m[i]), zero &= b[i] == 0;
	
	constexpr long long mod = 1000000007;
	if (!Garner::preprocess(b, m)) puts("-1");
	else if (zero) {
		long long ans = 1;
		for (auto c : m) ans = ans * c % mod;
		printf("%lld\n", ans);
	}
	else printf("%lld\n", Garner::garner(b, m, mod));
	return 0;
}