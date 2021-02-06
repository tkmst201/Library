---
title: 素集合データ構造 (Union-Find)
documentation_of: //DataStructure/UnionFind.hpp
---

# 概要

素集合の族を扱うデータ構造です。  
扱う要素数を $N$ とすると、2 つの集合の併合や集合に含まれる要素数の取得、ある要素が含まれる集合の取得を、ならし $\Theta(\alpha(N))$ で行うことができます。
ここで $\alpha(N)$ はアッカーマン関数の逆関数を表します。  

- `UnionFind(size_t n)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `size_t size(size_t x)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合の要素数を返す。
- `size_t find(size_t x)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合の代表元を返す
- `void unite(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合と要素 $y$ が属する集合を併合
- `bool issame(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 要素 $x, y$ が同じ集合に属しているか判定

<br>

# コンストラクタ

### UnionFind(size_t n)

要素数 $n$ で初期化します。
はじめ、すべての要素は自身のみからなる集合に属しています。  

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、要素数を $N$ とします。
また、アッカーマン関数の逆関数を $\alpha(N)$ と表します。  

---

### :warning: size_t size(size_t x)

要素 $x$ が属する集合の要素数を返します。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

**Verified**

- 2020/04/22 [https://atcoder.jp/contests/abc157/submissions/12223429](https://atcoder.jp/contests/abc157/submissions/12223429)

---

### size_t find(size_t x)

要素 $x$ が属する集合の代表元を返します。
`unite` を行うことにより代表元が変化する場合があります。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### void unite(size_t x, size_t y)

要素 $x$ が属する集合と要素 $y$ が属する集合を併合します。
要素 $x, y$ が同じ集合に属していた場合は何も行いません。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### bool issame(size_t x, size_t y)

要素 $x, y$ が同じ集合に属しているか判定します。
同じ集合に属しているなら $true$ 、違う集合に属しているなら $false$ を返します。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <DataStructure/UnionFind.hpp>
using namespace std;

int main() {
	constexpr int N = 5;
	UnionFind uf(N);
	
	cout << "representative: " << uf.find(0) << ", " << uf.find(1) << endl; // 0, 1
	cout << "size: " << uf.size(0) << ", " << uf.size(1) << endl; // 1, 1
	cout << boolalpha << "issame(0, 1): " << uf.issame(0, 1) << endl; // false
	uf.unite(0, 1);
	cout << "representative: " << uf.find(0) << ", " << uf.find(1) << endl; // 0 0 (or 1 1)
	cout << "size: " << uf.size(0) << ", " << uf.size(1) << endl; // 2, 2
	cout << boolalpha << "issame(0, 1): " << uf.issame(0, 1) << endl; // true
	
	uf.unite(2, 3);
	uf.unite(2, 4);
	cout << "size(0): " << uf.size(0) << endl; // 2
	cout << "size(2): " << uf.size(2) << endl; // 3
	uf.unite(1, 3);
	cout << "size(0) = size(4): " << uf.size(0) << ", " << uf.size(4) << endl; // 5, 5
}
```

<br>

# TODO

TODO: `size` の test を追加する  

# 参考
2020/04/22: [https://en.wikipedia.org/wiki/Disjoint-set_data_structure](https://qiita.com/kopricky/items/3e5847ab1451fe990367)  
2020/04/22: [https://qiita.com/kopricky/items/3e5847ab1451fe990367](https://qiita.com/kopricky/items/3e5847ab1451fe990367)  

<br>