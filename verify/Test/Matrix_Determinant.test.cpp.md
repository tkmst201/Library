---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Test/Matrix_Determinant.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/Matrix_Determinant.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-26 17:19:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Mathematics/Matrix.cpp.html">Mathematics/Matrix.cpp</a>
* :heavy_check_mark: <a href="../../library/Mathematics/ModInt.cpp.html">Mathematics/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "Mathematics/ModInt.cpp"
#include "Mathematics/Matrix.cpp"

#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	Matrix<ModInt<998244353>> mat(N, N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> mat[i][j];
	
	std::cout << mat.gauss_jordan().second << std::endl;
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/Matrix_Determinant.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#line 1 "Mathematics/ModInt.cpp"
#include <cassert>
#include <iostream>

/*
last-updated: 2020/02/26

ModInt(long long val = 0) : 負の整数にも対応したコンストラクタ

ModInt pow(long long n) const : O(log n) n 乗した値を返す(負の整数も対応)
ModInt inverse() const : O(log n) 法 M の元での逆元を返す

const value_type & get() const noexcept
value_type & get() noexcept : 値を返す

static decltype(M) get_mod() noexcept : 法 M を返す

explicit operator bool() const noexcept : boolへ型変換 0以外のときTrue
operator ==() const noexcept
operator !=() const noexcept
operator +() const noexept
operator -() const noexept
operator +(const ModInt & rhs) const noexept
operator -(const ModInt & rhs) const noexept
operator *(const ModInt & rhs) const noexept
operator /(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept
ModInt & operator +=(const ModInt & rhs) const noexept :

friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs)
friend std::istream & operator >>(std::istream & is, ModInt & rhs) :
	入出力用

参考 :
https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

template<int M>
struct ModInt {
public:
	using value_type = long long;
	
	ModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}
	
	explicit operator bool() const noexcept { return val; }
	bool operator ==(const ModInt & rhs) const noexcept { return val == rhs.val; }
	bool operator !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }
	ModInt operator +() const noexcept { return ModInt(*this); }
	ModInt operator -() const noexcept { return ModInt(0) -= *this; }
	ModInt operator +(const ModInt & rhs) const noexcept { return ModInt(*this) += rhs; }
	ModInt operator -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }
	ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *= rhs; }
	ModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this) /= rhs; }
	
	ModInt & operator +=(const ModInt & rhs) noexcept {
		val += rhs.val;
		if (val >= M) val -= M;
		return *this;
	}
	ModInt & operator -=(const ModInt & rhs) noexcept {
		if (val < rhs.val) val += M;
		val -= rhs.val;
		return *this;
	}
	ModInt & operator *=(const ModInt & rhs) noexcept {
		val = val * rhs.val % M;
		return *this;
	}
	ModInt & operator /=(const ModInt & rhs) noexcept {
		*this *= rhs.inverse();
		return *this;
	}
	
	ModInt pow(value_type n) const {
		ModInt res = 1, x = val;
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	ModInt inverse() const {
		long long a = val, a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;
		while (b > 0) {
			value_type q = a / b, r = a % b;
			value_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;
			a = b; b = r;
			a1 = b1; b1 = nb1;
			a2 = b2; b2 = nb2;
		}
		assert(a == 1);
		return a1;
	}
	
	const value_type & get() const noexcept { return val; }
	static decltype(M) get_mod() noexcept { return M; }
	
	friend std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val; }
	friend std::istream & operator >>(std::istream & is, ModInt & rhs) {
		value_type x;
		is >> x;
		rhs = ModInt(x);
		return is;
	}
private:
	value_type val;
};
#line 3 "Mathematics/Matrix.cpp"
#include <vector>
#include <utility>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
#include <cmath>

/*
last-updated: 2020/04/13

Matrix() : 空の行列を作成
Matrix(size_type h, size_type w, const value_type & x = 0) : 型(h, w) 初期値 x の行列を作成
Matrix(std::vector<std::vector<value_type>> val) : 2次元 vector から行列を作成
Matrix(std::initializer_list<std::vector<value_type>> init) : initializer_list から行列を作成

std::vector<value_type> & operator [](size_type i) noexcept
const std::vector<value_type> & operator [](size_type i) const noexcept
value_type & operator ()(size_type i, size_type j) noexcept
const value_type & operator ()(size_type i, size_type j) const noexcept
value_type & at(size_type i, size_type j)
const value_type & at(size_type i, size_type j) :
	要素(i, j) へのアクセス([]と()は同じ。at は範囲外判定をする)

bool empty() const : 行列が空であるかを返す
std::pair<size_type, size_type> type() const : 行列を型を返す
bool match_type(const Matrix & rhs) const noexcept : 2つの行列の型が等しいか判定する
bool is_square() : 正方行列であるかを返す
const std::vector<std::vector<value_type>> & get() const noexcept : 行列を 2次元vector にして返す

bool operator ==(const Matrix & rhs) const noexcept
bool operator !=(const Matrix & rhs) const noexcept
Matrix operator +() const
Matrix operator -() const
Matrix operator +(const Matrix & rhs) const
Matrix operator -(const Matrix & rhs) const
Matrix operator *(const Matrix & rhs) const
Matrix operator /(const Matrix & rhs) const
friend Matrix operator *(const value_type & lhs, const Matrix & rhs)
Matrix operator *(const value_type & rhs) const : O(hww')
Matrix operator /(const value_type & rhs) const : O(h^3)
Matrix & operator +=(const Matrix & rhs)
Matrix & operator -=(const Matrix & rhs)
Matrix & operator *=(const Matrix & rhs)
Matrix & operator /=(const Matrix & rhs)

Matrix pow(long long n) const : O(hww'log n) n 乗を返す
Matrix trans() const : 転置行列を返す
Matrix inverse() const : O(h^3) 逆行列を返す(存在しない場合は空行列)
Matrix vstack(const Matrix & A) const : 縦に2つの行列を結合する
Matrix hstack(const Matrix & A) const : 横に2つの行列を結合する
Matrix submat(size_type i1, size_type j1, size_type i2, size_type j2) const : [i1,i2), [j1,j2)の部分行列を返す
static Matrix identity(size_type n) : n 次元の単位行列を返す
std::pair<size_type, value_type> gauss_jordan(size_type colnum = -1) :
	O(h^2 w) ガウス・ジョルダン法を行う(元データは壊れる)
	(rank, determinant) を返す
friend std::ostream & operator <<(std::ostream & os, const Matrix & rhs) : 行列を出力できる

参考 :
https://drken1215.hatenablog.com/entry/2019/03/20/202800
*/

