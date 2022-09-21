# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Object -> Executable
assign8: assign8.o Maze.o
	g++ $(CCFLAGS) -o assign8 assign8.o Maze.o

# Source -> Object
assign8.o: assign8.cpp Maze.h
	g++ $(CCFLAGS) -c assign8.cpp

Maze.o: Maze.cpp Maze.h
	g++ $(CCFLAGS) -c Maze.cpp
	
# Pseudo-target Clean/Remove
clean:
	-rm *.o assign8
