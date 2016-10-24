CC=g++ -g -std=c++11
EXE=test.out
template=$(wildcard *.hpp) $(wildcard *.cpp)

all: $(EXE) 

$(EXE): $(template) test.cpp 
	$(CC) -o $@ test.cpp 

clean: 
	rm -rf *.o $(EXE) 
