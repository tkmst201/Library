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


# :heavy_check_mark: Test/DisjointSparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/DisjointSparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/DisjointSparseTable.hpp.html">DataStructure/DisjointSparseTable.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "DataStructure/DisjointSparseTable.hpp"
// これは可換の場合でのテスト

#include <cstdio>
#include <vector>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	using ll = long long;
	DisjointSparseTable<ll> dst(A.begin(), A.end(), [](ll x, ll y) {
		return x + y;
	});
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", dst.fold(l, r));
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/DisjointSparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#line 1 "DataStructure/DisjointSparseTable.hpp"



#include <vector>
#include <cassert>
#include <functional>
#include <algorithm>

/*
last-updated: 2020/04/30

# 仕様
※非可換の場合は unverified
T は半群
template<class InputIterator>
DisjointSparseTable(InputIterator first, InputIterator last, const F &f) :
	時間計算量: θ(n log n)
	[farst, last) でテーブルを作成する
	二項演算 f

size_type empty() const noexcept :
	時間計算量: θ(1)
	要素が空であるかを判定する

size_type size() const noexcept :
	時間計算量: θ(1)
	要素数を返す

value_type fold(size_type l, size_type r) const :
	時間計算量: θ(loglog n)
	[l, r) を fold した結果を返す

# 参考
https://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b, 2020/04/30
*/

template <typename T>
struct DisjointSparseTable {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
	template<class InputIterator>
	DisjointSparseTable(InputIterator first, InputIterator last, const F &f) : f(f) {
		table.emplace_back(first, last);
		build();
	}
	
	size_type empty() const noexcept { return size() == 0; }
	size_type size() const noexcept { return table.empty() ? 0 : table.front().size(); }
	
	value_type fold(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		--r;
		if (l == r) return table.front()[l];
		int level = msb(l ^ r) + 1;
		return f(table[level][l ^ (1 << level - 1) - 1], table[level][r]);
	}
	
private:
	F f;
	std::vector<std::vector<value_type>> table;
	
	void build() {
		assert(table.size() == 1);
		table.reserve(size() > 1 ? msb(size() - 1) + 2: 1);
		for (size_type level = 1; 1 << level - 1 <= size(); ++level) {
			size_type rest = size() % (1 << level);
			table.emplace_back();
			table.reserve(rest > 1 << level - 1 ? size() : size() - rest);
			
			for (size_type i = 0; i < size(); i += 1 << level) {
				size_type k = std::min(i + (1 << level - 1), size());
				if (k == size()) continue;
				
				table.back().emplace_back(table.front()[k - 1]);
				for (size_type j = k - 1; j > i; --j)
					table.back().emplace_back(f(table.front()[j - 1], table.back().back()));
				
				table.back().emplace_back(table.front()[k]);
				for (size_type j = k + 1, ej = std::min(i + (1 << level), size()); j < ej; ++j)
					table.back().emplace_back(f(table.back().back(), table.front()[j]));
			}
		}
	}
	
	size_type msb(size_type n) const {
		size_type l = 0, r = table.size();
		while (r - l > 1) {
			size_type m = (l + r) / 2;
			if (1 << m <= n) l = m;
			else r = m;
		}
		return l;
	}
};


#line 4 "Test/DisjointSparseTable.test.cpp"
// これは可換の場合でのテスト

#include <cstdio>
#line 8 "Test/DisjointSparseTable.test.cpp"

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	
	using ll = long long;
	DisjointSparseTable<ll> dst(A.begin(), A.end(), [](ll x, ll y) {
		return x + y;
	});
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", dst.fold(l, r));
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

