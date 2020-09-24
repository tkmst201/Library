#ifndef INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP
#define INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP

/*
last-updated: 2020/09/24

# 概要
動的セグメント木(非可換演算対応)

モノイドを扱う

添字の大きさの最大値を n 、代入する添字の種類数を m とすると
	空間計算量: O(n log m)
	1 クエリあたり 時間計算量: O(log m)
でセグメント木の操作が行える

TODO: 二分探索の実装

# 解説
必要なときに枝を伸ばしていき動的にセグメント木を構築する

葉にのみ配列の値を、節には部分木を fold した値を持たせている
葉の子に値を追加するときは、まず子に自身の値を移動させる

演算が可換な場合は部分木の fold した値を別に持たせることにより 空間計算量: O(N) が達成できる(たぶん実装も楽そう)

# 仕様
DynamicSegmentTree(size_type n, const_reference id_elem, const F & f)
	時間/空間 計算量: Θ(1)
	要素数 n, 単位元 id_elem, 二項演算 f で初期化

void clear()
	時間計算量: O(n)
	全ノードを解放する(= 全ての値を id_elem)

size_type size() const noexcept
	時間/空間 計算量: Θ(1)
	要素数を返す(\neq 内部のノード数)

void set(size_type i, const_reference x)
	時間/空間 計算量: O(log n)
	i 番目(0 \leq i < n) の要素に x を代入

const_reference get(size_type i) const
	時間計算量: O(log n)
	i 番目(0 \leq i < n) の要素を返す

value_type fold(size_type l, size_type r) const
	時間計算量: O(log n)
	[l, r) (0 \leq l \leq r \leq n) を fold した結果を返す
	l = r のときは id_elem を返す

const_reference fold_all() const
	時間計算量: Θ(1)
	fold(0, n) の結果を返す

private:
std::stack<node_ptr> find(size_type k)
	時間計算量: O(log n)
	根から k 番目の要素のノードの経路を返す(端点含む)
	k 番目の要素のノードが存在しない場合は k 番目の要素に最も近いノードまでの経路

# 参考
https://kazuma8128.hatenablog.com/entry/2018/11/29/093827, 2020/09/24
*/

#include <functional>
#include <cassert>
#include <stack>

template<typename T>
struct DynamicSegmentTree {
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	using F = std::function<value_type(const_reference, const_reference)>;
	
private:
	struct Node;
	using node_ptr = Node *;
	struct Node {
		value_type val;
		size_type pos;
		node_ptr l, r;
		Node(const_reference val, size_type pos) : val(val), pos(pos), l(nullptr), r(nullptr) {}
	};
	
private:
	size_type n, n_, log_n;
	value_type id_elem;
	F f;
	node_ptr root;
	
public:
	DynamicSegmentTree(size_type n, const_reference id_elem, const F & f)
		: n(n), id_elem(id_elem), f(f), root(nullptr) {
		n_ = 1;
		log_n = 0;
		while (n_ < n) n_ <<= 1, ++log_n;
	}
	
	~DynamicSegmentTree() {
		clear();
	}
	
	void clear() {
		std::stack<node_ptr> stk;
		stk.emplace(root);
		while (!stk.empty()) {
			node_ptr node = stk.top();
			stk.pop();
			if (node->r) stk.emplace(node->r);
			if (node->l) stk.emplace(node->l);
			delete node;
		}
		root = nullptr;
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type k, const_reference x) {
		assert(k < size());
		if (!root) {
			root = new Node{x, k};
			return;
		}
		
		std::stack<node_ptr> stk = find(k);
		if (stk.top()->pos == k) {
			stk.top()->val = x;
			stk.pop();
		}
		else if (stk.top()->l || stk.top()->r) {
			const node_ptr node = stk.top();
			if (k >> (log_n - stk.size()) & 1) node->r = new Node{x, k};
			else node->l = new Node{x, k};
		}
		else {
			while (true) {
				const node_ptr node = stk.top();
				
				const bool move_r = node->pos >> (log_n - stk.size()) & 1;
				const bool to_r = k >> (log_n - stk.size()) & 1;
				if (move_r) {
					node->r = new Node{node->val, node->pos};
					stk.emplace(node->r);
					if (!to_r) {
						node->l = new Node{x, k};
						break;
					}
				}
				else {
					node->l = new Node{node->val, node->pos};
					stk.emplace(node->l);
					if (to_r) {
						node->r = new Node{x, k};
						break;
					}
				}
			}
			stk.pop();
		}
		
		while (!stk.empty()) {
			const node_ptr node = stk.top();
			stk.pop();
			
			node->val = node->l ? node->l->val : id_elem;
			if (node->r) node->val = f(node->val, node->r->val);
		}
	}
	
	const_reference get(size_type k) const {
		assert(k < n);
		if (!root) return id_elem;
		const std::stack<node_ptr> hist = find(k);
		if (hist.top()->pos == k) return hist.top()->val;
		return id_elem;
	}
	
private:
	std::stack<node_ptr> find(size_type k) const {
		std::stack<node_ptr> res;
		if (!root) return res;
		node_ptr node = root;
		res.emplace(node);
		for (size_type i = log_n; i > 0; --i) {
			if (k >> (i - 1) & 1) {
				if (!node->r) break;
				node = node->r;
				res.emplace(node);
			}
			else {
				if (!node->l) break;
				node = node->l;
				res.emplace(node);
			}
		}
		return res;
	}
	
public:
	const_reference fold_all() const {
		if (!root) return id_elem;
		return root->val;
	}
	
	value_type fold(size_type l, size_type r) const {
		assert(l <= r);
		assert(r <= size());
		if (l == r || !root) return id_elem;
		
		struct Data {
			node_ptr node;
			size_type l, r;
			Data(node_ptr node, size_type l, size_type r) : node(node), l(l), r(r) {}
		};
		
		value_type res = id_elem;
		std::stack<Data> stk;
		stk.emplace(root, 0, n_);
		
		while (!stk.empty()) {
			const Data dat = stk.top();
			stk.pop();
			if (!dat.node->l && !dat.node->r) {
				if (l <= dat.node->pos && dat.node->pos < r) res = f(res, dat.node->val);
			}
			else if (l <= dat.l && dat.r <= r) {
				res = f(res, dat.node->val);
			}
			else {
				const size_type m = dat.l + ((dat.r - dat.l) >> 1);
				if (dat.node->r && m < r) stk.emplace(dat.node->r, m, dat.r);
				if (dat.node->l && m > l) stk.emplace(dat.node->l, dat.l, m);
			}
		}
		
		return res;
	}
};

#endif // INCLUDE_GUARD_DYNAMIC_SEGMENT_TREE_HPP