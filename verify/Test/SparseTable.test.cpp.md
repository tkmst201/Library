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


# :heavy_check_mark: Test/SparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SparseTable.cpp.html">DataStructure/SparseTable.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "DataStructure/SparseTable.cpp"

#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	SparseTable<int> st(A.begin(), A.end(), [](int x, int y) {
		return std::min(x, y);
	});
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", st.fold(l, r));
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#line 1 "DataStructure/SparseTable.cpp"
#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/04/30

T は結合律, 可換律, 反射律をすべて満たすもの
build θ(n log n), fold θ(1)

template<class InputIterator>
DisjointSparseTable(InputIterator first, InputIterator last, const F &f) :
	θ(n log n)
	[farst, last) でテーブルを作成する
	反射的な二項演算 f

size_type empty() const noexcept : θ(1) 要素が空であるかを判定する
size_type size() const noexcept : θ(1) 要素数を返す

value_type fold(size_type l, size_type r) const :
	θ(1)
	[l, r) を fold した結果を返す

参考 :
http://tookunn.hatenablog.com/entry/2016/07/13/211148, 2020/04/30
*/

template<typename T>
struct SparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	template<class InputIterator>
	SparseTable(InputIterator first, InputIterator last, const F &f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	bool empty() const noexcept { return size() == 0; }
	size_type size() const noexcept { return table.empty() ? 0 : table.front().size(); }
	
	value_type fold(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		size_type diff = r - l;
		return f(table[log_table[diff] - 1][l], table[log_table[diff] - 1][r - (1 << log_table[diff] - 1)]);
	}
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	std::vector<size_type> log_table;
	
	void build() {
		log_table.reserve(size() + 1);
		log_table.emplace_back(0);
		for (size_type i = 1; i <= size(); ++i) log_table.emplace_back(log_table[i >> 1] + 1);
		
		table.reserve(log_table[size()]);
		for (size_type i = 1; i < log_table[size()]; ++i) {
			table.emplace_back();
			table[i].reserve(size() - (1 << i) + 1);
			for (size_type j = 0; j + (1 << i) <= size(); ++j)
				table[i].emplace_back(f(table[i - 1][j], table[i - 1][j + (1 << i - 1)]));
		}
	}
};
#line 4 "Test/SparseTable.test.cpp"

#include <cstdio>
#include <algorithm>
#line 8 "Test/SparseTable.test.cpp"

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	SparseTable<int> st(A.begin(), A.end(), [](int x, int y) {
		return std::min(x, y);
	});
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", st.fold(l, r));
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

