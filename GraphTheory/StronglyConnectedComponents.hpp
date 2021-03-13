#ifndef INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP
#define INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP

#include <vector>
#include <cassert>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp
 */
struct StronglyConnectedComponents {
	using Graph = std::vector<std::vector<int>>;
	
private:
	int n;
	std::vector<int> rank_;
	std::vector<std::vector<int>> rank_list_;
	
public:
	explicit StronglyConnectedComponents(const Graph & g) : n(g.size()) {
		Graph rg(n);
		for (int i = 0; i < n; ++i) {
			for (int j : g[i]) {
				assert(0 <= j && j < n);
				rg[j].emplace_back(i);
			}
		}
		std::vector<bool> visited(n, false);
		std::vector<int> num;
		auto dfs = [&](auto self, int u) -> void {
			visited[u] = true;
			for (int v : g[u]) if (!visited[v]) self(self, v);
			num.emplace_back(u);
		};
		for (int i = 0; i < n; ++i) if (!visited[i]) dfs(dfs, i);
		int cnt = 0;
		visited.assign(n, false);
		rank_.assign(n, -1);
		auto rdfs = [&](auto self, int u) -> void {
			visited[u] = true;
			rank_[u] = cnt;
			for (int v : rg[u]) if (!visited[v]) self(self, v);
		};
		for (int i = n - 1; i >= 0; --i) if (!visited[num[i]]) rdfs(rdfs, num[i]), ++cnt;
		rank_list_.assign(cnt, {});
		for (int i = 0; i < n; ++i) rank_list_[rank_[i]].emplace_back(i);
	}
	
	int size() const noexcept {
		return n;
	}
	
	int scc_size() const noexcept {
		return rank_list_.size();
	}
	
	int scc_size(int k) const noexcept {
		assert(0 <= k && k < scc_size());
		return rank_list_[k].size();
	}
	
	int rank(int u) const noexcept {
		assert(0 <= u && u < size());
		return rank_[u];
	}
	
	const std::vector<int> & rank_list(int k) const noexcept {
		assert(0 <= k && k < scc_size());
		return rank_list_[k];
	}
	
	Graph get_graph(const Graph & g) const {
		Graph res(scc_size());
		for (int i = 0; i < scc_size(); ++i) {
			for (int j : rank_list_[i]) for (int v : g[j]) if (rank(v) != i) res[i].emplace_back(rank(v));
			std::sort(begin(res[i]), end(res[i]));
			res[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_STRONGLY_CONNECTED_COMPONENTS_HPP