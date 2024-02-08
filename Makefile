AR = ar
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O2 -march=x86-64 -fno-rtti
LDFLAGS = -s -static -ladvapi32 -lntdll

SRC = CryptoRand.cpp Mouse.cpp Time.cpp Xorshift64.cpp Xorshift1024s.cpp
OBJ = $(SRC:.cpp=.o)
DEST = CryptoRand.a
TEST_SRC = CryptoRandTest.cpp
TEST_DEST = CryptoRandTest.exe

build: $(OBJ)
	$(AR) r -o $(DEST) $^

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST)
