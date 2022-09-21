/**************************************************************
 PROGRAM:    Maze.h
 PROGRAMMER: Fabian Hueramo
 LOGON ID:   Z1857628
 DUE DATE:   2018-11-28

 FUNCTION:   Contains Maze class
***************************************************************/
#ifndef MAZE_H
#define MAZE_H
#include <stack>
#include <string>
enum SquareType
    {
    WALL = '#',
    SPACE = '.',
    START = 's',
    END = 'e'
    };

enum PathType
    {
    NORTH = 'n',
    SOUTH = 's',
    EAST = 'e',
    WEST = 'w'
    };

struct MazePos
    {
    int xpos;
    int ypos;
    };

struct MazeSquare
    {
    SquareType type;
    bool visited;
    };

class Maze
    {
    private:
	MazeSquare maze[25][25];
	int height;
	int width;
	MazePos start;
	MazePos end;
	std::stack<char> path;

    public:
	Maze();
	void printMaze() const;
	void clearPath();
	void readMaze(const std::string& fileName);
	bool solveMaze();
	bool solveMaze(int row, int col);
	void printPath();
    };

#endif
