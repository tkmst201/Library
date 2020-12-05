---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Matrix.hpp
    title: Mathematics/Matrix.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/ModInt.hpp
    title: Mathematics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"Test/Matrix_Determinant.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \r\n\r\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/11/20\r\
    \n\r\n\u81EA\u52D5\u3067 mod \u3092\u53D6\u3063\u3066\u304F\u308C\u308B\u4FBF\u5229\
    \u306A\u3082\u306E\r\n\r\n# \u4ED5\u69D8\r\n\u57FA\u672C\u7684\u306A\u6F14\u7B97\
    \u306F\u3060\u3044\u305F\u3044\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\r\n\u6A19\
    \u6E96\u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0 std::cin, std::cout \u306B\
    \u3082\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\r\n\r\nconstexpr ModInt(std::int_fast64_t\
    \ val = 0)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8CA0\u306E\u6574\
    \u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\r\n\r\nconstexpr static decltype(M) mod() noexcept\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M \u3092\u8FD4\u3059\r\n\r\nconstexpr const\
    \ value_type & val() noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\
    \n\t\u5024\u3092 int \u3067\u8FD4\u3059\r\n\r\nconstexpr ModInt pow(std::int_fast64_t\
    \ n) const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5236\u7D04\
    : n < 0 \u306E\u3068\u304D\u3001inv() \u306E\u5236\u7D04\u306B\u5F93\u3046\u3002\
    \r\n\tn \u4E57\u3057\u305F\u5024\u3092\u8FD4\u3059(n < 0 \u306B\u3082\u5BFE\u5FDC\
    )\r\n\r\nconstexpr ModInt inv() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log M)\r\n\t\u5236\u7D04: \u5024\u3068 M \u304C\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B(M \u304C\u7D20\u6570\u306A\u3089\u554F\
    \u984C\u306F\u306A\u3044)\u3002\r\n\t\u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n#include <cstdint>\r\n\
    \r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\npublic:\r\
    \n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\n\t\r\n\
    private:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val < 0 ? (val % M + M) % M : val % M) {}\r\n\tconstexpr const\
    \ value_type & val() const noexcept { return val_; }\r\n\tconstexpr static decltype(M)\
    \ mod() noexcept { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const\
    \ noexcept { return val_; }\r\n\tconstexpr bool operator !() const noexcept {\
    \ return !static_cast<bool>(*this); }\r\n\tconstexpr ModInt operator +() const\
    \ noexcept { return ModInt(*this); }\r\n\tconstexpr ModInt operator -() const\
    \ noexcept { return ModInt(-val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept\
    \ { ModInt res = *this; ++*this; return res; }\r\n\tconstexpr ModInt operator\
    \ --(int) noexcept { ModInt res = *this; --*this; return res; }\r\n\tconstexpr\
    \ ModInt & operator ++() noexcept { val_ = val_ + 1 == M ? 0 : val_ + 1; return\
    \ *this; }\r\n\tconstexpr ModInt & operator --() noexcept { val_ = val_ == 0 ?\
    \ M - 1 : val_ - 1; return *this; }\r\n\tconstexpr ModInt & operator +=(const\
    \ ModInt & rhs) noexcept { val_ += val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ -\
    \ M; return *this; }\r\n\tconstexpr ModInt & operator -=(const ModInt & rhs) noexcept\
    \ { val_ += val_ >= rhs.val_ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\t\
    constexpr ModInt & operator *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_)\
    \ * rhs.val_ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt\
    \ & rhs) noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt\
    \ operator +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const\
    \ ModInt & rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr\
    \ ModInt operator *(const ModInt & lhs, const ModInt & rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\r\n\tfriend constexpr ModInt operator /(const ModInt &\
    \ lhs, const ModInt & rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend\
    \ constexpr bool operator ==(const ModInt & lhs, const ModInt & rhs) noexcept\
    \ { return lhs.val_ == rhs.val_; }\r\n\tfriend constexpr bool operator !=(const\
    \ ModInt & lhs, const ModInt & rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend\
    \ std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os\
    \ << rhs.val_; }\r\n\tfriend std::istream & operator >>(std::istream & is, ModInt\
    \ & rhs) { calc_type x; is >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr\
    \ ModInt pow(calc_type n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\
    \t\tif (n < 0) { x = x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x;\
    \ x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv()\
    \ const noexcept {\r\n\t\tvalue_type a = val_, a1 = 1, a2 = 0, b = M, b1 = 0,\
    \ b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q = a / b, r = a % b;\r\n\
    \t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\n\t\t\ta = b; b = r;\r\
    \n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/Matrix.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/04/13\r\n\r\n# \u4ED5\u69D8\r\nMatrix() : \u7A7A\
    \u306E\u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(size_type h, size_type w, const\
    \ value_type & x = 0) : \u578B(h, w) \u521D\u671F\u5024 x \u306E\u884C\u5217\u3092\
    \u4F5C\u6210\r\nMatrix(std::vector<std::vector<value_type>> val) : 2\u6B21\u5143\
    \ vector \u304B\u3089\u884C\u5217\u3092\u4F5C\u6210\r\nMatrix(std::initializer_list<std::vector<value_type>>\
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
    \n*/\r\n\r\n#line 61 \"Mathematics/Matrix.hpp\"\n#include <vector>\r\n#include\
    \ <utility>\r\n#include <type_traits>\r\n#include <initializer_list>\r\n#include\
    \ <algorithm>\r\n#include <cmath>\r\n\r\ntemplate<typename T>\r\nstruct Matrix\
    \ {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing size_type = std::size_t;\r\
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
    \ val;\r\n};\r\n\r\n\n#line 5 \"Test/Matrix_Determinant.test.cpp\"\n\r\n#line\
    \ 7 \"Test/Matrix_Determinant.test.cpp\"\n\r\nint main() {\r\n\tstd::cin.tie(0);\r\
    \n\tstd::ios::sync_with_stdio(false);\r\n\t\r\n\tint N;\r\n\tstd::cin >> N;\r\n\
    \tMatrix<ModInt<998244353>> mat(N, N);\r\n\tfor (int i = 0; i < N; ++i) for (int\
    \ j = 0; j < N; ++j) std::cin >> mat[i][j];\r\n\t\r\n\tstd::cout << mat.gauss_jordan().second\
    \ << std::endl;\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ \"Mathematics/ModInt.hpp\"\r\n#include \"Mathematics/Matrix.hpp\"\r\n\r\n#include\
    \ <iostream>\r\n\r\nint main() {\r\n\tstd::cin.tie(0);\r\n\tstd::ios::sync_with_stdio(false);\r\
    \n\t\r\n\tint N;\r\n\tstd::cin >> N;\r\n\tMatrix<ModInt<998244353>> mat(N, N);\r\
    \n\tfor (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> mat[i][j];\r\
    \n\t\r\n\tstd::cout << mat.gauss_jordan().second << std::endl;\r\n\treturn 0;\r\
    \n}\r\n"
  dependsOn:
  - Mathematics/ModInt.hpp
  - Mathematics/Matrix.hpp
  isVerificationFile: true
  path: Test/Matrix_Determinant.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 23:55:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Matrix_Determinant.test.cpp
layout: document
redirect_from:
- /verify/Test/Matrix_Determinant.test.cpp
- /verify/Test/Matrix_Determinant.test.cpp.html
title: Test/Matrix_Determinant.test.cpp
---
