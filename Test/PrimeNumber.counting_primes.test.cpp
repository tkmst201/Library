#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "Mathematics/ModInt.cpp"
#include "Mathematics/PrimeNumber/counting_primes.cpp"

#include <cstdio>

int main() {
	long long N;
	scanf("%lld", &N);
	printf("%lld\n", tk::counting_primes(N));
	return 0;
}