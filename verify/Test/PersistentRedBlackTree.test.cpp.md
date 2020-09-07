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


# :heavy_check_mark: Test/PersistentRedBlackTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/PersistentRedBlackTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/associative_array">https://judge.yosupo.jp/problem/associative_array</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/PersistentRedBlackTree.hpp.html">DataStructure/PersistentRedBlackTree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/PersistentRedBlackTree.hpp"

#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	
	std::vector<int> q(Q);
	std::vector<ll> k(Q), v(Q);
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %lld", &q[i], &k[i]);
		if (q[i] == 0) scanf("%lld", &v[i]);
	}
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	std::vector<ll> cv;
	compress(k, cv);
	PersistentRedBlackTree<ll> tree(cv.size(), 0);
	
	for (int i = 0; i < Q; ++i) {
		if (q[i] == 0) {
			tree.erase(k[i]);
			tree.insert(k[i], v[i]);
		}
		else {
			printf("%lld\n", tree.get(k[i]));
		}
	}
	
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/PersistentRedBlackTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#line 1 "DataStructure/PersistentRedBlackTree.hpp"



#include <cassert>
#include <memory>
#include <utility>
#include <vector>

/*
last-updated: 2020/09/01

merge/split ベースの完全永続赤黒木

TODO: メモリプールを使用して高速化(できるかはわからない)

# 仕様
PersistentRedBlackTree() :
	時間計算量: O(1)
	空の木を作成

PersistentRedBlackTree(const std::vector<value_type> & v) :
	時間計算量: O(n)
	配列 v で初期化

PersistentRedBlackTree(size_type n, const_reference x) :
	時間計算量: O(n)
	n 個の値 x で初期化

size_type size() const noexcept :
	時間計算量: O(1)
	要素数を返す

bool empty() const noexcept :
	時間計算量: O(1)
	木が空であるかどうか判定する

PersistentRedBlackTree merge(const PersistentRedBlackTree & a) :
	時間計算量: O(|root.rank - a.rank|)
	赤黒木 a を merge した赤黒木を返す

std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type k) :
	時間計算量: O(log n)
	先頭 k 個の要素を持つ赤黒木とそれ以降の要素を持つ赤黒木の 2 つの赤黒木に分割して返す

PersistentRedBlackTree insert(size_type k, const_reference x) :
	時間計算量: O(log n)
	k 番目(0 \leq k \leq n) に値 x を挿入した赤黒木を返す

PersistentRedBlackTree erase(size_type k) :
	時間計算量: O(log n)
	k 番目の要素(0 \leq k < n) を削除した赤黒木を返す

const_reference get(size_type k) :
	時間計算量: O(log n)
	k 番目(9 \leq k < n) の要素を返す

bool check() const : 赤黒木の条件を満たしているか確認する

↓ 静的メンバ関数 ver. (元の木に変更を与えずに新たな木を生成して返す)
static PersistentRedBlackTree merge(const PersistentRedBlackTree & a, const PersistentRedBlackTree & b) :
static std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(const PersistentRedBlackTree & a, size_type k) :
static PersistentRedBlackTree insert(const PersistentRedBlackTree & a, const_reference x, size_type k) :
static PersistentRedBlackTree erase(const PersistentRedBlackTree & a, size_type k) :
static const_reference get(const PersistentRedBlackTree & a, size_type k) :

# 参考
https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf, 2020/08/30
http://blog.mitaki28.info/1447078746296/, 2020/08/30
http://algoogle.hadrori.jp/algorithm/rbtree_merge.html, 2020/08/30
*/

template<typename T>
struct PersistentRedBlackTree {
public:
	static constexpr bool red = true;
	static constexpr bool black = false;
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
	struct Node;
	using node_ptr = std::shared_ptr<Node>;
	
	struct Node {
		value_type val;
		bool color;
		size_type size, rank;
		node_ptr left, right;
		
		Node(bool color, const node_ptr & left, const node_ptr & right)
			: color(color), size(left->size + right->size), rank(left->rank + (left->color == black)),
				left(left), right(right) {}
		
		Node(const_reference val) : val(val), color(black), size(1), rank(0) {}
	};
	
private:
	static node_ptr create(bool color, const node_ptr & left, const node_ptr & right) {
		return std::make_shared<Node>(color, left, right);
	}
	
	static node_ptr create(const_reference val) {
		return std::make_shared<Node>(val);
	}
	
private:
	node_ptr root = nullptr;
	PersistentRedBlackTree(const node_ptr & root) : root(root) {}
	
public:
	PersistentRedBlackTree() {}
	PersistentRedBlackTree(const std::vector<value_type> & v) {
		if (!v.empty()) root = build(v);
	}
	PersistentRedBlackTree(size_type n, const_reference x) : PersistentRedBlackTree(std::vector<value_type>(n, x)) {}
	
	size_type size() const noexcept {
		return root ? root->size : 0;
	}
	
	bool empty() const noexcept {
		return size() == 0;
	}
	
	const PersistentRedBlackTree & merge(const PersistentRedBlackTree & a) {
		root = merge(root, a.root);
		return *this;
	}
	
