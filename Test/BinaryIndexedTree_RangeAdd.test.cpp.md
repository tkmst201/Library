---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: DataStructure/BinaryIndexedTree.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: DataStructure/BinaryIndexedTree_RangeAdd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"Test/BinaryIndexedTree_RangeAdd.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\r\n\r\n\
    #line 1 \"DataStructure/BinaryIndexedTree.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/08/15\r\
    \n\r\n# \u4ED5\u69D8\r\nSegmentTree(size_type n_, const F & f, const_reference\
    \ id_elem) :\r\n\t\u8981\u7D20\u6570 n_, \u4E8C\u9805\u6F14\u7B97 f, \u5358\u4F4D\
    \u5143 id_elem\r\n\r\n\r\nvoid add(size_type i, const_reference x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF \u0398(lon n)\r\n\ti \u756A\u76EE\u306E\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u3048\u308B\r\n\r\nvalue_type sum(size_type i) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF \u0398(log n)\r\n\t[0, i) \u306E\u5408\u8A08\u3092\u8FD4\
    \u3059\r\n\r\nsize_type lower_bound(const_reference x) const {\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF \u0398(log n)\r\n\tsum[0, r] \\leq x \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E r \u3092\u8FD4\u3059 (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \ size())\r\n\t\u5404\u8981\u7D20\u306F\u975E\u8CA0\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n\r\ntemplate<typename T>\r\nstruct BinaryIndexedTree {\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\n\tBinaryIndexedTree(size_type n, const F &\
    \ f, const_reference id_elem) : n(n), f(f), id_elem(id_elem) {\r\n\t\tnode.resize(n\
    \ + 1, id_elem);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid add(size_type i, const_reference x) {\r\n\t\tassert(i\
    \ < size());\r\n\t\t++i;\r\n\t\tfor (; i <= size(); i += i & -i) node[i] = f(node[i],\
    \ x);\r\n\t}\r\n\t\r\n\t// [0, i)\r\n\tvalue_type sum(size_type i) const {\r\n\
    \t\tassert(i <= size());\r\n\t\tvalue_type res = id_elem;\r\n\t\tfor (; i > 0;\
    \ i -= i & -i) res = f(res, node[i]);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t//\
    \ sum[0, r] <= x \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\u8FD4\u3059\
    \ (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 size())\r\n\tsize_type lower_bound(const_reference\
    \ x) const {\r\n\t\tsize_type res = 0;\r\n\t\tsize_type s = id_elem, w = 1;\r\n\
    \t\twhile (w < size()) w <<= 1;\r\n\t\tfor (; w > 0; w >>= 1) {\r\n\t\t\tif (res\
    \ + w <= size()) {\r\n\t\t\t\tvalue_type cur = f(s, node[res + w]);\r\n\t\t\t\t\
    if (cur < x) {\r\n\t\t\t\t\tres += w;\r\n\t\t\t\t\ts = cur;\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type n;\r\
    \n\tF f;\r\n\tvalue_type id_elem;\r\n\tstd::vector<value_type> node;\r\n};\r\n\
    \r\n\n#line 1 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/08/15\r\n\r\nBIT \u3092\u7528\u3044\u305F\u533A\u9593\u52A0\
    \u7B97\u304C\u884C\u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\
    \r\ntemplate<typename T, template<typename> class U> :\r\n\tT: \u5404\u8981\u7D20\
    \u306E\u30C7\u30FC\u30BF\u578B\r\n\tU: BinaryIndexedTree\r\n\tex. BinaryIndexedTree_RangeAdd<long\
    \ long, BinaryIndexedTree> bit(...)\r\n\r\nsize_type size() const noexcept :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\r\n\r\nvoid add(size_type l, size_type r, const_reference x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [l, r) \u306B\u4E00\u69D8\
    \u306B\u5024 x \u3092\u52A0\u7B97\r\n\r\nvalue_type sum(size_type i) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [0, i) \u306E\u5408\u8A08\
    \u3092\u53D6\u5F97\r\n\r\nvalue_type sum(size_type l, size_type r) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u533A\u9593 [l, r) \u306E\u5408\u8A08\
    \u3092\u53D6\u5F97\r\n\r\n# \u53C2\u8003\r\nhttps://algo-logic.info/binary-indexed-tree/,\
    \ 2020/08/15\r\n*/\r\n\r\n#line 38 \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \n\r\ntemplate<typename T, template<typename> class U>\r\nstruct BinaryIndexedTree_RangeAdd\
    \ {\r\n\tusing bit_type = U<T>;\r\n\tusing value_type = typename bit_type::value_type;\r\
    \n\tusing const_reference = typename bit_type::const_reference;\r\n\tusing size_type\
    \ = typename bit_type::size_type;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd(size_type\
    \ n) : n(n) {\r\n\t\tbit.resize(2, bit_type(n, [](auto && x, auto && y) { return\
    \ x + y; }, 0));\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\t// [l, r) += x\r\n\tvoid add(size_type l, size_type r,\
    \ const_reference x) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\
    \tbit[0].add(l, x);\r\n\t\tbit[0].add(r - 1, -x);\r\n\t\tbit[1].add(l, -x * (static_cast<value_type>(l)\
    \ - 1));\r\n\t\tbit[1].add(r - 1, x * (r - 1));\r\n\t}\r\n\t\r\n\t// \\Sum_{ k\
    \ = [0, i) } a_k\r\n\tvalue_type sum(size_type i) {\r\n\t\tassert(i <= size());\r\
    \n\t\treturn bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);\r\
    \n\t}\r\n\t\r\n\t// \\Sum_{ k = [l, r) } a_k\r\n\tvalue_type sum(size_type l,\
    \ size_type r) {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\treturn\
    \ sum(r) - sum(l);\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<bit_type>\
    \ bit;\r\n};\r\n\r\n\n#line 5 \"Test/BinaryIndexedTree_RangeAdd.test.cpp\"\n\r\
    \n#include <cstdio>\r\nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\", &n, &q);\r\
    \n\t\r\n\tusing ll = long long;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd<ll, BinaryIndexedTree>\
    \ bit(n);\r\n\twhile (q--) {\r\n\t\tint query, s, t;\r\n\t\tscanf(\"%d %d %d\"\
    , &query, &s, &t);\r\n\t\t--s;\r\n\t\tif (query == 0) {\r\n\t\t\tint x;\r\n\t\t\
    \tscanf(\"%d\", &x);\r\n\t\t\tbit.add(s, t, x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\
    \tprintf(\"%lld\\n\", bit.sum(s, t));\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include \"DataStructure/BinaryIndexedTree.hpp\"\r\n#include \"DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \r\n\r\n#include <cstdio>\r\nint main() {\r\n\tint n, q;\r\n\tscanf(\"%d %d\"\
    , &n, &q);\r\n\t\r\n\tusing ll = long long;\r\n\t\r\n\tBinaryIndexedTree_RangeAdd<ll,\
    \ BinaryIndexedTree> bit(n);\r\n\twhile (q--) {\r\n\t\tint query, s, t;\r\n\t\t\
    scanf(\"%d %d %d\", &query, &s, &t);\r\n\t\t--s;\r\n\t\tif (query == 0) {\r\n\t\
    \t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\n\t\t\tbit.add(s, t, x);\r\n\t\t}\r\n\
    \t\telse {\r\n\t\t\tprintf(\"%lld\\n\", bit.sum(s, t));\r\n\t\t}\r\n\t}\r\n\t\
    return 0;\r\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree.hpp
  - DataStructure/BinaryIndexedTree_RangeAdd.hpp
  isVerificationFile: true
  path: Test/BinaryIndexedTree_RangeAdd.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/BinaryIndexedTree_RangeAdd.test.cpp
layout: document
redirect_from:
- /verify/Test/BinaryIndexedTree_RangeAdd.test.cpp
- /verify/Test/BinaryIndexedTree_RangeAdd.test.cpp.html
title: Test/BinaryIndexedTree_RangeAdd.test.cpp
---
