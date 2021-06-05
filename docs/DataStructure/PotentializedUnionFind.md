---
title: ポテンシャル付き Union Find
documentation_of: //DataStructure/PotentializedUnionFind.hpp
---

# 概要

差分制約の一次方程式を効率的に解くことができるデータ構造です。  
変数が $N$ 個あるとき、差分制約の追加や差分の計算をならし $\Theta(\alpha(N))$ ( $\alpha(N)$ はアッカーマン関数の逆関数 ) で計算できます。  
[Union Find](https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp) の機能強化版です。  

- `PotentializedUnionFind(size_t n, const T & id_elem, const F & f, const F & g = [];(const_refrence x) { return -x; })`
	- $\Theta(n)$ $n$ 変数で初期化
- `:warning: size_t size(size_t x)`
	- ならし $\Theta(\alpha(N))$ 変数 $x$ と同じグループに含まれる変数の個数を返す
- `size_t find(size_t x)`
	- ならし $\Theta(\alpha(N))$ 変数 $x$ が属するグループの代表の変数を返す
- `void merge(size_t x, size_t y, const T & w)`
	- ならし $\Theta(\alpha(N))$ 変数 $x, y$ それぞれが属するグループを併合し、差分制約 $x + w = y$ を追加
- `T diff(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ これまでに追加された差分制約を満たすような変数 $x, y$ の値に対して $y - x$ を返す
- `bool issame(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 変数 $x, y$ が同じグループに属しているか判定

<br>

# コンストラクタ

### PotentializedUnionFind(size_t n, const T & id_elem, const F & f, const F & g = &#91;&#93;(const_refrence x) { return -x; })

$n$ 変数で初期化します。
はじめ、すべての変数は自身のみからなるグループに属しています。  

**制約**

- `f` の単位元は `id_elem`
- `g` は逆元を返す
- $(T, f,$ `id_elem`, `g`$)$ はアーベル群

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、変数の個数を $N$ とします。
また、アッカーマン関数の逆関数を $\alpha(N)$ と表します。  

---

### :warning: size_t size(size_t x)

変数 $x$ と同じグループに含まれる変数の個数を返します。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### size_t find(size_t x)

変数 $x$ が属するグループの代表の変数を返します。
`unite` を行うことにより代表の変数が変化する場合があります。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### void merge(size_t x, size_t y, const T & w)

変数 $x, y$ それぞれが属するグループを併合し、差分制約 $x + w = y$ を追加します。  

**制約**

- $0 \leq x, y < N$
- $x, y$ は同じグループに属さない

**計算量**

- ならし $\Theta(\alpha(N))$

---

### T diff(size_t x, size_t y)

これまでに追加された差分制約を満たすような変数 $x, y$ の値に対して $y - x$ を返します。  

**制約**

- $0 \leq x, y < N$
- $x, y$ は同じグループに属する

**計算量**

- ならし $\Theta(\alpha(N))$

---

### bool issame(size_t x, size_t y)

変数 $x, y$ が同じグループに属しているか判定します。
同じグループに属しているなら $true$ 、違うグループに属しているなら $false$ を返します。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PotentializedUnionFind.hpp"
using namespace std;

int main() {
	PotentializedUnionFind<int> puf(3, 0, [](auto x, auto y) { return x + y; });
	puf.merge(1, 0, 5); // x0 - x1 = 5
	cout << "diff(1, 0) = " << puf.diff(1, 0) << endl; // 5
	puf.merge(1, 2, 7); // x2 - x1 = 7
	cout << "diff(2, 1) = " << puf.diff(2, 1) << endl; // -7
	
	// => x0 - x2 = -2
	cout << "diff(2, 0) = " << puf.diff(2, 0) << endl;
	// => x0 - x2 = 2
	cout << "diff(0, 2) = " << puf.diff(0, 2) << endl;
	
	
	PotentializedUnionFind<int> pufxor(5, 0, [](auto x, auto y) { return x ^ y; }, [](auto x) { return x; });
	pufxor.merge(1, 0, 1); // x1 ^ x0 = 1
	pufxor.merge(1, 2, 2); // x2 ^ x1 = 2
	
	// => x2 ^ x0 = 3
	cout << "diff(2, 0) = " << pufxor.diff(2, 0) << endl;
	// => x0 ^ x2 = 3
	cout << "diff(0, 2) = " << pufxor.diff(2, 0) << endl;
	
	for (int i = 0; i < 5; ++i) cout << pufxor.size(i) << " \n"[i + 1 == 5]; // 3 3 3 1 1
	cout << "issame(0, 1) = " << boolalpha << pufxor.issame(0, 1) << endl; // true
	cout << "issame(2, 3) = " << boolalpha << pufxor.issame(2, 3) << endl; // false
	cout << "find(2) = " << pufxor.find(2) << endl; // 0 or 1 or 2
	cout << "find(4) = " << pufxor.find(4) << endl; // 4
}
```

<br>

# TODO

TODO: `size` の test を追加する  

# 参考

2021/03/09: [http://sigma425.hatenablog.com/entry/2015/12/07/185047](http://sigma425.hatenablog.com/entry/2015/12/07/185047)  
2021/03/09: [https://qiita.com/drken/items/cce6fc5c579051e64fab](https://qiita.com/drken/items/cce6fc5c579051e64fab)  

<br>