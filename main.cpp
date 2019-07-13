#include <iostream>
#include <string>
#include <set>
#include <sstream>

#include "Maze.h"
#include "Utils.h"
#include "Backtracking.h"
#include "Depth.h"
#include "Greedy.h"
#include "AStar.h"
#include "IDAStar.h"
#include "Statistics.h"
#include "Ordered.h"
#include "Breadth.h"

using namespace std;

int main(int argc, char** argv)
{
    srand (time(NULL));
    //Utils::newGeneratorRandomized(5, 5, 15);
    //return 0;

/*
    string instanceFileName = "../instances/instance_30_30_0_899.in";//"../instances/instance10_10_2.in";
    Maze maze(instanceFileName);
    Backtracking::backtrackingSearchAlgorithm(maze);
    Breadth::breadthSearchAlgorithm(maze);
    Depth::DepthSearchAlgorithm(maze);
    Ordered::orderedSearchAlgorithm(maze);
    Greedy::greedySearchAlgorithm(maze);
    AStar::ASearchAlgorithm(maze);
    IDAStar::IDAStarSearchAlgorithm(maze, statistics);
*/

    cout<<"Digite um valor para o tamanho da matriz quadrade: ";

    int unidades;
    cin>>unidades;

    Maze *mazeGenerated = Utils::mazeGeneratorRecursiveBacktracker(unidades, unidades, false);


    Backtracking::backtrackingSearchAlgorithm(*mazeGenerated);
    Backtracking::backtrackingSearchAlgorithmPAI(*mazeGenerated);
    Breadth::breadthSearchAlgorithm(*mazeGenerated);
    Depth::DepthSearchAlgorithm(*mazeGenerated);
    Ordered::orderedSearchAlgorithm(*mazeGenerated);
    Greedy::greedySearchAlgorithm(*mazeGenerated);
    AStar::ASearchAlgorithm(*mazeGenerated);
    IDAStar::IDAStarSearchAlgorithm(*mazeGenerated);

    return 0;
}


/*
void print(Maze& maze)
{
    for (int i = 0; i < maze.getMazeLines(); ++i)
    {
        for (int j = 0; j < maze.getMazeColumns(); ++j)
        {
            cout << maze.getRoom(i*maze.getMazeColumns()+j) <<
        }
    }
}*/
