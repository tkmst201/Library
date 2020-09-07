#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_D"

#include "String/SuffixArray.hpp"

#include <string>
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string T;
	int Q;
	cin >> T >> Q;
	
	SuffixArray sa(T);
	while (Q--) {
		string P;
		cin >> P;
		cout << (sa.search(P) != sa.size()) << endl;
	}
	
	return 0;
}