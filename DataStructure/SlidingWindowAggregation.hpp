#ifndef INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP
#define INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP

/*
last-updated: 2020/09/22

# 概要
モノイドを扱う SWAG
queue の push, pop に加え、要素全体を入れた順に fold した結果を償却 O(1) で求めることができるデータ構造

# 仕様
template<
	typename T: 扱うモノイド
>

SlidingWindowAggregation(const_reference id_elem, const F & f)
	時間計算量: Θ(1)
	単位元 id_elem, 二項演算 f として初期化

size_type size() const noexcept
	時間計算量: Θ(1)
	現在入っている要素数を返す

void push(const_reference x)
	時間計算量: O(1) amortized
	queue に値 x を追加する

void pop()
	時間計算量: O(1) amortized
	queue の最初の要素を削除する
	必ず要素が存在しなければならない

value_type fold_all()
	時間計算量: O(1) amortized
	現在入っている値を fold した結果を返す

# 参考
https://scrapbox.io/data-structures/Sliding_Window_Aggregation, 2020/09/22
https://snuke.hatenablog.com/entry/2018/09/18/135640, 2020/09/22
*/

#include <cstdint>
#include <cassert>
#include <vector>
#include <utility>
#include <functional>

template<typename T>
struct SlidingWindowAggregation {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::uint_fast32_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
private:
	value_type id_elem;
	F f;
	std::vector<std::pair<value_type, value_type>> lstack;
	std::vector<value_type> rstack;
	value_type rsum;
	
public:
	SlidingWindowAggregation(const_reference id_elem, const F & f) : id_elem(id_elem), f(f), rsum(id_elem) {}
	
	size_type size() const noexcept { return lstack.size() + rstack.size(); }
	
	void push(const_reference x) {
		rstack.emplace_back(x);
		rsum = f(rsum, x);
	}
	
	void pop() {
		assert(size() > 0);
		if (lstack.empty()) {
			if (rstack.size() > 1) {
				lstack.emplace_back(rstack.back(), rstack.back());
				rstack.pop_back();
			}
			while (rstack.size() > 1) {
				lstack.emplace_back(rstack.back(), f(rstack.back(), lstack.back().second));
				rstack.pop_back();
			}
			rstack.pop_back();
			rsum = id_elem;
		}
		else lstack.pop_back();
	}
	
	value_type fold_all() const {
		return f(lstack.empty() ? id_elem : lstack.back().second, rsum);
	}
};

#endif // INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP