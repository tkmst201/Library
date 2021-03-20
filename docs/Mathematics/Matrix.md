---
title: 行列
documentation_of: //Mathematics/Matrix.hpp
---

# 概要

行列を管理する構造体です。  
基本的な四則演算やスカラー倍、`std::cout` に対応しています。  

- `Matrix()`
	- $\Theta(1)$ 大きさ $(0, 0)$ の空の行列で初期化
- `Matrix(size_t h, size_t w, const T & x = 0)`
	- $\Theta(hw)$ 大きさ $(h, w)$ の行列で初期化
- `Matrix(const vector<vector<T>> & val)`
	- `val` の大きさを $(h, w)$ として $\Theta(hw)$ $2$ 次元 vector `val` で初期化
- `Matrix(initializer_list<vector<T>> init)`
	- `init` の大きさを $(h, w)$ として $\Theta(hw)$ initializer-list `init` で初期化
- `static Matrix identity(size_t n)`
	- $\Theta(n^2)$ 大きさ $(n, n)$ の単位行列を返す
- `(const) T & at(size_t i, size_t j)`
	- $\Theta(1)$ $(i, j)$ 成分の参照を返す
- `bool empty()`
	- $\Theta(1)$ 空行列であるか判定
- `pair<size_t, size_t> type()`
	- $\Theta(1)$ 行列の大きさ $(h, w)$ を返す
- `bool match_type(const Matrix & A)`
	- $\Theta(1)$ 行列 `A` と大きさが等しいか判定
- `bool is_square()`
	- $\Theta(1)$ 行列が正方行列であるか判定
- `const vector<vector<T>> & get()`
	- $\Theta(1)$ 内部で扱っている $2$ 次元 vector 配列を返す
- `Matrix pow(long long n)`
	- $\Theta(h^3 \log{n})$ 現在の行列を $n$ 乗した行列を返す
- `Matrix trans()`
	- $\Theta(hw)$ 現在の行列を転置した行列を返す
- `Matrix vstack(const Matrix & A)`
	- $\Theta((h + A_h) w)$ 現在の行列の下に行列 `A` (大きさ $(A_h, A_w)$ ) をつなげた行列を返す
- `Matrix hstack(const Matrix & A)`
	- $\Theta(h (w + A_w))$ 現在の行列の右に行列 `A` (大きさ $(A_h, A_w)$ ) をつなげた行列を返す
- `Matrix submat(size_t i1, size_t i2, size_t j1, size_t j2)`
	- $\Theta((i_2 - i_1)(j_2 - j_1))$ 0-indexed で現在の行列の $i_1$ 行目から $i_2-1$ 行目まで、$j_1$ 列目から $j_2-1$ 列目までの部分行列を返す
- `Matrix inv()`
	- $\mathcal{O}(h^3)$ 現在の行列の逆行列を返す
- `Matrix det()`
	- $\mathcal{O}(h^3)$ 現在の行列の行列式を返す
- `pair<uint32_t, T> gauss_jordan(uint32_t col)`
	- $\mathcal{O}(hw$ `col`$)$ 破壊的な操作で $0$ 列目から $col - 1$ 列目まで行基本変形でガウスの消去法を行い、行列の rank と行列式の組を返す

<br>

# コンストラクタ

要素の型を `T` に指定します。

**制約**

