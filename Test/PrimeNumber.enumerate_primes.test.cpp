#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "Mathematics/PrimeNumber/enumerate_primes.hpp"

#include <cstdio>

int main() {
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	
	auto primes = tk::enumerate_primes(N);
	
	std::vector<int> ans;
	for (int i = 0, idx = B; idx < primes.size() && primes[idx] <= N; ++i, idx += A)
		ans.emplace_back(primes[idx]);
	
	printf("%d %d\n", primes.size(), ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	
	return 0;
}