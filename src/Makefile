CXX = g++
CXXFLAGS = -Wall -O0
HDRS = json/JSON.h
OBJS = main.o

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
	rm *.o