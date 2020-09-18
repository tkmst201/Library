---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    - https://scrapbox.io/data-structures/Sliding_Window_Aggregation,
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.hpp\"\n\n\n\r\n#include\
    \ <stack>\r\n#include <vector>\r\n#include <cassert>\r\n#include <cstdio>\r\n\r\
    \n/*\r\nlast-updated: 2019/12/18\r\n\r\n\u73FE\u5728 \u533A\u9593min \u306E\u307F\
    \r\n\u62BD\u8C61\u5316\u3057\u305F\u3044\u306D\r\nvback\u306F1\u8981\u7D20\u3057\
    \u304B\u5FC5\u8981\u306A\u3044\u306E\u3067\u305D\u3046\u3059\u308B\u3079\u304D\
    \r\n\r\n# \u4ED5\u69D8\r\nvoid push(const int &x) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1) amortized\r\n\t\u5F8C\u308D\u306B\u5024 x \u3092\u5165\u308C\
    \u308B\r\n\r\nvoid pop() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1) amortized\r\
    \n\t\u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\r\nbool empty()\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u304B\u3069\u3046\
    \u304B\u3092\u8FD4\u3059\r\n\r\nint fald_all() :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u5168\u3066\u306E\
    \u8981\u7D20\u306E\u6F14\u7B97\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\nprivate:\r\
    \nint func(const int &x, const int &y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ \u0398(1)\r\n\t\u4E8C\u9805\u6F14\u7B97\r\n\r\n# \u53C2\u8003\r\nhttps://scrapbox.io/data-structures/Sliding_Window_Aggregation,\
    \ 2019/12/18\r\n*/\r\n\r\nstruct SlidingWindowAggregation {\r\npublic:\r\n\tvoid\
    \ push(const int &x) {\r\n\t\tpush(x, sback, vback);\r\n\t}\r\n\t\r\n\tvoid pop()\
    \ {\r\n\t\tassert(!empty());\r\n\t\tif (sfront.empty()) {\r\n\t\t\twhile (!sback.empty())\
    \ {\r\n\t\t\t\tpush(sback.top(), sfront, vfront);\r\n\t\t\t\tsback.pop();\r\n\t\
    \t\t}\r\n\t\t\tvback.clear();\r\n\t\t}\r\n\t\tsfront.pop();\r\n\t\tvfront.pop_back();\r\
    \n\t}\r\n\t\r\n\tbool empty() {\r\n\t\treturn sfront.empty() && sback.empty();\r\
    \n\t}\r\n\t\r\n\tint fold_all() {\r\n\t\tassert(!empty());\r\n\t\tif (vfront.empty())\
    \ return vback.back();\r\n\t\tif (vback.empty()) return vfront.back();\r\n\t\t\
    return func(vfront.back(), vback.back());\r\n\t}\r\n\t\r\nprivate:\r\n\tstd::stack<int>\
    \ sfront, sback;\r\n\tstd::vector<int> vfront, vback;\r\n\t\r\n\tvoid push(const\
    \ int &x, std::stack<int> &st, std::vector<int> &v) {\r\n\t\tst.push(x);\r\n\t\
    \tif (v.empty()) v.push_back(x);\r\n\t\telse {\r\n\t\t\tint addval = func(v.back(),\
    \ x);\r\n\t\t\tv.push_back(addval);\r\n\t\t}\r\n\t}\r\n\t\r\n\tint func(const\
    \ int &x, const int &y) {\r\n\t\treturn std::min(x, y);\r\n\t}\r\n};\r\n\r\n\r\
    \n/*\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\r\n\
    \r\nint main() {\r\n\tint N, L;\r\n\tscanf(\"%d %d\", &N, &L);\r\n\tstd::vector<int>\
    \ A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tSlidingWindowAggregation\
    \ swag;\r\n\tfor (int i = 0; i < L - 1; ++i) swag.push(A[i]);\r\n\t\r\n\tfor (int\
    \ i = L - 1; i < N; ++i) {\r\n\t\tswag.push(A[i]);\r\n\t\tprintf(\"%d%c\", swag.fold_all(),\
    \ i == N - 1 ? '\\n' : ' ');\r\n\t\tswag.pop();\r\n\t}\r\n\t\r\n\treturn 0;\r\n\
    }\r\n*/\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\n#define INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\
    \n\r\n#include <stack>\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <cstdio>\r\n\r\n/*\r\nlast-updated: 2019/12/18\r\n\r\n\u73FE\u5728 \u533A\u9593\
    min \u306E\u307F\r\n\u62BD\u8C61\u5316\u3057\u305F\u3044\u306D\r\nvback\u306F\
    1\u8981\u7D20\u3057\u304B\u5FC5\u8981\u306A\u3044\u306E\u3067\u305D\u3046\u3059\
    \u308B\u3079\u304D\r\n\r\n# \u4ED5\u69D8\r\nvoid push(const int &x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1) amortized\r\n\t\u5F8C\u308D\u306B\u5024 x\
    \ \u3092\u5165\u308C\u308B\r\n\r\nvoid pop() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1) amortized\r\n\t\u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\
    \u308B\r\n\r\nbool empty() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\
    \t\u7A7A\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\r\n\r\nint fald_all() :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u73FE\u5728\u5165\u3063\u3066\
    \u3044\u308B\u5168\u3066\u306E\u8981\u7D20\u306E\u6F14\u7B97\u7D50\u679C\u3092\
    \u8FD4\u3059\r\n\r\nprivate:\r\nint func(const int &x, const int &y) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u4E8C\u9805\u6F14\u7B97\r\n\r\n# \u53C2\
    \u8003\r\nhttps://scrapbox.io/data-structures/Sliding_Window_Aggregation, 2019/12/18\r\
    \n*/\r\n\r\nstruct SlidingWindowAggregation {\r\npublic:\r\n\tvoid push(const\
    \ int &x) {\r\n\t\tpush(x, sback, vback);\r\n\t}\r\n\t\r\n\tvoid pop() {\r\n\t\
    \tassert(!empty());\r\n\t\tif (sfront.empty()) {\r\n\t\t\twhile (!sback.empty())\
    \ {\r\n\t\t\t\tpush(sback.top(), sfront, vfront);\r\n\t\t\t\tsback.pop();\r\n\t\
    \t\t}\r\n\t\t\tvback.clear();\r\n\t\t}\r\n\t\tsfront.pop();\r\n\t\tvfront.pop_back();\r\
    \n\t}\r\n\t\r\n\tbool empty() {\r\n\t\treturn sfront.empty() && sback.empty();\r\
    \n\t}\r\n\t\r\n\tint fold_all() {\r\n\t\tassert(!empty());\r\n\t\tif (vfront.empty())\
    \ return vback.back();\r\n\t\tif (vback.empty()) return vfront.back();\r\n\t\t\
    return func(vfront.back(), vback.back());\r\n\t}\r\n\t\r\nprivate:\r\n\tstd::stack<int>\
    \ sfront, sback;\r\n\tstd::vector<int> vfront, vback;\r\n\t\r\n\tvoid push(const\
    \ int &x, std::stack<int> &st, std::vector<int> &v) {\r\n\t\tst.push(x);\r\n\t\
    \tif (v.empty()) v.push_back(x);\r\n\t\telse {\r\n\t\t\tint addval = func(v.back(),\
    \ x);\r\n\t\t\tv.push_back(addval);\r\n\t\t}\r\n\t}\r\n\t\r\n\tint func(const\
    \ int &x, const int &y) {\r\n\t\treturn std::min(x, y);\r\n\t}\r\n};\r\n\r\n\r\
    \n/*\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\r\n\
    \r\nint main() {\r\n\tint N, L;\r\n\tscanf(\"%d %d\", &N, &L);\r\n\tstd::vector<int>\
    \ A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tSlidingWindowAggregation\
    \ swag;\r\n\tfor (int i = 0; i < L - 1; ++i) swag.push(A[i]);\r\n\t\r\n\tfor (int\
    \ i = L - 1; i < N; ++i) {\r\n\t\tswag.push(A[i]);\r\n\t\tprintf(\"%d%c\", swag.fold_all(),\
    \ i == N - 1 ? '\\n' : ' ');\r\n\t\tswag.pop();\r\n\t}\r\n\t\r\n\treturn 0;\r\n\
    }\r\n*/\r\n\r\n#endif // INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/DataStructure/SlidingWindowAggregation.hpp
- /library/DataStructure/SlidingWindowAggregation.hpp.html
title: DataStructure/SlidingWindowAggregation.hpp
---
