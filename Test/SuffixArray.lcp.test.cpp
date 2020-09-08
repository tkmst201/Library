#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "String/SuffixArray.hpp"

#include <string>
#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	std::string S;
	std::cin >> S;
	
	SuffixArray sa(S);
	
	using ll = long long;
	ll ans = (ll)S.size() * (S.size() + 1) / 2;
	const auto & lcp = sa.get_lcp();
	for (auto l : lcp) ans -= l;
	std::cout << ans << std::endl;
	
	return 0;
}