---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Test/StronglyConnectedComponents.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\n\r\
    \n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/StronglyConnectedComponents.hpp\r\
    \n */\r\nstruct StronglyConnectedComponents {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<int> rank_;\r\n\tstd::vector<std::vector<int>>\
    \ rank_list_;\r\n\t\r\npublic:\r\n\texplicit StronglyConnectedComponents(const\
    \ Graph & g) : n(g.size()) {\r\n\t\tGraph rg(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\r\n\t\t\tfor (int j : g[i]) {\r\n\t\t\t\tassert(0 <= j && j < n);\r\n\
    \t\t\t\trg[j].emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<bool> visited(n,\
    \ false);\r\n\t\tstd::vector<int> num;\r\n\t\tauto dfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\tfor (int v : g[u]) if (!visited[v])\
    \ self(self, v);\r\n\t\t\tnum.emplace_back(u);\r\n\t\t};\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) if (!visited[i]) dfs(dfs, i);\r\n\t\tint cnt = 0;\r\n\t\tvisited.assign(n,\
    \ false);\r\n\t\trank_.assign(n, -1);\r\n\t\tauto rdfs = [&](auto self, int u)\
    \ -> void {\r\n\t\t\tvisited[u] = true;\r\n\t\t\trank_[u] = cnt;\r\n\t\t\tfor\
    \ (int v : rg[u]) if (!visited[v]) self(self, v);\r\n\t\t};\r\n\t\tfor (int i\
    \ = n - 1; i >= 0; --i) if (!visited[num[i]]) rdfs(rdfs, num[i]), ++cnt;\r\n\t\
    \trank_list_.assign(cnt, {});\r\n\t\tfor (int i = 0; i < n; ++i) rank_list_[rank_[i]].emplace_back(i);\r\
    \n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\
    \tint scc_size() const noexcept {\r\n\t\treturn rank_list_.size();\r\n\t}\r\n\t\
    \r\n\tint scc_size(int k) const noexcept {\r\n\t\tassert(0 <= k && k < scc_size());\r\
    \n\t\treturn rank_list_[k].size();\r\n\t}\r\n\t\r\n\tint rank(int u) const noexcept\
    \ {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn rank_[u];\r\n\t}\r\n\t\r\
    \n\tconst std::vector<int> & rank_list(int k) const noexcept {\r\n\t\tassert(0\
    \ <= k && k < scc_size());\r\n\t\treturn rank_list_[k];\r\n\t}\r\n\t\r\n\tGraph\
    \ get_graph(const Graph & g) const {\r\n\t\tGraph res(scc_size());\r\n\t\tfor\
    \ (int i = 0; i < scc_size(); ++i) {\r\n\t\t\tfor (int j : rank_list_[i]) for\
    \ (int v : g[j]) if (rank(v) != i) res[i].emplace_back(rank(v));\r\n\t\t\tstd::sort(begin(res[i]),\
    \ end(res[i]));\r\n\t\t\tres[i].erase(unique(begin(res[i]), end(res[i])), end(res[i]));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/StronglyConnectedComponents.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, M;\r\n\tscanf(\"%d %d\"\
    , &N, &M);\r\n\t\r\n\tStronglyConnectedComponents::Graph g(N);\r\n\tfor (int i\
    \ = 0; i < M; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\t\
    g[a].emplace_back(b);\r\n\t}\r\n\tStronglyConnectedComponents scc(g);\r\n\tprintf(\"\
    %d\\n\", scc.scc_size());\r\n\t\r\n\tfor (int i = 0; i < scc.scc_size(); ++i)\
    \ {\r\n\t\tauto & lis = scc.rank_list(i);\r\n\t\tprintf(\"%d \", lis.size());\r\
    \n\t\tfor (int j = 0; j < lis.size(); ++j) printf(\"%d%c\", lis[j], \" \\n\"[j\
    \ + 1 == lis.size()]);\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    GraphTheory/StronglyConnectedComponents.hpp\"\r\n\r\n#include <cstdio>\r\n\r\n\
    int main() {\r\n\tint N, M;\r\n\tscanf(\"%d %d\", &N, &M);\r\n\t\r\n\tStronglyConnectedComponents::Graph\
    \ g(N);\r\n\tfor (int i = 0; i < M; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d\
    \ %d\", &a, &b);\r\n\t\tg[a].emplace_back(b);\r\n\t}\r\n\tStronglyConnectedComponents\
    \ scc(g);\r\n\tprintf(\"%d\\n\", scc.scc_size());\r\n\t\r\n\tfor (int i = 0; i\
    \ < scc.scc_size(); ++i) {\r\n\t\tauto & lis = scc.rank_list(i);\r\n\t\tprintf(\"\
    %d \", lis.size());\r\n\t\tfor (int j = 0; j < lis.size(); ++j) printf(\"%d%c\"\
    , lis[j], \" \\n\"[j + 1 == lis.size()]);\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: Test/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/Test/StronglyConnectedComponents.test.cpp
- /verify/Test/StronglyConnectedComponents.test.cpp.html
title: Test/StronglyConnectedComponents.test.cpp
---
