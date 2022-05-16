---
title: Level Ancestor Problem
documentation_of: //GraphTheory/LevelAncestor.hpp
---

# 概要

`Level Ancestor Problem` とは次のような問題のことです。  

> 根付き木 $T$ が与えられます。以下のクエリ `LA(v, k)` に答えてください。  
> - `LA(v, k)` : 頂点 $v$ の先祖( $v$ 自身も含む) であって、根からの深さが $k$ [0-index] であるような頂点

`UP(v, k)` を "頂点 $v$ から $k$ 回根方向に上ったところにある頂点" と定義すると、各頂点の深さが分かっている場合 `LA` と `UP` は互いに変形可能です。  

このライブラリは、頂点数が $N$ の木に対して $O(N)$ 時間/空間の事前計算により、オンラインでクエリ $\Theta(1)$ 時間を達成します。  
The Macro-Micro-Tree Algorithm を使用しています。  

- `LevelAncestor(const Graph & g, int root = 0)`
	- 時間/空間 $\mathcal{O}(N)$ 根 `root` の根付き木 $g$ (頂点数 $N$) で初期化
- `int size()`
	- $\Theta(1)$ 木の頂点数 $N$ を返す
- `int depth(int v)`
	- $\Theta(1)$ 頂点 $v$ の深さ(根からの距離) を返す
- `int find(int v, int k)`
	- $\Theta(1)$ `LA(v, k)` を返す
- `int up(int v, int k)`
	- $\Theta(1)$ `UP(v, k)` を返す

<br>

# コンストラクタ

Macro-Tree と Micro-Tree の境界を $S$ ( Micro-Tree の頂点数は $S$ 未満) とし、$S$ 種類の値を表すことのできるビット数を $B$ としています。  
よく使いそうな $(S, B)$ の組み合わせを載せておきます。  

- $N < 2^{31}$ のとき $(8, 3)$
- $N < 2^{20}$ のとき $(5, 3)$
- $N < 2^{16}$ のとき $(4, 2)$

**制約**

- $2 \leq S \leq 2^B$
- $1 \le B \le 3$
- $S = floor(\log_2{N} / 4)$

---

### LevelAncestor(const Graph & g, int root = 0)

根 `root` の根付き木 $g$ (頂点数 $N$) で初期化します。  

**制約**

- $0 \leq$ `root` $< N$
- `g` は根付き木または木

**計算量**

- 時間/空間 $\mathcal{O}(N)$

---

<br>

# メンバ関数

以下、グラフの頂点数を $N$ とします。  

---

### int size()

木の頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int depth(int v)

頂点 $v$ の深さ(根からの距離) を返します。  

**制約**

- $0 \le v < N$

**計算量**

- $\Theta(1)$

---

### int find(int v, int k)

`LA(v, k)` を返します。  
つまり、頂点 $v$ の先祖であって、深さが $k$ であるような頂点を返します。  
`()` 演算子によっても呼び出すことができます。  

**制約**

- $0 \le v < N$
- $0 \le k \le$ `depth(v)`

**計算量**

- $\Theta(1)$

---

### int up(int v, int k)

`UP(v, k)` を返します。  
つまり、頂点 $v$ を根方向に $k$ 回辺を辿った後の頂点を返します。  

**制約**

- $0 \le v < N$
- $0 \le k \le$ `depth(v)`

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/LevelAncestor.hpp"
using namespace std;

