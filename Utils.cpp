//
// Created by viniman on 07/06/19.
//

// https://stackoverflow.com/questions/15160889/how-can-i-make-an-unordered-set-of-pairs-of-integers-in-c
// https://stackoverflow.com/questions/53796118/alternative-to-find-for-determining-whether-an-unordered-set-contains-a-key

#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include "Utils.h"
#include "Maze.h"

using namespace std;

Maze Utils::instanceReader(const string &instancePathName)
{

}

/**
 * Mazes generated with a depth-first search have a low branching factor and contain many long corridors,
 * because the algorithm explores as far as possible along each branch before backtracking. [Wikipedia]
 * https://en.wikipedia.org/wiki/Maze_generation_algorithm
 * @param m
 * @param n
 * @return
 */
Maze * Utils::mazeGeneratorRecursiveBacktracker(unsigned int m, unsigned int n, bool writeInstance)
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
            mazeGenerated->weightMatrix[currentCell->getId()/mazeGenerated->getMazeColumns()][choosenCell->getId()%mazeGenerated->getMazeColumns()] = 1;

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

    ///Salva instancia em arquivo
    if(writeInstance)
    {
        auto hash = [](const std::pair<int, int> &p) { return p.first * 31 + p.second; };
        std::unordered_set<std::pair<int, int>, decltype(hash)> set(8, hash);

        string saveFileName =
                "instance_" + to_string(m) + "_" + to_string(n) + "_" + to_string(mazeGenerated->getOrigin()->getId()) +
                "_" + to_string(mazeGenerated->getDestination()->getId()) + ".in";
        stringstream ss;
        ss << m << " " << n << " " << mazeGenerated->getOrigin()->getId() << " "
           << to_string(mazeGenerated->getDestination()->getId()) << endl;

        for (const auto &it : mazeGenerated->getRooms())
        {

            if (it->getBotton())
            {
                int id1 = it->getId(), id2 = it->getBotton()->getId();
                if (!set.count(make_pair(id1, id2)) && !set.count(make_pair(id2, id1)))
                {
                    ss << id1 << " " << id2 << endl;
                    set.insert(make_pair(id1, id2));
                }
            }
            if (it->getTop())
            {
                int id1 = it->getId(), id2 = it->getTop()->getId();
                if (!set.count(make_pair(id1, id2)) && !set.count(make_pair(id2, id1)))
                {
                    ss << id1 << " " << id2 << endl;
                    set.insert(make_pair(id1, id2));
                }
            }
            if (it->getRight())
            {
                int id1 = it->getId(), id2 = it->getRight()->getId();
                if (!set.count(make_pair(id1, id2)) && !set.count(make_pair(id2, id1)))
                {
                    ss << id1 << " " << id2 << endl;
                    set.insert(make_pair(id1, id2));
                }
            }
            if (it->getLeft())
            {
                int id1 = it->getId(), id2 = it->getLeft()->getId();
                if (!set.count(make_pair(id1, id2)) && !set.count(make_pair(id2, id1)))
                {
                    ss << id1 << " " << id2 << endl;
                    set.insert(make_pair(id1, id2));
                }
            }
        }
        writeToFile(ss.str(), saveFileName);
    }

    delete maze;
    return mazeGenerated;
}

///long long int ???
bool Utils::emptyRoom(unsigned long long int& iterator, unsigned long long int& room, unsigned int& m, unsigned int& n, unsigned int& r){
    if(r - room + 1 == n * m - iterator)
        return false;
    else
        return rand() % 100 < ((double) r/(m*n)) * 100 - 5;
}

/*
namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };

}
*/

//auto hash = [](const std::pair<int, int>& p){ return p.first * 31 + p.second; };
//std::unordered_set<std::pair<int, int>, decltype(hash)> u_edge_(8, hash);

void Utils::newGeneratorRandomized(unsigned int m, unsigned int n, unsigned int roomsWithDoor)
{
    unsigned long long int * M = nullptr, room = 0, origin = 0, destination = 0;

    stringstream fileString;
    fstream file;

    srand(time(NULL));

    M = new unsigned long long int[m * n];

    for(unsigned long long int i = 0; i < m * n; ++i){
        if(room > roomsWithDoor || emptyRoom(i, room, m, n, roomsWithDoor))
            M[i] = 0;
        else {
            if(room == 0)
                origin = i;
            else if(room == roomsWithDoor-1)
                destination = i;

            M[i] = i;
            room++;
        }
    }

    fileString << "instance_" << m << "_" << n << "_" << origin << "_" << destination  << ".in"; //roomsWithDoor
    file.open(fileString.str(), fstream::out);

    file << m << " " << n << " " << M[origin] << " " << M[destination] << "\n"; //roomsWithDoor <<

    for(unsigned long long int i = 0; i < m * n; ++i)
    {
        cout << M[i] << " ";
        if((i+1)%n==0)
            cout << "\n";

    }



    ///////////////////////////////////////////////////////////////////////////////
    long long int rooms = roomsWithDoor,  currentPosition, i = 0, j = 0;

    //inputFile >> m >> n >> rooms >> origin >> destination;
    auto hash = [](const std::pair<int, int>& p){ return p.first * 31 + p.second; };
    std::unordered_set<std::pair<int, int>, decltype(hash)> set(8, hash);

    //unordered_set <pair<int,int>> set;

    vector<long long int> matrix(m * n, 0);

    for(i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            matrix[i * n + j] = M[i * n + j];

    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j){
            currentPosition = i * n + j;
            if(!matrix[currentPosition])
                continue;
            if(j != n - 1 && matrix[currentPosition + 1] && !set.count(make_pair(currentPosition + 1, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition + 1)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition + 1] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition + 1], 'R');
                set.insert(make_pair(currentPosition, currentPosition + 1));
            }
            if(j != 0 && matrix[currentPosition - 1] && !set.count(make_pair(currentPosition - 1, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition - 1)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition - 1] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition - 1], 'L');
                set.insert(make_pair(currentPosition, currentPosition - 1));
            }
            if(i != m - 1 && matrix[currentPosition + n] && !set.count(make_pair(currentPosition + n, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition + n)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition + n] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition + n], 'B');
                set.insert(make_pair(currentPosition, currentPosition + n));
            }
            if(i != 0 && matrix[currentPosition - n] && !set.count(make_pair(currentPosition - n, currentPosition)) && !set.count(make_pair(currentPosition, currentPosition - n)))
            {
                file << matrix[currentPosition] << " " << matrix[currentPosition - n] << endl;//maze->addDoor(matrix[currentPosition], matrix[currentPosition - n], 'T');
                set.insert(make_pair(currentPosition, currentPosition - n));
            }
        }
    }



    ///////////////////////////////////////////////////////////////////////////////

    file.close();
}

void Utils::writeToFile(string strToWrite, string pathTosave)
{
    fstream file;
    file.open(pathTosave, fstream::out);
    file << strToWrite;
    file.close();
}

