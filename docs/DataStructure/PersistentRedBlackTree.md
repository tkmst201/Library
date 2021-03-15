---
title: 完全永続赤黒木 (平衡二分木)
documentation_of: //DataStructure/PersistentRedBlackTree.hpp
---

# 概要

完全永続赤黒木です。
可変配列を扱います。大きさ $N$ の配列の過去の任意の状態に対し、`split`、 `merge`、データの挿入、削除が $\mathcal{O}(\log{N})$ で行うことができます。
各操作 $\mathcal{O}(\log{N})$ の空間を消費します。    

- `PersistentRedBlackTree()`
	- $\Theta(1)$ 要素数 $0$ の可変配列で初期化
- `PersistentRedBlackTree(std::vector<T> v)`
	- 時間/空間 $\Theta($`v`$)$ $v$ で初期化
- `PersistentRedBlackTree(size_t n, const T & x)`
	- 時間/空間 $\Theta(n)$ すべての値が $x$ の要素数 $n$ の可変配列で初期化
- `bool empty()`
	- $\Theta(1)$ 可変配列が空なら $true$ を返す
- `size_t size()`
	- $\Theta(1)$ 可変配列の要素数 $N$ を返す
- `void clear()`
	- $\mathcal{O}(N)$ 可変配列のすべての要素を削除
- `std::vector<T> enumerate()`
	- $\Theta(N)$ 現在の可変配列を返す  
- `PersistentRedBlackTree merge(const PersistentRedBlackTree & a)`
	- 時間/空間 $\Theta(\|$`rank` $-$ `a.rank`$\|)$ 可変配列の末尾に `a` を追加した可変配列を返す
- `pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_t k)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 可変配列の先頭 $k$ 個の要素と $k + 1$ 個目の要素以降の $2$ つの可変配列に分けてこの順で返す
- `PersistentRedBlackTree insert(size_t k, const T & x)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 前に $k$ 個の要素がある位置に $x$ を挿入した可変配列を返す
- `PersistentRedBlackTree erase(size_t k)`
	- 時間/空間 $\mathcal{O}(\log{N})$ 先頭から `0-indexed` で $k$ 番目の要素を削除した可変配列を返す
- `const T & get(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から `0-indexed` で $k$ 番目の要素を返す

<br>

# コンストラクタ

### PersistentRedBlackTree()

要素数 $0$ の可変配列で初期化します。  
$T$ には保持したい値の型を指定します。  

**計算量**

- $\Theta(1)$

---

### PersistentRedBlackTree(std::vector&lt;T&gt; v)

$v$ で初期化します。  

**制約**

- `InputIterator` は `Random Access Iterator`

**計算量**

- $\Theta($`v`$)$

---

<br>

### PersistentRedBlackTree(size_t n, const T & x)

すべての値が $x$ の要素数 $n$ の可変配列で初期化します。  

**制約**

- `InputIterator` は `Random Access Iterator`

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

可変配列の要素数を $N$ とします。  
根から葉までのパス上 (根含まない) にある黒ノードの個数を `rank` とします。  

### bool empty()

可変配列が空なら $true$ を返します。
それ以外は $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

可変配列の要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void clear()

可変配列のすべての要素を削除します。  

**計算量**

- $\mathcal{O}(N)$

### std::vector<T> enumerate()

現在の可変配列を返します。  

**計算量**

- $\Theta(N)$

### PersistentRedBlackTree merge(const PersistentRedBlackTree & a)

可変配列の末尾に `a` を追加した可変配列を返します。  

**計算量**

- 時間/空間 $\Theta(\|$`rank` $-$ `a.rank`$\|)$

### pair&lt;PersistentRedBlackTree, PersistentRedBlackTree&gt; split(size_t k)

可変配列の先頭 $k$ 個の要素と $k + 1$ 個目の要素以降の $2$ つの可変配列に分けてこの順で返します。  

**制約**

- $0 \leq k \leq N$

**計算量**

- 時間/空間 $\mathcal{O}(\log{N})$

### PersistentRedBlackTree insert(size_t k, const T & x)

前に $k$ 個の要素がある位置に $x$ を挿入した可変配列を返します。  

**制約**

- $0 \leq k \leq N$

**計算量**

- 時間/空間 $\mathcal{O}(\log{N})$

### PersistentRedBlackTree erase(size_t k)

先頭から `0-indexed` で $k$ 番目の要素を削除した可変配列を返します。  

**制約**

- 時間/空間 $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

### const T & get(size_t k)

先頭から `0-indexed` で $k$ 番目の要素を返します。  

**制約**

- $0 \leq k < N$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PersistentRedBlackTree.hpp"
using namespace std;

int main() {
	PersistentRedBlackTree<int> rbt({0, 1, 2, 3, 4, 5, 6});
	
	cout << "empty() = " << boolalpha << rbt.empty() << endl; // false
	cout << "size = " << rbt.size() << endl; // 7
	// 0 1 2 3 4 5 6
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n';
	
	auto rbt2 = rbt.insert(0, 100);
	auto rbt3 = rbt.insert(3, 100);
	auto rbt4 = rbt.insert(7, 100);
	// 0 1 2 3 4 5 6
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n';
	// 100 0 1 2 3 4 5 6
	for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n';
	// 0 1 2 100 3 4 5 6
	for (int i : rbt3.enumerate()) cout << i << " "; cout << '\n';
	// 0 1 2 3 4 5 6 100
	for (int i : rbt4.enumerate()) cout << i << " "; cout << '\n';
	
	auto rbtm = rbt3.merge(rbt4);
	// 0 1 2 100 3 4 5 6 0 1 2 3 4 5 6 100
	for (int i : rbtm.enumerate()) cout << i << " "; cout << '\n';
	
	// 100 3 4 5 6 0 ( [3, 9) )
	auto rbts = rbtm.split(9).first.split(3).second;
	for (int i : rbts.enumerate()) cout << i << " "; cout << '\n';
	
	cout << "get(3) = " << rbts.get(3) << endl; // 5
	
	auto rbte = rbts.erase(3);
	// 100 3 4 6 0
	for (int i : rbte.enumerate()) cout << i << " "; cout << '\n';
	
	rbt = PersistentRedBlackTree<int>();
	cout << "empty() = " << boolalpha << rbt.empty() << endl; // true
	
	// 5 5 5
	for (int i : PersistentRedBlackTree<int>(3, 5).enumerate()) cout << i << " "; cout << '\n';
}
```

<br>

# TODO

TODO: メモリプールを使って高速化  

<br>

# 参考

2020/08/30: [https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf](https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf)  
2020/08/30: [http://blog.mitaki28.info/1447078746296/](http://blog.mitaki28.info/1447078746296/)  
2020/08/30: [http://algoogle.hadrori.jp/algorithm/rbtree_merge.html](http://algoogle.hadrori.jp/algorithm/rbtree_merge.html)  

<br>