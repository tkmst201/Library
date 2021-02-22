---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/MathUtility.hpp
    title: Mathematics/MathUtility.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/zeta_moebius_transform.hpp
    title: Mathematics/zeta_moebius_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-7
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012
  bundledCode: "#line 1 \"Test/zeta_moebius_transform.set.1.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#line 1 \"Mathematics/zeta_moebius_transform.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\nTODO: AOJ, yukicoder \u304B\u3089\
    \ verify \u554F\u984C\u3092\u63A2\u3059\r\n\r\n# \u4ED5\u69D8\r\n## \u96C6\u5408\
    \r\nvoid zeta_tranform_set_lower(std::vector<T> & v)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217 v \u3092\u914D\u5217 v' \u306B\u66F8\
    \u304D\u63DB\u3048\u308B(i \u306E\u4E0B\u4F4D\u96C6\u5408\u306B\u3064\u3044\u3066\
    \u7DCF\u548C\u3092\u53D6\u308B)\r\n\tv'[i] := \\Sum_{j \\subset i} v[j]\r\n\r\n\
    void moebius_transform_set_lower(std::vector<T> & v)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217 v \u3092\u6B21\u306E\u5F0F\u3092\u6E80\
    \u305F\u3059\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u4E0B\
    \u4F4D\u96C6\u5408\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B\u524D\
    \u306B\u623B\u3059)\r\n\tv[i] = \\Sum_{j \\subset i} v'[j]\r\n\r\nvoid zeta_tranform_set_upper(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u4E0A\u4F4D\
    \u96C6\u5408\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B)\r\n\tv'[i]\
    \ := \\Sum_{i \\subset j} v[j]\r\n\r\nvoid moebius_transform_set_upper(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u6B21\u306E\u5F0F\u3092\u6E80\u305F\u3059\u914D\u5217 v' \u306B\u66F8\
    \u304D\u63DB\u3048\u308B(i \u306E\u4E0A\u4F4D\u96C6\u5408\u306B\u3064\u3044\u3066\
    \u7DCF\u548C\u3092\u53D6\u308B\u524D\u306B\u623B\u3059)\r\n\tv[i] = \\Sum_{i \\\
    subset j} v'[j]\r\n\r\n## \u7D04\u6570\u500D\u6570\r\nvoid zeta_tranform_divisor_lower(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(|v|loglog|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u7D04\u6570\
    \u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B)\r\n\tv'[i] := \\Sum_{j|i}\
    \ v[j]\r\n\r\nvoid moebius_tranform_divisor_lower(std::vector<T> & v)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(|v|loglog|v|)\r\n\t\u914D\u5217 v \u3092\u6B21\u306E\
    \u5F0F\u3092\u6E80\u305F\u3059\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B\
    (i \u306E\u7D04\u6570\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B\u524D\
    \u306B\u623B\u3059)\r\n\tv[i] = \\Sum_{j|i} v'[j]\r\n\r\nvoid zeta_tranform_divisor_upper(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(|v|loglog|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u500D\u6570\
    \u306B\u3064\u3044\u3066\u7DCF\u548C)\r\n\tv'[i] := \\Sum_{i|j} v[j]\r\n\r\nvoid\
    \ moebius_tranform_divisor_upper(std::vector<T> & v)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(|v|loglog|v|)\r\n\t\u914D\u5217 v \u3092\u6B21\u306E\u5F0F\u3092\u6E80\
    \u305F\u3059\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u7D04\
    \u6570\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B\u524D\u306B\u623B\
    \u3059)\r\n\tv[i] = \\Sum_{i|j} v'[j]\r\n\r\n# \u53C2\u8003\r\n2020/11/12: https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\r\
    \n2020/11/14: https://aprilganmo.hatenablog.com/entry/2020/02/27/170239\r\n2020/11/14:\
    \ https://noshi91.hatenablog.com/entry/2018/12/27/121649\r\n2020/11/18: https://aprilganmo.hatenablog.com/entry/2020/07/24/190816\r\
    \n\r\n# verify\r\nvoid zeta_tranform_set_lower(std::vector<T> & v)\r\nvoid moebius_transform_set_lower(std::vector<T>\
    \ & v)\r\nvoid zeta_tranform_set_upper(std::vector<T> & v)\r\n- OK\r\n\r\nvoid\
    \ moebius_transform_set_upper(std::vector<T> & v)\r\n- TODO: \u30E1\u30D3\u30A6\
    \u30B9(\u4E0A\u4F4D\u96C6\u5408) \u306E verify\r\n\r\nvoid zeta_tranform_divisor_lower(std::vector<T>\
    \ & v)\r\n- https://atcoder.jp/contests/abc172/submissions/18200046\r\n\r\nvoid\
    \ moebius_tranform_divisor_lower(std::vector<T> & v)\r\n- TODO: \u30E1\u30D3\u30A6\
    \u30B9(\u500D\u6570) \u306E verify\r\n\r\nvoid zeta_tranform_divisor_upper(std::vector<T>\
    \ & v)\r\nvoid moebius_tranform_divisor_upper(std::vector<T> & v)\r\n- https://atcoder.jp/contests/abc162/submissions/18200657\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace tk {\r\n\
    template<typename T>\r\nvoid zeta_tranform_set_lower(std::vector<T> & v) {\r\n\
    \tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tfor (size_type\
    \ i = 1; i < v.size(); i <<= 1) {\r\n\t\tfor (size_type j = 0; j < v.size(); ++j)\
    \ {\r\n\t\t\tif (j & i) v[j] += v[j ^ i];\r\n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nvoid moebius_transform_set_lower(std::vector<T> & v) {\r\n\tassert(!v.empty());\r\
    \n\tusing size_type = std::size_t;\r\n\tfor (size_type i = 1; i < v.size(); i\
    \ <<= 1) {\r\n\t\tfor (size_type j = 0; j < v.size(); ++j) {\r\n\t\t\tif (j &\
    \ i) v[j] -= v[j ^ i];\r\n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate<typename T>\r\nvoid\
    \ zeta_tranform_set_upper(std::vector<T> & v) {\r\n\tassert(!v.empty());\r\n\t\
    using size_type = std::size_t;\r\n\tfor (size_type i = 1; i < v.size(); i <<=\
    \ 1) {\r\n\t\tfor (size_type j = 0; j < v.size(); ++j) {\r\n\t\t\tif (~j & i)\
    \ v[j] += v[j ^ i];\r\n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate<typename T>\r\nvoid moebius_transform_set_upper(std::vector<T>\
    \ & v) {\r\n\tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tfor\
    \ (size_type i = 1; i < v.size(); i <<= 1) {\r\n\t\tfor (size_type j = 0; j <\
    \ v.size(); ++j) {\r\n\t\t\tif (~j & i) v[j] -= v[j ^ i];\r\n\t\t}\r\n\t}\r\n\
    }\r\n} // namespace tk\r\n\r\nnamespace tk {\r\ntemplate<typename T>\r\nvoid zeta_tranform_divisor_lower(std::vector<T>\
    \ & v) {\r\n\tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tstd::vector<bool>\
    \ sieve(v.size(), true);\r\n\tfor (size_type p = 2; p < v.size(); ++p) {\r\n\t\
    \tif (!sieve[p]) continue;\r\n\t\tfor (size_type i = 1, t = p; t < v.size(); ++i,\
    \ t += p) {\r\n\t\t\tv[t] += v[i];\r\n\t\t\tsieve[t] = false;\r\n\t\t}\r\n\t}\r\
    \n}\r\n\r\ntemplate<typename T>\r\nvoid moebius_tranform_divisor_lower(std::vector<T>\
    \ & v) {\r\n\tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tstd::vector<bool>\
    \ sieve(v.size(), true);\r\n\tfor (size_type p = 2; p < v.size(); ++p) {\r\n\t\
    \tif (!sieve[p]) continue;\r\n\t\tfor (size_type i = (v.size() - 1) / p, t = i\
    \ * p; i > 0; --i, t -= p) {\r\n\t\t\tv[t] -= v[i];\r\n\t\t\tsieve[t] = false;\r\
    \n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate<typename T>\r\nvoid zeta_tranform_divisor_upper(std::vector<T>\
    \ & v) {\r\n\tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tstd::vector<bool>\
    \ sieve(v.size(), true);\r\n\tfor (size_type p = 2; p < v.size(); ++p) {\r\n\t\
    \tif (!sieve[p]) continue;\r\n\t\tfor (size_type i = (v.size() - 1) / p, t = i\
    \ * p; i > 0; --i, t -= p) {\r\n\t\t\tv[i] += v[t];\r\n\t\t\tsieve[t] = false;\r\
    \n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate<typename T>\r\nvoid moebius_tranform_divisor_upper(std::vector<T>\
    \ & v) {\r\n\tassert(!v.empty());\r\n\tusing size_type = std::size_t;\r\n\tstd::vector<bool>\
    \ sieve(v.size(), true);\r\n\tfor (size_type p = 2; p < v.size(); ++p) {\r\n\t\
    \tif (!sieve[p]) continue;\r\n\t\tfor (size_type i = 1, t = p; t < v.size(); ++i,\
    \ t += p) {\r\n\t\t\tv[i] -= v[t];\r\n\t\t\tsieve[t] = false;\r\n\t\t}\r\n\t}\r\
    \n}\r\n} // namespace tk\r\n\r\n\n#line 1 \"Mathematics/MathUtility.hpp\"\n\n\n\
    \r\n/*\r\nlast-updated: 2020/09/21\r\n\r\n# \u4ED5\u69D8\r\nT gcd(T a, T b)\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{a, b})\r\n\t\u975E\u8CA0\u6574\u6570\
    \ a \u3068 b \u306E\u6700\u5927\u516C\u7D04\u6570\u3092\u8FD4\u3059\r\n\t\u4E00\
    \u65B9\u306E\u5024\u304C 0 \u306E\u3068\u304D\u306F\u3082\u3046\u4E00\u65B9\u306E\
    \u5024\u3092\u8FD4\u3059\r\n\r\nT lcm(T a, T b)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log max{a, b})\r\n\t\u975E\u8CA0\u6574\u6570 a \u3068 b \u306E\u6700\u5C0F\
    \u516C\u500D\u6570\u3092\u8FD4\u3059\r\n\ta = 0 \u307E\u305F\u306F b = 0 \u306E\
    \u3068\u304D\u306F 0 \u3092\u8FD4\u3059\r\n\r\nT ext_gcd(const T & a, T & x, const\
    \ T & b, T & y)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log b)\r\n\ta > 0 \u304B\
    \u3064 b > 0\r\n\t\u4E00\u6B21\u4E0D\u5B9A\u65B9\u7A0B\u5F0F ax + by = gcd(x,\
    \ y) \u306E\u89E3 (x, y) \u3092\u6C42\u3081\u308B\r\n\tgcd(a, b) \u3092\u8FD4\u3059\
    \r\n\r\nT mod_pow(T x, T n, const T & mod)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\ta^n (modulo. mod) \u3092\u8FD4\u3059\r\n\t\u8A08\u7B97\u904E\
    \u7A0B\u3067 O(mod^2) \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\
    \u308B\u306E\u3067\u6CE8\u610F\r\n\r\nT mod_inv(const T & x, const T & mod)\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{x, mod})\r\n\tmodulo. mod \u4E0A\u306E\
    \ x \u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\tgcd(x, mod) = 1 \u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B(\u9006\u5143\u304C\u5B58\u5728\u3059\u308B\u305F\
    \u3081\u306E\u5FC5\u8981\u5341\u5206\u6761\u4EF6)\r\n\r\nstd::pair<T, T> chinese_remainder(T\
    \ b1, T m1, T b2, T m2)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log max{m1, m2})\r\
    \n\t\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 x \u3092\u6C42\u3081\u308B(0 \\leq x < lcm(m1, m2))\r\n\t\tx \\equiv\
    \ b1 (mod. m1)\r\n\t\tx \\equiv b2 (mod. m2)\r\n\t\u623B\u308A\u5024: { x, lcm(m1,\
    \ m2) }\r\n\t\u4E0A\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059 x \u306F\u5468\u671F\
    \ lcm(m1, m2)\r\n\tx \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F {0,\
    \ 0} \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nAC Library, 2020/09/21\r\nhttps://noshi91.hatenablog.com/entry/2019/04/01/184957,\
    \ 2020/01/14\r\n*/\r\n\r\n#line 49 \"Mathematics/MathUtility.hpp\"\n#include <utility>\r\
    \n\r\nnamespace tk {\r\ntemplate<typename T>\r\nT gcd(T a, T b) {\r\n\tassert(a\
    \ >= 0);\r\n\tassert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tT t = a % b;\r\n\t\t\
    a = b; b = t;\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nT lcm(T\
    \ a, T b) {\r\n\tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b ==\
    \ 0) return 0;\r\n\treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\
    \nT ext_gcd(const T & a, T & x, const T & b, T & y) {\r\n\tassert(a > 0);\r\n\t\
    assert(b > 0);\r\n\tT a0 = a, a1 = 1, a2 = 0, b0 = b, b1 = 0, b2 = 1;\r\n\twhile\
    \ (b0 > 0) {\r\n\t\tT q = a0 / b0, r = a0 % b0;\r\n\t\tT nb1 = a1 - q * b1, nb2\
    \ = a2 - q * b2;\r\n\t\ta0 = b0; b0 = r;\r\n\t\ta1 = b1; b1 = nb1;\r\n\t\ta2 =\
    \ b2; b2 = nb2;\r\n\t}\r\n\tx = a1;\r\n\ty = a2;\r\n\treturn a0;\r\n}\r\n\r\n\
    template<typename T>\r\nT mod_pow(T x, T n, const T & mod) {\r\n\tassert(mod >\
    \ 0);\r\n\tassert(n >= 0);\r\n\tx = (x % mod + mod) % mod;\r\n\tT res = 1 % mod;\r\
    \n\twhile (n > 0) {\r\n\t\tif (n & 1) res = res * x % mod;\r\n\t\tx = x * x %\
    \ mod;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate<typename T>\r\
    \nT mod_inv(const T & x, const T & mod) {\r\n\tassert(x > 0);\r\n\tassert(mod\
    \ > 0);\r\n\tT a, b;\r\n\tT g = ext_gcd(x, a, mod, b);\r\n\tassert(g == 1);\r\n\
    \treturn (a % mod + mod) % mod;\r\n}\r\n\r\ntemplate<typename T>\r\nstd::pair<T,\
    \ T> chinese_remainder(T b1, T m1, T b2, T m2) {\r\n\tassert(m1 > 0);\r\n\tassert(m2\
    \ > 0);\r\n\tif (m1 < m2) { std::swap(b1, b2); std::swap(m1, m2); }\r\n\tb1 =\
    \ (b1 % m1 + m1) % m1;\r\n\tb2 = (b2 % m2 + m2) % m2;\r\n\t\r\n\tT x, y;\r\n\t\
    T g = ext_gcd(m1, x, m2, y);\r\n\tconst T pm2 = m2 / g;\r\n\tx = (x % pm2 + pm2)\
    \ % pm2;\r\n\t\r\n\tif ((b2 - b1) % g != 0) return {0, 0};\r\n\tconst T t = ((b2\
    \ - b1) / g % pm2 + pm2) % pm2 * x % pm2;\r\n\treturn {b1 + t * m1, m1 * pm2};\r\
    \n}\r\n} // namespace tk\r\n\r\n\n#line 6 \"Test/zeta_moebius_transform.set.1.test.cpp\"\
    \n\r\n#line 8 \"Test/zeta_moebius_transform.set.1.test.cpp\"\n#include <iostream>\r\
    \n#include <cmath>\r\n\r\nint main() {\r\n\tusing ll = long long;\r\n\t\r\n\t\
    int N;\r\n\tll M;\r\n\tstd::cin >> N >> M;\r\n\tstd::vector<ll> A(N);\r\n\tstd::vector<int>\
    \ P(N);\r\n\tfor (int i = 0; i < N; ++i) std::cin >> A[i];\r\n\tfor (int i = 0;\
    \ i < N; ++i) std::cin >> P[i];\r\n\t\r\n\tauto solve1 = [&]() {\r\n\t\tstd::vector<ll>\
    \ v((1 << N));\r\n\t\t\r\n\t\tfor (int s = 1; s < 1 << N; ++s) {\r\n\t\t\tll l\
    \ = 1;\r\n\t\t\tbool ng = false;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\
    \t\tif (~s >> i & 1) continue;\r\n\t\t\t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\
    \t\tl /= g;\r\n\t\t\t\tif (l > M / A[i]) { ng = true; break; } // l A[i] <= M\r\
    \n\t\t\t\telse l *= A[i];\r\n\t\t\t}\r\n\t\t\tif (ng) continue;\r\n\t\t\tv[s]\
    \ = M / l;\r\n\t\t}\r\n\t\t\r\n\t\ttk::moebius_transform_set_lower(v);\r\n\t\t\
    \r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s) {\r\n\t\
    \t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (s >> i\
    \ & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\t\t\t}\r\
    \n\t\t\tans += std::abs(v[s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\n\t};\r\n\t\r\
    \n\tauto solve2 = [&]() {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\tfor (int\
    \ s = 0; s < 1 << N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\n\t\
    \t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\t\t\
    \t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M / A[i])\
    \ { ng = true; break; } // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\t}\r\
    \n\t\t\tif (ng) continue;\r\n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\ttk::moebius_transform_set_upper(v);\r\
    \n\t\ttk::zeta_tranform_set_lower(v);\r\n\t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\
    \n\t\tfor (int s = 0; s < 1 << N; ++s) {\r\n\t\t\tdouble p = 1;\r\n\t\t\tfor (int\
    \ i = 0; i < N; ++i) {\r\n\t\t\t\tif (s >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\t\
    else p *= (100 - P[i]) * 0.01;\r\n\t\t\t}\r\n\t\t\tans += (M - v[(1 << N) - 1\
    \ - s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\n\t};\r\n\t\r\n\tdouble ans1 = solve1();\r\
    \n\tdouble ans2 = solve2();\r\n\tprintf(\"%.16f\\n\", (ans1 + ans2) / 2.0);\r\n\
    \treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#include \"Mathematics/zeta_moebius_transform.hpp\"\
    \r\n#include \"Mathematics/MathUtility.hpp\"\r\n\r\n#include <vector>\r\n#include\
    \ <iostream>\r\n#include <cmath>\r\n\r\nint main() {\r\n\tusing ll = long long;\r\
    \n\t\r\n\tint N;\r\n\tll M;\r\n\tstd::cin >> N >> M;\r\n\tstd::vector<ll> A(N);\r\
    \n\tstd::vector<int> P(N);\r\n\tfor (int i = 0; i < N; ++i) std::cin >> A[i];\r\
    \n\tfor (int i = 0; i < N; ++i) std::cin >> P[i];\r\n\t\r\n\tauto solve1 = [&]()\
    \ {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\t\r\n\t\tfor (int s = 1; s < 1 <<\
    \ N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\n\t\t\tfor (int i =\
    \ 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\t\t\t\tll g = tk::gcd<ll>(l,\
    \ A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M / A[i]) { ng = true; break; }\
    \ // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\t}\r\n\t\t\tif (ng) continue;\r\
    \n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\ttk::moebius_transform_set_lower(v);\r\
    \n\t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s)\
    \ {\r\n\t\t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\t\
    if (s >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\
    \t\t\t}\r\n\t\t\tans += std::abs(v[s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\n\t\
    };\r\n\t\r\n\tauto solve2 = [&]() {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\t\
    for (int s = 0; s < 1 << N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\
    \n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\
    \t\t\t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M /\
    \ A[i]) { ng = true; break; } // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\
    \t}\r\n\t\t\tif (ng) continue;\r\n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\t\
    tk::moebius_transform_set_upper(v);\r\n\t\ttk::zeta_tranform_set_lower(v);\r\n\
    \t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s) {\r\
    \n\t\t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (s\
    \ >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\t\t\
    \t}\r\n\t\t\tans += (M - v[(1 << N) - 1 - s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\
    \n\t};\r\n\t\r\n\tdouble ans1 = solve1();\r\n\tdouble ans2 = solve2();\r\n\tprintf(\"\
    %.16f\\n\", (ans1 + ans2) / 2.0);\r\n\treturn 0;\r\n}"
  dependsOn:
  - Mathematics/zeta_moebius_transform.hpp
  - Mathematics/MathUtility.hpp
  isVerificationFile: true
  path: Test/zeta_moebius_transform.set.1.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 18:21:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/zeta_moebius_transform.set.1.test.cpp
layout: document
redirect_from:
- /verify/Test/zeta_moebius_transform.set.1.test.cpp
- /verify/Test/zeta_moebius_transform.set.1.test.cpp.html
title: Test/zeta_moebius_transform.set.1.test.cpp
---
