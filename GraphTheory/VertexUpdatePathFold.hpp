#ifndef INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP
#define INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/VertexUpdatePathFold.hpp
 */
template<typename T>
struct VertexUpdatePathFold {
	using value_type = T;
	using const_reference = const value_type &;
	using Graph = std::vector<std::vector<int>>;
	using F = std::function<value_type (const_reference, const_reference)>;
	
private:
	using int3 = std::tuple<int, int, int>;
	struct Node {
		value_type val, rval;
		int par;
		int dep; // 16bits(seg depth) 16bits(heavy-path depth)
		int childs[2];
		Node() = default;
		Node(value_type val) : val(val), rval(val), par(-1), childs{-1, -1} {};
		Node(int par, int seg_dep, int heavy_dep) : par(par), dep(comp_dep(seg_dep, heavy_dep)) {}
		Node(int par, int seg_dep, int heavy_dep, int lcld, int rcld)
			: par(par), dep(comp_dep(seg_dep, heavy_dep)), childs{lcld, rcld} {}
		static int comp_dep(int seg_dep, int heavy_dep) noexcept {
			return seg_dep << 16 | heavy_dep;
		}
		std::pair<int, int> decomp_dep() const noexcept {
			return {dep >> 16, dep & ((1 << 16) - 1)};
		}
		void set_dep(int seg_dep, int heavy_dep) noexcept {
			dep = comp_dep(seg_dep, heavy_dep);
		}
		void set_prop(int par, int seg_dep, int heavy_dep) noexcept {
			this->par = par;
			set_dep(seg_dep, heavy_dep);
		}
	};
	
	int n;
	const bool VERTEX;
	value_type id_elem;
	F f;
	std::vector<Node> nodes;
	std::vector<int> par_, depth_, heavy;
	
	void node_calc(int u) {
		nodes[u].val = f(nodes[nodes[u].childs[0]].val, nodes[nodes[u].childs[1]].val);
		nodes[u].rval = f(nodes[nodes[u].childs[1]].rval, nodes[nodes[u].childs[0]].rval);
	}
	
public:
	VertexUpdatePathFold(const Graph &g, int root, bool VERTEX, const_reference d_elem, const F &f)
		: n(g.size()), VERTEX(VERTEX), id_elem(id_elem), f(f) {
		nodes.reserve(2 * n);
		nodes.assign(n, {id_elem});
		build(g, root);
	}
	
