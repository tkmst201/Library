---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/AVL_Tree.hpp
    title: "AVL \u6728 (\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Test/AVL_Tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \r\n\r\n#line 1 \"DataStructure/AVL_Tree.hpp\"\n\n\n\r\n#include <algorithm>\r\
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
    };\r\n\r\n\n#line 4 \"Test/AVL_Tree.test.cpp\"\n\r\n#include <cstdio>\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <cassert>\r\n#line 10 \"Test/AVL_Tree.test.cpp\"\
    \n#include <set>\r\n#include <numeric>\r\n#line 13 \"Test/AVL_Tree.test.cpp\"\n\
    \r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::string\
    \ T;\r\n\tstd::cin >> T;\r\n\tAVL_Tree<int> avl;\r\n\tfor (int i = 0; i < T.size();\
    \ ++i) if (T[i] == '1') avl.insert(i);\r\n\t\r\n\twhile (Q--) {\r\n\t\tint c,\
    \ k;\r\n\t\tscanf(\"%d %d\", &c, &k);\r\n\t\tif (c <= 1) {\r\n\t\t\tauto it =\
    \ avl.find(k);\r\n\t\t\tif (c == 0 && it == avl.end()) avl.insert(k);\r\n\t\t\t\
    else if (c == 1 && it != avl.end()) avl.erase(it);\r\n\t\t}\r\n\t\telse if (c\
    \ == 2) {\r\n\t\t\tassert(avl.count(k) == (avl.find(k) != avl.end()));\r\n\t\t\
    \tprintf(\"%d\\n\", avl.find(k) != avl.end());\r\n\t\t}\r\n\t\telse if (c == 3)\
    \ {\r\n\t\t\tauto it = avl.lower_bound(k);\r\n\t\t\tint ans1 = it == avl.end()\
    \ ? -1 : it->val;\r\n\t\t\t\r\n\t\t\t\r\n\t\t\tauto cnt = avl.count_greater_equal(k);\r\
    \n\t\t\tint ans2 = cnt == 0 ? -1 : avl.k_th_largest(cnt)->val;\r\n\t\t\t\r\n\t\
    \t\tassert(ans1 == ans2);\r\n\t\t\tprintf(\"%d\\n\", ans1);\r\n\t\t}\r\n\t\telse\
    \ {\r\n\t\t\tauto it = avl.upper_bound(k);\r\n\t\t\tint ans1 = it == avl.begin()\
    \ ? -1 : avl.prev(it)->val;\r\n\t\t\t\r\n\t\t\tauto cnt = avl.count_less_equal(k);\r\
    \n\t\t\tint ans2 = cnt == 0 ? -1 : avl.k_th_smallest(cnt)->val;\r\n\t\t\t\r\n\t\
    \t\tassert(ans1 == ans2);\r\n\t\t\tprintf(\"%d\\n\", ans1);\r\n\t\t}\r\n\t}\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include \"DataStructure/AVL_Tree.hpp\"\r\n\r\n#include <cstdio>\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <cassert>\r\n#include <algorithm>\r\
    \n#include <set>\r\n#include <numeric>\r\n#include <vector>\r\n\r\nint main()\
    \ {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::string T;\r\n\
    \tstd::cin >> T;\r\n\tAVL_Tree<int> avl;\r\n\tfor (int i = 0; i < T.size(); ++i)\
    \ if (T[i] == '1') avl.insert(i);\r\n\t\r\n\twhile (Q--) {\r\n\t\tint c, k;\r\n\
    \t\tscanf(\"%d %d\", &c, &k);\r\n\t\tif (c <= 1) {\r\n\t\t\tauto it = avl.find(k);\r\
    \n\t\t\tif (c == 0 && it == avl.end()) avl.insert(k);\r\n\t\t\telse if (c == 1\
    \ && it != avl.end()) avl.erase(it);\r\n\t\t}\r\n\t\telse if (c == 2) {\r\n\t\t\
    \tassert(avl.count(k) == (avl.find(k) != avl.end()));\r\n\t\t\tprintf(\"%d\\n\"\
    , avl.find(k) != avl.end());\r\n\t\t}\r\n\t\telse if (c == 3) {\r\n\t\t\tauto\
    \ it = avl.lower_bound(k);\r\n\t\t\tint ans1 = it == avl.end() ? -1 : it->val;\r\
    \n\t\t\t\r\n\t\t\t\r\n\t\t\tauto cnt = avl.count_greater_equal(k);\r\n\t\t\tint\
    \ ans2 = cnt == 0 ? -1 : avl.k_th_largest(cnt)->val;\r\n\t\t\t\r\n\t\t\tassert(ans1\
    \ == ans2);\r\n\t\t\tprintf(\"%d\\n\", ans1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\t\
    auto it = avl.upper_bound(k);\r\n\t\t\tint ans1 = it == avl.begin() ? -1 : avl.prev(it)->val;\r\
    \n\t\t\t\r\n\t\t\tauto cnt = avl.count_less_equal(k);\r\n\t\t\tint ans2 = cnt\
    \ == 0 ? -1 : avl.k_th_smallest(cnt)->val;\r\n\t\t\t\r\n\t\t\tassert(ans1 == ans2);\r\
    \n\t\t\tprintf(\"%d\\n\", ans1);\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/AVL_Tree.hpp
  isVerificationFile: true
  path: Test/AVL_Tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-13 11:31:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AVL_Tree.test.cpp
layout: document
redirect_from:
- /verify/Test/AVL_Tree.test.cpp
- /verify/Test/AVL_Tree.test.cpp.html
title: Test/AVL_Tree.test.cpp
---
