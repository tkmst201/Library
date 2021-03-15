#ifndef INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP
#define INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP

#include <algorithm>
#include <cmath>

/**
 * @brief https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp
 */
namespace tk {
template<class CD, class FFT>
std::vector<long long> frequency_table_of_tree_distance(const typename CD::Graph & g) {
	using value_type = long long;
	CD cd(g);
	const int n = g.size();
	auto dfs = [&](auto self, int centroid) -> std::vector<value_type> {
		cd.done(centroid);
		bool iso = true;
		std::vector<value_type> res(1, 0), sum_table(1, 1);
		for (auto r : g[centroid]) {
			if (!cd.exist(r)) continue;
			iso = false;
			std::vector<value_type> table(1, 0);
			auto dfs2 = [&](auto && self, int u, int p, int d) -> void {
				if (table.size() == d) table.emplace_back(1);
				else ++table[d];
				for (auto v : g[u]) if (v != p && cd.exist(v)) self(self, v, u, d + 1);
			};
			dfs2(dfs2, r, -1, 1);
			for (int i = 1; i < std::min(sum_table.size(), table.size()); ++i) sum_table[i] += table[i];
			for (int i = sum_table.size(); i < table.size(); ++i) sum_table.emplace_back(table[i]);
			auto mul = FFT::multiply(table, table);
			for (int i = 1; i < std::min(res.size(), mul.size()); ++i) res[i] -= static_cast<value_type>(std::round(mul[i]));
			for (int i = res.size(); i < mul.size(); ++i) res.emplace_back(-static_cast<value_type>(std::round(mul[i])));
			table = self(self, cd.centroids(g, r)[0]);
			for (int i = 1; i < std::min(res.size(), table.size()); ++i) res[i] += table[i];
			for (int i = res.size(); i < table.size(); ++i) res.emplace_back(table[i]);
		}
		if (iso) res;
		auto mul = FFT::multiply(sum_table, sum_table);
		for (int i = 1; i < std::min(res.size(), mul.size()); ++i) res[i] += static_cast<value_type>(std::round(mul[i]));
		for (int i = res.size(); i < mul.size(); ++i) res.emplace_back(static_cast<value_type>(std::round(mul[i])));
		return res;
	};
	auto res = dfs(dfs, 0);
	for (int i = 1; i < res.size(); ++i) res[i] /= 2;
	res[0] = n;
	return res;
}
} // namespace tk

#endif // INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP