#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "Mathematics/ModInt.hpp"
#include "Mathematics/Matrix.hpp"

#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	Matrix<ModInt<998244353>> mat(N, N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> mat[i][j];
	std::cout << mat.det() << std::endl;
}
