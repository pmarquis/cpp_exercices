DEBUG_LEVEL     = -g
EXTRA_CCFLAGS   = -std=c++11 -W -Wall -Werror
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS         = $(CXXFLAGS)
CC=g++
LDFLAGS=

INCPATH=./include
SRC=./src
TEST=./tests
EXEC=main
TEST_EXEC=test

all: $(EXEC) $(TEST_EXEC)

main: WordCombinations.o main.o
	$(CC) -o main WordCombinations.o main.o $(LDFLAGS)

WordCombinations.o: $(SRC)/WordCombinations.cpp
	$(CC) -I $(INCPATH) -o WordCombinations.o -c $(SRC)/WordCombinations.cpp $(CCFLAGS)

main.o: $(SRC)/main.cpp include/WordCombinations.h 
	$(CC) -I $(INCPATH) -o main.o -c $(SRC)/main.cpp $(CCFLAGS)

clean_all: 
	rm -f *.o main test

test: WordCombinations.o TestWordCombinations.o test.o
	$(CC) -o test test.o WordCombinations.o TestWordCombinations.o $(LDFLAGS) 

test.o:
	$(CC) -I $(INCPATH) -o test.o -c $(TEST)/test.cpp $(CCFLAGS) 

TestWordCombinations.o:
	$(CC) -I $(INCPATH) -o TestWordCombinations.o -c $(TEST)/TestWordCombinations.cpp $(CCFLAGS) 

