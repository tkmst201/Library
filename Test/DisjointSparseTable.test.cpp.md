---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DisjointSparseTable.hpp
    title: Disjoint Sparse Table
  - icon: ':heavy_check_mark:'
    path: Mathematics/bit_operation.hpp
    title: "bit \u64CD\u4F5C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Test/DisjointSparseTable.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_sum\"\r\n\r\n#line 1 \"DataStructure/DisjointSparseTable.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <functional>\r\n\
    #include <algorithm>\r\n#include <utility>\r\n\r\n#include <Mathematics/bit_operation.hpp>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/DisjointSparseTable.hpp\r\
    \n */\r\ntemplate <typename T>\r\nstruct DisjointSparseTable {\r\npublic:\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing F = std::function<value_type (const_reference,\
    \ const_reference)>;\r\n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>>\
    \ table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\n\tDisjointSparseTable(InputIterator\
    \ first, InputIterator last, const F & f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\
    \n\t\treturn table.empty() ? 0 : table.front().size();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold(size_type l, size_type r) const noexcept {\r\n\t\tassert(l < r);\r\n\t\t\
    assert(r <= size());\r\n\t\t--r;\r\n\t\tif (l == r) return table.front()[l];\r\
    \n\t\tsize_type level = 31 - tk::count_leading_zeros(l ^ r);\r\n\t\treturn f(table[level][l\
    \ ^ ~(~0 << level)], table[level][r]);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build()\
    \ {\r\n\t\tif (size() <= 2) return;\r\n\t\ttable.reserve(32 - tk::count_leading_zeros(size()\
    \ - 1));\r\n\t\tfor (size_type level = 1; (1 << level) + 1 <= size(); ++level)\
    \ {\r\n\t\t\tstd::vector<value_type> dat;\r\n\t\t\tconst size_type cnt = size()\
    \ & (~0 << (level + 1));\r\n\t\t\tdat.reserve(cnt + (1 << level) + 1 <= size()\
    \ ? size() : cnt);\r\n\t\t\tfor (size_type i = 0; i < size(); i += 1 << (level\
    \ + 1)) {\r\n\t\t\t\tsize_type k = i + (1 << level);\r\n\t\t\t\tif (k >= size())\
    \ continue;\r\n\t\t\t\tdat.emplace_back(table.front()[k - 1]);\r\n\t\t\t\tfor\
    \ (size_type j = k - 1; j != i; --j) {\r\n\t\t\t\t\tdat.emplace_back(f(table.front()[j\
    \ - 1], dat.back()));\r\n\t\t\t\t}\r\n\t\t\t\tdat.emplace_back(table.front()[k]);\r\
    \n\t\t\t\tfor (size_type j = k + 1, ej = std::min(k + (1 << level), size()); j\
    \ != ej; ++j) {\r\n\t\t\t\t\tdat.emplace_back(f(dat.back(), table.front()[j]));\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\ttable.emplace_back(std::move(dat));\r\n\t\t}\r\
    \n\t}\r\n};\r\n\r\n\n#line 4 \"Test/DisjointSparseTable.test.cpp\"\n// \u3053\u308C\
    \u306F\u53EF\u63DB\u306E\u5834\u5408\u3067\u306E\u30C6\u30B9\u30C8\r\n\r\n#include\
    \ <cstdio>\r\n#line 8 \"Test/DisjointSparseTable.test.cpp\"\n\r\nint main() {\r\
    \n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\
    \n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tusing ll = long\
    \ long;\r\n\tDisjointSparseTable<ll> dst(A.begin(), A.end(), [](ll x, ll y) {\r\
    \n\t\treturn x + y;\r\n\t});\r\n\twhile (Q--) {\r\n\t\tint l, r;\r\n\t\tscanf(\"\
    %d%d\", &l, &r);\r\n\t\tprintf(\"%lld\\n\", dst.fold(l, r));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\r\n\r\
    \n#include \"DataStructure/DisjointSparseTable.hpp\"\r\n// \u3053\u308C\u306F\u53EF\
    \u63DB\u306E\u5834\u5408\u3067\u306E\u30C6\u30B9\u30C8\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N,\
    \ &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"\
    %d\", &A[i]);\r\n\t\r\n\tusing ll = long long;\r\n\tDisjointSparseTable<ll> dst(A.begin(),\
    \ A.end(), [](ll x, ll y) {\r\n\t\treturn x + y;\r\n\t});\r\n\twhile (Q--) {\r\
    \n\t\tint l, r;\r\n\t\tscanf(\"%d%d\", &l, &r);\r\n\t\tprintf(\"%lld\\n\", dst.fold(l,\
    \ r));\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/DisjointSparseTable.hpp
  - Mathematics/bit_operation.hpp
  isVerificationFile: true
  path: Test/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 11:48:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/Test/DisjointSparseTable.test.cpp
- /verify/Test/DisjointSparseTable.test.cpp.html
title: Test/DisjointSparseTable.test.cpp
---
