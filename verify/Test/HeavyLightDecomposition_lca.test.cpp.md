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


# :heavy_check_mark: Test/HeavyLightDecomposition_lca.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/HeavyLightDecomposition_lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/GraphTheory/HeavyLightDecomposition.hpp.html">GraphTheory/HeavyLightDecomposition.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "GraphTheory/HeavyLightDecomposition.hpp"

#include <cstdio>
#include <functional>

template<typename T>
struct Dummy {
	Dummy(int n_, const std::function<int(int, int)> f, const int & id_elem) {}
	
	int fold(int l, int r) {
		return 0;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	
	using HLD = HeavyLightDecomposition<int, Dummy>;
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int c;
			scanf("%d", &c);
			g[i].emplace_back(c);
			g[c].emplace_back(i);
		}
	}
	
	HLD hld(g, 0, [](int a, int b) { return a + b; }, 0, true);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", hld.lca(u, v));
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/HeavyLightDecomposition_lca.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#line 1 "GraphTheory/HeavyLightDecomposition.hpp"



#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
#include <stack>
#include <functional>

/*
last-updated: 2020/04/22

HL 分解

# 仕様
template<typename U, typename T> :
	U : モノイドの型
	T : fold 演算が可能なデータ構造(ex. SegmentTree)

HeavyLightDecomposition(
		std::vector<std::vector<size_type>> &g,
		size_type root_num,
		const F &f,
		const value_type
		&id_elem,
		bool value_on_vertex) :
	時間計算量: Θ(n)
	root_num を根とする木 g に対して HL 分解を行う。
	載せるモノイドの二項演算を f, 単位元を id_elem とする。
	{value_on_vertex - true : 頂点, false : 辺} に値を持たせる。

size_type size() const noexcept :
	時間計算量: Θ(1)
	分解前の頂点数を返す

void set(size_type i, const_reference x) :
	時間計算量: Θ(log N)
	頂点 i の値を x に変更する

void set(size_type u, size_type v, const_reference x) :
	時間計算量: Θ(log N)
	辺 (u, v) の重みを x に変更する

size_type lca(size_type x, size_type y) const :
	時間計算量: O(log N)
	x と y の LCA を返す

value_type fold(size_type u, size_type v) const :
	時間計算量: O(loglog N)
	パス u -> v で fold 演算した結果を返す

-- private --
std::pair<size_type, size_type> lca_node_num(size_type x, size_type y) const :
	時間計算量: O(log N)
	x と y の LCA が属する列にはじめて到達したときの頂点の組を返す。

# memo
	num は分解前の添字
	idx は分解後の添字

# 参考
https://qiita.com/ageprocpp/items/8dfe768218da83314989, 2020/04/19
https://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19

path query verfied : https://atcoder.jp/contests/abc133/submissions/14120006
*/

template<typename U, template<typename> typename T>
struct HeavyLightDecomposition {
public:
	using value_type = U;
	using container_type = T<U>;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	HeavyLightDecomposition(const std::vector<std::vector<size_type>> &g, size_type root_num, const F &f, const_reference id_elem, bool value_on_vertex) : f(f), id_elem(id_elem), value_on_vertex(value_on_vertex) {
		build(g, root_num);
	}
	
	size_type size() const noexcept {
		return size_;
	}
	
	void set(size_type i, const_reference x) {
		assert(value_on_vertex);
		assert(i < size());
		set_(i, x);
	}
	
	void set(size_type u, size_type v, const_reference x) {
		assert(!value_on_vertex);
		assert(u < size() && v < size());
		assert(par_num[u] == v || par_num[v] == u);
		size_type i = par_num[u] == v ? u : v;
		set_(i, x);
	}
	
	value_type fold(size_type u, size_type v) const {
		assert(u < size() && v < size());
		size_type lca_node = node_idx[lca_node_num(u, v).first];
		value_type lv = id_elem, rv = id_elem;
		
		while (node_idx[u] != lca_node) {
			lv = f(lv, value[node_idx[u]].fold(path_idx[u], ver_num[node_idx[u]].size()));
			u = par_num[ver_num[node_idx[u]].back()];
		}
		while (node_idx[v] != lca_node) {
			rv = f(rvalue[node_idx[v]].fold(0, get_r_path_idx(node_idx[v], path_idx[v]) + 1), rv);
			v = par_num[ver_num[node_idx[v]].back()];
		}
		
		if (path_idx[u] <= path_idx[v]) lv = f(lv, value[node_idx[u]].fold(path_idx[u], path_idx[v] + value_on_vertex));
		else rv = f(rvalue[node_idx[u]].fold(get_r_path_idx(node_idx[u], path_idx[u]) + !value_on_vertex, get_r_path_idx(node_idx[v], path_idx[v]) + 1), rv);
		
		return f(lv, rv);
	}
	
