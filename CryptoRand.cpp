#include "CryptoRand.h"
#include "Mouse.h"
#include "Time.h"
#include "Xorshift64.h"
#include "Xorshift1024s.h"

void CCryptoRand::Read(uint8_t* key, uint32_t keySize, std::function<void(float progress)> progressCallback) {
	RtlGenRandom(key, keySize);

	CXorshift64 xorshift64(CTime::GetCurrentSystemTime());
	for (size_t i = 0; i < keySize; ++i) {
		key[i] ^= xorshift64.next();
	}

	uint8_t xorshift1024sSeed[128] = {};

	UMousePos lastMousePos = CMouse::InvalidMousePos;
	for (size_t i = 0; i < sizeof(xorshift1024sSeed) * 80;) {
		UMousePos mousePos;
		if (CMouse::GetPos(mousePos)) {
			if (mousePos.u64 != lastMousePos.u64) {
				lastMousePos.u64 = mousePos.u64;
				*(uint16_t*)&xorshift1024sSeed[i % (sizeof(xorshift1024sSeed) - sizeof(uint16_t) + 1)] ^= mousePos.point.x ^ mousePos.point.y;
				if (i % sizeof(xorshift1024sSeed) == 0) {
					progressCallback((float)i / ((float)sizeof(xorshift1024sSeed) * 80.f));
				}
				++i;
			}
		}
		CTime::NanoSleep(10);
	}

	CXorshift1024s xorshift1024s(xorshift1024sSeed);
	for (size_t i = 0; i < keySize; ++i) {
		key[i] ^= xorshift1024s.next();
	}

	progressCallback(1.f);
}
