#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "Mathematics/TwoSat.hpp"

#include <iostream>
#include <string>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::string dummy; std::cin >> dummy >> dummy;
	
	int N, M;
	std::cin >> N >> M;
	
	TwoSat sat(N);
	
	while (M--) {
		int a, b, t;
		std::cin >> a >> b >> t;
		sat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);
	}
	
	if (!sat.build()) std::cout << "s UNSATISFIABLE" << std::endl;
	else {
		std::cout << "s SATISFIABLE" << std::endl;
		const auto & ans = sat.get_answer();
		std::cout << "v";
		for (int i = 0; i < N; ++i) std::cout << " " << (ans[i] ? i + 1 : -(i + 1));
		std::cout << " 0" << std::endl;
	}
	return 0;
}