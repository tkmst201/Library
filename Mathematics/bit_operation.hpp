#ifndef INCLUDE_BIT_OPERATION_HPP
#define INCLUDE_BIT_OPERATION_HPP

#include <cstdint>

namespace tk {
constexpr int pop_count(std::uint32_t x) {
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f;
	x += x >> 8;
	x += x >> 16;
	return x & 0xff;
}

 int pop_countll(std::uint64_t x) {
	x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
	x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
	x += x >> 8;
	x += x >> 16;
	x += x >> 32;
	return x & 0xff;
}

constexpr int count_trailing_zeros(std::uint32_t x) {
	return pop_count(~x & (x - 1));
}

 int count_trailing_zerosll(std::uint64_t x) {
	return pop_countll(~x & (x - 1));
}

constexpr int count_leading_zeros(std::uint32_t x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return pop_count(~x);
}

 int count_leading_zerosll(std::uint64_t x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;
	return pop_countll(~x);
}
} // namespace tk

#endif // INCLUDE_BIT_OPERATION_HPP
