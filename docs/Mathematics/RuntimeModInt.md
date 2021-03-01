---
title: 実行時 mod 指定 ModInt 構造体
documentation_of: //Mathematics/RuntimeModInt.hpp
---

# 概要

実行時に法 $M$ を指定する [ModInt 構造体](https://tkmst201.github.io/Library/DataStructure/LazySegmentTree.hpp) です。  
`ModInt` が渡せるほとんどのライブラリで用いることができます。  

- `RuntimeModInt(long long val = 0)`
	- $\Theta(1)$ $val$ で初期化
- `static void set_mod(int M)`
	- $\Theta(1)$ 法 $M$ を設定
- `static int mod()`
	- $\Theta(1)$ $M$ を返す
- `int val()`
	- $\Theta(1)$ $x \bmod{M}$ を返す
- `RuntimeModInt pow(long long n)`
	- $\Theta(\log{n})\ (n \geq 0),\ \Theta(\log{n} + \log{M})\ (n < 0)$ $x^n \bmod{M}$ を返す
- `RuntimeModInt inv()`
	- $\Theta(\log{M})$ $x^{-1} \bmod{M}$ を返す

<br>

# コンストラクタ

$ID$ に渡す値によって mod を区別することができます。
詳しくは使用例を参照してください。  

---

### RuntimeModInt(long long val = 0)

$val \bmod{M}$ で初期化します。
何も指定しない場合の初期値は $0$ です。  

**計算量**

- $\Theta(1)$

---

<br>

# 演算

以下の演算が使用可能です。  


```
+RuntimeModInt
-RuntimeModInt

RuntimeModInt++
RuntimeModInt--

++RuntimeModInt
--RuntimeModInt

RuntimeModInt += RuntimeModInt
RuntimeModInt -= RuntimeModInt
RuntimeModInt *= RuntimeModInt
RuntimeModInt /= RuntimeModInt

RuntimeModInt + RuntimeModInt
RuntimeModInt - RuntimeModInt
RuntimeModInt * RuntimeModInt
RuntimeModInt / RuntimeModInt

bool(RuntimeModInt)
!RuntimeModInt
RuntimeModInt == RuntimeModInt
RuntimeModInt != RuntimeModInt

std::cin >> RuntimeModInt
std::cout << RuntimeModInt
```

`bool(RuntimeModInt)` は法 $M$ で $0$ なら $true$ を、$0$ 以外なら $false$ を返します。
`!RuntimeModInt` は `bool(RuntimeModInt)` を論理否定した値を返します  
`RuntimeModInt == RuntimeModInt` は 2 つの `RuntimeModInt` の値が法 $M$ の元で合同ならば $true$ を、違えば $false$ を返します。
`RuntimeModInt != RuntimeModInt` はその逆の論理値になります。  

また、`int + RuntimeModInt` や `RuntimeModInt + int` などの他の型との演算は、それぞれ `RuntimeModInt(int) + RuntimeModInt` 、 `RuntimeModInt + RuntimeModInt(int)` として計算します。  


**制約**

- `RuntimeModInt /= RuntimeModInt` または `RuntimeModInt /= RuntimeModInt` のとき、右辺の値と $M$ は互いに素

**計算量**

- $\Theta(\log{M})$ ( `RuntimeModInt /= RuntimeModInt` または `RuntimeModInt /= RuntimeModInt` )
- $\Theta(1)$ (それ以外)


<br>


# メンバ関数

以下、保持している値を $x$ とします。  

---

### static void set_mod(int M)

法 $M$ を設定します。  

**制約**

- $0 < M$

**計算量**

- $\Theta(1)$

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

### RuntimeModInt pow(long long n)

$x^n \bmod{M}$ を返します。  

**制約**

- $n < 0$ のとき、$x$ と $M$ は互いに素

**計算量**

- $\Theta(\log{n})\ (n \geq 0)$
- $\Theta(\log{n} + \log{M})\ (n < 0)$

---

### RuntimeModInt inv()

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
#include <Mathematics/RuntimeModInt.hpp>
using namespace std;

using mint1 = RuntimeModInt<0>;
using mint2 = RuntimeModInt<1>;

int main() {
	mint1::set_mod(7);
	mint2::set_mod(13);
	
	cout << "M1 = " << mint1::mod() << ", M2 = " << mint2::mod() << endl; // 7, 13
	cout << mint1(100) << ", " << mint2(100) << endl; // 2, 9
	
	cout << "0: " << mint2(0) << endl; // 0
	cout << "15: " << mint2(15) << endl; // 2
	cout << "-1: " << mint2(-1) << endl; // 12
	cout << "-1: " << mint2(-1).val() << endl; // 12
	
	mint2 a(10);
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
	mint2 b(3);
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

# TODO

TODO: test の追加  

# 参考

[https://noshi91.hatenablog.com/entry/2019/03/31/174006](https://noshi91.hatenablog.com/entry/2019/03/31/174006)

<br>