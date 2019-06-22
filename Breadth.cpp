//
// Created by viniman on 09/06/19.
//

#include <queue>
#include "Breadth.h"

using namespace std;

void Breadth::breadthSearchAlgorithm(Maze &maze)
{
    queue<Node*> openedNodeList;
    queue<Node*> closedNodeList;
    Node* searchPointer = maze.getOrigin();
    bool failure, success;
    failure = success = false;

    openedNodeList.push(searchPointer);

    while (!(success || failure))
    {
        if(openedNodeList.empty())
            failure = true;
        else
        {
            Node* currentNode  = openedNodeList.front();
            if(currentNode->getId() == maze.getDestination()->getId())
                success = true;
            else
            {
                /*while () -> Proxima operacao
                {

                }*/
            }
        }
    }


}
