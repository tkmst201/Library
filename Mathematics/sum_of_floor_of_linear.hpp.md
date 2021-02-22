---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/sum_of_floor_of_linear.test.cpp
    title: Test/sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/HNJ/items/564f15316719209df73c,
    - https://twitter.com/kyopro_friends/status/1304063876019793921?s=20,
  bundledCode: "#line 1 \"Mathematics/sum_of_floor_of_linear.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/09/11\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nT sum_of_floor_of_linear(T\
    \ N, T M, T A, T B) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log min{M, A})\r\n\
    \t\\Sum_{i = 0}^{N - 1} floor((A \\times i + B) / M) \u3092\u6C42\u3081\u308B\r\
    \n\r\n# \u53C2\u8003\r\nhttps://twitter.com/kyopro_friends/status/1304063876019793921?s=20,\
    \ 2020/09/11\r\nhttps://qiita.com/HNJ/items/564f15316719209df73c, 2020/09/10\r\
    \n*/\r\n\r\n#include <utility>\r\n#include <cassert>\r\n\r\nnamespace tk {\r\n\
    template<typename T>\r\nT sum_of_floor_of_linear(T N, T M, T A, T B) {\r\n\tusing\
    \ value_type = T;\r\n\tvalue_type res = 0;\r\n\tassert(N >= 0);\r\n\tassert(M\
    \ > 0);\r\n\tassert(A >= 0);\r\n\tassert(B >= 0);\r\n\t\r\n\tif (B >= M) {\r\n\
    \t\tvalue_type d = B / M;\r\n\t\tres += d * N;\r\n\t\tB -= d * M;\r\n\t}\r\n\t\
    if (N == 0) return res;\r\n\t\r\n\twhile (true) {\r\n\t\tif (A >= M) {\r\n\t\t\
    \tvalue_type d = A / M;\r\n\t\t\tres += N * (N - 1) / 2 * d;\r\n\t\t\tA -= d *\
    \ M;\r\n\t\t}\r\n\t\tif (A == 0) break;\r\n\t\t\r\n\t\tvalue_type ymax = (A *\
    \ N + B) / M;\r\n\t\tif (ymax == 0) break;\r\n\t\t\r\n\t\tvalue_type t = M * ymax\
    \ - B;\r\n\t\tres += ymax * (N - (t + A - 1) / A);\r\n\t\tB = A - t % A;\r\n\t\
    \tif (B == A) B -= A;\r\n\t\tN = ymax;\r\n\t\tstd::swap(A, M);\r\n\t}\r\n\treturn\
    \ res;\r\n}\r\n} // namespace tk\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP\r\n#define INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/11\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename\
    \ T>\r\nT sum_of_floor_of_linear(T N, T M, T A, T B) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log min{M, A})\r\n\t\\Sum_{i = 0}^{N - 1} floor((A \\times i +\
    \ B) / M) \u3092\u6C42\u3081\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://twitter.com/kyopro_friends/status/1304063876019793921?s=20,\
    \ 2020/09/11\r\nhttps://qiita.com/HNJ/items/564f15316719209df73c, 2020/09/10\r\
    \n*/\r\n\r\n#include <utility>\r\n#include <cassert>\r\n\r\nnamespace tk {\r\n\
    template<typename T>\r\nT sum_of_floor_of_linear(T N, T M, T A, T B) {\r\n\tusing\
    \ value_type = T;\r\n\tvalue_type res = 0;\r\n\tassert(N >= 0);\r\n\tassert(M\
    \ > 0);\r\n\tassert(A >= 0);\r\n\tassert(B >= 0);\r\n\t\r\n\tif (B >= M) {\r\n\
    \t\tvalue_type d = B / M;\r\n\t\tres += d * N;\r\n\t\tB -= d * M;\r\n\t}\r\n\t\
    if (N == 0) return res;\r\n\t\r\n\twhile (true) {\r\n\t\tif (A >= M) {\r\n\t\t\
    \tvalue_type d = A / M;\r\n\t\t\tres += N * (N - 1) / 2 * d;\r\n\t\t\tA -= d *\
    \ M;\r\n\t\t}\r\n\t\tif (A == 0) break;\r\n\t\t\r\n\t\tvalue_type ymax = (A *\
    \ N + B) / M;\r\n\t\tif (ymax == 0) break;\r\n\t\t\r\n\t\tvalue_type t = M * ymax\
    \ - B;\r\n\t\tres += ymax * (N - (t + A - 1) / A);\r\n\t\tB = A - t % A;\r\n\t\
    \tif (B == A) B -= A;\r\n\t\tN = ymax;\r\n\t\tstd::swap(A, M);\r\n\t}\r\n\treturn\
    \ res;\r\n}\r\n} // namespace tk\r\n\r\n#endif // INCLUDE_GUARD_SUM_OF_FLOOR_OF_LINEAR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/sum_of_floor_of_linear.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/sum_of_floor_of_linear.test.cpp
documentation_of: Mathematics/sum_of_floor_of_linear.hpp
layout: document
redirect_from:
- /library/Mathematics/sum_of_floor_of_linear.hpp
- /library/Mathematics/sum_of_floor_of_linear.hpp.html
title: Mathematics/sum_of_floor_of_linear.hpp
---
