---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/PersistentUnionFind.test.cpp
    title: Test/PersistentUnionFind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://qiita.com/hotman78/items/9c643feae1de087e6fc5,
    - https://trap.jp/post/663/,
  bundledCode: "#line 1 \"DataStructure/PersistentArray.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/25\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\u6C38\u7D9A\u914D\u5217\r\n\
    \r\n\u4F7F\u7528\u30E1\u30E2\u30EA\u91CF\u304C\u591A\u3044\r\n\r\n\u6DFB\u5B57\
    \u306E\u7BC4\u56F2\u3092 [0, n), m \u5206\u6728\u3068\u3057\u305F\u3068\u304D\u3001\
    \r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: O(n log_m n)\r\n\t\u30A2\u30AF\u30BB\u30B9\
    , \u66F4\u65B0 \u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: O(log_m n)\r\n\r\n\
    \u4EFB\u610F\u306E\u6DFB\u5B57\u306B\u30A2\u30AF\u30BB\u30B9\u53EF\u80FD\u3060\
    \u304C\u8CA0\u306E\u6DFB\u5B57\u306B\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\
    \u3044(\u307B\u307C\u6B63\u3057\u304F\u52D5\u304F\u304C\u52D5\u4F5C\u304C\u9045\
    \u305D\u3046)\r\n\r\n# \u89E3\u8AAC\r\n\u6DFB\u5B57\u306E\u5927\u304D\u3055\u9806\
    \u306B\u4E26\u3079\u308B\u5FC5\u8981\u306F\u306A\u3044\u305F\u3081\u3001\u6DFB\
    \u5B57\u3092 m \u9032\u8868\u8A18\u3057\u305F\u3068\u304D\u306E\u4E0B\u306E\u6841\
    \u304B\u3089\u898B\u3066\u3044\u304D\u8981\u7D20\u3092\u4E26\u3079\u308B\u3002\
    \r\n\u3053\u308C\u306B\u3088\u308A\u3001\u6DFB\u5B57\u306E\u7BC4\u56F2\u3092\u4E8B\
    \u524D\u306B\u6307\u5B9A\u3059\u308B\u5FC5\u8981\u304C\u306A\u304F\u306A\u3063\
    \u3066\u5B09\u3057\u3044\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\n\ttypename T: \u6271\
    \u3046\u30C7\u30FC\u30BF\u306E\u578B\r\n\tstd::size_t M: \u5185\u90E8\u69CB\u9020\
    \u3092 M \u5206\u6728\u306B\u3059\u308B\r\n>\r\n\r\nPersistentArray(const_reference\
    \ def_val = 0)\r\n\t\u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: \u0398(1)\r\n\
    \t\u8981\u7D20\u6570\u304C\u7121\u9650\u306E\u6C38\u7D9A\u914D\u5217\u3092\u4F5C\
    \u6210, \u521D\u671F\u5024\u306F def_val\r\n\r\nPersistentArray set(size_type\
    \ k, const_reference x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_m k)\r\
    \n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(m log_m k)\r\n\tk \u756A\u76EE(0 \\\
    leq k) \u306E\u8981\u7D20\u3092 x \u306B\u66F8\u304D\u63DB\u3048\u305F\u914D\u5217\
    \u3092\u8FD4\u3059\r\n\r\nvoid destructive_set(size_type k, const_reference x)\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log_m k)\r\n\t\u7A7A\u9593\u8A08\u7B97\
    \u91CF: O(m log_m k)\r\n\tk \u756A\u76EE(0 \\leq k) \u306E\u8981\u7D20\u3092 x\
    \ \u306B\u66F8\u304D\u63DB\u3048\u308B\r\n\t\u64CD\u4F5C\u524D\u306E\u914D\u5217\
    \u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\
    \u6CE8\u610F(\u904E\u53BB\u306E\u72B6\u614B\u306B\u30A2\u30AF\u30BB\u30B9\u3057\
    \u305F\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9)\r\n\t\r\nconst_reference\
    \ get(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log_m n)\r\
    \n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\tk \u756A\u76EE(0 \\leq k) \u306E\
    \u8981\u7D20\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://trap.jp/post/663/,\
    \ 2020/04/10\r\nhttps://qiita.com/hotman78/items/9c643feae1de087e6fc5, 2020/09/25\r\
    \n*/\r\n\r\n#include <memory>\r\n#include <utility>\r\n\r\ntemplate<typename T,\
    \ std::size_t M>\r\nstruct PersistentArray {\r\n\tstatic_assert(M > 0);\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type\
    \ = std::shared_ptr<Node>;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node *;\r\n\tstruct Node {\r\n\t\tsptr_type childs[M];\r\n\t\tvalue_type\
    \ val;\r\n\t\tNode(const_reference val) : val(val) {}\r\n\t};\r\n\t\r\nprivate:\r\
    \n\tsptr_type root;\r\n\tvalue_type def_val;\r\n\t\r\nprivate:\r\n\tPersistentArray(sptr_type\
    \ && root, const_reference def_val) : root(root), def_val(def_val) {}\r\n\t\r\n\
    public:\r\n\tPersistentArray(const_reference def_val = 0) : root(nullptr), def_val(def_val)\
    \ {}\r\n\t\r\n\tPersistentArray set(size_type k, const_reference x) const {\r\n\
    \t\tconst_ptr node = root.get();\r\n\t\tsptr_type new_root = std::make_shared<Node>(k\
    \ == 0 ? x : (node ? node->val : def_val));\r\n\t\tnode_ptr new_node = new_root.get();\r\
    \n\t\tfor (; k > 0; k /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif\
    \ (node) {\r\n\t\t\t\tfor (size_type i = 0; i < M; ++i) {\r\n\t\t\t\t\tif (i !=\
    \ m) new_node->childs[i] = node->childs[i];\r\n\t\t\t\t}\r\n\t\t\t\tnew_node->childs[m]\
    \ = std::make_shared<Node>(k < M ? x : (node->childs[m] ? node->childs[m]->val\
    \ : def_val));\r\n\t\t\t\tnode = node->childs[m].get();\r\n\t\t\t}\r\n\t\t\telse\
    \ {\r\n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k < M ? x : def_val);\r\
    \n\t\t\t}\r\n\t\t\tnew_node = new_node->childs[m].get();\r\n\t\t}\r\n\t\tif (node)\
    \ {\r\n\t\t\tfor (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];\r\
    \n\t\t}\r\n\t\treturn {std::move(new_root), def_val};\r\n\t}\r\n\t\r\n\tvoid destructive_set(size_type\
    \ k, const_reference x) {\r\n\t\tif (!root) root = std::make_shared<Node>(k ==\
    \ 0 ? x : def_val);\r\n\t\tnode_ptr node = root.get();\r\n\t\tfor (; k >= M; k\
    \ /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (!node->childs[m]) node->childs[m]\
    \ = std::make_shared<Node>(def_val);\r\n\t\t\tnode = node->childs[m].get();\r\n\
    \t\t}\r\n\t\tif (node->childs[k]) node->childs[k]->val = x;\r\n\t\telse node->childs[k]\
    \ = std::make_shared<Node>(x);\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ k) const {\r\n\t\tconst_ptr node = root.get();\r\n\t\twhile (k > 0 && node)\
    \ {\r\n\t\t\tnode = node->childs[k % M].get();\r\n\t\t\tk /= M;\r\n\t\t}\r\n\t\
    \treturn k == 0 && node ? node->val : def_val;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/25\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\u6C38\
    \u7D9A\u914D\u5217\r\n\r\n\u4F7F\u7528\u30E1\u30E2\u30EA\u91CF\u304C\u591A\u3044\
    \r\n\r\n\u6DFB\u5B57\u306E\u7BC4\u56F2\u3092 [0, n), m \u5206\u6728\u3068\u3057\
    \u305F\u3068\u304D\u3001\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: O(n log_m n)\r\n\
    \t\u30A2\u30AF\u30BB\u30B9, \u66F4\u65B0 \u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\
    \u91CF: O(log_m n)\r\n\r\n\u4EFB\u610F\u306E\u6DFB\u5B57\u306B\u30A2\u30AF\u30BB\
    \u30B9\u53EF\u80FD\u3060\u304C\u8CA0\u306E\u6DFB\u5B57\u306B\u306F\u5BFE\u5FDC\
    \u3057\u3066\u3044\u306A\u3044(\u307B\u307C\u6B63\u3057\u304F\u52D5\u304F\u304C\
    \u52D5\u4F5C\u304C\u9045\u305D\u3046)\r\n\r\n# \u89E3\u8AAC\r\n\u6DFB\u5B57\u306E\
    \u5927\u304D\u3055\u9806\u306B\u4E26\u3079\u308B\u5FC5\u8981\u306F\u306A\u3044\
    \u305F\u3081\u3001\u6DFB\u5B57\u3092 m \u9032\u8868\u8A18\u3057\u305F\u3068\u304D\
    \u306E\u4E0B\u306E\u6841\u304B\u3089\u898B\u3066\u3044\u304D\u8981\u7D20\u3092\
    \u4E26\u3079\u308B\u3002\r\n\u3053\u308C\u306B\u3088\u308A\u3001\u6DFB\u5B57\u306E\
    \u7BC4\u56F2\u3092\u4E8B\u524D\u306B\u6307\u5B9A\u3059\u308B\u5FC5\u8981\u304C\
    \u306A\u304F\u306A\u3063\u3066\u5B09\u3057\u3044\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\
    \n\ttypename T: \u6271\u3046\u30C7\u30FC\u30BF\u306E\u578B\r\n\tstd::size_t M:\
    \ \u5185\u90E8\u69CB\u9020\u3092 M \u5206\u6728\u306B\u3059\u308B\r\n>\r\n\r\n\
    PersistentArray(const_reference def_val = 0)\r\n\t\u6642\u9593/\u7A7A\u9593 \u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u304C\u7121\u9650\u306E\u6C38\u7D9A\
    \u914D\u5217\u3092\u4F5C\u6210, \u521D\u671F\u5024\u306F def_val\r\n\r\nPersistentArray\
    \ set(size_type k, const_reference x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(m log_m k)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(m log_m k)\r\n\tk \u756A\
    \u76EE(0 \\leq k) \u306E\u8981\u7D20\u3092 x \u306B\u66F8\u304D\u63DB\u3048\u305F\
    \u914D\u5217\u3092\u8FD4\u3059\r\n\r\nvoid destructive_set(size_type k, const_reference\
    \ x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log_m k)\r\n\t\u7A7A\u9593\u8A08\
    \u7B97\u91CF: O(m log_m k)\r\n\tk \u756A\u76EE(0 \\leq k) \u306E\u8981\u7D20\u3092\
    \ x \u306B\u66F8\u304D\u63DB\u3048\u308B\r\n\t\u64CD\u4F5C\u524D\u306E\u914D\u5217\
    \u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\
    \u6CE8\u610F(\u904E\u53BB\u306E\u72B6\u614B\u306B\u30A2\u30AF\u30BB\u30B9\u3057\
    \u305F\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9)\r\n\t\r\nconst_reference\
    \ get(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log_m n)\r\
    \n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\tk \u756A\u76EE(0 \\leq k) \u306E\
    \u8981\u7D20\u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://trap.jp/post/663/,\
    \ 2020/04/10\r\nhttps://qiita.com/hotman78/items/9c643feae1de087e6fc5, 2020/09/25\r\
    \n*/\r\n\r\n#include <memory>\r\n#include <utility>\r\n\r\ntemplate<typename T,\
    \ std::size_t M>\r\nstruct PersistentArray {\r\n\tstatic_assert(M > 0);\r\n\t\
    using value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing\
    \ size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing sptr_type\
    \ = std::shared_ptr<Node>;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node *;\r\n\tstruct Node {\r\n\t\tsptr_type childs[M];\r\n\t\tvalue_type\
    \ val;\r\n\t\tNode(const_reference val) : val(val) {}\r\n\t};\r\n\t\r\nprivate:\r\
    \n\tsptr_type root;\r\n\tvalue_type def_val;\r\n\t\r\nprivate:\r\n\tPersistentArray(sptr_type\
    \ && root, const_reference def_val) : root(root), def_val(def_val) {}\r\n\t\r\n\
    public:\r\n\tPersistentArray(const_reference def_val = 0) : root(nullptr), def_val(def_val)\
    \ {}\r\n\t\r\n\tPersistentArray set(size_type k, const_reference x) const {\r\n\
    \t\tconst_ptr node = root.get();\r\n\t\tsptr_type new_root = std::make_shared<Node>(k\
    \ == 0 ? x : (node ? node->val : def_val));\r\n\t\tnode_ptr new_node = new_root.get();\r\
    \n\t\tfor (; k > 0; k /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif\
    \ (node) {\r\n\t\t\t\tfor (size_type i = 0; i < M; ++i) {\r\n\t\t\t\t\tif (i !=\
    \ m) new_node->childs[i] = node->childs[i];\r\n\t\t\t\t}\r\n\t\t\t\tnew_node->childs[m]\
    \ = std::make_shared<Node>(k < M ? x : (node->childs[m] ? node->childs[m]->val\
    \ : def_val));\r\n\t\t\t\tnode = node->childs[m].get();\r\n\t\t\t}\r\n\t\t\telse\
    \ {\r\n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k < M ? x : def_val);\r\
    \n\t\t\t}\r\n\t\t\tnew_node = new_node->childs[m].get();\r\n\t\t}\r\n\t\tif (node)\
    \ {\r\n\t\t\tfor (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];\r\
    \n\t\t}\r\n\t\treturn {std::move(new_root), def_val};\r\n\t}\r\n\t\r\n\tvoid destructive_set(size_type\
    \ k, const_reference x) {\r\n\t\tif (!root) root = std::make_shared<Node>(k ==\
    \ 0 ? x : def_val);\r\n\t\tnode_ptr node = root.get();\r\n\t\tfor (; k >= M; k\
    \ /= M) {\r\n\t\t\tconst size_type m = k % M;\r\n\t\t\tif (!node->childs[m]) node->childs[m]\
    \ = std::make_shared<Node>(def_val);\r\n\t\t\tnode = node->childs[m].get();\r\n\
    \t\t}\r\n\t\tif (node->childs[k]) node->childs[k]->val = x;\r\n\t\telse node->childs[k]\
    \ = std::make_shared<Node>(x);\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ k) const {\r\n\t\tconst_ptr node = root.get();\r\n\t\twhile (k > 0 && node)\
    \ {\r\n\t\t\tnode = node->childs[k % M].get();\r\n\t\t\tk /= M;\r\n\t\t}\r\n\t\
    \treturn k == 0 && node ? node->val : def_val;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentArray.hpp
  requiredBy: []
  timestamp: '2020-09-25 16:36:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/PersistentUnionFind.test.cpp
documentation_of: DataStructure/PersistentArray.hpp
layout: document
redirect_from:
- /library/DataStructure/PersistentArray.hpp
- /library/DataStructure/PersistentArray.hpp.html
title: DataStructure/PersistentArray.hpp
---
