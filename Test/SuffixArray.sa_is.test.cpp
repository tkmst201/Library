#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "String/SuffixArray.hpp"

#include <string>
#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	std::string S;
	std::cin >> S;
	
	auto sa = SuffixArray::sa_is(S);
	for (int i = 1; i <= S.size(); ++i) std::cout << sa[i] << " \n"[i == S.size()];
	return 0;
}