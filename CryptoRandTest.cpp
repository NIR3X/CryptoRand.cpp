#include "CryptoRand.h"
#include <cassert>
#include <cstdint>
#include <cstdio>

int main() {
	float lastProgress = 0.f;
	uint8_t key[256];
	CCryptoRand::Read(key, sizeof(key), [&] (float progress) {
		printf("\rMove the mouse around to generate a random key: %.2f%%", progress * 100.f);
		lastProgress = progress;
	});
	assert(lastProgress == 1.f);
	printf("\rKey: ");
	for (uint8_t byte : key) {
		printf("%d ", byte); 
	}
	printf("\n");
}
