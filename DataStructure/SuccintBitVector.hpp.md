---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.next_prev_value.test.cpp
    title: Test/WaveletMatrix.next_prev_value.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.quantile.test.cpp
    title: Test/WaveletMatrix.quantile.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.range_frequency.test.cpp
    title: Test/WaveletMatrix.range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.select.range_k.test.cpp
    title: Test/WaveletMatrix.select.range_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp
  bundledCode: "#line 1 \"DataStructure/SuccintBitVector.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cstdint>\r\n#include <algorithm>\r\n#include <cassert>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp\r\
    \n */\r\nstruct SuccintBitVector {\r\n\tusing size_type = std::size_t;\r\n\tusing\
    \ uint32 = std::uint32_t;\r\n\t\r\nprivate:\r\n\tusing uint8 = std::uint8_t;\r\
    \n\t\r\n\tstatic constexpr size_type LARGE = 8;\r\n\tstatic constexpr size_type\
    \ SMALL = 3;\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<uint8> bits;\r\
    \n\tstd::vector<uint32> large;\r\n\tstd::vector<uint8> small;\r\n\t\r\npublic:\r\
    \n\texplicit SuccintBitVector(size_type n)\r\n\t\t: n(n), bits(n == 0 ? 0 : ((n\
    \ - 1) >> SMALL) + 1, 0u) {}\r\n\t\r\n\texplicit SuccintBitVector(const std::vector<uint8>\
    \ & bits)\r\n\t\t: n(bits.size() << SMALL), bits(bits) {}\r\n\t\r\n\tvoid build()\
    \ {\r\n\t\tlarge.assign(((n - 1) >> LARGE) + 1, 0);\r\n\t\tsmall.assign(((n -\
    \ 1) >> SMALL) + 1, 0);\r\n\t\tfor (uint32 i = 0, lidx = 0; i < bits.size(); i\
    \ += 1u << (LARGE - SMALL), ++lidx) {\r\n\t\t\tif (lidx > 0) large[lidx] = large[lidx\
    \ - 1] + small[i - 1] + pop_count(bits[i - 1]);\r\n\t\t\tsmall[i] = 0;\r\n\t\t\
    \tfor (uint32 j = i + 1; j < std::min<uint32>(bits.size(), i + (1u << (LARGE -\
    \ SMALL))); ++j) {\r\n\t\t\t\tsmall[j] = small[j - 1] + pop_count(bits[j - 1]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i) noexcept {\r\n\t\tassert(i <\
    \ n);\r\n\t\tbits[i >> SMALL] |= 1u << (i & ~(~0u << SMALL));\r\n\t}\r\n\t\r\n\
    \tvoid reset(size_type i) noexcept {\r\n\t\tassert(i < n);\r\n\t\tbits[i >> SMALL]\
    \ &= ~(1u << (i & ~(~0u << SMALL)));\r\n\t}\r\n\t\r\n\tbool access(size_type i)\
    \ const noexcept {\r\n\t\tassert(i < n);\r\n\t\treturn bits[i >> SMALL] >> (i\
    \ & ~(~0u << SMALL)) & 1;\r\n\t}\r\n\t\r\n\tuint32 rank1(size_type i) const noexcept\
    \ {\r\n\t\tassert(i <= n);\r\n\t\tif (i == 0) return 0;\r\n\t\t--i;\r\n\t\treturn\
    \ large[i >> LARGE] + small[i >> SMALL] + pop_count(bits[i >> SMALL] & ~(~0u <<\
    \ ((i & (~(~0u << SMALL))) + 1)));\r\n\t}\r\n\t\r\n\tuint32 rank0(size_type i)\
    \ const noexcept {\r\n\t\tassert(i <= n);\r\n\t\treturn i - rank1(i);\r\n\t}\r\
    \n\t\r\n\tsize_type select1(size_type k) const noexcept {\r\n\t\tif (k == 0) return\
    \ size() + 1;\r\n\t\tuint32 l = 0, r = large.size();\r\n\t\twhile (l + 1 < r)\
    \ {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(large[m] < k ? l : r) =\
    \ m;\r\n\t\t}\r\n\t\tuint32 cnt = large[l];\r\n\t\tl = l << (LARGE - SMALL); r\
    \ = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + small[m]\
    \ < k ? l : r) = m;\r\n\t\t}\r\n\t\tcnt += small[l];\r\n\t\tconst uint32 idx =\
    \ l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u <<\
    \ SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(bits[idx] & ~(~0u << r)) < k) return\
    \ size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >>\
    \ 1;\r\n\t\t\t(cnt + pop_count(bits[idx] & ~(~0u << m)) < k ? l : r) = m;\r\n\t\
    \t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\n\tsize_type select0(size_type\
    \ k) const noexcept {\r\n\t\tif (k == 0) return size() + 1;\r\n\t\tuint32 l =\
    \ 0, r = large.size();\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l\
    \ + r) >> 1;\r\n\t\t\t(m * (1 << LARGE) - large[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tuint32 cnt = l * (1 << LARGE) - large[l];\r\n\t\tl = l << (LARGE - SMALL);\
    \ r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + (m & ~(~0u\
    \ << (LARGE - SMALL))) * (1u << SMALL) - small[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tcnt += (l & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[l];\r\n\t\
    \tconst uint32 idx = l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size()\
    \ - 1) & ~(0u << SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(~bits[idx] & ~(~0u\
    \ << r)) < k) return size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32\
    \ m = (l + r) >> 1;\r\n\t\t\t(cnt + pop_count(~bits[idx] & ~(~0u << m)) < k ?\
    \ l : r) = m;\r\n\t\t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic constexpr uint8 table[1u << (1u << SMALL)] {\r\n\t\t0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8\r\n\t};\r\
    \n\t\r\n\tstatic constexpr uint8 pop_count(uint8 x) noexcept {\r\n\t\treturn table[x];\r\
    \n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP\r\n#define INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP\r\
    \n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp\r\
    \n */\r\nstruct SuccintBitVector {\r\n\tusing size_type = std::size_t;\r\n\tusing\
    \ uint32 = std::uint32_t;\r\n\t\r\nprivate:\r\n\tusing uint8 = std::uint8_t;\r\
    \n\t\r\n\tstatic constexpr size_type LARGE = 8;\r\n\tstatic constexpr size_type\
    \ SMALL = 3;\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<uint8> bits;\r\
    \n\tstd::vector<uint32> large;\r\n\tstd::vector<uint8> small;\r\n\t\r\npublic:\r\
    \n\texplicit SuccintBitVector(size_type n)\r\n\t\t: n(n), bits(n == 0 ? 0 : ((n\
    \ - 1) >> SMALL) + 1, 0u) {}\r\n\t\r\n\texplicit SuccintBitVector(const std::vector<uint8>\
    \ & bits)\r\n\t\t: n(bits.size() << SMALL), bits(bits) {}\r\n\t\r\n\tvoid build()\
    \ {\r\n\t\tlarge.assign(((n - 1) >> LARGE) + 1, 0);\r\n\t\tsmall.assign(((n -\
    \ 1) >> SMALL) + 1, 0);\r\n\t\tfor (uint32 i = 0, lidx = 0; i < bits.size(); i\
    \ += 1u << (LARGE - SMALL), ++lidx) {\r\n\t\t\tif (lidx > 0) large[lidx] = large[lidx\
    \ - 1] + small[i - 1] + pop_count(bits[i - 1]);\r\n\t\t\tsmall[i] = 0;\r\n\t\t\
    \tfor (uint32 j = i + 1; j < std::min<uint32>(bits.size(), i + (1u << (LARGE -\
    \ SMALL))); ++j) {\r\n\t\t\t\tsmall[j] = small[j - 1] + pop_count(bits[j - 1]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i) noexcept {\r\n\t\tassert(i <\
    \ n);\r\n\t\tbits[i >> SMALL] |= 1u << (i & ~(~0u << SMALL));\r\n\t}\r\n\t\r\n\
    \tvoid reset(size_type i) noexcept {\r\n\t\tassert(i < n);\r\n\t\tbits[i >> SMALL]\
    \ &= ~(1u << (i & ~(~0u << SMALL)));\r\n\t}\r\n\t\r\n\tbool access(size_type i)\
    \ const noexcept {\r\n\t\tassert(i < n);\r\n\t\treturn bits[i >> SMALL] >> (i\
    \ & ~(~0u << SMALL)) & 1;\r\n\t}\r\n\t\r\n\tuint32 rank1(size_type i) const noexcept\
    \ {\r\n\t\tassert(i <= n);\r\n\t\tif (i == 0) return 0;\r\n\t\t--i;\r\n\t\treturn\
    \ large[i >> LARGE] + small[i >> SMALL] + pop_count(bits[i >> SMALL] & ~(~0u <<\
    \ ((i & (~(~0u << SMALL))) + 1)));\r\n\t}\r\n\t\r\n\tuint32 rank0(size_type i)\
    \ const noexcept {\r\n\t\tassert(i <= n);\r\n\t\treturn i - rank1(i);\r\n\t}\r\
    \n\t\r\n\tsize_type select1(size_type k) const noexcept {\r\n\t\tif (k == 0) return\
    \ size() + 1;\r\n\t\tuint32 l = 0, r = large.size();\r\n\t\twhile (l + 1 < r)\
    \ {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(large[m] < k ? l : r) =\
    \ m;\r\n\t\t}\r\n\t\tuint32 cnt = large[l];\r\n\t\tl = l << (LARGE - SMALL); r\
    \ = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + small[m]\
    \ < k ? l : r) = m;\r\n\t\t}\r\n\t\tcnt += small[l];\r\n\t\tconst uint32 idx =\
    \ l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u <<\
    \ SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(bits[idx] & ~(~0u << r)) < k) return\
    \ size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >>\
    \ 1;\r\n\t\t\t(cnt + pop_count(bits[idx] & ~(~0u << m)) < k ? l : r) = m;\r\n\t\
    \t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\n\tsize_type select0(size_type\
    \ k) const noexcept {\r\n\t\tif (k == 0) return size() + 1;\r\n\t\tuint32 l =\
    \ 0, r = large.size();\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l\
    \ + r) >> 1;\r\n\t\t\t(m * (1 << LARGE) - large[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tuint32 cnt = l * (1 << LARGE) - large[l];\r\n\t\tl = l << (LARGE - SMALL);\
    \ r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + (m & ~(~0u\
    \ << (LARGE - SMALL))) * (1u << SMALL) - small[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tcnt += (l & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[l];\r\n\t\
    \tconst uint32 idx = l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size()\
    \ - 1) & ~(0u << SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(~bits[idx] & ~(~0u\
    \ << r)) < k) return size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32\
    \ m = (l + r) >> 1;\r\n\t\t\t(cnt + pop_count(~bits[idx] & ~(~0u << m)) < k ?\
    \ l : r) = m;\r\n\t\t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic constexpr uint8 table[1u << (1u << SMALL)] {\r\n\t\t0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8\r\n\t};\r\
    \n\t\r\n\tstatic constexpr uint8 pop_count(uint8 x) noexcept {\r\n\t\treturn table[x];\r\
    \n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SuccintBitVector.hpp
  requiredBy:
  - DataStructure/WaveletMatrix.hpp
  timestamp: '2021-03-01 23:06:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/WaveletMatrix.range_frequency.test.cpp
  - Test/WaveletMatrix.quantile.test.cpp
  - Test/WaveletMatrix.select.range_k.test.cpp
  - Test/WaveletMatrix.next_prev_value.test.cpp
