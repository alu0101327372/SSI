CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

main: main.o Vernam.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cc Vernam.h
	$(CXX) -c main.cc

Vernam.o: Vernam.cc Vernam.h
	$(CXX) -c Vernam.cc