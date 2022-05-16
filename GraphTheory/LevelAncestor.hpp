#ifndef INCLUDE_GUARD_LEVEL_ANCESTOR_HPP
#define INCLUDE_GUARD_LEVEL_ANCESTOR_HPP

#include <vector>
#include <cassert>
#include <stack>
#include <utility>
#include <map>

#include "Mathematics/bit_operation.hpp"

/**
 * @brief https://tkmst201.github.io/Library/GraphTheory/LevelAncestor.hpp
 */
template<int S, int B>
struct LevelAncestor {
	static_assert(1 <= B && B <= 3);
	static_assert(2 <= S && S <= (1ull << B));
	using Graph = std::vector<std::vector<int>>;
	using size_type = std::size_t;
	
private:
	int n, logn;
	std::vector<int> depth_, jump, data, ladnum, utreeid, rdict, rdst;
	std::vector<std::vector<int>> ladder, jumpp;
	std::vector<std::vector<int>> microdb;
	
public:
	LevelAncestor(const Graph & g, int root = 0) : n(g.size()) {
		assert(0 <= root && root < n);
		std::vector<int> par(n, -1), jumps;
		depth_.assign(n, 0);
		jump.assign(n, n);
		data.assign(n, 1);
		
		// calculate Micro-Tree shape/query, |Micro-Tree| < S
		int stk1[2 * S], stk2[S], stkp1 = 0;
		std::map<int, int> micromap;
		utreeid.assign(n, -1);
		rdict.reserve(n);
		rdst.reserve(n);
		auto build_micro = [&](int r) {
			const int jp = jump[par[r]], utid = rdst.size();
			rdst.emplace_back(rdict.size());
			int tnum = 0, vcnt = 0;
			stk1[stkp1++] = r;
			while (stkp1) {
				int u = stk1[--stkp1];
				if (u == -1) { tnum <<= 1; continue; }
				tnum = tnum << 1 | 1;
				stk1[stkp1++] = -1;
				++vcnt;
				for (int v : g[u]) if (v != par[u]) {
					stk1[stkp1++] = v;
					assert(stkp1 < 2 * S);
				}
			}
			auto [it, done] = micromap.try_emplace(tnum, microdb.size());
			tnum = it->second;
			if (done) microdb.emplace_back(vcnt << B, -1);
			int dep = -1, num = 0;
			stk1[stkp1++] = r;
			while (stkp1) {
				int u = stk1[--stkp1];
				if (u < 0) {
					u = -u - 1;
					if (done) {
						const int bidx = data[u] & (((1 << B) - 1) << B);
						for (int i = 0; i <= dep; ++i) {
							assert(bidx + i < (vcnt << B));
							microdb[tnum][bidx + i] = stk2[dep - i];
						}
					}
					--dep;
					continue;
				}
				data[u] = (tnum << 2 * B) | (num << B) | ++dep;
				jump[u] = jp;
				utreeid[u] = utid;
				rdict.emplace_back(u);
				stk2[dep] = num++;
				stk1[stkp1++] = -u - 1;
				for (int v : g[u]) if (v != par[u]) stk1[stkp1++] = v;
			}
		}; 
		
		// build Macro-Micro-Tree
		int mxdep = 0;
		std::stack<std::pair<int, int>> stk;
		stk.emplace(root, 0);
		while (stk.size()) {
			const auto [u, i] = stk.top(); stk.pop();
			assert(0 <= u && u < n);
			if (g[u].size() == i) {
				if (par[u] != -1) data[par[u]] += data[u];
				bool f = false;
				if (jump[u] == n) {
					if (par[u] != -1 && data[u] < S) continue;
					jump[u] = u;
					jumps.emplace_back(u);
					f = true;
				}
				data[u] = -1;
				if (par[u] != -1 && jump[par[u]] == n) jump[par[u]] = jump[u];
				for (int v : g[u]) if (jump[v] == n) build_micro(v);
				if (f) jump[u] = -static_cast<int>(jumps.size());
			}
			else {
				stk.emplace(u, i + 1);
				if (g[u][i] == par[u]) continue;
				stk.emplace(g[u][i], 0);
				par[g[u][i]] = u;
				depth_[g[u][i]] = depth_[u] + 1;
				if (mxdep < depth_[g[u][i]]) mxdep = depth_[g[u][i]];
			}
		}
		rdict.shrink_to_fit();
		rdst.shrink_to_fit(); 
		
		// counting_sort(ord[i]) by depth_[i]
		std::vector<int> cnt(mxdep + 2);
		for (int i = 0; i < n; ++i) ++cnt[depth_[i] + 1];
		for (int i = 1; i < mxdep; ++i) cnt[i + 1] += cnt[i];
		std::vector<int> ord(n);
		for (int i = 0; i < n; ++i) ord[cnt[depth_[i]]++] = i;
		
		// build ladder
		ladnum.assign(n, -1);
		ladder.reserve(jumps.size());
		for (int t = n - 1; t >= 0; --t) {
			const int i = ord[t];
			if (ladnum[i] != -1) continue;
			int u = i, lpathc = 0;
			while (u != -1 && ladnum[u] == -1) ladnum[u] = ladder.size(), u = par[u], ++lpathc;
			int lsize = 0;
			while (u != -1 && lsize < lpathc) u = par[u], ++lsize;
			lsize += lpathc;
			ladder.emplace_back(lsize);
			u = i;
			for (int c = 0; c < lsize; ++c, u = par[u]) ladder.back()[c] = u;
		}
		
		// build jumpp
		if (n == 1) return;
		logn = 0;
		while ((1 << logn) < n) ++logn;
		jumpp.assign(logn, std::vector<int>(jumps.size(), -1));
		for (int i = 0; i < static_cast<int>(jumps.size()); ++i) jumpp[0][i] = par[jumps[i]];
		for (int i = 0; i + 1 < logn; ++i) {
			for (int j = 0; j < static_cast<int>(jumps.size()); ++j) {
				const int v = jumpp[i][j];
				if (v == -1) continue;
				const int ln = ladnum[v];
				const int ridx = depth_[v] - (1 << i) - depth_[ladder[ln].back()];
				if (ridx >= 0) {
					assert(ridx < static_cast<int>(ladder[ln].size()));
					jumpp[i + 1][j] = ladder[ln][ladder[ln].size() - 1 - ridx];
				}
			}
		}
	}
	
