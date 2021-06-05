---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Combination.test.cpp
    title: Test/Combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/Combination.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/Combination.hpp
  bundledCode: "#line 1 \"Mathematics/Combination.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/Combination.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct Combination {\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tstd::vector<T> fact_, finv_, inv_;\r\n\tstatic constexpr\
    \ size_type MAX_LIMIT = 50000000;\r\n\t\r\npublic:\r\n\texplicit Combination(size_type\
    \ sz = 1) : fact_(1, 1), finv_(1, 1), inv_(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type\
    \ k) { if (k >= T::mod()) return 0; build(k); return fact_[k]; }\r\n\tT finv(size_type\
    \ k) { assert(k < T::mod()); build(k); return finv_[k]; }\r\n\tT inv(size_type\
    \ k) { assert(k > 0 && k < T::mod()); build(k); return inv_[k]; }\r\n\tT operator\
    \ ()(int n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r <\
    \ 0 || n < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tvoid build(size_type k) {\r\n\t\tif (fact_.size() > k) return;\r\
    \n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::mod()),\
    \ std::max(fact_.size() * 2, k + 1)});\r\n\t\tsize_type presz = fact_.size();\r\
    \n\t\tfact_.resize(sz);\r\n\t\tfinv_.resize(sz);\r\n\t\tinv_.resize(sz);\r\n\t\
    \tfor (size_type i = presz; i < sz; ++i) fact_[i] = fact_[i - 1] * i;\r\n\t\t\
    finv_[sz - 1] = fact_[sz - 1].inv();\r\n\t\tfor (size_type i = sz - 1; i > presz;\
    \ --i) {\r\n\t\t\tfinv_[i - 1] = finv_[i] * i;\r\n\t\t\tinv_[i] = fact_[i - 1]\
    \ * finv_[i];\r\n\t\t}\r\n\t\tinv_[presz] = fact_[presz - 1] * finv_[presz];\r\
    \n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_COMBINATION_HPP\r\n#define INCLUDE_GUARD_COMBINATION_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/Combination.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct Combination {\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tstd::vector<T> fact_, finv_, inv_;\r\n\tstatic constexpr\
    \ size_type MAX_LIMIT = 50000000;\r\n\t\r\npublic:\r\n\texplicit Combination(size_type\
    \ sz = 1) : fact_(1, 1), finv_(1, 1), inv_(1, 1) { build(sz); }\r\n\t\r\n\tT fact(size_type\
    \ k) { if (k >= T::mod()) return 0; build(k); return fact_[k]; }\r\n\tT finv(size_type\
    \ k) { assert(k < T::mod()); build(k); return finv_[k]; }\r\n\tT inv(size_type\
    \ k) { assert(k > 0 && k < T::mod()); build(k); return inv_[k]; }\r\n\tT operator\
    \ ()(int n, int r) { return c(n, r); }\r\n\tT c(int n, int r) {\r\n\t\tif (r <\
    \ 0 || n < r) return 0;\r\n\t\treturn fact(n) * finv(r) * finv(n - r);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tvoid build(size_type k) {\r\n\t\tif (fact_.size() > k) return;\r\
    \n\t\tassert(k < MAX_LIMIT);\r\n\t\tsize_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::mod()),\
    \ std::max(fact_.size() * 2, k + 1)});\r\n\t\tsize_type presz = fact_.size();\r\
    \n\t\tfact_.resize(sz);\r\n\t\tfinv_.resize(sz);\r\n\t\tinv_.resize(sz);\r\n\t\
    \tfor (size_type i = presz; i < sz; ++i) fact_[i] = fact_[i - 1] * i;\r\n\t\t\
    finv_[sz - 1] = fact_[sz - 1].inv();\r\n\t\tfor (size_type i = sz - 1; i > presz;\
    \ --i) {\r\n\t\t\tfinv_[i - 1] = finv_[i] * i;\r\n\t\t\tinv_[i] = fact_[i - 1]\
    \ * finv_[i];\r\n\t\t}\r\n\t\tinv_[presz] = fact_[presz - 1] * finv_[presz];\r\
    \n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_COMBINATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Combination.hpp
  requiredBy: []
  timestamp: '2021-02-26 10:21:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Combination.test.cpp
