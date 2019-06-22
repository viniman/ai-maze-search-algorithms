#include <iostream>
#include <string>
#include <set>
#include <sstream>

#include "Maze.h"
#include "Utils.h"
#include "Backtracking.h"
#include "Depth.h"

using namespace std;




int main(int argc, char** argv)
{
    string instanceFileName = "../instances/instance10_10_1.in";
    Maze maze(instanceFileName);
    Backtracking::backtrackingSearchAlgorithm(maze);
    Depth::DepthSearchAlgorithm(maze);
    return 0;
}