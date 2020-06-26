#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/*
last-updated: 2020/02/28

辺の容量は非負の実数である必要がある。

EdmondsKarp(size_type n) : 頂点数を n とする

size_type size() const noexcept : 頂点数を返す
void add_edge(size_type i, size_type j, value_type c) : u -> v へ容量 c の辺を張る
value_type max_flow(size_type s, size_type t) : O(VE^2) s -> t の最大フローを返す

参考 :
http://hos.ac/slides/20150319_flow.pdf, 2020/02/27
*/

template<typename T>
struct EdmondsKarp {
public:
	using value_type = T;
	using size_type = std::size_t;
	
	EdmondsKarp(size_type n) : g(std::vector<std::vector<Edge>>(n)) {}
	
	size_type size() const noexcept { return g.size(); }
	
	void add_edge(size_type i, size_type j, value_type c) {
		assert(i < size() && j < size() && c >= 0);
		g[i].push_back({j, g[j].size(), c});
		g[j].push_back({i, g[i].size() - 1, 0});
	}
	
	value_type max_flow(size_type s, size_type t) {
		assert(s < size() && t < size());
		value_type res = 0;
		std::vector<std::pair<size_type, size_type>> prv(size(), std::make_pair(-1, -1));
		
		while (true) {
			std::vector<size_type> visited;
			std::queue<size_type> que;
			prv[s].first = s;
			visited.push_back(s);
			que.push(s);
			while (!que.empty() && !~prv[t].first) {
				size_type u = que.front(); que.pop();
				for (size_type i = 0; i < g[u].size(); ++i) {
					size_type to = g[u][i].to;
					if (~prv[to].first || g[u][i].c <= EPS) continue;
					prv[to] = std::make_pair(u, i);
					visited.push_back(to);
					if (to == t) break;
					que.push(to);
				}
			}
			if (!~prv[t].first) break;
			value_type flow = g[prv[t].first][prv[t].second].c;
			for (size_type u = prv[t].first; u != prv[u].first; u = prv[u].first)
				flow = std::min(flow, g[prv[u].first][prv[u].second].c);
			for (size_type u = t; u != prv[u].first; u = prv[u].first) {
				g[prv[u].first][prv[u].second].c -= flow;
				g[u][g[prv[u].first][prv[u].second].rev].c += flow;
			}
			for (size_type u : visited) prv[u] = std::make_pair(-1, -1);
			res += flow;
		}
		return res;
	}
	
private:
	struct Edge { size_type to, rev; value_type c; };
	std::vector<std::vector<Edge>> g;
	static constexpr value_type EPS = std::is_floating_point<value_type>() ? 1e-6 : 0;
};
