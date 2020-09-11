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


# :heavy_check_mark: String/RollingHash.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 16:22:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/RollingHash.test.cpp.html">Test/RollingHash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_ROLLING_HASH_HPP
#define INCLUDE_GUARD_ROLLING_HASH_HPP

#include <vector>
#include <string>
#include <random>
#include <functional>
#include <cassert>

/*
last-updated: 2020/08/22

Rolling Hash
mod 2^61 - 1
実行時に基数(原始根)をランダム生成

TODO: basep もクラス共通にする(デストラクタ実装？)

# 仕様
RollingHash(string_type s) :
	build(s)
	基数が未生成なら set_base() で生成

size_type size() const noexcept :
	時間計算量: Θ(1)
	ハッシュを計算した文字列のサイズを返す

void build(string_type s) :
	時間計算量: Θ(|s|)
	文字列 s のすべての位置 i について s[0, i) のハッシュ値を計算する

uint64 hash(size_type i, size_type l, size_type r) const :
	時間計算量: Θ(1)
	i 番目の基数で計算した s[l, r) のハッシュ値を返す

std::vector<uint64> hash(size_type l, size_type r) const :
	時間計算帳: Θ(|base|)
	それぞれの基数で計算した s[l, r) のハッシュ値の配列を返す

bool match(size_type l1, size_type r1, size_type l2, size_type r2) const :
	時間計算量: Θ(|base|)
	s[l1, r1) と s[l2, r2) のハッシュ値を比較して一致すれば true を返す

private:
static void set_base() :
	時間計算量: ??(軽そう)
	基数をセットする
	gen_cnt の数だけ基数をランダム生成

# 参考
https://qiita.com/keymoon/items/11fac5627672a6d6a9f6#fnref1, 2020/08/22
https://trap.jp/post/1036/, 2020/08/22
*/

