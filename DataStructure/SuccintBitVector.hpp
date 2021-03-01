#ifndef INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP
#define INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP

#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>

/**
 * @brief https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp
 */
struct SuccintBitVector {
	using size_type = std::size_t;
	using uint32 = std::uint32_t;
	
private:
	using uint8 = std::uint8_t;
	
	static constexpr size_type LARGE = 8;
	static constexpr size_type SMALL = 3;
	
private:
	size_type n;
	std::vector<uint8> bits;
	std::vector<uint32> large;
	std::vector<uint8> small;
	
public:
	explicit SuccintBitVector(size_type n)
		: n(n), bits(n == 0 ? 0 : ((n - 1) >> SMALL) + 1, 0u) {}
	
	explicit SuccintBitVector(const std::vector<uint8> & bits)
		: n(bits.size() << SMALL), bits(bits) {}
	
	void build() {
		large.assign(((n - 1) >> LARGE) + 1, 0);
		small.assign(((n - 1) >> SMALL) + 1, 0);
		for (uint32 i = 0, lidx = 0; i < bits.size(); i += 1u << (LARGE - SMALL), ++lidx) {
			if (lidx > 0) large[lidx] = large[lidx - 1] + small[i - 1] + pop_count(bits[i - 1]);
			small[i] = 0;
			for (uint32 j = i + 1; j < std::min<uint32>(bits.size(), i + (1u << (LARGE - SMALL))); ++j) {
				small[j] = small[j - 1] + pop_count(bits[j - 1]);
			}
		}
	}
	
	size_type size() const noexcept {
		return n;
	}
	
	void set(size_type i) noexcept {
		assert(i < n);
		bits[i >> SMALL] |= 1u << (i & ~(~0u << SMALL));
	}
	
	void reset(size_type i) noexcept {
		assert(i < n);
		bits[i >> SMALL] &= ~(1u << (i & ~(~0u << SMALL)));
	}
	
	bool access(size_type i) const noexcept {
		assert(i < n);
		return bits[i >> SMALL] >> (i & ~(~0u << SMALL)) & 1;
	}
	
	uint32 rank1(size_type i) const noexcept {
		assert(i <= n);
		if (i == 0) return 0;
		--i;
		return large[i >> LARGE] + small[i >> SMALL] + pop_count(bits[i >> SMALL] & ~(~0u << ((i & (~(~0u << SMALL))) + 1)));
	}
	
	uint32 rank0(size_type i) const noexcept {
		assert(i <= n);
		return i - rank1(i);
	}
	
	size_type select1(size_type k) const noexcept {
		if (k == 0) return size() + 1;
		uint32 l = 0, r = large.size();
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(large[m] < k ? l : r) = m;
		}
		uint32 cnt = large[l];
		l = l << (LARGE - SMALL); r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(cnt + small[m] < k ? l : r) = m;
		}
		cnt += small[l];
		const uint32 idx = l;
		l = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u << SMALL)) + 1 : 8;
		if (cnt + pop_count(bits[idx] & ~(~0u << r)) < k) return size() + 1;
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(cnt + pop_count(bits[idx] & ~(~0u << m)) < k ? l : r) = m;
		}
		return (idx << SMALL) + r;
	}
	
	size_type select0(size_type k) const noexcept {
		if (k == 0) return size() + 1;
		uint32 l = 0, r = large.size();
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(m * (1 << LARGE) - large[m] < k ? l : r) = m;
		}
		uint32 cnt = l * (1 << LARGE) - large[l];
		l = l << (LARGE - SMALL); r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(cnt + (m & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[m] < k ? l : r) = m;
		}
		cnt += (l & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[l];
		const uint32 idx = l;
		l = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u << SMALL)) + 1 : 8;
		if (cnt + pop_count(~bits[idx] & ~(~0u << r)) < k) return size() + 1;
		while (l + 1 < r) {
			const uint32 m = (l + r) >> 1;
			(cnt + pop_count(~bits[idx] & ~(~0u << m)) < k ? l : r) = m;
		}
		return (idx << SMALL) + r;
	}
	
private:
	static constexpr uint8 table[1u << (1u << SMALL)] {
		0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8
	};
	
	static constexpr uint8 pop_count(uint8 x) noexcept {
		return table[x];
	}
};

#endif // INCLUDE_GUARD_SUCCINT_BIT_VECTOR_HPP