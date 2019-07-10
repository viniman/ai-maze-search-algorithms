//
// Created by viniman on 07/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_UTILS_H
#define AI_MAZE_SEARCH_ALGORITHMS_UTILS_H

#include <string>
#include "Maze.h"
#include <stack>

class Utils
{
public:
    static Maze instanceReader(const std::string &instancePathName);
    static Maze *mazeGeneratorRecursiveBacktracker(unsigned int m, unsigned int n, bool writeInstance);
    static void newGeneratorRandomized(unsigned int m, unsigned int n, unsigned int roomsWithDoor);
    static bool emptyRoom(unsigned long long int& iterator, unsigned long long int& room, unsigned int& m, unsigned int& n, unsigned int& r);
    static void writeToFile(string str, string pathTosave);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_UTILS_H
