#ifndef INCLUDE_GUARD_BIPARTITE_MATCHING_HPP
#define INCLUDE_GUARD_BIPARTITE_MATCHING_HPP

/*
last-updated: 2020/08/26

二部グラフでの最大マッチングを求める
オーダーが怪しいが実際には高速に動く

N \leq 10^5, M \leq 2 \times 10^5 でも高速

TODO: 二部マッチング 頂点 or 辺 の追加や削除

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
	時間計算量: O(NE) ?? 謎だけど高速
	最大マッチングを求める
	最大マッチングの大きさを返す

std::vector<std::pair<size_type, size_type>> get_match() const :
	時間計算量: Θ(min{x, y})
	計算済みのマッチングのペアを返す (X の要素, Y の要素)

std::vector<size_type> get_match_x() const :
	時間計算量: Θ(x)
	X の各要素のマッチング先を記録した配列を返す(マッチングが存在しない場合 y)

std::vector<size_type> get_match_y() const :
	時間計算量: Θ(y)
	Y の各要素のマッチング先を記録した配列を返す(マッチングが存在しない場合 x)

# 参考
https://ikatakos.com/pot/programming_algorithm/graph_theory/bipartite_matching, 2020/03/05
https://snuke.hatenablog.com/entry/2019/05/07/013609, 2020/08/26
*/

#include <vector>
#include <cassert>
#include <utility>

struct BipartiteMatching {
	using size_type = std::size_t;
	
private:
	size_type x, y;
	std::vector<std::vector<size_type>> g;
	size_type match_;
	std::vector<size_type> match_x, match_y;
	std::vector<size_type> visited;
	bool isbuilt;
	
public:
	BipartiteMatching(size_type x, size_type y) : x(x), y(y), g(x + y, std::vector<size_type>()), isbuilt(false) {}
	BipartiteMatching(size_type n) : BipartiteMatching(n, n) {}
	
	void add_edge(size_type a, size_type b) {
		assert(a < x && b < y);
		g[a].push_back(b);
		isbuilt = false;
	}
	
	size_type build() {
		match_y.assign(y, x);
		match_x.assign(x, y);
		match_ = 0;
		size_type c = 0;
		visited.assign(x, 0);
		bool updated;
		do {
			updated = false;
			++c;
			for (size_type i = 0; i < x; ++i) {
				if (match_x[i] == y && dfs(i, c)) {
					++match_;
					updated = true;
				}
			}
		} while (updated);
		isbuilt = true;
		return match_;
	}
	
	size_type match() const {
		assert(isbuilt);
		return match_;
	}
	
	std::vector<std::pair<size_type, size_type>> get_match() const {
		assert(isbuilt);
		std::vector<std::pair<size_type, size_type>> res;
		if (x < y) {
			for (size_type i = 0; i < x; ++i) {
				if (match_x[i] != y) res.emplace_back(i, match_x[i]);
			}
		}
		else {
			for (size_type i = 0; i < y; ++i) {
				if (match_y[i] != x) res.emplace_back(match_y[i], i);
			}
		}
		return res;
	}
	
	std::vector<size_type> get_match_x() const {
		assert(isbuilt);
		return match_x;
	}
	
	std::vector<size_type> get_match_y() const {
		assert(isbuilt);
		return match_y;
	}
	
private:
	bool dfs(size_type u, size_type c) {
		if (visited[u] == c) return false;
		visited[u] = c;
		
		for (size_type v: g[u]) {
			if (match_y[v] == x || dfs(match_y[v], c)) {
				match_y[v] = u;
				match_x[u] = v;
				return true;
			}
		}
		return false;
	}
};

#endif // INCLUDE_GUARD_BIPARTITE_MATCHING_HPP