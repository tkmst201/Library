---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/SlidingWindowAggregation.test.cpp
    title: Test/SlidingWindowAggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://scrapbox.io/data-structures/Sliding_Window_Aggregation,
    - https://snuke.hatenablog.com/entry/2018/09/18/135640,
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAggregation.hpp\"\n\n\n\r\n/*\r\
    \nlast-updated: 2020/09/22\r\n\r\n# \u6982\u8981\r\n\u30E2\u30CE\u30A4\u30C9\u3092\
    \u6271\u3046 SWAG\r\nqueue \u306E push, pop \u306B\u52A0\u3048\u3001\u8981\u7D20\
    \u5168\u4F53\u3092\u5165\u308C\u305F\u9806\u306B fold \u3057\u305F\u7D50\u679C\
    \u3092\u511F\u5374 O(1) \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\n\t\
    typename T: \u6271\u3046\u30E2\u30CE\u30A4\u30C9\r\n>\r\n\r\nSlidingWindowAggregation(const_reference\
    \ id_elem, const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5358\
    \u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3068\u3057\u3066\u521D\u671F\
    \u5316\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\r\n\r\nvoid push(const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1) amortized\r\n\tqueue \u306B\u5024 x \u3092\u8FFD\u52A0\u3059\u308B\
    \r\n\r\nvoid pop()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1) amortized\r\n\tqueue\
    \ \u306E\u6700\u521D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\t\u5FC5\
    \u305A\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u306A\u3089\
    \u306A\u3044\r\n\r\nvalue_type fold_all()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(1) amortized\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u5024\u3092 fold\
    \ \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://scrapbox.io/data-structures/Sliding_Window_Aggregation,\
    \ 2020/09/22\r\nhttps://snuke.hatenablog.com/entry/2018/09/18/135640, 2020/09/22\r\
    \n*/\r\n\r\n#include <cstdint>\r\n#include <cassert>\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <functional>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ SlidingWindowAggregation {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing size_type = std::uint_fast32_t;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<std::pair<value_type, value_type>>\
    \ lstack;\r\n\tstd::vector<value_type> rstack;\r\n\tvalue_type rsum;\r\n\t\r\n\
    public:\r\n\tSlidingWindowAggregation(const_reference id_elem, const F & f) :\
    \ id_elem(id_elem), f(f), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ { return lstack.size() + rstack.size(); }\r\n\t\r\n\tvoid push(const_reference\
    \ x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum = f(rsum, x);\r\n\t}\r\n\t\r\
    \n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\tif (lstack.empty()) {\r\n\t\
    \t\tif (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(rstack.back(), rstack.back());\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\twhile (rstack.size() > 1) {\r\
    \n\t\t\t\tlstack.emplace_back(rstack.back(), f(rstack.back(), lstack.back().second));\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\n\t\t\t\
    rsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold_all() const {\r\n\t\treturn f(lstack.empty() ? id_elem : lstack.back().second,\
    \ rsum);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\n#define INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/22\r\n\r\n# \u6982\u8981\r\n\u30E2\u30CE\u30A4\
    \u30C9\u3092\u6271\u3046 SWAG\r\nqueue \u306E push, pop \u306B\u52A0\u3048\u3001\
    \u8981\u7D20\u5168\u4F53\u3092\u5165\u308C\u305F\u9806\u306B fold \u3057\u305F\
    \u7D50\u679C\u3092\u511F\u5374 O(1) \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\
    \u3067\u304D\u308B\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\
    \n\ttypename T: \u6271\u3046\u30E2\u30CE\u30A4\u30C9\r\n>\r\n\r\nSlidingWindowAggregation(const_reference\
    \ id_elem, const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5358\
    \u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3068\u3057\u3066\u521D\u671F\
    \u5316\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\r\n\r\nvoid push(const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1) amortized\r\n\tqueue \u306B\u5024 x \u3092\u8FFD\u52A0\u3059\u308B\
    \r\n\r\nvoid pop()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1) amortized\r\n\tqueue\
    \ \u306E\u6700\u521D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\t\u5FC5\
    \u305A\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u306A\u3089\
    \u306A\u3044\r\n\r\nvalue_type fold_all()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(1) amortized\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u5024\u3092 fold\
    \ \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://scrapbox.io/data-structures/Sliding_Window_Aggregation,\
    \ 2020/09/22\r\nhttps://snuke.hatenablog.com/entry/2018/09/18/135640, 2020/09/22\r\
    \n*/\r\n\r\n#include <cstdint>\r\n#include <cassert>\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <functional>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ SlidingWindowAggregation {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing size_type = std::uint_fast32_t;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<std::pair<value_type, value_type>>\
    \ lstack;\r\n\tstd::vector<value_type> rstack;\r\n\tvalue_type rsum;\r\n\t\r\n\
    public:\r\n\tSlidingWindowAggregation(const_reference id_elem, const F & f) :\
    \ id_elem(id_elem), f(f), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ { return lstack.size() + rstack.size(); }\r\n\t\r\n\tvoid push(const_reference\
    \ x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum = f(rsum, x);\r\n\t}\r\n\t\r\
    \n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\tif (lstack.empty()) {\r\n\t\
    \t\tif (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(rstack.back(), rstack.back());\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\twhile (rstack.size() > 1) {\r\
    \n\t\t\t\tlstack.emplace_back(rstack.back(), f(rstack.back(), lstack.back().second));\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\n\t\t\t\
    rsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold_all() const {\r\n\t\treturn f(lstack.empty() ? id_elem : lstack.back().second,\
    \ rsum);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2020-09-22 11:21:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/SlidingWindowAggregation.test.cpp
documentation_of: DataStructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/DataStructure/SlidingWindowAggregation.hpp
- /library/DataStructure/SlidingWindowAggregation.hpp.html
title: DataStructure/SlidingWindowAggregation.hpp
---
