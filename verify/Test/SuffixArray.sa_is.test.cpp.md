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


# :heavy_check_mark: Test/SuffixArray.sa_is.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SuffixArray.sa_is.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 10:02:39+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/SuffixArray.hpp.html">String/SuffixArray.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "String/SuffixArray.hpp"

#include <string>
#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	std::string S;
	std::cin >> S;
	
	auto sa = SuffixArray::sa_is(S);
	for (int i = 1; i <= S.size(); ++i) std::cout << sa[i] << " \n"[i == S.size()];
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SuffixArray.sa_is.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#line 1 "String/SuffixArray.hpp"



#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

/*
last-updated: 2020/08/25

# 概要
SuffixArray の計算は SA-IS: Θ(|s|)
LCP 配列の計算は Kasai&s's algorighm: Θ(|s|)
文字列 p の検索は LCP 配列を用いた二分探索: Θ(|p| + log|s|)

# 仕様
SuffixArray(string_type s) :
	build(s)

size_type size() const noexcept :
	時間計算量: Θ(1)
	文字列 s の大きさ |s| を返す

const std::vector<size_type> & get_sa() const noexcept :
const std::vector<size_type> & get_lcp() const noexcept :
	時間計算量: Θ(1)
	計算済みの sa, lcp をそれぞれ返す

void build(string_type s) :
	時間計算量: Θ(|s|)
	Suffix Array の構築 (Θ(|s|)
	Longest Common Prefix 配列の計算 (Θ(|s|))

std::pair<size_type, size_type> lower_bound(string_type p) const
	時間計算量: Θ(|p| + log|s|)
	文字列 s から辞書順で文字列 p 以上となるような最小の suffix を求める
	戻り値は (先頭位置を表す sa の index, lcp)

size_type search(string_type p) const :
	時間計算量: Θ(|p| + log|s|)
	文字列 s から文字列 p を検索し、その開始 index を返す
	複数あれば辞書順最小となる suffix の index を返す

std::vector<size_type> search_all(string_type p) const :
	時間計算量: Θ(|p| + log|s| + (p の出現数))
	文字列 s から文字列 p を検索し、出現位置を全て返す(suffix の辞書式順序)

# 解説
参考リンク先では、LCP 配列を用いた検索に lcp(s[sa[l..]], s[sa[r..]]) しか保持していない。
おそらく片方(l)のみでは s = bbbbbbbb..., p = bbbba みたいな形のときに m と p の単純比較で合計 2|s| 回程度の比較が発生しそう(O(|s| + |p| + log|s|) になる?)
そこで、lplcp = lcp(s[sa[l..]], s[sa[r..]]), rplcp = lcp(s[sa[l..]], s[sa[r..]]) の 2 つの値を保持して計算している。

lower_bound 内では、(l, r] として計算を行っていて、初期値は l = -1 である必要があるが、sa[0] は空文字列を表すので l = 0 として良い。
また、rplcp を計算する際には r は sa の添字範囲内に収まっていないといけないが、どの文字列よりも大きい文字列が最後に存在すると考えると収めなくても良い。

場合分け
	lplcp < lmlcp
		next: (m, r]
		lplcp, rplcp は変化なし
	
	lplcp > lmlcp
		next: (l, m]
		lplcp は変化なし
		rplcp は lmlcp に変化
			もともと rplcp \leq lmlcp であるはずなので rplcp は非減少
	
	rplcp < rmlcp
		next: (l, m]
		lplcp, rplcp は変化なし
	
	rplcp > rmlcp
		next: (m, r]
		lplcp は rmlcp に変化
			もともと lplcp \leq rmlcp であるはずなので lplcp は非減少
		rplcp は変化なし
	
	lplcp = lmlcp かつ rmlcp = rplcp
		m の lrlcp + 1 文字目(1-indexed) と p を比較
			mplcp = |p|
				next: (l, m]
				rplcp は mplcp (= |p|) に変化
			m[mplcp] < p[mplcp]
				next: (m, r]
				lplcp は mplcp に変化
			m[mplcp] > p[mplcp]
				next: (l, m]
				rplcp は mplcp に変化

# memo
sa[l] < sa[r] で lcp(s[sa[l]..], s[sa[r]..]) = min{lcp[sa[l]], lcp[sa[l] + 1], \ldots, lcp[sa[r] - 1]}
SparseTable を用いれば 構築: Θ(|s|log|s|), クエリ: Θ(1)

# 参考
https://qiita.com/flare/items/20439a1db54b367eea70, 2020/08/23
https://blog.shibayu36.org/entry/2017/01/06/103956, 2020/08/23
https://mametter.hatenablog.com/entry/20180130/p1, 2020/08/25
https://niuez.hatenablog.com/entry/2019/12/16/203739, 2020/08/25
*/

