#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/RedBlackTree.hpp"

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <set>
#include <numeric>

int main() {
	int Q;
	scanf("%d", &Q);
	
	using ll = long long;
	using pll = std::pair<ll, ll>;
	
	RedBlackTree<pll> rbt;
	
	while (Q--) {
		int q;
		ll k, v;
		scanf("%d %lld", &q, &k);
		auto it = rbt.lower_bound(pll{k, 0});
		
		if (q == 0) {
			scanf("%lld", &v);
			if (it != rbt.end() && it->val.first == k) rbt.erase(it);
			rbt.insert(pll{k, v});
		}
		else {
			printf("%lld\n", it == rbt.end() || it->val.first != k ? 0 : it->val.second);
		}
	}
	
	// [begin, next] test
	auto elem = rbt.enumerate();
	{
		std::vector<pll> elem2;
		for (auto it = rbt.begin(); it != rbt.end(); it = rbt.next(it)) elem2.emplace_back(it->val);
		assert(elem == elem2);
	}
	// [end, prev] test
	{
		std::vector<pll> elem2;
		for (auto it = rbt.prev(rbt.end()); it != rbt.end(); it = rbt.prev(it)) elem2.emplace_back(it->val);
		std::reverse(begin(elem2), end(elem2));
		assert(elem == elem2);
	}
	
	// [lower_bound, upper_bound] test
	for (int i = 0; i < elem.size(); ++i) {
		const auto & e = elem[i];
		auto itelemup = std::upper_bound(begin(elem), end(elem), e);
		assert(rbt.lower_bound(e) != rbt.end());
		assert(rbt.lower_bound(e)->val == e);
		assert(itelemup == elem.end() ? rbt.upper_bound(e) == rbt.end() : rbt.upper_bound(e)->val == *itelemup);
	}
	
	// [erase, size] test
	std::set<pll> ss;
	for (const auto & e : elem) ss.insert(e);
	std::vector<int> ord(elem.size());
	std::iota(begin(ord), end(ord), 0);
	std::sort(begin(ord), end(ord), [&](int i, int j) {
		if (elem[i].second == elem[j].second) return elem[i].first > elem[j].first;
		return elem[i].second < elem[j].second;
	});
	assert(ss.size() == rbt.size());
	for (int i : ord) {
		auto it = rbt.erase(elem[i]);
		auto its = ss.find(elem[i]); ++its;
		assert(its == ss.end() ? it == rbt.end() : it->val == *its);
		ss.erase(--its);
		assert(ss.size() == rbt.size());
	}
}