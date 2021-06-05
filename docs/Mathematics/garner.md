---
title: Garner (連立一次合同式 mod M)
documentation_of: //Mathematics/garner.hpp
---

# 概要

連立一次合同式の解 $\pmod M$ を求めます。  
似たような問題として、[中国剰余定理](https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp)があります。  

<br>

# 関数

### bool T pre_garner(const vector&lt;T&gt; & b, const vector&lt;T&gt; & m)

連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

$$\vdots$$

$$x \equiv b_K \pmod{m_K}$$

と同値な連立一次合同式であって、$m_i, m_j$ が互いに素、$0 \leq b_i < m_i$ となるように書き換えます。  
この合同式に解が存在するならば $true$ を、存在しないのならば $false$ を返します。  
連立一次合同式の解の存在条件や一意性については [中国剰余定理](https://tkmst201.github.io/Library/Mathematics/chinese_remainder.hpp)を参照してください。  

**制約**

- `T` は `int`, `long long`
- $0 < m_i$

**計算量**

- $\mathcal{O}(K^2 \log{\max{m_i}} \log{\log{\max{m_i}}}))$

---

### template&lt;typename T, typename U&gt; T garner(const vector&lt;T&gt; & b, const vector&lt;T&gt; & m, const T M)

$m_i, m_j (i \neq j)$ が互いに素な連立一次合同式

$$x \equiv b_1 \pmod{m_1}$$

$$x \equiv b_2 \pmod{m_2}$$

$$\vdots$$

$$x \equiv b_K \pmod{m_K}$$

の解 $x \pmod lcm(m_1, m_2, \ldots, m_K)$ に対して、 $x \pmod M$ を返します。  
内部の計算で使用する型を `U` に指定してください。  

**制約**

- `T`, `U` は `int` または `long long`
- $\max(m_i, M)^2$ が `U` で表現可能
- $0 < m_i, M$

**計算量**

- $\mathcal{O}(K(K + \log{\max{m_i}}))$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/garner.hpp"
using namespace std;

int main() {
	// 17
	cout << "garner({3, 6}, {7, 11}, 10000) = " << tk::garner<int, int>({3, 6}, {7, 11}, 10000) << endl;
	// 2
	cout << "garner({3, 6}, {7, 11}, 5) = " << tk::garner<int, int>({3, 6}, {7, 11}, 5) << endl;
	
	vector<int> b{2, 3, 4}, m{10, 20, 30};
	if (!tk::pre_garner(b, m)) cout << "no" << endl; // no
	
	b = {2, 12, 22};
	if (tk::pre_garner(b, m)) {
		for (int i = 0; i < 3; ++i) cout << "b[i] = " << b[i] << ", m[i] = " << m[i] << endl;
		// 52
		cout << "garner(b, m, 1000000) = " << tk::garner<int, long long>(b, m, 1000000) << endl;
		// 2
		cout << "garner(b, m, 10) = " << tk::garner<int, int>(b, m, 10) << endl;
	}
}
```

<br>

# 参考

2020/05/05: [https://qiita.com/drken/items/ae02240cd1f8edfc86fd](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)  

<br>