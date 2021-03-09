#ifndef INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP
#define INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP

#include <cassert>
#include <memory>
#include <utility>
#include <vector>
#include <stack>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/PersistentRedBlackTree.hpp
 */
template<typename T>
struct PersistentRedBlackTree {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
	static constexpr bool red = true;
	static constexpr bool black = false;
	struct Node;
	using node_ptr = std::shared_ptr<Node>;
	using node_ref = const node_ptr &;
	using raw_ptr = Node *;
	struct Node {
		value_type val;
		bool color;
		size_type size, rank;
		node_ptr l, r;
		Node(bool color, node_ref l, node_ref r)
			: color(color), size(l->size + r->size), rank(l->rank + (l->color == black)), l(l), r(r) {}
		Node(const_reference val) : val(val), color(black), size(1), rank(0), l(nullptr), r(nullptr) {}
	};
	
private:
	node_ptr root = nullptr;
	
	PersistentRedBlackTree(node_ref root) : root(root) {}
	
	static node_ptr create(bool color, node_ref l, node_ref r) {
		return std::make_shared<Node>(color, l, r);
	}
	
	static node_ptr create(const_reference val) {
		return std::make_shared<Node>(val);
	}
	
public:
	PersistentRedBlackTree() = default;
	
	PersistentRedBlackTree(const std::vector<value_type> & v)
		: root(v.empty() ? nullptr : build(std::begin(v), std::end(v), 30)) {}
	
	PersistentRedBlackTree(size_type n, const_reference x)
		: root(n == 0 ? nullptr : buildn(n, x, 30)) {}
	
	bool empty() const noexcept {
		return size() == 0;
	}
	
	size_type size() const noexcept {
		return root ? root->size : 0;
	}
	
	void clear() {
		root = nullptr;
	}
	
	std::vector<value_type> enumerate() const {
		std::vector<value_type> elements;
		std::stack<raw_ptr> stk;
		stk.emplace(root.get());
		while (!stk.empty()) {
			raw_ptr q = stk.top();
			stk.pop();
			if (q->l) {
				stk.emplace(q->r.get());
				stk.emplace(q->l.get());
			}
			else elements.emplace_back(q->val);
		}
		return elements;
	}
	
	PersistentRedBlackTree merge(const PersistentRedBlackTree & a) const {
		return merge(root, a.root);
	}
	
	std::pair<PersistentRedBlackTree, PersistentRedBlackTree> split(size_type k) const {
		assert(k <= size());
		const auto sp = split(root, k);
		return {sp.first, sp.second};
	}
	
	PersistentRedBlackTree insert(size_type k, const_reference x) const {
		assert(k <= size());
		return insert(root, k, x);
	}
	
	PersistentRedBlackTree erase(size_type k) const {
		assert(k < size());
		return erase(root, k);
	}
	
	const_reference get(size_type k) const noexcept {
		assert(k < size());
		raw_ptr q = root.get();
		while (q->l) {
			if (k < q->l->size) q = (q->l).get();
			else k -= q->l->size, q = (q->r).get();
		}
		return q->val;
	}
	
private:
	template<class InputIterator>
	node_ptr build(InputIterator first, InputIterator last, int k) const {
		if (first + 1 == last) return create(*first);
		const auto n = last - first;
		const unsigned int m = 1u << k;
		if (n > m) return merge(build(first, first + m, k - 1), build(first + m, last, k - 1));
		return build(first, last, k - 1);
	}
	
	node_ptr buildn(size_type n, const_reference x, int k) const {
		if (n == 1) return create(x);
		const unsigned int m = 1u << k;
		if (n > m) return merge(buildn(m, x, k - 1), buildn(n - m, x, k - 1));
		return buildn(n, x, k - 1);
	}
	
	node_ptr as_root(const node_ptr & q) const {
		if (!q) return nullptr;
		if (q->color == red) return create(black, q->l, q->r);
		return q;
	}
	
	node_ptr merge(const node_ptr & a, const node_ptr & b) const {
		if (!a) return b;
		if (!b) return a;
		node_ptr res = merge_sub(a, b);
		res->color = black;
		return res;
	}
	
	node_ptr merge_sub(const node_ptr & a, const node_ptr & b) const {
		if (a->rank < b->rank) {
			node_ptr c = merge_sub(a, b->l);
			if (b->color == black && c->color == red && c->l->color == red) {
				if (b->r->color == black) return create(black, c->l, create(red, c->r, b->r));
				c->color = black;
				return create(red, c, create(black, b->r->l, b->r->r));
			}
			return create(b->color, c, b->r);
		}
		else if (a->rank > b->rank) {
			const node_ptr c = merge_sub(a->r, b);
			if (a->color == black && c->color == red && c->r->color == red) {
				if (a->l->color == black) return create(black, create(red, a->l, c->l), c->r);
				c->color = black;
				return create(red, create(black, a->l->l, a->l->r), c);
			}
			return create(a->color, a->l, c);
		}
		return create(red, a, b);
	}
	
	std::pair<node_ptr, node_ptr> split(const node_ptr & a, size_type k) const {
		if (!a) return {nullptr, nullptr};
		if (k == 0) return {nullptr, as_root(a)};
		if (k == a->size) return {as_root(a), nullptr};
		if (k < a->l->size) {
			const auto sp = split(a->l, k);
			return {as_root(sp.first), merge(sp.second, as_root(a->r))};
		}
		if (k > a->l->size) {
			const auto sp = split(a->r, k - a->l->size);
			return {merge(as_root(a->l), sp.first), as_root(sp.second)};
		}
		return {as_root(a->l), as_root(a->r)};
	}
	
	node_ptr insert(const node_ptr & a, size_type k, const_reference x) const {
		if (!a) return create(x);
		const auto sp = split(a, k);
		return merge(sp.first, merge(create(x), sp.second));
	}
	
	node_ptr erase(const node_ptr & a, size_type k) const {
		const auto sp = split(a, k + 1);
		return merge(split(sp.first, k).first, sp.second);
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_RED_BLACK_TREE_HPP