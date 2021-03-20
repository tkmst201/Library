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

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/Matrix.hpp
 */
template<typename T>
struct Matrix {
	using value_type = T;
	using size_type = std::size_t;
	using uint32 = std::uint32_t;
	
private:
	size_type h = 0, w = 0;
	std::vector<std::vector<value_type>> val;
	constexpr static value_type eps = std::is_floating_point<value_type>::value ? 1e-8 : 0;
	
public:
	Matrix() = default;
	
	Matrix(size_type h, size_type w, const value_type & x = 0)
		: h(h), w(w), val(h, std::vector<value_type>(w, x)) {}
	
	explicit Matrix(const std::vector<std::vector<value_type>> & val)
		: h(val.size()), w(val.empty() ? 0 : val[0].size()), val(val) {
		for (size_type i = 1; i < h; ++i) assert(val[i].size() == w);
	}
	
	explicit Matrix(std::initializer_list<std::vector<value_type>> init) : val(init.begin(), init.end()) {
		h = val.size();
		w = val.empty() ? 0 : val[0].size();
		for (size_type i = 1; i < h; ++i) assert(val[i].size() == w);
	}
	
	static Matrix identity(size_type n) {
		Matrix res(n, n);
		for (size_type i = 0; i < n; ++i) res(i, i) = 1;
		return res;
	}
	
	Matrix operator +() const noexcept {
		return *this;
	}
	
	Matrix operator -() const {
		return Matrix(h, w, 0) -= *this;
	}
	
	Matrix & operator +=(const Matrix & rhs) noexcept {
		assert(match_type(rhs));
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j) val[i][j] += rhs.val[i][j];
		return *this;
	}
	
	Matrix & operator -=(const Matrix & rhs) noexcept {
		assert(match_type(rhs));
		for (size_type i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j) val[i][j] -= rhs.val[i][j];
		return *this;
	}
	
	Matrix & operator *=(const Matrix & rhs) {
		assert(w == rhs.h);
		Matrix mat(h, rhs.w);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j) for (size_type k = 0; k < w; ++k)
			mat.val[i][j] += val[i][k] * rhs.val[k][j];
		val = std::move(mat.val);
		return *this;
	}
	
	Matrix & operator /=(const Matrix & rhs) {
		assert(rhs.is_square());
		assert(!rhs.empty());
		assert(w == rhs.h);
		const Matrix mat = rhs.inv();
		assert(!mat.empty());
		*this *= mat;
		return *this;
	}
	
	friend Matrix operator +(const Matrix & lhs, const Matrix & rhs) {
		return Matrix(lhs) += rhs;
	}
	
	friend Matrix operator -(const Matrix & lhs, const Matrix & rhs) {
		return Matrix(lhs) -= rhs;
	}
	
	friend Matrix operator *(const Matrix & lhs, const Matrix & rhs) {
		return Matrix(lhs) *= rhs;
	}
	
	friend Matrix operator /(const Matrix & lhs, const Matrix & rhs) {
		return Matrix(lhs) /= rhs;
	}
	
	friend Matrix operator *(const value_type & lhs, const Matrix & rhs) {
		Matrix res(rhs.val);
		for (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j) res.val[i][j] = lhs * res.val[i][j];
		return res;
	}
	
	friend Matrix operator *(const Matrix & lhs, const value_type & rhs) {
		Matrix res(lhs.val);
		for (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j) res.val[i][j] *= rhs;
		return res;
	}
	
	friend Matrix operator /(const Matrix & lhs, const value_type & rhs) {
		assert(rhs != 0);
		Matrix res(lhs.val);
		for (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j) res.val[i][j] /= rhs;
		return res;
	}
	
	bool operator ==(const Matrix & rhs) const noexcept {
		return val == rhs.val;
	}
	
	bool operator !=(const Matrix & rhs) const noexcept {
		return !(*this == rhs);
	}
	
	std::vector<value_type> & operator [](size_type i) noexcept {
		return val[i];
	}
	
	const std::vector<value_type> & operator [](size_type i) const noexcept {
		return val[i];
	};
	
	value_type & at(size_type i, size_type j) noexcept {
		assert(i < h);
		assert(j < w);
		return val[i][j];
	}
	
	const value_type & at(size_type i, size_type j) const noexcept {
		assert(i < h);
		assert(j < w);
		return val[i][j];
	}
	
	value_type & operator ()(size_type i, size_type j) noexcept {
		assert(i < h);
		assert(j < w);
		return val[i][j];
	};
	
	const value_type & operator ()(size_type i, size_type j) const noexcept {
		assert(i < h);
		assert(j < w);
		return val[i][j];
	}
	
	bool empty() const noexcept {
		return h == 0 && w == 0;
	}
	
	std::pair<size_type, size_type> type() const noexcept {
		return {h, w};
	}
	
	bool match_type(const Matrix & A) const noexcept {
		return h == A.h && w == A.w;
	}
	
	bool is_square() const noexcept {
		return h == w;
	}
	
	const std::vector<std::vector<value_type>> & get() const noexcept {
		return val;
	}
	
	Matrix pow(long long n) const {
		assert(h == w);
		assert(n >= 0);
		Matrix res = identity(h), x(*this);
		while (n > 0) { if (n & 1) res *= x; x *= x; n >>= 1; }
		return res;
	}
	
	Matrix trans() const {
		Matrix res(w, h);
		for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j) res.val[j][i] = val[i][j];
		return res;
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
	
	Matrix submat(size_type i1, size_type i2, size_type j1, size_type j2) const {
		assert(i1 < i2 && i2 <= h);
		assert(j1 < j2 && j2 <= w);
		Matrix res(i2 - i1, j2 - j1);
		for (size_type i = 0; i < i2 - i1; ++i) std::copy(val[i + i1].begin() + j1, val[i + i1].begin() + j2, res.val[i].begin());
		return res;
	}
	
	Matrix inv() const {
		assert(is_square());
		Matrix aug_mat = this->hstack(identity(h));
		if (aug_mat.gauss_jordan(h).first != h) return Matrix();
		return aug_mat.submat(0, h, h, 2 * h);
	}
	
	value_type det() const {
		assert(is_square());
		return Matrix(*this).gauss_jordan(w).second;
	}
	
	std::pair<uint32, value_type> gauss_jordan(uint32 col) noexcept {
		assert(col <= w);
		uint32 rank = 0;
		value_type det = empty() || !is_square() ? 0 : 1;
		bool rflag = false;
		for (uint32 k = 0; k < col; ++k) {
			int pivot = -1;
			for (uint32 i = rank; i < h; ++i) if (val[i][k] != 0) { pivot = i; break; }
			if (pivot == -1) continue;
			if (static_cast<uint32>(pivot) != rank) {
				rflag ^= true;
				std::swap(val[pivot], val[rank]);
			}
			det *= val[rank][k];
			const value_type div = static_cast<value_type>(1) / val[rank][k];
			val[rank][k] = 1;
			for (uint32 j = k + 1; j < w; ++j) val[rank][j] *= div;
			for (uint32 i = 0; i < rank; ++i) {
				for (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];
				val[i][k] = 0;
			}
			for (uint32 i = std::max<uint32>(rank + 1, pivot); i < h; ++i) {
				for (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];
				val[i][k] = 0;
			}
			++rank;
		}
		if (rank != h) det = 0;
		if (rflag) det = -det;
		return {rank, det};
	}
	
	friend std::ostream & operator <<(std::ostream & os, const Matrix & rhs) {
		os << "type = (" << rhs.h << "," << rhs.w << ") [\n";
		for (size_type i = 0; i < rhs.h; ++i) {
			os << ' ';
			for (size_type j = 0; j < rhs.w; ++j) os << rhs.val[i][j] << " \n"[j + 1 == rhs.w];
		}
		return os << "]";
	}
};

