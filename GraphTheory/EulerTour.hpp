#ifndef INCLUDE_GUARD_EULER_TOUR_HPP
#define INCLUDE_GUARD_EULER_TOUR_HPP

#include <vector>
#include <cassert>
#include <stack>
#include <utility>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/EulerTour.hpp
 */
template<bool EDGE>
struct EulerTour {
	using size_type = std::size_t;
	using Graph = std::vector<std::vector<int>>;
	
private:
	int n, root;
	std::vector<int> in_, out_, par_, g_idx;
	
public:
	EulerTour(const Graph & g, int root = 0)
		: n(g.size()), root(root), in_(size(), -1), out_(size(), -1), par_(n, -1), g_idx(n << 1, -1) {
		std::stack<std::pair<int, int>> stk;
		int num = 0;
		in_[root] = num++;
		stk.emplace(root, 0);
		while (!stk.empty()) {
			const auto [u, i] = stk.top();
			stk.pop();
			if (i < g[u].size()) {
				const int v = g[u][i];
				assert(0 <= v && v < n);
				assert(v != u);
				stk.emplace(u, i + 1);
				if (v == par_[u]) g_idx[u << 1 | 1] = i;
				else {
					in_[v] = num++;
					par_[v] = u;
					g_idx[v << 1] = i;
					stk.emplace(v, 0);
				}
			}
			else {
				out_[u] = num;
				if (EDGE) ++num;
			}
		}
	}
	
	size_type size() const noexcept {
		return EDGE ? n << 1 : n;
	}
	
	int par(int k) const noexcept {
		assert(0 <= k && k < n);
		return par_[k];
	}
	
	int in(int k) const noexcept {
		assert(0 <= k && k < n);
		return in_[k];
	}
	
	int out(int k) const noexcept {
		assert(0 <= k && k < n);
		return out_[k];
	}
	
	std::pair<int, int> par_from(int k) const noexcept {
		assert(0 <= k && k < n);
		return {par_[k], g_idx[k << 1]};
	}
	
	int par_to(int k) const noexcept {
		assert(0 <= k && k < n);
		return g_idx[k << 1 | 1];
	}
};

#endif // INCLUDE_GUARD_EULER_TOUR_HPP