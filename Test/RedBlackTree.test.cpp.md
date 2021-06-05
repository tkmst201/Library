---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RedBlackTree.hpp
    title: "\u8D64\u9ED2\u6728 (\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Test/RedBlackTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\
    \r\n\r\n#line 1 \"DataStructure/RedBlackTree.hpp\"\n\n\n\r\n#include <algorithm>\r\
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
    \ q->par;\r\n\t\t}\r\n\t\treturn q;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/RedBlackTree.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#include <cassert>\r\n#line 8 \"Test/RedBlackTree.test.cpp\"\
    \n#include <set>\r\n#include <numeric>\r\n\r\nint main() {\r\n\tint Q;\r\n\tscanf(\"\
    %d\", &Q);\r\n\t\r\n\tusing ll = long long;\r\n\tusing pll = std::pair<ll, ll>;\r\
    \n\t\r\n\tRedBlackTree<pll> rbt;\r\n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\t\
    ll k, v;\r\n\t\tscanf(\"%d %lld\", &q, &k);\r\n\t\tauto it = rbt.lower_bound(pll{k,\
    \ 0});\r\n\t\t\r\n\t\tif (q == 0) {\r\n\t\t\tscanf(\"%lld\", &v);\r\n\t\t\tif\
    \ (it != rbt.end() && it->val.first == k) rbt.erase(it);\r\n\t\t\trbt.insert(pll{k,\
    \ v});\r\n\t\t}\r\n\t\telse {\r\n\t\t\tprintf(\"%lld\\n\", it == rbt.end() ||\
    \ it->val.first != k ? 0 : it->val.second);\r\n\t\t}\r\n\t}\r\n\t\r\n\t// [begin,\
    \ next] test\r\n\tauto elem = rbt.enumerate();\r\n\t{\r\n\t\tstd::vector<pll>\
    \ elem2;\r\n\t\tfor (auto it = rbt.begin(); it != rbt.end(); it = rbt.next(it))\
    \ elem2.emplace_back(it->val);\r\n\t\tassert(elem == elem2);\r\n\t}\r\n\t// [end,\
    \ prev] test\r\n\t{\r\n\t\tstd::vector<pll> elem2;\r\n\t\tfor (auto it = rbt.prev(rbt.end());\
    \ it != rbt.end(); it = rbt.prev(it)) elem2.emplace_back(it->val);\r\n\t\tstd::reverse(begin(elem2),\
    \ end(elem2));\r\n\t\tassert(elem == elem2);\r\n\t}\r\n\t\r\n\t// [lower_bound,\
    \ upper_bound] test\r\n\tfor (int i = 0; i < elem.size(); ++i) {\r\n\t\tconst\
    \ auto & e = elem[i];\r\n\t\tauto itelemup = std::upper_bound(begin(elem), end(elem),\
    \ e);\r\n\t\tassert(rbt.lower_bound(e) != rbt.end());\r\n\t\tassert(rbt.lower_bound(e)->val\
    \ == e);\r\n\t\tassert(itelemup == elem.end() ? rbt.upper_bound(e) == rbt.end()\
    \ : rbt.upper_bound(e)->val == *itelemup);\r\n\t}\r\n\t\r\n\t// [erase, size]\
    \ test\r\n\tstd::set<pll> ss;\r\n\tfor (const auto & e : elem) ss.insert(e);\r\
    \n\tstd::vector<int> ord(elem.size());\r\n\tstd::iota(begin(ord), end(ord), 0);\r\
    \n\tstd::sort(begin(ord), end(ord), [&](int i, int j) {\r\n\t\tif (elem[i].second\
    \ == elem[j].second) return elem[i].first > elem[j].first;\r\n\t\treturn elem[i].second\
    \ < elem[j].second;\r\n\t});\r\n\tassert(ss.size() == rbt.size());\r\n\tfor (int\
    \ i : ord) {\r\n\t\tauto it = rbt.erase(elem[i]);\r\n\t\tauto its = ss.find(elem[i]);\
    \ ++its;\r\n\t\tassert(its == ss.end() ? it == rbt.end() : it->val == *its);\r\
    \n\t\tss.erase(--its);\r\n\t\tassert(ss.size() == rbt.size());\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    \r\n#include \"DataStructure/RedBlackTree.hpp\"\r\n\r\n#include <cstdio>\r\n#include\
    \ <cassert>\r\n#include <algorithm>\r\n#include <set>\r\n#include <numeric>\r\n\
    \r\nint main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\n\t\r\n\tusing ll = long\
    \ long;\r\n\tusing pll = std::pair<ll, ll>;\r\n\t\r\n\tRedBlackTree<pll> rbt;\r\
    \n\t\r\n\twhile (Q--) {\r\n\t\tint q;\r\n\t\tll k, v;\r\n\t\tscanf(\"%d %lld\"\
    , &q, &k);\r\n\t\tauto it = rbt.lower_bound(pll{k, 0});\r\n\t\t\r\n\t\tif (q ==\
    \ 0) {\r\n\t\t\tscanf(\"%lld\", &v);\r\n\t\t\tif (it != rbt.end() && it->val.first\
    \ == k) rbt.erase(it);\r\n\t\t\trbt.insert(pll{k, v});\r\n\t\t}\r\n\t\telse {\r\
    \n\t\t\tprintf(\"%lld\\n\", it == rbt.end() || it->val.first != k ? 0 : it->val.second);\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\t// [begin, next] test\r\n\tauto elem = rbt.enumerate();\r\
    \n\t{\r\n\t\tstd::vector<pll> elem2;\r\n\t\tfor (auto it = rbt.begin(); it !=\
    \ rbt.end(); it = rbt.next(it)) elem2.emplace_back(it->val);\r\n\t\tassert(elem\
    \ == elem2);\r\n\t}\r\n\t// [end, prev] test\r\n\t{\r\n\t\tstd::vector<pll> elem2;\r\
    \n\t\tfor (auto it = rbt.prev(rbt.end()); it != rbt.end(); it = rbt.prev(it))\
    \ elem2.emplace_back(it->val);\r\n\t\tstd::reverse(begin(elem2), end(elem2));\r\
    \n\t\tassert(elem == elem2);\r\n\t}\r\n\t\r\n\t// [lower_bound, upper_bound] test\r\
    \n\tfor (int i = 0; i < elem.size(); ++i) {\r\n\t\tconst auto & e = elem[i];\r\
    \n\t\tauto itelemup = std::upper_bound(begin(elem), end(elem), e);\r\n\t\tassert(rbt.lower_bound(e)\
    \ != rbt.end());\r\n\t\tassert(rbt.lower_bound(e)->val == e);\r\n\t\tassert(itelemup\
    \ == elem.end() ? rbt.upper_bound(e) == rbt.end() : rbt.upper_bound(e)->val ==\
    \ *itelemup);\r\n\t}\r\n\t\r\n\t// [erase, size] test\r\n\tstd::set<pll> ss;\r\
    \n\tfor (const auto & e : elem) ss.insert(e);\r\n\tstd::vector<int> ord(elem.size());\r\
    \n\tstd::iota(begin(ord), end(ord), 0);\r\n\tstd::sort(begin(ord), end(ord), [&](int\
    \ i, int j) {\r\n\t\tif (elem[i].second == elem[j].second) return elem[i].first\
    \ > elem[j].first;\r\n\t\treturn elem[i].second < elem[j].second;\r\n\t});\r\n\
    \tassert(ss.size() == rbt.size());\r\n\tfor (int i : ord) {\r\n\t\tauto it = rbt.erase(elem[i]);\r\
    \n\t\tauto its = ss.find(elem[i]); ++its;\r\n\t\tassert(its == ss.end() ? it ==\
    \ rbt.end() : it->val == *its);\r\n\t\tss.erase(--its);\r\n\t\tassert(ss.size()\
    \ == rbt.size());\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/RedBlackTree.hpp
  isVerificationFile: true
  path: Test/RedBlackTree.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 13:17:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/RedBlackTree.test.cpp
layout: document
redirect_from:
- /verify/Test/RedBlackTree.test.cpp
- /verify/Test/RedBlackTree.test.cpp.html
title: Test/RedBlackTree.test.cpp
---
