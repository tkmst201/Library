#ifndef INCLUDE_GUARD_AVL_TREE_HPP
#define INCLUDE_GUARD_AVL_TREE_HPP

#include <algorithm>
#include <cstdint>
#include <vector>
#include <utility>
#include <stack>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/AVL_Tree.hpp
 */
template<typename T>
struct AVL_Tree {
	using size_type = std::size_t;
	using value_type = T;
	using const_reference = const value_type &;
	
private:
	using uint32 = std::uint32_t;
	using int8 = std::int8_t;
	
public:
	struct Node;
	using node_ptr = Node *;
	using const_ptr = const Node * const;
	struct Node {
		value_type val;
		node_ptr par, child[2] {nullptr, nullptr};
		bool is_r;
		int8 height[2] {};
		uint32 size[2] {};
		Node(const_reference x, node_ptr par, bool is_r) : val(x), par(par), is_r(is_r) {}
	};
	
	
private:
	uint32 size_ = 0;
	node_ptr root_node = nullptr;
	node_ptr e_ptr[2] {nullptr, nullptr};
	
public:
	AVL_Tree() {}
	
	AVL_Tree(const AVL_Tree & rhs) {
		*this = rhs;
	}
	
	AVL_Tree(AVL_Tree && rhs) {
		*this = std::forward<AVL_Tree>(rhs);
	}
	
	~AVL_Tree() {
		clear();
	}
	
	AVL_Tree & operator =(const AVL_Tree & rhs) {
		if (this != &rhs) {
			clear();
			root_node = copy_dfs(rhs.root_node, nullptr);
			size_ = rhs.size_;
			e_ptr[0] = e_ptr[1] = root_node;
			if (root_node) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];
		}
		return *this;
	}
	
	AVL_Tree & operator =(AVL_Tree && rhs) {
		if (this != &rhs) {
			clear();
			size_ = rhs.size_;
			rhs.size_ = 0;
			root_node = rhs.root_node;
			rhs.root_node = nullptr;
			std::copy(rhs.e_ptr, rhs.e_ptr + 2, e_ptr);
			std::fill(rhs.e_ptr, rhs.e_ptr + 2, nullptr);
		}
		return *this;
	}
	
	bool empty() const noexcept {
		return size_ == 0;
	}
	
	size_type size() const noexcept {
		return size_;
	}
	
	void clear() {
		if (!root_node) return;
		std::stack<node_ptr> stk;
		stk.emplace(root_node);
		while (!stk.empty()) {
			node_ptr node = stk.top();
			stk.pop();
			if (node->child[0]) stk.emplace(node->child[0]);
			if (node->child[1]) stk.emplace(node->child[1]);
			delete node;
		}
		root_node = nullptr;
		size_ = 0;
		std::fill(e_ptr, e_ptr + 2, nullptr);
	}
	
	std::vector<value_type> enumerate() const {
		std::vector<value_type> elements;
		elements.reserve(size());
		enumerate_dfs(root_node, elements);
		return elements;
	}
	
	node_ptr begin() const noexcept {
		return e_ptr[0];
	}
	
	node_ptr end() const noexcept {
		return nullptr;
	}
	
	node_ptr find(const_reference x) const noexcept {
		const node_ptr q = lower_bound(x);
		if (q != end() && q->val != x) return end();
		return q;
	}
	
	node_ptr insert(const_reference x) {
		bool ef[2] {};
		node_ptr q = root_node, r = nullptr;
		bool d = false;
		while (q) {
			r = q;
			d = q->val <= x;
			q = q->child[d];
			ef[!d] = true;
		}
		q = new Node(x, r, d);
		++size_;
		for (int i = 0; i < 2; ++i) if (!ef[i]) e_ptr[i] = q;
		if (r) {
			r->size[d] = 1;
			r->height[d] = 1;
			r->child[d] = q;
			update(r);
		}
		else root_node = q;
		return q;
	}
	
	node_ptr erase(const_reference x) noexcept {
		node_ptr q = find(x);
		if (q == end()) return end();
		return erase(q);
	}
	
	node_ptr erase(node_ptr q) noexcept {
		if (!q) return end();
		const node_ptr ret = next(q);
		if (e_ptr[0] == q) e_ptr[0] = next(q);
		if (e_ptr[1] == q) e_ptr[1] = prev(q);
		node_ptr upd = nullptr;
		if (q->child[0] && q->child[1]) {
			node_ptr p = q->child[0];
			while (p->child[1]) p = p->child[1];
			q->val = std::move(p->val);
			q = p;
		}
		const node_ptr r = q->par;
		if (r) upd = r;
		if (q->child[0] || q->child[1]) {
			const node_ptr p = q->child[0] ? q->child[0] : q->child[1];
			if (r) {
				r->size[q->is_r] = q->size[p->is_r];
				r->height[q->is_r] = q->height[p->is_r];
				r->child[q->is_r] = p;
				p->par = r;
				p->is_r = q->is_r;
			}
			else {
				p->par = nullptr;
				root_node = p;
			}
		}
		else if (r) {
			r->size[q->is_r] = 0;
			r->height[q->is_r] = 0;
			r->child[q->is_r] = nullptr;
		}
		else root_node = nullptr;
		delete q;
		--size_;
		if (upd) update(upd);
		return ret;
	}
	
	node_ptr lower_bound(const_reference x) const noexcept {
		node_ptr q = root_node;
		if (!q) return end();
		while (q->child[q->val < x]) q = q->child[q->val < x];
		if (q->val < x) q = next(q);
		return q;
	}
	
	node_ptr upper_bound(const_reference x) const noexcept {
		node_ptr q = root_node;
		if (!q) return end();
		while (q->child[q->val <= x]) q = q->child[q->val <= x];
		if (q->val <= x) q = next(q);
		return q;
	}
	
	size_type count_less_than(const_reference x) const noexcept {
		size_type res = 0;
		node_ptr q = root_node;
		while (q != nullptr) {
			bool r = q->val < x;
			if (r) res += q->size[0] + 1;
			q = q->child[r];
		}
		return res;
	}
	
	size_type count_less_equal(const_reference x) const noexcept {
		size_type res = 0;
		node_ptr q = root_node;
		while (q != nullptr) {
			bool r = q->val <= x;
			if (r) res += q->size[0] + 1;
			q = q->child[r];
		}
		return res;
	}
	
	size_type count_more_than(const_reference x) const noexcept {
		return size() - count_less_equal(x);
	}
	
	size_type count_more_equal(const_reference x) const noexcept {
		return size() - count_less_than(x);
	}
	
	size_type count(const_reference x) const noexcept {
		return count_less_equal(x) - count_less_than(x);
	}
	
	node_ptr k_th_smallest(uint32 k) const noexcept {
		if (k == 0 || size_ < k) return end();
		node_ptr q = root_node;
		while (k != q->size[0] + 1) {
			if (k > q->size[0] + 1) k -= q->size[0] + 1, q = q->child[1];
			else q = q->child[0];
		}
		return q;
	}
	
	node_ptr k_th_largest(uint32 k) const noexcept {
		if (k == 0 || size_ < k) return end();
		return k_th_smallest(size_ - k + 1);
	}
	
	node_ptr next(node_ptr q) const noexcept {
		if (q == end()) return begin();
		return move(q, true);
	}
	
	node_ptr prev(node_ptr q) const noexcept {
		if (q == begin()) return end();
		return move(q, false);
	}
	
