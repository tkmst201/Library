#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	std::vector<long long> A(N), B(M);
	for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
	for (int i = 0; i < M; ++i) scanf("%lld", &B[i]);
	
	auto ans = NumberTheoreticTransform_AnyMod<1'000'000'007>::multiply(A, B);
	for (int i = 0; i < N + M - 1; ++i) printf("%lld%c", ans[i], i == N + M - 1 ? '\n': ' ');
	return 0;
}