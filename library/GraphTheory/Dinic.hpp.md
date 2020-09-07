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


# :heavy_check_mark: GraphTheory/Dinic.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/Dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/Dinic.test.cpp.html">Test/Dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_DINIC_HPP
#define INCLUDE_GUARD_DINIC_HPP

#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/*
last-updated: 2020/03/03

辺の容量は非負の実数である必要がある。

# 仕様
Dinic(size_type n) :
	時間計算量: Θ(n)
	グラフの頂点数を n とする

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type i, size_type j, value_type c) :
	時間計算量: Θ(1)
	頂点 i -> 頂点 j へ容量 c の辺を張る

value_type max_flow(size_type s, size_type t) :
	時間計算量: O(V^2 E)
	頂点 s -> 頂点 t の最大フローを返す

# 参考
http://hos.ac/slides/20150319_flow.pdf, 2020/03/03
http://vartkw.hatenablog.com/entry/2016/12/02/002703, 2020/03/03
*/

template<typename T>
struct Dinic {
public:
	using value_type = T;
	using size_type = std::size_t;
	
	Dinic(size_type n) : g(std::vector<std::vector<Edge>>(n)) {}
	
	size_type size() const noexcept { return g.size(); }
	
	void add_edge(size_type i, size_type j, value_type c) {
		assert(i < size() && j < size() && c >= 0);
		g[i].push_back({j, g[j].size(), c});
		g[j].push_back({i, g[i].size() - 1, 0});
	}
	
	value_type max_flow(size_type s, size_type t) {
		value_type res = 0;
		while (bfs(s), ~level[t]) {
			iter.assign(size(), 0);
			value_type f;
			while ((f = dfs(s, t, INF)) > EPS) res += f;
		}
		return res;
	}
	
private:
	struct Edge { size_type to, rev; value_type c; };
	std::vector<std::vector<Edge>> g;
	static constexpr value_type EPS = std::is_floating_point<value_type>() ? 1e-6 : 0;
	static constexpr value_type INF = 1e9 + 100;
	std::vector<size_type> iter, level;
	
	void bfs(size_type s) {
		level.assign(size(), -1);
		std::queue<size_type> que;
		que.push(s);
		level[s] = 0;
		while (!que.empty()) {
			size_type u = que.front(); que.pop();
			for (Edge & e : g[u]) {
				if (e.c <= EPS || ~level[e.to]) continue;
				que.push(e.to);
				level[e.to] = level[u] + 1;
			}
		}
	}
	
	value_type dfs(size_type u, size_type t, value_type f) {
		if (u == t) return f;
		for (size_type & i = iter[u]; i < g[u].size(); ++i) {
			const Edge & e = g[u][i];
			if (e.c <= EPS || level[u] >= level[e.to]) continue;
			value_type cur = dfs(e.to, t, std::min(f, e.c));
			if (cur > EPS) {
				g[u][i].c -= cur;
				g[e.to][e.rev].c += cur;
				return cur;
			}
		}
		return 0;
	}
};

#endif // INCLUDE_GUARD_DINIC_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/Dinic.hpp"



#include <vector>
#include <cassert>
#include <queue>
#include <utility>
#include <type_traits>
#include <algorithm>

/*
last-updated: 2020/03/03

辺の容量は非負の実数である必要がある。

# 仕様
Dinic(size_type n) :
	時間計算量: Θ(n)
	グラフの頂点数を n とする

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type i, size_type j, value_type c) :
	時間計算量: Θ(1)
	頂点 i -> 頂点 j へ容量 c の辺を張る

value_type max_flow(size_type s, size_type t) :
	時間計算量: O(V^2 E)
	頂点 s -> 頂点 t の最大フローを返す

# 参考
http://hos.ac/slides/20150319_flow.pdf, 2020/03/03
http://vartkw.hatenablog.com/entry/2016/12/02/002703, 2020/03/03
*/

template<typename T>
struct Dinic {
public:
	using value_type = T;
	using size_type = std::size_t;
	
	Dinic(size_type n) : g(std::vector<std::vector<Edge>>(n)) {}
	
	size_type size() const noexcept { return g.size(); }
	
	void add_edge(size_type i, size_type j, value_type c) {
		assert(i < size() && j < size() && c >= 0);
		g[i].push_back({j, g[j].size(), c});
		g[j].push_back({i, g[i].size() - 1, 0});
	}
	
	value_type max_flow(size_type s, size_type t) {
		value_type res = 0;
		while (bfs(s), ~level[t]) {
			iter.assign(size(), 0);
			value_type f;
			while ((f = dfs(s, t, INF)) > EPS) res += f;
		}
		return res;
	}
	
private:
	struct Edge { size_type to, rev; value_type c; };
	std::vector<std::vector<Edge>> g;
	static constexpr value_type EPS = std::is_floating_point<value_type>() ? 1e-6 : 0;
	static constexpr value_type INF = 1e9 + 100;
	std::vector<size_type> iter, level;
	
	void bfs(size_type s) {
		level.assign(size(), -1);
		std::queue<size_type> que;
		que.push(s);
		level[s] = 0;
		while (!que.empty()) {
			size_type u = que.front(); que.pop();
			for (Edge & e : g[u]) {
				if (e.c <= EPS || ~level[e.to]) continue;
				que.push(e.to);
				level[e.to] = level[u] + 1;
			}
		}
	}
	
	value_type dfs(size_type u, size_type t, value_type f) {
		if (u == t) return f;
		for (size_type & i = iter[u]; i < g[u].size(); ++i) {
			const Edge & e = g[u][i];
			if (e.c <= EPS || level[u] >= level[e.to]) continue;
			value_type cur = dfs(e.to, t, std::min(f, e.c));
			if (cur > EPS) {
				g[u][i].c -= cur;
				g[e.to][e.rev].c += cur;
				return cur;
			}
		}
		return 0;
	}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

