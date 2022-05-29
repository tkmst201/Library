---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Combination.test.cpp
    title: Test/Combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DynamicSegmentTree.test.cpp
    title: Test/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
    title: Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LazySegmentTree.test.cpp
    title: Test/LazySegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SegmentTree.fold.test.cpp
    title: Test/SegmentTree.fold.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SlidingWindowAggregation.test.cpp
    title: Test/SlidingWindowAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/VertexUpdatePathFold.vertex.test.cpp
    title: Test/VertexUpdatePathFold.vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/matrix.det.test.cpp
    title: Test/matrix.det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/matrix.pow.test.cpp
    title: Test/matrix.pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/ModInt.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/ModInt.hpp
  bundledCode: "#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n#include <cassert>\r\n\
    #include <iostream>\r\n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
    \n */\r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\
    \n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\n\
    private:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val % M + (val >= 0 ? 0 : M)) {}\r\n\tconstexpr value_type val()\
    \ const noexcept { return val_; }\r\n\tconstexpr static decltype(M) mod() noexcept\
    \ { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const noexcept {\
    \ return val_; }\r\n\tconstexpr bool operator !() const noexcept { return !static_cast<bool>(*this);\
    \ }\r\n\tconstexpr ModInt operator +() const noexcept { return *this; }\r\n\t\
    constexpr ModInt operator -() const noexcept { return ModInt(val_ == 0 ? 0 : M\
    \ - val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept { ModInt res = *this;\
    \ ++*this; return res; }\r\n\tconstexpr ModInt operator --(int) noexcept { ModInt\
    \ res = *this; --*this; return res; }\r\n\tconstexpr ModInt & operator ++() noexcept\
    \ { val_ = val_ + 1 == M ? 0 : val_ + 1; return *this; }\r\n\tconstexpr ModInt\
    \ & operator --() noexcept { val_ = val_ == 0 ? M - 1 : val_ - 1; return *this;\
    \ }\r\n\tconstexpr ModInt & operator +=(const ModInt & rhs) noexcept { val_ +=\
    \ val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ - M; return *this; }\r\n\tconstexpr\
    \ ModInt & operator -=(const ModInt & rhs) noexcept { val_ += val_ >= rhs.val_\
    \ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\tconstexpr ModInt & operator\
    \ *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_\
    \ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt & rhs)\
    \ noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt operator\
    \ +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) += rhs;\
    \ }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr ModInt operator\
    \ *(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) *= rhs;\
    \ }\r\n\tfriend constexpr ModInt operator /(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend constexpr bool operator\
    \ ==(const ModInt & lhs, const ModInt & rhs) noexcept { return lhs.val_ == rhs.val_;\
    \ }\r\n\tfriend constexpr bool operator !=(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val_; }\r\n\tfriend\
    \ std::istream & operator >>(std::istream & is, ModInt & rhs) { calc_type x; is\
    \ >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr ModInt pow(calc_type\
    \ n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\t\tif (n < 0) { x =\
    \ x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1;\
    \ }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv() const noexcept\
    \ {\r\n\t\tvalue_type a = val_, a1 = 1, b = M, b1 = 0;\r\n\t\twhile (b > 0) {\r\
    \n\t\t\tconst value_type q = a / b;\r\n\t\t\tvalue_type tmp = a - q * b; a = b;\
    \ b = tmp;\r\n\t\t\ttmp = a1 - q * b1; a1 = b1; b1 = tmp;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\tif (a1 < 0) a1 += M;\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_MOD_INT_HPP\r\n#define INCLUDE_GUARD_MOD_INT_HPP\r\n\
    \r\n#include <cassert>\r\n#include <iostream>\r\n#include <cstdint>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\n */\r\
    \ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\n\tusing\
    \ value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\nprivate:\r\
    \n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type val = 0)\
    \ : val_(val % M + (val >= 0 ? 0 : M)) {}\r\n\tconstexpr value_type val() const\
    \ noexcept { return val_; }\r\n\tconstexpr static decltype(M) mod() noexcept {\
    \ return M; }\r\n\t\r\n\texplicit constexpr operator bool() const noexcept { return\
    \ val_; }\r\n\tconstexpr bool operator !() const noexcept { return !static_cast<bool>(*this);\
    \ }\r\n\tconstexpr ModInt operator +() const noexcept { return *this; }\r\n\t\
    constexpr ModInt operator -() const noexcept { return ModInt(val_ == 0 ? 0 : M\
    \ - val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept { ModInt res = *this;\
    \ ++*this; return res; }\r\n\tconstexpr ModInt operator --(int) noexcept { ModInt\
    \ res = *this; --*this; return res; }\r\n\tconstexpr ModInt & operator ++() noexcept\
    \ { val_ = val_ + 1 == M ? 0 : val_ + 1; return *this; }\r\n\tconstexpr ModInt\
    \ & operator --() noexcept { val_ = val_ == 0 ? M - 1 : val_ - 1; return *this;\
    \ }\r\n\tconstexpr ModInt & operator +=(const ModInt & rhs) noexcept { val_ +=\
    \ val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ - M; return *this; }\r\n\tconstexpr\
    \ ModInt & operator -=(const ModInt & rhs) noexcept { val_ += val_ >= rhs.val_\
    \ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\tconstexpr ModInt & operator\
    \ *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_\
    \ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt & rhs)\
    \ noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt operator\
    \ +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) += rhs;\
    \ }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr ModInt operator\
    \ *(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) *= rhs;\
    \ }\r\n\tfriend constexpr ModInt operator /(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend constexpr bool operator\
    \ ==(const ModInt & lhs, const ModInt & rhs) noexcept { return lhs.val_ == rhs.val_;\
    \ }\r\n\tfriend constexpr bool operator !=(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val_; }\r\n\tfriend\
    \ std::istream & operator >>(std::istream & is, ModInt & rhs) { calc_type x; is\
    \ >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr ModInt pow(calc_type\
    \ n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\t\tif (n < 0) { x =\
    \ x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1;\
    \ }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv() const noexcept\
    \ {\r\n\t\tvalue_type a = val_, a1 = 1, b = M, b1 = 0;\r\n\t\twhile (b > 0) {\r\
    \n\t\t\tconst value_type q = a / b;\r\n\t\t\tvalue_type tmp = a - q * b; a = b;\
    \ b = tmp;\r\n\t\t\ttmp = a1 - q * b1; a1 = b1; b1 = tmp;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\tif (a1 < 0) a1 += M;\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n#endif\
    \ // INCLUDE_GUARD_MOD_INT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/ModInt.hpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/matrix.pow.test.cpp
  - Test/HeavyLightDecomposition_Query.PathQuery.test.cpp
  - Test/LazySegmentTree.test.cpp
  - Test/DynamicSegmentTree.test.cpp
  - Test/SlidingWindowAggregation.test.cpp
  - Test/SegmentTree.fold.test.cpp
  - Test/Combination.test.cpp
  - Test/VertexUpdatePathFold.vertex.test.cpp
  - Test/matrix.det.test.cpp
documentation_of: Mathematics/ModInt.hpp
layout: document
title: "ModInt \u69CB\u9020\u4F53"
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

- `ModInt /= ModInt` または `ModInt / ModInt` のとき、右辺の値と $M$ は互いに素

**計算量**

- $\Theta(\log{M})$ ( `ModInt /= ModInt` または `ModInt / ModInt` )
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
#include "Mathematics/ModInt.hpp"
using namespace std;

constexpr int MOD = 13;
using mint = ModInt<MOD>;

int main() {
	cout << "M = " << mint::mod() << endl; // 13
	cout << "0: " << mint(0) << endl; // 0
	cout << "15: " << mint(15) << endl; // 2
	cout << "-1: " << mint(-1) << endl; // 12
	cout << "-1: " << mint(-1).val() << endl; // 12
	cout << "10^2 " << mint(10).pow(2) << endl; // 9
	cout << "3^-1 " << mint(3).inv() << endl; // 9 ( 9*3 = 27 = 1+(13*2) )
	
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