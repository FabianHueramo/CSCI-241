/**************************************************************
 PROGRAM:    Maze.cpp
 PROGRAMMER: Fabian Hueramo
 LOGON ID:   Z1857628
 DUE DATE:   2018-11-28

 FUNCTION:   Contains method definitions for Maze class
***************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Maze.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/////////////////////////////////////////////////*
//Funtion: Deafult constructor
//
//Purpose: 
//**********************************************/
Maze::Maze()
   {
   }

/////////////////////////////////////////////////*
//Funtion: readMaze()
//
//Purpose: 
//**********************************************/
void Maze::readMaze(const std::string& fileName)
   {
    std::ifstream inFile;
    int maxCol = 0;
    int maxRow = 0;
    int col = 0;
    int row = 0;
    char readChar;
    MazeSquare readSquare;

    inFile.open(fileName);

    if (!inFile)
    {
      std::cout << "[!] Error opening maze file.";
      exit(1);
    }

    inFile >> maxCol;
    inFile >> maxRow;
    width = maxCol;
    height = maxRow;

    for (row = 0; row < maxRow; row++)
      {
        for (col = 0; col < maxCol; col++)
          {
            inFile >> readChar;
            readSquare.visited = false;
            switch (readChar)
              {
                case WALL:
                  readSquare.type = WALL;
                  break;
                case SPACE:
                  readSquare.type = SPACE;
                  break;
                case START:
                  readSquare.type = START;
                  start.xpos = col;
                  start.ypos = row;
                  break;
                case END:
                  readSquare.type = END;
                  end.xpos = col;
                  end.ypos = row;
                  break;
                default:
                  std::cout << "[!] Error parsing maze file. Unknown char: '" << readChar << "'\n";
                  exit(1);
              }

            maze[col][row] = readSquare;
          }
      }

    inFile.close();
   }

/////////////////////////////////////////////////*
//Funtion: printMaze()
//
//Purpose: clears path
//**********************************************/
void Maze::printMaze() const
   {
   for (int row = 0; row < height; row++)
      {
      for (int col = 0; col < width; col++)
         {
         cout << (char) maze[row][col].type;
         }

      cout << endl;
      }
   }

/////////////////////////////////////////////////*
//Funtion: clearPath
//
//Purpose: clears path
//**********************************************/
void Maze::clearPath()
   {
   for (int row = 0; row < height; row++)
      {
      for (int col = 0; col < width; col++)
         maze[row][col].visited = false;
      }
   }

/////////////////////////////////////////////////*
//Funtion: solveMaze
//
//Purpose: calls solveMaze
//**********************************************/
bool Maze::solveMaze()
    {
    clearPath();
    return (solveMaze(start.xpos, start.ypos));
    }

bool Maze::solveMaze(int col, int row)
    {
    if(maze[col][row].type == END)
        {
	return true;
	}

    if(maze[col][row].type == WALL || maze[col][row].visited)
	{
	return false;
	}

    maze[col][row].visited = true;

    if(row != 0)
	{
        if(solveMaze(col, row-1))
	    {
	    path.push('n');
	    return true;
            }
        }
    if (row != height)
	{
        if(solveMaze(col, row+1))
	    {
	    path.push('s');
	    return true;
	    }
        }


    if(col != 0)
	{
	if(solveMaze(col-1, row))
	    {
	    path.push('w');
	    return true;
	    }
	}

    if(col != width)
	{
	if(solveMaze(col+1, row))
	    {
	    path.push('e');
	    return true;
	    }
	}

    return false;
    }


void Maze::printPath()
  {
    while (!path.empty())
      {
        std::cout << path.top() << " ";
	path.pop();
      }
  }
