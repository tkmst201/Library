---
title: ユークリッドの互除法
documentation_of: //Mathematics/euclid.hpp
---

# 概要

最大公約数、最小公倍数、拡張ユークリッドの互除法のセットです。  

<br>

# 関数

### T gcd(T a, T b)

整数 $a, b$ の最大公約数を返します。
どちらか一方が $0$ の場合はもう一方の値を返します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- $0 \leq a, b$

**計算量**

- $\mathcal{O}(\log{\min(a, b)})$

---

### T lcm(T a, T b)

整数 $a, b$ の最小公倍数を返します。
どちらか一方が $0$ の場合は $0$ を返します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- 最小公倍数が `T` で表現可能( 積 $ab$ が `T` で表現可能なら問題無し)
- $0 \leq a, b$

**計算量**

- $\mathcal{O}(\log{\min(a, b)})$

---

### tuple&lt;T, T, T&gt; ext_gcd(T a, T b)

整数 $a, b$ の最大公約数を $g$ として、一次不定方程式 $ax + by = g$ の特殊解の一つを返します。
得られる特殊解 $x = x_0, y = y_0$ は $\|x_0\| \leq b / g, \|y_0\| \leq a / g$ を満たします(ページ下部 `解説` 欄参照)。  
また、一般解は整数 $n$ を用いて $x = x_0 + \frac{b}{g} n, y = y_0 - \frac{a}{g} n$ と表されます。

**制約**

- `T` は `int`, `long long`
- $a, b \neq 0$

**計算量**

- $\mathcal{O}(\log{\min(a, b)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/euclid.hpp"
using namespace std;

int main() {
	cout << "gcd(4, 6) = " << tk::gcd(4, 6) << endl; // 2
	cout << "gcd(3, 9) = " << tk::gcd(3, 9) << endl; // 3
	cout << "gcd(100, 0) = " << tk::gcd(100, 0) << endl; // 100
	
	cout << "lcm(4, 6) = " << tk::lcm(4, 6) << endl; // 12
	cout << "lcm(3, 9) = " << tk::lcm(3, 9) << endl; // 9
	cout << "lcm(100, 0) = " << tk::lcm(100, 0) << endl; // 0
	cout << "lcm(1000000000, 3) = " << tk::lcm<long long>(1000000000, 3) << endl; // 3000000000
	
	auto ext_out = [](int a, int b) {
		auto [g, x0, y0] = tk::ext_gcd(a, b);
		cout << "ext_gcd(" << a << ", " << b << ") : g = " << g << ", x0 = " << x0 << ", y0 = " << y0 << endl;
		cout << "ax0 + by0 = " << a * x0 + b * y0 << endl; // g
	};
	/*
		ext_gcd(12, 10) : g = 2, x0 = 1, y0 = -1
		ax0 + by0 = 2
	*/
	ext_out(12, 10);
	/*
		ext_gcd(6, 25) : g = 1, x0 = -4, y0 = 1
		ax0 + by0 = 1
	*/
	ext_out(6, 25);
	/*
		ext_gcd(-28, 102) : g = 2, x0 = -11, y0 = -3
		ax0 + by0 = 2
	*/
	ext_out(-28, 102);
}
```

<br>

# 解説

### ext_gcd

整数 $a, b$ の最大公約数を $g$ として、`ext_gcd(T a, T b)` で得られる特殊解 $a x_0 + b y_0 = g$ が $\|x_0\| \leq b / g, \|y_0\| \leq a / g$ を満たすことを示します。  

そのために、ループの中で不変条件 $a \|b_1\| + b \|a_1\| \leq b \cdots$ (*) が常に満たされることを確かめます。  
ループの最初は、$a \times 0 + b \times \|1 or -1\| = b \leq b$ で (*) は成り立っています。  
$1$ 回ループ内の処理をした後では、$a, b, a_1, b_1$ はそれぞれ $q := a / b$ として $b, a - qy, b_1, a_1 - q b_1$ となるので、(*) の左辺に代入すると、

$$b\|a_1 - qb_1\| + (a - qb)\|b_1\| \leq b(\|a_1\| + q\|b_1\|) + (a - qb)\|b_1\| = b\|a_1\| + a\|b_1\| \leq b$$

で、$(*)$ は成り立つことが分かります。  

最終的に $a = g, b = 0$ でループは止まりますが、その最後のループの前では不変条件は $qg\|b_1\| + g\|a_1\| \leq b$ となっています。
これから、$\|x_0\| = \|a_1\| \leq b/g - q\|b_1\| \leq b/g$ が導かれます。  

$a, b, a_1, b_1$ を対象に同様の考察を行うことにより $\|y_0\| = \|a_2\| \leq a/g$ も導かれます。  

<br>

# 参考

2020/01/14: [https://noshi91.hatenablog.com/entry/2019/04/01/184957](https://noshi91.hatenablog.com/entry/2019/04/01/184957)  

<br>