int main() {
	// <S, B>: S := ceil(log_2(N)/4), B := ceil(log_2(S)) (S <= 2^B)
	// N < 2^31   ->   <8, 3>
	// N < 2^20   ->   <5, 3>
	// N < 2^16   ->   <4, 2>
	using LA = LevelAncestor<4, 2>;
	LA::Graph g(12);
	//            1
	//       2        3
	//   0      4          5
	// 6      7 8 9      10  11
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	g[0].emplace_back(6);
	g[4].emplace_back(7);
	g[4].emplace_back(8);
	g[4].emplace_back(9);
	g[5].emplace_back(10);
	g[5].emplace_back(11);
	
	g[4].emplace_back(2); // 逆辺があっても良い
	

	LA la(g, 1);
	
	cout << "size() = " << la.size() << endl; // 12
	cout << "depth(3) = " << la.depth(3) << endl; // 1
	cout << "la(7, 1) = " << la(7, 1) << endl; // 2
	cout << "la(10, 0) = " << la(10, 0) << endl; // 1
	cout << "find(5, 1) = " << la.find(5, 1) << endl; // 3
	cout << "find(10, 3) = " << la.find(10, 3) << endl; // 10
	cout << "up(5, 1) = " << la.up(5, 1) << endl; // 3
	cout << "up(11, 1) = " << la.up(11, 1) << endl; // 5
	cout << "up(2, 0) = " << la.up(2, 0) << endl; // 2
	
	// 2 0 1 1 2 2 3 3 3 3 3 3
	cout << "depth list: ";
	for (int i = 0; i < la.size(); ++i) cout << la.depth(i) << " \n"[i + 1 == la.size()];
}
```

# 解説

### long-path と ladder について

根からの距離が最長であるようなパス(long-path) に再帰的に分解します。  
$P(v)$ で頂点 $v$ が属する long-path を表すことにします。  

ここで次の重要な事実が成り立ちます。

> 任意の頂点 $v$ について、 $v$ から $k$ 回上った頂点を $u$ (存在しない場合は root で止める) とおくと、  
> $v \neq$ root なら $| P(u)$ の $u$ 以下(葉側) の頂点 $|$ $\ge |P(v)$ の $v$ 以下の頂点 $|$ + k  

これは各 long-path 上での高さみたいなものが $1$ 回根方向に上ることにより $1$ 以上増えることを表しています。  
 $k$ についての帰納法で証明ができます。ここでは $k = 1$ の場合のみ示しますが同じ議論で拡張できます。  

> 分かりやすくするために $H(v)$ を $| P(v)$ の $v$ 以下の頂点 $|$ とする。  
> $u \in P(u)$ の場合は、 $P(u) =P(v)$ より $H(u) = H(v) + 1$ であるので成り立つ。  
> $u \notin P(u)$ の場合は、$P(u) \neq P(v)$ であり $P(u)$ の方が先に long-path として選ばれているため $|H(v)| \le |H(u)|$ である。  
> $|H(v)| = |H(u)|$ と仮定すると、 $P(u)$ の $u$ より下を $P(v)$ につなぎ変えることにより long-path を今以上に長くできるため $P(u)$ が選ばれたことに矛盾する。よって $|H(v)| < |H(u)|$ である。  
> したがって $k = 1$ のとき上の事実は成り立つ。(証明終)  

この事実により、$P(u) \neq P(v)$ かつ $v \neq$ root のとき、$|P(u)| \ge |P(v)| + k$ が成り立ちます。  
これが、ダブリング(ジャンプ頂点) と ladder を組み合わせることにより $\Theta(1)$ で `LA` が求まる理由です。  
ダブリングでは $1$ 回の移動で対象 $t$ との距離 $d(v, t)$ の半分より大きい回数の頂点を上ることができます。  
移動後の頂点を $v$ とすると、  
$P(u) = P(v)$ のときは、$|P(v)| > d(v, t) / 2$  
$P(u) \neq P(v)$ のときは、上の事実より $|P(v)| > d(v, t) / 2$ です。  

頂点 $v$ から $t$ へは $d(v, t) / 2$ 回上がる必要がありますが、どちらの場合も $P(v)$ の最も根方向の頂点から $|P(v)|$ 回以下で到達することができるので ladder を用いて
$1$ 回での移動が可能です ( ladder $i$ は $P(i)$ の頂点に、
$P(i)$ より根方向にある頂点を順に $|P(i)|$ 個加えた列である)。  

### ジャンプ頂点の個数について

ジャンプ頂点 (ダブリング計算を行う頂点) は、自身を含む子孫(部分木) の頂点数が $S$ 以上となる極大の深さの頂点です。  
つまり、ある頂点 $v$ について、$v$ の子に $1$ つでも子孫が $S$ 個以上になるような頂点が存在する場合、$v$ はジャンプ頂点にはなり得ません。  
$v$ の全ての子それぞれの子孫が $S$ 子未満かつ、$v$ の子孫が $S$ 個以上になるとき $v$ はジャンプ頂点になります。  

ジャンプ頂点の個数を $x$ とすると、ジャンプ頂点の部分木にはジャンプ頂点は含まれないので、各部分木に登場する頂点は異なります。  
全ての頂点を合わせても高々 $N$ 種類であることから $x S \le N$ です。  
よってジャンプ頂点の個数は $\mathcal{O}(N / \log{N})$ となります。  

---

### 実装について

- jump[u] は頂点 $u$ の対応するジャンプ頂点を示しています。$u$ 自身がジャンプ頂点である場合、最後に -(jumpp に対応する index [1-index]) に書き換えられます。未確定のとき、$N$ が割り当てられています。
- data[u] は、処理の途中で表す内容が変化します。はじめは、頂点 $u$ の自身を含む子孫の数を表します。処理が終わると、Micro-Tree 内のノードは (Micro-Tree の形状 ID,　形状に対応した $u$ の頂点番号, Micro-Tree 内での深さ) を 1 つの int で表した値に書き換えられます。それ以外の頂点は -1 に設定されます。
- utreeid[u] は形状によらない各 Micro-Tree の固有 ID です (同じ形状の 2 つの Micro-Tree でも異なる ID を持つ) 。$u$ が Micro-Node ではない場合は -1 が入ります。
- rdict[i] は Micro-Tree での頂点番号 $x$ と対応しているもとの木 $T$ の頂点番号が utreeid 毎に連続して入っています。
- rdst[i] は rdict において、utreeid i の木の対応するデータが入っている先頭 index を表します。  
- `build_micro(int r)` は根を $r$ とする Micro-Tree の形状を求め、Micro-Tree 内のすべてのクエリを事前に計算する関数です。Micro-Tree 内の各頂点の data, jump の設定も行います。 jump[par[$r$]] が正しくセットされていることを仮定します。
- Micro-Tree 内クエリの事前計算には、Offline の Level Ancestor のアルゴリズムを用いています (定数倍高速化になっているかは分からない)。  

---

<br>

# 参考

2022/05/14: [https://noshi91.hatenablog.com/entry/2019/09/22/114149](https://noshi91.hatenablog.com/entry/2019/09/22/114149)  
2022/05/14: Michael A. Bender, Martin Farach-Colton: The Level Ancestor Problem simplified. Theor. Comput. Sci. 321(1): 5-12 (2004)  
2022/05/13: [https://37zigen.com/level-ancestor-problem/](https://37zigen.com/level-ancestor-problem/)  
2022/05/13: [https://hdbn.hatenadiary.org/entry/20111125/1322194487](https://hdbn.hatenadiary.org/entry/20111125/1322194487)  

<br>