- `T` は `double`, [ModInt](https://tkmst201.github.io/Library/Mathematics/ModInt.hpp)

---

### Matrix()

大きさ $(0, 0)$ の空の行列で初期化します。  

**計算量**

- $\Theta(1)$

---

### Matrix(size_t h, size_t w, const T & x = 0)

大きさ $(h, w)$ の行列で初期化します。
はじめ、すべての要素は $x$ です。  

**計算量**

- $\Theta(hw)$

---

### Matrix(const vector&lt;vector&lt;T&gt;&gt; & val)

$2$ 次元 vector `val` で初期化します。  

**計算量**

- `val` の大きさを $(h, w)$ として $\Theta(hw)$

---

### Matrix(initializer_list&lt;vector&lt;T&gt;&gt; init)

initializer-list `init` で初期化します。  

**計算量**

- `init` の大きさを $(h, w)$ として $\Theta(hw)$

---

<br>

# 演算

以下の演算が使用可能です。  

```
+Matrix
-Matrix

Matrix += Matrix
Matrix -= Matrix
Matrix *= Matrix
Matrix /= Matrix

Matrix + Matrix
Matrix - Matrix
Matrix * Matrix
Matrix / Matrix

Matrix * T
T * Matrix
Matrix / T

Matrix == Matrix
Matrix != Matrix

Matrix[i][j] // (i, j) 成分
Matrix(i, j) // (i, j) 成分

std::cout << Matrix
```

各演算は、その演算が適用できるような行列の大きさの関係式を満たす必要があります。
例えば `Matrix(lhs) += Matrix(rhs)` の場合、`lhs` 、`rhs` の大きさは一致している必要があります。  

**計算量**

左の項、右の項の行列の大きさをそれぞれ $(h_1, w_1), (h_2, w_2)$ とします。  
また、要素 `T` の演算に $f$ の計算量がかかる場合は `f` を掛け合わせてください。  

- $\Theta(h_1 w_1 w_2)$ ( `Matrix *= Matrix` または `Matrix * Matrix` )
- $\mathcal{O}((h_1 + w_1) w_1^2)$ ( `Matrix /= Matrix` または `Matrix / Matrix` )
- $\Theta(1)$ ( `Matrix[i][j]` または `Matrix(i, j)` )
- $\Theta(h_1 w_1)$ (それ以外)


<br>


# メンバ関数

以下、行列の大きさを $(h, w)$ とします。  

---

### static Matrix identity(size_t n)

大きさ $(n, n)$ の単位行列を返します。  

**制約**

- $0 \leq i < n$

**計算量**

- $\Theta(n^2)$

---

### (const) T & at(size_t i, size_t j)

$(i, j)$ 成分の参照を返します。  

**制約**

- $0 \leq i < h$
- $0 \leq j < w$

**計算量**

- $\Theta(1)$

---

### bool empty()

空行列であるか判定します。
空なら $true$ を、空でないなら $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### pair&lt;size_t, size_t&gt; type()

行列の大きさ $(h, w)$ を返します。  

**計算量**

- $\Theta(1)$

---

### bool match_type(const Matrix & A)

行列 `A` と大きさが等しいか判定します。
等しいなら $true$ を、等しくないなら $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### bool is_square()

行列が正方行列であるか判定します。
正方行列なら $true$ を、そうでないなら $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### const vector&lt;vector&lt;T&gt;&gt; & get()

内部で扱っている $2$ 次元 vector 配列を返します。  

**計算量**

- $\Theta(1)$

---

### Matrix pow(long long n)

現在の行列を $n$ 乗した行列を返します。  

**制約**

- 行列は正方行列 ($h = w$)
- $0 \leq n$

**計算量**

- $\Theta(h^3 \log{n})$

---

### Matrix trans()

現在の行列を転置した行列を返します。  

**計算量**

- $\Theta(hw)$

---

### Matrix vstack(const Matrix & A)

現在の行列の下に行列 `A` (大きさ $(A_h, A_w)$ ) をつなげた行列を返します。

**制約**

- $w = A_w$

**計算量**

- $\Theta((h + A_h) w)$

---

### Matrix hstack(const Matrix & A)

現在の行列の右に行列 `A` (大きさ $(A_h, A_w)$ ) をつなげた行列を返します。

**制約**

- $h = A_h$

**計算量**

- $\Theta(h (w + A_w))$

---

### Matrix submat(size_t i1, size_t i2, size_t j1, size_t j2)

0-indexed で現在の行列の $i_1$ 行目から $i_2-1$ 行目まで、$j_1$ 列目から $j_2-1$ 列目まで部分行列を返します。  

**制約**

- $0 \leq i_1 < i_2 \leq h$
- $0 \leq j_1 < j_2 \leq w$

**計算量**

- $\Theta((i_2 - i_1)(j_2 - j_1))$

---

### :warning: Matrix inv()

現在の行列の逆行列を返します。
正則でない (逆行列が存在しない) 場合は空の行列を返します。  

**制約**

- 行列は正方行列 ($h = w$)

**計算量**

- $\mathcal{O}(h^3)$

---

### Matrix det()

現在の行列の行列式を返します。  

**制約**

- 行列は正方行列 ($h = w$)

**計算量**

- $\mathcal{O}(h^3)$

---

### :warning: pair&lt;uint32_t, T&gt; gauss_jordan(uint32_t col)

$0$ 列目から $col - 1$ 列目まで行基本変形でガウスの消去法を行い、行列の rank と行列式の組を返します。
行列が正方行列でないときの行列式の値は $0$ です。  
行列の値を変更する破壊的な操作であることに注意してください。  

**制約**

- $0 \leq$ `col` $ \leq w$

**計算量**

- $\mathcal{O}(hw$ `col`$)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "Mathematics/Matrix.hpp"
#include "Mathematics/ModInt.hpp"
using namespace std;

using mint = ModInt<103>;

int main() {
	Matrix<mint> mat1(2, 2);
	mat1[0][0] = 1;
	mat1.at(0, 1) = 2;
	mat1(1, 0) = 3;
	mat1[1][1] = 4;
	// (2, 2) [[1, 2], [3, 4]]
	cout << mat1 << endl;
	Matrix<mint> mat2({ {1, 2}, {3, 4} });
	cout << mat2 << endl;
	cout << "mat1 == mat2 : " << boolalpha << (mat1 == mat2) << endl; // true
	
	cout << mat1 + mat2 << endl; // (2, 2) [[2, 4], [6, 8]]
	cout << mat1 - mat2 << endl; // (2, 2) [[0, 0], [0, 0]]
	cout << mat1 * mat2 << endl; // (2, 2) [[7, 10], [15, 22]]
	cout << mat1 / mat2 << endl; // (2, 2) [[1, 0], [0, 1]]
	cout << mat1 * 2 << endl; // (2, 2) [[2, 4], [6, 8]]
	cout << 3 * mat1 << endl; // (2, 2) [[3, 6], [9, 16]]
	cout << mat1 / 2 << endl; // (2, 2) [[52, 1], [53, 2]]
	cout << mat1[1][1] << endl; // 4
	
	cout << mat1.pow(3) << endl; // (2, 2) [[37, 54], [81, 15]]
	cout << mat1.det() << endl; // 101
	cout << mat1.trans() << endl; // (2, 2) [[1, 3], [2, 4]]
	
	cout << Matrix<mint>::identity(3) << endl; // (3, 3) [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
	cout << "mat1 empty() = " << boolalpha << mat1.empty() << endl; // false
	cout << "empty() = " << boolalpha << Matrix<mint>().empty() << endl; // true
	
	vector v(2, vector<mint>(3, 2));
	Matrix mat3(v);
	cout << mat3 << endl; // (2, 3) [[2, 2, 2], [2, 2, 2]]
	cout << "mat3 type() = (" << mat3.type().first << ", " << mat3.type().second << ")" << endl; // (2, 3)
	cout << "mat1 match_type(mat3) = " << boolalpha << mat1.match_type(mat3) << endl; // false
	cout << "mat1 match_type(mat2) = " << boolalpha << mat1.match_type(mat2) << endl; // true
	cout << "mat3 is_square() = " << boolalpha << mat3.is_square() << endl; // false
	
	mat3[1][2] = 0;
	cout << mat3.trans() << endl; // (3, 2) [[2, 2], [2, 2], [2, 0]]
	
	auto v2 = mat3.get();
	cout << "v == v2 : " << boolalpha << (v == v2) << endl; // false
	
	// (5, 2) [[1, 2], [3, 4], [2, 2], [2, 2], [2, 0]]
	cout << "mat1 vstack(mat3.trans())" << mat1.vstack(mat3.trans()) << endl;
	// (2, 5) [[1, 2, 2, 2, 2], [3, 4, 2, 2, 0]]
	cout << "mat1 hstack(mat3)" << mat1.hstack(mat3) << endl;
	// (2, 2) [[2, 2], [2, 0]]
	cout << "mat3 submat(0, 2, 1, 3) = " << mat3.submat(0, 2, 1, 3) << endl;
	cout << "mat1 inv() = " << mat1.inv() << endl; // (2, 2) [[101, 1], [53, 51]]
	cout << mat1.inv() * mat1 << endl; // (2, 2) [[1, 0], [0, 1]]
	cout << Matrix<mint>(2, 2, 2).inv() << endl; // (0, 0) []
	
	cout << "mat1 gauss_jordan(1)" << endl;
	mat1.gauss_jordan(1); // (2, 2) [[1, 2], [0, 101]]
	cout << mat1 << endl;
	mat1.gauss_jordan(2);
	cout << mat1 << endl; // (2, 2) [[1, 0], [0, 1]]
	
	Matrix<double> matd({ {1e-15, 0}, {0, 0} });
	cout << (Matrix<double>(2, 2, 0) == matd) << endl; // true (誤差を許容する)
}
```

<br>

# 参考

2021/03/20: [https://drken1215.hatenablog.com/entry/2019/03/20/202800](https://drken1215.hatenablog.com/entry/2019/03/20/202800)  

<br>