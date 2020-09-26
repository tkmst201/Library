#ifndef INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP
#define INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP

/*
last-updated: 2020/09/26

# 概要
完全永続 UnionFind
UnionFind で過去の任意の状態を見る or 操作可能

添字の範囲を [0, n), 完全永続配列の内部を m 分木としたとき、
	- unite
		時間/空間 計算量: O(m log_2 n log_m n)
	- find, size
		時間計算量: O(m log_2 n log_m n)
		空間計算量: Θ(1)

# 解説
UnionFind の経路圧縮は行わずマージテクのみ用いると 1 クエリあたりに O(log n) 箇所の要素しか関係しない
要素 i に対応する dat[i] は、非負のとき親の要素番号、負のとき自身が代表元かつ -{集合の要素数} を表す

# 仕様
template<
	class PARRAY: 配列数指定の無い完全永続配列(扱う要素の型は符号付き整数 ex. int) 6 分木にすると速い気がする
>

完全永続配列( m 分木)の計算量を次のように仮定
	- アクセス
		時間計算量: O(m log_m n)
		空間計算量: Θ(1)
	- 更新
		時間/空間計算量: O(m log_m n)

PersistentUnionFind()
	時間/空間計算量: Θ(1)
	全ての要素が自身のみからなる集合に属している状態で初期化

size_type find(size_type x) const
	時間計算量: O(m log_2 n log_m n)
	空間計算量: Θ(1)
	要素 x が属する集合の代表元を返す

size_type size(size_type x) const
	時間計算量: O(m log_2 n log_m n)
	空間計算量: Θ(1)
	要素 x が属する集合の要素数を返す

PersistentUnionFind unite(size_type x, size_type y) const
	時間/空間 計算量: O(m log_2 n log_m n)
	要素 x が属する集合と要素 y が属する集合を併合した状態を返す

void destructive_unite(size_type x, size_type y)
	時間/空間 計算量: O(m log_2 n log_m n)
	要素 x が属する集合と要素 y が属する集合を併合した状態を返す
	操作前の状態にアクセスできなくなるので注意(過去の状態にアクセスした場合の動作は未定義)

bool issame(size_type x, size_type y) const
	時間計算量: O(m log_2 n log_m n)
	空間計算量: Θ(1)
	要素 x, y が同じ集合に属しているか判定する

private:
std::pair<size_type, value_type> find_sub(size_type x) const
	時間計算量: O(m log_2 n log_m n)
	空間計算量: Θ(1)
	要素 x が属する集合について {代表元, 要素数} を返す

# 参考
https://qiita.com/hotman78/items/9c643feae1de087e6fc5, 2020/09/25
*/

#include <cstdint>
#include <type_traits>
#include <utility>

template<class PARRAY>
struct PersistentUnionFind {
	using value_type = typename PARRAY::value_type;
	static_assert(std::is_signed<value_type>::value == true);
	using size_type = std::uint_fast32_t;
	
private:
	PARRAY dat; // non-negative: par, negative: is root and group size
	
public:
	PersistentUnionFind() : dat(-1) {}
	
private:
	PersistentUnionFind(const PARRAY & dat) : dat(dat) {}
	
public:
	size_type find(size_type x) const {
		return find_sub(x).first;
	}
	
	size_type size(size_type x) const {
		return find_sub(x).second;
	}
	
private:
	std::pair<size_type, value_type> find_sub(size_type x) const {
		value_type d;
		for (d = dat.get(x); d >= 0; d = dat.get(x)) x = d;
		return {x, -d};
	}
	
public:
	PersistentUnionFind unite(size_type x, size_type y) const {
		if (x == y) return *this;
		std::pair<size_type, value_type> px = find_sub(x), py = find_sub(y);
		if (px.first == py.first) return *this;
		if (px.second > py.second) std::swap(px, py);
		return dat.set(px.first, py.first).set(py.first, -(px.second + py.second));
	}
	
	void destructive_unite(size_type x, size_type y) {
		std::pair<size_type, value_type> px = find_sub(x), py = find_sub(y);
		if (px.first == py.first) return;
		if (px.second > py.second) std::swap(px, py);
		dat.destructive_set(px.first, py.first);
		dat.destructive_set(py.first, -(px.second + py.second));
	}
	
	bool issame(size_type x, size_type y) const {
		return x == y ? true : find(x) == find(y);
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_UNION_FIND_HPP