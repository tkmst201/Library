---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SuccintBitVector.hpp
    title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.next_prev_value.test.cpp
    title: Test/WaveletMatrix.next_prev_value.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.quantile.test.cpp
    title: Test/WaveletMatrix.quantile.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.range_frequency.test.cpp
    title: Test/WaveletMatrix.range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/WaveletMatrix.select.range_k.test.cpp
    title: Test/WaveletMatrix.select.range_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp
  bundledCode: "#line 1 \"DataStructure/WaveletMatrix.hpp\"\n\n\n\r\n#line 1 \"DataStructure/SuccintBitVector.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <algorithm>\r\n\
    #include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp\r\
    \n */\r\nstruct SuccintBitVector {\r\n\tusing size_type = std::size_t;\r\n\tusing\
    \ uint32 = std::uint32_t;\r\n\t\r\nprivate:\r\n\tusing uint8 = std::uint8_t;\r\
    \n\t\r\n\tstatic constexpr size_type LARGE = 8;\r\n\tstatic constexpr size_type\
    \ SMALL = 3;\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<uint8> bits;\r\
    \n\tstd::vector<uint32> large;\r\n\tstd::vector<uint8> small;\r\n\t\r\npublic:\r\
    \n\texplicit SuccintBitVector(size_type n)\r\n\t\t: n(n), bits(n == 0 ? 0 : ((n\
    \ - 1) >> SMALL) + 1, 0u) {}\r\n\t\r\n\texplicit SuccintBitVector(const std::vector<uint8>\
    \ & bits)\r\n\t\t: n(bits.size() << SMALL), bits(bits) {}\r\n\t\r\n\tvoid build()\
    \ {\r\n\t\tlarge.assign(((n - 1) >> LARGE) + 1, 0);\r\n\t\tsmall.assign(((n -\
    \ 1) >> SMALL) + 1, 0);\r\n\t\tfor (uint32 i = 0, lidx = 0; i < bits.size(); i\
    \ += 1u << (LARGE - SMALL), ++lidx) {\r\n\t\t\tif (lidx > 0) large[lidx] = large[lidx\
    \ - 1] + small[i - 1] + pop_count(bits[i - 1]);\r\n\t\t\tsmall[i] = 0;\r\n\t\t\
    \tfor (uint32 j = i + 1; j < std::min<uint32>(bits.size(), i + (1u << (LARGE -\
    \ SMALL))); ++j) {\r\n\t\t\t\tsmall[j] = small[j - 1] + pop_count(bits[j - 1]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i) noexcept {\r\n\t\tassert(i <\
    \ n);\r\n\t\tbits[i >> SMALL] |= 1u << (i & ~(~0u << SMALL));\r\n\t}\r\n\t\r\n\
    \tvoid reset(size_type i) noexcept {\r\n\t\tassert(i < n);\r\n\t\tbits[i >> SMALL]\
    \ &= ~(1u << (i & ~(~0u << SMALL)));\r\n\t}\r\n\t\r\n\tbool access(size_type i)\
    \ const noexcept {\r\n\t\tassert(i < n);\r\n\t\treturn bits[i >> SMALL] >> (i\
    \ & ~(~0u << SMALL)) & 1;\r\n\t}\r\n\t\r\n\tuint32 rank1(size_type i) const noexcept\
    \ {\r\n\t\tassert(i <= n);\r\n\t\tif (i == 0) return 0;\r\n\t\t--i;\r\n\t\treturn\
    \ large[i >> LARGE] + small[i >> SMALL] + pop_count(bits[i >> SMALL] & ~(~0u <<\
    \ ((i & (~(~0u << SMALL))) + 1)));\r\n\t}\r\n\t\r\n\tuint32 rank0(size_type i)\
    \ const noexcept {\r\n\t\tassert(i <= n);\r\n\t\treturn i - rank1(i);\r\n\t}\r\
    \n\t\r\n\tsize_type select1(size_type k) const noexcept {\r\n\t\tif (k == 0) return\
    \ size() + 1;\r\n\t\tuint32 l = 0, r = large.size();\r\n\t\twhile (l + 1 < r)\
    \ {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(large[m] < k ? l : r) =\
    \ m;\r\n\t\t}\r\n\t\tuint32 cnt = large[l];\r\n\t\tl = l << (LARGE - SMALL); r\
    \ = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + small[m]\
    \ < k ? l : r) = m;\r\n\t\t}\r\n\t\tcnt += small[l];\r\n\t\tconst uint32 idx =\
    \ l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u <<\
    \ SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(bits[idx] & ~(~0u << r)) < k) return\
    \ size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >>\
    \ 1;\r\n\t\t\t(cnt + pop_count(bits[idx] & ~(~0u << m)) < k ? l : r) = m;\r\n\t\
    \t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\n\tsize_type select0(size_type\
    \ k) const noexcept {\r\n\t\tif (k == 0) return size() + 1;\r\n\t\tuint32 l =\
    \ 0, r = large.size();\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l\
    \ + r) >> 1;\r\n\t\t\t(m * (1 << LARGE) - large[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tuint32 cnt = l * (1 << LARGE) - large[l];\r\n\t\tl = l << (LARGE - SMALL);\
    \ r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + (m & ~(~0u\
    \ << (LARGE - SMALL))) * (1u << SMALL) - small[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tcnt += (l & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[l];\r\n\t\
    \tconst uint32 idx = l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size()\
    \ - 1) & ~(0u << SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(~bits[idx] & ~(~0u\
    \ << r)) < k) return size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32\
    \ m = (l + r) >> 1;\r\n\t\t\t(cnt + pop_count(~bits[idx] & ~(~0u << m)) < k ?\
    \ l : r) = m;\r\n\t\t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic constexpr uint8 table[1u << (1u << SMALL)] {\r\n\t\t0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8\r\n\t};\r\
    \n\t\r\n\tstatic constexpr uint8 pop_count(uint8 x) noexcept {\r\n\t\treturn table[x];\r\
    \n\t}\r\n};\r\n\r\n\n#line 5 \"DataStructure/WaveletMatrix.hpp\"\n\r\n#line 9\
    \ \"DataStructure/WaveletMatrix.hpp\"\n#include <tuple>\r\n#include <stack>\r\n\
    \r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp\r\
    \n */\r\ntemplate<typename T, int BITS>\r\nstruct WaveletMatrix {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\tstatic_assert(BITS > 0);\r\n\tstatic_assert(BITS <= 64);\r\n\t\
    static_assert(BITS <= 8 * sizeof(T));\r\n\t\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing bv_type = SuccintBitVector;\r\n\t\r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\
    \n\t\r\n\tsize_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<uint32>\
    \ zero;\r\n\t\r\npublic:\r\n\texplicit WaveletMatrix(const std::vector<value_type>\
    \ & v) {\r\n\t\tbuild(v);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build(const std::vector<value_type>\
    \ & v) {\r\n\t\tassert(!v.empty());\r\n\t\tn = v.size();\r\n\t\tfor (uint32 i\
    \ = 0; i < n; ++i) assert((v[i] >> BITS) == 0);\r\n\t\tbit_vector.assign(BITS,\
    \ bv_type(n));\r\n\t\tzero.assign(BITS, 0);\r\n\t\tstd::vector<value_type> ord(n),\
    \ nex_ord(n);\r\n\t\tord = v;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\
    \t\t\tfor (uint32 j = 0; j < n; ++j) {\r\n\t\t\t\tif (ord[j] >> i & 1) bit_vector[i].set(j);\r\
    \n\t\t\t\telse nex_ord[zero[i]++] = ord[j];\r\n\t\t\t}\r\n\t\t\tbit_vector[i].build();\r\
    \n\t\t\tif (i == 0) break;\r\n\t\t\tuint32 p1 = zero[i];\r\n\t\t\tfor (uint32\
    \ j = 0; j < n; ++j) if (ord[j] >> i & 1) nex_ord[p1++] = ord[j];\r\n\t\t\tstd::swap(ord,\
    \ nex_ord);\r\n\t\t}\r\n\t}\r\n\t\r\npublic:\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvalue_type access(size_type k) const noexcept\
    \ {\r\n\t\tassert(k < n);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS\
    \ - 1; i >= 0; --i) {\r\n\t\t\tif (bit_vector[i].access(k)) {\r\n\t\t\t\tres |=\
    \ 1ull << i;\r\n\t\t\t\tk = bit_vector[i].rank1(k) + zero[i];\r\n\t\t\t}\r\n\t\
    \t\telse k = bit_vector[i].rank0(k);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \n\tstd::tuple<uint32, uint32, uint32> rank_all(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\tif (l == r) return {0, 0, 0};\r\n\t\tuint32 rank_lt =\
    \ 0, rank_mt = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tconst\
    \ uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\n\t\t\tif\
    \ (x >> i & 1) {\r\n\t\t\t\trank_lt += (r - l) - (r1 - l1);\r\n\t\t\t\tl = l1\
    \ + zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \trank_mt += r1 - l1;\r\n\t\t\t\tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn {rank_lt, r - l, rank_mt};\r\n\t}\r\n\t\r\n\tuint32 rank_less_than(size_type\
    \ l, size_type r, const_reference x) const noexcept {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) == 0);\r\n\t\treturn std::get<0>(rank_all(l,\
    \ r, x));\r\n\t}\r\n\t\r\n\tuint32 rank(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\treturn std::get<1>(rank_all(l, r, x));\r\n\t}\r\n\t\r\
    \n\tuint32 rank_more_than(size_type l, size_type r, const_reference x) const noexcept\
    \ {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) ==\
    \ 0);\r\n\t\treturn std::get<2>(rank_all(l, r, x));\r\n\t}\r\n\t\r\n\tsize_type\
    \ select(uint32 k, const_reference x) const noexcept {\r\n\t\tassert((x >> BITS)\
    \ == 0);\r\n\t\tif (k == 0 || k > size()) return size() + 1;\r\n\t\tuint32 pos\
    \ = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tif (x >> i & 1) pos\
    \ = bit_vector[i].rank1(pos) + zero[i];\r\n\t\t\telse pos = bit_vector[i].rank0(pos);\r\
    \n\t\t}\r\n\t\tpos += k;\r\n\t\tif (pos > size()) return size() + 1;\r\n\t\tfor\
    \ (int i = 0; i < BITS; ++i) {\r\n\t\t\tif (x >> i & 1) {\r\n\t\t\t\tif (pos <=\
    \ zero[i]) return size() + 1;\r\n\t\t\t\tpos = bit_vector[i].select1(pos - zero[i]);\r\
    \n\t\t\t}\r\n\t\t\telse pos = bit_vector[i].select0(pos);\r\n\t\t\tif (pos > size())\
    \ return size() + 1;\r\n\t\t}\r\n\t\treturn pos;\r\n\t}\r\n\t\r\n\tvalue_type\
    \ quantile(size_type l, size_type r, uint32 k) const noexcept {\r\n\t\tassert(l\
    \ < r);\r\n\t\tassert(r <= size());\r\n\t\tassert(0 < k);\r\n\t\tassert(k <= r\
    \ - l);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i)\
    \ {\r\n\t\t\tconst uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\
    \n\t\t\tconst uint32 c = (r - l) - (r1 - l1);\r\n\t\t\tif (k <= c) {\r\n\t\t\t\
    \tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tl = l1 +\
    \ zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t\tk -= c;\r\n\t\t\t\tres |= 1ull\
    \ << i;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type range_frequency(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const noexcept {\r\n\t\t\
    assert(r <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >=\
    \ r || val_l >= val_r) return 0;\r\n\t\treturn rank_less_than(l, r, val_r) - rank_less_than(l,\
    \ r, val_l);\r\n\t}\r\n\t\r\nprivate:\r\n\tstruct Data {\r\n\t\tint i;\r\n\t\t\
    uint32 l, r;\r\n\t\tbool f;\r\n\t\tvalue_type val;\r\n\t\tData(int i, uint32 l,\
    \ uint32 r, bool f, const value_type & val)\r\n\t\t\t: i(i), l(l), r(r), f(f),\
    \ val(val) {}\r\n\t};\r\n\t\r\npublic:\r\n\tstd::vector<std::pair<value_type,\
    \ uint32>> range_min_k(\r\n\t\tsize_type l, size_type r, value_type val_l, value_type\
    \ val_r, uint32 k) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r -\
    \ 1) >> BITS) == 0);\r\n\t\tif (l >= r || val_l >= val_r || k == 0) return {};\r\
    \n\t\tstd::vector<std::pair<value_type, uint32>> res;\r\n\t\tstd::stack<Data>\
    \ stk;\r\n\t\tstk.emplace(BITS - 1, l, r, true, 0);\r\n\t\twhile (!stk.empty())\
    \ {\r\n\t\t\tconst Data dat = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (dat.i\
    \ == -1) {\r\n\t\t\t\tif (dat.val < val_r) {\r\n\t\t\t\t\tres.emplace_back(dat.val,\
    \ dat.r - dat.l);\r\n\t\t\t\t\tif (res.size() == k) break;\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l),\
    \ r1 = bit_vector[dat.i].rank1(dat.r);\r\n\t\t\tconst uint32 l0 = dat.l - l1,\
    \ r0 = dat.r - r1;\r\n\t\t\tconst bool bit = val_l >> dat.i & 1;\r\n\t\t\tif (l1\
    \ != r1) stk.emplace(dat.i - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f & bit,\
    \ dat.val | (1ull << dat.i));\r\n\t\t\tif (!(dat.f && bit) && l0 != r0) stk.emplace(dat.i\
    \ - 1, l0, r0, dat.f, dat.val);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    std::vector<std::pair<value_type, size_type>> range_max_k(\r\n\t\tsize_type l,\
    \ size_type r, value_type val_l, value_type val_r, uint32 k) const {\r\n\t\tassert(r\
    \ <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >= r ||\
    \ val_l >= val_r || k == 0) return {};\r\n\t\t--val_r;\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tstd::stack<Data> stk;\r\n\t\tstk.emplace(BITS - 1, l,\
    \ r, true, 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst Data dat = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\tif (dat.i == -1) {\r\n\t\t\t\tif (dat.val >= val_l)\
    \ {\r\n\t\t\t\t\tres.emplace_back(dat.val, dat.r - dat.l);\r\n\t\t\t\t\tif (res.size()\
    \ == k) break;\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l), r1 = bit_vector[dat.i].rank1(dat.r);\r\
    \n\t\t\tconst uint32 l0 = dat.l - l1, r0 = dat.r - r1;\r\n\t\t\tconst bool bit\
    \ = val_r >> dat.i & 1;\r\n\t\t\tif (l0 != r0) stk.emplace(dat.i - 1, l0, r0,\
    \ dat.f & !bit, dat.val);\r\n\t\t\tif (!(dat.f && !bit) && l1 != r1) stk.emplace(dat.i\
    \ - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f, dat.val | (1ull << dat.i));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<value_type, bool> next_value(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tconst auto\
    \ res = range_min_k(l, r, val_l, val_r, 1);\r\n\t\tif (res.empty()) return {0,\
    \ false};\r\n\t\treturn {res[0].first, true};\r\n\t}\r\n\t\r\n\tstd::pair<value_type,\
    \ bool> prev_value(size_type l, size_type r, value_type val_l, value_type val_r)\
    \ const {\r\n\t\tconst auto res = range_max_k(l, r, val_l, val_r, 1);\r\n\t\t\
    if (res.empty()) return {0, false};\r\n\t\treturn {res[0].first, true};\r\n\t\
    }\r\n\t\r\n\tstd::vector<std::pair<value_type, size_type>> get_rect(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tauto points\
    \ = range_min_k(l, r, val_l, val_r, r - l);\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tfor (const auto & p : points) {\r\n\t\t\tconst uint32\
    \ c = rank(0, l, p.first);\r\n\t\t\tfor (uint32 i = 0; i < p.second; ++i) res.emplace_back(p.first,\
    \ select(c + i + 1, p.first) - 1);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_WAVELET_MATRIX_HPP\r\n#define INCLUDE_GUARD_WAVELET_MATRIX_HPP\r\
    \n\r\n#include \"DataStructure/SuccintBitVector.hpp\"\r\n\r\n#include <vector>\r\
    \n#include <cstdint>\r\n#include <cassert>\r\n#include <tuple>\r\n#include <stack>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp\r\
    \n */\r\ntemplate<typename T, int BITS>\r\nstruct WaveletMatrix {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\tstatic_assert(BITS > 0);\r\n\tstatic_assert(BITS <= 64);\r\n\t\
    static_assert(BITS <= 8 * sizeof(T));\r\n\t\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing bv_type = SuccintBitVector;\r\n\t\r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\
    \n\t\r\n\tsize_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<uint32>\
    \ zero;\r\n\t\r\npublic:\r\n\texplicit WaveletMatrix(const std::vector<value_type>\
    \ & v) {\r\n\t\tbuild(v);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build(const std::vector<value_type>\
    \ & v) {\r\n\t\tassert(!v.empty());\r\n\t\tn = v.size();\r\n\t\tfor (uint32 i\
    \ = 0; i < n; ++i) assert((v[i] >> BITS) == 0);\r\n\t\tbit_vector.assign(BITS,\
    \ bv_type(n));\r\n\t\tzero.assign(BITS, 0);\r\n\t\tstd::vector<value_type> ord(n),\
    \ nex_ord(n);\r\n\t\tord = v;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\
    \t\t\tfor (uint32 j = 0; j < n; ++j) {\r\n\t\t\t\tif (ord[j] >> i & 1) bit_vector[i].set(j);\r\
    \n\t\t\t\telse nex_ord[zero[i]++] = ord[j];\r\n\t\t\t}\r\n\t\t\tbit_vector[i].build();\r\
    \n\t\t\tif (i == 0) break;\r\n\t\t\tuint32 p1 = zero[i];\r\n\t\t\tfor (uint32\
    \ j = 0; j < n; ++j) if (ord[j] >> i & 1) nex_ord[p1++] = ord[j];\r\n\t\t\tstd::swap(ord,\
    \ nex_ord);\r\n\t\t}\r\n\t}\r\n\t\r\npublic:\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvalue_type access(size_type k) const noexcept\
    \ {\r\n\t\tassert(k < n);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS\
    \ - 1; i >= 0; --i) {\r\n\t\t\tif (bit_vector[i].access(k)) {\r\n\t\t\t\tres |=\
    \ 1ull << i;\r\n\t\t\t\tk = bit_vector[i].rank1(k) + zero[i];\r\n\t\t\t}\r\n\t\
    \t\telse k = bit_vector[i].rank0(k);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \n\tstd::tuple<uint32, uint32, uint32> rank_all(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\tif (l == r) return {0, 0, 0};\r\n\t\tuint32 rank_lt =\
    \ 0, rank_mt = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tconst\
    \ uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\n\t\t\tif\
    \ (x >> i & 1) {\r\n\t\t\t\trank_lt += (r - l) - (r1 - l1);\r\n\t\t\t\tl = l1\
    \ + zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \trank_mt += r1 - l1;\r\n\t\t\t\tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn {rank_lt, r - l, rank_mt};\r\n\t}\r\n\t\r\n\tuint32 rank_less_than(size_type\
    \ l, size_type r, const_reference x) const noexcept {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) == 0);\r\n\t\treturn std::get<0>(rank_all(l,\
    \ r, x));\r\n\t}\r\n\t\r\n\tuint32 rank(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\treturn std::get<1>(rank_all(l, r, x));\r\n\t}\r\n\t\r\
    \n\tuint32 rank_more_than(size_type l, size_type r, const_reference x) const noexcept\
    \ {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) ==\
    \ 0);\r\n\t\treturn std::get<2>(rank_all(l, r, x));\r\n\t}\r\n\t\r\n\tsize_type\
    \ select(uint32 k, const_reference x) const noexcept {\r\n\t\tassert((x >> BITS)\
    \ == 0);\r\n\t\tif (k == 0 || k > size()) return size() + 1;\r\n\t\tuint32 pos\
    \ = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tif (x >> i & 1) pos\
    \ = bit_vector[i].rank1(pos) + zero[i];\r\n\t\t\telse pos = bit_vector[i].rank0(pos);\r\
    \n\t\t}\r\n\t\tpos += k;\r\n\t\tif (pos > size()) return size() + 1;\r\n\t\tfor\
    \ (int i = 0; i < BITS; ++i) {\r\n\t\t\tif (x >> i & 1) {\r\n\t\t\t\tif (pos <=\
    \ zero[i]) return size() + 1;\r\n\t\t\t\tpos = bit_vector[i].select1(pos - zero[i]);\r\
    \n\t\t\t}\r\n\t\t\telse pos = bit_vector[i].select0(pos);\r\n\t\t\tif (pos > size())\
    \ return size() + 1;\r\n\t\t}\r\n\t\treturn pos;\r\n\t}\r\n\t\r\n\tvalue_type\
    \ quantile(size_type l, size_type r, uint32 k) const noexcept {\r\n\t\tassert(l\
    \ < r);\r\n\t\tassert(r <= size());\r\n\t\tassert(0 < k);\r\n\t\tassert(k <= r\
    \ - l);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i)\
    \ {\r\n\t\t\tconst uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\
    \n\t\t\tconst uint32 c = (r - l) - (r1 - l1);\r\n\t\t\tif (k <= c) {\r\n\t\t\t\
    \tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tl = l1 +\
    \ zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t\tk -= c;\r\n\t\t\t\tres |= 1ull\
    \ << i;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type range_frequency(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const noexcept {\r\n\t\t\
    assert(r <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >=\
    \ r || val_l >= val_r) return 0;\r\n\t\treturn rank_less_than(l, r, val_r) - rank_less_than(l,\
    \ r, val_l);\r\n\t}\r\n\t\r\nprivate:\r\n\tstruct Data {\r\n\t\tint i;\r\n\t\t\
    uint32 l, r;\r\n\t\tbool f;\r\n\t\tvalue_type val;\r\n\t\tData(int i, uint32 l,\
    \ uint32 r, bool f, const value_type & val)\r\n\t\t\t: i(i), l(l), r(r), f(f),\
    \ val(val) {}\r\n\t};\r\n\t\r\npublic:\r\n\tstd::vector<std::pair<value_type,\
    \ uint32>> range_min_k(\r\n\t\tsize_type l, size_type r, value_type val_l, value_type\
    \ val_r, uint32 k) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r -\
    \ 1) >> BITS) == 0);\r\n\t\tif (l >= r || val_l >= val_r || k == 0) return {};\r\
    \n\t\tstd::vector<std::pair<value_type, uint32>> res;\r\n\t\tstd::stack<Data>\
    \ stk;\r\n\t\tstk.emplace(BITS - 1, l, r, true, 0);\r\n\t\twhile (!stk.empty())\
    \ {\r\n\t\t\tconst Data dat = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (dat.i\
    \ == -1) {\r\n\t\t\t\tif (dat.val < val_r) {\r\n\t\t\t\t\tres.emplace_back(dat.val,\
    \ dat.r - dat.l);\r\n\t\t\t\t\tif (res.size() == k) break;\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l),\
    \ r1 = bit_vector[dat.i].rank1(dat.r);\r\n\t\t\tconst uint32 l0 = dat.l - l1,\
    \ r0 = dat.r - r1;\r\n\t\t\tconst bool bit = val_l >> dat.i & 1;\r\n\t\t\tif (l1\
    \ != r1) stk.emplace(dat.i - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f & bit,\
    \ dat.val | (1ull << dat.i));\r\n\t\t\tif (!(dat.f && bit) && l0 != r0) stk.emplace(dat.i\
    \ - 1, l0, r0, dat.f, dat.val);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    std::vector<std::pair<value_type, size_type>> range_max_k(\r\n\t\tsize_type l,\
    \ size_type r, value_type val_l, value_type val_r, uint32 k) const {\r\n\t\tassert(r\
    \ <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >= r ||\
    \ val_l >= val_r || k == 0) return {};\r\n\t\t--val_r;\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tstd::stack<Data> stk;\r\n\t\tstk.emplace(BITS - 1, l,\
    \ r, true, 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst Data dat = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\tif (dat.i == -1) {\r\n\t\t\t\tif (dat.val >= val_l)\
    \ {\r\n\t\t\t\t\tres.emplace_back(dat.val, dat.r - dat.l);\r\n\t\t\t\t\tif (res.size()\
    \ == k) break;\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l), r1 = bit_vector[dat.i].rank1(dat.r);\r\
    \n\t\t\tconst uint32 l0 = dat.l - l1, r0 = dat.r - r1;\r\n\t\t\tconst bool bit\
    \ = val_r >> dat.i & 1;\r\n\t\t\tif (l0 != r0) stk.emplace(dat.i - 1, l0, r0,\
    \ dat.f & !bit, dat.val);\r\n\t\t\tif (!(dat.f && !bit) && l1 != r1) stk.emplace(dat.i\
    \ - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f, dat.val | (1ull << dat.i));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<value_type, bool> next_value(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tconst auto\
    \ res = range_min_k(l, r, val_l, val_r, 1);\r\n\t\tif (res.empty()) return {0,\
    \ false};\r\n\t\treturn {res[0].first, true};\r\n\t}\r\n\t\r\n\tstd::pair<value_type,\
    \ bool> prev_value(size_type l, size_type r, value_type val_l, value_type val_r)\
    \ const {\r\n\t\tconst auto res = range_max_k(l, r, val_l, val_r, 1);\r\n\t\t\
    if (res.empty()) return {0, false};\r\n\t\treturn {res[0].first, true};\r\n\t\
    }\r\n\t\r\n\tstd::vector<std::pair<value_type, size_type>> get_rect(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tauto points\
    \ = range_min_k(l, r, val_l, val_r, r - l);\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tfor (const auto & p : points) {\r\n\t\t\tconst uint32\
    \ c = rank(0, l, p.first);\r\n\t\t\tfor (uint32 i = 0; i < p.second; ++i) res.emplace_back(p.first,\
    \ select(c + i + 1, p.first) - 1);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\
    \r\n#endif // INCLUDE_GUARD_WAVELET_MATRIX_HPP"
  dependsOn:
  - DataStructure/SuccintBitVector.hpp
  isVerificationFile: false
  path: DataStructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/WaveletMatrix.range_frequency.test.cpp
  - Test/WaveletMatrix.select.range_k.test.cpp
  - Test/WaveletMatrix.next_prev_value.test.cpp
  - Test/WaveletMatrix.quantile.test.cpp
