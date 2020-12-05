---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DynamicSegmentTree.hpp
    title: DataStructure/DynamicSegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Mathematics/ModInt.hpp
    title: Mathematics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Test/DynamicSegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#line 1 \"DataStructure/DynamicSegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/24\r\n\r\n# \u6982\u8981\r\n\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728(\u975E\u53EF\u63DB\u6F14\u7B97\u5BFE\u5FDC)\r\n\r\n\u30E2\u30CE\u30A4\u30C9\
    \u3092\u6271\u3046\r\n\r\n\u6DFB\u5B57\u306E\u5927\u304D\u3055\u306E\u6700\u5927\
    \u5024\u3092 n \u3001\u4EE3\u5165\u3059\u308B\u6DFB\u5B57\u306E\u7A2E\u985E\u6570\
    \u3092 m \u3068\u3059\u308B\u3068\r\n\t\u7A7A\u9593\u8A08\u7B97\u91CF: O(n log\
    \ m)\r\n\t1 \u30AF\u30A8\u30EA\u3042\u305F\u308A \u6642\u9593\u8A08\u7B97\u91CF\
    : O(log m)\r\n\u3067\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u64CD\u4F5C\u304C\
    \u884C\u3048\u308B\r\n\r\nTODO: \u4E8C\u5206\u63A2\u7D22\u306E\u5B9F\u88C5\r\n\
    \r\n# \u89E3\u8AAC\r\n\u5FC5\u8981\u306A\u3068\u304D\u306B\u679D\u3092\u4F38\u3070\
    \u3057\u3066\u3044\u304D\u52D5\u7684\u306B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3092\u69CB\u7BC9\u3059\u308B\r\n\r\n\u8449\u306B\u306E\u307F\u914D\u5217\u306E\
    \u5024\u3092\u3001\u7BC0\u306B\u306F\u90E8\u5206\u6728\u3092 fold \u3057\u305F\
    \u5024\u3092\u6301\u305F\u305B\u3066\u3044\u308B\r\n\u8449\u306E\u5B50\u306B\u5024\
    \u3092\u8FFD\u52A0\u3059\u308B\u3068\u304D\u306F\u3001\u307E\u305A\u5B50\u306B\
    \u81EA\u8EAB\u306E\u5024\u3092\u79FB\u52D5\u3055\u305B\u308B\r\n\r\n\u6F14\u7B97\
    \u304C\u53EF\u63DB\u306A\u5834\u5408\u306F\u90E8\u5206\u6728\u306E fold \u3057\
    \u305F\u5024\u3092\u5225\u306B\u6301\u305F\u305B\u308B\u3053\u3068\u306B\u3088\
    \u308A \u7A7A\u9593\u8A08\u7B97\u91CF: O(N) \u304C\u9054\u6210\u3067\u304D\u308B\
    (\u305F\u3076\u3093\u5B9F\u88C5\u3082\u697D\u305D\u3046)\r\n\r\n# \u4ED5\u69D8\
    \r\nDynamicSegmentTree(size_type n, const_reference id_elem, const F & f)\r\n\t\
    \u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\
    \ n, \u5358\u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3067\u521D\u671F\
    \u5316\r\n\r\nvoid clear()\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\n\t\u5168\
    \u30CE\u30FC\u30C9\u3092\u89E3\u653E\u3059\u308B(= \u5168\u3066\u306E\u5024\u3092\
    \ id_elem)\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\u9593/\u7A7A\u9593\
    \ \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059(\\neq\
    \ \u5185\u90E8\u306E\u30CE\u30FC\u30C9\u6570)\r\n\r\nvoid set(size_type i, const_reference\
    \ x)\r\n\t\u6642\u9593/\u7A7A\u9593 \u8A08\u7B97\u91CF: O(log n)\r\n\ti \u756A\
    \u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u306B x \u3092\u4EE3\u5165\r\n\r\nconst_reference\
    \ get(size_type i) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\ti\
    \ \u756A\u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nvalue_type\
    \ fold(size_type l, size_type r) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log\
    \ n)\r\n\t[l, r) (0 \\leq l \\leq r \\leq n) \u3092 fold \u3057\u305F\u7D50\u679C\
    \u3092\u8FD4\u3059\r\n\tl = r \u306E\u3068\u304D\u306F id_elem \u3092\u8FD4\u3059\
    \r\n\r\nconst_reference fold_all() const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ \u0398(1)\r\n\tfold(0, n) \u306E\u7D50\u679C\u3092\u8FD4\u3059\r\n\r\nprivate:\r\
    \nstd::stack<node_ptr> find(size_type k)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\
    \ O(log n)\r\n\t\u6839\u304B\u3089 k \u756A\u76EE\u306E\u8981\u7D20\u306E\u30CE\
    \u30FC\u30C9\u306E\u7D4C\u8DEF\u3092\u8FD4\u3059(\u7AEF\u70B9\u542B\u3080)\r\n\
    \tk \u756A\u76EE\u306E\u8981\u7D20\u306E\u30CE\u30FC\u30C9\u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F k \u756A\u76EE\u306E\u8981\u7D20\u306B\u6700\u3082\
    \u8FD1\u3044\u30CE\u30FC\u30C9\u307E\u3067\u306E\u7D4C\u8DEF\r\n\r\n# \u53C2\u8003\
    \r\nhttps://kazuma8128.hatenablog.com/entry/2018/11/29/093827, 2020/09/24\r\n\
    */\r\n\r\n#include <functional>\r\n#include <cassert>\r\n#include <stack>\r\n\r\
    \ntemplate<typename T>\r\nstruct DynamicSegmentTree {\r\n\tusing value_type =\
    \ T;\r\n\tusing const_reference = const value_type &;\r\n\tusing size_type = std::size_t;\r\
    \n\tusing F = std::function<value_type(const_reference, const_reference)>;\r\n\
    \t\r\nprivate:\r\n\tstruct Node;\r\n\tusing node_ptr = Node *;\r\n\tstruct Node\
    \ {\r\n\t\tvalue_type val;\r\n\t\tsize_type pos;\r\n\t\tnode_ptr l, r;\r\n\t\t\
    Node(const_reference val, size_type pos) : val(val), pos(pos), l(nullptr), r(nullptr)\
    \ {}\r\n\t};\r\n\t\r\nprivate:\r\n\tsize_type n, n_, log_n;\r\n\tvalue_type id_elem;\r\
    \n\tF f;\r\n\tnode_ptr root;\r\n\t\r\npublic:\r\n\tDynamicSegmentTree(size_type\
    \ n, const_reference id_elem, const F & f)\r\n\t\t: n(n), id_elem(id_elem), f(f),\
    \ root(nullptr) {\r\n\t\tn_ = 1;\r\n\t\tlog_n = 0;\r\n\t\twhile (n_ < n) n_ <<=\
    \ 1, ++log_n;\r\n\t}\r\n\t\r\n\t~DynamicSegmentTree() {\r\n\t\tclear();\r\n\t\
    }\r\n\t\r\n\tvoid clear() {\r\n\t\tstd::stack<node_ptr> stk;\r\n\t\tstk.emplace(root);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tnode_ptr node = stk.top();\r\n\t\t\tstk.pop();\r\
    \n\t\t\tif (node->r) stk.emplace(node->r);\r\n\t\t\tif (node->l) stk.emplace(node->l);\r\
    \n\t\t\tdelete node;\r\n\t\t}\r\n\t\troot = nullptr;\r\n\t}\r\n\t\r\n\tsize_type\
    \ size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid set(size_type\
    \ k, const_reference x) {\r\n\t\tassert(k < size());\r\n\t\tif (!root) {\r\n\t\
    \t\troot = new Node{x, k};\r\n\t\t\treturn;\r\n\t\t}\r\n\t\t\r\n\t\tstd::stack<node_ptr>\
    \ stk = find(k);\r\n\t\tif (stk.top()->pos == k) {\r\n\t\t\tstk.top()->val = x;\r\
    \n\t\t\tstk.pop();\r\n\t\t}\r\n\t\telse if (stk.top()->l || stk.top()->r) {\r\n\
    \t\t\tconst node_ptr node = stk.top();\r\n\t\t\tif (k >> (log_n - stk.size())\
    \ & 1) node->r = new Node{x, k};\r\n\t\t\telse node->l = new Node{x, k};\r\n\t\
    \t}\r\n\t\telse {\r\n\t\t\twhile (true) {\r\n\t\t\t\tconst node_ptr node = stk.top();\r\
    \n\t\t\t\t\r\n\t\t\t\tconst bool move_r = node->pos >> (log_n - stk.size()) &\
    \ 1;\r\n\t\t\t\tconst bool to_r = k >> (log_n - stk.size()) & 1;\r\n\t\t\t\tif\
    \ (move_r) {\r\n\t\t\t\t\tnode->r = new Node{node->val, node->pos};\r\n\t\t\t\t\
    \tstk.emplace(node->r);\r\n\t\t\t\t\tif (!to_r) {\r\n\t\t\t\t\t\tnode->l = new\
    \ Node{x, k};\r\n\t\t\t\t\t\tbreak;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tnode->l = new Node{node->val, node->pos};\r\n\t\t\t\t\tstk.emplace(node->l);\r\
    \n\t\t\t\t\tif (to_r) {\r\n\t\t\t\t\t\tnode->r = new Node{x, k};\r\n\t\t\t\t\t\
    \tbreak;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tstk.pop();\r\n\t\t}\r\
    \n\t\t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst node_ptr node = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\t\r\n\t\t\tnode->val = node->l ? node->l->val : id_elem;\r\
    \n\t\t\tif (node->r) node->val = f(node->val, node->r->val);\r\n\t\t}\r\n\t}\r\
    \n\t\r\n\tconst_reference get(size_type k) const {\r\n\t\tassert(k < n);\r\n\t\
    \tif (!root) return id_elem;\r\n\t\tconst std::stack<node_ptr> hist = find(k);\r\
    \n\t\tif (hist.top()->pos == k) return hist.top()->val;\r\n\t\treturn id_elem;\r\
    \n\t}\r\n\t\r\nprivate:\r\n\tstd::stack<node_ptr> find(size_type k) const {\r\n\
    \t\tstd::stack<node_ptr> res;\r\n\t\tif (!root) return res;\r\n\t\tnode_ptr node\
    \ = root;\r\n\t\tres.emplace(node);\r\n\t\tfor (size_type i = log_n; i > 0; --i)\
    \ {\r\n\t\t\tif (k >> (i - 1) & 1) {\r\n\t\t\t\tif (!node->r) break;\r\n\t\t\t\
    \tnode = node->r;\r\n\t\t\t\tres.emplace(node);\r\n\t\t\t}\r\n\t\t\telse {\r\n\
    \t\t\t\tif (!node->l) break;\r\n\t\t\t\tnode = node->l;\r\n\t\t\t\tres.emplace(node);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\npublic:\r\n\tconst_reference\
    \ fold_all() const {\r\n\t\tif (!root) return id_elem;\r\n\t\treturn root->val;\r\
    \n\t}\r\n\t\r\n\tvalue_type fold(size_type l, size_type r) const {\r\n\t\tassert(l\
    \ <= r);\r\n\t\tassert(r <= size());\r\n\t\tif (l == r || !root) return id_elem;\r\
    \n\t\t\r\n\t\tstruct Data {\r\n\t\t\tnode_ptr node;\r\n\t\t\tsize_type l, r;\r\
    \n\t\t\tData(node_ptr node, size_type l, size_type r) : node(node), l(l), r(r)\
    \ {}\r\n\t\t};\r\n\t\t\r\n\t\tvalue_type res = id_elem;\r\n\t\tstd::stack<Data>\
    \ stk;\r\n\t\tstk.emplace(root, 0, n_);\r\n\t\t\r\n\t\twhile (!stk.empty()) {\r\
    \n\t\t\tconst Data dat = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (!dat.node->l\
    \ && !dat.node->r) {\r\n\t\t\t\tif (l <= dat.node->pos && dat.node->pos < r) res\
    \ = f(res, dat.node->val);\r\n\t\t\t}\r\n\t\t\telse if (l <= dat.l && dat.r <=\
    \ r) {\r\n\t\t\t\tres = f(res, dat.node->val);\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\
    \t\t\tconst size_type m = dat.l + ((dat.r - dat.l) >> 1);\r\n\t\t\t\tif (dat.node->r\
    \ && m < r) stk.emplace(dat.node->r, m, dat.r);\r\n\t\t\t\tif (dat.node->l &&\
    \ m > l) stk.emplace(dat.node->l, dat.l, m);\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\
    \treturn res;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"Mathematics/ModInt.hpp\"\n\n\n\r\
    \n/*\r\nlast-updated: 2020/11/20\r\n\r\n\u81EA\u52D5\u3067 mod \u3092\u53D6\u3063\
    \u3066\u304F\u308C\u308B\u4FBF\u5229\u306A\u3082\u306E\r\n\r\n# \u4ED5\u69D8\r\
    \n\u57FA\u672C\u7684\u306A\u6F14\u7B97\u306F\u3060\u3044\u305F\u3044\u5BFE\u5FDC\
    \u3057\u3066\u3044\u308B\u3002\r\n\u6A19\u6E96\u5165\u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0 std::cin, std::cout \u306B\u3082\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    \u3002\r\n\r\nconstexpr ModInt(std::int_fast64_t val = 0)\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u8CA0\u306E\u6574\u6570\u306B\u3082\u5BFE\u5FDC\u3057\
    \u305F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n\r\nconstexpr static decltype(M)\
    \ mod() noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u6CD5 M\
    \ \u3092\u8FD4\u3059\r\n\r\nconstexpr const value_type & val() noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5024\u3092 int \u3067\u8FD4\u3059\r\
    \n\r\nconstexpr ModInt pow(std::int_fast64_t n) const noexcept\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: O(log n)\r\n\t\u5236\u7D04: n < 0 \u306E\u3068\u304D\u3001\
    inv() \u306E\u5236\u7D04\u306B\u5F93\u3046\u3002\r\n\tn \u4E57\u3057\u305F\u5024\
    \u3092\u8FD4\u3059(n < 0 \u306B\u3082\u5BFE\u5FDC)\r\n\r\nconstexpr ModInt inv()\
    \ const noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log M)\r\n\t\u5236\u7D04\
    : \u5024\u3068 M \u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B(M \u304C\u7D20\u6570\u306A\u3089\u554F\u984C\u306F\u306A\u3044)\u3002\
    \r\n\t\u6CD5 M \u306E\u5143\u3067\u306E\u9006\u5143\u3092\u8FD4\u3059\r\n\r\n\
    # \u53C2\u8003\r\nhttps://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n*/\r\
    \n\r\n#line 40 \"Mathematics/ModInt.hpp\"\n#include <iostream>\r\n#include <cstdint>\r\
    \n\r\ntemplate<int M>\r\nstruct ModInt {\r\n\tstatic_assert(M > 0);\r\n\t\r\n\
    public:\r\n\tusing value_type = int;\r\n\tusing calc_type = std::int_fast64_t;\r\
    \n\t\r\nprivate:\r\n\tvalue_type val_;\r\n\t\r\npublic:\r\n\tconstexpr ModInt(calc_type\
    \ val = 0) : val_(val < 0 ? (val % M + M) % M : val % M) {}\r\n\tconstexpr const\
    \ value_type & val() const noexcept { return val_; }\r\n\tconstexpr static decltype(M)\
    \ mod() noexcept { return M; }\r\n\t\r\n\texplicit constexpr operator bool() const\
    \ noexcept { return val_; }\r\n\tconstexpr bool operator !() const noexcept {\
    \ return !static_cast<bool>(*this); }\r\n\tconstexpr ModInt operator +() const\
    \ noexcept { return ModInt(*this); }\r\n\tconstexpr ModInt operator -() const\
    \ noexcept { return ModInt(-val_); }\r\n\tconstexpr ModInt operator ++(int) noexcept\
    \ { ModInt res = *this; ++*this; return res; }\r\n\tconstexpr ModInt operator\
    \ --(int) noexcept { ModInt res = *this; --*this; return res; }\r\n\tconstexpr\
    \ ModInt & operator ++() noexcept { val_ = val_ + 1 == M ? 0 : val_ + 1; return\
    \ *this; }\r\n\tconstexpr ModInt & operator --() noexcept { val_ = val_ == 0 ?\
    \ M - 1 : val_ - 1; return *this; }\r\n\tconstexpr ModInt & operator +=(const\
    \ ModInt & rhs) noexcept { val_ += val_ < M - rhs.val_ ? rhs.val_ : rhs.val_ -\
    \ M; return *this; }\r\n\tconstexpr ModInt & operator -=(const ModInt & rhs) noexcept\
    \ { val_ += val_ >= rhs.val_ ? -rhs.val_ : M - rhs.val_; return *this; }\r\n\t\
    constexpr ModInt & operator *=(const ModInt & rhs) noexcept { val_ = static_cast<calc_type>(val_)\
    \ * rhs.val_ % M; return *this; }\r\n\tconstexpr ModInt & operator /=(const ModInt\
    \ & rhs) noexcept { return *this *= rhs.inv(); }\r\n\tfriend constexpr ModInt\
    \ operator +(const ModInt & lhs, const ModInt & rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\r\n\tfriend constexpr ModInt operator -(const ModInt & lhs, const\
    \ ModInt & rhs) noexcept { return ModInt(lhs) -= rhs; }\r\n\tfriend constexpr\
    \ ModInt operator *(const ModInt & lhs, const ModInt & rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\r\n\tfriend constexpr ModInt operator /(const ModInt &\
    \ lhs, const ModInt & rhs) noexcept { return ModInt(lhs) /= rhs; }\r\n\tfriend\
    \ constexpr bool operator ==(const ModInt & lhs, const ModInt & rhs) noexcept\
    \ { return lhs.val_ == rhs.val_; }\r\n\tfriend constexpr bool operator !=(const\
    \ ModInt & lhs, const ModInt & rhs) noexcept { return !(lhs == rhs); }\r\n\tfriend\
    \ std::ostream & operator <<(std::ostream & os, const ModInt & rhs) { return os\
    \ << rhs.val_; }\r\n\tfriend std::istream & operator >>(std::istream & is, ModInt\
    \ & rhs) { calc_type x; is >> x; rhs = ModInt(x); return is; }\r\n\t\r\n\tconstexpr\
    \ ModInt pow(calc_type n) const noexcept {\r\n\t\tModInt res = 1, x = val_;\r\n\
    \t\tif (n < 0) { x = x.inv(); n = -n; }\r\n\t\twhile (n) { if (n & 1) res *= x;\
    \ x *= x; n >>= 1; }\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tconstexpr ModInt inv()\
    \ const noexcept {\r\n\t\tvalue_type a = val_, a1 = 1, a2 = 0, b = M, b1 = 0,\
    \ b2 = 1;\r\n\t\twhile (b > 0) {\r\n\t\t\tvalue_type q = a / b, r = a % b;\r\n\
    \t\t\tvalue_type nb1 = a1 - q * b1, nb2 = a2 - q * b2;\r\n\t\t\ta = b; b = r;\r\
    \n\t\t\ta1 = b1; b1 = nb1;\r\n\t\t\ta2 = b2; b2 = nb2;\r\n\t\t}\r\n\t\tassert(a\
    \ == 1);\r\n\t\treturn a1;\r\n\t}\r\n};\r\n\r\n\n#line 5 \"Test/DynamicSegmentTree.test.cpp\"\
    \n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\"\
    , &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\n\tusing pmm = std::pair<mint,\
    \ mint>;\r\n\t\r\n\tDynamicSegmentTree<pmm> seg(N, pmm(1, 0), [](const pmm & a,\
    \ const pmm & b) -> pmm {\r\n\t\treturn {a.first * b.first, b.first * a.second\
    \ + b.second};\r\n\t});\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint a,\
    \ b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tseg.set(i, {a, b});\r\n\t}\r\n\t\r\
    \n\twhile (Q--) {\r\n\t\tint q, a, b, c;\r\n\t\tscanf(\"%d %d %d %d\", &q, &a,\
    \ &b, &c);\r\n\t\tif (q == 0) {\r\n\t\t\tseg.set(a, {b, c});\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\tpmm v = seg.fold(a, b);\r\n\t\t\tmint ans = v.first * c + v.second;\r\
    \n\t\t\tprintf(\"%d\\n\", ans.val());\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include \"DataStructure/DynamicSegmentTree.hpp\"\r\n#include \"Mathematics/ModInt.hpp\"\
    \r\n\r\n#include <cstdio>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\"\
    , &N, &Q);\r\n\t\r\n\tusing mint = ModInt<998244353>;\r\n\tusing pmm = std::pair<mint,\
    \ mint>;\r\n\t\r\n\tDynamicSegmentTree<pmm> seg(N, pmm(1, 0), [](const pmm & a,\
    \ const pmm & b) -> pmm {\r\n\t\treturn {a.first * b.first, b.first * a.second\
    \ + b.second};\r\n\t});\r\n\t\r\n\tfor (int i = 0; i < N; ++i) {\r\n\t\tint a,\
    \ b;\r\n\t\tscanf(\"%d %d\", &a, &b);\r\n\t\tseg.set(i, {a, b});\r\n\t}\r\n\t\r\
    \n\twhile (Q--) {\r\n\t\tint q, a, b, c;\r\n\t\tscanf(\"%d %d %d %d\", &q, &a,\
    \ &b, &c);\r\n\t\tif (q == 0) {\r\n\t\t\tseg.set(a, {b, c});\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\tpmm v = seg.fold(a, b);\r\n\t\t\tmint ans = v.first * c + v.second;\r\
    \n\t\t\tprintf(\"%d\\n\", ans.val());\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - DataStructure/DynamicSegmentTree.hpp
  - Mathematics/ModInt.hpp
  isVerificationFile: true
  path: Test/DynamicSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 23:55:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DynamicSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/Test/DynamicSegmentTree.test.cpp
- /verify/Test/DynamicSegmentTree.test.cpp.html
title: Test/DynamicSegmentTree.test.cpp
---
