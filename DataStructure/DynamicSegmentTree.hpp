#ifndef INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP

#include <functional>
#include <cassert>
#include <stack>
#include <cstdint>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/DynamicSegmentTree.hpp
 */
template<typename T>
struct DynamicSegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	struct Node;
	using node_ptr = Node *;
	using const_ptr = const Node * const;
	struct Node {
		value_type val;
		node_ptr child[2] {nullptr, nullptr};
		Node() = default;
		Node(const_reference val) : val(val) {}
	};
	
	template<typename U>
	struct Data {
		U node;
		size_type l, r;
		Data(U node, size_type l, size_type r) : node(node), l(l), r(r) {}
	};
	
private:
	size_type n, n_;
	int log_n;
	value_type id_elem;
	F f;
	node_ptr root = nullptr;
	
public:
	DynamicSegmentTree(size_type n, const_reference id_elem, const F & f)
		: n(n), id_elem(id_elem), f(f), root(nullptr) {
		n_ = 1;
		log_n = 0;
		while (n_ < n) n_ <<= 1, ++log_n;
	}
	
	DynamicSegmentTree(const DynamicSegmentTree & rhs) {
		*this = rhs;
	}
	
	DynamicSegmentTree(DynamicSegmentTree && rhs) {
		*this = std::forward<DynamicSegmentTree>(rhs);
	}
	
	~DynamicSegmentTree() {
		clear();
	}
	
	DynamicSegmentTree & operator =(const DynamicSegmentTree & rhs) {
		if (this != &rhs) {
			clear();
			n = rhs.n;
			n_ = rhs.n_;
			log_n = rhs.log_n;
			id_elem = rhs.id_elem;
			f = rhs.f;
			root = copy_dfs(rhs.root, nullptr);
		}
		return *this;
	}
	
	DynamicSegmentTree & operator =(DynamicSegmentTree && rhs) {
		if (this != &rhs) {
			clear();
			n = rhs.n;
			n_ = rhs.n_;
			log_n = rhs.log_n;
			id_elem = rhs.id_elem;
			f = rhs.f;
			root = rhs.root;
			rhs.root = nullptr;
		}
		return *this;
	}
	
	void clear() {
		clear_subtree(root);
		root = nullptr;
	}
	
	void clear(size_type l, size_type r) {
		assert(l <= r);
		assert(r <= size());
		if ((l == 0 && r == n_) || n_ == 1) {
			clear_subtree(root);
			root = nullptr;
			return;
		}
		if (l == r || !root) return;
		std::stack<Data<node_ptr>> stk;
		stk.emplace(root, 0, n_);
		while (!stk.empty()) {
			auto [node, cl, cr] = stk.top();
			stk.pop();
			if (cl == cr) {
				node->val = f(node->child[0] ? node->child[0]->val : id_elem, node->child[1] ? node->child[1]->val : id_elem);
				continue;
			}
			const size_type m = cl + ((cr - cl) >> 1);
			stk.emplace(node, 0, 0);
			if (m < r && node->child[1]) {
				if (l <= m && cr <= r) {
					clear_subtree(node->child[1]);
					node->child[1] = nullptr;
				}
				else stk.emplace(node->child[1], m, cr);
			}
			if (l < m && node->child[0]) {
				if (l <= cl && m <= r) {
					clear_subtree(node->child[0]);
					node->child[0] = nullptr;
				}
				else stk.emplace(node->child[0], cl, m);
			}
		}
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type k, const_reference x) {
		assert(k < size());
		if (!root) root = new Node;
		node_ptr node = root;
		std::stack<node_ptr> stk;
		for (int i = log_n - 1; i >= 0; --i) {
			stk.emplace(node);
			const bool r = k >> i & 1;
			if (!node->child[r]) node->child[r] = new Node;
			node = node->child[r];
		}
		node->val = x;
		while (!stk.empty()) {
			node = stk.top();
			stk.pop();
			node->val = f(node->child[0] ? node->child[0]->val : id_elem, node->child[1] ? node->child[1]->val : id_elem);
		}
	}
	
	value_type get(size_type k) const noexcept {
		assert(k < size());
		if (!root) return id_elem;
		node_ptr node = root;
		for (int i = log_n - 1; i >= 0; --i) {
			const bool r = k >> i & 1;
			if (!node->child[r]) return id_elem;
			node = node->child[r];
		}
		return node->val;
	}
	
	value_type fold(size_type l, size_type r) const noexcept {
		assert(l <= r);
		assert(r <= size());
		if (l == r || !root) return id_elem;
		value_type res = id_elem;
		std::stack<Data<node_ptr>> stk;
		stk.emplace(root, 0, n_);
		while (!stk.empty()) {
			auto [node, cl, cr] = stk.top();
			stk.pop();
			if (l <= cl && cr <= r) res = f(res, node->val);
			else {
				const size_type m = cl + ((cr - cl) >> 1);
				if (m < r && node->child[1]) stk.emplace(node->child[1], m, cr);
				if (l < m && node->child[0]) stk.emplace(node->child[0], cl, m);
			}
		}
		return res;
	}
	
	value_type fold_all() const noexcept {
		if (!root) return id_elem;
		return root->val;
	}
	
	void swap(DynamicSegmentTree & rhs, size_type l, size_type r) {
		assert(size() == rhs.size());
		assert(id_elem == rhs.id_elem);
		assert(l <= r);
		assert(r <= size());
		if (this == &rhs) return;
		if (l == r) return;
		if ((l == 0 && r == n_) || n_ == 1) { std::swap(root, rhs.root); return; }
		if (!root && !rhs.root) return;
		if (!root) root = new Node{id_elem};
		if (!rhs.root) rhs.root = new Node{id_elem};
		std::stack<Data<std::pair<node_ptr, node_ptr>>> stk;
		stk.emplace(std::make_pair(root, rhs.root), 0, n_);
		while (!stk.empty()) {
			auto [nodes, cl, cr] = stk.top();
			auto [node1, node2] = nodes;
			stk.pop();
			if (cl == cr) {
				node1->val = f(node1->child[0] ? node1->child[0]->val : id_elem, node1->child[1] ? node1->child[1]->val : id_elem);
				node2->val = f(node2->child[0] ? node2->child[0]->val : id_elem, node2->child[1] ? node2->child[1]->val : id_elem);
				continue;
			}
			const size_type m = cl + ((cr - cl) >> 1);
			stk.emplace(nodes, 0, 0);
			if (m < r && (node1->child[1] || node2->child[1])) {
				if (l <= m && cr <= r) std::swap(node1->child[1], node2->child[1]);
				else {
					if (!node1->child[1]) node1->child[1] = new Node;
					else if (!node2->child[1]) node2->child[1] = new Node;
					stk.emplace(std::make_pair(node1->child[1], node2->child[1]), m, cr);
				}
			}
			if (l < m && (node1->child[0] || node2->child[0])) {
				if (l <= cl && m <= r) std::swap(node1->child[0], node2->child[0]);
				else {
					if (!node1->child[0]) node1->child[0] = new Node;
					else if (!node2->child[0]) node2->child[0] = new Node;
					stk.emplace(std::make_pair(node1->child[0], node2->child[0]), cl, m);
				}
			}
		}
	}
	
private:
	node_ptr copy_dfs(const_ptr q, node_ptr r) {
		if (!q) return nullptr;
		node_ptr res = new Node{q->val};
		res->child[0] = copy_dfs(q->child[0], res);
		res->child[1] = copy_dfs(q->child[1], res);
		return res;
	}
	
	void clear_subtree(node_ptr r) {
		if (!r) return;
		std::stack<node_ptr> stk;
		stk.emplace(r);
		while (!stk.empty()) {
			node_ptr node = stk.top();
			stk.pop();
			if (node->child[0]) stk.emplace(node->child[0]);
			if (node->child[1]) stk.emplace(node->child[1]);
			delete node;
		}
	}
};

#endif // INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP