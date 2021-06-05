---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/sum_of_floor_of_linear.test.cpp
    title: Test/sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp
  bundledCode: "#line 1 \"Mathematics/sum_of_floor_of_linear.hpp\"\n\n\n\r\n#include\
    \ <utility>\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\n/**\r\n * @brief\
    \ https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp\r\n\
    \ */\r\nnamespace tk {\r\ntemplate<typename T>\r\nT sum_of_floor_of_linear(T n,\
    \ T m, T a, T b) {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(n\
    \ >= 0);\r\n\tassert(m > 0);\r\n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif\
    \ (n == 0) return 0;\r\n\tconst T qa = a / m, qb = b / m;\r\n\tT res = n * (n\
    \ - 1) / 2 * qa + n * qb;\r\n\ta -= qa * m;\r\n\tb -= qb * m;\r\n\tif (a == 0)\
    \ return res;\r\n\tconst T q = (a * n + b) / m, r = (a * n + b) - q * m;\r\n\t\
    return res + sum_of_floor_of_linear(q, a, m, r);\r\n}\r\n} // namespace tk\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP\r\n#define INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP\r\
    \n\r\n#include <utility>\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/sum_of_floor_of_linear.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nT sum_of_floor_of_linear(T\
    \ n, T m, T a, T b) {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(n\
    \ >= 0);\r\n\tassert(m > 0);\r\n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif\
    \ (n == 0) return 0;\r\n\tconst T qa = a / m, qb = b / m;\r\n\tT res = n * (n\
    \ - 1) / 2 * qa + n * qb;\r\n\ta -= qa * m;\r\n\tb -= qb * m;\r\n\tif (a == 0)\
    \ return res;\r\n\tconst T q = (a * n + b) / m, r = (a * n + b) - q * m;\r\n\t\
    return res + sum_of_floor_of_linear(q, a, m, r);\r\n}\r\n} // namespace tk\r\n\
    \r\n#endif // INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/sum_of_floor_of_linear.hpp
  requiredBy: []
  timestamp: '2021-04-13 10:29:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/sum_of_floor_of_linear.test.cpp
documentation_of: Mathematics/sum_of_floor_of_linear.hpp
layout: document
title: Sum of Floor of Linear
---

# 概要

整数 $N, M, A, B$ に対して $\sum_{i=0}^{N-1} floor((A \times i + B) / M)$ を求めます。  

<br>

# 関数

### T sum_of_floor_of_linear(T N, T M, T A, T B)

$\sum_{i=0}^{N-1} floor((A \times i + B) / M)$ を返します。
ただし、 $N = 0$ のときは $0$ を返します。  
ここで $floor(x)$ は $x$ を超えない最大の整数を表します。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- 式の値が `T` で表現可能 ( $(AN^2+B)/M$ が `T` で表現可能なら問題無し)
- $0 \leq N, A, B$
- $0 < M$

**計算量**

- $\mathcal{O}(\log{\min(M, A)})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/sum_of_floor_of_linear.hpp"
using namespace std;

int main() {
	// n, m, a, b
	cout << tk::sum_of_floor_of_linear(5, 4, 2, 3) << endl; // sum[3/4, 5/4, 7/4, 9/4, 11/4] = 6
	cout << tk::sum_of_floor_of_linear(3, 2, 7, 4) << endl; // sum[4/2, 11/2, 18/2] = 16
	cout << tk::sum_of_floor_of_linear<long long>(100000, 1, 1, 0) << endl; // sum[...] = 4999950000
	cout << tk::sum_of_floor_of_linear(0, 1, 1, 100) << endl; // sum[] = 0
	cout << tk::sum_of_floor_of_linear(100, 3, 0, 100) << endl; // sum[33, ..., 33] = 3300
}
```

<br>

# 参考

2021/04/13: [https://atcoder.jp/contests/practice2/editorial/579](https://atcoder.jp/contests/practice2/editorial/579)  
2020/09/11: [https://twitter.com/kyopro_friends/status/1304063876019793921?s=20](https://twitter.com/kyopro_friends/status/1304063876019793921?s=20)  
2020/09/10: [https://qiita.com/HNJ/items/564f15316719209df73c](https://qiita.com/HNJ/items/564f15316719209df73c)  

<br>