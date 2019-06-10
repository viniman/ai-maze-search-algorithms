#include <iostream>
#include <string>
#include <set>
#include <sstream>

#include "Maze.h"
#include "Utils.h"
#include "Backtracking.h"

using namespace std;




int main(int argc, char** argv)
{
    string instanceFileName = "../instances/instance10_10_3.in";
    Maze maze(instanceFileName);
    Backtracking::backtrackingSearchAlgorithm(maze);
    return 0;
}