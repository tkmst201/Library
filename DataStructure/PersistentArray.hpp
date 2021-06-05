#ifndef INCLUDE_GUARD_PERSISTENT_ARRAY_HPP
#define INCLUDE_GUARD_PERSISTENT_ARRAY_HPP

#include <memory>
#include <utility>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/PersistentArray.hpp
 */
template<typename T, int M>
struct PersistentArray {
	static_assert(M > 1);
	
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
	PersistentArray(const sptr_type & root, const_reference def_val) : root(root), def_val(def_val) {}
	
public:
	explicit PersistentArray(const_reference def_val = 0) : root(nullptr), def_val(def_val) {}
	
	PersistentArray set(size_type k, const_reference x) const {
		const_ptr node = root.get();
		sptr_type new_root = std::make_shared<Node>(k == 0 ? x : (node ? node->val : def_val));
		node_ptr new_node = new_root.get();
		for (; k > 0; k /= M) {
			const size_type m = k % M;
			if (node) {
				for (size_type i = 0; i < M; ++i) if (i != m) new_node->childs[i] = node->childs[i];
				new_node->childs[m] = std::make_shared<Node>(k < M ? x : (node->childs[m] ? node->childs[m]->val : def_val));
				node = node->childs[m].get();
			}
			else new_node->childs[m] = std::make_shared<Node>(k < M ? x : def_val);
			new_node = new_node->childs[m].get();
		}
		if (node) for (size_type i = 0; i < M; ++i) new_node->childs[i] = node->childs[i];
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
	
	const_reference get(size_type k) const noexcept {
		const_ptr node = root.get();
		while (k > 0 && node) {
			node = node->childs[k % M].get();
			k /= M;
		}
		return k == 0 && node ? node->val : def_val;
	}
};

#endif // INCLUDE_GUARD_PERSISTENT_ARRAY_HPP