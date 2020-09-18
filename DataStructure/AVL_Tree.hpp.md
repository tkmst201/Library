---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AVL_Tree.test.cpp
    title: Test/AVL_Tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://ja.wikipedia.org/wiki/AVL%E6%9C%A8,
  bundledCode: "#line 1 \"DataStructure/AVL_Tree.hpp\"\n\n\n\r\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\n/*\r\nlast-updated: 2020/08/29\r\n\r\n# \u4ED5\u69D8\
    \r\n\u30A4\u30C6\u30EC\u30FC\u30BF\u306F\u5B9F\u88C5\u3057\u3066\u3044\u306A\u3044\
    \u306E\u3067\u30DD\u30A4\u30F3\u30BF\u3067\u30CE\u30FC\u30C9\u3092\u6271\u3046\
    \r\n\r\nAVL_Tree() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\
    \u306E\u6728\u3092\u4F5C\u6210\u3059\u308B\r\n\r\nAVL_Tree(const AVL_Tree &rhs)\
    \ :\r\nAVL_Tree &operator=(const AVL_Tree &rhs) :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(n log n)\r\n\t\u6728\u306E\u30B3\u30D4\u30FC\u3092\u884C\u3046\r\
    \n\tenumerate() \u3067\u5F97\u305F\u5404\u8981\u7D20\u3092 insert() \u3057\u3066\
    \u3044\u308B\u306E\u3067\u9045\u3044\r\n\r\nbool empty() const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6728\u304C\u7A7A\u304C\u3069\u3046\u304B\u5224\
    \u5B9A\u3059\u308B\r\n\r\nstd::size_t size() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u6728\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\n\
    void clear() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u5168\u3066\
    \u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\r\nstd::vector<T> enumerate()\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u6728\u306E\u5168\
    \u3066\u306E\u8981\u7D20\u3092\u6607\u9806\u306B std::vector \u306B\u5165\u308C\
    \u3066\u8FD4\u3059\r\n\r\nNode *begin() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u6700\u3082\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3092\u8FD4\u3059\r\n\r\nNode *end() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u6700\u3082\u5927\u304D\u3044\u8981\u7D20\u306E\u6B21\u306E\
    \u8981\u7D20(?)\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *find(const\
    \ T &x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20\
    \ x \u3092\u691C\u7D22\u3057\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\t\u8907\u6570\u5B58\u5728\u3059\u308B\u5834\u5408\u30DD\u30A4\u30F3\
    \u30BF\u3067\u6700\u5C0F\u306E\u30DD\u30A4\u30F3\u30BF\r\n\r\nNode *insert(const\
    \ T &x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20\
    \ x \u3092\u633F\u5165\u3057\u3001\u633F\u5165\u5F8C\u306E\u8981\u7D20\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *erase(const T &x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20 x \u3092\u524A\u9664\
    \u3059\u308B\r\n\r\nNode *erase(Node *Q) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\t\u30DD\u30A4\u30F3\u30BF Q \u306E\u8981\u7D20\u3092\u524A\
    \u9664\u3059\u308B\r\n\r\nNode *lower_bound(const T &x) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(log n)\r\n\tx \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\
    \u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *upper_bound(const\
    \ T &x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\tx \u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3092\u8FD4\u3059\r\n\r\nNode *k_th_smallest(std::size_t k) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\tk \u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\
    \nNode *k_th_largest(std::size_t k) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\tk \u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *next(Node *Q) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tQ \u306E\u6B21\u306B\u5927\u304D\u3044\
    \u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *prev(Node\
    \ *Q) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tQ \u3088\u308A\
    \ 1 \u3064\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\r\n# \u53C2\u8003\r\nhttps://ja.wikipedia.org/wiki/AVL%E6%9C%A8, 2019/11/19\r\
    \n*/\r\n\r\ntemplate<typename T> struct AVL_Tree {\r\npublic:\r\n\t\r\n\t// private\
    \ \u306B, \u3057\u305F\u304F\u306A\u3044\u2026??\r\n\tstruct Node {\r\n\t\tT value;\r\
    \n\t\tNode *child[2] {}, *par = nullptr;\r\n\t\tbool is_r;\r\n\t\tstd::size_t\
    \ size[2] {}, height[2] {};\r\n\t\t\r\n\t\tNode(T x, Node *par, bool is_r)\r\n\
    \t\t\t: value(x), par(par), is_r(is_r) {}\r\n\t};\r\n\t\r\n\tAVL_Tree() : size_(0),\
    \ root_node(nullptr) {}\r\n\t~AVL_Tree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\t\
    AVL_Tree(const AVL_Tree &rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tAVL_Tree\
    \ &operator=(const AVL_Tree &rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tthis->clear();\r\
    \n\t\t\tstd::vector<T> tmp = rhs.enumerate();\r\n\t\t\tfor (const T &elm : tmp)\
    \ this->insert(elm);\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tbool empty()\
    \ const {\r\n\t\treturn size_ == 0;\r\n\t}\r\n\t\r\n\tstd::size_t size() const\
    \ {\r\n\t\treturn size_;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tclear_dfs(root_node);\r\
    \n\t\troot_node = nullptr;\r\n\t\tsize_ = 0;\r\n\t\te_ptr[0] = e_ptr[1] = nullptr;\r\
    \n\t}\r\n\t\r\n\tstd::vector<T> enumerate() const {\r\n\t\tstd::vector<T> elements;\r\
    \n\t\telements.reserve(size_);\r\n\t\tenumerate_dfs(root_node, elements);\r\n\t\
    \treturn elements;\r\n\t}\r\n\t\r\n\tNode *begin() const {\r\n\t\treturn begin_();\r\
    \n\t}\r\n\t\r\n\tNode *end() const {\r\n\t\treturn end_();\r\n\t}\r\n\t\r\n\t\
    Node *find(const T &x) {\r\n\t\treturn find_(x);\r\n\t}\r\n\t\r\n\tNode *insert(const\
    \ T &x) {\r\n\t\tsize_++;\r\n\t\tbool ef[2] {};\r\n\t\t\r\n\t\tNode *Q = root_node,\
    \ *R = nullptr;\r\n\t\tbool d = false;\r\n\t\twhile (Q) {\r\n\t\t\tR = Q;\r\n\t\
    \t\td = Q->value <= x;\r\n\t\t\tef[!d] = true;\r\n\t\t\tQ = Q->child[d];\r\n\t\
    \t}\r\n\t\tQ = new Node(x, R, d);\r\n\t\tif (!ef[0]) e_ptr[0] = Q;\r\n\t\tif (!ef[1])\
    \ e_ptr[1] = Q;\r\n\t\t\r\n\t\tif (R) {\r\n\t\t\tR->size[d] = 1;\r\n\t\t\tR->height[d]\
    \ = 1;\r\n\t\t\tR->child[d] = Q;\r\n\t\t\tupdate(R);\r\n\t\t}\r\n\t\telse root_node\
    \ = Q;\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *erase(const T &x) {\r\n\t\tNode\
    \ *Q = find_(x);\r\n\t\tif (Q) return erase_(Q);\r\n\t\treturn end_();\r\n\t}\r\
    \n\t\r\n\tNode *erase(Node *Q) {\r\n\t\tif (Q) return erase_(Q);\r\n\t\treturn\
    \ end_();\r\n\t}\r\n\t\r\n\tNode *lower_bound(const T &x) const {\r\n\t\treturn\
    \ lower_bound_(x);\r\n\t}\r\n\t\r\n\tNode *upper_bound(const T &x) const {\r\n\
    \t\treturn upper_bound_(x);\r\n\t}\r\n\t\r\n\tNode *k_th_smallest(std::size_t\
    \ k) const {\r\n\t\treturn k_th_smallest_(k);\r\n\t}\r\n\t\r\n\tNode *k_th_largest(std::size_t\
    \ k) const {\r\n\t\treturn k_th_largest_(k);\r\n\t}\r\n\t\r\n\tNode *next(Node\
    \ *Q) const {\r\n\t\tif (Q) return move(Q, true);\r\n\t\treturn e_ptr[0];\r\n\t\
    }\r\n\t\r\n\tNode *prev(Node *Q) const {\r\n\t\tif (Q) return move(Q, false);\r\
    \n\t\treturn e_ptr[1];\r\n\t}\r\n\t\r\nprivate:\r\n\tstd::size_t size_ {};\r\n\
    \tNode *root_node {};\r\n\tNode *e_ptr[2] {};\r\n\t\r\n\tvoid clear_dfs(Node*\
    \ Q) {\r\n\t\tif (!Q) return;\r\n\t\tclear_dfs(Q->child[0]);\r\n\t\tclear_dfs(Q->child[1]);\r\
    \n\t\tdelete Q;\r\n\t}\r\n\t\r\n\tvoid enumerate_dfs(const Node *Q, std::vector<T>\
    \ &elements) const {\r\n\t\tif (!Q) return;\r\n\t\tenumerate_dfs(Q->child[0],\
    \ elements);\r\n\t\telements.push_back(Q->value);\r\n\t\tenumerate_dfs(Q->child[1],\
    \ elements);\r\n\t}\r\n\t\r\n\t Node *begin_() const {\r\n\t\treturn e_ptr[0];\r\
    \n\t}\r\n\t\r\n\tNode *end_() const {\r\n\t\treturn nullptr;\r\n\t}\r\n\t\r\n\t\
    Node *rotate(Node *Q, bool d) {\r\n\t\tNode *R = Q->par, *P = Q->child[!d], *B\
    \ = P->child[d];\r\n\t\t\r\n\t\tif (R) R->child[Q->is_r] = P;\r\n\t\telse root_node\
    \ = P;\r\n\t\t\r\n\t\tQ->child[!d] = B;\r\n\t\tP->child[d] = Q;\r\n\t\t\r\n\t\t\
    if (B) {\r\n\t\t\tB->par = Q;\r\n\t\t\tB->is_r = !d;\r\n\t\t}\r\n\t\t\r\n\t\t\
    P->par = Q->par;\r\n\t\tP->is_r = Q->is_r;\r\n\t\t\r\n\t\tQ->par = P;\r\n\t\t\
    Q->is_r = d;\r\n\t\tQ->size[!d] = P->size[d];\r\n\t\tQ->height[!d] = P->height[d];\r\
    \n\t\t\r\n\t\tP->size[d] = Q->size[0] + Q->size[1] + 1;\r\n\t\tP->height[d] =\
    \ std::max(Q->height[0], Q->height[1]) + 1;\r\n\t\treturn P;\r\n\t}\r\n\t\r\n\t\
    void update(Node *Q) {\r\n\t\tbool done = false;\r\n\t\twhile (true) {\r\n\t\t\
    \tif (!done && std::abs(static_cast<int>(Q->height[0]) - static_cast<int>(Q->height[1]))\
    \ > 1) {\r\n\t\t\t\tbool d = Q->height[0] > Q->height[1];\r\n\t\t\t\tNode *P =\
    \ Q->child[!d];\r\n\t\t\t\tif (P->height[!d] < P->height[d]) rotate(P, !d);\r\n\
    \t\t\t\tQ = rotate(Q, d);\r\n\t\t\t\tdone = true;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\
    \tNode *R = Q->par;\r\n\t\t\tif (!R) break;\r\n\t\t\tR->size[Q->is_r] = Q->size[0]\
    \ + Q->size[1] + 1;\r\n\t\t\tR->height[Q->is_r] = std::max(Q->height[0], Q->height[1])\
    \ + 1;\r\n\t\t\tQ = R;\r\n\t\t}\r\n\t}\r\n\t\r\n\tNode *find_(const T &x) {\r\n\
    \t\tNode *Q = lower_bound_(x);\r\n\t\tif (Q && Q->value != x) Q = end_();\r\n\t\
    \treturn Q;\r\n\t}\r\n\t\r\n\tNode *erase_(Node *Q) {\r\n\t\tsize_--;\r\n\t\t\
    Node *ret = next(Q), *upd = nullptr;\r\n\t\t\r\n\t\tif (Q->child[0] && Q->child[1])\
    \ {\r\n\t\t\tNode *P = Q->child[0];\r\n\t\t\twhile (P->child[1]) P = P->child[1];\r\
    \n\t\t\tQ->value = std::move(P->value);\r\n\t\t\tQ = P;\r\n\t\t}\r\n\t\t\r\n\t\
    \tNode *R = Q->par;\r\n\t\tif (R) upd = R;\r\n\t\tif (Q->child[0] || Q->child[1])\
    \ {\r\n\t\t\tNode *P = Q->child[0] ? Q->child[0] : Q->child[1];\r\n\t\t\tif (R)\
    \ {\r\n\t\t\t\tR->size[Q->is_r] = Q->size[P->is_r];\r\n\t\t\t\tR->height[Q->is_r]\
    \ = Q->height[P->is_r];\r\n\t\t\t\tR->child[Q->is_r] = P;\r\n\t\t\t\tP->par =\
    \ R;\r\n\t\t\t\tP->is_r = Q->is_r;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tP->par\
    \ = nullptr;\r\n\t\t\t\troot_node = P;\r\n\t\t\t}\r\n\t\t}\r\n\t\telse {\r\n\t\
    \t\tif (R) {\r\n\t\t\t\tR->size[Q->is_r] = 0;\r\n\t\t\t\tR->height[Q->is_r] =\
    \ 0;\r\n\t\t\t\tR->child[Q->is_r] = nullptr;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\
    \t\troot_node = nullptr;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tif (e_ptr[0] == Q)\
    \ e_ptr[0] = next(Q);\r\n\t\tif (e_ptr[1] == Q) e_ptr[1] = prev(Q);\r\n\t\tdelete\
    \ Q;\r\n\t\tif (upd) update(upd);\r\n\t\treturn ret;\r\n\t}\r\n\t\r\n\tNode *lower_bound_(const\
    \ T &x) const {\r\n\t\tNode *Q = root_node;\r\n\t\tif (!Q) return end_();\r\n\t\
    \twhile (true) {\r\n\t\t\tNode *P = Q->child[Q->value < x];\r\n\t\t\tif (!P) break;\r\
    \n\t\t\tQ = P;\r\n\t\t}\r\n\t\tif (!Q) return end_();\r\n\t\tif (Q->value < x)\
    \ Q = next(Q);\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *upper_bound_(const T &x)\
    \ const {\r\n\t\tNode *Q = root_node;\r\n\t\tif (!Q) return end_();\r\n\t\twhile\
    \ (true) {\r\n\t\t\tNode *P = Q->child[Q->value <= x];\r\n\t\t\tif (!P) break;\r\
    \n\t\t\tQ = P;\r\n\t\t}\r\n\t\tif (!Q) return end_();\r\n\t\tif (Q->value <= x)\
    \ Q = next(Q);\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *k_th_smallest_(std::size_t\
    \ k) const {\r\n\t\tif (k == 0 || size_ < k) return end_();\r\n\t\tNode *Q = root_node;\r\
    \n\t\tstd::size_t sum = 0;\r\n\t\twhile (sum < k) {\r\n\t\t\tif (sum + Q->size[0]\
    \ >= k) {\r\n\t\t\t\tQ = Q->child[0];\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tsum\
    \ += Q->size[0];\r\n\t\t\t\t++sum;\r\n\t\t\t\tif (sum != k) Q = Q->child[1];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *k_th_largest_(std::size_t\
    \ k) const {\r\n\t\tif (k == 0 || size_ < k) return end_();\r\n\t\treturn k_th_smallest_(size_\
    \ - k + 1);\r\n\t}\r\n\t\r\n\tNode *move(Node *Q, bool d) const {\r\n\t\tif (Q->child[d])\
    \ {\r\n\t\t\tQ = Q->child[d];\r\n\t\t\twhile (Q->child[!d]) Q = Q->child[!d];\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\twhile (Q && (d ^ !Q->is_r)) Q = Q->par;\r\n\t\t\
    \tif (Q) Q = Q->par;\r\n\t\t}\r\n\t\treturn Q;\r\n\t}\r\n};\r\n\r\n/*\r\nint main()\
    \ {\r\n\tAVL_Tree<int> tree;\r\n\t\r\n\tconst int queryNumber = 11;\r\n\tstd::string\
    \ str[queryNumber] = {\"clear\", \"kths\", \"kthl\", \"size\", \"print\", \"ins\"\
    , \"find\", \"era\", \"lower\", \"upper\", \"exit\"};\r\n\tstd::set<std::string>\
    \ ss;\r\n\tREP(i, queryNumber) ss.insert(str[i]);\r\n\t\r\n\twhile (true) {\r\n\
    \t\tstd::string query;\r\n\t\tstd::cin >> query;\r\n\t\t\r\n\t\tif (ss.find(query)\
    \ == ss.end()) {\r\n\t\t\tputs(\"Please input again\");\r\n\t\t\tcontinue;\r\n\
    \t\t}\r\n\t\t\r\n\t\tif (query == \"exit\") {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\t\
    if (query == \"clear\") {\r\n\t\t\ttree.clear();\r\n\t\t}\r\n\t\telse if (query\
    \ == \"size\") {\r\n\t\t\tprintf(\"size: %d\\n\", tree.size());\r\n\t\t}\r\n\t\
    \telse if (query == \"print\") {\r\n\t\t\tstd::vector<int> v = tree.enumerate();\r\
    \n\t\t\tREP(i, v.size()) printf(\"%d \", v[i]);\r\n\t\t\tputs(\"\");\r\n\t\t\t\
    \r\n\t\t}\r\n\t\telse {\r\n\t\t\tint num;\r\n\t\t\tstd::cin >> num;\r\n\t\t\t\
    if (query == \"ins\") {\r\n\t\t\t\ttree.insert(num);\r\n\t\t\t}\r\n\t\t\telse\
    \ if (query == \"find\") {\r\n\t\t\t\t\r\n\t\t\t\tstd::cout << std::boolalpha\
    \ << (bool)tree.find(num) << std::endl;\r\n\t\t\t}\r\n\t\t\telse if (query ==\
    \ \"era\") {\r\n\t\t\t\ttree.erase(num);\r\n\t\t\t}\r\n\t\t\telse if (query ==\
    \ \"lower\") {\r\n\t\t\t\tauto *p = tree.lower_bound(num);\r\n\t\t\t\twhile (p)\
    \ {\r\n\t\t\t\t\tprintf(\"%d \", p->value);\r\n\t\t\t\t\tp = tree.next(p);\r\n\
    \t\t\t\t}\r\n\t\t\t\tputs(\"\");\r\n\t\t\t}\r\n\t\t\telse if (query == \"upper\"\
    ) {\r\n\t\t\t\tauto *p = tree.upper_bound(num);\r\n\t\t\t\twhile (p) {\r\n\t\t\
    \t\t\tprintf(\"%d \", p->value);\r\n\t\t\t\t\tp = tree.next(p);\r\n\t\t\t\t}\r\
    \n\t\t\t\tputs(\"\");\r\n\t\t\t}\r\n\t\t\telse if (query == \"kths\") {\r\n\t\t\
    \t\tauto *P = tree.k_th_smallest(num);\r\n\t\t\t\tif (P) cout << P->value << endl;\r\
    \n\t\t\t}\r\n\t\t\telse if (query == \"kthl\") {\r\n\t\t\t\tauto *P = tree.k_th_largest(num);\r\
    \n\t\t\t\tif (P) cout << P->value << endl;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int>\
    \ v = tree.enumerate();\r\n\t\tREP(i, v.size()) printf(\"%d \", v[i]); puts(\"\
    \");\r\n\t\tif (!tree.empty()) printf(\"begin: %d, end: %d\\n\", tree.begin()->value,\
    \ prev(tree.end())->value);\r\n\t\t\r\n\t}\r\n\t\r\n\treturn 0;\r\n}\r\n*/\r\n\
    \r\n\n"
  code: "#ifndef INCLUDE_GUARD_AVL_TREE_HPP\r\n#define INCLUDE_GUARD_AVL_TREE_HPP\r\
    \n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n/*\r\nlast-updated: 2020/08/29\r\
    \n\r\n# \u4ED5\u69D8\r\n\u30A4\u30C6\u30EC\u30FC\u30BF\u306F\u5B9F\u88C5\u3057\
    \u3066\u3044\u306A\u3044\u306E\u3067\u30DD\u30A4\u30F3\u30BF\u3067\u30CE\u30FC\
    \u30C9\u3092\u6271\u3046\r\n\r\nAVL_Tree() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u7A7A\u306E\u6728\u3092\u4F5C\u6210\u3059\u308B\r\n\r\nAVL_Tree(const\
    \ AVL_Tree &rhs) :\r\nAVL_Tree &operator=(const AVL_Tree &rhs) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n log n)\r\n\t\u6728\u306E\u30B3\u30D4\u30FC\u3092\u884C\
    \u3046\r\n\tenumerate() \u3067\u5F97\u305F\u5404\u8981\u7D20\u3092 insert() \u3057\
    \u3066\u3044\u308B\u306E\u3067\u9045\u3044\r\n\r\nbool empty() const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6728\u304C\u7A7A\u304C\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B\r\n\r\nstd::size_t size() const :\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u6728\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\
    \n\r\nvoid clear() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u5168\
    \u3066\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\r\nstd::vector<T> enumerate()\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u6728\u306E\u5168\
    \u3066\u306E\u8981\u7D20\u3092\u6607\u9806\u306B std::vector \u306B\u5165\u308C\
    \u3066\u8FD4\u3059\r\n\r\nNode *begin() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u6700\u3082\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3092\u8FD4\u3059\r\n\r\nNode *end() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: \u0398(1)\r\n\t\u6700\u3082\u5927\u304D\u3044\u8981\u7D20\u306E\u6B21\u306E\
    \u8981\u7D20(?)\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *find(const\
    \ T &x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20\
    \ x \u3092\u691C\u7D22\u3057\u3066\u305D\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\t\u8907\u6570\u5B58\u5728\u3059\u308B\u5834\u5408\u30DD\u30A4\u30F3\
    \u30BF\u3067\u6700\u5C0F\u306E\u30DD\u30A4\u30F3\u30BF\r\n\r\nNode *insert(const\
    \ T &x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20\
    \ x \u3092\u633F\u5165\u3057\u3001\u633F\u5165\u5F8C\u306E\u8981\u7D20\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *erase(const T &x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\t\u8981\u7D20 x \u3092\u524A\u9664\
    \u3059\u308B\r\n\r\nNode *erase(Node *Q) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\t\u30DD\u30A4\u30F3\u30BF Q \u306E\u8981\u7D20\u3092\u524A\
    \u9664\u3059\u308B\r\n\r\nNode *lower_bound(const T &x) const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(log n)\r\n\tx \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\
    \u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *upper_bound(const\
    \ T &x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\tx \u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3092\u8FD4\u3059\r\n\r\nNode *k_th_smallest(std::size_t k) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\tk \u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\
    \nNode *k_th_largest(std::size_t k) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(log n)\r\n\tk \u756A\u76EE\u306B\u5927\u304D\u3044\u8981\u7D20\u306E\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *next(Node *Q) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tQ \u306E\u6B21\u306B\u5927\u304D\u3044\
    \u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nNode *prev(Node\
    \ *Q) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tQ \u3088\u308A\
    \ 1 \u3064\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\r\n# \u53C2\u8003\r\nhttps://ja.wikipedia.org/wiki/AVL%E6%9C%A8, 2019/11/19\r\
    \n*/\r\n\r\ntemplate<typename T> struct AVL_Tree {\r\npublic:\r\n\t\r\n\t// private\
    \ \u306B, \u3057\u305F\u304F\u306A\u3044\u2026??\r\n\tstruct Node {\r\n\t\tT value;\r\
    \n\t\tNode *child[2] {}, *par = nullptr;\r\n\t\tbool is_r;\r\n\t\tstd::size_t\
    \ size[2] {}, height[2] {};\r\n\t\t\r\n\t\tNode(T x, Node *par, bool is_r)\r\n\
    \t\t\t: value(x), par(par), is_r(is_r) {}\r\n\t};\r\n\t\r\n\tAVL_Tree() : size_(0),\
    \ root_node(nullptr) {}\r\n\t~AVL_Tree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\t\
    AVL_Tree(const AVL_Tree &rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tAVL_Tree\
    \ &operator=(const AVL_Tree &rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tthis->clear();\r\
    \n\t\t\tstd::vector<T> tmp = rhs.enumerate();\r\n\t\t\tfor (const T &elm : tmp)\
    \ this->insert(elm);\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tbool empty()\
    \ const {\r\n\t\treturn size_ == 0;\r\n\t}\r\n\t\r\n\tstd::size_t size() const\
    \ {\r\n\t\treturn size_;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\t\tclear_dfs(root_node);\r\
    \n\t\troot_node = nullptr;\r\n\t\tsize_ = 0;\r\n\t\te_ptr[0] = e_ptr[1] = nullptr;\r\
    \n\t}\r\n\t\r\n\tstd::vector<T> enumerate() const {\r\n\t\tstd::vector<T> elements;\r\
    \n\t\telements.reserve(size_);\r\n\t\tenumerate_dfs(root_node, elements);\r\n\t\
    \treturn elements;\r\n\t}\r\n\t\r\n\tNode *begin() const {\r\n\t\treturn begin_();\r\
    \n\t}\r\n\t\r\n\tNode *end() const {\r\n\t\treturn end_();\r\n\t}\r\n\t\r\n\t\
    Node *find(const T &x) {\r\n\t\treturn find_(x);\r\n\t}\r\n\t\r\n\tNode *insert(const\
    \ T &x) {\r\n\t\tsize_++;\r\n\t\tbool ef[2] {};\r\n\t\t\r\n\t\tNode *Q = root_node,\
    \ *R = nullptr;\r\n\t\tbool d = false;\r\n\t\twhile (Q) {\r\n\t\t\tR = Q;\r\n\t\
    \t\td = Q->value <= x;\r\n\t\t\tef[!d] = true;\r\n\t\t\tQ = Q->child[d];\r\n\t\
    \t}\r\n\t\tQ = new Node(x, R, d);\r\n\t\tif (!ef[0]) e_ptr[0] = Q;\r\n\t\tif (!ef[1])\
    \ e_ptr[1] = Q;\r\n\t\t\r\n\t\tif (R) {\r\n\t\t\tR->size[d] = 1;\r\n\t\t\tR->height[d]\
    \ = 1;\r\n\t\t\tR->child[d] = Q;\r\n\t\t\tupdate(R);\r\n\t\t}\r\n\t\telse root_node\
    \ = Q;\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *erase(const T &x) {\r\n\t\tNode\
    \ *Q = find_(x);\r\n\t\tif (Q) return erase_(Q);\r\n\t\treturn end_();\r\n\t}\r\
    \n\t\r\n\tNode *erase(Node *Q) {\r\n\t\tif (Q) return erase_(Q);\r\n\t\treturn\
    \ end_();\r\n\t}\r\n\t\r\n\tNode *lower_bound(const T &x) const {\r\n\t\treturn\
    \ lower_bound_(x);\r\n\t}\r\n\t\r\n\tNode *upper_bound(const T &x) const {\r\n\
    \t\treturn upper_bound_(x);\r\n\t}\r\n\t\r\n\tNode *k_th_smallest(std::size_t\
    \ k) const {\r\n\t\treturn k_th_smallest_(k);\r\n\t}\r\n\t\r\n\tNode *k_th_largest(std::size_t\
    \ k) const {\r\n\t\treturn k_th_largest_(k);\r\n\t}\r\n\t\r\n\tNode *next(Node\
    \ *Q) const {\r\n\t\tif (Q) return move(Q, true);\r\n\t\treturn e_ptr[0];\r\n\t\
    }\r\n\t\r\n\tNode *prev(Node *Q) const {\r\n\t\tif (Q) return move(Q, false);\r\
    \n\t\treturn e_ptr[1];\r\n\t}\r\n\t\r\nprivate:\r\n\tstd::size_t size_ {};\r\n\
    \tNode *root_node {};\r\n\tNode *e_ptr[2] {};\r\n\t\r\n\tvoid clear_dfs(Node*\
    \ Q) {\r\n\t\tif (!Q) return;\r\n\t\tclear_dfs(Q->child[0]);\r\n\t\tclear_dfs(Q->child[1]);\r\
    \n\t\tdelete Q;\r\n\t}\r\n\t\r\n\tvoid enumerate_dfs(const Node *Q, std::vector<T>\
    \ &elements) const {\r\n\t\tif (!Q) return;\r\n\t\tenumerate_dfs(Q->child[0],\
    \ elements);\r\n\t\telements.push_back(Q->value);\r\n\t\tenumerate_dfs(Q->child[1],\
    \ elements);\r\n\t}\r\n\t\r\n\t Node *begin_() const {\r\n\t\treturn e_ptr[0];\r\
    \n\t}\r\n\t\r\n\tNode *end_() const {\r\n\t\treturn nullptr;\r\n\t}\r\n\t\r\n\t\
    Node *rotate(Node *Q, bool d) {\r\n\t\tNode *R = Q->par, *P = Q->child[!d], *B\
    \ = P->child[d];\r\n\t\t\r\n\t\tif (R) R->child[Q->is_r] = P;\r\n\t\telse root_node\
    \ = P;\r\n\t\t\r\n\t\tQ->child[!d] = B;\r\n\t\tP->child[d] = Q;\r\n\t\t\r\n\t\t\
    if (B) {\r\n\t\t\tB->par = Q;\r\n\t\t\tB->is_r = !d;\r\n\t\t}\r\n\t\t\r\n\t\t\
    P->par = Q->par;\r\n\t\tP->is_r = Q->is_r;\r\n\t\t\r\n\t\tQ->par = P;\r\n\t\t\
    Q->is_r = d;\r\n\t\tQ->size[!d] = P->size[d];\r\n\t\tQ->height[!d] = P->height[d];\r\
    \n\t\t\r\n\t\tP->size[d] = Q->size[0] + Q->size[1] + 1;\r\n\t\tP->height[d] =\
    \ std::max(Q->height[0], Q->height[1]) + 1;\r\n\t\treturn P;\r\n\t}\r\n\t\r\n\t\
    void update(Node *Q) {\r\n\t\tbool done = false;\r\n\t\twhile (true) {\r\n\t\t\
    \tif (!done && std::abs(static_cast<int>(Q->height[0]) - static_cast<int>(Q->height[1]))\
    \ > 1) {\r\n\t\t\t\tbool d = Q->height[0] > Q->height[1];\r\n\t\t\t\tNode *P =\
    \ Q->child[!d];\r\n\t\t\t\tif (P->height[!d] < P->height[d]) rotate(P, !d);\r\n\
    \t\t\t\tQ = rotate(Q, d);\r\n\t\t\t\tdone = true;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\
    \tNode *R = Q->par;\r\n\t\t\tif (!R) break;\r\n\t\t\tR->size[Q->is_r] = Q->size[0]\
    \ + Q->size[1] + 1;\r\n\t\t\tR->height[Q->is_r] = std::max(Q->height[0], Q->height[1])\
    \ + 1;\r\n\t\t\tQ = R;\r\n\t\t}\r\n\t}\r\n\t\r\n\tNode *find_(const T &x) {\r\n\
    \t\tNode *Q = lower_bound_(x);\r\n\t\tif (Q && Q->value != x) Q = end_();\r\n\t\
    \treturn Q;\r\n\t}\r\n\t\r\n\tNode *erase_(Node *Q) {\r\n\t\tsize_--;\r\n\t\t\
    Node *ret = next(Q), *upd = nullptr;\r\n\t\t\r\n\t\tif (Q->child[0] && Q->child[1])\
    \ {\r\n\t\t\tNode *P = Q->child[0];\r\n\t\t\twhile (P->child[1]) P = P->child[1];\r\
    \n\t\t\tQ->value = std::move(P->value);\r\n\t\t\tQ = P;\r\n\t\t}\r\n\t\t\r\n\t\
    \tNode *R = Q->par;\r\n\t\tif (R) upd = R;\r\n\t\tif (Q->child[0] || Q->child[1])\
    \ {\r\n\t\t\tNode *P = Q->child[0] ? Q->child[0] : Q->child[1];\r\n\t\t\tif (R)\
    \ {\r\n\t\t\t\tR->size[Q->is_r] = Q->size[P->is_r];\r\n\t\t\t\tR->height[Q->is_r]\
    \ = Q->height[P->is_r];\r\n\t\t\t\tR->child[Q->is_r] = P;\r\n\t\t\t\tP->par =\
    \ R;\r\n\t\t\t\tP->is_r = Q->is_r;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tP->par\
    \ = nullptr;\r\n\t\t\t\troot_node = P;\r\n\t\t\t}\r\n\t\t}\r\n\t\telse {\r\n\t\
    \t\tif (R) {\r\n\t\t\t\tR->size[Q->is_r] = 0;\r\n\t\t\t\tR->height[Q->is_r] =\
    \ 0;\r\n\t\t\t\tR->child[Q->is_r] = nullptr;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\
    \t\troot_node = nullptr;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tif (e_ptr[0] == Q)\
    \ e_ptr[0] = next(Q);\r\n\t\tif (e_ptr[1] == Q) e_ptr[1] = prev(Q);\r\n\t\tdelete\
    \ Q;\r\n\t\tif (upd) update(upd);\r\n\t\treturn ret;\r\n\t}\r\n\t\r\n\tNode *lower_bound_(const\
    \ T &x) const {\r\n\t\tNode *Q = root_node;\r\n\t\tif (!Q) return end_();\r\n\t\
    \twhile (true) {\r\n\t\t\tNode *P = Q->child[Q->value < x];\r\n\t\t\tif (!P) break;\r\
    \n\t\t\tQ = P;\r\n\t\t}\r\n\t\tif (!Q) return end_();\r\n\t\tif (Q->value < x)\
    \ Q = next(Q);\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *upper_bound_(const T &x)\
    \ const {\r\n\t\tNode *Q = root_node;\r\n\t\tif (!Q) return end_();\r\n\t\twhile\
    \ (true) {\r\n\t\t\tNode *P = Q->child[Q->value <= x];\r\n\t\t\tif (!P) break;\r\
    \n\t\t\tQ = P;\r\n\t\t}\r\n\t\tif (!Q) return end_();\r\n\t\tif (Q->value <= x)\
    \ Q = next(Q);\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *k_th_smallest_(std::size_t\
    \ k) const {\r\n\t\tif (k == 0 || size_ < k) return end_();\r\n\t\tNode *Q = root_node;\r\
    \n\t\tstd::size_t sum = 0;\r\n\t\twhile (sum < k) {\r\n\t\t\tif (sum + Q->size[0]\
    \ >= k) {\r\n\t\t\t\tQ = Q->child[0];\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tsum\
    \ += Q->size[0];\r\n\t\t\t\t++sum;\r\n\t\t\t\tif (sum != k) Q = Q->child[1];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn Q;\r\n\t}\r\n\t\r\n\tNode *k_th_largest_(std::size_t\
    \ k) const {\r\n\t\tif (k == 0 || size_ < k) return end_();\r\n\t\treturn k_th_smallest_(size_\
    \ - k + 1);\r\n\t}\r\n\t\r\n\tNode *move(Node *Q, bool d) const {\r\n\t\tif (Q->child[d])\
    \ {\r\n\t\t\tQ = Q->child[d];\r\n\t\t\twhile (Q->child[!d]) Q = Q->child[!d];\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\twhile (Q && (d ^ !Q->is_r)) Q = Q->par;\r\n\t\t\
    \tif (Q) Q = Q->par;\r\n\t\t}\r\n\t\treturn Q;\r\n\t}\r\n};\r\n\r\n/*\r\nint main()\
    \ {\r\n\tAVL_Tree<int> tree;\r\n\t\r\n\tconst int queryNumber = 11;\r\n\tstd::string\
    \ str[queryNumber] = {\"clear\", \"kths\", \"kthl\", \"size\", \"print\", \"ins\"\
    , \"find\", \"era\", \"lower\", \"upper\", \"exit\"};\r\n\tstd::set<std::string>\
    \ ss;\r\n\tREP(i, queryNumber) ss.insert(str[i]);\r\n\t\r\n\twhile (true) {\r\n\
    \t\tstd::string query;\r\n\t\tstd::cin >> query;\r\n\t\t\r\n\t\tif (ss.find(query)\
    \ == ss.end()) {\r\n\t\t\tputs(\"Please input again\");\r\n\t\t\tcontinue;\r\n\
    \t\t}\r\n\t\t\r\n\t\tif (query == \"exit\") {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\t\
    if (query == \"clear\") {\r\n\t\t\ttree.clear();\r\n\t\t}\r\n\t\telse if (query\
    \ == \"size\") {\r\n\t\t\tprintf(\"size: %d\\n\", tree.size());\r\n\t\t}\r\n\t\
    \telse if (query == \"print\") {\r\n\t\t\tstd::vector<int> v = tree.enumerate();\r\
    \n\t\t\tREP(i, v.size()) printf(\"%d \", v[i]);\r\n\t\t\tputs(\"\");\r\n\t\t\t\
    \r\n\t\t}\r\n\t\telse {\r\n\t\t\tint num;\r\n\t\t\tstd::cin >> num;\r\n\t\t\t\
    if (query == \"ins\") {\r\n\t\t\t\ttree.insert(num);\r\n\t\t\t}\r\n\t\t\telse\
    \ if (query == \"find\") {\r\n\t\t\t\t\r\n\t\t\t\tstd::cout << std::boolalpha\
    \ << (bool)tree.find(num) << std::endl;\r\n\t\t\t}\r\n\t\t\telse if (query ==\
    \ \"era\") {\r\n\t\t\t\ttree.erase(num);\r\n\t\t\t}\r\n\t\t\telse if (query ==\
    \ \"lower\") {\r\n\t\t\t\tauto *p = tree.lower_bound(num);\r\n\t\t\t\twhile (p)\
    \ {\r\n\t\t\t\t\tprintf(\"%d \", p->value);\r\n\t\t\t\t\tp = tree.next(p);\r\n\
    \t\t\t\t}\r\n\t\t\t\tputs(\"\");\r\n\t\t\t}\r\n\t\t\telse if (query == \"upper\"\
    ) {\r\n\t\t\t\tauto *p = tree.upper_bound(num);\r\n\t\t\t\twhile (p) {\r\n\t\t\
    \t\t\tprintf(\"%d \", p->value);\r\n\t\t\t\t\tp = tree.next(p);\r\n\t\t\t\t}\r\
    \n\t\t\t\tputs(\"\");\r\n\t\t\t}\r\n\t\t\telse if (query == \"kths\") {\r\n\t\t\
    \t\tauto *P = tree.k_th_smallest(num);\r\n\t\t\t\tif (P) cout << P->value << endl;\r\
    \n\t\t\t}\r\n\t\t\telse if (query == \"kthl\") {\r\n\t\t\t\tauto *P = tree.k_th_largest(num);\r\
    \n\t\t\t\tif (P) cout << P->value << endl;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int>\
    \ v = tree.enumerate();\r\n\t\tREP(i, v.size()) printf(\"%d \", v[i]); puts(\"\
    \");\r\n\t\tif (!tree.empty()) printf(\"begin: %d, end: %d\\n\", tree.begin()->value,\
    \ prev(tree.end())->value);\r\n\t\t\r\n\t}\r\n\t\r\n\treturn 0;\r\n}\r\n*/\r\n\
    \r\n#endif // INCLUDE_GUARD_AVL_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/AVL_Tree.hpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AVL_Tree.test.cpp
documentation_of: DataStructure/AVL_Tree.hpp
layout: document
redirect_from:
- /library/DataStructure/AVL_Tree.hpp
- /library/DataStructure/AVL_Tree.hpp.html
title: DataStructure/AVL_Tree.hpp
---
