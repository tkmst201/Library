#ifndef INCLUDE_GUARD_EDMONDS_KARP_HPP
#define INCLUDE_GUARD_EDMONDS_KARP_HPP

#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/EdmondsKarp.hpp
 */
template<typename T>
struct EdmondsKarp {
	using cap_type = T;
	
private:
	static constexpr cap_type EPS = std::is_floating_point<cap_type>() ? 1e-8 : 0;
	struct Edge {
		int to, rev;
		cap_type c;
		Edge(int to, int rev, const cap_type & c) : to(to), rev(rev), c(c) {}
	};
	using Graph = std::vector<std::vector<Edge>>;
	Graph g;
	
public:
	explicit EdmondsKarp(int n) : g(n) {}
	
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
		std::vector<std::pair<int, int>> prv(size(), std::make_pair(-1, -1));
		while (true) {
			std::vector<int> visited;
			std::queue<int> que;
			prv[s].first = s;
			visited.emplace_back(s);
			que.emplace(s);
			while (!que.empty() && prv[t].first == -1) {
				const int u = que.front();
				que.pop();
				for (int i = 0; i < static_cast<int>(g[u].size()); ++i) {
					const int to = g[u][i].to;
					if (prv[to].first != -1 || g[u][i].c <= EPS) continue;
					prv[to] = {u, i};
					visited.emplace_back(to);
					if (to == t) break;
					que.emplace(to);
				}
			}
			if (prv[t].first == -1) break;
			cap_type flow = g[prv[t].first][prv[t].second].c;
			for (int u = prv[t].first; u != prv[u].first; u = prv[u].first) {
				flow = std::min(flow, g[prv[u].first][prv[u].second].c);
			}
			for (int u = t; u != prv[u].first; u = prv[u].first) {
				const auto [v, eidx] = prv[u];
				g[v][eidx].c -= flow;
				g[u][g[v][eidx].rev].c += flow;
			}
			for (int u : visited) prv[u] = {-1, -1};
			res += flow;
		}
		return res;
	}
};

#endif // INCLUDE_GUARD_EDMONDS_KARP_HPP