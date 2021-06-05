---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/frequency_table_of_tree_distance.hpp
    title: https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/FastFourierTransform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (FFT)"
  - icon: ':heavy_check_mark:'
    path: GraphTheory/CentroidDecomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"Test/FastFourierTransform.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\r\n\r\n#line\
    \ 1 \"GraphTheory/CentroidDecomposition.hpp\"\n\n\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n#include <algorithm>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/CentroidDecomposition.hpp\r\
    \n */\r\nstruct CentroidDecomposition {\r\n\tusing Graph = std::vector<std::vector<int>>;\r\
    \n\t\r\nprivate:\r\n\tint n;\r\n\tstd::vector<bool> done_;\r\n\tstd::vector<int>\
    \ sz;\r\n\t\r\npublic:\r\n\texplicit CentroidDecomposition(const Graph & g) :\
    \ n(g.size()), done_(size(), false), sz(size(), 0) {\r\n\t\tfor (int i = 0; i\
    \ < size(); ++i) for (int j : g[i]) assert(0 <= j && j < size());\r\n\t}\r\n\t\
    \r\n\tint size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool exist(int\
    \ u) const noexcept {\r\n\t\tassert(0 <= u && u < size());\r\n\t\treturn !done_[u];\r\
    \n\t}\r\n\t\r\n\tstd::vector<int> centroids(const Graph & g, int root) {\r\n\t\
    \tassert(0 <= root && root < size());\r\n\t\tassert(exist(root));\r\n\t\tauto\
    \ dfs = [&](auto self, int u, int p) -> void {\r\n\t\t\tsz[u] = 1;\r\n\t\t\tfor\
    \ (auto v : g[u]) if (v != p && exist(v)) self(self, v, u), sz[u] += sz[v];\r\n\
    \t\t};\r\n\t\tdfs(dfs, root, -1);\r\n\t\tint u = root, p = -1;\r\n\t\tstd::vector<int>\
    \ res;\r\n\t\twhile (true) {\r\n\t\t\tbool update = false;\r\n\t\t\tfor (auto\
    \ v : g[u]) {\r\n\t\t\t\tif (v == p || !exist(v)) continue;\r\n\t\t\t\tif (sz[v]\
    \ * 2 > sz[root]) { p = u; u = v; update = true; break; }\r\n\t\t\t\tif (sz[v]\
    \ * 2 == sz[root]) res.emplace_back(v);\r\n\t\t\t}\r\n\t\t\tif (update) continue;\r\
    \n\t\t\tres.emplace_back(u);\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tvoid done(int v) noexcept {\r\n\t\tassert(0 <= v && v < size());\r\
    \n\t\tdone_[v] = true;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tstd::fill(begin(done_),\
    \ end(done_), false);\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Convolution/FastFourierTransform.hpp\"\
    \n\n\n\r\n#line 5 \"Convolution/FastFourierTransform.hpp\"\n#include <complex>\r\
    \n#line 7 \"Convolution/FastFourierTransform.hpp\"\n#include <cstdint>\r\n\r\n\
    /**\r\n * @brief https://tkmst201.github.io/Library/Convolution/FastFourierTransform.hpp\r\
    \n */\r\nstruct FastFourierTransform {\r\n\tusing value_type = double;\r\n\tusing\
    \ complex_type = std::complex<value_type>;\r\n\t\r\nprivate:\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\tconstexpr static value_type pi = 3.1415926535897932384626433832795028841972;\r\
    \n\tconstexpr static complex_type ie{0, 1};\r\n\t\r\n\tuint32 mlog_n;\r\n\tstd::vector<complex_type>\
    \ zeta;\r\n\t\r\npublic:\r\n\texplicit FastFourierTransform(uint32 max_n) : mlog_n(calc_l2(max_n)),\
    \ zeta(zeta_(mlog_n)) {}\r\n\t\r\n\ttemplate<typename T>\r\n\tstd::vector<value_type>\
    \ operator ()(const std::vector<T> & a, const std::vector<T> & b) const {\r\n\t\
    \tif (a.empty() || b.empty()) return {};\r\n\t\tif (a.size() == 1 && b.size()\
    \ == 1) return {static_cast<value_type>(a.front()) * b.front()};\r\n\t\tassert((a.size()\
    \ + b.size() - 1) <= (1u << mlog_n));\r\n\t\treturn multiply_sub(a, b, zeta, mlog_n);\r\
    \n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic std::vector<value_type> multiply(const\
    \ std::vector<T> & a, const std::vector<T> & b) {\r\n\t\tif (a.empty() || b.empty())\
    \ return {};\r\n\t\tif (a.size() == 1 && b.size() == 1) return {static_cast<value_type>(a.front())\
    \ * b.front()};\r\n\t\tconst uint32 log_n = calc_l2(a.size() + b.size() - 1);\r\
    \n\t\tconst std::vector<complex_type> zeta = zeta_(log_n);\r\n\t\treturn multiply_sub(a,\
    \ b, zeta, log_n);\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename T>\r\n\tstatic\
    \ std::vector<value_type> multiply_sub(const std::vector<T> & a, const std::vector<T>\
    \ & b, const std::vector<complex_type> & zeta, uint32 log_z) {\r\n\t\tconst uint32\
    \ n_ = a.size() + b.size() - 1;\r\n\t\tconst uint32 log_n = calc_l2(n_), n = 1u\
    \ << log_n, m = n >> 1;\r\n\t\tstd::vector<complex_type> h(n);\r\n\t\tfor (uint32\
    \ i = 0; i < a.size(); ++i) h[i].real(a[i]);\r\n\t\tfor (uint32 i = 0; i < b.size();\
    \ ++i) h[i].imag(b[i]);\r\n\t\tfft(h, log_n, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<complex_type>\
    \ p(m);\r\n\t\t{\r\n\t\t\tconst value_type cf = h[0].real() * h[0].imag();\r\n\
    \t\t\tconst value_type cb = h[m].real() * h[m].imag();\r\n\t\t\tp[0] = complex_type(cf\
    \ + cb, -(cf - cb)) / 2.0;\r\n\t\t}\r\n\t\tfor (uint32 i = 1; i <= (m >> 1); ++i)\
    \ {\r\n\t\t\tconst complex_type cf = -(h[i] + std::conj(h[n - i])) * (h[i] - std::conj(h[n\
    \ - i])) * ie;\r\n\t\t\tconst complex_type cb = -(h[m - i] + std::conj(h[m + i]))\
    \ * (h[m - i] - std::conj(h[m + i])) * ie;\r\n\t\t\tp[i] = std::conj((cf + std::conj(cb)\
    \ + (cf - std::conj(cb)) * std::conj(zeta_f(log_n, i, zeta, log_z)) * ie)) / 8.0;\r\
    \n\t\t\tif (i != m / 2) p[m - i] = std::conj((cb + std::conj(cf)) + (cb - std::conj(cf))\
    \ * std::conj(zeta_f(log_n, m - i, zeta, log_z)) * ie) / 8.0;\r\n\t\t}\r\n\t\t\
    fft(p, log_n - 1, zeta, log_z);\r\n\t\t\r\n\t\tstd::vector<value_type> res;\r\n\
    \t\tres.reserve(n_);\r\n\t\tfor (uint32 i = 0; i < m; ++i) {\r\n\t\t\tif ((i <<\
    \ 1) < n_) res.emplace_back(p[i].real() / static_cast<value_type>(m));\r\n\t\t\
    \tif ((i << 1 | 1) < n_) res.emplace_back(-p[i].imag() / static_cast<value_type>(m));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic void fft(std::vector<complex_type>\
    \ & a, uint32 log_n, const std::vector<complex_type> & zeta, uint32 log_z) {\r\
    \n\t\tconst uint32 n = a.size(), m = n >> 1;\r\n\t\tbit_reverse(a);\r\n\t\tfor\
    \ (uint32 w = 4, c = 2; w <= n; w <<= 2, c += 2) {\r\n\t\t\tconst uint32 s = w\
    \ >> 2;\r\n\t\t\tfor (uint32 p = 0; p < n; p += w) {\r\n\t\t\t\tfor (uint32 i\
    \ = 0; i < s; ++i) {\r\n\t\t\t\t\tconst uint32 pos = p + i;\r\n\t\t\t\t\tconst\
    \ complex_type a0 = a[pos], a2 = a[pos + s] * zeta_f(c - 1, i, zeta, log_z);\r\
    \n\t\t\t\t\tconst complex_type a1 = a[pos + (s << 1)] * zeta_f(c, i, zeta, log_z),\
    \ a3 = a[pos + w - s] * zeta_f(c, 3 * i, zeta, log_z);\r\n\t\t\t\t\tconst complex_type\
    \ lp = a0 + a2, rp = a1 + a3, ln = a0 - a2, rn = a1 - a3;\r\n\t\t\t\t\ta[pos]\
    \ = lp + rp;\r\n\t\t\t\t\ta[pos + (s << 1)] = lp - rp;\r\n\t\t\t\t\ta[pos + s]\
    \ = ln + rn * ie;\r\n\t\t\t\t\ta[pos + w - s] = ln - rn * ie;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tif (~log_n & 1) return;\r\n\t\tfor (uint32 i = 0; i <\
    \ m; ++i) {\r\n\t\t\tconst complex_type x = a[i], y = a[i + m] * zeta_f(log_n,\
    \ i, zeta, log_z);\r\n\t\t\ta[i] = x + y;\r\n\t\t\ta[i + m] = x - y;\r\n\t\t}\r\
    \n\t}\r\n\t\r\n\tstatic uint32 calc_l2(uint32 n_) noexcept {\r\n\t\tuint32 log_n\
    \ = 0;\r\n\t\tfor (uint32 n = 1; n < n_; n <<= 1) ++log_n;\r\n\t\treturn log_n;\r\
    \n\t}\r\n\t\r\n\tstatic void bit_reverse(std::vector<complex_type> & a) noexcept\
    \ {\r\n\t\tconst uint32 N = a.size();\r\n\t\tfor (uint32 i = 1, j = 0; i < N -\
    \ 1; ++i) {\r\n\t\t\tfor (uint32 k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\t\
    if (i < j) std::swap(a[i], a[j]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tstatic std::vector<complex_type>\
    \ zeta_(uint32 log_n) {\r\n\t\tif (log_n == 0) return {};\r\n\t\tstd::vector<complex_type>\
    \ zeta;\r\n\t\tzeta.reserve(1 << (log_n - 1));\r\n\t\tzeta.emplace_back(1, 0);\r\
    \n\t\tfor (uint32 i = 0; i < (log_n - 1); ++i) {\r\n\t\t\tconst complex_type t\
    \ = std::polar<value_type>(1, 2.0 * pi / static_cast<value_type>(1 << (log_n -\
    \ i)));\r\n\t\t\tzeta.emplace_back(t);\r\n\t\t\tfor (uint32 j = 1; j < (1u <<\
    \ i); ++j) zeta.emplace_back(zeta[j] * t);\r\n\t\t}\r\n\t\treturn zeta;\r\n\t\
    }\r\n\t\r\n\tstatic complex_type zeta_f(uint32 d, uint32 p, const std::vector<complex_type>\
    \ & zeta, uint32 log_z) noexcept {\r\n\t\tconst uint32 idx = p << (log_z - d);\r\
    \n\t\treturn idx < zeta.size() ? zeta[idx] : -zeta[idx - zeta.size()];\r\n\t}\r\
    \n};\r\n\r\n\n#line 1 \"Algorithm/frequency_table_of_tree_distance.hpp\"\n\n\n\
    \r\n#line 5 \"Algorithm/frequency_table_of_tree_distance.hpp\"\n#include <cmath>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/Algorithm/frequency_table_of_tree_distance.hpp\r\
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
    \ = n;\r\n\treturn res;\r\n}\r\n} // namespace tk\r\n\r\n\n#line 6 \"Test/FastFourierTransform.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 9 \"Test/FastFourierTransform.test.cpp\"\n\r\n\
    int main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\tCentroidDecomposition::Graph\
    \ g(N);\r\n\tfor (int i = 0; i < N - 1; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\tg[a].emplace_back(b);\r\n\t\tg[b].emplace_back(a);\r\n\
    \t}\r\n\tauto table = tk::frequency_table_of_tree_distance<CentroidDecomposition,\
    \ FastFourierTransform>(g);\r\n\tfor (int i = 1; i < N; ++i) printf(\"%lld%c\"\
    , i < table.size() ? table[i] : 0, \" \\n\"[i + 1 == N]);\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include \"GraphTheory/CentroidDecomposition.hpp\"\r\n#include \"Convolution/FastFourierTransform.hpp\"\
    \r\n#include \"Algorithm/frequency_table_of_tree_distance.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"\
    %d\", &N);\r\n\tCentroidDecomposition::Graph g(N);\r\n\tfor (int i = 0; i < N\
    \ - 1; ++i) {\r\n\t\tint a, b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tg[a].emplace_back(b);\r\
    \n\t\tg[b].emplace_back(a);\r\n\t}\r\n\tauto table = tk::frequency_table_of_tree_distance<CentroidDecomposition,\
    \ FastFourierTransform>(g);\r\n\tfor (int i = 1; i < N; ++i) printf(\"%lld%c\"\
    , i < table.size() ? table[i] : 0, \" \\n\"[i + 1 == N]);\r\n\treturn 0;\r\n}"
  dependsOn:
  - GraphTheory/CentroidDecomposition.hpp
  - Convolution/FastFourierTransform.hpp
  - Algorithm/frequency_table_of_tree_distance.hpp
  isVerificationFile: true
  path: Test/FastFourierTransform.test.cpp
  requiredBy: []
  timestamp: '2021-06-05 13:56:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/FastFourierTransform.test.cpp
layout: document
redirect_from:
- /verify/Test/FastFourierTransform.test.cpp
- /verify/Test/FastFourierTransform.test.cpp.html
title: Test/FastFourierTransform.test.cpp
---
