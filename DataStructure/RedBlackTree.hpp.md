---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/RedBlackTree.lower.upper.test.cpp
    title: Test/RedBlackTree.lower.upper.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/RedBlackTree.test.cpp
    title: Test/RedBlackTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: https://tkmst201.github.io/Library/DataStructure/RedBlackTree.hpp
    links:
    - https://tkmst201.github.io/Library/DataStructure/RedBlackTree.hpp
  bundledCode: "#line 1 \"DataStructure/RedBlackTree.hpp\"\n\n\n\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <utility>\r\n#include <stack>\r\n\r\n/**\r\n *\
    \ @brief https://tkmst201.github.io/Library/DataStructure/RedBlackTree.hpp\r\n\
    \ */\r\ntemplate<typename T>\r\nstruct RedBlackTree {\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing const_ptr\
    \ = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\t\tbool\
    \ isred;\r\n\t\tnode_ptr par;\r\n\t\tbool isr;\r\n\t\tnode_ptr child[2] {nullptr,\
    \ nullptr};\r\n\t\tNode(const_reference val, bool isred, node_ptr par, bool isr)\r\
    \n\t\t\t: val(val), isred(isred), par(par), isr(isr) {}\r\n\t};\r\n\t\r\nprivate:\r\
    \n\tsize_type n = 0;\r\n\tnode_ptr root = nullptr;\r\n\tnode_ptr e_ptr[2] {nullptr,\
    \ nullptr};\r\n\t\r\npublic:\r\n\tRedBlackTree() = default;\r\n\t\r\n\tRedBlackTree(const\
    \ RedBlackTree & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\n\t\r\n\tRedBlackTree(RedBlackTree\
    \ && rhs) {\r\n\t\t*this = std::forward<RedBlackTree>(rhs);\r\n\t}\r\n\t\r\n\t\
    ~RedBlackTree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\tRedBlackTree & operator =(const\
    \ RedBlackTree & rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\tclear();\r\n\t\t\t\
    auto dfs = [](auto self, const_ptr q, node_ptr r) -> node_ptr {\r\n\t\t\t\tif\
    \ (!q) return nullptr;\r\n\t\t\t\tnode_ptr res = new Node(q->val, q->isred, r,\
    \ q->isr);\r\n\t\t\t\tfor (int i = 0; i < 2; ++i) res->child[i] = self(self, q->child[i],\
    \ res);\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\troot = dfs(dfs, rhs.root,\
    \ nullptr);\r\n\t\t\tn = rhs.n;\r\n\t\t\te_ptr[0] = e_ptr[1] = root;\r\n\t\t\t\
    if (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\tRedBlackTree & operator =(RedBlackTree\
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
    \ x) {\r\n\t\tnode_ptr p = nullptr, node = root;\r\n\t\tbool ef[2] {}, d = false;\r\
    \n\t\twhile (node) {\r\n\t\t\td = node->val <= x;\r\n\t\t\tp = node;\r\n\t\t\t\
    node = node->child[d];\r\n\t\t\tef[!d] = true;\r\n\t\t}\r\n\t\tnode = new Node{x,\
    \ true, p, d};\r\n\t\t++n;\r\n\t\tif (!ef[0]) e_ptr[0] = node;\r\n\t\tif (!ef[1])\
    \ e_ptr[1] = node;\r\n\t\tif (!p) {\r\n\t\t\troot = node;\r\n\t\t\tnode->isred\
    \ = false;\r\n\t\t\treturn node;\r\n\t\t}\r\n\t\tp->child[d] = node;\r\n\t\tif\
    \ (!p->isred) return node;\r\n\t\tnode_ptr g = p->par, u = g->child[!p->isr];\r\
    \n\t\tif (!u) {\r\n\t\t\tif (node->isr == p->isr) {\r\n\t\t\t\trotate(g, !p->isr);\r\
    \n\t\t\t\tp->isred = false;\r\n\t\t\t\tg->isred = true;\r\n\t\t\t\treturn node;\r\
    \n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tp->child[node->isr] = nullptr;\r\n\t\t\t\t\
    g->child[!p->isr] = node;\r\n\t\t\t\tnode->par = g;\r\n\t\t\t\tstd::swap(g->val,\
    \ node->val);\r\n\t\t\t\tif (e_ptr[0] == g) e_ptr[0] = node;\r\n\t\t\t\tif (e_ptr[1]\
    \ == g) e_ptr[1] = node;\r\n\t\t\t\treturn g;\r\n\t\t\t}\r\n\t\t}\r\n\t\twhile\
    \ (u->isred) {\r\n\t\t\tg->isred = true;\r\n\t\t\tp->isred = false;\r\n\t\t\t\
    u->isred = false;\r\n\t\t\tconst node_ptr cur = g;\r\n\t\t\tp = cur->par;\r\n\t\
    \t\tif (!p) { cur->isred = false; break; }\r\n\t\t\tif (!p->isred) break;\r\n\t\
    \t\tg = p->par;\r\n\t\t\tu = g->child[!p->isr];\r\n\t\t\tif (!u->isred) {\r\n\t\
    \t\t\tif (cur->isr == p->isr) {\r\n\t\t\t\t\trotate(g, !p->isr);\r\n\t\t\t\t\t\
    p->isred = false;\r\n\t\t\t\t\tg->isred = true;\r\n\t\t\t\t}\r\n\t\t\t\telse {\r\
    \n\t\t\t\t\trotate(p, p->isr);\r\n\t\t\t\t\trotate(g, !p->isr);\r\n\t\t\t\t\t\
    cur->isred = false;\r\n\t\t\t\t\tg->isred = true;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr erase(const_reference x) noexcept\
    \ {\r\n\t\tnode_ptr q = find(x);\r\n\t\tif (q == end()) return end();\r\n\t\t\
    return erase(q);\r\n\t}\r\n\t\r\n\tnode_ptr erase(node_ptr q) noexcept {\r\n\t\
    \tif (!q) return end();\r\n\t\tnode_ptr ret = next(q);\r\n\t\tif (q->child[0])\
    \ {\r\n\t\t\tnode_ptr p = q->child[0];\r\n\t\t\twhile (p->child[1]) p = p->child[1];\r\
    \n\t\t\tq->val = std::move(p->val);\r\n\t\t\tq = p;\r\n\t\t}\r\n\t\tif (e_ptr[0]\
    \ == q) e_ptr[0] = next(q);\r\n\t\tif (e_ptr[1] == q) e_ptr[1] = prev(q);\r\n\t\
    \tnode_ptr ch = q->child[0] ? q->child[0] : q->child[1];\r\n\t\tif (ch) {\r\n\t\
    \t\tq->val = std::move(ch->val);\r\n\t\t\tif (e_ptr[0] == ch) e_ptr[0] = q;\r\n\
    \t\t\tif (e_ptr[1] == ch) e_ptr[1] = q;\r\n\t\t\tif (ret == ch) ret = q;\r\n\t\
    \t\tq = ch;\r\n\t\t}\r\n\t\tnode_ptr p = q->par;\r\n\t\tbool isred = q->isred,\
    \ isr = q->isr;\r\n\t\t(p ? p->child[q->isr] : root) = nullptr;\r\n\t\tdelete\
    \ q;\r\n\t\t--n;\r\n\t\tif (!root || isred) return ret;\r\n\t\twhile (p) {\r\n\
    \t\t\tnode_ptr c = p->child[!isr];\r\n\t\t\tif (c->isred) {\r\n\t\t\t\trotate(p,\
    \ isr);\r\n\t\t\t\tc->isred = false;\r\n\t\t\t\tp->isred = true;\r\n\t\t\t\tc\
    \ = p->child[!isr];\r\n\t\t\t}\r\n\t\t\tnode_ptr g = c->child[!isr];\r\n\t\t\t\
    if (g && g->isred) {\r\n\t\t\t\trotate(p, isr);\r\n\t\t\t\tc->isred = p->isred;\r\
    \n\t\t\t\tg->isred = false;\r\n\t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\
    \t\t\t}\r\n\t\t\tg = c->child[isr];\r\n\t\t\tif (g && g->isred) {\r\n\t\t\t\t\
    rotate(c, !isr);\r\n\t\t\t\trotate(p, isr);\r\n\t\t\t\tg->isred = p->isred;\r\n\
    \t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tc->isred = true;\r\
    \n\t\t\tif (p->isred) {\r\n\t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\
    \t}\r\n\t\t\tisr = p->isr;\r\n\t\t\tp = p->par;\r\n\t\t}\r\n\t\tif (root) root->isred\
    \ = false;\r\n\t\treturn ret;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference\
    \ x) const noexcept {\r\n\t\tconst node_ptr q = lower_bound(x);\r\n\t\tif (q !=\
    \ end() && q->val != x) return end();\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ lower_bound(const_reference x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\
    \t\tif (!q) return end();\r\n\t\twhile (q->child[q->val < x]) q = q->child[q->val\
    \ < x];\r\n\t\tif (q->val < x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\t\
    node_ptr upper_bound(const_reference x) const noexcept {\r\n\t\tnode_ptr q = root;\r\
    \n\t\tif (!q) return end();\r\n\t\twhile (q->child[q->val <= x]) q = q->child[q->val\
    \ <= x];\r\n\t\tif (q->val <= x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\
    \tnode_ptr next(node_ptr q) const noexcept {\r\n\t\treturn move(q, true);\r\n\t\
    }\r\n\t\r\n\tnode_ptr prev(node_ptr q) const noexcept {\r\n\t\treturn move(q,\
    \ false);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid rotate(node_ptr q, bool d) noexcept\
    \ {\r\n\t\tnode_ptr r = q->par, p = q->child[!d], b = p->child[d];\r\n\t\t(r ?\
    \ r->child[q->isr] : root) = p;\r\n\t\tq->child[!d] = b;\r\n\t\tp->child[d] =\
    \ q;\r\n\t\tif (b) {\r\n\t\t\tb->par = q;\r\n\t\t\tb->isr = !d;\r\n\t\t}\r\n\t\
    \tp->par = r;\r\n\t\tp->isr = q->isr;\r\n\t\tq->par = p;\r\n\t\tq->isr = d;\r\n\
    \t}\r\n\t\r\n\tnode_ptr move(node_ptr q, bool d) const noexcept {\r\n\t\tif (q\
    \ == end()) return e_ptr[!d];\r\n\t\tif (q == begin() && !d) return end();\r\n\
    \t\tif (q->child[d]) for (q = q->child[d]; q->child[!d]; q = q->child[!d]);\r\n\
    \t\telse {\r\n\t\t\twhile (q && (d ^ !q->isr)) q = q->par;\r\n\t\t\tif (q) q =\
    \ q->par;\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n};\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_RED_BLACK_TREE_HPP\r\n#define INCLUDE_GUARD_RED_BLACK_TREE_HPP\r\
    \n\r\n#include <algorithm>\r\n#include <vector>\r\n#include <utility>\r\n#include\
    \ <stack>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/RedBlackTree.hpp\r\
    \n */\r\ntemplate<typename T>\r\nstruct RedBlackTree {\r\n\tusing size_type =\
    \ std::size_t;\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type\
    \ &;\r\n\t\r\npublic:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tusing\
    \ const_ptr = const Node * const;\r\n\tstruct Node {\r\n\t\tvalue_type val;\r\n\
    \t\tbool isred;\r\n\t\tnode_ptr par;\r\n\t\tbool isr;\r\n\t\tnode_ptr child[2]\
    \ {nullptr, nullptr};\r\n\t\tNode(const_reference val, bool isred, node_ptr par,\
    \ bool isr)\r\n\t\t\t: val(val), isred(isred), par(par), isr(isr) {}\r\n\t};\r\
    \n\t\r\nprivate:\r\n\tsize_type n = 0;\r\n\tnode_ptr root = nullptr;\r\n\tnode_ptr\
    \ e_ptr[2] {nullptr, nullptr};\r\n\t\r\npublic:\r\n\tRedBlackTree() = default;\r\
    \n\t\r\n\tRedBlackTree(const RedBlackTree & rhs) {\r\n\t\t*this = rhs;\r\n\t}\r\
    \n\t\r\n\tRedBlackTree(RedBlackTree && rhs) {\r\n\t\t*this = std::forward<RedBlackTree>(rhs);\r\
    \n\t}\r\n\t\r\n\t~RedBlackTree() {\r\n\t\tclear();\r\n\t}\r\n\t\r\n\tRedBlackTree\
    \ & operator =(const RedBlackTree & rhs) {\r\n\t\tif (this != &rhs) {\r\n\t\t\t\
    clear();\r\n\t\t\tauto dfs = [](auto self, const_ptr q, node_ptr r) -> node_ptr\
    \ {\r\n\t\t\t\tif (!q) return nullptr;\r\n\t\t\t\tnode_ptr res = new Node(q->val,\
    \ q->isred, r, q->isr);\r\n\t\t\t\tfor (int i = 0; i < 2; ++i) res->child[i] =\
    \ self(self, q->child[i], res);\r\n\t\t\t\treturn res;\r\n\t\t\t};\r\n\t\t\troot\
    \ = dfs(dfs, rhs.root, nullptr);\r\n\t\t\tn = rhs.n;\r\n\t\t\te_ptr[0] = e_ptr[1]\
    \ = root;\r\n\t\t\tif (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i])\
    \ e_ptr[i] = e_ptr[i]->child[i];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\t\r\n\
    \tRedBlackTree & operator =(RedBlackTree && rhs) {\r\n\t\tif (this != &rhs) {\r\
    \n\t\t\tclear();\r\n\t\t\tn = rhs.n;\r\n\t\t\trhs.n = 0;\r\n\t\t\troot = rhs.root;\r\
    \n\t\t\trhs.root = nullptr;\r\n\t\t\tstd::copy(rhs.e_ptr, rhs.e_ptr + 2, e_ptr);\r\
    \n\t\t\tstd::fill(rhs.e_ptr, rhs.e_ptr + 2, nullptr);\r\n\t\t}\r\n\t\treturn *this;\r\
    \n\t}\r\n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn size() == 0;\r\n\t\
    }\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\
    \n\tvoid clear() {\r\n\t\tif (!root) return;\r\n\t\tstd::stack<node_ptr> stk;\r\
    \n\t\tstk.emplace(root);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node\
    \ = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (node->child[0]) stk.emplace(node->child[0]);\r\
    \n\t\t\tif (node->child[1]) stk.emplace(node->child[1]);\r\n\t\t\tdelete node;\r\
    \n\t\t}\r\n\t\tn = 0;\r\n\t\troot = nullptr;\r\n\t\tstd::fill(e_ptr, e_ptr + 2,\
    \ nullptr);\r\n\t}\r\n\t\r\n\tstd::vector<value_type> enumerate() const {\r\n\t\
    \tstd::vector<value_type> elements;\r\n\t\telements.reserve(size());\r\n\t\tauto\
    \ dfs = [&elements](auto self, const_ptr q) -> void {\r\n\t\t\tif (!q) return;\r\
    \n\t\t\tself(self, q->child[0]);\r\n\t\t\telements.emplace_back(q->val);\r\n\t\
    \t\tself(self, q->child[1]);\r\n\t\t};\r\n\t\tdfs(dfs, root);\r\n\t\treturn elements;\r\
    \n\t}\r\n\t\r\n\tnode_ptr begin() const noexcept {\r\n\t\treturn e_ptr[0];\r\n\
    \t}\r\n\t\r\n\tnode_ptr end() const noexcept {\r\n\t\treturn nullptr;\r\n\t}\r\
    \n\t\r\n\tnode_ptr insert(const_reference x) {\r\n\t\tnode_ptr p = nullptr, node\
    \ = root;\r\n\t\tbool ef[2] {}, d = false;\r\n\t\twhile (node) {\r\n\t\t\td =\
    \ node->val <= x;\r\n\t\t\tp = node;\r\n\t\t\tnode = node->child[d];\r\n\t\t\t\
    ef[!d] = true;\r\n\t\t}\r\n\t\tnode = new Node{x, true, p, d};\r\n\t\t++n;\r\n\
    \t\tif (!ef[0]) e_ptr[0] = node;\r\n\t\tif (!ef[1]) e_ptr[1] = node;\r\n\t\tif\
    \ (!p) {\r\n\t\t\troot = node;\r\n\t\t\tnode->isred = false;\r\n\t\t\treturn node;\r\
    \n\t\t}\r\n\t\tp->child[d] = node;\r\n\t\tif (!p->isred) return node;\r\n\t\t\
    node_ptr g = p->par, u = g->child[!p->isr];\r\n\t\tif (!u) {\r\n\t\t\tif (node->isr\
    \ == p->isr) {\r\n\t\t\t\trotate(g, !p->isr);\r\n\t\t\t\tp->isred = false;\r\n\
    \t\t\t\tg->isred = true;\r\n\t\t\t\treturn node;\r\n\t\t\t}\r\n\t\t\telse {\r\n\
    \t\t\t\tp->child[node->isr] = nullptr;\r\n\t\t\t\tg->child[!p->isr] = node;\r\n\
    \t\t\t\tnode->par = g;\r\n\t\t\t\tstd::swap(g->val, node->val);\r\n\t\t\t\tif\
    \ (e_ptr[0] == g) e_ptr[0] = node;\r\n\t\t\t\tif (e_ptr[1] == g) e_ptr[1] = node;\r\
    \n\t\t\t\treturn g;\r\n\t\t\t}\r\n\t\t}\r\n\t\twhile (u->isred) {\r\n\t\t\tg->isred\
    \ = true;\r\n\t\t\tp->isred = false;\r\n\t\t\tu->isred = false;\r\n\t\t\tconst\
    \ node_ptr cur = g;\r\n\t\t\tp = cur->par;\r\n\t\t\tif (!p) { cur->isred = false;\
    \ break; }\r\n\t\t\tif (!p->isred) break;\r\n\t\t\tg = p->par;\r\n\t\t\tu = g->child[!p->isr];\r\
    \n\t\t\tif (!u->isred) {\r\n\t\t\t\tif (cur->isr == p->isr) {\r\n\t\t\t\t\trotate(g,\
    \ !p->isr);\r\n\t\t\t\t\tp->isred = false;\r\n\t\t\t\t\tg->isred = true;\r\n\t\
    \t\t\t}\r\n\t\t\t\telse {\r\n\t\t\t\t\trotate(p, p->isr);\r\n\t\t\t\t\trotate(g,\
    \ !p->isr);\r\n\t\t\t\t\tcur->isred = false;\r\n\t\t\t\t\tg->isred = true;\r\n\
    \t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn node;\r\n\t}\r\n\t\r\n\tnode_ptr erase(const_reference\
    \ x) noexcept {\r\n\t\tnode_ptr q = find(x);\r\n\t\tif (q == end()) return end();\r\
    \n\t\treturn erase(q);\r\n\t}\r\n\t\r\n\tnode_ptr erase(node_ptr q) noexcept {\r\
    \n\t\tif (!q) return end();\r\n\t\tnode_ptr ret = next(q);\r\n\t\tif (q->child[0])\
    \ {\r\n\t\t\tnode_ptr p = q->child[0];\r\n\t\t\twhile (p->child[1]) p = p->child[1];\r\
    \n\t\t\tq->val = std::move(p->val);\r\n\t\t\tq = p;\r\n\t\t}\r\n\t\tif (e_ptr[0]\
    \ == q) e_ptr[0] = next(q);\r\n\t\tif (e_ptr[1] == q) e_ptr[1] = prev(q);\r\n\t\
    \tnode_ptr ch = q->child[0] ? q->child[0] : q->child[1];\r\n\t\tif (ch) {\r\n\t\
    \t\tq->val = std::move(ch->val);\r\n\t\t\tif (e_ptr[0] == ch) e_ptr[0] = q;\r\n\
    \t\t\tif (e_ptr[1] == ch) e_ptr[1] = q;\r\n\t\t\tif (ret == ch) ret = q;\r\n\t\
    \t\tq = ch;\r\n\t\t}\r\n\t\tnode_ptr p = q->par;\r\n\t\tbool isred = q->isred,\
    \ isr = q->isr;\r\n\t\t(p ? p->child[q->isr] : root) = nullptr;\r\n\t\tdelete\
    \ q;\r\n\t\t--n;\r\n\t\tif (!root || isred) return ret;\r\n\t\twhile (p) {\r\n\
    \t\t\tnode_ptr c = p->child[!isr];\r\n\t\t\tif (c->isred) {\r\n\t\t\t\trotate(p,\
    \ isr);\r\n\t\t\t\tc->isred = false;\r\n\t\t\t\tp->isred = true;\r\n\t\t\t\tc\
    \ = p->child[!isr];\r\n\t\t\t}\r\n\t\t\tnode_ptr g = c->child[!isr];\r\n\t\t\t\
    if (g && g->isred) {\r\n\t\t\t\trotate(p, isr);\r\n\t\t\t\tc->isred = p->isred;\r\
    \n\t\t\t\tg->isred = false;\r\n\t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\
    \t\t\t}\r\n\t\t\tg = c->child[isr];\r\n\t\t\tif (g && g->isred) {\r\n\t\t\t\t\
    rotate(c, !isr);\r\n\t\t\t\trotate(p, isr);\r\n\t\t\t\tg->isred = p->isred;\r\n\
    \t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tc->isred = true;\r\
    \n\t\t\tif (p->isred) {\r\n\t\t\t\tp->isred = false;\r\n\t\t\t\tbreak;\r\n\t\t\
    \t}\r\n\t\t\tisr = p->isr;\r\n\t\t\tp = p->par;\r\n\t\t}\r\n\t\tif (root) root->isred\
    \ = false;\r\n\t\treturn ret;\r\n\t}\r\n\t\r\n\tnode_ptr find(const_reference\
    \ x) const noexcept {\r\n\t\tconst node_ptr q = lower_bound(x);\r\n\t\tif (q !=\
    \ end() && q->val != x) return end();\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\tnode_ptr\
    \ lower_bound(const_reference x) const noexcept {\r\n\t\tnode_ptr q = root;\r\n\
    \t\tif (!q) return end();\r\n\t\twhile (q->child[q->val < x]) q = q->child[q->val\
    \ < x];\r\n\t\tif (q->val < x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\t\
    node_ptr upper_bound(const_reference x) const noexcept {\r\n\t\tnode_ptr q = root;\r\
    \n\t\tif (!q) return end();\r\n\t\twhile (q->child[q->val <= x]) q = q->child[q->val\
    \ <= x];\r\n\t\tif (q->val <= x) q = next(q);\r\n\t\treturn q;\r\n\t}\r\n\t\r\n\
    \tnode_ptr next(node_ptr q) const noexcept {\r\n\t\treturn move(q, true);\r\n\t\
    }\r\n\t\r\n\tnode_ptr prev(node_ptr q) const noexcept {\r\n\t\treturn move(q,\
    \ false);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid rotate(node_ptr q, bool d) noexcept\
    \ {\r\n\t\tnode_ptr r = q->par, p = q->child[!d], b = p->child[d];\r\n\t\t(r ?\
    \ r->child[q->isr] : root) = p;\r\n\t\tq->child[!d] = b;\r\n\t\tp->child[d] =\
    \ q;\r\n\t\tif (b) {\r\n\t\t\tb->par = q;\r\n\t\t\tb->isr = !d;\r\n\t\t}\r\n\t\
    \tp->par = r;\r\n\t\tp->isr = q->isr;\r\n\t\tq->par = p;\r\n\t\tq->isr = d;\r\n\
    \t}\r\n\t\r\n\tnode_ptr move(node_ptr q, bool d) const noexcept {\r\n\t\tif (q\
    \ == end()) return e_ptr[!d];\r\n\t\tif (q == begin() && !d) return end();\r\n\
    \t\tif (q->child[d]) for (q = q->child[d]; q->child[!d]; q = q->child[!d]);\r\n\
    \t\telse {\r\n\t\t\twhile (q && (d ^ !q->isr)) q = q->par;\r\n\t\t\tif (q) q =\
    \ q->par;\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n};\r\n\r\n#endif // INCLUDE_GUARD_RED_BLACK_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RedBlackTree.hpp
  requiredBy: []
  timestamp: '2021-03-13 13:17:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/RedBlackTree.test.cpp
  - Test/RedBlackTree.lower.upper.test.cpp
documentation_of: DataStructure/RedBlackTree.hpp
layout: document
title: "\u8D64\u9ED2\u6728 (\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728)"
---

# 概要

順序付き集合を扱う赤黒木です。
要素数 $N$ に対し、基本的な操作を $\Theta(\log{N})$ で行うことができます。  
[AVL 木](https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp) と比べると `insert` 、`erase` は速く、検索クエリは遅いです。  
速度はそこまで変わらないので、より機能が多い [AVL 木](https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp) を使用した方が良いです。  

- `RedBlackTree()`
	- $\Theta(1)$ 空の赤黒木を作成
- `RedBlackTree(const RedBlackTree & rhs)`
	- $\Theta(\|$`rhs`$\|)$ `rhs` をコピー
- `RedBlackTree(RedBlackTree && rhs)`
	- $\Theta(1)$ `rhs` をムーブ
- `bool empty()`
	- $\Theta(1)$ 赤黒木が空であるか判定
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

### RedBlackTree()

空の赤黒木を作成します。  

**計算量**

- $\Theta(1)$

---

### RedBlackTree(const RedBlackTree & rhs)

`rhs` をコピーします。  

**計算量**

- $\Theta(N + \|$`rhs`$\|)$

---

### RedBlackTree(RedBlackTree && rhs)

`rhs` をムーブします。
ムーブ後の `rhs` は空の赤黒木となります。  

**計算量**

- $\Theta(N)$

---

<br>

# メンバ関数

すべての要素は値の昇順に、同じ値同士は追加した順に順序付けされているとします。  

---

### bool empty()

赤黒木が空であるか判定します。
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
#include "DataStructure/RedBlackTree.hpp"
using namespace std;

int main() {
	RedBlackTree<int> rbt;
	cout << "size = " << rbt.size() << endl; // 0
	
	for (int i : {1, 2, 2, 3, 4, 5, 6, 6, 6, 7}) rbt.insert(i);
	cout << "size = " << rbt.size() << endl; // 10
	
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 2 3 4 5 6 6 6 7
	cout << "min = " << rbt.begin()->val << endl; // 1
	cout << "max = " << rbt.prev(rbt.end())->val << endl; // 7
	
	auto it = rbt.find(2);
	cout << "find(2) : " << it->val << endl; // 2
	cout << "next : " << rbt.next(it)->val << endl; // 2
	cout << "prev : " << rbt.prev(it)->val << endl; // 1
	
	rbt.erase(it);
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 6 7
	rbt.erase(6);
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	
	cout << "lower_bound(-1) = " << rbt.lower_bound(-1)->val << endl; // 1
	cout << "upper_bound(6) = " << rbt.upper_bound(6)->val << endl; // 7
	cout << "upper_bound(7) == end() : " << boolalpha << (rbt.upper_bound(7) == rbt.end()) << endl; // true
	
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		RedBlackTree<int> rbt2 = rbt;
		for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	{
		RedBlackTree<int> rbt2 = std::move(rbt);
		for (int i : rbt2.enumerate()) cout << i << " "; cout << '\n'; // 1 2 3 4 5 6 6 7
	}
	for (int i : rbt.enumerate()) cout << i << " "; cout << '\n'; // empty
	cout << "empty = " << boolalpha << rbt.empty() << endl; // true
}
```

<br>

# 参考

2020/08/27: [https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8](https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8)  
2020/08/27: [http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html](http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html)  
2020/08/27: [http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html](http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html)  

<br>