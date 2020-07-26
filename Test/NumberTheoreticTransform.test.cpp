#include "Mathematics/Convolution/NumberTheoreticTransform.cpp"

#include <cstdio>
#include <vector>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	std::vector<long long> A(N), B(M);
	for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
	for (int i = 0; i < M; ++i) scanf("%lld", &B[i]);
	
	auto ans = NumberTheoreticTransform::multiply(A, B, 1'000'000'007);
	for (int i = 0; i < N + M - 1; ++i) printf("%lld%c", ans[i], i == N + M - 1 ? '\n': ' ');
}