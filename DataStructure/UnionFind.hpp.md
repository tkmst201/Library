---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/UnionFind.test.cpp
    title: Test/UnionFind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/abc157/submissions/12223429
    - https://en.wikipedia.org/wiki/Disjoint-set_data_structure,
    - https://qiita.com/kopricky/items/3e5847ab1451fe990367,
  bundledCode: "#line 1 \"DataStructure/UnionFind.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <numeric>\r\n#include <utility>\r\n#include <cassert>\r\n\r\n/*\r\n\
    last-updated: 2020/04/22\r\n\r\nsize() verify : https://atcoder.jp/contests/abc157/submissions/12223429\r\
    \n\r\n# \u4ED5\u69D8\r\nUnionFind(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n)\r\n\t\u8981\u7D20\u6570 n \u3067\u521D\u671F\u5316\r\n\r\nsize_type\
    \ size(size_type x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\
    \u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\r\n\r\nsize_type find(size_type x) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\
    \u30FC\u30D7\u306E\u4EE3\u8868\u756A\u53F7\u3092\u8FD4\u3059\r\n\r\nvoid unite(size_type\
    \ x, size_type y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\
    \u7D20 x, y \u304C\u305D\u308C\u305E\u308C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u3092\u4F75\u5408\u3059\u308B\r\n\r\nbool issame(size_type x, size_type\
    \ y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\u7D20 x,\
    \ y \u304C\u540C\u4E00\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u3092\
    \u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://en.wikipedia.org/wiki/Disjoint-set_data_structure,\
    \ 2020/04/22\r\nhttps://qiita.com/kopricky/items/3e5847ab1451fe990367, 2020/04/22\r\
    \n*/\r\n\r\nstruct UnionFind {\r\npublic:\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\n\tUnionFind(size_type n) : n(n), size_(n, 1) {\r\n\t\tpar.resize(n);\r\
    \n\t\tstd::iota(par.begin(), par.end(), 0);\r\n\t}\r\n\t\r\n\tsize_type size(size_type\
    \ x) { return size_[find(x)]; }\r\n\t\r\n\tsize_type find(size_type x) {\r\n\t\
    \tassert(x < n);\r\n\t\twhile (par[x] != x) {\r\n\t\t\tpar[x] = par[par[x]];\r\
    \n\t\t\tx = par[x];\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\t\r\n\tvoid unite(size_type\
    \ x, size_type y) {\r\n\t\tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y)\
    \ return;\r\n\t\tif (size(x) > size(y)) std::swap(x, y);\r\n\t\tpar[x] = y;\r\n\
    \t\tsize_[y] += size_[x];\r\n\t}\r\n\t\r\n\tbool issame(size_type x, size_type\
    \ y) { return find(x) == find(y); }\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\t\
    std::vector<size_type> size_, par;\r\n};\r\n\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_UNION_FIND_HPP\r\n#define INCLUDE_GUARD_UNION_FIND_HPP\r\
    \n\r\n#include <vector>\r\n#include <numeric>\r\n#include <utility>\r\n#include\
    \ <cassert>\r\n\r\n/*\r\nlast-updated: 2020/04/22\r\n\r\nsize() verify : https://atcoder.jp/contests/abc157/submissions/12223429\r\
    \n\r\n# \u4ED5\u69D8\r\nUnionFind(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n)\r\n\t\u8981\u7D20\u6570 n \u3067\u521D\u671F\u5316\r\n\r\nsize_type\
    \ size(size_type x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\
    \u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\r\n\r\nsize_type find(size_type x) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\
    \u30FC\u30D7\u306E\u4EE3\u8868\u756A\u53F7\u3092\u8FD4\u3059\r\n\r\nvoid unite(size_type\
    \ x, size_type y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\
    \u7D20 x, y \u304C\u305D\u308C\u305E\u308C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u3092\u4F75\u5408\u3059\u308B\r\n\r\nbool issame(size_type x, size_type\
    \ y) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(\u03B1(n))\r\n\t\u8981\u7D20 x,\
    \ y \u304C\u540C\u4E00\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u3092\
    \u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://en.wikipedia.org/wiki/Disjoint-set_data_structure,\
    \ 2020/04/22\r\nhttps://qiita.com/kopricky/items/3e5847ab1451fe990367, 2020/04/22\r\
    \n*/\r\n\r\nstruct UnionFind {\r\npublic:\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\n\tUnionFind(size_type n) : n(n), size_(n, 1) {\r\n\t\tpar.resize(n);\r\
    \n\t\tstd::iota(par.begin(), par.end(), 0);\r\n\t}\r\n\t\r\n\tsize_type size(size_type\
    \ x) { return size_[find(x)]; }\r\n\t\r\n\tsize_type find(size_type x) {\r\n\t\
    \tassert(x < n);\r\n\t\twhile (par[x] != x) {\r\n\t\t\tpar[x] = par[par[x]];\r\
    \n\t\t\tx = par[x];\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\t\r\n\tvoid unite(size_type\
    \ x, size_type y) {\r\n\t\tx = find(x);\r\n\t\ty = find(y);\r\n\t\tif (x == y)\
    \ return;\r\n\t\tif (size(x) > size(y)) std::swap(x, y);\r\n\t\tpar[x] = y;\r\n\
    \t\tsize_[y] += size_[x];\r\n\t}\r\n\t\r\n\tbool issame(size_type x, size_type\
    \ y) { return find(x) == find(y); }\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\t\
    std::vector<size_type> size_, par;\r\n};\r\n\r\n\r\n#endif // INCLUDE_GUARD_UNION_FIND_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/UnionFind.test.cpp
documentation_of: DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.hpp
- /library/DataStructure/UnionFind.hpp.html
title: DataStructure/UnionFind.hpp
---
