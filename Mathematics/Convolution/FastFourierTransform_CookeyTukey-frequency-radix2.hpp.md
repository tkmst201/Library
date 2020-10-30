---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform_CookeyTukey-frequency-radix2.test.cpp
    title: Test/FastFourierTransform_CookeyTukey-frequency-radix2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,
  bundledCode: "#line 1 \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/08/02\r\n\r\n\u57FA\u6570 2 \u5468\u6CE2\u6570\
    \u9593\u5F15\u304D Cooley-Tukey\r\n\r\n# \u89E3\u8AAC\r\nN \u3092 2 \u51AA\u3068\
    \u3057\u3066 f[0], f[1], \\ldots, f[N - 1] \u304C\u65E2\u77E5\r\n\r\n\\omega_N\
    \ := 1 \u306E\u539F\u59CB N \u4E57\u6839\r\n\r\nF[z] := \\Sum_{k = 0}^{N - 1}\
    \ f[k] z^k\r\nF[\\omega_N^{-i}] = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-ki}\r\
    \n\u3067 i \u306E\u5076\u5947\u3067\u5206\u3051\u308B\u3002\r\n\r\n0 \\leq i <\
    \ N/2 \u3068\u3057\u3066\r\nF[\\omega_N^{-2i}]       = \\Sum_{k = 0}^{N/2 - 1}\
    \ (f[k] + f[k + N/2]) \\omega_{N/2}^{-ki}\r\nF[\\omega_N^{-(2i + 1)}] = \\Sum_{k\
    \ = 0}^{N/2 - 1} (f[k] - f[k + N/2]) \\omega_{N/2}^{-ki}\r\n\r\n\u8A08\u7B97\u7D50\
    \u679C\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\u3057\u305F\u4F4D\u7F6E\u306B\u306A\
    \u3063\u3066\u3044\u308B\u306E\u3067\u6700\u5F8C\u306B\u4FEE\u6B63\u3059\u308B\
    \u3002\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type>\
    \ multiply(const std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log\
    \ n)\r\n\t2 \u3064\u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\
    \u3002\r\n\r\n# \u53C2\u8003\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/05/02\r\n*/\r\n\r\n#include <vector>\r\n#include <complex>\r\n#include\
    \ <algorithm>\r\n\r\nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type\
    \ = double;\r\n\tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a, b;\r\n\t\ta.reserve(n),\
    \ b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i],\
    \ 0);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);\r\
    \n\t\ta.resize(n); fft(a, zeta);\r\n\t\tb.resize(n); fft(b, zeta);\r\n\t\t\r\n\
    \t\tstd::vector<complex_type> c;\r\n\t\tc.reserve(n);\r\n\t\tfor (size_type i\
    \ = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));\r\n\t\tfft(c, zeta);\r\
    \n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type>\
    \ &A, const std::vector<complex_type> &zeta) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\t\r\n\
    \t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);\r\
    \n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > A.size()) --ni;\r\n\t\t\r\n\t\
    \tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type m = n\
    \ >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
    \ i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tconst complex_type a = A[i],\
    \ b = A[i + m];\r\n\t\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = (a - b) * zeta[(i\
    \ - p) << (zi - ni)];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tbit_reverse(A);\r\
    \n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> &A) {\r\n\t\
    \tconst size_type N = A.size();\r\n\t\tfor (size_type i = 1, j = 0; i < N - 1;\
    \ ++i) {\r\n\t\t\tfor (size_type k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\t\
    if (i < j) std::swap(A[i], A[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ _zeta(size_type max_p) {\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t// zeta[j] := \\omega_{2^max_p}^j (0 \\leq j < 2^(max_p - 1))\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << max_p - 1);\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (size_type i = 0; i < max_p - 1; ++i) {\r\n\t\t\tconst value_type rad\
    \ = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);\r\
    \n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\n\t\t\tfor (size_type\
    \ j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\t\t\tzeta.emplace_back(zeta[1\
    \ << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn zeta;\r\n\t}\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP\r\
    \n#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/02\r\n\r\n\u57FA\u6570 2 \u5468\u6CE2\u6570\u9593\
    \u5F15\u304D Cooley-Tukey\r\n\r\n# \u89E3\u8AAC\r\nN \u3092 2 \u51AA\u3068\u3057\
    \u3066 f[0], f[1], \\ldots, f[N - 1] \u304C\u65E2\u77E5\r\n\r\n\\omega_N := 1\
    \ \u306E\u539F\u59CB N \u4E57\u6839\r\n\r\nF[z] := \\Sum_{k = 0}^{N - 1} f[k]\
    \ z^k\r\nF[\\omega_N^{-i}] = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-ki}\r\n\u3067\
    \ i \u306E\u5076\u5947\u3067\u5206\u3051\u308B\u3002\r\n\r\n0 \\leq i < N/2 \u3068\
    \u3057\u3066\r\nF[\\omega_N^{-2i}]       = \\Sum_{k = 0}^{N/2 - 1} (f[k] + f[k\
    \ + N/2]) \\omega_{N/2}^{-ki}\r\nF[\\omega_N^{-(2i + 1)}] = \\Sum_{k = 0}^{N/2\
    \ - 1} (f[k] - f[k + N/2]) \\omega_{N/2}^{-ki}\r\n\r\n\u8A08\u7B97\u7D50\u679C\
    \u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\u3057\u305F\u4F4D\u7F6E\u306B\u306A\u3063\
    \u3066\u3044\u308B\u306E\u3067\u6700\u5F8C\u306B\u4FEE\u6B63\u3059\u308B\u3002\
    \r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type>\
    \ multiply(const std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log\
    \ n)\r\n\t2 \u3064\u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\
    \u3002\r\n\r\n# \u53C2\u8003\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/05/02\r\n*/\r\n\r\n#include <vector>\r\n#include <complex>\r\n#include\
    \ <algorithm>\r\n\r\nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type\
    \ = double;\r\n\tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a, b;\r\n\t\ta.reserve(n),\
    \ b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i],\
    \ 0);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);\r\
    \n\t\ta.resize(n); fft(a, zeta);\r\n\t\tb.resize(n); fft(b, zeta);\r\n\t\t\r\n\
    \t\tstd::vector<complex_type> c;\r\n\t\tc.reserve(n);\r\n\t\tfor (size_type i\
    \ = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));\r\n\t\tfft(c, zeta);\r\
    \n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real() / static_cast<value_type>(n));\r\
    \n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type>\
    \ &A, const std::vector<complex_type> &zeta) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\t\r\n\
    \t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size(); i <<= 1, ++zi);\r\
    \n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > A.size()) --ni;\r\n\t\t\r\n\t\
    \tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type m = n\
    \ >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
    \ i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tconst complex_type a = A[i],\
    \ b = A[i + m];\r\n\t\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = (a - b) * zeta[(i\
    \ - p) << (zi - ni)];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tbit_reverse(A);\r\
    \n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> &A) {\r\n\t\
    \tconst size_type N = A.size();\r\n\t\tfor (size_type i = 1, j = 0; i < N - 1;\
    \ ++i) {\r\n\t\t\tfor (size_type k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\t\
    if (i < j) std::swap(A[i], A[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ _zeta(size_type max_p) {\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t// zeta[j] := \\omega_{2^max_p}^j (0 \\leq j < 2^(max_p - 1))\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << max_p - 1);\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (size_type i = 0; i < max_p - 1; ++i) {\r\n\t\t\tconst value_type rad\
    \ = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);\r\
    \n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\n\t\t\tfor (size_type\
    \ j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\t\t\tzeta.emplace_back(zeta[1\
    \ << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn zeta;\r\n\t}\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform_CookeyTukey-frequency-radix2.test.cpp
documentation_of: Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp
- /library/Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp.html
title: Mathematics/Convolution/FastFourierTransform_CookeyTukey-frequency-radix2.hpp
---