	int size() const noexcept {
		return n;
	}
	
	int depth(int v) const noexcept {
		assert(0 <= v && v < n);
		return depth_[v];
	}
	
	int operator ()(int v, int k) const noexcept {
		assert(0 <= v && v < n);
		assert(depth_[v] >= k);
		return find(v, k);
	}
	
	int find(int v, int k) const noexcept {
		assert(0 <= v && v < n);
		assert(0 <= k && k <= depth_[v]);
		if (data[v] != -1) {
			const int tnum = data[v] >> 2 * B;
			const int vnum = data[v] >> B & ((1 << B) - 1);
			const int mdep = data[v] & ((1 << B) - 1);
			if (depth_[v] - k <= mdep) {
				const int avnum = microdb[tnum][vnum << B | (depth_[v] - k)];
				return rdict[rdst[utreeid[v]] + avnum];
			}
			v = jump[v];
		}
		else if (jump[v] >= 0) v = jump[v];
		if (depth_[v] == k) return v;
		const int jpi = 31 - tk::count_leading_zeros(depth_[v] - k);
		v = jumpp[jpi][-jump[v] - 1];
		const int ln = ladnum[v];
		const int ridx = k - depth_[ladder[ln].back()];
		assert(0 <= ridx && ridx < ladder[ln].size());
		return ladder[ln][ladder[ln].size() - 1 - ridx];
	}
	
	int up(int v, int k) const noexcept {
		assert(0 <= v && v < n);
		assert(0 <= k && k <= depth_[v]);
		return find(v, depth_[v] - k);
	}
};

#endif // INCLUDE_GUARD_LEVEL_ANCESTOR_HPP