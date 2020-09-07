---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: String/KMP.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/KMP.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_KMP_HPP
#define INCLUDE_GUARD_KMP_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

/*
last-updated: 2019/11/30

# 解説
S[i] で不一致が起こった場合、次に table[i] から比較を行う。

# 仕様
std::vector<int> build_KMP_table(const std::string &S) :
	時間計算量: Θ(|S|)
	KMP_table を構築する

std::vector<std::size_t> search_KMP(const std::string &T, const std::string &S, const std::vector<int> &table) :
	時間計算量: Θ(|T|)
	KMP テーブル(table) を用いて文字列 S から文字列 T を検索する

std::vector<int> build_period_table(const std::string &S) : --unverified--
	時間計算量: Θ(|S|)
	MP 法を利用して S[0..i-1] の最小周期を求める。

# 参考
https://snuke.hatenablog.com/entry/2014/12/01/235807, 2019/11/30
https://snuke.hatenablog.com/entry/2017/07/18/101026, 2019/11/30
https://qiita.com/itomomoti/items/5e95aeef3f17a29a41cd, 2019/11/30
*/

std::vector<int> build_KMP_table(const std::string &S) {
	std::vector<int> table(S.size() + 1);
	table[0] = -1;
	int j = -1;
	for (int i = 1; i <= S.size(); ++i) {
		while (j >= 0 && S[i - 1] != S[j]) j = table[j];
		++j;
		table[i] = i == S.size() || S[i] != S[j] ? j : table[j];
	}
	return table;
}

std::vector<std::size_t> search_KMP(const std::string &T, const std::string &S, const std::vector<int> &table) {
	std::vector<std::size_t> res;
	int i = 0, j = 0;
	while (i < T.size()) {
		while (j >= 0 && T[i] != S[j]) j = table[j];
		++i; ++j;
		if (j == S.size()) {
			res.emplace_back(i - S.size());
			j = table[S.size()];
		}
	}
	return res;
}

std::vector<int> build_period_table(const std::string &S) {
	std::vector<int> table(S.size() + 1);
	table[0] = -1;
	int j = -1;
	for (int i = 1; i <= S.size(); ++i) {
		while (j >= 0 && S[i - 1] != S[j]) j = table[j];
		++j;
		table[i] = j;
	}
	
	table[0] = 0;
	for (int i = 1; i <= S.size(); ++i) table[i] = i - table[i];
	return table;
}

int main() {
	std::string S, T;
	printf("T : "); std::cin >> T;
	printf("S : "); std::cin >> S;
	printf("|S| = %d, |T| = %d\n", S.size(), T.size());
	auto ans = search_KMP(T, S, build_KMP_table(S));
	printf("%d found\n", ans.size());
	for (int pos : ans) {
		printf("%d : ", pos);
		std::cout << T.substr(pos, S.size()) << std::endl;
	}
	auto period_table = build_period_table(S);
	for (int cur : period_table) printf("%d ", cur);
	puts("");
	
	return 0;
}

#endif // INCLUDE_GUARD_KMP_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/KMP.hpp"



#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

/*
last-updated: 2019/11/30

# 解説
S[i] で不一致が起こった場合、次に table[i] から比較を行う。

# 仕様
std::vector<int> build_KMP_table(const std::string &S) :
	時間計算量: Θ(|S|)
	KMP_table を構築する

std::vector<std::size_t> search_KMP(const std::string &T, const std::string &S, const std::vector<int> &table) :
	時間計算量: Θ(|T|)
	KMP テーブル(table) を用いて文字列 S から文字列 T を検索する

std::vector<int> build_period_table(const std::string &S) : --unverified--
	時間計算量: Θ(|S|)
	MP 法を利用して S[0..i-1] の最小周期を求める。

# 参考
https://snuke.hatenablog.com/entry/2014/12/01/235807, 2019/11/30
https://snuke.hatenablog.com/entry/2017/07/18/101026, 2019/11/30
https://qiita.com/itomomoti/items/5e95aeef3f17a29a41cd, 2019/11/30
*/

std::vector<int> build_KMP_table(const std::string &S) {
	std::vector<int> table(S.size() + 1);
	table[0] = -1;
	int j = -1;
	for (int i = 1; i <= S.size(); ++i) {
		while (j >= 0 && S[i - 1] != S[j]) j = table[j];
		++j;
		table[i] = i == S.size() || S[i] != S[j] ? j : table[j];
	}
	return table;
}

std::vector<std::size_t> search_KMP(const std::string &T, const std::string &S, const std::vector<int> &table) {
	std::vector<std::size_t> res;
	int i = 0, j = 0;
	while (i < T.size()) {
		while (j >= 0 && T[i] != S[j]) j = table[j];
		++i; ++j;
		if (j == S.size()) {
			res.emplace_back(i - S.size());
			j = table[S.size()];
		}
	}
	return res;
}

std::vector<int> build_period_table(const std::string &S) {
	std::vector<int> table(S.size() + 1);
	table[0] = -1;
	int j = -1;
	for (int i = 1; i <= S.size(); ++i) {
		while (j >= 0 && S[i - 1] != S[j]) j = table[j];
		++j;
		table[i] = j;
	}
	
	table[0] = 0;
	for (int i = 1; i <= S.size(); ++i) table[i] = i - table[i];
	return table;
}

int main() {
	std::string S, T;
	printf("T : "); std::cin >> T;
	printf("S : "); std::cin >> S;
	printf("|S| = %d, |T| = %d\n", S.size(), T.size());
	auto ans = search_KMP(T, S, build_KMP_table(S));
	printf("%d found\n", ans.size());
	for (int pos : ans) {
		printf("%d : ", pos);
		std::cout << T.substr(pos, S.size()) << std::endl;
	}
	auto period_table = build_period_table(S);
	for (int cur : period_table) printf("%d ", cur);
	puts("");
	
	return 0;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

