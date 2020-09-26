---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform_CookeyTukey-radix2.test.cpp
    title: Test/FastFourierTransform_CookeyTukey-radix2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/08/02\r\n\r\n\u57FA\u6570 2 Cooley-Tukey\r\n\
    \r\n# \u89E3\u8AAC\r\n\u5468\u6CE2\u6570\u9593\u5F15\u304D\u3067 FFT \u3092\u884C\
    \u3063\u305F\u3042\u3068\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\u3057\u305F\u4F4D\
    \u7F6E\u306B\u306A\u3063\u3066\u3044\u308B\u3002\r\n\u305D\u306E\u307E\u307E\u6642\
    \u9593\u9593\u5F15\u304D\u3067 FFT \u3092\u884C\u3046\u3053\u3068\u3067\u30D3\u30C3\
    \u30C8\u53CD\u8EE2\u306E\u51E6\u7406\u304C\u4E0D\u8981\u306B\u306A\u308B\u3002\
    \r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic std::vector<value_type>\
    \ multiply(const std::vector<T> &A, const std::vector<T> &B) :\r\n\t\u03B8(n log\
    \ n)\r\n\t2 \u3064\u306E\u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\
    \u3002\r\n\t\r\n# \u53C2\u8003\r\n\u5468\u6CE2\u6570\u9593\u5F15\u304D FFT \u3068\
    \ \u6642\u9593\u9593\u5F15\u304D FFT \u305D\u308C\u305E\u308C\u53C2\u7167\r\n\
    */\r\n\r\n#include <vector>\r\n#include <complex>\r\n#include <algorithm>\r\n\r\
    \nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type = double;\r\n\
    \tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst std::vector<complex_type>\
    \ zeta = _zeta(ni);\r\n\t\t\r\n\t\tstd::vector<complex_type> a, b;\r\n\t\ta.reserve(n),\
    \ b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i],\
    \ 0);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);\r\
    \n\t\ta.resize(n); fft_frequency(a, zeta);\r\n\t\tb.resize(n); fft_frequency(b,\
    \ zeta);\r\n\t\t\r\n\t\tstd::vector<complex_type> c;\r\n\t\tc.reserve(n);\r\n\t\
    \tfor (size_type i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));\r\n\
    \t\tfft_time(c, zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\
    \n\t\tfor (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real()\
    \ / static_cast<value_type>(n));\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic void fft_frequency(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > N) --ni;\r\
    \n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type\
    \ m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
    \ i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tconst complex_type a = A[i],\
    \ b = A[i + m];\r\n\t\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = (a - b) * zeta[(i\
    \ - p) << (zi - ni)];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic\
    \ void fft_time(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 0;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\t\r\n\t\tfor (size_type n = 2; n <= N; n <<= 1, --zi)\
    \ {\r\n\t\t\tconst size_type m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N;\
    \ p += n) {\r\n\t\t\t\tfor (size_type i = p, ei = p + m; i != ei; ++i) {\r\n\t\
    \t\t\t\tconst complex_type a = A[i], b = A[i + m] * zeta[(i - p) << zi];\r\n\t\
    \t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = a - b;\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type> _zeta(size_type max_p)\
    \ {\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\
    \t// zeta[j] := \\omega_{2^max_p}^j (0 \\leq j < 2^(max_p - 1))\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << max_p - 1);\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (size_type i = 0; i < max_p - 1; ++i) {\r\n\t\t\tconst value_type rad\
    \ = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);\r\
    \n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\n\t\t\tfor (size_type\
    \ j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\t\t\tzeta.emplace_back(zeta[1\
    \ << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn zeta;\r\n\t}\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HPP\r\n\
    #define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HPP\r\n\r\n/*\r\
    \nlast-updated: 2020/08/02\r\n\r\n\u57FA\u6570 2 Cooley-Tukey\r\n\r\n# \u89E3\u8AAC\
    \r\n\u5468\u6CE2\u6570\u9593\u5F15\u304D\u3067 FFT \u3092\u884C\u3063\u305F\u3042\
    \u3068\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\u3057\u305F\u4F4D\u7F6E\u306B\u306A\
    \u3063\u3066\u3044\u308B\u3002\r\n\u305D\u306E\u307E\u307E\u6642\u9593\u9593\u5F15\
    \u304D\u3067 FFT \u3092\u884C\u3046\u3053\u3068\u3067\u30D3\u30C3\u30C8\u53CD\u8EE2\
    \u306E\u51E6\u7406\u304C\u4E0D\u8981\u306B\u306A\u308B\u3002\r\n\r\n# \u4ED5\u69D8\
    \r\ntemplate<typename T>\r\nstatic std::vector<value_type> multiply(const std::vector<T>\
    \ &A, const std::vector<T> &B) :\r\n\t\u03B8(n log n)\r\n\t2 \u3064\u306E\u591A\
    \u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\u3002\r\n\t\r\n# \u53C2\u8003\
    \r\n\u5468\u6CE2\u6570\u9593\u5F15\u304D FFT \u3068 \u6642\u9593\u9593\u5F15\u304D\
    \ FFT \u305D\u308C\u305E\u308C\u53C2\u7167\r\n*/\r\n\r\n#include <vector>\r\n\
    #include <complex>\r\n#include <algorithm>\r\n\r\nstruct FastFourierTransform\
    \ {\r\npublic:\r\n\tusing value_type = double;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing complex_type = std::complex<value_type>;\r\n\t\r\n\ttemplate<typename\
    \ T>\r\n\tstatic std::vector<value_type> multiply(const std::vector<T> &A, const\
    \ std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty()) return {};\r\n\t\tsize_type\
    \ n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n = 1, ni = 0;\r\n\t\twhile (n\
    \ < n_) n <<= 1, ++ni;\r\n\t\tconst std::vector<complex_type> zeta = _zeta(ni);\r\
    \n\t\t\r\n\t\tstd::vector<complex_type> a, b;\r\n\t\ta.reserve(n), b.reserve(n);\r\
    \n\t\tfor (size_type i = 0; i < A.size(); ++i) a.emplace_back(A[i], 0);\r\n\t\t\
    for (size_type i = 0; i < B.size(); ++i) b.emplace_back(B[i], 0);\r\n\t\ta.resize(n);\
    \ fft_frequency(a, zeta);\r\n\t\tb.resize(n); fft_frequency(b, zeta);\r\n\t\t\r\
    \n\t\tstd::vector<complex_type> c;\r\n\t\tc.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) c.emplace_back(std::conj(a[i] * b[i]));\r\n\t\tfft_time(c,\
    \ zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\n\
    \t\tfor (size_type i = 0; i < n; ++i) res.emplace_back(std::conj(c[i]).real()\
    \ / static_cast<value_type>(n));\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic void fft_frequency(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > N) --ni;\r\
    \n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type\
    \ m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
    \ i = p, ei = p + m; i != ei; ++i) {\r\n\t\t\t\t\tconst complex_type a = A[i],\
    \ b = A[i + m];\r\n\t\t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = (a - b) * zeta[(i\
    \ - p) << (zi - ni)];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic\
    \ void fft_time(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 0;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\t\r\n\t\tfor (size_type n = 2; n <= N; n <<= 1, --zi)\
    \ {\r\n\t\t\tconst size_type m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N;\
    \ p += n) {\r\n\t\t\t\tfor (size_type i = p, ei = p + m; i != ei; ++i) {\r\n\t\
    \t\t\t\tconst complex_type a = A[i], b = A[i + m] * zeta[(i - p) << zi];\r\n\t\
    \t\t\t\tA[i] = a + b;\r\n\t\t\t\t\tA[i + m] = a - b;\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type> _zeta(size_type max_p)\
    \ {\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\n\t\
    \t// zeta[j] := \\omega_{2^max_p}^j (0 \\leq j < 2^(max_p - 1))\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << max_p - 1);\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (size_type i = 0; i < max_p - 1; ++i) {\r\n\t\t\tconst value_type rad\
    \ = static_cast<value_type>(-2) * PI / static_cast<value_type>(1 << max_p - i);\r\
    \n\t\t\tzeta.emplace_back(std::polar<value_type>(1, rad));\r\n\t\t\tfor (size_type\
    \ j = (1 << i) + 1, ej = 1 << i + 1; j != ej; ++j) {\r\n\t\t\t\tzeta.emplace_back(zeta[1\
    \ << i ^ j] * zeta[1 << i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn zeta;\r\n\t}\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_COOLEY_TUKEY_RADIX2_HP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform_CookeyTukey-radix2.test.cpp
documentation_of: Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp
- /library/Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp.html
title: Mathematics/Convolution/FastFourierTransform_CookeyTukey-radix2.hpp
---
