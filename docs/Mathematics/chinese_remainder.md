---
title: 中国剰余定理
documentation_of: //Mathematics/chinese_remainder.hpp
---

# 概要

中国剰余定理です。連立一次合同式を解きます。  

<br>

# 関数

### pair<T, T> chinese_remainder(T b1, T m1, T b2, T m2)

連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

の解の一つを $0 \leq x < lcm(m_1, m_2)$ の範囲で求め、$(x, lcm(m_1, m_2))$ を返します。  
解が存在しない場合は $(0, 0)$ を返します。  
また、この合同式の解は、$b_1 \equiv b_2 \pmod{gcd(m_1, m_2)}$ であるときに限り存在し、周期 $lcm(m_1, m_2)$ の中で一意です。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- $lcm(m_1, m_2)$ が `T` で表現可能
- $0 < m_1, m_2$

**計算量**

- $\mathcal{O}(\log{\min(m1, m2)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/chinese_remainder.hpp"
using namespace std;

int main() {
	auto [a, l] = tk::chinese_remainder(2, 3, 5, 12);
	cout << "chinese_remainder(2, 3, 5, 12) = (" << a << ", " << l << ")" << endl; // (5, 12)
	
	tie(a, l) = tk::chinese_remainder(3, 7, 6, 11);
	cout << "chinese_remainder(3, 7, 6, 11) = (" << a << ", " << l << ")" << endl; // (17, 77)
	
	tie(a, l) = tk::chinese_remainder(0, 10, 0, 4);
	cout << "chinese_remainder(0, 10, 0, 4) = (" << a << ", " << l << ")" << endl; // (0, 20)
	
	tie(a, l) = tk::chinese_remainder(2, 10, 1, 8);
	cout << "chinese_remainder(2, 10, 1, 8) = (" << a << ", " << l << ")" << endl; // (0, 0)
}
```

<br>

# 参考

2021/03/18: [https://qiita.com/drken/items/ae02240cd1f8edfc86fd](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)  
2020/09/21: [AC Library](https://github.com/atcoder/ac-library)  

<br>