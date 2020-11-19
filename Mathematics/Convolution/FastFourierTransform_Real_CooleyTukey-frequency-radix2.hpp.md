---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform_Real_CooleyTukey-frequency-radix2.test.cpp
    title: Test/FastFourierTransform_Real_CooleyTukey-frequency-radix2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,
    - https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79,
  bundledCode: "#line 1 \"Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n\u5B9F\u6570\u306E\u7573\u307F\
    \u8FBC\u307F\r\n\u57FA\u6570 2 \u5468\u6CE2\u6570\u9593\u5F15\u304D Cooley-Tukey\r\
    \n\r\n# \u89E3\u8AAC\r\n## \u5B9F\u6570\u5024\u95A2\u6570\u306E\u7573\u307F\u8FBC\
    \u307F\r\nN \u3092 2 \u51AA\u3068\u3057\u3066\r\n f[0], f[1], \\ldots, f[N - 1],\
    \ g[0], g[1], \\ldots, g[N - 1] \u304C\u65E2\u77E5\u3067 \"\u5B9F\u6570\"\r\n\r\
    \n\\omega_N := 1 \u306E\u539F\u59CB N \u4E57\u6839\r\n\r\nF[z] := \\Sum_{k = 0}^{N\
    \ - 1} f[k] z^k\r\nF[\\omega_N^{-j}] = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-kj}\r\
    \n\r\nconj(z) \u306F z \u306E\u8907\u7D20\u5171\u5F79\u3092\u8868\u3059\u3002\r\
    \n\r\nf[j] \u306F\u5B9F\u6570\u306A\u306E\u3067 conj(f[j]) = f[j] \u3088\u308A\
    \u3001\r\nF[\\omega_N^{-(N - j)}] = conj(F[\\omega_N^{-j}])\r\n\r\nh[k] := f[k]\
    \ + g[k] i ( i \u306F\u865A\u6570\u5358\u4F4D) (0 \\leq k < N)\r\n\r\nH[\\omega_N^{-j}]\
    \ = F[\\omega_N^{-j}] + G[\\omega_N^{-j}] i\r\nH[\\omega_N^{N - j}] = conj(F[\\\
    omega_N^{-j}]) - conj(G[\\omega_N^{-j}]) i\r\n\u3092\u9023\u7ACB\u3055\u305B\u3066\
    \u89E3\u304F\u3068\u3001\r\n\r\nF[\\omega_N^{-j}] = (H[\\omega_N^{-j}] + conj(H[\\\
    omega_N^{N - j}]) / 2\r\nG[\\omega_N^{-j}] = (H[\\omega_N^{-j}] - conj(H[\\omega_N^{N\
    \ - j}]) / 2i\r\n\u304C\u5F97\u3089\u308C\u308B\u3002( j = 0 \u306E\u3068\u304D\
    \ \\omega_N^N \u304C\u73FE\u308C\u308B\u3053\u3068\u306B\u6CE8\u610F)\r\n\r\n\
    ## \u5B9F\u6570\u5024\u95A2\u6570\u306E\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\
    \u63DB\r\n\u5B9F\u6570\u5024\u95A2\u6570\u306E\u7573\u307F\u8FBC\u307F\u306F\u5B9F\
    \u6570\u5024\u3067\u3042\u308B\u3053\u3068\u3092\u7528\u3044\u3066\u3001\u305D\
    \u306E\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\u304B\u3089\u7573\u307F\u8FBC\u307F\
    \u306E\u5024\u3092\u5FA9\u5143\u3059\u308B\u3002\r\n\r\nN \u3092 2 \u51AA\u3068\
    \u3057\u3066 f[0], f[1], \\ldots, f[N - 1] \u304C \"\u5B9F\u6570\"\r\nF[z] \u3092\
    \ f[k] \u306E\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\u3068\u3057\u3001\
    F[\\omega_N^{-j}] (0 \\leq j < N) \u304C\u65E2\u77E5\u306E\u5834\u5408\u3092\u8003\
    \u3048\u308B\u3002\r\n\r\nF[z] := \\Sum_{k = 0}^{N - 1} f[k] z^k\r\nF[\\omega_N^{-j}]\
    \ = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-kj}\r\n\r\n0 \\leq i < N/2 \u3068\u3057\
    \u3066\r\nF[\\omega_N^{-i}]         = \\Sum_{k = 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki}\
    \ + \\Sum_{k = 0}^{N/2 - 1} f[2k + 1] \\omega_{N/2}^{-ki}\r\nF[\\omega_N^{-(i\
    \ + N/2)}] = \\Sum_{k = 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki} - \\Sum_{k = 0}^{N/2\
    \ - 1} f[2k + 1] \\omega_{N/2}^{-ki}\r\n\u3067\u3042\u308B\u306E\u3067 f \u306E\
    \u6B21\u6570\u306E\u5076\u5947\u3067\u5206\u3051\u305F\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\u304B\u3089\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\
    \u304D\u308B(\u6642\u9593\u9593\u5F15\u304D)\r\n\r\nh[k] := f[2k] + f[2k + 1]\
    \ i (i \u306F\u865A\u6570\u5358\u4F4D) (0 \\leq k < N/2)\r\nH[z] := \\Sum_{k =\
    \ 0}^{N - 1} h[k] z^k = F[2z] + F[2z + 1] i\r\n\r\n\u9023\u7ACB\u3055\u305B\u3066\
    \ H[\\omega_N^{-i}] \u3092 F[\\omega_N^{-2i}], F[\\omega_N^{-(2i + 1)}] \u304B\
    \u3089\u8A08\u7B97\u3057\u96E2\u6563\u9006\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\
    \u3092\u884C\u3046\u3002\r\nf[2k], f[2k + 1] \u306F\u5B9F\u6570\u306A\u306E\u3067\
    \ h[k] \u306E\u5B9F\u90E8\u3068\u865A\u90E8\u304B\u3089 f[0], f[1], \\ldots, f[N\
    \ - 1] \u304C\u6C42\u307E\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename\
    \ T>\r\nstatic std::vector<value_type> multiply(const std::vector<T> &A, const\
    \ std::vector<T> &B)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(N log N) (N :=\
    \ |A| + |B| - 1 \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA)\r\n\t2 \u3064\u306E\
    \u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\u3002\r\n\t\u5236\u7D04\
    :\r\n\t\tT: int | double\r\n\t\t\u623B\u308A\u5024\u306F double \u578B\u306E\u914D\
    \u5217(\u30B5\u30A4\u30BA |A| + |B| - 1)\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79,\
    \ 2020/05/01\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/08/01\r\n*/\r\n\r\n#include <vector>\r\n#include <complex>\r\n#include\
    \ <algorithm>\r\n\r\nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type\
    \ = double;\r\n\tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst size_type m =\
    \ n >> 1;\r\n\t\tconst std::vector<complex_type> zeta = _zeta(ni);\r\n\t\t\r\n\
    \t\tstd::vector<complex_type> a;\r\n\t\ta.resize(n);\r\n\t\tfor (size_type i =\
    \ 0; i < A.size(); ++i) a[i].real(A[i]);\r\n\t\tfor (size_type i = 0; i < B.size();\
    \ ++i) a[i].imag(B[i]);\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<complex_type>\
    \ c;\r\n\t\tc.reserve(m + 1);\r\n\t\tc.emplace_back(a[0].real() * a[0].imag(),\
    \ 0);\r\n\t\tfor (size_type i = 1; i != m; ++i) {\r\n\t\t\tconst complex_type\
    \ a_conj = std::conj(a[n - i]);\r\n\t\t\tconst complex_type prod = (a[i] + a_conj)\
    \ * (a[i] - a_conj) / 4.0;\r\n\t\t\tc.emplace_back(prod.imag(), -prod.real());\r\
    \n\t\t}\r\n\t\tc.emplace_back(a[m].real() * a[m].imag(), 0);\r\n\t\t\r\n\t\ta.resize(m);\r\
    \n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tconst complex_type c_conj =\
    \ std::conj(c[m - i]);\r\n\t\t\tconst complex_type e = (c[i] + c_conj) / 2.0;\r\
    \n\t\t\tconst complex_type o = (c[i] - c_conj) * std::conj(zeta[i]) / 2.0;\r\n\
    \t\t\ta[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());\r\n\t\t\
    }\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\
    \n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tres.emplace_back(a[i].real()\
    \ / static_cast<value_type>(m));\r\n\t\t\tres.emplace_back(-a[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\tres.resize(A.size() + B.size() - 1);\r\n\t\treturn res;\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > N) --ni;\r\
    \n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type\
    \ m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
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
  code: "#ifndef INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP\r\
    \n#define INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n\u5B9F\u6570\u306E\u7573\u307F\u8FBC\
    \u307F\r\n\u57FA\u6570 2 \u5468\u6CE2\u6570\u9593\u5F15\u304D Cooley-Tukey\r\n\
    \r\n# \u89E3\u8AAC\r\n## \u5B9F\u6570\u5024\u95A2\u6570\u306E\u7573\u307F\u8FBC\
    \u307F\r\nN \u3092 2 \u51AA\u3068\u3057\u3066\r\n f[0], f[1], \\ldots, f[N - 1],\
    \ g[0], g[1], \\ldots, g[N - 1] \u304C\u65E2\u77E5\u3067 \"\u5B9F\u6570\"\r\n\r\
    \n\\omega_N := 1 \u306E\u539F\u59CB N \u4E57\u6839\r\n\r\nF[z] := \\Sum_{k = 0}^{N\
    \ - 1} f[k] z^k\r\nF[\\omega_N^{-j}] = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-kj}\r\
    \n\r\nconj(z) \u306F z \u306E\u8907\u7D20\u5171\u5F79\u3092\u8868\u3059\u3002\r\
    \n\r\nf[j] \u306F\u5B9F\u6570\u306A\u306E\u3067 conj(f[j]) = f[j] \u3088\u308A\
    \u3001\r\nF[\\omega_N^{-(N - j)}] = conj(F[\\omega_N^{-j}])\r\n\r\nh[k] := f[k]\
    \ + g[k] i ( i \u306F\u865A\u6570\u5358\u4F4D) (0 \\leq k < N)\r\n\r\nH[\\omega_N^{-j}]\
    \ = F[\\omega_N^{-j}] + G[\\omega_N^{-j}] i\r\nH[\\omega_N^{N - j}] = conj(F[\\\
    omega_N^{-j}]) - conj(G[\\omega_N^{-j}]) i\r\n\u3092\u9023\u7ACB\u3055\u305B\u3066\
    \u89E3\u304F\u3068\u3001\r\n\r\nF[\\omega_N^{-j}] = (H[\\omega_N^{-j}] + conj(H[\\\
    omega_N^{N - j}]) / 2\r\nG[\\omega_N^{-j}] = (H[\\omega_N^{-j}] - conj(H[\\omega_N^{N\
    \ - j}]) / 2i\r\n\u304C\u5F97\u3089\u308C\u308B\u3002( j = 0 \u306E\u3068\u304D\
    \ \\omega_N^N \u304C\u73FE\u308C\u308B\u3053\u3068\u306B\u6CE8\u610F)\r\n\r\n\
    ## \u5B9F\u6570\u5024\u95A2\u6570\u306E\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\
    \u63DB\r\n\u5B9F\u6570\u5024\u95A2\u6570\u306E\u7573\u307F\u8FBC\u307F\u306F\u5B9F\
    \u6570\u5024\u3067\u3042\u308B\u3053\u3068\u3092\u7528\u3044\u3066\u3001\u305D\
    \u306E\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\u304B\u3089\u7573\u307F\u8FBC\u307F\
    \u306E\u5024\u3092\u5FA9\u5143\u3059\u308B\u3002\r\n\r\nN \u3092 2 \u51AA\u3068\
    \u3057\u3066 f[0], f[1], \\ldots, f[N - 1] \u304C \"\u5B9F\u6570\"\r\nF[z] \u3092\
    \ f[k] \u306E\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\u3068\u3057\u3001\
    F[\\omega_N^{-j}] (0 \\leq j < N) \u304C\u65E2\u77E5\u306E\u5834\u5408\u3092\u8003\
    \u3048\u308B\u3002\r\n\r\nF[z] := \\Sum_{k = 0}^{N - 1} f[k] z^k\r\nF[\\omega_N^{-j}]\
    \ = \\Sum_{k = 0}^{N - 1} f[k] \\omega_N^{-kj}\r\n\r\n0 \\leq i < N/2 \u3068\u3057\
    \u3066\r\nF[\\omega_N^{-i}]         = \\Sum_{k = 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki}\
    \ + \\Sum_{k = 0}^{N/2 - 1} f[2k + 1] \\omega_{N/2}^{-ki}\r\nF[\\omega_N^{-(i\
    \ + N/2)}] = \\Sum_{k = 0}^{N/2 - 1} f[2k] \\omega_{N/2}^{-ki} - \\Sum_{k = 0}^{N/2\
    \ - 1} f[2k + 1] \\omega_{N/2}^{-ki}\r\n\u3067\u3042\u308B\u306E\u3067 f \u306E\
    \u6B21\u6570\u306E\u5076\u5947\u3067\u5206\u3051\u305F\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\u304B\u3089\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\
    \u304D\u308B(\u6642\u9593\u9593\u5F15\u304D)\r\n\r\nh[k] := f[2k] + f[2k + 1]\
    \ i (i \u306F\u865A\u6570\u5358\u4F4D) (0 \\leq k < N/2)\r\nH[z] := \\Sum_{k =\
    \ 0}^{N - 1} h[k] z^k = F[2z] + F[2z + 1] i\r\n\r\n\u9023\u7ACB\u3055\u305B\u3066\
    \ H[\\omega_N^{-i}] \u3092 F[\\omega_N^{-2i}], F[\\omega_N^{-(2i + 1)}] \u304B\
    \u3089\u8A08\u7B97\u3057\u96E2\u6563\u9006\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\
    \u3092\u884C\u3046\u3002\r\nf[2k], f[2k + 1] \u306F\u5B9F\u6570\u306A\u306E\u3067\
    \ h[k] \u306E\u5B9F\u90E8\u3068\u865A\u90E8\u304B\u3089 f[0], f[1], \\ldots, f[N\
    \ - 1] \u304C\u6C42\u307E\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename\
    \ T>\r\nstatic std::vector<value_type> multiply(const std::vector<T> &A, const\
    \ std::vector<T> &B)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(N log N) (N :=\
    \ |A| + |B| - 1 \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA)\r\n\t2 \u3064\u306E\
    \u591A\u9805\u5F0F\u306E\u4E57\u7B97\u3092\u884C\u3046\u3002\r\n\t\u5236\u7D04\
    :\r\n\t\tT: int | double\r\n\t\t\u623B\u308A\u5024\u306F double \u578B\u306E\u914D\
    \u5217(\u30B5\u30A4\u30BA |A| + |B| - 1)\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79,\
    \ 2020/05/01\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/08/01\r\n*/\r\n\r\n#include <vector>\r\n#include <complex>\r\n#include\
    \ <algorithm>\r\n\r\nstruct FastFourierTransform {\r\npublic:\r\n\tusing value_type\
    \ = double;\r\n\tusing size_type = std::size_t;\r\n\tusing complex_type = std::complex<value_type>;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> &A, const std::vector<T> &B) {\r\n\t\tif (A.empty() || B.empty())\
    \ return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n\
    \ = 1, ni = 0;\r\n\t\twhile (n < n_) n <<= 1, ++ni;\r\n\t\tconst size_type m =\
    \ n >> 1;\r\n\t\tconst std::vector<complex_type> zeta = _zeta(ni);\r\n\t\t\r\n\
    \t\tstd::vector<complex_type> a;\r\n\t\ta.resize(n);\r\n\t\tfor (size_type i =\
    \ 0; i < A.size(); ++i) a[i].real(A[i]);\r\n\t\tfor (size_type i = 0; i < B.size();\
    \ ++i) a[i].imag(B[i]);\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<complex_type>\
    \ c;\r\n\t\tc.reserve(m + 1);\r\n\t\tc.emplace_back(a[0].real() * a[0].imag(),\
    \ 0);\r\n\t\tfor (size_type i = 1; i != m; ++i) {\r\n\t\t\tconst complex_type\
    \ a_conj = std::conj(a[n - i]);\r\n\t\t\tconst complex_type prod = (a[i] + a_conj)\
    \ * (a[i] - a_conj) / 4.0;\r\n\t\t\tc.emplace_back(prod.imag(), -prod.real());\r\
    \n\t\t}\r\n\t\tc.emplace_back(a[m].real() * a[m].imag(), 0);\r\n\t\t\r\n\t\ta.resize(m);\r\
    \n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tconst complex_type c_conj =\
    \ std::conj(c[m - i]);\r\n\t\t\tconst complex_type e = (c[i] + c_conj) / 2.0;\r\
    \n\t\t\tconst complex_type o = (c[i] - c_conj) * std::conj(zeta[i]) / 2.0;\r\n\
    \t\t\ta[i] = complex_type(e.real() - o.imag(), -e.imag() - o.real());\r\n\t\t\
    }\r\n\t\tfft(a, zeta);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\t\tres.reserve(n);\r\
    \n\t\tfor (size_type i = 0; i < m; ++i) {\r\n\t\t\tres.emplace_back(a[i].real()\
    \ / static_cast<value_type>(m));\r\n\t\t\tres.emplace_back(-a[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\tres.resize(A.size() + B.size() - 1);\r\n\t\treturn res;\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tstatic void fft(std::vector<complex_type> &A, const std::vector<complex_type>\
    \ &zeta) {\r\n\t\tconst size_type N = A.size();\r\n\t\tconst value_type PI = std::acos(static_cast<value_type>(-1));\r\
    \n\t\t\r\n\t\tsize_type zi = 1;\r\n\t\tfor (size_type i = 1; i < zeta.size();\
    \ i <<= 1, ++zi);\r\n\t\tsize_type ni = zi;\r\n\t\twhile (1 << ni > N) --ni;\r\
    \n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1, --ni) {\r\n\t\t\tconst size_type\
    \ m = n >> 1;\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type\
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
    };\r\n\r\n#endif // INCLUDE_GUARD_FAST_FOURIER_TRANSFORM_REAL_COOLEY_TUKEY_FREQUENCY_RADIX2_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp
  requiredBy: []
  timestamp: '2020-11-19 14:06:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform_Real_CooleyTukey-frequency-radix2.test.cpp
documentation_of: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp
- /library/Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp.html
title: Mathematics/Convolution/FastFourierTransform_Real_CooleyTukey-frequency-radix2.hpp
---
