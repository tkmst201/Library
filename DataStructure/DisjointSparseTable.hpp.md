---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DisjointSparseTable.test.cpp
    title: Test/DisjointSparseTable.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b,
  bundledCode: "#line 1 \"DataStructure/DisjointSparseTable.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/04/30\r\n\r\n# \u4ED5\u69D8\r\n\u203B\u975E\u53EF\u63DB\u306E\
    \u5834\u5408\u306F unverified\r\nT \u306F\u534A\u7FA4\r\ntemplate<class InputIterator>\r\
    \nDisjointSparseTable(InputIterator first, InputIterator last, const F &f) :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u03B8(n log n)\r\n\t[farst, last) \u3067\u30C6\
    \u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\u308B\r\n\t\u4E8C\u9805\u6F14\u7B97\
    \ f\r\n\r\nsize_type empty() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u03B8(1)\r\n\t\u8981\u7D20\u304C\u7A7A\u3067\u3042\u308B\u304B\u3092\u5224\u5B9A\
    \u3059\u308B\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u03B8(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\nvalue_type\
    \ fold(size_type l, size_type r) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ \u03B8(loglog n)\r\n\t[l, r) \u3092 fold \u3057\u305F\u7D50\u679C\u3092\u8FD4\
    \u3059\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b,\
    \ 2020/04/30\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n#include <algorithm>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ DisjointSparseTable {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing size_type = std::size_t;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\t\r\n\ttemplate<class InputIterator>\r\n\tDisjointSparseTable(InputIterator\
    \ first, InputIterator last, const F &f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type empty() const noexcept {\
    \ return size() == 0; }\r\n\tsize_type size() const noexcept { return table.empty()\
    \ ? 0 : table.front().size(); }\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\t--r;\r\n\
    \t\tif (l == r) return table.front()[l];\r\n\t\tint level = msb(l ^ r) + 1;\r\n\
    \t\treturn f(table[level][l ^ (1 << level - 1) - 1], table[level][r]);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>> table;\r\n\
    \t\r\n\tvoid build() {\r\n\t\tassert(table.size() == 1);\r\n\t\ttable.reserve(size()\
    \ > 1 ? msb(size() - 1) + 2: 1);\r\n\t\tfor (size_type level = 1; 1 << level -\
    \ 1 <= size(); ++level) {\r\n\t\t\tsize_type rest = size() % (1 << level);\r\n\
    \t\t\ttable.emplace_back();\r\n\t\t\ttable.reserve(rest > 1 << level - 1 ? size()\
    \ : size() - rest);\r\n\t\t\t\r\n\t\t\tfor (size_type i = 0; i < size(); i +=\
    \ 1 << level) {\r\n\t\t\t\tsize_type k = std::min(i + (1 << level - 1), size());\r\
    \n\t\t\t\tif (k == size()) continue;\r\n\t\t\t\t\r\n\t\t\t\ttable.back().emplace_back(table.front()[k\
    \ - 1]);\r\n\t\t\t\tfor (size_type j = k - 1; j > i; --j)\r\n\t\t\t\t\ttable.back().emplace_back(f(table.front()[j\
    \ - 1], table.back().back()));\r\n\t\t\t\t\r\n\t\t\t\ttable.back().emplace_back(table.front()[k]);\r\
    \n\t\t\t\tfor (size_type j = k + 1, ej = std::min(i + (1 << level), size()); j\
    \ < ej; ++j)\r\n\t\t\t\t\ttable.back().emplace_back(f(table.back().back(), table.front()[j]));\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type msb(size_type n) const {\r\n\t\t\
    size_type l = 0, r = table.size();\r\n\t\twhile (r - l > 1) {\r\n\t\t\tsize_type\
    \ m = (l + r) / 2;\r\n\t\t\tif (1 << m <= n) l = m;\r\n\t\t\telse r = m;\r\n\t\
    \t}\r\n\t\treturn l;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP\r\n#define INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/04/30\r\n\r\n# \u4ED5\u69D8\r\n\u203B\u975E\u53EF\
    \u63DB\u306E\u5834\u5408\u306F unverified\r\nT \u306F\u534A\u7FA4\r\ntemplate<class\
    \ InputIterator>\r\nDisjointSparseTable(InputIterator first, InputIterator last,\
    \ const F &f) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u03B8(n log n)\r\n\t[farst,\
    \ last) \u3067\u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\u308B\r\n\t\u4E8C\
    \u9805\u6F14\u7B97 f\r\n\r\nsize_type empty() const noexcept :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u03B8(1)\r\n\t\u8981\u7D20\u304C\u7A7A\u3067\u3042\u308B\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u03B8(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\
    \n\r\nvalue_type fold(size_type l, size_type r) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u03B8(loglog n)\r\n\t[l, r) \u3092 fold \u3057\u305F\u7D50\u679C\
    \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2018/05/08/183946#fn-3c2b044b,\
    \ 2020/04/30\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n#include <algorithm>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ DisjointSparseTable {\r\npublic:\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing size_type = std::size_t;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\t\r\n\ttemplate<class InputIterator>\r\n\tDisjointSparseTable(InputIterator\
    \ first, InputIterator last, const F &f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type empty() const noexcept {\
    \ return size() == 0; }\r\n\tsize_type size() const noexcept { return table.empty()\
    \ ? 0 : table.front().size(); }\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\t--r;\r\n\
    \t\tif (l == r) return table.front()[l];\r\n\t\tint level = msb(l ^ r) + 1;\r\n\
    \t\treturn f(table[level][l ^ (1 << level - 1) - 1], table[level][r]);\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>> table;\r\n\
    \t\r\n\tvoid build() {\r\n\t\tassert(table.size() == 1);\r\n\t\ttable.reserve(size()\
    \ > 1 ? msb(size() - 1) + 2: 1);\r\n\t\tfor (size_type level = 1; 1 << level -\
    \ 1 <= size(); ++level) {\r\n\t\t\tsize_type rest = size() % (1 << level);\r\n\
    \t\t\ttable.emplace_back();\r\n\t\t\ttable.reserve(rest > 1 << level - 1 ? size()\
    \ : size() - rest);\r\n\t\t\t\r\n\t\t\tfor (size_type i = 0; i < size(); i +=\
    \ 1 << level) {\r\n\t\t\t\tsize_type k = std::min(i + (1 << level - 1), size());\r\
    \n\t\t\t\tif (k == size()) continue;\r\n\t\t\t\t\r\n\t\t\t\ttable.back().emplace_back(table.front()[k\
    \ - 1]);\r\n\t\t\t\tfor (size_type j = k - 1; j > i; --j)\r\n\t\t\t\t\ttable.back().emplace_back(f(table.front()[j\
    \ - 1], table.back().back()));\r\n\t\t\t\t\r\n\t\t\t\ttable.back().emplace_back(table.front()[k]);\r\
    \n\t\t\t\tfor (size_type j = k + 1, ej = std::min(i + (1 << level), size()); j\
    \ < ej; ++j)\r\n\t\t\t\t\ttable.back().emplace_back(f(table.back().back(), table.front()[j]));\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type msb(size_type n) const {\r\n\t\t\
    size_type l = 0, r = table.size();\r\n\t\twhile (r - l > 1) {\r\n\t\t\tsize_type\
    \ m = (l + r) / 2;\r\n\t\t\tif (1 << m <= n) l = m;\r\n\t\t\telse r = m;\r\n\t\
    \t}\r\n\t\treturn l;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_DISJOINT_SPARSE_TABLE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DisjointSparseTable.test.cpp
documentation_of: DataStructure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/DataStructure/DisjointSparseTable.hpp
- /library/DataStructure/DisjointSparseTable.hpp.html
title: DataStructure/DisjointSparseTable.hpp
---
