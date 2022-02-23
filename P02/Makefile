CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

main: main.o RC4.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cc RC4.h
	$(CXX) -c main.cc

RC4.o: RC4.cc RC4.h
	$(CXX) -c Vernam.cc