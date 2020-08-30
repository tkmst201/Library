---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Test/StronglyConnectedComponents.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/StronglyConnectedComponents.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-27 11:41:13+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/GraphTheory/StronglyConnectedComponents.cpp.html">GraphTheory/StronglyConnectedComponents.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "GraphTheory/StronglyConnectedComponents.cpp"

#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	StronglyConnectedComponents scc(N);
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	
	int sz = scc.build();
	printf("%d\n", sz);
	
	for (int i = 0; i < sz; ++i) {
		auto &lis = scc.get_map(i);
		printf("%d ", lis.size());
		for (int j = 0; j < lis.size(); ++j) printf("%d%c", lis[j], " \n"[j + 1 == lis.size()]);
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/StronglyConnectedComponents.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#line 1 "GraphTheory/StronglyConnectedComponents.cpp"
#include <vector>
#include <cassert>
#include <algorithm>

/*
last-updated: 2020/08/27

# 仕様
StronglyConnectedComponents(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを準備

StronglyConnectedComponentx(std::vector<std::vector<size_type>> g) :
	時間計算量: Θ(n + m)
	グラフ g で初期化

size_type size() const noexcept :
	時間計算量: Θ(1)
	頂点数を返す

void add_edge(size_type u, size_type v) :
	時間計算量: Θ(1)
	頂点 u から 頂点 v へ辺を張る

size_type build() :
	時間計算量: Θ(n + m)
	強連結成分分解を行う
	強連結成分の個数を返す

size_type get_rank(size_type i) :
	時間計算量: Θ(1)
	頂点 i が属する強連結成分のトポロジカル順序を返す

const std::vetor<size_type> & get_map(size_type i) :
	時間計算量: Θ(1)
	トポロジカル順序が i である強連結成分に属する頂点のリストを返す(昇順)

std::vector<std::vector<size_type>> get_graph() const :
	時間計算量: O(n + m log m)
	強連結成分分解後のグラフを作成して返す

# 参考
https://mathtrain.jp/kyorenketsu, 2020/08/27
*/

struct StronglyConnectedComponents {
	using size_type = std::size_t;
	
private:
	std::vector<std::vector<size_type>> g, rg;
	std::vector<size_type> rank; // [i] := 頂点 i が属する強連結成分のトポロジカル順序
	std::vector<std::vector<size_type>> idx_map; // [i][j] := トポロジカル順序が i の強連結成分に属する j 番目の頂点の番号(昇順)
	bool isbuilt = false;
	
public:
	StronglyConnectedComponents(size_type n) {
		g.resize(n);
		rg.resize(n);
	}
	
	StronglyConnectedComponents(std::vector<std::vector<size_type>> g) : g(g) {
		rg.resize(size());
		for (size_type i = 0; i < size(); ++i) {
			for (size_type j : g[i]) rg[j].emplace_back(i);
		}
	}
	
	size_type size() const noexcept {
		return g.size();
	}
	
	void add_edge(size_type u, size_type v) {
		assert(u < size());
		assert(v < size());
		g[u].emplace_back(v);
		rg[v].emplace_back(u);
		isbuilt = false;
	}
	
	size_type build() {
		std::vector<bool> visited;
		std::vector<size_type> back_num; // [i] := 帰りがけ順が i である頂点
		
		auto dfs = [&](auto &&self, size_type u) -> void {
			visited[u] = true;
			for (size_type v : g[u]) if (!visited[v]) self(self, v);
			size_type c = back_num.size();
			back_num.emplace_back(u);
		};
		
		visited.assign(size(), false);
		back_num.reserve(size());
		for (size_type i = 0; i < size(); ++i) if (!visited[i]) dfs(dfs, i);
		
		size_type c = 0;
		auto rdfs = [&](auto &&self, size_type u) -> void {
			visited[u] = true;
			rank[u] = c;
			for (size_type v : rg[u]) if (!visited[v]) self(self, v);
		};
		
		rank.resize(size());
		visited.assign(size(), false);
		for (size_type i = size(); i > 0; --i) {
			const size_type u = back_num[i - 1];
			if (visited[u]) continue;
			rdfs(rdfs, u);
			++c;
		}
		
		idx_map.assign(c, {});
		for (size_type i = 0; i < size(); ++i) idx_map[rank[i]].emplace_back(i);
		
		isbuilt = true;
		return idx_map.size();
	}
	
	size_type get_rank(size_type i) {
		assert(isbuilt);
		assert(i < size());
		return i;
	}
	
	const std::vector<size_type> & get_map(size_type i) {
		assert(isbuilt);
		assert(i < idx_map.size());
		return idx_map[i];
	}
	
	std::vector<std::vector<size_type>> get_graph() const {
		assert(isbuilt);
		std::vector<std::vector<size_type>> res(idx_map.size());
		for (size_type i = 0; i < idx_map.size(); ++i) {
			for (size_type j : idx_map[i]) {
				for (size_type v : g[j]) res[i].emplace_back(v);
			}
			std::sort(std::begin(res[i]), std::end(res[i]));
			res[i].erase(std::unique(std::begin(res[i]), std::end(res[i])), std::end(res[i]));
		}
		return res;
	}
};
#line 4 "Test/StronglyConnectedComponents.test.cpp"

#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	StronglyConnectedComponents scc(N);
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	
	int sz = scc.build();
	printf("%d\n", sz);
	
	for (int i = 0; i < sz; ++i) {
		auto &lis = scc.get_map(i);
		printf("%d ", lis.size());
		for (int j = 0; j < lis.size(); ++j) printf("%d%c", lis[j], " \n"[j + 1 == lis.size()]);
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

