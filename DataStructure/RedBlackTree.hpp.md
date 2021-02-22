---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/RedBlackTree.test.cpp
    title: Test/RedBlackTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html,
    - http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html,
    - https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8,
  bundledCode: "#line 1 \"DataStructure/RedBlackTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/08/30\r\n\r\n\u5168\u3066\u306E\u30CE\u30FC\u30C9\u306B\u5024\u3092\u6301\
    \u305F\u305B\u308B insert/delete \u30D9\u30FC\u30B9\u306E\u8D64\u9ED2\u6728\r\n\
    \u64CD\u4F5C\u306E\u524D\u5F8C\u3067\u5B89\u5B9A\r\n\r\nTODO: \u8449\u306B\u5024\
    \u3092\u6301\u305F\u305B\u308B\u3088\u3046\u306A insert/erase \u30D9\u30FC\u30B9\
    (merge/split \u5BFE\u5FDC) \u306E\u8D64\u9ED2\u6728\u306E\u4F5C\u6210(\u3067\u304D\
    \u308B\u304B\u306F\u308F\u304B\u3089\u306A\u3044)\r\n\r\n# \u4ED5\u69D8\r\nRedBrackTree()\
    \ :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u7A7A\u306E RedBrackTree \u3092\
    \u4F5C\u6210\r\n\r\nRedBrackTree(const RedBrackTree & rhs) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(rhs.n)\r\n\t\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u521D\
    \u671F\u5316\r\n\r\n~RedBrackTree() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\
    \n\t\u30C7\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\tclear() \u3092\u547C\u3076\r\n\r\
    \nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\
    \n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\nbool empty() const noexcept :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u8981\u7D20\u304C\u7A7A\u3067\u3042\
    \u308B\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\r\n\r\nvoid clear() :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\n\t\u5168\u3066\u306E\u8981\u7D20\u3092\
    \ delete \u3059\u308B\r\n\r\nnode_ptr begin() const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\r\n\t\u6700\u3082\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\
    \u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr end() const :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(1)\r\n\t\u6700\u3082\u5927\u304D\u3044\u8981\u7D20\u306E\
    \u6B21\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr next(node_ptr\
    \ node) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n), \u306A\u3089\u3057\
    \ O(1)\r\n\tnode \u306E\u6B21\u306B\u5927\u304D\u3044\u8981\u7D20\u306E\u30DD\u30A4\
    \u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr prev(node_ptr node) const :\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: O(log n), \u306A\u3089\u3057 O(1)\r\n\tnode\
    \ \u306E\u6B21\u306B\u5C0F\u3055\u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\
    \u3092\u8FD4\u3059\r\n\r\nnode_ptr insert(const_reference x) :\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(log n)\r\n\t\u5024 x \u3092\u633F\u5165\u3059\u308B\r\n\r\
    \nnode_ptr lower_bound(const_reference x) const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(log n)\r\n\tx \u4EE5\u4E0A\u3067\u5148\u982D\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\r\n\r\nnode_ptr upper_bound(const_reference x) const :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tx \u3088\u308A\u5927\u304D\u3044\u5148\
    \u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr find(const_reference\
    \ x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tx \u3068\u7B49\
    \u3057\u3044\u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr erase(const_reference\
    \ x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5024 x \u3092\u6301\
    \u3064\u8981\u7D20\u3092 1 \u3064\u524A\u9664\u3059\u308B\r\n\t\u8907\u6570\u5B58\
    \u5728\u3059\u308B\u5834\u5408\u306F\u4E00\u756A\u5148\u982D\u306E\u8981\u7D20\
    \r\n\t\u524A\u9664\u3057\u305F\u8981\u7D20\u306E\u6B21\u306B\u5927\u304D\u3044\
    \u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr erase(node_ptr node) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tnode \u304C\u6307\u3059\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B\r\n\t\u524A\u9664\u3057\u305F\u8981\u7D20\u306E\u6B21\
    \u306B\u5927\u304D\u3044\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nbool check() const\
    \ : \u8D64\u9ED2\u6728\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3057\u3066\u3044\u308B\
    \u304B\u78BA\u8A8D\u3059\u308B\r\nvoid debug() : \u6728\u3092\u51FA\u529B\u3059\
    \u308B(int, std::pair) \u306B\u5BFE\u5FDC\r\n\r\n# \u53C2\u8003\r\nhttps://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8,\
    \ 2020/08/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html, 2020/08/27\r\
    \nhttp://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html, 2020/08/27\r\n*/\r\n\r\n\
    // #include <iostream>\r\n\r\n#include <cassert>\r\n#include <utility>\r\n\r\n\
    template<typename T>\r\nstruct RedBlackTree {\r\nprivate:\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\
    \n\t\r\npublic:\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tbool isred;\r\
    \n\t\tnode_ptr child[2];\r\n\t\tnode_ptr par;\r\n\t\tbool isright;\r\n\t\t\r\n\
    \t\tNode(const_reference val, bool isred, node_ptr child_l, node_ptr child_r,\
    \ node_ptr par, bool isright)\r\n\t\t\t: val(val), isred(isred), child{child_l,\
    \ child_r}, par(par), isright(isright) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tnode_ptr\
    \ root = nullptr;\r\n\tnode_ptr begin_ptr = nullptr, end_ptr = nullptr;\r\n\t\
    size_type n = 0;\r\n\t\r\npublic:\r\n\tRedBlackTree() = default;\r\n\t\r\n\tRedBlackTree(const\
    \ RedBlackTree & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tRedBlackTree & operator\
    \ =(const RedBlackTree & rhs) {\r\n\t\tauto dfs = [&](auto &&self, node_ptr node,\
    \ node_ptr par) -> node_ptr {\r\n\t\t\tif (!node) return nullptr;\r\n\t\t\tnode_ptr\
    \ ret = new Node{node->val, node->isred, nullptr, nullptr, par, node->isright};\r\
    \n\t\t\tif (node == rhs.begin_ptr) begin_ptr = ret;\r\n\t\t\tif (node == rhs.end_ptr)\
    \ end_ptr = ret;\r\n\t\t\tret->child[0] = self(self, node->child[0], ret);\r\n\
    \t\t\tret->child[1] = self(self, node->child[1], ret);\r\n\t\t\treturn ret;\r\n\
    \t\t};\r\n\t\troot = dfs(dfs, rhs.root, nullptr);\r\n\t\tn = rhs.n;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\t~RedBlackTree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\t\
    size_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool empty()\
    \ const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\
    \n\t\tnode_ptr cur = root;\r\n\t\twhile (cur) {\r\n\t\t\tif (cur->child[0]) cur\
    \ = cur->child[0];\r\n\t\t\telse if (cur->child[1]) cur = cur->child[1];\r\n\t\
    \t\telse {\r\n\t\t\t\tnode_ptr par = cur->par;\r\n\t\t\t\tif (par) par->child[cur->isright]\
    \ = nullptr;\r\n\t\t\t\tdelete cur;\r\n\t\t\t\tcur = par;\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tnode_ptr begin() const {\r\n\t\treturn\
    \ begin_ptr;\r\n\t}\r\n\t\r\n\tnode_ptr end() const {\r\n\t\treturn nullptr;\r\
    \n\t}\r\n\t\r\n\tnode_ptr next(node_ptr node) const {\r\n\t\treturn node != end()\
    \ ? move(node, true) : begin_ptr;\r\n\t};\r\n\t\r\n\tnode_ptr prev(node_ptr node)\
    \ const {\r\n\t\treturn node != end() ? move(node, false) : end_ptr;\r\n\t}\r\n\
    \t\r\n\tnode_ptr insert(const_reference x) {\r\n\t\tif (!root) {\r\n\t\t\troot\
    \ = new Node{x, false, nullptr, nullptr, nullptr, false};\r\n\t\t\t++n;\r\n\t\t\
    \tbegin_ptr = end_ptr = root;\r\n\t\t\treturn root;\r\n\t\t}\r\n\t\t\r\n\t\tnode_ptr\
    \ par = root, ins = nullptr;\r\n\t\tbool move_only[2] {true, true};\r\n\t\twhile\
    \ (!ins) {\r\n\t\t\tconst bool nex_r = par->val <= x;\r\n\t\t\tmove_only[!nex_r]\
    \ = false;\r\n\t\t\tif (par->child[nex_r]) par = par->child[nex_r];\r\n\t\t\t\
    else {\r\n\t\t\t\tins = new Node{x, true, nullptr, nullptr, par, nex_r};\r\n\t\
    \t\t\t++n;\r\n\t\t\t\tif (move_only[0]) begin_ptr = ins;\r\n\t\t\t\tif (move_only[1])\
    \ end_ptr = ins;\r\n\t\t\t\tpar->child[nex_r] = ins;\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif (!par->isred) return ins;\r\n\t\t\r\n\t\t// (ins, par) = (red, red), par\
    \ \\neq root\r\n\t\tnode_ptr grand = par->par; // grand = black\r\n\t\tnode_ptr\
    \ uncle = grand->child[!par->isright];\r\n\t\tif (!uncle) {\r\n\t\t\tif (ins->isright\
    \ == par->isright) {\r\n\t\t\t\trotate(grand, !par->isright);\r\n\t\t\t\tpar->isred\
    \ = false;\r\n\t\t\t\tgrand->isred = true;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \tconst bool isflip = par->isright;\r\n\t\t\t\t\r\n\t\t\t\tgrand->child[par->isright]\
    \ = nullptr;\r\n\t\t\t\tpar->child[ins->isright] = nullptr;\r\n\t\t\t\t\r\n\t\t\
    \t\tins->isred = false;\r\n\t\t\t\tins->par = grand->par;\r\n\t\t\t\tins->isright\
    \ = grand->isright;\r\n\t\t\t\tins->child[isflip] = par;\r\n\t\t\t\tins->child[!isflip]\
    \ = grand;\r\n\t\t\t\t\r\n\t\t\t\tpar->par = ins;\r\n\t\t\t\tpar->isright = isflip;\r\
    \n\t\t\t\t\r\n\t\t\t\tgrand->isred = true;\r\n\t\t\t\tgrand->par = ins;\r\n\t\t\
    \t\tgrand->isright = !isflip;\r\n\t\t\t\t\r\n\t\t\t\tif (ins->par) ins->par->child[ins->isright]\
    \ = ins;\r\n\t\t\t\telse root = ins;\r\n\t\t\t}\r\n\t\t\treturn ins;\r\n\t\t}\r\
    \n\t\t\r\n\t\t// uncle = red\r\n\t\tgrand->isred = true;\r\n\t\tpar->isred = false;\r\
    \n\t\tuncle->isred = false;\r\n\t\t\r\n\t\twhile (true) {\r\n\t\t\t// grand =\
    \ red, exists(par(grand)) = ?\r\n\t\t\tnode_ptr cur = grand;\r\n\t\t\tpar = cur->par;\r\
    \n\t\t\tif (!par) {\r\n\t\t\t\tcur->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tif (!par->isred) break;\r\n\t\t\tgrand = par->par;\r\n\t\t\tuncle =\
    \ grand->child[!par->isright];\r\n\t\t\t\r\n\t\t\t// (cur, par) = (red, red),\
    \ grand = black, uncle = ?\r\n\t\t\tif (!uncle->isred) {\r\n\t\t\t\tif (cur->isright\
    \ == par->isright) {\r\n\t\t\t\t\trotate(grand, !par->isright);\r\n\t\t\t\t\t\
    par->isred = false;\r\n\t\t\t\t\tgrand->isred = true;\r\n\t\t\t\t}\r\n\t\t\t\t\
    else {\r\n\t\t\t\t\trotate(par, par->isright);\r\n\t\t\t\t\trotate(grand, !par->isright);\r\
    \n\t\t\t\t\tcur->isred = false;\r\n\t\t\t\t\tgrand->isred = true;\r\n\t\t\t\t\
    }\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tgrand->isred = true;\r\n\t\t\
    \tpar->isred = false;\r\n\t\t\tuncle->isred = false;\r\n\t\t}\r\n\t\treturn ins;\r\
    \n\t}\r\n\t\r\n\tnode_ptr lower_bound(const_reference x) const {\r\n\t\tnode_ptr\
    \ node = root;\r\n\t\tif (!node) return end();\r\n\t\twhile (true) {\r\n\t\t\t\
    bool cmp = x <= node->val;\r\n\t\t\tif (node->child[!cmp]) node = node->child[!cmp];\r\
    \n\t\t\telse break;\r\n\t\t}\r\n\t\tif (node->val < x) return next(node);\r\n\t\
    \treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr upper_bound(const_reference x) const\
    \ {\r\n\t\tnode_ptr node = root;\r\n\t\tif (!node) return end();\r\n\t\twhile\
    \ (true) {\r\n\t\t\tbool cmp = x < node->val;\r\n\t\t\tif (node->child[!cmp])\
    \ node = node->child[!cmp];\r\n\t\t\telse break;\r\n\t\t}\r\n\t\tif (x <= node->val)\
    \ return next(node);\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference\
    \ x) const {\r\n\t\tnode_ptr cur = lower_bound(x);\r\n\t\tif (cur != end() &&\
    \ cur->val == x) return cur;\r\n\t\treturn end();\r\n\t}\r\n\t\r\n\tnode_ptr erase(const_reference\
    \ x) {\r\n\t\treturn erase(find(x));\r\n\t}\r\n\t\r\n\tnode_ptr erase(node_ptr\
    \ node) {\r\n\t\tif (node == end()) return end();\r\n\t\tnode_ptr ret = next(node);\r\
    \n\t\tif (node->child[0]) {\r\n\t\t\tnode_ptr rep = node->child[0];\r\n\t\t\t\
    while (rep->child[1]) rep = rep->child[1];\r\n\t\t\tnode->val = std::move(rep->val);\r\
    \n\t\t\terase_sub(rep);\r\n\t\t}\r\n\t\telse erase_sub(node);\r\n\t\treturn ret;\r\
    \n\t}\r\n\t\r\n\tbool check() const {\r\n\t\tif (!root) return true;\r\n\t\tassert(!root->isred);\r\
    \n\t\t\r\n\t\tsize_type tmp = -1;\r\n\t\t\r\n\t\tauto dfs = [&](auto &&self, node_ptr\
    \ node, node_ptr par, size_type cnt) -> node_ptr {\r\n\t\t\tif (!node) {\r\n\t\
    \t\t\t++cnt;\r\n\t\t\t\tif (tmp == -1) tmp = cnt;\r\n\t\t\t\tassert(cnt == tmp);\r\
    \n\t\t\t\treturn node;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tif (!node->isred) ++cnt;\r\
    \n\t\t\t\r\n\t\t\tif (node->child[0]) {\r\n\t\t\t\tassert(node->child[0]->val\
    \ <= node->val);\r\n\t\t\t\tassert(!node->isred || !node->child[0]->isred);\r\n\
    \t\t\t\tif (par) assert(node == par->child[node->isright]);\r\n\t\t\t\telse assert(root\
    \ == node);\r\n\t\t\t}\r\n\t\t\tself(self, node->child[0], node, cnt);\r\n\t\t\
    \t\r\n\t\t\tif (node->child[1]) {\r\n\t\t\t\tassert(node->child[1]->val >= node->val);\r\
    \n\t\t\t\tassert(!node->isred || !node->child[1]->isred);\r\n\t\t\t\tif (par)\
    \ assert(node == par->child[node->isright]);\r\n\t\t\t\telse assert(root == node);\r\
    \n\t\t\t}\r\n\t\t\tself(self, node->child[1], node, cnt);\r\n\t\t\treturn node;\r\
    \n\t\t};\r\n\t\tdfs(dfs, root, nullptr, 0);\r\n\t\treturn true;\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tvoid rotate(node_ptr node, bool rotR) {\r\n\t\tnode_ptr u = node->child[!rotR];\r\
    \n\t\tnode_ptr b = u->child[rotR];\r\n\t\t\r\n\t\tif (node->par) node->par->child[node->isright]\
    \ = u;\r\n\t\telse root = u;\r\n\t\t\r\n\t\tu->par = node->par;\r\n\t\tu->isright\
    \ = node->isright;\r\n\t\tu->child[rotR] = node;\r\n\t\t\r\n\t\tnode->par = u;\r\
    \n\t\tnode->isright = rotR;\r\n\t\tnode->child[!rotR] = b;\r\n\t\t\r\n\t\tif (b)\
    \ {\r\n\t\t\tb->par = node;\r\n\t\t\tb->isright = !rotR;\r\n\t\t}\r\n\t}\r\n\t\
    \r\n\tnode_ptr move(node_ptr node, bool isnext) const {\r\n\t\tif (node->child[isnext])\
    \ {\r\n\t\t\tnode = node->child[isnext];\r\n\t\t\twhile (node->child[!isnext])\
    \ node = node->child[!isnext];\r\n\t\t}\r\n\t\telse {\r\n\t\t\twhile (node &&\
    \ (!node->isright ^ isnext)) node = node->par;\r\n\t\t\tif (node) node = node->par;\r\
    \n\t\t}\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tvoid erase_sub(node_ptr node) {\r\
    \n\t\t// |node->child| \\leq 1\r\n\t\tbool isred = node->isred;\r\n\t\tbool isright\
    \ = node->isright;\r\n\t\t\r\n\t\tnode_ptr par = node->par;\r\n\t\tfor (size_type\
    \ i = 0; i < 2; ++i) {\r\n\t\t\tif (node->child[i]) {\r\n\t\t\t\tif (par) par->child[node->isright]\
    \ = node->child[i];\r\n\t\t\t\telse root = node->child[i];\r\n\t\t\t\tnode->child[i]->par\
    \ = par;\r\n\t\t\t\tnode->child[i]->isright = node->isright;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tif (!node->child[0] && !node->child[1]) {\r\n\t\t\tif (par) par->child[node->isright]\
    \ = nullptr;\r\n\t\t\telse root = nullptr;\r\n\t\t}\r\n\t\tdelete node;\r\n\t\t\
    --n;\r\n\t\tif (isred) return;\r\n\t\t\r\n\t\twhile (par) {\r\n\t\t\t// exists(par->child[!isright])\
    \ = true\r\n\t\t\t// isright = -1-subtree\r\n\t\t\tnode_ptr b = par->child[!isright];\r\
    \n\t\t\t\r\n\t\t\tif (b->isred) {\r\n\t\t\t\t// par = black, b = red\r\n\t\t\t\
    \trotate(par, isright);\r\n\t\t\t\tb->isred = false;\r\n\t\t\t\tpar->isred = true;\r\
    \n\t\t\t\tb = par->child[!isright];\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tnode_ptr tar\
    \ = b->child[!isright];\r\n\t\t\tif (tar && tar->isred) {\r\n\t\t\t\trotate(par,\
    \ isright);\r\n\t\t\t\tb->isred = par->isred;\r\n\t\t\t\tpar->isred = false;\r\
    \n\t\t\t\ttar->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\
    tar = b->child[isright];\r\n\t\t\tif (tar && tar->isred) {\r\n\t\t\t\trotate(b,\
    \ !isright);\r\n\t\t\t\trotate(par, isright);\r\n\t\t\t\ttar->isred = par->isred;\r\
    \n\t\t\t\tpar->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tb->isred =\
    \ true;\r\n\t\t\tif (par->isred) {\r\n\t\t\t\tpar->isred = false;\r\n\t\t\t\t\
    break;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tisright = par->isright;\r\n\t\t\tpar = par->par;\r\
    \n\t\t}\r\n\t\t\r\n\t\tif (root) root->isred = false;\r\n\t}\r\n\t\r\npublic:\r\
    \n\t// void debug() {\r\n\t// \tif (!root) {\r\n\t// \t\tstd::cout << \"debug\
    \ : empty\" << std::endl;\r\n\t// \t\treturn;\r\n\t// \t}\r\n\t// \tauto dfs =\
    \ [&](auto &&self, node_ptr cur) -> void {\r\n\t// \t\tif (!root) std::cout <<\
    \ \"empty\" << std::endl;\r\n\t// \t\tif (!cur) return;\r\n\t\t\t\r\n\t// \t\t\
    std::cout << \"val = \" << cur->val << \", color = \" << (cur->isred ? \"red\"\
    \ : \"black\");\r\n\t// \t\tif (cur->par) std::cout << \", par = \" << cur->par->val\
    \ << \", \" << (cur->isright ? \"right\" : \"left\");\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", leftval = \";\r\n\t// \t\tif (!cur->child[0]) std::cout << \"null\";\r\
    \n\t// \t\telse std::cout << cur->child[0]->val;\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", rightval = \";\r\n\t// \t\tif (!cur->child[1]) std::cout << \"null\"\
    ;\r\n\t// \t\telse std::cout << cur->child[1]->val;\r\n\t// \t\tstd::cout << std::endl;\r\
    \n\t\t\t\r\n\t// \t\tif (cur->child[0]) {\r\n\t// \t\t\tstd::cout << \"move left\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[0]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->child[1]) {\r\n\t// \t\t\tstd::cout << \"move right\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[1]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->par) std::cout << \"move par -> val = \" << cur->par->val\
    \ << std::endl;\r\n\t// \t};\r\n\t// \tdfs(dfs, root);\r\n\t// }\r\n\t\r\n\t//\
    \ void debug() {\r\n\t// \tif (!root) {\r\n\t// \t\tstd::cout << \"debug : empty\"\
    \ << std::endl;\r\n\t// \t\treturn;\r\n\t// \t}\r\n\t// \tauto dfs = [&](auto\
    \ &&self, node_ptr cur) -> void {\r\n\t// \t\tif (!root) std::cout << \"empty\"\
    \ << std::endl;\r\n\t// \t\tif (!cur) return;\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \"val = \" << \"(\" << cur->val.first << \", \" << cur->val.second << \"\
    )\" << \", color = \" << (cur->isred ? \"red\" : \"black\");\r\n\t// \t\tif (cur->par)\
    \ std::cout << \", par = (\" << cur->par->val.first << \", \" << cur->par->val.second\
    \ << \")\" << \", \" << (cur->isright ? \"right\" : \"left\");\r\n\t\t\t\r\n\t\
    // \t\tstd::cout << \", leftval = \";\r\n\t// \t\tif (!cur->child[0]) std::cout\
    \ << \"null\";\r\n\t// \t\telse std::cout << \"(\" << cur->child[0]->val.first\
    \ << \", \" << cur->child[0]->val.second << \")\";\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", rightval = \";\r\n\t// \t\tif (!cur->child[1]) std::cout << \"null\"\
    ;\r\n\t// \t\telse std::cout << \"(\" << cur->child[1]->val.first << \", \" <<\
    \ cur->child[1]->val.second << \")\";\r\n\t// \t\tstd::cout << std::endl;\r\n\t\
    \t\t\r\n\t// \t\tif (cur->child[0]) {\r\n\t// \t\t\tstd::cout << \"move left\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[0]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->child[1]) {\r\n\t// \t\t\tstd::cout << \"move right\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[1]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->par) std::cout << \"move par -> val = \" <<  \"(\" <<\
    \ cur->par->val.first << \", \" << cur->par->val.second << \")\"<< std::endl;\r\
    \n\t// \t};\r\n\t// \tdfs(dfs, root);\r\n\t// }\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_RED_BLACK_TREE_HPP\r\n#define INCLUDE_GUARD_RED_BLACK_TREE_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/08/30\r\n\r\n\u5168\u3066\u306E\u30CE\u30FC\u30C9\
    \u306B\u5024\u3092\u6301\u305F\u305B\u308B insert/delete \u30D9\u30FC\u30B9\u306E\
    \u8D64\u9ED2\u6728\r\n\u64CD\u4F5C\u306E\u524D\u5F8C\u3067\u5B89\u5B9A\r\n\r\n\
    TODO: \u8449\u306B\u5024\u3092\u6301\u305F\u305B\u308B\u3088\u3046\u306A insert/erase\
    \ \u30D9\u30FC\u30B9(merge/split \u5BFE\u5FDC) \u306E\u8D64\u9ED2\u6728\u306E\u4F5C\
    \u6210(\u3067\u304D\u308B\u304B\u306F\u308F\u304B\u3089\u306A\u3044)\r\n\r\n#\
    \ \u4ED5\u69D8\r\nRedBrackTree() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\
    \n\t\u7A7A\u306E RedBrackTree \u3092\u4F5C\u6210\r\n\r\nRedBrackTree(const RedBrackTree\
    \ & rhs) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(rhs.n)\r\n\t\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u521D\u671F\u5316\r\n\r\n~RedBrackTree() :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(n)\r\n\t\u30C7\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\t\
    clear() \u3092\u547C\u3076\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\
    \nbool empty() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\
    \u8981\u7D20\u304C\u7A7A\u3067\u3042\u308B\u304B\u3069\u3046\u304B\u5224\u5B9A\
    \u3059\u308B\r\n\r\nvoid clear() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\
    \n\t\u5168\u3066\u306E\u8981\u7D20\u3092 delete \u3059\u308B\r\n\r\nnode_ptr begin()\
    \ const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u6700\u3082\u5C0F\u3055\
    \u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr\
    \ end() const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u6700\u3082\u5927\
    \u304D\u3044\u8981\u7D20\u306E\u6B21\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\
    \u3059\r\n\r\nnode_ptr next(node_ptr node) const :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(log n), \u306A\u3089\u3057 O(1)\r\n\tnode \u306E\u6B21\u306B\u5927\u304D\
    \u3044\u8981\u7D20\u306E\u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr\
    \ prev(node_ptr node) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n), \u306A\
    \u3089\u3057 O(1)\r\n\tnode \u306E\u6B21\u306B\u5C0F\u3055\u3044\u8981\u7D20\u306E\
    \u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\r\n\r\nnode_ptr insert(const_reference\
    \ x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5024 x \u3092\u633F\
    \u5165\u3059\u308B\r\n\r\nnode_ptr lower_bound(const_reference x) const :\r\n\t\
    \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tx \u4EE5\u4E0A\u3067\u5148\u982D\
    \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr upper_bound(const_reference\
    \ x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tx \u3088\u308A\
    \u5927\u304D\u3044\u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr\
    \ find(const_reference x) const :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\
    \n\tx \u3068\u7B49\u3057\u3044\u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \r\n\r\nnode_ptr erase(const_reference x) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\t\u5024 x \u3092\u6301\u3064\u8981\u7D20\u3092 1 \u3064\u524A\u9664\
    \u3059\u308B\r\n\t\u8907\u6570\u5B58\u5728\u3059\u308B\u5834\u5408\u306F\u4E00\
    \u756A\u5148\u982D\u306E\u8981\u7D20\r\n\t\u524A\u9664\u3057\u305F\u8981\u7D20\
    \u306E\u6B21\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nnode_ptr\
    \ erase(node_ptr node) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tnode\
    \ \u304C\u6307\u3059\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\r\n\t\u524A\u9664\
    \u3057\u305F\u8981\u7D20\u306E\u6B21\u306B\u5927\u304D\u3044\u8981\u7D20\u3092\
    \u8FD4\u3059\r\n\r\nbool check() const : \u8D64\u9ED2\u6728\u306E\u6761\u4EF6\u3092\
    \u6E80\u305F\u3057\u3066\u3044\u308B\u304B\u78BA\u8A8D\u3059\u308B\r\nvoid debug()\
    \ : \u6728\u3092\u51FA\u529B\u3059\u308B(int, std::pair) \u306B\u5BFE\u5FDC\r\n\
    \r\n# \u53C2\u8003\r\nhttps://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8,\
    \ 2020/08/27\r\nhttp://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html, 2020/08/27\r\
    \nhttp://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html, 2020/08/27\r\n*/\r\n\r\n\
    // #include <iostream>\r\n\r\n#include <cassert>\r\n#include <utility>\r\n\r\n\
    template<typename T>\r\nstruct RedBlackTree {\r\nprivate:\r\n\tusing value_type\
    \ = T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type =\
    \ std::size_t;\r\n\t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\
    \n\t\r\npublic:\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tbool isred;\r\
    \n\t\tnode_ptr child[2];\r\n\t\tnode_ptr par;\r\n\t\tbool isright;\r\n\t\t\r\n\
    \t\tNode(const_reference val, bool isred, node_ptr child_l, node_ptr child_r,\
    \ node_ptr par, bool isright)\r\n\t\t\t: val(val), isred(isred), child{child_l,\
    \ child_r}, par(par), isright(isright) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tnode_ptr\
    \ root = nullptr;\r\n\tnode_ptr begin_ptr = nullptr, end_ptr = nullptr;\r\n\t\
    size_type n = 0;\r\n\t\r\npublic:\r\n\tRedBlackTree() = default;\r\n\t\r\n\tRedBlackTree(const\
    \ RedBlackTree & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tRedBlackTree & operator\
    \ =(const RedBlackTree & rhs) {\r\n\t\tauto dfs = [&](auto &&self, node_ptr node,\
    \ node_ptr par) -> node_ptr {\r\n\t\t\tif (!node) return nullptr;\r\n\t\t\tnode_ptr\
    \ ret = new Node{node->val, node->isred, nullptr, nullptr, par, node->isright};\r\
    \n\t\t\tif (node == rhs.begin_ptr) begin_ptr = ret;\r\n\t\t\tif (node == rhs.end_ptr)\
    \ end_ptr = ret;\r\n\t\t\tret->child[0] = self(self, node->child[0], ret);\r\n\
    \t\t\tret->child[1] = self(self, node->child[1], ret);\r\n\t\t\treturn ret;\r\n\
    \t\t};\r\n\t\troot = dfs(dfs, rhs.root, nullptr);\r\n\t\tn = rhs.n;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\t\r\n\t~RedBlackTree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\t\
    size_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tbool empty()\
    \ const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\
    \n\t\tnode_ptr cur = root;\r\n\t\twhile (cur) {\r\n\t\t\tif (cur->child[0]) cur\
    \ = cur->child[0];\r\n\t\t\telse if (cur->child[1]) cur = cur->child[1];\r\n\t\
    \t\telse {\r\n\t\t\t\tnode_ptr par = cur->par;\r\n\t\t\t\tif (par) par->child[cur->isright]\
    \ = nullptr;\r\n\t\t\t\tdelete cur;\r\n\t\t\t\tcur = par;\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tnode_ptr begin() const {\r\n\t\treturn\
    \ begin_ptr;\r\n\t}\r\n\t\r\n\tnode_ptr end() const {\r\n\t\treturn nullptr;\r\
    \n\t}\r\n\t\r\n\tnode_ptr next(node_ptr node) const {\r\n\t\treturn node != end()\
    \ ? move(node, true) : begin_ptr;\r\n\t};\r\n\t\r\n\tnode_ptr prev(node_ptr node)\
    \ const {\r\n\t\treturn node != end() ? move(node, false) : end_ptr;\r\n\t}\r\n\
    \t\r\n\tnode_ptr insert(const_reference x) {\r\n\t\tif (!root) {\r\n\t\t\troot\
    \ = new Node{x, false, nullptr, nullptr, nullptr, false};\r\n\t\t\t++n;\r\n\t\t\
    \tbegin_ptr = end_ptr = root;\r\n\t\t\treturn root;\r\n\t\t}\r\n\t\t\r\n\t\tnode_ptr\
    \ par = root, ins = nullptr;\r\n\t\tbool move_only[2] {true, true};\r\n\t\twhile\
    \ (!ins) {\r\n\t\t\tconst bool nex_r = par->val <= x;\r\n\t\t\tmove_only[!nex_r]\
    \ = false;\r\n\t\t\tif (par->child[nex_r]) par = par->child[nex_r];\r\n\t\t\t\
    else {\r\n\t\t\t\tins = new Node{x, true, nullptr, nullptr, par, nex_r};\r\n\t\
    \t\t\t++n;\r\n\t\t\t\tif (move_only[0]) begin_ptr = ins;\r\n\t\t\t\tif (move_only[1])\
    \ end_ptr = ins;\r\n\t\t\t\tpar->child[nex_r] = ins;\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif (!par->isred) return ins;\r\n\t\t\r\n\t\t// (ins, par) = (red, red), par\
    \ \\neq root\r\n\t\tnode_ptr grand = par->par; // grand = black\r\n\t\tnode_ptr\
    \ uncle = grand->child[!par->isright];\r\n\t\tif (!uncle) {\r\n\t\t\tif (ins->isright\
    \ == par->isright) {\r\n\t\t\t\trotate(grand, !par->isright);\r\n\t\t\t\tpar->isred\
    \ = false;\r\n\t\t\t\tgrand->isred = true;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \tconst bool isflip = par->isright;\r\n\t\t\t\t\r\n\t\t\t\tgrand->child[par->isright]\
    \ = nullptr;\r\n\t\t\t\tpar->child[ins->isright] = nullptr;\r\n\t\t\t\t\r\n\t\t\
    \t\tins->isred = false;\r\n\t\t\t\tins->par = grand->par;\r\n\t\t\t\tins->isright\
    \ = grand->isright;\r\n\t\t\t\tins->child[isflip] = par;\r\n\t\t\t\tins->child[!isflip]\
    \ = grand;\r\n\t\t\t\t\r\n\t\t\t\tpar->par = ins;\r\n\t\t\t\tpar->isright = isflip;\r\
    \n\t\t\t\t\r\n\t\t\t\tgrand->isred = true;\r\n\t\t\t\tgrand->par = ins;\r\n\t\t\
    \t\tgrand->isright = !isflip;\r\n\t\t\t\t\r\n\t\t\t\tif (ins->par) ins->par->child[ins->isright]\
    \ = ins;\r\n\t\t\t\telse root = ins;\r\n\t\t\t}\r\n\t\t\treturn ins;\r\n\t\t}\r\
    \n\t\t\r\n\t\t// uncle = red\r\n\t\tgrand->isred = true;\r\n\t\tpar->isred = false;\r\
    \n\t\tuncle->isred = false;\r\n\t\t\r\n\t\twhile (true) {\r\n\t\t\t// grand =\
    \ red, exists(par(grand)) = ?\r\n\t\t\tnode_ptr cur = grand;\r\n\t\t\tpar = cur->par;\r\
    \n\t\t\tif (!par) {\r\n\t\t\t\tcur->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tif (!par->isred) break;\r\n\t\t\tgrand = par->par;\r\n\t\t\tuncle =\
    \ grand->child[!par->isright];\r\n\t\t\t\r\n\t\t\t// (cur, par) = (red, red),\
    \ grand = black, uncle = ?\r\n\t\t\tif (!uncle->isred) {\r\n\t\t\t\tif (cur->isright\
    \ == par->isright) {\r\n\t\t\t\t\trotate(grand, !par->isright);\r\n\t\t\t\t\t\
    par->isred = false;\r\n\t\t\t\t\tgrand->isred = true;\r\n\t\t\t\t}\r\n\t\t\t\t\
    else {\r\n\t\t\t\t\trotate(par, par->isright);\r\n\t\t\t\t\trotate(grand, !par->isright);\r\
    \n\t\t\t\t\tcur->isred = false;\r\n\t\t\t\t\tgrand->isred = true;\r\n\t\t\t\t\
    }\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tgrand->isred = true;\r\n\t\t\
    \tpar->isred = false;\r\n\t\t\tuncle->isred = false;\r\n\t\t}\r\n\t\treturn ins;\r\
    \n\t}\r\n\t\r\n\tnode_ptr lower_bound(const_reference x) const {\r\n\t\tnode_ptr\
    \ node = root;\r\n\t\tif (!node) return end();\r\n\t\twhile (true) {\r\n\t\t\t\
    bool cmp = x <= node->val;\r\n\t\t\tif (node->child[!cmp]) node = node->child[!cmp];\r\
    \n\t\t\telse break;\r\n\t\t}\r\n\t\tif (node->val < x) return next(node);\r\n\t\
    \treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr upper_bound(const_reference x) const\
    \ {\r\n\t\tnode_ptr node = root;\r\n\t\tif (!node) return end();\r\n\t\twhile\
    \ (true) {\r\n\t\t\tbool cmp = x < node->val;\r\n\t\t\tif (node->child[!cmp])\
    \ node = node->child[!cmp];\r\n\t\t\telse break;\r\n\t\t}\r\n\t\tif (x <= node->val)\
    \ return next(node);\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference\
    \ x) const {\r\n\t\tnode_ptr cur = lower_bound(x);\r\n\t\tif (cur != end() &&\
    \ cur->val == x) return cur;\r\n\t\treturn end();\r\n\t}\r\n\t\r\n\tnode_ptr erase(const_reference\
    \ x) {\r\n\t\treturn erase(find(x));\r\n\t}\r\n\t\r\n\tnode_ptr erase(node_ptr\
    \ node) {\r\n\t\tif (node == end()) return end();\r\n\t\tnode_ptr ret = next(node);\r\
    \n\t\tif (node->child[0]) {\r\n\t\t\tnode_ptr rep = node->child[0];\r\n\t\t\t\
    while (rep->child[1]) rep = rep->child[1];\r\n\t\t\tnode->val = std::move(rep->val);\r\
    \n\t\t\terase_sub(rep);\r\n\t\t}\r\n\t\telse erase_sub(node);\r\n\t\treturn ret;\r\
    \n\t}\r\n\t\r\n\tbool check() const {\r\n\t\tif (!root) return true;\r\n\t\tassert(!root->isred);\r\
    \n\t\t\r\n\t\tsize_type tmp = -1;\r\n\t\t\r\n\t\tauto dfs = [&](auto &&self, node_ptr\
    \ node, node_ptr par, size_type cnt) -> node_ptr {\r\n\t\t\tif (!node) {\r\n\t\
    \t\t\t++cnt;\r\n\t\t\t\tif (tmp == -1) tmp = cnt;\r\n\t\t\t\tassert(cnt == tmp);\r\
    \n\t\t\t\treturn node;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tif (!node->isred) ++cnt;\r\
    \n\t\t\t\r\n\t\t\tif (node->child[0]) {\r\n\t\t\t\tassert(node->child[0]->val\
    \ <= node->val);\r\n\t\t\t\tassert(!node->isred || !node->child[0]->isred);\r\n\
    \t\t\t\tif (par) assert(node == par->child[node->isright]);\r\n\t\t\t\telse assert(root\
    \ == node);\r\n\t\t\t}\r\n\t\t\tself(self, node->child[0], node, cnt);\r\n\t\t\
    \t\r\n\t\t\tif (node->child[1]) {\r\n\t\t\t\tassert(node->child[1]->val >= node->val);\r\
    \n\t\t\t\tassert(!node->isred || !node->child[1]->isred);\r\n\t\t\t\tif (par)\
    \ assert(node == par->child[node->isright]);\r\n\t\t\t\telse assert(root == node);\r\
    \n\t\t\t}\r\n\t\t\tself(self, node->child[1], node, cnt);\r\n\t\t\treturn node;\r\
    \n\t\t};\r\n\t\tdfs(dfs, root, nullptr, 0);\r\n\t\treturn true;\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tvoid rotate(node_ptr node, bool rotR) {\r\n\t\tnode_ptr u = node->child[!rotR];\r\
    \n\t\tnode_ptr b = u->child[rotR];\r\n\t\t\r\n\t\tif (node->par) node->par->child[node->isright]\
    \ = u;\r\n\t\telse root = u;\r\n\t\t\r\n\t\tu->par = node->par;\r\n\t\tu->isright\
    \ = node->isright;\r\n\t\tu->child[rotR] = node;\r\n\t\t\r\n\t\tnode->par = u;\r\
    \n\t\tnode->isright = rotR;\r\n\t\tnode->child[!rotR] = b;\r\n\t\t\r\n\t\tif (b)\
    \ {\r\n\t\t\tb->par = node;\r\n\t\t\tb->isright = !rotR;\r\n\t\t}\r\n\t}\r\n\t\
    \r\n\tnode_ptr move(node_ptr node, bool isnext) const {\r\n\t\tif (node->child[isnext])\
    \ {\r\n\t\t\tnode = node->child[isnext];\r\n\t\t\twhile (node->child[!isnext])\
    \ node = node->child[!isnext];\r\n\t\t}\r\n\t\telse {\r\n\t\t\twhile (node &&\
    \ (!node->isright ^ isnext)) node = node->par;\r\n\t\t\tif (node) node = node->par;\r\
    \n\t\t}\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tvoid erase_sub(node_ptr node) {\r\
    \n\t\t// |node->child| \\leq 1\r\n\t\tbool isred = node->isred;\r\n\t\tbool isright\
    \ = node->isright;\r\n\t\t\r\n\t\tnode_ptr par = node->par;\r\n\t\tfor (size_type\
    \ i = 0; i < 2; ++i) {\r\n\t\t\tif (node->child[i]) {\r\n\t\t\t\tif (par) par->child[node->isright]\
    \ = node->child[i];\r\n\t\t\t\telse root = node->child[i];\r\n\t\t\t\tnode->child[i]->par\
    \ = par;\r\n\t\t\t\tnode->child[i]->isright = node->isright;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tif (!node->child[0] && !node->child[1]) {\r\n\t\t\tif (par) par->child[node->isright]\
    \ = nullptr;\r\n\t\t\telse root = nullptr;\r\n\t\t}\r\n\t\tdelete node;\r\n\t\t\
    --n;\r\n\t\tif (isred) return;\r\n\t\t\r\n\t\twhile (par) {\r\n\t\t\t// exists(par->child[!isright])\
    \ = true\r\n\t\t\t// isright = -1-subtree\r\n\t\t\tnode_ptr b = par->child[!isright];\r\
    \n\t\t\t\r\n\t\t\tif (b->isred) {\r\n\t\t\t\t// par = black, b = red\r\n\t\t\t\
    \trotate(par, isright);\r\n\t\t\t\tb->isred = false;\r\n\t\t\t\tpar->isred = true;\r\
    \n\t\t\t\tb = par->child[!isright];\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tnode_ptr tar\
    \ = b->child[!isright];\r\n\t\t\tif (tar && tar->isred) {\r\n\t\t\t\trotate(par,\
    \ isright);\r\n\t\t\t\tb->isred = par->isred;\r\n\t\t\t\tpar->isred = false;\r\
    \n\t\t\t\ttar->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\
    tar = b->child[isright];\r\n\t\t\tif (tar && tar->isred) {\r\n\t\t\t\trotate(b,\
    \ !isright);\r\n\t\t\t\trotate(par, isright);\r\n\t\t\t\ttar->isred = par->isred;\r\
    \n\t\t\t\tpar->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tb->isred =\
    \ true;\r\n\t\t\tif (par->isred) {\r\n\t\t\t\tpar->isred = false;\r\n\t\t\t\t\
    break;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tisright = par->isright;\r\n\t\t\tpar = par->par;\r\
    \n\t\t}\r\n\t\t\r\n\t\tif (root) root->isred = false;\r\n\t}\r\n\t\r\npublic:\r\
    \n\t// void debug() {\r\n\t// \tif (!root) {\r\n\t// \t\tstd::cout << \"debug\
    \ : empty\" << std::endl;\r\n\t// \t\treturn;\r\n\t// \t}\r\n\t// \tauto dfs =\
    \ [&](auto &&self, node_ptr cur) -> void {\r\n\t// \t\tif (!root) std::cout <<\
    \ \"empty\" << std::endl;\r\n\t// \t\tif (!cur) return;\r\n\t\t\t\r\n\t// \t\t\
    std::cout << \"val = \" << cur->val << \", color = \" << (cur->isred ? \"red\"\
    \ : \"black\");\r\n\t// \t\tif (cur->par) std::cout << \", par = \" << cur->par->val\
    \ << \", \" << (cur->isright ? \"right\" : \"left\");\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", leftval = \";\r\n\t// \t\tif (!cur->child[0]) std::cout << \"null\";\r\
    \n\t// \t\telse std::cout << cur->child[0]->val;\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", rightval = \";\r\n\t// \t\tif (!cur->child[1]) std::cout << \"null\"\
    ;\r\n\t// \t\telse std::cout << cur->child[1]->val;\r\n\t// \t\tstd::cout << std::endl;\r\
    \n\t\t\t\r\n\t// \t\tif (cur->child[0]) {\r\n\t// \t\t\tstd::cout << \"move left\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[0]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->child[1]) {\r\n\t// \t\t\tstd::cout << \"move right\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[1]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->par) std::cout << \"move par -> val = \" << cur->par->val\
    \ << std::endl;\r\n\t// \t};\r\n\t// \tdfs(dfs, root);\r\n\t// }\r\n\t\r\n\t//\
    \ void debug() {\r\n\t// \tif (!root) {\r\n\t// \t\tstd::cout << \"debug : empty\"\
    \ << std::endl;\r\n\t// \t\treturn;\r\n\t// \t}\r\n\t// \tauto dfs = [&](auto\
    \ &&self, node_ptr cur) -> void {\r\n\t// \t\tif (!root) std::cout << \"empty\"\
    \ << std::endl;\r\n\t// \t\tif (!cur) return;\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \"val = \" << \"(\" << cur->val.first << \", \" << cur->val.second << \"\
    )\" << \", color = \" << (cur->isred ? \"red\" : \"black\");\r\n\t// \t\tif (cur->par)\
    \ std::cout << \", par = (\" << cur->par->val.first << \", \" << cur->par->val.second\
    \ << \")\" << \", \" << (cur->isright ? \"right\" : \"left\");\r\n\t\t\t\r\n\t\
    // \t\tstd::cout << \", leftval = \";\r\n\t// \t\tif (!cur->child[0]) std::cout\
    \ << \"null\";\r\n\t// \t\telse std::cout << \"(\" << cur->child[0]->val.first\
    \ << \", \" << cur->child[0]->val.second << \")\";\r\n\t\t\t\r\n\t// \t\tstd::cout\
    \ << \", rightval = \";\r\n\t// \t\tif (!cur->child[1]) std::cout << \"null\"\
    ;\r\n\t// \t\telse std::cout << \"(\" << cur->child[1]->val.first << \", \" <<\
    \ cur->child[1]->val.second << \")\";\r\n\t// \t\tstd::cout << std::endl;\r\n\t\
    \t\t\r\n\t// \t\tif (cur->child[0]) {\r\n\t// \t\t\tstd::cout << \"move left\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[0]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->child[1]) {\r\n\t// \t\t\tstd::cout << \"move right\"\
    \ << std::endl;\r\n\t// \t\t\tself(self, cur->child[1]);\r\n\t// \t\t}\r\n\t\t\
    \t\r\n\t// \t\tif (cur->par) std::cout << \"move par -> val = \" <<  \"(\" <<\
    \ cur->par->val.first << \", \" << cur->par->val.second << \")\"<< std::endl;\r\
    \n\t// \t};\r\n\t// \tdfs(dfs, root);\r\n\t// }\r\n};\r\n\r\n#endif // INCLUDE_GUARD_RED_BLACK_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RedBlackTree.hpp
  requiredBy: []
  timestamp: '2020-09-21 15:29:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/RedBlackTree.test.cpp
documentation_of: DataStructure/RedBlackTree.hpp
layout: document
redirect_from:
- /library/DataStructure/RedBlackTree.hpp
- /library/DataStructure/RedBlackTree.hpp.html
title: DataStructure/RedBlackTree.hpp
---
