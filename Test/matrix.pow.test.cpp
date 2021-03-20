#define PROBLEM "https://yukicoder.me/problems/no/891"

#include "Mathematics/ModInt.hpp"
#include "Mathematics/Matrix.hpp"

#include <cstdio>

int main() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	using Mat = Matrix<ModInt<1000000007>>;
	Mat mat({{a, b}, {1, 0}});
	mat = mat.pow(n);
	printf("%d\n", (mat * Mat({{1}, {0}}))[1][0].val());
}
