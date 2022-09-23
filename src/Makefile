CXX = g++
CXXFLAGS = -Wall -O0
HDRS = json/JSON.h
SRCS := $(wildcard *.cpp)
SRCS_JSON := $(wildcard json/*.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS)) $(patsubst %.cpp, %.o, $(SRCS_JSON))

%.o : %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

JSONTest: $(OBJS)
	$(CXX) -o $@ $^

all: JSONTest

.PHONY: run
run: ./JSONTest
	@echo Executing JSONTest [main.cpp code]...
	./JSONTest

.PHONY: clean
clean:
	rm *.o json/*.o