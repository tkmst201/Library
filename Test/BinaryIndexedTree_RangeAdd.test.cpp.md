---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: "\u533A\u9593\u52A0\u7B97 Binary Indexed Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"Test/BinaryIndexedTree_RangeAdd.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\r\n\r\n\
    #line 1 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\n\n\r\n#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\
    \r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing F = std::function<value_type\
    \ (const_reference, const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\
    \t\r\nprivate:\r\n\tsize_type n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tBinaryIndexedTree(size_type n, const_reference id_elem,\
    \ const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f), node(n + 1, id_elem) {}\r\
    \n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\t\
    void add(size_type i, const_reference x) noexcept {\r\n\t\tassert(i < size());\r\
    \n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i], x);\r\n\
    \t}\r\n\t\r\n\tvalue_type sum(size_type i) const noexcept {\r\n\t\tassert(i <=\
    \ size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0; i -= i & -i)\
    \ res = f(node[i], res);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem,\
    \ w = 1;\r\n\t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\
    \t\t\tif (res + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\
    \n\t\t\t\tif (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \n\r\n#line 8 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/DataStructure/BinaryIndexedTree_RangeAdd.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree_RangeAdd {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\t\r\n\tusing bit_type = BinaryIndexedTree<T>;\r\n\tusing value_type\
    \ = typename bit_type::value_type;\r\n\tusing size_type = typename bit_type::size_type;\r\
    \n\t\r\nprivate:\r\n\tstd::vector<bit_type> bit;\r\n\t\r\npublic:\r\n\texplicit\
    \ BinaryIndexedTree_RangeAdd(size_type n)\r\n\t\t: bit(2, bit_type{n, 0, [](value_type\
    \ x, value_type y) { return x + y; }}) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn bit[0].size();\r\n\t}\r\n\t\r\n\tvoid add(size_type l, size_type\
    \ r, value_type x) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return;\r\n\t\tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\
    \n\t\tbit[1].add(l, -x * l);\r\n\t\tbit[1].add(r - 1, x * r);\r\n\t}\r\n\t\r\n\
    \tvalue_type sum(size_type i) noexcept {\r\n\t\tassert(i <= size());\r\n\t\treturn\
    \ bit[0].sum(i) * i + bit[1].sum(i);\r\n\t}\r\n\t\r\n\tvalue_type sum(size_type\
    \ l, size_type r) noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= size());\r\
    \n\t\tif (l == r) return 0;\r\n\t\treturn sum(r) - sum(l);\r\n\t}\r\n};\r\n\r\n\
    \n#line 4 \"Test/BinaryIndexedTree_RangeAdd.test.cpp\"\n\r\n#include <cstdio>\r\
    \nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\", &n, &q);\r\n\t\r\n\tusing\
    \ ll = long long;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd<ll> bit(n);\r\n\twhile\
    \ (q--) {\r\n\t\tint query, s, t;\r\n\t\tscanf(\"%d %d %d\", &query, &s, &t);\r\
    \n\t\t--s;\r\n\t\tif (query == 0) {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\
    \n\t\t\tbit.add(s, t, x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tprintf(\"%lld\\n\",\
    \ bit.sum(s, t));\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\", &n, &q);\r\n\t\
    \r\n\tusing ll = long long;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd<ll> bit(n);\r\
    \n\twhile (q--) {\r\n\t\tint query, s, t;\r\n\t\tscanf(\"%d %d %d\", &query, &s,\
    \ &t);\r\n\t\t--s;\r\n\t\tif (query == 0) {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"\
    %d\", &x);\r\n\t\t\tbit.add(s, t, x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tprintf(\"\
    %lld\\n\", bit.sum(s, t));\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree_RangeAdd.hpp
  - DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: Test/BinaryIndexedTree_RangeAdd.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BinaryIndexedTree_RangeAdd.test.cpp
layout: document
redirect_from:
- /verify/Test/BinaryIndexedTree_RangeAdd.test.cpp
- /verify/Test/BinaryIndexedTree_RangeAdd.test.cpp.html
title: Test/BinaryIndexedTree_RangeAdd.test.cpp
---
