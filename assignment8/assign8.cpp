/**************************************************************
 PROGRAM:    CSCI 241 Assignment 8
 PROGRAMMER: your name
 LOGON ID:   your z-ID
 DUE DATE:   due date of assignment
 
 FUNCTION:   This program tests the functionality of the
             Maze class.
***************************************************************/

#include <iostream>
#include <string>
#include "Maze.h"

using std::cout;
using std::endl;
using std::to_string;

int main()
   {
   Maze m;

   for (int i = 1; i <= 3; ++i)
      {
      m.readMaze("maze" + to_string(i) + ".txt");

      m.printMaze();

      cout << endl;

      // Test with invalid path that hits a wall
      if (m.solveMaze())
         {
         cout << "Valid path: ";
         m.printPath();
         cout << endl;
         }
      else
         cout << "There is no valid path through this maze.\n";
      }

   return 0;
   }
