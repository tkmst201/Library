---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/UnionFind.test.cpp
    title: Test/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp
  bundledCode: "#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <utility>\r\n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp\r\
    \n */\r\nstruct UnionFind {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tstd::vector<int> dat;\r\n\t\r\npublic:\r\n\texplicit UnionFind(size_type\
    \ n) : n(n), dat(n, -1) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\
    \n\t\tassert(x < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type\
    \ find(size_type x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return\
    \ x;\r\n\t\treturn dat[x] = find(dat[x]);\r\n\t}\r\n\t\r\n\tvoid unite(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y) return;\r\n\t\tif (dat[x]\
    \ < dat[y]) std::swap(x, y);\r\n\t\tdat[y] += dat[x];\r\n\t\tdat[x] = y;\r\n\t\
    }\r\n\t\r\n\tbool issame(size_type x, size_type y) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\
    \n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_UNION_FIND_HPP\r\n#define INCLUDE_GUARD_UNION_FIND_HPP\r\
    \n\r\n#include <vector>\r\n#include <utility>\r\n#include <cassert>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/UnionFind.hpp\r\n\
    \ */\r\nstruct UnionFind {\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type n;\r\n\tstd::vector<int> dat;\r\n\t\r\npublic:\r\n\texplicit UnionFind(size_type\
    \ n) : n(n), dat(n, -1) {}\r\n\t\r\n\tsize_type size(size_type x) noexcept {\r\
    \n\t\tassert(x < n);\r\n\t\treturn -dat[find(x)];\r\n\t}\r\n\t\r\n\tsize_type\
    \ find(size_type x) noexcept {\r\n\t\tassert(x < n);\r\n\t\tif (dat[x] < 0) return\
    \ x;\r\n\t\treturn dat[x] = find(dat[x]);\r\n\t}\r\n\t\r\n\tvoid unite(size_type\
    \ x, size_type y) noexcept {\r\n\t\tassert(x < n);\r\n\t\tassert(y < n);\r\n\t\
    \tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y) return;\r\n\t\tif (dat[x]\
    \ < dat[y]) std::swap(x, y);\r\n\t\tdat[y] += dat[x];\r\n\t\tdat[x] = y;\r\n\t\
    }\r\n\t\r\n\tbool issame(size_type x, size_type y) noexcept {\r\n\t\tassert(x\
    \ < n);\r\n\t\tassert(y < n);\r\n\t\treturn find(x) == find(y);\r\n\t}\r\n};\r\
    \n\r\n#endif // INCLUDE_GUARD_UNION_FIND_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2021-03-09 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/UnionFind.test.cpp
documentation_of: DataStructure/UnionFind.hpp
layout: document
title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020 (Union-Find)"
---

# 概要

素集合の族を扱うデータ構造です。  
扱う要素数を $N$ とすると、2 つの集合の併合や集合に含まれる要素数の取得、ある要素が含まれる集合の取得を、ならし $\Theta(\alpha(N))$ で行うことができます。
ここで $\alpha(N)$ はアッカーマン関数の逆関数を表します。  

- `UnionFind(size_t n)`
	- $\Theta(n)$ 要素数 $n$ で初期化
- `size_t size(size_t x)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合の要素数を返す。
- `size_t find(size_t x)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合の代表元を返す
- `void unite(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 要素 $x$ が属する集合と要素 $y$ が属する集合を併合
- `bool issame(size_t x, size_t y)`
	- ならし $\Theta(\alpha(N))$ 要素 $x, y$ が同じ集合に属しているか判定

<br>

# コンストラクタ

### UnionFind(size_t n)

要素数 $n$ で初期化します。
はじめ、すべての要素は自身のみからなる集合に属しています。  

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、要素数を $N$ とします。
また、アッカーマン関数の逆関数を $\alpha(N)$ と表します。  

---

### :warning: size_t size(size_t x)

要素 $x$ が属する集合の要素数を返します。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### size_t find(size_t x)

要素 $x$ が属する集合の代表元を返します。
`unite` を行うことにより代表元が変化する場合があります。  

**制約**

- $0 \leq x < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### void unite(size_t x, size_t y)

要素 $x$ が属する集合と要素 $y$ が属する集合を併合します。
要素 $x, y$ が同じ集合に属していた場合は何も行いません。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

### bool issame(size_t x, size_t y)

要素 $x, y$ が同じ集合に属しているか判定します。
同じ集合に属しているなら $true$ 、違う集合に属しているなら $false$ を返します。  

**制約**

- $0 \leq x, y < N$

**計算量**

- ならし $\Theta(\alpha(N))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/UnionFind.hpp"
using namespace std;

int main() {
	constexpr int N = 5;
	UnionFind uf(N);
	
	cout << "representative: " << uf.find(0) << ", " << uf.find(1) << endl; // 0, 1
	cout << "size: " << uf.size(0) << ", " << uf.size(1) << endl; // 1, 1
	cout << boolalpha << "issame(0, 1): " << uf.issame(0, 1) << endl; // false
	uf.unite(0, 1);
	cout << "representative: " << uf.find(0) << ", " << uf.find(1) << endl; // 0 0 (or 1 1)
	cout << "size: " << uf.size(0) << ", " << uf.size(1) << endl; // 2, 2
	cout << boolalpha << "issame(0, 1): " << uf.issame(0, 1) << endl; // true
	
	uf.unite(2, 3);
	uf.unite(2, 4);
	cout << "size(0): " << uf.size(0) << endl; // 2
	cout << "size(2): " << uf.size(2) << endl; // 3
	uf.unite(1, 3);
	cout << "size(0) = size(4): " << uf.size(0) << ", " << uf.size(4) << endl; // 5, 5
}
```

<br>

# TODO

TODO: `size` の test を追加する  

# 参考

2020/04/22: [https://en.wikipedia.org/wiki/Disjoint-set_data_structure](https://qiita.com/kopricky/items/3e5847ab1451fe990367)  
2020/04/22: [https://qiita.com/kopricky/items/3e5847ab1451fe990367](https://qiita.com/kopricky/items/3e5847ab1451fe990367)  

<br>