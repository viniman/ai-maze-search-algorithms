//
// Created by viniman on 07/06/19.
//

#include <iostream>
#include "Utils.h"
#include "Maze.h"

using namespace std;

Maze Utils::instanceReader(const string &instancePathName)
{

}

/**
 * Mazes generated with a depth-first search have a low branching factor and contain many long corridors,
 * because the algorithm explores as far as possible along each branch before backtracking. [Wikipedia]
 * @param m
 * @param n
 * @return
 */
Maze * Utils::mazeGenerator(unsigned int m, unsigned int n)
{
    srand (time(NULL));
    //vector<char> operations = {'L', 'R', 'T', 'B'};
    Maze* maze = new Maze(m, n, true);
    // Criacao com nenhuma porta, como se tivesse parede entre todos
    Maze* mazeGenerated = new Maze(m, n, false);

    stack<Node*> stackRooms;
    Node *currentCell = maze->getRoom(0);
    currentCell->setVisited();
    mazeGenerated->setOrigin(currentCell->getId());

    unsigned int countVisited = 1;

    while (countVisited < maze->getNumRooms())
    {
        if (!currentCell->getRight()->isVisited() || !currentCell->getLeft()->isVisited() ||
            !currentCell->getTop()->isVisited() || !currentCell->getBotton()->isVisited())
        {

            vector<char> notVisited;
            if (currentCell->getRight() && !currentCell->getRight()->isVisited())
                notVisited.push_back('R');
            if (currentCell->getLeft() && !currentCell->getLeft()->isVisited())
                notVisited.push_back('L');
            if (currentCell->getTop() && !currentCell->getTop()->isVisited())
                notVisited.push_back('T');
            if (currentCell->getBotton() && !currentCell->getBotton()->isVisited())
                notVisited.push_back('B');

            unsigned long ranPos = rand() % notVisited.size();
            Node *choosenCell = currentCell->roomDirectionReturn(notVisited[ranPos]);

            stackRooms.push(currentCell);

            mazeGenerated->addDoor(currentCell->getId(), choosenCell->getId());

            currentCell = choosenCell;
            currentCell->setVisited();
            ++countVisited;
        }
        else if (!stackRooms.empty())
        {

            currentCell = stackRooms.top();
            stackRooms.pop();
        }
    }
    mazeGenerated->setDestination((m*n)-1);
    cout << "Labirinto gerado" << endl;
    delete maze;
    return mazeGenerated;
}
