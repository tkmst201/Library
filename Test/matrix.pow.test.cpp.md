---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: Mathematics/ModInt.hpp
    title: "ModInt \u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/891
    links:
    - https://yukicoder.me/problems/no/891
  bundledCode: "#line 1 \"Test/matrix.pow.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/891\"\
    \r\n\r\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n#include <cassert>\r\n#include\
    \ <iostream>\r\n#include <cstdint>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/ModInt.hpp\r\
    \n */\r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\
    \n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\n\
    private:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val % M + (val >= 0 ? 0 : M)) {}\r\n\tconstexpr value_type val()\
    \ const noexcept { return val_; }\r\n\tconstexpr static decltype(M) mod() noexcept\
    \ { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const noexcept {\
    \ return val_; }\r\n\tconstexpr bool operator !() const noexcept { return !static_cast<bool>(*this);\
    \ }\r\n\tconstexpr ModInt operator +() const noexcept { return *this; }\r\n\t\
    constexpr ModInt operator -() const noexcept { return ModInt(val_ == 0 ? 0 : M\
    \ - val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept { ModInt res = *this;\
    \ ++*this; return res; }\r\n\tconstexpr ModInt operator --(int) noexcept { ModInt\
    \ res = *this; --*this; return res; }\r\n\tconstexpr ModInt & operator ++() noexcept\
    \ { val_ = val_ + 1 == M ? 0 : val_ + 1; return *this; }\r\n\tconstexpr ModInt\
    \ & operator --() noexcept { val_ = val_ == 0 ? M - 1 : val_ - 1; return *this;\
    \ }\r\n\tconstexpr ModInt & operator +=(const ModInt & rhs) noexcept { val_ +=\
    \ val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ - M; return *this; }\r\n\tconstexpr\
    \ ModInt & operator -=(const ModInt & rhs) noexcept { val_ += val_ >= rhs.val_\
    \ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\tconstexpr ModInt & operator\
    \ *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_) * rhs.val_\
    \ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt & rhs)\
    \ noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt operator\
    \ +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) += rhs;\
    \ }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr ModInt operator\
    \ *(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs) *= rhs;\
    \ }\r\n\tfriend constexpr ModInt operator /(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend constexpr bool operator\
    \ ==(const ModInt & lhs, const ModInt & rhs) noexcept { return lhs.val_ == rhs.val_;\
    \ }\r\n\tfriend constexpr bool operator !=(const ModInt & lhs, const ModInt &\
    \ rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const ModInt & rhs) { return os << rhs.val_; }\r\n\tfriend\
    \ std::istream & operator >>(std::istream & is, ModInt & rhs) { calc_type x; is\
    \ >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr ModInt pow(calc_type\
    \ n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\t\tif (n < 0) { x =\
    \ x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1;\
    \ }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv() const noexcept\
    \ {\r\n\t\tvalue_type a = val_, a1 = 1, b = M, b1 = 0;\r\n\t\twhile (b > 0) {\r\
    \n\t\t\tconst value_type q = a / b;\r\n\t\t\tvalue_type tmp = a - q * b; a = b;\
    \ b = tmp;\r\n\t\t\ttmp = a1 - q * b1; a1 = b1; b1 = tmp;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\tif (a1 < 0) a1 += M;\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n\
    #line 1 \"Mathematics/Matrix.hpp\"\n\n\n\r\n#line 6 \"Mathematics/Matrix.hpp\"\
    \n#include <vector>\r\n#include <utility>\r\n#include <type_traits>\r\n#include\
    \ <initializer_list>\r\n#include <algorithm>\r\n#include <cmath>\r\n\r\n/**\r\n\
    \ * @brief https://tkmst201.github.io/Library/Mathematics/Matrix.hpp\r\n */\r\n\
    template<typename T>\r\nstruct Matrix {\r\n\tusing value_type = T;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing uint32 = std::uint32_t;\r\n\t\r\nprivate:\r\
    \n\tsize_type h = 0, w = 0;\r\n\tstd::vector<std::vector<value_type>> val;\r\n\
    \tconstexpr static value_type eps = std::is_floating_point<value_type>::value\
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
    \n\n#line 5 \"Test/matrix.pow.test.cpp\"\n\r\n#include <cstdio>\r\n\r\nint main()\
    \ {\r\n\tint a, b, n;\r\n\tscanf(\"%d %d %d\", &a, &b, &n);\r\n\tusing Mat = Matrix<ModInt<1000000007>>;\r\
    \n\tMat mat({{a, b}, {1, 0}});\r\n\tmat = mat.pow(n);\r\n\tprintf(\"%d\\n\", (mat\
    \ * Mat({{1}, {0}}))[1][0].val());\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/891\"\r\n\r\n#include\
    \ \"Mathematics/ModInt.hpp\"\r\n#include \"Mathematics/Matrix.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\n\r\nint main() {\r\n\tint a, b, n;\r\n\tscanf(\"%d %d %d\", &a,\
    \ &b, &n);\r\n\tusing Mat = Matrix<ModInt<1000000007>>;\r\n\tMat mat({{a, b},\
    \ {1, 0}});\r\n\tmat = mat.pow(n);\r\n\tprintf(\"%d\\n\", (mat * Mat({{1}, {0}}))[1][0].val());\r\
    \n}\r\n"
  dependsOn:
  - Mathematics/ModInt.hpp
  - Mathematics/Matrix.hpp
  isVerificationFile: true
  path: Test/matrix.pow.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/matrix.pow.test.cpp
layout: document
redirect_from:
- /verify/Test/matrix.pow.test.cpp
- /verify/Test/matrix.pow.test.cpp.html
title: Test/matrix.pow.test.cpp
---
