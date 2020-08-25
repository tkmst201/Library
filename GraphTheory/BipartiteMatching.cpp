#include <vector>
#include <cassert>

/*
last-updated: 2020/03/05

unverified
二部グラフでの最大マッチングを求める

TODO: 計算量がアなので高速なものに切り替える

# 仕様
BipartiteMatching(size_type x, size_type y)
	時間計算量: Θ(x + y)
	集合 X, Y の二部グラフを準備
	|X| = x, |Y| = y

BipartiteMatching(size_type n)
	時間計算量: Θ(n)
	|X| = |Y| = y の二部グラフを準備

void add_edge(size_type a, size_type b) :
	時間計算量: Θ(1)
	頂点 a, 頂点 b 間に辺を張る

size_type build() :
	時間計算量: Θ(NE)
	最大マッチングを求める

std::vector<size_type> get() const :
	時間計算量: Θ(1)
	Y の各要素のマッチング先の配列を返す(事前に build() する必要がある)

# 参考
https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching, 2020/03/05
*/

struct BipartiteMatching {
	using size_type = std::size_t;
	
	BipartiteMatching(size_type x, size_type y) : x(x), y(y), g(x + y, std::vector<size_type>()) {}
	BipartiteMatching(size_type n) : BipartiteMatching(n, n) {}
	
	void add_edge(size_type a, size_type b) {
		assert(a < x && b < y);
		g[a].push_back(b + x);
		g[b + x].push_back(a);
	}
	
	size_type build() {
		match.assign(y, -1);
		size_type res = 0;
		for (size_type i = 0; i < x; ++i) {
			visited.assign(y, 0);
			if (dfs(i)) ++res;
		}
		return res;
	}
	
	std::vector<size_type> get() const {
		return match;
	}
	
private:
	size_type x, y;
	std::vector<std::vector<size_type>> g;
	std::vector<size_type> match;
	std::vector<bool> visited;
	
	bool dfs(size_type u) {
		for (auto v: g[u]) {
			v -= x;
			if (!visited[v]) {
				visited[v] = true;
				if (!~match[v] || dfs(match[v])) {
					match[v] = u;
					return true;
				}
			}
		}
		return false;
	}
};
