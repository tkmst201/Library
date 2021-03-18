---
title: 2-SAT
documentation_of: //Mathematics/TwoSat.hpp
---

# 概要

論理変数 $x_0, \ldots, x_{N-1}$ に対して $(x_0 \lor x_1) \land (\lnot x_0 \lor x_2) \land (x_3 \lor x_0) \land (x_5) \land (x_2 \lor x_{N-1})$ のような形式の論理式を満たす真偽の組み合わせを求めます。  
より具体的には、クロージャ(括弧) の積で表されていて各クロージャ内は 2 つ以下のリテラルの和で表されているような論理式を解きます。  

- `TwoSat(int n)`
	- $\Theta(n)$ $n$ 個の論理変数で初期化
- `int size()`
	- $\Theta(1)$ 論理変数の個数 $N$ を返す
- `void add_clause(int x, bool xb, int y, bool yb)`
	- ならし $\Theta(1)$ クロージャ $x = xb \lor y = yb$ を追加
- `void add_clause(int x, bool xb)`
	- ならし $\Theta(1)$ クロージャ $x = xb$ を追加
- `bool build()`
	- $\Theta(N)$ 論理式を満たすような論理値の割り当てを求める
- `const vector<bool> & ans_list`
	- $\Theta(1)$ 論理式を満たすような論理値の割り当てを返す
- `bool get(int i)`
	- $\Theta(1)$ 論理式を満たすような論理値の割り当てで $x_i$ の真偽値を返す

<br>

# コンストラクタ

### TwoSat(int n)

$n$ 個の論理変数で初期化します。  

**制約**

- $0 \leq n$

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、論理変数の個数を $N$ とし、それぞれ $x_0, \ldots, x_{N-1}$ とします。  

---

### int size()

論理変数の個数 $N$ を返します。

**計算量**

- $\Theta(1)$

---

### void add_clause(int x, bool xb, int y, bool yb)

クロージャ $x = xb \lor y = yb$ を追加します。  

**制約**

- $0 \leq x, y < N$
- $xb, yb$ はそれぞれ $true, false$ のいずれか

**計算量**

- ならし $\Theta(1)$

---

### void add_clause(int x, bool xb)

クロージャ $x = xb$ を追加します。  

**制約**

- $0 \leq x < N$
- $xb$ は $true, false$ のいずれか

**計算量**

- ならし $\Theta(1)$

---

### bool build()

論理式を満たすような論理値の割り当てを求めます。
割り当てることができた場合は $true$ を、割り当てが存在しない場合は $false$ を返します。  

**計算量**

- $\Theta(N)$

### const vector<bool> & ans_list

論理式を満たすような論理値の割り当てを返します。  
$[i] := x_i$ の論理値

**制約**

- 論理式を満たすような論理値の割り当てが存在する

**計算量**

- $\Theta(1)$

### bool get(int i)

論理式を満たすような論理値の割り当てで $x_i$ の真偽値を返します。  

**制約**

- 論理式を満たすような論理値の割り当てが存在する
- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/TwoSat.hpp"
using namespace std;

int main() {
	TwoSat sat(5);
	cout << "sat.size() = " << sat.size() << endl; // 5
	sat.add_clause(0, true, 1, false);
	sat.add_clause(1, false, 2, false);
	
	sat.build();
	// true true false true true
	for (bool b : sat.ans_list()) cout << boolalpha << b << " "; cout << '\n';
	for (int i = 0; i < sat.size(); ++i) cout << boolalpha << sat.get(i) << " "; cout << '\n';
	
	sat.add_clause(0, false);
	sat.add_clause(1, false);
	sat.build();
	// false false false true true
	for (bool b : sat.ans_list()) cout << boolalpha << b << " "; cout << '\n';
	
	sat.add_clause(0, true, 1, true);
	bool f = sat.build();
	cout << boolalpha << f << endl; // false
}
```

<br>

# 参考

2021/03/18: [https://noshi91.hatenablog.com/entry/2019/10/03/184812](https://noshi91.hatenablog.com/entry/2019/10/03/184812)  
2021/03/18: [https://www.slideshare.net/yoshiokatsuneo/2sat-72370606](https://www.slideshare.net/yoshiokatsuneo/2sat-72370606)  
2020/09/10: [AC Library](https://github.com/atcoder/ac-library)  

<br>