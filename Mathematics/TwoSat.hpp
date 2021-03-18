#ifndef INCLUDE_GUARD_TWO_SAT_HPP
#define INCLUDE_GUARD_TWO_SAT_HPP

#include "GraphTheory/StronglyConnectedComponents.hpp"

#include <vector>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/Mathematics/TwoSat.hpp
 */
struct TwoSat {
	using scc_type = StronglyConnectedComponents;
	
private:
	int n;
	typename scc_type::Graph g;
	std::vector<bool> ans;
	bool satisfiability = false;
	
public:
	explicit TwoSat(int n) : n(n), g(2 * n) {}
	
	int size() const noexcept {
		return n;
	}
	
	void add_clause(int x, bool xb, int y, bool yb) {
		assert(0 <= x && x < n);
		assert(0 <= y && y < n);
		g[x + (xb ? n : 0)].emplace_back(y + (yb ? 0 : n));
		g[y + (yb ? n : 0)].emplace_back(x + (xb ? 0 : n));
		satisfiability = false;
	}
	
	void add_clause(int x, bool xb) {
		assert(0 <= x && x < n);
		g[x + (xb ? n : 0)].emplace_back(x + (xb ? 0 : n));
		satisfiability = false;
	}
	
	bool build() {
		scc_type scc(g);
		ans.assign(n, false);
		satisfiability = false;
		for (int i = 0; i < n; ++i) {
			if (scc.rank(i) == scc.rank(i + n)) return false;
			if (scc.rank(i) > scc.rank(i + n)) ans[i] = true;
		}
		satisfiability = true;
		return true;
	}
	
	const std::vector<bool> & ans_list() const noexcept {
		assert(satisfiability);
		return ans;
	}
	
	bool get(int i) const noexcept {
		assert(satisfiability);
		assert(0 <= i && i < n);
		return ans[i];
	}
};

#endif // INCLUDE_GUARD_TWO_SAT_HPP