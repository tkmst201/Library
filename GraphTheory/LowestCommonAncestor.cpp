#include <vector>
#include <cassert>
#include <utility>
#include <iostream>

/*
last-updated: 2020/03/03

LowestCommonAncestor(size_t)
LowestCommonAncestor(vector<vector<int>>, int rootNode = 0, bool isper = true) : isper=falseでbuildしない

void add_edge(int u, int v) : u -> v Θ(1)
void clear() : クリア
void build(int rootNode) : Θ(N log N) 構築
int find(int a, int b) const : Θ(log N) 頂点 a , 頂点 b の LCA を求める
int query(int a, int b) const : Θ(log N) パス a - b の長さを求める
*/

struct LowestCommonAncestor {
public:
	LowestCommonAncestor(std::size_t _size) : _size(_size) {
		g.resize(_size);
		isbuilt = false;
	}
	LowestCommonAncestor(std::vector<std::vector<int> > g, int rootNode = 0, bool isper = true) : g(g) {
		_size = g.size();
		if (isper) build(rootNode);
	};
	
	void add_edge(int s, int t) {
		g[s].push_back(t);
	}
	
	void clear() {
		_size = 0;
		g.clear();
		par.clear();
		depth.clear();
		isbuilt = false;
	}
	
	void build(int rootNode = 0) {
		logsize = 1;
		while (1<<logsize < _size) ++logsize;
		depth.assign(_size, -1);
		par.assign(logsize, std::vector<int>(_size, -1));
		
		depth[rootNode] = 0;
		dfs(rootNode, -1);
		for (int i = 1; i < logsize; ++i) {
			for (int j = 0; j < _size; ++j) {
				if (~par[i - 1][j]) par[i][j] = par[i - 1][ par[i - 1][j] ];
			}
		}
		isbuilt = true;
	}
	
	int find(int a, int b) const {
		assert(isbuilt);
		if (depth[a] < depth[b]) std::swap(a, b);
		
		int up = depth[a] - depth[b];
		for (int i = 0; i < logsize; ++i) if (up >> i & 1) a = par[i][a];
		if (a == b) return a;
		for (int i = logsize - 1; i >= 0; i--) {
			if (par[i][a] != par[i][b]) {
				a = par[i][a];
				b = par[i][b];
			}
		}
		return par[0][a];
	}
	
	int query(int a, int b) const {
		assert(isbuilt);
		return depth[a] + depth[b] - 2 * depth[find(a, b)];
	}
	
private:
	std::size_t _size, logsize;
	std::vector<std::vector<int> > g, par;
	std::vector<int> depth;
	bool isbuilt;
	
	void dfs(int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			depth[v] = depth[u] + 1;
			par[0][v] = u;
			dfs(v, u);
		}
	}
};

/*
int main() {
	std::cin.tie(0);
	
	int N, Q;
	std::cin >> N >> Q;
	LowestCommonAncestor lca(N);
	for (int i = 1; i < N; ++i) {
		int p; std::cin >> p;
		lca.add_edge(p, i);
	}
	lca.build();
	
	while (Q--) {
		int u, v;
		std::cin >> u >> v;
		std::cout << lca.find(u, v) << '\n';
	}
	
	return 0;
}
*/