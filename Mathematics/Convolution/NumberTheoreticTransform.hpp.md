---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/Garner.hpp
    title: Mathematics/Garner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/NumberTheoreticTransform.test.cpp
    title: Test/NumberTheoreticTransform.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,
    - https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,
    - https://math314.hateblo.jp/entry/2015/05/07/014908,
  bundledCode: "#line 1 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\n\
    \n\n\r\n#include <vector>\r\n#include <utility>\r\n#include <cassert>\r\n\r\n\
    #line 1 \"Mathematics/Garner.hpp\"\n\n\n\r\n#line 6 \"Mathematics/Garner.hpp\"\
    \n\r\n/*\r\nlast-updated: 2020/07/27\r\n\r\n# \u89E3\u8AAC\r\nb: ( b_0, \\ldots,\
    \ b_{k-1} ), m: ( m_0, \\ldots, m_{k-1} ) \u306B\u5BFE\u3057\u3066\u3001\r\nx\
    \ \\equiv b_i (mod. m_i) (\\forall i) \u3068\u306A\u308B x \u3092 [0, lcm(m_0,\
    \ \\ldots, m_{k-1})) \u306E\u7BC4\u56F2\u3067\u6C42\u3081\u308B\u3002\r\n\u3053\
    \u306E\u3088\u3046\u306A x \u306F\u3001b_0 \\equiv \\dots \\equiv b_{k-1} (mod.\
    \ gcd(m_0, \\ldots, m_{k-1})) \u3067\u3042\u308B\u3068\u304D\u306E\u307F\u5B58\
    \u5728\u3057\u3001\u4E00\u610F\u3067\u3042\u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\
    \ntemplate<typename T>\r\nstatic bool preprocess(std::vector<T> &b, std::vector<T>\
    \ &m) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(k^2 log m (loglog m)) ? \u3053\u308C\
    \u3088\u308A\u5C0F\u3055\u3044\u6C17\u304C\u3059\u308B\u304C\u5206\u304B\u3089\
    \u305A\r\n\tm \u304C\u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u3068\u304D\u306B\
    \u9023\u7ACB\u5408\u540C\u5F0F\u306E\u540C\u5024\u5909\u5F62\u3092\u884C\u3044\
    \u3001\u4E92\u3044\u306B\u7D20\u306B\u5909\u5F62\u3059\u308B\u3002\r\n\t\u89E3\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F false \u3092\u8FD4\u3059\
    \r\n\r\ntemplate<typename T>\r\nstatic T garner(const std::vector<T> & b, std::vector<T>\
    \ m, const T &mod) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(k(k + log m))\r\n\t\
    m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\u304C\u5FC5\u8981\
    \r\n\t(x \\equiv b_i (mod. m_i) (\\forall i) \u3068\u306A\u308B x) modulo. mod\
    \ \u3092\u8FD4\u3059(m \u306F\u4E92\u3044\u306B\u7D20\u3088\u308A\u5FC5\u305A\u5B58\
    \u5728\u3059\u308B)\r\n\r\n\u4ED5\u69D8\r\n- T \u306F\u7B26\u53F7\u4ED8\u304D\u6574\
    \u6570\u3002\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/drken/items/ae02240cd1f8edfc86fd,\
    \ 2020/05/05\r\n*/\r\n\r\nstruct Garner {\r\npublic:\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\n\ttemplate<typename T>\r\n\tstatic bool preprocess(std::vector<T> &b,\
    \ std::vector<T> &m) {\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\
    \t\tfor (size_type j = 0; j < i; ++j) {\r\n\t\t\t\tT g = gcd(m[i], m[j]);\r\n\t\
    \t\t\tif ((b[i] - b[j]) % g) return false;\r\n\t\t\t\tm[i] /= g; m[j] /= g;\r\n\
    \t\t\t\t\r\n\t\t\t\tT gi = gcd(g, m[i]), gj = g / gi;\r\n\t\t\t\tdo {\r\n\t\t\t\
    \t\tg = gcd(gi, gj);\r\n\t\t\t\t\tgi *= g; gj /= g;\r\n\t\t\t\t} while (g != 1);\r\
    \n\t\t\t\t\r\n\t\t\t\tm[i] *= gi; m[j] *= gj;\r\n\t\t\t\tb[i] %= m[i]; b[j] %=\
    \ m[j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\t\r\n\ttemplate<typename\
    \ T>\r\n\tstatic T garner(const std::vector<T> &b, std::vector<T> m, const T mod)\
    \ {\r\n\t\tassert(b.size() == m.size());\r\n\t\tassert(!b.empty());\r\n\t\tT tg\
    \ = m[0];\r\n\t\tfor (size_type i = 0; i < b.size(); ++i) {\r\n\t\t\tassert(m[i]\
    \ > 0);\r\n\t\t\ttg = gcd(tg, m[i]);\r\n\t\t}\r\n\t\tassert(mod > 0);\r\n\t\t\
    assert(b.size() == 1 || tg == 1);\r\n\t\t\r\n\t\tm.emplace_back(mod);\r\n\t\t\
    std::vector<T> sum(m.size()), ip(m.size(), 1);\r\n\t\tfor (size_type i = 0; i\
    \ < b.size(); ++i) {\r\n\t\t\t/*\r\n\t\t\t\tip[j] := m_0 m_1 \\ldots m_{i-1} (mod.\
    \ m_j)\r\n\t\t\t\tsum[j] := t_0 ip[0]  t_1 ip[1]  \\ldots  t_{i-1} ip[i-1] (mod.\
    \ m_j)\r\n\t\t\t*/\r\n\t\t\tT t = ((b[i] % m[i] + m[i]) % m[i] - sum[i] + m[i])\
    \ % m[i] % m[i] * inverse(ip[i], m[i]) % m[i];\r\n\t\t\tfor (size_type j = i +\
    \ 1; j < m.size(); ++j) {\r\n\t\t\t\tsum[j] = (sum[j] + ip[j] * t) % m[j];\r\n\
    \t\t\t\tip[j] = (ip[j] * m[i] % m[j]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn sum.back();\r\
    \n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename T>\r\n\tstatic T gcd(T a, T b)\
    \ {\r\n\t\twhile (b > 0) {\r\n\t\t\tT nb = a % b;\r\n\t\t\ta = b;\r\n\t\t\tb =\
    \ nb;\r\n\t\t}\r\n\t\treturn a;\r\n\t}\r\n\t\r\n\ttemplate<typename T>\r\n\tstatic\
    \ T inverse(const T &a, const T &mod) {\r\n\t\tT a0 = (a % mod + mod) % mod, a1\
    \ = 1, a2 = 0;\r\n\t\tT b0 = mod, b1 = 0, b2 = 1;\r\n\t\twhile (b0 > 0) {\r\n\t\
    \t\tT q = a0 / b0;\r\n\t\t\tT nb0 = a0 % b0, nb1 = a1 - b1 * q, nb2 = a2 - b2\
    \ * q;\r\n\t\t\ta0 = b0; a1 = b1; a2 = b2;\r\n\t\t\tb0 = nb0; b1 = nb1; b2 = nb2;\r\
    \n\t\t}\r\n\t\tassert(a0 == 1);\r\n\t\treturn (a1 % mod + mod) % mod;\r\n\t}\r\
    \n};\r\n\r\n\n#line 9 \"Mathematics/Convolution/NumberTheoreticTransform.hpp\"\
    \n\r\n/*\r\nlast-updated: 2020/07/27\r\n\r\nstatic std::vector<value_type> multiply(\r\
    \n\tconst std::vector<value_type> &A,\r\n\tconst std::vector<value_type> &B,\r\
    \n\tvalue_type mod) : \r\n\t\r\n\tA, B \u306E\u7573\u307F\u8FBC\u307F modulo.\
    \ mod \u3092\u8FD4\u3059\r\n\t\r\n\tN = |A| + |B| \u4EE5\u4E0A\u306E\u6700\u5C0F\
    \u306E 2 \u51AA\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(N log N)\r\n\t\u5236\
    \u7D04:\r\n\t\tN \\leq 2^min(two_exps) ( N \u4E57\u6839\u3092\u6C42\u3081\u308B\
    \u305F\u3081)\r\n\t\t\u5404\u8981\u7D20\u306E\u6700\u5927\u5024\u3092 M \u3068\
    \u3057\u3066\u3001max(|A|, |B|) * M^2 \\leq \\prod mods (Garger \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\u3067\u5FA9\u5143\u3059\u308B\u305F\u3081)\r\n\r\n\u53C2\
    \u8003 :\r\nhttps://math314.hateblo.jp/entry/2015/05/07/014908, 2020/07/27\r\n\
    https://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,\
    \ 2020/07/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/07/27\r\n*/\r\n\r\nstruct NumberTheoreticTransform {\r\npublic:\r\n\tusing\
    \ value_type = long long;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tstatic\
    \ std::vector<value_type> multiply(const std::vector<value_type> &A, const std::vector<value_type>\
    \ &B, value_type mod) {\r\n\t\tstd::vector<value_type> mods;\r\n\t\tstd::vector<value_type>\
    \ primitive_roots;\r\n\t\tstd::vector<size_type> two_exps;\r\n\t\t// mods.emplace_back(998'244'353);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(23);\r\n\t\tmods.emplace_back(1'224'736'769);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(24);\r\n\t\tmods.emplace_back(469'762'049);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(26);\r\n\t\tmods.emplace_back(167'772'161);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(25);\r\n\t\t\r\n\t\t\
    std::vector<std::vector<value_type>> ntt_result;\r\n\t\tntt_result.reserve(mods.size());\r\
    \n\t\tfor (size_type i = 0; i < mods.size(); ++i) ntt_result.emplace_back(_multiply(A,\
    \ B, mods[i], primitive_roots[i], two_exps[i]));\r\n\t\t\r\n\t\tstd::vector<value_type>\
    \ res;\r\n\t\tres.reserve(ntt_result[0].size());\r\n\t\tstd::vector<value_type>\
    \ gar_b(mods.size());\r\n\t\tfor (size_type i = 0; i < ntt_result[0].size(); ++i)\
    \ {\r\n\t\t\tfor(size_type j = 0; j < mods.size(); ++j) gar_b[j] = ntt_result[j][i];\r\
    \n\t\t\tres.emplace_back(Garner::garner(gar_b, mods, mod));\r\n\t\t}\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic value_type mod_pow(value_type x, value_type\
    \ n, value_type mod) {\r\n\t\tvalue_type res = 1;\r\n\t\twhile (n > 0) {\r\n\t\
    \t\tif (n & 1) res = res * x % mod;\r\n\t\t\tx = x * x % mod;\r\n\t\t\tn >>= 1;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic value_type mod_inv(value_type\
    \ x, value_type mod) {\r\n\t\treturn mod_pow(x, mod - 2, mod);\r\n\t}\r\n\t\r\n\
    \tstatic std::vector<value_type> _multiply(const std::vector<value_type> &A, const\
    \ std::vector<value_type> &B, const value_type mod, const value_type primitive_root,\
    \ const size_type two_exp) {\r\n\t\tif (A.empty() || B.empty()) return {};\r\n\
    \t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n = 1;\r\n\t\twhile\
    \ (n < n_) n <<= 1;\r\n\t\tassert(1 << two_exp >= n);\r\n\t\tstd::vector<value_type>\
    \ a, b;\r\n\t\ta.reserve(n), b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size();\
    \ ++i) a.emplace_back((A[i] % mod + mod) % mod);\r\n\t\tfor (size_type i = 0;\
    \ i < B.size(); ++i) b.emplace_back((B[i] % mod + mod) % mod);\r\n\t\ta.resize(n);\
    \ ntt(a, mod, primitive_root);\r\n\t\tb.resize(n); ntt(b, mod, primitive_root);\r\
    \n\t\t\r\n\t\tconst value_type ninv = mod_inv(n, mod);\r\n\t\tfor (size_type i\
    \ = 0; i < n; ++i) a[i] = a[i] * b[i] % mod * ninv % mod;\r\n\t\tntt(a, mod, primitive_root,\
    \ true);\r\n\t\treturn a;\r\n\t}\r\n\t\r\n\tstatic void ntt(std::vector<value_type>\
    \ &A, const value_type mod, const value_type primitive_root, const bool inv =\
    \ false) {\r\n\t\tconst size_type N = A.size();\r\n\t\t\r\n\t\tvalue_type nroot\
    \ = mod_pow(primitive_root, (mod - 1) / N, mod);\r\n\t\tif (inv) nroot = mod_inv(nroot,\
    \ mod);\r\n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1) {\r\n\t\t\tconst\
    \ size_type m = n >> 1;\r\n\t\t\tstd::vector<value_type> omega;\r\n\t\t\tomega.reserve(m);\r\
    \n\t\t\tomega.emplace_back(1);\r\n\t\t\tfor (size_type i = 0; i < m; ++i) omega.emplace_back(omega.back()\
    \ * nroot % mod);\r\n\t\t\tvalue_type half = mod_pow(nroot, m, mod);\r\n\t\t\t\
    \r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type i =\
    \ p, ei = p + m; i < ei; ++i) {\r\n\t\t\t\t\tconst value_type a = A[i], b = A[i\
    \ + m];\r\n\t\t\t\t\tA[i] = (a + b) % mod;\r\n\t\t\t\t\tA[i + m] = (a + b * half\
    \ % mod + mod) * omega[i - p] % mod;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnroot =\
    \ nroot * nroot % mod;\r\n\t\t}\r\n\t\t\r\n\t\tbit_reverse(A);\r\n\t}\r\n\t\r\n\
    \tstatic void bit_reverse(std::vector<value_type> &A) {\r\n\t\tconst size_type\
    \ N = A.size();\r\n\t\tfor (size_type i = 1, j = 0; i < N - 1; ++i) {\r\n\t\t\t\
    for (size_type k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\tif (i < j) std::swap(A[i],\
    \ A[j]);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\n#define INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP\r\
    \n\r\n#include <vector>\r\n#include <utility>\r\n#include <cassert>\r\n\r\n#include\
    \ \"Mathematics/Garner.hpp\"\r\n\r\n/*\r\nlast-updated: 2020/07/27\r\n\r\nstatic\
    \ std::vector<value_type> multiply(\r\n\tconst std::vector<value_type> &A,\r\n\
    \tconst std::vector<value_type> &B,\r\n\tvalue_type mod) : \r\n\t\r\n\tA, B \u306E\
    \u7573\u307F\u8FBC\u307F modulo. mod \u3092\u8FD4\u3059\r\n\t\r\n\tN = |A| + |B|\
    \ \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(N log N)\r\n\t\u5236\u7D04:\r\n\t\tN \\leq 2^min(two_exps) ( N \u4E57\
    \u6839\u3092\u6C42\u3081\u308B\u305F\u3081)\r\n\t\t\u5404\u8981\u7D20\u306E\u6700\
    \u5927\u5024\u3092 M \u3068\u3057\u3066\u3001max(|A|, |B|) * M^2 \\leq \\prod\
    \ mods (Garger \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3067\u5FA9\u5143\u3059\
    \u308B\u305F\u3081)\r\n\r\n\u53C2\u8003 :\r\nhttps://math314.hateblo.jp/entry/2015/05/07/014908,\
    \ 2020/07/27\r\nhttps://ja.wikibooks.org/wiki/%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96/%E5%8E%9F%E5%A7%8B%E6%A0%B9%E3%81%A8%E6%8C%87%E6%95%B0,\
    \ 2020/07/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/stockham/cooley-tukey.html,\
    \ 2020/07/27\r\n*/\r\n\r\nstruct NumberTheoreticTransform {\r\npublic:\r\n\tusing\
    \ value_type = long long;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tstatic\
    \ std::vector<value_type> multiply(const std::vector<value_type> &A, const std::vector<value_type>\
    \ &B, value_type mod) {\r\n\t\tstd::vector<value_type> mods;\r\n\t\tstd::vector<value_type>\
    \ primitive_roots;\r\n\t\tstd::vector<size_type> two_exps;\r\n\t\t// mods.emplace_back(998'244'353);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(23);\r\n\t\tmods.emplace_back(1'224'736'769);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(24);\r\n\t\tmods.emplace_back(469'762'049);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(26);\r\n\t\tmods.emplace_back(167'772'161);\
    \ primitive_roots.emplace_back(3); two_exps.emplace_back(25);\r\n\t\t\r\n\t\t\
    std::vector<std::vector<value_type>> ntt_result;\r\n\t\tntt_result.reserve(mods.size());\r\
    \n\t\tfor (size_type i = 0; i < mods.size(); ++i) ntt_result.emplace_back(_multiply(A,\
    \ B, mods[i], primitive_roots[i], two_exps[i]));\r\n\t\t\r\n\t\tstd::vector<value_type>\
    \ res;\r\n\t\tres.reserve(ntt_result[0].size());\r\n\t\tstd::vector<value_type>\
    \ gar_b(mods.size());\r\n\t\tfor (size_type i = 0; i < ntt_result[0].size(); ++i)\
    \ {\r\n\t\t\tfor(size_type j = 0; j < mods.size(); ++j) gar_b[j] = ntt_result[j][i];\r\
    \n\t\t\tres.emplace_back(Garner::garner(gar_b, mods, mod));\r\n\t\t}\r\n\t\treturn\
    \ res;\r\n\t}\r\n\t\r\nprivate:\r\n\tstatic value_type mod_pow(value_type x, value_type\
    \ n, value_type mod) {\r\n\t\tvalue_type res = 1;\r\n\t\twhile (n > 0) {\r\n\t\
    \t\tif (n & 1) res = res * x % mod;\r\n\t\t\tx = x * x % mod;\r\n\t\t\tn >>= 1;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstatic value_type mod_inv(value_type\
    \ x, value_type mod) {\r\n\t\treturn mod_pow(x, mod - 2, mod);\r\n\t}\r\n\t\r\n\
    \tstatic std::vector<value_type> _multiply(const std::vector<value_type> &A, const\
    \ std::vector<value_type> &B, const value_type mod, const value_type primitive_root,\
    \ const size_type two_exp) {\r\n\t\tif (A.empty() || B.empty()) return {};\r\n\
    \t\tsize_type n_ = A.size() + B.size() - 1;\r\n\t\tsize_type n = 1;\r\n\t\twhile\
    \ (n < n_) n <<= 1;\r\n\t\tassert(1 << two_exp >= n);\r\n\t\tstd::vector<value_type>\
    \ a, b;\r\n\t\ta.reserve(n), b.reserve(n);\r\n\t\tfor (size_type i = 0; i < A.size();\
    \ ++i) a.emplace_back((A[i] % mod + mod) % mod);\r\n\t\tfor (size_type i = 0;\
    \ i < B.size(); ++i) b.emplace_back((B[i] % mod + mod) % mod);\r\n\t\ta.resize(n);\
    \ ntt(a, mod, primitive_root);\r\n\t\tb.resize(n); ntt(b, mod, primitive_root);\r\
    \n\t\t\r\n\t\tconst value_type ninv = mod_inv(n, mod);\r\n\t\tfor (size_type i\
    \ = 0; i < n; ++i) a[i] = a[i] * b[i] % mod * ninv % mod;\r\n\t\tntt(a, mod, primitive_root,\
    \ true);\r\n\t\treturn a;\r\n\t}\r\n\t\r\n\tstatic void ntt(std::vector<value_type>\
    \ &A, const value_type mod, const value_type primitive_root, const bool inv =\
    \ false) {\r\n\t\tconst size_type N = A.size();\r\n\t\t\r\n\t\tvalue_type nroot\
    \ = mod_pow(primitive_root, (mod - 1) / N, mod);\r\n\t\tif (inv) nroot = mod_inv(nroot,\
    \ mod);\r\n\t\t\r\n\t\tfor (size_type n = N; n > 1; n >>= 1) {\r\n\t\t\tconst\
    \ size_type m = n >> 1;\r\n\t\t\tstd::vector<value_type> omega;\r\n\t\t\tomega.reserve(m);\r\
    \n\t\t\tomega.emplace_back(1);\r\n\t\t\tfor (size_type i = 0; i < m; ++i) omega.emplace_back(omega.back()\
    \ * nroot % mod);\r\n\t\t\tvalue_type half = mod_pow(nroot, m, mod);\r\n\t\t\t\
    \r\n\t\t\tfor (size_type p = 0; p < N; p += n) {\r\n\t\t\t\tfor (size_type i =\
    \ p, ei = p + m; i < ei; ++i) {\r\n\t\t\t\t\tconst value_type a = A[i], b = A[i\
    \ + m];\r\n\t\t\t\t\tA[i] = (a + b) % mod;\r\n\t\t\t\t\tA[i + m] = (a + b * half\
    \ % mod + mod) * omega[i - p] % mod;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tnroot =\
    \ nroot * nroot % mod;\r\n\t\t}\r\n\t\t\r\n\t\tbit_reverse(A);\r\n\t}\r\n\t\r\n\
    \tstatic void bit_reverse(std::vector<value_type> &A) {\r\n\t\tconst size_type\
    \ N = A.size();\r\n\t\tfor (size_type i = 1, j = 0; i < N - 1; ++i) {\r\n\t\t\t\
    for (size_type k = N >> 1; k > (j ^= k); k >>= 1);\r\n\t\t\tif (i < j) std::swap(A[i],\
    \ A[j]);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_NUMBER_THEORETIC_TRANSFORM_HPP"
  dependsOn:
  - Mathematics/Garner.hpp
  isVerificationFile: false
  path: Mathematics/Convolution/NumberTheoreticTransform.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/NumberTheoreticTransform.test.cpp
documentation_of: Mathematics/Convolution/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/Mathematics/Convolution/NumberTheoreticTransform.hpp
- /library/Mathematics/Convolution/NumberTheoreticTransform.hpp.html
title: Mathematics/Convolution/NumberTheoreticTransform.hpp
---
