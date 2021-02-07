---
title: ModInt 構造体
documentation_of: //Mathematics/ModInt.hpp
---

# 概要

自動で mod を取ってくれる構造体です。
基本的な四則演算や `std::cin`、`std::cout` に対応しています。  
`int` が渡せるほとんどのライブラリで用いることができます。  

- `ModInt(long long val = 0)`
	- $\Theta(1)$ $val$ で初期化
- `static int mod()`
	- $\Theta(1)$ $M$ を返す
- `int val()`
	- $\Theta(1)$ $x \bmod{M}$ を返す
- `ModInt pow(long long n)`
	- $\Theta(\log{n})\ (n \geq 0),\ \Theta(\log{n} + \log{M})\ (n < 0)$ $x^n \bmod{M}$ を返す
- `ModInt inv()`
	- $\Theta(\log{M})$ $x^{-1} \bmod{M}$ を返す

<br>

# コンストラクタ

mod に取りたい値を $M$ に渡します。  

**制約**

- $M > 0$

---

### ModInt(long long val = 0)

$val \bmod{M}$ で初期化します。
何も指定しない場合の初期値は $0$ です。  

**計算量**

- $\Theta(1)$

---

<br>

# 演算

以下の演算が使用可能です。  


```
+ModInt
-ModInt

ModInt++
ModInt--

++ModInt
--ModInt

ModInt += ModInt
ModInt -= ModInt
ModInt *= ModInt
ModInt /= ModInt

ModInt + ModInt
ModInt - ModInt
ModInt * ModInt
ModInt / ModInt

bool(ModInt)
!ModInt
ModInt == ModInt
ModInt != ModInt

std::cin >> ModInt
std::cout << ModInt
```

`bool(ModInt)` は法 $M$ で $0$ なら $true$ を、$0$ 以外なら $false$ を返します。
`!ModInt` は `bool(ModInt)` を論理否定した値を返します  
`ModInt == ModInt` は 2 つの `ModInt` の値が法 $M$ の元で合同ならば $true$ を、違えば $false$ を返します。
`ModInt != ModInt` はその逆の論理値になります。  

また、`int + ModInt` や `ModInt + int` などの他の型との演算は、それぞれ `ModInt(int) + ModInt` 、 `ModInt + ModInt(int)` として計算します。  


**制約**

- `ModInt /= ModInt` または `ModInt /= ModInt` のとき、右辺の値と $M$ は互いに素

**計算量**

- $\Theta(\log{M})$ ( `ModInt /= ModInt` または `ModInt /= ModInt` )
- $\Theta(1)$ (それ以外)


<br>


# メンバ関数

以下、保持している値を $x$ とします。  

---

### static int mod()

$M$ を返します。  

**計算量**

- $\Theta(1)$

---

### int val()

$x \bmod{M}$ を返します。  

**計算量**

- $\Theta(1)$

---

### ModInt pow(long long n)

$x^n \bmod{M}$ を返します。  

**制約**

- $n < 0$ のとき、$x$ と $M$ は互いに素

**計算量**

- $\Theta(\log{n})\ (n \geq 0)$
- $\Theta(\log{n} + \log{M})\ (n < 0)$

---

### ModInt inv()

$x^{-1} \bmod{M}$ を返します。  

**制約**

- $x$ と $M$ は互いに素

**計算量**

- $\Theta(\log{M})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <Mathematics/ModInt.hpp>
using namespace std;

constexpr int MOD = 13;
using mint = ModInt<MOD>;

int main() {
	cout << "M = " << mint::mod() << endl; // 13
	cout << "0: " << mint(0) << endl; // 0
	cout << "15: " << mint(15) << endl; // 2
	cout << "-1: " << mint(-1) << endl; // 12
	cout << "-1: " << mint(-1).val() << endl; // 12
	
	mint a(10);
	cout << a << endl; // 10
	cout << a + 3 << endl; // 0
	a += 5;
	cout << a << endl; // 2
	a *= 3;
	cout << a << endl; // 6
	a /= 2;
	cout << a << endl; // 3
	a /= 5;
	cout << a << endl; // 11 (5 * 11 = 55 = 3 + 4 * 13)
	a = 5 - a;
	cout << a << endl; // 7
	cout << -a << endl; // 6
	
	a = 10;
	mint b(3);
	cout << a * b << endl; // 4
	
	a = 1;
	b = ++a;
	cout << a << ", " << b << endl; // 2, 2
	a = 1;
	b = a++;
	cout << a << ", " << b << endl; // 2, 1
}
```

<br>

# 参考
[https://noshi91.hatenablog.com/entry/2019/03/31/174006](https://noshi91.hatenablog.com/entry/2019/03/31/174006)

<br>