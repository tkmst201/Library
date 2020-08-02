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


# :warning: GraphTheory/BipartiteMatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/BipartiteMatching.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <cassert>

/*
last-updated: 2020/03/05

二部グラフでの最大マッチングを求める

BipartiteMatching(size_type x, size_type y)
BipartiteMatching(size_type n)

void add_edge(size_type a, size_type b) : a, b 間に辺を張る
size_type build() : O(NE) 最大マッチングを求める
std::vector<size_type> get() const : Y の各要素のマッチング先の配列を返す

参考 :
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/BipartiteMatching.cpp"
#include <vector>
#include <cassert>

/*
last-updated: 2020/03/05

二部グラフでの最大マッチングを求める

BipartiteMatching(size_type x, size_type y)
BipartiteMatching(size_type n)

void add_edge(size_type a, size_type b) : a, b 間に辺を張る
size_type build() : O(NE) 最大マッチングを求める
std::vector<size_type> get() const : Y の各要素のマッチング先の配列を返す

参考 :
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

