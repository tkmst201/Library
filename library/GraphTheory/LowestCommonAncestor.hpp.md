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


# :heavy_check_mark: GraphTheory/LowestCommonAncestor.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/LowestCommonAncestor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/LowestCommonAncestor.test.cpp.html">Test/LowestCommonAncestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP
#define INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP

#include <vector>
#include <cassert>
#include <utility>

/*
last-updated: 2020/08/27

木グラフでの最近共通祖先を求める
木グラフではないとバグるので注意

おまけで木の任意の 2 頂点間のパスの長さを返す機能がついている

# 仕様
LowestCommonAncestor(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを作成する

LowestCommonAncestor(std::vector<std::vector<size_type>> g) :
	時間計算量: Θ(n + m)
	グラフ g で初期化する
	build() を呼ぶ必要があることに注意

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type s, size_type t)
	時間計算量: Θ(1)
	頂点 u -> 頂点 v に辺を張る

void clear() :
	時間計算量: Θ(n)
	グラフを削除する

void build(size_type rootNode = 0)
	時間計算量: Θ(N log N)
	LCA 計算のための事前計算を行う

size_type find(size_type a, size_type b) const
	時間計算量: Θ(log N)
	頂点 a , 頂点 b の LCA を求める

size_type query(size_type a, size_type b) const :
	時間計算量: Θ(log N)
	パス a - b の長さを求める
*/

#include <vector>
#include <cassert>
#include <utility>

struct LowestCommonAncestor {
	using size_type = std::size_t;
	
private:
	size_type logsize;
	std::vector<std::vector<size_type> > g, par;
	std::vector<size_type> depth;
	bool isbuilt;
	
public:
	LowestCommonAncestor(size_type n) {
		g.resize(n);
		isbuilt = false;
	}
	
	LowestCommonAncestor(std::vector<std::vector<size_type>> g) : g(g) {
		isbuilt = false;
	};
	
	size_type size() const noexcept {
		return g.size();
	}
	
	void add_edge(size_type s, size_type t) {
		assert(s < size());
		assert(t < size());
		g[s].push_back(t);
		isbuilt = false;
	}
	
	void clear() {
		g.clear();
		par.clear();
		depth.clear();
		isbuilt = false;
	}
	
	void build(size_type rootNode = 0) {
		assert(rootNode < size());
		logsize = 1;
		while (1 << logsize < size()) ++logsize;
		depth.assign(size(), size());
		par.assign(logsize, std::vector<size_type>(size(), size()));
		
		depth[rootNode] = 0;
		dfs(rootNode, size());
		for (size_type i = 1; i < logsize; ++i) {
			for (size_type j = 0; j < size(); ++j) {
				if (par[i - 1][j] != size()) par[i][j] = par[i - 1][ par[i - 1][j] ];
			}
		}
		isbuilt = true;
	}
	
	size_type find(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		if (depth[a] < depth[b]) std::swap(a, b);
		
		size_type up = depth[a] - depth[b];
		for (size_type i = 0; i < logsize; ++i) if (up >> i & 1) a = par[i][a];
		if (a == b) return a;
		for (size_type i = logsize; i > 0; --i) {
			if (par[i - 1][a] != par[i - 1][b]) {
				a = par[i - 1][a];
				b = par[i - 1][b];
			}
		}
		return par[0][a];
	}
	
	size_type query(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		return depth[a] + depth[b] - 2 * depth[find(a, b)];
	}
	
private:
	void dfs(size_type u, size_type p) {
		for (size_type v : g[u]) {
			if (v == p) continue;
			depth[v] = depth[u] + 1;
			par[0][v] = u;
			dfs(v, u);
		}
	}
};

#endif // INCLUDE_GUARD_LOWEST_COMMON_ANCESTOR_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/LowestCommonAncestor.hpp"



#include <vector>
#include <cassert>
#include <utility>

/*
last-updated: 2020/08/27

木グラフでの最近共通祖先を求める
木グラフではないとバグるので注意

おまけで木の任意の 2 頂点間のパスの長さを返す機能がついている

# 仕様
LowestCommonAncestor(size_type n) :
	時間計算量: Θ(n)
	頂点数が n のグラフを作成する

LowestCommonAncestor(std::vector<std::vector<size_type>> g) :
	時間計算量: Θ(n + m)
	グラフ g で初期化する
	build() を呼ぶ必要があることに注意

size_type size() const noexcept :
	時間計算量: Θ(1)
	グラフの頂点数を返す

void add_edge(size_type s, size_type t)
	時間計算量: Θ(1)
	頂点 u -> 頂点 v に辺を張る

void clear() :
	時間計算量: Θ(n)
	グラフを削除する

void build(size_type rootNode = 0)
	時間計算量: Θ(N log N)
	LCA 計算のための事前計算を行う

size_type find(size_type a, size_type b) const
	時間計算量: Θ(log N)
	頂点 a , 頂点 b の LCA を求める

size_type query(size_type a, size_type b) const :
	時間計算量: Θ(log N)
	パス a - b の長さを求める
*/

#line 54 "GraphTheory/LowestCommonAncestor.hpp"

struct LowestCommonAncestor {
	using size_type = std::size_t;
	
private:
	size_type logsize;
	std::vector<std::vector<size_type> > g, par;
	std::vector<size_type> depth;
	bool isbuilt;
	
public:
	LowestCommonAncestor(size_type n) {
		g.resize(n);
		isbuilt = false;
	}
	
	LowestCommonAncestor(std::vector<std::vector<size_type>> g) : g(g) {
		isbuilt = false;
	};
	
	size_type size() const noexcept {
		return g.size();
	}
	
	void add_edge(size_type s, size_type t) {
		assert(s < size());
		assert(t < size());
		g[s].push_back(t);
		isbuilt = false;
	}
	
	void clear() {
		g.clear();
		par.clear();
		depth.clear();
		isbuilt = false;
	}
	
	void build(size_type rootNode = 0) {
		assert(rootNode < size());
		logsize = 1;
		while (1 << logsize < size()) ++logsize;
		depth.assign(size(), size());
		par.assign(logsize, std::vector<size_type>(size(), size()));
		
		depth[rootNode] = 0;
		dfs(rootNode, size());
		for (size_type i = 1; i < logsize; ++i) {
			for (size_type j = 0; j < size(); ++j) {
				if (par[i - 1][j] != size()) par[i][j] = par[i - 1][ par[i - 1][j] ];
			}
		}
		isbuilt = true;
	}
	
	size_type find(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		if (depth[a] < depth[b]) std::swap(a, b);
		
		size_type up = depth[a] - depth[b];
		for (size_type i = 0; i < logsize; ++i) if (up >> i & 1) a = par[i][a];
		if (a == b) return a;
		for (size_type i = logsize; i > 0; --i) {
			if (par[i - 1][a] != par[i - 1][b]) {
				a = par[i - 1][a];
				b = par[i - 1][b];
			}
		}
		return par[0][a];
	}
	
	size_type query(size_type a, size_type b) const {
		assert(isbuilt);
		assert(a < size());
		assert(b < size());
		return depth[a] + depth[b] - 2 * depth[find(a, b)];
	}
	
private:
	void dfs(size_type u, size_type p) {
		for (size_type v : g[u]) {
			if (v == p) continue;
			depth[v] = depth[u] + 1;
			par[0][v] = u;
			dfs(v, u);
		}
	}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

