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


# :heavy_check_mark: DataStructure/SuccintBitVector.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SuccintBitVector.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 21:36:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/WaveletMatrix.next_prev_value.test.cpp.html">Test/WaveletMatrix.next_prev_value.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/WaveletMatrix.quantile.test.cpp.html">Test/WaveletMatrix.quantile.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/WaveletMatrix.range_frequency.test.cpp.html">Test/WaveletMatrix.range_frequency.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/WaveletMatrix.select.test.cpp.html">Test/WaveletMatrix.select.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP
#define INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP

#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>

/*
last-updated: 2020/09/07

使用する前に必ず build() を呼ぶ
高速化のために assert チェックを入れていないので注意

TODO: O(1) select を調べる

# 仕様
n = 2^16 ~ 10^4.8 で計算量が保証されている実装
空間計算量: n + o(n)

SuccintBitVector(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

SuccintBitVector(const std::vector<uint64> & v) :
	時間計算量: Θ(n)
	bit 配列 v で初期化

size_type size() const noexcept :
	時間計算量: O(1)
	要素数 n を返す

void set(size_type i) :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットを立てる

bool access(size_type i) const :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットの値を返す

size_type rank1(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 1 になっているビットの数を返す

size_type rank0(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 0 になっているビットの数を返す

size_type select1(size_type k) const :
	時間計算量: O(log n)
	rank1(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 1 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

size_type select0(size_type k) const :
	時間計算量: O(log n)
	rank0(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 0 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

# 参考
https://misteer.hatenablog.com/entry/bit-vector, 2020/09/03
https://miti-7.hatenablog.com/entry/2018/04/15/155638, 2020/09/03
*/

struct SuccintBitVector {
	using size_type = std::size_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
	
private:
	// optimized n = 2^16
	static constexpr size_type LARGE = 8; // bits, log^2 n
	static constexpr size_type SMALL = 3; // bits, (log n) / 2
	static constexpr size_type DAT_B = 6; // bits (2^6 = 64 bit)
	static constexpr size_type SMALL_S = 1ull << (1ull << SMALL);
	
private:
	size_type n;
	std::vector<uint64> bits;
	std::vector<uint32> large;
	std::vector<uint16> small;
	
	static const uint16 table[SMALL_S];
	
public:
	SuccintBitVector(size_type n) {
		assert(n > 0);
		n = (n + (1u << LARGE) - 1) >> LARGE << LARGE;
		this->n = n;
		bits.resize((n >> DAT_B) + 1);
	}
	
	SuccintBitVector(const std::vector<uint64> & v) {
		assert(!v.empty());
		n = ((v.size() << DAT_B) + (1u << LARGE) - 1) >> LARGE << LARGE;
		bits.resize((n >> DAT_B) + 1);
		std::copy(std::begin(v), std::end(v), std::begin(bits));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i) {
		bits[i >> DAT_B] |= 1ull << (i & ((1u << DAT_B) - 1));
	}
	
	bool access(size_type i) const {
		return bits[i >> DAT_B] >> (i & ((1u << DAT_B) - 1)) & 1;
	}
	
	size_type rank1(size_type i) const {
		return large[i >> LARGE] + small[i >> SMALL]
			+ pop_count(
				get_val(bits[i >> DAT_B], (i & ((1u << DAT_B) - 1)) >> SMALL)
					& ((1u << (i & ((1u << SMALL) - 1))) - 1) );
		// (i >> DAT_B) < bits.size() となるように +1 余分に確保
	}
	
	size_type rank0(size_type i) const {
		return i - rank1(i);
	}
	
	size_type select1(size_type k) const {
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (bits[base] >> idx & 1) --k;
		}
		return res;
	}
	
	size_type select0(size_type k) const {
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << LARGE) * m - large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= (1u << LARGE) * (r - 1) - large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << SMALL) * m - small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= (1u << SMALL) * (r - 1) - small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (~bits[base] >> idx & 1) --k;
		}
		return res;
	}
	
	void build() {
		large.assign((n >> LARGE) + 1, 0);
		small.assign((n >> SMALL) + 1, 0);
		
		for (size_type i = 0, small_idx = 1; i < bits.size() - 1; ++i) {
			if ((i & ((1u << (LARGE - DAT_B)) - 1)) == 0) small[small_idx] = pop_count(get_val(bits[i], 0));
			else small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], 0));
			++small_idx;
			
			for (size_type j = 1; j < (1u << (DAT_B - SMALL)); ++j, ++small_idx)
				small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], j));
		}
		
		for (size_type i = 1; i < large.size(); ++i) {
			large[i] = large[i - 1] + small[i << (LARGE - SMALL)];
			small[i << (LARGE - SMALL)] = 0;
		}
	}
	
private:
	uint16 get_val(uint64 x, size_type i) const {
		return x >> ((1u << SMALL) * i) & (SMALL_S - 1);
	}
	
	uint16 pop_count(uint16 x) const {
		return table[x];
	}
};

constexpr SuccintBitVector::uint16 SuccintBitVector::table[256] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
};

#endif // INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SuccintBitVector.hpp"



#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>

