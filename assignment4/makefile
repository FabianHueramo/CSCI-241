# Compiler Variables
CCFLAGS = -Wall -std=c++11


# Object -> Executable
assign4: assign4.o Complex.o
	g++ $(CCFLAGS) -o assign4 assign4.o Complex.o


# Source -> Object
assign4.o: assign4.cpp Complex.h
	g++ $(CCFLAGS) -c assign4.cpp

Complex.o: Complex.cpp Complex.h
	g++ $(CCFLAGS) -c Complex.cpp


# Pseudo-Target Clean
clean:
	-rm *.o assign4
