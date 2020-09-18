---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree_RangeAdd.test.cpp
    title: Test/BinaryIndexedTree_RangeAdd.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree.test.cpp
    title: Test/BinaryIndexedTree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://algo-logic.info/binary-indexed-tree/,
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\n\n\n\r\n#include\
    \ <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n/*\r\nlast-updated:\
    \ 2020/08/15\r\n\r\n# \u4ED5\u69D8\r\nSegmentTree(size_type n_, const F & f, const_reference\
    \ id_elem) :\r\n\t\u8981\u7D20\u6570 n_, \u4E8C\u9805\u6F14\u7B97 f, \u5358\u4F4D\
    \u5143 id_elem\r\n\r\n\r\nvoid add(size_type i, const_reference x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF \u0398(lon n)\r\n\ti \u756A\u76EE\u306E\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u3048\u308B\r\n\r\nvalue_type sum(size_type i) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF \u0398(log n)\r\n\t[0, i) \u306E\u5408\u8A08\u3092\u8FD4\
    \u3059\r\n\r\nsize_type lower_bound(const_reference x) const {\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF \u0398(log n)\r\n\tsum[0, r] \\leq x \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E r \u3092\u8FD4\u3059 (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \ size())\r\n\t\u5404\u8981\u7D20\u306F\u975E\u8CA0\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing F = std::function<value_type(const_reference, const_reference)>;\r\n\t\
    using size_type = std::size_t;\r\n\t\r\n\tBinaryIndexedTree(size_type n, const\
    \ F & f, const_reference id_elem) : n(n), f(f), id_elem(id_elem) {\r\n\t\tnode.resize(n\
    \ + 1, id_elem);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid add(size_type i, const_reference x) {\r\n\t\tassert(i\
    \ < size());\r\n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i],\
    \ x);\r\n\t}\r\n\t\r\n\t// [0, i)\r\n\tvalue_type sum(size_type i) const {\r\n\
    \t\tassert(i <= size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0;\
    \ i -= i & -i) res = f(res, node[i]);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t//\
    \ sum[0, r] <= x \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\u8FD4\u3059\
    \ (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 size())\r\n\tsize_type lower_bound(const_reference\
    \ x) const {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem, w = 1;\r\n\
    \t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\t\t\tif (res\
    \ + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\n\t\t\t\t\
    if (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type n;\r\
    \n\tF f;\r\n\tvalue_type id_elem;\r\n\tstd::vector<value_type> node;\r\n};\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\r\n\
    /*\r\nlast-updated: 2020/08/15\r\n\r\n# \u4ED5\u69D8\r\nSegmentTree(size_type\
    \ n_, const F & f, const_reference id_elem) :\r\n\t\u8981\u7D20\u6570 n_, \u4E8C\
    \u9805\u6F14\u7B97 f, \u5358\u4F4D\u5143 id_elem\r\n\r\n\r\nvoid add(size_type\
    \ i, const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF \u0398(lon n)\r\n\
    \ti \u756A\u76EE\u306E\u8981\u7D20\u306B x \u3092\u52A0\u3048\u308B\r\n\r\nvalue_type\
    \ sum(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF \u0398(log n)\r\
    \n\t[0, i) \u306E\u5408\u8A08\u3092\u8FD4\u3059\r\n\r\nsize_type lower_bound(const_reference\
    \ x) const {\r\n\t\u6642\u9593\u8A08\u7B97\u91CF \u0398(log n)\r\n\tsum[0, r]\
    \ \\leq x \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\u8FD4\u3059 (\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 size())\r\n\t\u5404\u8981\u7D20\u306F\u975E\
    \u8CA0\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\r\n# \u53C2\u8003\r\
    \nhttps://algo-logic.info/binary-indexed-tree/, 2020/08/15\r\n*/\r\n\r\ntemplate<typename\
    \ T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tBinaryIndexedTree(size_type\
    \ n, const F & f, const_reference id_elem) : n(n), f(f), id_elem(id_elem) {\r\n\
    \t\tnode.resize(n + 1, id_elem);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid add(size_type i, const_reference x)\
    \ {\r\n\t\tassert(i < size());\r\n\t\t++i;\r\n\t\tfor (; i <= size(); i += i &\
    \ -i) node[i] = f(node[i], x);\r\n\t}\r\n\t\r\n\t// [0, i)\r\n\tvalue_type sum(size_type\
    \ i) const {\r\n\t\tassert(i <= size());\r\n\t\tvalue_type res = id_elem;\r\n\t\
    \tfor (; i > 0; i -= i & -i) res = f(res, node[i]);\r\n\t\treturn res;\r\n\t}\r\
    \n\t\r\n\t// sum[0, r] <= x \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\
    \u8FD4\u3059 (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 size())\r\n\tsize_type\
    \ lower_bound(const_reference x) const {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type\
    \ s = id_elem, w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0;\
    \ w >>= 1) {\r\n\t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s,\
    \ node[res + w]);\r\n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\
    \ts = cur;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    private:\r\n\tsize_type n;\r\n\tF f;\r\n\tvalue_type id_elem;\r\n\tstd::vector<value_type>\
    \ node;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree_RangeAdd.test.cpp
  - Test/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.hpp
- /library/DataStructure/BinaryIndexedTree.hpp.html
title: DataStructure/BinaryIndexedTree.hpp
---
