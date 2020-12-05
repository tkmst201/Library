---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SlidingWindowAggregation.hpp
    title: DataStructure/SlidingWindowAggregation.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/ModInt.hpp
    title: Mathematics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \nlast-updated: 2020/11/20\r\n\r\n\u81EA\u52D5\u3067 mod \u3092\u53D6\u3063\u3066\
    \u304F\u308C\u308B\u4FBF\u5229\u306A\u3082\u306E\r\n\r\n# \u4ED5\u69D8\r\n\u57FA\
    \u672C\u7684\u306A\u6F14\u7B97\u306F\u3060\u3044\u305F\u3044\u5BFE\u5FDC\u3057\
    \u3066\u3044\u308B\u3002\r\n\u6A19\u6E96\u5165\u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0 std::cin, std::cout \u306B\u3082\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\
    \r\n\r\nconstexpr ModInt(std::int_fast64_t val = 0)\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\u305F\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nconstexpr static decltype(M)\
    \ mod() noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M\
    \ \u3092\u8FD4\u3059\r\n\r\nconstexpr const value_type & val() noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5024\u3092 int \u3067\u8FD4\u3059\r\
    \n\r\nconstexpr ModInt pow(std::int_fast64_t n) const noexcept\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(log n)\r\n\t\u5236\u7D04: n < 0 \u306E\u3068\u304D\u3001\
    inv() \u306E\u5236\u7D04\u306B\u5F93\u3046\u3002\r\n\tn \u4E57\u3057\u305F\u5024\
    \u3092\u8FD4\u3059(n < 0 \u306B\u3082\u5BFE\u5FDC)\r\n\r\nconstexpr ModInt inv()\
    \ const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log M)\r\n\t\u5236\u7D04\
    : \u5024\u3068 M \u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B(M \u304C\u7D20\u6570\u306A\u3089\u554F\u984C\u306F\u306A\u3044)\u3002\
    \r\n\t\u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\r\n\
    # \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n*/\r\
    \n\r\n#line 40 \"Mathematics/ModInt.hpp\"\n#include <iostream>\r\n#line 42 \"\
    Mathematics/ModInt.hpp\"\n\r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M\
    \ > 0);\r\n\t\r\npublic:\r\n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\
    \n\t\r\nprivate:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val < 0 ? (val % M + M) % M : val % M) {}\r\n\tconstexpr const\
    \ value_type & val() const noexcept { return val_; }\r\n\tconstexpr static decltype(M)\
    \ mod() noexcept { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const\
    \ noexcept { return val_; }\r\n\tconstexpr bool operator !() const noexcept {\
    \ return !static_cast<bool>(*this); }\r\n\tconstexpr ModInt operator +() const\
    \ noexcept { return ModInt(*this); }\r\n\tconstexpr ModInt operator -() const\
    \ noexcept { return ModInt(-val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept\
    \ { ModInt res = *this; ++*this; return res; }\r\n\tconstexpr ModInt operator\
    \ --(int) noexcept { ModInt res = *this; --*this; return res; }\r\n\tconstexpr\
    \ ModInt & operator ++() noexcept { val_ = val_ + 1 == M ? 0 : val_ + 1; return\
    \ *this; }\r\n\tconstexpr ModInt & operator --() noexcept { val_ = val_ == 0 ?\
    \ M - 1 : val_ - 1; return *this; }\r\n\tconstexpr ModInt & operator +=(const\
    \ ModInt & rhs) noexcept { val_ += val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ -\
    \ M; return *this; }\r\n\tconstexpr ModInt & operator -=(const ModInt & rhs) noexcept\
    \ { val_ += val_ >= rhs.val_ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\t\
    constexpr ModInt & operator *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_)\
    \ * rhs.val_ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt\
    \ & rhs) noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt\
    \ operator +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const\
    \ ModInt & rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr\
    \ ModInt operator *(const ModInt & lhs, const ModInt & rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\r\n\tfriend constexpr ModInt operator /(const ModInt &\
    \ lhs, const ModInt & rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend\
    \ constexpr bool operator ==(const ModInt & lhs, const ModInt & rhs) noexcept\
    \ { return lhs.val_ == rhs.val_; }\r\n\tfriend constexpr bool operator !=(const\
    \ ModInt & lhs, const ModInt & rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend\
    \ std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os\
    \ << rhs.val_; }\r\n\tfriend std::istream & operator >>(std::istream & is, ModInt\
    \ & rhs) { calc_type x; is >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr\
    \ ModInt pow(calc_type n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\
    \t\tif (n < 0) { x = x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x;\
    \ x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv()\
    \ const noexcept {\r\n\t\tvalue_type a = val_, a1 = 1, a2 = 0, b = M, b1 = 0,\
    \ b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q = a / b, r = a % b;\r\n\
    \t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\n\t\t\ta = b; b = r;\r\
    \n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/SlidingWindowAggregation.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 8 \"Test/SlidingWindowAggregation.test.cpp\"\n\
    \r\nint main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\
    \n\tusing P = std::pair<mint, mint>;\r\n\t\r\n\tSlidingWindowAggregation<P> swag({1,\
    \ 0}, [](auto && x, auto && y) -> P {\r\n\t\treturn {x.first * y.first, x.second\
    \ * y.first + y.second };\r\n\t});\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\
    \tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint a, b;\r\n\t\t\tscanf(\"\
    %d %d\", &a, &b);\r\n\t\t\tswag.push({a, b});\r\n\t\t}\r\n\t\telse if (q == 1)\
    \ swag.pop();\r\n\t\telse {\r\n\t\t\tint x;\r\n\t\t\tscanf(\"%d\", &x);\r\n\t\t\
    \tauto res = swag.fold_all();\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\
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
    \tauto res = swag.fold_all();\r\n\t\t\tprintf(\"%d\\n\", (res.first * x + res.second).val());\r\
    \n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/SlidingWindowAggregation.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 23:55:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/Test/SlidingWindowAggregation.test.cpp
- /verify/Test/SlidingWindowAggregation.test.cpp.html
title: Test/SlidingWindowAggregation.test.cpp
---
