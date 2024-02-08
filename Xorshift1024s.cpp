#include "Xorshift1024s.h"

CXorshift1024s::CXorshift1024s(uint8_t seed[128]) : index(0) {
	for (size_t i = 0; i < 16; ++i) {
		x[i] = *((uint64_t*)seed + i);
	}
}

uint64_t CXorshift1024s::next() {
	auto state = this;
	int index = state->index;
	uint64_t const s = state->x[index++];
	uint64_t t = state->x[index &= 15];
	t ^= t << 31;		// a
	t ^= t >> 11;		// b  -- Again, the shifts and the multipliers are tunable
	t ^= s ^ (s >> 30);	// c
	state->x[index] = t;
	state->index = index;
	return t * 1181783497276652981ULL;
}
