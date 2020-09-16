#ifndef INCLUDE_GUARD_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_SEGMENT_TREE_HPP

/*
last-updated: 2020/09/13

max_right: verified(https://atcoder.jp/contests/practice2/submissions/16664880)
min_left: unverified

# 仕様
SegmentTree(size_type n, const_reference id_elem, const F & f) :
	時間計算量: Θ(n)
	要素数 n, 単位元 id_elem, 二項演算 f で初期化

SegmentTree(std::vector<value_type> v, const_reference id_elem, const F & f) :
	時間計算量: Θ(n)
	配列 v で初期化
	他の引数については上記の通り

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数を返す(\neq 内部のノード数)

void set(size_type i, const_reference x) :
	時間計算量: Θ(log n)
	i 番目(0 \leq i < n) の要素に x を代入

const_reference get(size_type i) const :
	時間計算量: Θ(1)
	i 番目(0 \leq i < n) の要素を返す

value_type fold(size_type l, size_type r) const :
	時間計算量: O(log n)
	[l, r) (0 \leq l \leq r \leq n) を fold した結果を返す
	l = r のときは id_elem を返す

const_reference fold_all() const :
	時間計算量: Θ(1)
	fold(0, n) の結果を返す

size_type max_right(size_type l, std::function<bool(const_reference)> g) const :
	時間計算量: O(log n)
	0 \leq l \leq n
	g は単調な関数
	次の条件を満たす最小の r を返す
		l \leq i \leq r では g(fold(l, i)) = true
		g(fold(l, r + 1)) = false
	g(fold(l, n)) = true のときは r = n

size_type min_left(size_type r, std::function<bool(const_reference)> g) const :
	時間計算量: O(log n)
	0 \leq r \leq n
	g は単調な関数
	次の条件を満たす最大の l を返す
		l \leq i \leq r では g(fold(i, r)) = true
		g(fold(l - 1, r)) = false
	g(fold(0, r)) = true のときは l = 0

# 参考
https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf, 2020/04/08
AC Library, 2020/09/13
*/

#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>


template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
private:
	size_type n, n_;
	value_type id_elem;
	F f;
	std::vector<value_type> node;
	
public:
	SegmentTree(size_type n, const_reference id_elem, const F & f) : n(n), id_elem(id_elem), f(f) {
		n_ = 1;
		while (n_ < n) n_ <<= 1;
		node.resize(2 * n_, id_elem);
	}
	
	SegmentTree(std::vector<value_type> v, const_reference id_elem, const F & f) :
			SegmentTree(v.size(), id_elem, f) {
		for (size_type i = 0; i < v.size(); ++i) node[i + n_] = v[i];
		for (size_type i = n_ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += n_] = x;
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
	
	const_reference get(size_type i) const {
		assert(i < size());
		return node[i + n_];
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= r);
		assert(r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	const_reference fold_all() const {
		return node[1];
	}
	
	size_type max_right(size_type l, std::function<bool(const_reference)> g) const {
		assert(l <= size());
		assert(g(id_elem));
		if (l == size()) return size();
		l += n_;
		value_type sum = id_elem;
		while (true) {
			while (~l & 1) l >>= 1;
			const value_type nex_sum = f(sum, node[l]);
			if (g(nex_sum)) { sum = nex_sum; ++l; }
			else break;
			if ((l & -l) == l) return size();
		}
		while (l < n_) {
			const value_type nex_sum = f(sum, node[l << 1]);
			l <<= 1;
			if (g(nex_sum)) { sum = nex_sum; l |= 1; }
		}
		return l - n_;
	}
	
	size_type min_left(size_type r, std::function<bool(const_reference)> g) const {
		assert(r <= size());
		assert(g(id_elem));
		if (r == 0) return 0;
		r += n_;
		value_type sum = id_elem;
		while (true) {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			const value_type nex_sum = f(node[r], sum);
			if (g(nex_sum)) sum = nex_sum;
			else break;
			if ((r & -r) == r) return 0;
		}
		while (r < n_) {
			const value_type nex_sum = f(node[r << 1 | 1], sum);
			r <<= 1;
			if (!g(nex_sum)) r |= 1;
			else sum = nex_sum;
		}
		return r + 1 - n_;
	}
};

#endif // INCLUDE_GUARD_SEGMENT_TREE_HPP