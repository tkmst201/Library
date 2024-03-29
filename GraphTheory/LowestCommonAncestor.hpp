#ifndef INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP
#define INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP

#include <vector>
#include <cassert>
#include <utility>
#include <cstdint>
#include <stack>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/LowestCommonAncestor.hpp
 */
struct LowestCommonAncestor {
	using Graph = std::vector<std::vector<int>>;
	
private:
	int n, logn;
	std::vector<std::vector<int>> par;
	std::vector<int> depth_;
	
public:
	LowestCommonAncestor(const Graph & g, int root = 0) : n(g.size()) {
		assert(0 <= root && root < n);
		logn = 1;
		while ((1 << logn) + 1 <= n) ++logn;
		par.assign(logn, std::vector<int>(n, -1));
		depth_.assign(n, 0);
		std::stack<std::pair<int, int>> stk;
		par[0][root] = root;
		stk.emplace(root, root);
		while (!stk.empty()) {
			const auto [u, p] = stk.top();
			stk.pop();
			for (int v : g[u]) {
				if (v == p) continue;
				assert(0 <= v && v < n);
				par[0][v] = u;
				depth_[v] = depth_[u] + 1;
				stk.emplace(v, u);
			}
		}
		for (int i = 1; i < logn; ++i) {
			for (int j = 0; j < n; ++j) par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	
	int size() const noexcept {
		return n;
	}
	
	int find(int a, int b) const noexcept {
		assert(0 <= a && a < size());
		assert(0 <= b && b < size());
		assert(par[0][a] != -1);
		assert(par[0][b] != -1);
		if (depth_[a] < depth_[b]) std::swap(a, b);
		a = parent(a, depth_[a] - depth_[b]);
		if (a == b) return a;
		for (int i = logn - 1; i >= 0; --i) {
			if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b]; 
		}
		return par[0][a];
	}
	
	int parent(int u, int k = 1) const noexcept {
		assert(0 <= u && u < size());
		assert(0 <= k && k <= depth_[u]);
		assert(par[0][u] != -1);
		for (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];
		return u;
	}
	
	int depth(int u) const noexcept {
		assert(0 <= u && u < size());
		assert(par[0][u] != -1);
		return depth_[u];
	}
};

#endif // INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP