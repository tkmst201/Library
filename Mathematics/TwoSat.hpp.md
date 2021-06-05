---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/TwoSat.test.cpp
    title: Test/TwoSat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp
  bundledCode: "#line 1 \"Mathematics/TwoSat.hpp\"\n\n\n\r\n#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp\r\
    \n */\r\nstruct StronglyConnectedComponents {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<int> rank_;\r\n\tstd::vector<std::vector<int>>\
    \ rank_list_;\r\n\t\r\npublic:\r\n\texplicit StronglyConnectedComponents(const\
    \ Graph & g) : n(g.size()) {\r\n\t\tGraph rg(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\t\tfor (int j : g[i]) {\r\n\t\t\t\tassert(0 <= j && j < n);\r\n\
    \t\t\t\trg[j].emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool> visited(n,\
    \ false);\r\n\t\tstd::vector<int> num;\r\n\t\tauto dfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\tfor (int v : g[u]) if (!visited[v])\
    \ self(self, v);\r\n\t\t\tnum.emplace_back(u);\r\n\t\t};\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) if (!visited[i]) dfs(dfs, i);\r\n\t\tint cnt = 0;\r\n\t\tvisited.assign(n,\
    \ false);\r\n\t\trank_.assign(n, -1);\r\n\t\tauto rdfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank_[u] = cnt;\r\n\t\t\tfor\
    \ (int v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\tfor (int i\
    \ = n - 1; i >= 0; --i) if (!visited[num[i]]) rdfs(rdfs, num[i]), ++cnt;\r\n\t\
    \trank_list_.assign(cnt, {});\r\n\t\tfor (int i = 0; i < n; ++i) rank_list_[rank_[i]].emplace_back(i);\r\
    \n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\
    \tint scc_size() const noexcept {\r\n\t\treturn rank_list_.size();\r\n\t}\r\n\t\
    \r\n\tint scc_size(int k) const noexcept {\r\n\t\tassert(0 <= k && k < scc_size());\r\
    \n\t\treturn rank_list_[k].size();\r\n\t}\r\n\t\r\n\tint rank(int u) const noexcept\
    \ {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn rank_[u];\r\n\t}\r\n\t\r\
    \n\tconst std::vector<int> & rank_list(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < scc_size());\r\n\t\treturn rank_list_[k];\r\n\t}\r\n\t\r\n\tGraph\
    \ get_graph(const Graph & g) const {\r\n\t\tGraph res(scc_size());\r\n\t\tfor\
    \ (int i = 0; i < scc_size(); ++i) {\r\n\t\t\tfor (int j : rank_list_[i]) for\
    \ (int v : g[j]) if (rank(v) != i) res[i].emplace_back(rank(v));\r\n\t\t\tstd::sort(begin(res[i]),\
    \ end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Mathematics/TwoSat.hpp\"\
    \n\r\n#line 8 \"Mathematics/TwoSat.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp\r\
    \n */\r\nstruct TwoSat {\r\n\tusing scc_type = StronglyConnectedComponents;\r\n\
    \t\r\nprivate:\r\n\tint n;\r\n\ttypename scc_type::Graph g;\r\n\tstd::vector<bool>\
    \ ans;\r\n\tbool satisfiability = false;\r\n\t\r\npublic:\r\n\texplicit TwoSat(int\
    \ n) : n(n), g(2 * n) {}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid add_clause(int x, bool xb, int y, bool yb) {\r\n\t\
    \tassert(0 <= x && x < n);\r\n\t\tassert(0 <= y && y < n);\r\n\t\tg[x + (xb ?\
    \ n : 0)].emplace_back(y + (yb ? 0 : n));\r\n\t\tg[y + (yb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tvoid add_clause(int\
    \ x, bool xb) {\r\n\t\tassert(0 <= x && x < n);\r\n\t\tg[x + (xb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tbool build()\
    \ {\r\n\t\tscc_type scc(g);\r\n\t\tans.assign(n, false);\r\n\t\tsatisfiability\
    \ = false;\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (scc.rank(i) == scc.rank(i\
    \ + n)) return false;\r\n\t\t\tif (scc.rank(i) > scc.rank(i + n)) ans[i] = true;\r\
    \n\t\t}\r\n\t\tsatisfiability = true;\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\tconst\
    \ std::vector<bool> & ans_list() const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\treturn ans;\r\n\t}\r\n\t\r\n\tbool get(int i) const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\tassert(0 <= i && i < n);\r\n\t\treturn ans[i];\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_TWO_SAT_HPP\r\n#define INCLUDE_GUARD_TWO_SAT_HPP\r\n\
    \r\n#include \"GraphTheory/StronglyConnectedComponents.hpp\"\r\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp\r\
    \n */\r\nstruct TwoSat {\r\n\tusing scc_type = StronglyConnectedComponents;\r\n\
    \t\r\nprivate:\r\n\tint n;\r\n\ttypename scc_type::Graph g;\r\n\tstd::vector<bool>\
    \ ans;\r\n\tbool satisfiability = false;\r\n\t\r\npublic:\r\n\texplicit TwoSat(int\
    \ n) : n(n), g(2 * n) {}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid add_clause(int x, bool xb, int y, bool yb) {\r\n\t\
    \tassert(0 <= x && x < n);\r\n\t\tassert(0 <= y && y < n);\r\n\t\tg[x + (xb ?\
    \ n : 0)].emplace_back(y + (yb ? 0 : n));\r\n\t\tg[y + (yb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tvoid add_clause(int\
    \ x, bool xb) {\r\n\t\tassert(0 <= x && x < n);\r\n\t\tg[x + (xb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tbool build()\
    \ {\r\n\t\tscc_type scc(g);\r\n\t\tans.assign(n, false);\r\n\t\tsatisfiability\
    \ = false;\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (scc.rank(i) == scc.rank(i\
    \ + n)) return false;\r\n\t\t\tif (scc.rank(i) > scc.rank(i + n)) ans[i] = true;\r\
    \n\t\t}\r\n\t\tsatisfiability = true;\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\tconst\
    \ std::vector<bool> & ans_list() const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\treturn ans;\r\n\t}\r\n\t\r\n\tbool get(int i) const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\tassert(0 <= i && i < n);\r\n\t\treturn ans[i];\r\n\t}\r\n};\r\n\r\n#endif\
    \ // INCLUDE_GUARD_TWO_SAT_HPP"
  dependsOn:
  - GraphTheory/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: Mathematics/TwoSat.hpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/TwoSat.test.cpp
documentation_of: Mathematics/TwoSat.hpp
layout: document
title: 2-SAT
---

# 概要

論理変数 $x_0, \ldots, x_{N-1}$ に対して $(x_0 \lor x_1) \land (\lnot x_0 \lor x_2) \land (x_3 \lor x_0) \land (x_5) \land (x_2 \lor x_{N-1})$ のような形式の論理式を満たす真偽の組み合わせを求めます。  
より具体的には、クロージャ(括弧) の積で表されていて各クロージャ内は 2 つ以下のリテラルの和で表されているような論理式を解きます。  

- `TwoSat(int n)`
	- $\Theta(n)$ $n$ 個の論理変数で初期化
- `int size()`
	- $\Theta(1)$ 論理変数の個数 $N$ を返す
- `void add_clause(int x, bool xb, int y, bool yb)`
	- ならし $\Theta(1)$ クロージャ $x = xb \lor y = yb$ を追加
- `void add_clause(int x, bool xb)`
	- ならし $\Theta(1)$ クロージャ $x = xb$ を追加
- `bool build()`
	- $\Theta(N)$ 論理式を満たすような論理値の割り当てを求める
- `const vector<bool> & ans_list`
	- $\Theta(1)$ 論理式を満たすような論理値の割り当てを返す
- `bool get(int i)`
	- $\Theta(1)$ 論理式を満たすような論理値の割り当てで $x_i$ の真偽値を返す

<br>

# コンストラクタ

### TwoSat(int n)

$n$ 個の論理変数で初期化します。  

**制約**

- $0 \leq n$

**計算量**

- $\Theta(n)$

---

<br>

# メンバ関数

以下、論理変数の個数を $N$ とし、それぞれ $x_0, \ldots, x_{N-1}$ とします。  

---

### int size()

論理変数の個数 $N$ を返します。

**計算量**

- $\Theta(1)$

---

### void add_clause(int x, bool xb, int y, bool yb)

クロージャ $x = xb \lor y = yb$ を追加します。  

**制約**

- $0 \leq x, y < N$
- $xb, yb$ はそれぞれ $true, false$ のいずれか

**計算量**

- ならし $\Theta(1)$

---

### void add_clause(int x, bool xb)

クロージャ $x = xb$ を追加します。  

**制約**

- $0 \leq x < N$
- $xb$ は $true, false$ のいずれか

**計算量**

- ならし $\Theta(1)$

---

### bool build()

論理式を満たすような論理値の割り当てを求めます。
割り当てることができた場合は $true$ を、割り当てが存在しない場合は $false$ を返します。  

**計算量**

- $\Theta(N)$

### const vector<bool> & ans_list

論理式を満たすような論理値の割り当てを返します。  
$[i] := x_i$ の論理値

**制約**

- 論理式を満たすような論理値の割り当てが存在する

**計算量**

- $\Theta(1)$

### bool get(int i)

論理式を満たすような論理値の割り当てで $x_i$ の真偽値を返します。  

**制約**

- 論理式を満たすような論理値の割り当てが存在する
- $0 \leq i < N$

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/TwoSat.hpp"
using namespace std;

int main() {
	TwoSat sat(5);
	cout << "sat.size() = " << sat.size() << endl; // 5
	sat.add_clause(0, true, 1, false);
	sat.add_clause(1, false, 2, false);
	
	sat.build();
	// true true false true true
	for (bool b : sat.ans_list()) cout << boolalpha << b << " "; cout << '\n';
	for (int i = 0; i < sat.size(); ++i) cout << boolalpha << sat.get(i) << " "; cout << '\n';
	
	sat.add_clause(0, false);
	sat.add_clause(1, false);
	sat.build();
	// false false false true true
	for (bool b : sat.ans_list()) cout << boolalpha << b << " "; cout << '\n';
	
	sat.add_clause(0, true, 1, true);
	bool f = sat.build();
	cout << boolalpha << f << endl; // false
}
```

<br>

# 参考

2021/03/18: [https://noshi91.hatenablog.com/entry/2019/10/03/184812](https://noshi91.hatenablog.com/entry/2019/10/03/184812)  
2021/03/18: [https://www.slideshare.net/yoshiokatsuneo/2sat-72370606](https://www.slideshare.net/yoshiokatsuneo/2sat-72370606)  
2020/09/10: [AC Library](https://github.com/atcoder/ac-library)  

<br>