documentation_of: DataStructure/SuccintBitVector.hpp
layout: document
title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB"
---

# 概要

ビット列を扱うデータ構造です。  
長さ $N$ のビット列に対し事前計算 $\Theta(N)$ で、ある位置までに存在する $1$ (または $0$ ) の個数を $\Theta(1)$ 、先頭から $i$ 番目の $1$ (または $0$ ) の位置を $\mathcal{O}(\log{N})$ で求めることができます。  

- `SuccintBitVector(size_t n)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `SuccintBitVector(const std::vector<uint8> & bits)`
	- $\Theta(\|$`bits`$\|)$ ビット列 `bits` で初期化
- `void build()`
	- 時間: $\Theta(N)$ 空間: $N + o(N)$ 事前計算を行う。`rank`、`select` を使用する前に呼ぶ
- `size_t size()`
	- $\Theta(1)$ ビット列の長さ $N$ を返す
- `void set(size_t i)`
	- $\Theta(1)$ $B_i = 1$
- `void reset(size_t i)`
	- $\Theta(1)$ $B_i = 0$
- `bool access(size_t i)`
	- $\Theta(1)$ $B_i$ を返す
- `uint32_t rank1(size_t i)`
	- $\Theta(1)$ $B_0, \ldots, B_{i-1}$ に存在する $1$ の個数を返す
- `uint32_t rank0(size_t i)`
	- $\Theta(1)$ $B_0, \ldots, B_{i-1}$ に存在する $0$ の個数を返す
- `size_t select1(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から $k$ 番目の $1$ の位置を 1-indexed で返す。そのような位置が存在しなければ $N + 1$ を返す
- `size_t select0(size_t k)`
	- $\mathcal{O}(\log{N})$ 先頭から $k$ 番目の $0$ の位置を 1-indexed で返す。そのような位置が存在しなければ $N + 1$ を返す

<br>

# コンストラクタ

### SuccintBitVector(size_t n)

要素数 $n$ で初期化します。
はじめ、すべてのビットは $0$ です。  

**計算量**

- $\Theta(n)$

---

### SuccintBitVector(const std::vector<uint8> & bits)

ビット列 `bits` で初期化します。  

**計算量**

- $\Theta(\|$`bits`$\|)$

---

<br>

# メンバ関数

以下、長さ $N$ のビット列 $B_0, B_1, \ldots, B_{N-1}$ を対象とします。  

---

### void build()

事前計算を行います。
`rank` 、`select` を呼ぶ前に必ず呼んでください。  

**計算量**

- 時間: $\Theta(N)$
- 空間: $N + o(N)$ \[bit\]

---

### size_t size()

ビット列の長さ $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void set(size_t i)

$B_i$ を $1$ に変更します。
`build` の後に呼んだ場合のその後の動作は未定義です。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### void reset(size_t i)

$B_i$ を $0$ に変更します。
`build` の後に呼んだ場合のその後の動作は未定義です。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### bool access(size_t i)

$B_i$ を返します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

### uint32_t rank1(size_t i)

$B_0, \ldots, B_{i-1}$ に存在する $1$ の個数を返します。
ただし、$i = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\Theta(1)$

---

### uint32_t rank0(size_t i)

$B_0, \ldots, B_{i-1}$ に存在する $0$ の個数を返します。
ただし、$i = 0$ のときは $0$ を返します。  

**制約**

- $0 \leq i \leq N$

**計算量**

- $\Theta(1)$

---

### size_t select1(size_t k)

先頭から $k$ 番目の $1$ の位置を 1-indexed で返します。
$k = 0$ または、そのような位置が存在しなければ $N + 1$ を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log{N})$

