#
# PROGRAM:    assign5
# PROGRAMMER: Fabian Hueramo
# LOGON ID:   z1857628
# DATE DUE:   2018-10-30
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign5: assign5.o NIUString.o 
	g++ $(CCFLAGS) -o assign5 assign5.o NIUString.o

# Rules to compile source code files to object code
assign5.o: assign5.cpp NIUString.h
	g++ $(CCFLAGS) -c assign5.cpp

NIUString.o: NIUString.cpp NIUString.h
	g++ $(CCFLAGS) -c NIUString.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5
