---
title: Sum of Floor of Linear
documentation_of: //Mathematics/sum_of_floor_of_linear.hpp
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