// #include <iostream>

struct SuffixArray {
	using size_type = std::size_t;
	using string_type = std::string;
	
	SuffixArray(string_type s) {
		build(s);
	}
	
	size_type size() const noexcept {
		return s.size();
	}
	
	const size_type & operator[](size_type i) const noexcept {
		return sa[i];
	}
	
	const size_type & at(size_type i) const {
		assert(i <= size());
		return (*this)[i];
	}
	
	const std::vector<size_type> & get_sa() const noexcept {
		return sa;
	}
	
	const std::vector<size_type> & get_lcp() const noexcept {
		return lcp;
	}
	
	void build(string_type s) {
		this->s = s;
		sa = sa_is(s);
		rank.resize(size() + 1);
		for (size_type i = 0; i <= size(); ++i) rank[sa[i]] = i;
		
		// LCP 配列の構築
		lcp.resize(size());
		lcp[0] = 0;
		size_type mtc = 0;
		// lcp[i] := lcp(s[sa[i]], s[sa[i + 1])
		for (size_type i = 0; i < size(); ++i) {
			// lcp[rank[i]] = lcp(s[i..], s[sa[rank[i] + 1])
			if (rank[i] == size()) continue;
			size_type k = sa[rank[i] + 1];
			while (i + mtc < size() && k + mtc < size() && s[i + mtc] == s[k + mtc]) ++mtc;
			lcp[rank[i]] = mtc;
			if (mtc > 0) --mtc;
		}
		
		// セグ木の初期化
		seg_n = 1;
		while (seg_n < size() + 1) seg_n <<= 1;
		seg.resize(seg_n << 1);
		for (size_type i = 0; i < size(); ++i) seg[i + seg_n] = lcp[i];
		for (size_type i = size(); i < seg_n; ++i) seg[i + seg_n] = 0;
		for (size_type i = seg_n - 1; i > 0; --i) seg[i] = std::min(seg[i << 1], seg[i << 1 | 1]);
		
		// debug 出力
		// for (size_type i = 0; i <= size(); ++i) {
		// 	std::cout << "sa[" << i << "] = " << sa[i] << "\t, s[sa[i]..] = " << s.substr(sa[i]);
		// 	if (i < size()) std::cout << "\t\t\t lcp[i] = " << lcp[i];
		// 	std::cout << std::endl;
		// }
	}
	
	template<class S>
	static std::vector<size_type> sa_is(S s, const size_type kind = 128) {
		size_type n = s.size();
		for (size_type i = 0; i < n; ++i) ++s[i];
		s.push_back(0);
		
		std::vector<bool> Stype(n + 1); // true: S-type, false: L-type
		std::vector<size_type> lms; // LMS-index
		std::vector<size_type> lms_map(n + 1, n + 1); // [i] := もし i が LMS-index なら lms 配列の index, 違えば n + 1
		std::vector<size_type> bin(kind + 2); // [i] := count_{j < i} (s[j] = j) => count(s[i] = i]) = bin[i + 1] - bin[i]
		++bin[1];
		
		Stype[n] = true;
		for (size_type i = n; i > 0; --i) {
			Stype[i - 1] = s[i - 1] == s[i] ? Stype[i] : s[i - 1] < s[i];
			++bin[s[i - 1] + 1];
		}
		for (size_type i = 1; i <= n; ++i) {
			if (!Stype[i - 1] && Stype[i]) {
				lms_map[i] = lms.size();
				lms.emplace_back(i);
			}
		}
		for (size_type i = 0; i < kind + 1; ++i) bin[i + 1] += bin[i];
		
		std::vector<size_type> sa, cnt;
		
		auto induce = [&](const std::vector<size_type> &lms) {
			sa.assign(n + 1, 0);
			
			cnt.assign(kind + 1, 0);
			for (size_type i = lms.size(); i > 0; --i) {
				const size_type idx = lms[i - 1];
				const size_type c = s[idx];
				sa[bin[c + 1] - cnt[c] - 1] = idx;
				++cnt[c];
			}
			
			cnt.assign(kind + 1, 0);
			for (size_type i = 0; i < n; ++i) {
				if (sa[i] == 0) continue;
				const size_type idx = sa[i] - 1;
				if (!Stype[idx]) {
					const size_type c = s[idx];
					sa[bin[c] + cnt[c]] = idx;
					++cnt[c];
				}
			}
			
			cnt.assign(kind + 1, 0);
			for (size_type i = n; i > 0; --i) {
				if (sa[i] == 0) continue;
				const size_type idx = sa[i] - 1;
				if (Stype[idx]) {
					const size_type c = s[idx];
					sa[bin[c + 1] - 1 - cnt[c]] = idx;
					++cnt[c];
				}
			}
		};
		
		induce(lms);
		
		if (lms.size() >= 2) {
			std::vector<size_type> lms_str(lms.size() - 1); // [i] := lms の index i が何番目(0-indexed) に小さいか("$" は無視)
			size_type pre = lms[lms_map[sa[0]]], pre_len = 1, rank = 0;
			for (size_type i = 1; i <= n; ++i) {
				const size_type lms_idx = lms_map[sa[i]]; // sa[i] が LMS なら lms の index, 違えば n + 1
				if (lms_idx == n + 1) continue;
				const size_type idx = lms[lms_map[sa[i]]];
				const size_type len = lms[lms_idx + 1] - idx + 1;
				
				// LMS-substring の s[pre..] と s[idx..] を比較
				bool issame = pre_len == len;
				if (issame) {
					for (size_type j = 0; j < len; ++j) {
						if (s[pre + j] != s[idx + j]) {
							issame = false;
							break;
						}
					}
				}
				rank += !issame;
				lms_str[lms_idx] = rank - 1;
				
				pre = idx;
				pre_len = len;
			}
			
			std::vector<size_type> new_seed(lms.size());
			new_seed[0] = sa[0];
			
			if (rank == lms_str.size()) {
				for (size_type i = 0; i < lms_str.size(); ++i) new_seed[lms_str[i] + 1] = lms[i];
			}
			else {
				std::vector<size_type> lms_sa = sa_is(lms_str, rank);
				for (size_type i = 1; i < lms_sa.size(); ++i) new_seed[i] = lms[lms_sa[i]];
			}
			
			induce(new_seed);
		}
		
		return sa;
	}
	
