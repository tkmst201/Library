---
title: Sliding Window Aggregation (SWAG)
documentation_of: //DataStructure/SlidingWindowAggregation.hpp
---

# 概要

数列を扱うデータ構造です。  
キューの `enqueue` 、`dequeue` 操作をならし $\Theta(1)$ で、キューに入っている要素全体の `fold` 演算を $\Theta(1)$ でできます。  
区間に対して一意に値が定まり、区間をまとめて計算できるような演算が扱えます。例: `+`, `xor`, `min`, `gcd`, `関数の合成` など。  

- ` SlidingWindowAggregation(const T & id_elem, const F & f)`
	- $\Theta(1)$ 単位元 `id_elem` 、二項演算 $f$ で初期化
- ` size_t size()`
	- $\Theta(1)$ 現在キューに入っている要素数を返す
- ` void push(const T & x)`
	- ならし $\Theta(1)$ 値 $x$ をキューに追加
- ` void pop()`
	- ならし $\Theta(1)$ キューの先頭要素を削除
- ` T fold_all()`
	- $\Theta(1)$ キューに入っている要素を追加した順に $f$ で畳み込んだ結果を返す。

<br>

# コンストラクタ

`F` は二項演算 `std::function<T (const T &, const T &)>` の略記です。  

**制約**

- `F` の単位元は `id_elem`
- $(T, f,$ `id_elem`$)$ はモノイド

---

### SlidingWindowAggregation(const T & id_elem, const F & f)

単位元 `id_elem` 、二項演算 $f$ で初期化します。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

### size_t size()

現在キューに入っている要素数を返します。  

**計算量**

- $\Theta(1)$

---

### void push(const T & x)

値 $x$ をキューに追加します。  

**計算量**

- ならし $\Theta(1)$

---

### void pop()

キューの先頭要素を削除します。

**制約**

- キューが空でない

**計算量**

- ならし $\Theta(1)$

---

### T fold_all()

キューに入っている要素の個数を $N$ 、キューに入っている要素を追加した順に $A_1, A_2, \ldots, A_N$ として、$f(A_1, f(A_2, f(\ldots, A_N)\ldots))$ を返します。  
キューに何も入っていない場合は単位元を返します。  

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

`min` を載せました。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SlidingWindowAggregation.hpp>
using namespace std;

int main() {
	SlidingWindowAggregation<int> swag(numeric_limits<int>::max(),
		[](auto x, auto y) { return min(x, y); });
	
	cout << "size() = " << swag.size() << endl; // 0
	cout << "fold_all() = " << swag.fold_all() << endl; // INF
	swag.push(10);
	cout << "fold_all() = " << swag.fold_all() << endl; // 10
	swag.push(9);
	swag.push(12);
	swag.push(13);
	cout << "size() = " << swag.size() << endl; // 4
	cout << "fold_all() = " << swag.fold_all() << endl; // 9
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 9
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 12
	cout << "size() = " << swag.size() << endl; // 2
	swag.pop();
	cout << "fold_all() = " << swag.fold_all() << endl; // 13
	swag.pop();
	cout << "size() = " << swag.size() << endl; // 0
	cout << "fold_all() = " << swag.fold_all() << endl; // INF
}
```

<br>

# 参考

2020/09/22: [https://scrapbox.io/data-structures/Sliding_Window_Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)
2020/09/22: [https://snuke.hatenablog.com/entry/2018/09/18/135640](https://snuke.hatenablog.com/entry/2018/09/18/135640)

<br>