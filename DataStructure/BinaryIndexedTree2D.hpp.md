---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/BinaryIndexedTree2D.test.cpp
    title: Test/BinaryIndexedTree2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://algo-logic.info/binary-indexed-tree/,
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree2D.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/08/15\r\n\r\n# \u4ED5\u69D8\r\nBinaryIndexedTree2D(size_type\
    \ h, size_type w) :\r\n\th \\times w \u306E\u8868\u3092\u69CB\u7BC9\r\n\r\nvoid\
    \ add(size_type i, size_type j, const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(log h log w)\r\n\t\u70B9 (i, j) \u306B\u5024 x \u3092\u52A0\u7B97\
    \r\n\r\nvalue_type sum(size_type i, size_type j) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log h log w)\r\n\t[0, i) \\times [0, j) \u306E\u5408\u8A08\
    \u3092\u8FD4\u3059\r\n\r\n\t// [i1, i2) x [j1, j2)\r\nvalue_type sum(size_type\
    \ i1, size_type j1, size_type i2, size_type j2) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log h log w)\r\n\t[i1, i2) \\times [j1, j2) \u306E\u5408\u8A08\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree2D {\r\n\
    \tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\t\
    using size_type = std::size_t;\r\n\t\r\n\tBinaryIndexedTree2D(size_type h, size_type\
    \ w) : h(h), w(w) {\r\n\t\tnode.resize(h + 1, std::vector<value_type>(w + 1));\r\
    \n\t}\r\n\t\r\n\tvoid add(size_type i, size_type j, const_reference x) {\r\n\t\
    \tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\t++i; ++j;\r\n\t\tfor (; i <= h;\
    \ i += i & -i) {\r\n\t\t\tfor (size_type k = j; k <= w; k += k & -k) {\r\n\t\t\
    \t\tnode[i][k] += x;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\t// [0, i) x [0, j)\r\
    \n\tvalue_type sum(size_type i, size_type j) const {\r\n\t\tassert(i <= h);\r\n\
    \t\tassert(j <= w);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ {\r\n\t\t\tfor (size_type k = j; k > 0; k -= k & -k) {\r\n\t\t\t\tres += node[i][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t// [i1, i2) x [j1, j2)\r\
    \n\tvalue_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const\
    \ {\r\n\t\tassert(i1 < i2);\r\n\t\tassert(j1 < j2);\r\n\t\tassert(i2 <= h);\r\n\
    \t\tassert(j2 <= w);\r\n\t\treturn sum(i2, j2) - sum(i2, j1) - sum(i1, j2) + sum(i1,\
    \ j1);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ node;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP\r\n#define INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/15\r\n\r\n# \u4ED5\u69D8\r\nBinaryIndexedTree2D(size_type\
    \ h, size_type w) :\r\n\th \\times w \u306E\u8868\u3092\u69CB\u7BC9\r\n\r\nvoid\
    \ add(size_type i, size_type j, const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(log h log w)\r\n\t\u70B9 (i, j) \u306B\u5024 x \u3092\u52A0\u7B97\
    \r\n\r\nvalue_type sum(size_type i, size_type j) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log h log w)\r\n\t[0, i) \\times [0, j) \u306E\u5408\u8A08\
    \u3092\u8FD4\u3059\r\n\r\n\t// [i1, i2) x [j1, j2)\r\nvalue_type sum(size_type\
    \ i1, size_type j1, size_type i2, size_type j2) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log h log w)\r\n\t[i1, i2) \\times [j1, j2) \u306E\u5408\u8A08\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree2D {\r\n\
    \tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\t\
    using size_type = std::size_t;\r\n\t\r\n\tBinaryIndexedTree2D(size_type h, size_type\
    \ w) : h(h), w(w) {\r\n\t\tnode.resize(h + 1, std::vector<value_type>(w + 1));\r\
    \n\t}\r\n\t\r\n\tvoid add(size_type i, size_type j, const_reference x) {\r\n\t\
    \tassert(i < h);\r\n\t\tassert(j < w);\r\n\t\t++i; ++j;\r\n\t\tfor (; i <= h;\
    \ i += i & -i) {\r\n\t\t\tfor (size_type k = j; k <= w; k += k & -k) {\r\n\t\t\
    \t\tnode[i][k] += x;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\t// [0, i) x [0, j)\r\
    \n\tvalue_type sum(size_type i, size_type j) const {\r\n\t\tassert(i <= h);\r\n\
    \t\tassert(j <= w);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ {\r\n\t\t\tfor (size_type k = j; k > 0; k -= k & -k) {\r\n\t\t\t\tres += node[i][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t// [i1, i2) x [j1, j2)\r\
    \n\tvalue_type sum(size_type i1, size_type j1, size_type i2, size_type j2) const\
    \ {\r\n\t\tassert(i1 < i2);\r\n\t\tassert(j1 < j2);\r\n\t\tassert(i2 <= h);\r\n\
    \t\tassert(j2 <= w);\r\n\t\treturn sum(i2, j2) - sum(i2, j1) - sum(i1, j2) + sum(i1,\
    \ j1);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type h, w;\r\n\tstd::vector<std::vector<value_type>>\
    \ node;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_BINARY_INDEXED_TREE_2D_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree2D.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/BinaryIndexedTree2D.test.cpp
documentation_of: DataStructure/BinaryIndexedTree2D.hpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree2D.hpp
- /library/DataStructure/BinaryIndexedTree2D.hpp.html
title: DataStructure/BinaryIndexedTree2D.hpp
---
