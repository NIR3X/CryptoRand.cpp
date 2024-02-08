#include "Xorshift64.h"

CXorshift64::CXorshift64(uint64_t seed) : a(seed) {
}

uint64_t CXorshift64::next() {
	uint64_t x = a;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return a = x;
}
