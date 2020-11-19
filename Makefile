CXX		  := g++
CXX_FLAGS := -Wall -std=c++14 -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= dfa_simulation


all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): *.cc
	$(CXX) $(CXX_FLAGS) -I*.h $^ -o $@ 

clean:
	-rm $(EXECUTABLE)
