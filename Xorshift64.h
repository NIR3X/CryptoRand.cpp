#pragma once

#include <cstdint>

class CXorshift64 {
protected:
	uint64_t a;

public:
	CXorshift64(uint64_t seed);

	uint64_t next();
};
