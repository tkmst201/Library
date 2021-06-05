#define PROBLEM "https://yukicoder.me/problems/no/415"

#include "Mathematics/euclid.hpp"

#include <cstdio>
#include <cassert>

int main() {
	int N, D;
	scanf("%d %d", &N, &D);
	long long lcm = tk::lcm<long long>(N, D);
	assert(lcm / D - 1 == N / tk::gcd(N, D) - 1);
	printf("%d\n", N / tk::gcd(N, D) - 1);
}