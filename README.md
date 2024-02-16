# CryptoRand.cpp - Random Key Generation using Cryptographic Techniques

The CryptoRand.cpp module provides a secure method for generating random keys using cryptographic techniques and user interactions.

## Description

This module utilizes cryptographic algorithms along with user interactions (mouse movements) to generate random keys. It employs Xorshift random number generators for additional randomness.

## Features

* Generates random keys securely.
* Utilizes cryptographic algorithms for randomness.
* Incorporates user interactions (mouse movements) for added entropy.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/CryptoRand.cpp
cd CryptoRand.cpp
make
```

## Usage

1. Include the necessary header file: `CryptoRand.h`.
2. Call the `CCryptoRand::Read()` function to generate a random key.
3. Provide a callback function to track the progress of key generation.
4. Ensure the generated key is used securely in your application.

Example usage:

```cpp
#include "CryptoRand.h"
#include <cstdint>
#include <cstdio>

int main() {
	uint8_t key[256];
	CCryptoRand::Read(key, sizeof(key), [] (float progress) {
		printf("\rMove the mouse around to generate a random key: %.2f%%", progress * 100.f);
	});
	printf("\rKey: ");
	for (uint8_t byte : key) {
		printf("%d ", byte); 
	}
	printf("\n");
}
```

## License

[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
