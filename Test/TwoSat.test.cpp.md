---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC)"
  - icon: ':heavy_check_mark:'
    path: Mathematics/TwoSat.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"Test/TwoSat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#line 1 \"Mathematics/TwoSat.hpp\"\n\n\n\r\n#line 1 \"GraphTheory/StronglyConnectedComponents.hpp\"\
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
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Mathematics/TwoSat.hpp\"\
    \n\r\n#line 8 \"Mathematics/TwoSat.hpp\"\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp\r\
    \n */\r\nstruct TwoSat {\r\n\tusing scc_type = StronglyConnectedComponents;\r\n\
    \t\r\nprivate:\r\n\tint n;\r\n\ttypename scc_type::Graph g;\r\n\tstd::vector<bool>\
    \ ans;\r\n\tbool satisfiability = false;\r\n\t\r\npublic:\r\n\texplicit TwoSat(int\
    \ n) : n(n), g(2 * n) {}\r\n\t\r\n\tint size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid add_clause(int x, bool xb, int y, bool yb) {\r\n\t\
    \tassert(0 <= x && x < n);\r\n\t\tassert(0 <= y && y < n);\r\n\t\tg[x + (xb ?\
    \ n : 0)].emplace_back(y + (yb ? 0 : n));\r\n\t\tg[y + (yb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tvoid add_clause(int\
    \ x, bool xb) {\r\n\t\tassert(0 <= x && x < n);\r\n\t\tg[x + (xb ? n : 0)].emplace_back(x\
    \ + (xb ? 0 : n));\r\n\t\tsatisfiability = false;\r\n\t}\r\n\t\r\n\tbool build()\
    \ {\r\n\t\tscc_type scc(g);\r\n\t\tans.assign(n, false);\r\n\t\tsatisfiability\
    \ = false;\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tif (scc.rank(i) == scc.rank(i\
    \ + n)) return false;\r\n\t\t\tif (scc.rank(i) > scc.rank(i + n)) ans[i] = true;\r\
    \n\t\t}\r\n\t\tsatisfiability = true;\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\tconst\
    \ std::vector<bool> & ans_list() const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\treturn ans;\r\n\t}\r\n\t\r\n\tbool get(int i) const noexcept {\r\n\t\tassert(satisfiability);\r\
    \n\t\tassert(0 <= i && i < n);\r\n\t\treturn ans[i];\r\n\t}\r\n};\r\n\r\n\n#line\
    \ 4 \"Test/TwoSat.test.cpp\"\n\r\n#include <iostream>\r\n#include <string>\r\n\
    #include <cmath>\r\n\r\nint main() {\r\n\tstd::ios::sync_with_stdio(false);\r\n\
    \tstd::cin.tie(0);\r\n\t\r\n\tstd::string dummy; std::cin >> dummy >> dummy;\r\
    \n\t\r\n\tint N, M;\r\n\tstd::cin >> N >> M;\r\n\t\r\n\tTwoSat sat(N);\r\n\t\r\
    \n\twhile (M--) {\r\n\t\tint a, b, t;\r\n\t\tstd::cin >> a >> b >> t;\r\n\t\t\
    sat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);\r\n\t}\r\n\t\r\
    \n\tif (!sat.build()) std::cout << \"s UNSATISFIABLE\" << std::endl;\r\n\telse\
    \ {\r\n\t\tstd::cout << \"s SATISFIABLE\" << std::endl;\r\n\t\tstd::cout << \"\
    v\";\r\n\t\tfor (int i = 0; i < N; ++i) std::cout << \" \" << (sat.get(i) ? i\
    \ + 1 : -(i + 1));\r\n\t\tstd::cout << \" 0\" << std::endl;\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n\r\n#include\
    \ \"Mathematics/TwoSat.hpp\"\r\n\r\n#include <iostream>\r\n#include <string>\r\
    \n#include <cmath>\r\n\r\nint main() {\r\n\tstd::ios::sync_with_stdio(false);\r\
    \n\tstd::cin.tie(0);\r\n\t\r\n\tstd::string dummy; std::cin >> dummy >> dummy;\r\
    \n\t\r\n\tint N, M;\r\n\tstd::cin >> N >> M;\r\n\t\r\n\tTwoSat sat(N);\r\n\t\r\
    \n\twhile (M--) {\r\n\t\tint a, b, t;\r\n\t\tstd::cin >> a >> b >> t;\r\n\t\t\
    sat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);\r\n\t}\r\n\t\r\
    \n\tif (!sat.build()) std::cout << \"s UNSATISFIABLE\" << std::endl;\r\n\telse\
    \ {\r\n\t\tstd::cout << \"s SATISFIABLE\" << std::endl;\r\n\t\tstd::cout << \"\
    v\";\r\n\t\tfor (int i = 0; i < N; ++i) std::cout << \" \" << (sat.get(i) ? i\
    \ + 1 : -(i + 1));\r\n\t\tstd::cout << \" 0\" << std::endl;\r\n\t}\r\n}"
  dependsOn:
  - Mathematics/TwoSat.hpp
  - GraphTheory/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: Test/TwoSat.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/TwoSat.test.cpp
layout: document
redirect_from:
- /verify/Test/TwoSat.test.cpp
- /verify/Test/TwoSat.test.cpp.html
title: Test/TwoSat.test.cpp
---
