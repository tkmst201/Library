#ifndef INCLUDE_GUARD_RED_BLACK_TREE_HPP
#define INCLUDE_GUARD_RED_BLACK_TREE_HPP

/*
last-updated: 2020/08/30

全てのノードに値を持たせる insert/delete ベースの赤黒木
操作の前後で安定

TODO: 葉に値を持たせるような insert/erase ベース(merge/split 対応) の赤黒木の作成(できるかはわからない)

# 仕様
RedBrackTree() :
	時間計算量: O(1)
	空の RedBrackTree を作成

RedBrackTree(const RedBrackTree & rhs) :
	時間計算量: O(rhs.n)
	コンストラクタ初期化

~RedBrackTree() :
	時間計算量: O(n)
	デストラクタ
	clear() を呼ぶ

size_type size() const noexcept :
	時間計算量: O(1)
	要素数を返す

bool empty() const noexcept :
	時間計算量: O(1)
	要素が空であるかどうか判定する

void clear() :
	時間計算量: O(n)
	全ての要素を delete する

node_ptr begin() const :
	時間計算量: O(1)
	最も小さい要素のポインタを返す

node_ptr end() const :
	時間計算量: O(1)
	最も大きい要素の次のポインタを返す

node_ptr next(node_ptr node) const :
	時間計算量: O(log n), ならし O(1)
	node の次に大きい要素のポインタを返す

node_ptr prev(node_ptr node) const :
	時間計算量: O(log n), ならし O(1)
	node の次に小さい要素のポインタを返す

node_ptr insert(const_reference x) :
	時間計算量: O(log n)
	値 x を挿入する

node_ptr lower_bound(const_reference x) const :
	時間計算量: O(log n)
	x 以上で先頭の要素を返す

node_ptr upper_bound(const_reference x) const :
	時間計算量: O(log n)
	x より大きい先頭の要素を返す

node_ptr find(const_reference x) const :
	時間計算量: O(log n)
	x と等しい先頭の要素を返す

node_ptr erase(const_reference x) :
	時間計算量: O(log n)
	値 x を持つ要素を 1 つ削除する
	複数存在する場合は一番先頭の要素
	削除した要素の次に大きい要素を返す

node_ptr erase(node_ptr node) :
	時間計算量: O(log n)
	node が指す要素を削除する
	削除した要素の次に大きい要素を返す

bool check() const : 赤黒木の条件を満たしているか確認する
void debug() : 木を出力する(int, std::pair) に対応

# 参考
https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8, 2020/08/27
http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html, 2020/08/27
http://www.nct9.ne.jp/m_hiroi/light/pyalgo16.html, 2020/08/27
*/

// #include <iostream>

#include <cassert>
#include <utility>

template<typename T>
struct RedBlackTree {
private:
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
public:
	struct Node;
	using node_ptr = Node *;
	
public:
	struct Node {
		value_type val;
		bool isred;
		node_ptr child[2];
		node_ptr par;
		bool isright;
		
		Node(const_reference val, bool isred, node_ptr child_l, node_ptr child_r, node_ptr par, bool isright)
			: val(val), isred(isred), child{child_l, child_r}, par(par), isright(isright) {}
	};
	
private:
	node_ptr root = nullptr;
	node_ptr begin_ptr = nullptr, end_ptr = nullptr;
	size_type n = 0;
	
public:
	RedBlackTree() = default;
	
	RedBlackTree(const RedBlackTree & rhs) {
		*this = rhs;
	}
	
	RedBlackTree & operator =(const RedBlackTree & rhs) {
		auto dfs = [&](auto &&self, node_ptr node, node_ptr par) -> node_ptr {
			if (!node) return nullptr;
			node_ptr ret = new Node{node->val, node->isred, nullptr, nullptr, par, node->isright};
			if (node == rhs.begin_ptr) begin_ptr = ret;
			if (node == rhs.end_ptr) end_ptr = ret;
			ret->child[0] = self(self, node->child[0], ret);
			ret->child[1] = self(self, node->child[1], ret);
			return ret;
		};
		root = dfs(dfs, rhs.root, nullptr);
		n = rhs.n;
		return *this;
	}
	
