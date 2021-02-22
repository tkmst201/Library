---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/MathUtility.hpp
    title: Mathematics/MathUtility.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
    title: Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Garner.test.cpp
    title: Test/Garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform_AnyMod.test.cpp
    title: Test/NumberTheoreticTransform_AnyMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/drken/items/ae02240cd1f8edfc86fd,
  bundledCode: "#line 1 \"Mathematics/Garner.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/09/21\r\
    \n\r\n# \u89E3\u8AAC\r\nb: ( b_0, \\ldots, b_{k-1} ), m: ( m_0, \\ldots, m_{k-1}\
    \ ) \u306B\u5BFE\u3057\u3066\u3001\r\nx \\equiv b_i (mod. m_i) (\\forall i) \u3068\
    \u306A\u308B x \u3092 [0, lcm(m_0, \\ldots, m_{k-1})) \u306E\u7BC4\u56F2\u3067\
    \u6C42\u3081\u308B\u3002\r\n\u3053\u306E\u3088\u3046\u306A x \u306F\u3001b_0 \\\
    equiv \\dots \\equiv b_{k-1} (mod. gcd(m_0, \\ldots, m_{k-1})) \u3067\u3042\u308B\
    \u3068\u304D\u306E\u307F\u5B58\u5728\u3057\u3001\u4E00\u610F\u3067\u3042\u308B\
    \u3002\r\n\r\ngarner \u306E\u8A08\u7B97\u9014\u4E2D\u306F O(m^2) \u7A0B\u5EA6\u307E\
    \u3067\u5024\u304C\u5927\u304D\u304F\u306A\u308B\u306E\u3067 overflow \u306B\u6CE8\
    \u610F\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename T>\r\nstatic bool preprocess(std::vector<T>\
    \ &b, std::vector<T> &m) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(k^2 log m (loglog\
    \ m)) ? \u3053\u308C\u3088\u308A\u5C0F\u3055\u3044\u6C17\u304C\u3059\u308B\u304C\
    \u5206\u304B\u3089\u305A\r\n\tm \u304C\u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\
    \u3068\u304D\u306B\u9023\u7ACB\u5408\u540C\u5F0F\u306E\u540C\u5024\u5909\u5F62\
    \u3092\u884C\u3044\u3001\u4E92\u3044\u306B\u7D20\u306B\u5909\u5F62\u3059\u308B\
    \u3002\r\n\t\u89E3\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F false\
    \ \u3092\u8FD4\u3059\r\n\t\u8A08\u7B97\u904E\u7A0B\u3067\u306F m \u306F\u5C0F\u3055\
    \u304F\u306A\u308B\u65B9\u5411\u306B\u3057\u304B\u5909\u5316\u3057\u306A\u3044\
    \u305F\u3081 overflow \u3059\u308B\u3053\u3068\u306F\u306A\u3044\r\n\r\ntemplate<typename\
    \ T>\r\nstatic T garner(const std::vector<T> & b, std::vector<T> m, const T &mod)\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(k(k + log m))\r\n\tm \u306F\u4E92\u3044\
    \u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\u5FC5\u8981\r\n\t(x \\equiv b_i\
    \ (mod. m_i) (\\forall i) \u3068\u306A\u308B x) modulo. mod \u3092\u8FD4\u3059\
    (m \u306F\u4E92\u3044\u306B\u7D20\u3088\u308A\u5FC5\u305A\u5B58\u5728\u3059\u308B\
    )\r\n\t\u8A08\u7B97\u904E\u7A0B\u3067 m^2 \u7A0B\u5EA6\u307E\u3067\u5024\u304C\
    \u5927\u304D\u304F\u306A\u308B\r\n\r\n\u4ED5\u69D8\r\n- T \u306F\u7B26\u53F7\u4ED8\
    \u304D\u6574\u6570\u3002\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/drken/items/ae02240cd1f8edfc86fd,\
    \ 2020/05/05\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\n#include\
    \ <Mathematics/MathUtility.hpp>\r\n\r\nstruct Garner {\r\npublic:\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic bool preprocess(std::vector<T>\
    \ &b, std::vector<T> &m) {\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\
    \n\t\t\tfor (size_type j = 0; j < i; ++j) {\r\n\t\t\t\tT g = tk::gcd(m[i], m[j]);\r\
    \n\t\t\t\tif ((b[i] - b[j]) % g) return false;\r\n\t\t\t\tm[i] /= g; m[j] /= g;\r\
    \n\t\t\t\t\r\n\t\t\t\tT gi = tk::gcd(g, m[i]), gj = g / gi;\r\n\t\t\t\tdo {\r\n\
    \t\t\t\t\tg = tk::gcd(gi, gj);\r\n\t\t\t\t\tgi *= g; gj /= g;\r\n\t\t\t\t} while\
    \ (g != 1);\r\n\t\t\t\t\r\n\t\t\t\tm[i] *= gi; m[j] *= gj;\r\n\t\t\t\tb[i] %=\
    \ m[i]; b[j] %= m[j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\
    \ttemplate<typename T>\r\n\tstatic T garner(const std::vector<T> &b, std::vector<T>\
    \ m, const T mod) {\r\n\t\tassert(b.size() == m.size());\r\n\t\tassert(!b.empty());\r\
    \n\t\tT tg = m[0];\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\t\t\
    assert(m[i] > 0);\r\n\t\t\ttg = tk::gcd(tg, m[i]);\r\n\t\t}\r\n\t\tassert(mod\
    \ > 0);\r\n\t\tassert(b.size() == 1 || tg == 1);\r\n\t\t\r\n\t\tm.emplace_back(mod);\r\
    \n\t\tstd::vector<T> sum(m.size()), ip(m.size(), 1);\r\n\t\tfor (size_type i =\
    \ 0; i < b.size(); ++i) {\r\n\t\t\t/*\r\n\t\t\t\tip[j] := m_0 m_1 \\ldots m_{i-1}\
    \ (mod. m_j)\r\n\t\t\t\tsum[j] := t_0 ip[0]  t_1 ip[1]  \\ldots  t_{i-1} ip[i-1]\
    \ (mod. m_j)\r\n\t\t\t*/\r\n\t\t\tif (m[i] == 1) continue;\r\n\t\t\tT t = ((b[i]\
    \ % m[i] + m[i]) % m[i] - sum[i] + m[i]) % m[i] * tk::mod_inv(ip[i], m[i]) % m[i];\r\
    \n\t\t\tfor (size_type j = i + 1; j < m.size(); ++j) {\r\n\t\t\t\tsum[j] = (sum[j]\
    \ + ip[j] * t) % m[j];\r\n\t\t\t\tip[j] = (ip[j] * m[i] % m[j]);\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn sum.back();\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_GARNER_HPP\r\n#define INCLUDE_GUARD_GARNER_HPP\r\n\r\
    \n/*\r\nlast-updated: 2020/09/21\r\n\r\n# \u89E3\u8AAC\r\nb: ( b_0, \\ldots, b_{k-1}\
    \ ), m: ( m_0, \\ldots, m_{k-1} ) \u306B\u5BFE\u3057\u3066\u3001\r\nx \\equiv\
    \ b_i (mod. m_i) (\\forall i) \u3068\u306A\u308B x \u3092 [0, lcm(m_0, \\ldots,\
    \ m_{k-1})) \u306E\u7BC4\u56F2\u3067\u6C42\u3081\u308B\u3002\r\n\u3053\u306E\u3088\
    \u3046\u306A x \u306F\u3001b_0 \\equiv \\dots \\equiv b_{k-1} (mod. gcd(m_0, \\\
    ldots, m_{k-1})) \u3067\u3042\u308B\u3068\u304D\u306E\u307F\u5B58\u5728\u3057\u3001\
    \u4E00\u610F\u3067\u3042\u308B\u3002\r\n\r\ngarner \u306E\u8A08\u7B97\u9014\u4E2D\
    \u306F O(m^2) \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\u308B\
    \u306E\u3067 overflow \u306B\u6CE8\u610F\r\n\r\n# \u4ED5\u69D8\r\ntemplate<typename\
    \ T>\r\nstatic bool preprocess(std::vector<T> &b, std::vector<T> &m) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(k^2 log m (loglog m)) ? \u3053\u308C\u3088\u308A\u5C0F\
    \u3055\u3044\u6C17\u304C\u3059\u308B\u304C\u5206\u304B\u3089\u305A\r\n\tm \u304C\
    \u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u3068\u304D\u306B\u9023\u7ACB\u5408\
    \u540C\u5F0F\u306E\u540C\u5024\u5909\u5F62\u3092\u884C\u3044\u3001\u4E92\u3044\
    \u306B\u7D20\u306B\u5909\u5F62\u3059\u308B\u3002\r\n\t\u89E3\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F false \u3092\u8FD4\u3059\r\n\t\u8A08\u7B97\
    \u904E\u7A0B\u3067\u306F m \u306F\u5C0F\u3055\u304F\u306A\u308B\u65B9\u5411\u306B\
    \u3057\u304B\u5909\u5316\u3057\u306A\u3044\u305F\u3081 overflow \u3059\u308B\u3053\
    \u3068\u306F\u306A\u3044\r\n\r\ntemplate<typename T>\r\nstatic T garner(const\
    \ std::vector<T> & b, std::vector<T> m, const T &mod) :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(k(k + log m))\r\n\tm \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\u304C\u5FC5\u8981\r\n\t(x \\equiv b_i (mod. m_i) (\\forall\
    \ i) \u3068\u306A\u308B x) modulo. mod \u3092\u8FD4\u3059(m \u306F\u4E92\u3044\
    \u306B\u7D20\u3088\u308A\u5FC5\u305A\u5B58\u5728\u3059\u308B)\r\n\t\u8A08\u7B97\
    \u904E\u7A0B\u3067 m^2 \u7A0B\u5EA6\u307E\u3067\u5024\u304C\u5927\u304D\u304F\u306A\
    \u308B\r\n\r\n\u4ED5\u69D8\r\n- T \u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3002\
    \r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/drken/items/ae02240cd1f8edfc86fd,\
    \ 2020/05/05\r\n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\n#include\
    \ <Mathematics/MathUtility.hpp>\r\n\r\nstruct Garner {\r\npublic:\r\n\tusing size_type\
    \ = std::size_t;\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic bool preprocess(std::vector<T>\
    \ &b, std::vector<T> &m) {\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\
    \n\t\t\tfor (size_type j = 0; j < i; ++j) {\r\n\t\t\t\tT g = tk::gcd(m[i], m[j]);\r\
    \n\t\t\t\tif ((b[i] - b[j]) % g) return false;\r\n\t\t\t\tm[i] /= g; m[j] /= g;\r\
    \n\t\t\t\t\r\n\t\t\t\tT gi = tk::gcd(g, m[i]), gj = g / gi;\r\n\t\t\t\tdo {\r\n\
    \t\t\t\t\tg = tk::gcd(gi, gj);\r\n\t\t\t\t\tgi *= g; gj /= g;\r\n\t\t\t\t} while\
    \ (g != 1);\r\n\t\t\t\t\r\n\t\t\t\tm[i] *= gi; m[j] *= gj;\r\n\t\t\t\tb[i] %=\
    \ m[i]; b[j] %= m[j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\
    \ttemplate<typename T>\r\n\tstatic T garner(const std::vector<T> &b, std::vector<T>\
    \ m, const T mod) {\r\n\t\tassert(b.size() == m.size());\r\n\t\tassert(!b.empty());\r\
    \n\t\tT tg = m[0];\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\t\t\
    assert(m[i] > 0);\r\n\t\t\ttg = tk::gcd(tg, m[i]);\r\n\t\t}\r\n\t\tassert(mod\
    \ > 0);\r\n\t\tassert(b.size() == 1 || tg == 1);\r\n\t\t\r\n\t\tm.emplace_back(mod);\r\
    \n\t\tstd::vector<T> sum(m.size()), ip(m.size(), 1);\r\n\t\tfor (size_type i =\
    \ 0; i < b.size(); ++i) {\r\n\t\t\t/*\r\n\t\t\t\tip[j] := m_0 m_1 \\ldots m_{i-1}\
    \ (mod. m_j)\r\n\t\t\t\tsum[j] := t_0 ip[0]  t_1 ip[1]  \\ldots  t_{i-1} ip[i-1]\
    \ (mod. m_j)\r\n\t\t\t*/\r\n\t\t\tif (m[i] == 1) continue;\r\n\t\t\tT t = ((b[i]\
    \ % m[i] + m[i]) % m[i] - sum[i] + m[i]) % m[i] * tk::mod_inv(ip[i], m[i]) % m[i];\r\
    \n\t\t\tfor (size_type j = i + 1; j < m.size(); ++j) {\r\n\t\t\t\tsum[j] = (sum[j]\
    \ + ip[j] * t) % m[j];\r\n\t\t\t\tip[j] = (ip[j] * m[i] % m[j]);\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn sum.back();\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_GARNER_HPP"
  dependsOn:
  - Mathematics/MathUtility.hpp
  isVerificationFile: false
  path: Mathematics/Garner.hpp
  requiredBy:
  - Mathematics/Convolution/NumberTheoreticTransform_AnyMod.hpp
  timestamp: '2020-09-21 16:44:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Garner.test.cpp
  - Test/NumberTheoreticTransform_AnyMod.test.cpp
documentation_of: Mathematics/Garner.hpp
layout: document
redirect_from:
- /library/Mathematics/Garner.hpp
- /library/Mathematics/Garner.hpp.html
title: Mathematics/Garner.hpp
---
