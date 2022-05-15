---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AVL_Tree.2.test.cpp
    title: Test/AVL_Tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AVL_Tree.test.cpp
    title: Test/AVL_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp
  bundledCode: "#line 1 \"DataStructure/AVL_Tree.hpp\"\n\n\n\r\n#include <algorithm>\r\
    \n#include <cstdint>\r\n#include <vector>\r\n#include <utility>\r\n#include <stack>\r\
    \n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct AVL_Tree {\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \t\r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\n\tusing int8 = std::int8_t;\r\
    \n\t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tnode_ptr\
    \ par, child[2] {nullptr, nullptr};\r\n\t\tbool isr;\r\n\t\tint8 height[2] {};\r\
    \n\t\tuint32 size[2] {};\r\n\t\tNode(const_reference val, node_ptr par, bool isr)\
    \ : val(val), par(par), isr(isr) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tsize_type n\
    \ = 0;\r\n\tnode_ptr root = nullptr;\r\n\tnode_ptr e_ptr[2] {nullptr, nullptr};\r\
    \n\t\r\npublic:\r\n\tAVL_Tree() = default;\r\n\t\r\n\tAVL_Tree(const AVL_Tree\
    \ & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tAVL_Tree(AVL_Tree && rhs) {\r\
    \n\t\t*this = std::forward<AVL_Tree>(rhs);\r\n\t}\r\n\t\r\n\t~AVL_Tree() {\r\n\
    \t\tclear();\r\n\t}\r\n\t\r\n\tAVL_Tree & operator =(const AVL_Tree & rhs) {\r\
    \n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tauto dfs = [](auto self,\
    \ const_ptr q, node_ptr r) -> node_ptr {\r\n\t\t\t\tif (!q) return nullptr;\r\n\
    \t\t\t\tnode_ptr res = new Node(q->val, r, q->isr);\r\n\t\t\t\tfor (int i = 0;\
    \ i < 2; ++i) {\r\n\t\t\t\t\tres->height[i] = q->height[i];\r\n\t\t\t\t\tres->size[i]\
    \ = q->size[i];\r\n\t\t\t\t\tres->child[i] = self(self, q->child[i], res);\r\n\
    \t\t\t\t}\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\troot = dfs(dfs, rhs.root,\
    \ nullptr);\r\n\t\t\tn = rhs.n;\r\n\t\t\te_ptr[0] = e_ptr[1] = root;\r\n\t\t\t\
    if (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tAVL_Tree & operator =(AVL_Tree\
    \ && rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\
    \n\t\t\trhs.n = 0;\r\n\t\t\troot = rhs.root;\r\n\t\t\trhs.root = nullptr;\r\n\t\
    \t\tstd::copy(rhs.e_ptr, rhs.e_ptr + 2, e_ptr);\r\n\t\t\tstd::fill(rhs.e_ptr,\
    \ rhs.e_ptr + 2, nullptr);\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tbool\
    \ empty() const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\
    \t\tif (!root) return;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tstk.emplace(root);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (node->child[0]) stk.emplace(node->child[0]);\r\n\t\t\tif (node->child[1])\
    \ stk.emplace(node->child[1]);\r\n\t\t\tdelete node;\r\n\t\t}\r\n\t\tn = 0;\r\n\
    \t\troot = nullptr;\r\n\t\tstd::fill(e_ptr, e_ptr + 2, nullptr);\r\n\t}\r\n\t\r\
    \n\tstd::vector<value_type> enumerate() const {\r\n\t\tstd::vector<value_type>\
    \ elements;\r\n\t\telements.reserve(size());\r\n\t\tauto dfs = [&elements](auto\
    \ self, const_ptr q) -> void {\r\n\t\t\tif (!q) return;\r\n\t\t\tself(self, q->child[0]);\r\
    \n\t\t\telements.emplace_back(q->val);\r\n\t\t\tself(self, q->child[1]);\r\n\t\
    \t};\r\n\t\tdfs(dfs, root);\r\n\t\treturn elements;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ begin() const noexcept {\r\n\t\treturn e_ptr[0];\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ end() const noexcept {\r\n\t\treturn nullptr;\r\n\t}\r\n\t\r\n\tnode_ptr insert(const_reference\
    \ x) {\r\n\t\tnode_ptr q = root, r = nullptr;\r\n\t\tbool ef[2] {}, d = false;\r\
    \n\t\twhile (q) {\r\n\t\t\tr = q;\r\n\t\t\td = q->val <= x;\r\n\t\t\tq = q->child[d];\r\
    \n\t\t\tef[!d] = true;\r\n\t\t}\r\n\t\tq = new Node(x, r, d);\r\n\t\t++n;\r\n\t\
    \tif (!ef[0]) e_ptr[0] = q;\r\n\t\tif (!ef[1]) e_ptr[1] = q;\r\n\t\tif (r) {\r\
    \n\t\t\tr->size[d] = 1;\r\n\t\t\tr->height[d] = 1;\r\n\t\t\tr->child[d] = q;\r\
    \n\t\t\tupdate(r);\r\n\t\t}\r\n\t\telse root = q;\r\n\t\treturn q;\r\n\t}\r\n\t\
    \r\n\tnode_ptr erase(const_reference x) noexcept {\r\n\t\tnode_ptr q = find(x);\r\
    \n\t\tif (q == end()) return end();\r\n\t\treturn erase(q);\r\n\t}\r\n\t\r\n\t\
    node_ptr erase(node_ptr q) noexcept {\r\n\t\tif (!q) return end();\r\n\t\tconst\
    \ node_ptr ret = next(q);\r\n\t\tif (q->child[0] && q->child[1]) {\r\n\t\t\tnode_ptr\
    \ p = q->child[0];\r\n\t\t\twhile (p->child[1]) p = p->child[1];\r\n\t\t\tq->val\
    \ = std::move(p->val);\r\n\t\t\tq = p;\r\n\t\t}\r\n\t\tif (e_ptr[0] == q) e_ptr[0]\
    \ = next(q);\r\n\t\tif (e_ptr[1] == q) e_ptr[1] = prev(q);\r\n\t\tconst node_ptr\
    \ r = q->par;\r\n\t\tif (q->child[0] || q->child[1]) {\r\n\t\t\tconst node_ptr\
    \ p = q->child[0] ? q->child[0] : q->child[1];\r\n\t\t\tif (r) {\r\n\t\t\t\tr->size[q->isr]\
    \ = q->size[p->isr];\r\n\t\t\t\tr->height[q->isr] = q->height[p->isr];\r\n\t\t\
    \t\tr->child[q->isr] = p;\r\n\t\t\t\tp->par = r;\r\n\t\t\t\tp->isr = q->isr;\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tp->par = nullptr;\r\n\t\t\t\troot = p;\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\telse if (r) {\r\n\t\t\tr->size[q->isr] = 0;\r\n\t\t\t\
    r->height[q->isr] = 0;\r\n\t\t\tr->child[q->isr] = nullptr;\r\n\t\t}\r\n\t\telse\
    \ root = nullptr;\r\n\t\tdelete q;\r\n\t\t--n;\r\n\t\tif (r) update(r);\r\n\t\t\
    return ret;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference x) const noexcept\
    \ {\r\n\t\tconst node_ptr q = lower_bound(x);\r\n\t\tif (q != end() && q->val\
    \ != x) return end();\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\t\tif (!q) return end();\r\
    \n\t\twhile (q->child[q->val < x]) q = q->child[q->val < x];\r\n\t\tif (q->val\
    \ < x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr upper_bound(const_reference\
    \ x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\t\tif (!q) return end();\r\
    \n\t\twhile (q->child[q->val <= x]) q = q->child[q->val <= x];\r\n\t\tif (q->val\
    \ <= x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tsize_type count_less_than(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tnode_ptr q = root;\r\n\t\
    \twhile (q != nullptr) {\r\n\t\t\tbool r = q->val < x;\r\n\t\t\tif (r) res +=\
    \ q->size[0] + 1;\r\n\t\t\tq = q->child[r];\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tsize_type count_less_equal(const_reference x) const noexcept {\r\n\
    \t\tsize_type res = 0;\r\n\t\tnode_ptr q = root;\r\n\t\twhile (q != nullptr) {\r\
    \n\t\t\tbool r = q->val <= x;\r\n\t\t\tif (r) res += q->size[0] + 1;\r\n\t\t\t\
    q = q->child[r];\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type count_greater_than(const_reference\
    \ x) const noexcept {\r\n\t\treturn size() - count_less_equal(x);\r\n\t}\r\n\t\
    \r\n\tsize_type count_greater_equal(const_reference x) const noexcept {\r\n\t\t\
    return size() - count_less_than(x);\r\n\t}\r\n\t\r\n\tsize_type count(const_reference\
    \ x) const noexcept {\r\n\t\treturn count_less_equal(x) - count_less_than(x);\r\
    \n\t}\r\n\t\r\n\tnode_ptr k_th_smallest(uint32 k) const noexcept {\r\n\t\tif (k\
    \ == 0 || n < k) return end();\r\n\t\tnode_ptr q = root;\r\n\t\twhile (k != q->size[0]\
    \ + 1) {\r\n\t\t\tif (k > q->size[0] + 1) k -= q->size[0] + 1, q = q->child[1];\r\
    \n\t\t\telse q = q->child[0];\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ k_th_largest(uint32 k) const noexcept {\r\n\t\tif (k == 0 || n < k) return end();\r\
    \n\t\treturn k_th_smallest(n - k + 1);\r\n\t}\r\n\t\r\n\tnode_ptr next(node_ptr\
    \ q) const noexcept {\r\n\t\treturn move(q, true);\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ prev(node_ptr q) const noexcept {\r\n\t\treturn move(q, false);\r\n\t}\r\n\t\
    \r\nprivate:\r\n\tnode_ptr rotate(node_ptr q, bool d) noexcept {\r\n\t\tnode_ptr\
    \ r = q->par, p = q->child[!d], b = p->child[d];\r\n\t\t(r ? r->child[q->isr]\
    \ : root) = p;\r\n\t\tq->child[!d] = b;\r\n\t\tp->child[d] = q;\r\n\t\tif (b)\
    \ {\r\n\t\t\tb->par = q;\r\n\t\t\tb->isr = !d;\r\n\t\t}\r\n\t\tp->par = r;\r\n\
    \t\tp->isr = q->isr;\r\n\t\tq->par = p;\r\n\t\tq->isr = d;\r\n\t\tq->size[!d]\
    \ = p->size[d];\r\n\t\tq->height[!d] = p->height[d];\r\n\t\tp->size[d] = q->size[0]\
    \ + q->size[1] + 1;\r\n\t\tp->height[d] = std::max(q->height[0], q->height[1])\
    \ + 1;\r\n\t\treturn p;\r\n\t}\r\n\t\r\n\tvoid update(node_ptr q) noexcept {\r\
    \n\t\tbool done = false;\r\n\t\twhile (true) {\r\n\t\t\tif (!done && std::abs(q->height[0]\
    \ - q->height[1]) > 1) {\r\n\t\t\t\tconst bool d = q->height[0] > q->height[1];\r\
    \n\t\t\t\tconst node_ptr p = q->child[!d];\r\n\t\t\t\tif (p->height[!d] < p->height[d])\
    \ rotate(p, !d);\r\n\t\t\t\tq = rotate(q, d);\r\n\t\t\t\tdone = true;\r\n\t\t\t\
    }\r\n\t\t\tconst node_ptr r = q->par;\r\n\t\t\tif (!r) break;\r\n\t\t\tr->size[q->isr]\
    \ = q->size[0] + q->size[1] + 1;\r\n\t\t\tr->height[q->isr] = std::max(q->height[0],\
    \ q->height[1]) + 1;\r\n\t\t\tq = r;\r\n\t\t}\r\n\t}\r\n\t\r\n\tnode_ptr move(node_ptr\
    \ q, bool d) const noexcept {\r\n\t\tif (q == end()) return e_ptr[!d];\r\n\t\t\
    if (q == begin() && !d) return end();\r\n\t\tif (q->child[d]) for (q = q->child[d];\
    \ q->child[!d]; q = q->child[!d]);\r\n\t\telse {\r\n\t\t\twhile (q && (d ^ !q->isr))\
    \ q = q->par;\r\n\t\t\tif (q) q = q->par;\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_AVL_TREE_HPP\r\n#define INCLUDE_GUARD_AVL_TREE_HPP\r\
    \n\r\n#include <algorithm>\r\n#include <cstdint>\r\n#include <vector>\r\n#include\
    \ <utility>\r\n#include <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct AVL_Tree {\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \t\r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\n\tusing int8 = std::int8_t;\r\
    \n\t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tnode_ptr\
    \ par, child[2] {nullptr, nullptr};\r\n\t\tbool isr;\r\n\t\tint8 height[2] {};\r\
    \n\t\tuint32 size[2] {};\r\n\t\tNode(const_reference val, node_ptr par, bool isr)\
    \ : val(val), par(par), isr(isr) {}\r\n\t};\r\n\t\r\nprivate:\r\n\tsize_type n\
    \ = 0;\r\n\tnode_ptr root = nullptr;\r\n\tnode_ptr e_ptr[2] {nullptr, nullptr};\r\
    \n\t\r\npublic:\r\n\tAVL_Tree() = default;\r\n\t\r\n\tAVL_Tree(const AVL_Tree\
    \ & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tAVL_Tree(AVL_Tree && rhs) {\r\
    \n\t\t*this = std::forward<AVL_Tree>(rhs);\r\n\t}\r\n\t\r\n\t~AVL_Tree() {\r\n\
    \t\tclear();\r\n\t}\r\n\t\r\n\tAVL_Tree & operator =(const AVL_Tree & rhs) {\r\
    \n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tauto dfs = [](auto self,\
    \ const_ptr q, node_ptr r) -> node_ptr {\r\n\t\t\t\tif (!q) return nullptr;\r\n\
    \t\t\t\tnode_ptr res = new Node(q->val, r, q->isr);\r\n\t\t\t\tfor (int i = 0;\
    \ i < 2; ++i) {\r\n\t\t\t\t\tres->height[i] = q->height[i];\r\n\t\t\t\t\tres->size[i]\
    \ = q->size[i];\r\n\t\t\t\t\tres->child[i] = self(self, q->child[i], res);\r\n\
    \t\t\t\t}\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\troot = dfs(dfs, rhs.root,\
    \ nullptr);\r\n\t\t\tn = rhs.n;\r\n\t\t\te_ptr[0] = e_ptr[1] = root;\r\n\t\t\t\
    if (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tAVL_Tree & operator =(AVL_Tree\
    \ && rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\
    \n\t\t\trhs.n = 0;\r\n\t\t\troot = rhs.root;\r\n\t\t\trhs.root = nullptr;\r\n\t\
    \t\tstd::copy(rhs.e_ptr, rhs.e_ptr + 2, e_ptr);\r\n\t\t\tstd::fill(rhs.e_ptr,\
    \ rhs.e_ptr + 2, nullptr);\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tbool\
    \ empty() const noexcept {\r\n\t\treturn size() == 0;\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid clear() {\r\n\
    \t\tif (!root) return;\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tstk.emplace(root);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (node->child[0]) stk.emplace(node->child[0]);\r\n\t\t\tif (node->child[1])\
    \ stk.emplace(node->child[1]);\r\n\t\t\tdelete node;\r\n\t\t}\r\n\t\tn = 0;\r\n\
    \t\troot = nullptr;\r\n\t\tstd::fill(e_ptr, e_ptr + 2, nullptr);\r\n\t}\r\n\t\r\
    \n\tstd::vector<value_type> enumerate() const {\r\n\t\tstd::vector<value_type>\
    \ elements;\r\n\t\telements.reserve(size());\r\n\t\tauto dfs = [&elements](auto\
    \ self, const_ptr q) -> void {\r\n\t\t\tif (!q) return;\r\n\t\t\tself(self, q->child[0]);\r\
    \n\t\t\telements.emplace_back(q->val);\r\n\t\t\tself(self, q->child[1]);\r\n\t\
    \t};\r\n\t\tdfs(dfs, root);\r\n\t\treturn elements;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ begin() const noexcept {\r\n\t\treturn e_ptr[0];\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ end() const noexcept {\r\n\t\treturn nullptr;\r\n\t}\r\n\t\r\n\tnode_ptr insert(const_reference\
    \ x) {\r\n\t\tnode_ptr q = root, r = nullptr;\r\n\t\tbool ef[2] {}, d = false;\r\
    \n\t\twhile (q) {\r\n\t\t\tr = q;\r\n\t\t\td = q->val <= x;\r\n\t\t\tq = q->child[d];\r\
    \n\t\t\tef[!d] = true;\r\n\t\t}\r\n\t\tq = new Node(x, r, d);\r\n\t\t++n;\r\n\t\
    \tif (!ef[0]) e_ptr[0] = q;\r\n\t\tif (!ef[1]) e_ptr[1] = q;\r\n\t\tif (r) {\r\
    \n\t\t\tr->size[d] = 1;\r\n\t\t\tr->height[d] = 1;\r\n\t\t\tr->child[d] = q;\r\
    \n\t\t\tupdate(r);\r\n\t\t}\r\n\t\telse root = q;\r\n\t\treturn q;\r\n\t}\r\n\t\
    \r\n\tnode_ptr erase(const_reference x) noexcept {\r\n\t\tnode_ptr q = find(x);\r\
    \n\t\tif (q == end()) return end();\r\n\t\treturn erase(q);\r\n\t}\r\n\t\r\n\t\
    node_ptr erase(node_ptr q) noexcept {\r\n\t\tif (!q) return end();\r\n\t\tconst\
    \ node_ptr ret = next(q);\r\n\t\tif (q->child[0] && q->child[1]) {\r\n\t\t\tnode_ptr\
    \ p = q->child[0];\r\n\t\t\twhile (p->child[1]) p = p->child[1];\r\n\t\t\tq->val\
    \ = std::move(p->val);\r\n\t\t\tq = p;\r\n\t\t}\r\n\t\tif (e_ptr[0] == q) e_ptr[0]\
    \ = next(q);\r\n\t\tif (e_ptr[1] == q) e_ptr[1] = prev(q);\r\n\t\tconst node_ptr\
    \ r = q->par;\r\n\t\tif (q->child[0] || q->child[1]) {\r\n\t\t\tconst node_ptr\
    \ p = q->child[0] ? q->child[0] : q->child[1];\r\n\t\t\tif (r) {\r\n\t\t\t\tr->size[q->isr]\
    \ = q->size[p->isr];\r\n\t\t\t\tr->height[q->isr] = q->height[p->isr];\r\n\t\t\
    \t\tr->child[q->isr] = p;\r\n\t\t\t\tp->par = r;\r\n\t\t\t\tp->isr = q->isr;\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tp->par = nullptr;\r\n\t\t\t\troot = p;\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\telse if (r) {\r\n\t\t\tr->size[q->isr] = 0;\r\n\t\t\t\
    r->height[q->isr] = 0;\r\n\t\t\tr->child[q->isr] = nullptr;\r\n\t\t}\r\n\t\telse\
    \ root = nullptr;\r\n\t\tdelete q;\r\n\t\t--n;\r\n\t\tif (r) update(r);\r\n\t\t\
    return ret;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference x) const noexcept\
    \ {\r\n\t\tconst node_ptr q = lower_bound(x);\r\n\t\tif (q != end() && q->val\
    \ != x) return end();\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr lower_bound(const_reference\
    \ x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\t\tif (!q) return end();\r\
    \n\t\twhile (q->child[q->val < x]) q = q->child[q->val < x];\r\n\t\tif (q->val\
    \ < x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr upper_bound(const_reference\
    \ x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\t\tif (!q) return end();\r\
    \n\t\twhile (q->child[q->val <= x]) q = q->child[q->val <= x];\r\n\t\tif (q->val\
    \ <= x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tsize_type count_less_than(const_reference\
    \ x) const noexcept {\r\n\t\tsize_type res = 0;\r\n\t\tnode_ptr q = root;\r\n\t\
    \twhile (q != nullptr) {\r\n\t\t\tbool r = q->val < x;\r\n\t\t\tif (r) res +=\
    \ q->size[0] + 1;\r\n\t\t\tq = q->child[r];\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\t\r\n\tsize_type count_less_equal(const_reference x) const noexcept {\r\n\
    \t\tsize_type res = 0;\r\n\t\tnode_ptr q = root;\r\n\t\twhile (q != nullptr) {\r\
    \n\t\t\tbool r = q->val <= x;\r\n\t\t\tif (r) res += q->size[0] + 1;\r\n\t\t\t\
    q = q->child[r];\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type count_greater_than(const_reference\
    \ x) const noexcept {\r\n\t\treturn size() - count_less_equal(x);\r\n\t}\r\n\t\
    \r\n\tsize_type count_greater_equal(const_reference x) const noexcept {\r\n\t\t\
    return size() - count_less_than(x);\r\n\t}\r\n\t\r\n\tsize_type count(const_reference\
    \ x) const noexcept {\r\n\t\treturn count_less_equal(x) - count_less_than(x);\r\
    \n\t}\r\n\t\r\n\tnode_ptr k_th_smallest(uint32 k) const noexcept {\r\n\t\tif (k\
    \ == 0 || n < k) return end();\r\n\t\tnode_ptr q = root;\r\n\t\twhile (k != q->size[0]\
    \ + 1) {\r\n\t\t\tif (k > q->size[0] + 1) k -= q->size[0] + 1, q = q->child[1];\r\
    \n\t\t\telse q = q->child[0];\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ k_th_largest(uint32 k) const noexcept {\r\n\t\tif (k == 0 || n < k) return end();\r\
    \n\t\treturn k_th_smallest(n - k + 1);\r\n\t}\r\n\t\r\n\tnode_ptr next(node_ptr\
    \ q) const noexcept {\r\n\t\treturn move(q, true);\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ prev(node_ptr q) const noexcept {\r\n\t\treturn move(q, false);\r\n\t}\r\n\t\
    \r\nprivate:\r\n\tnode_ptr rotate(node_ptr q, bool d) noexcept {\r\n\t\tnode_ptr\
    \ r = q->par, p = q->child[!d], b = p->child[d];\r\n\t\t(r ? r->child[q->isr]\
    \ : root) = p;\r\n\t\tq->child[!d] = b;\r\n\t\tp->child[d] = q;\r\n\t\tif (b)\
    \ {\r\n\t\t\tb->par = q;\r\n\t\t\tb->isr = !d;\r\n\t\t}\r\n\t\tp->par = r;\r\n\
    \t\tp->isr = q->isr;\r\n\t\tq->par = p;\r\n\t\tq->isr = d;\r\n\t\tq->size[!d]\
    \ = p->size[d];\r\n\t\tq->height[!d] = p->height[d];\r\n\t\tp->size[d] = q->size[0]\
    \ + q->size[1] + 1;\r\n\t\tp->height[d] = std::max(q->height[0], q->height[1])\
    \ + 1;\r\n\t\treturn p;\r\n\t}\r\n\t\r\n\tvoid update(node_ptr q) noexcept {\r\
    \n\t\tbool done = false;\r\n\t\twhile (true) {\r\n\t\t\tif (!done && std::abs(q->height[0]\
    \ - q->height[1]) > 1) {\r\n\t\t\t\tconst bool d = q->height[0] > q->height[1];\r\
    \n\t\t\t\tconst node_ptr p = q->child[!d];\r\n\t\t\t\tif (p->height[!d] < p->height[d])\
    \ rotate(p, !d);\r\n\t\t\t\tq = rotate(q, d);\r\n\t\t\t\tdone = true;\r\n\t\t\t\
    }\r\n\t\t\tconst node_ptr r = q->par;\r\n\t\t\tif (!r) break;\r\n\t\t\tr->size[q->isr]\
    \ = q->size[0] + q->size[1] + 1;\r\n\t\t\tr->height[q->isr] = std::max(q->height[0],\
    \ q->height[1]) + 1;\r\n\t\t\tq = r;\r\n\t\t}\r\n\t}\r\n\t\r\n\tnode_ptr move(node_ptr\
    \ q, bool d) const noexcept {\r\n\t\tif (q == end()) return e_ptr[!d];\r\n\t\t\
    if (q == begin() && !d) return end();\r\n\t\tif (q->child[d]) for (q = q->child[d];\
    \ q->child[!d]; q = q->child[!d]);\r\n\t\telse {\r\n\t\t\twhile (q && (d ^ !q->isr))\
    \ q = q->par;\r\n\t\t\tif (q) q = q->par;\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_AVL_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/AVL_Tree.hpp
  requiredBy: []
  timestamp: '2021-03-13 13:17:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AVL_Tree.2.test.cpp
  - Test/AVL_Tree.test.cpp