struct RollingHash {
public:
	using size_type = std::size_t;
	using string_type = std::string;
	using uint64 = std::uint64_t;
	
private:
	static constexpr uint64 mod = (1ull << 61) - 1;
	static constexpr uint64 mask31 = (1ull << 31) - 1;
	static constexpr uint64 mask30 = (1ull << 30) - 1;
	static constexpr uint64 mask61 = (1ull << 61) - 1;
	
public:
	RollingHash(string_type s) {
		if (base().empty()) set_base();
		build(s);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void build(string_type s) {
		n = s.size();
		hashv.clear();
		basep.clear();
		for (size_type i = 0; i < base().size(); ++i) {
			hashv.emplace_back();
			basep.emplace_back();
			hashv[i].emplace_back(0);
			basep[i].emplace_back(1);
			for (size_type j = 0; j < size(); ++j) {
				uint64 nh = mul(hashv[i].back(), base()[i]) + static_cast<uint64>(s[j]);
				hashv[i].emplace_back(modulo(nh));
				basep[i].emplace_back(modulo(mul(basep[i].back(), base()[i])));
			}
		}
	}
	
	uint64 hash(size_type i, size_type l, size_type r) const {
		assert(i < base().size());
		assert(l < r);
		assert(r <= size());
		return modulo((mod << 2) - mul(hashv[i][l], basep[i][r - l]) + hashv[i][r]);
	}
	
	std::vector<uint64> hash(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		std::vector<uint64> res;
		for (size_type i = 0; i < base().size(); ++i) res.emplace_back(hash(i, l, r));
		return res;
	}
	
	bool match(size_type l1, size_type r1, size_type l2, size_type r2) const {
		assert(l1 < r1);
		assert(r1 <= size());
		assert(l2 < r2);
		assert(r2 <= size());
		for (size_type i = 0; i < base().size(); ++i) if (hash(i, l1, r1) != hash(i, l2, r2)) return false;
		return true;
	}
	
private:
	size_type n;
	std::vector<std::vector<uint64>> basep;
	std::vector<std::vector<uint64>> hashv; // [i][j] := hash(s[0..j-1]), use base[i]
	
	static std::vector<uint64> & base() {
		static std::vector<uint64> base_;
		return base_;
	}
	
	static void set_base() {
		base().emplace_back(100000001111);
		// base().emplace_back(100000011200);
		// base().emplace_back(100000011000);
		// base().emplace_back(100000014848);
		// base().emplace_back(100000015050);
		
		auto rnd = std::bind(std::uniform_int_distribution<uint64>(2, mod - 2), std::mt19937_64(std::random_device{}()));
		constexpr size_type gen_cnt = 1;
		for (size_type i = 0; i < gen_cnt; ++i) {
			while (true) {
				uint64 k = rnd();
				if (gcd(k, mod - 1) != 1) continue;
				uint64 cur = mod_pow(base()[0], k);
				if (cur < 10000000000) continue;
				base().emplace_back(cur);
				break;
			}
		}
	}
	
	// x, y < mod => res < (mod << 2)
	static uint64 mul(uint64 x, uint64 y) {
		const uint64 xu = x >> 31, xd = x & mask31;
		const uint64 yu = y >> 31, yd = y & mask31;
		const uint64 t = xu * yd + yu * xd;
		uint64 res = (xu * yu) << 1;
		res += (t >> 30) + ((t & mask30) << 31);
		res += xd * yd;
		return res;
	}
	
	static uint64 modulo(uint64 x) {
		const uint64 sum = (x >> 61) + (x & mask61);
		return sum < mod ? sum : sum - mod;
	}
	
	static uint64 mod_pow(uint64 x, uint64 n) {
		if (n == 0) return 1;
		uint64 res = mod_pow(modulo(mul(x, x)), n >> 1);
		if (n & 1) res = modulo(mul(res, x));
		return res;
	}
	
	static uint64 gcd(uint64 x, uint64 y) {
		while (y > 0) {
			uint64 t = y;
			y = x % y;
			x = t;
		}
		return x;
	}
};

#endif // INCLUDE_GUARD_ROLLING_HASH_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/RollingHash.hpp"



#include <vector>
#include <string>
#include <random>
#include <functional>
#include <cassert>

/*
last-updated: 2020/08/22

Rolling Hash
mod 2^61 - 1
実行時に基数(原始根)をランダム生成

TODO: basep もクラス共通にする(デストラクタ実装？)

# 仕様
RollingHash(string_type s) :
	build(s)
	基数が未生成なら set_base() で生成

size_type size() const noexcept :
	時間計算量: Θ(1)
	ハッシュを計算した文字列のサイズを返す

void build(string_type s) :
	時間計算量: Θ(|s|)
	文字列 s のすべての位置 i について s[0, i) のハッシュ値を計算する

uint64 hash(size_type i, size_type l, size_type r) const :
	時間計算量: Θ(1)
	i 番目の基数で計算した s[l, r) のハッシュ値を返す

std::vector<uint64> hash(size_type l, size_type r) const :
	時間計算帳: Θ(|base|)
	それぞれの基数で計算した s[l, r) のハッシュ値の配列を返す

bool match(size_type l1, size_type r1, size_type l2, size_type r2) const :
	時間計算量: Θ(|base|)
	s[l1, r1) と s[l2, r2) のハッシュ値を比較して一致すれば true を返す

private:
static void set_base() :
	時間計算量: ??(軽そう)
	基数をセットする
	gen_cnt の数だけ基数をランダム生成

# 参考
https://qiita.com/keymoon/items/11fac5627672a6d6a9f6#fnref1, 2020/08/22
https://trap.jp/post/1036/, 2020/08/22
*/

struct RollingHash {
public:
	using size_type = std::size_t;
	using string_type = std::string;
	using uint64 = std::uint64_t;
	
private:
	static constexpr uint64 mod = (1ull << 61) - 1;
	static constexpr uint64 mask31 = (1ull << 31) - 1;
	static constexpr uint64 mask30 = (1ull << 30) - 1;
	static constexpr uint64 mask61 = (1ull << 61) - 1;
	
public:
	RollingHash(string_type s) {
		if (base().empty()) set_base();
		build(s);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void build(string_type s) {
		n = s.size();
		hashv.clear();
		basep.clear();
		for (size_type i = 0; i < base().size(); ++i) {
			hashv.emplace_back();
			basep.emplace_back();
			hashv[i].emplace_back(0);
			basep[i].emplace_back(1);
			for (size_type j = 0; j < size(); ++j) {
				uint64 nh = mul(hashv[i].back(), base()[i]) + static_cast<uint64>(s[j]);
				hashv[i].emplace_back(modulo(nh));
				basep[i].emplace_back(modulo(mul(basep[i].back(), base()[i])));
			}
		}
	}
	
	uint64 hash(size_type i, size_type l, size_type r) const {
		assert(i < base().size());
		assert(l < r);
		assert(r <= size());
		return modulo((mod << 2) - mul(hashv[i][l], basep[i][r - l]) + hashv[i][r]);
	}
	
	std::vector<uint64> hash(size_type l, size_type r) const {
		assert(l < r);
		assert(r <= size());
		std::vector<uint64> res;
		for (size_type i = 0; i < base().size(); ++i) res.emplace_back(hash(i, l, r));
		return res;
	}
	
	bool match(size_type l1, size_type r1, size_type l2, size_type r2) const {
		assert(l1 < r1);
		assert(r1 <= size());
		assert(l2 < r2);
		assert(r2 <= size());
		for (size_type i = 0; i < base().size(); ++i) if (hash(i, l1, r1) != hash(i, l2, r2)) return false;
		return true;
	}
	
private:
	size_type n;
	std::vector<std::vector<uint64>> basep;
	std::vector<std::vector<uint64>> hashv; // [i][j] := hash(s[0..j-1]), use base[i]
	
	static std::vector<uint64> & base() {
		static std::vector<uint64> base_;
		return base_;
	}
	
	static void set_base() {
		base().emplace_back(100000001111);
		// base().emplace_back(100000011200);
		// base().emplace_back(100000011000);
		// base().emplace_back(100000014848);
		// base().emplace_back(100000015050);
		
		auto rnd = std::bind(std::uniform_int_distribution<uint64>(2, mod - 2), std::mt19937_64(std::random_device{}()));
		constexpr size_type gen_cnt = 1;
		for (size_type i = 0; i < gen_cnt; ++i) {
			while (true) {
				uint64 k = rnd();
				if (gcd(k, mod - 1) != 1) continue;
				uint64 cur = mod_pow(base()[0], k);
				if (cur < 10000000000) continue;
				base().emplace_back(cur);
				break;
			}
		}
	}
	
	// x, y < mod => res < (mod << 2)
	static uint64 mul(uint64 x, uint64 y) {
		const uint64 xu = x >> 31, xd = x & mask31;
		const uint64 yu = y >> 31, yd = y & mask31;
		const uint64 t = xu * yd + yu * xd;
		uint64 res = (xu * yu) << 1;
		res += (t >> 30) + ((t & mask30) << 31);
		res += xd * yd;
		return res;
	}
	
	static uint64 modulo(uint64 x) {
		const uint64 sum = (x >> 61) + (x & mask61);
		return sum < mod ? sum : sum - mod;
	}
	
	static uint64 mod_pow(uint64 x, uint64 n) {
		if (n == 0) return 1;
		uint64 res = mod_pow(modulo(mul(x, x)), n >> 1);
		if (n & 1) res = modulo(mul(res, x));
		return res;
	}
	
	static uint64 gcd(uint64 x, uint64 y) {
		while (y > 0) {
			uint64 t = y;
			y = x % y;
			x = t;
		}
		return x;
	}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

