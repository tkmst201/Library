---
title: 赤黒木 (平衡二分探索木)
documentation_of: //DataStructure/RedBlackTree.hpp
---

# 概要

順序付き集合を扱う赤黒木です。
要素数 $N$ に対し、基本的な操作を $\Theta(\log{N})$ で行うことができます。  
[AVL 木](https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp) と比べると `insert` 、`erase` は速く、検索クエリは遅いです。  
速度はそこまで変わらないので、より機能が多い [AVL 木](https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp) を使用した方が良いです。  

- `RedBlackTree()`
	- $\Theta(1)$ 空の赤黒木を作成
- `RedBlackTree(const RedBlackTree & rhs)`
	- $\Theta(\|$`rhs`$\|)$ `rhs` をコピー
- `RedBlackTree(RedBlackTree && rhs)`
	- $\Theta(1)$ `rhs` をムーブ
- `bool empty()`
	- $\Theta(1)$ 赤黒木が空であるか判定
- `size_t size()`
	- $\Theta(1)$ 要素数 $N$ を返す
- `void clear()`
	- $\Theta(N)$ すべての要素を削除
- `std::vector<T> enumerate()`
	- $\Theta(N)$ すべての要素を昇順に列挙
- `Node * begin()`
	- $\Theta(1)$ 先頭の要素のポインタを返す
- `Node * end()`
	- $\Theta(1)$ 最後の要素の次の位置を示すポインタを返す
- `Node * insert(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ を追加
- `Node * erase(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の中で先頭の要素を削除し、その次の要素のポインタを返す
- `Node * erase(Node * q)`
	- $\Theta(\log{N})$ ポインタ $q$ が指す要素を削除し、その次の要素のポインタを返す
- `Node * find(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の中で先頭の要素のポインタを返す
- `Node * lower_bound(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以上の要素の中で先頭の要素のポインタを返す
- `Node * upper_bound(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ より大きい要素の中で先頭の要素のポインタを返す
- `Node * next(Node * q)`
	- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$ ポインタ $q$ が指す要素の次の要素のポインタを返す
- `Node * prev(Node * q)`
	- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$ ポインタ $q$ が指す要素の $1$ つ前の要素のポインタを返す

<br>

# コンストラクタ

以降、要素数を $N$ とします。  

---

**制約**

- `T` は比較可能

---

### RedBlackTree()

空の赤黒木を作成します。  

**計算量**

- $\Theta(1)$

---

### RedBlackTree(const RedBlackTree & rhs)

`rhs` をコピーします。  

**計算量**

- $\Theta(N + \|$`rhs`$\|)$

---

### RedBlackTree(RedBlackTree && rhs)

`rhs` をムーブします。
ムーブ後の `rhs` は空の赤黒木となります。  

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

すべての要素は値の昇順に、同じ値同士は追加した順に順序付けされているとします。  

---

### bool empty()

赤黒木が空であるか判定します。
空なら $true$ 、そうでないなら $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void clear()

すべての要素を削除します。  

**計算量**

- $\Theta(N)$

---

### std::vector<T> enumerate()

すべての要素を昇順に列挙します。  

**計算量**

- $\Theta(N)$

---

### Node * begin()

先頭の要素のポインタを返します。  

**計算量**

- $\Theta(1)$

---

### Node * end()

最後の要素の次の位置を示すポインタを返します。  

**計算量**

- $\Theta(1)$

---

### Node * insert(const T & x)

値 $x$ を追加します。
追加した要素のポインタを返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * erase(const T & x)

値 $x$ と等しい要素の中で先頭の要素を削除し、その次の要素のポインタを返します。
値 $x$ が存在しない場合は何も行わず、`end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * erase(Node * q)

ポインタ $q$ が指す要素を削除し、その次の要素のポインタを返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\Theta(\log{N})$

---

### Node * find(const T & x)

値 $x$ と等しい要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * lower_bound(const T & x)

値 $x$ 以上の要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * upper_bound(const T & x)

値 $x$ より大きい要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * next(Node * q)

ポインタ $q$ が指す要素の次の要素のポインタを返します。
$q =$ `end()` の場合は `begin()` を返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$

---

### Node * prev(Node * q)

ポインタ $q$ が指す要素の $1$ つ前の要素のポインタを返します。
$q =$ `begin()` の場合は `end()` を返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/RedBlackTree.hpp"
using namespace std;

int main() {
	RedBlackTree<int> rbt;
	cout << "size = " << rbt.size() << endl; // 0
	
	for (int i : {1, 2, 2, 3, 4, 5, 6, 6, 6, 7}) rbt.insert(i);
	cout << "size = " << rbt.size() << endl; // 10
	
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 2 3 4 5 6 6 6 7
	cout << "min = " << rbt.begin()->val << endl; // 1
	cout << "max = " << rbt.prev(rbt.end())->val << endl; // 7
	
	auto it = rbt.find(2);
	cout << "find(2) : " << it->val << endl; // 2
	cout << "next : " << rbt.next(it)->val << endl; // 2
	cout << "prev : " << rbt.prev(it)->val << endl; // 1
	
	rbt.erase(it);
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 6 7
	rbt.erase(6);
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	
	cout << "lower_bound(-1) = " << rbt.lower_bound(-1)->val << endl; // 1
	cout << "upper_bound(6) = " << rbt.upper_bound(6)->val << endl; // 7
	cout << "upper_bound(7) == end() : " << boolalpha << (rbt.upper_bound(7) == rbt.end()) << endl; // true
	
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		RedBlackTree<int> rbt2 = rbt;
		for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		RedBlackTree<int> rbt2 = std::move(rbt);
		for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // empty
	cout << "empty = " << boolalpha << rbt.empty() << endl; // true
}
```

<br>

# 参考

2020/08/27: [https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8](https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8)  
2020/08/27: [http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html](http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html)  
2020/08/27: [http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html](http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html)  

<br>