#ifndef INCLUDE_GUARD_TWO_SAT_HPP
#define INCLUDE_GUARD_TWO_SAT_HPP

/*
last-updated: 2020/09/10

# 仕様
TwoSat(size_type n) :
	時間計算量: Θ(n)
	n 変数を対象として構築

void add_clause(size_type x, bool xb, size_type y, bool yb) :
	時間計算量: Θ(1)
	(x = xb) v (y = yb) を加える

void add_clause(size_type x, bool xb) :
	時間計算量: Θ(1)
	x = xb を加える

bool build() :
	時間計算量: Θ(n)
	全ての条件を満たすような変数の値の組み合わせを求める
	そのような組み合わせが存在するならば true, 存在しないのならば false を返す

const std::vector<bool> & get_answer() const :
	時間計算量: Θ(1)
	全ての条件を満たすような変数の真偽値が入っているテーブルを返す

bool get(size_type i) :
	時間計算量: Θ(1)
	全ての条件を満たすような変数の値の組み合わせで、変数 i の真偽値を返す

# 参考
"AC Library" https://atcoder.jp/posts/517m, 2020/09/10
*/

#include "GraphTheory/StronglyConnectedComponents.hpp"

#include <vector>
#include <cassert>

struct TwoSat {
	using size_type = std::size_t;
	
private:
	size_type n;
	StronglyConnectedComponents scc;
	std::vector<bool> ans;
	bool isbuilt, satisfiability;
	
public:
	TwoSat(size_type n) : n(n), scc(2 * n + 2) {}
	
	void add_clause(size_type x, bool xb, size_type y, bool yb) {
		assert(x < n);
		assert(y < n);
		scc.add_edge(x + (xb ? n : 0), y + ((yb^1) ? n : 0));
		scc.add_edge(y + (yb ? n : 0), x + ((xb^1) ? n : 0));
		isbuilt = false;
	}
	
	void add_clause(size_type x, bool xb) {
		assert(x < n);
		scc.add_edge(x + (xb ? n : 0), 2*n);
		scc.add_edge(x + (xb ? n : 0), 2*n + 1);
		scc.add_edge(2*n, x + ((xb^1) ? n : 0));
		scc.add_edge(2*n + 1, x + ((xb^1) ? n : 0));
	}
	
	bool build() {
		scc.build(false);
		ans.assign(n, false);
		satisfiability = false;
		if (scc.get_rank(2*n) == scc.get_rank(2*n + 1)) return false;
		for (size_type i = 0; i < n; ++i) {
			if (scc.get_rank(i) == scc.get_rank(i + n)) return false;
			if (scc.get_rank(i) > scc.get_rank(i + n)) ans[i] = true;
		}
		isbuilt = true;
		satisfiability = true;
		return true;
	}
	
	const std::vector<bool> & get_answer() const {
		assert(isbuilt);
		assert(satisfiability);
		return ans;
	}
	
	bool get(size_type i) const {
		assert(isbuilt);
		assert(satisfiability);
		assert(i < n);
		return ans[i];
	}
};

#endif // INCLUDE_GUARD_TWO_SAT_HPP