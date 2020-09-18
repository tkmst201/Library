---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform_Real_CooleyTukey-time-radix4.test.cpp
    title: Test/FastFourierTransform_Real_CooleyTukey-time-radix4.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <complex>\r\n#include <algorithm>\r\n\r\
    \n/*\r\nlast-updated: 2020/08/04\r\n\r\n\u5B9F\u6570\u306E\u7573\u307F\u8FBC\u307F\
    \r\n\u57FA\u6570 4 \u5468\u6CE2\u6570\u9593\u5F15\u304D Cooley-Tukey\r\n\r\n\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u5185\u3067\u306F\u4E00\u756A\u9AD8\u901F(\u306E\u306F\
    \u305A)\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type>\
    \ multiply(const std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log\
    \ n)\r\n\t2 \u3064\u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\
    \u3002\r\n\r\n# \u53C2\u8003\r\n\u57FA\u6570 4 \u306E\u6642\u9593\u9593\u5F15\u304D\
    \ FFT\r\n\u5B9F\u6570\u306E\u7573\u307F\u8FBC\u307F\r\n*/\r\n\r\nstruct FastFourierTransform\
    \ {\r\npublic:\r\n\tusing value_type = double;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing complex_type = std::complex<value_type>;\r\n\t\r\n\ttemplate<typename\
    \ T>\r\n\tstatic std::vector<value_type> multiply(const std::vector<T> &A, const\
    \ std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty()) return {};\r\n\t\tsize_type\
    \ n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n = 1, ni = 0;\r\n\t\twhile (n\
    \ < n_) n <<= 1, ++ni;\r\n\t\tconst size_type m = n >> 1;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a;\r\n\t\ta.resize(n);\r\
    \n\t\tfor (size_type i = 0; i < A.size(); ++i) a[i].real(A[i]);\r\n\t\tfor (size_type\
    \ i = 0; i < B.size(); ++i) a[i].imag(B[i]);\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\
    \tstd::vector<complex_type> c;\r\n\t\tc.reserve(m + 1);\r\n\t\tc.emplace_back(a[0].real()\
    \ * a[0].imag(), 0);\r\n\t\tfor (size_type i = 1; i != m; ++i) {\r\n\t\t\tconst\
    \ complex_type a_conj = std::conj(a[n - i]);\r\n\t\t\tconst complex_type prod\
    \ = (a[i] + a_conj) * (a[i] - a_conj) / 4.0;\r\n\t\t\tc.emplace_back(prod.imag(),\
    \ -prod.real());\r\n\t\t}\r\n\t\tc.emplace_back(a[m].real() * a[m].imag(), 0);\r\
    \n\t\t\r\n\t\ta.resize(m);\r\n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\t\
    const complex_type c_conj = std::conj(c[m - i]);\r\n\t\t\tconst complex_type e\
    \ = (c[i] + c_conj) / 2.0;\r\n\t\t\tconst complex_type o = (c[i] - c_conj) * std::conj(zeta[i])\
    \ / 2.0;\r\n\t\t\ta[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());\r\
    \n\t\t}\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\
    \tres.reserve(n);\r\n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tres.emplace_back(a[i].real()\
    \ / static_cast<value_type>(m));\r\n\t\t\tres.emplace_back(-a[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type>\
    \ &A, const std::vector<complex_type> &zeta) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\t\r\n\
    \t\tsize_type zi = 0;\r\n\t\tfor (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);\r\
    \n\t\t\r\n\t\tbit_reverse(A);\r\n\t\tsize_type n;\r\n\t\tfor (n = 4; n <= N; n\
    \ <<= 2) {\r\n\t\t\tzi -= 2;\r\n\t\t\tsize_type m = n >> 2;\r\n\t\t\t// \\omega_n^k\
    \ = zeta[k << zi]\r\n\t\t\tsize_type p;\r\n\t\t\tfor (p = 0; p < N; p += n) {\r\
    \n\t\t\t\tfor (size_type i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tcomplex_type\
    \ a0 = A[i], a2 = A[i + m] * zeta[(i - p) << (zi + 1)];\r\n\t\t\t\t\tcomplex_type\
    \ a1 = A[i + (m << 1)] * zeta[(i - p) << zi], a3 = A[i + n - m] * zeta[3 * (i\
    \ - p) << zi];\r\n\t\t\t\t\t\r\n\t\t\t\t\tcomplex_type lp = a0 + a2, ln = a0 -\
    \ a2;\r\n\t\t\t\t\tcomplex_type rp = a1 + a3, rn = a1 - a3;\r\n\t\t\t\t\tA[i]\
    \ = lp + rp;\r\n\t\t\t\t\tA[i + m] = complex_type(ln.real() + rn.imag(), ln.imag()\
    \ - rn.real());\r\n\t\t\t\t\tA[i + (m << 1)] = lp - rp;\r\n\t\t\t\t\tA[i + n -\
    \ m] = complex_type(ln.real() - rn.imag(), ln.imag() + rn.real());\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tif (n >> 2 < N) {\r\n\t\t\t--zi;\r\n\t\t\t\
    for (size_type i = 0, m = N >> 1; i != m; ++i) {\r\n\t\t\t\tconst complex_type\
    \ a = A[i], b = A[i + m] * zeta[i << zi];\r\n\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\
    A[i + m] = a - b;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type>\
    \ &A) {\r\n\t\tconst size_type N = A.size();\r\n\t\tfor (size_type i = 1, j =\
    \ 0; i < N - 1; ++i) {\r\n\t\t\tfor (size_type k = N >> 1; k > (j ^= k); k >>=\
    \ 1);\r\n\t\t\tif (i < j) std::swap(A[i], A[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic\
    \ std::vector<complex_type> _zeta(size_type max_p) {\r\n\t\tconst value_type PI\
    \ = std::acos(static_cast<value_type>(-1));\r\n\t\t// zeta[j] := \\omega_{2^max_p}^j\r\
    \n\t\tstd::vector<complex_type> zeta;\r\n\t\tzeta.reserve(1 << max_p);\r\n\t\t\
    zeta.emplace_back(1, 0);\r\n\t\tfor (size_type i = 0; i < max_p; ++i) {\r\n\t\t\
    \tconst value_type rad = static_cast<value_type>(-2) * PI / static_cast<value_type>(1\
    \ << max_p - i);\r\n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\
    \n\t\t\tfor (size_type j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\
    \t\t\tzeta.emplace_back(zeta[1 << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\treturn zeta;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_TIME_RADIX4_HPP\r\
    \n#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_TIME_RADIX4_HPP\r\
    \n\r\n#include <vector>\r\n#include <complex>\r\n#include <algorithm>\r\n\r\n\
    /*\r\nlast-updated: 2020/08/04\r\n\r\n\u5B9F\u6570\u306E\u7573\u307F\u8FBC\u307F\
    \r\n\u57FA\u6570 4 \u5468\u6CE2\u6570\u9593\u5F15\u304D Cooley-Tukey\r\n\r\n\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u5185\u3067\u306F\u4E00\u756A\u9AD8\u901F(\u306E\u306F\
    \u305A)\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type>\
    \ multiply(const std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log\
    \ n)\r\n\t2 \u3064\u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\
    \u3002\r\n\r\n# \u53C2\u8003\r\n\u57FA\u6570 4 \u306E\u6642\u9593\u9593\u5F15\u304D\
    \ FFT\r\n\u5B9F\u6570\u306E\u7573\u307F\u8FBC\u307F\r\n*/\r\n\r\nstruct FastFourierTransform\
    \ {\r\npublic:\r\n\tusing value_type = double;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing complex_type = std::complex<value_type>;\r\n\t\r\n\ttemplate<typename\
    \ T>\r\n\tstatic std::vector<value_type> multiply(const std::vector<T> &A, const\
    \ std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty()) return {};\r\n\t\tsize_type\
    \ n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n = 1, ni = 0;\r\n\t\twhile (n\
    \ < n_) n <<= 1, ++ni;\r\n\t\tconst size_type m = n >> 1;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a;\r\n\t\ta.resize(n);\r\
    \n\t\tfor (size_type i = 0; i < A.size(); ++i) a[i].real(A[i]);\r\n\t\tfor (size_type\
    \ i = 0; i < B.size(); ++i) a[i].imag(B[i]);\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\
    \tstd::vector<complex_type> c;\r\n\t\tc.reserve(m + 1);\r\n\t\tc.emplace_back(a[0].real()\
    \ * a[0].imag(), 0);\r\n\t\tfor (size_type i = 1; i != m; ++i) {\r\n\t\t\tconst\
    \ complex_type a_conj = std::conj(a[n - i]);\r\n\t\t\tconst complex_type prod\
    \ = (a[i] + a_conj) * (a[i] - a_conj) / 4.0;\r\n\t\t\tc.emplace_back(prod.imag(),\
    \ -prod.real());\r\n\t\t}\r\n\t\tc.emplace_back(a[m].real() * a[m].imag(), 0);\r\
    \n\t\t\r\n\t\ta.resize(m);\r\n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\t\
    const complex_type c_conj = std::conj(c[m - i]);\r\n\t\t\tconst complex_type e\
    \ = (c[i] + c_conj) / 2.0;\r\n\t\t\tconst complex_type o = (c[i] - c_conj) * std::conj(zeta[i])\
    \ / 2.0;\r\n\t\t\ta[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());\r\
    \n\t\t}\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\
    \tres.reserve(n);\r\n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tres.emplace_back(a[i].real()\
    \ / static_cast<value_type>(m));\r\n\t\t\tres.emplace_back(-a[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type>\
    \ &A, const std::vector<complex_type> &zeta) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\t\r\n\
    \t\tsize_type zi = 0;\r\n\t\tfor (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);\r\
    \n\t\t\r\n\t\tbit_reverse(A);\r\n\t\tsize_type n;\r\n\t\tfor (n = 4; n <= N; n\
    \ <<= 2) {\r\n\t\t\tzi -= 2;\r\n\t\t\tsize_type m = n >> 2;\r\n\t\t\t// \\omega_n^k\
    \ = zeta[k << zi]\r\n\t\t\tsize_type p;\r\n\t\t\tfor (p = 0; p < N; p += n) {\r\
    \n\t\t\t\tfor (size_type i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tcomplex_type\
    \ a0 = A[i], a2 = A[i + m] * zeta[(i - p) << (zi + 1)];\r\n\t\t\t\t\tcomplex_type\
    \ a1 = A[i + (m << 1)] * zeta[(i - p) << zi], a3 = A[i + n - m] * zeta[3 * (i\
    \ - p) << zi];\r\n\t\t\t\t\t\r\n\t\t\t\t\tcomplex_type lp = a0 + a2, ln = a0 -\
    \ a2;\r\n\t\t\t\t\tcomplex_type rp = a1 + a3, rn = a1 - a3;\r\n\t\t\t\t\tA[i]\
    \ = lp + rp;\r\n\t\t\t\t\tA[i + m] = complex_type(ln.real() + rn.imag(), ln.imag()\
    \ - rn.real());\r\n\t\t\t\t\tA[i + (m << 1)] = lp - rp;\r\n\t\t\t\t\tA[i + n -\
    \ m] = complex_type(ln.real() - rn.imag(), ln.imag() + rn.real());\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tif (n >> 2 < N) {\r\n\t\t\t--zi;\r\n\t\t\t\
    for (size_type i = 0, m = N >> 1; i != m; ++i) {\r\n\t\t\t\tconst complex_type\
    \ a = A[i], b = A[i + m] * zeta[i << zi];\r\n\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\
    A[i + m] = a - b;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type>\
    \ &A) {\r\n\t\tconst size_type N = A.size();\r\n\t\tfor (size_type i = 1, j =\
    \ 0; i < N - 1; ++i) {\r\n\t\t\tfor (size_type k = N >> 1; k > (j ^= k); k >>=\
    \ 1);\r\n\t\t\tif (i < j) std::swap(A[i], A[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic\
    \ std::vector<complex_type> _zeta(size_type max_p) {\r\n\t\tconst value_type PI\
    \ = std::acos(static_cast<value_type>(-1));\r\n\t\t// zeta[j] := \\omega_{2^max_p}^j\r\
    \n\t\tstd::vector<complex_type> zeta;\r\n\t\tzeta.reserve(1 << max_p);\r\n\t\t\
    zeta.emplace_back(1, 0);\r\n\t\tfor (size_type i = 0; i < max_p; ++i) {\r\n\t\t\
    \tconst value_type rad = static_cast<value_type>(-2) * PI / static_cast<value_type>(1\
    \ << max_p - i);\r\n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\
    \n\t\t\tfor (size_type j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\
    \t\t\tzeta.emplace_back(zeta[1 << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\treturn zeta;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_TIME_RADIX4_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform_Real_CooleyTukey-time-radix4.test.cpp
documentation_of: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp
- /library/Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp.html
title: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-time-radix4.hpp
---