private:
	node_ptr copy_dfs(const_ptr q, node_ptr r) {
		if (!q) return nullptr;
		node_ptr res = new Node(q->val, r, q->is_r);
		for (int i = 0; i < 2; ++i) {
			res->height[i] = q->height[i];
			res->size[i] = q->size[i];
			res->child[i] = copy_dfs(q->child[i], res);
		}
		return res;
	}
	
	void enumerate_dfs(const_ptr q, std::vector<value_type> & elements) const {
		if (!q) return;
		enumerate_dfs(q->child[0], elements);
		elements.emplace_back(q->val);
		enumerate_dfs(q->child[1], elements);
	}
	
	node_ptr rotate(node_ptr q, bool d) noexcept {
		node_ptr r = q->par, p = q->child[!d], b = p->child[d];
		(r ? r->child[q->is_r] : root_node) = p;
		q->child[!d] = b;
		p->child[d] = q;
		if (b) {
			b->par = q;
			b->is_r = !d;
		}
		p->par = q->par;
		p->is_r = q->is_r;
		q->par = p;
		q->is_r = d;
		q->size[!d] = p->size[d];
		q->height[!d] = p->height[d];
		p->size[d] = q->size[0] + q->size[1] + 1;
		p->height[d] = std::max(q->height[0], q->height[1]) + 1;
		return p;
	}
	
	void update(node_ptr q) noexcept {
		bool done = false;
		while (true) {
			if (!done && std::abs(q->height[0] - q->height[1]) > 1) {
				const bool d = q->height[0] > q->height[1];
				const node_ptr p = q->child[!d];
				if (p->height[!d] < p->height[d]) rotate(p, !d);
				q = rotate(q, d);
				done = true;
			}
			const node_ptr r = q->par;
			if (!r) break;
			r->size[q->is_r] = q->size[0] + q->size[1] + 1;
			r->height[q->is_r] = std::max(q->height[0], q->height[1]) + 1;
			q = r;
		}
	}
	
	node_ptr move(node_ptr q, bool d) const noexcept {
		if (q == end()) return e_ptr[!d];
		if (q == begin() && !d) return end();
		if (q->child[d]) for (q = q->child[d]; q->child[!d]; q = q->child[!d]);
		else {
			while (q && (d ^ !q->is_r)) q = q->par;
			if (q) q = q->par;
		}
		return q;
	}
};

#endif // INCLUDE_GUARD_AVL_TREE_HPP