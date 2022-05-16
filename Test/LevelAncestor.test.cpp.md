---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/LevelAncestor.hpp
    title: Level Ancestor Problem
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/LevelAncestor.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \r\n\r\n#line 1 \"GraphTheory/LevelAncestor.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n#include <stack>\r\n#include <utility>\r\n#include <map>\r\
    \n\r\n#line 1 \"Mathematics/bit_operation.hpp\"\n\n\n\r\n#include <cstdint>\r\n\
    \r\n/**\r\n * @brief https://tkmst201.github.io/Library/Mathematics/bit_operation.hpp\r\
    \n */\r\nnamespace tk {\r\nconstexpr int pop_count(std::uint32_t x) noexcept {\r\
    \n\tx = (x & 0x55555555) + ((x >> 1) & 0x55555555);\r\n\tx = (x & 0x33333333)\
    \ + ((x >> 2) & 0x33333333);\r\n\tx = (x + (x >> 4)) & 0x0f0f0f0f;\r\n\tx += x\
    \ >> 8;\r\n\tx += x >> 16;\r\n\treturn x & 0xff;\r\n}\r\n\r\nconstexpr int pop_countll(std::uint64_t\
    \ x) noexcept {\r\n\tx = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);\r\
    \n\tx = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\r\n\tx = (x\
    \ + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;\r\n\tx += x >> 8;\r\n\tx += x >> 16;\r\n\t\
    x += x >> 32;\r\n\treturn x & 0xff;\r\n}\r\n\r\nconstexpr int count_trailing_zeros(std::uint32_t\
    \ x) noexcept {\r\n\treturn pop_count(~x & (x - 1));\r\n}\r\n\r\nconstexpr int\
    \ count_trailing_zerosll(std::uint64_t x) noexcept {\r\n\treturn pop_countll(~x\
    \ & (x - 1));\r\n}\r\n\r\nconstexpr int count_leading_zeros(std::uint32_t x) noexcept\
    \ {\r\n\tx |= x >> 1;\r\n\tx |= x >> 2;\r\n\tx |= x >> 4;\r\n\tx |= x >> 8;\r\n\
    \tx |= x >> 16;\r\n\treturn pop_count(~x);\r\n}\r\n\r\nconstexpr int count_leading_zerosll(std::uint64_t\
    \ x) noexcept {\r\n\tx |= x >> 1;\r\n\tx |= x >> 2;\r\n\tx |= x >> 4;\r\n\tx |=\
    \ x >> 8;\r\n\tx |= x >> 16;\r\n\tx |= x >> 32;\r\n\treturn pop_countll(~x);\r\
    \n}\r\n} // namespace tk\r\n\r\n\n#line 11 \"GraphTheory/LevelAncestor.hpp\"\n\
    \r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LevelAncestor.hpp\r\
    \n */\r\ntemplate<int S, int B>\r\nstruct LevelAncestor {\r\n\tstatic_assert(1\
    \ <= B && B <= 3);\r\n\tstatic_assert(2 <= S && S <= (1ull << B));\r\n\tusing\
    \ Graph = std::vector<std::vector<int>>;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tint n, logn;\r\n\tstd::vector<int> depth_, jump, data, ladnum,\
    \ utreeid, rdict, rdst;\r\n\tstd::vector<std::vector<int>> ladder, jumpp;\r\n\t\
    std::vector<std::vector<int>> microdb;\r\n\t\r\npublic:\r\n\tLevelAncestor(const\
    \ Graph & g, int root = 0) : n(g.size()) {\r\n\t\tassert(0 <= root && root < n);\r\
    \n\t\tstd::vector<int> par(n, -1), jumps;\r\n\t\tdepth_.assign(n, 0);\r\n\t\t\
    jump.assign(n, n);\r\n\t\tdata.assign(n, 1);\r\n\t\t\r\n\t\t// calculate Micro-Tree\
    \ shape/query, |Micro-Tree| < S\r\n\t\tint stk1[2 * S], stk2[S], stkp1 = 0;\r\n\
    \t\tstd::map<int, int> micromap;\r\n\t\tutreeid.assign(n, -1);\r\n\t\trdict.reserve(n);\r\
    \n\t\trdst.reserve(n);\r\n\t\tauto build_micro = [&](int r) {\r\n\t\t\tconst int\
    \ jp = jump[par[r]], utid = rdst.size();\r\n\t\t\trdst.emplace_back(rdict.size());\r\
    \n\t\t\tint tnum = 0, vcnt = 0;\r\n\t\t\tstk1[stkp1++] = r;\r\n\t\t\twhile (stkp1)\
    \ {\r\n\t\t\t\tint u = stk1[--stkp1];\r\n\t\t\t\tif (u == -1) { tnum <<= 1; continue;\
    \ }\r\n\t\t\t\ttnum = tnum << 1 | 1;\r\n\t\t\t\tstk1[stkp1++] = -1;\r\n\t\t\t\t\
    ++vcnt;\r\n\t\t\t\tfor (int v : g[u]) if (v != par[u]) {\r\n\t\t\t\t\tstk1[stkp1++]\
    \ = v;\r\n\t\t\t\t\tassert(stkp1 < 2 * S);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tauto\
    \ [it, done] = micromap.try_emplace(tnum, microdb.size());\r\n\t\t\ttnum = it->second;\r\
    \n\t\t\tif (done) microdb.emplace_back(vcnt << B, -1);\r\n\t\t\tint dep = -1,\
    \ num = 0;\r\n\t\t\tstk1[stkp1++] = r;\r\n\t\t\twhile (stkp1) {\r\n\t\t\t\tint\
    \ u = stk1[--stkp1];\r\n\t\t\t\tif (u < 0) {\r\n\t\t\t\t\tu = -u - 1;\r\n\t\t\t\
    \t\tif (done) {\r\n\t\t\t\t\t\tconst int bidx = data[u] & (((1 << B) - 1) << B);\r\
    \n\t\t\t\t\t\tfor (int i = 0; i <= dep; ++i) {\r\n\t\t\t\t\t\t\tassert(bidx +\
    \ i < (vcnt << B));\r\n\t\t\t\t\t\t\tmicrodb[tnum][bidx + i] = stk2[dep - i];\r\
    \n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\t--dep;\r\n\t\t\t\t\tcontinue;\r\n\t\
    \t\t\t}\r\n\t\t\t\tdata[u] = (tnum << 2 * B) | (num << B) | ++dep;\r\n\t\t\t\t\
    jump[u] = jp;\r\n\t\t\t\tutreeid[u] = utid;\r\n\t\t\t\trdict.emplace_back(u);\r\
    \n\t\t\t\tstk2[dep] = num++;\r\n\t\t\t\tstk1[stkp1++] = -u - 1;\r\n\t\t\t\tfor\
    \ (int v : g[u]) if (v != par[u]) stk1[stkp1++] = v;\r\n\t\t\t}\r\n\t\t}; \r\n\
    \t\t\r\n\t\t// build Macro-Micro-Tree\r\n\t\tint mxdep = 0;\r\n\t\tstd::stack<std::pair<int,\
    \ int>> stk;\r\n\t\tstk.emplace(root, 0);\r\n\t\twhile (stk.size()) {\r\n\t\t\t\
    const auto [u, i] = stk.top(); stk.pop();\r\n\t\t\tassert(0 <= u && u < n);\r\n\
    \t\t\tif (g[u].size() == i) {\r\n\t\t\t\tif (par[u] != -1) data[par[u]] += data[u];\r\
    \n\t\t\t\tbool f = false;\r\n\t\t\t\tif (jump[u] == n) {\r\n\t\t\t\t\tif (par[u]\
    \ != -1 && data[u] < S) continue;\r\n\t\t\t\t\tjump[u] = u;\r\n\t\t\t\t\tjumps.emplace_back(u);\r\
    \n\t\t\t\t\tf = true;\r\n\t\t\t\t}\r\n\t\t\t\tdata[u] = -1;\r\n\t\t\t\tif (par[u]\
    \ != -1 && jump[par[u]] == n) jump[par[u]] = jump[u];\r\n\t\t\t\tfor (int v :\
    \ g[u]) if (jump[v] == n) build_micro(v);\r\n\t\t\t\tif (f) jump[u] = -static_cast<int>(jumps.size());\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (g[u][i]\
    \ == par[u]) continue;\r\n\t\t\t\tstk.emplace(g[u][i], 0);\r\n\t\t\t\tpar[g[u][i]]\
    \ = u;\r\n\t\t\t\tdepth_[g[u][i]] = depth_[u] + 1;\r\n\t\t\t\tif (mxdep < depth_[g[u][i]])\
    \ mxdep = depth_[g[u][i]];\r\n\t\t\t}\r\n\t\t}\r\n\t\trdict.shrink_to_fit();\r\
    \n\t\trdst.shrink_to_fit(); \r\n\t\t\r\n\t\t// counting_sort(ord[i]) by depth_[i]\r\
    \n\t\tstd::vector<int> cnt(mxdep + 2);\r\n\t\tfor (int i = 0; i < n; ++i) ++cnt[depth_[i]\
    \ + 1];\r\n\t\tfor (int i = 1; i < mxdep; ++i) cnt[i + 1] += cnt[i];\r\n\t\tstd::vector<int>\
    \ ord(n);\r\n\t\tfor (int i = 0; i < n; ++i) ord[cnt[depth_[i]]++] = i;\r\n\t\t\
    \r\n\t\t// build ladder\r\n\t\tladnum.assign(n, -1);\r\n\t\tladder.reserve(jumps.size());\r\
    \n\t\tfor (int t = n - 1; t >= 0; --t) {\r\n\t\t\tconst int i = ord[t];\r\n\t\t\
    \tif (ladnum[i] != -1) continue;\r\n\t\t\tint u = i, lpathc = 0;\r\n\t\t\twhile\
    \ (u != -1 && ladnum[u] == -1) ladnum[u] = ladder.size(), u = par[u], ++lpathc;\r\
    \n\t\t\tint lsize = 0;\r\n\t\t\twhile (u != -1 && lsize < lpathc) u = par[u],\
    \ ++lsize;\r\n\t\t\tlsize += lpathc;\r\n\t\t\tladder.emplace_back(lsize);\r\n\t\
    \t\tu = i;\r\n\t\t\tfor (int c = 0; c < lsize; ++c, u = par[u]) ladder.back()[c]\
    \ = u;\r\n\t\t}\r\n\t\t\r\n\t\t// build jumpp\r\n\t\tif (n == 1) return;\r\n\t\
    \tlogn = 0;\r\n\t\twhile ((1 << logn) < n) ++logn;\r\n\t\tjumpp.assign(logn, std::vector<int>(jumps.size(),\
    \ -1));\r\n\t\tfor (int i = 0; i < static_cast<int>(jumps.size()); ++i) jumpp[0][i]\
    \ = par[jumps[i]];\r\n\t\tfor (int i = 0; i + 1 < logn; ++i) {\r\n\t\t\tfor (int\
    \ j = 0; j < static_cast<int>(jumps.size()); ++j) {\r\n\t\t\t\tconst int v = jumpp[i][j];\r\
    \n\t\t\t\tif (v == -1) continue;\r\n\t\t\t\tconst int ln = ladnum[v];\r\n\t\t\t\
    \tconst int ridx = depth_[v] - (1 << i) - depth_[ladder[ln].back()];\r\n\t\t\t\
    \tif (ridx >= 0) {\r\n\t\t\t\t\tassert(ridx < static_cast<int>(ladder[ln].size()));\r\
    \n\t\t\t\t\tjumpp[i + 1][j] = ladder[ln][ladder[ln].size() - 1 - ridx];\r\n\t\t\
    \t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tint size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tint depth(int v) const noexcept {\r\n\t\tassert(0\
    \ <= v && v < n);\r\n\t\treturn depth_[v];\r\n\t}\r\n\t\r\n\tint operator ()(int\
    \ v, int k) const noexcept {\r\n\t\tassert(0 <= v && v < n);\r\n\t\tassert(depth_[v]\
    \ >= k);\r\n\t\treturn find(v, k);\r\n\t}\r\n\t\r\n\tint find(int v, int k) const\
    \ noexcept {\r\n\t\tassert(0 <= v && v < n);\r\n\t\tassert(0 <= k && k <= depth_[v]);\r\
    \n\t\tif (data[v] != -1) {\r\n\t\t\tconst int tnum = data[v] >> 2 * B;\r\n\t\t\
    \tconst int vnum = data[v] >> B & ((1 << B) - 1);\r\n\t\t\tconst int mdep = data[v]\
    \ & ((1 << B) - 1);\r\n\t\t\tif (depth_[v] - k <= mdep) {\r\n\t\t\t\tconst int\
    \ avnum = microdb[tnum][vnum << B | (depth_[v] - k)];\r\n\t\t\t\treturn rdict[rdst[utreeid[v]]\
    \ + avnum];\r\n\t\t\t}\r\n\t\t\tv = jump[v];\r\n\t\t}\r\n\t\telse if (jump[v]\
    \ >= 0) v = jump[v];\r\n\t\tif (depth_[v] == k) return v;\r\n\t\tconst int jpi\
    \ = 31 - tk::count_leading_zeros(depth_[v] - k);\r\n\t\tv = jumpp[jpi][-jump[v]\
    \ - 1];\r\n\t\tconst int ln = ladnum[v];\r\n\t\tconst int ridx = k - depth_[ladder[ln].back()];\r\
    \n\t\tassert(0 <= ridx && ridx < ladder[ln].size());\r\n\t\treturn ladder[ln][ladder[ln].size()\
    \ - 1 - ridx];\r\n\t}\r\n\t\r\n\tint up(int v, int k) const noexcept {\r\n\t\t\
    assert(0 <= v && v < n);\r\n\t\tassert(0 <= k && k <= depth_[v]);\r\n\t\treturn\
    \ find(v, depth_[v] - k);\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/LevelAncestor.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 7 \"Test/LevelAncestor.test.cpp\"\n\r\nint main()\
    \ {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing LA = LevelAncestor<5,\
    \ 3>;\r\n\tLA::Graph g(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\
    \t\tscanf(\"%d\", &p);\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\t\r\n\tLevelAncestor<5,\
    \ 3> la(g);\r\n\t\r\n\t/* verify */\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\t\
    assert(la.up(i, 0) == i);\r\n\t\tassert(la.up(i, la.depth(i)) == 0);\r\n\t}\r\n\
    \t//\r\n\t\r\n\tint logn = 1;\r\n\twhile ((1 << logn) < N) ++logn;\r\n\twhile\
    \ (Q--) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\", &u, &v);\r\n\t\tif (la.depth(u)\
    \ < la.depth(v)) std::swap(u, v);\r\n\t\t// depth(u) >= depth(v)\r\n\t\tu = la.up(u,\
    \ la.depth(u) - la.depth(v));\r\n\t\tif (u == v) { printf(\"%d\\n\", u); continue;\
    \ }\r\n\t\tint up = 0;\r\n\t\tfor (int i = logn - 1; i >= 0; --i) {\r\n\t\t\t\
    const int cur = up + (1 << i);\r\n\t\t\tif (cur > la.depth(u)) continue;\r\n\t\
    \t\tif (la.up(u, cur) != la.up(v, cur)) up += 1 << i;\r\n\t\t}\r\n\t\tint ans\
    \ = la.up(u, up);\r\n\t\tif (la.depth(ans)) ans = la.up(ans, 1);\r\n\t\tprintf(\"\
    %d\\n\", ans);\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    GraphTheory/LevelAncestor.hpp\"\r\n\r\n#include <cstdio>\r\n#include <utility>\r\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing\
    \ LA = LevelAncestor<5, 3>;\r\n\tLA::Graph g(N);\r\n\tfor (int i = 1; i < N; ++i)\
    \ {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\tg[p].emplace_back(i);\r\n\t\
    }\r\n\t\r\n\tLevelAncestor<5, 3> la(g);\r\n\t\r\n\t/* verify */\r\n\tfor (int\
    \ i = 0; i < N; ++i) {\r\n\t\tassert(la.up(i, 0) == i);\r\n\t\tassert(la.up(i,\
    \ la.depth(i)) == 0);\r\n\t}\r\n\t//\r\n\t\r\n\tint logn = 1;\r\n\twhile ((1 <<\
    \ logn) < N) ++logn;\r\n\twhile (Q--) {\r\n\t\tint u, v;\r\n\t\tscanf(\"%d %d\"\
    , &u, &v);\r\n\t\tif (la.depth(u) < la.depth(v)) std::swap(u, v);\r\n\t\t// depth(u)\
    \ >= depth(v)\r\n\t\tu = la.up(u, la.depth(u) - la.depth(v));\r\n\t\tif (u ==\
    \ v) { printf(\"%d\\n\", u); continue; }\r\n\t\tint up = 0;\r\n\t\tfor (int i\
    \ = logn - 1; i >= 0; --i) {\r\n\t\t\tconst int cur = up + (1 << i);\r\n\t\t\t\
    if (cur > la.depth(u)) continue;\r\n\t\t\tif (la.up(u, cur) != la.up(v, cur))\
    \ up += 1 << i;\r\n\t\t}\r\n\t\tint ans = la.up(u, up);\r\n\t\tif (la.depth(ans))\
    \ ans = la.up(ans, 1);\r\n\t\tprintf(\"%d\\n\", ans);\r\n\t}\r\n}"
  dependsOn:
  - GraphTheory/LevelAncestor.hpp
  - Mathematics/bit_operation.hpp
  isVerificationFile: true
  path: Test/LevelAncestor.test.cpp
  requiredBy: []
  timestamp: '2022-05-16 13:51:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LevelAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/LevelAncestor.test.cpp
- /verify/Test/LevelAncestor.test.cpp.html
title: Test/LevelAncestor.test.cpp
---
