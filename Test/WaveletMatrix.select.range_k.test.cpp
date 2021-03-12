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
	std::vector<int> idx_map(N);
	
	for (int i = 0; i < x.size(); ++i) {
		sy[sum[x[i] - 1] + cnt[x[i]]] = y[i];
		idx_map[sum[x[i] - 1] + cnt[x[i]]] = i;
		++cnt[x[i]];
	}
	
	WaveletMatrix<19, int, SuccintBitVector> wm(sy);
	
	auto compress_get = [](auto &&cv, auto &&x) {
		return std::lower_bound(begin(cv), end(cv), x) - std::begin(cv);
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
		// test range_min_k
		{
			for (int j = 1; j < points.size(); ++j) {
				assert(points[j - 1].first <= points[j].first);
				if (points[j - 1].first == points[j].first) assert(points[j - 1].second < points[j].second);
			}
			for (const auto [v, idx] : points) {
				assert(idx >= stx && idx < edx);
				assert(wm.access(idx) == v);
			}
		}
		std::vector<int> ans;
		for (auto &p : points) ans.emplace_back(idx_map[p.second]);
		std::sort(begin(ans), end(ans));
		for (int j = 0; j < ans.size(); ++j) printf("%d\n", ans[j]);
		putchar('\n');
		
		// test range_max_k
		{
			auto t_points = wm.range_max_k(stx, edx, sty, edy, edx - stx);
			using wm_type = WaveletMatrix<19, int, SuccintBitVector>;
			std::vector<std::pair<wm_type::value_type, wm_type::size_type>> res;
			for (const auto & p : t_points) {
				const unsigned int c = wm.rank(0, stx, p.first);
				for (int j = 0; j < p.second; ++j) res.emplace_back(p.first, wm.select(c + j + 1, p.first) - 1);
			}
			for (int j = 1; j < res.size(); ++j) {
				assert(res[j - 1].first >= res[j].first);
				if (res[j - 1].first == res[j].first) assert(res[j - 1].second < res[j].second);
			}
			for (const auto [v, idx] : res) {
				assert(idx >= stx && idx < edx);
				assert(wm.access(idx) == v);
			}
			assert(points.size() == res.size());
		}
	}
}