---

### size_t select0(size_t k)

先頭から $k$ 番目の $0$ の位置を 1-indexed で返します。
$k = 0$ または、そのような位置が存在しなければ $N + 1$ を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\mathcal{O}(\log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/SuccintBitVector.hpp"
using namespace std;

int main() {
	SuccintBitVector bit(10);
	bit.set(0);
	bit.set(4);
	bit.set(6);
	bit.set(8);
	bit.set(9);
	
	cout << bit.access(9) << endl; // 1
	bit.reset(9);
	cout << bit.access(9) << endl; // 0
	bit.set(9);
	
	for (int i = 0; i < 10; ++i) cout << bit.access(i); cout << endl; // 1000101011
	
	bit.build(); // 忘れずに呼ぶ
	
	/*
		i = 0 : rank0 = 0, rank1 = 0
		i = 1 : rank0 = 0, rank1 = 1
		i = 2 : rank0 = 1, rank1 = 1
		i = 3 : rank0 = 2, rank1 = 1
		i = 4 : rank0 = 3, rank1 = 1
		i = 5 : rank0 = 3, rank1 = 2
		i = 6 : rank0 = 4, rank1 = 2
		i = 7 : rank0 = 4, rank1 = 3
		i = 8 : rank0 = 5, rank1 = 3
		i = 9 : rank0 = 5, rank1 = 4
		i = 10 : rank0 = 5, rank1 = 5
	*/
	for (int i = 0; i <= 10; ++i) cout << "i = " << i << " : rank0 = " << bit.rank0(i) << ", rank1 = " << bit.rank1(i) << endl;
	
	/*
		i = 0 : select0 = 0, select1 = 0
		i = 1 : select0 = 2, select1 = 1
		i = 2 : select0 = 3, select1 = 5
		i = 3 : select0 = 4, select1 = 7
		i = 4 : select0 = 6, select1 = 9
		i = 5 : select0 = 8, select1 = 10
		i = 6 : select0 = 11, select1 = 11
	*/
	for (int i = 0; i <= 6; ++i) cout << "i = " << i << " : select0 = " << bit.select0(i) << ", select1 = " << bit.select1(i) << endl;
}
```

<br>

# TODO

TODO: $\Theta(1)$ `rank` を調べる  

<br>

# 参考

2020/09/03: [https://misteer.hatenablog.com/entry/bit-vector](https://misteer.hatenablog.com/entry/bit-vector)  
2020/09/03: [https://miti-7.hatenablog.com/entry/2018/04/15/155638](https://miti-7.hatenablog.com/entry/2018/04/15/155638)  

<br>