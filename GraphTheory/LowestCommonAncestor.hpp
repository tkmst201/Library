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
	using size_type = std::size_t;
	using Graph = std::vector<std::vector<int>>;
	
	Graph g;
	bool isbuilt;
	int logn = 0;
	std::vector<std::vector<int>> par;
	std::vector<int> depth_;
	
	explicit LowestCommonAncestor(size_type n) : g(n), isbuilt(false) {}
	
	explicit LowestCommonAncestor(const Graph & g) : g(g), isbuilt(false) {}
	
	size_type size() const noexcept {
		return g.size();
	}
	
	const Graph & get_graph() const noexcept {
		return g;
	}
	
	void add_edge(int u, int v) {
		assert(0 <= u && u < size());
		assert(0 <= v && v < size());
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		isbuilt = false;
	}
	
	void add_directed_edge(int u, int v) {
		assert(0 <= u && u < size());
		assert(0 <= v && v < size());
		g[u].emplace_back(v);
		isbuilt = false;
	}
	
	void clear() noexcept {
		g.clear();
		par.clear();
		depth_.clear();
		isbuilt = false;
	}
	
	void build(int root = 0) {
		assert(0 <= root && root < size());
		logn = 1;
		while ((1 << logn) + 1 <= size()) ++logn;
		par.assign(logn, std::vector<int>(size()));
		depth_.assign(size(), 0);
		std::stack<std::pair<int, int>> stk;
		par[0][root] = root;
		stk.emplace(root, root);
		while (!stk.empty()) {
			auto [u, p] = stk.top();
			stk.pop();
			for (int v : g[u]) {
				if (v == p) continue;
				par[0][v] = u;
				depth_[v] = depth_[u] + 1;
				stk.emplace(v, u);
			}
		}
		for (int i = 1; i < logn; ++i) {
			for (int j = 0; j < size(); ++j) par[i][j] = par[i - 1][par[i - 1][j]];
		}
		isbuilt = true;
	}
	
	int find(int a, int b) const noexcept {
		assert(isbuilt);
		assert(0 <= a && a < size());
		assert(0 <= b && b < size());
		assert(par[0][a] != size());
		assert(par[0][b] != size());
		if (depth_[a] < depth_[b]) std::swap(a, b);
		a = parent(a, depth_[a] - depth_[b]);
		if (a == b) return a;
		for (int i = logn - 1; i >= 0; --i) {
			if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b]; 
		}
		return par[0][a];
	}
	
	int parent(int u, int k = 1) const noexcept {
		assert(isbuilt);
		assert(0 <= u && u < size());
		assert(k <= depth_[u]);
		assert(par[0][u] != size());
		for (int i = 0; i < logn; ++i) if (k >> i & 1) u = par[i][u];
		return u;
	}
	
	int depth(int u) const noexcept {
		assert(isbuilt);
		assert(0 <= u && u < size());
		assert(par[0][u] != size());
		return depth_[u];
	}
};

#endif // INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP