---
title: 完全永続配列
documentation_of: //DataStructure/PersistentArray.hpp
---

# 概要

完全永続配列です。  
内部を $M$ 分木、アクセスする添字を $k$ とすると、過去の任意の状態の参照を $\mathcal{O}(\log_M{k})$ 、更新を $\mathcal{O}(M \log_M{k})$ で行えます。  

- `PersistentArray(const T & def_val = 0)`
	- $\Theta(1)$ 要素数無限の Array を作成
- `PersistentArray set(size_t k, const T & x)`
	- $時間/空間 \mathcal{O}(M \log_M{k})$ $A_k$ に $x$ を代入
- `void destructive_set(size_t k, const T & x)`
	- $時間/空間 \mathcal{O}(M \log_M{k})$ $A_k$ に $x$ を破壊的に代入
- `const T & get(size_t k)`
	- $\mathcal{O}(\log_M{k})$ $A_k$ を返す

<br>

# コンストラクタ

保持したい値の型を $T$ とし、内部を $M$ 分木で管理します。  

**制約**

- $M > 1$

---

### PersistentArray(const T & def_val = 0)

要素数無限の Array を作成します。
初期値は `def_val` です。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

以下、配列 $A_0, A_1, \ldots$ を対象とします。

---

### PersistentArray set(size_t k, const T & x)

$A_k$ に $x$ を代入した Array を返します。  

**制約**

- $0 \leq k$

**時間/空間計算量**

- $\mathcal{O}(M \log_M{k})$

---

### void destructive_set(size_t k, const T & x)

$A_k$ に $x$ を破壊的に代入します。
`set` よりも高速に動作します。  
この関数を呼んだ後で同一の履歴ツリーに含まれる別の状態にアクセスしたときの動作は未定義です。  

**制約**

- $0 \leq k$

**時間/空間計算量**

- $\mathcal{O}(M \log_M{k})$

---

### const T & get(size_t k)

$A_k$ を返す。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log_M{k})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PersistentArray.hpp"
using namespace std;

int main() {
	using pa = PersistentArray<int, 3>;
	
	pa ary1;
	cout << ary1.get(10) << endl; // 0
	
	pa ary2 = ary1.set(1, 5);
	pa ary3 = ary1.set(1, 6);
	cout << ary1.get(1) << ", " << ary2.get(1) << ", " << ary3.get(1) << endl; // 0, 5, 6
	
	pa ary4 = ary3.set(3, 7);
	cout << ary1.get(3) << ", " << ary3.get(3) << ", " << ary4.get(3) << endl; // 0, 0, 7
	
	cout << ary1.get(1) << ", " << ary3.get(1) << ", " << ary4.get(1) << endl; // 0, 6, 6
	ary4.destructive_set(1, -100);
	// undefined, undefined, -100
	cout << ary1.get(1) << ", " << ary3.get(1) << ", " << ary4.get(1) << endl;
}
```

<br>

# 解説

添字の大きさ順にノードを並べる必要はないので、添字を m 進表記したときの下の桁から見ていき要素を並べるようにしています。  
これにより要素数を事前に指定する必要が無くなっています。

<br>

# 参考

2020/04/10: [https://trap.jp/post/663/](https://trap.jp/post/663/)  
2020/09/25: [https://qiita.com/hotman78/items/9c643feae1de087e6fc5](https://qiita.com/hotman78/items/9c643feae1de087e6fc5)  

<br>