	size_type lca(size_type x, size_type y) const {
		assert(x < size() && y < size());
		std::pair<size_type, size_type> res = lca_node_num(x, y);
		return ver_num[node_idx[res.first]][std::max(path_idx[res.first], path_idx[res.second])];
	}
	
private:
	F f; // 二項演算 f
	const value_type id_elem; // 単位元
	bool value_on_vertex; // 値が {true : 頂点, false : 辺} に存在する
	size_type size_; // 分解前の頂点数
	std::vector<size_type> node_idx; // node_idx[i] := 頂点 i が属する分解後の列の index
	std::vector<size_type> path_idx; // path_idx[i] := 頂点 i が属する分解後の列での頂点 i の index
	std::vector<std::vector<size_type>> ver_num; // [i][j] := 分解後の列 i の j 番目の要素の分解前の頂点番号
	
	std::vector<size_type> par_num; // par_num[i] := 頂点 i の親の頂点番号
	std::vector<std::vector<size_type>> childs; // childs[i] := 頂点 i の子の頂点番号
	std::vector<container_type> value, rvalue; // 頂点や辺の値, rvalue は逆向きの演算
	
	void build(const std::vector<std::vector<size_type>> &g, size_type root_num) {
		size_ = g.size();
		node_idx.resize(size());
		path_idx.resize(size());
		par_num.resize(size());
		childs.resize(size());
		
		std::vector<bool> done(size(), 0);
		std::vector<size_type> sub_size(size(), 0);
		
		std::stack<std::pair<size_type, size_type>> stk;
		stk.emplace(root_num, 0);
		par_num[root_num] = root_num;
		done[root_num] = true;
		
		while (!stk.empty()) {
			int u = stk.top().first;
			int idx = stk.top().second;
			stk.pop();
			
			if (idx < g[u].size()) {
				stk.emplace(u, idx + 1);
				
				int v = g[u][idx];
				if (!done[v]) {
					done[v] = true;
					par_num[v] = u;
					childs[u].push_back(v);
					stk.emplace(v, 0);
				}
			}
			else {
				size_type mx_idx, mx_size = 0, size_cnt = 1;
				for (size_type child : childs[u]) {
					size_cnt += sub_size[child];
					if (mx_size < sub_size[child]) {
						mx_size = sub_size[child];
						mx_idx = child;
					}
				}
				
				if (size_cnt == 1) ver_num.emplace_back();
				size_type cur_node_idx = size_cnt == 1 ? ver_num.size() - 1 : node_idx[mx_idx];
				sub_size[u] = size_cnt;
				node_idx[u] = cur_node_idx;
				path_idx[u] = ver_num[node_idx[u]].size();
				ver_num[node_idx[u]].emplace_back(u);
			}
		}
		
		for (size_type i = 0; i < ver_num.size(); ++i) {
			value.emplace_back(ver_num[i].size(), f, id_elem);
			rvalue.emplace_back(ver_num[i].size(), f, id_elem);
		}
	}
	
	std::pair<size_type, size_type> lca_node_num(size_type x, size_type y) const {
		assert(x < size() && y < size());
		if (node_idx[x] == node_idx[y]) return {x, y};
		std::stack<size_type> stk[2];
		for (size_type i = 0; i < 2; ++i) {
			stk[i].emplace(-1);
			stk[i].emplace(i == 0 ? x : y);
			while (true) {
				size_type top_num = ver_num[node_idx[stk[i].top()]].back();
				size_type par = par_num[top_num];
				if (top_num == par) break;
				stk[i].emplace(par);
			}
		}
		
		size_type lca_pred[2];
		while (node_idx[stk[0].top()] == node_idx[stk[1].top()]) {
			for (size_type i = 0; i < 2; ++i) {
				lca_pred[i] = stk[i].top();
				stk[i].pop();
			}
		}
		return {lca_pred[0], lca_pred[1]};
	}
	
	size_type get_r_path_idx(size_type nidx, size_type pidx) const {
		assert(nidx < ver_num.size());
		assert(pidx < ver_num[nidx].size());
		return ver_num[nidx].size() - pidx - 1;
	}
	
	void set_(size_type i, const_reference x) {
		assert(i < size());
		value[node_idx[i]].set(path_idx[i], x);
		rvalue[node_idx[i]].set(get_r_path_idx(node_idx[i], path_idx[i]), x);
	}
};


#line 4 "Test/HeavyLightDecomposition_lca.test.cpp"

#include <cstdio>
#line 7 "Test/HeavyLightDecomposition_lca.test.cpp"

template<typename T>
struct Dummy {
	Dummy(int n_, const std::function<int(int, int)> f, const int & id_elem) {}
	
	int fold(int l, int r) {
		return 0;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	
	using HLD = HeavyLightDecomposition<int, Dummy>;
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int c;
			scanf("%d", &c);
			g[i].emplace_back(c);
			g[c].emplace_back(i);
		}
	}
	
	HLD hld(g, 0, [](int a, int b) { return a + b; }, 0, true);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", hld.lca(u, v));
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

