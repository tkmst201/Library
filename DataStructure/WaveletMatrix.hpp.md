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
    - http://algoogle.hadrori.jp/algorithm/wavelet.html,
    - https://miti-7.hatenablog.com/entry/2018/04/28/152259,
    - https://www.slideshare.net/pfi/ss-15916040,
  bundledCode: "#line 1 \"DataStructure/WaveletMatrix.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/07\r\n\r\n\u975E\u8CA0\u6574\u6570\u5217\u3092\u6271\u3046\u9759\u7684\
    \u306A\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\r\nBitVector \u306B\
    \u304A\u3044\u3066 select \u306E\u8A08\u7B97\u91CF\u3092 \u03B1 \u3068\u3059\u308B\
    \u3002\r\n\r\nWaveletMatrix(const std::vector<value_type> &v) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n log BITS)\r\n\tv \u306E\u5024\u3067 WaveletMatrix\
    \ \u3092\u69CB\u7BC9\u3059\u308B\r\n\r\nvalue_type access(size_type k) const :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\ti \u756A\u76EE[0-indexed]\
    \ \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nstd::tuple<size_type, size_type,\
    \ size_type> rank_all(size_type l, size_type r, const_reference x) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\u8981\
    \u7D20\u3067\u3042\u3063\u3066 ({x \u3088\u308A\u5C0F\u3055\u3044\u8981\u7D20\u306E\
    \u500B\u6570}, {x \u3068\u7B49\u3057\u3044\u8981\u7D20\u306E\u500B\u6570}, {x\
    \ \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u306E\u500B\u6570}) \u3092\u8FD4\u3059\
    \r\n\tl \\geq r \u306E\u5834\u5408\u306F {0, 0, 0} \u3092\u8FD4\u3059\r\n\r\n\
    size_type rank(size_type l, size_type r, const_reference x) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r) \u5185\u306E\u8981\u7D20\
    \u3067\u3042\u3063\u3066\u5024\u304C x \u3068\u7B49\u3057\u3044\u8981\u7D20\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\r\n\tl \\geq r \u306E\u5834\u5408\u306F 0 \u3092\
    \u8FD4\u3059\r\n\r\nsize_type rank_less_than(size_type l, size_type r, const_reference\
    \ x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log BITS)\r\n\t[l, r)\
    \ \u5185\u306E\u8981\u7D20\u3067\u3042\u3063\u3066\u5024\u304C x \u3088\u308A\u5C0F\
    \u3055\u3044\u8981\u7D20\u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\tl \\geq r \u306E\
    \u5834\u5408\u306F 0 \u3092\u8FD4\u3059\r\n\r\nsize_type rank_more_than(size_type\
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
    #include <vector>\r\n#include <cstdint>\r\n#include <cassert>\r\n#include <numeric>\r\
    \n#include <tuple>\r\n#include <stack>\r\n\r\ntemplate<std::size_t BITS, typename\
    \ T, class BV>\r\nstruct WaveletMatrix {\r\n\tstatic_assert(BITS > 0, \"BITS >\
    \ 0\");\r\n\t\r\n\tusing size_type = std::size_t;\r\n\tusing value_type = T;\r\
    \n\tusing bv_type = BV;\r\n\tusing const_reference = const value_type &;\r\n\t\
    \r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<size_type>\
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
    \n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_WAVELET_MATRIX_HPP\r\n#define INCLUDE_GUARD_WAVELET_MATRIX_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/07\r\n\r\n\u975E\u8CA0\u6574\u6570\u5217\u3092\
    \u6271\u3046\u9759\u7684\u306A\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\
    \r\nBitVector \u306B\u304A\u3044\u3066 select \u306E\u8A08\u7B97\u91CF\u3092 \u03B1\
    \ \u3068\u3059\u308B\u3002\r\n\r\nWaveletMatrix(const std::vector<value_type>\
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
    #include <vector>\r\n#include <cstdint>\r\n#include <cassert>\r\n#include <numeric>\r\
    \n#include <tuple>\r\n#include <stack>\r\n\r\ntemplate<std::size_t BITS, typename\
    \ T, class BV>\r\nstruct WaveletMatrix {\r\n\tstatic_assert(BITS > 0, \"BITS >\
    \ 0\");\r\n\t\r\n\tusing size_type = std::size_t;\r\n\tusing value_type = T;\r\
    \n\tusing bv_type = BV;\r\n\tusing const_reference = const value_type &;\r\n\t\
    \r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<size_type>\
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
    \n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_WAVELET_MATRIX_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/WaveletMatrix.range_frequency.test.cpp
  - Test/WaveletMatrix.select.test.cpp
  - Test/WaveletMatrix.quantile.test.cpp
  - Test/WaveletMatrix.next_prev_value.test.cpp
documentation_of: DataStructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/DataStructure/WaveletMatrix.hpp
- /library/DataStructure/WaveletMatrix.hpp.html
title: DataStructure/WaveletMatrix.hpp
---
