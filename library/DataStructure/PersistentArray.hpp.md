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


# :warning: DataStructure/PersistentArray.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PersistentArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP
#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP

#include <memory>
#include <stack>
#include <utility>
#include <cassert>

/*
last-updated: 2020/04/15

永続配列

# 仕様
PersistentArray() :
	時間計算量: Θ(1)
	空の array の作成

PersistentArray(size_type n, const_reference def_v) :
	時間計算量: Θ(n)
	サイズ n 以上の最小の 2 冪の配列を作成, 初期値は def_v

bool empty() const noexcept :
	時間計算量: Θ(1)
	空であるかどうかを判定する

size_type size() const noexcept :
	時間計算量: Θ(1)
	配列のサイズを返す

const_reference lookup(size_type i) const :
	時間計算量: Θ(log n)
	i(0-indexed) 番目の要素を返す

PersistentArray update(size_type i, const_reference x) const :
	時間計算量: Θ(log n)
	i(0-indexed) 番目の要素を x に書き換えた配列を作成

# 参考
https://trap.jp/post/663/, 2020/04/10
*/

template<typename T>
struct PersistentArray {
public:
	using value_type = int;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	using const_sptr_ptr = const sptr_type *;
	struct Node {
		sptr_type child[2];
		value_type value;
		Node() = default;
		Node(value_type value) : value(value) {}
	};
	
public:
	PersistentArray() = default;
	
	PersistentArray(size_type n, const_reference def_v) {
		depth = 0;
		while (1 << depth < n) ++depth;
		
		std::stack<std::pair<const_sptr_ptr, size_type>> stk;
		top_node = std::make_shared<Node>();
		stk.emplace(&top_node, 0);
		while (!stk.empty()) {
			const_sptr_ptr cur_node = stk.top().first;
			size_type cur_d = stk.top().second;
			stk.pop();
			
			if (cur_d == depth) (*cur_node)->value = def_v;
			else {
				for (size_type i = 0; i < 2; ++i) {
					(*cur_node)->child[i] = std::make_shared<Node>();
					stk.emplace(&(*cur_node)->child[i], cur_d + 1);
				}
			}
		}
	}
	
	bool empty() const noexcept { return !static_cast<bool>(top_node); }
	
	size_type size() const noexcept { return empty() ? 0 : 1 << depth; }
	
	const_reference lookup(size_type i) const {
		assert(i < size());
		const_sptr_ptr cur_node = &top_node;
		for (size_type pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {
			bool right = false;
			if (pos + (rng >> 1) <= i) {
				pos += rng >> 1;
				right = true;
			}
			cur_node = &(*cur_node)->child[right];
		}
		return (*cur_node)->value;
	}
	
	PersistentArray update(size_type i, const_reference x) const {
		assert(i < size());
		sptr_type nex_top = std::make_shared<Node>();
		const_sptr_ptr cur_node = &nex_top, walk_node = &top_node;
		for (size_type pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {
			bool right = false;
			if (pos + (rng >> 1) <= i) {
				pos += rng >> 1;
				right = true;
			}
			(*cur_node)->child[!right] = (*walk_node)->child[!right];
			(*cur_node)->child[right] = std::make_shared<Node>();
			
			cur_node = &(*cur_node)->child[right];
			walk_node = &(*walk_node)->child[right];
		}
		(*cur_node)->value = x;
		return PersistentArray(nex_top, depth);
	}
	
private:
	sptr_type top_node;
	size_type depth;
	
	PersistentArray(sptr_type top_node, size_type depth) : top_node(top_node), depth(depth) {}
};

#endif // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PersistentArray.hpp"



#include <memory>
#include <stack>
#include <utility>
#include <cassert>

/*
last-updated: 2020/04/15

永続配列

# 仕様
PersistentArray() :
	時間計算量: Θ(1)
	空の array の作成

PersistentArray(size_type n, const_reference def_v) :
	時間計算量: Θ(n)
	サイズ n 以上の最小の 2 冪の配列を作成, 初期値は def_v

bool empty() const noexcept :
	時間計算量: Θ(1)
	空であるかどうかを判定する

size_type size() const noexcept :
	時間計算量: Θ(1)
	配列のサイズを返す

const_reference lookup(size_type i) const :
	時間計算量: Θ(log n)
	i(0-indexed) 番目の要素を返す

PersistentArray update(size_type i, const_reference x) const :
	時間計算量: Θ(log n)
	i(0-indexed) 番目の要素を x に書き換えた配列を作成

# 参考
https://trap.jp/post/663/, 2020/04/10
*/

template<typename T>
struct PersistentArray {
public:
	using value_type = int;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	using const_sptr_ptr = const sptr_type *;
	struct Node {
		sptr_type child[2];
		value_type value;
		Node() = default;
		Node(value_type value) : value(value) {}
	};
	
public:
	PersistentArray() = default;
	
	PersistentArray(size_type n, const_reference def_v) {
		depth = 0;
		while (1 << depth < n) ++depth;
		
		std::stack<std::pair<const_sptr_ptr, size_type>> stk;
		top_node = std::make_shared<Node>();
		stk.emplace(&top_node, 0);
		while (!stk.empty()) {
			const_sptr_ptr cur_node = stk.top().first;
			size_type cur_d = stk.top().second;
			stk.pop();
			
			if (cur_d == depth) (*cur_node)->value = def_v;
			else {
				for (size_type i = 0; i < 2; ++i) {
					(*cur_node)->child[i] = std::make_shared<Node>();
					stk.emplace(&(*cur_node)->child[i], cur_d + 1);
				}
			}
		}
	}
	
	bool empty() const noexcept { return !static_cast<bool>(top_node); }
	
	size_type size() const noexcept { return empty() ? 0 : 1 << depth; }
	
	const_reference lookup(size_type i) const {
		assert(i < size());
		const_sptr_ptr cur_node = &top_node;
		for (size_type pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {
			bool right = false;
			if (pos + (rng >> 1) <= i) {
				pos += rng >> 1;
				right = true;
			}
			cur_node = &(*cur_node)->child[right];
		}
		return (*cur_node)->value;
	}
	
	PersistentArray update(size_type i, const_reference x) const {
		assert(i < size());
		sptr_type nex_top = std::make_shared<Node>();
		const_sptr_ptr cur_node = &nex_top, walk_node = &top_node;
		for (size_type pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {
			bool right = false;
			if (pos + (rng >> 1) <= i) {
				pos += rng >> 1;
				right = true;
			}
			(*cur_node)->child[!right] = (*walk_node)->child[!right];
			(*cur_node)->child[right] = std::make_shared<Node>();
			
			cur_node = &(*cur_node)->child[right];
			walk_node = &(*walk_node)->child[right];
		}
		(*cur_node)->value = x;
		return PersistentArray(nex_top, depth);
	}
	
private:
	sptr_type top_node;
	size_type depth;
	
	PersistentArray(sptr_type top_node, size_type depth) : top_node(top_node), depth(depth) {}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

