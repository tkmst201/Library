#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "String/RollingHash.hpp"

#include <string>
#include <iostream>
using namespace std;

int main() {
	string T, P;
	cin >> T >> P;
	RollingHash rh(T);
	auto phash = RollingHash(P).hash(0, 0, P.size());
	
	for (int i = P.size(); i <= T.size(); ++i) {
		if (rh.hash(0, i - P.size(), i) == phash) {
			printf("%d\n", i - P.size());
		}
	}
	
	return 0;
}