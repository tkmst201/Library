---
title: 完全永続 Stack
documentation_of: //DataStructure/PersistentStack.hpp
---

# 概要

完全永続 Stack です。  
過去の任意の状態の参照や更新が $\Theta(1)$ で行えます。  

- `PersistentStack()`
	- $\Theta(1)$ 空の Stack を作成
- `bool empty()`
	- $\Theta(1)$ Stack が空であるか判定
- `PersistentStack push(const T & x)`
	- $\Theta(1)$ データ $x$ を push する
- `PersistentStack pop()`
	- $\Theta(1)$ データを pop する
- `const T & top()`
	- $\Theta(1)$ 一番最後に push したデータを返す

<br>

# コンストラクタ

### PersistentStack()

空の Stack を作成します。
$T$ には保持したい値の型を指定します。  

**計算量**

- $\Theta(1)$

---

<br>

# メンバ関数

### bool empty()

Stack が空なら $true$ を返します。
それ以外は $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

Stack に入っている要素数を返します。  

**計算量**

- $\Theta(1)$

---

### PersistentStack push(const T & x)

データ $x$ を push した Stack を返します。  

**計算量**

- $\Theta(1)$

---

### PersistentStack pop()

一番最後に push したデータを取り除いた Stack を返します。  

**制約**

- Stack は空ではない

**計算量**

- $\Theta(1)$

---

### const T & top()

一番最後に push したデータを返します。  

**制約**

- Stack は空ではない

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <DataStructure/PersistentStack.hpp>
using namespace std;

int main() {
	using ps = PersistentStack<int>;
	
	ps stk1;
	cout << stk1.size() << endl; // 0
	ps stk2 = stk1.push(1);
	ps stk3 = stk2.push(2);
	cout << stk2.size() << ", " << stk2.top() << endl; // 1, 1
	cout << stk3.size() << ", " << stk3.top() << endl; // 2, 2
	
	cout << stk3.pop().top() << endl; // 1
	
	ps stk4 = stk2.push(3);
	cout << stk2.top() << ", " << stk3.top() << ", " << stk4.top() << endl; // 1, 2, 3
	cout << stk4.size() << endl; // 2
	
	ps stk5 = stk2.pop();
	ps stk6 = stk5.push(4);
	
	cout << stk6.top() << endl; // 4
	cout << stk6.pop().size() << endl; // 0
}
```

<br>

# 参考
2020/04/10: http://noshi91.hatenablog.com/entry/2019/02/04/175100

<br>