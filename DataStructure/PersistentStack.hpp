#ifndef INCLUDE_GUARD_PERSISTENT_STACK_HPP
#define INCLUDE_GUARD_PERSISTENT_STACK_HPP

/*
last-updated: 2020/04/15 unverified

永続スタック

# 仕様
PersistentStack() :
	時間計算量: Θ(1)
	空の stack を作成する

bool empty() const :
	時間計算量: Θ(1)
	空であるかどうか判定する

PersistentStack push(value_type x) const :
	時間計算量: Θ(1)
	値 x を追加した stack を作成する

PersistentStack pop() const :
	時間計算量: Θ(1)
	一番最後に入れた要素を削除した stack を作成

const_reference top() const :
	時間計算量: Θ(1)
	最後に入れた要素を返す

# 参考
http://noshi91.hatenablog.com/entry/2019/02/04/175100, 2020/04/10
*/

#include <vector>
#include <memory>
#include <cassert>

template<typename T>
struct PersistentStack {
public:
	using value_type = T;
	using const_reference = const value_type &;
	
private:
	struct Node;
	using sptr_type = std::shared_ptr<Node>;
	struct Node {
		value_type value;
		sptr_type prev;
		Node(value_type value, sptr_type prev) : value(value), prev(prev) {}
	};
	
public:
	PersistentStack() = default;
	
	bool empty() const { return !static_cast<bool>(top_node); }
	
	PersistentStack push(const value_type &x) const { return PersistentStack{ std::make_shared<Node>(x, top_node) }; }
	
	PersistentStack pop() const {
		assert(!empty());
		return PersistentStack{top_node->prev};
	}
	
	value_type top() const {
		assert(!empty());
		return top_node->value;
	}
	
private:
	sptr_type top_node;
	PersistentStack(sptr_type prev) : top_node(prev) {}
};

#endif // INCLUDE_GUARD_PERSISTENT_STACK_HPP