---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: MatheMatics/zeta_moebius_transform.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Summer/2446?year=2012\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#include \"MatheMatics/zeta_moebius_transform.hpp\"\
    \r\n#include \"Mathematics/MathUtility.hpp\"\r\n\r\n#include <vector>\r\n#include\
    \ <iostream>\r\n#include <cmath>\r\n\r\nint main() {\r\n\tusing ll = long long;\r\
    \n\t\r\n\tint N;\r\n\tll M;\r\n\tstd::cin >> N >> M;\r\n\tstd::vector<ll> A(N);\r\
    \n\tstd::vector<int> P(N);\r\n\tfor (int i = 0; i < N; ++i) std::cin >> A[i];\r\
    \n\tfor (int i = 0; i < N; ++i) std::cin >> P[i];\r\n\t\r\n\tauto solve1 = [&]()\
    \ {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\t\r\n\t\tfor (int s = 1; s < 1 <<\
    \ N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\n\t\t\tfor (int i =\
    \ 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\t\t\t\tll g = tk::gcd<ll>(l,\
    \ A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M / A[i]) { ng = true; break; }\
    \ // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\t}\r\n\t\t\tif (ng) continue;\r\
    \n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\ttk::moebius_transform_set_lower(v);\r\
    \n\t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s)\
    \ {\r\n\t\t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\t\
    if (s >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\
    \t\t\t}\r\n\t\t\tans += std::abs(v[s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\n\t\
    };\r\n\t\r\n\tauto solve2 = [&]() {\r\n\t\tstd::vector<ll> v((1 << N));\r\n\t\t\
    for (int s = 0; s < 1 << N; ++s) {\r\n\t\t\tll l = 1;\r\n\t\t\tbool ng = false;\r\
    \n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (~s >> i & 1) continue;\r\n\
    \t\t\t\tll g = tk::gcd<ll>(l, A[i]);\r\n\t\t\t\tl /= g;\r\n\t\t\t\tif (l > M /\
    \ A[i]) { ng = true; break; } // l A[i] <= M\r\n\t\t\t\telse l *= A[i];\r\n\t\t\
    \t}\r\n\t\t\tif (ng) continue;\r\n\t\t\tv[s] = M / l;\r\n\t\t}\r\n\t\t\r\n\t\t\
    tk::moebius_transform_set_upper(v);\r\n\t\ttk::zeta_tranform_set_lower(v);\r\n\
    \t\t\r\n\t\tdouble ans = 0;\r\n\t\t\r\n\t\tfor (int s = 0; s < 1 << N; ++s) {\r\
    \n\t\t\tdouble p = 1;\r\n\t\t\tfor (int i = 0; i < N; ++i) {\r\n\t\t\t\tif (s\
    \ >> i & 1) p *= P[i] * 0.01;\r\n\t\t\t\telse p *= (100 - P[i]) * 0.01;\r\n\t\t\
    \t}\r\n\t\t\tans += (M - v[(1 << N) - 1 - s]) * p;\r\n\t\t}\r\n\t\treturn ans;\r\
    \n\t};\r\n\t\r\n\tdouble ans1 = solve1();\r\n\tdouble ans2 = solve2();\r\n\tprintf(\"\
    %.16f\\n\", (ans1 + ans2) / 2.0);\r\n\treturn 0;\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: Test/zeta_moebius_transform.set.1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/zeta_moebius_transform.set.1.test.cpp
layout: document
redirect_from:
- /verify/Test/zeta_moebius_transform.set.1.test.cpp
- /verify/Test/zeta_moebius_transform.set.1.test.cpp.html
title: Test/zeta_moebius_transform.set.1.test.cpp
---
