---
title: AVL 木 (平衡二分探索木)
documentation_of: //DataStructure/AVL_Tree.hpp
---

# 概要

順序付き集合を扱う AVL 木です。
要素数 $N$ に対し、基本的な操作を $\Theta(\log{N})$ で行うことができます。  

- `AVL_Tree()`
	- $\Theta(1)$ 空の AVL 木を作成
- `AVL_Tree(const AVL_Tree & rhs)`
	- $\Theta(\|$`rhs`$\|)$ `rhs` をコピー
- `AVL_Tree(AVL_Tree && rhs)`
	- $\Theta(1)$ `rhs` をムーブ
- `bool empty()`
	- $\Theta(1)$ AVL 木が空であるか判定
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
- `size_t count_less_than(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 未満の要素の個数を返す
- `size_t count_less_equal(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以下の要素の個数を返す
- `size_t count_greater_than(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ より大きい要素の個数を返す
- `size_t count_greater_equal(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以上の要素の個数を返す
- `size_t count(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の個数を返す
- `Node * k_th_smallest(uint32_t k)`
	- $\Theta(\log{N})$ 先頭から $k$ 番目の要素のポインタを返す
- `Node * k_th_largest(uint32_t k)`
	- $\Theta(\log{N})$ 後ろから $k$ 番目の要素のポインタを返す
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

### AVL_Tree()

空の AVL 木を作成します。  

**計算量**

- $\Theta(1)$

---

### AVL_Tree(const AVL_Tree & rhs)

`rhs` をコピーします。  

**計算量**

- $\Theta(N + \|$`rhs`$\|)$

---

### AVL_Tree(AVL_Tree && rhs)

`rhs` をムーブします。
ムーブ後の `rhs` は空の AVL 木となります。  

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

すべての要素は値の昇順に、同じ値同士は追加した順に順序付けされているとします。  

---

### bool empty()

AVL 木が空であるか判定します。
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

### size_t count_less_than(const T & x)

値 $x$ 未満の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_less_equal(const T & x)

値 $x$ 以下の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_greater_than(const T & x)

値 $x$ より大きい要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_greater_equal(const T & x)

値 $x$ 以上の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count(const T & x)

値 $x$ と等しい要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * k_th_smallest(uint32_t k)

先頭から $k$ 番目の要素のポインタを返します。
$k = 0$ またはそのような要素が存在しない場合は `end()` を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\Theta(\log{N})$

---

### Node * k_th_largest(uint32_t k)

後ろから $k$ 番目の要素のポインタを返します。
$k = 0$ またはそのような要素が存在しない場合は `end()` を返します。  

**制約**

- $0 \leq k$

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
#include "DataStructure/AVL_Tree.hpp"
using namespace std;

int main() {
	AVL_Tree<int> avl;
	cout << "size = " << avl.size() << endl; // 0
	
	for (int i : {1, 2, 2, 3, 4, 5, 6, 6, 6, 7}) avl.insert(i);
	cout << "size = " << avl.size() << endl; // 10
	
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 2 3 4 5 6 6 6 7
	cout << "min = " << avl.begin()->val << endl; // 1
	cout << "max = " << avl.prev(avl.end())->val << endl; // 7
	
	auto it = avl.find(2);
	cout << "find(2) : " << it->val << endl; // 2
	cout << "next : " << avl.next(it)->val << endl; // 2
	cout << "prev : " << avl.prev(it)->val << endl; // 1
	
	avl.erase(it);
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 6 7
	avl.erase(6);
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	
	cout << "lower_bound(-1) = " << avl.lower_bound(-1)->val << endl; // 1
	cout << "upper_bound(6) = " << avl.upper_bound(6)->val << endl; // 7
	cout << "upper_bound(7) == end() : " << boolalpha << (avl.upper_bound(7) == avl.end()) << endl; // true
	
	cout << "count_less_than(3) = " << avl.count_less_than(3) << endl; // 2
	cout << "count_less_equal(4) = " << avl.count_less_equal(4) << endl; // 4
	cout << "count_greater_than(6) = " << avl.count_greater_than(6) << endl; // 1
	cout << "count_greater_equal(6) = " << avl.count_greater_equal(6) << endl; // 3
	cout << "count(6) = " << avl.count(6) << endl; // 2
	cout << "count_greater_than(7) = " << avl.count_greater_than(7) << endl; // 0
	
	cout << "k_th_smallest(3) = " << avl.k_th_smallest(3)->val << endl; // 3
	cout << "k_th_largest(4) = " << avl.k_th_largest(4)->val << endl; // 5
	
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		AVL_Tree<int> avl2 = avl;
		for (int i : avl2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		AVL_Tree<int> avl2 = std::move(avl);
		for (int i : avl2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // empty
	cout << "empty = " << boolalpha << avl.empty() << endl; // true
}
```

<br>

# 解説

### AVL 木の高さと頂点数の関係

ここでは、根と葉のパスに含まれる辺の個数の最大値を AVL 木の高さと定義し、頂点数 $N$ の AVL 木の高さがどれくらいになるか調べます。  

$C_i :=$ 高さが $i$ である AVL 木の最小頂点数 と定義します。
AVL 木の平衡条件より左部分木と右部分木の高さの差は $1$ 以下で、高さが低い方が最小頂点数は少ないので次のような関係式が成り立ちます。  

$$C_0 = 1, C_1 = 2, C_i = C_{i-1} + C_{i-2} + 1\ (i \geq 2)$$

フィボナッチ数列 $F_0 = 1, F_1 = 1, F_i = F_{i-1} + F_{i-2}\ (i \geq 2)$ と比較すると $C_i \geq F_i$ より、頂点数 $N$ に対して高さは $\mathcal{O}(\log{N})$ であることが分かります。  

また、高さ $h$ に対して頂点数が最大となるのは完全二分木 (葉以外の頂点がすべて $2$ つの子を持つ) となっているときで、頂点数 $N$ に対して最小の高さは $\Omega(\log{N})$ です。  

以上より、頂点数 $N$ の AVL 木の高さは $\Theta(\log{N})$ であることが分かりました。  

# TODO

TODO: イテレータを実装(アドレス解決演算子やアロー演算子で `val` にアクセスしたい)  
TODO: `size`, `height` を子ではなく自身で持つように変更(必要な空間が減る)

<br>

# 参考

2019/11/19: [https://ja.wikipedia.org/wiki/AVL%E6%9C%A8](https://ja.wikipedia.org/wiki/AVL%E6%9C%A8)  

<br>