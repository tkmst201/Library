---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/SuffixArray.lcp.test.cpp
    title: Test/SuffixArray.lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SuffixArray.sa_is.test.cpp
    title: Test/SuffixArray.sa_is.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/SuffixArray.search.test.cpp
    title: Test/SuffixArray.search.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://blog.shibayu36.org/entry/2017/01/06/103956,
    - https://mametter.hatenablog.com/entry/20180130/p1,
    - https://niuez.hatenablog.com/entry/2019/12/16/203739,
    - https://qiita.com/flare/items/20439a1db54b367eea70,
  bundledCode: "#line 1 \"String/SuffixArray.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/08/25\r\
    \n\r\n# \u6982\u8981\r\nSuffixArray \u306E\u8A08\u7B97\u306F SA-IS: \u0398(|s|)\r\
    \nLCP \u914D\u5217\u306E\u8A08\u7B97\u306F Kasai&s's algorighm: \u0398(|s|)\r\n\
    \u6587\u5B57\u5217 p \u306E\u691C\u7D22\u306F LCP \u914D\u5217\u3092\u7528\u3044\
    \u305F\u4E8C\u5206\u63A2\u7D22: \u0398(|p| + log|s|)\r\n\r\n# \u4ED5\u69D8\r\n\
    SuffixArray(string_type s) :\r\n\tbuild(s)\r\n\r\nsize_type size() const noexcept\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6587\u5B57\u5217 s \u306E\
    \u5927\u304D\u3055 |s| \u3092\u8FD4\u3059\r\n\r\nconst std::vector<size_type>\
    \ & get_sa() const noexcept :\r\nconst std::vector<size_type> & get_lcp() const\
    \ noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8A08\u7B97\u6E08\
    \u307F\u306E sa, lcp \u3092\u305D\u308C\u305E\u308C\u8FD4\u3059\r\n\r\nvoid build(string_type\
    \ s) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|s|)\r\n\tSuffix Array \u306E\
    \u69CB\u7BC9 (\u0398(|s|)\r\n\tLongest Common Prefix \u914D\u5217\u306E\u8A08\u7B97\
    \ (\u0398(|s|))\r\n\r\nstd::pair<size_type, size_type> lower_bound(string_type\
    \ p) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|p| + log|s|)\r\n\t\u6587\
    \u5B57\u5217 s \u304B\u3089\u8F9E\u66F8\u9806\u3067\u6587\u5B57\u5217 p \u4EE5\
    \u4E0A\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306E suffix \u3092\u6C42\
    \u3081\u308B\r\n\t\u623B\u308A\u5024\u306F (\u5148\u982D\u4F4D\u7F6E\u3092\u8868\
    \u3059 sa \u306E index, lcp)\r\n\r\nsize_type search(string_type p) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|p| + log|s|)\r\n\t\u6587\u5B57\u5217\
    \ s \u304B\u3089\u6587\u5B57\u5217 p \u3092\u691C\u7D22\u3057\u3001\u305D\u306E\
    \u958B\u59CB index \u3092\u8FD4\u3059\r\n\t\u8907\u6570\u3042\u308C\u3070\u8F9E\
    \u66F8\u9806\u6700\u5C0F\u3068\u306A\u308B suffix \u306E index \u3092\u8FD4\u3059\
    \r\n\r\nstd::vector<size_type> search_all(string_type p) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(|p| + log|s| + (p \u306E\u51FA\u73FE\u6570))\r\n\t\u6587\
    \u5B57\u5217 s \u304B\u3089\u6587\u5B57\u5217 p \u3092\u691C\u7D22\u3057\u3001\
    \u51FA\u73FE\u4F4D\u7F6E\u3092\u5168\u3066\u8FD4\u3059(suffix \u306E\u8F9E\u66F8\
    \u5F0F\u9806\u5E8F)\r\n\r\n# \u89E3\u8AAC\r\n\u53C2\u8003\u30EA\u30F3\u30AF\u5148\
    \u3067\u306F\u3001LCP \u914D\u5217\u3092\u7528\u3044\u305F\u691C\u7D22\u306B lcp(s[sa[l..]],\
    \ s[sa[r..]]) \u3057\u304B\u4FDD\u6301\u3057\u3066\u3044\u306A\u3044\u3002\r\n\
    \u304A\u305D\u3089\u304F\u7247\u65B9(l)\u306E\u307F\u3067\u306F s = bbbbbbbb...,\
    \ p = bbbba \u307F\u305F\u3044\u306A\u5F62\u306E\u3068\u304D\u306B m \u3068 p\
    \ \u306E\u5358\u7D14\u6BD4\u8F03\u3067\u5408\u8A08 2|s| \u56DE\u7A0B\u5EA6\u306E\
    \u6BD4\u8F03\u304C\u767A\u751F\u3057\u305D\u3046(O(|s| + |p| + log|s|) \u306B\u306A\
    \u308B?)\r\n\u305D\u3053\u3067\u3001lplcp = lcp(s[sa[l..]], s[sa[r..]]), rplcp\
    \ = lcp(s[sa[l..]], s[sa[r..]]) \u306E 2 \u3064\u306E\u5024\u3092\u4FDD\u6301\u3057\
    \u3066\u8A08\u7B97\u3057\u3066\u3044\u308B\u3002\r\n\r\nlower_bound \u5185\u3067\
    \u306F\u3001(l, r] \u3068\u3057\u3066\u8A08\u7B97\u3092\u884C\u3063\u3066\u3044\
    \u3066\u3001\u521D\u671F\u5024\u306F l = -1 \u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u304C\u3001sa[0] \u306F\u7A7A\u6587\u5B57\u5217\u3092\u8868\u3059\
    \u306E\u3067 l = 0 \u3068\u3057\u3066\u826F\u3044\u3002\r\n\u307E\u305F\u3001\
    rplcp \u3092\u8A08\u7B97\u3059\u308B\u969B\u306B\u306F r \u306F sa \u306E\u6DFB\
    \u5B57\u7BC4\u56F2\u5185\u306B\u53CE\u307E\u3063\u3066\u3044\u306A\u3044\u3068\
    \u3044\u3051\u306A\u3044\u304C\u3001\u3069\u306E\u6587\u5B57\u5217\u3088\u308A\
    \u3082\u5927\u304D\u3044\u6587\u5B57\u5217\u304C\u6700\u5F8C\u306B\u5B58\u5728\
    \u3059\u308B\u3068\u8003\u3048\u308B\u3068\u53CE\u3081\u306A\u304F\u3066\u3082\
    \u826F\u3044\u3002\r\n\r\n\u5834\u5408\u5206\u3051\r\n\tlplcp < lmlcp\r\n\t\t\
    next: (m, r]\r\n\t\tlplcp, rplcp \u306F\u5909\u5316\u306A\u3057\r\n\t\r\n\tlplcp\
    \ > lmlcp\r\n\t\tnext: (l, m]\r\n\t\tlplcp \u306F\u5909\u5316\u306A\u3057\r\n\t\
    \trplcp \u306F lmlcp \u306B\u5909\u5316\r\n\t\t\t\u3082\u3068\u3082\u3068 rplcp\
    \ \\leq lmlcp \u3067\u3042\u308B\u306F\u305A\u306A\u306E\u3067 rplcp \u306F\u975E\
    \u6E1B\u5C11\r\n\t\r\n\trplcp < rmlcp\r\n\t\tnext: (l, m]\r\n\t\tlplcp, rplcp\
    \ \u306F\u5909\u5316\u306A\u3057\r\n\t\r\n\trplcp > rmlcp\r\n\t\tnext: (m, r]\r\
    \n\t\tlplcp \u306F rmlcp \u306B\u5909\u5316\r\n\t\t\t\u3082\u3068\u3082\u3068\
    \ lplcp \\leq rmlcp \u3067\u3042\u308B\u306F\u305A\u306A\u306E\u3067 lplcp \u306F\
    \u975E\u6E1B\u5C11\r\n\t\trplcp \u306F\u5909\u5316\u306A\u3057\r\n\t\r\n\tlplcp\
    \ = lmlcp \u304B\u3064 rmlcp = rplcp\r\n\t\tm \u306E lrlcp + 1 \u6587\u5B57\u76EE\
    (1-indexed) \u3068 p \u3092\u6BD4\u8F03\r\n\t\t\tmplcp = |p|\r\n\t\t\t\tnext:\
    \ (l, m]\r\n\t\t\t\trplcp \u306F mplcp (= |p|) \u306B\u5909\u5316\r\n\t\t\tm[mplcp]\
    \ < p[mplcp]\r\n\t\t\t\tnext: (m, r]\r\n\t\t\t\tlplcp \u306F mplcp \u306B\u5909\
    \u5316\r\n\t\t\tm[mplcp] > p[mplcp]\r\n\t\t\t\tnext: (l, m]\r\n\t\t\t\trplcp \u306F\
    \ mplcp \u306B\u5909\u5316\r\n\r\n# memo\r\nsa[l] < sa[r] \u3067 lcp(s[sa[l]..],\
    \ s[sa[r]..]) = min{lcp[sa[l]], lcp[sa[l] + 1], \\ldots, lcp[sa[r] - 1]}\r\nSparseTable\
    \ \u3092\u7528\u3044\u308C\u3070 \u69CB\u7BC9: \u0398(|s|log|s|), \u30AF\u30A8\
    \u30EA: \u0398(1)\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/flare/items/20439a1db54b367eea70,\
    \ 2020/08/23\r\nhttps://blog.shibayu36.org/entry/2017/01/06/103956, 2020/08/23\r\
    \nhttps://mametter.hatenablog.com/entry/20180130/p1, 2020/08/25\r\nhttps://niuez.hatenablog.com/entry/2019/12/16/203739,\
    \ 2020/08/25\r\n*/\r\n\r\n// #include <iostream>\r\n\r\n#include <string>\r\n\
    #include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\n\r\nstruct\
    \ SuffixArray {\r\n\tusing size_type = std::size_t;\r\n\tusing string_type = std::string;\r\
    \n\t\r\n\tSuffixArray(string_type s) {\r\n\t\tbuild(s);\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn s.size();\r\n\t}\r\n\t\r\n\tconst size_type\
    \ & operator[](size_type i) const noexcept {\r\n\t\treturn sa[i];\r\n\t}\r\n\t\
    \r\n\tconst size_type & at(size_type i) const {\r\n\t\tassert(i <= size());\r\n\
    \t\treturn (*this)[i];\r\n\t}\r\n\t\r\n\tconst std::vector<size_type> & get_sa()\
    \ const noexcept {\r\n\t\treturn sa;\r\n\t}\r\n\t\r\n\tconst std::vector<size_type>\
    \ & get_lcp() const noexcept {\r\n\t\treturn lcp;\r\n\t}\r\n\t\r\n\tvoid build(string_type\
    \ s) {\r\n\t\tthis->s = s;\r\n\t\tsa = sa_is(s);\r\n\t\trank.resize(size() + 1);\r\
    \n\t\tfor (size_type i = 0; i <= size(); ++i) rank[sa[i]] = i;\r\n\t\t\r\n\t\t\
    // LCP \u914D\u5217\u306E\u69CB\u7BC9\r\n\t\tlcp.resize(size());\r\n\t\tlcp[0]\
    \ = 0;\r\n\t\tsize_type mtc = 0;\r\n\t\t// lcp[i] := lcp(s[sa[i]], s[sa[i + 1])\r\
    \n\t\tfor (size_type i = 0; i < size(); ++i) {\r\n\t\t\t// lcp[rank[i]] = lcp(s[i..],\
    \ s[sa[rank[i] + 1])\r\n\t\t\tif (rank[i] == size()) continue;\r\n\t\t\tsize_type\
    \ k = sa[rank[i] + 1];\r\n\t\t\twhile (i + mtc < size() && k + mtc < size() &&\
    \ s[i + mtc] == s[k + mtc]) ++mtc;\r\n\t\t\tlcp[rank[i]] = mtc;\r\n\t\t\tif (mtc\
    \ > 0) --mtc;\r\n\t\t}\r\n\t\t\r\n\t\t// \u30BB\u30B0\u6728\u306E\u521D\u671F\u5316\
    \r\n\t\tseg_n = 1;\r\n\t\twhile (seg_n < size() + 1) seg_n <<= 1;\r\n\t\tseg.resize(seg_n\
    \ << 1);\r\n\t\tfor (size_type i = 0; i < size(); ++i) seg[i + seg_n] = lcp[i];\r\
    \n\t\tfor (size_type i = size(); i < seg_n; ++i) seg[i + seg_n] = 0;\r\n\t\tfor\
    \ (size_type i = seg_n - 1; i > 0; --i) seg[i] = std::min(seg[i << 1], seg[i <<\
    \ 1 | 1]);\r\n\t\t\r\n\t\t// debug \u51FA\u529B\r\n\t\t// for (size_type i = 0;\
    \ i <= size(); ++i) {\r\n\t\t// \tstd::cout << \"sa[\" << i << \"] = \" << sa[i]\
    \ << \"\\t, s[sa[i]..] = \" << s.substr(sa[i]);\r\n\t\t// \tif (i < size()) std::cout\
    \ << \"\\t\\t\\t lcp[i] = \" << lcp[i];\r\n\t\t// \tstd::cout << std::endl;\r\n\
    \t\t// }\r\n\t}\r\n\t\r\n\ttemplate<class S>\r\n\tstatic std::vector<size_type>\
    \ sa_is(S s, const size_type kind = 128) {\r\n\t\tsize_type n = s.size();\r\n\t\
    \tfor (size_type i = 0; i < n; ++i) ++s[i];\r\n\t\ts.push_back(0);\r\n\t\t\r\n\
    \t\tstd::vector<bool> Stype(n + 1); // true: S-type, false: L-type\r\n\t\tstd::vector<size_type>\
    \ lms; // LMS-index\r\n\t\tstd::vector<size_type> lms_map(n + 1, n + 1); // [i]\
    \ := \u3082\u3057 i \u304C LMS-index \u306A\u3089 lms \u914D\u5217\u306E index,\
    \ \u9055\u3048\u3070 n + 1\r\n\t\tstd::vector<size_type> bin(kind + 2); // [i]\
    \ := count_{j < i} (s[j] = j) => count(s[i] = i]) = bin[i + 1] - bin[i]\r\n\t\t\
    ++bin[1];\r\n\t\t\r\n\t\tStype[n] = true;\r\n\t\tfor (size_type i = n; i > 0;\
    \ --i) {\r\n\t\t\tStype[i - 1] = s[i - 1] == s[i] ? Stype[i] : s[i - 1] < s[i];\r\
    \n\t\t\t++bin[s[i - 1] + 1];\r\n\t\t}\r\n\t\tfor (size_type i = 1; i <= n; ++i)\
    \ {\r\n\t\t\tif (!Stype[i - 1] && Stype[i]) {\r\n\t\t\t\tlms_map[i] = lms.size();\r\
    \n\t\t\t\tlms.emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (size_type i = 0;\
    \ i < kind + 1; ++i) bin[i + 1] += bin[i];\r\n\t\t\r\n\t\tstd::vector<size_type>\
    \ sa, cnt;\r\n\t\t\r\n\t\tauto induce = [&](const std::vector<size_type> &lms)\
    \ {\r\n\t\t\tsa.assign(n + 1, 0);\r\n\t\t\t\r\n\t\t\tcnt.assign(kind + 1, 0);\r\
    \n\t\t\tfor (size_type i = lms.size(); i > 0; --i) {\r\n\t\t\t\tconst size_type\
    \ idx = lms[i - 1];\r\n\t\t\t\tconst size_type c = s[idx];\r\n\t\t\t\tsa[bin[c\
    \ + 1] - cnt[c] - 1] = idx;\r\n\t\t\t\t++cnt[c];\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\
    cnt.assign(kind + 1, 0);\r\n\t\t\tfor (size_type i = 0; i < n; ++i) {\r\n\t\t\t\
    \tif (sa[i] == 0) continue;\r\n\t\t\t\tconst size_type idx = sa[i] - 1;\r\n\t\t\
    \t\tif (!Stype[idx]) {\r\n\t\t\t\t\tconst size_type c = s[idx];\r\n\t\t\t\t\t\
    sa[bin[c] + cnt[c]] = idx;\r\n\t\t\t\t\t++cnt[c];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t\t\r\n\t\t\tcnt.assign(kind + 1, 0);\r\n\t\t\tfor (size_type i = n; i > 0; --i)\
    \ {\r\n\t\t\t\tif (sa[i] == 0) continue;\r\n\t\t\t\tconst size_type idx = sa[i]\
    \ - 1;\r\n\t\t\t\tif (Stype[idx]) {\r\n\t\t\t\t\tconst size_type c = s[idx];\r\
    \n\t\t\t\t\tsa[bin[c + 1] - 1 - cnt[c]] = idx;\r\n\t\t\t\t\t++cnt[c];\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t};\r\n\t\t\r\n\t\tinduce(lms);\r\n\t\t\r\n\t\tif (lms.size()\
    \ >= 2) {\r\n\t\t\tstd::vector<size_type> lms_str(lms.size() - 1); // [i] := lms\
    \ \u306E index i \u304C\u4F55\u756A\u76EE(0-indexed) \u306B\u5C0F\u3055\u3044\u304B\
    (\"$\" \u306F\u7121\u8996)\r\n\t\t\tsize_type pre = lms[lms_map[sa[0]]], pre_len\
    \ = 1, rank = 0;\r\n\t\t\tfor (size_type i = 1; i <= n; ++i) {\r\n\t\t\t\tconst\
    \ size_type lms_idx = lms_map[sa[i]]; // sa[i] \u304C LMS \u306A\u3089 lms \u306E\
    \ index, \u9055\u3048\u3070 n + 1\r\n\t\t\t\tif (lms_idx == n + 1) continue;\r\
    \n\t\t\t\tconst size_type idx = lms[lms_map[sa[i]]];\r\n\t\t\t\tconst size_type\
    \ len = lms[lms_idx + 1] - idx + 1;\r\n\t\t\t\t\r\n\t\t\t\t// LMS-substring \u306E\
    \ s[pre..] \u3068 s[idx..] \u3092\u6BD4\u8F03\r\n\t\t\t\tbool issame = pre_len\
    \ == len;\r\n\t\t\t\tif (issame) {\r\n\t\t\t\t\tfor (size_type j = 0; j < len;\
    \ ++j) {\r\n\t\t\t\t\t\tif (s[pre + j] != s[idx + j]) {\r\n\t\t\t\t\t\t\tissame\
    \ = false;\r\n\t\t\t\t\t\t\tbreak;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\
    }\r\n\t\t\t\trank += !issame;\r\n\t\t\t\tlms_str[lms_idx] = rank - 1;\r\n\t\t\t\
    \t\r\n\t\t\t\tpre = idx;\r\n\t\t\t\tpre_len = len;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\
    \tstd::vector<size_type> new_seed(lms.size());\r\n\t\t\tnew_seed[0] = sa[0];\r\
    \n\t\t\t\r\n\t\t\tif (rank == lms_str.size()) {\r\n\t\t\t\tfor (size_type i =\
    \ 0; i < lms_str.size(); ++i) new_seed[lms_str[i] + 1] = lms[i];\r\n\t\t\t}\r\n\
    \t\t\telse {\r\n\t\t\t\tstd::vector<size_type> lms_sa = sa_is(lms_str, rank);\r\
    \n\t\t\t\tfor (size_type i = 1; i < lms_sa.size(); ++i) new_seed[i] = lms[lms_sa[i]];\r\
    \n\t\t\t}\r\n\t\t\t\r\n\t\t\tinduce(new_seed);\r\n\t\t}\r\n\t\t\r\n\t\treturn\
    \ sa;\r\n\t}\r\n\t\r\n\tstd::pair<size_type, size_type> lower_bound(string_type\
    \ p) const {\r\n\t\tsize_type l = 0, r = seg_n;\r\n\t\tsize_type lplcp = 0, rplcp\
    \ = 0;\r\n\t\tsize_type seg_idx = 1;\r\n\t\t\r\n\t\twhile (r - l > 1) {\r\n\t\t\
    \tconst size_type m = (l + r) >> 1;\r\n\t\t\tconst size_type lmlcp = seg[seg_idx\
    \ << 1];\r\n\t\t\tconst size_type rmlcp = seg[seg_idx << 1 | 1];\r\n\t\t\t// std::cout\
    \ << \"(l, r] = (\" << l << \", \" << r << \"], m = \" << m << \" : lplcp = \"\
    \ << lplcp << \", rplcp = \" << rplcp << \", lmlcp = \" << lmlcp << \", rmlcp\
    \ = \" << rmlcp << std::endl;\r\n\t\t\tbool move_r;\r\n\t\t\t\r\n\t\t\tif (lplcp\
    \ < lmlcp) {\r\n\t\t\t\tmove_r = true;\r\n\t\t\t}\r\n\t\t\telse if (lplcp > lmlcp)\
    \ {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t\trplcp = lmlcp;\r\n\t\t\t}\r\n\t\t\t\
    else if (rplcp < rmlcp) {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t}\r\n\t\t\telse\
    \ if (rplcp > rmlcp) {\r\n\t\t\t\tmove_r = true;\r\n\t\t\t\tlplcp = rmlcp;\r\n\
    \t\t\t}\r\n\t\t\telse if (m > size()) {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t}\r\
    \n\t\t\telse {\r\n\t\t\t\tsize_type mplcp = lplcp;\r\n\t\t\t\twhile (sa[m] + mplcp\
    \ < size() && mplcp < p.size() && s[sa[m] + mplcp] == p[mplcp]) ++mplcp;\r\n\t\
    \t\t\t\r\n\t\t\t\tif (mplcp == p.size() || sa[m] + mplcp < size() && s[sa[m] +\
    \ mplcp] > p[mplcp]) move_r = false;\r\n\t\t\t\telse move_r = true;\r\n\t\t\t\t\
    (move_r ? lplcp : rplcp) = mplcp;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tseg_idx <<= 1;\r\
    \n\t\t\tif (move_r) {\r\n\t\t\t\tl = m;\r\n\t\t\t\tseg_idx |= 1;\r\n\t\t\t}\r\n\
    \t\t\telse r = m;\r\n\t\t}\r\n\t\tif (r > size()) r = size() + 1;\r\n\t\treturn\
    \ {r, rplcp};\r\n\t}\r\n\t\r\n\tsize_type search(string_type p) const {\r\n\t\t\
    const auto lb = lower_bound(p);\r\n\t\treturn lb.second < p.size() ? size() :\
    \ sa[lb.first];\r\n\t}\r\n\t\r\n\tstd::vector<size_type> search_all(string_type\
    \ p) const {\r\n\t\tconst auto lb = lower_bound(p);\r\n\t\tif (lb.second < p.size())\
    \ return {};\r\n\t\tsize_type idx = lb.first;\r\n\t\tstd::vector<size_type> res;\r\
    \n\t\tres.emplace_back(sa[idx++]);\r\n\t\tfor (; idx <= size() && lcp[idx - 1]\
    \ >= p.size(); ++idx) res.emplace_back(sa[idx]);\r\n\t\treturn res;\r\n\t}\r\n\
    \t\r\nprivate:\r\n\tstring_type s;\r\n\tstd::vector<size_type> sa; // sa[i (<=\
    \ |s|)] := i \u756A\u76EE\u306B\u5C0F\u3055\u3044 suffix \u306E\u5148\u982D index\r\
    \n\tstd::vector<size_type> rank; // [i (<= |s|)] := s[i..] \u304C suffix \u306E\
    \u4E2D\u3067 rank[i] \u756A\u76EE(0-indexed) \u306B\u5C0F\u3055\u3044\r\n\tstd::vector<size_type>\
    \ lcp; // [i (< size())] := lcp(s[sa[i]..], s[sa[i + 1]..])\r\n\tsize_type seg_n;\r\
    \n\tstd::vector<size_type> seg;\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_SUFFIX_ARRAY_HPP\r\n#define INCLUDE_GUARD_SUFFIX_ARRAY_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/25\r\n\r\n# \u6982\u8981\r\nSuffixArray \u306E\
    \u8A08\u7B97\u306F SA-IS: \u0398(|s|)\r\nLCP \u914D\u5217\u306E\u8A08\u7B97\u306F\
    \ Kasai&s's algorighm: \u0398(|s|)\r\n\u6587\u5B57\u5217 p \u306E\u691C\u7D22\u306F\
    \ LCP \u914D\u5217\u3092\u7528\u3044\u305F\u4E8C\u5206\u63A2\u7D22: \u0398(|p|\
    \ + log|s|)\r\n\r\n# \u4ED5\u69D8\r\nSuffixArray(string_type s) :\r\n\tbuild(s)\r\
    \n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u6587\u5B57\u5217 s \u306E\u5927\u304D\u3055 |s| \u3092\u8FD4\u3059\r\
    \n\r\nconst std::vector<size_type> & get_sa() const noexcept :\r\nconst std::vector<size_type>\
    \ & get_lcp() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\
    \n\t\u8A08\u7B97\u6E08\u307F\u306E sa, lcp \u3092\u305D\u308C\u305E\u308C\u8FD4\
    \u3059\r\n\r\nvoid build(string_type s) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(|s|)\r\n\tSuffix Array \u306E\u69CB\u7BC9 (\u0398(|s|)\r\n\tLongest Common\
    \ Prefix \u914D\u5217\u306E\u8A08\u7B97 (\u0398(|s|))\r\n\r\nstd::pair<size_type,\
    \ size_type> lower_bound(string_type p) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(|p| + log|s|)\r\n\t\u6587\u5B57\u5217 s \u304B\u3089\u8F9E\u66F8\u9806\
    \u3067\u6587\u5B57\u5217 p \u4EE5\u4E0A\u3068\u306A\u308B\u3088\u3046\u306A\u6700\
    \u5C0F\u306E suffix \u3092\u6C42\u3081\u308B\r\n\t\u623B\u308A\u5024\u306F (\u5148\
    \u982D\u4F4D\u7F6E\u3092\u8868\u3059 sa \u306E index, lcp)\r\n\r\nsize_type search(string_type\
    \ p) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|p| + log|s|)\r\n\t\u6587\
    \u5B57\u5217 s \u304B\u3089\u6587\u5B57\u5217 p \u3092\u691C\u7D22\u3057\u3001\
    \u305D\u306E\u958B\u59CB index \u3092\u8FD4\u3059\r\n\t\u8907\u6570\u3042\u308C\
    \u3070\u8F9E\u66F8\u9806\u6700\u5C0F\u3068\u306A\u308B suffix \u306E index \u3092\
    \u8FD4\u3059\r\n\r\nstd::vector<size_type> search_all(string_type p) const :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|p| + log|s| + (p \u306E\u51FA\u73FE\
    \u6570))\r\n\t\u6587\u5B57\u5217 s \u304B\u3089\u6587\u5B57\u5217 p \u3092\u691C\
    \u7D22\u3057\u3001\u51FA\u73FE\u4F4D\u7F6E\u3092\u5168\u3066\u8FD4\u3059(suffix\
    \ \u306E\u8F9E\u66F8\u5F0F\u9806\u5E8F)\r\n\r\n# \u89E3\u8AAC\r\n\u53C2\u8003\u30EA\
    \u30F3\u30AF\u5148\u3067\u306F\u3001LCP \u914D\u5217\u3092\u7528\u3044\u305F\u691C\
    \u7D22\u306B lcp(s[sa[l..]], s[sa[r..]]) \u3057\u304B\u4FDD\u6301\u3057\u3066\u3044\
    \u306A\u3044\u3002\r\n\u304A\u305D\u3089\u304F\u7247\u65B9(l)\u306E\u307F\u3067\
    \u306F s = bbbbbbbb..., p = bbbba \u307F\u305F\u3044\u306A\u5F62\u306E\u3068\u304D\
    \u306B m \u3068 p \u306E\u5358\u7D14\u6BD4\u8F03\u3067\u5408\u8A08 2|s| \u56DE\
    \u7A0B\u5EA6\u306E\u6BD4\u8F03\u304C\u767A\u751F\u3057\u305D\u3046(O(|s| + |p|\
    \ + log|s|) \u306B\u306A\u308B?)\r\n\u305D\u3053\u3067\u3001lplcp = lcp(s[sa[l..]],\
    \ s[sa[r..]]), rplcp = lcp(s[sa[l..]], s[sa[r..]]) \u306E 2 \u3064\u306E\u5024\
    \u3092\u4FDD\u6301\u3057\u3066\u8A08\u7B97\u3057\u3066\u3044\u308B\u3002\r\n\r\
    \nlower_bound \u5185\u3067\u306F\u3001(l, r] \u3068\u3057\u3066\u8A08\u7B97\u3092\
    \u884C\u3063\u3066\u3044\u3066\u3001\u521D\u671F\u5024\u306F l = -1 \u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u304C\u3001sa[0] \u306F\u7A7A\u6587\u5B57\
    \u5217\u3092\u8868\u3059\u306E\u3067 l = 0 \u3068\u3057\u3066\u826F\u3044\u3002\
    \r\n\u307E\u305F\u3001rplcp \u3092\u8A08\u7B97\u3059\u308B\u969B\u306B\u306F r\
    \ \u306F sa \u306E\u6DFB\u5B57\u7BC4\u56F2\u5185\u306B\u53CE\u307E\u3063\u3066\
    \u3044\u306A\u3044\u3068\u3044\u3051\u306A\u3044\u304C\u3001\u3069\u306E\u6587\
    \u5B57\u5217\u3088\u308A\u3082\u5927\u304D\u3044\u6587\u5B57\u5217\u304C\u6700\
    \u5F8C\u306B\u5B58\u5728\u3059\u308B\u3068\u8003\u3048\u308B\u3068\u53CE\u3081\
    \u306A\u304F\u3066\u3082\u826F\u3044\u3002\r\n\r\n\u5834\u5408\u5206\u3051\r\n\
    \tlplcp < lmlcp\r\n\t\tnext: (m, r]\r\n\t\tlplcp, rplcp \u306F\u5909\u5316\u306A\
    \u3057\r\n\t\r\n\tlplcp > lmlcp\r\n\t\tnext: (l, m]\r\n\t\tlplcp \u306F\u5909\u5316\
    \u306A\u3057\r\n\t\trplcp \u306F lmlcp \u306B\u5909\u5316\r\n\t\t\t\u3082\u3068\
    \u3082\u3068 rplcp \\leq lmlcp \u3067\u3042\u308B\u306F\u305A\u306A\u306E\u3067\
    \ rplcp \u306F\u975E\u6E1B\u5C11\r\n\t\r\n\trplcp < rmlcp\r\n\t\tnext: (l, m]\r\
    \n\t\tlplcp, rplcp \u306F\u5909\u5316\u306A\u3057\r\n\t\r\n\trplcp > rmlcp\r\n\
    \t\tnext: (m, r]\r\n\t\tlplcp \u306F rmlcp \u306B\u5909\u5316\r\n\t\t\t\u3082\u3068\
    \u3082\u3068 lplcp \\leq rmlcp \u3067\u3042\u308B\u306F\u305A\u306A\u306E\u3067\
    \ lplcp \u306F\u975E\u6E1B\u5C11\r\n\t\trplcp \u306F\u5909\u5316\u306A\u3057\r\
    \n\t\r\n\tlplcp = lmlcp \u304B\u3064 rmlcp = rplcp\r\n\t\tm \u306E lrlcp + 1 \u6587\
    \u5B57\u76EE(1-indexed) \u3068 p \u3092\u6BD4\u8F03\r\n\t\t\tmplcp = |p|\r\n\t\
    \t\t\tnext: (l, m]\r\n\t\t\t\trplcp \u306F mplcp (= |p|) \u306B\u5909\u5316\r\n\
    \t\t\tm[mplcp] < p[mplcp]\r\n\t\t\t\tnext: (m, r]\r\n\t\t\t\tlplcp \u306F mplcp\
    \ \u306B\u5909\u5316\r\n\t\t\tm[mplcp] > p[mplcp]\r\n\t\t\t\tnext: (l, m]\r\n\t\
    \t\t\trplcp \u306F mplcp \u306B\u5909\u5316\r\n\r\n# memo\r\nsa[l] < sa[r] \u3067\
    \ lcp(s[sa[l]..], s[sa[r]..]) = min{lcp[sa[l]], lcp[sa[l] + 1], \\ldots, lcp[sa[r]\
    \ - 1]}\r\nSparseTable \u3092\u7528\u3044\u308C\u3070 \u69CB\u7BC9: \u0398(|s|log|s|),\
    \ \u30AF\u30A8\u30EA: \u0398(1)\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/flare/items/20439a1db54b367eea70,\
    \ 2020/08/23\r\nhttps://blog.shibayu36.org/entry/2017/01/06/103956, 2020/08/23\r\
    \nhttps://mametter.hatenablog.com/entry/20180130/p1, 2020/08/25\r\nhttps://niuez.hatenablog.com/entry/2019/12/16/203739,\
    \ 2020/08/25\r\n*/\r\n\r\n// #include <iostream>\r\n\r\n#include <string>\r\n\
    #include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\n\r\nstruct\
    \ SuffixArray {\r\n\tusing size_type = std::size_t;\r\n\tusing string_type = std::string;\r\
    \n\t\r\n\tSuffixArray(string_type s) {\r\n\t\tbuild(s);\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn s.size();\r\n\t}\r\n\t\r\n\tconst size_type\
    \ & operator[](size_type i) const noexcept {\r\n\t\treturn sa[i];\r\n\t}\r\n\t\
    \r\n\tconst size_type & at(size_type i) const {\r\n\t\tassert(i <= size());\r\n\
    \t\treturn (*this)[i];\r\n\t}\r\n\t\r\n\tconst std::vector<size_type> & get_sa()\
    \ const noexcept {\r\n\t\treturn sa;\r\n\t}\r\n\t\r\n\tconst std::vector<size_type>\
    \ & get_lcp() const noexcept {\r\n\t\treturn lcp;\r\n\t}\r\n\t\r\n\tvoid build(string_type\
    \ s) {\r\n\t\tthis->s = s;\r\n\t\tsa = sa_is(s);\r\n\t\trank.resize(size() + 1);\r\
    \n\t\tfor (size_type i = 0; i <= size(); ++i) rank[sa[i]] = i;\r\n\t\t\r\n\t\t\
    // LCP \u914D\u5217\u306E\u69CB\u7BC9\r\n\t\tlcp.resize(size());\r\n\t\tlcp[0]\
    \ = 0;\r\n\t\tsize_type mtc = 0;\r\n\t\t// lcp[i] := lcp(s[sa[i]], s[sa[i + 1])\r\
    \n\t\tfor (size_type i = 0; i < size(); ++i) {\r\n\t\t\t// lcp[rank[i]] = lcp(s[i..],\
    \ s[sa[rank[i] + 1])\r\n\t\t\tif (rank[i] == size()) continue;\r\n\t\t\tsize_type\
    \ k = sa[rank[i] + 1];\r\n\t\t\twhile (i + mtc < size() && k + mtc < size() &&\
    \ s[i + mtc] == s[k + mtc]) ++mtc;\r\n\t\t\tlcp[rank[i]] = mtc;\r\n\t\t\tif (mtc\
    \ > 0) --mtc;\r\n\t\t}\r\n\t\t\r\n\t\t// \u30BB\u30B0\u6728\u306E\u521D\u671F\u5316\
    \r\n\t\tseg_n = 1;\r\n\t\twhile (seg_n < size() + 1) seg_n <<= 1;\r\n\t\tseg.resize(seg_n\
    \ << 1);\r\n\t\tfor (size_type i = 0; i < size(); ++i) seg[i + seg_n] = lcp[i];\r\
    \n\t\tfor (size_type i = size(); i < seg_n; ++i) seg[i + seg_n] = 0;\r\n\t\tfor\
    \ (size_type i = seg_n - 1; i > 0; --i) seg[i] = std::min(seg[i << 1], seg[i <<\
    \ 1 | 1]);\r\n\t\t\r\n\t\t// debug \u51FA\u529B\r\n\t\t// for (size_type i = 0;\
    \ i <= size(); ++i) {\r\n\t\t// \tstd::cout << \"sa[\" << i << \"] = \" << sa[i]\
    \ << \"\\t, s[sa[i]..] = \" << s.substr(sa[i]);\r\n\t\t// \tif (i < size()) std::cout\
    \ << \"\\t\\t\\t lcp[i] = \" << lcp[i];\r\n\t\t// \tstd::cout << std::endl;\r\n\
    \t\t// }\r\n\t}\r\n\t\r\n\ttemplate<class S>\r\n\tstatic std::vector<size_type>\
    \ sa_is(S s, const size_type kind = 128) {\r\n\t\tsize_type n = s.size();\r\n\t\
    \tfor (size_type i = 0; i < n; ++i) ++s[i];\r\n\t\ts.push_back(0);\r\n\t\t\r\n\
    \t\tstd::vector<bool> Stype(n + 1); // true: S-type, false: L-type\r\n\t\tstd::vector<size_type>\
    \ lms; // LMS-index\r\n\t\tstd::vector<size_type> lms_map(n + 1, n + 1); // [i]\
    \ := \u3082\u3057 i \u304C LMS-index \u306A\u3089 lms \u914D\u5217\u306E index,\
    \ \u9055\u3048\u3070 n + 1\r\n\t\tstd::vector<size_type> bin(kind + 2); // [i]\
    \ := count_{j < i} (s[j] = j) => count(s[i] = i]) = bin[i + 1] - bin[i]\r\n\t\t\
    ++bin[1];\r\n\t\t\r\n\t\tStype[n] = true;\r\n\t\tfor (size_type i = n; i > 0;\
    \ --i) {\r\n\t\t\tStype[i - 1] = s[i - 1] == s[i] ? Stype[i] : s[i - 1] < s[i];\r\
    \n\t\t\t++bin[s[i - 1] + 1];\r\n\t\t}\r\n\t\tfor (size_type i = 1; i <= n; ++i)\
    \ {\r\n\t\t\tif (!Stype[i - 1] && Stype[i]) {\r\n\t\t\t\tlms_map[i] = lms.size();\r\
    \n\t\t\t\tlms.emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (size_type i = 0;\
    \ i < kind + 1; ++i) bin[i + 1] += bin[i];\r\n\t\t\r\n\t\tstd::vector<size_type>\
    \ sa, cnt;\r\n\t\t\r\n\t\tauto induce = [&](const std::vector<size_type> &lms)\
    \ {\r\n\t\t\tsa.assign(n + 1, 0);\r\n\t\t\t\r\n\t\t\tcnt.assign(kind + 1, 0);\r\
    \n\t\t\tfor (size_type i = lms.size(); i > 0; --i) {\r\n\t\t\t\tconst size_type\
    \ idx = lms[i - 1];\r\n\t\t\t\tconst size_type c = s[idx];\r\n\t\t\t\tsa[bin[c\
    \ + 1] - cnt[c] - 1] = idx;\r\n\t\t\t\t++cnt[c];\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\
    cnt.assign(kind + 1, 0);\r\n\t\t\tfor (size_type i = 0; i < n; ++i) {\r\n\t\t\t\
    \tif (sa[i] == 0) continue;\r\n\t\t\t\tconst size_type idx = sa[i] - 1;\r\n\t\t\
    \t\tif (!Stype[idx]) {\r\n\t\t\t\t\tconst size_type c = s[idx];\r\n\t\t\t\t\t\
    sa[bin[c] + cnt[c]] = idx;\r\n\t\t\t\t\t++cnt[c];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t\t\r\n\t\t\tcnt.assign(kind + 1, 0);\r\n\t\t\tfor (size_type i = n; i > 0; --i)\
    \ {\r\n\t\t\t\tif (sa[i] == 0) continue;\r\n\t\t\t\tconst size_type idx = sa[i]\
    \ - 1;\r\n\t\t\t\tif (Stype[idx]) {\r\n\t\t\t\t\tconst size_type c = s[idx];\r\
    \n\t\t\t\t\tsa[bin[c + 1] - 1 - cnt[c]] = idx;\r\n\t\t\t\t\t++cnt[c];\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t};\r\n\t\t\r\n\t\tinduce(lms);\r\n\t\t\r\n\t\tif (lms.size()\
    \ >= 2) {\r\n\t\t\tstd::vector<size_type> lms_str(lms.size() - 1); // [i] := lms\
    \ \u306E index i \u304C\u4F55\u756A\u76EE(0-indexed) \u306B\u5C0F\u3055\u3044\u304B\
    (\"$\" \u306F\u7121\u8996)\r\n\t\t\tsize_type pre = lms[lms_map[sa[0]]], pre_len\
    \ = 1, rank = 0;\r\n\t\t\tfor (size_type i = 1; i <= n; ++i) {\r\n\t\t\t\tconst\
    \ size_type lms_idx = lms_map[sa[i]]; // sa[i] \u304C LMS \u306A\u3089 lms \u306E\
    \ index, \u9055\u3048\u3070 n + 1\r\n\t\t\t\tif (lms_idx == n + 1) continue;\r\
    \n\t\t\t\tconst size_type idx = lms[lms_map[sa[i]]];\r\n\t\t\t\tconst size_type\
    \ len = lms[lms_idx + 1] - idx + 1;\r\n\t\t\t\t\r\n\t\t\t\t// LMS-substring \u306E\
    \ s[pre..] \u3068 s[idx..] \u3092\u6BD4\u8F03\r\n\t\t\t\tbool issame = pre_len\
    \ == len;\r\n\t\t\t\tif (issame) {\r\n\t\t\t\t\tfor (size_type j = 0; j < len;\
    \ ++j) {\r\n\t\t\t\t\t\tif (s[pre + j] != s[idx + j]) {\r\n\t\t\t\t\t\t\tissame\
    \ = false;\r\n\t\t\t\t\t\t\tbreak;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\
    }\r\n\t\t\t\trank += !issame;\r\n\t\t\t\tlms_str[lms_idx] = rank - 1;\r\n\t\t\t\
    \t\r\n\t\t\t\tpre = idx;\r\n\t\t\t\tpre_len = len;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\
    \tstd::vector<size_type> new_seed(lms.size());\r\n\t\t\tnew_seed[0] = sa[0];\r\
    \n\t\t\t\r\n\t\t\tif (rank == lms_str.size()) {\r\n\t\t\t\tfor (size_type i =\
    \ 0; i < lms_str.size(); ++i) new_seed[lms_str[i] + 1] = lms[i];\r\n\t\t\t}\r\n\
    \t\t\telse {\r\n\t\t\t\tstd::vector<size_type> lms_sa = sa_is(lms_str, rank);\r\
    \n\t\t\t\tfor (size_type i = 1; i < lms_sa.size(); ++i) new_seed[i] = lms[lms_sa[i]];\r\
    \n\t\t\t}\r\n\t\t\t\r\n\t\t\tinduce(new_seed);\r\n\t\t}\r\n\t\t\r\n\t\treturn\
    \ sa;\r\n\t}\r\n\t\r\n\tstd::pair<size_type, size_type> lower_bound(string_type\
    \ p) const {\r\n\t\tsize_type l = 0, r = seg_n;\r\n\t\tsize_type lplcp = 0, rplcp\
    \ = 0;\r\n\t\tsize_type seg_idx = 1;\r\n\t\t\r\n\t\twhile (r - l > 1) {\r\n\t\t\
    \tconst size_type m = (l + r) >> 1;\r\n\t\t\tconst size_type lmlcp = seg[seg_idx\
    \ << 1];\r\n\t\t\tconst size_type rmlcp = seg[seg_idx << 1 | 1];\r\n\t\t\t// std::cout\
    \ << \"(l, r] = (\" << l << \", \" << r << \"], m = \" << m << \" : lplcp = \"\
    \ << lplcp << \", rplcp = \" << rplcp << \", lmlcp = \" << lmlcp << \", rmlcp\
    \ = \" << rmlcp << std::endl;\r\n\t\t\tbool move_r;\r\n\t\t\t\r\n\t\t\tif (lplcp\
    \ < lmlcp) {\r\n\t\t\t\tmove_r = true;\r\n\t\t\t}\r\n\t\t\telse if (lplcp > lmlcp)\
    \ {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t\trplcp = lmlcp;\r\n\t\t\t}\r\n\t\t\t\
    else if (rplcp < rmlcp) {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t}\r\n\t\t\telse\
    \ if (rplcp > rmlcp) {\r\n\t\t\t\tmove_r = true;\r\n\t\t\t\tlplcp = rmlcp;\r\n\
    \t\t\t}\r\n\t\t\telse if (m > size()) {\r\n\t\t\t\tmove_r = false;\r\n\t\t\t}\r\
    \n\t\t\telse {\r\n\t\t\t\tsize_type mplcp = lplcp;\r\n\t\t\t\twhile (sa[m] + mplcp\
    \ < size() && mplcp < p.size() && s[sa[m] + mplcp] == p[mplcp]) ++mplcp;\r\n\t\
    \t\t\t\r\n\t\t\t\tif (mplcp == p.size() || sa[m] + mplcp < size() && s[sa[m] +\
    \ mplcp] > p[mplcp]) move_r = false;\r\n\t\t\t\telse move_r = true;\r\n\t\t\t\t\
    (move_r ? lplcp : rplcp) = mplcp;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tseg_idx <<= 1;\r\
    \n\t\t\tif (move_r) {\r\n\t\t\t\tl = m;\r\n\t\t\t\tseg_idx |= 1;\r\n\t\t\t}\r\n\
    \t\t\telse r = m;\r\n\t\t}\r\n\t\tif (r > size()) r = size() + 1;\r\n\t\treturn\
    \ {r, rplcp};\r\n\t}\r\n\t\r\n\tsize_type search(string_type p) const {\r\n\t\t\
    const auto lb = lower_bound(p);\r\n\t\treturn lb.second < p.size() ? size() :\
    \ sa[lb.first];\r\n\t}\r\n\t\r\n\tstd::vector<size_type> search_all(string_type\
    \ p) const {\r\n\t\tconst auto lb = lower_bound(p);\r\n\t\tif (lb.second < p.size())\
    \ return {};\r\n\t\tsize_type idx = lb.first;\r\n\t\tstd::vector<size_type> res;\r\
    \n\t\tres.emplace_back(sa[idx++]);\r\n\t\tfor (; idx <= size() && lcp[idx - 1]\
    \ >= p.size(); ++idx) res.emplace_back(sa[idx]);\r\n\t\treturn res;\r\n\t}\r\n\
    \t\r\nprivate:\r\n\tstring_type s;\r\n\tstd::vector<size_type> sa; // sa[i (<=\
    \ |s|)] := i \u756A\u76EE\u306B\u5C0F\u3055\u3044 suffix \u306E\u5148\u982D index\r\
    \n\tstd::vector<size_type> rank; // [i (<= |s|)] := s[i..] \u304C suffix \u306E\
    \u4E2D\u3067 rank[i] \u756A\u76EE(0-indexed) \u306B\u5C0F\u3055\u3044\r\n\tstd::vector<size_type>\
    \ lcp; // [i (< size())] := lcp(s[sa[i]..], s[sa[i + 1]..])\r\n\tsize_type seg_n;\r\
    \n\tstd::vector<size_type> seg;\r\n};\r\n\r\n#endif // INCLUDE_GUARD_SUFFIX_ARRAY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/SuffixArray.lcp.test.cpp
  - Test/SuffixArray.search.test.cpp
  - Test/SuffixArray.sa_is.test.cpp
documentation_of: String/SuffixArray.hpp
layout: document
redirect_from:
- /library/String/SuffixArray.hpp
- /library/String/SuffixArray.hpp.html
title: String/SuffixArray.hpp
---
