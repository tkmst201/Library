---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/PotentializedUnionFind.test.cpp
    title: Test/PotentializedUnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp
  bundledCode: "#line 1 \"DataStructure/PotentializedUnionFind.hpp\"\n\n\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n#include <functional>\r\n#include <utility>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PotentializedUnionFind {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\tusing G = std::function<value_type (const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tG g;\r\n\tstd::vector<int>\
    \ dat;\r\n\tstd::vector<value_type> val;\r\n\t\r\npublic:\r\n\tPotentializedUnionFind(size_type\
    \ n, const_reference id_elem, const F & f, const G & g = [](const_reference x)\
    \ { return -x; })\r\n\t\t: n(n), id_elem(id_elem), f(f), g(g), dat(n, -1), val(n,\
    \ id_elem) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type find(size_type\
    \ x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return x;\r\n\t\t\
    const size_type p = dat[x];\r\n\t\tdat[x] = find(p);\r\n\t\tval[x] = f(val[x],\
    \ val[p]);\r\n\t\treturn dat[x];\r\n\t}\r\n\t\r\n\tvoid merge(size_type x, size_type\
    \ y, const_reference w) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\
    \n\t\tsize_type rx = find(x), ry = find(y);\r\n\t\tassert(rx != ry);\r\n\t\tvalue_type\
    \ v = f(val[y], g(f(val[x], w)));\r\n\t\tif (dat[rx] < dat[ry]) {\r\n\t\t\tstd::swap(rx,\
    \ ry);\r\n\t\t\tv = g(v);\r\n\t\t}\r\n\t\tdat[ry] += dat[rx];\r\n\t\tdat[rx] =\
    \ ry;\r\n\t\tval[rx] = std::move(v);\r\n\t}\r\n\t\r\n\tvalue_type diff(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tconst size_type rx = find(x), ry = find(y);\r\n\t\tassert(rx == ry);\r\n\t\t\
    return f(val[y], g(val[x]));\r\n\t}\r\n\t\r\n\tbool issame(size_type x, size_type\
    \ y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x)\
    \ == find(y);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP\r\n#define INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP\r\
    \n\r\n#include <cassert>\r\n#include <vector>\r\n#include <functional>\r\n#include\
    \ <utility>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/PotentializedUnionFind.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct PotentializedUnionFind {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\tusing G = std::function<value_type (const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tG g;\r\n\tstd::vector<int>\
    \ dat;\r\n\tstd::vector<value_type> val;\r\n\t\r\npublic:\r\n\tPotentializedUnionFind(size_type\
    \ n, const_reference id_elem, const F & f, const G & g = [](const_reference x)\
    \ { return -x; })\r\n\t\t: n(n), id_elem(id_elem), f(f), g(g), dat(n, -1), val(n,\
    \ id_elem) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type find(size_type\
    \ x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return x;\r\n\t\t\
    const size_type p = dat[x];\r\n\t\tdat[x] = find(p);\r\n\t\tval[x] = f(val[x],\
    \ val[p]);\r\n\t\treturn dat[x];\r\n\t}\r\n\t\r\n\tvoid merge(size_type x, size_type\
    \ y, const_reference w) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\
    \n\t\tsize_type rx = find(x), ry = find(y);\r\n\t\tassert(rx != ry);\r\n\t\tvalue_type\
    \ v = f(val[y], g(f(val[x], w)));\r\n\t\tif (dat[rx] < dat[ry]) {\r\n\t\t\tstd::swap(rx,\
    \ ry);\r\n\t\t\tv = g(v);\r\n\t\t}\r\n\t\tdat[ry] += dat[rx];\r\n\t\tdat[rx] =\
    \ ry;\r\n\t\tval[rx] = std::move(v);\r\n\t}\r\n\t\r\n\tvalue_type diff(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tconst size_type rx = find(x), ry = find(y);\r\n\t\tassert(rx == ry);\r\n\t\t\
    return f(val[y], g(val[x]));\r\n\t}\r\n\t\r\n\tbool issame(size_type x, size_type\
    \ y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x)\
    \ == find(y);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_POTENTIALIZED_UNION_FIND_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PotentializedUnionFind.hpp
  requiredBy: []
  timestamp: '2021-03-09 20:19:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/PotentializedUnionFind.test.cpp
documentation_of: DataStructure/PotentializedUnionFind.hpp
layout: document
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
---

# 概要

差分制約の一次方程式を効率的に解くことができるデータ構造です。  
変数が $N$ 個あるとき、差分制約の追加や差分の計算をならし $\Theta(\alpha(N))$ ( $\alpha(N)$ はアッカーマン関数の逆関数 ) で計算できます。  
[Union Find](https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp) の機能強化版です。  

