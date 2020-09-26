---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SparseTable.hpp
    title: DataStructure/SparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"DataStructure/SparseTable.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/04/30\r\n\r\nbuild \u03B8(n log n), fold \u03B8(1)\r\n\r\n# \u4ED5\u69D8\
    \r\ntemplate<class InputIterator>\r\nDisjointSparseTable(InputIterator first,\
    \ InputIterator last, const F &f) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (n log n)\r\n\t[farst, last) \u3067\u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u6210\u3059\
    \u308B\r\n\t\u51AA\u7B49\u306A\u4E8C\u9805\u6F14\u7B97 f\r\n\r\nsize_type empty()\
    \ const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\
    \u304C\u7A7A\u3067\u3042\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\r\n\r\nsize_type\
    \ size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\nvalue_type fold(size_type l, size_type\
    \ r) const :\r\n\t\u03B8(1)\r\n\t[l, r) \u3092 fold \u3057\u305F\u7D50\u679C\u3092\
    \u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://tookunn.hatenablog.com/entry/2016/07/13/211148,\
    \ 2020/04/30\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T>\r\nstruct SparseTable {\r\npublic:\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing size_type = std::size_t;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\t\r\n\ttemplate<class InputIterator>\r\n\tSparseTable(InputIterator\
    \ first, InputIterator last, const F &f) : f(f) {\r\n\t\ttable.emplace_back(first,\
    \ last);\r\n\t\tbuild();\r\n\t}\r\n\t\r\n\tbool empty() const noexcept { return\
    \ size() == 0; }\r\n\tsize_type size() const noexcept { return table.empty() ?\
    \ 0 : table.front().size(); }\r\n\t\r\n\tvalue_type fold(size_type l, size_type\
    \ r) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\tsize_type\
    \ diff = r - l;\r\n\t\treturn f(table[log_table[diff] - 1][l], table[log_table[diff]\
    \ - 1][r - (1 << log_table[diff] - 1)]);\r\n\t}\r\n\t\r\nprivate:\r\n\tF f;\r\n\
    \tstd::vector<std::vector<value_type>> table;\r\n\tstd::vector<size_type> log_table;\r\
    \n\t\r\n\tvoid build() {\r\n\t\tlog_table.reserve(size() + 1);\r\n\t\tlog_table.emplace_back(0);\r\
    \n\t\tfor (size_type i = 1; i <= size(); ++i) log_table.emplace_back(log_table[i\
    \ >> 1] + 1);\r\n\t\t\r\n\t\ttable.reserve(log_table[size()]);\r\n\t\tfor (size_type\
    \ i = 1; i < log_table[size()]; ++i) {\r\n\t\t\ttable.emplace_back();\r\n\t\t\t\
    table[i].reserve(size() - (1 << i) + 1);\r\n\t\t\tfor (size_type j = 0; j + (1\
    \ << i) <= size(); ++j)\r\n\t\t\t\ttable[i].emplace_back(f(table[i - 1][j], table[i\
    \ - 1][j + (1 << i - 1)]));\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/SparseTable.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <algorithm>\r\n#line 8 \"Test/SparseTable.test.cpp\"\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::vector<int>\
    \ A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tSparseTable<int>\
    \ st(A.begin(), A.end(), [](int x, int y) {\r\n\t\treturn std::min(x, y);\r\n\t\
    });\r\n\twhile (Q--) {\r\n\t\tint l, r;\r\n\t\tscanf(\"%d %d\", &l, &r);\r\n\t\
    \tprintf(\"%d\\n\", st.fold(l, r));\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"DataStructure/SparseTable.hpp\"\r\n\r\n#include <cstdio>\r\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N,\
    \ &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"\
    %d\", &A[i]);\r\n\t\r\n\tSparseTable<int> st(A.begin(), A.end(), [](int x, int\
    \ y) {\r\n\t\treturn std::min(x, y);\r\n\t});\r\n\twhile (Q--) {\r\n\t\tint l,\
    \ r;\r\n\t\tscanf(\"%d %d\", &l, &r);\r\n\t\tprintf(\"%d\\n\", st.fold(l, r));\r\
    \n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: Test/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/Test/SparseTable.test.cpp
- /verify/Test/SparseTable.test.cpp.html
title: Test/SparseTable.test.cpp
---