template<>
bool Matrix<double>::operator ==(const Matrix<double> & rhs) const noexcept {
	using size_type = Matrix<double>::size_type;
	if (!match_type(rhs)) return false;
	for (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j) if (std::abs(val[i][j] - rhs.val[i][j]) >= eps) return false;
	return true;
}

template<>
std::pair<Matrix<double>::uint32, double> Matrix<double>::gauss_jordan(Matrix<double>::uint32 col) noexcept {
	assert(col <= w);
	using uint32 = Matrix<double>::uint32;
	uint32 rank = 0;
	double det = empty() || !is_square() ? 0 : 1;
	bool rflag = false;
	for (uint32 k = 0; k < col; ++k) {
		int pivot = -1;
		double mx = eps;
		for (uint32 i = rank; i < h; ++i) {
			const double cur = std::abs(val[i][k]);
			if (mx < cur) mx = cur, pivot = i;
		}
		if (pivot == -1) continue;
		if (static_cast<uint32>(pivot) != rank) {
			rflag ^= true;
			std::swap(val[pivot], val[rank]);
		}
		det *= val[rank][k];
		const double div = 1.0 / val[rank][k];
		val[rank][k] = 1;
		for (uint32 j = k + 1; j < w; ++j) val[rank][j] *= div;
		for (uint32 i = 0; i < rank; ++i) {
			for (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];
			val[i][k] = 0;
		}
		for (uint32 i = std::max<uint32>(rank + 1, pivot); i < h; ++i) {
			for (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];
			val[i][k] = 0;
		}
		++rank;
	}
	if (rank != h) det = 0;
	if (rflag) det = -det;
	return {rank, det};
}

#endif // INCLUDE_GUARD_MATRIX_HPP