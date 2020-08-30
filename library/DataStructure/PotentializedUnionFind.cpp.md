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


# :heavy_check_mark: DataStructure/PotentializedUnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PotentializedUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 21:49:12+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/PotentializedUnionFind.test.cpp.html">Test/PotentializedUnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <numeric>
#include <utility>
#include <cassert>
#include <functional>
#include <stack>

/*
last-updated: 2020/04/23

ポテンシャル付き UnionFind

# 仕様
PotentializedUnionFind(size_type n, const F &f, const_reference id_elem) :
	時間計算量: Θ(n)
	要素数 n, 二項演算 f, 単位元 id_elem で初期化

size_type size(size_type x) :
	時間計算量: O(log n)
	要素 x が属するグループの要素数を返す

value_type get(size_type x) :
	時間計算量: O(log n)
	要素 x から根まで fold した結果を返す

size_type add(const_reference v) :
	時間計算量: Θ(1)
	値が v である頂点を追加する

size_type find(size_type x) :
	時間計算量: O(log n)
	要素 x が属するグループの代表番号を返す

void link(size_type p, size_type x) :
	時間計算量: O(log n)
	要素 x の親を p に設定する(このとき、x の親の付け替えは発生してはいけない)

bool issame(size_type x, size_type y) :
	時間計算量: O(log n)
	要素 x, y が同一グループに属するかを返す

TODO: 計算量を O(α(n)) に改善できるらしいのでする
TODO: Potential 感を出す (2 要素の差の制約の追加, diff の追加など)

# 参考
http://sigma425.hatenablog.com/entry/2015/12/07/185047, 2020/04/23

verify : https://atcoder.jp/contests/abc087/submissions/12241089
*/

template<typename T>
struct PotentializedUnionFind {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	PotentializedUnionFind(size_type n, const F &f, const_reference id_elem)
			: n(n), f(f), id_elem(id_elem), size_(n, 1), val(n, id_elem) {
		par.resize(n);
		std::iota(par.begin(), par.end(), 0);
	}
	
	size_type size(size_type x) { return size_[find(x)]; }
	
	value_type get(size_type x) {
		find(x);
		if (par[x] == x) return val[x];
		return f(val[par[x]], val[x]);
	}
	
	size_type add(const_reference v) {
		size_.emplace_back(1);
		par.emplace_back(n);
		val.emplace_back(v);
		return n++;
	}
	
	size_type find(size_type x) {
		assert(x < n);
		std::stack<size_type> stk;
		stk.push(x);
		while (par[stk.top()] != stk.top()) stk.push(par[stk.top()]);
		
		size_type r = stk.top();
		stk.pop();
		bool r_child = true;
		while (!stk.empty()) {
			const size_type &t = stk.top();
			if (!r_child) val[t] = f(val[par[t]], val[t]);
			par[t] = r;
			r_child = false;
			stk.pop();
		}
		return r;
	}
	
	void link(size_type p, size_type x) {
		assert(par[x] == x);
		par[x] = p;
		size_[find(p)] += size_[x];
	}
	
	bool issame(size_type x, size_type y) { return find(x) == find(y); }
	
private:
	size_type n;
	value_type id_elem;
	F f;
	std::vector<size_type> size_, par;
	std::vector<value_type> val;
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PotentializedUnionFind.cpp"
#include <vector>
#include <numeric>
#include <utility>
#include <cassert>
#include <functional>
#include <stack>

/*
last-updated: 2020/04/23

ポテンシャル付き UnionFind

# 仕様
PotentializedUnionFind(size_type n, const F &f, const_reference id_elem) :
	時間計算量: Θ(n)
	要素数 n, 二項演算 f, 単位元 id_elem で初期化

size_type size(size_type x) :
	時間計算量: O(log n)
	要素 x が属するグループの要素数を返す

value_type get(size_type x) :
	時間計算量: O(log n)
	要素 x から根まで fold した結果を返す

size_type add(const_reference v) :
	時間計算量: Θ(1)
	値が v である頂点を追加する

size_type find(size_type x) :
	時間計算量: O(log n)
	要素 x が属するグループの代表番号を返す

void link(size_type p, size_type x) :
	時間計算量: O(log n)
	要素 x の親を p に設定する(このとき、x の親の付け替えは発生してはいけない)

bool issame(size_type x, size_type y) :
	時間計算量: O(log n)
	要素 x, y が同一グループに属するかを返す

TODO: 計算量を O(α(n)) に改善できるらしいのでする
TODO: Potential 感を出す (2 要素の差の制約の追加, diff の追加など)

# 参考
http://sigma425.hatenablog.com/entry/2015/12/07/185047, 2020/04/23

verify : https://atcoder.jp/contests/abc087/submissions/12241089
*/

template<typename T>
struct PotentializedUnionFind {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	PotentializedUnionFind(size_type n, const F &f, const_reference id_elem)
			: n(n), f(f), id_elem(id_elem), size_(n, 1), val(n, id_elem) {
		par.resize(n);
		std::iota(par.begin(), par.end(), 0);
	}
	
	size_type size(size_type x) { return size_[find(x)]; }
	
	value_type get(size_type x) {
		find(x);
		if (par[x] == x) return val[x];
		return f(val[par[x]], val[x]);
	}
	
	size_type add(const_reference v) {
		size_.emplace_back(1);
		par.emplace_back(n);
		val.emplace_back(v);
		return n++;
	}
	
	size_type find(size_type x) {
		assert(x < n);
		std::stack<size_type> stk;
		stk.push(x);
		while (par[stk.top()] != stk.top()) stk.push(par[stk.top()]);
		
		size_type r = stk.top();
		stk.pop();
		bool r_child = true;
		while (!stk.empty()) {
			const size_type &t = stk.top();
			if (!r_child) val[t] = f(val[par[t]], val[t]);
			par[t] = r;
			r_child = false;
			stk.pop();
		}
		return r;
	}
	
	void link(size_type p, size_type x) {
		assert(par[x] == x);
		par[x] = p;
		size_[find(p)] += size_[x];
	}
	
	bool issame(size_type x, size_type y) { return find(x) == find(y); }
	
private:
	size_type n;
	value_type id_elem;
	F f;
	std::vector<size_type> size_, par;
	std::vector<value_type> val;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

