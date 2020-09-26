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
  bundledCode: "#line 1 \"DataStructure/PersistentUnionFind.hpp\"\n\n\n\r\n/*\r\n\
    last-updated: 2020/09/26\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\u6C38\u7D9A UnionFind\r\
    \nUnionFind \u3067\u904E\u53BB\u306E\u4EFB\u610F\u306E\u72B6\u614B\u3092\u898B\
    \u308B or \u64CD\u4F5C\u53EF\u80FD\r\n\r\n\u6DFB\u5B57\u306E\u7BC4\u56F2\u3092\
    \ [0, n), \u5B8C\u5168\u6C38\u7D9A\u914D\u5217\u306E\u5185\u90E8\u3092 m \u5206\
    \u6728\u3068\u3057\u305F\u3068\u304D\u3001\r\n\t- unite\r\n\t\t\u6642\u9593/\u7A7A\
    \u9593 \u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t- find, size\r\n\t\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\t\u7A7A\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\r\n# \u89E3\u8AAC\r\nUnionFind \u306E\u7D4C\u8DEF\u5727\u7E2E\
    \u306F\u884C\u308F\u305A\u30DE\u30FC\u30B8\u30C6\u30AF\u306E\u307F\u7528\u3044\
    \u308B\u3068 1 \u30AF\u30A8\u30EA\u3042\u305F\u308A\u306B O(log n) \u7B87\u6240\
    \u306E\u8981\u7D20\u3057\u304B\u95A2\u4FC2\u3057\u306A\u3044\r\n\u8981\u7D20 i\
    \ \u306B\u5BFE\u5FDC\u3059\u308B dat[i] \u306F\u3001\u975E\u8CA0\u306E\u3068\u304D\
    \u89AA\u306E\u8981\u7D20\u756A\u53F7\u3001\u8CA0\u306E\u3068\u304D\u81EA\u8EAB\
    \u304C\u4EE3\u8868\u5143\u304B\u3064 -{\u96C6\u5408\u306E\u8981\u7D20\u6570} \u3092\
    \u8868\u3059\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\n\tclass PARRAY: \u914D\u5217\
    \u6570\u6307\u5B9A\u306E\u7121\u3044\u5B8C\u5168\u6C38\u7D9A\u914D\u5217(\u6271\
    \u3046\u8981\u7D20\u306E\u578B\u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570 ex. int)\
    \ 6 \u5206\u6728\u306B\u3059\u308B\u3068\u901F\u3044\u6C17\u304C\u3059\u308B\r\
    \n>\r\n\r\n\u5B8C\u5168\u6C38\u7D9A\u914D\u5217( m \u5206\u6728)\u306E\u8A08\u7B97\
    \u91CF\u3092\u6B21\u306E\u3088\u3046\u306B\u4EEE\u5B9A\r\n\t- \u30A2\u30AF\u30BB\
    \u30B9\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_m n)\r\n\t\t\u7A7A\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t- \u66F4\u65B0\r\n\t\t\u6642\u9593/\u7A7A\u9593\
    \u8A08\u7B97\u91CF: O(m log_m n)\r\n\r\nPersistentUnionFind()\r\n\t\u6642\u9593\
    /\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5168\u3066\u306E\u8981\u7D20\
    \u304C\u81EA\u8EAB\u306E\u307F\u304B\u3089\u306A\u308B\u96C6\u5408\u306B\u5C5E\
    \u3057\u3066\u3044\u308B\u72B6\u614B\u3067\u521D\u671F\u5316\r\n\r\nsize_type\
    \ find(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_2 n log_m\
    \ n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20 x \u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\r\n\r\
    \nsize_type size(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_2\
    \ n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\
    \ x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \r\n\r\nPersistentUnionFind unite(size_type x, size_type y) const\r\n\t\u6642\u9593\
    /\u7A7A\u9593 \u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\u8981\u7D20 x \u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u3068\u8981\u7D20 y \u304C\u5C5E\u3059\u308B\u96C6\
    \u5408\u3092\u4F75\u5408\u3057\u305F\u72B6\u614B\u3092\u8FD4\u3059\r\n\r\nvoid\
    \ destructive_unite(size_type x, size_type y)\r\n\t\u6642\u9593/\u7A7A\u9593 \u8A08\
    \u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\u8981\u7D20 x \u304C\u5C5E\u3059\u308B\
    \u96C6\u5408\u3068\u8981\u7D20 y \u304C\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\
    \u5408\u3057\u305F\u72B6\u614B\u3092\u8FD4\u3059\r\n\t\u64CD\u4F5C\u524D\u306E\
    \u72B6\u614B\u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u306A\u304F\u306A\u308B\
    \u306E\u3067\u6CE8\u610F(\u904E\u53BB\u306E\u72B6\u614B\u306B\u30A2\u30AF\u30BB\
    \u30B9\u3057\u305F\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9)\r\n\r\
    \nbool issame(size_type x, size_type y) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(m log_2 n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\
    \u7D20 x, y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\r\n\r\nprivate:\r\nstd::pair<size_type, value_type>\
    \ find_sub(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_2 n\
    \ log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20 x\
    \ \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306B\u3064\u3044\u3066 {\u4EE3\u8868\u5143\
    , \u8981\u7D20\u6570} \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/hotman78/items/9c643feae1de087e6fc5,\
    \ 2020/09/25\r\n*/\r\n\r\n#include <cstdint>\r\n#include <type_traits>\r\n#include\
    \ <utility>\r\n\r\ntemplate<class PARRAY>\r\nstruct PersistentUnionFind {\r\n\t\
    using value_type = typename PARRAY::value_type;\r\n\tstatic_assert(std::is_signed<value_type>::value\
    \ == true);\r\n\tusing size_type = std::uint_fast32_t;\r\n\t\r\nprivate:\r\n\t\
    PARRAY dat; // non-negative: par, negative: is root and group size\r\n\t\r\npublic:\r\
    \n\tPersistentUnionFind() : dat(-1) {}\r\n\t\r\nprivate:\r\n\tPersistentUnionFind(const\
    \ PARRAY & dat) : dat(dat) {}\r\n\t\r\npublic:\r\n\tsize_type find(size_type x)\
    \ const {\r\n\t\treturn find_sub(x).first;\r\n\t}\r\n\t\r\n\tsize_type size(size_type\
    \ x) const {\r\n\t\treturn find_sub(x).second;\r\n\t}\r\n\t\r\nprivate:\r\n\t\
    std::pair<size_type, value_type> find_sub(size_type x) const {\r\n\t\tvalue_type\
    \ d;\r\n\t\tfor (d = dat.get(x); d >= 0; d = dat.get(x)) x = d;\r\n\t\treturn\
    \ {x, -d};\r\n\t}\r\n\t\r\npublic:\r\n\tPersistentUnionFind unite(size_type x,\
    \ size_type y) const {\r\n\t\tif (x == y) return *this;\r\n\t\tstd::pair<size_type,\
    \ value_type> px = find_sub(x), py = find_sub(y);\r\n\t\tif (px.first == py.first)\
    \ return *this;\r\n\t\tif (px.second > py.second) std::swap(px, py);\r\n\t\treturn\
    \ dat.set(px.first, py.first).set(py.first, -(px.second + py.second));\r\n\t}\r\
    \n\t\r\n\tvoid destructive_unite(size_type x, size_type y) {\r\n\t\tstd::pair<size_type,\
    \ value_type> px = find_sub(x), py = find_sub(y);\r\n\t\tif (px.first == py.first)\
    \ return;\r\n\t\tif (px.second > py.second) std::swap(px, py);\r\n\t\tdat.destructive_set(px.first,\
    \ py.first);\r\n\t\tdat.destructive_set(py.first, -(px.second + py.second));\r\
    \n\t}\r\n\t\r\n\tbool issame(size_type x, size_type y) const {\r\n\t\treturn x\
    \ == y ? true : find(x) == find(y);\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP\r\n#define INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/26\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\u6C38\
    \u7D9A UnionFind\r\nUnionFind \u3067\u904E\u53BB\u306E\u4EFB\u610F\u306E\u72B6\
    \u614B\u3092\u898B\u308B or \u64CD\u4F5C\u53EF\u80FD\r\n\r\n\u6DFB\u5B57\u306E\
    \u7BC4\u56F2\u3092 [0, n), \u5B8C\u5168\u6C38\u7D9A\u914D\u5217\u306E\u5185\u90E8\
    \u3092 m \u5206\u6728\u3068\u3057\u305F\u3068\u304D\u3001\r\n\t- unite\r\n\t\t\
    \u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t- find,\
    \ size\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\t\u7A7A\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\r\n# \u89E3\u8AAC\r\nUnionFind \u306E\u7D4C\
    \u8DEF\u5727\u7E2E\u306F\u884C\u308F\u305A\u30DE\u30FC\u30B8\u30C6\u30AF\u306E\
    \u307F\u7528\u3044\u308B\u3068 1 \u30AF\u30A8\u30EA\u3042\u305F\u308A\u306B O(log\
    \ n) \u7B87\u6240\u306E\u8981\u7D20\u3057\u304B\u95A2\u4FC2\u3057\u306A\u3044\r\
    \n\u8981\u7D20 i \u306B\u5BFE\u5FDC\u3059\u308B dat[i] \u306F\u3001\u975E\u8CA0\
    \u306E\u3068\u304D\u89AA\u306E\u8981\u7D20\u756A\u53F7\u3001\u8CA0\u306E\u3068\
    \u304D\u81EA\u8EAB\u304C\u4EE3\u8868\u5143\u304B\u3064 -{\u96C6\u5408\u306E\u8981\
    \u7D20\u6570} \u3092\u8868\u3059\r\n\r\n# \u4ED5\u69D8\r\ntemplate<\r\n\tclass\
    \ PARRAY: \u914D\u5217\u6570\u6307\u5B9A\u306E\u7121\u3044\u5B8C\u5168\u6C38\u7D9A\
    \u914D\u5217(\u6271\u3046\u8981\u7D20\u306E\u578B\u306F\u7B26\u53F7\u4ED8\u304D\
    \u6574\u6570 ex. int) 6 \u5206\u6728\u306B\u3059\u308B\u3068\u901F\u3044\u6C17\
    \u304C\u3059\u308B\r\n>\r\n\r\n\u5B8C\u5168\u6C38\u7D9A\u914D\u5217( m \u5206\u6728\
    )\u306E\u8A08\u7B97\u91CF\u3092\u6B21\u306E\u3088\u3046\u306B\u4EEE\u5B9A\r\n\t\
    - \u30A2\u30AF\u30BB\u30B9\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_m n)\r\
    \n\t\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t- \u66F4\u65B0\r\n\t\t\u6642\
    \u9593/\u7A7A\u9593\u8A08\u7B97\u91CF: O(m log_m n)\r\n\r\nPersistentUnionFind()\r\
    \n\t\u6642\u9593/\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5168\u3066\u306E\
    \u8981\u7D20\u304C\u81EA\u8EAB\u306E\u307F\u304B\u3089\u306A\u308B\u96C6\u5408\
    \u306B\u5C5E\u3057\u3066\u3044\u308B\u72B6\u614B\u3067\u521D\u671F\u5316\r\n\r\
    \nsize_type find(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(m log_2\
    \ n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\
    \ x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\
    \r\n\r\nsize_type size(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(m log_2 n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\
    \u7D20 x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\r\n\r\nPersistentUnionFind unite(size_type x, size_type y) const\r\n\t\u6642\
    \u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\u8981\u7D20\
    \ x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u3068\u8981\u7D20 y \u304C\u5C5E\u3059\
    \u308B\u96C6\u5408\u3092\u4F75\u5408\u3057\u305F\u72B6\u614B\u3092\u8FD4\u3059\
    \r\n\r\nvoid destructive_unite(size_type x, size_type y)\r\n\t\u6642\u9593/\u7A7A\
    \u9593 \u8A08\u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\u8981\u7D20 x \u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u3068\u8981\u7D20 y \u304C\u5C5E\u3059\u308B\u96C6\u5408\
    \u3092\u4F75\u5408\u3057\u305F\u72B6\u614B\u3092\u8FD4\u3059\r\n\t\u64CD\u4F5C\
    \u524D\u306E\u72B6\u614B\u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u306A\u304F\
    \u306A\u308B\u306E\u3067\u6CE8\u610F(\u904E\u53BB\u306E\u72B6\u614B\u306B\u30A2\
    \u30AF\u30BB\u30B9\u3057\u305F\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\
    \u7FA9)\r\n\r\nbool issame(size_type x, size_type y) const\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(m log_2 n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u8981\u7D20 x, y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\
    \u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\r\n\r\nprivate:\r\nstd::pair<size_type,\
    \ value_type> find_sub(size_type x) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(m log_2 n log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\
    \u7D20 x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306B\u3064\u3044\u3066 {\u4EE3\u8868\
    \u5143, \u8981\u7D20\u6570} \u3092\u8FD4\u3059\r\n\r\n# \u53C2\u8003\r\nhttps://qiita.com/hotman78/items/9c643feae1de087e6fc5,\
    \ 2020/09/25\r\n*/\r\n\r\n#include <cstdint>\r\n#include <type_traits>\r\n#include\
    \ <utility>\r\n\r\ntemplate<class PARRAY>\r\nstruct PersistentUnionFind {\r\n\t\
    using value_type = typename PARRAY::value_type;\r\n\tstatic_assert(std::is_signed<value_type>::value\
    \ == true);\r\n\tusing size_type = std::uint_fast32_t;\r\n\t\r\nprivate:\r\n\t\
    PARRAY dat; // non-negative: par, negative: is root and group size\r\n\t\r\npublic:\r\
    \n\tPersistentUnionFind() : dat(-1) {}\r\n\t\r\nprivate:\r\n\tPersistentUnionFind(const\
    \ PARRAY & dat) : dat(dat) {}\r\n\t\r\npublic:\r\n\tsize_type find(size_type x)\
    \ const {\r\n\t\treturn find_sub(x).first;\r\n\t}\r\n\t\r\n\tsize_type size(size_type\
    \ x) const {\r\n\t\treturn find_sub(x).second;\r\n\t}\r\n\t\r\nprivate:\r\n\t\
    std::pair<size_type, value_type> find_sub(size_type x) const {\r\n\t\tvalue_type\
    \ d;\r\n\t\tfor (d = dat.get(x); d >= 0; d = dat.get(x)) x = d;\r\n\t\treturn\
    \ {x, -d};\r\n\t}\r\n\t\r\npublic:\r\n\tPersistentUnionFind unite(size_type x,\
    \ size_type y) const {\r\n\t\tif (x == y) return *this;\r\n\t\tstd::pair<size_type,\
    \ value_type> px = find_sub(x), py = find_sub(y);\r\n\t\tif (px.first == py.first)\
    \ return *this;\r\n\t\tif (px.second > py.second) std::swap(px, py);\r\n\t\treturn\
    \ dat.set(px.first, py.first).set(py.first, -(px.second + py.second));\r\n\t}\r\
    \n\t\r\n\tvoid destructive_unite(size_type x, size_type y) {\r\n\t\tstd::pair<size_type,\
    \ value_type> px = find_sub(x), py = find_sub(y);\r\n\t\tif (px.first == py.first)\
    \ return;\r\n\t\tif (px.second > py.second) std::swap(px, py);\r\n\t\tdat.destructive_set(px.first,\
    \ py.first);\r\n\t\tdat.destructive_set(py.first, -(px.second + py.second));\r\
    \n\t}\r\n\t\r\n\tbool issame(size_type x, size_type y) const {\r\n\t\treturn x\
    \ == y ? true : find(x) == find(y);\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2020-09-26 12:14:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/PersistentUnionFind.test.cpp
documentation_of: DataStructure/PersistentUnionFind.hpp
layout: document
redirect_from:
- /library/DataStructure/PersistentUnionFind.hpp
- /library/DataStructure/PersistentUnionFind.hpp.html
title: DataStructure/PersistentUnionFind.hpp
---
