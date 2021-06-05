---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/FastFourierTransform.test.cpp
    title: Test/FastFourierTransform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp
    links:
    - https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp
  bundledCode: "#line 1 \"Algorithm/frequency_table_of_tree_distance.hpp\"\n\n\n\r\
    \n#include <algorithm>\r\n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<class CD, class FFT>\r\nstd::vector<long long>\
    \ frequency_table_of_tree_distance(const typename CD::Graph & g) {\r\n\tassert(!g.empty());\r\
    \n\tusing value_type = long long;\r\n\tCD cd(g);\r\n\tconst int n = g.size();\r\
    \n\tFFT fft(n);\r\n\tauto dfs = [&](auto self, int centroid) -> std::vector<value_type>\
    \ {\r\n\t\tcd.done(centroid);\r\n\t\tbool iso = true;\r\n\t\tstd::vector<value_type>\
    \ res(1, 0), sum_table(1, 1);\r\n\t\tfor (auto r : g[centroid]) {\r\n\t\t\tif\
    \ (!cd.exist(r)) continue;\r\n\t\t\tiso = false;\r\n\t\t\tstd::vector<value_type>\
    \ table(1, 0);\r\n\t\t\tauto dfs2 = [&](auto self, int u, int p, int d) -> void\
    \ {\r\n\t\t\t\tif (static_cast<int>(table.size()) == d) table.emplace_back(1);\r\
    \n\t\t\t\telse ++table[d];\r\n\t\t\t\tfor (auto v : g[u]) if (v != p && cd.exist(v))\
    \ self(self, v, u, d + 1);\r\n\t\t\t};\r\n\t\t\tdfs2(dfs2, r, -1, 1);\r\n\t\t\t\
    for (int i = 1; i < std::min<int>(sum_table.size(), table.size()); ++i) sum_table[i]\
    \ += table[i];\r\n\t\t\tfor (int i = sum_table.size(); i < static_cast<int>(table.size());\
    \ ++i) sum_table.emplace_back(table[i]);\r\n\t\t\tconst auto mul = fft(table,\
    \ table);\r\n\t\t\tfor (int i = 1; i < std::min<int>(res.size(), mul.size());\
    \ ++i) res[i] -= static_cast<value_type>(std::round(mul[i]));\r\n\t\t\tfor (int\
    \ i = res.size(); i < static_cast<int>(mul.size()); ++i) res.emplace_back(-static_cast<value_type>(std::round(mul[i])));\r\
    \n\t\t\ttable = self(self, cd.centroids(g, r)[0]);\r\n\t\t\tfor (int i = 1; i\
    \ < std::min<int>(res.size(), table.size()); ++i) res[i] += table[i];\r\n\t\t\t\
    for (int i = res.size(); i < static_cast<int>(table.size()); ++i) res.emplace_back(table[i]);\r\
    \n\t\t}\r\n\t\tif (iso) return res;\r\n\t\tconst auto mul = fft(sum_table, sum_table);\r\
    \n\t\tfor (int i = 1; i < std::min<int>(res.size(), mul.size()); ++i) res[i] +=\
    \ static_cast<value_type>(std::round(mul[i]));\r\n\t\tfor (int i = res.size();\
    \ i < static_cast<int>(mul.size()); ++i) res.emplace_back(static_cast<value_type>(std::round(mul[i])));\r\
    \n\t\treturn res;\r\n\t};\r\n\tauto res = dfs(dfs, cd.centroids(g, 0)[0]);\r\n\
    \tfor (int i = 1; i < static_cast<int>(res.size()); ++i) res[i] /= 2;\r\n\tres[0]\
    \ = n;\r\n\treturn res;\r\n}\r\n} // namespace tk\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP\r\n#define INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP\r\
    \n\r\n#include <algorithm>\r\n#include <cmath>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp\r\
    \n */\r\nnamespace tk {\r\ntemplate<class CD, class FFT>\r\nstd::vector<long long>\
    \ frequency_table_of_tree_distance(const typename CD::Graph & g) {\r\n\tassert(!g.empty());\r\
    \n\tusing value_type = long long;\r\n\tCD cd(g);\r\n\tconst int n = g.size();\r\
    \n\tFFT fft(n);\r\n\tauto dfs = [&](auto self, int centroid) -> std::vector<value_type>\
    \ {\r\n\t\tcd.done(centroid);\r\n\t\tbool iso = true;\r\n\t\tstd::vector<value_type>\
    \ res(1, 0), sum_table(1, 1);\r\n\t\tfor (auto r : g[centroid]) {\r\n\t\t\tif\
    \ (!cd.exist(r)) continue;\r\n\t\t\tiso = false;\r\n\t\t\tstd::vector<value_type>\
    \ table(1, 0);\r\n\t\t\tauto dfs2 = [&](auto self, int u, int p, int d) -> void\
    \ {\r\n\t\t\t\tif (static_cast<int>(table.size()) == d) table.emplace_back(1);\r\
    \n\t\t\t\telse ++table[d];\r\n\t\t\t\tfor (auto v : g[u]) if (v != p && cd.exist(v))\
    \ self(self, v, u, d + 1);\r\n\t\t\t};\r\n\t\t\tdfs2(dfs2, r, -1, 1);\r\n\t\t\t\
    for (int i = 1; i < std::min<int>(sum_table.size(), table.size()); ++i) sum_table[i]\
    \ += table[i];\r\n\t\t\tfor (int i = sum_table.size(); i < static_cast<int>(table.size());\
    \ ++i) sum_table.emplace_back(table[i]);\r\n\t\t\tconst auto mul = fft(table,\
    \ table);\r\n\t\t\tfor (int i = 1; i < std::min<int>(res.size(), mul.size());\
    \ ++i) res[i] -= static_cast<value_type>(std::round(mul[i]));\r\n\t\t\tfor (int\
    \ i = res.size(); i < static_cast<int>(mul.size()); ++i) res.emplace_back(-static_cast<value_type>(std::round(mul[i])));\r\
    \n\t\t\ttable = self(self, cd.centroids(g, r)[0]);\r\n\t\t\tfor (int i = 1; i\
    \ < std::min<int>(res.size(), table.size()); ++i) res[i] += table[i];\r\n\t\t\t\
    for (int i = res.size(); i < static_cast<int>(table.size()); ++i) res.emplace_back(table[i]);\r\
    \n\t\t}\r\n\t\tif (iso) return res;\r\n\t\tconst auto mul = fft(sum_table, sum_table);\r\
    \n\t\tfor (int i = 1; i < std::min<int>(res.size(), mul.size()); ++i) res[i] +=\
    \ static_cast<value_type>(std::round(mul[i]));\r\n\t\tfor (int i = res.size();\
    \ i < static_cast<int>(mul.size()); ++i) res.emplace_back(static_cast<value_type>(std::round(mul[i])));\r\
    \n\t\treturn res;\r\n\t};\r\n\tauto res = dfs(dfs, cd.centroids(g, 0)[0]);\r\n\
    \tfor (int i = 1; i < static_cast<int>(res.size()); ++i) res[i] /= 2;\r\n\tres[0]\
    \ = n;\r\n\treturn res;\r\n}\r\n} // namespace tk\r\n\r\n#endif // INCLUDE_GUARD_FREQUENCY_TABLE_OF_TREE_DISTANCE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/frequency_table_of_tree_distance.hpp
  requiredBy: []
  timestamp: '2021-05-02 14:06:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/FastFourierTransform.test.cpp
documentation_of: Algorithm/frequency_table_of_tree_distance.hpp
layout: document
redirect_from:
- /library/Algorithm/frequency_table_of_tree_distance.hpp
- /library/Algorithm/frequency_table_of_tree_distance.hpp.html
title: https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp
---
