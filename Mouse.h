#pragma once

#include <windows.h>
#include <cstdint>
union UMousePos {
	POINT point;
	uint64_t u64;
};

class CMouse {
public:
	constexpr static UMousePos InvalidMousePos = { .u64 = 0xFFFFFFFFFFFFFFFF };
	static bool GetPos(UMousePos& pos);
};
