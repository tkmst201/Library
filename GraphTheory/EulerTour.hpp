#ifndef INCLUDE_GUARD_EULER_TOUR_HPP
#define INCLUDE_GUARD_EULER_TOUR_HPP

/*
last-updated: 2020/09/16

辺に番号を付けるタイプの EulerTour
単純な木のみ対応(自己ループ, 多重辺, 森には非対応)
グラフには孤立点が存在しないと仮定する

# 解説
部分木クエリの処理
	(i) 頂点に値が存在するとき
		各頂点 u に対し、in[u] に頂点 u の値を持たせる。
		部分木 u の値の総和は [in[u], out[u]) の総和
	(ii) 辺に値が存在するとき
		各頂点 u に対し、親 p からの辺の値を in[u] に持たせる。
		部分木 u の値の総和は [in[u] + 1, out[u]) の総和

パスクエリの処理
	頂点に値が存在するときのみ考える(辺も同様)
	各頂点 u に対し、
		in[u] に頂点 u の値
		out[u] に頂点 u の値の逆元
	をもたせる。
	葉へ下る方向にしか計算できないため、lca を求めて 2 つのパスに分けて計算する。
	このとき、可換でない場合はパスの上り下りで計算の仕方を工夫する必要がある。

# 仕様
EulerTour(const Tree & tree, size_type root)
	時間計算量: Θ(n)
	木 g, 根を root として EulerTour で番号を振る
	ここで渡した tree の参照元は変更してはいけない。

size_type size() const noexcept
	時間計算量: Θ(1)
	割り振った辺の番号の総数(2n) を返す

size_type par(size_type k) const
	時間計算量: Θ(1)
	頂点 k の親の頂点番号を返す

size_type in(size_type k) const
	時間計算量: Θ(1)
	頂点 k に入ったときの辺番号(EulerTour 順) を返す
	k が根の場合は 0

size_type out(size_type k) const
	時間計算量: Θ(1)
	頂点 k から出たときの辺番号(EulerTour 順) を返す
	k が根の場合は 2n

std::pair<size_type, size_type> par_from(size_type k) const
	時間計算量: Θ(1)
	頂点 k の親から頂点 k への辺 e の情報 ( {頂点 k の親の頂点番号}, {tree 上の辺 e の index}) を返す
	つまり、tree[par[k]][e-index] = k
	k が根の場合は (n, n)

size_type par_to(size_type k) const
	時間計算量: Θ(1)
	頂点 k から親への辺 e の tree 上の index を返す
	つまり、tree[k][e-index] = par[k]
	k が根もしくは tree が逆辺を持っていない場合は n

# 参考
https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7, 2020/09/16
https://beet-aizu.hatenablog.com/entry/2019/07/08/174727, 2020/09/16
*/

#include <cstdint>
#include <vector>
#include <cassert>
#include <stack>
#include <utility>

struct EulerTour {
	using size_type = std::size_t;
	using Tree = std::vector<std::vector<size_type>>;
	
private:
	size_type n;
	const Tree & tree;
	size_type root;
	std::vector<size_type> in_, out_;
	std::vector<size_type> par_, g_idx;
	
public:
	EulerTour(const Tree & tree, size_type root) : n(tree.size()), tree(tree), root(root) {
		in_.assign(size(), size());
		out_.assign(size(), size());
		par_.assign(n, n);
		g_idx.assign(size(), n);
		
		std::stack<std::pair<size_type, size_type>> stk;
		std::vector<size_type> par_edge(n, n);
		size_type num = 0;
		
		in_[root] = num++;
		stk.emplace(root, 0);
		
		while (!stk.empty()) {
			const size_type u = stk.top().first;
			const size_type i = stk.top().second;
			stk.pop();
			
			if (i < tree[u].size()) {
				const size_type v = tree[u][i];
				stk.emplace(u, i + 1);
				if (v == par_[u]) par_edge[u] = i;
				else {
					g_idx[num] = i;
					in_[v] = num++;
					par_[v] = u;
					stk.emplace(v, 0);
				}
			}
			else out_[u] = num++;
		}
		for (size_type i = 0; i < n; ++i) g_idx[out_[i]] = par_edge[i];
	}
	
	size_type size() const noexcept { return n << 1; }
	size_type par(size_type k) const { assert(k < size()); return par_[k]; }
	size_type in(size_type k) const { assert(k < size()); return in_[k]; }
	size_type out(size_type k) const { assert(k < size()); return out_[k]; }
	std::pair<size_type, size_type> par_from(size_type k) const { assert(k < size()); return {par_[k], g_idx[in_[k]]}; }
	size_type par_to(size_type k) const { assert(k < size()); return g_idx[out_[k]]; }
};

#endif // INCLUDE_GUARD_EULER_TOUR_HPP