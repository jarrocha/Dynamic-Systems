CXX=g++
CXXFLAGS=-Wall -g -std=c++11
LDFLAGS= -lm -I/usr/include/python2.7 -lpython2.7
# LDFLAGS= -lm -lpthread -I/usr/include/python3.8 -lpython3.8

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(@:.out=) $(LDFLAGS)

clean: $(patsubst %.cpp, %.clean, $(wildcard *.cpp))

%.clean:
	rm -f $(@:.clean=)