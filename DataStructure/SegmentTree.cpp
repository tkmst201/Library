#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

SegmentTree(size_type n_, const F & f, const_reference id_elem) : 要素数 n_, 二項演算 f, 単位元 id_elem
void set(size_type i, const_reference x) : Θ(log n) i 番目の要素に x を代入
void add(size_type i, const_reference x) : Θ(lon n) i 番目の要素に x を演算する
value_type fold(size_type l, size_type r) const : Θ(log n) [l, r) を fold した結果を返す
size_type lower_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) >= x となるような最小の idx を返す
size_type upper_bound(const_reference x) const : Θ(log n) 単調増加を仮定し、fold(0, idx) > x となるような最小の idx を返す

参考 :
https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf, 2020/04/08
*/

template<typename T>
struct SegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using F = std::function<value_type(const_reference, const_reference)>;
	using size_type = std::size_t;
	
	SegmentTree(size_type n_, const F & f, const_reference id_elem) : f(f), id_elem(id_elem) {
		n = 1;
		while (n < n_) n <<= 1;
		node.resize(2 * n, id_elem);
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i, const_reference x) {
		assert(i < size());
		node[i += size()] = x;
		update_(i);
	}
	
	void add(size_type i, const_reference x) {
		assert(i < size());
		i += size();
		node[i] = f(node[i], x);
		update_(i);
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= size() && r <= size());
		value_type lv = id_elem, rv = id_elem;
		for (l += size(), r += size(); l < r; l >>= 1, r >>= 1) {
			if (l & 1) lv = f(lv, node[l++]);
			if (r & 1) rv = f(node[r - 1], rv);
		}
		return f(lv, rv);
	}
	
	size_type lower_bound(const_reference x) const {
		if (node[1] < x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
			value_type nex = f(s, node[idx << 1]);
			if (nex < x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
	size_type upper_bound(const_reference x) const {
		if (node[1] <= x) return size();
		size_type idx;
		value_type s = id_elem;
		for (idx = 1; idx < size();) {
			value_type nex = f(s, node[idx << 1]);
			if (nex <= x) {
				idx = idx << 1 | 1;
				s = nex;
			}
			else idx = idx << 1;
		}
		return idx - n;
	}
	
private:
	size_type n;
	F f;
	value_type id_elem;
	std::vector<value_type> node;
	
	void update_(size_type i) {
		assert(size() <= i && i < node.size());
		while (i > 1) {
			i >>= 1;
			node[i] = f(node[i << 1], node[i << 1 | 1]);
		}
	}
};
