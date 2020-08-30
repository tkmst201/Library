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


# :warning: GraphTheory/EdmondsKarp.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/EdmondsKarp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 21:49:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/*
last-updated: 2020/02/28

辺の容量は非負の実数である必要がある。

# 仕様
EdmondsKarp(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを準備

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type i, size_type j, value_type c) :
	時間計算量: Θ(1)
	u -> v へ容量 c の辺を張る

value_type max_flow(size_type s, size_type t) :
	時間計算量: O(VE^2)
	s -> t の最大フローを返す

# 参考
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/EdmondsKarp.cpp"
#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/*
last-updated: 2020/02/28

辺の容量は非負の実数である必要がある。

# 仕様
EdmondsKarp(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを準備

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type i, size_type j, value_type c) :
	時間計算量: Θ(1)
	u -> v へ容量 c の辺を張る

value_type max_flow(size_type s, size_type t) :
	時間計算量: O(VE^2)
	s -> t の最大フローを返す

# 参考
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

