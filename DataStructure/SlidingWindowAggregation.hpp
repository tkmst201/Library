#ifndef INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP
#define INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP

#include <cassert>
#include <vector>
#include <functional>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/SlidingWindowAggregation.hpp
 */
template<typename T>
struct SlidingWindowAggregation {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	value_type id_elem;
	F f;
	std::vector<value_type> lstack, rstack;
	value_type rsum;
	
public:
	SlidingWindowAggregation(const_reference id_elem, const F & f)
		: id_elem(id_elem), f(f), lstack(1, id_elem), rsum(id_elem) {}
	
	size_type size() const noexcept {
		return lstack.size() - 1 + rstack.size();
	}
	
	void push(const_reference x) {
		rstack.emplace_back(x);
		rsum = f(rsum, x);
	}
	
	void pop() {
		assert(size() > 0);
		if (lstack.size() == 1) {
			while (rstack.size() > 1) {
				lstack.emplace_back(f(rstack.back(), lstack.back()));
				rstack.pop_back();
			}
			rstack.pop_back();
			rsum = id_elem;
		}
		else lstack.pop_back();
	}
	
	value_type fold_all() const {
		return f(lstack.back(), rsum);
	}
};

#endif // INCLUDE_GUARD_SLIDING_WINDOW_AGGREGATION_HPP