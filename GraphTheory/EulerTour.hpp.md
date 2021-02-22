---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/EulerTour.test.cpp
    title: Test/EulerTour.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://beet-aizu.hatenablog.com/entry/2019/07/08/174727,
    - https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7,
  bundledCode: "#line 1 \"GraphTheory/EulerTour.hpp\"\n\n\n\r\n/*\r\nlast-updated:\
    \ 2020/09/16\r\n\r\n\u8FBA\u306B\u756A\u53F7\u3092\u4ED8\u3051\u308B\u30BF\u30A4\
    \u30D7\u306E EulerTour\r\n\u5358\u7D14\u306A\u6728\u306E\u307F\u5BFE\u5FDC(\u81EA\
    \u5DF1\u30EB\u30FC\u30D7, \u591A\u91CD\u8FBA, \u68EE\u306B\u306F\u975E\u5BFE\u5FDC\
    )\r\n\u30B0\u30E9\u30D5\u306B\u306F\u5B64\u7ACB\u70B9\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u3068\u4EEE\u5B9A\u3059\u308B\r\n\r\n# \u89E3\u8AAC\r\n\u90E8\u5206\u6728\
    \u30AF\u30A8\u30EA\u306E\u51E6\u7406\r\n\t(i) \u9802\u70B9\u306B\u5024\u304C\u5B58\
    \u5728\u3059\u308B\u3068\u304D\r\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3001\
    in[u] \u306B\u9802\u70B9 u \u306E\u5024\u3092\u6301\u305F\u305B\u308B\u3002\r\n\
    \t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\u306F [in[u], out[u])\
    \ \u306E\u7DCF\u548C\r\n\t(ii) \u8FBA\u306B\u5024\u304C\u5B58\u5728\u3059\u308B\
    \u3068\u304D\r\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3001\u89AA p \u304B\
    \u3089\u306E\u8FBA\u306E\u5024\u3092 in[u] \u306B\u6301\u305F\u305B\u308B\u3002\
    \r\n\t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\u306F [in[u] + 1,\
    \ out[u]) \u306E\u7DCF\u548C\r\n\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u51E6\
    \u7406\r\n\t\u9802\u70B9\u306B\u5024\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\
    \u306E\u307F\u8003\u3048\u308B(\u8FBA\u3082\u540C\u69D8)\r\n\t\u5404\u9802\u70B9\
    \ u \u306B\u5BFE\u3057\u3001\r\n\t\tin[u] \u306B\u9802\u70B9 u \u306E\u5024\r\n\
    \t\tout[u] \u306B\u9802\u70B9 u \u306E\u5024\u306E\u9006\u5143\r\n\t\u3092\u3082\
    \u305F\u305B\u308B\u3002\r\n\t\u8449\u3078\u4E0B\u308B\u65B9\u5411\u306B\u3057\
    \u304B\u8A08\u7B97\u3067\u304D\u306A\u3044\u305F\u3081\u3001lca \u3092\u6C42\u3081\
    \u3066 2 \u3064\u306E\u30D1\u30B9\u306B\u5206\u3051\u3066\u8A08\u7B97\u3059\u308B\
    \u3002\r\n\t\u3053\u306E\u3068\u304D\u3001\u53EF\u63DB\u3067\u306A\u3044\u5834\
    \u5408\u306F\u30D1\u30B9\u306E\u4E0A\u308A\u4E0B\u308A\u3067\u8A08\u7B97\u306E\
    \u4ED5\u65B9\u3092\u5DE5\u592B\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \r\n\r\n# \u4ED5\u69D8\r\nEulerTour(const Tree & tree, size_type root)\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u6728 g, \u6839\u3092 root \u3068\u3057\
    \u3066 EulerTour \u3067\u756A\u53F7\u3092\u632F\u308B\r\n\t\u3053\u3053\u3067\u6E21\
    \u3057\u305F tree \u306E\u53C2\u7167\u5143\u306F\u5909\u66F4\u3057\u3066\u306F\
    \u3044\u3051\u306A\u3044\u3002\r\n\r\nsize_type size() const noexcept\r\n\t\u6642\
    \u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5272\u308A\u632F\u3063\u305F\u8FBA\u306E\
    \u756A\u53F7\u306E\u7DCF\u6570(2n) \u3092\u8FD4\u3059\r\n\r\nsize_type par(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3092\u8FD4\u3059\r\n\r\nsize_type\
    \ in(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\
    \u70B9 k \u306B\u5165\u3063\u305F\u3068\u304D\u306E\u8FBA\u756A\u53F7(EulerTour\
    \ \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\u306E\u5834\u5408\u306F 0\r\n\
    \r\nsize_type out(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u9802\u70B9 k \u304B\u3089\u51FA\u305F\u3068\u304D\u306E\u8FBA\u756A\
    \u53F7(EulerTour \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\u306E\u5834\u5408\
    \u306F 2n\r\n\r\nstd::pair<size_type, size_type> par_from(size_type k) const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k \u306E\u89AA\
    \u304B\u3089\u9802\u70B9 k \u3078\u306E\u8FBA e \u306E\u60C5\u5831 ( {\u9802\u70B9\
    \ k \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7}, {tree \u4E0A\u306E\u8FBA e \u306E\
    \ index}) \u3092\u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[par[k]][e-index]\
    \ = k\r\n\tk \u304C\u6839\u306E\u5834\u5408\u306F (n, n)\r\n\r\nsize_type par_to(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u304B\u3089\u89AA\u3078\u306E\u8FBA e \u306E tree \u4E0A\u306E index \u3092\
    \u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[k][e-index] = par[k]\r\n\tk \u304C\
    \u6839\u3082\u3057\u304F\u306F tree \u304C\u9006\u8FBA\u3092\u6301\u3063\u3066\
    \u3044\u306A\u3044\u5834\u5408\u306F n\r\n\r\n# \u53C2\u8003\r\nhttps://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7,\
    \ 2020/09/16\r\nhttps://beet-aizu.hatenablog.com/entry/2019/07/08/174727, 2020/09/16\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\n\t\
    using Tree = std::vector<std::vector<size_type>>;\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tconst Tree & tree;\r\n\tsize_type root;\r\n\tstd::vector<size_type>\
    \ in_, out_;\r\n\tstd::vector<size_type> par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const\
    \ Tree & tree, size_type root) : n(tree.size()), tree(tree), root(root) {\r\n\t\
    \tin_.assign(size(), size());\r\n\t\tout_.assign(size(), size());\r\n\t\tpar_.assign(n,\
    \ n);\r\n\t\tg_idx.assign(size(), n);\r\n\t\t\r\n\t\tstd::stack<std::pair<size_type,\
    \ size_type>> stk;\r\n\t\tstd::vector<size_type> par_edge(n, n);\r\n\t\tsize_type\
    \ num = 0;\r\n\t\t\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root, 0);\r\n\t\
    \t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst size_type u = stk.top().first;\r\
    \n\t\t\tconst size_type i = stk.top().second;\r\n\t\t\tstk.pop();\r\n\t\t\t\r\n\
    \t\t\tif (i < tree[u].size()) {\r\n\t\t\t\tconst size_type v = tree[u][i];\r\n\
    \t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (v == par_[u]) par_edge[u] = i;\r\
    \n\t\t\t\telse {\r\n\t\t\t\t\tg_idx[num] = i;\r\n\t\t\t\t\tin_[v] = num++;\r\n\
    \t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\telse out_[u] = num++;\r\n\t\t}\r\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) g_idx[out_[i]] = par_edge[i];\r\n\t}\r\n\t\r\n\tsize_type size() const\
    \ noexcept { return n << 1; }\r\n\tsize_type par(size_type k) const { assert(k\
    \ < size()); return par_[k]; }\r\n\tsize_type in(size_type k) const { assert(k\
    \ < size()); return in_[k]; }\r\n\tsize_type out(size_type k) const { assert(k\
    \ < size()); return out_[k]; }\r\n\tstd::pair<size_type, size_type> par_from(size_type\
    \ k) const { assert(k < size()); return {par_[k], g_idx[in_[k]]}; }\r\n\tsize_type\
    \ par_to(size_type k) const { assert(k < size()); return g_idx[out_[k]]; }\r\n\
    };\r\n\r\n\n"
  code: "#ifndef INCLUDE_GUARD_EULER_TOUR_HPP\r\n#define INCLUDE_GUARD_EULER_TOUR_HPP\r\
    \n\r\n/*\r\nlast-updated: 2020/09/16\r\n\r\n\u8FBA\u306B\u756A\u53F7\u3092\u4ED8\
    \u3051\u308B\u30BF\u30A4\u30D7\u306E EulerTour\r\n\u5358\u7D14\u306A\u6728\u306E\
    \u307F\u5BFE\u5FDC(\u81EA\u5DF1\u30EB\u30FC\u30D7, \u591A\u91CD\u8FBA, \u68EE\u306B\
    \u306F\u975E\u5BFE\u5FDC)\r\n\u30B0\u30E9\u30D5\u306B\u306F\u5B64\u7ACB\u70B9\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u3068\u4EEE\u5B9A\u3059\u308B\r\n\r\n# \u89E3\u8AAC\
    \r\n\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306E\u51E6\u7406\r\n\t(i) \u9802\u70B9\
    \u306B\u5024\u304C\u5B58\u5728\u3059\u308B\u3068\u304D\r\n\t\t\u5404\u9802\u70B9\
    \ u \u306B\u5BFE\u3057\u3001in[u] \u306B\u9802\u70B9 u \u306E\u5024\u3092\u6301\
    \u305F\u305B\u308B\u3002\r\n\t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\
    \u306F [in[u], out[u]) \u306E\u7DCF\u548C\r\n\t(ii) \u8FBA\u306B\u5024\u304C\u5B58\
    \u5728\u3059\u308B\u3068\u304D\r\n\t\t\u5404\u9802\u70B9 u \u306B\u5BFE\u3057\u3001\
    \u89AA p \u304B\u3089\u306E\u8FBA\u306E\u5024\u3092 in[u] \u306B\u6301\u305F\u305B\
    \u308B\u3002\r\n\t\t\u90E8\u5206\u6728 u \u306E\u5024\u306E\u7DCF\u548C\u306F\
    \ [in[u] + 1, out[u]) \u306E\u7DCF\u548C\r\n\r\n\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u306E\u51E6\u7406\r\n\t\u9802\u70B9\u306B\u5024\u304C\u5B58\u5728\u3059\u308B\
    \u3068\u304D\u306E\u307F\u8003\u3048\u308B(\u8FBA\u3082\u540C\u69D8)\r\n\t\u5404\
    \u9802\u70B9 u \u306B\u5BFE\u3057\u3001\r\n\t\tin[u] \u306B\u9802\u70B9 u \u306E\
    \u5024\r\n\t\tout[u] \u306B\u9802\u70B9 u \u306E\u5024\u306E\u9006\u5143\r\n\t\
    \u3092\u3082\u305F\u305B\u308B\u3002\r\n\t\u8449\u3078\u4E0B\u308B\u65B9\u5411\
    \u306B\u3057\u304B\u8A08\u7B97\u3067\u304D\u306A\u3044\u305F\u3081\u3001lca \u3092\
    \u6C42\u3081\u3066 2 \u3064\u306E\u30D1\u30B9\u306B\u5206\u3051\u3066\u8A08\u7B97\
    \u3059\u308B\u3002\r\n\t\u3053\u306E\u3068\u304D\u3001\u53EF\u63DB\u3067\u306A\
    \u3044\u5834\u5408\u306F\u30D1\u30B9\u306E\u4E0A\u308A\u4E0B\u308A\u3067\u8A08\
    \u7B97\u306E\u4ED5\u65B9\u3092\u5DE5\u592B\u3059\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\r\n\r\n# \u4ED5\u69D8\r\nEulerTour(const Tree & tree, size_type root)\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u6728 g, \u6839\u3092 root\
    \ \u3068\u3057\u3066 EulerTour \u3067\u756A\u53F7\u3092\u632F\u308B\r\n\t\u3053\
    \u3053\u3067\u6E21\u3057\u305F tree \u306E\u53C2\u7167\u5143\u306F\u5909\u66F4\
    \u3057\u3066\u306F\u3044\u3051\u306A\u3044\u3002\r\n\r\nsize_type size() const\
    \ noexcept\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5272\u308A\u632F\
    \u3063\u305F\u8FBA\u306E\u756A\u53F7\u306E\u7DCF\u6570(2n) \u3092\u8FD4\u3059\r\
    \n\r\nsize_type par(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (1)\r\n\t\u9802\u70B9 k \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3092\u8FD4\
    \u3059\r\n\r\nsize_type in(size_type k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\u9802\u70B9 k \u306B\u5165\u3063\u305F\u3068\u304D\u306E\u8FBA\
    \u756A\u53F7(EulerTour \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\u306E\u5834\
    \u5408\u306F 0\r\n\r\nsize_type out(size_type k) const\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k \u304B\u3089\u51FA\u305F\u3068\u304D\
    \u306E\u8FBA\u756A\u53F7(EulerTour \u9806) \u3092\u8FD4\u3059\r\n\tk \u304C\u6839\
    \u306E\u5834\u5408\u306F 2n\r\n\r\nstd::pair<size_type, size_type> par_from(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u306E\u89AA\u304B\u3089\u9802\u70B9 k \u3078\u306E\u8FBA e \u306E\u60C5\u5831\
    \ ( {\u9802\u70B9 k \u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7}, {tree \u4E0A\u306E\
    \u8FBA e \u306E index}) \u3092\u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[par[k]][e-index]\
    \ = k\r\n\tk \u304C\u6839\u306E\u5834\u5408\u306F (n, n)\r\n\r\nsize_type par_to(size_type\
    \ k) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u9802\u70B9 k\
    \ \u304B\u3089\u89AA\u3078\u306E\u8FBA e \u306E tree \u4E0A\u306E index \u3092\
    \u8FD4\u3059\r\n\t\u3064\u307E\u308A\u3001tree[k][e-index] = par[k]\r\n\tk \u304C\
    \u6839\u3082\u3057\u304F\u306F tree \u304C\u9006\u8FBA\u3092\u6301\u3063\u3066\
    \u3044\u306A\u3044\u5834\u5408\u306F n\r\n\r\n# \u53C2\u8003\r\nhttps://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7,\
    \ 2020/09/16\r\nhttps://beet-aizu.hatenablog.com/entry/2019/07/08/174727, 2020/09/16\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n#include <stack>\r\n#include\
    \ <utility>\r\n\r\nstruct EulerTour {\r\n\tusing size_type = std::size_t;\r\n\t\
    using Tree = std::vector<std::vector<size_type>>;\r\n\t\r\nprivate:\r\n\tsize_type\
    \ n;\r\n\tconst Tree & tree;\r\n\tsize_type root;\r\n\tstd::vector<size_type>\
    \ in_, out_;\r\n\tstd::vector<size_type> par_, g_idx;\r\n\t\r\npublic:\r\n\tEulerTour(const\
    \ Tree & tree, size_type root) : n(tree.size()), tree(tree), root(root) {\r\n\t\
    \tin_.assign(size(), size());\r\n\t\tout_.assign(size(), size());\r\n\t\tpar_.assign(n,\
    \ n);\r\n\t\tg_idx.assign(size(), n);\r\n\t\t\r\n\t\tstd::stack<std::pair<size_type,\
    \ size_type>> stk;\r\n\t\tstd::vector<size_type> par_edge(n, n);\r\n\t\tsize_type\
    \ num = 0;\r\n\t\t\r\n\t\tin_[root] = num++;\r\n\t\tstk.emplace(root, 0);\r\n\t\
    \t\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst size_type u = stk.top().first;\r\
    \n\t\t\tconst size_type i = stk.top().second;\r\n\t\t\tstk.pop();\r\n\t\t\t\r\n\
    \t\t\tif (i < tree[u].size()) {\r\n\t\t\t\tconst size_type v = tree[u][i];\r\n\
    \t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\tif (v == par_[u]) par_edge[u] = i;\r\
    \n\t\t\t\telse {\r\n\t\t\t\t\tg_idx[num] = i;\r\n\t\t\t\t\tin_[v] = num++;\r\n\
    \t\t\t\t\tpar_[v] = u;\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\
    }\r\n\t\t\telse out_[u] = num++;\r\n\t\t}\r\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) g_idx[out_[i]] = par_edge[i];\r\n\t}\r\n\t\r\n\tsize_type size() const\
    \ noexcept { return n << 1; }\r\n\tsize_type par(size_type k) const { assert(k\
    \ < size()); return par_[k]; }\r\n\tsize_type in(size_type k) const { assert(k\
    \ < size()); return in_[k]; }\r\n\tsize_type out(size_type k) const { assert(k\
    \ < size()); return out_[k]; }\r\n\tstd::pair<size_type, size_type> par_from(size_type\
    \ k) const { assert(k < size()); return {par_[k], g_idx[in_[k]]}; }\r\n\tsize_type\
    \ par_to(size_type k) const { assert(k < size()); return g_idx[out_[k]]; }\r\n\
    };\r\n\r\n#endif // INCLUDE_GUARD_EULER_TOUR_HPP"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/EulerTour.hpp
  requiredBy: []
  timestamp: '2020-09-17 16:57:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/EulerTour.test.cpp
documentation_of: GraphTheory/EulerTour.hpp
layout: document
redirect_from:
- /library/GraphTheory/EulerTour.hpp
- /library/GraphTheory/EulerTour.hpp.html
title: GraphTheory/EulerTour.hpp
---
