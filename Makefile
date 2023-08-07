CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
DEFINES := -DCPPHTTPLIB_OPENSSL_SUPPORT
INCLUDES := -I./cpp-httplib
LIBS := -lssl -lcrypto

all: dogfact

dogfact: dogfact.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(DEFINES) $(INCLUDES) $(LIBS)

clean:
	rm -f dogfact

.PHONY: all clean
