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


# :warning: DataStructure/PersistentStack.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PersistentStack.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_PERSISTENT_STACK_HPP
#define INCLUDE_GUARD_PERSISTENT_STACK_HPP

#include <vector>
#include <memory>
#include <cassert>

/*
last-updated: 2020/04/15 unverified

永続スタック

# 仕様
PersistentStack() :
	時間計算量: Θ(1)
	空の stack を作成する

bool empty() const :
	時間計算量: Θ(1)
	空であるかどうか判定する

PersistentStack push(value_type x) const :
	時間計算量: Θ(1)
	値 x を追加した stack を作成する

PersistentStack pop() const :
	時間計算量: Θ(1)
	一番最後に入れた要素を削除した stack を作成

const_reference top() const :
	時間計算量: Θ(1)
	最後に入れた要素を返す

# 参考
http://noshi91.hatenablog.com/entry/2019/02/04/175100, 2020/04/10
*/

template<typename T>
struct PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type &;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	struct Node {
		value_type value;
		sptr_type prev;
		Node(value_type value, sptr_type prev) : value(value), prev(prev) {}
	};
	
public:
	PersistentStack() = default;
	
	bool empty() const { return !static_cast<bool>(top_node); }
	
	PersistentStack push(const value_type &x) const { return PersistentStack{ std::make_shared<Node>(x, top_node) }; }
	
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack{top_node->prev};
	}
	
	value_type top() const {
		assert(!empty());
		return top_node->value;
	}
	
private:
	sptr_type top_node;
	PersistentStack(sptr_type prev) : top_node(prev) {}
};

#endif // INCLUDE_GUARD_PERSISTENT_STACK_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PersistentStack.hpp"



#include <vector>
#include <memory>
#include <cassert>

/*
last-updated: 2020/04/15 unverified

永続スタック

# 仕様
PersistentStack() :
	時間計算量: Θ(1)
	空の stack を作成する

bool empty() const :
	時間計算量: Θ(1)
	空であるかどうか判定する

PersistentStack push(value_type x) const :
	時間計算量: Θ(1)
	値 x を追加した stack を作成する

PersistentStack pop() const :
	時間計算量: Θ(1)
	一番最後に入れた要素を削除した stack を作成

const_reference top() const :
	時間計算量: Θ(1)
	最後に入れた要素を返す

# 参考
http://noshi91.hatenablog.com/entry/2019/02/04/175100, 2020/04/10
*/

template<typename T>
struct PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type &;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	struct Node {
		value_type value;
		sptr_type prev;
		Node(value_type value, sptr_type prev) : value(value), prev(prev) {}
	};
	
public:
	PersistentStack() = default;
	
	bool empty() const { return !static_cast<bool>(top_node); }
	
	PersistentStack push(const value_type &x) const { return PersistentStack{ std::make_shared<Node>(x, top_node) }; }
	
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack{top_node->prev};
	}
	
	value_type top() const {
		assert(!empty());
		return top_node->value;
	}
	
private:
	sptr_type top_node;
	PersistentStack(sptr_type prev) : top_node(prev) {}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>
