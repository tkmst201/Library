#define PROBLEM "https://yukicoder.me/problems/no/1181"

#include "Mathematics/ModInt.hpp"
#include "Mathematics/Combination.hpp"

#include <cstdio>
#include <vector>

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;
Combination<mint> comb;
using ll = long long;

int main() {
	int N;
	ll K;
	scanf("%d %lld", &N, &K);
	K %= MOD;
	
	mint sum = mint(1 + K) * K / 2;
	std::vector<mint> powk(N + 1);
	powk[0] = 1;
	for (int i = 1; i < N; ++i) powk[i] = powk[i - 1] * K;
	mint ans = mint(K).pow(N), p = 1;
	for (int i = 0; i < N; ++i) {
		mint pat = comb(N, i) * powk[N - i];
		ans += pat * p;
		p *= sum;
	}
	printf("%d\n", ans.val());
	return 0;
}