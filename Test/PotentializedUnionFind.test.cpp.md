---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PotentializedUnionFind.hpp
    title: DataStructure/PotentializedUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"Test/PotentializedUnionFind.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\r\n\r\n#line\
    \ 1 \"DataStructure/PotentializedUnionFind.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/04/23\r\n\r\n\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D UnionFind\r\
    \n\r\n# \u4ED5\u69D8\r\nPotentializedUnionFind(size_type n, const F &f, const_reference\
    \ id_elem) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u8981\u7D20\u6570\
    \ n, \u4E8C\u9805\u6F14\u7B97 f, \u5358\u4F4D\u5143 id_elem \u3067\u521D\u671F\
    \u5316\r\n\r\nsize_type size(size_type x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\t\u8981\u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\nvalue_type get(size_type x)\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u8981\u7D20 x \u304B\u3089\
    \u6839\u307E\u3067 fold \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ add(const_reference v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \u5024\u304C v \u3067\u3042\u308B\u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\r\n\
    \r\nsize_type find(size_type x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\
    \n\t\u8981\u7D20 x \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u4EE3\
    \u8868\u756A\u53F7\u3092\u8FD4\u3059\r\n\r\nvoid link(size_type p, size_type x)\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u8981\u7D20 x \u306E\u89AA\
    \u3092 p \u306B\u8A2D\u5B9A\u3059\u308B(\u3053\u306E\u3068\u304D\u3001x \u306E\
    \u89AA\u306E\u4ED8\u3051\u66FF\u3048\u306F\u767A\u751F\u3057\u3066\u306F\u3044\
    \u3051\u306A\u3044)\r\n\r\nbool issame(size_type x, size_type y) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u8981\u7D20 x, y \u304C\u540C\u4E00\u30B0\
    \u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u3092\u8FD4\u3059\r\n\r\nTODO:\
    \ \u8A08\u7B97\u91CF\u3092 O(\u03B1(n)) \u306B\u6539\u5584\u3067\u304D\u308B\u3089\
    \u3057\u3044\u306E\u3067\u3059\u308B\r\nTODO: Potential \u611F\u3092\u51FA\u3059\
    \ (2 \u8981\u7D20\u306E\u5DEE\u306E\u5236\u7D04\u306E\u8FFD\u52A0, diff \u306E\
    \u8FFD\u52A0\u306A\u3069)\r\n\r\n# \u53C2\u8003\r\nhttp://sigma425.hatenablog.com/entry/2015/12/07/185047,\
    \ 2020/04/23\r\n\r\nverify : https://atcoder.jp/contests/abc087/submissions/12241089\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <numeric>\r\n#include <utility>\r\n\
    #include <cassert>\r\n#include <functional>\r\n#include <stack>\r\n\r\ntemplate<typename\
    \ T>\r\nstruct PotentializedUnionFind {\r\npublic:\r\n\tusing value_type = T;\r\
    \n\tusing const_reference = const value_type &;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing F = std::function<value_type(const_reference, const_reference)>;\r\n\
    \t\r\n\tPotentializedUnionFind(size_type n, const F &f, const_reference id_elem)\r\
    \n\t\t\t: n(n), f(f), id_elem(id_elem), size_(n, 1), val(n, id_elem) {\r\n\t\t\
    par.resize(n);\r\n\t\tstd::iota(par.begin(), par.end(), 0);\r\n\t}\r\n\t\r\n\t\
    size_type size(size_type x) { return size_[find(x)]; }\r\n\t\r\n\tvalue_type get(size_type\
    \ x) {\r\n\t\tfind(x);\r\n\t\tif (par[x] == x) return val[x];\r\n\t\treturn f(val[par[x]],\
    \ val[x]);\r\n\t}\r\n\t\r\n\tsize_type add(const_reference v) {\r\n\t\tsize_.emplace_back(1);\r\
    \n\t\tpar.emplace_back(n);\r\n\t\tval.emplace_back(v);\r\n\t\treturn n++;\r\n\t\
    }\r\n\t\r\n\tsize_type find(size_type x) {\r\n\t\tassert(x < n);\r\n\t\tstd::stack<size_type>\
    \ stk;\r\n\t\tstk.push(x);\r\n\t\twhile (par[stk.top()] != stk.top()) stk.push(par[stk.top()]);\r\
    \n\t\t\r\n\t\tsize_type r = stk.top();\r\n\t\tstk.pop();\r\n\t\tbool r_child =\
    \ true;\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst size_type &t = stk.top();\r\
    \n\t\t\tif (!r_child) val[t] = f(val[par[t]], val[t]);\r\n\t\t\tpar[t] = r;\r\n\
    \t\t\tr_child = false;\r\n\t\t\tstk.pop();\r\n\t\t}\r\n\t\treturn r;\r\n\t}\r\n\
    \t\r\n\tvoid link(size_type p, size_type x) {\r\n\t\tassert(par[x] == x);\r\n\t\
    \tpar[x] = p;\r\n\t\tsize_[find(p)] += size_[x];\r\n\t}\r\n\t\r\n\tbool issame(size_type\
    \ x, size_type y) { return find(x) == find(y); }\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<size_type> size_, par;\r\
    \n\tstd::vector<value_type> val;\r\n};\r\n\r\n\n#line 4 \"Test/PotentializedUnionFind.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, M;\r\n\twhile(scanf(\"\
    %d %d\", &N, &M), N && M) {\r\n\t\tPotentializedUnionFind<int> puf(N, [](int a,\
    \ int b){ return a + b; }, 0);\r\n\t\tfor (int i = 0; i < M; ++i) {\r\n\t\t\t\
    char c;\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\" %c %d %d\", &c, &a, &b);\r\n\t\t\t\
    --a; --b;\r\n\t\t\t\r\n\t\t\tif (c == '!') {\r\n\t\t\t\tint w;\r\n\t\t\t\tscanf(\"\
    %d\", &w);\r\n\t\t\t\tif (!puf.issame(a, b)) {\r\n\t\t\t\t\tint u = puf.add(w\
    \ - puf.get(b));\r\n\t\t\t\t\tpuf.link(a, u);\r\n\t\t\t\t\tpuf.link(u, puf.find(b));\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tif (puf.issame(a, b)) printf(\"\
    %d\\n\", puf.get(b) - puf.get(a));\r\n\t\t\t\telse puts(\"UNKNOWN\");\r\n\t\t\t\
    }\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \r\n\r\n#include \"DataStructure/PotentializedUnionFind.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\n\r\nint main() {\r\n\tint N, M;\r\n\twhile(scanf(\"%d %d\", &N,\
    \ &M), N && M) {\r\n\t\tPotentializedUnionFind<int> puf(N, [](int a, int b){ return\
    \ a + b; }, 0);\r\n\t\tfor (int i = 0; i < M; ++i) {\r\n\t\t\tchar c;\r\n\t\t\t\
    int a, b;\r\n\t\t\tscanf(\" %c %d %d\", &c, &a, &b);\r\n\t\t\t--a; --b;\r\n\t\t\
    \t\r\n\t\t\tif (c == '!') {\r\n\t\t\t\tint w;\r\n\t\t\t\tscanf(\"%d\", &w);\r\n\
    \t\t\t\tif (!puf.issame(a, b)) {\r\n\t\t\t\t\tint u = puf.add(w - puf.get(b));\r\
    \n\t\t\t\t\tpuf.link(a, u);\r\n\t\t\t\t\tpuf.link(u, puf.find(b));\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tif (puf.issame(a, b)) printf(\"%d\\n\"\
    , puf.get(b) - puf.get(a));\r\n\t\t\t\telse puts(\"UNKNOWN\");\r\n\t\t\t}\r\n\t\
    \t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - DataStructure/PotentializedUnionFind.hpp
  isVerificationFile: true
  path: Test/PotentializedUnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PotentializedUnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/PotentializedUnionFind.test.cpp
- /verify/Test/PotentializedUnionFind.test.cpp.html
title: Test/PotentializedUnionFind.test.cpp
---
