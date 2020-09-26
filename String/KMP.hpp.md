---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://qiita.com/itomomoti/items/5e95aeef3f17a29a41cd,
    - https://snuke.hatenablog.com/entry/2014/12/01/235807,
    - https://snuke.hatenablog.com/entry/2017/07/18/101026,
  bundledCode: "#line 1 \"String/KMP.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2019/11/30\r\
    \n\r\n# \u89E3\u8AAC\r\nS[i] \u3067\u4E0D\u4E00\u81F4\u304C\u8D77\u3053\u3063\u305F\
    \u5834\u5408\u3001\u6B21\u306B table[i] \u304B\u3089\u6BD4\u8F03\u3092\u884C\u3046\
    \u3002\r\n\r\n# \u4ED5\u69D8\r\nstd::vector<int> build_KMP_table(const std::string\
    \ &S) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|S|)\r\n\tKMP_table \u3092\
    \u69CB\u7BC9\u3059\u308B\r\n\r\nstd::vector<std::size_t> search_KMP(const std::string\
    \ &T, const std::string &S, const std::vector<int> &table) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(|T|)\r\n\tKMP \u30C6\u30FC\u30D6\u30EB(table) \u3092\
    \u7528\u3044\u3066\u6587\u5B57\u5217 S \u304B\u3089\u6587\u5B57\u5217 T \u3092\
    \u691C\u7D22\u3059\u308B\r\n\r\nstd::vector<int> build_period_table(const std::string\
    \ &S) : --unverified--\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|S|)\r\n\t\
    MP \u6CD5\u3092\u5229\u7528\u3057\u3066 S[0..i-1] \u306E\u6700\u5C0F\u5468\u671F\
    \u3092\u6C42\u3081\u308B\u3002\r\n\r\n# \u53C2\u8003\r\nhttps://snuke.hatenablog.com/entry/2014/12/01/235807,\
    \ 2019/11/30\r\nhttps://snuke.hatenablog.com/entry/2017/07/18/101026, 2019/11/30\r\
    \nhttps://qiita.com/itomomoti/items/5e95aeef3f17a29a41cd, 2019/11/30\r\n*/\r\n\
    \r\n#include <vector>\r\n#include <string>\r\n#include <iostream>\r\n#include\
    \ <cstdio>\r\n\r\nstd::vector<int> build_KMP_table(const std::string &S) {\r\n\
    \tstd::vector<int> table(S.size() + 1);\r\n\ttable[0] = -1;\r\n\tint j = -1;\r\
    \n\tfor (int i = 1; i <= S.size(); ++i) {\r\n\t\twhile (j >= 0 && S[i - 1] !=\
    \ S[j]) j = table[j];\r\n\t\t++j;\r\n\t\ttable[i] = i == S.size() || S[i] != S[j]\
    \ ? j : table[j];\r\n\t}\r\n\treturn table;\r\n}\r\n\r\nstd::vector<std::size_t>\
    \ search_KMP(const std::string &T, const std::string &S, const std::vector<int>\
    \ &table) {\r\n\tstd::vector<std::size_t> res;\r\n\tint i = 0, j = 0;\r\n\twhile\
    \ (i < T.size()) {\r\n\t\twhile (j >= 0 && T[i] != S[j]) j = table[j];\r\n\t\t\
    ++i; ++j;\r\n\t\tif (j == S.size()) {\r\n\t\t\tres.emplace_back(i - S.size());\r\
    \n\t\t\tj = table[S.size()];\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nstd::vector<int>\
    \ build_period_table(const std::string &S) {\r\n\tstd::vector<int> table(S.size()\
    \ + 1);\r\n\ttable[0] = -1;\r\n\tint j = -1;\r\n\tfor (int i = 1; i <= S.size();\
    \ ++i) {\r\n\t\twhile (j >= 0 && S[i - 1] != S[j]) j = table[j];\r\n\t\t++j;\r\
    \n\t\ttable[i] = j;\r\n\t}\r\n\t\r\n\ttable[0] = 0;\r\n\tfor (int i = 1; i <=\
    \ S.size(); ++i) table[i] = i - table[i];\r\n\treturn table;\r\n}\r\n\r\nint main()\
    \ {\r\n\tstd::string S, T;\r\n\tprintf(\"T : \"); std::cin >> T;\r\n\tprintf(\"\
    S : \"); std::cin >> S;\r\n\tprintf(\"|S| = %d, |T| = %d\\n\", S.size(), T.size());\r\
    \n\tauto ans = search_KMP(T, S, build_KMP_table(S));\r\n\tprintf(\"%d found\\\
    n\", ans.size());\r\n\tfor (int pos : ans) {\r\n\t\tprintf(\"%d : \", pos);\r\n\
    \t\tstd::cout << T.substr(pos, S.size()) << std::endl;\r\n\t}\r\n\tauto period_table\
    \ = build_period_table(S);\r\n\tfor (int cur : period_table) printf(\"%d \", cur);\r\
    \n\tputs(\"\");\r\n\t\r\n\treturn 0;\r\n}\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_KMP_HPP\r\n#define INCLUDE_GUARD_KMP_HPP\r\n\r\n/*\r\
    \nlast-updated: 2019/11/30\r\n\r\n# \u89E3\u8AAC\r\nS[i] \u3067\u4E0D\u4E00\u81F4\
    \u304C\u8D77\u3053\u3063\u305F\u5834\u5408\u3001\u6B21\u306B table[i] \u304B\u3089\
    \u6BD4\u8F03\u3092\u884C\u3046\u3002\r\n\r\n# \u4ED5\u69D8\r\nstd::vector<int>\
    \ build_KMP_table(const std::string &S) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(|S|)\r\n\tKMP_table \u3092\u69CB\u7BC9\u3059\u308B\r\n\r\nstd::vector<std::size_t>\
    \ search_KMP(const std::string &T, const std::string &S, const std::vector<int>\
    \ &table) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(|T|)\r\n\tKMP \u30C6\u30FC\
    \u30D6\u30EB(table) \u3092\u7528\u3044\u3066\u6587\u5B57\u5217 S \u304B\u3089\u6587\
    \u5B57\u5217 T \u3092\u691C\u7D22\u3059\u308B\r\n\r\nstd::vector<int> build_period_table(const\
    \ std::string &S) : --unverified--\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (|S|)\r\n\tMP \u6CD5\u3092\u5229\u7528\u3057\u3066 S[0..i-1] \u306E\u6700\u5C0F\
    \u5468\u671F\u3092\u6C42\u3081\u308B\u3002\r\n\r\n# \u53C2\u8003\r\nhttps://snuke.hatenablog.com/entry/2014/12/01/235807,\
    \ 2019/11/30\r\nhttps://snuke.hatenablog.com/entry/2017/07/18/101026, 2019/11/30\r\
    \nhttps://qiita.com/itomomoti/items/5e95aeef3f17a29a41cd, 2019/11/30\r\n*/\r\n\
    \r\n#include <vector>\r\n#include <string>\r\n#include <iostream>\r\n#include\
    \ <cstdio>\r\n\r\nstd::vector<int> build_KMP_table(const std::string &S) {\r\n\
    \tstd::vector<int> table(S.size() + 1);\r\n\ttable[0] = -1;\r\n\tint j = -1;\r\
    \n\tfor (int i = 1; i <= S.size(); ++i) {\r\n\t\twhile (j >= 0 && S[i - 1] !=\
    \ S[j]) j = table[j];\r\n\t\t++j;\r\n\t\ttable[i] = i == S.size() || S[i] != S[j]\
    \ ? j : table[j];\r\n\t}\r\n\treturn table;\r\n}\r\n\r\nstd::vector<std::size_t>\
    \ search_KMP(const std::string &T, const std::string &S, const std::vector<int>\
    \ &table) {\r\n\tstd::vector<std::size_t> res;\r\n\tint i = 0, j = 0;\r\n\twhile\
    \ (i < T.size()) {\r\n\t\twhile (j >= 0 && T[i] != S[j]) j = table[j];\r\n\t\t\
    ++i; ++j;\r\n\t\tif (j == S.size()) {\r\n\t\t\tres.emplace_back(i - S.size());\r\
    \n\t\t\tj = table[S.size()];\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nstd::vector<int>\
    \ build_period_table(const std::string &S) {\r\n\tstd::vector<int> table(S.size()\
    \ + 1);\r\n\ttable[0] = -1;\r\n\tint j = -1;\r\n\tfor (int i = 1; i <= S.size();\
    \ ++i) {\r\n\t\twhile (j >= 0 && S[i - 1] != S[j]) j = table[j];\r\n\t\t++j;\r\
    \n\t\ttable[i] = j;\r\n\t}\r\n\t\r\n\ttable[0] = 0;\r\n\tfor (int i = 1; i <=\
    \ S.size(); ++i) table[i] = i - table[i];\r\n\treturn table;\r\n}\r\n\r\nint main()\
    \ {\r\n\tstd::string S, T;\r\n\tprintf(\"T : \"); std::cin >> T;\r\n\tprintf(\"\
    S : \"); std::cin >> S;\r\n\tprintf(\"|S| = %d, |T| = %d\\n\", S.size(), T.size());\r\
    \n\tauto ans = search_KMP(T, S, build_KMP_table(S));\r\n\tprintf(\"%d found\\\
    n\", ans.size());\r\n\tfor (int pos : ans) {\r\n\t\tprintf(\"%d : \", pos);\r\n\
    \t\tstd::cout << T.substr(pos, S.size()) << std::endl;\r\n\t}\r\n\tauto period_table\
    \ = build_period_table(S);\r\n\tfor (int cur : period_table) printf(\"%d \", cur);\r\
    \n\tputs(\"\");\r\n\t\r\n\treturn 0;\r\n}\r\n\r\n#endif // INCLUDE_GUARD_KMP_HPP"
  dependsOn: []
  isVerificationFile: false
  path: String/KMP.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/KMP.hpp
layout: document
redirect_from:
- /library/String/KMP.hpp
- /library/String/KMP.hpp.html
title: String/KMP.hpp
---
