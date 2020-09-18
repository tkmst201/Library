---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/PrimeNumber/enumerate_primes.hpp
    title: Mathematics/PrimeNumber/enumerate_primes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://math314.hateblo.jp/entry/2016/06/05/004332,
  bundledCode: "#line 1 \"Mathematics/PrimeNumber/prime_sum.hpp\"\n\n\n\r\n#include\
    \ <cstdint>\r\n#include <vector>\r\n#include <algorithm>\r\n\r\n#line 1 \"Mathematics/PrimeNumber/enumerate_primes.hpp\"\
    \n\n\n\r\n#line 7 \"Mathematics/PrimeNumber/enumerate_primes.hpp\"\n\r\n/*\r\n\
    last-updated: 2020/09/08\r\n\r\n# \u4ED5\u69D8\r\nstd::vector<std::uint32_t> enumerate_primes(std::uint32_t\
    \ n) :\r\n\u6642\u9593\u8A08\u7B97\u91CF: O(n / loglog n)\r\n\u7A7A\u9593\u8A08\
    \u7B97\u91CF: \u7D20\u6570\u306E\u500B\u6570 + \u0398(n^(1/2))\r\n\r\nn \u4EE5\
    \u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u914D\u5217\
    \u3092\u8FD4\u3059\r\n\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\
    \ {2, 3, 5} \u306E\u500D\u6570\u3092\u9664\u3044\u305F\u9AD8\u901F\u5316\u7248\
    \r\n\r\n\r\n# \u53C2\u8003\r\nhttps://en.wikipedia.org/wiki/Sieve_of_Eratosthenes,\
    \ 2020/09/07\r\nhttps://qiita.com/peria/items/a4ff4ddb3336f7b81d50, 2020/09/08\r\
    \n*/\r\n\r\nnamespace tk {\r\nstd::vector<std::uint32_t> enumerate_primes(std::uint32_t\
    \ n) {\r\n\tif (n < 2) return {};\r\n\tusing byte = std::uint8_t;\r\n\tusing uint32\
    \ = std::uint32_t;\r\n\t\r\n\tconstexpr byte m[8] = {1, 7, 11, 13, 17, 19, 23,\
    \ 29};\r\n\tconstexpr byte diff[8] = {6, 4, 2, 4, 2, 4, 6, 2}; // [i] := m[i +\
    \ 1] - m[i]\r\n\tconstexpr byte plus_byte[8][8] = {\r\n\t\t{0,0,0,0,0,0,0,1},{1,1,1,0,1,1,1,1},{2,2,0,2,0,2,2,1},{3,1,1,2,1,1,3,1},\r\
    \n\t\t{3,3,1,2,1,3,3,1},{4,2,2,2,2,2,4,1},{5,3,1,4,1,3,5,1},{6,4,2,4,2,4,6,1},\r\
    \n\t}; // [i][j] := floor(m_i m_{j+1} / 30) - floor(m_i m_j / 30)\r\n\tconstexpr\
    \ byte bit_mask[8][8] = {\r\n\t\t{254,253,251,247,239,223,191,127},{253,223,239,254,127,247,251,191},\r\
    \n\t\t{251,239,254,191,253,127,247,223},{247,254,191,223,251,253,127,239},\r\n\
    \t\t{239,127,253,251,223,191,254,247},{223,247,127,253,191,254,239,251},\r\n\t\
    \t{191,251,247,127,254,239,223,253},{127,191,223,239,247,251,253,254},\r\n\t};\
    \ // [i][j] := ((1<<8)-1) - (1 << to_m_idx(m[i]m[j] (mod. 30))) (mod. 8))\r\n\t\
    \r\n\tauto pop_count = [](byte x) {\r\n\t\tbyte res = (x & 0x55) + (x >> 1 & 0x55);\r\
    \n\t\tres = (res & 0x33) + (res >> 2 & 0x33);\r\n\t\tres = (res + (res >> 4))\
    \ & 0xf;\r\n\t\treturn res;\r\n\t};\r\n\t\r\n\tauto sqrt = [](uint32 n) {\r\n\t\
    \tuint32 res = 0;\r\n\t\tfor (uint32 i = sizeof(n) << 2; i > 0; --i) {\r\n\t\t\
    \tuint32 x = res + (1u << (i - 1));\r\n\t\t\tif (x * x <= n) res |= 1u << (i -\
    \ 1);\r\n\t\t}\r\n\t\treturn res;\r\n\t};\r\n\t\r\n\tbyte b_idx[129]; // [1 <<\
    \ i] = i\r\n\tfor (uint32 i = 0; i < 8; ++i) b_idx[1 << i] = i;\r\n\t\r\n\tauto\
    \ get_prime_pos = [&](uint32 n) {\r\n\t\tuint32 s = sqrt(n); // floor(sqrt(n))\r\
    \n\t\tconst uint32 s30 = s / 30 + (s % 30 != 0);\r\n\t\tconst uint32 n30 = n /\
    \ 30 + (n % 30 != 0);\r\n\t\t\r\n\t\tstd::vector<byte> isprime(n30, 255);\r\n\t\
    \tisprime[0] = 254;\r\n\t\tfor (uint32 i = 0; i < s30; ++i) {\r\n\t\t\tfor (byte\
    \ j = isprime[i]; j; j &= j - 1) {\r\n\t\t\t\tconst byte mi = b_idx[j & -j];\r\
    \n\t\t\t\tbyte k = mi;\r\n\t\t\t\tfor (uint32 b = (30*i + 2*m[mi])*i + m[mi]*m[mi]/30;\
    \ b < n30; b += i*diff[k] + plus_byte[mi][k], k = (k + 1) & 7)\r\n\t\t\t\t\tisprime[b]\
    \ &= bit_mask[mi][k];\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tfor (uint32 i = 8; i\
    \ > 0; --i) {\r\n\t\t\tif ((n30 - 1) * 30 + m[i - 1] <= n) break;\r\n\t\t\tisprime.back()\
    \ &= ~(1 << (i - 1));\r\n\t\t}\r\n\t\t\r\n\t\tuint32 cnt = 0;\r\n\t\tstd::vector<uint32>\
    \ prime_pos; // {byte} << 3 | {bit}\r\n\t\tfor (uint32 i = 0; i < n30; ++i) {\r\
    \n\t\t\tfor (uint32 j = isprime[i]; j; j &= j - 1) {\r\n\t\t\t\tprime_pos.emplace_back(i\
    \ << 3 | b_idx[j & -j]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn prime_pos;\r\n\t};\r\
    \n\t\r\n\tauto prime_pos = get_prime_pos(sqrt(n));\r\n\tconstexpr uint32 segment\
    \ = 1 << 18;\r\n\tstd::vector<uint32> pos;\r\n\tpos.reserve(prime_pos.size());\r\
    \n\tfor (uint32 i = 0; i < prime_pos.size(); ++i) {\r\n\t\tconst uint32 pb = prime_pos[i]\
    \ >> 3;\r\n\t\tconst byte mi = prime_pos[i] & 7;\r\n\t\tpos.emplace_back(((30*pb\
    \ + 2*m[mi])*pb + m[mi]*m[mi]/30) << 3 | mi);\r\n\t}\r\n\t\r\n\tstd::vector<uint32>\
    \ primes;\r\n\tif (2 <= n) primes.emplace_back(2);\r\n\tif (3 <= n) primes.emplace_back(3);\r\
    \n\tif (5 <= n) primes.emplace_back(5);\r\n\t\r\n\tconst uint32 n30 = n / 30 +\
    \ (n % 30 != 0);\r\n\tstd::vector<uint32> isprime;\r\n\tfor (uint32 l = 0; l <\
    \ n30; l += segment) {\r\n\t\tconst uint32 d = std::min(segment, n30 - l);\r\n\
    \t\tconst uint32 r = l + d;\r\n\t\t\r\n\t\tisprime.assign(d, 255);\r\n\t\tif (l\
    \ == 0) isprime[0] = 254;\r\n\t\t\r\n\t\tfor (uint32 i = 0; i < prime_pos.size();\
    \ ++i) {\r\n\t\t\tconst uint32 pb = prime_pos[i] >> 3;\r\n\t\t\tconst byte mi\
    \ = prime_pos[i] & 7;\r\n\t\t\tuint32 b = pos[i] >> 3;\r\n\t\t\tbyte k = pos[i]\
    \ & 7;\r\n\t\t\twhile (b < d) {\r\n\t\t\t\tisprime[b] &= bit_mask[mi][k];\r\n\t\
    \t\t\tb += pb*diff[k] + plus_byte[mi][k];\r\n\t\t\t\tk = (k + 1) & 7;\r\n\t\t\t\
    }\r\n\t\t\tpos[i] = (b - d) << 3 | k;\r\n\t\t}\r\n\t\t\r\n\t\tfor (uint32 i =\
    \ 8; i > 0; --i) {\r\n\t\t\tif ((r - 1) * 30 + m[i - 1] <= n) break;\r\n\t\t\t\
    isprime.back() &= ~(1 << (i - 1));\r\n\t\t}\r\n\t\t\r\n\t\tfor (uint32 i = 0;\
    \ i < d; ++i) {\r\n\t\t\tfor (uint32 j = isprime[i]; j; j &= j - 1) primes.emplace_back((l\
    \ + i) * 30 + m[b_idx[j & -j]]);\r\n\t\t}\r\n\t}\r\n\treturn primes;\r\n}\r\n\
    } // namespace tk\r\n\r\n\n#line 9 \"Mathematics/PrimeNumber/prime_sum.hpp\"\n\
    \r\n/*\r\nlast-updated: 2020/09/07\r\n\r\nunverified \u3060\u304C\u3001\u307B\u3068\
    \u3093\u3069\u5B9F\u88C5\u304C\u540C\u3058 counting_primes \u3092 verify \u3057\
    \u3066\u3044\u308B\u306E\u3067\u307B\u307C\u6B63\u3057\u3044(\u3068\u601D\u3046\
    )\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nT prime_sum(std::uint64_t n)\
    \ :\r\ntemplate T: n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u5408\u8A08\u3092\u5165\
    \u308C\u308B\u578B\r\n\u6642\u9593\u8A08\u7B97\u91CF: O(n^(3/4))\r\n\u7A7A\u9593\
    \u8A08\u7B97\u91CF: \u0398(n^(1/2))\r\n\r\nn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\
    \u5408\u8A08\u3092\u8FD4\u3059\r\nn \\leq 10^11 \u306A\u3089 1 sec \u4EE5\u5185\
    \u306B\u6C42\u307E\u308B\r\n\r\n# \u89E3\u8AAC\r\n\u4EFB\u610F\u306E\u975E\u8CA0\
    \u6574\u6570 a, b, c \u306B\u5BFE\u3057\u3001floor(floor(a / b) / c) = floor(a\
    \ / (bc)) \u3068\u306A\u308B\u3002\r\n\u304A\u6C17\u6301\u3061:\r\n\ta / b \u3092\
    \u5C0F\u6570\u3067\u8003\u3048\u308B\u3068 floor((a / b) / c) \u306F c \\times\
    \ k \\leq a / b \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570 k \u3068\u4E00\
    \u81F4\u3059\u308B\u305F\u3081\u3001\u5C0F\u6570\u90E8\u5206\u306F\u7121\u8996\
    \u3067\u304D\u308B\u3002\r\n\t\u3057\u305F\u304C\u3063\u3066\u3001floor(floor(a\
    \ / b) / c) = floor((a / b) / c) = floor(a / (bc))\r\n\r\nfloor(n / i) (1 \\leq\
    \ i \\ leq n) \u306E\u53D6\u308A\u3046\u308B\u5024\u3092\u964D\u9806\u306B\u5217\
    \u6319\u3059\u308B\u8A71\r\n\tfloor(n / i) = floor(n / j) \u3068\u306A\u308B\u6700\
    \u5927\u306E j \u306F floor(n / floor(n / i)) \u3067\u3042\u308B\u3002\r\n\t\u3053\
    \u308C\u306F\u3001n = p_1 i + q_1 (0 \\leq q_1 < i), q_1 = p_2 p_1 + q_2 (0 \\\
    leq q_2 < p_1, q_2 \\leq q_1) \u3068\u5909\u5F62\u3057\u3066\u8A08\u7B97\u3059\
    \u308B\u3053\u3068\u306B\u3088\u3063\u3066\u5206\u304B\u308B\u3002\r\n\t\u2191\
    \ \u3082\u3063\u3068\u76F4\u611F\u7684\u306A\u8A3C\u660E\u304C\u307B\u3057\u3044\
    \r\n\r\n\u4EE5\u4E0B s := floor(sqrt(n)) \u3068\u3059\u308B\u3002\r\n\r\n\u6574\
    \u6570 i (1 \\leq i < s) \u3067\u306F floor(n / i) - 1 \\geq floor(n / (i + 1))\
    \ \u3067\u3042\u308B\u3002\r\n\tn / i - (n / (i + 1)) = n / i(i + 1) ...(1) \u3067\
    \u3042\u308B\u304C\u3001 i(i + 1) < s^2 \\leq n \u306A\u306E\u3067 (1) \u5F0F\u306F\
    \ 1 \u4EE5\u4E0A\u3067\u3042\u308B\u3002\r\n\t\u5DEE\u304C 1 \u4EE5\u4E0A\u3042\
    \u308C\u3070 floor \u3092\u53D6\u3063\u3066\u3082 1 \u4EE5\u4E0A\u306E\u5DEE\u304C\
    \u3067\u308B\u3053\u3068\u304B\u3089\u5206\u304B\u308B\u3002\r\n\r\n1 \\leq a\
    \ \\leq s \u306E\u3068\u304D\u3001b = floor(n / a) \u3068\u304A\u304F\u3068 b\
    \ \\geq s \u3067\u3042\u308A\u3001a = floor(n / b) \u3068\u306A\u308B\u3002\r\n\
    \tb \\leq s \u3068\u4EEE\u5B9A\u3059\u308B\u3068 ab \\leq n \u306F\u5FC5\u305A\
    \u6210\u308A\u7ACB\u3064\u306E\u3067 b \\geq s \u3068\u5206\u304B\u308B\u3002\r\
    \n\tb \u306F ai \\leq n \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570 i \u3067\
    \u3042\u308B\u3053\u3068\u304B\u3089 a(b + 1) > n <=> n - ab < a \u304C\u6210\u308A\
    \u7ACB\u3064\u3002\r\n\t\u5148\u7A0B\u306E\u7D50\u679C\u3088\u308A a \\leq b \u3068\
    \u5206\u304B\u308B\u306E\u3067 n - ab < b \u3067\u3042\u308B\u3002\r\n\tab \\\
    leq n \u3068\u4F75\u305B\u3066 a = floor(n / b) \u3068\u5206\u304B\u308B\u3002\
    \r\n\r\nfloor(n / i) (1 \\leq i \\leq n) \u304C\u53D6\u308B\u5024\r\n\ts < a \\\
    leq n \u306E\u3068\u304D\u3001floor(n / a) < s \u3067\u3042\u308B\u306E\u3067\u5148\
    \u7A0B\u306E\u7D50\u679C\u3092\u7528\u3044\u308B\u3068\u3001\r\n\t1 \\leq j \\\
    leq s \u306B\u3064\u3044\u3066\u3001j \u3068 floor(n / j) \u3092\u96C6\u3081\u305F\
    \u96C6\u5408\u304C floor(n / i) (1 \\leq i \\leq n) \u304C\u53D6\u308B\u5024\u306E\
    \u96C6\u5408\u3068\u4E00\u81F4\u3059\u308B\u3002\r\n\u2191 \u3053\u306E\u53D6\u308B\
    \u5024\u306E\u96C6\u5408\u3092 div \u3068\u3059\u308B\r\n\r\ndiv \u306E\u8981\u7D20\
    \u304B\u3089 div \u306E index \u3092\u6C42\u3081\u308B\u65B9\u6CD5\r\n\t\u3053\
    \u308C\u307E\u3067\u306E\u7D50\u679C\u3092\u7528\u3044\u308B\u3068\u6B21\u306E\
    \u3088\u3046\u306B\u6C42\u3081\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \r\n\tk \\in div \u306E\u3068\u304D\u3001\r\n\t\tk \\leq s \u306A\u3089 div[k\
    \ - 1] = k\r\n\t\tk > s \u306A\u3089 div[div.size() - n / k] = k\r\n\t\r\n# \u53C2\
    \u8003\r\nhttps://math314.hateblo.jp/entry/2016/06/05/004332, 2020/09/07\r\n*/\r\
    \n\r\nnamespace tk {\r\ntemplate<typename T>\r\nT prime_sum(std::uint64_t n) {\r\
    \n\tif (n == 0) return 0;\r\n\tusing uint32 = std::uint32_t;\r\n\tusing uint64\
    \ = std::uint64_t;\r\n\t\r\n\tuint32 s = 0; // floor(sqrt(n))\r\n\tfor (uint32\
    \ i = 32; i > 0; --i) {\r\n\t\tuint64 x = s + (1u << (i - 1));\r\n\t\tif (x *\
    \ x <= n) s |= 1u << (i - 1);\r\n\t}\r\n\t\r\n\tstd::vector<uint64> div;\r\n\t\
    div.reserve(2 * s);\r\n\t{\r\n\t\tuint64 l = 1;\r\n\t\twhile (l <= n) {\r\n\t\t\
    \tdiv.emplace_back(n / l);\r\n\t\t\tl = n / div.back() + 1;\r\n\t\t}\r\n\t}\r\n\
    \tstd::reverse(begin(div), end(div));\r\n\t\r\n\tauto primes = enumerate_primes(s);\r\
    \n\tstd::vector<T> sum(primes.size() + 1, 0);\r\n\tfor (uint32 i = 0; i < primes.size();\
    \ ++i) sum[i + 1] += primes[i];\r\n\t\r\n\tstd::vector<T> dp; // [i]([j]) := S(div[i],\
    \ j)\r\n\tfor (auto d : div) {\r\n\t\tif (d & 1) dp.emplace_back(static_cast<T>(d)\
    \ * ((d + 1) / 2) - 1);\r\n\t\telse dp.emplace_back(static_cast<T>(d / 2) * (d\
    \ + 1) - 1);\r\n\t}\r\n\t\r\n\tfor (uint32 j = 0; j < primes.size(); ++j) {\r\n\
    \t\tfor (uint32 i = div.size(); i > 0; --i) {\r\n\t\t\tconst uint64 m = div[i\
    \ - 1];\r\n\t\t\tif (static_cast<uint64>(primes[j]) * primes[j] > m) break;\r\n\
    \t\t\tconst uint64 d = m / primes[j];\r\n\t\t\tconst uint32 idx = d <= s ? d -\
    \ 1 : div.size() - n / d;\r\n\t\t\tdp[i - 1] -= (dp[idx] - sum[j]) * primes[j];\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\treturn dp.back();\r\n}\r\n} // namespace tk\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PRIME_SUM_HPP\r\n#define INCLUDE_GUARD_PRIME_SUM_HPP\r\
    \n\r\n#include <cstdint>\r\n#include <vector>\r\n#include <algorithm>\r\n\r\n\
    #include \"Mathematics/PrimeNumber/enumerate_primes.hpp\"\r\n\r\n/*\r\nlast-updated:\
    \ 2020/09/07\r\n\r\nunverified \u3060\u304C\u3001\u307B\u3068\u3093\u3069\u5B9F\
    \u88C5\u304C\u540C\u3058 counting_primes \u3092 verify \u3057\u3066\u3044\u308B\
    \u306E\u3067\u307B\u307C\u6B63\u3057\u3044(\u3068\u601D\u3046)\r\n\r\n# \u4ED5\
    \u69D8\r\ntemplate<typename T>\r\nT prime_sum(std::uint64_t n) :\r\ntemplate T:\
    \ n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u5408\u8A08\u3092\u5165\u308C\u308B\u578B\
    \r\n\u6642\u9593\u8A08\u7B97\u91CF: O(n^(3/4))\r\n\u7A7A\u9593\u8A08\u7B97\u91CF\
    : \u0398(n^(1/2))\r\n\r\nn \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u5408\u8A08\u3092\
    \u8FD4\u3059\r\nn \\leq 10^11 \u306A\u3089 1 sec \u4EE5\u5185\u306B\u6C42\u307E\
    \u308B\r\n\r\n# \u89E3\u8AAC\r\n\u4EFB\u610F\u306E\u975E\u8CA0\u6574\u6570 a,\
    \ b, c \u306B\u5BFE\u3057\u3001floor(floor(a / b) / c) = floor(a / (bc)) \u3068\
    \u306A\u308B\u3002\r\n\u304A\u6C17\u6301\u3061:\r\n\ta / b \u3092\u5C0F\u6570\u3067\
    \u8003\u3048\u308B\u3068 floor((a / b) / c) \u306F c \\times k \\leq a / b \u3068\
    \u306A\u308B\u6700\u5927\u306E\u6574\u6570 k \u3068\u4E00\u81F4\u3059\u308B\u305F\
    \u3081\u3001\u5C0F\u6570\u90E8\u5206\u306F\u7121\u8996\u3067\u304D\u308B\u3002\
    \r\n\t\u3057\u305F\u304C\u3063\u3066\u3001floor(floor(a / b) / c) = floor((a /\
    \ b) / c) = floor(a / (bc))\r\n\r\nfloor(n / i) (1 \\leq i \\ leq n) \u306E\u53D6\
    \u308A\u3046\u308B\u5024\u3092\u964D\u9806\u306B\u5217\u6319\u3059\u308B\u8A71\
    \r\n\tfloor(n / i) = floor(n / j) \u3068\u306A\u308B\u6700\u5927\u306E j \u306F\
    \ floor(n / floor(n / i)) \u3067\u3042\u308B\u3002\r\n\t\u3053\u308C\u306F\u3001\
    n = p_1 i + q_1 (0 \\leq q_1 < i), q_1 = p_2 p_1 + q_2 (0 \\leq q_2 < p_1, q_2\
    \ \\leq q_1) \u3068\u5909\u5F62\u3057\u3066\u8A08\u7B97\u3059\u308B\u3053\u3068\
    \u306B\u3088\u3063\u3066\u5206\u304B\u308B\u3002\r\n\t\u2191 \u3082\u3063\u3068\
    \u76F4\u611F\u7684\u306A\u8A3C\u660E\u304C\u307B\u3057\u3044\r\n\r\n\u4EE5\u4E0B\
    \ s := floor(sqrt(n)) \u3068\u3059\u308B\u3002\r\n\r\n\u6574\u6570 i (1 \\leq\
    \ i < s) \u3067\u306F floor(n / i) - 1 \\geq floor(n / (i + 1)) \u3067\u3042\u308B\
    \u3002\r\n\tn / i - (n / (i + 1)) = n / i(i + 1) ...(1) \u3067\u3042\u308B\u304C\
    \u3001 i(i + 1) < s^2 \\leq n \u306A\u306E\u3067 (1) \u5F0F\u306F 1 \u4EE5\u4E0A\
    \u3067\u3042\u308B\u3002\r\n\t\u5DEE\u304C 1 \u4EE5\u4E0A\u3042\u308C\u3070 floor\
    \ \u3092\u53D6\u3063\u3066\u3082 1 \u4EE5\u4E0A\u306E\u5DEE\u304C\u3067\u308B\u3053\
    \u3068\u304B\u3089\u5206\u304B\u308B\u3002\r\n\r\n1 \\leq a \\leq s \u306E\u3068\
    \u304D\u3001b = floor(n / a) \u3068\u304A\u304F\u3068 b \\geq s \u3067\u3042\u308A\
    \u3001a = floor(n / b) \u3068\u306A\u308B\u3002\r\n\tb \\leq s \u3068\u4EEE\u5B9A\
    \u3059\u308B\u3068 ab \\leq n \u306F\u5FC5\u305A\u6210\u308A\u7ACB\u3064\u306E\
    \u3067 b \\geq s \u3068\u5206\u304B\u308B\u3002\r\n\tb \u306F ai \\leq n \u3068\
    \u306A\u308B\u6700\u5927\u306E\u6574\u6570 i \u3067\u3042\u308B\u3053\u3068\u304B\
    \u3089 a(b + 1) > n <=> n - ab < a \u304C\u6210\u308A\u7ACB\u3064\u3002\r\n\t\u5148\
    \u7A0B\u306E\u7D50\u679C\u3088\u308A a \\leq b \u3068\u5206\u304B\u308B\u306E\u3067\
    \ n - ab < b \u3067\u3042\u308B\u3002\r\n\tab \\leq n \u3068\u4F75\u305B\u3066\
    \ a = floor(n / b) \u3068\u5206\u304B\u308B\u3002\r\n\r\nfloor(n / i) (1 \\leq\
    \ i \\leq n) \u304C\u53D6\u308B\u5024\r\n\ts < a \\leq n \u306E\u3068\u304D\u3001\
    floor(n / a) < s \u3067\u3042\u308B\u306E\u3067\u5148\u7A0B\u306E\u7D50\u679C\u3092\
    \u7528\u3044\u308B\u3068\u3001\r\n\t1 \\leq j \\leq s \u306B\u3064\u3044\u3066\
    \u3001j \u3068 floor(n / j) \u3092\u96C6\u3081\u305F\u96C6\u5408\u304C floor(n\
    \ / i) (1 \\leq i \\leq n) \u304C\u53D6\u308B\u5024\u306E\u96C6\u5408\u3068\u4E00\
    \u81F4\u3059\u308B\u3002\r\n\u2191 \u3053\u306E\u53D6\u308B\u5024\u306E\u96C6\u5408\
    \u3092 div \u3068\u3059\u308B\r\n\r\ndiv \u306E\u8981\u7D20\u304B\u3089 div \u306E\
    \ index \u3092\u6C42\u3081\u308B\u65B9\u6CD5\r\n\t\u3053\u308C\u307E\u3067\u306E\
    \u7D50\u679C\u3092\u7528\u3044\u308B\u3068\u6B21\u306E\u3088\u3046\u306B\u6C42\
    \u3081\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\r\n\tk \\in div \u306E\u3068\
    \u304D\u3001\r\n\t\tk \\leq s \u306A\u3089 div[k - 1] = k\r\n\t\tk > s \u306A\u3089\
    \ div[div.size() - n / k] = k\r\n\t\r\n# \u53C2\u8003\r\nhttps://math314.hateblo.jp/entry/2016/06/05/004332,\
    \ 2020/09/07\r\n*/\r\n\r\nnamespace tk {\r\ntemplate<typename T>\r\nT prime_sum(std::uint64_t\
    \ n) {\r\n\tif (n == 0) return 0;\r\n\tusing uint32 = std::uint32_t;\r\n\tusing\
    \ uint64 = std::uint64_t;\r\n\t\r\n\tuint32 s = 0; // floor(sqrt(n))\r\n\tfor\
    \ (uint32 i = 32; i > 0; --i) {\r\n\t\tuint64 x = s + (1u << (i - 1));\r\n\t\t\
    if (x * x <= n) s |= 1u << (i - 1);\r\n\t}\r\n\t\r\n\tstd::vector<uint64> div;\r\
    \n\tdiv.reserve(2 * s);\r\n\t{\r\n\t\tuint64 l = 1;\r\n\t\twhile (l <= n) {\r\n\
    \t\t\tdiv.emplace_back(n / l);\r\n\t\t\tl = n / div.back() + 1;\r\n\t\t}\r\n\t\
    }\r\n\tstd::reverse(begin(div), end(div));\r\n\t\r\n\tauto primes = enumerate_primes(s);\r\
    \n\tstd::vector<T> sum(primes.size() + 1, 0);\r\n\tfor (uint32 i = 0; i < primes.size();\
    \ ++i) sum[i + 1] += primes[i];\r\n\t\r\n\tstd::vector<T> dp; // [i]([j]) := S(div[i],\
    \ j)\r\n\tfor (auto d : div) {\r\n\t\tif (d & 1) dp.emplace_back(static_cast<T>(d)\
    \ * ((d + 1) / 2) - 1);\r\n\t\telse dp.emplace_back(static_cast<T>(d / 2) * (d\
    \ + 1) - 1);\r\n\t}\r\n\t\r\n\tfor (uint32 j = 0; j < primes.size(); ++j) {\r\n\
    \t\tfor (uint32 i = div.size(); i > 0; --i) {\r\n\t\t\tconst uint64 m = div[i\
    \ - 1];\r\n\t\t\tif (static_cast<uint64>(primes[j]) * primes[j] > m) break;\r\n\
    \t\t\tconst uint64 d = m / primes[j];\r\n\t\t\tconst uint32 idx = d <= s ? d -\
    \ 1 : div.size() - n / d;\r\n\t\t\tdp[i - 1] -= (dp[idx] - sum[j]) * primes[j];\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\treturn dp.back();\r\n}\r\n} // namespace tk\r\n\r\n\
    #endif // INCLUDE_GUARD_PRIME_SUM_HPP"
  dependsOn:
  - Mathematics/PrimeNumber/enumerate_primes.hpp
  isVerificationFile: false
  path: Mathematics/PrimeNumber/prime_sum.hpp
  requiredBy: []
  timestamp: '2020-09-08 16:59:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/PrimeNumber/prime_sum.hpp
layout: document
redirect_from:
- /library/Mathematics/PrimeNumber/prime_sum.hpp
- /library/Mathematics/PrimeNumber/prime_sum.hpp.html
title: Mathematics/PrimeNumber/prime_sum.hpp
---
