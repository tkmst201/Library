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
    - http://noshi91.hatenablog.com/entry/2019/02/04/175100,
  bundledCode: "#line 1 \"DataStructure/PersistentStack.hpp\"\n\n\n\r\n#include <vector>\r\
    \n#include <memory>\r\n#include <cassert>\r\n\r\n/*\r\nlast-updated: 2020/04/15\
    \ unverified\r\n\r\n\u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\r\n\r\n# \u4ED5\u69D8\
    \r\nPersistentStack() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\
    \u306E stack \u3092\u4F5C\u6210\u3059\u308B\r\n\r\nbool empty() const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u3067\u3042\u308B\u304B\u3069\u3046\
    \u304B\u5224\u5B9A\u3059\u308B\r\n\r\nPersistentStack push(value_type x) const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5024 x \u3092\u8FFD\u52A0\
    \u3057\u305F stack \u3092\u4F5C\u6210\u3059\u308B\r\n\r\nPersistentStack pop()\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u4E00\u756A\u6700\
    \u5F8C\u306B\u5165\u308C\u305F\u8981\u7D20\u3092\u524A\u9664\u3057\u305F stack\
    \ \u3092\u4F5C\u6210\r\n\r\nconst_reference top() const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u6700\u5F8C\u306B\u5165\u308C\u305F\u8981\u7D20\u3092\
    \u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://noshi91.hatenablog.com/entry/2019/02/04/175100,\
    \ 2020/04/10\r\n*/\r\n\r\ntemplate<typename T>\r\nstruct PersistentStack {\r\n\
    public:\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type\
    \ &;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type = std::shared_ptr<Node>;\r\
    \n\tstruct Node {\r\n\t\tvalue_type value;\r\n\t\tsptr_type prev;\r\n\t\tNode(value_type\
    \ value, sptr_type prev) : value(value), prev(prev) {}\r\n\t};\r\n\t\r\npublic:\r\
    \n\tPersistentStack() = default;\r\n\t\r\n\tbool empty() const { return !static_cast<bool>(top_node);\
    \ }\r\n\t\r\n\tPersistentStack push(const value_type &x) const { return PersistentStack{\
    \ std::make_shared<Node>(x, top_node) }; }\r\n\t\r\n\tPersistentStack pop() const\
    \ {\r\n\t\tassert(!empty());\r\n\t\treturn PersistentStack{top_node->prev};\r\n\
    \t}\r\n\t\r\n\tvalue_type top() const {\r\n\t\tassert(!empty());\r\n\t\treturn\
    \ top_node->value;\r\n\t}\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tPersistentStack(sptr_type\
    \ prev) : top_node(prev) {}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_STACK_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_STACK_HPP\r\
    \n\r\n#include <vector>\r\n#include <memory>\r\n#include <cassert>\r\n\r\n/*\r\
    \nlast-updated: 2020/04/15 unverified\r\n\r\n\u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\
    \r\n\r\n# \u4ED5\u69D8\r\nPersistentStack() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u7A7A\u306E stack \u3092\u4F5C\u6210\u3059\u308B\r\n\r\nbool\
    \ empty() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u3067\
    \u3042\u308B\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\r\n\r\nPersistentStack\
    \ push(value_type x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\
    \t\u5024 x \u3092\u8FFD\u52A0\u3057\u305F stack \u3092\u4F5C\u6210\u3059\u308B\
    \r\n\r\nPersistentStack pop() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u4E00\u756A\u6700\u5F8C\u306B\u5165\u308C\u305F\u8981\u7D20\u3092\u524A\
    \u9664\u3057\u305F stack \u3092\u4F5C\u6210\r\n\r\nconst_reference top() const\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6700\u5F8C\u306B\u5165\
    \u308C\u305F\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttp://noshi91.hatenablog.com/entry/2019/02/04/175100,\
    \ 2020/04/10\r\n*/\r\n\r\ntemplate<typename T>\r\nstruct PersistentStack {\r\n\
    public:\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type\
    \ &;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type = std::shared_ptr<Node>;\r\
    \n\tstruct Node {\r\n\t\tvalue_type value;\r\n\t\tsptr_type prev;\r\n\t\tNode(value_type\
    \ value, sptr_type prev) : value(value), prev(prev) {}\r\n\t};\r\n\t\r\npublic:\r\
    \n\tPersistentStack() = default;\r\n\t\r\n\tbool empty() const { return !static_cast<bool>(top_node);\
    \ }\r\n\t\r\n\tPersistentStack push(const value_type &x) const { return PersistentStack{\
    \ std::make_shared<Node>(x, top_node) }; }\r\n\t\r\n\tPersistentStack pop() const\
    \ {\r\n\t\tassert(!empty());\r\n\t\treturn PersistentStack{top_node->prev};\r\n\
    \t}\r\n\t\r\n\tvalue_type top() const {\r\n\t\tassert(!empty());\r\n\t\treturn\
    \ top_node->value;\r\n\t}\r\n\t\r\nprivate:\r\n\tsptr_type top_node;\r\n\tPersistentStack(sptr_type\
    \ prev) : top_node(prev) {}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_STACK_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentStack.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentStack.hpp
layout: document
redirect_from:
- /library/DataStructure/PersistentStack.hpp
- /library/DataStructure/PersistentStack.hpp.html
title: DataStructure/PersistentStack.hpp
---
