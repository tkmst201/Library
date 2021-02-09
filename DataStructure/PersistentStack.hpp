#ifndef INCLUDE_GUARD_PERSISTENT_STACK_HPP
#define INCLUDE_GUARD_PERSISTENT_STACK_HPP

#include <memory>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/PersistentStack.hpp
 */
template<typename T>
struct PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	struct Node {
		value_type value;
		sptr_type prev;
		size_type sz;
		Node(const_reference value, const sptr_type & prev, size_type sz) : value(value), prev(prev), sz(sz) {}
	};
	
private:
	sptr_type top_node;
	PersistentStack(const sptr_type & prev) : top_node(prev) {}
	
public:
	PersistentStack() = default;
	
	bool empty() const noexcept {
		return !static_cast<bool>(top_node);
	}
	
	size_type size() const noexcept {
		if (empty()) return 0;
		return top_node->sz;
	}
	
	PersistentStack push(const_reference x) const {
		return PersistentStack{std::make_shared<Node>(x, top_node, size() + 1)};
	}
	
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack{top_node->prev};
	}
	
	const_reference top() const {
		assert(!empty());
		return top_node->value;
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_STACK_HPP