#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "Mathematics/Convolution/NumberTheoreticTransform.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	std::vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	for (int i = 0; i < M; ++i) scanf("%d", &B[i]);
	
	auto ans = NumberTheoreticTransform<998'244'353, 3>::multiply(A, B);
	for (int i = 0; i < N + M - 1; ++i) printf("%d%c", ans[i], i == N + M - 1 ? '\n': ' ');
}