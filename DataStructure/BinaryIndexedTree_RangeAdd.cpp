#include <vector>
#include <cassert>
#include <functional>

/*
last-updated: 2020/08/15

BIT を用いた区間加算が行えるデータ構造

# 仕様
template<typename T, template<typename> class U> :
	T: 各要素のデータ型
	U: BinaryIndexedTree
	ex. BinaryIndexedTree_RangeAdd<long long, BinaryIndexedTree> bit(...)

size_type size() const noexcept :
	時間計算量: Θ(1)
	要素数を取得

void add(size_type l, size_type r, const_reference x) :
	時間計算量: Θ(log n)
	区間 [l, r) に一様に値 x を加算

value_type sum(size_type i) :
	時間計算量: Θ(log n)
	区間 [0, i) の合計を取得

value_type sum(size_type l, size_type r) :
	時間計算量: Θ(log n)
	区間 [l, r) の合計を取得

# 参考
https://algo-logic.info/binary-indexed-tree/, 2020/08/15
*/

template<typename T, template<typename> class U>
struct BinaryIndexedTree_RangeAdd {
	using bit_type = U<T>;
	using value_type = typename bit_type::value_type;
	using const_reference = typename bit_type::const_reference;
	using size_type = typename bit_type::size_type;
	
	BinaryIndexedTree_RangeAdd(size_type n) : n(n) {
		bit.resize(2, bit_type(n, [](auto && x, auto && y) { return x + y; }, 0));
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	// [l, r) += x
	void add(size_type l, size_type r, const_reference x) {
		assert(l < r);
		assert(r <= size());
		bit[0].add(l, x);
		bit[0].add(r - 1, -x);
		bit[1].add(l, -x * (static_cast<value_type>(l) - 1));
		bit[1].add(r - 1, x * (r - 1));
	}
	
	// \Sum_{ k = [0, i) } a_k
	value_type sum(size_type i) {
		assert(i <= size());
		return bit[0].sum(i) * (static_cast<value_type>(i) - 1) + bit[1].sum(i);
	}
	
	// \Sum_{ k = [l, r) } a_k
	value_type sum(size_type l, size_type r) {
		assert(l < r);
		assert(r <= size());
		return sum(r) - sum(l);
	}
	
private:
	size_type n;
	std::vector<bit_type> bit;
};