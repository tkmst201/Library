---
title: 数論変換 (NTT)
documentation_of: //Convolution/NumberTheoreticTransform.hpp
---

# 概要

特殊な整数 $M$ と $2$ つの整数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x) \bmod{M}$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  
基数 $2$ の時間間引き Cooley-Tukey 型アルゴリズムを用いています。  

<br>

# 静的メンバ関数

### std::vector&lt;T&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i \bmod{M}$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i \bmod{M}$ として、
積 $f(x)g(x) \equiv \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i \pmod{M}$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i] \bmod{M}$ 返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- $M > 0$
- 適当な整数 $p$ を用いて $M - 1 = Np$ ($N$ は $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪) と表すことが可能
- `PRIMITIVE_ROOT` は $M$ の原始根
- `T` は `int`, `unsigned int`, `long long int`, `unsigned long long`

**計算量**

- $N$ を $\|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# 使用例

代表的な `MOD` とその原始根の組み合わせの例を下に載せておきます。

```cpp
NumberTheoreticTransform<998'244'353, 3> // 2^23 | (mod - 1)
NumberTheoreticTransform<1'224'736'769, 3> // 2^24 | (mod - 1)
NumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)
NumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)
```

```cpp
#include <bits/stdc++.h>
#include "Convolution/NumberTheoreticTransform.hpp"
using namespace std;

int main() {
	vector<int> a({0, 1, 2, 3}), b({2, 3, 4});
	auto c = NumberTheoreticTransform<998244353, 3>::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 16 17 12
	// 0 0 0
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	
	vector<int> a2({4}), b2({3, 2});
	auto c2 = NumberTheoreticTransform<167772161, 3>::multiply(a2, b2);
	cout << "size = " << c2.size() << endl; // 2
	for (int i = 0; i < c2.size(); ++i) cout << c2[i] << " "; cout << endl; // 12 8
	// 12 
	//    8
	// ==============
	// 12 8
	
	vector<int> a3({-3, 1}), b3({-2, -9});
	auto c3 = NumberTheoreticTransform<5, 3>::multiply(a3, b3);
	cout << "size = " << c3.size() << endl; // 3
	for (int i = 0; i < c3.size(); ++i) cout << c3[i] << " "; cout << endl; // 1 0 1
	// 1(6) 3(-2)
	//      2(27) 1(-9)
	// ==============
	// 1    0     1
	
	vector<int> a4, b4({1, 2, 3});
	auto c4 = NumberTheoreticTransform<469'762'049, 3>::multiply(a4, b4);
	cout << "size = " << c4.size() << endl; // 0
}
```

<br>

# 参考

2020/07/27: [https://math314.hateblo.jp/entry/2015/05/07/014908](https://math314.hateblo.jp/entry/2015/05/07/014908)  
2020/07/27: [https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0](https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0)  
2020/07/27: [http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html](http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html)  

<br>