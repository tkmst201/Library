#ifndef INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP
#define INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP

#include <vector>
#include <cassert>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp
 */
struct CentroidDecomposition {
	using Graph = std::vector<std::vector<int>>;
	
private:
	int n;
	std::vector<bool> done_;
	std::vector<int> sz;
	
public:
	explicit CentroidDecomposition(const Graph & g) : n(g.size()), done_(size(), false), sz(size(), 0) {
		for (int i = 0; i < size(); ++i) for (int j : g[i]) assert(0 <= j && j < size());
	}
	
	int size() const noexcept {
		return n;
	}
	
	bool exist(int u) const noexcept {
		assert(0 <= u && u < size());
		return !done_[u];
	}
	
	std::vector<int> centroids(const Graph & g, int root) {
		assert(0 <= root && root < size());
		assert(exist(root));
		auto dfs = [&](auto self, int u, int p) -> void {
			sz[u] = 1;
			for (auto v : g[u]) if (v != p && exist(v)) self(self, v, u), sz[u] += sz[v];
		};
		dfs(dfs, root, -1);
		int u = root, p = -1;
		std::vector<int> res;
		while (true) {
			bool update = false;
			for (auto v : g[u]) {
				if (v == p || !exist(v)) continue;
				if (sz[v] * 2 > sz[root]) { p = u; u = v; update = true; break; }
				if (sz[v] * 2 == sz[root]) res.emplace_back(v);
			}
			if (update) continue;
			res.emplace_back(u);
			break;
		}
		return res;
	}
	
	void done(int v) noexcept {
		assert(0 <= v && v < size());
		done_[v] = true;
	}
	
	void clear() {
		std::fill(begin(done_), end(done_), false);
	}
};

#endif // INCLUDE_GUARD_CENTROID_DECOMPOSITION_HPP