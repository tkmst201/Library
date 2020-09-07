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


# :heavy_check_mark: Test/CentroidDecomposition.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/CentroidDecomposition.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/tree_diameter">https://judge.yosupo.jp/problem/tree_diameter</a>


## Depends on

* :heavy_check_mark: <a href="../../library/GraphTheory/CentroidDecomposition.hpp.html">GraphTheory/CentroidDecomposition.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "GraphTheory/CentroidDecomposition.hpp"

#include <cstdio>
#include <vector>

int main() {
	int N;
	scanf("%d", &N);
	
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	
	std::vector<std::vector<std::pair<size_type, int>>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	using ll = long long;
	std::vector<size_type> path;
	ll X = get_tree_diameter(g, path);
	
	printf("%lld %d\n", X, path.size());
	for (int i = 0; i < path.size(); ++i) printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/CentroidDecomposition.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#line 1 "GraphTheory/CentroidDecomposition.hpp"



#include <vector>
#include <cassert>

/*
last-updated: 2020/09/03

コンストラクタで渡した g は変更してはいけない
used フラグの変更は set を通して行う

# 仕様

CentroidDecomposition(const Graph & g) :
	時間計算量: Θ(n)
	重心分解を行うグラフ g で初期化する

bool operator [](size_type v) const :
	時間計算量: Θ(1)
	used フラグの値を返す

bool operator at(size_type v) const :
	時間計算量: Θ(1)
	used フラグの値を返す
	assert チェックあり

std::vector<size_type> get_centroid(size_type root) :
	時間計算量: Θ(k)
	used フラグが立っている頂点を取り除いた森上で頂点 root が属する木(頂点数を k とする) の重心を求める

void set(size_type v) :
	時間計算量: Θ(1)
	頂点 v の used フラグを true に変更する

void clear() :
	時間計算量: Θ(n)
	used フラグをリセットする

# 使用例
size_type get_centroid_decomposition_tree(const Graph & g, Graph & cdg) :
	時間計算量: Θ(n log n)
	重心分解を再帰的に行い、各部分木の重心に辺を張ったグラフを cdg に格納する
	根の index(g の重心の 1 つ) を返す
	
	verified(2020/09/02) : https://codeforces.com/contest/321/submission/91621846

long long get_tree_diameter(
		const std::vector<std::vector<std::pair<size_type, int>>> & wg,
		std::vector<size_type> & path
	)
	時間計算量: Θ(n log n)
	重み付きグラフ上で最遠頂点対を求める
	最遠頂点対 (u, v) の長さを返し、そのパスを path に格納する
	定数倍がすごく重い(
		提出: https://judge.yosupo.jp/submission/20914
		手元では line グラフの処理が max_random に比べて 4 倍程度遅いが library-checker 上でははやかった(なぜ?)
	)。
	
	負辺でも正しく動作しそう(unverified)
	全方位木 dp を用いれば Θ(n) で求めることができそう
	重みが正の場合は double-sweap で Θ(n) で求まる
	これは verify 用

// おまけ その３
std::vector<long long> get_dist_frequency_table(const Graph & g) :
	要求ライブラリ: FastFourierTransform(multiply を実装済)
	時間計算量: Θ(n log^2 n)
	n 頂点の木において次のテーブルを作成する
		table[i] = u \leq v で dist(u, v) = i となるような (u, v) の個数
	
	# 解説
		u < v で (u, v), (v, u) と重複して数えあげて最後に 2 で割る
		
		centroid を通るパスを考える。
		部分木ごとに centroid からの距離を d として table[d]++ した table を用意
		全ての table の和を取る
		この table を 2 乗すると (異なる部分木を結合した table) + (同一部分木を結合した table) が得られる
		このとき、両方の table で [0] = 1 としておくと centroid - * のパスを数えることが可能
		((centroid, *) が重複してちょうど 2 回数え上げられる)
		
		(同一部分木を結合した table) では (centroid, *) は正しいが (*, *) の状態は消す必要があるので
		[0] = 0 として部分木のテーブルを 2 乗して引く
		
		1 つの階層で全体で O(n log n) の畳み込み
		全 O(log n) 層なので全体で O(n log^2 n)

# 参考
https://ferin-tech.hatenablog.com/entry/2020/03/06/162311, 2020/09/02
https://qiita.com/drken/items/4b4c3f1824339b090202, 2020/09/02
*/

class CentroidDecomposition {
public:
	using size_type = std::size_t;
	using Graph = std::vector<std::vector<size_type>>;
	
private:
	const Graph & g;
	std::vector<bool> used;
	std::vector<size_type> sz;
	
public:
	CentroidDecomposition() = delete;
	CentroidDecomposition(const Graph & g) : g(g) {
		used.resize(size(), false);
		sz.resize(size());
	}
	
	size_type size() const noexcept {
		return g.size();
	}
	
	bool operator [](size_type v) const {
		return used[v];
	}
	
	bool at(size_type v) const {
		assert(v < size());
		return used[v];
	}
	
	std::vector<size_type> get_centroid(size_type root) {
		assert(root < size());
		
		auto szdfs = [this](auto &&self, size_type v, size_type par) -> size_type {
			sz[v] = 1;
			for (auto to : g[v]) {
				if (to == par || used[to]) continue;
				sz[v] += self(self, to, v);
			}
			return sz[v];
		};
		szdfs(szdfs, root, size());
		
		size_type v = root, par = size();
		std::vector<size_type> res;
		while (true) {
			bool updated = false;
			for (auto to : g[v]) {
				if (to == par || used[to]) continue;
				if (sz[to] * 2 > sz[root]) {
					par = v;
					v = to;
					updated = true;
					break;
				}
				if (sz[to] * 2 == sz[root]) res.emplace_back(to);
			}
			if (updated) continue;
			res.emplace_back(v);
			break;
		}
		return res;
	}
	
	void set(size_type v) {
		assert(v < size());
		used[v] = true;
	}
	
	void clear() {
		used.assign(size(), false);
	}
};


// おまけ その１
CentroidDecomposition::size_type get_centroid_decomposition_tree(
		const CentroidDecomposition::Graph & g,
		CentroidDecomposition::Graph & cdg
	) {
	assert(!g.empty());
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	CD cd(g);
	
	cdg.assign(g.size(), {});
	
	auto dfs = [&](auto && self, size_type centroid) -> void {
		cd.set(centroid);
		for (auto r : g[centroid]) {
			if (cd[r]) continue;
			auto nex_cent = cd.get_centroid(r);
			
			cdg[centroid].emplace_back(nex_cent[0]);
			
			self(self, nex_cent[0]);
		}
	};
	
	size_type root = cd.get_centroid(0)[0];
	dfs(dfs, root);
	return root;
}

// おまけ その２
long long get_tree_diameter(
		const std::vector<std::vector<std::pair<CentroidDecomposition::size_type, int>>> & wg,
		std::vector<CentroidDecomposition::size_type> & path
	) {
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	using ll = long long;
	
	CD::Graph g(wg.size());
	for (CD::size_type i = 0; i < wg.size(); ++i) {
		for (auto v : wg[i]) g[i].emplace_back(v.first);
	}
	CD cd(g);
	
	struct Data {
		ll dist;
		size_type u, v;
		Data(ll dist, size_type u, size_type v) : dist(dist), u(u), v(v) {} 
		bool operator <(const Data & rhs) const {
			return dist < rhs.dist;
		}
	};
	
	auto dfs = [&](auto && self, size_type centroid) -> Data {
		cd.set(centroid);
		Data res{0, centroid, centroid};
		
		Data top = res, top2 = res;
		for (auto e : wg[centroid]) {
			size_type r = e.first;
			if (cd[r]) continue;
			
			auto dfs2 = [&](auto && self, size_type u, size_type par, ll c) -> Data {
				Data res{c, centroid, u};
				for (auto e : wg[u]) {
					size_type to = e.first;
					if (to == par || cd[to]) continue;
					Data nexd = self(self, to, u, c + e.second);
					if (res < nexd) res = nexd;
				}
				return res;
			};
			
			Data pred = dfs2(dfs2, r, wg.size(), e.second);
			if (top < pred) { top2 = top; top = pred; }
			else if (top2 < pred) { top2 = pred; }
			
			pred = self(self, cd.get_centroid(r)[0]);
			if (res < pred) res = pred;
		}
		
		if (top.dist + top2.dist > res.dist) return {top.dist + top2.dist, top.v, top2.v};
		return res;
	};
	
	size_type root = cd.get_centroid(0)[0];
	Data dat = dfs(dfs, root);
	
	std::vector<size_type> par(g.size(), g.size());
	auto dfs3 = [&](auto && self, size_type u) -> void {
		for (auto v : g[u]) {
			if (v == par[u]) continue;
			par[v] = u;
			self(self, v);
		}
	};
	
	dfs3(dfs3, dat.u);
	
	path.emplace_back(dat.v);
	while (par[path.back()] != g.size()) path.emplace_back(par[path.back()]);
	return dat.dist;
}

// おまけ その３
#include <cmath>
#include <algorithm>

template<class FFT>
std::vector<long long> get_dist_frequency_table(const CentroidDecomposition::Graph & g) {
	using CD = CentroidDecomposition;
	using value_type = long long;
	using size_type = CD::size_type;
	CD cd(g);
	
	size_type n = g.size();
	std::vector<size_type> depth(n);
	
	auto dfs = [&](auto && self, size_type centroid) -> std::vector<value_type> {
		cd.set(centroid);
		
		bool iso = true;
		for (auto r : g[centroid]) if (!cd[r]) { iso = false; break; }
		if (iso) return {0};
		
		std::vector<value_type> res;
		std::vector<value_type> sum_table;
		for (auto r : g[centroid]) {
			if (cd[r]) continue;
			
			std::vector<size_type> dvec;
			auto dfs2 = [&](auto && self, size_type u, size_type par) -> size_type {
				size_type res = depth[u];
				dvec.emplace_back(depth[u]);
				for (auto v : g[u]) {
					if (v == par || cd[v]) continue;
					depth[v] = depth[u] + 1;
					size_type pred = self(self, v, u);
					if (res < pred) res = pred;
				}
				return res;
			};
			
			depth[r] = 1;
			size_type mx_depth = dfs2(dfs2, r, n);
			std::vector<value_type> table(mx_depth + 1, 0);
			for (auto i : dvec) ++table[i];
			if (sum_table.size() < mx_depth + 1) sum_table.resize(mx_depth + 1);
			for (size_type i = 1; i < table.size(); ++i) sum_table[i] += table[i];
			
			auto mul = FFT::multiply(table, table);
			if (mul.size() > n) mul.resize(n);
			if (res.size() < mul.size()) res.resize(mul.size());
			for (size_type i = 1; i < mul.size(); ++i) res[i] -= static_cast<value_type>(std::round(mul[i]));
			
			table = self(self, cd.get_centroid(r)[0]);
			if (res.size() < table.size()) res.resize(table.size());
			for (size_type i = 1; i < table.size(); ++i) res[i] += table[i];
		}
		
		sum_table[0] = 1;
		auto prod = FFT::multiply(sum_table, sum_table);
		if (prod.size() > n) prod.resize(n);
		if (res.size() < prod.size()) res.resize(prod.size());
		for (size_type i = 1; i < prod.size(); ++i) res[i] += static_cast<value_type>(std::round(prod[i]));
		return res;
	};
	
	auto res = dfs(dfs, cd.get_centroid(0)[0]);
	for (size_type i = 1; i < res.size(); ++i) res[i] >>= 1;
	if (res.size() < n) res.resize(n);
	res[0] = n;
	return res;
}


#line 4 "Test/CentroidDecomposition.test.cpp"

#include <cstdio>
#line 7 "Test/CentroidDecomposition.test.cpp"

int main() {
	int N;
	scanf("%d", &N);
	
	using CD = CentroidDecomposition;
	using size_type = CD::size_type;
	
	std::vector<std::vector<std::pair<size_type, int>>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	using ll = long long;
	std::vector<size_type> path;
	ll X = get_tree_diameter(g, path);
	
	printf("%lld %d\n", X, path.size());
	for (int i = 0; i < path.size(); ++i) printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

