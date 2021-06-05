---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/matrix.det.test.cpp
    title: Test/matrix.det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/matrix.pow.test.cpp
    title: Test/matrix.pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Mathematics/Matrix.hpp
    links:
    - https://tkmst201.github.io/Library/Mathematics/Matrix.hpp
  bundledCode: "#line 1 \"Mathematics/Matrix.hpp\"\n\n\n\r\n#include <iostream>\r\n\
    #include <cassert>\r\n#include <vector>\r\n#include <utility>\r\n#include <type_traits>\r\
    \n#include <initializer_list>\r\n#include <algorithm>\r\n#include <cmath>\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/Matrix.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct Matrix {\r\n\tusing value_type = T;\r\n\
    \tusing size_type = std::size_t;\r\n\tusing uint32 = std::uint32_t;\r\n\t\r\n\
    private:\r\n\tsize_type h = 0, w = 0;\r\n\tstd::vector<std::vector<value_type>>\
    \ val;\r\n\tconstexpr static value_type eps = std::is_floating_point<value_type>::value\
    \ ? 1e-8 : 0;\r\n\t\r\npublic:\r\n\tMatrix() = default;\r\n\t\r\n\tMatrix(size_type\
    \ h, size_type w, const value_type & x = 0)\r\n\t\t: h(h), w(w), val(h, std::vector<value_type>(w,\
    \ x)) {}\r\n\t\r\n\texplicit Matrix(const std::vector<std::vector<value_type>>\
    \ & val)\r\n\t\t: h(val.size()), w(val.empty() ? 0 : val[0].size()), val(val)\
    \ {\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size() == w);\r\n\t\
    }\r\n\t\r\n\texplicit Matrix(std::initializer_list<std::vector<value_type>> init)\
    \ : val(init.begin(), init.end()) {\r\n\t\th = val.size();\r\n\t\tw = val.empty()\
    \ ? 0 : val[0].size();\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size()\
    \ == w);\r\n\t}\r\n\t\r\n\tstatic Matrix identity(size_type n) {\r\n\t\tMatrix\
    \ res(n, n);\r\n\t\tfor (size_type i = 0; i < n; ++i) res(i, i) = 1;\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix operator +() const noexcept {\r\n\t\treturn *this;\r\
    \n\t}\r\n\t\r\n\tMatrix operator -() const {\r\n\t\treturn Matrix(h, w, 0) -=\
    \ *this;\r\n\t}\r\n\t\r\n\tMatrix & operator +=(const Matrix & rhs) noexcept {\r\
    \n\t\tassert(match_type(rhs));\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j) val[i][j] += rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\
    \n\t\r\n\tMatrix & operator -=(const Matrix & rhs) noexcept {\r\n\t\tassert(match_type(rhs));\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j) val[i][j]\
    \ -= rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tMatrix & operator *=(const\
    \ Matrix & rhs) {\r\n\t\tassert(w == rhs.h);\r\n\t\tMatrix mat(h, rhs.w);\r\n\t\
    \tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j) for\
    \ (size_type k = 0; k < w; ++k)\r\n\t\t\tmat.val[i][j] += val[i][k] * rhs.val[k][j];\r\
    \n\t\th = mat.h;\r\n\t\tw = mat.w;\r\n\t\tval = std::move(mat.val);\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\tMatrix & operator /=(const Matrix & rhs) {\r\n\t\t\
    assert(rhs.is_square());\r\n\t\tassert(!rhs.empty());\r\n\t\tassert(w == rhs.h);\r\
    \n\t\tconst Matrix mat = rhs.inv();\r\n\t\tassert(!mat.empty());\r\n\t\t*this\
    \ *= mat;\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tfriend Matrix operator +(const\
    \ Matrix & lhs, const Matrix & rhs) {\r\n\t\treturn Matrix(lhs) += rhs;\r\n\t\
    }\r\n\t\r\n\tfriend Matrix operator -(const Matrix & lhs, const Matrix & rhs)\
    \ {\r\n\t\treturn Matrix(lhs) -= rhs;\r\n\t}\r\n\t\r\n\tfriend Matrix operator\
    \ *(const Matrix & lhs, const Matrix & rhs) {\r\n\t\treturn Matrix(lhs) *= rhs;\r\
    \n\t}\r\n\t\r\n\tfriend Matrix operator /(const Matrix & lhs, const Matrix & rhs)\
    \ {\r\n\t\treturn Matrix(lhs) /= rhs;\r\n\t}\r\n\t\r\n\tfriend Matrix operator\
    \ *(const value_type & lhs, const Matrix & rhs) {\r\n\t\tMatrix res(rhs.val);\r\
    \n\t\tfor (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j)\
    \ res.val[i][j] = lhs * res.val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tfriend\
    \ Matrix operator *(const Matrix & lhs, const value_type & rhs) {\r\n\t\tMatrix\
    \ res(lhs.val);\r\n\t\tfor (size_type i = 0; i < res.h; ++i) for (size_type j\
    \ = 0; j < res.w; ++j) res.val[i][j] *= rhs;\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \n\tfriend Matrix operator /(const Matrix & lhs, const value_type & rhs) {\r\n\
    \t\tif constexpr (std::is_floating_point<value_type>::value) assert(std::abs(rhs)\
    \ >= eps);\r\n\t\telse assert(rhs != 0);\r\n\t\tMatrix res(lhs.val);\r\n\t\tfor\
    \ (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j) res.val[i][j]\
    \ /= rhs;\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tfriend bool operator ==(const Matrix\
    \ & lhs, const Matrix & rhs) noexcept {\r\n\t\tif (!lhs.match_type(rhs)) return\
    \ false;\r\n\t\tif constexpr (!std::is_floating_point<value_type>::value) return\
    \ lhs.val == rhs.val;\r\n\t\telse {\r\n\t\t\tfor (size_type i = 0; i < lhs.h;\
    \ ++i) for (size_type j = 0; j < lhs.w; ++j) {\r\n\t\t\t\tif (std::abs(lhs.val[i][j]\
    \ - rhs.val[i][j]) >= eps) return false;\r\n\t\t\t}\r\n\t\t\treturn true;\r\n\t\
    \t}\r\n\t}\r\n\t\r\n\tfriend bool operator !=(const Matrix & lhs, const Matrix\
    \ & rhs) noexcept {\r\n\t\treturn !(lhs == rhs);\r\n\t}\r\n\t\r\n\tstd::vector<value_type>\
    \ & operator [](size_type i) noexcept {\r\n\t\treturn val[i];\r\n\t}\r\n\t\r\n\
    \tconst std::vector<value_type> & operator [](size_type i) const noexcept {\r\n\
    \t\treturn val[i];\r\n\t};\r\n\t\r\n\tvalue_type & at(size_type i, size_type j)\
    \ noexcept {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\
    \n\t}\r\n\t\r\n\tconst value_type & at(size_type i, size_type j) const noexcept\
    \ {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t\
    }\r\n\t\r\n\tvalue_type & operator ()(size_type i, size_type j) noexcept {\r\n\
    \t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t};\r\n\t\
    \r\n\tconst value_type & operator ()(size_type i, size_type j) const noexcept\
    \ {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t\
    }\r\n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn h == 0 && w == 0;\r\n\
    \t}\r\n\t\r\n\tstd::pair<size_type, size_type> type() const noexcept {\r\n\t\t\
    return {h, w};\r\n\t}\r\n\t\r\n\tbool match_type(const Matrix & A) const noexcept\
    \ {\r\n\t\treturn h == A.h && w == A.w;\r\n\t}\r\n\t\r\n\tbool is_square() const\
    \ noexcept {\r\n\t\treturn h == w;\r\n\t}\r\n\t\r\n\tconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept {\r\n\t\treturn val;\r\n\t}\r\n\t\r\n\tMatrix pow(long\
    \ long n) const {\r\n\t\tassert(h == w);\r\n\t\tassert(n >= 0);\r\n\t\tMatrix\
    \ res = identity(h), x(*this);\r\n\t\twhile (n > 0) { if (n & 1) res *= x; x *=\
    \ x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix trans() const {\r\n\
    \t\tMatrix res(w, h);\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j) res.val[j][i] = val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tMatrix vstack(const Matrix & A) const {\r\n\t\tassert(w == A.w);\r\n\t\t\
    Matrix res(h + A.h, w);\r\n\t\tstd::copy(val.begin(), val.end(), res.val.begin());\r\
    \n\t\tstd::copy(A.val.begin(), A.val.end(), res.val.begin() + h);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix hstack(const Matrix & A) const {\r\n\t\tassert(h\
    \ == A.h);\r\n\t\tMatrix res(h, w + A.w);\r\n\t\tfor (int i = 0; i < h; ++i) {\r\
    \n\t\t\tstd::copy(val[i].begin(), val[i].end(), res.val[i].begin());\r\n\t\t\t\
    std::copy(A.val[i].begin(), A.val[i].end(), res.val[i].begin() + w);\r\n\t\t}\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix submat(size_type i1, size_type i2,\
    \ size_type j1, size_type j2) const {\r\n\t\tassert(i1 < i2 && i2 <= h);\r\n\t\
    \tassert(j1 < j2 && j2 <= w);\r\n\t\tMatrix res(i2 - i1, j2 - j1);\r\n\t\tfor\
    \ (size_type i = 0; i < i2 - i1; ++i) std::copy(val[i + i1].begin() + j1, val[i\
    \ + i1].begin() + j2, res.val[i].begin());\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    \tMatrix inv() const {\r\n\t\tassert(is_square());\r\n\t\tMatrix aug_mat = this->hstack(identity(h));\r\
    \n\t\tif (aug_mat.gauss_jordan(h).first != h) return Matrix();\r\n\t\treturn aug_mat.submat(0,\
    \ h, h, 2 * h);\r\n\t}\r\n\t\r\n\tvalue_type det() const {\r\n\t\tassert(is_square());\r\
    \n\t\treturn Matrix(*this).gauss_jordan(w).second;\r\n\t}\r\n\t\r\n\tstd::pair<uint32,\
    \ value_type> gauss_jordan(uint32 col) noexcept {\r\n\t\tassert(col <= w);\r\n\
    \t\tuint32 rank = 0;\r\n\t\tvalue_type det = empty() || !is_square() ? 0 : 1;\r\
    \n\t\tbool rflag = false;\r\n\t\tfor (uint32 k = 0; k < col; ++k) {\r\n\t\t\t\
    int pivot = -1;\r\n\t\t\tif constexpr (std::is_floating_point<value_type>::value)\
    \ {\r\n\t\t\t\tvalue_type mx = eps;\r\n\t\t\t\tfor (uint32 i = rank; i < h; ++i)\
    \ {\r\n\t\t\t\t\tconst value_type cur = std::abs(val[i][k]);\r\n\t\t\t\t\tif (mx\
    \ < cur) mx = cur, pivot = i;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \tfor (uint32 i = rank; i < h; ++i) if (val[i][k] != 0) { pivot = i; break; }\r\
    \n\t\t\t}\r\n\t\t\tif (pivot == -1) continue;\r\n\t\t\tif (static_cast<uint32>(pivot)\
    \ != rank) {\r\n\t\t\t\trflag ^= true;\r\n\t\t\t\tstd::swap(val[pivot], val[rank]);\r\
    \n\t\t\t}\r\n\t\t\tdet *= val[rank][k];\r\n\t\t\tconst value_type div = static_cast<value_type>(1)\
    \ / val[rank][k];\r\n\t\t\tval[rank][k] = 1;\r\n\t\t\tfor (uint32 j = k + 1; j\
    \ < w; ++j) val[rank][j] *= div;\r\n\t\t\tfor (uint32 i = 0; i < rank; ++i) {\r\
    \n\t\t\t\tfor (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];\r\
    \n\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\tfor (uint32 i = std::max<uint32>(rank\
    \ + 1, pivot); i < h; ++i) {\r\n\t\t\t\tfor (uint32 j = k + 1; j < w; ++j) val[i][j]\
    \ -= val[rank][j] * val[i][k];\r\n\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\t\
    ++rank;\r\n\t\t}\r\n\t\tif (rank != h) det = 0;\r\n\t\tif (rflag) det = -det;\r\
    \n\t\treturn {rank, det};\r\n\t}\r\n\t\r\n\tfriend std::ostream & operator <<(std::ostream\
    \ & os, const Matrix & rhs) {\r\n\t\tos << \"type = (\" << rhs.h << \",\" << rhs.w\
    \ << \") [\\n\";\r\n\t\tfor (size_type i = 0; i < rhs.h; ++i) {\r\n\t\t\tos <<\
    \ ' ';\r\n\t\t\tfor (size_type j = 0; j < rhs.w; ++j) os << rhs.val[i][j] << \"\
    \ \\n\"[j + 1 == rhs.w];\r\n\t\t}\r\n\t\treturn os << \"]\";\r\n\t}\r\n};\r\n\r\
    \n\n"
  code: "#ifndef INCLUDE_GUARD_MATRIX_HPP\r\n#define INCLUDE_GUARD_MATRIX_HPP\r\n\r\
    \n#include <iostream>\r\n#include <cassert>\r\n#include <vector>\r\n#include <utility>\r\
    \n#include <type_traits>\r\n#include <initializer_list>\r\n#include <algorithm>\r\
    \n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/Matrix.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct Matrix {\r\n\tusing value_type = T;\r\n\
    \tusing size_type = std::size_t;\r\n\tusing uint32 = std::uint32_t;\r\n\t\r\n\
    private:\r\n\tsize_type h = 0, w = 0;\r\n\tstd::vector<std::vector<value_type>>\
    \ val;\r\n\tconstexpr static value_type eps = std::is_floating_point<value_type>::value\
    \ ? 1e-8 : 0;\r\n\t\r\npublic:\r\n\tMatrix() = default;\r\n\t\r\n\tMatrix(size_type\
    \ h, size_type w, const value_type & x = 0)\r\n\t\t: h(h), w(w), val(h, std::vector<value_type>(w,\
    \ x)) {}\r\n\t\r\n\texplicit Matrix(const std::vector<std::vector<value_type>>\
    \ & val)\r\n\t\t: h(val.size()), w(val.empty() ? 0 : val[0].size()), val(val)\
    \ {\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size() == w);\r\n\t\
    }\r\n\t\r\n\texplicit Matrix(std::initializer_list<std::vector<value_type>> init)\
    \ : val(init.begin(), init.end()) {\r\n\t\th = val.size();\r\n\t\tw = val.empty()\
    \ ? 0 : val[0].size();\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size()\
    \ == w);\r\n\t}\r\n\t\r\n\tstatic Matrix identity(size_type n) {\r\n\t\tMatrix\
    \ res(n, n);\r\n\t\tfor (size_type i = 0; i < n; ++i) res(i, i) = 1;\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix operator +() const noexcept {\r\n\t\treturn *this;\r\
    \n\t}\r\n\t\r\n\tMatrix operator -() const {\r\n\t\treturn Matrix(h, w, 0) -=\
    \ *this;\r\n\t}\r\n\t\r\n\tMatrix & operator +=(const Matrix & rhs) noexcept {\r\
    \n\t\tassert(match_type(rhs));\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j) val[i][j] += rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\
    \n\t\r\n\tMatrix & operator -=(const Matrix & rhs) noexcept {\r\n\t\tassert(match_type(rhs));\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j) val[i][j]\
    \ -= rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tMatrix & operator *=(const\
    \ Matrix & rhs) {\r\n\t\tassert(w == rhs.h);\r\n\t\tMatrix mat(h, rhs.w);\r\n\t\
    \tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j) for\
    \ (size_type k = 0; k < w; ++k)\r\n\t\t\tmat.val[i][j] += val[i][k] * rhs.val[k][j];\r\
    \n\t\th = mat.h;\r\n\t\tw = mat.w;\r\n\t\tval = std::move(mat.val);\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\tMatrix & operator /=(const Matrix & rhs) {\r\n\t\t\
    assert(rhs.is_square());\r\n\t\tassert(!rhs.empty());\r\n\t\tassert(w == rhs.h);\r\
    \n\t\tconst Matrix mat = rhs.inv();\r\n\t\tassert(!mat.empty());\r\n\t\t*this\
    \ *= mat;\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tfriend Matrix operator +(const\
    \ Matrix & lhs, const Matrix & rhs) {\r\n\t\treturn Matrix(lhs) += rhs;\r\n\t\
    }\r\n\t\r\n\tfriend Matrix operator -(const Matrix & lhs, const Matrix & rhs)\
    \ {\r\n\t\treturn Matrix(lhs) -= rhs;\r\n\t}\r\n\t\r\n\tfriend Matrix operator\
    \ *(const Matrix & lhs, const Matrix & rhs) {\r\n\t\treturn Matrix(lhs) *= rhs;\r\
    \n\t}\r\n\t\r\n\tfriend Matrix operator /(const Matrix & lhs, const Matrix & rhs)\
    \ {\r\n\t\treturn Matrix(lhs) /= rhs;\r\n\t}\r\n\t\r\n\tfriend Matrix operator\
    \ *(const value_type & lhs, const Matrix & rhs) {\r\n\t\tMatrix res(rhs.val);\r\
    \n\t\tfor (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j)\
    \ res.val[i][j] = lhs * res.val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tfriend\
    \ Matrix operator *(const Matrix & lhs, const value_type & rhs) {\r\n\t\tMatrix\
    \ res(lhs.val);\r\n\t\tfor (size_type i = 0; i < res.h; ++i) for (size_type j\
    \ = 0; j < res.w; ++j) res.val[i][j] *= rhs;\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \n\tfriend Matrix operator /(const Matrix & lhs, const value_type & rhs) {\r\n\
    \t\tif constexpr (std::is_floating_point<value_type>::value) assert(std::abs(rhs)\
    \ >= eps);\r\n\t\telse assert(rhs != 0);\r\n\t\tMatrix res(lhs.val);\r\n\t\tfor\
    \ (size_type i = 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j) res.val[i][j]\
    \ /= rhs;\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tfriend bool operator ==(const Matrix\
    \ & lhs, const Matrix & rhs) noexcept {\r\n\t\tif (!lhs.match_type(rhs)) return\
    \ false;\r\n\t\tif constexpr (!std::is_floating_point<value_type>::value) return\
    \ lhs.val == rhs.val;\r\n\t\telse {\r\n\t\t\tfor (size_type i = 0; i < lhs.h;\
    \ ++i) for (size_type j = 0; j < lhs.w; ++j) {\r\n\t\t\t\tif (std::abs(lhs.val[i][j]\
    \ - rhs.val[i][j]) >= eps) return false;\r\n\t\t\t}\r\n\t\t\treturn true;\r\n\t\
    \t}\r\n\t}\r\n\t\r\n\tfriend bool operator !=(const Matrix & lhs, const Matrix\
    \ & rhs) noexcept {\r\n\t\treturn !(lhs == rhs);\r\n\t}\r\n\t\r\n\tstd::vector<value_type>\
    \ & operator [](size_type i) noexcept {\r\n\t\treturn val[i];\r\n\t}\r\n\t\r\n\
    \tconst std::vector<value_type> & operator [](size_type i) const noexcept {\r\n\
    \t\treturn val[i];\r\n\t};\r\n\t\r\n\tvalue_type & at(size_type i, size_type j)\
    \ noexcept {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\
    \n\t}\r\n\t\r\n\tconst value_type & at(size_type i, size_type j) const noexcept\
    \ {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t\
    }\r\n\t\r\n\tvalue_type & operator ()(size_type i, size_type j) noexcept {\r\n\
    \t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t};\r\n\t\
    \r\n\tconst value_type & operator ()(size_type i, size_type j) const noexcept\
    \ {\r\n\t\tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\treturn val[i][j];\r\n\t\
    }\r\n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn h == 0 && w == 0;\r\n\
    \t}\r\n\t\r\n\tstd::pair<size_type, size_type> type() const noexcept {\r\n\t\t\
    return {h, w};\r\n\t}\r\n\t\r\n\tbool match_type(const Matrix & A) const noexcept\
    \ {\r\n\t\treturn h == A.h && w == A.w;\r\n\t}\r\n\t\r\n\tbool is_square() const\
    \ noexcept {\r\n\t\treturn h == w;\r\n\t}\r\n\t\r\n\tconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept {\r\n\t\treturn val;\r\n\t}\r\n\t\r\n\tMatrix pow(long\
    \ long n) const {\r\n\t\tassert(h == w);\r\n\t\tassert(n >= 0);\r\n\t\tMatrix\
    \ res = identity(h), x(*this);\r\n\t\twhile (n > 0) { if (n & 1) res *= x; x *=\
    \ x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix trans() const {\r\n\
    \t\tMatrix res(w, h);\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j) res.val[j][i] = val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tMatrix vstack(const Matrix & A) const {\r\n\t\tassert(w == A.w);\r\n\t\t\
    Matrix res(h + A.h, w);\r\n\t\tstd::copy(val.begin(), val.end(), res.val.begin());\r\
    \n\t\tstd::copy(A.val.begin(), A.val.end(), res.val.begin() + h);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix hstack(const Matrix & A) const {\r\n\t\tassert(h\
    \ == A.h);\r\n\t\tMatrix res(h, w + A.w);\r\n\t\tfor (int i = 0; i < h; ++i) {\r\
    \n\t\t\tstd::copy(val[i].begin(), val[i].end(), res.val[i].begin());\r\n\t\t\t\
    std::copy(A.val[i].begin(), A.val[i].end(), res.val[i].begin() + w);\r\n\t\t}\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix submat(size_type i1, size_type i2,\
    \ size_type j1, size_type j2) const {\r\n\t\tassert(i1 < i2 && i2 <= h);\r\n\t\
    \tassert(j1 < j2 && j2 <= w);\r\n\t\tMatrix res(i2 - i1, j2 - j1);\r\n\t\tfor\
    \ (size_type i = 0; i < i2 - i1; ++i) std::copy(val[i + i1].begin() + j1, val[i\
    \ + i1].begin() + j2, res.val[i].begin());\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    \tMatrix inv() const {\r\n\t\tassert(is_square());\r\n\t\tMatrix aug_mat = this->hstack(identity(h));\r\
    \n\t\tif (aug_mat.gauss_jordan(h).first != h) return Matrix();\r\n\t\treturn aug_mat.submat(0,\
    \ h, h, 2 * h);\r\n\t}\r\n\t\r\n\tvalue_type det() const {\r\n\t\tassert(is_square());\r\
    \n\t\treturn Matrix(*this).gauss_jordan(w).second;\r\n\t}\r\n\t\r\n\tstd::pair<uint32,\
    \ value_type> gauss_jordan(uint32 col) noexcept {\r\n\t\tassert(col <= w);\r\n\
    \t\tuint32 rank = 0;\r\n\t\tvalue_type det = empty() || !is_square() ? 0 : 1;\r\
    \n\t\tbool rflag = false;\r\n\t\tfor (uint32 k = 0; k < col; ++k) {\r\n\t\t\t\
    int pivot = -1;\r\n\t\t\tif constexpr (std::is_floating_point<value_type>::value)\
    \ {\r\n\t\t\t\tvalue_type mx = eps;\r\n\t\t\t\tfor (uint32 i = rank; i < h; ++i)\
    \ {\r\n\t\t\t\t\tconst value_type cur = std::abs(val[i][k]);\r\n\t\t\t\t\tif (mx\
    \ < cur) mx = cur, pivot = i;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \tfor (uint32 i = rank; i < h; ++i) if (val[i][k] != 0) { pivot = i; break; }\r\
    \n\t\t\t}\r\n\t\t\tif (pivot == -1) continue;\r\n\t\t\tif (static_cast<uint32>(pivot)\
    \ != rank) {\r\n\t\t\t\trflag ^= true;\r\n\t\t\t\tstd::swap(val[pivot], val[rank]);\r\
    \n\t\t\t}\r\n\t\t\tdet *= val[rank][k];\r\n\t\t\tconst value_type div = static_cast<value_type>(1)\
    \ / val[rank][k];\r\n\t\t\tval[rank][k] = 1;\r\n\t\t\tfor (uint32 j = k + 1; j\
    \ < w; ++j) val[rank][j] *= div;\r\n\t\t\tfor (uint32 i = 0; i < rank; ++i) {\r\
    \n\t\t\t\tfor (uint32 j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];\r\
    \n\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\tfor (uint32 i = std::max<uint32>(rank\
    \ + 1, pivot); i < h; ++i) {\r\n\t\t\t\tfor (uint32 j = k + 1; j < w; ++j) val[i][j]\
    \ -= val[rank][j] * val[i][k];\r\n\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\t\
    ++rank;\r\n\t\t}\r\n\t\tif (rank != h) det = 0;\r\n\t\tif (rflag) det = -det;\r\
    \n\t\treturn {rank, det};\r\n\t}\r\n\t\r\n\tfriend std::ostream & operator <<(std::ostream\
    \ & os, const Matrix & rhs) {\r\n\t\tos << \"type = (\" << rhs.h << \",\" << rhs.w\
    \ << \") [\\n\";\r\n\t\tfor (size_type i = 0; i < rhs.h; ++i) {\r\n\t\t\tos <<\
    \ ' ';\r\n\t\t\tfor (size_type j = 0; j < rhs.w; ++j) os << rhs.val[i][j] << \"\
    \ \\n\"[j + 1 == rhs.w];\r\n\t\t}\r\n\t\treturn os << \"]\";\r\n\t}\r\n};\r\n\r\
    \n#endif // INCLUDE_GUARD_MATRIX_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Matrix.hpp
  requiredBy: []
  timestamp: '2021-05-02 14:09:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/matrix.det.test.cpp
  - Test/matrix.pow.test.cpp
documentation_of: Mathematics/Matrix.hpp
layout: document
title: "\u884C\u5217"
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
	// (2, 2) [[1, 2], [3, 4]]
	cout << mat2 << endl;
	cout << "mat1 == mat2 : " << boolalpha << (mat1 == mat2) << endl; // true
	
	cout << mat1 + mat2 << endl; // (2, 2) [[2, 4], [6, 8]]
	cout << mat1 - mat2 << endl; // (2, 2) [[0, 0], [0, 0]]
	cout << mat1 * mat2 << endl; // (2, 2) [[7, 10], [15, 22]]
	cout << mat1 / mat2 << endl; // (2, 2) [[1, 0], [0, 1]]
	cout << mat1 * 2 << endl; // (2, 2) [[2, 4], [6, 8]]
	cout << 3 * mat1 << endl; // (2, 2) [[3, 6], [9, 12]]
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