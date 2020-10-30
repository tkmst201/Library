---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree_RangeAdd.test.cpp
    title: Test/BinaryIndexedTree_RangeAdd.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://algo-logic.info/binary-indexed-tree/,
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\n\n\r\n\
    /*\r\nlast-updated: 2020/08/15\r\n\r\nBIT \u3092\u7528\u3044\u305F\u533A\u9593\
    \u52A0\u7B97\u304C\u884C\u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate<typename T, template<typename> class U> :\r\n\tT: \u5404\u8981\
    \u7D20\u306E\u30C7\u30FC\u30BF\u578B\r\n\tU: BinaryIndexedTree\r\n\tex. BinaryIndexedTree_RangeAdd<long\
    \ long, BinaryIndexedTree> bit(...)\r\n\r\nsize_type size() const noexcept :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\r\n\r\nvoid add(size_type l, size_type r, const_reference x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [l, r) \u306B\u4E00\u69D8\
    \u306B\u5024 x \u3092\u52A0\u7B97\r\n\r\nvalue_type sum(size_type i) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [0, i) \u306E\u5408\u8A08\
    \u3092\u53D6\u5F97\r\n\r\nvalue_type sum(size_type l, size_type r) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [l, r) \u306E\u5408\u8A08\
    \u3092\u53D6\u5F97\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T, template<typename> class U>\r\nstruct\
    \ BinaryIndexedTree_RangeAdd {\r\n\tusing bit_type = U<T>;\r\n\tusing value_type\
    \ = typename bit_type::value_type;\r\n\tusing const_reference = typename bit_type::const_reference;\r\
    \n\tusing size_type = typename bit_type::size_type;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd(size_type\
    \ n) : n(n) {\r\n\t\tbit.resize(2, bit_type(n, [](auto && x, auto && y) { return\
    \ x + y; }, 0));\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\t// [l, r) += x\r\n\tvoid add(size_type l, size_type r,\
    \ const_reference x) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\
    \tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\n\t\tbit[1].add(l, -x * (static_cast<value_type>(l)\
    \ - 1));\r\n\t\tbit[1].add(r - 1, x * (r - 1));\r\n\t}\r\n\t\r\n\t// \\Sum_{ k\
    \ = [0, i) } a_k\r\n\tvalue_type sum(size_type i) {\r\n\t\tassert(i <= size());\r\
    \n\t\treturn bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);\r\
    \n\t}\r\n\t\r\n\t// \\Sum_{ k = [l, r) } a_k\r\n\tvalue_type sum(size_type l,\
    \ size_type r) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\treturn\
    \ sum(r) - sum(l);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<bit_type>\
    \ bit;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/15\r\n\r\nBIT \u3092\u7528\u3044\u305F\u533A\
    \u9593\u52A0\u7B97\u304C\u884C\u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\
    \n# \u4ED5\u69D8\r\ntemplate<typename T, template<typename> class U> :\r\n\tT:\
    \ \u5404\u8981\u7D20\u306E\u30C7\u30FC\u30BF\u578B\r\n\tU: BinaryIndexedTree\r\
    \n\tex. BinaryIndexedTree_RangeAdd<long long, BinaryIndexedTree> bit(...)\r\n\r\
    \nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u8981\u7D20\u6570\u3092\u53D6\u5F97\r\n\r\nvoid add(size_type l, size_type\
    \ r, const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\
    \n\t\u533A\u9593 [l, r) \u306B\u4E00\u69D8\u306B\u5024 x \u3092\u52A0\u7B97\r\n\
    \r\nvalue_type sum(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (log n)\r\n\t\u533A\u9593 [0, i) \u306E\u5408\u8A08\u3092\u53D6\u5F97\r\n\r\n\
    value_type sum(size_type l, size_type r) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\t\u533A\u9593 [l, r) \u306E\u5408\u8A08\u3092\u53D6\u5F97\r\
    \n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/, 2020/08/15\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\
    \n\r\ntemplate<typename T, template<typename> class U>\r\nstruct BinaryIndexedTree_RangeAdd\
    \ {\r\n\tusing bit_type = U<T>;\r\n\tusing value_type = typename bit_type::value_type;\r\
    \n\tusing const_reference = typename bit_type::const_reference;\r\n\tusing size_type\
    \ = typename bit_type::size_type;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd(size_type\
    \ n) : n(n) {\r\n\t\tbit.resize(2, bit_type(n, [](auto && x, auto && y) { return\
    \ x + y; }, 0));\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\t// [l, r) += x\r\n\tvoid add(size_type l, size_type r,\
    \ const_reference x) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\
    \tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\n\t\tbit[1].add(l, -x * (static_cast<value_type>(l)\
    \ - 1));\r\n\t\tbit[1].add(r - 1, x * (r - 1));\r\n\t}\r\n\t\r\n\t// \\Sum_{ k\
    \ = [0, i) } a_k\r\n\tvalue_type sum(size_type i) {\r\n\t\tassert(i <= size());\r\
    \n\t\treturn bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);\r\
    \n\t}\r\n\t\r\n\t// \\Sum_{ k = [l, r) } a_k\r\n\tvalue_type sum(size_type l,\
    \ size_type r) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\treturn\
    \ sum(r) - sum(l);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<bit_type>\
    \ bit;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_RANGE_ADD_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree_RangeAdd.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree_RangeAdd.test.cpp
documentation_of: DataStructure/BinaryIndexedTree_RangeAdd.hpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree_RangeAdd.hpp
- /library/DataStructure/BinaryIndexedTree_RangeAdd.hpp.html
title: DataStructure/BinaryIndexedTree_RangeAdd.hpp
---
