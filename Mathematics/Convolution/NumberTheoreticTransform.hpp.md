---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/MathUtility.hpp
    title: Mathematics/MathUtility.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform.test.cpp
    title: Test/NumberTheoreticTransform.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform_AnyMod.test.cpp
    title: Test/NumberTheoreticTransform_AnyMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,
    - https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,
    - https://math314.hateblo.jp/entry/2015/05/07/014908,
  bundledCode: "#line 1 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\n\
    \n\n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n# \u89E3\u8AAC\r\n\u4EE3\u8868\u7684\
    \u306A mod \u3068\u305D\u306E\u539F\u59CB\u6839\r\nNumberTheoreticTransform<998'244'353,\
    \ 3> // 2^23 | (mod - 1)\r\nNumberTheoreticTransform<1'224'736'769, 3> // 2^24\
    \ | (mod - 1)\r\nNumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)\r\
    \nNumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate \u5F15\u6570:\r\n\tint MOD: mod \u3092\u53D6\u308A\u305F\u3044\
    \u5024\r\n\tint PRIMITIVE_ROOT: \u539F\u59CB\u6839\r\n\r\nstatic std::vector<T>\
    \ multiply(const std::vector<T> & A, const std::vector<T> & B)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(N log N) (N := |A| + |B| - 1 \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E 2 \u51AA)\r\n\tA, B \u306E\u6CD5 mod \u306E\u5143\u3067\u306E\u7573\
    \u307F\u8FBC\u307F(\u30B5\u30A4\u30BA |A| + |B| - 1) \u3092\u8FD4\u3059\r\n\t\r\
    \n\t\u5236\u7D04:\r\n\t\ttwo_exp := (mod - 1) \u306B\u542B\u307E\u308C\u308B\u7D20\
    \u56E0\u6570 2 \u306E\u500B\u6570\r\n\t\tN \\leq 2^min(two_exp) ( N \u4E57\u6839\
    \u3092\u6C42\u3081\u308B\u305F\u3081)\r\n\t\tT: int | long long int | unsigned\
    \ int | unsigned long long \u306A\u3069 (TODO: ModInt \u306B\u5BFE\u5FDC\u3059\
    \u308B)\r\n\r\n# \u53C2\u8003\r\nhttps://math314.hateblo.jp/entry/2015/05/07/014908,\
    \ 2020/07/27\r\nhttps://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,\
    \ 2020/07/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/07/27\r\n*/\r\n\r\n#line 1 \"Mathematics/MathUtility.hpp\"\n\n\n\r\n/*\r\
    \nlast-updated: 2020/09/21\r\n\r\n# \u4ED5\u69D8\r\nT gcd(T a, T b)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log max{a, b})\r\n\t\u975E\u8CA0\u6574\u6570 a \u3068\
    \ b \u306E\u6700\u5927\u516C\u7D04\u6570\u3092\u8FD4\u3059\r\n\t\u4E00\u65B9\u306E\
    \u5024\u304C 0 \u306E\u3068\u304D\u306F\u3082\u3046\u4E00\u65B9\u306E\u5024\u3092\
    \u8FD4\u3059\r\n\r\nT lcm(T a, T b)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log\
    \ max{a, b})\r\n\t\u975E\u8CA0\u6574\u6570 a \u3068 b \u306E\u6700\u5C0F\u516C\
    \u500D\u6570\u3092\u8FD4\u3059\r\n\ta = 0 \u307E\u305F\u306F b = 0 \u306E\u3068\
    \u304D\u306F 0 \u3092\u8FD4\u3059\r\n\r\nT ext_gcd(const T & a, T & x, const T\
    \ & b, T & y)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta > 0 \u304B\u3064\
    \ b > 0\r\n\t\u4E00\u6B21\u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax + by = gcd(x, y) \u306E\
    \u89E3 (x, y) \u3092\u6C42\u3081\u308B\r\n\tgcd(a, b) \u3092\u8FD4\u3059\r\n\r\
    \nT mod_pow(T x, T n, const T & mod)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (log n)\r\n\ta^n (modulo. mod) \u3092\u8FD4\u3059\r\n\t\u8A08\u7B97\u904E\u7A0B\
    \u3067 O(mod^2) \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\u308B\
    \u306E\u3067\u6CE8\u610F\r\n\r\nT mod_inv(const T & x, const T & mod)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log max{x, mod})\r\n\tmodulo. mod \u4E0A\u306E x \u306E\
    \u9006\u5143\u3092\u8FD4\u3059\r\n\tgcd(x, mod) = 1 \u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B(\u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u305F\u3081\u306E\
    \u5FC5\u8981\u5341\u5206\u6761\u4EF6)\r\n\r\nstd::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{m1, m2})\r\
    \n\t\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 x \u3092\u6C42\u3081\u308B(0 \\leq x < lcm(m1, m2))\r\n\t\tx \\equiv\
    \ b1 (mod. m1)\r\n\t\tx \\equiv b2 (mod. m2)\r\n\t\u623B\u308A\u5024: { x, lcm(m1,\
    \ m2) }\r\n\t\u4E0A\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059 x \u306F\u5468\u671F\
    \ lcm(m1, m2)\r\n\tx \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F {0,\
    \ 0} \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nAC Library, 2020/09/21\r\nhttps://noshi91.hatenablog.com/entry/2019/04/01/184957,\
    \ 2020/01/14\r\n*/\r\n\r\n#include <cassert>\r\n#include <utility>\r\n\r\nnamespace\
    \ tk {\r\ntemplate<typename T>\r\nT gcd(T a, T b) {\r\n\tassert(a >= 0);\r\n\t\
    assert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tT t = a % b;\r\n\t\ta = b; b = t;\r\
    \n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nT lcm(T a, T b) {\r\n\
    \tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\n\
    \treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nT ext_gcd(const\
    \ T & a, T & x, const T & b, T & y) {\r\n\tassert(a > 0);\r\n\tassert(b > 0);\r\
    \n\tT a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;\r\n\twhile (b0 > 0) {\r\n\
    \t\tT q = a0 / b0, r = a0 % b0;\r\n\t\tT nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\
    \n\t\ta0 = b0; b0 = r;\r\n\t\ta1 = b1; b1 = nb1;\r\n\t\ta2 = b2; b2 = nb2;\r\n\
    \t}\r\n\tx = a1;\r\n\ty = a2;\r\n\treturn a0;\r\n}\r\n\r\ntemplate<typename T>\r\
    \nT mod_pow(T x, T n, const T & mod) {\r\n\tassert(mod > 0);\r\n\tassert(n >=\
    \ 0);\r\n\tx = (x % mod + mod) % mod;\r\n\tT res = 1 % mod;\r\n\twhile (n > 0)\
    \ {\r\n\t\tif (n & 1) res = res * x % mod;\r\n\t\tx = x * x % mod;\r\n\t\tn >>=\
    \ 1;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\nT mod_inv(const\
    \ T & x, const T & mod) {\r\n\tassert(x > 0);\r\n\tassert(mod > 0);\r\n\tT a,\
    \ b;\r\n\tT g = ext_gcd(x, a, mod, b);\r\n\tassert(g == 1);\r\n\treturn (a % mod\
    \ + mod) % mod;\r\n}\r\n\r\ntemplate<typename T>\r\nstd::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2) {\r\n\tassert(m1 > 0);\r\n\tassert(m2 > 0);\r\n\tif (m1\
    \ < m2) { std::swap(b1, b2); std::swap(m1, m2); }\r\n\tb1 = (b1 % m1 + m1) % m1;\r\
    \n\tb2 = (b2 % m2 + m2) % m2;\r\n\t\r\n\tT x, y;\r\n\tT g = ext_gcd(m1, x, m2,\
    \ y);\r\n\tconst T pm2 = m2 / g;\r\n\tx = (x % pm2 + pm2) % pm2;\r\n\t\r\n\tif\
    \ ((b2 - b1) % g != 0) return {0, 0};\r\n\tconst T t = ((b2 - b1) / g % pm2 +\
    \ pm2) % pm2 * x % pm2;\r\n\treturn {b1 + t * m1, m1 * pm2};\r\n}\r\n} // namespace\
    \ tk\r\n\r\n\n#line 35 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\
    \n\r\n#include <vector>\r\n#line 39 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\
    \n#include <cstdint>\r\n\r\ntemplate<int MOD, int PRIMITIVE_ROOT>\r\nstruct NumberTheoreticTransform\
    \ {\r\npublic:\r\n\tusing value_type = long long;\r\n\tusing size_type = std::uint_fast32_t;\r\
    \n\tstatic_assert(MOD > 0);\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T>\
    \ multiply(const std::vector<T> & A, const std::vector<T> & B) {\r\n\t\tif (A.empty()\
    \ || B.empty()) return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\
    \tsize_type n = 1;\r\n\t\twhile (n < n_) n <<= 1;\r\n\t\t\r\n\t\t{\r\n\t\t\tsize_type\
    \ two_exp = 0;\r\n\t\t\tsize_type tm = MOD - 1;\r\n\t\t\twhile (tm > 0 && (~tm\
    \ & 1)) ++two_exp, tm >>= 1;\r\n\t\t\tassert(1 << two_exp >= n);\r\n\t\t}\r\n\t\
    \t\r\n\t\tstd::vector<T> a, b;\r\n\t\ta.reserve(n), b.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < A.size(); ++i) a.emplace_back((static_cast<value_type>(A[i]) % MOD\
    \ + MOD) % MOD);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back((static_cast<value_type>(B[i])\
    \ % MOD + MOD) % MOD);\r\n\t\ta.resize(n, 0); ntt(a);\r\n\t\tb.resize(n, 0); ntt(b);\r\
    \n\t\t\r\n\t\tconst value_type ninv = tk::mod_inv<value_type>(n, MOD);\r\n\t\t\
    for (size_type i = 0; i < n; ++i) a[i] = static_cast<value_type>(a[i]) * static_cast<value_type>(b[i])\
    \ % MOD * ninv % MOD;\r\n\t\tb.clear();\r\n\t\tntt(a, true);\r\n\t\ta.resize(A.size()\
    \ + B.size() - 1);\r\n\t\treturn a;\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename\
    \ T>\r\n\tstatic void ntt(std::vector<T> &A, const bool inv = false) {\r\n\t\t\
    const size_type N = A.size();\r\n\t\tvalue_type nroot = tk::mod_pow<value_type>(PRIMITIVE_ROOT,\
    \ (MOD - 1) / N, MOD);\r\n\t\tif (inv) nroot = tk::mod_inv<value_type>(nroot,\
    \ MOD);\r\n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1) {\r\n\t\t\tconst\
    \ size_type m = n >> 1;\r\n\t\t\tstd::vector<T> omega;\r\n\t\t\tomega.reserve(m);\r\
    \n\t\t\tomega.emplace_back(1);\r\n\t\t\tfor (size_type i = 0; i < m; ++i) omega.emplace_back(static_cast<value_type>(omega.back())\
    \ * nroot % MOD);\r\n\t\t\tvalue_type half = tk::mod_pow<value_type>(nroot, m,\
    \ MOD);\r\n\t\t\t\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\t\
    for (size_type i = p, ei = p + m; i < ei; ++i) {\r\n\t\t\t\t\tconst value_type\
    \ a = A[i], b = A[i + m];\r\n\t\t\t\t\tA[i] = (a + b) % MOD;\r\n\t\t\t\t\tA[i\
    \ + m] = (a + b * half % MOD) % MOD * static_cast<value_type>(omega[i - p]) %\
    \ MOD;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnroot = nroot * nroot % MOD;\r\n\t\t}\r\
    \n\t\t\r\n\t\tbit_reverse(A);\r\n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic\
    \ void bit_reverse(std::vector<T> &A) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tfor (size_type i = 1, j = 0; i < N - 1; ++i) {\r\n\t\t\tfor (size_type k\
    \ = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\tif (i < j) std::swap(A[i], A[j]);\r\
    \n\t\t}\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\n#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n# \u89E3\u8AAC\r\n\u4EE3\u8868\u7684\
    \u306A mod \u3068\u305D\u306E\u539F\u59CB\u6839\r\nNumberTheoreticTransform<998'244'353,\
    \ 3> // 2^23 | (mod - 1)\r\nNumberTheoreticTransform<1'224'736'769, 3> // 2^24\
    \ | (mod - 1)\r\nNumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)\r\
    \nNumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate \u5F15\u6570:\r\n\tint MOD: mod \u3092\u53D6\u308A\u305F\u3044\
    \u5024\r\n\tint PRIMITIVE_ROOT: \u539F\u59CB\u6839\r\n\r\nstatic std::vector<T>\
    \ multiply(const std::vector<T> & A, const std::vector<T> & B)\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(N log N) (N := |A| + |B| - 1 \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E 2 \u51AA)\r\n\tA, B \u306E\u6CD5 mod \u306E\u5143\u3067\u306E\u7573\
    \u307F\u8FBC\u307F(\u30B5\u30A4\u30BA |A| + |B| - 1) \u3092\u8FD4\u3059\r\n\t\r\
    \n\t\u5236\u7D04:\r\n\t\ttwo_exp := (mod - 1) \u306B\u542B\u307E\u308C\u308B\u7D20\
    \u56E0\u6570 2 \u306E\u500B\u6570\r\n\t\tN \\leq 2^min(two_exp) ( N \u4E57\u6839\
    \u3092\u6C42\u3081\u308B\u305F\u3081)\r\n\t\tT: int | long long int | unsigned\
    \ int | unsigned long long \u306A\u3069 (TODO: ModInt \u306B\u5BFE\u5FDC\u3059\
    \u308B)\r\n\r\n# \u53C2\u8003\r\nhttps://math314.hateblo.jp/entry/2015/05/07/014908,\
    \ 2020/07/27\r\nhttps://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,\
    \ 2020/07/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/07/27\r\n*/\r\n\r\n#include \"Mathematics/MathUtility.hpp\"\r\n\r\n#include\
    \ <vector>\r\n#include <utility>\r\n#include <cassert>\r\n#include <cstdint>\r\
    \n\r\ntemplate<int MOD, int PRIMITIVE_ROOT>\r\nstruct NumberTheoreticTransform\
    \ {\r\npublic:\r\n\tusing value_type = long long;\r\n\tusing size_type = std::uint_fast32_t;\r\
    \n\tstatic_assert(MOD > 0);\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T>\
    \ multiply(const std::vector<T> & A, const std::vector<T> & B) {\r\n\t\tif (A.empty()\
    \ || B.empty()) return {};\r\n\t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\
    \tsize_type n = 1;\r\n\t\twhile (n < n_) n <<= 1;\r\n\t\t\r\n\t\t{\r\n\t\t\tsize_type\
    \ two_exp = 0;\r\n\t\t\tsize_type tm = MOD - 1;\r\n\t\t\twhile (tm > 0 && (~tm\
    \ & 1)) ++two_exp, tm >>= 1;\r\n\t\t\tassert(1 << two_exp >= n);\r\n\t\t}\r\n\t\
    \t\r\n\t\tstd::vector<T> a, b;\r\n\t\ta.reserve(n), b.reserve(n);\r\n\t\tfor (size_type\
    \ i = 0; i < A.size(); ++i) a.emplace_back((static_cast<value_type>(A[i]) % MOD\
    \ + MOD) % MOD);\r\n\t\tfor (size_type i = 0; i < B.size(); ++i) b.emplace_back((static_cast<value_type>(B[i])\
    \ % MOD + MOD) % MOD);\r\n\t\ta.resize(n, 0); ntt(a);\r\n\t\tb.resize(n, 0); ntt(b);\r\
    \n\t\t\r\n\t\tconst value_type ninv = tk::mod_inv<value_type>(n, MOD);\r\n\t\t\
    for (size_type i = 0; i < n; ++i) a[i] = static_cast<value_type>(a[i]) * static_cast<value_type>(b[i])\
    \ % MOD * ninv % MOD;\r\n\t\tb.clear();\r\n\t\tntt(a, true);\r\n\t\ta.resize(A.size()\
    \ + B.size() - 1);\r\n\t\treturn a;\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename\
    \ T>\r\n\tstatic void ntt(std::vector<T> &A, const bool inv = false) {\r\n\t\t\
    const size_type N = A.size();\r\n\t\tvalue_type nroot = tk::mod_pow<value_type>(PRIMITIVE_ROOT,\
    \ (MOD - 1) / N, MOD);\r\n\t\tif (inv) nroot = tk::mod_inv<value_type>(nroot,\
    \ MOD);\r\n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1) {\r\n\t\t\tconst\
    \ size_type m = n >> 1;\r\n\t\t\tstd::vector<T> omega;\r\n\t\t\tomega.reserve(m);\r\
    \n\t\t\tomega.emplace_back(1);\r\n\t\t\tfor (size_type i = 0; i < m; ++i) omega.emplace_back(static_cast<value_type>(omega.back())\
    \ * nroot % MOD);\r\n\t\t\tvalue_type half = tk::mod_pow<value_type>(nroot, m,\
    \ MOD);\r\n\t\t\t\r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\t\
    for (size_type i = p, ei = p + m; i < ei; ++i) {\r\n\t\t\t\t\tconst value_type\
    \ a = A[i], b = A[i + m];\r\n\t\t\t\t\tA[i] = (a + b) % MOD;\r\n\t\t\t\t\tA[i\
    \ + m] = (a + b * half % MOD) % MOD * static_cast<value_type>(omega[i - p]) %\
    \ MOD;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnroot = nroot * nroot % MOD;\r\n\t\t}\r\
    \n\t\t\r\n\t\tbit_reverse(A);\r\n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic\
    \ void bit_reverse(std::vector<T> &A) {\r\n\t\tconst size_type N = A.size();\r\
    \n\t\tfor (size_type i = 1, j = 0; i < N - 1; ++i) {\r\n\t\t\tfor (size_type k\
    \ = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\tif (i < j) std::swap(A[i], A[j]);\r\
    \n\t\t}\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP"
  dependsOn:
  - Mathematics/MathUtility.hpp
  isVerificationFile: false
  path: Mathematics/Convolution/NumberTheoreticTransform.hpp
  requiredBy:
  - Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  timestamp: '2020-11-19 12:38:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/NumberTheoreticTransform.test.cpp
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
documentation_of: Mathematics/Convolution/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/NumberTheoreticTransform.hpp
- /library/Mathematics/Convolution/NumberTheoreticTransform.hpp.html
title: Mathematics/Convolution/NumberTheoreticTransform.hpp
---
