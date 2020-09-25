#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP
#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP

/*
last-updated: 2020/09/25

# 概要
完全永続配列

使用メモリ量が多い

添字の範囲を [0, n), m 分木としたとき、
	空間計算量: O(n log_m n)
	アクセス, 更新 時間/空間 計算量: O(log_m n)

任意の添字にアクセス可能だが負の添字には対応していない(ほぼ正しく動くが動作が遅そう)

# 解説
添字の大きさ順に並べる必要はないため、添字を m 進表記したときの下の桁から見ていき要素を並べる。
これにより、添字の範囲を事前に指定する必要がなくなって嬉しい

# 仕様
template<
	typename T: 扱うデータの型
	std::size_t M: 内部構造を M 分木にする
>

PersistentArray(const_reference def_val = 0)
	時間/空間 計算量: Θ(1)
	要素数が無限の永続配列を作成, 初期値は def_val

PersistentArray set(size_type k, const_reference x) const
	時間計算量: O(m log_m k)
	空間計算量: Θ(m log_m k)
	k 番目(0 \leq k) の要素を x に書き換えた配列を返す

void destructive_set(size_type k, const_reference x)
	時間計算量: Θ(log_m k)
	空間計算量: O(m log_m k)
	k 番目(0 \leq k) の要素を x に書き換える
	操作前の配列にアクセスできなくなるので注意(過去の状態にアクセスした場合の動作は未定義)
	
const_reference get(size_type k) const
	時間計算量: Θ(log_m n)
	空間計算量: Θ(1)
	k 番目(0 \leq k) の要素を返す

# 参考
https://trap.jp/post/663/, 2020/04/10
https://qiita.com/hotman78/items/9c643feae1de087e6fc5, 2020/09/25
*/

#include <memory>
#include <utility>

template<typename T, std::size_t M>
struct PersistentArray {
	static_assert(M > 0);
	using value_type = T;
	using const_reference = const value_type &;
	using size_type = std::size_t;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	using node_ptr = Node *;
	using const_ptr = const Node *;
	struct Node {
		sptr_type childs[M];
		value_type val;
		Node(const_reference val) : val(val) {}
	};
	
private:
	sptr_type root;
	value_type def_val;
	
private:
	PersistentArray(sptr_type && root, const_reference def_val) : root(root), def_val(def_val) {}
	
public:
	PersistentArray(const_reference def_val = 0) : root(nullptr), def_val(def_val) {}
	
	PersistentArray set(size_type k, const_reference x) const {
		const_ptr node = root.get();
		sptr_type new_root = std::make_shared<Node>(k == 0 ? x : (node ? node->val : def_val));
		node_ptr new_node = new_root.get();
		for (; k > 0; k /= M) {
			const size_type m = k % M;
			if (node) {
				for (size_type i = 0; i < M; ++i) {
					if (i != m) new_node->childs[i] = node->childs[i];
				}
				new_node->childs[m] = std::make_shared<Node>(k < M ? x : (node->childs[m] ? node->childs[m]->val : def_val));
				node = node->childs[m].get();
			}
			else {
				new_node->childs[m] = std::make_shared<Node>(k < M ? x : def_val);
			}
			new_node = new_node->childs[m].get();
		}
		if (node) {
			for (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];
		}
		return {std::move(new_root), def_val};
	}
	
	void destructive_set(size_type k, const_reference x) {
		if (!root) root = std::make_shared<Node>(k == 0 ? x : def_val);
		node_ptr node = root.get();
		for (; k >= M; k /= M) {
			const size_type m = k % M;
			if (!node->childs[m]) node->childs[m] = std::make_shared<Node>(def_val);
			node = node->childs[m].get();
		}
		if (node->childs[k]) node->childs[k]->val = x;
		else node->childs[k] = std::make_shared<Node>(x);
	}
	
	const_reference get(size_type k) const {
		const_ptr node = root.get();
		while (k > 0 && node) {
			node = node->childs[k % M].get();
			k /= M;
		}
		return k == 0 && node ? node->val : def_val;
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP