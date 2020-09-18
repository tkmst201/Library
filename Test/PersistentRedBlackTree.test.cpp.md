---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentRedBlackTree.hpp
    title: DataStructure/PersistentRedBlackTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Test/PersistentRedBlackTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\r\n\r\n#line 1 \"DataStructure/PersistentRedBlackTree.hpp\"\
    \n\n\n\r\n#include <cassert>\r\n#include <memory>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\n/*\r\nlast-updated: 2020/09/01\r\n\r\nmerge/split \u30D9\u30FC\
    \u30B9\u306E\u5B8C\u5168\u6C38\u7D9A\u8D64\u9ED2\u6728\r\n\r\nTODO: \u30E1\u30E2\
    \u30EA\u30D7\u30FC\u30EB\u3092\u4F7F\u7528\u3057\u3066\u9AD8\u901F\u5316(\u3067\
    \u304D\u308B\u304B\u306F\u308F\u304B\u3089\u306A\u3044)\r\n\r\n# \u4ED5\u69D8\r\
    \nPersistentRedBlackTree() :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u7A7A\
    \u306E\u6728\u3092\u4F5C\u6210\r\n\r\nPersistentRedBlackTree(const std::vector<value_type>\
    \ & v) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\n\t\u914D\u5217 v \u3067\u521D\
    \u671F\u5316\r\n\r\nPersistentRedBlackTree(size_type n, const_reference x) :\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: O(n)\r\n\tn \u500B\u306E\u5024 x \u3067\u521D\
    \u671F\u5316\r\n\r\nsize_type size() const noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\u3059\r\n\r\nbool empty() const\
    \ noexcept :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(1)\r\n\t\u6728\u304C\u7A7A\
    \u3067\u3042\u308B\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\r\n\r\nPersistentRedBlackTree\
    \ merge(const PersistentRedBlackTree & a) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(|root.rank - a.rank|)\r\n\t\u8D64\u9ED2\u6728 a \u3092 merge \u3057\u305F\u8D64\
    \u9ED2\u6728\u3092\u8FD4\u3059\r\n\r\nstd::pair<PersistentRedBlackTree, PersistentRedBlackTree>\
    \ split(size_type k) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\u5148\
    \u982D k \u500B\u306E\u8981\u7D20\u3092\u6301\u3064\u8D64\u9ED2\u6728\u3068\u305D\
    \u308C\u4EE5\u964D\u306E\u8981\u7D20\u3092\u6301\u3064\u8D64\u9ED2\u6728\u306E\
    \ 2 \u3064\u306E\u8D64\u9ED2\u6728\u306B\u5206\u5272\u3057\u3066\u8FD4\u3059\r\
    \n\r\nPersistentRedBlackTree insert(size_type k, const_reference x) :\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tk \u756A\u76EE(0 \\leq k \\leq n) \u306B\
    \u5024 x \u3092\u633F\u5165\u3057\u305F\u8D64\u9ED2\u6728\u3092\u8FD4\u3059\r\n\
    \r\nPersistentRedBlackTree erase(size_type k) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : O(log n)\r\n\tk \u756A\u76EE\u306E\u8981\u7D20(0 \\leq k < n) \u3092\u524A\u9664\
    \u3057\u305F\u8D64\u9ED2\u6728\u3092\u8FD4\u3059\r\n\r\nconst_reference get(size_type\
    \ k) :\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\tk \u756A\u76EE(9 \\\
    leq k < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\r\n\r\nbool check() const : \u8D64\
    \u9ED2\u6728\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3057\u3066\u3044\u308B\u304B\
    \u78BA\u8A8D\u3059\u308B\r\n\r\n\u2193 \u9759\u7684\u30E1\u30F3\u30D0\u95A2\u6570\
    \ ver. (\u5143\u306E\u6728\u306B\u5909\u66F4\u3092\u4E0E\u3048\u305A\u306B\u65B0\
    \u305F\u306A\u6728\u3092\u751F\u6210\u3057\u3066\u8FD4\u3059)\r\nstatic PersistentRedBlackTree\
    \ merge(const PersistentRedBlackTree & a, const PersistentRedBlackTree & b) :\r\
    \nstatic std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(const\
    \ PersistentRedBlackTree & a, size_type k) :\r\nstatic PersistentRedBlackTree\
    \ insert(const PersistentRedBlackTree & a, const_reference x, size_type k) :\r\
    \nstatic PersistentRedBlackTree erase(const PersistentRedBlackTree & a, size_type\
    \ k) :\r\nstatic const_reference get(const PersistentRedBlackTree & a, size_type\
    \ k) :\r\n\r\n# \u53C2\u8003\r\nhttps://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf,\
    \ 2020/08/30\r\nhttp://blog.mitaki28.info/1447078746296/, 2020/08/30\r\nhttp://algoogle.hadrori.jp/algorithm/rbtree_merge.html,\
    \ 2020/08/30\r\n*/\r\n\r\ntemplate<typename T>\r\nstruct PersistentRedBlackTree\
    \ {\r\npublic:\r\n\tstatic constexpr bool red = true;\r\n\tstatic constexpr bool\
    \ black = false;\r\n\tusing value_type = T;\r\n\tusing const_reference = const\
    \ value_type &;\r\n\tusing size_type = std::size_t;\r\n\t\r\n\tstruct Node;\r\n\
    \tusing node_ptr = std::shared_ptr<Node>;\r\n\t\r\n\tstruct Node {\r\n\t\tvalue_type\
    \ val;\r\n\t\tbool color;\r\n\t\tsize_type size, rank;\r\n\t\tnode_ptr left, right;\r\
    \n\t\t\r\n\t\tNode(bool color, const node_ptr & left, const node_ptr & right)\r\
    \n\t\t\t: color(color), size(left->size + right->size), rank(left->rank + (left->color\
    \ == black)),\r\n\t\t\t\tleft(left), right(right) {}\r\n\t\t\r\n\t\tNode(const_reference\
    \ val) : val(val), color(black), size(1), rank(0) {}\r\n\t};\r\n\t\r\nprivate:\r\
    \n\tstatic node_ptr create(bool color, const node_ptr & left, const node_ptr &\
    \ right) {\r\n\t\treturn std::make_shared<Node>(color, left, right);\r\n\t}\r\n\
    \t\r\n\tstatic node_ptr create(const_reference val) {\r\n\t\treturn std::make_shared<Node>(val);\r\
    \n\t}\r\n\t\r\nprivate:\r\n\tnode_ptr root = nullptr;\r\n\tPersistentRedBlackTree(const\
    \ node_ptr & root) : root(root) {}\r\n\t\r\npublic:\r\n\tPersistentRedBlackTree()\
    \ {}\r\n\tPersistentRedBlackTree(const std::vector<value_type> & v) {\r\n\t\t\
    if (!v.empty()) root = build(v);\r\n\t}\r\n\tPersistentRedBlackTree(size_type\
    \ n, const_reference x) : PersistentRedBlackTree(std::vector<value_type>(n, x))\
    \ {}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\treturn root ? root->size\
    \ : 0;\r\n\t}\r\n\t\r\n\tbool empty() const noexcept {\r\n\t\treturn size() ==\
    \ 0;\r\n\t}\r\n\t\r\n\tconst PersistentRedBlackTree & merge(const PersistentRedBlackTree\
    \ & a) {\r\n\t\troot = merge(root, a.root);\r\n\t\treturn *this;\r\n\t}\r\n\t\r\
    \n\tstd::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type\
    \ k) {\r\n\t\tassert(k <= size());\r\n\t\treturn split(*this, k);\r\n\t}\r\n\t\
    \r\n\tconst PersistentRedBlackTree & insert(size_type k, const_reference x) {\r\
    \n\t\tassert(k <= size());\r\n\t\troot = insert(root, k, x);\r\n\t\treturn *this;\r\
    \n\t}\r\n\t\r\n\tconst PersistentRedBlackTree & erase(size_type k) {\r\n\t\tassert(k\
    \ < size());\r\n\t\troot = erase(root, k);\r\n\t\treturn *this;\r\n\t}\r\n\t\r\
    \n\tconst_reference get(size_type k) {\r\n\t\tassert(k < size());\r\n\t\treturn\
    \ get(root, k);\r\n\t}\r\n\t\r\npublic:\r\n\tstatic PersistentRedBlackTree merge(const\
    \ PersistentRedBlackTree & a, const PersistentRedBlackTree & b) {\r\n\t\treturn\
    \ merge(a.root, b.root);\r\n\t}\r\n\t\r\n\tstatic std::pair<PersistentRedBlackTree,\
    \ PersistentRedBlackTree> split(const PersistentRedBlackTree & a, size_type k)\
    \ {\r\n\t\tassert(a.size() <= k);\r\n\t\tconst auto sp = split(a.root, k);\r\n\
    \t\treturn {PersistentRedBlackTree{sp.first}, PersistentRedBlackTree{sp.second}};\r\
    \n\t}\r\n\t\r\n\tstatic PersistentRedBlackTree insert(const PersistentRedBlackTree\
    \ & a, size_type k, const_reference x) {\r\n\t\tassert(k <= a.size());\r\n\t\t\
    return insert(a.root, k, x);\r\n\t}\r\n\t\r\n\tstatic PersistentRedBlackTree erase(const\
    \ PersistentRedBlackTree & a, size_type k) {\r\n\t\tassert(k < a.size());\r\n\t\
    \treturn erase(a.root, k);\r\n\t}\r\n\t\r\n\tstatic const_reference get(const\
    \ PersistentRedBlackTree & a, size_type k) {\r\n\t\tassert(k < a.size());\r\n\t\
    \treturn get(a.root, k);\r\n\t}\r\n\t\r\nprivate:\r\n\ttemplate<typename U>\r\n\
    \tnode_ptr build(const std::vector<U> & v) const {\r\n\t\tif (v.size() == 1) return\
    \ create(v[0]);\r\n\t\treturn merge(\r\n\t\t\tbuild(std::vector<U>(std::begin(v),\
    \ std::begin(v) + v.size() / 2)),\r\n\t\t\tbuild(std::vector<U>(std::begin(v)\
    \ + v.size() / 2, std::end(v)))\r\n\t\t);\r\n\t}\r\n\t\r\n\tstatic node_ptr as_root(const\
    \ node_ptr & a) {\r\n\t\tif (!a) return nullptr;\r\n\t\tif (a->color == red) return\
    \ create(black, a->left, a->right);\r\n\t\treturn a;\r\n\t}\r\n\t\r\n\tstatic\
    \ node_ptr merge(const node_ptr & a, const node_ptr & b) {\r\n\t\tif (!a) return\
    \ b;\r\n\t\tif (!b) return a;\r\n\t\treturn as_root(merge_sub(a, b));\r\n\t}\r\
    \n\t\r\n\tstatic node_ptr merge_sub(const node_ptr & a, const node_ptr & b) {\r\
    \n\t\tif (a->rank < b->rank) {\r\n\t\t\tnode_ptr c = merge_sub(a, b->left);\r\n\
    \t\t\tif (b->color == black && c->color == red && c->left->color == red) {\r\n\
    \t\t\t\tif (b->right->color == black) return create(black, c->left, create(red,\
    \ c->right, b->right));\r\n\t\t\t\treturn create(red, create(black, c->left, c->right),\
    \ create(black, b->right->left, b->right->right));\r\n\t\t\t}\r\n\t\t\treturn\
    \ create(b->color, c, b->right);\r\n\t\t}\r\n\t\tif (a->rank > b->rank) {\r\n\t\
    \t\tconst node_ptr c = merge_sub(a->right, b);\r\n\t\t\tif (a->color == black\
    \ && c->color == red && c->right->color == red) {\r\n\t\t\t\tif (a->left->color\
    \ == black) return create(black, create(red, a->left, c->left), c->right);\r\n\
    \t\t\t\treturn create(red, create(black, a->left->left, a->left->right), create(black,\
    \ c->left, c->right));\r\n\t\t\t}\r\n\t\t\treturn create(a->color, a->left, c);\r\
    \n\t\t}\r\n\t\treturn create(red, a, b);\r\n\t}\r\n\t\r\n\tstatic std::pair<node_ptr,\
    \ node_ptr> split(const node_ptr &a, size_type k) {\r\n\t\tif (!a) return {nullptr,\
    \ nullptr};\r\n\t\treturn split_sub(a, k);\r\n\t}\r\n\t\r\n\tstatic std::pair<node_ptr,\
    \ node_ptr> split_sub(const node_ptr & a, size_type k) {\r\n\t\tif (k == 0) return\
    \ {nullptr, as_root(a)};\r\n\t\tif (k == a->size) return {as_root(a), nullptr};\r\
    \n\t\tif (k < a->left->size) {\r\n\t\t\tconst auto sp = split_sub(a->left, k);\r\
    \n\t\t\treturn {as_root(sp.first), merge(sp.second, as_root(a->right))};\r\n\t\
    \t}\r\n\t\tif (k > a->left->size) {\r\n\t\t\tconst auto sp = split_sub(a->right,\
    \ k - a->left->size);\r\n\t\t\treturn {merge(as_root(a->left), sp.first), as_root(sp.second)};\r\
    \n\t\t}\r\n\t\treturn {as_root(a->left), as_root(a->right)};\r\n\t}\r\n\t\r\n\t\
    static node_ptr insert(const node_ptr & a, size_type k, const_reference x) {\r\
    \n\t\tif (!a) return create(x);\r\n\t\tconst auto sp = split(a, k);\r\n\t\treturn\
    \ merge(sp.first, merge(create(x), sp.second));\r\n\t}\r\n\t\r\n\tstatic node_ptr\
    \ erase(const node_ptr & a, size_type k) {\r\n\t\tconst auto sp = split(a, k +\
    \ 1);\r\n\t\treturn merge(split(sp.first, k).first, sp.second);\r\n\t}\r\n\t\r\
    \n\tstatic const_reference get(node_ptr a, size_type k) {\r\n\t\twhile (a->left)\
    \ {\r\n\t\t\tif (k < a->left->size) a = a->left;\r\n\t\t\telse {\r\n\t\t\t\tk\
    \ -= a->left->size;\r\n\t\t\t\ta = a->right;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ a->val;\r\n\t}\r\n};\r\n\r\n\n#line 4 \"Test/PersistentRedBlackTree.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 7 \"Test/PersistentRedBlackTree.test.cpp\"\n\
    #include <algorithm>\r\n\r\nint main() {\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\
    \n\t\r\n\tusing ll = long long;\r\n\t\r\n\tstd::vector<int> q(Q);\r\n\tstd::vector<ll>\
    \ k(Q), v(Q);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tscanf(\"%d %lld\"\
    , &q[i], &k[i]);\r\n\t\tif (q[i] == 0) scanf(\"%lld\", &v[i]);\r\n\t}\r\n\t\r\n\
    \tauto compress = [](auto &&v, auto &&cv) -> void {\r\n\t\tfor (auto &&u : v)\
    \ cv.emplace_back(u);\r\n\t\tstd::sort(std::begin(cv), std::end(cv));\r\n\t\t\
    cv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\n\t\tfor\
    \ (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u) - std::begin(cv);\r\
    \n\t};\r\n\t\r\n\tstd::vector<ll> cv;\r\n\tcompress(k, cv);\r\n\tPersistentRedBlackTree<ll>\
    \ tree(cv.size(), 0);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tif (q[i]\
    \ == 0) {\r\n\t\t\ttree.erase(k[i]);\r\n\t\t\ttree.insert(k[i], v[i]);\r\n\t\t\
    }\r\n\t\telse {\r\n\t\t\tprintf(\"%lld\\n\", tree.get(k[i]));\r\n\t\t}\r\n\t}\r\
    \n\t\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    \r\n#include \"DataStructure/PersistentRedBlackTree.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n#include <algorithm>\r\n\r\nint main() {\r\n\tint Q;\r\n\
    \tscanf(\"%d\", &Q);\r\n\t\r\n\tusing ll = long long;\r\n\t\r\n\tstd::vector<int>\
    \ q(Q);\r\n\tstd::vector<ll> k(Q), v(Q);\r\n\t\r\n\tfor (int i = 0; i < Q; ++i)\
    \ {\r\n\t\tscanf(\"%d %lld\", &q[i], &k[i]);\r\n\t\tif (q[i] == 0) scanf(\"%lld\"\
    , &v[i]);\r\n\t}\r\n\t\r\n\tauto compress = [](auto &&v, auto &&cv) -> void {\r\
    \n\t\tfor (auto &&u : v) cv.emplace_back(u);\r\n\t\tstd::sort(std::begin(cv),\
    \ std::end(cv));\r\n\t\tcv.erase(std::unique(std::begin(cv), std::end(cv)), std::end(cv));\r\
    \n\t\tfor (auto &&u : v) u = std::lower_bound(std::begin(cv), std::end(cv), u)\
    \ - std::begin(cv);\r\n\t};\r\n\t\r\n\tstd::vector<ll> cv;\r\n\tcompress(k, cv);\r\
    \n\tPersistentRedBlackTree<ll> tree(cv.size(), 0);\r\n\t\r\n\tfor (int i = 0;\
    \ i < Q; ++i) {\r\n\t\tif (q[i] == 0) {\r\n\t\t\ttree.erase(k[i]);\r\n\t\t\ttree.insert(k[i],\
    \ v[i]);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tprintf(\"%lld\\n\", tree.get(k[i]));\r\
    \n\t\t}\r\n\t}\r\n\t\r\n\treturn 0;\r\n}"
  dependsOn:
  - DataStructure/PersistentRedBlackTree.hpp
  isVerificationFile: true
  path: Test/PersistentRedBlackTree.test.cpp
  requiredBy: []
  timestamp: '2020-09-07 16:22:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PersistentRedBlackTree.test.cpp
layout: document
redirect_from:
- /verify/Test/PersistentRedBlackTree.test.cpp
- /verify/Test/PersistentRedBlackTree.test.cpp.html
title: Test/PersistentRedBlackTree.test.cpp
---
