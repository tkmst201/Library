#ifndef INCLUDE_GUARD_BIPARTITE_MATCHING_HPP
#define INCLUDE_GUARD_BIPARTITE_MATCHING_HPP

#include <vector>
#include <cassert>
#include <utility>
#include <queue>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/BipartiteMatching.hpp
 */
struct BipartiteMatching {
private:
	using Graph = std::vector<std::vector<int>>;
	Graph g;
	int x, y;
	bool isswap;
	int max_maching_;
	std::vector<int> match_x, match_y;
	bool isbuilt = false;
	
public:
	BipartiteMatching(int x, int y)
		: g(std::min(x, y)), x(std::min(x, y)), y(std::max(x, y)), isswap(x > y) {}
	
	BipartiteMatching(int n) : BipartiteMatching(n, n) {}
	
	void add_edge(int a, int b) {
		if (isswap) std::swap(a, b);
		assert(0 <= a && a < x);
		assert(0 <= b && b < y);
		g[a].emplace_back(b);
		isbuilt = false;
	}
	
	void build() {
		match_y.assign(y, -1);
		match_x.assign(x, -1);
		max_maching_ = 0;
		int c = 1;
		std::vector<int> visited(x, 0);
		bool update = false;
		auto dfs = [&](auto self, int u) -> bool {
			visited[u] = c;
			for (int v : g[u]) if (match_y[v] == -1) { match_y[v] = u; match_x[u] = v; return true; }
			for (int v : g[u]) if (visited[match_y[v]] >= 0 && visited[match_y[v]] != c && self(self, match_y[v])) { match_y[v] = u; match_x[u] = v; return true; }
			if (!update) visited[u] = -1;
			return false;
		};
		std::queue<int> que;
		for (int i = 0; i < x; ++i) {
			if (dfs(dfs, i)) ++max_maching_, update = true;
			else if (update) que.emplace(i);
		}
		while (!que.empty()) {
			++c;
			const int n = que.size();
			update = false;
			for (int i = 0; i < n; ++i) {
				const int u = que.front();
				que.pop();
				if (match_x[u] == -1 && visited[u] != c && dfs(dfs, u)) {
					++max_maching_;
					update = true;
				}
				else if (update) que.emplace(u);
			}
		}
		isbuilt = true;
	}
	
	int max_matching() const noexcept {
		assert(isbuilt);
		return max_maching_;
	}
	
	std::vector<std::pair<int, int>> matching() const {
		assert(isbuilt);
		std::vector<std::pair<int, int>> res;
		for (int i = 0; i < x; ++i) {
			if (match_x[i] == -1) continue;
			if (isswap) res.emplace_back(match_x[i], i);
			else res.emplace_back(i, match_x[i]);
		}
		return res;
	}
	
	int matching_x(int k) const noexcept {
		assert(isbuilt);
		assert(0 <= k && k < (isswap ? y : x));
		return isswap ? match_y[k] : match_x[k];
	}
	
	int matching_y(int k) const noexcept {
		assert(isbuilt);
		assert(0 <= k && k < (isswap ? x : y));
		return isswap ? match_x[k] : match_y[k];
	}
};

#endif // INCLUDE_GUARD_BIPARTITE_MATCHING_HPP