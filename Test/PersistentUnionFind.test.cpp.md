---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.hpp
    title: DataStructure/PersistentArray.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentUnionFind.hpp
    title: DataStructure/PersistentUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"Test/PersistentUnionFind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\r\n#line 1 \"DataStructure/PersistentArray.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/09/25\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\
    \u6C38\u7D9A\u914D\u5217\r\n\r\n\u4F7F\u7528\u30E1\u30E2\u30EA\u91CF\u304C\u591A\
    \u3044\r\n\r\n\u6DFB\u5B57\u306E\u7BC4\u56F2\u3092 [0, n), m \u5206\u6728\u3068\
    \u3057\u305F\u3068\u304D\u3001\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: O(n log_m\
    \ n)\r\n\t\u30A2\u30AF\u30BB\u30B9, \u66F4\u65B0 \u6642\u9593/\u7A7A\u9593 \u8A08\
    \u7B97\u91CF: O(log_m n)\r\n\r\n\u4EFB\u610F\u306E\u6DFB\u5B57\u306B\u30A2\u30AF\
    \u30BB\u30B9\u53EF\u80FD\u3060\u304C\u8CA0\u306E\u6DFB\u5B57\u306B\u306F\u5BFE\
    \u5FDC\u3057\u3066\u3044\u306A\u3044(\u307B\u307C\u6B63\u3057\u304F\u52D5\u304F\
    \u304C\u52D5\u4F5C\u304C\u9045\u305D\u3046)\r\n\r\n# \u89E3\u8AAC\r\n\u6DFB\u5B57\
    \u306E\u5927\u304D\u3055\u9806\u306B\u4E26\u3079\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u305F\u3081\u3001\u6DFB\u5B57\u3092 m \u9032\u8868\u8A18\u3057\u305F\u3068\
    \u304D\u306E\u4E0B\u306E\u6841\u304B\u3089\u898B\u3066\u3044\u304D\u8981\u7D20\
    \u3092\u4E26\u3079\u308B\u3002\r\n\u3053\u308C\u306B\u3088\u308A\u3001\u6DFB\u5B57\
    \u306E\u7BC4\u56F2\u3092\u4E8B\u524D\u306B\u6307\u5B9A\u3059\u308B\u5FC5\u8981\
    \u304C\u306A\u304F\u306A\u3063\u3066\u5B09\u3057\u3044\r\n\r\n# \u4ED5\u69D8\r\
    \ntemplate<\r\n\ttypename T: \u6271\u3046\u30C7\u30FC\u30BF\u306E\u578B\r\n\t\
    std::size_t M: \u5185\u90E8\u69CB\u9020\u3092 M \u5206\u6728\u306B\u3059\u308B\
    \r\n>\r\n\r\nPersistentArray(const_reference def_val = 0)\r\n\t\u6642\u9593/\u7A7A\
    \u9593 \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u304C\u7121\u9650\
    \u306E\u6C38\u7D9A\u914D\u5217\u3092\u4F5C\u6210, \u521D\u671F\u5024\u306F def_val\r\
    \n\r\nPersistentArray set(size_type k, const_reference x) const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(m log_m k)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(m\
    \ log_m k)\r\n\tk \u756A\u76EE(0 \\leq k) \u306E\u8981\u7D20\u3092 x \u306B\u66F8\
    \u304D\u63DB\u3048\u305F\u914D\u5217\u3092\u8FD4\u3059\r\n\r\nvoid destructive_set(size_type\
    \ k, const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log_m k)\r\
    \n\t\u7A7A\u9593\u8A08\u7B97\u91CF: O(m log_m k)\r\n\tk \u756A\u76EE(0 \\leq k)\
    \ \u306E\u8981\u7D20\u3092 x \u306B\u66F8\u304D\u63DB\u3048\u308B\r\n\t\u64CD\u4F5C\
    \u524D\u306E\u914D\u5217\u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u306A\u304F\
    \u306A\u308B\u306E\u3067\u6CE8\u610F(\u904E\u53BB\u306E\u72B6\u614B\u306B\u30A2\
    \u30AF\u30BB\u30B9\u3057\u305F\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\
    \u7FA9)\r\n\t\r\nconst_reference get(size_type k) const\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(log_m n)\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\
    \n\tk \u756A\u76EE(0 \\leq k) \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\n# \u53C2\
    \u8003\r\nhttps://trap.jp/post/663/, 2020/04/10\r\nhttps://qiita.com/hotman78/items/9c643feae1de087e6fc5,\
    \ 2020/09/25\r\n*/\r\n\r\n#include <memory>\r\n#include <utility>\r\n\r\ntemplate<typename\
    \ T, std::size_t M>\r\nstruct PersistentArray {\r\n\tstatic_assert(M > 0);\r\n\
    \tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\t\
    using size_type = std::size_t;\r\n\t\r\nprivate:\r\n\tstruct Node;\r\n\tusing\
    \ sptr_type = std::shared_ptr<Node>;\r\n\tusing node_ptr = Node *;\r\n\tusing\
    \ const_ptr = const Node *;\r\n\tstruct Node {\r\n\t\tsptr_type childs[M];\r\n\
    \t\tvalue_type val;\r\n\t\tNode(const_reference val) : val(val) {}\r\n\t};\r\n\
    \t\r\nprivate:\r\n\tsptr_type root;\r\n\tvalue_type def_val;\r\n\t\r\nprivate:\r\
    \n\tPersistentArray(sptr_type && root, const_reference def_val) : root(root),\
    \ def_val(def_val) {}\r\n\t\r\npublic:\r\n\tPersistentArray(const_reference def_val\
    \ = 0) : root(nullptr), def_val(def_val) {}\r\n\t\r\n\tPersistentArray set(size_type\
    \ k, const_reference x) const {\r\n\t\tconst_ptr node = root.get();\r\n\t\tsptr_type\
    \ new_root = std::make_shared<Node>(k == 0 ? x : (node ? node->val : def_val));\r\
    \n\t\tnode_ptr new_node = new_root.get();\r\n\t\tfor (; k > 0; k /= M) {\r\n\t\
    \t\tconst size_type m = k % M;\r\n\t\t\tif (node) {\r\n\t\t\t\tfor (size_type\
    \ i = 0; i < M; ++i) {\r\n\t\t\t\t\tif (i != m) new_node->childs[i] = node->childs[i];\r\
    \n\t\t\t\t}\r\n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k < M ? x\
    \ : (node->childs[m] ? node->childs[m]->val : def_val));\r\n\t\t\t\tnode = node->childs[m].get();\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tnew_node->childs[m] = std::make_shared<Node>(k\
    \ < M ? x : def_val);\r\n\t\t\t}\r\n\t\t\tnew_node = new_node->childs[m].get();\r\
    \n\t\t}\r\n\t\tif (node) {\r\n\t\t\tfor (size_type i = 0; i < M; ++i) new_node->childs[i]\
    \ = node->childs[i];\r\n\t\t}\r\n\t\treturn {std::move(new_root), def_val};\r\n\
    \t}\r\n\t\r\n\tvoid destructive_set(size_type k, const_reference x) {\r\n\t\t\
    if (!root) root = std::make_shared<Node>(k == 0 ? x : def_val);\r\n\t\tnode_ptr\
    \ node = root.get();\r\n\t\tfor (; k >= M; k /= M) {\r\n\t\t\tconst size_type\
    \ m = k % M;\r\n\t\t\tif (!node->childs[m]) node->childs[m] = std::make_shared<Node>(def_val);\r\
    \n\t\t\tnode = node->childs[m].get();\r\n\t\t}\r\n\t\tif (node->childs[k]) node->childs[k]->val\
    \ = x;\r\n\t\telse node->childs[k] = std::make_shared<Node>(x);\r\n\t}\r\n\t\r\
    \n\tconst_reference get(size_type k) const {\r\n\t\tconst_ptr node = root.get();\r\
    \n\t\twhile (k > 0 && node) {\r\n\t\t\tnode = node->childs[k % M].get();\r\n\t\
    \t\tk /= M;\r\n\t\t}\r\n\t\treturn k == 0 && node ? node->val : def_val;\r\n\t\
    }\r\n};\r\n\r\n\n#line 1 \"DataStructure/PersistentUnionFind.hpp\"\n\n\n\r\n/*\r\
    \nlast-updated: 2020/09/26\r\n\r\n# \u6982\u8981\r\n\u5B8C\u5168\u6C38\u7D9A UnionFind\r\
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
    \ 2020/09/25\r\n*/\r\n\r\n#include <cstdint>\r\n#include <type_traits>\r\n#line\
    \ 75 \"DataStructure/PersistentUnionFind.hpp\"\n\r\ntemplate<class PARRAY>\r\n\
    struct PersistentUnionFind {\r\n\tusing value_type = typename PARRAY::value_type;\r\
    \n\tstatic_assert(std::is_signed<value_type>::value == true);\r\n\tusing size_type\
    \ = std::uint_fast32_t;\r\n\t\r\nprivate:\r\n\tPARRAY dat; // non-negative: par,\
    \ negative: is root and group size\r\n\t\r\npublic:\r\n\tPersistentUnionFind()\
    \ : dat(-1) {}\r\n\t\r\nprivate:\r\n\tPersistentUnionFind(const PARRAY & dat)\
    \ : dat(dat) {}\r\n\t\r\npublic:\r\n\tsize_type find(size_type x) const {\r\n\t\
    \treturn find_sub(x).first;\r\n\t}\r\n\t\r\n\tsize_type size(size_type x) const\
    \ {\r\n\t\treturn find_sub(x).second;\r\n\t}\r\n\t\r\nprivate:\r\n\tstd::pair<size_type,\
    \ value_type> find_sub(size_type x) const {\r\n\t\tvalue_type d;\r\n\t\tfor (d\
    \ = dat.get(x); d >= 0; d = dat.get(x)) x = d;\r\n\t\treturn {x, -d};\r\n\t}\r\
    \n\t\r\npublic:\r\n\tPersistentUnionFind unite(size_type x, size_type y) const\
    \ {\r\n\t\tif (x == y) return *this;\r\n\t\tstd::pair<size_type, value_type> px\
    \ = find_sub(x), py = find_sub(y);\r\n\t\tif (px.first == py.first) return *this;\r\
    \n\t\tif (px.second > py.second) std::swap(px, py);\r\n\t\treturn dat.set(px.first,\
    \ py.first).set(py.first, -(px.second + py.second));\r\n\t}\r\n\t\r\n\tvoid destructive_unite(size_type\
    \ x, size_type y) {\r\n\t\tstd::pair<size_type, value_type> px = find_sub(x),\
    \ py = find_sub(y);\r\n\t\tif (px.first == py.first) return;\r\n\t\tif (px.second\
    \ > py.second) std::swap(px, py);\r\n\t\tdat.destructive_set(px.first, py.first);\r\
    \n\t\tdat.destructive_set(py.first, -(px.second + py.second));\r\n\t}\r\n\t\r\n\
    \tbool issame(size_type x, size_type y) const {\r\n\t\treturn x == y ? true :\
    \ find(x) == find(y);\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/PersistentUnionFind.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\
    \n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing PUF = PersistentUnionFind<PersistentArray<int,\
    \ 6>>;\r\n\tstd::vector<PUF> hist(Q + 1);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i)\
    \ {\r\n\t\tint t, k, u, v;\r\n\t\tscanf(\"%d %d %d %d\", &t, &k, &u, &v);\r\n\t\
    \t++k;\r\n\t\tif (t == 0) hist[i + 1] = (hist[k].unite(u, v));\r\n\t\telse printf(\"\
    %d\\n\", hist[k].issame(u, v));\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n\r\n#include \"DataStructure/PersistentArray.hpp\"\r\n#include \"DataStructure/PersistentUnionFind.hpp\"\
    \r\n\r\n#include <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tusing PUF = PersistentUnionFind<PersistentArray<int,\
    \ 6>>;\r\n\tstd::vector<PUF> hist(Q + 1);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i)\
    \ {\r\n\t\tint t, k, u, v;\r\n\t\tscanf(\"%d %d %d %d\", &t, &k, &u, &v);\r\n\t\
    \t++k;\r\n\t\tif (t == 0) hist[i + 1] = (hist[k].unite(u, v));\r\n\t\telse printf(\"\
    %d\\n\", hist[k].issame(u, v));\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/PersistentArray.hpp
  - DataStructure/PersistentUnionFind.hpp
  isVerificationFile: true
  path: Test/PersistentUnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 12:14:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PersistentUnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/PersistentUnionFind.test.cpp
- /verify/Test/PersistentUnionFind.test.cpp.html
title: Test/PersistentUnionFind.test.cpp
---
