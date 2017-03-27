# This makefile will take any <filename>.cpp source file with a main function
# And create a corresponding executable <filename>.out
#-include $(deps)
#g++ -MM -std=c++11 $*.cpp > $*.d

CFLAGS=-g -std=c++11 #-Wc++11-extensions
objects := $(patsubst %.cpp, %.o, $(wildcard ds/**/*.cpp))
deps := $(objects:.o=.d)
outputs := $(patsubst %.cpp,%.out,$(wildcard *.cpp))
templates := $(wildcard ds/*.cpp) $(wildcard ds/*.hpp) $(wildcard ds/**/*.cpp) $(wildcard ds/**/*.hpp) $(wildcard ds/**/*.tpp) 

all: $(objects) $(outputs) 

%.o : %.cpp %.hpp 
	g++ $(CFLAGS) -c $*.cpp -o $*.o


%.out: %.cpp $(templates)
	g++ $(CFLAGS) $(objects) -o $@ $(patsubst %.out,%.cpp, $@) 

clean:
	rm -rf *.out *.dSYM $(objects) $(deps) 
