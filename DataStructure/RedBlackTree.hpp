#ifndef INCLUDE_GUARD_RED_BLACK_TREE_HPP
#define INCLUDE_GUARD_RED_BLACK_TREE_HPP

#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/RedBlackTree.hpp
 */
template<typename T>
struct RedBlackTree {
	using size_type = std::size_t;
	using value_type = T;
	using const_reference = const value_type &;
	
public:
	struct Node;
	using node_ptr = Node *;
	using const_ptr = const Node * const;
	struct Node {
		value_type val;
		bool isred;
		node_ptr par;
		bool isr;
		node_ptr child[2] {nullptr, nullptr};
		Node(const_reference val, bool isred, node_ptr par, bool isr)
			: val(val), isred(isred), par(par), isr(isr) {}
	};
	
private:
	size_type n = 0;
	node_ptr root = nullptr;
	node_ptr e_ptr[2] {nullptr, nullptr};
	
public:
	RedBlackTree() = default;
	
	RedBlackTree(const RedBlackTree & rhs) {
		*this = rhs;
	}
	
	RedBlackTree(RedBlackTree && rhs) {
		*this = std::forward<RedBlackTree>(rhs);
	}
	
	~RedBlackTree() {
		clear();
	}
	
	RedBlackTree & operator =(const RedBlackTree & rhs) {
		if (this != &rhs) {
			clear();
			root = copy_dfs(rhs.root, nullptr);
			n = rhs.n;
			e_ptr[0] = e_ptr[1] = root;
			if (root) for (int i = 0; i < 2; ++i) while (e_ptr[i]->child[i]) e_ptr[i] = e_ptr[i]->child[i];
		}
		return *this;
	}
	
	RedBlackTree & operator =(RedBlackTree && rhs) {
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
		enumerate_dfs(root, elements);
		return elements;
	}
	
	node_ptr begin() const noexcept {
		return e_ptr[0];
	}
	
	node_ptr end() const noexcept {
		return nullptr;
	}
	
	node_ptr insert(const_reference x) {
		node_ptr p = nullptr, node = root;
		bool ef[2] {}, d = false;
		while (node) {
			d = node->val <= x;
			p = node;
			node = node->child[d];
			ef[!d] = true;
		}
		node = new Node{x, true, p, d};
		++n;
		if (!ef[0]) e_ptr[0] = node;
		if (!ef[1]) e_ptr[1] = node;
		if (!p) {
			root = node;
			node->isred = false;
			return node;
		}
		p->child[d] = node;
		if (!p->isred) return node;
		node_ptr g = p->par, u = g->child[!p->isr];
		if (!u) {
			if (node->isr == p->isr) {
				rotate(g, !p->isr);
				p->isred = false;
				g->isred = true;
				return node;
			}
			else {
				p->child[node->isr] = nullptr;
				g->child[!p->isr] = node;
				node->par = g;
				std::swap(g->val, node->val);
				if (e_ptr[0] == g) e_ptr[0] = node;
				if (e_ptr[1] == g) e_ptr[1] = node;
				return g;
			}
		}
		while (u->isred) {
			g->isred = true;
			p->isred = false;
			u->isred = false;
			const node_ptr cur = g;
			p = cur->par;
			if (!p) { cur->isred = false; break; }
			if (!p->isred) break;
			g = p->par;
			u = g->child[!p->isr];
			if (!u->isred) {
				if (cur->isr == p->isr) {
					rotate(g, !p->isr);
					p->isred = false;
					g->isred = true;
				}
				else {
					rotate(p, p->isr);
					rotate(g, !p->isr);
					cur->isred = false;
					g->isred = true;
				}
			}
		}
		return node;
	}
	
	node_ptr erase(const_reference x) noexcept {
		node_ptr q = find(x);
		if (q == end()) return end();
		return erase(q);
	}
	
	node_ptr erase(node_ptr q) noexcept {
		if (!q) return end();
		node_ptr ret = next(q);
		if (q->child[0]) {
			node_ptr p = q->child[0];
			while (p->child[1]) p = p->child[1];
			q->val = std::move(p->val);
			q = p;
		}
		if (e_ptr[0] == q) e_ptr[0] = next(q);
		if (e_ptr[1] == q) e_ptr[1] = prev(q);
		node_ptr ch = q->child[0] ? q->child[0] : q->child[1];
		if (ch) {
			q->val = std::move(ch->val);
			if (e_ptr[0] == ch) e_ptr[0] = q;
			if (e_ptr[1] == ch) e_ptr[1] = q;
			if (ret == ch) ret = q;
			q = ch;
		}
		node_ptr p = q->par;
		bool isred = q->isred, isr = q->isr;
		(p ? p->child[q->isr] : root) = nullptr;
		delete q;
		--n;
		if (!root || isred) return ret;
		while (p) {
			node_ptr c = p->child[!isr];
			if (c->isred) {
				rotate(p, isr);
				c->isred = false;
				p->isred = true;
				c = p->child[!isr];
			}
			node_ptr g = c->child[!isr];
			if (g && g->isred) {
				rotate(p, isr);
				c->isred = p->isred;
				g->isred = false;
				p->isred = false;
				break;
			}
			g = c->child[isr];
			if (g && g->isred) {
				rotate(c, !isr);
				rotate(p, isr);
				g->isred = p->isred;
				p->isred = false;
				break;
			}
			c->isred = true;
			if (p->isred) {
				p->isred = false;
				break;
			}
			isr = p->isr;
			p = p->par;
		}
		if (root) root->isred = false;
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
	
	node_ptr next(node_ptr q) const noexcept {
		return move(q, true);
	}
	
	node_ptr prev(node_ptr q) const noexcept {
		return move(q, false);
	}
	
private:
	node_ptr copy_dfs(const_ptr q, node_ptr r) {
		if (!q) return nullptr;
		node_ptr res = new Node(q->val, q->isred, r, q->isr);
		for (int i = 0; i < 2; ++i) res->child[i] = copy_dfs(q->child[i], res);
		return res;
	}
	
	void enumerate_dfs(const_ptr q, std::vector<value_type> & elements) const {
		if (!q) return;
		enumerate_dfs(q->child[0], elements);
		elements.emplace_back(q->val);
		enumerate_dfs(q->child[1], elements);
	}
	
	void rotate(node_ptr q, bool d) noexcept {
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

#endif // INCLUDE_GUARD_RED_BLACK_TREE_HPP