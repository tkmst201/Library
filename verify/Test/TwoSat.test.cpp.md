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


# :heavy_check_mark: Test/TwoSat.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/TwoSat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:57:52+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../library/GraphTheory/StronglyConnectedComponents.hpp.html">GraphTheory/StronglyConnectedComponents.hpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/TwoSat.hpp.html">Mathematics/TwoSat.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "Mathematics/TwoSat.hpp"

#include <iostream>
#include <string>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::string dummy; std::cin >> dummy >> dummy;
	
	int N, M;
	std::cin >> N >> M;
	
	TwoSat sat(N);
	
	while (M--) {
		int a, b, t;
		std::cin >> a >> b >> t;
		sat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);
	}
	
	if (!sat.build()) std::cout << "s UNSATISFIABLE" << std::endl;
	else {
		std::cout << "s SATISFIABLE" << std::endl;
		const auto & ans = sat.get_answer();
		std::cout << "v";
		for (int i = 0; i < N; ++i) std::cout << " " << (ans[i] ? i + 1 : -(i + 1));
		std::cout << " 0" << std::endl;
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/TwoSat.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#line 1 "Mathematics/TwoSat.hpp"



#include <vector>
#include <cassert>

/*
last-updated: 2020/09/10

# 仕様
TwoSat(size_type n) :
	時間計算量: Θ(n)
	n 変数を対象として構築

void add_clause(size_type x, bool xb, size_type y, bool yb) :
	時間計算量: Θ(1)
	(x = xb) v (y = yb) を加える

void add_clause(size_type x, bool xb) :
	時間計算量: Θ(1)
	x = xb を加える

bool build() :
	時間計算量: Θ(n)
	全ての条件を満たすような変数の値の組み合わせを求める
	そのような組み合わせが存在するならば true, 存在しないのならば false を返す

const std::vector<bool> & get_answer() const :
	時間計算量: Θ(1)
	全ての条件を満たすような変数の真偽値が入っているテーブルを返す

bool get(size_type i) :
	時間計算量: Θ(1)
	全ての条件を満たすような変数の値の組み合わせで、変数 i の真偽値を返す

# 参考
"AC Library" https://atcoder.jp/posts/517m, 2020/09/10
*/

#line 1 "GraphTheory/StronglyConnectedComponents.hpp"



#line 6 "GraphTheory/StronglyConnectedComponents.hpp"
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

size_type build(bool build_idx_map = true)
	時間計算量: Θ(n + m)
	強連結成分分解を行う
	強連結成分の個数を返す
	build_idx_map が false のときは idx_map テーブルを構築しない(get_map や get_graph の動作は未定義)

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
	
	size_type build(bool build_idx_map = true) {
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
		
		if (build_idx_map) {
			idx_map.assign(c, {});
			for (size_type i = 0; i < size(); ++i) idx_map[rank[i]].emplace_back(i);
		}
		isbuilt = true;
		return c;
	}
	
	size_type get_rank(size_type i) {
		assert(isbuilt);
		assert(i < size());
		return rank[i];
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
			std::sort(begin(res[i]), end(res[i]));
			res[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));
		}
		return res;
	}
};


#line 41 "Mathematics/TwoSat.hpp"

struct TwoSat {
	using size_type = std::size_t;
	
private:
	size_type n;
	StronglyConnectedComponents scc;
	std::vector<bool> ans;
	bool isbuilt, satisfiability;
	
public:
	TwoSat(size_type n) : n(n), scc(2 * n + 2) {}
	
	void add_clause(size_type x, bool xb, size_type y, bool yb) {
		assert(x < n);
		assert(y < n);
		scc.add_edge(x + (xb ? n : 0), y + ((yb^1) ? n : 0));
		scc.add_edge(y + (yb ? n : 0), x + ((xb^1) ? n : 0));
		isbuilt = false;
	}
	
	void add_clause(size_type x, bool xb) {
		assert(x < n);
		scc.add_edge(x + (xb ? n : 0), 2*n);
		scc.add_edge(x + (xb ? n : 0), 2*n + 1);
		scc.add_edge(2*n, x + ((xb^1) ? n : 0));
		scc.add_edge(2*n + 1, x + ((xb^1) ? n : 0));
	}
	
	bool build() {
		scc.build(false);
		ans.assign(n, false);
		satisfiability = false;
		if (scc.get_rank(2*n) == scc.get_rank(2*n + 1)) return false;
		for (size_type i = 0; i < n; ++i) {
			if (scc.get_rank(i) == scc.get_rank(i + n)) return false;
			if (scc.get_rank(i) > scc.get_rank(i + n)) ans[i] = true;
		}
		isbuilt = true;
		satisfiability = true;
		return true;
	}
	
	const std::vector<bool> & get_answer() const {
		assert(isbuilt);
		assert(satisfiability);
		return ans;
	}
	
	bool get(size_type i) const {
		assert(isbuilt);
		assert(satisfiability);
		assert(i < n);
		return ans[i];
	}
};


#line 4 "Test/TwoSat.test.cpp"

#include <iostream>
#include <string>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::string dummy; std::cin >> dummy >> dummy;
	
	int N, M;
	std::cin >> N >> M;
	
	TwoSat sat(N);
	
	while (M--) {
		int a, b, t;
		std::cin >> a >> b >> t;
		sat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);
	}
	
	if (!sat.build()) std::cout << "s UNSATISFIABLE" << std::endl;
	else {
		std::cout << "s SATISFIABLE" << std::endl;
		const auto & ans = sat.get_answer();
		std::cout << "v";
		for (int i = 0; i < N; ++i) std::cout << " " << (ans[i] ? i + 1 : -(i + 1));
		std::cout << " 0" << std::endl;
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

