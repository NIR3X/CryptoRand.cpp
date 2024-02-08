#pragma once

#include <windows.h>
#include <cstdint>

extern "C" NTSYSAPI NTSTATUS NTAPI NtDelayExecution(IN BOOLEAN Alertable, IN PLARGE_INTEGER Interval);

class CTime {
public:
	static int64_t GetCurrentSystemTime();
	static void NanoSleep(int64_t nanoseconds);
};
