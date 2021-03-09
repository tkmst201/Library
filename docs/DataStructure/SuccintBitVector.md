---
title: 簡潔ビットベクトル
documentation_of: //DataStructure/SuccintBitVector.hpp
---

# 概要

ビット列を扱うデータ構造です。  
長さ $N$ のビット列に対し事前計算 $\Theta(N)$ で、ある位置までに存在する $1$ (または $0$ ) の個数を $\Theta(1)$ 、先頭から $i$ 番目の $1$ (または $0$ ) の位置を $\mathcal{O}(\log{N})$ で求めることができます。  

- `SuccintBitVector(size_t n)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `SuccintBitVector(const std::vector<uint8> & bits)`
	- $\Theta(\|$`bits`$\|)$ ビット列 `bits` で初期化
- `void build()`
	- 時間: $\Theta(N)$ 空間: $N + o(N)$ 事前計算を行う。`rank`、`select` を使用する前に呼ぶ
- `size_t size()`
	- $\Theta(1)$ ビット列の長さ $N$ を返す
- `void set(size_t i)`
	- $\Theta(1)$ $B_i = 1$
- `void reset(size_t i)`
	- $\Theta(1)$ $B_i = 0$
- `bool access(size_t i)`
	- $\Theta(1)$ $B_i$ を返す
- `uint32_t rank1(size_t i)`
	- $\Theta(1)$ $B_0, \ldots, B_{i-1}$ に存在する $1$ の個数を返す
- `uint32_t rank0(size_t i)`
	- $\Theta(1)$ $B_0, \ldots, B_{i-1}$ に存在する $0$ の個数を返す
- `size_t select1(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から $k$ 番目の $1$ の位置を 1-indexed で返す。そのような位置が存在しなければ $N + 1$ を返す
- `size_t select0(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から $k$ 番目の $0$ の位置を 1-indexed で返す。そのような位置が存在しなければ $N + 1$ を返す

<br>

# コンストラクタ

### SuccintBitVector(size_t n)

要素数 $n$ で初期化します。
はじめ、すべてのビットは $0$ です。  

**計算量**

- $\Theta(n)$

---

### SuccintBitVector(const std::vector<uint8> & bits)

ビット列 `bits` で初期化します。  

**計算量**

- $\Theta(\|$`bits`$\|)$

---

<br>

# メンバ関数

以下、長さ $N$ のビット列 $B_0, B_1, \ldots, B_{N-1}$ を対象とします。  

---

### void build()

事前計算を行います。
`rank` 、`select` を呼ぶ前に必ず呼んでください。  

**計算量**

- 時間: $\Theta(N)$
- 空間: $N + o(N)$ \[bit\]

---

### size_t size()

ビット列の長さ $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void set(size_t i)

$B_i$ を $1$ に変更します。
`build` の後に呼んだ場合のその後の動作は未定義です。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### void reset(size_t i)

$B_i$ を $0$ に変更します。
`build` の後に呼んだ場合のその後の動作は未定義です。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### bool access(size_t i)

$B_i$ を返します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### uint32_t rank1(size_t i)

$B_0, \ldots, B_{i-1}$ に存在する $1$ の個数を返します。
ただし、$i = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\Theta(1)$

---

### uint32_t rank0(size_t i)

$B_0, \ldots, B_{i-1}$ に存在する $0$ の個数を返します。
ただし、$i = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\Theta(1)$

---

### size_t select1(size_t k)

先頭から $k$ 番目の $1$ の位置を 1-indexed で返します。
$k = 0$ または、そのような位置が存在しなければ $N + 1$ を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log{N})$

---

### size_t select0(size_t k)

先頭から $k$ 番目の $0$ の位置を 1-indexed で返します。
$k = 0$ または、そのような位置が存在しなければ $N + 1$ を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SuccintBitVector.hpp>
using namespace std;

int main() {
	SuccintBitVector bit(10);
	bit.set(0);
	bit.set(4);
	bit.set(6);
	bit.set(8);
	bit.set(9);
	
	cout << bit.access(9) << endl; // 1
	bit.reset(9);
	cout << bit.access(9) << endl; // 0
	bit.set(9);
	
	for (int i = 0; i < 10; ++i) cout << bit.access(i); cout << endl; // 1000101011
	
	bit.build(); // 忘れずに呼ぶ
	
	/*
		i = 0 : rank0 = 0, rank1 = 0
		i = 1 : rank0 = 0, rank1 = 1
		i = 2 : rank0 = 1, rank1 = 1
		i = 3 : rank0 = 2, rank1 = 1
		i = 4 : rank0 = 3, rank1 = 1
		i = 5 : rank0 = 3, rank1 = 2
		i = 6 : rank0 = 4, rank1 = 2
		i = 7 : rank0 = 4, rank1 = 3
		i = 8 : rank0 = 5, rank1 = 3
		i = 9 : rank0 = 5, rank1 = 4
		i = 10 : rank0 = 5, rank1 = 5
	*/
	for (int i = 0; i <= 10; ++i) cout << "i = " << i << " : rank0 = " << bit.rank0(i) << ", rank1 = " << bit.rank1(i) << endl;
	
	/*
		i = 0 : select0 = 0, select1 = 0
		i = 1 : select0 = 2, select1 = 1
		i = 2 : select0 = 3, select1 = 5
		i = 3 : select0 = 4, select1 = 7
		i = 4 : select0 = 6, select1 = 9
		i = 5 : select0 = 8, select1 = 10
		i = 6 : select0 = 11, select1 = 11
	*/
	for (int i = 0; i <= 6; ++i) cout << "i = " << i << " : select0 = " << bit.select0(i) << ", select1 = " << bit.select1(i) << endl;
}
```

<br>

# TODO

TODO: $\Theta(1)$ `rank` を調べる  

<br>

# 参考

2020/09/03: [https://misteer.hatenablog.com/entry/bit-vector](https://misteer.hatenablog.com/entry/bit-vector)  
2020/09/03: [https://miti-7.hatenablog.com/entry/2018/04/15/155638](https://miti-7.hatenablog.com/entry/2018/04/15/155638)  

<br>