documentation_of: DataStructure/AVL_Tree.hpp
layout: document
title: "AVL \u6728 (\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728)"
---

# 概要

順序付き集合を扱う AVL 木です。
要素数 $N$ に対し、基本的な操作を $\Theta(\log{N})$ で行うことができます。  

- `AVL_Tree()`
	- $\Theta(1)$ 空の AVL 木を作成
- `AVL_Tree(const AVL_Tree & rhs)`
	- $\Theta(\|$`rhs`$\|)$ `rhs` をコピー
- `AVL_Tree(AVL_Tree && rhs)`
	- $\Theta(1)$ `rhs` をムーブ
- `bool empty()`
	- $\Theta(1)$ AVL 木が空であるか判定
- `size_t size()`
	- $\Theta(1)$ 要素数 $N$ を返す
- `void clear()`
	- $\Theta(N)$ すべての要素を削除
- `std::vector<T> enumerate()`
	- $\Theta(N)$ すべての要素を昇順に列挙
- `Node * begin()`
	- $\Theta(1)$ 先頭の要素のポインタを返す
- `Node * end()`
	- $\Theta(1)$ 最後の要素の次の位置を示すポインタを返す
- `Node * insert(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ を追加
- `Node * erase(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の中で先頭の要素を削除し、その次の要素のポインタを返す
- `Node * erase(Node * q)`
	- $\Theta(\log{N})$ ポインタ $q$ が指す要素を削除し、その次の要素のポインタを返す
- `Node * find(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の中で先頭の要素のポインタを返す
- `Node * lower_bound(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以上の要素の中で先頭の要素のポインタを返す
- `Node * upper_bound(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ より大きい要素の中で先頭の要素のポインタを返す
- `size_t count_less_than(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 未満の要素の個数を返す
- `size_t count_less_equal(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以下の要素の個数を返す
- `size_t count_greater_than(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ より大きい要素の個数を返す
- `size_t count_greater_equal(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ 以上の要素の個数を返す
- `size_t count(const T & x)`
	- $\Theta(\log{N})$ 値 $x$ と等しい要素の個数を返す
- `Node * k_th_smallest(uint32_t k)`
	- $\Theta(\log{N})$ 先頭から $k$ 番目の要素のポインタを返す
- `Node * k_th_largest(uint32_t k)`
	- $\Theta(\log{N})$ 後ろから $k$ 番目の要素のポインタを返す
- `Node * next(Node * q)`
	- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$ ポインタ $q$ が指す要素の次の要素のポインタを返す
- `Node * prev(Node * q)`
	- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$ ポインタ $q$ が指す要素の $1$ つ前の要素のポインタを返す

<br>

# コンストラクタ

以降、要素数を $N$ とします。  

---

**制約**

- `T` は比較可能

---

### AVL_Tree()

空の AVL 木を作成します。  

**計算量**

- $\Theta(1)$

---

### AVL_Tree(const AVL_Tree & rhs)

`rhs` をコピーします。  

**計算量**

- $\Theta(N + \|$`rhs`$\|)$

---

### AVL_Tree(AVL_Tree && rhs)

`rhs` をムーブします。
ムーブ後の `rhs` は空の AVL 木となります。  

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

すべての要素は値の昇順に、同じ値同士は追加した順に順序付けされているとします。  

---

### bool empty()

AVL 木が空であるか判定します。
空なら $true$ 、そうでないなら $false$ を返します。  

**計算量**

- $\Theta(1)$

---

### size_t size()

要素数 $N$ を返します。  

**計算量**

- $\Theta(1)$

---

### void clear()

すべての要素を削除します。  

**計算量**

- $\Theta(N)$

---

### std::vector<T> enumerate()

すべての要素を昇順に列挙します。  

**計算量**

- $\Theta(N)$

---

### Node * begin()

先頭の要素のポインタを返します。  

**計算量**

- $\Theta(1)$

---

### Node * end()

最後の要素の次の位置を示すポインタを返します。  

**計算量**

- $\Theta(1)$

---

### Node * insert(const T & x)

値 $x$ を追加します。
追加した要素のポインタを返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * erase(const T & x)

値 $x$ と等しい要素の中で先頭の要素を削除し、その次の要素のポインタを返します。
値 $x$ が存在しない場合は何も行わず、`end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * erase(Node * q)

ポインタ $q$ が指す要素を削除し、その次の要素のポインタを返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\Theta(\log{N})$

---

### Node * find(const T & x)

値 $x$ と等しい要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * lower_bound(const T & x)

値 $x$ 以上の要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * upper_bound(const T & x)

値 $x$ より大きい要素の中で先頭の要素のポインタを返します。
そのような要素が存在しない場合は `end()` を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_less_than(const T & x)

値 $x$ 未満の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_less_equal(const T & x)

値 $x$ 以下の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_greater_than(const T & x)

値 $x$ より大きい要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count_greater_equal(const T & x)

値 $x$ 以上の要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### size_t count(const T & x)

値 $x$ と等しい要素の個数を返します。  

**計算量**

- $\Theta(\log{N})$

---

### Node * k_th_smallest(uint32_t k)

先頭から $k$ 番目の要素のポインタを返します。
$k = 0$ またはそのような要素が存在しない場合は `end()` を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\Theta(\log{N})$

---

### Node * k_th_largest(uint32_t k)

後ろから $k$ 番目の要素のポインタを返します。
$k = 0$ またはそのような要素が存在しない場合は `end()` を返します。  

**制約**

- $0 \leq k$

**計算量**

- $\Theta(\log{N})$

---

### Node * next(Node * q)

ポインタ $q$ が指す要素の次の要素のポインタを返します。
$q =$ `end()` の場合は `begin()` を返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$

---

### Node * prev(Node * q)

ポインタ $q$ が指す要素の $1$ つ前の要素のポインタを返します。
$q =$ `begin()` の場合は `end()` を返します。  

**制約**

- $q$ は有効なポインタ

**計算量**

- $\mathcal{O}(\log{N})$, ならし $\Theta(1)$

---

<br>

# 使用例

```cpp
#include <bits/stdc++.h>
#include "DataStructure/AVL_Tree.hpp"
using namespace std;

int main() {
	AVL_Tree<int> avl;
	cout << "size = " << avl.size() << endl; // 0
	
	for (int i : {1, 2, 2, 3, 4, 5, 6, 6, 6, 7}) avl.insert(i);
	cout << "size = " << avl.size() << endl; // 10
	
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 2 3 4 5 6 6 6 7
	cout << "min = " << avl.begin()->val << endl; // 1
	cout << "max = " << avl.prev(avl.end())->val << endl; // 7
	
	auto it = avl.find(2);
	cout << "find(2) : " << it->val << endl; // 2
	cout << "next : " << avl.next(it)->val << endl; // 2
	cout << "prev : " << avl.prev(it)->val << endl; // 1
	
	avl.erase(it);
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 6 7
	avl.erase(6);
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	
	cout << "lower_bound(-1) = " << avl.lower_bound(-1)->val << endl; // 1
	cout << "upper_bound(6) = " << avl.upper_bound(6)->val << endl; // 7
	cout << "upper_bound(7) == end() : " << boolalpha << (avl.upper_bound(7) == avl.end()) << endl; // true
	
	cout << "count_less_than(3) = " << avl.count_less_than(3) << endl; // 2
	cout << "count_less_equal(4) = " << avl.count_less_equal(4) << endl; // 4
	cout << "count_greater_than(6) = " << avl.count_greater_than(6) << endl; // 1
	cout << "count_greater_equal(6) = " << avl.count_greater_equal(6) << endl; // 3
	cout << "count(6) = " << avl.count(6) << endl; // 2
	cout << "count_greater_than(7) = " << avl.count_greater_than(7) << endl; // 0
	
	cout << "k_th_smallest(3) = " << avl.k_th_smallest(3)->val << endl; // 3
	cout << "k_th_largest(4) = " << avl.k_th_largest(4)->val << endl; // 5
	
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		AVL_Tree<int> avl2 = avl;
		for (int i : avl2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		AVL_Tree<int> avl2 = std::move(avl);
		for (int i : avl2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : avl.enumerate()) cout << i << " "; cout << '\n'; // empty
	cout << "empty = " << boolalpha << avl.empty() << endl; // true
}
```

<br>

# 解説

### AVL 木の高さと頂点数の関係

ここでは、根と葉のパスに含まれる辺の個数の最大値を AVL 木の高さと定義し、頂点数 $N$ の AVL 木の高さがどれくらいになるか調べます。  

$C_i :=$ 高さが $i$ である AVL 木の最小頂点数 と定義します。
AVL 木の平衡条件より左部分木と右部分木の高さの差は $1$ 以下で、高さが低い方が最小頂点数は少ないので次のような関係式が成り立ちます。  

$$C_0 = 1, C_1 = 2, C_i = C_{i-1} + C_{i-2} + 1\ (i \geq 2)$$

フィボナッチ数列 $F_0 = 1, F_1 = 1, F_i = F_{i-1} + F_{i-2}\ (i \geq 2)$ と比較すると $C_i \geq F_i$ より、頂点数 $N$ に対して高さは $\mathcal{O}(\log{N})$ であることが分かります。  

また、高さ $h$ に対して頂点数が最大となるのは完全二分木 (葉以外の頂点がすべて $2$ つの子を持つ) となっているときで、頂点数 $N$ に対して最小の高さは $\Omega(\log{N})$ です。  

以上より、頂点数 $N$ の AVL 木の高さは $\Theta(\log{N})$ であることが分かりました。  

# TODO

TODO: イテレータを実装(アドレス解決演算子やアロー演算子で `val` にアクセスしたい)  
TODO: `size`, `height` を子ではなく自身で持つように変更(必要な空間が減る)

<br>

# 参考

2019/11/19: [https://ja.wikipedia.org/wiki/AVL%E6%9C%A8](https://ja.wikipedia.org/wiki/AVL%E6%9C%A8)  

<br>