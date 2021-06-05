#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "DataStructure/AVL_Tree.hpp"

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
	
	AVL_Tree<pll> avl;
	
	while (Q--) {
		int q;
		ll k, v;
		scanf("%d %lld", &q, &k);
		auto it = avl.lower_bound({k, 0});
		
		if (q == 0) {
			scanf("%lld", &v);
			if (it != avl.end() && it->val.first == k) avl.erase(it);
			avl.insert({k, v});
		}
		else {
			printf("%lld\n", it == avl.end() || it->val.first != k ? 0 : it->val.second);
		}
	}
	
	// [begin, next] test
	auto elem = avl.enumerate();
	{
		std::vector<pll> elem2;
		for (auto it = avl.begin(); it != avl.end(); it = avl.next(it)) elem2.emplace_back(it->val);
		assert(elem == elem2);
	}
	// [end, prev] test
	{
		std::vector<pll> elem2;
		for (auto it = avl.prev(avl.end()); it != avl.end(); it = avl.prev(it)) elem2.emplace_back(it->val);
		std::reverse(begin(elem2), end(elem2));
		assert(elem == elem2);
	}
	
	// [*_bound, count*, k_th_*] test
	for (int i = 0; i < elem.size(); ++i) {
		const auto & e = elem[i];
		auto itelemup = std::upper_bound(begin(elem), end(elem), e);
		auto itelemlo = std::lower_bound(begin(elem), end(elem), e);
		assert(avl.lower_bound(e) != avl.end());
		assert(avl.lower_bound(e)->val == e);
		assert(itelemup == elem.end() ? avl.upper_bound(e) == avl.end() : avl.upper_bound(e)->val == *itelemup);
		
		const auto lt = itelemlo - elem.begin(), eq = itelemup - itelemlo, gt = elem.end() - itelemup;
		assert(avl.count_less_than(e) == lt);
		assert(avl.count_less_equal(e) == lt + eq);
		assert(avl.count_greater_than(e) == gt);
		assert(avl.count_greater_equal(e) == gt + eq);
		assert(avl.count(e) == eq);
		assert(avl.k_th_smallest(i + 1)->val == e);
		assert(avl.k_th_largest(elem.size() - i)->val == e);
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
	assert(ss.size() == avl.size());
	for (int i : ord) {
		auto it = avl.erase(elem[i]);
		auto its = ss.find(elem[i]); ++its;
		assert(its == ss.end() ? it == avl.end() : it->val == *its);
		ss.erase(--its);
		assert(ss.size() == avl.size());
	}
}