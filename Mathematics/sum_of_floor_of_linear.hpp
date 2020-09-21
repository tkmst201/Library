#ifndef INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP
#define INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP

/*
last-updated: 2020/09/11

# 仕様
template<typename T>
T sum_of_floor_of_linear(T N, T M, T A, T B) :
	時間計算量: O(log min{M, A})
	\Sum_{i = 0}^{N - 1} floor((A \times i + B) / M) を求める

# 参考
https://twitter.com/kyopro_friends/status/1304063876019793921?s=20, 2020/09/11
https://qiita.com/HNJ/items/564f15316719209df73c, 2020/09/10
*/

#include <utility>
#include <cassert>

namespace tk {
template<typename T>
T sum_of_floor_of_linear(T N, T M, T A, T B) {
	using value_type = T;
	value_type res = 0;
	assert(N >= 0);
	assert(M > 0);
	assert(A >= 0);
	assert(B >= 0);
	
	if (B >= M) {
		value_type d = B / M;
		res += d * N;
		B -= d * M;
	}
	if (N == 0) return res;
	
	while (true) {
		if (A >= M) {
			value_type d = A / M;
			res += N * (N - 1) / 2 * d;
			A -= d * M;
		}
		if (A == 0) break;
		
		value_type ymax = (A * N + B) / M;
		if (ymax == 0) break;
		
		value_type t = M * ymax - B;
		res += ymax * (N - (t + A - 1) / A);
		B = A - t % A;
		if (B == A) B -= A;
		N = ymax;
		std::swap(A, M);
	}
	return res;
}
} // namespace tk

#endif // INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP