#
# Program:     makefile
# Programmer:  Fabian Hueramo
# Logon ID:    Z1857628
# Date due:    2018-11-20
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11 -g

# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rule to compile source code files to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Psuedo-target to remove object code and executable files
clean:
	-rm *.o assign7