- `PotentializedUnionFind(size_t n, const T & id_elem, const F & f, const F & g = [];(const_refrence x) { return -x; })`
	- $\Theta(n)$ $n$ 変数で初期化
- `:warning: size_t size(size_t x)`
	- ならし $\Theta(\alpha(N))$ 変数 $x$ と同じグループに含まれる変数の個数を返す
- `size_t find(size_t x)`
	- ならし $\Theta(\alpha(N))$ 変数 $x$ が属するグループの代表の変数を返す
- `void merge(size_t x, size_t y, const T & w)`
	- ならし $\Theta(\alpha(N))$ 変数 $x, y$ それぞれが属するグループを併合し、差分制約 $x + w = y$ を追加
- `T diff(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ これまでに追加された差分制約を満たすような変数 $x, y$ の値に対して $y - x$ を返す
- `bool issame(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 変数 $x, y$ が同じグループに属しているか判定

<br>

# コンストラクタ

### PotentializedUnionFind(size_t n, const T & id_elem, const F & f, const F & g = &#91;&#93;(const_refrence x) { return -x; })

$n$ 変数で初期化します。
はじめ、すべての変数は自身のみからなるグループに属しています。  

**制約**

- `f` の単位元は `id_elem`
- `g` は逆元を返す
- $(T, f,$ `id_elem`, `g`$)$ はアーベル群

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、変数の個数を $N$ とします。
また、アッカーマン関数の逆関数を $\alpha(N)$ と表します。  

---

### :warning: size_t size(size_t x)

変数 $x$ と同じグループに含まれる変数の個数を返します。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### size_t find(size_t x)

変数 $x$ が属するグループの代表の変数を返します。
`unite` を行うことにより代表の変数が変化する場合があります。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### void merge(size_t x, size_t y, const T & w)

変数 $x, y$ それぞれが属するグループを併合し、差分制約 $x + w = y$ を追加します。  

**制約**

- $0 \leq x, y < N$
- $x, y$ は同じグループに属さない

**計算量**

- ならし $\Theta(\alpha(N))$

---

### T diff(size_t x, size_t y)

これまでに追加された差分制約を満たすような変数 $x, y$ の値に対して $y - x$ を返します。  

**制約**

- $0 \leq x, y < N$
- $x, y$ は同じグループに属する

**計算量**

- ならし $\Theta(\alpha(N))$

---

### bool issame(size_t x, size_t y)

変数 $x, y$ が同じグループに属しているか判定します。
同じグループに属しているなら $true$ 、違うグループに属しているなら $false$ を返します。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/PotentializedUnionFind.hpp"
using namespace std;

int main() {
	PotentializedUnionFind<int> puf(3, 0, [](auto x, auto y) { return x + y; });
	puf.merge(1, 0, 5); // x0 - x1 = 5
	cout << "diff(1, 0) = " << puf.diff(1, 0) << endl; // 5
	puf.merge(1, 2, 7); // x2 - x1 = 7
	cout << "diff(2, 1) = " << puf.diff(2, 1) << endl; // -7
	
	// => x0 - x2 = -2
	cout << "diff(2, 0) = " << puf.diff(2, 0) << endl;
	// => x0 - x2 = 2
	cout << "diff(0, 2) = " << puf.diff(0, 2) << endl;
	
	
	PotentializedUnionFind<int> pufxor(5, 0, [](auto x, auto y) { return x ^ y; }, [](auto x) { return x; });
	pufxor.merge(1, 0, 1); // x1 ^ x0 = 1
	pufxor.merge(1, 2, 2); // x2 ^ x1 = 2
	
	// => x2 ^ x0 = 3
	cout << "diff(2, 0) = " << pufxor.diff(2, 0) << endl;
	// => x0 ^ x2 = 3
	cout << "diff(0, 2) = " << pufxor.diff(2, 0) << endl;
	
	for (int i = 0; i < 5; ++i) cout << pufxor.size(i) << " \n"[i + 1 == 5]; // 3 3 3 1 1
	cout << "issame(0, 1) = " << boolalpha << pufxor.issame(0, 1) << endl; // true
	cout << "issame(2, 3) = " << boolalpha << pufxor.issame(2, 3) << endl; // false
	cout << "find(2) = " << pufxor.find(2) << endl; // 0 or 1 or 2
	cout << "find(4) = " << pufxor.find(4) << endl; // 4
}
```

<br>

# TODO

TODO: `size` の test を追加する  

# 参考

2021/03/09: [http://sigma425.hatenablog.com/entry/2015/12/07/185047](http://sigma425.hatenablog.com/entry/2015/12/07/185047)  
2021/03/09: [https://qiita.com/drken/items/cce6fc5c579051e64fab](https://qiita.com/drken/items/cce6fc5c579051e64fab)  

<br>