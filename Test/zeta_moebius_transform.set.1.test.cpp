#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012"
#define ERROR "1e-7"

#include "Mathematics/zeta_moebius_transform.hpp"
#include "Mathematics/euclid.hpp"

#include <vector>
#include <iostream>
#include <cmath>

int main() {
	using ll = long long;
	
	int N;
	ll M;
	std::cin >> N >> M;
	std::vector<ll> A(N);
	std::vector<int> P(N);
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < N; ++i) std::cin >> P[i];
	
	auto solve1 = [&]() {
		std::vector<ll> v((1 << N));
		
		for (int s = 1; s < 1 << N; ++s) {
			ll l = 1;
			bool ng = false;
			for (int i = 0; i < N; ++i) {
				if (~s >> i & 1) continue;
				ll g = tk::gcd<ll>(l, A[i]);
				l /= g;
				if (l > M / A[i]) { ng = true; break; } // l A[i] <= M
				else l *= A[i];
			}
			if (ng) continue;
			v[s] = M / l;
		}
		
		tk::moebius_transform_set_lower(v);
		
		double ans = 0;
		
		for (int s = 0; s < 1 << N; ++s) {
			double p = 1;
			for (int i = 0; i < N; ++i) {
				if (s >> i & 1) p *= P[i] * 0.01;
				else p *= (100 - P[i]) * 0.01;
			}
			ans += std::abs(v[s]) * p;
		}
		return ans;
	};
	
	auto solve2 = [&]() {
		std::vector<ll> v((1 << N));
		for (int s = 0; s < 1 << N; ++s) {
			ll l = 1;
			bool ng = false;
			for (int i = 0; i < N; ++i) {
				if (~s >> i & 1) continue;
				ll g = tk::gcd<ll>(l, A[i]);
				l /= g;
				if (l > M / A[i]) { ng = true; break; } // l A[i] <= M
				else l *= A[i];
			}
			if (ng) continue;
			v[s] = M / l;
		}
		
		tk::moebius_transform_set_upper(v);
		tk::zeta_tranform_set_lower(v);
		
		double ans = 0;
		
		for (int s = 0; s < 1 << N; ++s) {
			double p = 1;
			for (int i = 0; i < N; ++i) {
				if (s >> i & 1) p *= P[i] * 0.01;
				else p *= (100 - P[i]) * 0.01;
			}
			ans += (M - v[(1 << N) - 1 - s]) * p;
		}
		return ans;
	};
	
	double ans1 = solve1();
	double ans2 = solve2();
	printf("%.16f\n", (ans1 + ans2) / 2.0);
	return 0;
}