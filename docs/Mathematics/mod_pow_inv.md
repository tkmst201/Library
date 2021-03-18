---
title: $\mod{m}$ での冪と逆元
documentation_of: //Mathematics/mod_pow_inv.hpp
---

# 概要

整数 $a, x, m$ に対して $a^x \pmod{m}$ や $a^{-1} \pmod{m}$ を求めます。  

<br>

# 関数

### T mod_pow(T x, T n, T m)

整数 $x, n, m$ に対して $x^n \pmod{m}$ を返します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- $m^2$ が `T` で表現可能
- $0 \leq n$
- $0 < m$

**計算量**

- $\Theta(\log{n})$

---

### T mod_inv(T x, T m)

整数 $x, m$ に対して $x^{-1} \pmod{m}$ を返します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- $0 < m$
- $x$ と $m$ は互いに素

**計算量**

- $\mathcal{O}(\log{\min(x, m)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/mod_pow_inv.hpp"
using namespace std;

int main() {
	cout << "mod_pow(2, 3, 3) = " << tk::mod_pow(2, 3, 3) << endl; // 2 (2^3 = 8)
	cout << "mod_pow(5, 0, 10) = " << tk::mod_pow(2, 3, 3) << endl; // 1 (5^0 = 1)
	cout << "mod_pow(10, 2, 10000) = " << tk::mod_pow(10, 2, 10000) << endl; // 100 (10^2 = 100)
	
	cout << "mod_inv(10, 7) = " << tk::mod_inv(10, 7) << endl; // -2 (10*(-2) = -20 = 7*(-3) + 1)
	cout << "mod_inv(4, 3) = " << tk::mod_inv(4, 3) << endl; // 1 (4*1 = 3*1 + 1)
	cout << "mod_inv(-5, 8) = " << tk::mod_inv(-5, 8) << endl; // 3 (-5*3 = 8*(-2) + 1)
}
```

<br>

# 参考

2020/01/14: [https://noshi91.hatenablog.com/entry/2019/04/01/184957](https://noshi91.hatenablog.com/entry/2019/04/01/184957)  

<br>