documentation_of: DataStructure/WaveletMatrix.hpp
layout: document
title: Wavelet Matrix
---

# 概要

非負整数列を扱う静的データ構造です。  
各要素の値が $0$ 以上 $2^\sigma$ 未満の長さ $N$ の非負整数列に対し、事前計算 $\Theta(\sigma N)$ 、空間計算量 $N + o(N)$ で様々な計算を高速に行うことができます。  

- `WaveletMatrix(const std::vector<value_type> & v)`
	- 時間 $\Theta(\sigma \|$`v`$\|)$, 空間 $\|$`v`$\| + o(\|$`v`$\|)$ 配列 `v` で初期化
- `size_t size()`
	- $\Theta(1)$ 非負整数列の長さ $N$ を返す
- `T access(size_t k)`
	- $\Theta(\sigma)$ $A_k$ を返す
- `tuple<uint32_t, uint32_t, uint32_t> rank_all(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する ( $x$ より小さい値の個数, $x$ と等しい値の個数, $x$ より大きい値の個数) を返す
- `uint32_t rank_less_than(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数を返す
- `uint32_t rank(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ と等しい値の個数を返す
- `uint32_t rank_more_than(size_t l, size_t r, const T & x)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より大きい値の個数を返す
- `size_t select(uint32_t k, const T & x)`
	- $\mathcal{O}(\sigma \log{N})$ 先頭から $k$ 番目に出現する $x$ の位置 (1-indexed) を返す
- `T quantile(size_t l, size_t r, uint32_t k)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ の中から昇順で $k$ 番目の値を返す
- `size_t range_frequency(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の個数を返す
- `vector<pair<T, uint32_t>> range_min_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)`
	- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて小さい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返す
- `vector<pair<T, uint32_t>> range_max_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)`
	- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて大きい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返す
- `pair<T, bool> next_value(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最小値を返す
- `pair<T, bool> prev_value(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta(\sigma)$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最大値を返す
- `vector<pair<T, size_t>> get_rect(size_t l, size_t r, T val_l, T val_r)`
	- $\Theta((r - l) \sigma \log{N})$ $A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値を昇順に、値と出現位置 (0-indexed) の組の配列にして返す

<br>

# コンストラクタ

以降、$\sigma :=$ `BITS` とします。
扱う値の範囲は $0$ 以上 $2^\sigma$ 未満です。  

**制約**

- `T` は `int`, `unsigned int`, `long long`, `unsigned long long`
- `BITS` は `T` のビット数以下

---

### WaveletMatrix(const std::vector&lt;value_type&gt; & v)

配列 `v` で初期化します。  

**制約**

- `v` のすべての要素の値は非負

**計算量**

- 時間 $\Theta(\sigma \|$`v`$\|)$
- 空間 $\|$`v`$\| + o(\|$`v`$\|)$

---

<br>

# メンバ関数

以下、長さ $N$ の非負整数列 $A_0, A_1, \ldots, A_{N-1}$ を対象とします。  
また、[`SuccintBitVector`](https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp) の `rank` の計算量を $\Theta(1)$ 、`select` の計算量を $\mathcal{O}(\log{N})$ と仮定しています。  

---

### size_t size()

非負整数列 $A$ の長さ $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### T access(size_t k)

$A_k$ を返します。  

**制約**

- $0 \leq i < N$

**計算量**

- $\Theta(\sigma)$

---

### tuple<uint32_t, uint32_t, uint32_t> rank_all(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数、$x$ と等しい値の個数、$x$ より大きい値の個数を順にまとめたタプルを返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank_less_than(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より小さい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ と等しい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### uint32_t rank_more_than(size_t l, size_t r, const T & x)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する $x$ より大きい値の個数を返します。
$l = r$ のときは $(0, 0, 0)$ を返します。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq x < 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### size_t select(uint32_t k, const T & x)

先頭から $k$ 番目に出現する $x$ の位置 (1-indexed) を返します。
$k = 0$ または、そのような位置が存在しない場合は $N + 1$ を返します。  

**制約**

- $0 \leq k$
- $0 \leq x < 2^\sigma$

**計算量**

- $\mathcal{O}(\sigma \log{N})$

---

### T quantile(size_t l, size_t r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ の中から昇順で $k$ 番目の値を返します。  

**制約**

- $0 \leq l < r \leq N$
- $0 < k \leq r - l$

**計算量**

- $\Theta(\sigma)$

---

### size_t range_frequency(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の個数を返します。
$l = r$ または `val_l` $=$ `val_r` のときは $0$ を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので、この場合は代わりに `rank_all` を使用してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### vector&lt;pair&lt;T, uint32_t&gt;&gt; range_min_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて小さい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返します。
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$

---

### vector&lt;pair&lt;T, uint32_t&gt;&gt; range_max_k(size_t l, size_t r, T val_l, T val_r, uint32_t k)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値のうち、同じ値はまとめて大きい値から順に $k$ 個まで取り出し、値と出現頻度の組の配列にして返します。
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $< 2^\sigma - 1$

**計算量**

- 対象となる値の種類数を $D$ として $\Theta(D + \sigma)$

---

### pair&lt;T, bool&gt; next_value(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最小値を返します。
そのような値が存在するときは pair の $2$ 番目の値が $true$ に、存在しない場合は $false$ になります。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### pair&lt;T, bool&gt; prev_value(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値の最大値を返します。
そのような値が存在するときは pair の $2$ 番目の値が $true$ に、存在しない場合は $false$ になります。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta(\sigma)$

---

### vector&lt;pair&lt;T, size_t&gt;&gt; get_rect(size_t l, size_t r, T val_l, T val_r)

$A_l, A_{l+1}, \ldots, A_{r-1}$ に存在する `val_l` 以上 `val_r` 未満の値を昇順に、値と出現位置 (0-indexed) の組の配列にして返します。
同じ値の順序は、出現位置の昇順となります。  
$l = r$ または `val_l` $=$ `val_r` のときは空の配列を返します。  
実装の都合上 `val_r` $= ($ `T` の最大値 $) + 1$ を指定することはできないので注意してください。  

**制約**

- $0 \leq l \leq r \leq N$
- $0 \leq$ `val_l` $\leq$ `val_r` $\leq 2^\sigma$

**計算量**

- $\Theta((r - l) \sigma \log{N})$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/WaveletMatrix.hpp"
using namespace std;

int main() {
	//                                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	WaveletMatrix<int, 3> wm({3, 0, 2, 3, 4, 6, 5, 7, 1, 1});
	cout << "size = " << wm.size() << endl; // 10
	
	// 3 0 2 3 4 6 5 7 1 1
	for (int i = 0; i < wm.size(); ++i) cout << wm.access(i) << " \n"[i + 1 == wm.size()];
	
	auto [lt, r, gt] = wm.rank_all(0, 7, 3); // target = [3, 0, 2, 3, 4, 6, 5]
	cout << "< 3 (ans " << lt << "), = 3 (ans " << r << "), > 3 (ans " << gt << ")" << endl; // 2, 2, 3
	
	cout << "rank_less_than(5, 8, 7) = " << wm.rank_less_than(5, 8, 7) << endl; // 2
	cout << "rank(5, 8, 7) = " << wm.rank(5, 8, 7) << endl; // 1
	cout << "rank_more_than(5, 8, 7) = " << wm.rank_more_than(5, 8, 7) << endl; // 0
	
	cout << "select(1, 6) = " << wm.select(1, 6) << endl; // 6 (1-indexed)
	cout << "select(2, 6) = " << wm.select(2, 6) << endl; // 11 (= N + 1) (1-indexed)
	cout << "select(2, 1) = " << wm.select(2, 1) << endl; // 10
	
	cout << "quantile(2, 10, 4) = " << wm.quantile(2, 10, 4) << endl; // 3 [1, 1, 2, 3, 4, 5, 6, 7](sorted)
	
	cout << "range_frequency(1, 10, 2, 4) = " << wm.range_frequency(1, 10, 2, 4) << endl; // 2 [2, 3]
	
	puts("range_min_k");
	// target = [3, 0, 2, 3, 4, 6] -> [3, 3, 4]
	// v = 3, frequency = 2
	// v = 4, frequency = 1
	for (auto [v, fq] : wm.range_min_k(0, 6, 3, 5, 2)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	puts("range_max_k");
	
	// target = [5, 7, 1, 1] -> [5, 7, 1, 1]
	// v = 7, frequency = 1
	// v = 5, frequency = 1
	for (auto [v, fq] : wm.range_max_k(6, 10, 0, 8, 2)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	
	puts("range_min_k");
	// target = [1, 1] -> [1, 1]
	// v = 1, frequency = 2
	for (auto [v, fq] : wm.range_min_k(8, 10, 1, 2, 3)) cout << "v = " << v << ", frequency = " << fq << endl;
	
	// idx: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	//  wm: 3, 0, 2, 3, 4, 6, 5, 7, 1, 1
	
	{
		// target = [0, 2, 3] -> [2, 3]
		auto [v, b] = wm.next_value(1, 4, 2, 5);
		cout << "next_value(1, 4, 2, 5) : " << "v = " << v << ", b = " << boolalpha << b << endl; // 2, true
	}
	{
		// target = [0, 2, 3, 4, 6, 5] -> [3, 4, 5]
		auto [v, b] = wm.prev_value(1, 7, 3, 6);
		cout << "next_value(1, 7, 3, 6) : " << "v = " << v << ", b = " << boolalpha << b << endl; // 5, true
	}
	{
		// target = [2, 3] -> []
		auto [v, b] = wm.prev_value(2, 4, 0, 1);
		cout << "next_value(2, 4, 0, 1) : " << "v = " << v << ", b = " << boolalpha << b << endl; // *, false
	}
	
	// target = [2, 3, 4, 6, 5, 7, 1, 1] -> [2, 3, 1, 1]
	// v = 1, idx = 8
	// v = 1, idx = 9
	// v = 2, idx = 2
	// v = 3, idx = 3
	for (auto [v, idx] : wm.get_rect(2, 10, 1, 4)) cout << "v = " << v << ", idx = " << idx << endl;
}
```

<br>

# 参考

2020/09/03: [https://www.slideshare.net/pfi/ss-15916040](https://www.slideshare.net/pfi/ss-15916040)  
2020/09/04: [https://miti-7.hatenablog.com/entry/2018/04/28/152259](https://miti-7.hatenablog.com/entry/2018/04/28/152259)  
2020/09/07: [http://algoogle.hadrori.jp/algorithm/wavelet.html](http://algoogle.hadrori.jp/algorithm/wavelet.html)  

<br>