documentation_of: Mathematics/Combination.hpp
layout: document
title: "\u7D44\u307F\u5408\u308F\u305B $_nC_r$"
---

# 概要

`ModInt` 構造体に対して組み合わせを計算する構造体です。  
$5 \times 10^7$ 未満の $n$ や $r$ に対して $_nC_r \bmod{M}$ を ならし $\Theta(1)$ で計算します。  
[AC Library](https://github.com/atcoder/ac-library) の `Modint` 構造体を使用することもできます  
全体で $\max(n)$ の空間計算量がかかります。  

- `Combination(size_t sz = 1)`
	- $\Theta(sz + \log{M})$ $sz$ を指定することにより事前にテーブルを構築
- `T fact(size_t k)`
	- ならし $\Theta(1)$ $k!$ を返す。
- `T finv(size_t k)`
	- ならし $\Theta(1)$ $(k!)^{-1}$ を返す
- `T inv(size_t k)`
	- ならし $\Theta(1)$ $k^{-1}$ を返す
- `T c(int n, int r)`
	- ならし $\Theta(1)$ $_nC_r$ を返す

<br>

# コンストラクタ

**制約**

- $T$ は [`ModInt`](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)
- $T$ の法 $M$ は素数

---

### Combination(size_t sz = 1)

初期化します。
事前に $n$ として使用する値の最大値が分かっている場合は $sz$ にその値を指定すると少し早くなります。

**計算量**

- $\Theta(sz + \log{M})$

---

<br>

# メンバ関数

以下、`T: ModInt` の法を $M$ とします。
`MAX_LIMIT` は $5 \times 10^7$ です。  

### T fact(size_t k)

$k!$ を返します。  

**制約**

- $0 \leq k <$ `MAX_LIMIT`

**計算量**

- ならし $\Theta(1)$

---

### T finv(size_t k)

$(k!)^{-1}$ を返します。  

**制約**

- $0 \leq k < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

---

### T inv(size_t k)

$k^{-1}$ を返します。  

**制約**

- $0 \leq k < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

---

### T c(int n, int r)

$_nC_r \bmod{M}$ を返します。
$n < 0$ または $n < r$ の場合は $0$ を返します。  
`Combination(n, r)` と書いても同じ結果になります。
詳しくは使用例を参照してください。  

**制約**

- $0 \leq n < \min(M,$ `MAX_LIMIT`$)$

**計算量**

- ならし $\Theta(1)$

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/ModInt.hpp"
#include "Mathematics/Combination.hpp"
using namespace std;

constexpr int MOD = 13;
using mint = ModInt<MOD>;
using Comb = Combination<mint>;

int main() {
	Comb comb;
	cout << comb(5, 2) << endl; // 10
	cout << comb(3, 2) << endl; // 3
	cout << comb(8, 3) << endl; // 4 (8 * 7 * 6 / 3! = 56 = 4 + 4 * 13)
	
	cout << comb.fact(3) << endl; // 6 (= 3!)
	cout << comb.finv(5) << endl; // 9 (= (5!)^{-1})
	cout << comb.finv(5) * comb.fact(5) << endl; // 1
	cout << comb.inv(2) << endl; // 7 (2 * 7 = 14 = 1 + 13)
}
```

<br>

# 解説

事前計算のテーブルを $2$ 倍しながら計算することにより、ならし $\Theta(1)$ を達成しています。  
ならし計算量については [https://trap.jp/post/883/](https://trap.jp/post/883/) が参考になると思います。  

<br>

# TODO

TODO: 重複組合せ nHk の追加  
TODO: 順列 nPk の追加
TODO: $r$ が小さい場合の愚直計算の追加  