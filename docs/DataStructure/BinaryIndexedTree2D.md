---
title: 二次元 Binary Indexed Tree
documentation_of: //DataStructure/BinaryIndexedTree2D.hpp
---

# 概要

二次元になった Binary Indexed Tree です。  
大きさ $H \times W$ の二次元グリッド上で $1$ 点加算と任意の矩形領域和の計算が $\mathcal{O}(\log{H} \log{W})$ で行えます。  

- `BinaryIndexedTree_Ragne2d(size_t h, size_t w)`
	- $\Theta(hw)$ $h \times w$ のテーブルで初期化
- `pair<size_t, size_t> size()`
	- $\Theta(1)$ テーブルの型 $(H, W)$ を返す
- `void add(size_t i, size_t j, T x)`
	- $\mathcal{O}(\log{H} \log{W})$ $A_{ij}$ += $x$ をする
- `T sum(size_t i, size_t j)`
	- $\mathcal{O}(\log{H} \log{W})$ $\sum_{y=0}^{i-1} \sum_{x=0}^{j-1} A_{yx}$ を返す
- `T sum(size_t i1, size_t j1, size_t i2, size_t j2)`
	- $\mathcal{O}(\log{H} \log{W})$ $\sum_{y=i1}^{i2-1} \sum_{x=j1}^{j2-1} A_{yx}$ を返す

<br>

# コンストラクタ

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`, [`ModInt`](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)

---

### BinaryIndexedTree_Ragne2d(size_t h, size_t w)

$h \times w$ のテーブルで初期化します。
初期値は $0$ です。  

**計算量**

- $\Theta(hw)$

---

<br>

# メンバ関数

以下、$H \times W$ のテーブル $A_{ij}\ (0 \leq i < H,\ 0 \leq j < W)$ を対象とします。

---

### pair<size_t, size_t> size()

テーブルの型 $(H, W)$ を返します。  

**計算量**

- $\Theta(1)$

---

### void add(size_t i, size_t j, T x)

$A_{ij}$ += $x$ をします。  

**制約**

- $0 \leq i < H$
- $0 \leq j < W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

### T sum(size_t i, size_t j)

$\sum_{y=0}^{i-1} \sum_{x=0}^{j-1} A_{yx}$ を返します。
$i = 0$ または $j = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq H$
- $0 \leq j \leq W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

### T sum(size_t i1, size_t j1, size_t i2, size_t j2)

$\sum_{y=i1}^{i2-1} \sum_{x=j1}^{j2-1} A_{yx}$ を返します。
$i1 = i2$ または $j1 = j2$ のときは $0$ を返します。  

**制約**

- $0 \leq i1 \leq i2 \leq H$
- $0 \leq j1 \leq j2 \leq W$

**計算量**

- $\mathcal{O}(\log{H} \log{W})$

---

<br>

# 使用例

オーバーフローに注意してください。総和が $2^{31}$ 以上になる場合は `long long` を使いましょう。  

```cpp
#include <bits/stdc++.h>
#include <DataStructure/BinaryIndexedTree2D.hpp>
using namespace std;

int main() {
	BinaryIndexedTree2D<int> bit(3, 4);
	
	auto [h, w] = bit.size();
	cout << "h = " << h << ", " << "w = " << w << endl; // 3, 4
	
	bit.add(0, 2, -2);
	bit.add(1, 0, 5);
	bit.add(2, 1, 4);
	bit.add(2, 3, 1);
	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << bit.sum(i, j, i + 1, j + 1) << " \n"[j + 1 == w];
		}
	}
	/*
		0 0 -2 0
		5 0 0 0
		0 4 0 1
	*/
	
	cout << "sum = " << bit.sum(1, 1, 3, 4) << endl; // 5
	cout << "sum = " << bit.sum(0, 0, 1, 3) << endl; // -2
	cout << "sum = " << bit.sum(3, 3) << endl; // 7
}
```

<br>

# TODO

TODO: `sum` の引数を `i1, i2, j1, j2` の順に変更  

<br>

# 参考

2020/08/15: [https://algo-logic.info/binary-indexed-tree/](https://algo-logic.info/binary-indexed-tree/)  

<br>