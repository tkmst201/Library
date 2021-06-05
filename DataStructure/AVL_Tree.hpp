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
		bool isr;
		int8 height[2] {};
		uint32 size[2] {};
		Node(const_reference val, node_ptr par, bool isr) : val(val), par(par), isr(isr) {}
	};
	
private:
	size_type n = 0;
	node_ptr root = nullptr;
	node_ptr e_ptr[2] {nullptr, nullptr};
	
public:
	AVL_Tree() = default;
	
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
			auto dfs = [](auto self, const_ptr q, node_ptr r) -> node_ptr {
				if (!q) return nullptr;
				node_ptr res = new Node(q->val, r, q->isr);
				for (int i = 0; i < 2; ++i) {
					res->height[i] = q->height[i];
					res->size[i] = q->size[i];
					res->child[i] = self(self, q->child[i], res);
				}
				return res;
			};
			root = dfs(dfs, rhs.root, nullptr);
			n = rhs.n;
			e_ptr[0] = e_ptr[1] = root;
			if (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];
		}
		return *this;
	}
	
	AVL_Tree & operator =(AVL_Tree && rhs) {
		if (this != &rhs) {
			clear();
			n = rhs.n;
			rhs.n = 0;
			root = rhs.root;
			rhs.root = nullptr;
			std::copy(rhs.e_ptr, rhs.e_ptr + 2, e_ptr);
			std::fill(rhs.e_ptr, rhs.e_ptr + 2, nullptr);
		}
		return *this;
	}
	
	bool empty() const noexcept {
		return size() == 0;
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void clear() {
		if (!root) return;
		std::stack<node_ptr> stk;
		stk.emplace(root);
		while (!stk.empty()) {
			node_ptr node = stk.top();
			stk.pop();
			if (node->child[0]) stk.emplace(node->child[0]);
			if (node->child[1]) stk.emplace(node->child[1]);
			delete node;
		}
		n = 0;
		root = nullptr;
		std::fill(e_ptr, e_ptr + 2, nullptr);
	}
	
	std::vector<value_type> enumerate() const {
		std::vector<value_type> elements;
		elements.reserve(size());
		auto dfs = [&elements](auto self, const_ptr q) -> void {
			if (!q) return;
			self(self, q->child[0]);
			elements.emplace_back(q->val);
			self(self, q->child[1]);
		};
		dfs(dfs, root);
		return elements;
	}
	
	node_ptr begin() const noexcept {
		return e_ptr[0];
	}
	
	node_ptr end() const noexcept {
		return nullptr;
	}
	
	node_ptr insert(const_reference x) {
		node_ptr q = root, r = nullptr;
		bool ef[2] {}, d = false;
		while (q) {
			r = q;
			d = q->val <= x;
			q = q->child[d];
			ef[!d] = true;
		}
		q = new Node(x, r, d);
		++n;
		if (!ef[0]) e_ptr[0] = q;
		if (!ef[1]) e_ptr[1] = q;
		if (r) {
			r->size[d] = 1;
			r->height[d] = 1;
			r->child[d] = q;
			update(r);
		}
		else root = q;
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
		if (q->child[0] && q->child[1]) {
			node_ptr p = q->child[0];
			while (p->child[1]) p = p->child[1];
			q->val = std::move(p->val);
			q = p;
		}
		if (e_ptr[0] == q) e_ptr[0] = next(q);
		if (e_ptr[1] == q) e_ptr[1] = prev(q);
		const node_ptr r = q->par;
		if (q->child[0] || q->child[1]) {
			const node_ptr p = q->child[0] ? q->child[0] : q->child[1];
			if (r) {
				r->size[q->isr] = q->size[p->isr];
				r->height[q->isr] = q->height[p->isr];
				r->child[q->isr] = p;
				p->par = r;
				p->isr = q->isr;
			}
			else {
				p->par = nullptr;
				root = p;
			}
		}
		else if (r) {
			r->size[q->isr] = 0;
			r->height[q->isr] = 0;
			r->child[q->isr] = nullptr;
		}
		else root = nullptr;
		delete q;
		--n;
		if (r) update(r);
		return ret;
	}
	
	node_ptr find(const_reference x) const noexcept {
		const node_ptr q = lower_bound(x);
		if (q != end() && q->val != x) return end();
		return q;
	}
	
	node_ptr lower_bound(const_reference x) const noexcept {
		node_ptr q = root;
		if (!q) return end();
		while (q->child[q->val < x]) q = q->child[q->val < x];
		if (q->val < x) q = next(q);
		return q;
	}
	
	node_ptr upper_bound(const_reference x) const noexcept {
		node_ptr q = root;
		if (!q) return end();
		while (q->child[q->val <= x]) q = q->child[q->val <= x];
		if (q->val <= x) q = next(q);
		return q;
	}
	
	size_type count_less_than(const_reference x) const noexcept {
		size_type res = 0;
		node_ptr q = root;
		while (q != nullptr) {
			bool r = q->val < x;
			if (r) res += q->size[0] + 1;
			q = q->child[r];
		}
		return res;
	}
	
	size_type count_less_equal(const_reference x) const noexcept {
		size_type res = 0;
		node_ptr q = root;
		while (q != nullptr) {
			bool r = q->val <= x;
			if (r) res += q->size[0] + 1;
			q = q->child[r];
		}
		return res;
	}
	
	size_type count_greater_than(const_reference x) const noexcept {
		return size() - count_less_equal(x);
	}
	
	size_type count_greater_equal(const_reference x) const noexcept {
		return size() - count_less_than(x);
	}
	
	size_type count(const_reference x) const noexcept {
		return count_less_equal(x) - count_less_than(x);
	}
	
	node_ptr k_th_smallest(uint32 k) const noexcept {
		if (k == 0 || n < k) return end();
		node_ptr q = root;
		while (k != q->size[0] + 1) {
			if (k > q->size[0] + 1) k -= q->size[0] + 1, q = q->child[1];
			else q = q->child[0];
		}
		return q;
	}
	
	node_ptr k_th_largest(uint32 k) const noexcept {
		if (k == 0 || n < k) return end();
		return k_th_smallest(n - k + 1);
	}
	
	node_ptr next(node_ptr q) const noexcept {
		return move(q, true);
	}
	
	node_ptr prev(node_ptr q) const noexcept {
		return move(q, false);
	}
	
private:
	node_ptr rotate(node_ptr q, bool d) noexcept {
		node_ptr r = q->par, p = q->child[!d], b = p->child[d];
		(r ? r->child[q->isr] : root) = p;
		q->child[!d] = b;
		p->child[d] = q;
		if (b) {
			b->par = q;
			b->isr = !d;
		}
		p->par = r;
		p->isr = q->isr;
		q->par = p;
		q->isr = d;
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
			r->size[q->isr] = q->size[0] + q->size[1] + 1;
			r->height[q->isr] = std::max(q->height[0], q->height[1]) + 1;
			q = r;
		}
	}
	
	node_ptr move(node_ptr q, bool d) const noexcept {
		if (q == end()) return e_ptr[!d];
		if (q == begin() && !d) return end();
		if (q->child[d]) for (q = q->child[d]; q->child[!d]; q = q->child[!d]);
		else {
			while (q && (d ^ !q->isr)) q = q->par;
			if (q) q = q->par;
		}
		return q;
	}
};

#endif // INCLUDE_GUARD_AVL_TREE_HPP