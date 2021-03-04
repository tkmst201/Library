---
title: 組み合わせ $_nC_r$
documentation_of: //Mathematics/Combination.hpp
---

# 概要

`ModInt` 構造体に対して組み合わせを計算する構造体です。  
$5 \times 10^7$ 未満の $n$ や $r$ に対して $_nC_r \bmod{M}$ を ならし $\Theta(1)$ で計算します。  
[AC Library](https://github.com/atcoder/ac-library) の `Modint` 構造体を使用することもできます  
全体で $\max(n)$ の空間計算量がかかります。  

- `Combination(size_t sz = 1)`
	- $\Theta(sz + \log{M})$ $sz$ を指定することにより事前にテーブルを構築
- `T fact(size_t k)`
	- ならし $\Theta(1)$ $k!$ を返す。
- `T finv(size_t k)`
	- ならし $\Theta(1)$ $(k!)^{-1}$ を返す
- `T inv(size_t k)`
	- ならし $\Theta(1)$ $k^{-1}$ を返す
- `T c(int n, int r)`
	- ならし $\Theta(1)$ $_nC_r$ を返す

<br>

# コンストラクタ

**制約**

- $T$ は [`ModInt`](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)
- $T$ の法 $M$ は素数

---

### Combination(size_t sz = 1)

初期化します。
事前に $n$ として使用する値の最大値が分かっている場合は $sz$ にその値を指定すると少し早くなります。

**計算量**

- $\Theta(sz + \log{M})$

---

<br>

# メンバ関数

以下、`T: ModInt` の法を $M$ とします。
`MAX_LIMIT` は $5 \times 10^7$ です。  

### T fact(size_t k)

$k!$ を返します。  

**制約**

- $0 \leq k <$ `MAX_LIMIT`

**計算量**

- ならし $\Theta(1)$

---

### T finv(size_t k)

$(k!)^{-1}$ を返します。  

**制約**

- $0 \leq k < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

---

### T inv(size_t k)

$k^{-1}$ を返します。  

**制約**

- $0 \leq k < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

---

### T c(int n, int r)

$_nC_r \bmod{M}$ を返します。
$n < 0$ または $n < r$ の場合は $0$ を返します。  
`Combination(n, r)` と書いても同じ結果になります。
詳しくは使用例を参照してください。  

**制約**

- $0 \leq n < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <Mathematics/ModInt.hpp>
#include <Mathematics/Combination.hpp>
using namespace std;

constexpr int MOD = 13;
using mint = ModInt<MOD>;
using Comb = Combination<mint>;

int main() {
	Comb comb;
	cout << comb(5, 2) << endl; // 10
	cout << comb(3, 2) << endl; // 3
	cout << comb(8, 3) << endl; // 4 (8 * 7 * 6 / 3! = 56 = 4 + 4 * 13)
	
	cout << comb.fact(3) << endl; // 6 (= 3!)
	cout << comb.finv(5) << endl; // 9 (= (5!)^{-1})
	cout << comb.finv(5) * comb.fact(5) << endl; // 1
	cout << comb.inv(2) << endl; // 7 (2 * 7 = 14 = 1 + 13)
}
```

<br>

# 解説

事前計算のテーブルを $2$ 倍しながら計算することにより、ならし $\Theta(1)$ を達成しています。  
ならし計算量については [https://trap.jp/post/883/](https://trap.jp/post/883/) が参考になると思います。  

<br>

# TODO

TODO: test の追加  
TODO: 重複組合せ nHk の追加  
TODO: 順列 nPk の追加
TODO: $r$ が小さい場合の愚直計算の追加  