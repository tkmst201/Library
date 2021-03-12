#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2426?year=2012"

#include "DataStructure/SuccintBitVector.hpp"
#include "DataStructure/WaveletMatrix.hpp"

#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int INF = 1'000'000'001;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	std::vector<int> x(N), y(N), cx, cy;
	for (int i = 0; i < N; ++i) scanf("%d %d", &x[i], &y[i]);
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		cv.emplace_back(INF);
		cv.emplace_back(-INF);
		std::sort(begin(cv), end(cv));
		cv.erase(std::unique(begin(cv), end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(begin(cv), end(cv), u) - std::begin(cv);
	};
	
	compress(x, cx);
	compress(y, cy);
	
	// 同じ x 座標でも wavelet matrix 上では異なる index になるように修正する必要がある
	std::vector<int> sum(cx.size()); // [i] := x[j] が i 以下であるような j の個数
	for (int i = 0; i < x.size(); ++i) ++sum[x[i]];
	for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
	
	std::vector<int> cnt(cx.size()), sy(N); // sy[i] := x 座標が i 番目に小さい点の y 座標(x 座標が同一の場合にも差をつける)
	for (int i = 0; i < x.size(); ++i) sy[sum[x[i] - 1] + cnt[x[i]]++] = y[i];
	
	WaveletMatrix<13, int, SuccintBitVector> wm(sy);
	
	auto compress_get = [](auto &&cv, auto &&x) {
		return std::lower_bound(begin(cv), end(cv), x) - std::begin(cv);
	};
	
	for (int i = 0; i < M; ++i) {
		int sty, stx, edy, edx;
		scanf("%d %d %d %d", &stx, &sty, &edx, &edy);
		++edx; ++edy;
		sty = compress_get(cy, sty);
		stx = compress_get(cx, stx);
		edy = compress_get(cy, edy);
		edx = compress_get(cx, edx);
		printf("%llu\n", wm.range_frequency(sum[stx - 1], sum[edx - 1], sty, edy));
	}
}