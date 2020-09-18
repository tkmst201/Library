---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/PrimeNumber/enumerate_primes.hpp
    title: Mathematics/PrimeNumber/enumerate_primes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"Test/PrimeNumber.enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\n#line 1 \"Mathematics/PrimeNumber/enumerate_primes.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <algorithm>\r\n\r\
    \n/*\r\nlast-updated: 2020/09/08\r\n\r\n# \u4ED5\u69D8\r\nstd::vector<std::uint32_t>\
    \ enumerate_primes(std::uint32_t n) :\r\n\u6642\u9593\u8A08\u7B97\u91CF: O(n /\
    \ loglog n)\r\n\u7A7A\u9593\u8A08\u7B97\u91CF: \u7D20\u6570\u306E\u500B\u6570\
    \ + \u0398(n^(1/2))\r\n\r\nn \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u305F\u914D\u5217\u3092\u8FD4\u3059\r\n\u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9\u306E {2, 3, 5} \u306E\u500D\u6570\u3092\u9664\u3044\u305F\
    \u9AD8\u901F\u5316\u7248\r\n\r\n\r\n# \u53C2\u8003\r\nhttps://en.wikipedia.org/wiki/Sieve_of_Eratosthenes,\
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
    } // namespace tk\r\n\r\n\n#line 4 \"Test/PrimeNumber.enumerate_primes.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, A, B;\r\n\tscanf(\"%d\
    \ %d %d\", &N, &A, &B);\r\n\t\r\n\tauto primes = tk::enumerate_primes(N);\r\n\t\
    \r\n\tstd::vector<int> ans;\r\n\tfor (int i = 0, idx = B; idx < primes.size()\
    \ && primes[idx] <= N; ++i, idx += A)\r\n\t\tans.emplace_back(primes[idx]);\r\n\
    \t\r\n\tprintf(\"%d %d\\n\", primes.size(), ans.size());\r\n\tfor (int i = 0;\
    \ i < ans.size(); ++i) printf(\"%d%c\", ans[i], \" \\n\"[i + 1 == ans.size()]);\r\
    \n\t\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\
    \n#include \"Mathematics/PrimeNumber/enumerate_primes.hpp\"\r\n\r\n#include <cstdio>\r\
    \n\r\nint main() {\r\n\tint N, A, B;\r\n\tscanf(\"%d %d %d\", &N, &A, &B);\r\n\
    \t\r\n\tauto primes = tk::enumerate_primes(N);\r\n\t\r\n\tstd::vector<int> ans;\r\
    \n\tfor (int i = 0, idx = B; idx < primes.size() && primes[idx] <= N; ++i, idx\
    \ += A)\r\n\t\tans.emplace_back(primes[idx]);\r\n\t\r\n\tprintf(\"%d %d\\n\",\
    \ primes.size(), ans.size());\r\n\tfor (int i = 0; i < ans.size(); ++i) printf(\"\
    %d%c\", ans[i], \" \\n\"[i + 1 == ans.size()]);\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - Mathematics/PrimeNumber/enumerate_primes.hpp
  isVerificationFile: true
  path: Test/PrimeNumber.enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2020-09-08 16:59:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PrimeNumber.enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/Test/PrimeNumber.enumerate_primes.test.cpp
- /verify/Test/PrimeNumber.enumerate_primes.test.cpp.html
title: Test/PrimeNumber.enumerate_primes.test.cpp
---
