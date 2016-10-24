# This makefile will take any <filename>.cpp source file with a main function
# And create a corresponding executable <filename>.out

outputs := $(patsubst %.cpp,%.out,$(wildcard *.cpp))
templates := ll/node.hpp ll/linkedlist.hpp ll/linkedlist.cpp

all: $(outputs) 

%.out: %.cpp $(templates)
	g++ -g -std=c++11 -o $@ $(patsubst %.out,%.cpp, $@)

clean:
	rm -rf *.out *.dSYM
