---
data:
  _extendedDependsOn: []
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
    path: Test/WaveletMatrix.select.test.cpp
    title: Test/WaveletMatrix.select.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://misteer.hatenablog.com/entry/bit-vector,
    - https://miti-7.hatenablog.com/entry/2018/04/15/155638,
  bundledCode: "#line 1 \"DataStructure/SuccintBitVector.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
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
    4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP\r\n#define INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/07\r\n\r\n\u4F7F\u7528\u3059\u308B\u524D\u306B\
    \u5FC5\u305A build() \u3092\u547C\u3076\r\n\u9AD8\u901F\u5316\u306E\u305F\u3081\
    \u306B assert \u30C1\u30A7\u30C3\u30AF\u3092\u5165\u308C\u3066\u3044\u306A\u3044\
    \u306E\u3067\u6CE8\u610F\r\n\r\nTODO: O(1) select \u3092\u8ABF\u3079\u308B\r\n\
    \r\n# \u4ED5\u69D8\r\nn = 2^16 ~ 10^4.8 \u3067\u8A08\u7B97\u91CF\u304C\u4FDD\u8A3C\
    \u3055\u308C\u3066\u3044\u308B\u5B9F\u88C5\r\n\u7A7A\u9593\u8A08\u7B97\u91CF:\
    \ n + o(n)\r\n\r\nSuccintBitVector(size_type n) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n)\r\n\t\u8981\u7D20\u6570 n \u3067\u521D\u671F\u5316\r\n\r\nSuccintBitVector(const\
    \ std::vector<uint64> & v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\
    \tbit \u914D\u5217 v \u3067\u521D\u671F\u5316\r\n\r\nsize_type size() const noexcept\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u8981\u7D20\u6570 n \u3092\
    \u8FD4\u3059\r\n\r\nvoid set(size_type i) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(1)\r\n\ti (0 \\leq i < n) \u756A\u76EE\u306E\u30D3\u30C3\u30C8\u3092\u7ACB\
    \u3066\u308B\r\n\r\nbool access(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\r\n\ti (0 \\leq i < n) \u756A\u76EE\u306E\u30D3\u30C3\u30C8\u306E\
    \u5024\u3092\u8FD4\u3059\r\n\r\nsize_type rank1(size_type i) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(1)\r\n\t(0 \\leq i \\leq n) [0, i) \u3067 1 \u306B\
    \u306A\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u6570\u3092\u8FD4\u3059\
    \r\n\r\nsize_type rank0(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(1)\r\n\t(0 \\leq i \\leq n) [0, i) \u3067 0 \u306B\u306A\u3063\u3066\u3044\
    \u308B\u30D3\u30C3\u30C8\u306E\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type select1(size_type\
    \ k) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\trank1(i) = k \u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306E k \u3092\u8FD4\u3059 (k > 0 \u306E\u3068\u304D\
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
    4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SuccintBitVector.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/WaveletMatrix.range_frequency.test.cpp
  - Test/WaveletMatrix.select.test.cpp
  - Test/WaveletMatrix.quantile.test.cpp
  - Test/WaveletMatrix.next_prev_value.test.cpp
documentation_of: DataStructure/SuccintBitVector.hpp
layout: document
redirect_from:
- /library/DataStructure/SuccintBitVector.hpp
- /library/DataStructure/SuccintBitVector.hpp.html
title: DataStructure/SuccintBitVector.hpp
---
