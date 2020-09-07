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


# :heavy_check_mark: Test/BipartiteMatching.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/BipartiteMatching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../library/GraphTheory/BipartiteMatching.hpp.html">GraphTheory/BipartiteMatching.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "GraphTheory/BipartiteMatching.hpp"

#include <cstdio>

int main() {
	int L, R, M;
	scanf("%d %d %d", &L, &R, &M);
	
	BipartiteMatching bm(L, R);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		bm.add_edge(a, b);
	}
	bm.build();
	
	auto match = bm.get_match();
	printf("%d\n", match.size());
	for (int i = 0; i < match.size(); ++i) printf("%d %d\n", match[i].first, match[i].second);
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/BipartiteMatching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#line 1 "GraphTheory/BipartiteMatching.hpp"



#include <vector>
#include <cassert>
#include <utility>

/*
last-updated: 2020/08/26

二部グラフでの最大マッチングを求める
オーダーが怪しいが実際には高速に動く

N \leq 10^5, M \leq 2 \times 10^5 でも高速

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


#line 4 "Test/BipartiteMatching.test.cpp"

#include <cstdio>

int main() {
	int L, R, M;
	scanf("%d %d %d", &L, &R, &M);
	
	BipartiteMatching bm(L, R);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		bm.add_edge(a, b);
	}
	bm.build();
	
	auto match = bm.get_match();
	printf("%d\n", match.size());
	for (int i = 0; i < match.size(); ++i) printf("%d %d\n", match[i].first, match[i].second);
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

