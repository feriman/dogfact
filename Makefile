CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
LIBS := -lhttplib

all: dogfact

dogfact: dogfact.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)

clean:
	rm -f dogfact

.PHONY: all clean
