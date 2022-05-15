---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/bit_operation.hpp
    title: "bit \u64CD\u4F5C"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LevelAncestor.test.cpp
    title: Test/LevelAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/GraphTheory/LevelAncestor.hpp
    links:
    - https://tkmst201.github.io/Library/GraphTheory/LevelAncestor.hpp
  bundledCode: "#line 1 \"GraphTheory/LevelAncestor.hpp\"\n\n\n\r\n#include <vector>\r\
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
    \t\trdict.shrink_to_fit();\r\n\t\trdst.shrink_to_fit();\r\n\t\t\r\n\t\t// build\
    \ Macro-Micro-Tree\r\n\t\tint mxdep = 0;\r\n\t\tstd::stack<std::pair<int, int>>\
    \ stk;\r\n\t\tstk.emplace(root, 0);\r\n\t\twhile (stk.size()) {\r\n\t\t\tconst\
    \ auto [u, i] = stk.top(); stk.pop();\r\n\t\t\tassert(0 <= u && u < n);\r\n\t\t\
    \tif (g[u].size() == i) {\r\n\t\t\t\tif (par[u] != -1) data[par[u]] += data[u];\r\
    \n\t\t\t\tbool f = false;\r\n\t\t\t\tif (jump[u] == n) {\r\n\t\t\t\t\tif (par[u]\
    \ != -1 && data[u] < S) continue;\r\n\t\t\t\t\tjump[u] = u;\r\n\t\t\t\t\tjumps.emplace_back(u);\r\
    \n\t\t\t\t\tf = true;\r\n\t\t\t\t}\r\n\t\t\t\tif (par[u] != -1 && jump[par[u]]\
    \ == n) jump[par[u]] = jump[u];\r\n\t\t\t\tdata[u] = -1;\r\n\t\t\t\tfor (int v\
    \ : g[u]) if (jump[v] == n) build_micro(v);\r\n\t\t\t\tif (f) jump[u] = -static_cast<int>(jumps.size());\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (g[u][i]\
    \ == par[u]) continue;\r\n\t\t\t\tstk.emplace(g[u][i], 0);\r\n\t\t\t\tpar[g[u][i]]\
    \ = u;\r\n\t\t\t\tdepth_[g[u][i]] = depth_[u] + 1;\r\n\t\t\t\tif (mxdep < depth_[g[u][i]])\
    \ mxdep = depth_[g[u][i]];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\t// counting_sort(ord[i])\
    \ by depth_[i]\r\n\t\tstd::vector<int> cnt(mxdep + 2);\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) ++cnt[depth_[i] + 1];\r\n\t\tfor (int i = 1; i < mxdep; ++i) cnt[i\
    \ + 1] += cnt[i];\r\n\t\tstd::vector<int> ord(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) ord[cnt[depth_[i]]++] = i;\r\n\t\t\r\n\t\t// build ladder\r\n\t\tladnum.assign(n,\
    \ -1);\r\n\t\tladder.reserve(jumps.size());\r\n\t\tfor (int t = n - 1; t >= 0;\
    \ --t) {\r\n\t\t\tconst int i = ord[t];\r\n\t\t\tif (ladnum[i] != -1) continue;\r\
    \n\t\t\tint u = i, lpathc = 0;\r\n\t\t\twhile (u != -1 && ladnum[u] == -1) ladnum[u]\
    \ = ladder.size(), u = par[u], ++lpathc;\r\n\t\t\tint lsize = 0;\r\n\t\t\twhile\
    \ (u != -1 && lsize < lpathc) u = par[u], ++lsize;\r\n\t\t\tlsize += lpathc;\r\
    \n\t\t\tladder.emplace_back(lsize);\r\n\t\t\tu = i;\r\n\t\t\tfor (int c = 0; c\
    \ < lsize; ++c, u = par[u]) ladder.back()[c] = u;\r\n\t\t}\r\n\t\t\r\n\t\t// build\
    \ jumpp\r\n\t\tlogn = 0;\r\n\t\twhile ((1 << logn) < n) ++logn;\r\n\t\tjumpp.assign(logn,\
    \ std::vector<int>(jumps.size(), -1));\r\n\t\tfor (int i = 0; i < static_cast<int>(jumps.size());\
    \ ++i) jumpp[0][i] = par[jumps[i]];\r\n\t\tfor (int i = 0; i + 1 < logn; ++i)\
    \ {\r\n\t\t\tfor (int j = 0; j < static_cast<int>(jumps.size()); ++j) {\r\n\t\t\
    \t\tconst int v = jumpp[i][j];\r\n\t\t\t\tif (v == -1) continue;\r\n\t\t\t\tconst\
    \ int ln = ladnum[v];\r\n\t\t\t\tconst int ridx = depth_[v] - (1 << i) - depth_[ladder[ln].back()];\r\
    \n\t\t\t\tif (ridx >= 0) {\r\n\t\t\t\t\tassert(ridx < static_cast<int>(ladder[ln].size()));\r\
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
    \ find(v, depth_[v] - k);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_LEVEL_ANCESTOR_HPP\r\n#define INCLUDE_GUARD_LEVEL_ANCESTOR_HPP\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n#include <map>\r\n\r\n#include \"Mathematics/bit_operation.hpp\"\
    \r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/GraphTheory/LevelAncestor.hpp\r\
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
    \t\trdict.shrink_to_fit();\r\n\t\trdst.shrink_to_fit();\r\n\t\t\r\n\t\t// build\
    \ Macro-Micro-Tree\r\n\t\tint mxdep = 0;\r\n\t\tstd::stack<std::pair<int, int>>\
    \ stk;\r\n\t\tstk.emplace(root, 0);\r\n\t\twhile (stk.size()) {\r\n\t\t\tconst\
    \ auto [u, i] = stk.top(); stk.pop();\r\n\t\t\tassert(0 <= u && u < n);\r\n\t\t\
    \tif (g[u].size() == i) {\r\n\t\t\t\tif (par[u] != -1) data[par[u]] += data[u];\r\
    \n\t\t\t\tbool f = false;\r\n\t\t\t\tif (jump[u] == n) {\r\n\t\t\t\t\tif (par[u]\
    \ != -1 && data[u] < S) continue;\r\n\t\t\t\t\tjump[u] = u;\r\n\t\t\t\t\tjumps.emplace_back(u);\r\
    \n\t\t\t\t\tf = true;\r\n\t\t\t\t}\r\n\t\t\t\tif (par[u] != -1 && jump[par[u]]\
    \ == n) jump[par[u]] = jump[u];\r\n\t\t\t\tdata[u] = -1;\r\n\t\t\t\tfor (int v\
    \ : g[u]) if (jump[v] == n) build_micro(v);\r\n\t\t\t\tif (f) jump[u] = -static_cast<int>(jumps.size());\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (g[u][i]\
    \ == par[u]) continue;\r\n\t\t\t\tstk.emplace(g[u][i], 0);\r\n\t\t\t\tpar[g[u][i]]\
    \ = u;\r\n\t\t\t\tdepth_[g[u][i]] = depth_[u] + 1;\r\n\t\t\t\tif (mxdep < depth_[g[u][i]])\
    \ mxdep = depth_[g[u][i]];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\t// counting_sort(ord[i])\
    \ by depth_[i]\r\n\t\tstd::vector<int> cnt(mxdep + 2);\r\n\t\tfor (int i = 0;\
    \ i < n; ++i) ++cnt[depth_[i] + 1];\r\n\t\tfor (int i = 1; i < mxdep; ++i) cnt[i\
    \ + 1] += cnt[i];\r\n\t\tstd::vector<int> ord(n);\r\n\t\tfor (int i = 0; i < n;\
    \ ++i) ord[cnt[depth_[i]]++] = i;\r\n\t\t\r\n\t\t// build ladder\r\n\t\tladnum.assign(n,\
    \ -1);\r\n\t\tladder.reserve(jumps.size());\r\n\t\tfor (int t = n - 1; t >= 0;\
    \ --t) {\r\n\t\t\tconst int i = ord[t];\r\n\t\t\tif (ladnum[i] != -1) continue;\r\
    \n\t\t\tint u = i, lpathc = 0;\r\n\t\t\twhile (u != -1 && ladnum[u] == -1) ladnum[u]\
    \ = ladder.size(), u = par[u], ++lpathc;\r\n\t\t\tint lsize = 0;\r\n\t\t\twhile\
    \ (u != -1 && lsize < lpathc) u = par[u], ++lsize;\r\n\t\t\tlsize += lpathc;\r\
    \n\t\t\tladder.emplace_back(lsize);\r\n\t\t\tu = i;\r\n\t\t\tfor (int c = 0; c\
    \ < lsize; ++c, u = par[u]) ladder.back()[c] = u;\r\n\t\t}\r\n\t\t\r\n\t\t// build\
    \ jumpp\r\n\t\tlogn = 0;\r\n\t\twhile ((1 << logn) < n) ++logn;\r\n\t\tjumpp.assign(logn,\
    \ std::vector<int>(jumps.size(), -1));\r\n\t\tfor (int i = 0; i < static_cast<int>(jumps.size());\
    \ ++i) jumpp[0][i] = par[jumps[i]];\r\n\t\tfor (int i = 0; i + 1 < logn; ++i)\
    \ {\r\n\t\t\tfor (int j = 0; j < static_cast<int>(jumps.size()); ++j) {\r\n\t\t\
    \t\tconst int v = jumpp[i][j];\r\n\t\t\t\tif (v == -1) continue;\r\n\t\t\t\tconst\
    \ int ln = ladnum[v];\r\n\t\t\t\tconst int ridx = depth_[v] - (1 << i) - depth_[ladder[ln].back()];\r\
    \n\t\t\t\tif (ridx >= 0) {\r\n\t\t\t\t\tassert(ridx < static_cast<int>(ladder[ln].size()));\r\
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
    \ find(v, depth_[v] - k);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_LEVEL_ANCESTOR_HPP"
  dependsOn:
  - Mathematics/bit_operation.hpp
  isVerificationFile: false
  path: GraphTheory/LevelAncestor.hpp
  requiredBy: []
  timestamp: '2022-05-15 20:57:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LevelAncestor.test.cpp
documentation_of: GraphTheory/LevelAncestor.hpp
layout: document
title: Level Ancestor Problem
---

# 概要

`Level Ancestor Problem` とは次のような問題のことです。  

> 根付き木 $T$ が与えられます。以下のクエリ `LA(v, k)` に答えてください。  
> - `LA(v, k)` : 頂点 $v$ の先祖( $v$ 自身も含む) であって、根からの深さが $k$ [0-index] であるような頂点

`UP(v, k)` を "頂点 $v$ から $k$ 回根方向に上ったところにある頂点" と定義すると、各頂点の深さが分かっている場合 `LA` と `UP` は互いに変形可能です。  

このライブラリは、頂点数が $N$ の木に対して $O(N)$ 時間/空間の事前計算により、オンラインでクエリ $\Theta(1)$ 時間を達成します。  
The Macro-Micro-Tree Algorithm を使用しています。  

- `LevelAncestor(const Graph & g, int root = 0)`
	- 時間/空間 $\mathcal{O}(N)$ 根 `root` の根付き木 $g$ (頂点数 $N$) で初期化
- `int size()`
	- $\Theta(1)$ 木の頂点数 $N$ を返す
- `int depth(int v)`
	- $\Theta(1)$ 頂点 $v$ の深さ(根からの距離) を返す
- `int find(int v, int k)`
	- $\Theta(1)$ `LA(v, k)` を返す
- `int up(int v, int k)`
	- $\Theta(1)$ `UP(v, k)` を返す

<br>

# コンストラクタ

Macro-Tree と Micro-Tree の境界を $S$ ( Micro-Tree の頂点数は $S$ 未満) とし、$S$ 種類の値を表すことのできるビット数を $B$ としています。  
よく使いそうな $(S, B)$ の組み合わせを載せておきます。  

- $N < 2^{31}$ のとき $(8, 3)$
- $N < 2^{20}$ のとき $(5, 3)$
- $N < 2^{16}$ のとき $(4, 2)$

**制約**

- $2 \leq S \leq 2^B$
- $1 \le B \le 3$
- $S = floor(\log_2{N} / 4)$

---

### LevelAncestor(const Graph & g, int root = 0)

根 `root` の根付き木 $g$ (頂点数 $N$) で初期化します。  

**制約**

- $0 \leq$ `root` $< N$
- `g` は根付き木または木

**計算量**

- 時間/空間 $\mathcal{O}(N)$

---

<br>

# メンバ関数

以下、グラフの頂点数を $N$ とします。  

---

### int size()

木の頂点数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### int depth(int v)

頂点 $v$ の深さ(根からの距離) を返します。  

**制約**

- $0 \le v < N$

**計算量**

- $\Theta(1)$

---

### int find(int v, int k)

`LA(v, k)` を返します。  
つまり、頂点 $v$ の先祖であって、深さが $k$ であるような頂点を返します。  
`()` 演算子によっても呼び出すことができます。  

**制約**

- $0 \le v < N$
- $0 \le k \le$ `depth(v)`

**計算量**

- $\Theta(1)$

---

### int up(int v, int k)

`UP(v, k)` を返します。  
つまり、頂点 $v$ を根方向に $k$ 回辺を辿った後の頂点を返します。  

**制約**

- $0 \le v < N$
- $0 \le k \le$ `depth(v)`

**計算量**

- $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "GraphTheory/LevelAncestor.hpp"
using namespace std;

int main() {
	// <S, B>: S := ceil(log_2(N)/4), B := ceil(log_2(S)) (S <= 2^B)
	// N < 2^31   ->   <8, 3>
	// N < 2^20   ->   <5, 3>
	// N < 2^16   ->   <4, 2>
	using LA = LevelAncestor<4, 2>;
	LA::Graph g(12);
	//            1
	//       2        3
	//   0      4          5
	// 6      7 8 9      10  11
	g[1].emplace_back(2);
	g[1].emplace_back(3);
	g[2].emplace_back(0);
	g[2].emplace_back(4);
	g[3].emplace_back(5);
	g[0].emplace_back(6);
	g[4].emplace_back(7);
	g[4].emplace_back(8);
	g[4].emplace_back(9);
	g[5].emplace_back(10);
	g[5].emplace_back(11);
	
	g[4].emplace_back(2); // 逆辺があっても良い
	

	LA la(g, 1);
	
	cout << "size() = " << la.size() << endl; // 12
	cout << "depth(3) = " << la.depth(3) << endl; // 1
	cout << "la(7, 1) = " << la(7, 1) << endl; // 2
	cout << "la(10, 0) = " << la(10, 0) << endl; // 1
	cout << "find(5, 1) = " << la.find(5, 1) << endl; // 3
	cout << "find(10, 3) = " << la.find(10, 3) << endl; // 10
	cout << "up(5, 1) = " << la.up(5, 1) << endl; // 3
	cout << "up(11, 1) = " << la.up(11, 1) << endl; // 5
	cout << "up(2, 0) = " << la.up(2, 0) << endl; // 2
	
	// 2 0 1 1 2 2 3 3 3 3 3 3
	cout << "depth list: ";
	for (int i = 0; i < la.size(); ++i) cout << la.depth(i) << " \n"[i + 1 == la.size()];
}
```

# 解説

### long-path と ladder について

---

根からの距離が最長であるようなパス(long-path) に再帰的に分解します。  
$P(v)$ で頂点 $v$ が属する long-path を表すことにします。  

ここで次の重要な事実が成り立ちます。

> 任意の頂点 $v$ について、 $v$ から $k$ 回上った頂点を $u$ (存在しない場合は root で止める) とおくと、  
> $v \neq$ root なら $| P(u)$ の $u$ 以下(葉側) の頂点 $|$ $\ge |P(v)$ の $v$ 以下の頂点 $|$ + k  

これは各 long-path 上での高さみたいなものが $1$ 回根方向に上ることにより $1$ 以上増えることを表しています。  
 $k$ についての帰納法で証明ができます。ここでは $k = 1$ の場合のみ示しますが同じ議論で拡張できます。  

> 分かりやすくするため、$H(v)$ を $| P(v)$ の $v$ 以下の頂点 $|$ とする。  
> $u \in P(u)$ の場合は、 $P(u) =P(v)$ より $H(u) = H(v) + 1$ であるので成り立つ。  
> $u \notin P(u)$ の場合は、$P(u) \neq P(v)$ であり $P(u)$ の方が先に long-path として選ばれているため $|H(v)| \le |H(u)|$ である。  
> $|H(v)| = |H(u)|$ と仮定すると、 $P(u)$ の $u$ より下を $P(v)$ につなぎ変えることにより long-path を今以上に長くできるため $P(u)$ が選ばれたことに矛盾する。よって $|H(v)| < |H(u)|$ である。  
> したがって $k = 1$ のとき上の事実は成り立つ。(証明終)  

この事実により、$P(u) \neq P(v)$ かつ $v \neq$ root のとき、$|P(u)| \ge |P(v)| + k$ が成り立ちます。  
これが、ダブリング(ジャンプ頂点) と ladder を組み合わせることにより $\Theta(1)$ で `LA` が求まる理由です。  
ダブリングでは $1$ 回の移動で対象 $t$ との距離 $d(v, t)$ の半分より大きい回数の頂点を上ることができます。  
移動後の頂点を $v$ とすると、  
$P(u) = P(v)$ のときは、$|P(v)| > d(v, t) / 2$  
$P(u) \neq P(v)$ のときは、上の事実より $|P(v)| > d(v, t) / 2$ です。  

頂点 $v$ から $t$ へは残り $d(v, t) / 2$ 回上がる必要がありますが、どちらの場合も $P(v)$ の最も根方向の頂点から $|P(v)|$ 回以下で到達することができるので ladder を用いて
$1$ 回での移動が可能です ( ladder $i$ は $P(i)$ の頂点に、
$P(i)$ より根方向にある頂点を順に $|P(i)|$ 個加えた列である)。  


### ジャンプ頂点の個数について

---

ジャンプ頂点 (ダブリング計算を行う頂点) は、自身を含む子孫(部分木) の頂点数が $S$ 以上となる極大の深さの頂点です。  
つまり、ある頂点 $v$ について、$v$ の子に $1$ つでも子孫が $S$ 個以上になるような頂点が存在する場合、$v$ はジャンプ頂点にはなり得ません。  
$v$ の全ての子それぞれの子孫が $S$ 子未満かつ、$v$ の子孫が $S$ 個以上になるとき $v$ はジャンプ頂点になります。  

ジャンプ頂点の個数を $x$ とすると、ジャンプ頂点の部分木にはジャンプ頂点は含まれないので、各部分木に登場する頂点は異なります。  
全ての頂点を合わせても高々 $N$ 種類であることから $x S \le N$ です。  
よってジャンプ頂点の個数は $\mathcal{O}(N / \log{N})$ となります。  


### 実装について

---

- jump[u] は頂点 $u$ の対応するジャンプ頂点を示しています。$u$ 自身がジャンプ頂点である場合、最後に -(jumpp に対応する index [1-index]) に書き換えられます。未確定のとき、$N$ が割り当てられています。
- data[u] は、処理の途中で表す内容が変化します。はじめは、頂点 $u$ の自身を含む子孫の数を表します。処理が終わると、Micro-Tree 内のノードは (Micro-Tree の形状 ID,　形状に対応した $u$ の頂点番号, Micro-Tree 内での深さ) を 1 つの int で表した値に書き換えられます。それ以外の頂点は -1 に設定されます。
- utreeid[u] は形状によらない各 Micro-Tree の固有 ID です。$u$ が Micro-Node ではない場合は -1 が入ります。
- rdict[i] は Micro-Tree での頂点番号 $x$ と対応しているもとの木 $T$ の頂点番号が utreeid 毎に連続して入っています。
- rdst[i] は utreeid i の木の対応する rdict のデータが入っている先頭 index を表します。  
- `build_micro(int r)` は根を $r$ とする Micro-Tree の形状を求め、Micro-Tree 内のすべてのクエリを事前に計算する関数です。Micro-Tree 内の各頂点の data, jump の設定も行います。 jump[par[$r$]] が正しくセットされていることを仮定します。
- Micro-Tree 内クエリの事前計算には、Offline の Level Ancestor のアルゴリズムを用いています (定数倍高速化になっているかは分からない)。  


<br>

# 参考

2022/05/14: [https://noshi91.hatenablog.com/entry/2019/09/22/114149](https://noshi91.hatenablog.com/entry/2019/09/22/114149)  
2022/05/14: Michael A. Bender, Martin Farach-Colton: The Level Ancestor Problem simplified. Theor. Comput. Sci. 321(1): 5-12 (2004)  
2022/05/13: [https://37zigen.com/level-ancestor-problem/](https://37zigen.com/level-ancestor-problem/)  
2022/05/13: [https://hdbn.hatenadiary.org/entry/20111125/1322194487](https://hdbn.hatenadiary.org/entry/20111125/1322194487)  

<br>