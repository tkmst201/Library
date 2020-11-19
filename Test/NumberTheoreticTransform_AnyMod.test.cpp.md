---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Convolution/NumberTheoreticTransform.hpp
    title: Mathematics/Convolution/NumberTheoreticTransform.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/Garner.hpp
    title: Mathematics/Garner.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/MathUtility.hpp
    title: Mathematics/MathUtility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"Test/NumberTheoreticTransform_AnyMod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\r\n\r\
    \n#line 1 \"Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp\"\n\n\n\
    \r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n# \u89E3\u8AAC\r\nA, B \u305D\u308C\u305E\
    \u308C\u306E\u8981\u7D20\u306E\u6700\u5927\u5024\u3092 M \u3068\u3057\u3066\u3001\
    max(|A|, |B|) * M^2 \\leq \\prod mods \u3068\u306A\u308B\u3088\u3046\u306B mod\
    \ \u3092\u9078\u3076\u5FC5\u8981\u304C\u3042\u308B\r\n\r\nNumberTheoreticTransform<998'244'353,\
    \ 3> // 2^23 | (mod - 1)\r\nNumberTheoreticTransform<1'224'736'769, 3> // 2^24\
    \ | (mod - 1)\r\nNumberTheoreticTransform<469'762'049, 3> // 2^26 | (mod - 1)\r\
    \nNumberTheoreticTransform<167'772'161, 3> // 2^25 | (mod - 1)\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate \u5F15\u6570:\r\n\tint MOD: mod \u3092\u53D6\u308A\u305F\u3044\
    \u5024\r\n\r\nstatic std::vector<T> multiply(const std::vector<T> & A, const std::vector<T>\
    \ & B)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(N log N) (N := |A| + |B| -\
    \ 1 \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA)\r\n\tA, B \u306E\u6CD5 mod\
    \ \u306E\u5143\u3067\u306E\u7573\u307F\u8FBC\u307F(\u30B5\u30A4\u30BA |A| + |B|\
    \ - 1) \u3092\u8FD4\u3059\r\n\t\r\n\t\u5236\u7D04\u306F NumberTheoreticTransform\
    \ \u3068\u540C\u3058\r\n*/\r\n\r\n#line 1 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\n# \u89E3\u8AAC\r\n\u4EE3\u8868\
    \u7684\u306A mod \u3068\u305D\u306E\u539F\u59CB\u6839\r\nNumberTheoreticTransform<998'244'353,\
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
    \n\t\t}\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/Garner.hpp\"\n\n\n\r\n/*\r\
    \nlast-updated: 2020/09/21\r\n\r\n# \u89E3\u8AAC\r\nb: ( b_0, \\ldots, b_{k-1}\
    \ ), m: ( m_0, \\ldots, m_{k-1} ) \u306B\u5BFE\u3057\u3066\u3001\r\nx \\equiv\
    \ b_i (mod. m_i) (\\forall i) \u3068\u306A\u308B x \u3092 [0, lcm(m_0, \\ldots,\
    \ m_{k-1})) \u306E\u7BC4\u56F2\u3067\u6C42\u3081\u308B\u3002\r\n\u3053\u306E\u3088\
    \u3046\u306A x \u306F\u3001b_0 \\equiv \\dots \\equiv b_{k-1} (mod. gcd(m_0, \\\
    ldots, m_{k-1})) \u3067\u3042\u308B\u3068\u304D\u306E\u307F\u5B58\u5728\u3057\u3001\
    \u4E00\u610F\u3067\u3042\u308B\u3002\r\n\r\ngarner \u306E\u8A08\u7B97\u9014\u4E2D\
    \u306F O(m^2) \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\u308B\
    \u306E\u3067 overflow \u306B\u6CE8\u610F\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename\
    \ T>\r\nstatic bool preprocess(std::vector<T> &b, std::vector<T> &m) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(k^2 log m (loglog m)) ? \u3053\u308C\u3088\u308A\u5C0F\
    \u3055\u3044\u6C17\u304C\u3059\u308B\u304C\u5206\u304B\u3089\u305A\r\n\tm \u304C\
    \u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u3068\u304D\u306B\u9023\u7ACB\u5408\
    \u540C\u5F0F\u306E\u540C\u5024\u5909\u5F62\u3092\u884C\u3044\u3001\u4E92\u3044\
    \u306B\u7D20\u306B\u5909\u5F62\u3059\u308B\u3002\r\n\t\u89E3\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F false \u3092\u8FD4\u3059\r\n\t\u8A08\u7B97\
    \u904E\u7A0B\u3067\u306F m \u306F\u5C0F\u3055\u304F\u306A\u308B\u65B9\u5411\u306B\
    \u3057\u304B\u5909\u5316\u3057\u306A\u3044\u305F\u3081 overflow \u3059\u308B\u3053\
    \u3068\u306F\u306A\u3044\r\n\r\ntemplate<typename T>\r\nstatic T garner(const\
    \ std::vector<T> & b, std::vector<T> m, const T &mod) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(k(k + log m))\r\n\tm \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\u304C\u5FC5\u8981\r\n\t(x \\equiv b_i (mod. m_i) (\\forall\
    \ i) \u3068\u306A\u308B x) modulo. mod \u3092\u8FD4\u3059(m \u306F\u4E92\u3044\
    \u306B\u7D20\u3088\u308A\u5FC5\u305A\u5B58\u5728\u3059\u308B)\r\n\t\u8A08\u7B97\
    \u904E\u7A0B\u3067 m^2 \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\
    \u308B\r\n\r\n\u4ED5\u69D8\r\n- T \u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3002\
    \r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/drken/items/ae02240cd1f8edfc86fd,\
    \ 2020/05/05\r\n*/\r\n\r\n#line 38 \"Mathematics/Garner.hpp\"\n\r\n#include <Mathematics/MathUtility.hpp>\r\
    \n\r\nstruct Garner {\r\npublic:\r\n\tusing size_type = std::size_t;\r\n\t\r\n\
    \ttemplate<typename T>\r\n\tstatic bool preprocess(std::vector<T> &b, std::vector<T>\
    \ &m) {\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\t\tfor (size_type\
    \ j = 0; j < i; ++j) {\r\n\t\t\t\tT g = tk::gcd(m[i], m[j]);\r\n\t\t\t\tif ((b[i]\
    \ - b[j]) % g) return false;\r\n\t\t\t\tm[i] /= g; m[j] /= g;\r\n\t\t\t\t\r\n\t\
    \t\t\tT gi = tk::gcd(g, m[i]), gj = g / gi;\r\n\t\t\t\tdo {\r\n\t\t\t\t\tg = tk::gcd(gi,\
    \ gj);\r\n\t\t\t\t\tgi *= g; gj /= g;\r\n\t\t\t\t} while (g != 1);\r\n\t\t\t\t\
    \r\n\t\t\t\tm[i] *= gi; m[j] *= gj;\r\n\t\t\t\tb[i] %= m[i]; b[j] %= m[j];\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\
    \tstatic T garner(const std::vector<T> &b, std::vector<T> m, const T mod) {\r\n\
    \t\tassert(b.size() == m.size());\r\n\t\tassert(!b.empty());\r\n\t\tT tg = m[0];\r\
    \n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\t\tassert(m[i] > 0);\r\n\
    \t\t\ttg = tk::gcd(tg, m[i]);\r\n\t\t}\r\n\t\tassert(mod > 0);\r\n\t\tassert(b.size()\
    \ == 1 || tg == 1);\r\n\t\t\r\n\t\tm.emplace_back(mod);\r\n\t\tstd::vector<T>\
    \ sum(m.size()), ip(m.size(), 1);\r\n\t\tfor (size_type i = 0; i < b.size(); ++i)\
    \ {\r\n\t\t\t/*\r\n\t\t\t\tip[j] := m_0 m_1 \\ldots m_{i-1} (mod. m_j)\r\n\t\t\
    \t\tsum[j] := t_0 ip[0]  t_1 ip[1]  \\ldots  t_{i-1} ip[i-1] (mod. m_j)\r\n\t\t\
    \t*/\r\n\t\t\tif (m[i] == 1) continue;\r\n\t\t\tT t = ((b[i] % m[i] + m[i]) %\
    \ m[i] - sum[i] + m[i]) % m[i] * tk::mod_inv(ip[i], m[i]) % m[i];\r\n\t\t\tfor\
    \ (size_type j = i + 1; j < m.size(); ++j) {\r\n\t\t\t\tsum[j] = (sum[j] + ip[j]\
    \ * t) % m[j];\r\n\t\t\t\tip[j] = (ip[j] * m[i] % m[j]);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\treturn sum.back();\r\n\t}\r\n};\r\n\r\n\n#line 28 \"Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp\"\
    \n\r\n#line 32 \"Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp\"\
    \n\r\ntemplate<int MOD>\r\nstruct NumberTheoreticTransform_AnyMod {\r\npublic:\r\
    \n\tusing value_type = long long;\r\n\tusing size_type = std::uint_fast32_t;\r\
    \n\tstatic_assert(MOD > 0);\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<T>\
    \ multiply(const std::vector<T> & A, const std::vector<T> & B) {\r\n\t\tstd::vector<value_type>\
    \ m;\r\n\t\tauto ntt1_res = NumberTheoreticTransform<1'224'736'769, 3>::multiply(A,\
    \ B);\r\n\t\tm.emplace_back(1'224'736'769);\r\n\t\tauto ntt2_res = NumberTheoreticTransform<469'762'049,\
    \ 3>::multiply(A, B);\r\n\t\tm.emplace_back(469'762'049);\r\n\t\tauto ntt3_res\
    \ = NumberTheoreticTransform<167'772'161, 3>::multiply(A, B);\r\n\t\tm.emplace_back(167'772'161);\r\
    \n\t\t// auto ntt4_res = NumberTheoreticTransform<998'244'353, 3>::multiply(A,\
    \ B);\r\n\t\t// m.emplace_back(998'244'353);\r\n\t\t\r\n\t\tstd::vector<value_type>\
    \ b(m.size());\r\n\t\tstd::vector<T> res(ntt1_res.size());\r\n\t\tfor (size_type\
    \ i = 0; i < res.size(); ++i) {\r\n\t\t\tb[0] = ntt1_res[i];\r\n\t\t\tb[1] = ntt2_res[i];\r\
    \n\t\t\tb[2] = ntt3_res[i];\r\n\t\t\t// b[3] = ntt4_res[i];\r\n\t\t\tres[i] =\
    \ Garner::garner<value_type>(b, m, MOD);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\
    };\r\n\r\n\n#line 4 \"Test/NumberTheoreticTransform_AnyMod.test.cpp\"\n\r\n#include\
    \ <cstdio>\r\n#line 7 \"Test/NumberTheoreticTransform_AnyMod.test.cpp\"\n\r\n\
    int main() {\r\n\tint N, M;\r\n\tscanf(\"%d %d\", &N, &M);\r\n\t\r\n\tstd::vector<int>\
    \ A(N), B(M);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\tfor\
    \ (int i = 0; i < M; ++i) scanf(\"%d\", &B[i]);\r\n\t\r\n\tauto ans = NumberTheoreticTransform_AnyMod<1'000'000'007>::multiply(A,\
    \ B);\r\n\tfor (int i = 0; i < N + M - 1; ++i) printf(\"%d%c\", ans[i], i == N\
    \ + M - 1 ? '\\n': ' ');\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \r\n\r\n#include \"Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N,\
    \ M;\r\n\tscanf(\"%d %d\", &N, &M);\r\n\t\r\n\tstd::vector<int> A(N), B(M);\r\n\
    \tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\tfor (int i = 0; i < M;\
    \ ++i) scanf(\"%d\", &B[i]);\r\n\t\r\n\tauto ans = NumberTheoreticTransform_AnyMod<1'000'000'007>::multiply(A,\
    \ B);\r\n\tfor (int i = 0; i < N + M - 1; ++i) printf(\"%d%c\", ans[i], i == N\
    \ + M - 1 ? '\\n': ' ');\r\n\treturn 0;\r\n}"
  dependsOn:
  - Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  - Mathematics/Convolution/NumberTheoreticTransform.hpp
  - Mathematics/MathUtility.hpp
  - Mathematics/Garner.hpp
  isVerificationFile: true
  path: Test/NumberTheoreticTransform_AnyMod.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 12:38:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/NumberTheoreticTransform_AnyMod.test.cpp
layout: document
redirect_from:
- /verify/Test/NumberTheoreticTransform_AnyMod.test.cpp
- /verify/Test/NumberTheoreticTransform_AnyMod.test.cpp.html
title: Test/NumberTheoreticTransform_AnyMod.test.cpp
---