template<typename T>
struct Matrix {
public:
	using value_type = T;
	using size_type = std::size_t;
	
	Matrix() {}
	Matrix(size_type h, size_type w, const value_type & x = 0) : h(h), w(w), val(h, std::vector<value_type>(w, x)) {
		assert(h > 0 && w > 0);
	}
	Matrix(std::vector<std::vector<value_type>> val) : h(val.size()), w(val.size() ? val[0].size() : 0), val(val) {
		assert(h > 0 && w > 0);
		for (size_type i = 1; i < h; ++i) assert(val[i].size() == w);
	}
	Matrix(std::initializer_list<std::vector<value_type>> init) : val(init.begin(), init.end()) {
		h = val.size();
		w = val.size() ? val[0].size() : 0;
		assert(h > 0 && w > 0);
		for (size_type i = 1; i < h; ++i) assert(val[i].size() == w);
	}
	
	std::vector<value_type> & operator [](size_type i) noexcept { return val[i]; }
	const std::vector<value_type> & operator [](size_type i) const noexcept { return val[i]; };
	value_type & operator ()(size_type i, size_type j) noexcept { return val[i][j]; };
	const value_type & operator ()(size_type i, size_type j) const noexcept { return val[i][j]; }
	value_type & at(size_type i, size_type j) {
		assert(i < h && j < w);
		return val[i][j];
	}
	const value_type & at(size_type i, size_type j) const {
		assert(i < h & j < w);
		return val[i][j];
	}
	
	bool empty() const { return !(h || w); }
	std::pair<size_type, size_type> type() const { return std::make_pair(h, w); }
	bool match_type(const Matrix & rhs) const noexcept { return h == rhs.h && w == rhs.w; }
	bool is_square() const { return h == w; }
	const std::vector<std::vector<value_type>> & get() const noexcept { return val; }
	
