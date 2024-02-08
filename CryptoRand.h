#pragma once

#include <windows.h>
#include <cstdint>
#include <functional>

#define RtlGenRandom SystemFunction036
extern "C" BOOLEAN NTAPI RtlGenRandom(PVOID RandomBuffer, ULONG RandomBufferLength);

class CCryptoRand {
public:
    static void Read(uint8_t* key, uint32_t keySize, std::function<void(float progress)> progressCallback);
};
