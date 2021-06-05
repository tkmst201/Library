---
title: 任意 mod 数論変換 (任意 mod NTT)
documentation_of: //Convolution/NumberTheoreticTransform_AnyMod.hpp
---

# 概要

[数論変換 (NTT)](https://tkmst201.github.io/Library/Convolution/NumberTheoreticTransform.hpp) に [Garner](https://tkmst201.github.io/Library/Mathematics/garner.hpp) を組み合わせて、法 $M$ が任意に取れるようになったものです。ただし、積の各係数において $\bmod{M}$ を取る前の値がある値以下に収まっている必要があります。  
$2$ つの整数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x) \bmod{M}$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  

<br>

# 静的メンバ関数

### std::vector&lt;T&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i \bmod{MOD}$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i \bmod{MOD}$ として、
積 $f(x)g(x) \equiv \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i \pmod{MOD}$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i] \bmod{MOD}$ 返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- `MOD` $> 0$
- $a_i, b_j \geq 0$
- 多項式 $a, b$ の係数の最大値を $Q$ として、$\max(\|A\|, \|B\|) * Q^2 < \prod_i m_i$ となるように $m$ が選ばれている
- `T` は `int`, `long long int`

**計算量**

法 $m$ の個数を $K$ 、$N$ を $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪とします。
- $\mathcal{O}(N\log{N} + (\|a\| + \|b\|) K(K + \log{\max{m_i}}))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Convolution/NumberTheoreticTransform_AnyMod.hpp"
using namespace std;

int main() {
	vector<int> a({0, 1, 2, 3}), b({2, 3, 4});
	auto c = NumberTheoreticTransform_AnyMod<14>::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 2 3 12
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	// 0 2 7  2  3 12
	
	vector<int> a2({4}), b2({3, 2});
	auto c2 = NumberTheoreticTransform_AnyMod<7>::multiply(a2, b2);
	cout << "size = " << c2.size() << endl; // 2
	for (int i = 0; i < c2.size(); ++i) cout << c2[i] << " "; cout << endl; // 5 1
	// 12 
	//    8
	// ==============
	// 12 8
	//  5 1
	
	vector<int> a3, b3({1, 2, 3});
	auto c3 = NumberTheoreticTransform_AnyMod<100>::multiply(a3, b3);
	cout << "size = " << c3.size() << endl; // 0
}
```

<br>

# 参考

2020/07/27: [https://math314.hateblo.jp/entry/2015/05/07/014908](https://math314.hateblo.jp/entry/2015/05/07/014908)  

<br>