---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/sum_of_floor_of_linear.hpp
    title: Mathematics/sum_of_floor_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Test/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line 1 \"\
    Mathematics/sum_of_floor_of_linear.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/09/11\r\
    \n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nT sum_of_floor_of_linear(T N,\
    \ T M, T A, T B) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log min{M, A})\r\n\t\
    \\Sum_{i = 0}^{N - 1} floor((A \\times i + B) / M) \u3092\u6C42\u3081\u308B\r\n\
    \r\n# \u53C2\u8003\r\nhttps://twitter.com/kyopro_friends/status/1304063876019793921?s=20,\
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
    \ res;\r\n}\r\n} // namespace tk\r\n\r\n\n#line 4 \"Test/sum_of_floor_of_linear.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint T;\r\n\tscanf(\"%d\", &T);\r\
    \n\t\r\n\tusing ll = long long;\r\n\t\r\n\twhile (T--) {\r\n\t\tll n, m, a, b;\r\
    \n\t\tscanf(\"%lld %lld %lld %lld\", &n, &m, &a, &b);\r\n\t\tprintf(\"%lld\\n\"\
    , tk::sum_of_floor_of_linear<ll>(n, m, a, b));\r\n\t}\r\n\t\r\n\treturn 0;\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include \"Mathematics/sum_of_floor_of_linear.hpp\"\r\n\r\n#include <cstdio>\r\
    \n\r\nint main() {\r\n\tint T;\r\n\tscanf(\"%d\", &T);\r\n\t\r\n\tusing ll = long\
    \ long;\r\n\t\r\n\twhile (T--) {\r\n\t\tll n, m, a, b;\r\n\t\tscanf(\"%lld %lld\
    \ %lld %lld\", &n, &m, &a, &b);\r\n\t\tprintf(\"%lld\\n\", tk::sum_of_floor_of_linear<ll>(n,\
    \ m, a, b));\r\n\t}\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - Mathematics/sum_of_floor_of_linear.hpp
  isVerificationFile: true
  path: Test/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/Test/sum_of_floor_of_linear.test.cpp
- /verify/Test/sum_of_floor_of_linear.test.cpp.html
title: Test/sum_of_floor_of_linear.test.cpp
---
