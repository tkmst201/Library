---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"DataStructure/SparseTable.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <functional>\r\n#include <cstdint>\r\n\r\n/**\r\
    \n * @brief https://tkmst201.github.io/Library/DataStructure/SparseTable.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct SparseTable {\r\npublic:\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing F = std::function<value_type (const_reference, const_reference)>;\r\
    \n\t\r\nprivate:\r\n\tF f;\r\n\tstd::vector<std::vector<value_type>> table;\r\n\
    \tstd::vector<std::uint8_t> log_table;\r\n\t\r\npublic:\r\n\ttemplate<class InputIterator>\r\
    \n\tSparseTable(InputIterator first, InputIterator last, const F & f) : f(f) {\r\
    \n\t\ttable.emplace_back(first, last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn table.empty() ? 0 : table.front().size();\r\
    \n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type r) const noexcept {\r\n\
    \t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\tconst size_type k = log_table[r\
    \ - l];\r\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\r\n\t}\r\n\t\r\n\
    private:\r\n\tvoid build() {\r\n\t\tlog_table.reserve(size() + 1);\r\n\t\tlog_table.emplace_back(0);\r\
    \n\t\tlog_table.emplace_back(0);\r\n\t\tfor (size_type i = 2; i <= size(); ++i)\
    \ log_table.emplace_back(log_table[i >> 1] + 1);\r\n\t\t\r\n\t\ttable.reserve(log_table[size()]\
    \ + 1);\r\n\t\tfor (size_type i = 1; i <= log_table[size()]; ++i) {\r\n\t\t\t\
    table.emplace_back();\r\n\t\t\ttable[i].reserve(size() - (1 << i) + 1);\r\n\t\t\
    \tfor (size_type j = 0; j + (1 << i) <= size(); ++j) {\r\n\t\t\t\ttable[i].emplace_back(f(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]));\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    };\r\n\r\n\n#line 4 \"Test/SparseTable.test.cpp\"\n\r\n#include <cstdio>\r\n#include\
    \ <algorithm>\r\n#line 8 \"Test/SparseTable.test.cpp\"\n\r\nint main() {\r\n\t\
    int N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\n\
    \tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tSparseTable<int>\
    \ st(A.begin(), A.end(), [](int x, int y) {\r\n\t\treturn std::min(x, y);\r\n\t\
    });\r\n\twhile (Q--) {\r\n\t\tint l, r;\r\n\t\tscanf(\"%d %d\", &l, &r);\r\n\t\
    \tprintf(\"%d\\n\", st.fold(l, r));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"DataStructure/SparseTable.hpp\"\r\n\r\n#include <cstdio>\r\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N,\
    \ &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"\
    %d\", &A[i]);\r\n\t\r\n\tSparseTable<int> st(A.begin(), A.end(), [](int x, int\
    \ y) {\r\n\t\treturn std::min(x, y);\r\n\t});\r\n\twhile (Q--) {\r\n\t\tint l,\
    \ r;\r\n\t\tscanf(\"%d %d\", &l, &r);\r\n\t\tprintf(\"%d\\n\", st.fold(l, r));\r\
    \n\t}\r\n}"
  dependsOn:
  - DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: Test/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 18:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/Test/SparseTable.test.cpp
- /verify/Test/SparseTable.test.cpp.html
title: Test/SparseTable.test.cpp
---
