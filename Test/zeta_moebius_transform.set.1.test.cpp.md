---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/euclid.hpp
    title: "\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
    \n}\r\n} // namespace tk\r\n\r\n\n#line 1 \"Mathematics/euclid.hpp\"\n\n\n\r\n\
    #line 5 \"Mathematics/euclid.hpp\"\n#include <utility>\r\n#include <tuple>\r\n\
    #include <type_traits>\r\n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/euclid.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<typename T>\r\nconstexpr T gcd(T a, T b) noexcept\
    \ {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\tassert(a >= 0);\r\n\t\
    assert(b >= 0);\r\n\twhile (b != 0) {\r\n\t\tconst T t = a % b;\r\n\t\ta = b;\
    \ b = t;\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr T\
    \ lcm(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\n\
    \tassert(a >= 0);\r\n\tassert(b >= 0);\r\n\tif (a == 0 || b == 0) return 0;\r\n\
    \treturn a / gcd(a, b) * b;\r\n}\r\n\r\ntemplate<typename T>\r\nconstexpr std::tuple<T,\
    \ T, T> ext_gcd(T a, T b) noexcept {\r\n\tstatic_assert(std::is_integral<T>::value);\r\
    \n\tstatic_assert(std::is_signed<T>::value);\r\n\tassert(a != 0);\r\n\tassert(b\
    \ != 0);\r\n\tT a1 = (a > 0) * 2 - 1, a2 = 0, b1 = 0, b2 = (b > 0) * 2 - 1;\r\n\
    \ta = std::abs(a);\r\n\tb = std::abs(b);\r\n\twhile (b > 0) {\r\n\t\tconst T q\
    \ = a / b;\r\n\t\tT tmp = a - q * b; a = b; b = tmp;\r\n\t\ttmp = a1 - q * b1;\
    \ a1 = b1; b1 = tmp;\r\n\t\ttmp = a2 - q * b2; a2 = b2; b2 = tmp;\r\n\t}\r\n\t\
    return {a, a1, a2};\r\n}\r\n} // namespace tk\r\n\r\n\n#line 6 \"Test/zeta_moebius_transform.set.1.test.cpp\"\
    \n\r\n#line 8 \"Test/zeta_moebius_transform.set.1.test.cpp\"\n#include <iostream>\r\
    \n#line 10 \"Test/zeta_moebius_transform.set.1.test.cpp\"\n\r\nint main() {\r\n\
    \tusing ll = long long;\r\n\t\r\n\tint N;\r\n\tll M;\r\n\tstd::cin >> N >> M;\r\
    \n\tstd::vector<ll> A(N);\r\n\tstd::vector<int> P(N);\r\n\tfor (int i = 0; i <\
    \ N; ++i) std::cin >> A[i];\r\n\tfor (int i = 0; i < N; ++i) std::cin >> P[i];\r\
    \n\t\r\n\tauto solve1 = [&]() {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\t\r\n\
    \t\tfor (int s = 1; s < 1 << N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\
    \n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\
    \t\t\t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M /\
    \ A[i]) { ng = true; break; } // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\
    \t}\r\n\t\t\tif (ng) continue;\r\n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\t\
    tk::moebius_transform_set_lower(v);\r\n\t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\
    \t\tfor (int s = 0; s < 1 << N; ++s) {\r\n\t\t\tdouble p = 1;\r\n\t\t\tfor (int\
    \ i = 0; i < N; ++i) {\r\n\t\t\t\tif (s >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\t\
    else p *= (100 - P[i]) * 0.01;\r\n\t\t\t}\r\n\t\t\tans += std::abs(v[s]) * p;\r\
    \n\t\t}\r\n\t\treturn ans;\r\n\t};\r\n\t\r\n\tauto solve2 = [&]() {\r\n\t\tstd::vector<ll>\
    \ v((1 << N));\r\n\t\tfor (int s = 0; s < 1 << N; ++s) {\r\n\t\t\tll l = 1;\r\n\
    \t\t\tbool ng = false;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (~s\
    \ >> i & 1) continue;\r\n\t\t\t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\t\tl /=\
    \ g;\r\n\t\t\t\tif (l > M / A[i]) { ng = true; break; } // l A[i] <= M\r\n\t\t\
    \t\telse l *= A[i];\r\n\t\t\t}\r\n\t\t\tif (ng) continue;\r\n\t\t\tv[s] = M /\
    \ l;\r\n\t\t}\r\n\t\t\r\n\t\ttk::moebius_transform_set_upper(v);\r\n\t\ttk::zeta_tranform_set_lower(v);\r\
    \n\t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s)\
    \ {\r\n\t\t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\t\
    if (s >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\
    \t\t\t}\r\n\t\t\tans += (M - v[(1 << N) - 1 - s]) * p;\r\n\t\t}\r\n\t\treturn\
    \ ans;\r\n\t};\r\n\t\r\n\tdouble ans1 = solve1();\r\n\tdouble ans2 = solve2();\r\
    \n\tprintf(\"%.16f\\n\", (ans1 + ans2) / 2.0);\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#include \"Mathematics/zeta_moebius_transform.hpp\"\
    \r\n#include \"Mathematics/euclid.hpp\"\r\n\r\n#include <vector>\r\n#include <iostream>\r\
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
    \treturn 0;\r\n}"
  dependsOn:
  - Mathematics/zeta_moebius_transform.hpp
  - Mathematics/euclid.hpp
  isVerificationFile: true
  path: Test/zeta_moebius_transform.set.1.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 14:09:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/zeta_moebius_transform.set.1.test.cpp
layout: document
redirect_from:
- /verify/Test/zeta_moebius_transform.set.1.test.cpp
- /verify/Test/zeta_moebius_transform.set.1.test.cpp.html
title: Test/zeta_moebius_transform.set.1.test.cpp
---
