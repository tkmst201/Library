---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SlidingWindowAggregation.hpp
    title: DataStructure/SlidingWindowAggregation.hpp
  - icon: ':question:'
    path: Mathematics/ModInt.hpp
    title: Mathematics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"Test/SlidingWindowAggregation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\r\n\r\n#line\
    \ 1 \"DataStructure/SlidingWindowAggregation.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/22\r\n\r\n# \u6982\u8981\r\n\u30E2\u30CE\u30A4\u30C9\u3092\u6271\u3046\
    \ SWAG\r\nqueue \u306E push, pop \u306B\u52A0\u3048\u3001\u8981\u7D20\u5168\u4F53\
    \u3092\u5165\u308C\u305F\u9806\u306B fold \u3057\u305F\u7D50\u679C\u3092\u511F\
    \u5374 O(1) \u3067\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u30C7\
    \u30FC\u30BF\u69CB\u9020\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\n\ttypename T: \u6271\
    \u3046\u30E2\u30CE\u30A4\u30C9\r\n>\r\n\r\nSlidingWindowAggregation(const_reference\
    \ id_elem, const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5358\
    \u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3068\u3057\u3066\u521D\u671F\
    \u5316\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\r\n\r\nvoid push(const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1) amortized\r\n\tqueue \u306B\u5024 x \u3092\u8FFD\u52A0\u3059\u308B\
    \r\n\r\nvoid pop()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1) amortized\r\n\tqueue\
    \ \u306E\u6700\u521D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\t\u5FC5\
    \u305A\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u306A\u3089\
    \u306A\u3044\r\n\r\nvalue_type fold_all()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(1) amortized\r\n\t\u73FE\u5728\u5165\u3063\u3066\u3044\u308B\u5024\u3092 fold\
    \ \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://scrapbox.io/data-structures/Sliding_Window_Aggregation,\
    \ 2020/09/22\r\nhttps://snuke.hatenablog.com/entry/2018/09/18/135640, 2020/09/22\r\
    \n*/\r\n\r\n#include <cstdint>\r\n#include <cassert>\r\n#include <vector>\r\n\
    #include <utility>\r\n#include <functional>\r\n\r\ntemplate<typename T>\r\nstruct\
    \ SlidingWindowAggregation {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing size_type = std::uint_fast32_t;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<std::pair<value_type, value_type>>\
    \ lstack;\r\n\tstd::vector<value_type> rstack;\r\n\tvalue_type rsum;\r\n\t\r\n\
    public:\r\n\tSlidingWindowAggregation(const_reference id_elem, const F & f) :\
    \ id_elem(id_elem), f(f), rsum(id_elem) {}\r\n\t\r\n\tsize_type size() const noexcept\
    \ { return lstack.size() + rstack.size(); }\r\n\t\r\n\tvoid push(const_reference\
    \ x) {\r\n\t\trstack.emplace_back(x);\r\n\t\trsum = f(rsum, x);\r\n\t}\r\n\t\r\
    \n\tvoid pop() {\r\n\t\tassert(size() > 0);\r\n\t\tif (lstack.empty()) {\r\n\t\
    \t\tif (rstack.size() > 1) {\r\n\t\t\t\tlstack.emplace_back(rstack.back(), rstack.back());\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\twhile (rstack.size() > 1) {\r\
    \n\t\t\t\tlstack.emplace_back(rstack.back(), f(rstack.back(), lstack.back().second));\r\
    \n\t\t\t\trstack.pop_back();\r\n\t\t\t}\r\n\t\t\trstack.pop_back();\r\n\t\t\t\
    rsum = id_elem;\r\n\t\t}\r\n\t\telse lstack.pop_back();\r\n\t}\r\n\t\r\n\tvalue_type\
    \ fold_all() const {\r\n\t\treturn f(lstack.empty() ? id_elem : lstack.back().second,\
    \ rsum);\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\n/*\r\
    \nlast-updated: 2020/02/26\r\n\r\n# \u4ED5\u69D8\r\nModInt(long long val = 0)\
    \ : \u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\r\n\r\nModInt pow(long long n) const : O(log n) n \u4E57\
    \u3057\u305F\u5024\u3092\u8FD4\u3059(\u8CA0\u306E\u6574\u6570\u3082\u5BFE\u5FDC\
    )\r\nModInt inverse() const : O(log n) \u6CD5 M \u306E\u5143\u3067\u306E\u9006\
    \u5143\u3092\u8FD4\u3059\r\n\r\nconst value_type & get() const noexcept\r\nvalue_type\
    \ & get() noexcept : \u5024\u3092\u8FD4\u3059\r\n\r\nstatic decltype(M) get_mod()\
    \ noexcept : \u6CD5 M \u3092\u8FD4\u3059\r\n\r\nexplicit operator bool() const\
    \ noexcept : bool\u3078\u578B\u5909\u63DB 0\u4EE5\u5916\u306E\u3068\u304DTrue\r\
    \noperator ==() const noexcept\r\noperator !=() const noexcept\r\noperator +()\
    \ const noexept\r\noperator -() const noexept\r\noperator +(const ModInt & rhs)\
    \ const noexept\r\noperator -(const ModInt & rhs) const noexept\r\noperator *(const\
    \ ModInt & rhs) const noexept\r\noperator /(const ModInt & rhs) const noexept\r\
    \nModInt & operator +=(const ModInt & rhs) const noexept\r\nModInt & operator\
    \ +=(const ModInt & rhs) const noexept :\r\n\r\nfriend std::ostream & operator\
    \ <<(std::ostream & os, const ModInt & rhs)\r\nfriend std::istream & operator\
    \ >>(std::istream & is, ModInt & rhs) :\r\n\t\u5165\u51FA\u529B\u7528\r\n\r\n\
    # \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n*/\r\
    \n\r\n#line 39 \"Mathematics/ModInt.hpp\"\n#include <iostream>\r\n\r\ntemplate<int\
    \ M>\r\nstruct ModInt {\r\npublic:\r\n\tusing value_type = long long;\r\n\t\r\n\
    \tModInt(value_type val = 0) : val(val < 0 ? (M - (-val % M)) % M : val % M) {}\r\
    \n\t\r\n\texplicit operator bool() const noexcept { return val; }\r\n\tbool operator\
    \ ==(const ModInt & rhs) const noexcept { return val == rhs.val; }\r\n\tbool operator\
    \ !=(const ModInt & rhs) const noexcept { return !(*this == rhs); }\r\n\tModInt\
    \ operator +() const noexcept { return ModInt(*this); }\r\n\tModInt operator -()\
    \ const noexcept { return ModInt(0) -= *this; }\r\n\tModInt operator +(const ModInt\
    \ & rhs) const noexcept { return ModInt(*this) += rhs; }\r\n\tModInt operator\
    \ -(const ModInt & rhs) const noexcept { return ModInt(*this) -= rhs; }\r\n\t\
    ModInt operator *(const ModInt & rhs) const noexcept { return ModInt(*this) *=\
    \ rhs; }\r\n\tModInt operator /(const ModInt & rhs) const noexcept { return ModInt(*this)\
    \ /= rhs; }\r\n\t\r\n\tModInt & operator +=(const ModInt & rhs) noexcept {\r\n\
    \t\tval += rhs.val;\r\n\t\tif (val >= M) val -= M;\r\n\t\treturn *this;\r\n\t\
    }\r\n\tModInt & operator -=(const ModInt & rhs) noexcept {\r\n\t\tif (val < rhs.val)\
    \ val += M;\r\n\t\tval -= rhs.val;\r\n\t\treturn *this;\r\n\t}\r\n\tModInt & operator\
    \ *=(const ModInt & rhs) noexcept {\r\n\t\tval = val * rhs.val % M;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\tModInt & operator /=(const ModInt & rhs) noexcept {\r\n\t\
    \t*this *= rhs.inverse();\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tModInt pow(value_type\
    \ n) const {\r\n\t\tModInt res = 1, x = val;\r\n\t\tif (n < 0) { x = x.inverse();\
    \ n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x; x *= x; n >>= 1; }\r\n\t\t\
    return res;\r\n\t}\r\n\t\r\n\tModInt inverse() const {\r\n\t\tlong long a = val,\
    \ a1 = 1, a2 = 0, b = M, b1 = 0, b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type\
    \ q = a / b, r = a % b;\r\n\t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q *\
    \ b2;\r\n\t\t\ta = b; b = r;\r\n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2\
    \ = nb2;\r\n\t\t}\r\n\t\tassert(a == 1);\r\n\t\treturn a1;\r\n\t}\r\n\t\r\n\t\
    const value_type & get() const noexcept { return val; }\r\n\tstatic decltype(M)\
    \ get_mod() noexcept { return M; }\r\n\t\r\n\tfriend std::ostream & operator <<(std::ostream\
    \ & os, const ModInt & rhs) { return os << rhs.val; }\r\n\tfriend std::istream\
    \ & operator >>(std::istream & is, ModInt & rhs) {\r\n\t\tvalue_type x;\r\n\t\t\
    is >> x;\r\n\t\trhs = ModInt(x);\r\n\t\treturn is;\r\n\t}\r\nprivate:\r\n\tvalue_type\
    \ val;\r\n};\r\n\r\n\n#line 5 \"Test/SlidingWindowAggregation.test.cpp\"\n\r\n\
    #include <cstdio>\r\n#line 8 \"Test/SlidingWindowAggregation.test.cpp\"\n\r\n\
    int main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\tusing P = std::pair<mint, mint>;\r\n\t\r\n\tSlidingWindowAggregation<P> swag({1,\
    \ 0}, [](auto && x, auto && y) -> P {\r\n\t\treturn {x.first * y.first, x.second\
    \ * y.first + y.second };\r\n\t});\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\
    \tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\t\tswag.push({a, b});\r\n\t\t}\r\n\t\telse if (q == 1)\
    \ swag.pop();\r\n\t\telse {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\n\t\t\
    \tauto res = swag.fold_all();\r\n\t\t\tprintf(\"%lld\\n\", (res.first * x + res.second).get());\r\
    \n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include \"DataStructure/SlidingWindowAggregation.hpp\"\r\n#include \"\
    Mathematics/ModInt.hpp\"\r\n\r\n#include <cstdio>\r\n#include <utility>\r\n\r\n\
    int main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\tusing P = std::pair<mint, mint>;\r\n\t\r\n\tSlidingWindowAggregation<P> swag({1,\
    \ 0}, [](auto && x, auto && y) -> P {\r\n\t\treturn {x.first * y.first, x.second\
    \ * y.first + y.second };\r\n\t});\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\
    \tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\t\tswag.push({a, b});\r\n\t\t}\r\n\t\telse if (q == 1)\
    \ swag.pop();\r\n\t\telse {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\n\t\t\
    \tauto res = swag.fold_all();\r\n\t\t\tprintf(\"%lld\\n\", (res.first * x + res.second).get());\r\
    \n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/SlidingWindowAggregation.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:21:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/Test/SlidingWindowAggregation.test.cpp
- /verify/Test/SlidingWindowAggregation.test.cpp.html
title: Test/SlidingWindowAggregation.test.cpp
---
