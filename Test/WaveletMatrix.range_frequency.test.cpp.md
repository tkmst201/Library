---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SuccintBitVector.hpp
    title: DataStructure/SuccintBitVector.hpp
  - icon: ':x:'
    path: DataStructure/WaveletMatrix.hpp
    title: DataStructure/WaveletMatrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2426?year=2012
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2426?year=2012
  bundledCode: "#line 1 \"Test/WaveletMatrix.range_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2426?year=2012\"\
    \r\n\r\n#line 1 \"DataStructure/SuccintBitVector.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/07\r\n\r\n\u4F7F\u7528\u3059\u308B\u524D\u306B\u5FC5\u305A build() \u3092\
    \u547C\u3076\r\n\u9AD8\u901F\u5316\u306E\u305F\u3081\u306B assert \u30C1\u30A7\
    \u30C3\u30AF\u3092\u5165\u308C\u3066\u3044\u306A\u3044\u306E\u3067\u6CE8\u610F\
    \r\n\r\nTODO: O(1) select \u3092\u8ABF\u3079\u308B\r\n\r\n# \u4ED5\u69D8\r\nn\
    \ = 2^16 ~ 10^4.8 \u3067\u8A08\u7B97\u91CF\u304C\u4FDD\u8A3C\u3055\u308C\u3066\
    \u3044\u308B\u5B9F\u88C5\r\n\u7A7A\u9593\u8A08\u7B97\u91CF: n + o(n)\r\n\r\nSuccintBitVector(size_type\
    \ n) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u8981\u7D20\u6570\
    \ n \u3067\u521D\u671F\u5316\r\n\r\nSuccintBitVector(const std::vector<uint64>\
    \ & v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\tbit \u914D\u5217\
    \ v \u3067\u521D\u671F\u5316\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u8981\u7D20\u6570 n \u3092\u8FD4\u3059\r\n\
    \r\nvoid set(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\ti (0\
    \ \\leq i < n) \u756A\u76EE\u306E\u30D3\u30C3\u30C8\u3092\u7ACB\u3066\u308B\r\n\
    \r\nbool access(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\
    \n\ti (0 \\leq i < n) \u756A\u76EE\u306E\u30D3\u30C3\u30C8\u306E\u5024\u3092\u8FD4\
    \u3059\r\n\r\nsize_type rank1(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\r\n\t(0 \\leq i \\leq n) [0, i) \u3067 1 \u306B\u306A\u3063\u3066\
    \u3044\u308B\u30D3\u30C3\u30C8\u306E\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ rank0(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t(0\
    \ \\leq i \\leq n) [0, i) \u3067 0 \u306B\u306A\u3063\u3066\u3044\u308B\u30D3\u30C3\
    \u30C8\u306E\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type select1(size_type k) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\trank1(i) = k \u3092\u6E80\
    \u305F\u3059\u6700\u5C0F\u306E k \u3092\u8FD4\u3059 (k > 0 \u306E\u3068\u304D\
    \ k \u756A\u76EE[1-indexed] \u306B 1 \u304C\u51FA\u73FE\u3059\u308B\u4F4D\u7F6E\
    [1-indexed])\r\n\t\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 size() + 1 \u3092\
    \u8FD4\u3059\r\n\r\nsize_type select0(size_type k) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\r\n\trank0(i) = k \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\
    \ k \u3092\u8FD4\u3059 (k > 0 \u306E\u3068\u304D k \u756A\u76EE[1-indexed] \u306B\
    \ 0 \u304C\u51FA\u73FE\u3059\u308B\u4F4D\u7F6E[1-indexed])\r\n\t\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 size() + 1 \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\
    \nhttps://misteer.hatenablog.com/entry/bit-vector, 2020/09/03\r\nhttps://miti-7.hatenablog.com/entry/2018/04/15/155638,\
    \ 2020/09/03\r\n*/\r\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nstruct SuccintBitVector {\r\n\tusing\
    \ size_type = std::size_t;\r\n\tusing uint16 = std::uint16_t;\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\tusing uint64 = std::uint64_t;\r\n\t\r\nprivate:\r\n\t\
    // optimized n = 2^16\r\n\tstatic constexpr size_type LARGE = 8; // bits, log^2\
    \ n\r\n\tstatic constexpr size_type SMALL = 3; // bits, (log n) / 2\r\n\tstatic\
    \ constexpr size_type DAT_B = 6; // bits (2^6 = 64 bit)\r\n\tstatic constexpr\
    \ size_type SMALL_S = 1ull << (1ull << SMALL);\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tstd::vector<uint64> bits;\r\n\tstd::vector<uint32> large;\r\n\tstd::vector<uint16>\
    \ small;\r\n\t\r\n\tstatic const uint16 table[SMALL_S];\r\n\t\r\npublic:\r\n\t\
    SuccintBitVector(size_type n) {\r\n\t\tassert(n > 0);\r\n\t\tn = (n + (1u << LARGE)\
    \ - 1) >> LARGE << LARGE;\r\n\t\tthis->n = n;\r\n\t\tbits.resize((n >> DAT_B)\
    \ + 1);\r\n\t}\r\n\t\r\n\tSuccintBitVector(const std::vector<uint64> & v) {\r\n\
    \t\tassert(!v.empty());\r\n\t\tn = ((v.size() << DAT_B) + (1u << LARGE) - 1) >>\
    \ LARGE << LARGE;\r\n\t\tbits.resize((n >> DAT_B) + 1);\r\n\t\tstd::copy(std::begin(v),\
    \ std::end(v), std::begin(bits));\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i) {\r\n\t\tbits[i >>\
    \ DAT_B] |= 1ull << (i & ((1u << DAT_B) - 1));\r\n\t}\r\n\t\r\n\tbool access(size_type\
    \ i) const {\r\n\t\treturn bits[i >> DAT_B] >> (i & ((1u << DAT_B) - 1)) & 1;\r\
    \n\t}\r\n\t\r\n\tsize_type rank1(size_type i) const {\r\n\t\treturn large[i >>\
    \ LARGE] + small[i >> SMALL]\r\n\t\t\t+ pop_count(\r\n\t\t\t\tget_val(bits[i >>\
    \ DAT_B], (i & ((1u << DAT_B) - 1)) >> SMALL)\r\n\t\t\t\t\t& ((1u << (i & ((1u\
    \ << SMALL) - 1))) - 1) );\r\n\t\t// (i >> DAT_B) < bits.size() \u3068\u306A\u308B\
    \u3088\u3046\u306B +1 \u4F59\u5206\u306B\u78BA\u4FDD\r\n\t}\r\n\t\r\n\tsize_type\
    \ rank0(size_type i) const {\r\n\t\treturn i - rank1(i);\r\n\t}\r\n\t\r\n\tsize_type\
    \ select1(size_type k) const {\r\n\t\tif (k == 0) return 0;\r\n\t\t\r\n\t\tsize_type\
    \ l = 0, r = large.size() - 1; // (l, r]\r\n\t\twhile (r - l > 1) {\r\n\t\t\t\
    size_type m = (l + r) >> 1;\r\n\t\t\t(large[m] >= k ? r : l) = m;\r\n\t\t}\r\n\
    \t\t\r\n\t\tsize_type res = (r - 1) << LARGE;\r\n\t\tk -= large[r - 1];\r\n\t\t\
    size_type base = (r - 1) << (LARGE - SMALL);\r\n\t\tl = 0; r = 1u << (LARGE -\
    \ SMALL);\r\n\t\twhile (r - l > 1) {\r\n\t\t\tsize_type m = (l + r) >> 1;\r\n\t\
    \t\t(small[base + m] >= k ? r : l) = m;\r\n\t\t}\r\n\t\t\r\n\t\tres += (r - 1)\
    \ << SMALL;\r\n\t\tbase += r - 1;\r\n\t\tk -= small[base];\r\n\t\tbase >>= DAT_B\
    \ - SMALL;\r\n\t\tfor (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL;\
    \ k; ++idx, ++res) {\r\n\t\t\tif (bits[base] >> idx & 1) --k;\r\n\t\t}\r\n\t\t\
    return res;\r\n\t}\r\n\t\r\n\tsize_type select0(size_type k) const {\r\n\t\tif\
    \ (k == 0) return 0;\r\n\t\t\r\n\t\tsize_type l = 0, r = large.size() - 1; //\
    \ (l, r]\r\n\t\twhile (r - l > 1) {\r\n\t\t\tsize_type m = (l + r) >> 1;\r\n\t\
    \t\t((1u << LARGE) * m - large[m] >= k ? r : l) = m;\r\n\t\t}\r\n\t\t\r\n\t\t\
    size_type res = (r - 1) << LARGE;\r\n\t\tk -= (1u << LARGE) * (r - 1) - large[r\
    \ - 1];\r\n\t\tsize_type base = (r - 1) << (LARGE - SMALL);\r\n\t\tl = 0; r =\
    \ 1u << (LARGE - SMALL);\r\n\t\twhile (r - l > 1) {\r\n\t\t\tsize_type m = (l\
    \ + r) >> 1;\r\n\t\t\t((1u << SMALL) * m - small[base + m] >= k ? r : l) = m;\r\
    \n\t\t}\r\n\t\t\r\n\t\tres += (r - 1) << SMALL;\r\n\t\tbase += r - 1;\r\n\t\t\
    k -= (1u << SMALL) * (r - 1) - small[base];\r\n\t\tbase >>= DAT_B - SMALL;\r\n\
    \t\tfor (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res)\
    \ {\r\n\t\t\tif (~bits[base] >> idx & 1) --k;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tvoid build() {\r\n\t\tlarge.assign((n >> LARGE) + 1, 0);\r\n\t\t\
    small.assign((n >> SMALL) + 1, 0);\r\n\t\t\r\n\t\tfor (size_type i = 0, small_idx\
    \ = 1; i < bits.size() - 1; ++i) {\r\n\t\t\tif ((i & ((1u << (LARGE - DAT_B))\
    \ - 1)) == 0) small[small_idx] = pop_count(get_val(bits[i], 0));\r\n\t\t\telse\
    \ small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], 0));\r\n\
    \t\t\t++small_idx;\r\n\t\t\t\r\n\t\t\tfor (size_type j = 1; j < (1u << (DAT_B\
    \ - SMALL)); ++j, ++small_idx)\r\n\t\t\t\tsmall[small_idx] = small[small_idx -\
    \ 1] + pop_count(get_val(bits[i], j));\r\n\t\t}\r\n\t\t\r\n\t\tfor (size_type\
    \ i = 1; i < large.size(); ++i) {\r\n\t\t\tlarge[i] = large[i - 1] + small[i <<\
    \ (LARGE - SMALL)];\r\n\t\t\tsmall[i << (LARGE - SMALL)] = 0;\r\n\t\t}\r\n\t}\r\
    \n\t\r\nprivate:\r\n\tuint16 get_val(uint64 x, size_type i) const {\r\n\t\treturn\
    \ x >> ((1u << SMALL) * i) & (SMALL_S - 1);\r\n\t}\r\n\t\r\n\tuint16 pop_count(uint16\
    \ x) const {\r\n\t\treturn table[x];\r\n\t}\r\n};\r\n\r\nconstexpr SuccintBitVector::uint16\
    \ SuccintBitVector::table[256] = {\r\n\t0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,\r\n\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\n\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\n\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\
    \n\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\n\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\
    \t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\n\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\
    \n\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\
    \t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\
    4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,\r\n};\r\n\r\n\n#line 1 \"DataStructure/WaveletMatrix.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/09/07\r\n\r\n\u975E\u8CA0\u6574\u6570\u5217\
    \u3092\u6271\u3046\u9759\u7684\u306A\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\
    \u69D8\r\nBitVector \u306B\u304A\u3044\u3066 select \u306E\u8A08\u7B97\u91CF\u3092\
    \ \u03B1 \u3068\u3059\u308B\u3002\r\n\r\nWaveletMatrix(const std::vector<value_type>\
    \ &v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n log BITS)\r\n\tv \u306E\u5024\
    \u3067 WaveletMatrix \u3092\u69CB\u7BC9\u3059\u308B\r\n\r\nvalue_type access(size_type\
    \ k) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\ti \u756A\
    \u76EE[0-indexed] \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nstd::tuple<size_type,\
    \ size_type, size_type> rank_all(size_type l, size_type r, const_reference x)\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\
    \u306E\u8981\u7D20\u3067\u3042\u3063\u3066 ({x \u3088\u308A\u5C0F\u3055\u3044\u8981\
    \u7D20\u306E\u500B\u6570}, {x \u3068\u7B49\u3057\u3044\u8981\u7D20\u306E\u500B\
    \u6570}, {x \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u306E\u500B\u6570}) \u3092\
    \u8FD4\u3059\r\n\tl \\geq r \u306E\u5834\u5408\u306F {0, 0, 0} \u3092\u8FD4\u3059\
    \r\n\r\nsize_type rank(size_type l, size_type r, const_reference x) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\u8981\
    \u7D20\u3067\u3042\u3063\u3066\u5024\u304C x \u3068\u7B49\u3057\u3044\u8981\u7D20\
    \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\tl \\geq r \u306E\u5834\u5408\u306F 0\
    \ \u3092\u8FD4\u3059\r\n\r\nsize_type rank_less_than(size_type l, size_type r,\
    \ const_reference x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\
    \n\t[l, r) \u5185\u306E\u8981\u7D20\u3067\u3042\u3063\u3066\u5024\u304C x \u3088\
    \u308A\u5C0F\u3055\u3044\u8981\u7D20\u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\t\
    l \\geq r \u306E\u5834\u5408\u306F 0 \u3092\u8FD4\u3059\r\n\r\nsize_type rank_more_than(size_type\
    \ l, size_type r, const_reference x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\u8981\u7D20\u3067\u3042\u3063\u3066\
    \u5024\u304C x \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\r\n\tl \\geq r \u306E\u5834\u5408\u306F 0 \u3092\u8FD4\u3059\r\n\r\
    \nsize_type select(size_type k, const_reference x) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(\u03B1 log BITS)\r\n\trank(i, x) = k \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E i \u3092\u8FD4\u3059 (k > 0 \u306E\u3068\u304D\u3001k \u756A\
    \u76EE[1-indexed] \u306E x \u306E\u51FA\u73FE\u4F4D\u7F6E[1-indexed])\r\n\t\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 size() + 1 \u3092\u8FD4\u3059\r\n\r\nvalue_type\
    \ quantile(size_type l, size_type r, size_type k) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u3067 k \u756A\u76EE[1-indexed]\
    \ \u306B\u5C0F\u3055\u3044\u8981\u7D20\u3092\u8FD4\u3059\r\n\tl < r \\leq n \u304B\
    \u3064 0 < k \\leq r - l \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\r\
    \nsize_type range_frequency(size_type l, size_type r, value_type val_l, value_type\
    \ val_r) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l,\
    \ r) \u5185\u306E\u8981\u7D20\u3067\u3042\u3063\u3066\u3001\u5024\u304C [val_l,\
    \ val_r) \u306E\u7BC4\u56F2\u306B\u5165\u3063\u3066\u3044\u308B\u3088\u3046\u306A\
    \u8981\u7D20\u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\tl \\geq \u307E\u305F\u306F\
    \ val_l \\geq r \u306E\u5834\u5408\u306F 0 \u3092\u8FD4\u3059\r\n\r\nstd::vector<std::pair<value_type,\
    \ size_type>> range_min_k\r\n\t(size_type l, size_type r, value_type val_l, value_type\
    \ val_r, size_type k) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(k log\
    \ BITS)\r\n\t[l, r) \u5185\u306E\u8981\u7D20\u3067\u3042\u3063\u3066\u3001\u5024\
    \u304C [val_l, val_r) \u5185\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u3082\u306E\
    \u304B\u3089\u3001\r\n\t\u540C\u3058\u5024\u306F\u307E\u3068\u3081\u3066\u5C0F\
    \u3055\u3044\u5024\u304B\u3089\u9806\u306B k \u500B\u4EE5\u4E0B\u306E\u7D44 (\u5024\
    , \u51FA\u73FE\u56DE\u6570) \u306E\u914D\u5217\u306B\u3057\u3066\u8FD4\u3059\r\
    \n\r\nstd::vector<std::pair<value_type, size_type>> range_max_k\r\n\t(size_type\
    \ l, size_type r, value_type val_l, value_type val_r, size_type k) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(k log BITS)\r\n\t[l, r) \u5185\u306E\u8981\
    \u7D20\u3067\u3042\u3063\u3066\u3001\u5024\u304C [val_l, val_r) \u5185\u306B\u542B\
    \u307E\u308C\u3066\u3044\u308B\u3082\u306E\u304B\u3089\u3001\r\n\t\u540C\u3058\
    \u5024\u306F\u307E\u3068\u3081\u3066\u5927\u304D\u3044\u5024\u304B\u3089\u9806\
    \u306B k \u500B\u4EE5\u4E0B\u306E\u7D44 (\u5024, \u51FA\u73FE\u56DE\u6570) \u306E\
    \u914D\u5217\u306B\u3057\u3066\u8FD4\u3059\r\n\r\nstd::pair<value_type, bool>\
    \ next_value(size_type l, size_type r, value_type val_l, value_type val_r) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\
    \u8981\u7D20\u3067\u3042\u3063\u3066\u3001\u5024\u304C [val_l, val_r) \u306E\u7BC4\
    \u56F2\u306B\u5165\u308B\u3088\u3046\u306A\u8981\u7D20\u306E\u6700\u5C0F\u5024\
    \u3092\u8FD4\u3059\r\n\t( \u6700\u5C0F\u5024, \u6700\u5C0F\u5024\u304C\u5B58\u5728\
    \u3059\u308B\u304B\u3069\u3046\u304B(true: \u5B58\u5728\u3059\u308B, false: \u5B58\
    \u5728\u3057\u306A\u3044) )\r\n\r\nstd::pair<value_type, bool> prev_value(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\u8981\u7D20\u3067\
    \u3042\u3063\u3066\u3001\u5024\u304C [val_l, val_r) \u306E\u7BC4\u56F2\u306B\u5165\
    \u308B\u3088\u3046\u306A\u8981\u7D20\u306E\u6700\u5927\u5024\u3092\u8FD4\u3059\
    \r\n\t( \u6700\u5927\u5024, \u6700\u5927\u5024\u304C\u5B58\u5728\u3059\u308B\u304B\
    \u3069\u3046\u304B(true: \u5B58\u5728\u3059\u308B, false: \u5B58\u5728\u3057\u306A\
    \u3044) )\r\n\r\nstd::vector<std::pair<size_type, value_type>> get_rect(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(D log BITS)\r\n\t[l, r) \u5185\u306E\u8981\u7D20\u3067\
    \u3042\u3063\u3066\u3001\u5024\u304C [val_l, val_r) \u306E\u7BC4\u56F2\u306B\u5165\
    \u308B\u3088\u3046\u306A\u8981\u7D20\u3092 (index, \u5024) \u306E\u7D44\u306E\u914D\
    \u5217\u306B\u3057\u3066\u8FD4\u3059\r\n\t\u5BFE\u8C61\u306E\u8981\u7D20\u306E\
    \u500B\u6570\u3092 D \u3068\u3059\u308B\u3002\r\n\r\n# \u53C2\u8003\r\nhttps://www.slideshare.net/pfi/ss-15916040,\
    \ 2020/09/03\r\nhttps://miti-7.hatenablog.com/entry/2018/04/28/152259, 2020/09/04\r\
    \nhttp://algoogle.hadrori.jp/algorithm/wavelet.html, 2020/09/07\r\n*/\r\n\r\n\
    #line 91 \"DataStructure/WaveletMatrix.hpp\"\n#include <numeric>\r\n#include <tuple>\r\
    \n#include <stack>\r\n\r\ntemplate<std::size_t BITS, typename T, class BV>\r\n\
    struct WaveletMatrix {\r\n\tstatic_assert(BITS > 0, \"BITS > 0\");\r\n\t\r\n\t\
    using size_type = std::size_t;\r\n\tusing value_type = T;\r\n\tusing bv_type =\
    \ BV;\r\n\tusing const_reference = const value_type &;\r\n\t\r\nprivate:\r\n\t\
    size_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<size_type>\
    \ zero;\r\n\t\r\npublic:\r\n\tWaveletMatrix(const std::vector<value_type> &v)\
    \ {\r\n\t\tbuild(v);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\
    \treturn n;\r\n\t}\r\n\t\r\n\tvalue_type access(size_type k) const {\r\n\t\tassert(k\
    \ < size());\r\n\t\t\r\n\t\tvalue_type res = 0;\r\n\t\tfor (size_type i = BITS;\
    \ i > 0; --i) {\r\n\t\t\tconst size_type b = i - 1;\r\n\t\t\tif (bit_vector[b].access(k))\
    \ {\r\n\t\t\t\tres |= 1ull << b;\r\n\t\t\t\tk = bit_vector[b].rank1(k) + zero[b];\r\
    \n\t\t\t}\r\n\t\t\telse k = bit_vector[b].rank0(k);\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\t\r\n\tstd::tuple<size_type, size_type, size_type> rank_all(size_type\
    \ l, size_type r, const_reference x) const {\r\n\t\tassert(r <= size());\r\n\t\
    \tassert((x >> BITS) == 0);\r\n\t\tif (l >= r) return std::make_tuple(0, 0, 0);\r\
    \n\t\t\r\n\t\tsize_type rank_lt = 0, rank_mt = 0;\r\n\t\tfor (size_type i = BITS;\
    \ i > 0; --i) {\r\n\t\t\tsize_type b = i - 1;\r\n\t\t\tconst size_type l1 = bit_vector[b].rank1(l),\
    \ r1 = bit_vector[b].rank1(r);\r\n\t\t\tif (x >> b & 1) {\r\n\t\t\t\trank_lt +=\
    \ (r - r1) - (l - l1);\r\n\t\t\t\tl = l1 + zero[b];\r\n\t\t\t\tr = r1 + zero[b];\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\trank_mt += r1 - l1;\r\n\t\t\t\tl -= l1;\r\
    \n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn std::make_tuple(rank_lt,\
    \ r - l, rank_mt);\r\n\t}\r\n\t\r\n\tsize_type rank_less_than(size_type l, size_type\
    \ r, const_reference x) const {\r\n\t\treturn std::get<0>(rank_all(l, r, x));\r\
    \n\t}\r\n\t\r\n\tsize_type rank(size_type l, size_type r, const_reference x) const\
    \ {\r\n\t\treturn std::get<1>(rank_all(l, r, x));\r\n\t}\r\n\t\r\n\tsize_type\
    \ rank_more_than(size_type l, size_type r, const_reference x) const {\r\n\t\t\
    return std::get<2>(rank_all(l, r, x));\r\n\t}\r\n\t\r\n\tsize_type select(size_type\
    \ k, const_reference x) const {\r\n\t\tassert(k <= size());\r\n\t\tassert((x >>\
    \ BITS) == 0);\r\n\t\tif (k == 0) return 0;\r\n\t\t\r\n\t\tsize_type pos = 0;\r\
    \n\t\tfor (size_type i = BITS; i > 0; --i) {\r\n\t\t\tconst size_type b = i -\
    \ 1;\r\n\t\t\tif (x >> b & 1) pos = bit_vector[b].rank1(pos) + zero[b];\r\n\t\t\
    \telse pos = bit_vector[b].rank0(pos);\r\n\t\t}\r\n\t\tpos += k - 1;\r\n\t\tif\
    \ (pos >= size()) return size() + 1;\r\n\t\t\r\n\t\tfor (size_type i = 0; i <\
    \ BITS; ++i) {\r\n\t\t\tsize_type npos;\r\n\t\t\tif (x >> i & 1) {\r\n\t\t\t\t\
    if (pos < zero[i]) return size() + 1;\r\n\t\t\t\tnpos = bit_vector[i].select1(pos\
    \ - zero[i] + 1);\r\n\t\t\t}\r\n\t\t\telse npos = bit_vector[i].select0(pos +\
    \ 1);\r\n\t\t\t\r\n\t\t\tif (npos > size()) return size() + 1;\r\n\t\t\tpos =\
    \ npos - 1;\r\n\t\t}\r\n\t\treturn pos + 1;\r\n\t}\r\n\t\r\n\tvalue_type quantile(size_type\
    \ l, size_type r, size_type k) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <=\
    \ size());\r\n\t\tassert(0 < k);\r\n\t\tassert(k <= r - l);\r\n\t\t\r\n\t\tvalue_type\
    \ res = 0;\r\n\t\tfor (size_type i = BITS; i > 0; --i) {\r\n\t\t\tconst size_type\
    \ b = i - 1;\r\n\t\t\tconst size_type l1 = bit_vector[b].rank1(l), r1 = bit_vector[b].rank1(r);\r\
    \n\t\t\tconst size_type c = (r - r1) - (l - l1);\r\n\t\t\t\r\n\t\t\tif (k <= c)\
    \ {\r\n\t\t\t\tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\
    \t\tl = l1 + zero[b];\r\n\t\t\t\tr = r1 + zero[b];\r\n\t\t\t\tk -= c;\r\n\t\t\t\
    \tres |= 1ull << b;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    size_type range_frequency(size_type l, size_type r, value_type val_l, value_type\
    \ val_r) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r - 1) >> BITS)\
    \ == 0);\r\n\t\tif (l >= r || val_l >= val_r) return 0;\r\n\t\treturn rank_less_than(l,\
    \ r, val_r) - rank_less_than(l, r, val_l);\r\n\t}\r\n\t\r\n\tstd::vector<std::pair<value_type,\
    \ size_type>> range_min_k\r\n\t\t(size_type l, size_type r, value_type val_l,\
    \ value_type val_r, size_type k) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r\
    \ - 1) >> BITS) == 0);\r\n\t\tif (l >= r || val_l >= val_r || k == 0) return {};\r\
    \n\t\t\r\n\t\tstd::vector<std::pair<value_type, size_type>> res;\r\n\t\tstruct\
    \ Data {\r\n\t\t\tsize_type i, l, r;\r\n\t\t\tbool ismin;\r\n\t\t\tvalue_type\
    \ val;\r\n\t\t\tData(size_type i, size_type l, size_type r, bool ismin, value_type\
    \ val)\r\n\t\t\t\t: i(i), l(l), r(r), ismin(ismin), val(val) {}\r\n\t\t};\r\n\t\
    \t\r\n\t\tstd::stack<Data> stk;\r\n\t\tstk.emplace(BITS, l, r, true, 0);\r\n\t\
    \t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst Data dat = stk.top(); stk.pop();\r\
    \n\t\t\tif (dat.i == 0) {\r\n\t\t\t\tif (dat.val < val_r) {\r\n\t\t\t\t\tres.emplace_back(dat.val,\
    \ dat.r - dat.l);\r\n\t\t\t\t\tif (res.size() == k) break;\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\telse break;\r\n\t\t\t}\r\n\t\t\tconst size_type b = dat.i\
    \ - 1;\r\n\t\t\tconst size_type l1 = bit_vector[b].rank1(dat.l), r1 = bit_vector[b].rank1(dat.r);\r\
    \n\t\t\t\r\n\t\t\tconst bool bit = val_l >> b & 1;\r\n\t\t\tif (l1 != r1) stk.emplace(b,\
    \ l1 + zero[b], r1 + zero[b], dat.ismin & bit, dat.val | (1ull << b));\r\n\t\t\
    \tif (!(dat.ismin && bit)) {\r\n\t\t\t\tconst size_type l0 = dat.l - l1, r0 =\
    \ dat.r - r1;\r\n\t\t\t\tif (l0 != r0) stk.emplace(b, l0, r0, dat.ismin, dat.val);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::vector<std::pair<value_type,\
    \ size_type>> range_max_k\r\n\t\t(size_type l, size_type r, value_type val_l,\
    \ value_type val_r, size_type k) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r\
    \ - 1) >> BITS) == 0);\r\n\t\tif (l >= r || val_l >= val_r || k == 0) return {};\r\
    \n\t\t--val_r;\r\n\t\t\r\n\t\tstd::vector<std::pair<value_type, size_type>> res;\r\
    \n\t\tstruct Data {\r\n\t\t\tsize_type i, l, r;\r\n\t\t\tbool ismax;\r\n\t\t\t\
    value_type val;\r\n\t\t\tData(size_type i, size_type l, size_type r, bool ismax,\
    \ value_type val)\r\n\t\t\t\t: i(i), l(l), r(r), ismax(ismax), val(val) {}\r\n\
    \t\t};\r\n\t\t\r\n\t\tstd::stack<Data> stk;\r\n\t\tstk.emplace(BITS, l, r, true,\
    \ 0);\r\n\t\t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst Data dat = stk.top();\
    \ stk.pop();\r\n\t\t\tif (dat.i == 0) {\r\n\t\t\t\tif (dat.val >= val_l) {\r\n\
    \t\t\t\t\tres.emplace_back(dat.val, dat.r - dat.l);\r\n\t\t\t\t\tif (res.size()\
    \ == k) break;\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\telse break;\r\n\t\
    \t\t}\r\n\t\t\tconst size_type b = dat.i - 1;\r\n\t\t\tconst size_type l1 = bit_vector[b].rank1(dat.l),\
    \ r1 = bit_vector[b].rank1(dat.r);\r\n\t\t\t\r\n\t\t\tconst bool bit = val_r >>\
    \ b & 1;\r\n\t\t\tconst size_type l0 = dat.l - l1, r0 = dat.r - r1;\r\n\t\t\t\
    if (l0 != r0) stk.emplace(b, l0, r0, dat.ismax & !bit, dat.val);\r\n\t\t\tif (!(dat.ismax\
    \ & !bit) && l1 != r1) stk.emplace(b, l1 + zero[b], r1 + zero[b], dat.ismax, dat.val\
    \ | (1ull << b));\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<value_type,\
    \ bool> next_value(size_type l, size_type r, value_type val_l, value_type val_r)\
    \ const {\r\n\t\tconst auto res = range_min_k(l, r, val_l, val_r, 1);\r\n\t\t\
    if (res.empty()) return {0, false};\r\n\t\treturn {res[0].first, true};\r\n\t\
    }\r\n\t\r\n\tstd::pair<value_type, bool> prev_value(size_type l, size_type r,\
    \ value_type val_l, value_type val_r) const {\r\n\t\tconst auto res = range_max_k(l,\
    \ r, val_l, val_r, 1);\r\n\t\tif (res.empty()) return {0, false};\r\n\t\treturn\
    \ {res[0].first, true};\r\n\t}\r\n\t\r\n\tstd::vector<std::pair<size_type, value_type>>\
    \ get_rect(size_type l, size_type r, value_type val_l, value_type val_r) const\
    \ {\r\n\t\tauto points = range_min_k(l, r, val_l, val_r, r - l);\r\n\t\tstd::vector<std::pair<size_type,\
    \ value_type>> res;\r\n\t\tfor (auto &p : points) {\r\n\t\t\tconst size_type c\
    \ = rank(0, l, p.first);\r\n\t\t\tfor (size_type i = 0; i < p.second; ++i) res.emplace_back(select(c\
    \ + i + 1, p.first) - 1, p.first);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\
    private:\r\n\tvoid build(const std::vector<value_type> &v) {\r\n\t\tassert(!v.empty());\r\
    \n\t\tn = v.size();\r\n\t\tfor (size_type i = 0; i < n; ++i) assert((v[i] >> BITS)\
    \ == 0);\r\n\t\t\r\n\t\tbit_vector.resize(BITS, bv_type{n});\r\n\t\tzero.resize(BITS,\
    \ 0);\r\n\t\t\r\n\t\tstd::vector<size_type> ord(n), nex_ord;\r\n\t\tstd::iota(std::begin(ord),\
    \ std::end(ord), 0);\r\n\t\t\r\n\t\tfor (size_type i = BITS - 1; i >= 0; --i)\
    \ {\r\n\t\t\tnex_ord.assign(n, 0);\r\n\t\t\tfor (size_type j = 0; j < n; ++j)\
    \ {\r\n\t\t\t\tif (v[ord[j]] >> i & 1) bit_vector[i].set(j);\r\n\t\t\t\telse ++zero[i];\r\
    \n\t\t\t}\r\n\t\t\tif (i == 0) break; // \u6700\u5F8C\u306F sort \u3057\u306A\u3044\
    \r\n\t\t\t\r\n\t\t\tsize_type p0 = 0, p1 = zero[i];\r\n\t\t\tfor (size_type j\
    \ = 0; j < n; ++j) {\r\n\t\t\t\tif (v[ord[j]] >> i & 1) nex_ord[p1++] = ord[j];\r\
    \n\t\t\t\telse nex_ord[p0++] = ord[j];\r\n\t\t\t}\r\n\t\t\tstd::swap(ord, nex_ord);\r\
    \n\t\t}\r\n\t\t\r\n\t\tfor (size_type i = 0; i < BITS; ++i) bit_vector[i].build();\r\
    \n\t}\r\n};\r\n\r\n\n#line 5 \"Test/WaveletMatrix.range_frequency.test.cpp\"\n\
    \r\n#include <cstdio>\r\n#line 9 \"Test/WaveletMatrix.range_frequency.test.cpp\"\
    \n\r\nconstexpr int INF = 1'000'000'001;\r\n\r\nint main() {\r\n\tint N, M;\r\n\
    \tscanf(\"%d %d\", &N, &M);\r\n\t\r\n\tstd::vector<int> x(N), y(N), cx, cy;\r\n\
    \tfor (int i = 0; i < N; ++i) scanf(\"%d %d\", &x[i], &y[i]);\r\n\t\r\n\tauto\
    \ compress = [](auto &&v, auto &&cv) -> void {\r\n\t\tfor (auto &&u : v) cv.emplace_back(u);\r\
    \n\t\tcv.emplace_back(INF);\r\n\t\tcv.emplace_back(-INF);\r\n\t\tstd::sort(std::begin(cv),\
    \ std::end(cv));\r\n\t\tcv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\
    \n\t\tfor (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u)\
    \ - std::begin(cv);\r\n\t};\r\n\t\r\n\tcompress(x, cx);\r\n\tcompress(y, cy);\r\
    \n\t\r\n\t// \u540C\u3058 x \u5EA7\u6A19\u3067\u3082 wavelet matrix \u4E0A\u3067\
    \u306F\u7570\u306A\u308B index \u306B\u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\
    \u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\tstd::vector<int> sum(cx.size());\
    \ // [i] := x[j] \u304C i \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A j \u306E\
    \u500B\u6570\r\n\tfor (int i = 0; i < x.size(); ++i) ++sum[x[i]];\r\n\tfor (int\
    \ i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];\r\n\t\r\n\tstd::vector<int>\
    \ cnt(cx.size()), sy(N); // sy[i] := x \u5EA7\u6A19\u304C i \u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u70B9\u306E y \u5EA7\u6A19(x \u5EA7\u6A19\u304C\u540C\u4E00\
    \u306E\u5834\u5408\u306B\u3082\u5DEE\u3092\u3064\u3051\u308B)\r\n\tfor (int i\
    \ = 0; i < x.size(); ++i) sy[sum[x[i] - 1] + cnt[x[i]]++] = y[i];\r\n\t\r\n\t\
    WaveletMatrix<13, int, SuccintBitVector> wm(sy);\r\n\t\r\n\tauto compress_get\
    \ = [](auto &&cv, auto &&x) {\r\n\t\treturn std::lower_bound(std::begin(cv), std::end(cv),\
    \ x) - std::begin(cv);\r\n\t};\r\n\t\r\n\tfor (int i = 0; i < M; ++i) {\r\n\t\t\
    int sty, stx, edy, edx;\r\n\t\tscanf(\"%d %d %d %d\", &stx, &sty, &edx, &edy);\r\
    \n\t\t++edx; ++edy;\r\n\t\tsty = compress_get(cy, sty);\r\n\t\tstx = compress_get(cx,\
    \ stx);\r\n\t\tedy = compress_get(cy, edy);\r\n\t\tedx = compress_get(cx, edx);\r\
    \n\t\tprintf(\"%d\\n\", wm.range_frequency(sum[stx - 1], sum[edx - 1], sty, edy));\r\
    \n\t}\r\n\t\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2426?year=2012\"\
    \r\n\r\n#include \"DataStructure/SuccintBitVector.hpp\"\r\n#include \"DataStructure/WaveletMatrix.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n#include <algorithm>\r\n\r\n\
    constexpr int INF = 1'000'000'001;\r\n\r\nint main() {\r\n\tint N, M;\r\n\tscanf(\"\
    %d %d\", &N, &M);\r\n\t\r\n\tstd::vector<int> x(N), y(N), cx, cy;\r\n\tfor (int\
    \ i = 0; i < N; ++i) scanf(\"%d %d\", &x[i], &y[i]);\r\n\t\r\n\tauto compress\
    \ = [](auto &&v, auto &&cv) -> void {\r\n\t\tfor (auto &&u : v) cv.emplace_back(u);\r\
    \n\t\tcv.emplace_back(INF);\r\n\t\tcv.emplace_back(-INF);\r\n\t\tstd::sort(std::begin(cv),\
    \ std::end(cv));\r\n\t\tcv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\
    \n\t\tfor (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u)\
    \ - std::begin(cv);\r\n\t};\r\n\t\r\n\tcompress(x, cx);\r\n\tcompress(y, cy);\r\
    \n\t\r\n\t// \u540C\u3058 x \u5EA7\u6A19\u3067\u3082 wavelet matrix \u4E0A\u3067\
    \u306F\u7570\u306A\u308B index \u306B\u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\
    \u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\tstd::vector<int> sum(cx.size());\
    \ // [i] := x[j] \u304C i \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A j \u306E\
    \u500B\u6570\r\n\tfor (int i = 0; i < x.size(); ++i) ++sum[x[i]];\r\n\tfor (int\
    \ i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];\r\n\t\r\n\tstd::vector<int>\
    \ cnt(cx.size()), sy(N); // sy[i] := x \u5EA7\u6A19\u304C i \u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u70B9\u306E y \u5EA7\u6A19(x \u5EA7\u6A19\u304C\u540C\u4E00\
    \u306E\u5834\u5408\u306B\u3082\u5DEE\u3092\u3064\u3051\u308B)\r\n\tfor (int i\
    \ = 0; i < x.size(); ++i) sy[sum[x[i] - 1] + cnt[x[i]]++] = y[i];\r\n\t\r\n\t\
    WaveletMatrix<13, int, SuccintBitVector> wm(sy);\r\n\t\r\n\tauto compress_get\
    \ = [](auto &&cv, auto &&x) {\r\n\t\treturn std::lower_bound(std::begin(cv), std::end(cv),\
    \ x) - std::begin(cv);\r\n\t};\r\n\t\r\n\tfor (int i = 0; i < M; ++i) {\r\n\t\t\
    int sty, stx, edy, edx;\r\n\t\tscanf(\"%d %d %d %d\", &stx, &sty, &edx, &edy);\r\
    \n\t\t++edx; ++edy;\r\n\t\tsty = compress_get(cy, sty);\r\n\t\tstx = compress_get(cx,\
    \ stx);\r\n\t\tedy = compress_get(cy, edy);\r\n\t\tedx = compress_get(cx, edx);\r\
    \n\t\tprintf(\"%d\\n\", wm.range_frequency(sum[stx - 1], sum[edx - 1], sty, edy));\r\
    \n\t}\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - DataStructure/SuccintBitVector.hpp
  - DataStructure/WaveletMatrix.hpp
  isVerificationFile: true
  path: Test/WaveletMatrix.range_frequency.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/WaveletMatrix.range_frequency.test.cpp
layout: document
redirect_from:
- /verify/Test/WaveletMatrix.range_frequency.test.cpp
- /verify/Test/WaveletMatrix.range_frequency.test.cpp.html
title: Test/WaveletMatrix.range_frequency.test.cpp
---
