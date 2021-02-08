---
title: bit 操作
documentation_of: //Mathematics/bit_operation.hpp
---

# 概要

bit 操作関連の関数の寄せ集めです。  

<br>

# 関数

関数名の末尾に `ll` が付いているものは 64 bit バージョンです。

### int tk::pop_count(uint32_t x)
### int tk::pop_countll(uint64_t x)

$x$ の二進表記で $1$ が立っているビットの個数を返します。  

**計算量**

- $\Theta(1)$

---

### int tk::count_trailing_zeros(uint32_t x)
### int tk::count_trailing_zerosll(uint64_t x)

$x$ の二進表記で最下位ビットから連続する $0$ の個数を返します。  

**計算量**

- $\Theta(1)$

---

### int tk::count_leading_zeros(uint32_t x)
### int tk::count_leading_zerosll(uint64_t x)

$x$ の二進表記で最上位ビットから連続する $0$ の個数を返します。  

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include <Mathematics/bit_operation.hpp>
using namespace std;

int main() {
	int a = 0b00101000;
	cout << tk::pop_count(a) << endl; // 2
	cout << tk::count_trailing_zeros(a) << endl; // 3
	cout << tk::count_leading_zeros(a) << endl; // 26
	
	unsigned long long b = 0xffffffffffffffff;
	cout << tk::pop_countll(b) << endl; // 64
	cout << tk::count_trailing_zerosll(b) << endl; // 0
	cout << tk::count_leading_zerosll(b) << endl; // 0
	
	cout << tk::pop_countll(0) << endl; // 0
	cout << tk::count_trailing_zerosll(0) << endl; // 64
	cout << tk::count_leading_zerosll(0) << endl; // 64
}
```

<br>

# 解説

#### pop_count

$x = (11 01 10 11 00 11 11 11 11 11 11 11 11 11 11 11)_2$ のときの計算過程を載せておきます。  

```cpp
constexpr int pop_count(unsigned int x) {
	// x = 11 01 10 11 00 11 11 11 11 11 11 11 11 11 11 11
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	//     10 01 01 10 00 10 10 10 10 10 10 10 10 10 10 10
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	// 0011 0011 0010 0100 0100 0100 0100 0100
	x += (x + (x >> 4)) & 0x0f0f0f0f;
	// 00000110 00000110 00001000 00001000
	x += x >> 8;
	// 0000011000001100 0000100000010000
	x += x >> 16;
	// 0000011000001100 0000111000011100
	return x & 0xff;
	// 00011100 = 28
}
```

<br>

# 参考
2020/08/31: https://qiita.com/zawawahoge/items/8bbd4c2319e7f7746266  
2021/02/08: http://www.nminoru.jp/~nminoru/programming/bitcount.html  

<br>