#pragma once

#include <cstdint>

class CXorshift1024s {
protected:
	uint64_t x[16];
	int index;

public:
	CXorshift1024s(uint8_t seed[128]);

	uint64_t next();
};
