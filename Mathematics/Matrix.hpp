#ifndef INCLUDE_GUARD_MATRIX_HPP
#define INCLUDE_GUARD_MATRIX_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
#include <cmath>

/*
last-updated: 2020/04/13

# 仕様
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

# 参考
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

#endif // INCLUDE_GUARD_MATRIX_HPP