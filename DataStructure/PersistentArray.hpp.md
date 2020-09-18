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
    - https://trap.jp/post/663/,
  bundledCode: "#line 1 \"DataStructure/PersistentArray.hpp\"\n\n\n\r\n#include <memory>\r\
    \n#include <stack>\r\n#include <utility>\r\n#include <cassert>\r\n\r\n/*\r\nlast-updated:\
    \ 2020/04/15\r\n\r\n\u6C38\u7D9A\u914D\u5217\r\n\r\n# \u4ED5\u69D8\r\nPersistentArray()\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u306E array \u306E\
    \u4F5C\u6210\r\n\r\nPersistentArray(size_type n, const_reference def_v) :\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B5\u30A4\u30BA n \u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u306E 2 \u51AA\u306E\u914D\u5217\u3092\u4F5C\u6210, \u521D\u671F\
    \u5024\u306F def_v\r\n\r\nbool empty() const noexcept :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u3067\u3042\u308B\u304B\u3069\u3046\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u914D\u5217\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\
    \u3059\r\n\r\nconst_reference lookup(size_type i) const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log n)\r\n\ti(0-indexed) \u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\r\n\r\nPersistentArray update(size_type i, const_reference x) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\ti(0-indexed) \u756A\
    \u76EE\u306E\u8981\u7D20\u3092 x \u306B\u66F8\u304D\u63DB\u3048\u305F\u914D\u5217\
    \u3092\u4F5C\u6210\r\n\r\n# \u53C2\u8003\r\nhttps://trap.jp/post/663/, 2020/04/10\r\
    \n*/\r\n\r\ntemplate<typename T>\r\nstruct PersistentArray {\r\npublic:\r\n\t\
    using value_type = int;\r\n\tusing const_reference = const value_type &;\r\n\t\
    using size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing\
    \ sptr_type = std::shared_ptr<Node>;\r\n\tusing const_sptr_ptr = const sptr_type\
    \ *;\r\n\tstruct Node {\r\n\t\tsptr_type child[2];\r\n\t\tvalue_type value;\r\n\
    \t\tNode() = default;\r\n\t\tNode(value_type value) : value(value) {}\r\n\t};\r\
    \n\t\r\npublic:\r\n\tPersistentArray() = default;\r\n\t\r\n\tPersistentArray(size_type\
    \ n, const_reference def_v) {\r\n\t\tdepth = 0;\r\n\t\twhile (1 << depth < n)\
    \ ++depth;\r\n\t\t\r\n\t\tstd::stack<std::pair<const_sptr_ptr, size_type>> stk;\r\
    \n\t\ttop_node = std::make_shared<Node>();\r\n\t\tstk.emplace(&top_node, 0);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tconst_sptr_ptr cur_node = stk.top().first;\r\
    \n\t\t\tsize_type cur_d = stk.top().second;\r\n\t\t\tstk.pop();\r\n\t\t\t\r\n\t\
    \t\tif (cur_d == depth) (*cur_node)->value = def_v;\r\n\t\t\telse {\r\n\t\t\t\t\
    for (size_type i = 0; i < 2; ++i) {\r\n\t\t\t\t\t(*cur_node)->child[i] = std::make_shared<Node>();\r\
    \n\t\t\t\t\tstk.emplace(&(*cur_node)->child[i], cur_d + 1);\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tbool empty() const noexcept { return !static_cast<bool>(top_node);\
    \ }\r\n\t\r\n\tsize_type size() const noexcept { return empty() ? 0 : 1 << depth;\
    \ }\r\n\t\r\n\tconst_reference lookup(size_type i) const {\r\n\t\tassert(i < size());\r\
    \n\t\tconst_sptr_ptr cur_node = &top_node;\r\n\t\tfor (size_type pos = 0, rng\
    \ = 1 << depth; rng > 1; rng >>= 1) {\r\n\t\t\tbool right = false;\r\n\t\t\tif\
    \ (pos + (rng >> 1) <= i) {\r\n\t\t\t\tpos += rng >> 1;\r\n\t\t\t\tright = true;\r\
    \n\t\t\t}\r\n\t\t\tcur_node = &(*cur_node)->child[right];\r\n\t\t}\r\n\t\treturn\
    \ (*cur_node)->value;\r\n\t}\r\n\t\r\n\tPersistentArray update(size_type i, const_reference\
    \ x) const {\r\n\t\tassert(i < size());\r\n\t\tsptr_type nex_top = std::make_shared<Node>();\r\
    \n\t\tconst_sptr_ptr cur_node = &nex_top, walk_node = &top_node;\r\n\t\tfor (size_type\
    \ pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {\r\n\t\t\tbool right = false;\r\
    \n\t\t\tif (pos + (rng >> 1) <= i) {\r\n\t\t\t\tpos += rng >> 1;\r\n\t\t\t\tright\
    \ = true;\r\n\t\t\t}\r\n\t\t\t(*cur_node)->child[!right] = (*walk_node)->child[!right];\r\
    \n\t\t\t(*cur_node)->child[right] = std::make_shared<Node>();\r\n\t\t\t\r\n\t\t\
    \tcur_node = &(*cur_node)->child[right];\r\n\t\t\twalk_node = &(*walk_node)->child[right];\r\
    \n\t\t}\r\n\t\t(*cur_node)->value = x;\r\n\t\treturn PersistentArray(nex_top,\
    \ depth);\r\n\t}\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tsize_type depth;\r\
    \n\t\r\n\tPersistentArray(sptr_type top_node, size_type depth) : top_node(top_node),\
    \ depth(depth) {}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\
    \n\r\n#include <memory>\r\n#include <stack>\r\n#include <utility>\r\n#include\
    \ <cassert>\r\n\r\n/*\r\nlast-updated: 2020/04/15\r\n\r\n\u6C38\u7D9A\u914D\u5217\
    \r\n\r\n# \u4ED5\u69D8\r\nPersistentArray() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u7A7A\u306E array \u306E\u4F5C\u6210\r\n\r\nPersistentArray(size_type\
    \ n, const_reference def_v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\
    \n\t\u30B5\u30A4\u30BA n \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E 2 \u51AA\u306E\u914D\
    \u5217\u3092\u4F5C\u6210, \u521D\u671F\u5024\u306F def_v\r\n\r\nbool empty() const\
    \ noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u3067\u3042\
    \u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\r\n\r\nsize_type\
    \ size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\
    \u914D\u5217\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\r\n\r\nconst_reference\
    \ lookup(size_type i) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log\
    \ n)\r\n\ti(0-indexed) \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\n\
    PersistentArray update(size_type i, const_reference x) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(log n)\r\n\ti(0-indexed) \u756A\u76EE\u306E\u8981\u7D20\
    \u3092 x \u306B\u66F8\u304D\u63DB\u3048\u305F\u914D\u5217\u3092\u4F5C\u6210\r\n\
    \r\n# \u53C2\u8003\r\nhttps://trap.jp/post/663/, 2020/04/10\r\n*/\r\n\r\ntemplate<typename\
    \ T>\r\nstruct PersistentArray {\r\npublic:\r\n\tusing value_type = int;\r\n\t\
    using const_reference = const value_type &;\r\n\tusing size_type = std::size_t;\r\
    \n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type = std::shared_ptr<Node>;\r\
    \n\tusing const_sptr_ptr = const sptr_type *;\r\n\tstruct Node {\r\n\t\tsptr_type\
    \ child[2];\r\n\t\tvalue_type value;\r\n\t\tNode() = default;\r\n\t\tNode(value_type\
    \ value) : value(value) {}\r\n\t};\r\n\t\r\npublic:\r\n\tPersistentArray() = default;\r\
    \n\t\r\n\tPersistentArray(size_type n, const_reference def_v) {\r\n\t\tdepth =\
    \ 0;\r\n\t\twhile (1 << depth < n) ++depth;\r\n\t\t\r\n\t\tstd::stack<std::pair<const_sptr_ptr,\
    \ size_type>> stk;\r\n\t\ttop_node = std::make_shared<Node>();\r\n\t\tstk.emplace(&top_node,\
    \ 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst_sptr_ptr cur_node = stk.top().first;\r\
    \n\t\t\tsize_type cur_d = stk.top().second;\r\n\t\t\tstk.pop();\r\n\t\t\t\r\n\t\
    \t\tif (cur_d == depth) (*cur_node)->value = def_v;\r\n\t\t\telse {\r\n\t\t\t\t\
    for (size_type i = 0; i < 2; ++i) {\r\n\t\t\t\t\t(*cur_node)->child[i] = std::make_shared<Node>();\r\
    \n\t\t\t\t\tstk.emplace(&(*cur_node)->child[i], cur_d + 1);\r\n\t\t\t\t}\r\n\t\
    \t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tbool empty() const noexcept { return !static_cast<bool>(top_node);\
    \ }\r\n\t\r\n\tsize_type size() const noexcept { return empty() ? 0 : 1 << depth;\
    \ }\r\n\t\r\n\tconst_reference lookup(size_type i) const {\r\n\t\tassert(i < size());\r\
    \n\t\tconst_sptr_ptr cur_node = &top_node;\r\n\t\tfor (size_type pos = 0, rng\
    \ = 1 << depth; rng > 1; rng >>= 1) {\r\n\t\t\tbool right = false;\r\n\t\t\tif\
    \ (pos + (rng >> 1) <= i) {\r\n\t\t\t\tpos += rng >> 1;\r\n\t\t\t\tright = true;\r\
    \n\t\t\t}\r\n\t\t\tcur_node = &(*cur_node)->child[right];\r\n\t\t}\r\n\t\treturn\
    \ (*cur_node)->value;\r\n\t}\r\n\t\r\n\tPersistentArray update(size_type i, const_reference\
    \ x) const {\r\n\t\tassert(i < size());\r\n\t\tsptr_type nex_top = std::make_shared<Node>();\r\
    \n\t\tconst_sptr_ptr cur_node = &nex_top, walk_node = &top_node;\r\n\t\tfor (size_type\
    \ pos = 0, rng = 1 << depth; rng > 1; rng >>= 1) {\r\n\t\t\tbool right = false;\r\
    \n\t\t\tif (pos + (rng >> 1) <= i) {\r\n\t\t\t\tpos += rng >> 1;\r\n\t\t\t\tright\
    \ = true;\r\n\t\t\t}\r\n\t\t\t(*cur_node)->child[!right] = (*walk_node)->child[!right];\r\
    \n\t\t\t(*cur_node)->child[right] = std::make_shared<Node>();\r\n\t\t\t\r\n\t\t\
    \tcur_node = &(*cur_node)->child[right];\r\n\t\t\twalk_node = &(*walk_node)->child[right];\r\
    \n\t\t}\r\n\t\t(*cur_node)->value = x;\r\n\t\treturn PersistentArray(nex_top,\
    \ depth);\r\n\t}\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tsize_type depth;\r\
    \n\t\r\n\tPersistentArray(sptr_type top_node, size_type depth) : top_node(top_node),\
    \ depth(depth) {}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentArray.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentArray.hpp
layout: document
redirect_from:
- /library/DataStructure/PersistentArray.hpp
- /library/DataStructure/PersistentArray.hpp.html
title: DataStructure/PersistentArray.hpp
---