	std::pair<size_type, size_type> lower_bound(string_type p) const {
		size_type l = 0, r = seg_n;
		size_type lplcp = 0, rplcp = 0;
		size_type seg_idx = 1;
		
		while (r - l > 1) {
			const size_type m = (l + r) >> 1;
			const size_type lmlcp = seg[seg_idx << 1];
			const size_type rmlcp = seg[seg_idx << 1 | 1];
			// std::cout << "(l, r] = (" << l << ", " << r << "], m = " << m << " : lplcp = " << lplcp << ", rplcp = " << rplcp << ", lmlcp = " << lmlcp << ", rmlcp = " << rmlcp << std::endl;
			bool move_r;
			
			if (lplcp < lmlcp) {
				move_r = true;
			}
			else if (lplcp > lmlcp) {
				move_r = false;
				rplcp = lmlcp;
			}
			else if (rplcp < rmlcp) {
				move_r = false;
			}
			else if (rplcp > rmlcp) {
				move_r = true;
				lplcp = rmlcp;
			}
			else if (m > size()) {
				move_r = false;
			}
			else {
				size_type mplcp = lplcp;
				while (sa[m] + mplcp < size() && mplcp < p.size() && s[sa[m] + mplcp] == p[mplcp]) ++mplcp;
				
				if (mplcp == p.size() || sa[m] + mplcp < size() && s[sa[m] + mplcp] > p[mplcp]) move_r = false;
				else move_r = true;
				(move_r ? lplcp : rplcp) = mplcp;
			}
			
			seg_idx <<= 1;
			if (move_r) {
				l = m;
				seg_idx |= 1;
			}
			else r = m;
		}
		if (r > size()) r = size() + 1;
		return {r, rplcp};
	}
	
	size_type search(string_type p) const {
		const auto lb = lower_bound(p);
		return lb.second < p.size() ? size() : sa[lb.first];
	}
	
	std::vector<size_type> search_all(string_type p) const {
		const auto lb = lower_bound(p);
		if (lb.second < p.size()) return {};
		size_type idx = lb.first;
		std::vector<size_type> res;
		res.emplace_back(sa[idx++]);
		for (; idx <= size() && lcp[idx - 1] >= p.size(); ++idx) res.emplace_back(sa[idx]);
		return res;
	}
	
private:
	string_type s;
	std::vector<size_type> sa; // sa[i (<= |s|)] := i 番目に小さい suffix の先頭 index
	std::vector<size_type> rank; // [i (<= |s|)] := s[i..] が suffix の中で rank[i] 番目(0-indexed) に小さい
	std::vector<size_type> lcp; // [i (< size())] := lcp(s[sa[i]..], s[sa[i + 1]..])
	size_type seg_n;
	std::vector<size_type> seg;
};


#line 4 "Test/SuffixArray.sa_is.test.cpp"

#line 6 "Test/SuffixArray.sa_is.test.cpp"
#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	std::string S;
	std::cin >> S;
	
	auto sa = SuffixArray::sa_is(S);
	for (int i = 1; i <= S.size(); ++i) std::cout << sa[i] << " \n"[i == S.size()];
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

