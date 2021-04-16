---
title: 高速フーリエ変換 (FFT)
documentation_of: //Convolution/FastFourierTransform.hpp
---

# 概要

$2$ つの実数係数多項式 $f(x), g(x)$ に対して、積 $f(x)g(x)$ を計算します。
計算量は $\Theta(N\log{N})$ (積の次数を $N$ ) です。  
基数 $4$ の時間間引き Cooley-Tukey 型アルゴリズムを用いています。  

<br>

# 静的メンバ関数

### std::vector&lt;double&gt; multiply(const std::vector&lt;T&gt; &amp; a, const std::vector&lt;T&gt; &amp; b)

$f(x) := \sum_{i=0}^{\|a\| - 1} a[i] x^i$, $g(x) := \sum_{i=0}^{\|b\| - 1} b[i] x^i$ として、
積 $f(x)g(x) = \sum_{i=0}^{\|a\| + \|b\| - 2} c[i] x^i$ となるような大きさ $\|a\| + \|b\| - 1$ の列 $c[i]$ を `double` 型で返します。  
$a, b$ いずれかが空である場合は、空の列を返します。  

**制約**

- `T` は `int`, `long long int`, `float`, `double`

**計算量**

- $N := \|a\| + \|b\| - 1$ 以上の最小の $2$ 冪 として $\Theta(N\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Convolution/FastFourierTransform.hpp"
using namespace std;

int main() {
	vector<int> a{{0, 1, 2, 3}}, b{{2, 3, 4}};
	auto c = FastFourierTransform::multiply(a, b);
	cout << "size = " << c.size() << endl; // 6
	for (int i = 0; i < c.size(); ++i) cout << c[i] << " "; cout << endl; // 0 2 7 16 17 12
	// 0 0 0
	//   2 3 4
	//     4 6 8
	//       6 9 12
	// ==============
	// 0 2 7 16 17 12
	// c は double 型であることに注意
	
	vector<int> d{};
	cout << "size = " << FastFourierTransform::multiply(a, d).size() << endl; // 0
	
	vector<double> ad({1.5, 2}), bd({2, 5.5, 4});
	auto cd = FastFourierTransform::multiply(ad, bd);
	cout << "size = " << cd.size() << endl; // 4
	for (int i = 0; i < cd.size(); ++i) cout << cd[i] << " "; cout << endl; // 3 12.25 17 8
	// 3 8.25  6
	//   4     11 8
	// ==============
	// 3 12.25 17 8
}
```

<br>

# 解説

離散フーリエ変換の基礎については既知であるとします。    

### 記法

多項式 $f(x)$ の $i$ 次の係数を $f[k]$ と書きます。
つまり、$f(x)$ の次数を $d$ とすると、 $f(x) = \sum_{i=0}^d f[x]x^i$ です。  
$\zeta_N$ は $1$ の $N$ 乗根を表します。
また、複素数 $z$ の複素共役を $\overline{z}$ 、虚数単位を $j$ と表します。  
以下 $N$ が $2$ の冪として次数 $N-1$ の多項式を扱います。  

<br>

### 離散フーリエ変換

$N-1$ 次多項式 $f(x)$ の離散フーリエ変換 $F(t)$ を $F(t) = \sum_{i=0}^{N-1} f(\zeta_N^i) t^i$ で定義します。  

$f[k] = \frac{1}{N} F(\zeta_N^{-k})$ です(逆離散フーリエ変換)。詳しく知りたい方は参考欄のサイトを参照してください。  

$F(\zeta_N^{-k}) = \sum_{i=0}^{N-1} F[i] \zeta_N^{-ki} = \overline{\sum_{i=0}^{N-1} \overline{F[i]} \zeta_N^{ki}}$ より、$F(t)$ の係数の複素共役を取った後で離散フーリエ変換を行い $N$ で割ることにより $f(x)$ が復元できます。  

<br>

### $2$ つの実数係数多項式の離散フーリエ変換を $1$ 回の離散フーリエ変換で行うテク

$2$ つの実数係数多項式 $f(x), g(x)$ のフーリエ変換 $F(t), G(t)$ を $1$ 回の離散フーリエ変換で求めることができます。  

まず、$F[N] = F[0]$ として、$F[N-t] = \overline{F[t]}$ が成り立ちます。  
これは、$f(x)$ が実数係数であることから $f[i] = \overline{f[i]}$ が成り立ち、$F[N-t] = \sum_{i=0}^{N-1} f[i] \zeta_N^{N-t} = \overline{\sum_{i=0}^{N-1} \overline{f[i] \zeta_N^{-t}}} = \overline{\sum_{i=0}^{N-1} f[i] \zeta_N^t} = F[t]$ より分かります。  

ここで、$h(x) := f(x) + j g(x)$ として多項式 $h(x)$ を定義します。$h(x)$ の離散フーリエ変換 $H(t)$ に対して $H(t) = F(t) + j G(t)$ です。  

一方、$\overline{H[N-t]} = \overline{F(N-t)} - \overline{G[N-t]} j = F[t] - j G[t]$ も成り立ちます。  

これら $2$ つの等式を連立して解くことにより次の式が得られます。  

$$F[t] = \frac{1}{2} (H[t] + \overline{H[N-t]})$$
$$G[t] = \frac{1}{2i} (H[t] - \overline{H[N-t]})$$

これより、$C[t] := F[t] G[t]$ とすると、$C[t] = \frac{1}{4i} (H[t] + \overline{H[N-t]})(H[t] - \overline{H[N-t]})$ です。  

$C[t]$ に対して逆離散フーリエ変換を行うことにより積 $c(x) = f(x) g(x)$ が計算できます。  

### 実数係数多項式の離散フーリエ変換

周波数間引きにより、$2$ つの $N/2 - 1$ 次の多項式 $c_e, c_o$ を $c_e[k] = c[2k], c_o[k] = c[2k+1]$ として定めると、

$$C[t] = C_e[t] + \zeta_N^t C_o[t]$$
$$C[t + N/2] = C_e[t] - \zeta_N^t C_o[t]$$

です。  

これらを $C_e[t], C_o[t]$ について解くことにより、

$$C_e[t] = \frac{1}{2} (C[t] + C[t + N/2])$$
$$C_o[t] = \frac{1}{2} \overline{\zeta_N^{t}} (C[t] - C[t + N/2])$$

が得られ、$C(t)$ から $C_o(t), C_e(t)$ が求まることが分かります。  

ここで、$p(x) := c_e(x) + j c_o(x)$ として多項式 $p(x)$ を定義します。  
$p(x)$ の離散フーリエ変換 $P(t) = C_e(t) + j C_o(t)$ を逆離散フーリエ変換することにより $p(x) = c_e(x) + j c_o(x)$ が復元できることと、$c_e(x), c_o(x)$ は実数係数多項式なので $p[i]$ の実部、虚部がそれぞれ $c_e[i], c_o[i]$  に対応することに注意しておきます。  

$C(t)$ は先程の "$2$ つの実数係数多項式の離散フーリエ変換を $1$ 回の離散フーリエ変換で行うテク" で求めることができるので、$C_e(t), C_o(t)$ は計算が可能です。$C_e(t), C_o(t)$ から $P(t)$ を構築して逆離散フーリエ変換を行うことにより $c_e(x), c_o(x)$ すなわち、$c(x)$ が計算できます。  

したがって、長さが $N$ の離散フーリエ変換と長さが半分($N/2$) の逆離散フーリエ変換を $1$ 回ずつ行うことにより積 $f(x) g(x)$ が得られました。  


### 実装

$\overline{C[N-t]} = \overline{F[N-t]G[N-t]} = F[t]G[t] = C[t]$ より、 $\overline{C[t + N/2]} = C[N - (t + N/2)] = C[N/2 - t]$ です。  

これを代入することにより、

$$C_e[t] = \frac{1}{2} (C[t] + \overline{C[N/2 - t]})$$
$$C_o[t] = \frac{1}{2} \overline{\zeta_N^{t}} (C[t] - \overline{C[N/2 - t]})$$

が得られます。  

最後に、実装を読むときのためのメモを以下に記しておきます。  

- $C[t], C[N/2 - t]$ をそれぞれ $cf, cb$ という名前で管理している
- $F[0] = H[0].real(), G[0] = H[0].imag(), F[N/2] = H[N/2].real(), G[N/2] = H[N/2].imag()$ より、
$C[0] = H[0].real() \times H[0].imag(), C[N/2] = H[N/2].real() \times H[N/2].imag()$
- $zeta[i] := \zeta_N^i\ (0 \leq i < N / 2)$
- $zeta_f(d, p) := \zeta_{2^d}^p$
- $cf, cb$ に掛けるべき $\frac{1}{4}$ を後の $p$ への代入時の計算にまとめている

<br>

# TODO

TODO: 周波数間引きを書いて bit_reverese を消す  
TODO: zeta 配列を線形に見るように上手く変形する  


# 参考

2020/05/01: [https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79](https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79)  
2020/08/01: [http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html](http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html)  
2021/04/16: [http://www.ocw.titech.ac.jp/index.php?module=General&action=T0300&JWC=202002382&lang=JA&vid=03](http://www.ocw.titech.ac.jp/index.php?module=General&action=T0300&JWC=202002382&lang=JA&vid=03)  

<br>