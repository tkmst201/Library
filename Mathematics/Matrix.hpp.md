---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Matrix_Determinant.test.cpp
    title: Test/Matrix_Determinant.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://drken1215.hatenablog.com/entry/2019/03/20/202800
  bundledCode: "#line 1 \"Mathematics/Matrix.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/04/13\r\
    \n\r\n# \u4ED5\u69D8\r\nMatrix() : \u7A7A\u306E\u884C\u5217\u3092\u4F5C\u6210\r\
    \nMatrix(size_type h, size_type w, const value_type & x = 0) : \u578B(h, w) \u521D\
    \u671F\u5024 x \u306E\u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(std::vector<std::vector<value_type>>\
    \ val) : 2\u6B21\u5143 vector \u304B\u3089\u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(std::initializer_list<std::vector<value_type>>\
    \ init) : initializer_list \u304B\u3089\u884C\u5217\u3092\u4F5C\u6210\r\n\r\n\
    std::vector<value_type> & operator [](size_type i) noexcept\r\nconst std::vector<value_type>\
    \ & operator [](size_type i) const noexcept\r\nvalue_type & operator ()(size_type\
    \ i, size_type j) noexcept\r\nconst value_type & operator ()(size_type i, size_type\
    \ j) const noexcept\r\nvalue_type & at(size_type i, size_type j)\r\nconst value_type\
    \ & at(size_type i, size_type j) :\r\n\t\u8981\u7D20(i, j) \u3078\u306E\u30A2\u30AF\
    \u30BB\u30B9([]\u3068()\u306F\u540C\u3058\u3002at \u306F\u7BC4\u56F2\u5916\u5224\
    \u5B9A\u3092\u3059\u308B)\r\n\r\nbool empty() const : \u884C\u5217\u304C\u7A7A\
    \u3067\u3042\u308B\u304B\u3092\u8FD4\u3059\r\nstd::pair<size_type, size_type>\
    \ type() const : \u884C\u5217\u3092\u578B\u3092\u8FD4\u3059\r\nbool match_type(const\
    \ Matrix & rhs) const noexcept : 2\u3064\u306E\u884C\u5217\u306E\u578B\u304C\u7B49\
    \u3057\u3044\u304B\u5224\u5B9A\u3059\u308B\r\nbool is_square() : \u6B63\u65B9\u884C\
    \u5217\u3067\u3042\u308B\u304B\u3092\u8FD4\u3059\r\nconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept : \u884C\u5217\u3092 2\u6B21\u5143vector \u306B\u3057\
    \u3066\u8FD4\u3059\r\n\r\nbool operator ==(const Matrix & rhs) const noexcept\r\
    \nbool operator !=(const Matrix & rhs) const noexcept\r\nMatrix operator +() const\r\
    \nMatrix operator -() const\r\nMatrix operator +(const Matrix & rhs) const\r\n\
    Matrix operator -(const Matrix & rhs) const\r\nMatrix operator *(const Matrix\
    \ & rhs) const\r\nMatrix operator /(const Matrix & rhs) const\r\nfriend Matrix\
    \ operator *(const value_type & lhs, const Matrix & rhs)\r\nMatrix operator *(const\
    \ value_type & rhs) const : O(hww')\r\nMatrix operator /(const value_type & rhs)\
    \ const : O(h^3)\r\nMatrix & operator +=(const Matrix & rhs)\r\nMatrix & operator\
    \ -=(const Matrix & rhs)\r\nMatrix & operator *=(const Matrix & rhs)\r\nMatrix\
    \ & operator /=(const Matrix & rhs)\r\n\r\nMatrix pow(long long n) const : O(hww'log\
    \ n) n \u4E57\u3092\u8FD4\u3059\r\nMatrix trans() const : \u8EE2\u7F6E\u884C\u5217\
    \u3092\u8FD4\u3059\r\nMatrix inverse() const : O(h^3) \u9006\u884C\u5217\u3092\
    \u8FD4\u3059(\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u7A7A\u884C\u5217\
    )\r\nMatrix vstack(const Matrix & A) const : \u7E26\u306B2\u3064\u306E\u884C\u5217\
    \u3092\u7D50\u5408\u3059\u308B\r\nMatrix hstack(const Matrix & A) const : \u6A2A\
    \u306B2\u3064\u306E\u884C\u5217\u3092\u7D50\u5408\u3059\u308B\r\nMatrix submat(size_type\
    \ i1, size_type j1, size_type i2, size_type j2) const : [i1,i2), [j1,j2)\u306E\
    \u90E8\u5206\u884C\u5217\u3092\u8FD4\u3059\r\nstatic Matrix identity(size_type\
    \ n) : n \u6B21\u5143\u306E\u5358\u4F4D\u884C\u5217\u3092\u8FD4\u3059\r\nstd::pair<size_type,\
    \ value_type> gauss_jordan(size_type colnum = -1) :\r\n\tO(h^2 w) \u30AC\u30A6\
    \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u6CD5\u3092\u884C\u3046(\u5143\u30C7\
    \u30FC\u30BF\u306F\u58CA\u308C\u308B)\r\n\t(rank, determinant) \u3092\u8FD4\u3059\
    \r\nfriend std::ostream & operator <<(std::ostream & os, const Matrix & rhs) :\
    \ \u884C\u5217\u3092\u51FA\u529B\u3067\u304D\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://drken1215.hatenablog.com/entry/2019/03/20/202800\r\
    \n*/\r\n\r\n#include <iostream>\r\n#include <cassert>\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <type_traits>\r\n#include <initializer_list>\r\n\
    #include <algorithm>\r\n#include <cmath>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ Matrix {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\n\tMatrix() {}\r\n\tMatrix(size_type h, size_type w, const value_type &\
    \ x = 0) : h(h), w(w), val(h, std::vector<value_type>(w, x)) {\r\n\t\tassert(h\
    \ > 0 && w > 0);\r\n\t}\r\n\tMatrix(std::vector<std::vector<value_type>> val)\
    \ : h(val.size()), w(val.size() ? val[0].size() : 0), val(val) {\r\n\t\tassert(h\
    \ > 0 && w > 0);\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size()\
    \ == w);\r\n\t}\r\n\tMatrix(std::initializer_list<std::vector<value_type>> init)\
    \ : val(init.begin(), init.end()) {\r\n\t\th = val.size();\r\n\t\tw = val.size()\
    \ ? val[0].size() : 0;\r\n\t\tassert(h > 0 && w > 0);\r\n\t\tfor (size_type i\
    \ = 1; i < h; ++i) assert(val[i].size() == w);\r\n\t}\r\n\t\r\n\tstd::vector<value_type>\
    \ & operator [](size_type i) noexcept { return val[i]; }\r\n\tconst std::vector<value_type>\
    \ & operator [](size_type i) const noexcept { return val[i]; };\r\n\tvalue_type\
    \ & operator ()(size_type i, size_type j) noexcept { return val[i][j]; };\r\n\t\
    const value_type & operator ()(size_type i, size_type j) const noexcept { return\
    \ val[i][j]; }\r\n\tvalue_type & at(size_type i, size_type j) {\r\n\t\tassert(i\
    \ < h && j < w);\r\n\t\treturn val[i][j];\r\n\t}\r\n\tconst value_type & at(size_type\
    \ i, size_type j) const {\r\n\t\tassert(i < h & j < w);\r\n\t\treturn val[i][j];\r\
    \n\t}\r\n\t\r\n\tbool empty() const { return !(h || w); }\r\n\tstd::pair<size_type,\
    \ size_type> type() const { return std::make_pair(h, w); }\r\n\tbool match_type(const\
    \ Matrix & rhs) const noexcept { return h == rhs.h && w == rhs.w; }\r\n\tbool\
    \ is_square() const { return h == w; }\r\n\tconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept { return val; }\r\n\t\r\n\tbool operator ==(const Matrix\
    \ & rhs) const noexcept { return match_type(rhs) && val == rhs.val; }\r\n\tbool\
    \ operator !=(const Matrix & rhs) const noexcept { return !(*this == rhs); }\r\
    \n\tMatrix operator +() const { return Matrix(*this); }\r\n\tMatrix operator -()\
    \ const { return Matrix(h, w) - Matrix(*this); }\r\n\tMatrix operator +(const\
    \ Matrix & rhs) const { return Matrix(*this) += rhs; }\r\n\tMatrix operator -(const\
    \ Matrix & rhs) const { return Matrix(*this) -= rhs; }\r\n\tMatrix operator *(const\
    \ Matrix & rhs) const {\r\n\t\tassert(w == rhs.h);\r\n\t\tMatrix res(h, rhs.w);\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j)\
    \ for (size_type k = 0; k < w; ++k)\r\n\t\t\tres.val[i][j] += val[i][k] * rhs.val[k][j];\r\
    \n\t\treturn res;\r\n\t}\r\n\tMatrix operator /(const Matrix & rhs) const { return\
    \ Matrix(*this) /= rhs; }\r\n\tfriend Matrix operator *(const value_type & lhs,\
    \ const Matrix & rhs) {\r\n\t\tMatrix res(rhs.val);\r\n\t\tfor (size_type i =\
    \ 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j)\r\n\t\t\tres.val[i][j]\
    \ = lhs * res.val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\tMatrix operator *(const\
    \ value_type & rhs) const {\r\n\t\tMatrix res(val);\r\n\t\tfor (size_type i =\
    \ 0; i < h; ++i) for (size_type j = 0; j < w; ++j)\r\n\t\t\tres.val[i][j] *= rhs;\r\
    \n\t\treturn res;\r\n\t}\r\n\tMatrix operator /(const value_type & rhs) const\
    \ {\r\n\t\tMatrix res(val);\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j)\r\n\t\t\tres.val[i][j] /= rhs;\r\n\t\treturn res;\r\n\t}\r\
    \n\tMatrix & operator +=(const Matrix & rhs) {\r\n\t\tassert(match_type(rhs));\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)\r\n\t\
    \t\tval[i][j] += rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator\
    \ -=(const Matrix & rhs) {\r\n\t\tassert(match_type(rhs));\r\n\t\tfor (size_type\
    \ i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j)\r\n\t\t\tval[i][j] -= rhs.val[i][j];\r\
    \n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator *=(const Matrix & rhs) {\r\n\
    \t\t*this = *this * rhs;\r\n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator /=(const\
    \ Matrix & rhs) {\r\n\t\t*this *= rhs.inverse();\r\n\t\treturn *this;\r\n\t}\r\
    \n\t\r\n\tMatrix pow(long long n) const {\r\n\t\tMatrix res = identity(h), x(*this);\r\
    \n\t\tif (n < 0) { x = x.inverse(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res\
    \ *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix trans()\
    \ const {\r\n\t\tMatrix res(w, h);\r\n\t\tfor (size_type i = 0; i < h; ++i) for\
    \ (size_type j = 0; j < w; ++j)\r\n\t\t\tres.val[j][i] = val[i][j];\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix inverse() const {\r\n\t\tassert(is_square());\r\
    \n\t\tMatrix aug_mat = this->hstack(identity(h));\r\n\t\tif (aug_mat.gauss_jordan().first\
    \ != h) return Matrix();\r\n\t\treturn aug_mat.submat(0, w, h, 2 * w);\r\n\t}\r\
    \n\t\r\n\tMatrix vstack(const Matrix & A) const {\r\n\t\tassert(w == A.w);\r\n\
    \t\tMatrix res(h + A.h, w);\r\n\t\tstd::copy(val.begin(), val.end(), res.val.begin());\r\
    \n\t\tstd::copy(A.val.begin(), A.val.end(), res.val.begin() + h);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix hstack(const Matrix & A) const {\r\n\t\tassert(h\
    \ == A.h);\r\n\t\tMatrix res(h, w + A.w);\r\n\t\tfor (int i = 0; i < h; ++i) {\r\
    \n\t\t\tstd::copy(val[i].begin(), val[i].end(), res.val[i].begin());\r\n\t\t\t\
    std::copy(A.val[i].begin(), A.val[i].end(), res.val[i].begin() + w);\r\n\t\t}\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix submat(size_type i1, size_type j1,\
    \ size_type i2, size_type j2) const {\r\n\t\tassert(i1 < i2 && j1 < j2 && i2 <=\
    \ h && j2 <= w);\r\n\t\tMatrix res(i2 - i1, j2 - j1);\r\n\t\tfor (size_type i\
    \ = 0; i < i2 - i1; ++i)\r\n\t\t\tstd::copy(val[i + i1].begin() + j1, val[i +\
    \ i1].begin() + j2, res.val[i].begin());\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    static Matrix identity(size_type n) {\r\n\t\tMatrix res(n, n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) res(i, i) = 1;\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<size_type,\
    \ value_type> gauss_jordan(size_type colnum = -1) {\r\n\t\tif (colnum == -1) colnum\
    \ = w;\r\n\t\tsize_type rank = 0;\r\n\t\tvalue_type det {};\r\n\t\tbool done =\
    \ false, rflag = false;\r\n\t\t\r\n\t\tfor (size_type k = 0; k < colnum; ++k)\
    \ {\r\n\t\t\tsize_type pivot = -1;\r\n\t\t\tfor (size_type i = rank; i < h; ++i)\
    \ {\r\n\t\t\t\tif (val[i][k] != 0) {\r\n\t\t\t\t\tpivot = i;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (pivot == -1) continue;\r\n\t\t\tif (pivot\
    \ != rank) {\r\n\t\t\t\trflag ^= 1;\r\n\t\t\t\tstd::swap(val[rank], val[pivot]);\r\
    \n\t\t\t}\r\n\t\t\t\r\n\t\t\tif (!done) { det = val[rank][k]; done = true; }\r\
    \n\t\t\telse det *= val[rank][k];\r\n\t\t\t\r\n\t\t\tvalue_type div = static_cast<value_type>(1)\
    \ / val[rank][k];\r\n\t\t\tfor (size_type j = k; j < w; ++j) val[rank][j] *= div;\r\
    \n\t\t\t\r\n\t\t\tfor (size_type i = 0; i < h; ++i) if (i != rank) {\r\n\t\t\t\
    \tfor (size_type j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];\r\
    \n\t\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\t++rank;\r\n\t\t}\r\n\t\t\r\n\t\t\
    if (!is_square() || rank != h) det = 0;\r\n\t\telse if (rflag) det *= -1;\r\n\t\
    \t\r\n\t\treturn {rank, det};\r\n\t}\r\n\t\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const Matrix & rhs) {\r\n\t\tos << \"type = (\" << rhs.h\
    \ << \",\" << rhs.w << \") [\\n\";\r\n\t\tfor (size_type i = 0; i < rhs.h; ++i)\
    \ for (size_type j = 0; j < rhs.w; ++j)\r\n\t\t\tos << (j == 0 ? \" \" : \"\"\
    ) << rhs.val[i][j] << (j + 1 == rhs.w ? '\\n' : ' ');\r\n\t\treturn os << \"]\"\
    ;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ val;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_MATRIX_HPP\r\n#define INCLUDE_GUARD_MATRIX_HPP\r\n\r\
    \n/*\r\nlast-updated: 2020/04/13\r\n\r\n# \u4ED5\u69D8\r\nMatrix() : \u7A7A\u306E\
    \u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(size_type h, size_type w, const value_type\
    \ & x = 0) : \u578B(h, w) \u521D\u671F\u5024 x \u306E\u884C\u5217\u3092\u4F5C\u6210\
    \r\nMatrix(std::vector<std::vector<value_type>> val) : 2\u6B21\u5143 vector \u304B\
    \u3089\u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(std::initializer_list<std::vector<value_type>>\
    \ init) : initializer_list \u304B\u3089\u884C\u5217\u3092\u4F5C\u6210\r\n\r\n\
    std::vector<value_type> & operator [](size_type i) noexcept\r\nconst std::vector<value_type>\
    \ & operator [](size_type i) const noexcept\r\nvalue_type & operator ()(size_type\
    \ i, size_type j) noexcept\r\nconst value_type & operator ()(size_type i, size_type\
    \ j) const noexcept\r\nvalue_type & at(size_type i, size_type j)\r\nconst value_type\
    \ & at(size_type i, size_type j) :\r\n\t\u8981\u7D20(i, j) \u3078\u306E\u30A2\u30AF\
    \u30BB\u30B9([]\u3068()\u306F\u540C\u3058\u3002at \u306F\u7BC4\u56F2\u5916\u5224\
    \u5B9A\u3092\u3059\u308B)\r\n\r\nbool empty() const : \u884C\u5217\u304C\u7A7A\
    \u3067\u3042\u308B\u304B\u3092\u8FD4\u3059\r\nstd::pair<size_type, size_type>\
    \ type() const : \u884C\u5217\u3092\u578B\u3092\u8FD4\u3059\r\nbool match_type(const\
    \ Matrix & rhs) const noexcept : 2\u3064\u306E\u884C\u5217\u306E\u578B\u304C\u7B49\
    \u3057\u3044\u304B\u5224\u5B9A\u3059\u308B\r\nbool is_square() : \u6B63\u65B9\u884C\
    \u5217\u3067\u3042\u308B\u304B\u3092\u8FD4\u3059\r\nconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept : \u884C\u5217\u3092 2\u6B21\u5143vector \u306B\u3057\
    \u3066\u8FD4\u3059\r\n\r\nbool operator ==(const Matrix & rhs) const noexcept\r\
    \nbool operator !=(const Matrix & rhs) const noexcept\r\nMatrix operator +() const\r\
    \nMatrix operator -() const\r\nMatrix operator +(const Matrix & rhs) const\r\n\
    Matrix operator -(const Matrix & rhs) const\r\nMatrix operator *(const Matrix\
    \ & rhs) const\r\nMatrix operator /(const Matrix & rhs) const\r\nfriend Matrix\
    \ operator *(const value_type & lhs, const Matrix & rhs)\r\nMatrix operator *(const\
    \ value_type & rhs) const : O(hww')\r\nMatrix operator /(const value_type & rhs)\
    \ const : O(h^3)\r\nMatrix & operator +=(const Matrix & rhs)\r\nMatrix & operator\
    \ -=(const Matrix & rhs)\r\nMatrix & operator *=(const Matrix & rhs)\r\nMatrix\
    \ & operator /=(const Matrix & rhs)\r\n\r\nMatrix pow(long long n) const : O(hww'log\
    \ n) n \u4E57\u3092\u8FD4\u3059\r\nMatrix trans() const : \u8EE2\u7F6E\u884C\u5217\
    \u3092\u8FD4\u3059\r\nMatrix inverse() const : O(h^3) \u9006\u884C\u5217\u3092\
    \u8FD4\u3059(\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u7A7A\u884C\u5217\
    )\r\nMatrix vstack(const Matrix & A) const : \u7E26\u306B2\u3064\u306E\u884C\u5217\
    \u3092\u7D50\u5408\u3059\u308B\r\nMatrix hstack(const Matrix & A) const : \u6A2A\
    \u306B2\u3064\u306E\u884C\u5217\u3092\u7D50\u5408\u3059\u308B\r\nMatrix submat(size_type\
    \ i1, size_type j1, size_type i2, size_type j2) const : [i1,i2), [j1,j2)\u306E\
    \u90E8\u5206\u884C\u5217\u3092\u8FD4\u3059\r\nstatic Matrix identity(size_type\
    \ n) : n \u6B21\u5143\u306E\u5358\u4F4D\u884C\u5217\u3092\u8FD4\u3059\r\nstd::pair<size_type,\
    \ value_type> gauss_jordan(size_type colnum = -1) :\r\n\tO(h^2 w) \u30AC\u30A6\
    \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u6CD5\u3092\u884C\u3046(\u5143\u30C7\
    \u30FC\u30BF\u306F\u58CA\u308C\u308B)\r\n\t(rank, determinant) \u3092\u8FD4\u3059\
    \r\nfriend std::ostream & operator <<(std::ostream & os, const Matrix & rhs) :\
    \ \u884C\u5217\u3092\u51FA\u529B\u3067\u304D\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://drken1215.hatenablog.com/entry/2019/03/20/202800\r\
    \n*/\r\n\r\n#include <iostream>\r\n#include <cassert>\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <type_traits>\r\n#include <initializer_list>\r\n\
    #include <algorithm>\r\n#include <cmath>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ Matrix {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\n\tMatrix() {}\r\n\tMatrix(size_type h, size_type w, const value_type &\
    \ x = 0) : h(h), w(w), val(h, std::vector<value_type>(w, x)) {\r\n\t\tassert(h\
    \ > 0 && w > 0);\r\n\t}\r\n\tMatrix(std::vector<std::vector<value_type>> val)\
    \ : h(val.size()), w(val.size() ? val[0].size() : 0), val(val) {\r\n\t\tassert(h\
    \ > 0 && w > 0);\r\n\t\tfor (size_type i = 1; i < h; ++i) assert(val[i].size()\
    \ == w);\r\n\t}\r\n\tMatrix(std::initializer_list<std::vector<value_type>> init)\
    \ : val(init.begin(), init.end()) {\r\n\t\th = val.size();\r\n\t\tw = val.size()\
    \ ? val[0].size() : 0;\r\n\t\tassert(h > 0 && w > 0);\r\n\t\tfor (size_type i\
    \ = 1; i < h; ++i) assert(val[i].size() == w);\r\n\t}\r\n\t\r\n\tstd::vector<value_type>\
    \ & operator [](size_type i) noexcept { return val[i]; }\r\n\tconst std::vector<value_type>\
    \ & operator [](size_type i) const noexcept { return val[i]; };\r\n\tvalue_type\
    \ & operator ()(size_type i, size_type j) noexcept { return val[i][j]; };\r\n\t\
    const value_type & operator ()(size_type i, size_type j) const noexcept { return\
    \ val[i][j]; }\r\n\tvalue_type & at(size_type i, size_type j) {\r\n\t\tassert(i\
    \ < h && j < w);\r\n\t\treturn val[i][j];\r\n\t}\r\n\tconst value_type & at(size_type\
    \ i, size_type j) const {\r\n\t\tassert(i < h & j < w);\r\n\t\treturn val[i][j];\r\
    \n\t}\r\n\t\r\n\tbool empty() const { return !(h || w); }\r\n\tstd::pair<size_type,\
    \ size_type> type() const { return std::make_pair(h, w); }\r\n\tbool match_type(const\
    \ Matrix & rhs) const noexcept { return h == rhs.h && w == rhs.w; }\r\n\tbool\
    \ is_square() const { return h == w; }\r\n\tconst std::vector<std::vector<value_type>>\
    \ & get() const noexcept { return val; }\r\n\t\r\n\tbool operator ==(const Matrix\
    \ & rhs) const noexcept { return match_type(rhs) && val == rhs.val; }\r\n\tbool\
    \ operator !=(const Matrix & rhs) const noexcept { return !(*this == rhs); }\r\
    \n\tMatrix operator +() const { return Matrix(*this); }\r\n\tMatrix operator -()\
    \ const { return Matrix(h, w) - Matrix(*this); }\r\n\tMatrix operator +(const\
    \ Matrix & rhs) const { return Matrix(*this) += rhs; }\r\n\tMatrix operator -(const\
    \ Matrix & rhs) const { return Matrix(*this) -= rhs; }\r\n\tMatrix operator *(const\
    \ Matrix & rhs) const {\r\n\t\tassert(w == rhs.h);\r\n\t\tMatrix res(h, rhs.w);\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < rhs.w; ++j)\
    \ for (size_type k = 0; k < w; ++k)\r\n\t\t\tres.val[i][j] += val[i][k] * rhs.val[k][j];\r\
    \n\t\treturn res;\r\n\t}\r\n\tMatrix operator /(const Matrix & rhs) const { return\
    \ Matrix(*this) /= rhs; }\r\n\tfriend Matrix operator *(const value_type & lhs,\
    \ const Matrix & rhs) {\r\n\t\tMatrix res(rhs.val);\r\n\t\tfor (size_type i =\
    \ 0; i < res.h; ++i) for (size_type j = 0; j < res.w; ++j)\r\n\t\t\tres.val[i][j]\
    \ = lhs * res.val[i][j];\r\n\t\treturn res;\r\n\t}\r\n\tMatrix operator *(const\
    \ value_type & rhs) const {\r\n\t\tMatrix res(val);\r\n\t\tfor (size_type i =\
    \ 0; i < h; ++i) for (size_type j = 0; j < w; ++j)\r\n\t\t\tres.val[i][j] *= rhs;\r\
    \n\t\treturn res;\r\n\t}\r\n\tMatrix operator /(const value_type & rhs) const\
    \ {\r\n\t\tMatrix res(val);\r\n\t\tfor (size_type i = 0; i < h; ++i) for (size_type\
    \ j = 0; j < w; ++j)\r\n\t\t\tres.val[i][j] /= rhs;\r\n\t\treturn res;\r\n\t}\r\
    \n\tMatrix & operator +=(const Matrix & rhs) {\r\n\t\tassert(match_type(rhs));\r\
    \n\t\tfor (size_type i = 0; i < h; ++i) for (size_type j = 0; j < w; ++j)\r\n\t\
    \t\tval[i][j] += rhs.val[i][j];\r\n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator\
    \ -=(const Matrix & rhs) {\r\n\t\tassert(match_type(rhs));\r\n\t\tfor (size_type\
    \ i = 0; i < h; ++i) for(size_type j = 0; j < w; ++j)\r\n\t\t\tval[i][j] -= rhs.val[i][j];\r\
    \n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator *=(const Matrix & rhs) {\r\n\
    \t\t*this = *this * rhs;\r\n\t\treturn *this;\r\n\t}\r\n\tMatrix & operator /=(const\
    \ Matrix & rhs) {\r\n\t\t*this *= rhs.inverse();\r\n\t\treturn *this;\r\n\t}\r\
    \n\t\r\n\tMatrix pow(long long n) const {\r\n\t\tMatrix res = identity(h), x(*this);\r\
    \n\t\tif (n < 0) { x = x.inverse(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res\
    \ *= x; x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix trans()\
    \ const {\r\n\t\tMatrix res(w, h);\r\n\t\tfor (size_type i = 0; i < h; ++i) for\
    \ (size_type j = 0; j < w; ++j)\r\n\t\t\tres.val[j][i] = val[i][j];\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix inverse() const {\r\n\t\tassert(is_square());\r\
    \n\t\tMatrix aug_mat = this->hstack(identity(h));\r\n\t\tif (aug_mat.gauss_jordan().first\
    \ != h) return Matrix();\r\n\t\treturn aug_mat.submat(0, w, h, 2 * w);\r\n\t}\r\
    \n\t\r\n\tMatrix vstack(const Matrix & A) const {\r\n\t\tassert(w == A.w);\r\n\
    \t\tMatrix res(h + A.h, w);\r\n\t\tstd::copy(val.begin(), val.end(), res.val.begin());\r\
    \n\t\tstd::copy(A.val.begin(), A.val.end(), res.val.begin() + h);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\n\tMatrix hstack(const Matrix & A) const {\r\n\t\tassert(h\
    \ == A.h);\r\n\t\tMatrix res(h, w + A.w);\r\n\t\tfor (int i = 0; i < h; ++i) {\r\
    \n\t\t\tstd::copy(val[i].begin(), val[i].end(), res.val[i].begin());\r\n\t\t\t\
    std::copy(A.val[i].begin(), A.val[i].end(), res.val[i].begin() + w);\r\n\t\t}\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\n\tMatrix submat(size_type i1, size_type j1,\
    \ size_type i2, size_type j2) const {\r\n\t\tassert(i1 < i2 && j1 < j2 && i2 <=\
    \ h && j2 <= w);\r\n\t\tMatrix res(i2 - i1, j2 - j1);\r\n\t\tfor (size_type i\
    \ = 0; i < i2 - i1; ++i)\r\n\t\t\tstd::copy(val[i + i1].begin() + j1, val[i +\
    \ i1].begin() + j2, res.val[i].begin());\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    static Matrix identity(size_type n) {\r\n\t\tMatrix res(n, n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) res(i, i) = 1;\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<size_type,\
    \ value_type> gauss_jordan(size_type colnum = -1) {\r\n\t\tif (colnum == -1) colnum\
    \ = w;\r\n\t\tsize_type rank = 0;\r\n\t\tvalue_type det {};\r\n\t\tbool done =\
    \ false, rflag = false;\r\n\t\t\r\n\t\tfor (size_type k = 0; k < colnum; ++k)\
    \ {\r\n\t\t\tsize_type pivot = -1;\r\n\t\t\tfor (size_type i = rank; i < h; ++i)\
    \ {\r\n\t\t\t\tif (val[i][k] != 0) {\r\n\t\t\t\t\tpivot = i;\r\n\t\t\t\t\tbreak;\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (pivot == -1) continue;\r\n\t\t\tif (pivot\
    \ != rank) {\r\n\t\t\t\trflag ^= 1;\r\n\t\t\t\tstd::swap(val[rank], val[pivot]);\r\
    \n\t\t\t}\r\n\t\t\t\r\n\t\t\tif (!done) { det = val[rank][k]; done = true; }\r\
    \n\t\t\telse det *= val[rank][k];\r\n\t\t\t\r\n\t\t\tvalue_type div = static_cast<value_type>(1)\
    \ / val[rank][k];\r\n\t\t\tfor (size_type j = k; j < w; ++j) val[rank][j] *= div;\r\
    \n\t\t\t\r\n\t\t\tfor (size_type i = 0; i < h; ++i) if (i != rank) {\r\n\t\t\t\
    \tfor (size_type j = k + 1; j < w; ++j) val[i][j] -= val[rank][j] * val[i][k];\r\
    \n\t\t\t\t\tval[i][k] = 0;\r\n\t\t\t}\r\n\t\t\t++rank;\r\n\t\t}\r\n\t\t\r\n\t\t\
    if (!is_square() || rank != h) det = 0;\r\n\t\telse if (rflag) det *= -1;\r\n\t\
    \t\r\n\t\treturn {rank, det};\r\n\t}\r\n\t\r\n\tfriend std::ostream & operator\
    \ <<(std::ostream & os, const Matrix & rhs) {\r\n\t\tos << \"type = (\" << rhs.h\
    \ << \",\" << rhs.w << \") [\\n\";\r\n\t\tfor (size_type i = 0; i < rhs.h; ++i)\
    \ for (size_type j = 0; j < rhs.w; ++j)\r\n\t\t\tos << (j == 0 ? \" \" : \"\"\
    ) << rhs.val[i][j] << (j + 1 == rhs.w ? '\\n' : ' ');\r\n\t\treturn os << \"]\"\
    ;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ val;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_MATRIX_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Matrix.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Matrix_Determinant.test.cpp
documentation_of: Mathematics/Matrix.hpp
layout: document
redirect_from:
- /library/Mathematics/Matrix.hpp
- /library/Mathematics/Matrix.hpp.html
title: Mathematics/Matrix.hpp
---