	std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type k) {
		assert(k <= size());
		return split(*this, k);
	}
	
	const PersistentRedBlackTree & insert(size_type k, const_reference x) {
		assert(k <= size());
		root = insert(root, k, x);
		return *this;
	}
	
	const PersistentRedBlackTree & erase(size_type k) {
		assert(k < size());
		root = erase(root, k);
		return *this;
	}
	
	const_reference get(size_type k) {
		assert(k < size());
		return get(root, k);
	}
	
public:
	static PersistentRedBlackTree merge(const PersistentRedBlackTree & a, const PersistentRedBlackTree & b) {
		return merge(a.root, b.root);
	}
	
	static std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(const PersistentRedBlackTree & a, size_type k) {
		assert(a.size() <= k);
		const auto sp = split(a.root, k);
		return {PersistentRedBlackTree{sp.first}, PersistentRedBlackTree{sp.second}};
	}
	
	static PersistentRedBlackTree insert(const PersistentRedBlackTree & a, size_type k, const_reference x) {
		assert(k <= a.size());
		return insert(a.root, k, x);
	}
	
	static PersistentRedBlackTree erase(const PersistentRedBlackTree & a, size_type k) {
		assert(k < a.size());
		return erase(a.root, k);
	}
	
	static const_reference get(const PersistentRedBlackTree & a, size_type k) {
		assert(k < a.size());
		return get(a.root, k);
	}
	
private:
	template<typename U>
	node_ptr build(const std::vector<U> & v) const {
		if (v.size() == 1) return create(v[0]);
		return merge(
			build(std::vector<U>(std::begin(v), std::begin(v) + v.size() / 2)),
			build(std::vector<U>(std::begin(v) + v.size() / 2, std::end(v)))
		);
	}
	
	static node_ptr as_root(const node_ptr & a) {
		if (!a) return nullptr;
		if (a->color == red) return create(black, a->left, a->right);
		return a;
	}
	
	static node_ptr merge(const node_ptr & a, const node_ptr & b) {
		if (!a) return b;
		if (!b) return a;
		return as_root(merge_sub(a, b));
	}
	
	static node_ptr merge_sub(const node_ptr & a, const node_ptr & b) {
		if (a->rank < b->rank) {
			node_ptr c = merge_sub(a, b->left);
			if (b->color == black && c->color == red && c->left->color == red) {
				if (b->right->color == black) return create(black, c->left, create(red, c->right, b->right));
				return create(red, create(black, c->left, c->right), create(black, b->right->left, b->right->right));
			}
			return create(b->color, c, b->right);
		}
		if (a->rank > b->rank) {
			const node_ptr c = merge_sub(a->right, b);
			if (a->color == black && c->color == red && c->right->color == red) {
				if (a->left->color == black) return create(black, create(red, a->left, c->left), c->right);
				return create(red, create(black, a->left->left, a->left->right), create(black, c->left, c->right));
			}
			return create(a->color, a->left, c);
		}
		return create(red, a, b);
	}
	
	static std::pair<node_ptr, node_ptr> split(const node_ptr &a, size_type k) {
		if (!a) return {nullptr, nullptr};
		return split_sub(a, k);
	}
	
	static std::pair<node_ptr, node_ptr> split_sub(const node_ptr & a, size_type k) {
		if (k == 0) return {nullptr, as_root(a)};
		if (k == a->size) return {as_root(a), nullptr};
		if (k < a->left->size) {
			const auto sp = split_sub(a->left, k);
			return {as_root(sp.first), merge(sp.second, as_root(a->right))};
		}
		if (k > a->left->size) {
			const auto sp = split_sub(a->right, k - a->left->size);
			return {merge(as_root(a->left), sp.first), as_root(sp.second)};
		}
		return {as_root(a->left), as_root(a->right)};
	}
	
	static node_ptr insert(const node_ptr & a, size_type k, const_reference x) {
		if (!a) return create(x);
		const auto sp = split(a, k);
		return merge(sp.first, merge(create(x), sp.second));
	}
	
	static node_ptr erase(const node_ptr & a, size_type k) {
		const auto sp = split(a, k + 1);
		return merge(split(sp.first, k).first, sp.second);
	}
	
	static const_reference get(node_ptr a, size_type k) {
		while (a->left) {
			if (k < a->left->size) a = a->left;
			else {
				k -= a->left->size;
				a = a->right;
			}
		}
		return a->val;
	}
};


#line 4 "Test/PersistentRedBlackTree.test.cpp"

#include <cstdio>
#line 7 "Test/PersistentRedBlackTree.test.cpp"
#include <algorithm>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	
	std::vector<int> q(Q);
	std::vector<ll> k(Q), v(Q);
	
	for (int i = 0; i < Q; ++i) {
		scanf("%d %lld", &q[i], &k[i]);
		if (q[i] == 0) scanf("%lld", &v[i]);
	}
	
	auto compress = [](auto &&v, auto &&cv) -> void {
		for (auto &&u : v) cv.emplace_back(u);
		std::sort(std::begin(cv), std::end(cv));
		cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));
		for (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);
	};
	
	std::vector<ll> cv;
	compress(k, cv);
	PersistentRedBlackTree<ll> tree(cv.size(), 0);
	
	for (int i = 0; i < Q; ++i) {
		if (q[i] == 0) {
			tree.erase(k[i]);
			tree.insert(k[i], v[i]);
		}
		else {
			printf("%lld\n", tree.get(k[i]));
		}
	}
	
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
