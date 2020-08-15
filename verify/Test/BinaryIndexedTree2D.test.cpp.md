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


# :heavy_check_mark: Test/BinaryIndexedTree2D.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/BinaryIndexedTree2D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 23:22:28+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/BinaryIndexedTree2D.cpp.html">DataStructure/BinaryIndexedTree2D.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include "DataStructure/BinaryIndexedTree2D.cpp"

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

int main() {
	int H, W, T, Q;
	scanf("%d %d %d %d", &H, &W, &T, &Q);
	std::vector<int> t(Q), c(Q), h1(Q), w1(Q), h2(Q), w2(Q);
	
	using pii = std::pair<int, int>;
	
	std::queue<pii> que; // 焼き上がりの時刻, イベントID
	BinaryIndexedTree2D<int> bit1(H, W), bit2(H, W); // bit1: 焼き上がった, bit2: まだ焼き上がっていない
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %d %d %d", &t[i], &c[i], &h1[i], &w1[i]);
		--h1[i]; --w1[i];
		
		while (!que.empty() && que.front().first <= t[i]) {
			int idx = que.front().second; que.pop();
			bit2.add(h1[idx], w1[idx], -1);
			bit1.add(h1[idx], w1[idx], 1);
		}
		
		if (c[i] == 0) { // セット
			bit2.add(h1[i], w1[i], 1);
			que.emplace(t[i] + T, i);
		}
		else if (c[i] == 1) { // つまみ食い
			if (bit1.sum(h1[i], w1[i], h1[i] + 1, w1[i] + 1) == 1) bit1.add(h1[i], w1[i], -1);
		}
		else { // カウント
			scanf("%d %d", &h2[i], &w2[i]);
			printf("%d %d\n", bit1.sum(h1[i], w1[i], h2[i], w2[i]), bit2.sum(h1[i], w1[i], h2[i], w2[i]));
		}
	}
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/BinaryIndexedTree2D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#line 1 "DataStructure/BinaryIndexedTree2D.cpp"
#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

# 仕様
BinaryIndexedTree2D(size_type h, size_type w) :
	h \times w の表を構築

void add(size_type i, size_type j, const_reference x) :
	時間計算量: Θ(log h log w)
	点 (i, j) に値 x を加算

value_type sum(size_type i, size_type j) const :
	時間計算量: Θ(log h log w)
	[0, i) \times [0, j) の合計を返す

	// [i1, i2) x [j1, j2)
value_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const :
	時間計算量: Θ(log h log w)
	[i1, i2) \times [j1, j2) の合計を返す

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T>
struct BinaryIndexedTree2D {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
	BinaryIndexedTree2D(size_type h, size_type w) : h(h), w(w) {
		node.resize(h + 1, std::vector<value_type>(w + 1));
	}
	
	void add(size_type i, size_type j, const_reference x) {
		assert(i < h);
		assert(j < w);
		++i; ++j;
		for (; i <= h; i += i & -i) {
			for (size_type k = j; k <= w; k += k & -k) {
				node[i][k] += x;
			}
		}
	}
	
	// [0, i) x [0, j)
	value_type sum(size_type i, size_type j) const {
		assert(i <= h);
		assert(j <= w);
		value_type res = 0;
		for (; i > 0; i -= i & -i) {
			for (size_type k = j; k > 0; k -= k & -k) {
				res += node[i][k];
			}
		}
		return res;
	}
	
	// [i1, i2) x [j1, j2)
	value_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const {
		assert(i1 < i2);
		assert(j1 < j2);
		assert(i2 <= h);
		assert(j2 <= w);
		return sum(i2, j2) - sum(i2, j1) - sum(i1, j2) + sum(i1, j1);
	}
	
private:
	size_type h, w;
	std::vector<std::vector<value_type>> node;
};
#line 4 "Test/BinaryIndexedTree2D.test.cpp"

#include <cstdio>
#line 7 "Test/BinaryIndexedTree2D.test.cpp"
#include <queue>
#include <utility>

int main() {
	int H, W, T, Q;
	scanf("%d %d %d %d", &H, &W, &T, &Q);
	std::vector<int> t(Q), c(Q), h1(Q), w1(Q), h2(Q), w2(Q);
	
	using pii = std::pair<int, int>;
	
	std::queue<pii> que; // 焼き上がりの時刻, イベントID
	BinaryIndexedTree2D<int> bit1(H, W), bit2(H, W); // bit1: 焼き上がった, bit2: まだ焼き上がっていない
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %d %d %d", &t[i], &c[i], &h1[i], &w1[i]);
		--h1[i]; --w1[i];
		
		while (!que.empty() && que.front().first <= t[i]) {
			int idx = que.front().second; que.pop();
			bit2.add(h1[idx], w1[idx], -1);
			bit1.add(h1[idx], w1[idx], 1);
		}
		
		if (c[i] == 0) { // セット
			bit2.add(h1[i], w1[i], 1);
			que.emplace(t[i] + T, i);
		}
		else if (c[i] == 1) { // つまみ食い
			if (bit1.sum(h1[i], w1[i], h1[i] + 1, w1[i] + 1) == 1) bit1.add(h1[i], w1[i], -1);
		}
		else { // カウント
			scanf("%d %d", &h2[i], &w2[i]);
			printf("%d %d\n", bit1.sum(h1[i], w1[i], h2[i], w2[i]), bit2.sum(h1[i], w1[i], h2[i], w2[i]));
		}
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

