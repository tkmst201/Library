#ifndef INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP
#define INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP

/*
last-updated: 2020/11/19

TODO: AOJ, yukicoder から verify 問題を探す

# 仕様
## 集合
void zeta_tranform_set_lower(std::vector<T> & v)
	時間計算量: Θ(|v|log|v|)
	配列 v を配列 v' に書き換える(i の下位集合について総和を取る)
	v'[i] := \Sum_{j \subset i} v[j]

void moebius_transform_set_lower(std::vector<T> & v)
	時間計算量: Θ(|v|log|v|)
	配列 v を次の式を満たす配列 v' に書き換える(i の下位集合について総和を取る前に戻す)
	v[i] = \Sum_{j \subset i} v'[j]

void zeta_tranform_set_upper(std::vector<T> & v)
	時間計算量: Θ(|v|log|v|)
	配列 v を配列 v' に書き換える(i の上位集合について総和を取る)
	v'[i] := \Sum_{i \subset j} v[j]

void moebius_transform_set_upper(std::vector<T> & v)
	時間計算量: Θ(|v|log|v|)
	配列 v を次の式を満たす配列 v' に書き換える(i の上位集合について総和を取る前に戻す)
	v[i] = \Sum_{i \subset j} v'[j]

## 約数倍数
void zeta_tranform_divisor_lower(std::vector<T> & v)
	時間計算量: O(|v|loglog|v|)
	配列 v を配列 v' に書き換える(i の約数について総和を取る)
	v'[i] := \Sum_{j|i} v[j]

void moebius_tranform_divisor_lower(std::vector<T> & v)
	時間計算量: O(|v|loglog|v|)
	配列 v を次の式を満たす配列 v' に書き換える(i の約数について総和を取る前に戻す)
	v[i] = \Sum_{j|i} v'[j]

void zeta_tranform_divisor_upper(std::vector<T> & v)
	時間計算量: O(|v|loglog|v|)
	配列 v を配列 v' に書き換える(i の倍数について総和)
	v'[i] := \Sum_{i|j} v[j]

void moebius_tranform_divisor_upper(std::vector<T> & v)
	時間計算量: O(|v|loglog|v|)
	配列 v を次の式を満たす配列 v' に書き換える(i の約数について総和を取る前に戻す)
	v[i] = \Sum_{i|j} v'[j]

# 参考
2020/11/12: https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
2020/11/14: https://aprilganmo.hatenablog.com/entry/2020/02/27/170239
2020/11/14: https://noshi91.hatenablog.com/entry/2018/12/27/121649
2020/11/18: https://aprilganmo.hatenablog.com/entry/2020/07/24/190816

# verify
void zeta_tranform_set_lower(std::vector<T> & v)
void moebius_transform_set_lower(std::vector<T> & v)
void zeta_tranform_set_upper(std::vector<T> & v)
- OK

void moebius_transform_set_upper(std::vector<T> & v)
- TODO: メビウス(上位集合) の verify

void zeta_tranform_divisor_lower(std::vector<T> & v)
- https://atcoder.jp/contests/abc172/submissions/18200046

void moebius_tranform_divisor_lower(std::vector<T> & v)
- TODO: メビウス(倍数) の verify

void zeta_tranform_divisor_upper(std::vector<T> & v)
void moebius_tranform_divisor_upper(std::vector<T> & v)
- https://atcoder.jp/contests/abc162/submissions/18200657
*/

#include <vector>
#include <cassert>

namespace tk {
template<typename T>
void zeta_tranform_set_lower(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	for (size_type i = 1; i < v.size(); i <<= 1) {
		for (size_type j = 0; j < v.size(); ++j) {
			if (j & i) v[j] += v[j ^ i];
		}
	}
}

template<typename T>
void moebius_transform_set_lower(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	for (size_type i = 1; i < v.size(); i <<= 1) {
		for (size_type j = 0; j < v.size(); ++j) {
			if (j & i) v[j] -= v[j ^ i];
		}
	}
}

template<typename T>
void zeta_tranform_set_upper(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	for (size_type i = 1; i < v.size(); i <<= 1) {
		for (size_type j = 0; j < v.size(); ++j) {
			if (~j & i) v[j] += v[j ^ i];
		}
	}
}

template<typename T>
void moebius_transform_set_upper(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	for (size_type i = 1; i < v.size(); i <<= 1) {
		for (size_type j = 0; j < v.size(); ++j) {
			if (~j & i) v[j] -= v[j ^ i];
		}
	}
}
} // namespace tk

namespace tk {
template<typename T>
void zeta_tranform_divisor_lower(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	std::vector<bool> sieve(v.size(), true);
	for (size_type p = 2; p < v.size(); ++p) {
		if (!sieve[p]) continue;
		for (size_type i = 1, t = p; t < v.size(); ++i, t += p) {
			v[t] += v[i];
			sieve[t] = false;
		}
	}
}

template<typename T>
void moebius_tranform_divisor_lower(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	std::vector<bool> sieve(v.size(), true);
	for (size_type p = 2; p < v.size(); ++p) {
		if (!sieve[p]) continue;
		for (size_type i = (v.size() - 1) / p, t = i * p; i > 0; --i, t -= p) {
			v[t] -= v[i];
			sieve[t] = false;
		}
	}
}

template<typename T>
void zeta_tranform_divisor_upper(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	std::vector<bool> sieve(v.size(), true);
	for (size_type p = 2; p < v.size(); ++p) {
		if (!sieve[p]) continue;
		for (size_type i = (v.size() - 1) / p, t = i * p; i > 0; --i, t -= p) {
			v[i] += v[t];
			sieve[t] = false;
		}
	}
}

template<typename T>
void moebius_tranform_divisor_upper(std::vector<T> & v) {
	assert(!v.empty());
	using size_type = std::size_t;
	std::vector<bool> sieve(v.size(), true);
	for (size_type p = 2; p < v.size(); ++p) {
		if (!sieve[p]) continue;
		for (size_type i = 1, t = p; t < v.size(); ++i, t += p) {
			v[i] -= v[t];
			sieve[t] = false;
		}
	}
}
} // namespace tk

#endif // INCLUDE_GUARD_ZETA_MOEBIUS_TRANSFORM_HPP