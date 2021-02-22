---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/zeta_moebius_transform.set.1.test.cpp
    title: Test/zeta_moebius_transform.set.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://aprilganmo.hatenablog.com/entry/2020/02/27/170239
    - https://aprilganmo.hatenablog.com/entry/2020/07/24/190816
    - https://atcoder.jp/contests/abc162/submissions/18200657
    - https://atcoder.jp/contests/abc172/submissions/18200046
    - https://noshi91.hatenablog.com/entry/2018/12/27/121649
    - https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
  bundledCode: "#line 1 \"Mathematics/zeta_moebius_transform.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/11/19\r\n\r\nTODO: AOJ, yukicoder \u304B\u3089 verify \u554F\
    \u984C\u3092\u63A2\u3059\r\n\r\n# \u4ED5\u69D8\r\n## \u96C6\u5408\r\nvoid zeta_tranform_set_lower(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u4E0B\u4F4D\
    \u96C6\u5408\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B)\r\n\tv'[i]\
    \ := \\Sum_{j \\subset i} v[j]\r\n\r\nvoid moebius_transform_set_lower(std::vector<T>\
    \ & v)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217\
    \ v \u3092\u6B21\u306E\u5F0F\u3092\u6E80\u305F\u3059\u914D\u5217 v' \u306B\u66F8\
    \u304D\u63DB\u3048\u308B(i \u306E\u4E0B\u4F4D\u96C6\u5408\u306B\u3064\u3044\u3066\
    \u7DCF\u548C\u3092\u53D6\u308B\u524D\u306B\u623B\u3059)\r\n\tv[i] = \\Sum_{j \\\
    subset i} v'[j]\r\n\r\nvoid zeta_tranform_set_upper(std::vector<T> & v)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217 v \u3092\u914D\u5217\
    \ v' \u306B\u66F8\u304D\u63DB\u3048\u308B(i \u306E\u4E0A\u4F4D\u96C6\u5408\u306B\
    \u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\u308B)\r\n\tv'[i] := \\Sum_{i \\subset\
    \ j} v[j]\r\n\r\nvoid moebius_transform_set_upper(std::vector<T> & v)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(|v|log|v|)\r\n\t\u914D\u5217 v \u3092\u6B21\u306E\
    \u5F0F\u3092\u6E80\u305F\u3059\u914D\u5217 v' \u306B\u66F8\u304D\u63DB\u3048\u308B\
    (i \u306E\u4E0A\u4F4D\u96C6\u5408\u306B\u3064\u3044\u3066\u7DCF\u548C\u3092\u53D6\
    \u308B\u524D\u306B\u623B\u3059)\r\n\tv[i] = \\Sum_{i \\subset j} v'[j]\r\n\r\n\
    ## \u7D04\u6570\u500D\u6570\r\nvoid zeta_tranform_divisor_lower(std::vector<T>\
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
    \n}\r\n} // namespace tk\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP\r\n#define INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/11/19\r\n\r\nTODO: AOJ, yukicoder \u304B\u3089\
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
    \n}\r\n} // namespace tk\r\n\r\n#endif // INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/zeta_moebius_transform.hpp
  requiredBy: []
  timestamp: '2020-11-19 17:25:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/zeta_moebius_transform.set.1.test.cpp
documentation_of: Mathematics/zeta_moebius_transform.hpp
layout: document
redirect_from:
- /library/Mathematics/zeta_moebius_transform.hpp
- /library/Mathematics/zeta_moebius_transform.hpp.html
title: Mathematics/zeta_moebius_transform.hpp
---
