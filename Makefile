#this is makefile for testing and compiling
all: %.cpp
	$(CXX) %.cpp -o a.out
