CXX = g++
CXXFLAGS = -Wall -O0
HDRS = json/JSON.h json/JSONPair.h
OBJS = main.o json/JSON.o json/CommandLineParser.o json/JSONParser.o json/JSONObject.o json/JSONKey.o json/JSONKeys.o

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