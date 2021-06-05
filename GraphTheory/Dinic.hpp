#ifndef INCLUDE_GUARD_DINIC_HPP
#define INCLUDE_GUARD_DINIC_HPP

#include <vector>
#include <cassert>
#include <queue>
#include <type_traits>
#include <algorithm>
#include <limits>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/Dinic.hpp
 */
template<typename T>
struct Dinic {
	using cap_type = T;
	
private:
	static constexpr cap_type EPS = std::is_floating_point<cap_type>() ? 1e-8 : 0;
	static constexpr cap_type INF = std::numeric_limits<cap_type>::max();
	struct Edge {
		int to, rev;
		cap_type c;
		Edge(int to, int rev, const cap_type & c) : to(to), rev(rev), c(c) {}
	};
	using Graph = std::vector<std::vector<Edge>>;
	Graph g;
	
public:
	Dinic(int n) : g(n) {}
	
	int size() const noexcept {
		return g.size();
	}
	
	void add_edge(int u, int v, const cap_type & cap) {
		assert(0 <= u && u < size());
		assert(0 <= v && v < size());
		assert(cap >= 0);
		g[u].emplace_back(v, g[v].size(), cap);
		g[v].emplace_back(u, g[u].size() - 1, 0);
	}
	
	cap_type max_flow(int s, int t) {
		assert(0 <= s && s < size());
		assert(0 <= t && t < size());
		assert(s != t);
		cap_type res = 0;
		std::vector<int> iter, level;
		while (true) {
			level.assign(size(), -1);
			std::queue<int> que;
			level[s] = 0;
			que.emplace(s);
			while (!que.empty() && level[t] == -1) {
				const int u = que.front();
				que.pop();
				for (const auto & e : g[u]) {
					if (e.c <= EPS || level[e.to] != -1) continue;
					level[e.to] = level[u] + 1;
					if (e.to == t) break;
					que.emplace(e.to);
				}
			}
			if (level[t] == -1) break;
			iter.assign(size(), 0);
			auto dfs = [&](auto self, int u, cap_type f) -> cap_type {
				if (u == t) return f;
				if (level[u] >= level[t]) return 0;
				for (int & i = iter[u]; i < static_cast<int>(g[u].size()); ++i) {
					auto & e = g[u][i];
					if (e.c <= EPS || level[u] >= level[e.to]) continue;
					const cap_type cur = self(self, e.to, std::min(f, e.c));
					if (cur > EPS) {
						e.c -= cur;
						g[e.to][e.rev].c += cur;
						return cur;
					}
				}
				return 0;
			};
			cap_type f;
			while ((f = dfs(dfs, s, INF)) > EPS) res += f;
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_DINIC_HPP