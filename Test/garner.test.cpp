#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "Mathematics/garner.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	std::vector<int> b(N), m(N);
	bool zero = true;
	for (int i = 0; i < N; ++i) scanf("%d %d", &b[i], &m[i]), zero &= b[i] == 0;
	
	constexpr int mod = 1000000007;
	if (!tk::pre_garner(b, m)) puts("-1");
	else if (zero) {
		long long ans = 1;
		for (auto c : m) ans = ans * c % mod;
		printf("%lld\n", ans);
	}
	else printf("%d\n", tk::garner<int, long long>(b, m, mod));
}