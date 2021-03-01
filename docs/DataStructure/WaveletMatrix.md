---
title: Wavelet Matrix
documentation_of: //DataStructure/WaveletMatrix.hpp
---

# 概要

非負整数列を扱う静的データ構造です。  
各要素の値が $0$ 以上 $2^\sigma$ 未満の長さ $N$ の非負整数列に対し、事前計算 $\Theta(\sigma N)$ 、空間計算量 $N + o(N)$ で様々な計算を高速に行うことができます。  

- `WaveletMatrix(const std::vector<value_type> & v)`
	- 時間 $\Theta(\sigma \|$`v`$\|)$, 空間 $\|$`v`$\| + o(\|$`v`$\|)$ 配列 `v` で初期化
- `size_t size()`
	- $\Theta(1)$ 非負整数列の長さ $N$ を返す
- `T access(size_t k)`
	- $\Theta(\sigma)$ $A_k$ を返す
- `tuple<uint32_t, uint32_t, uint32_t> rank_all(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する ( $x$ より小さい値の個数, $x$ と等しい値の個数, $x$ より大きい値の個数) を返す
- `uint32_t rank_less_than(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数を返す
- `uint32_t rank(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ と等しい値の個数を返す
- `uint32_t rank_more_than(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より大きい値の個数を返す
- `size_t select(uint32_t k, const T & x)`
	- $\mathcal{O}(\sigma \log{N})$ 先頭から $k$ 番目に出現する $x$ の位置 (1-indexed) を返す
- `T quantile(size_t l, size_t r, uint32_t k)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ の中から昇順で $k$ 番目の値を返す
- `size_t range_frequency(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の個数を返す
- `vector<pair<T, uint32_t>> range_min_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)`
	- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて小さい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返す
- `vector<pair<T, uint32_t>> range_max_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)`
	- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて大きい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返す
- `pair<T, bool> next_value(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最小値を返す
- `pair<T, bool> prev_value(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最大値を返す
- `vector<pair<T, size_t>> get_rect(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta((r - l) \sigma \log{N})$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値を昇順に、値と出現位置 (0-indexed) の組の配列にして返す

<br>

# コンストラクタ

以降、$\sigma :=$ `BITS` とします。
扱う値の範囲は $0$ 以上 $2^\sigma$ 未満です。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- `BITS` は `T` のビット数以下
- `BV` は [`SuccintBitVector`](https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp)

---

### WaveletMatrix(const std::vector&lt;value_type&gt; & v)

配列 `v` で初期化します。  

**制約**

- `v` のすべての要素の値は非負

**計算量**

- 時間 $\Theta(\sigma \|$`v`$\|)$
- 空間 $\|$`v`$\| + o(\|$`v`$\|)$

---

<br>

# メンバ関数

以下、長さ $N$ の非負整数列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。  
また、[`SuccintBitVector`](https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp) の `rank` の計算量を $\Theta(1)$ 、`select` の計算量を $\mathcal{O}(\log{N})$ と仮定しています。  

---

### size_t size()

非負整数列 $A$ の長さ $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### T access(size_t k)

$A_k$ を返します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(\sigma)$

---

### tuple<uint32_t, uint32_t, uint32_t> rank_all(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数、$x$ と等しい値の個数、$x$ より大きい値の個数を順にまとめたタプルを返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank_less_than(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ と等しい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank_more_than(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より大きい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### size_t select(uint32_t k, const T & x)

先頭から $k$ 番目に出現する $x$ の位置 (1-indexed) を返します。
$k = 0$ または、そのような位置が存在しない場合は $N + 1$ を返します。  

**制約**

- $0 \leq k$
- $0 \leq x < 2^\sigma$

**計算量**

- $\mathcal{O}(\sigma \log{N})$

---

### T quantile(size_t l, size_t r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ の中から昇順で $k$ 番目の値を返します。  

**制約**

- $0 \leq l < r \leq N$
- $0 < k \leq r - l$

**計算量**

- $\Theta(\sigma)$

---

### size_t range_frequency(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の個数を返します。
$l = r$ または `val_l` $=$ `val_r` のときは $0$ を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので、この場合は代わりに `rank_all` を使用してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### vector&lt;pair&lt;T, uint32_t&gt;&gt; range_min_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて小さい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返します。
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$

---

### vector&lt;pair&lt;T, uint32_t&gt;&gt; range_max_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて大きい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返します。
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $< 2^\sigma - 1$

**計算量**

- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$

---

### pair&lt;T, bool&gt; next_value(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最小値を返します。
そのような値が存在するときは pair の $2$ 番目の値が $true$ に、存在しない場合は $false$ になります。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### pair&lt;T, bool&gt; prev_value(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最大値を返します。
そのような値が存在するときは pair の $2$ 番目の値が $true$ に、存在しない場合は $false$ になります。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### vector&lt;pair&lt;T, size_t&gt;&gt; get_rect(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値を昇順に、値と出現位置 (0-indexed) の組の配列にして返します。
同じ値の順序は、出現位置の昇順となります。  
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta((r - l) \sigma \log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <DataStructure/SuccintBitVector.hpp>
#include <DataStructure/WaveletMatrix.hpp>
using namespace std;

int main() {
	//                                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	WaveletMatrix<3, int, SuccintBitVector> wm({3, 0, 2, 3, 4, 6, 5, 7, 1, 1});
	cout << "size = " << wm.size() << endl; // 10
	
	// 3 0 2 3 4 6 5 7 1 1
	for (int i = 0; i < wm.size(); ++i) cout << wm.access(i) << " \n"[i + 1 == wm.size()];
	
	auto [lt, r, gt] = wm.rank_all(0, 7, 3); // target = [3, 0, 2, 3, 4, 6, 5]
	cout << "< 3 (ans " << lt << "), = 3 (ans " << r << "), > 3 (ans " << gt << ")" << endl; // 2, 2, 3
	
	cout << "rank_less_than(5, 8, 7) = " << wm.rank_less_than(5, 8, 7) << endl; // 2
	cout << "rank(5, 8, 7) = " << wm.rank(5, 8, 7) << endl; // 1
	cout << "rank_more_than(5, 8, 7) = " << wm.rank_more_than(5, 8, 7) << endl; // 0
	
	cout << "select(1, 6) = " << wm.select(1, 6) << endl; // 6 (1-indexed)
	cout << "select(2, 6) = " << wm.select(2, 6) << endl; // 11 (= N + 1) (1-indexed)
	cout << "select(2, 1) = " << wm.select(2, 1) << endl; // 10
	
	cout << "quantile(2, 10, 4) = " << wm.quantile(2, 10, 4) << endl; // 3 [1, 1, 2, 3, 4, 5, 6, 7](sorted)
	
	cout << "range_frequency(1, 10, 2, 4) = " << wm.range_frequency(1, 10, 2, 4) << endl; // 2 [2, 3]
	
	puts("range_min_k");
	// target = [3, 0, 2, 3, 4, 6] -> [3, 3, 4]
	// v = 3, frequency = 2
	// v = 4, frequency = 1
	for (auto [v, fq] : wm.range_min_k(0, 6, 3, 5, 2)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	puts("range_max_k");
	
	// target = [5, 7, 1, 1] -> [5, 7, 1, 1]
	// v = 7, frequency = 1
	// v = 5, frequency = 1
	for (auto [v, fq] : wm.range_max_k(6, 10, 0, 8, 2)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	
	puts("range_min_k");
	// target = [1, 1] -> [1, 1]
	// v = 1, frequency = 2
	for (auto [v, fq] : wm.range_min_k(8, 10, 1, 2, 3)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	// idx: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	//  wm: 3, 0, 2, 3, 4, 6, 5, 7, 1, 1
	
	{
		// target = [0, 2, 3] -> [2, 3]
		auto [v, b] = wm.next_value(1, 4, 2, 5);
		cout << "next_value(1, 4, 2, 5) : " << "v = " << v << ", b = " << boolalpha << b << endl; // 2, true
	}
	{
		// target = [0, 2, 3, 4, 6, 5] -> [3, 4, 5]
		auto [v, b] = wm.prev_value(1, 7, 3, 6);
		cout << "next_value(1, 7, 3, 6) : " << "v = " << v << ", b = " << boolalpha << b << endl; // 5, true
	}
	{
		// target = [2, 3] -> []
		auto [v, b] = wm.prev_value(2, 4, 0, 1);
		cout << "next_value(2, 4, 0, 1) : " << "v = " << v << ", b = " << boolalpha << b << endl; // *, false
	}
	
	// target = [2, 3, 4, 6, 5, 7, 1, 1] -> [2, 3, 1, 1]
	// v = 1, idx = 8
	// v = 1, idx = 9
	// v = 2, idx = 2
	// v = 3, idx = 3
	for (auto [v, idx] : wm.get_rect(2, 10, 1, 4)) cout << "v = " << v << ", idx = " << idx << endl;
}
```

<br>

# 参考

2020/09/03: [https://www.slideshare.net/pfi/ss-15916040](https://www.slideshare.net/pfi/ss-15916040)  
2020/09/04: [https://miti-7.hatenablog.com/entry/2018/04/28/152259](https://miti-7.hatenablog.com/entry/2018/04/28/152259)  
2020/09/07: [http://algoogle.hadrori.jp/algorithm/wavelet.html](http://algoogle.hadrori.jp/algorithm/wavelet.html)  

<br>