/*
last-updated: 2020/09/07

使用する前に必ず build() を呼ぶ
高速化のために assert チェックを入れていないので注意

TODO: O(1) select を調べる

# 仕様
n = 2^16 ~ 10^4.8 で計算量が保証されている実装
空間計算量: n + o(n)

SuccintBitVector(size_type n) :
	時間計算量: Θ(n)
	要素数 n で初期化

SuccintBitVector(const std::vector<uint64> & v) :
	時間計算量: Θ(n)
	bit 配列 v で初期化

size_type size() const noexcept :
	時間計算量: O(1)
	要素数 n を返す

void set(size_type i) :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットを立てる

bool access(size_type i) const :
	時間計算量: O(1)
	i (0 \leq i < n) 番目のビットの値を返す

size_type rank1(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 1 になっているビットの数を返す

size_type rank0(size_type i) const :
	時間計算量: O(1)
	(0 \leq i \leq n) [0, i) で 0 になっているビットの数を返す

size_type select1(size_type k) const :
	時間計算量: O(log n)
	rank1(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 1 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

size_type select0(size_type k) const :
	時間計算量: O(log n)
	rank0(i) = k を満たす最小の k を返す (k > 0 のとき k 番目[1-indexed] に 0 が出現する位置[1-indexed])
	存在しなければ size() + 1 を返す

# 参考
https://misteer.hatenablog.com/entry/bit-vector, 2020/09/03
https://miti-7.hatenablog.com/entry/2018/04/15/155638, 2020/09/03
*/

struct SuccintBitVector {
	using size_type = std::size_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
	
private:
	// optimized n = 2^16
	static constexpr size_type LARGE = 8; // bits, log^2 n
	static constexpr size_type SMALL = 3; // bits, (log n) / 2
	static constexpr size_type DAT_B = 6; // bits (2^6 = 64 bit)
	static constexpr size_type SMALL_S = 1ull << (1ull << SMALL);
	
private:
	size_type n;
	std::vector<uint64> bits;
	std::vector<uint32> large;
	std::vector<uint16> small;
	
	static const uint16 table[SMALL_S];
	
public:
	SuccintBitVector(size_type n) {
		assert(n > 0);
		n = (n + (1u << LARGE) - 1) >> LARGE << LARGE;
		this->n = n;
		bits.resize((n >> DAT_B) + 1);
	}
	
	SuccintBitVector(const std::vector<uint64> & v) {
		assert(!v.empty());
		n = ((v.size() << DAT_B) + (1u << LARGE) - 1) >> LARGE << LARGE;
		bits.resize((n >> DAT_B) + 1);
		std::copy(std::begin(v), std::end(v), std::begin(bits));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i) {
		bits[i >> DAT_B] |= 1ull << (i & ((1u << DAT_B) - 1));
	}
	
	bool access(size_type i) const {
		return bits[i >> DAT_B] >> (i & ((1u << DAT_B) - 1)) & 1;
	}
	
	size_type rank1(size_type i) const {
		return large[i >> LARGE] + small[i >> SMALL]
			+ pop_count(
				get_val(bits[i >> DAT_B], (i & ((1u << DAT_B) - 1)) >> SMALL)
					& ((1u << (i & ((1u << SMALL) - 1))) - 1) );
		// (i >> DAT_B) < bits.size() となるように +1 余分に確保
	}
	
	size_type rank0(size_type i) const {
		return i - rank1(i);
	}
	
	size_type select1(size_type k) const {
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			(small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (bits[base] >> idx & 1) --k;
		}
		return res;
	}
	
	size_type select0(size_type k) const {
		if (k == 0) return 0;
		
		size_type l = 0, r = large.size() - 1; // (l, r]
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << LARGE) * m - large[m] >= k ? r : l) = m;
		}
		
		size_type res = (r - 1) << LARGE;
		k -= (1u << LARGE) * (r - 1) - large[r - 1];
		size_type base = (r - 1) << (LARGE - SMALL);
		l = 0; r = 1u << (LARGE - SMALL);
		while (r - l > 1) {
			size_type m = (l + r) >> 1;
			((1u << SMALL) * m - small[base + m] >= k ? r : l) = m;
		}
		
		res += (r - 1) << SMALL;
		base += r - 1;
		k -= (1u << SMALL) * (r - 1) - small[base];
		base >>= DAT_B - SMALL;
		for (size_type idx = ((r - 1) & ((1u << SMALL) - 1)) << SMALL; k; ++idx, ++res) {
			if (~bits[base] >> idx & 1) --k;
		}
		return res;
	}
	
	void build() {
		large.assign((n >> LARGE) + 1, 0);
		small.assign((n >> SMALL) + 1, 0);
		
		for (size_type i = 0, small_idx = 1; i < bits.size() - 1; ++i) {
			if ((i & ((1u << (LARGE - DAT_B)) - 1)) == 0) small[small_idx] = pop_count(get_val(bits[i], 0));
			else small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], 0));
			++small_idx;
			
			for (size_type j = 1; j < (1u << (DAT_B - SMALL)); ++j, ++small_idx)
				small[small_idx] = small[small_idx - 1] + pop_count(get_val(bits[i], j));
		}
		
		for (size_type i = 1; i < large.size(); ++i) {
			large[i] = large[i - 1] + small[i << (LARGE - SMALL)];
			small[i << (LARGE - SMALL)] = 0;
		}
	}
	
private:
	uint16 get_val(uint64 x, size_type i) const {
		return x >> ((1u << SMALL) * i) & (SMALL_S - 1);
	}
	
	uint16 pop_count(uint16 x) const {
		return table[x];
	}
};

constexpr SuccintBitVector::uint16 SuccintBitVector::table[256] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