	~RedBlackTree() {
		clear();
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	bool empty() const noexcept {
		return size() == 0;
	}
	
	void clear() {
		node_ptr cur = root;
		while (cur) {
			if (cur->child[0]) cur = cur->child[0];
			else if (cur->child[1]) cur = cur->child[1];
			else {
				node_ptr par = cur->par;
				if (par) par->child[cur->isright] = nullptr;
				delete cur;
				cur = par;
			}
		}
		root = nullptr;
	}
	
	node_ptr begin() const {
		return begin_ptr;
	}
	
	node_ptr end() const {
		return nullptr;
	}
	
	node_ptr next(node_ptr node) const {
		return node != end() ? move(node, true) : begin_ptr;
	};
	
	node_ptr prev(node_ptr node) const {
		return node != end() ? move(node, false) : end_ptr;
	}
	
	node_ptr insert(const_reference x) {
		if (!root) {
			root = new Node{x, false, nullptr, nullptr, nullptr, false};
			++n;
			begin_ptr = end_ptr = root;
			return root;
		}
		
		node_ptr par = root, ins = nullptr;
		bool move_only[2] {true, true};
		while (!ins) {
			const bool nex_r = par->val <= x;
			move_only[!nex_r] = false;
			if (par->child[nex_r]) par = par->child[nex_r];
			else {
				ins = new Node{x, true, nullptr, nullptr, par, nex_r};
				++n;
				if (move_only[0]) begin_ptr = ins;
				if (move_only[1]) end_ptr = ins;
				par->child[nex_r] = ins;
			}
		}
		if (!par->isred) return ins;
		
		// (ins, par) = (red, red), par \neq root
		node_ptr grand = par->par; // grand = black
		node_ptr uncle = grand->child[!par->isright];
		if (!uncle) {
			if (ins->isright == par->isright) {
				rotate(grand, !par->isright);
				par->isred = false;
				grand->isred = true;
			}
			else {
				const bool isflip = par->isright;
				
				grand->child[par->isright] = nullptr;
				par->child[ins->isright] = nullptr;
				
				ins->isred = false;
				ins->par = grand->par;
				ins->isright = grand->isright;
				ins->child[isflip] = par;
				ins->child[!isflip] = grand;
				
				par->par = ins;
				par->isright = isflip;
				
				grand->isred = true;
				grand->par = ins;
				grand->isright = !isflip;
				
				if (ins->par) ins->par->child[ins->isright] = ins;
				else root = ins;
			}
			return ins;
		}
		
		// uncle = red
		grand->isred = true;
		par->isred = false;
		uncle->isred = false;
		
		while (true) {
			// grand = red, exists(par(grand)) = ?
			node_ptr cur = grand;
			par = cur->par;
			if (!par) {
				cur->isred = false;
				break;
			}
			if (!par->isred) break;
			grand = par->par;
			uncle = grand->child[!par->isright];
			
			// (cur, par) = (red, red), grand = black, uncle = ?
			if (!uncle->isred) {
				if (cur->isright == par->isright) {
					rotate(grand, !par->isright);
					par->isred = false;
					grand->isred = true;
				}
				else {
					rotate(par, par->isright);
					rotate(grand, !par->isright);
					cur->isred = false;
					grand->isred = true;
				}
				break;
			}
			
			grand->isred = true;
			par->isred = false;
			uncle->isred = false;
		}
		return ins;
	}
	
	node_ptr lower_bound(const_reference x) const {
		node_ptr node = root;
		if (!node) return end();
		while (true) {
			bool cmp = x <= node->val;
			if (node->child[!cmp]) node = node->child[!cmp];
			else break;
		}
		if (node->val < x) return next(node);
		return node;
	}
	
	node_ptr upper_bound(const_reference x) const {
		node_ptr node = root;
		if (!node) return end();
		while (true) {
			bool cmp = x < node->val;
			if (node->child[!cmp]) node = node->child[!cmp];
			else break;
		}
		if (x <= node->val) return next(node);
		return node;
	}
	
	node_ptr find(const_reference x) const {
		node_ptr cur = lower_bound(x);
		if (cur != end() && cur->val == x) return cur;
		return end();
	}
	
	node_ptr erase(const_reference x) {
		return erase(find(x));
	}
	
	node_ptr erase(node_ptr node) {
		if (node == end()) return end();
		node_ptr ret = next(node);
		if (node->child[0]) {
			node_ptr rep = node->child[0];
			while (rep->child[1]) rep = rep->child[1];
			node->val = std::move(rep->val);
			erase_sub(rep);
		}
		else erase_sub(node);
		return ret;
	}
	
	bool check() const {
		if (!root) return true;
		assert(!root->isred);
		
		size_type tmp = -1;
		
		auto dfs = [&](auto &&self, node_ptr node, node_ptr par, size_type cnt) -> node_ptr {
			if (!node) {
				++cnt;
				if (tmp == -1) tmp = cnt;
				assert(cnt == tmp);
				return node;
			}
			
			if (!node->isred) ++cnt;
			
			if (node->child[0]) {
				assert(node->child[0]->val <= node->val);
				assert(!node->isred || !node->child[0]->isred);
				if (par) assert(node == par->child[node->isright]);
				else assert(root == node);
			}
			self(self, node->child[0], node, cnt);
			
			if (node->child[1]) {
				assert(node->child[1]->val >= node->val);
				assert(!node->isred || !node->child[1]->isred);
				if (par) assert(node == par->child[node->isright]);
				else assert(root == node);
			}
			self(self, node->child[1], node, cnt);
			return node;
		};
		dfs(dfs, root, nullptr, 0);
		return true;
	}
	
private:
	void rotate(node_ptr node, bool rotR) {
		node_ptr u = node->child[!rotR];
		node_ptr b = u->child[rotR];
		
		if (node->par) node->par->child[node->isright] = u;
		else root = u;
		
		u->par = node->par;
		u->isright = node->isright;
		u->child[rotR] = node;
		
		node->par = u;
		node->isright = rotR;
		node->child[!rotR] = b;
		
		if (b) {
			b->par = node;
			b->isright = !rotR;
		}
	}
	
	node_ptr move(node_ptr node, bool isnext) const {
		if (node->child[isnext]) {
			node = node->child[isnext];
			while (node->child[!isnext]) node = node->child[!isnext];
		}
		else {
			while (node && (!node->isright ^ isnext)) node = node->par;
			if (node) node = node->par;
		}
		return node;
	}
	
	void erase_sub(node_ptr node) {
		// |node->child| \leq 1
		bool isred = node->isred;
		bool isright = node->isright;
		
		node_ptr par = node->par;
		for (size_type i = 0; i < 2; ++i) {
			if (node->child[i]) {
				if (par) par->child[node->isright] = node->child[i];
				else root = node->child[i];
				node->child[i]->par = par;
				node->child[i]->isright = node->isright;
			}
		}
		if (!node->child[0] && !node->child[1]) {
			if (par) par->child[node->isright] = nullptr;
			else root = nullptr;
		}
		delete node;
		--n;
		if (isred) return;
		
		while (par) {
			// exists(par->child[!isright]) = true
			// isright = -1-subtree
			node_ptr b = par->child[!isright];
			
			if (b->isred) {
				// par = black, b = red
				rotate(par, isright);
				b->isred = false;
				par->isred = true;
				b = par->child[!isright];
			}
			
			node_ptr tar = b->child[!isright];
			if (tar && tar->isred) {
				rotate(par, isright);
				b->isred = par->isred;
				par->isred = false;
				tar->isred = false;
				break;
			}
			
			tar = b->child[isright];
			if (tar && tar->isred) {
				rotate(b, !isright);
				rotate(par, isright);
				tar->isred = par->isred;
				par->isred = false;
				break;
			}
			b->isred = true;
			if (par->isred) {
				par->isred = false;
				break;
			}
			
			isright = par->isright;
			par = par->par;
		}
		
		if (root) root->isred = false;
	}
	
public:
	// void debug() {
	// 	if (!root) {
	// 		std::cout << "debug : empty" << std::endl;
	// 		return;
	// 	}
	// 	auto dfs = [&](auto &&self, node_ptr cur) -> void {
	// 		if (!root) std::cout << "empty" << std::endl;
	// 		if (!cur) return;
			
	// 		std::cout << "val = " << cur->val << ", color = " << (cur->isred ? "red" : "black");
	// 		if (cur->par) std::cout << ", par = " << cur->par->val << ", " << (cur->isright ? "right" : "left");
			
	// 		std::cout << ", leftval = ";
	// 		if (!cur->child[0]) std::cout << "null";
	// 		else std::cout << cur->child[0]->val;
			
	// 		std::cout << ", rightval = ";
	// 		if (!cur->child[1]) std::cout << "null";
	// 		else std::cout << cur->child[1]->val;
	// 		std::cout << std::endl;
			
	// 		if (cur->child[0]) {
	// 			std::cout << "move left" << std::endl;
	// 			self(self, cur->child[0]);
	// 		}
			
	// 		if (cur->child[1]) {
	// 			std::cout << "move right" << std::endl;
	// 			self(self, cur->child[1]);
	// 		}
			
	// 		if (cur->par) std::cout << "move par -> val = " << cur->par->val << std::endl;
	// 	};
	// 	dfs(dfs, root);
	// }
	
	// void debug() {
	// 	if (!root) {
	// 		std::cout << "debug : empty" << std::endl;
	// 		return;
	// 	}
	// 	auto dfs = [&](auto &&self, node_ptr cur) -> void {
	// 		if (!root) std::cout << "empty" << std::endl;
	// 		if (!cur) return;
			
	// 		std::cout << "val = " << "(" << cur->val.first << ", " << cur->val.second << ")" << ", color = " << (cur->isred ? "red" : "black");
	// 		if (cur->par) std::cout << ", par = (" << cur->par->val.first << ", " << cur->par->val.second << ")" << ", " << (cur->isright ? "right" : "left");
			
	// 		std::cout << ", leftval = ";
	// 		if (!cur->child[0]) std::cout << "null";
	// 		else std::cout << "(" << cur->child[0]->val.first << ", " << cur->child[0]->val.second << ")";
			
	// 		std::cout << ", rightval = ";
	// 		if (!cur->child[1]) std::cout << "null";
	// 		else std::cout << "(" << cur->child[1]->val.first << ", " << cur->child[1]->val.second << ")";
	// 		std::cout << std::endl;
			
	// 		if (cur->child[0]) {
	// 			std::cout << "move left" << std::endl;
	// 			self(self, cur->child[0]);
	// 		}
			
	// 		if (cur->child[1]) {
	// 			std::cout << "move right" << std::endl;
	// 			self(self, cur->child[1]);
	// 		}
			
	// 		if (cur->par) std::cout << "move par -> val = " <<  "(" << cur->par->val.first << ", " << cur->par->val.second << ")"<< std::endl;
	// 	};
	// 	dfs(dfs, root);
	// }
};

#endif // INCLUDE_GUARD_RED_BLACK_TREE_HPP