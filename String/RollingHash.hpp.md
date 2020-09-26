---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/RollingHash.test.cpp
    title: Test/RollingHash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6#fnref1,
    - https://trap.jp/post/1036/,
  bundledCode: "#line 1 \"String/RollingHash.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/08/22\r\
    \n\r\nRolling Hash\r\nmod 2^61 - 1\r\n\u5B9F\u884C\u6642\u306B\u57FA\u6570(\u539F\
    \u59CB\u6839)\u3092\u30E9\u30F3\u30C0\u30E0\u751F\u6210\r\n\r\nTODO: basep \u3082\
    \u30AF\u30E9\u30B9\u5171\u901A\u306B\u3059\u308B(\u30C7\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u5B9F\u88C5\uFF1F)\r\n\r\n# \u4ED5\u69D8\r\nRollingHash(string_type s)\
    \ :\r\n\tbuild(s)\r\n\t\u57FA\u6570\u304C\u672A\u751F\u6210\u306A\u3089 set_base()\
    \ \u3067\u751F\u6210\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3057\
    \u305F\u6587\u5B57\u5217\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\r\n\r\nvoid\
    \ build(string_type s) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|s|)\r\n\t\
    \u6587\u5B57\u5217 s \u306E\u3059\u3079\u3066\u306E\u4F4D\u7F6E i \u306B\u3064\
    \u3044\u3066 s[0, i) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8A08\u7B97\u3059\
    \u308B\r\n\r\nuint64 hash(size_type i, size_type l, size_type r) const :\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\ti \u756A\u76EE\u306E\u57FA\u6570\
    \u3067\u8A08\u7B97\u3057\u305F s[l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\
    \u8FD4\u3059\r\n\r\nstd::vector<uint64> hash(size_type l, size_type r) const :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u5E33: \u0398(|base|)\r\n\t\u305D\u308C\u305E\u308C\
    \u306E\u57FA\u6570\u3067\u8A08\u7B97\u3057\u305F s[l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u306E\u914D\u5217\u3092\u8FD4\u3059\r\n\r\nbool match(size_type l1,\
    \ size_type r1, size_type l2, size_type r2) const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(|base|)\r\n\ts[l1, r1) \u3068 s[l2, r2) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u6BD4\u8F03\u3057\u3066\u4E00\u81F4\u3059\u308C\u3070 true\
    \ \u3092\u8FD4\u3059\r\n\r\nprivate:\r\nstatic void set_base() :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: ??(\u8EFD\u305D\u3046)\r\n\t\u57FA\u6570\u3092\u30BB\u30C3\
    \u30C8\u3059\u308B\r\n\tgen_cnt \u306E\u6570\u3060\u3051\u57FA\u6570\u3092\u30E9\
    \u30F3\u30C0\u30E0\u751F\u6210\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/keymoon/items/11fac5627672a6d6a9f6#fnref1,\
    \ 2020/08/22\r\nhttps://trap.jp/post/1036/, 2020/08/22\r\n*/\r\n\r\n#include <vector>\r\
    \n#include <string>\r\n#include <random>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n\r\nstruct RollingHash {\r\npublic:\r\n\tusing size_type = std::size_t;\r\
    \n\tusing string_type = std::string;\r\n\tusing uint64 = std::uint64_t;\r\n\t\r\
    \nprivate:\r\n\tstatic constexpr uint64 mod = (1ull << 61) - 1;\r\n\tstatic constexpr\
    \ uint64 mask31 = (1ull << 31) - 1;\r\n\tstatic constexpr uint64 mask30 = (1ull\
    \ << 30) - 1;\r\n\tstatic constexpr uint64 mask61 = (1ull << 61) - 1;\r\n\t\r\n\
    public:\r\n\tRollingHash(string_type s) {\r\n\t\tif (base().empty()) set_base();\r\
    \n\t\tbuild(s);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid build(string_type s) {\r\n\t\tn = s.size();\r\n\t\t\
    hashv.clear();\r\n\t\tbasep.clear();\r\n\t\tfor (size_type i = 0; i < base().size();\
    \ ++i) {\r\n\t\t\thashv.emplace_back();\r\n\t\t\tbasep.emplace_back();\r\n\t\t\
    \thashv[i].emplace_back(0);\r\n\t\t\tbasep[i].emplace_back(1);\r\n\t\t\tfor (size_type\
    \ j = 0; j < size(); ++j) {\r\n\t\t\t\tuint64 nh = mul(hashv[i].back(), base()[i])\
    \ + static_cast<uint64>(s[j]);\r\n\t\t\t\thashv[i].emplace_back(modulo(nh));\r\
    \n\t\t\t\tbasep[i].emplace_back(modulo(mul(basep[i].back(), base()[i])));\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tuint64 hash(size_type i, size_type l, size_type\
    \ r) const {\r\n\t\tassert(i < base().size());\r\n\t\tassert(l < r);\r\n\t\tassert(r\
    \ <= size());\r\n\t\treturn modulo((mod << 2) - mul(hashv[i][l], basep[i][r -\
    \ l]) + hashv[i][r]);\r\n\t}\r\n\t\r\n\tstd::vector<uint64> hash(size_type l,\
    \ size_type r) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\
    \tstd::vector<uint64> res;\r\n\t\tfor (size_type i = 0; i < base().size(); ++i)\
    \ res.emplace_back(hash(i, l, r));\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tbool match(size_type\
    \ l1, size_type r1, size_type l2, size_type r2) const {\r\n\t\tassert(l1 < r1);\r\
    \n\t\tassert(r1 <= size());\r\n\t\tassert(l2 < r2);\r\n\t\tassert(r2 <= size());\r\
    \n\t\tfor (size_type i = 0; i < base().size(); ++i) if (hash(i, l1, r1) != hash(i,\
    \ l2, r2)) return false;\r\n\t\treturn true;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tstd::vector<std::vector<uint64>> basep;\r\n\tstd::vector<std::vector<uint64>>\
    \ hashv; // [i][j] := hash(s[0..j-1]), use base[i]\r\n\t\r\n\tstatic std::vector<uint64>\
    \ & base() {\r\n\t\tstatic std::vector<uint64> base_;\r\n\t\treturn base_;\r\n\
    \t}\r\n\t\r\n\tstatic void set_base() {\r\n\t\tbase().emplace_back(100000001111);\r\
    \n\t\t// base().emplace_back(100000011200);\r\n\t\t// base().emplace_back(100000011000);\r\
    \n\t\t// base().emplace_back(100000014848);\r\n\t\t// base().emplace_back(100000015050);\r\
    \n\t\t\r\n\t\tauto rnd = std::bind(std::uniform_int_distribution<uint64>(2, mod\
    \ - 2), std::mt19937_64(std::random_device{}()));\r\n\t\tconstexpr size_type gen_cnt\
    \ = 1;\r\n\t\tfor (size_type i = 0; i < gen_cnt; ++i) {\r\n\t\t\twhile (true)\
    \ {\r\n\t\t\t\tuint64 k = rnd();\r\n\t\t\t\tif (gcd(k, mod - 1) != 1) continue;\r\
    \n\t\t\t\tuint64 cur = mod_pow(base()[0], k);\r\n\t\t\t\tif (cur < 10000000000)\
    \ continue;\r\n\t\t\t\tbase().emplace_back(cur);\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\t// x, y < mod => res < (mod << 2)\r\n\tstatic uint64\
    \ mul(uint64 x, uint64 y) {\r\n\t\tconst uint64 xu = x >> 31, xd = x & mask31;\r\
    \n\t\tconst uint64 yu = y >> 31, yd = y & mask31;\r\n\t\tconst uint64 t = xu *\
    \ yd + yu * xd;\r\n\t\tuint64 res = (xu * yu) << 1;\r\n\t\tres += (t >> 30) +\
    \ ((t & mask30) << 31);\r\n\t\tres += xd * yd;\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tstatic uint64 modulo(uint64 x) {\r\n\t\tconst uint64 sum = (x >> 61) + (x\
    \ & mask61);\r\n\t\treturn sum < mod ? sum : sum - mod;\r\n\t}\r\n\t\r\n\tstatic\
    \ uint64 mod_pow(uint64 x, uint64 n) {\r\n\t\tif (n == 0) return 1;\r\n\t\tuint64\
    \ res = mod_pow(modulo(mul(x, x)), n >> 1);\r\n\t\tif (n & 1) res = modulo(mul(res,\
    \ x));\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic uint64 gcd(uint64 x, uint64\
    \ y) {\r\n\t\twhile (y > 0) {\r\n\t\t\tuint64 t = y;\r\n\t\t\ty = x % y;\r\n\t\
    \t\tx = t;\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_ROLLING_HASH_HPP\r\n#define INCLUDE_GUARD_ROLLING_HASH_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/22\r\n\r\nRolling Hash\r\nmod 2^61 - 1\r\n\u5B9F\
    \u884C\u6642\u306B\u57FA\u6570(\u539F\u59CB\u6839)\u3092\u30E9\u30F3\u30C0\u30E0\
    \u751F\u6210\r\n\r\nTODO: basep \u3082\u30AF\u30E9\u30B9\u5171\u901A\u306B\u3059\
    \u308B(\u30C7\u30B9\u30C8\u30E9\u30AF\u30BF\u5B9F\u88C5\uFF1F)\r\n\r\n# \u4ED5\
    \u69D8\r\nRollingHash(string_type s) :\r\n\tbuild(s)\r\n\t\u57FA\u6570\u304C\u672A\
    \u751F\u6210\u306A\u3089 set_base() \u3067\u751F\u6210\r\n\r\nsize_type size()\
    \ const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u30CF\u30C3\
    \u30B7\u30E5\u3092\u8A08\u7B97\u3057\u305F\u6587\u5B57\u5217\u306E\u30B5\u30A4\
    \u30BA\u3092\u8FD4\u3059\r\n\r\nvoid build(string_type s) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(|s|)\r\n\t\u6587\u5B57\u5217 s \u306E\u3059\u3079\u3066\u306E\
    \u4F4D\u7F6E i \u306B\u3064\u3044\u3066 s[0, i) \u306E\u30CF\u30C3\u30B7\u30E5\
    \u5024\u3092\u8A08\u7B97\u3059\u308B\r\n\r\nuint64 hash(size_type i, size_type\
    \ l, size_type r) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    i \u756A\u76EE\u306E\u57FA\u6570\u3067\u8A08\u7B97\u3057\u305F s[l, r) \u306E\u30CF\
    \u30C3\u30B7\u30E5\u5024\u3092\u8FD4\u3059\r\n\r\nstd::vector<uint64> hash(size_type\
    \ l, size_type r) const :\r\n\t\u6642\u9593\u8A08\u7B97\u5E33: \u0398(|base|)\r\
    \n\t\u305D\u308C\u305E\u308C\u306E\u57FA\u6570\u3067\u8A08\u7B97\u3057\u305F s[l,\
    \ r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u306E\u914D\u5217\u3092\u8FD4\u3059\r\
    \n\r\nbool match(size_type l1, size_type r1, size_type l2, size_type r2) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|base|)\r\n\ts[l1, r1) \u3068\
    \ s[l2, r2) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6BD4\u8F03\u3057\u3066\
    \u4E00\u81F4\u3059\u308C\u3070 true \u3092\u8FD4\u3059\r\n\r\nprivate:\r\nstatic\
    \ void set_base() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: ??(\u8EFD\u305D\u3046\
    )\r\n\t\u57FA\u6570\u3092\u30BB\u30C3\u30C8\u3059\u308B\r\n\tgen_cnt \u306E\u6570\
    \u3060\u3051\u57FA\u6570\u3092\u30E9\u30F3\u30C0\u30E0\u751F\u6210\r\n\r\n# \u53C2\
    \u8003\r\nhttps://qiita.com/keymoon/items/11fac5627672a6d6a9f6#fnref1, 2020/08/22\r\
    \nhttps://trap.jp/post/1036/, 2020/08/22\r\n*/\r\n\r\n#include <vector>\r\n#include\
    \ <string>\r\n#include <random>\r\n#include <functional>\r\n#include <cassert>\r\
    \n\r\nstruct RollingHash {\r\npublic:\r\n\tusing size_type = std::size_t;\r\n\t\
    using string_type = std::string;\r\n\tusing uint64 = std::uint64_t;\r\n\t\r\n\
    private:\r\n\tstatic constexpr uint64 mod = (1ull << 61) - 1;\r\n\tstatic constexpr\
    \ uint64 mask31 = (1ull << 31) - 1;\r\n\tstatic constexpr uint64 mask30 = (1ull\
    \ << 30) - 1;\r\n\tstatic constexpr uint64 mask61 = (1ull << 61) - 1;\r\n\t\r\n\
    public:\r\n\tRollingHash(string_type s) {\r\n\t\tif (base().empty()) set_base();\r\
    \n\t\tbuild(s);\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn\
    \ n;\r\n\t}\r\n\t\r\n\tvoid build(string_type s) {\r\n\t\tn = s.size();\r\n\t\t\
    hashv.clear();\r\n\t\tbasep.clear();\r\n\t\tfor (size_type i = 0; i < base().size();\
    \ ++i) {\r\n\t\t\thashv.emplace_back();\r\n\t\t\tbasep.emplace_back();\r\n\t\t\
    \thashv[i].emplace_back(0);\r\n\t\t\tbasep[i].emplace_back(1);\r\n\t\t\tfor (size_type\
    \ j = 0; j < size(); ++j) {\r\n\t\t\t\tuint64 nh = mul(hashv[i].back(), base()[i])\
    \ + static_cast<uint64>(s[j]);\r\n\t\t\t\thashv[i].emplace_back(modulo(nh));\r\
    \n\t\t\t\tbasep[i].emplace_back(modulo(mul(basep[i].back(), base()[i])));\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tuint64 hash(size_type i, size_type l, size_type\
    \ r) const {\r\n\t\tassert(i < base().size());\r\n\t\tassert(l < r);\r\n\t\tassert(r\
    \ <= size());\r\n\t\treturn modulo((mod << 2) - mul(hashv[i][l], basep[i][r -\
    \ l]) + hashv[i][r]);\r\n\t}\r\n\t\r\n\tstd::vector<uint64> hash(size_type l,\
    \ size_type r) const {\r\n\t\tassert(l < r);\r\n\t\tassert(r <= size());\r\n\t\
    \tstd::vector<uint64> res;\r\n\t\tfor (size_type i = 0; i < base().size(); ++i)\
    \ res.emplace_back(hash(i, l, r));\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tbool match(size_type\
    \ l1, size_type r1, size_type l2, size_type r2) const {\r\n\t\tassert(l1 < r1);\r\
    \n\t\tassert(r1 <= size());\r\n\t\tassert(l2 < r2);\r\n\t\tassert(r2 <= size());\r\
    \n\t\tfor (size_type i = 0; i < base().size(); ++i) if (hash(i, l1, r1) != hash(i,\
    \ l2, r2)) return false;\r\n\t\treturn true;\r\n\t}\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tstd::vector<std::vector<uint64>> basep;\r\n\tstd::vector<std::vector<uint64>>\
    \ hashv; // [i][j] := hash(s[0..j-1]), use base[i]\r\n\t\r\n\tstatic std::vector<uint64>\
    \ & base() {\r\n\t\tstatic std::vector<uint64> base_;\r\n\t\treturn base_;\r\n\
    \t}\r\n\t\r\n\tstatic void set_base() {\r\n\t\tbase().emplace_back(100000001111);\r\
    \n\t\t// base().emplace_back(100000011200);\r\n\t\t// base().emplace_back(100000011000);\r\
    \n\t\t// base().emplace_back(100000014848);\r\n\t\t// base().emplace_back(100000015050);\r\
    \n\t\t\r\n\t\tauto rnd = std::bind(std::uniform_int_distribution<uint64>(2, mod\
    \ - 2), std::mt19937_64(std::random_device{}()));\r\n\t\tconstexpr size_type gen_cnt\
    \ = 1;\r\n\t\tfor (size_type i = 0; i < gen_cnt; ++i) {\r\n\t\t\twhile (true)\
    \ {\r\n\t\t\t\tuint64 k = rnd();\r\n\t\t\t\tif (gcd(k, mod - 1) != 1) continue;\r\
    \n\t\t\t\tuint64 cur = mod_pow(base()[0], k);\r\n\t\t\t\tif (cur < 10000000000)\
    \ continue;\r\n\t\t\t\tbase().emplace_back(cur);\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\t// x, y < mod => res < (mod << 2)\r\n\tstatic uint64\
    \ mul(uint64 x, uint64 y) {\r\n\t\tconst uint64 xu = x >> 31, xd = x & mask31;\r\
    \n\t\tconst uint64 yu = y >> 31, yd = y & mask31;\r\n\t\tconst uint64 t = xu *\
    \ yd + yu * xd;\r\n\t\tuint64 res = (xu * yu) << 1;\r\n\t\tres += (t >> 30) +\
    \ ((t & mask30) << 31);\r\n\t\tres += xd * yd;\r\n\t\treturn res;\r\n\t}\r\n\t\
    \r\n\tstatic uint64 modulo(uint64 x) {\r\n\t\tconst uint64 sum = (x >> 61) + (x\
    \ & mask61);\r\n\t\treturn sum < mod ? sum : sum - mod;\r\n\t}\r\n\t\r\n\tstatic\
    \ uint64 mod_pow(uint64 x, uint64 n) {\r\n\t\tif (n == 0) return 1;\r\n\t\tuint64\
    \ res = mod_pow(modulo(mul(x, x)), n >> 1);\r\n\t\tif (n & 1) res = modulo(mul(res,\
    \ x));\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic uint64 gcd(uint64 x, uint64\
    \ y) {\r\n\t\twhile (y > 0) {\r\n\t\t\tuint64 t = y;\r\n\t\t\ty = x % y;\r\n\t\
    \t\tx = t;\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_ROLLING_HASH_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/RollingHash.test.cpp
documentation_of: String/RollingHash.hpp
layout: document
redirect_from:
- /library/String/RollingHash.hpp
- /library/String/RollingHash.hpp.html
title: String/RollingHash.hpp
---