	template<typename U>
	VertexUpdatePathFold(const Graph &g, int root, const std::vector<U> &dat, bool VERTEX, const_reference id_elem, const F &f)
		: n(g.size()), VERTEX(VERTEX), id_elem(id_elem), f(f) {
		nodes.reserve(2 * n);
		for (int i = 0; i < n; ++i) nodes.emplace_back(dat[i]);
		build(g, root);
	}
	
private:
	void build(const Graph &g, int root) {
		par_.assign(n, -1);
		depth_.assign(n, 0);
		heavy.assign(n, -1);
		std::vector<int> siz(n, 0);
		std::stack<std::pair<int, int>> stk;
		stk.emplace(root, 0);
		siz[root] = 0;
		while (stk.size()) {
			auto [u, idx] = stk.top(); stk.pop();
			if (idx == g[u].size()) {
				if (par_[u] != -1) siz[par_[u]] += ++siz[u];
			}
			else {
				stk.emplace(u, idx + 1);
				const int v = g[u][idx];
				if (v == par_[u]) continue;
				stk.emplace(v, 0);
				par_[v] = u;
				depth_[v] = depth_[u] + 1;
			}
		}
		int heavy_num = 0;
		std::vector<int> heavy_stk;
		heavy_stk.emplace_back(-(root + 1));
		nodes[root].dep = 0;
		stk.emplace(root, 0);
		while (stk.size()) {
			auto [u, idx] = stk.top(); stk.pop();
			if (idx == g[u].size()) {
				if (nodes[u].par != -1) {
					const int v = g[u][nodes[u].par];
					heavy_stk.emplace_back(v);
					nodes[v].dep = nodes[u].dep;
					stk.emplace(v, 0);
					continue;
				}
				if (g[u].size() == 0) siz[u] = 1;
				int st = static_cast<int>(heavy_stk.size()) - 1;
				while (heavy_stk[st] >= 0) --st;
				heavy_stk[st] = -heavy_stk[st] - 1;
				const int rootnum = n << 1;
				const int heavy_par = st == 0 ? rootnum : (heavy_stk[st - 1] >= 0 ? heavy_stk[st - 1] : -heavy_stk[st - 1] - 1);
				const int hs = static_cast<int>(heavy_stk.size()) - st;
				const int heavy_dep = nodes[heavy_stk[st]].dep;
				for (int i = 0; i < hs; ++i) heavy[heavy_stk[st + i]] = heavy_num;
				++heavy_num;
				std::vector<int> sum(hs + 1);
				sum[0] = 0;
				for (int i = 0; i < hs; ++i) sum[i + 1] = sum[i] + siz[heavy_stk[st + i]];
				std::stack<int3> merge_stk;
				merge_stk.emplace(0, hs, heavy_par);
				while (merge_stk.size()) {
					auto [l, r, p] = merge_stk.top(); merge_stk.pop();
					if (l == -1) { node_calc(p); continue; }
					const bool rchild = p < 0;
					if (p < 0) p = -p - 1;
					const int seg_dep = (p == heavy_par) ? 0 : nodes[p].decomp_dep().first + 1;
					auto merge = [&](int u, int v, int p, bool rchild, int seg_dep) -> int {
						const int self = nodes.size();
						nodes.emplace_back(p, seg_dep, heavy_dep, u, v);
						if (u != -1) nodes[u].set_prop(self, seg_dep + 1, heavy_dep);
						if (v != -1) nodes[v].set_prop(self, seg_dep + 1, heavy_dep);
						if (p != heavy_par) nodes[p].childs[rchild] = self;
						if (u != -1 && v != -1) node_calc(self);
						else merge_stk.emplace(-1, -1, self);
						return self;
					};
					if (r - l <= 2) {
						if (r - l == 1) {
							const int v = heavy_stk[l + st];
							nodes[v].set_prop(p, seg_dep, heavy_dep);
							if (p != heavy_par) nodes[p].childs[rchild] = v;
						}
						else merge(heavy_stk[l + st], heavy_stk[l + st + 1], p, rchild, seg_dep);
						continue;
					}
					const int m = lower_bound(sum.begin() + l + 1, sum.begin() + r + 1, (sum[r] + sum[l]) >> 1) - sum.begin() - 1;
					const int v = heavy_stk[m + st];
					const int top = nodes.size();
					if (m == l) {
						merge(v, -1, p, rchild, seg_dep);
						merge_stk.emplace(m + 1, r, -top - 1);
					}
					else if (m + 1 == r) {
						merge(-1, v, p, rchild, seg_dep);
						merge_stk.emplace(l, m, top);
					}
					else {
						if (sum[m] - sum[l] < sum[r] - sum[m + 1]) {
							merge(-1, -1, p, rchild, seg_dep);
							merge_stk.emplace(m + 1, r, -top - 1);
							merge(-1, v, top, false, seg_dep + 1);
							merge_stk.emplace(l, m, top + 1);
						}
						else {
							merge(-1, -1, p, rchild, seg_dep);
							merge_stk.emplace(l, m, top);
							merge(v, -1, top, true, seg_dep + 1);
							merge_stk.emplace(m + 1, r, -(top + 1) - 1);
						}
					}
				}
				while (heavy_stk.size() > st) heavy_stk.pop_back();
				if (heavy_par != rootnum) siz[heavy_par] += hs;
			}
			else {
				if (idx == 0) {
					siz[u] = 1;
					int mxc = 0;
					for (int i = 0; i < static_cast<int>(g[u].size()); ++i) {
						const int v = g[u][i];
						if (v != par_[u] && mxc < siz[v]) {
							nodes[u].par = i;
							mxc = siz[v];
						}
					}
				}
				stk.emplace(u, idx + 1);
				const int v = g[u][idx];
				if (v == par_[u] || idx == nodes[u].par) continue;
				heavy_stk.emplace_back(-(v + 1));
				nodes[v].dep = nodes[u].dep + 1;
				stk.emplace(v, 0);
			}
		}
	}

public:
	int size() const noexcept {
		return n;
	}
	
