#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C"

#include "DataStructure/SuccintBitVector.hpp"
#include "DataStructure/WaveletMatrix.hpp"

#include <cstdio>
#include <vector>

constexpr int INF = 1'000'000'001;

int main() {
	int N;
	scanf("%d", &N);
	
	std::vector<int> x(N), y(N), cx, cy;
	for (int i = 0; i < N; ++i) scanf("%d %d", &x[i], &y[i]);
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		cv.emplace_back(INF);
		cv.emplace_back(-INF);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	compress(x, cx);
	compress(y, cy);
	
	// 同じ x 座標でも wavelet matrix 上では異なる index になるように修正する必要がある
	std::vector<int> sum(cx.size()); // [i] := x[j] が i 以下であるような j の個数
	for (int i = 0; i < x.size(); ++i) ++sum[x[i]];
	for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
	
	std::vector<int> cnt(cx.size()), sy(N); // sy[i] := x 座標が i 番目に小さい点の y 座標(x 座標が同一の場合にも差をつける)
	std::vector<int> idx_map(N);
	
	for (int i = 0; i < x.size(); ++i) {
		sy[sum[x[i] - 1] + cnt[x[i]]] = y[i];
		idx_map[sum[x[i] - 1] + cnt[x[i]]] = i;
		++cnt[x[i]];
	}
	
	WaveletMatrix<19, int, SuccintBitVector> wm(sy);
	
	auto compress_get = [](auto &&cv, auto &&x) {
		return std::lower_bound(std::begin(cv), std::end(cv), x) - std::begin(cv);
	};
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int sty, stx, edy, edx;
		scanf("%d %d %d %d", &stx, &edx, &sty, &edy);
		++edx; ++edy;
		sty = compress_get(cy, sty);
		stx = compress_get(cx, stx); stx = sum[stx - 1];
		edy = compress_get(cy, edy);
		edx = compress_get(cx, edx); edx = sum[edx - 1];

		auto points = wm.get_rect(stx, edx, sty, edy);
		std::vector<int> ans;
		for (auto &p : points) ans.emplace_back(idx_map[p.first]);
		std::sort(begin(ans), end(ans));
		for (int j = 0; j < ans.size(); ++j) printf("%d\n", ans[j], " \n"[j + 1 == ans.size()]);
		putchar('\n');
	}
	
	return 0;
}
