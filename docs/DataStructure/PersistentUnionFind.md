---
title: 完全永続 Union Find
documentation_of: //DataStructure/PersistentUnionFind.hpp
---

# 概要

完全永続になった [Union Find](https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp)です。  
過去の任意の状態に対する操作や参照が行えます。  

このページでは、完全永続配列 ( $N$ 要素 $M$ 分木) の計算量を次のように仮定しています。
- アクセス 時間 $\mathcal{O}(M \log_M{N})$ 空間 $\Theta(1)$
- 更新 時間/空間 $\mathcal{O}(M \log_M{N})$

<br>

- `PersistentUnionFind()`
	- $\Theta(1)$ 初期化
- `size_t size(size_t x)`
	- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$ 要素 $x$ が属する集合の要素数を返す
- `size_t find(size_t x)
	- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$ 要素 $x$ が属する集合の代表元を返します。
- `PersistentUnionFind unite(size_t x, size_t y)`
	- 時間 $\mathcal{O}(\frac{(log{N})^2}{\log{M}} + M \frac{log{N}}{\log{M}})$ 空間 $\mathcal{O}(M \frac{\log{N}}{\log{M}})$ 要素 $x$ が属する集合と要素 $y$ が属する集合を併合
- `void destructive_unite(size_t x, size_t y)`
	- 時間 $\mathcal{O}(\frac{(log{N})^2}{\log{M}} + M \frac{log{N}}{\log{M}})$ 空間 $\mathcal{O}(M \frac{\log{N}}{\log{M}})$ 要素 $x$ が属する集合と要素 $y$ が属する集合を破壊的に併合
- `bool issame(size_t x, size_t y)`
	- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$ 要素 $x, y$ が同じ集合に属しているか判定


<br>

# コンストラクタ

内部を $M$ 分木で管理します。  

**制約**

- $PARRAY$ は `PersistentArray`
- $M > 1$

---

### PersistentUnionFind()

初期化します。
はじめ、すべての要素は自身のみからなる集合に属しています。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

以下、アクセスする要素の最大値を $N-1$ とします。  

---

### :warning: size_t size(size_t x)

要素 $x$ が属する集合の要素数を返します。  

**制約**

- $0 \leq x$

**計算量**

- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$

---

### size_t find(size_t x)

要素 $x$ が属する集合の代表元を返します。
`unite` を行うことにより代表元が変化する場合があります。  

**制約**

- $0 \leq x$

**計算量**

- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$

---

### PersistentUnionFind unite(size_t x, size_t y)

要素 $x$ が属する集合と要素 $y$ が属する集合を併合した Union Find を返します。
要素 $x, y$ が同じ集合に属していた場合は自身を返します。  

**制約**

- $0 \leq x, y$

**計算量**

- 時間 $\mathcal{O}(\frac{(\log{N})^2}{\log{M}} + M \frac{\log{N}}{\log{M}})$
- 空間 $\mathcal{O}(M \frac{\log{N}}{\log{M}})$

---

### void destructive_unite(size_t x, size_t y)

要素 $x$ が属する集合と要素 $y$ が属する集合を破壊的に併合します。
要素 $x, y$ が同じ集合に属していた場合は何も行いません。  
この関数を呼んだ後で同一の履歴ツリーに含まれる別の状態にアクセスしたときの動作は未定義です。  

**制約**

- $0 \leq x, y$

**計算量**

- 時間 $\mathcal{O}(\frac{(\log{N})^2}{\log{M}} + M \frac{\log{N}}{\log{M}})$
- 空間 $\mathcal{O}(M \frac{\log{N}}{\log{M}})$

---

### bool issame(size_t x, size_t y)

要素 $x, y$ が同じ集合に属しているか判定します。
同じ集合に属しているなら $true$ 、違う集合に属しているなら $false$ を返します。  

**制約**

- $0 \leq x, y$

**計算量**

- $\mathcal{O}(\frac{(\log{N})^2}{\log{M}})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <DataStructure/PersistentArray.hpp>
#include <DataStructure/PersistentUnionFind.hpp>
using namespace std;

int main() {
	using PUF = PersistentUnionFind<PersistentArray, 6>;
	
	PUF uf1;
	cout << uf1.find(6) << ", " << uf1.size(6) << endl; // 6, 1
	PUF uf2 = uf1.unite(6, 7);
	cout << uf2.find(6) << ", " << uf2.find(7) << endl; // same (6 or 7)
	cout << uf1.size(6) << ", " << uf2.size(6) << endl; // 1, 2
	
	PUF uf3 = uf2.unite(0, 6);
	cout << uf3.size(0) << endl; // 3
	
	PUF uf4 = uf2.unite(8, 9);
	cout << uf1.size(6) << ", " << uf2.size(6) << ", " << uf4.size(6) << endl; // 1, 2, 2
	uf4.destructive_unite(6, 9);
	// undefined, undefined, 4
	cout << uf1.size(6) << ", " << uf2.size(6) << ", " << uf4.size(6) << endl;
}
```

<br>

# 解説

経路圧縮は行わずにマージテク (データ構造をマージする一般的なテク) のみ用いています。  
マージテクにより 1 クエリあたり高々 $O(log N)$ 個の要素しか関係しません。  
実装では、負の数をときは集合の個数を、非負の数のときは親の要素として管理しています。  

<br>

# 参考

2020/09/25: https://qiita.com/hotman78/items/9c643feae1de087e6fc5

<br>