	int par(int v) const noexcept {
		assert(0 <= v && v < n);
		return par_[v];
	}
	
	int depth(int v) const noexcept {
		assert(0 <= v && v < n);
		return depth_[v];
	}
	
	void set(int v, const_reference x) noexcept {
		assert(VERTEX);
		assert(0 <= v && v < n);
		set_impl(v, x);
	}
	
	value_type get(int v) const noexcept {
		assert(VERTEX);
		assert(0 <= v && v < n);
		return get_impl(v);
	}
	
	void set(int u, int v, const_reference x) noexcept {
		assert(!VERTEX);
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		set_impl(par_[u] == v ? u : v, x);
	}
	
	value_type get(int u, int v) const noexcept {
		assert(!VERTEX);
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		return get_impl(par_[u] == v ? u : v);
	}
	
	value_type fold(int u, int v) const noexcept {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		value_type lv = id_elem, rv = id_elem;
		auto uup = [&](int step = -1, bool lret = true) {
			if (step == -1) {
				lv = f(lv, nodes[u].rval);
				step = nodes[u].decomp_dep().first + 1;
			}
			while (step--) {
				const int p = nodes[u].par;
				if (lret && nodes[p].childs[1] == u) lv = f(lv, nodes[nodes[p].childs[0]].rval);
				if (!lret && nodes[p].childs[0] == u) lv = f(lv, nodes[nodes[p].childs[1]].val);
				u = p;
			}
		};
		auto vup = [&](int step = -1, bool lret = true) {
			if (step == -1) {
				rv = f(nodes[v].val, rv);
				step = nodes[v].decomp_dep().first + 1;
			}
			while(step--) {
				const int p = nodes[v].par;
				if (lret && nodes[p].childs[1] == v) rv = f(nodes[nodes[p].childs[0]].val, rv);
				if (!lret && nodes[p].childs[0] == v) rv = f(nodes[nodes[p].childs[1]].rval, rv);
				v = p;
			}
		};
		while (nodes[u].decomp_dep().second > nodes[v].decomp_dep().second) uup();
		while (nodes[u].decomp_dep().second < nodes[v].decomp_dep().second) vup();
		while (heavy[u] != heavy[v]) uup(), vup();
		bool lright = depth_[u] > depth_[v];
		if (u == v) return VERTEX ? f(f(lv, nodes[u].val), rv) : f(lv, rv);
		if (VERTEX || lright) lv = f(lv, nodes[u].val);
		if (VERTEX || !lright) rv = f(nodes[v].val, rv);
		const int udep = nodes[u].decomp_dep().first, vdep = nodes[v].decomp_dep().first;
		if (udep > vdep) uup(udep - vdep, lright);
		if (udep < vdep) vup(vdep - udep, !lright);
		while (nodes[u].par != nodes[v].par) uup(1, lright), vup(1, !lright);
		return f(lv, rv);
	}
	
private:
	void set_impl(int v, const_reference x) noexcept {
		nodes[v].val = x;
		nodes[v].rval = x;
		for (int i = nodes[v].decomp_dep().first; i > 0; --i) node_calc(v = nodes[v].par);
	}
	
	value_type get_impl(int v) const noexcept {
		return nodes[v].val;
	}
};

#endif // INCLUDE_GUARD_VERTEX_UPDATE_PATH_FOLD_HPP