	bool operator ==(const Matrix & rhs) const noexcept { return match_type(rhs) && val == rhs.val; }
	bool operator !=(const Matrix & rhs) const noexcept { return !(*this == rhs); }
	Matrix operator +() const { return Matrix(*this); }
	Matrix operator -() const { return Matrix(h, w) - Matrix(*this); }
	Matrix operator +(const Matrix & rhs) const { return Matrix(*this) += rhs; }
	Matrix operator -(const Matrix & rhs) const { return Matrix(*this) -= rhs; }
	Matrix operator *(const Matrix & rhs) const {
		assert(w == rhs.h);
		Matrix res(h, rhs.w);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j) for (size_type k = 0; k < w; ++k)
			res.val[i][j] += val[i][k] * rhs.val[k][j];
		return res;
	}
	Matrix operator /(const Matrix & rhs) const { return Matrix(*this) /= rhs; }
	friend Matrix operator *(const value_type & lhs, const Matrix & rhs) {
		Matrix res(rhs.val);
		for (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j)
			res.val[i][j] = lhs * res.val[i][j];
		return res;
	}
	Matrix operator *(const value_type & rhs) const {
		Matrix res(val);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)
			res.val[i][j] *= rhs;
		return res;
	}
	Matrix operator /(const value_type & rhs) const {
		Matrix res(val);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)
			res.val[i][j] /= rhs;
		return res;
	}
	Matrix & operator +=(const Matrix & rhs) {
		assert(match_type(rhs));
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)
			val[i][j] += rhs.val[i][j];
		return *this;
	}
	Matrix & operator -=(const Matrix & rhs) {
		assert(match_type(rhs));
		for (size_type i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j)
			val[i][j] -= rhs.val[i][j];
		return *this;
	}
	Matrix & operator *=(const Matrix & rhs) {
		*this = *this * rhs;
		return *this;
	}
	Matrix & operator /=(const Matrix & rhs) {
		*this *= rhs.inverse();
		return *this;
	}
	
	Matrix pow(long long n) const {
		Matrix res = identity(h), x(*this);
		if (n < 0) { x = x.inverse(); n = -n; }
		while (n) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	Matrix trans() const {
		Matrix res(w, h);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)
			res.val[j][i] = val[i][j];
		return res;
	}
	
	Matrix inverse() const {
		assert(is_square());
		Matrix aug_mat = this->hstack(identity(h));
		if (aug_mat.gauss_jordan().first != h) return Matrix();
		return aug_mat.submat(0, w, h, 2 * w);
	}
	
	Matrix vstack(const Matrix & A) const {
		assert(w == A.w);
		Matrix res(h + A.h, w);
		std::copy(val.begin(), val.end(), res.val.begin());
		std::copy(A.val.begin(), A.val.end(), res.val.begin() + h);
		return res;
	}
	
	Matrix hstack(const Matrix & A) const {
		assert(h == A.h);
		Matrix res(h, w + A.w);
		for (int i = 0; i < h; ++i) {
			std::copy(val[i].begin(), val[i].end(), res.val[i].begin());
			std::copy(A.val[i].begin(), A.val[i].end(), res.val[i].begin() + w);
		}
		return res;
	}
	
	Matrix submat(size_type i1, size_type j1, size_type i2, size_type j2) const {
		assert(i1 < i2 && j1 < j2 && i2 <= h && j2 <= w);
		Matrix res(i2 - i1, j2 - j1);
		for (size_type i = 0; i < i2 - i1; ++i)
			std::copy(val[i + i1].begin() + j1, val[i + i1].begin() + j2, res.val[i].begin());
		return res;
	}
	
	static Matrix identity(size_type n) {
		Matrix res(n, n);
		for (size_type i = 0; i < n; ++i) res(i, i) = 1;
		return res;
	}
	
	std::pair<size_type, value_type> gauss_jordan(size_type colnum = -1) {
		if (colnum == -1) colnum = w;
		size_type rank = 0;
		value_type det {};
		bool done = false, rflag = false;
		
		for (size_type k = 0; k < colnum; ++k) {
			size_type pivot = -1;
			for (size_type i = rank; i < h; ++i) {
				if (val[i][k] != 0) {
					pivot = i;
					break;
				}
			}
			if (pivot == -1) continue;
			if (pivot != rank) {
				rflag ^= 1;
				std::swap(val[rank], val[pivot]);
			}
			
			if (!done) { det = val[rank][k]; done = true; }
			else det *= val[rank][k];
			
			value_type div = static_cast<value_type>(1) / val[rank][k];
			for (size_type j = k; j < w; ++j) val[rank][j] *= div;
			
			for (size_type i = 0; i < h; ++i) if (i != rank) {
				for (size_type j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];
					val[i][k] = 0;
			}
			++rank;
		}
		
		if (!is_square() || rank != h) det = 0;
		else if (rflag) det *= -1;
		
		return {rank, det};
	}
	
	friend std::ostream & operator <<(std::ostream & os, const Matrix & rhs) {
		os << "type = (" << rhs.h << "," << rhs.w << ") [\n";
		for (size_type i = 0; i < rhs.h; ++i) for (size_type j = 0; j < rhs.w; ++j)
			os << (j == 0 ? " " : "") << rhs.val[i][j] << (j + 1 == rhs.w ? '\n' : ' ');
		return os << "]";
	}
	
private:
	size_type h, w;
	std::vector<std::vector<value_type>> val;
};
#line 5 "Test/Matrix_Determinant.test.cpp"

#line 7 "Test/Matrix_Determinant.test.cpp"

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	Matrix<ModInt<998244353>> mat(N, N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> mat[i][j];
	
	std::cout << mat.gauss_jordan().second << std::endl;
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

