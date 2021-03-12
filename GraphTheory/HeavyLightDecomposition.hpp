#ifndef INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP
#define INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP

#include <vector>
#include <cassert>
#include <stack>
#include <utility>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/HeavyLightDecomposition.hpp
 */
struct HeavyLightDecomposition {
	using Graph = std::vector<std::vector<int>>;
	
private:
	int n;
	std::vector<int> par_;
	std::vector<int> heavy_, head_, heavy_size_, heavy_depth_;
	std::vector<int> tree_id_, roots_;
	std::vector<int> in_, out_;
	std::vector<std::vector<int>> par_dblng_;
	bool LCA;
	
public:
	HeavyLightDecomposition(const Graph & g, bool LCA = false)
		: HeavyLightDecomposition(g, -1, LCA) {}
	
	HeavyLightDecomposition(const Graph & g, int root, bool LCA)
		: n(g.size()), par_(n, -1), heavy_(n, -1), tree_id_(n, -1), in_(n, -1), out_(n, -1), LCA(LCA) {
		std::vector<int> sub_size(n, 0), next(n, -1);
		for (int i = 0; i < n; ++i) {
			if (tree_id_[i] != -1) continue;
			if (root != -1 && i != root) continue;
			tree_id_[i] = roots_.size();
			std::stack<int> stk;
			stk.emplace(i);
			while (!stk.empty()) {
				const int u = stk.top();
				stk.pop();
				if (sub_size[u]) {
					int mx_size = 0;
					for (int v : g[u]) {
						if (v == par_[u]) continue;
						sub_size[u] += sub_size[v];
						if (mx_size < sub_size[v]) mx_size = sub_size[v], next[u] = v;
					}
					continue;
				}
				sub_size[u] = 1;
				stk.emplace(u);
				for (int v : g[u]) {
					assert(0 <= v && v < n);
					assert(v != u);
					if (v == par_[u]) continue;
					par_[v] = u;
					tree_id_[v] = roots_.size();
					stk.emplace(v);
				}
			}
			roots_.emplace_back(i);
		}
		int euc = 0;
		for (int r : roots_) {
			heavy_[r] = head_.size();
			head_.emplace_back(r);
			heavy_size_.emplace_back(1);
			heavy_depth_.emplace_back(0);
			std::stack<std::pair<int, int>> stk;
			stk.emplace(r, 0);
			while (!stk.empty()) {
				const auto [u, i] = stk.top();
				stk.pop();
				if (i < static_cast<int>(g[u].size())) {
					stk.emplace(u, i + 1);
					const int v = g[u][i];
					if (v != par_[u] && v != next[u]) {
						heavy_[v] = head_.size();
						head_.emplace_back(v);
						heavy_size_.emplace_back(1);
						heavy_depth_.emplace_back(heavy_depth_[heavy_[u]] + 1);
						stk.emplace(v, 0);
					}
				}
				if (i == 0) {
					in_[u] = euc++;
					const int v = next[u];
					if (v != -1) {
						heavy_[v] = heavy_[u];
						++heavy_size_[heavy_[u]];
						stk.emplace(v, 0);
					}
				}
				if (i == static_cast<int>(g[u].size())) out_[u] = euc;
			}
		}
		if (!LCA) return;
		int max_depth = *std::max_element(begin(heavy_depth_), end(heavy_depth_));
		int lglg_n = 0;
		while ((1 << lglg_n) <= max_depth) ++lglg_n;
		par_dblng_.assign(lglg_n + 1, std::vector<int>(heavy_size(), -1));
		for (int i = 0; i < heavy_size(); ++i) par_dblng_[0][i] = par_[head_[i]] == -1 ? head_[i] : par_[head_[i]];
		for (int i = 0; i < lglg_n; ++i) {
			for (int j = 0; j < heavy_size(); ++j) {
				par_dblng_[i + 1][j] = par_dblng_[i][heavy_[par_dblng_[i][j]]];
			}
		}
	}
	
	int size() const noexcept {
		return n;
	}
	
	int par(int v) const noexcept {
		assert(0 <= v && v < size());
		return par_[v];
	}
	
	int tree_id(int v) const noexcept {
		assert(0 <= v && v < size());
		return tree_id_[v];
	}
	
	int tree_cnt() const noexcept {
		return roots_.size();
	}
	
	const std::vector<int> & trees() const noexcept {
		return roots_;
	}
	
	int heavy(int v) const noexcept {
		assert(0 <= v && v < size());
		return heavy_[v];
	}
	
	int head(int k) const noexcept {
		assert(0 <= k && k < heavy_size());
		return head_[k];
	}
	
	int heavy_size() const noexcept {
		return head_.size();
	}
	
	int heavy_size(int k) const noexcept {
		assert(0 <= k && k < heavy_size());
		return heavy_size_[k];
	}
	
	int heavy_depth(int k) const noexcept {
		assert(0 <= k && k < heavy_size());
		return heavy_depth_[k];
	}
	
	int in(int v) const noexcept {
		assert(0 <= v && v < size());
		return in_[v];
	}
	
	int out(int v) const noexcept {
		assert(0 <= v && v < size());
		return out_[v];
	}
	
	const std::vector<std::vector<int>> & par_dblng() const noexcept {
		assert(LCA);
		return par_dblng_;
	}
	
	std::pair<int, int> lca_heavy(int x, int y) const noexcept {
		assert(LCA);
		assert(0 <= x && x < size());
		assert(0 <= y && y < size());
		assert(tree_id_[x] == tree_id_[y]);
		if (heavy_[x] == heavy_[y]) return {x, y};
		const bool isswap = heavy_depth_[heavy_[x]] < heavy_depth_[heavy_[y]];
		if (isswap) std::swap(x, y);
		const int diff = heavy_depth_[heavy_[x]] - heavy_depth_[heavy_[y]];
		for (int i = 0; i < static_cast<int>(par_dblng_.size()); ++i) if (diff >> i & 1) x = par_dblng_[i][heavy_[x]];
		if (heavy_[x] == heavy_[y]) return isswap ? std::make_pair(y, x) : std::make_pair(x, y);
		for (int i = par_dblng_.size() - 1; i >= 0; --i) {
			const int p1 = par_dblng_[i][heavy_[x]], p2 = par_dblng_[i][heavy_[y]];
			if (heavy_[p1] != heavy_[p2]) x = p1, y = p2;
		}
		x = par_dblng_[0][heavy_[x]];
		y = par_dblng_[0][heavy_[y]];
		return isswap ? std::make_pair(y, x) : std::make_pair(x, y);
	}
	
	int lca(int x, int y) {
		assert(LCA);
		assert(0 <= x && x < size());
		assert(0 <= y && y < size());
		assert(tree_id_[x] == tree_id_[y]);
		const auto [a, b] = lca_heavy(x, y);
		return in_[a] < in_[b] ? a : b;
	}
};

#endif // INCLUDE_GUARD_HEAVY_LIGHT_DECOMPOSITION_HPP