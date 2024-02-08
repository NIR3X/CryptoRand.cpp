#include "Time.h"

int64_t CTime::GetCurrentSystemTime() {
	FILETIME systemTime;
	GetSystemTimeAsFileTime(&systemTime);

	LARGE_INTEGER systemTimeInteger;
	systemTimeInteger.HighPart = systemTime.dwHighDateTime;
	systemTimeInteger.LowPart = systemTime.dwLowDateTime;
	return systemTimeInteger.QuadPart;
}

void CTime::NanoSleep(int64_t nanoseconds) {
	LARGE_INTEGER delayTime = { .QuadPart = nanoseconds / -100LL };
	NtDelayExecution(false, &delayTime);
}
