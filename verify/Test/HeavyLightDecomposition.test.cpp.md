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


# :heavy_check_mark: Test/HeavyLightDecomposition.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/HeavyLightDecomposition.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SegmentTree.cpp.html">DataStructure/SegmentTree.cpp</a>
* :heavy_check_mark: <a href="../../library/GraphTheory/HeavyLightDecomposition.cpp.html">GraphTheory/HeavyLightDecomposition.cpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/ModInt.cpp.html">Mathematics/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "Mathematics/ModInt.cpp"
#include "DataStructure/SegmentTree.cpp"
#include "GraphTheory/HeavyLightDecomposition.cpp"

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	using HLD = HeavyLightDecomposition<pmm, SegmentTree>;
	
	std::vector<pmm> val(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		val[i] = {a, b};
	}
	
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	HLD hld(g, 0, [](const pmm &a, const pmm &b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0), true);
	
	for (int i = 0; i < N; ++i) {
		hld.set(i, val[i]);
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			hld.set(a, {b, c});
		}
		else {
			pmm v = hld.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/HeavyLightDecomposition.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#line 1 "Mathematics/ModInt.cpp"
#include <cassert>
#include <iostream>

/*
last-updated: 2020/02/26

ModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

ModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
ModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static decltype(M) get_mod() noexcept : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const ModInt & rhs) const noexept
operator -(const ModInt & rhs) const noexept
operator *(const ModInt & rhs) const noexept
operator /(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs)
friend std::istream & operator >>(std::istream & is, ModInt & rhs) :
	入出力用

参考 :
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

template<int M>
struct ModInt {
public:
	using value_type = long long;
	
	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }
	ModInt operator +() const noexcept { return ModInt(*this); }
	ModInt operator -() const noexcept { return ModInt(0) -= *this; }
	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }
	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }
	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }
	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }
	
	ModInt & operator +=(const ModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= M) val -= M;
		return *this;
	}
	ModInt & operator -=(const ModInt & rhs) noexcept {
		if (val < rhs.val) val += M;
		val -= rhs.val;
		return *this;
	}
	ModInt & operator *=(const ModInt & rhs) noexcept {
		val = val * rhs.val % M;
		return *this;
	}
	ModInt & operator /=(const ModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	ModInt pow(value_type n) const {
		ModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	ModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;
			a = b; b = r;
			a1 = b1; b1 = nb1;
			a2 = b2; b2 = nb2;
		}
		assert(a == 1);
		return a1;
	}
	
	const value_type & get() const noexcept { return val; }
	static decltype(M) get_mod() noexcept { return M; }
	
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {
		value_type x;
		is >> x;
		rhs = ModInt(x);
		return is;
	}
private:
	value_type val;
};
#line 1 "DataStructure/SegmentTree.cpp"
#include <vector>
#include <algorithm>
#line 4 "DataStructure/SegmentTree.cpp"
#include <functional>

/*
last-updated: 2020/04/22

SegmentTree(size_type n_, const F & f, const_reference id_elem) : 要素数 n_, 二項演算 f, 単位元 id_elem
void set(size_type i, const_reference x) : Θ(log n) i 番目の要素に x を代入
void add(size_type i, const_reference x) : Θ(lon n) i 番目の要素に x を演算する
value_type fold(size_type l, size_type r) const : Θ(log n) [l, r) を fold した結果を返す
size_type lower_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す
size_type upper_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

参考 :
https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf, 2020/04/08
*/

template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	SegmentTree(size_type n_, const F & f, const_reference id_elem) : f(f), id_elem(id_elem) {
		n = 1;
		while (n < n_) n <<= 1;
		node.resize(2 * n, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += n] = x;
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += n;
		node[i] = f(node[i], x);
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex < x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
	size_type upper_bound(const_reference x) const {
		if (node[1] <= x) return n;
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < n;) {
			value_type nex = f(s, node[idx << 1]);
			if (nex <= x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
private:
	size_type n;
	F f;
	value_type id_elem;
	std::vector<value_type> node;
};
#line 2 "GraphTheory/HeavyLightDecomposition.cpp"
#include <utility>
#line 5 "GraphTheory/HeavyLightDecomposition.cpp"
#include <stack>
#line 7 "GraphTheory/HeavyLightDecomposition.cpp"

/*
last-updated: 2020/04/22

HL 分解

template<typename U, typename T> :
	U : モノイドの型
	T : fold 演算を行なえるデータ構造(ex. SegmentTree)

HeavyLightDecomposition(
		std::vector<std::vector<size_type>> &g,
		size_type root_num,
		const F &f,
		const value_type
		&id_elem,
		bool value_on_vertex) :
	Θ(N)
	root_num を根とする木 g に対して HL 分解を行う。
	載せるモノイドの二項演算を f, 単位元を id_elem とする。
	{value_on_vertex - true : 頂点, false : 辺} に値を持たせる。

size_type size() const noexcept :
	分解前の頂点数を返す

void set(size_type i, const_reference x) :
	Θ(log N)
	頂点 i の値を x に変更する

void set(size_type u, size_type v, const_reference x) :
	Θ(log N)
	辺 (u, v) の重みを x に変更する


size_type lca(size_type x, size_type y) const :
	O(log N)
	x と y の LCA を返す

value_type fold(size_type u, size_type v) const :
	O(loglog N)
	パス u -> v で fold 演算した結果を返す

-- private --
std::pair<size_type, size_type> lca_node_num(size_type x, size_type y) const :
	O(log N)
	x と y の LCA が属する列にはじめて到達したときの頂点の組を返す。

memo :
	num は分解前の添字
	idx は分解後の添字

参考 :
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
	
	HeavyLightDecomposition(std::vector<std::vector<size_type>> &g, size_type root_num, const F &f, const_reference id_elem, bool value_on_vertex) : f(f), id_elem(id_elem), value_on_vertex(value_on_vertex) {
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
#line 6 "Test/HeavyLightDecomposition.test.cpp"

#include <cstdio>
#line 9 "Test/HeavyLightDecomposition.test.cpp"

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	using HLD = HeavyLightDecomposition<pmm, SegmentTree>;
	
	std::vector<pmm> val(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		val[i] = {a, b};
	}
	
	std::vector<std::vector<HLD::size_type>> g(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	HLD hld(g, 0, [](const pmm &a, const pmm &b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0), true);
	
	for (int i = 0; i < N; ++i) {
		hld.set(i, val[i]);
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			hld.set(a, {b, c});
		}
		else {
			pmm v = hld.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

