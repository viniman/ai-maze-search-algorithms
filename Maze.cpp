//
// Created by viniman on 10/06/19.
//

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include "Maze.h"
#include <cmath>

#define HAS_RAND_WEIGHT false
#define VALUE_MAX_RAND_WEIGHT 200

Maze::Maze(string path)
{

    ofstream outFile;
    ifstream inFile;
    string inFileName;
    string outFileName;

    int originId, destinationId;

    inFile.open(path);

    if (inFile)
    {
        cout << "\tLendo arquivo instancia" << endl;
        cout << "\tPath (caminho): " << path << endl;

        // get length of file:
        inFile.seekg(0, std::ifstream::end);
        auto length = static_cast<unsigned int>(inFile.tellg());
        inFile.seekg(0, std::ifstream::beg);

        //criando e inicializando buffer
        //buffer contem o arquivo inteiro
        auto *buffer = new char[length];
        inFile.read(buffer, length);
        inFile.close();


        stringstream stream;

        cout << "\tLendo Instancia\n";
        char *p = strtok(buffer, "\n");

        stream << p;

        stream >> this->mazeLines >> this->mazeColumns  >> originId >> destinationId;

        initiateWeightMatrix(HAS_RAND_WEIGHT, VALUE_MAX_RAND_WEIGHT);

        this->numRooms = this->mazeLines * this->mazeColumns;

        rooms = vector<Node*>(numRooms, nullptr);

        for (int i = 0; i < rooms.size(); ++i)
        {
            rooms[i] = new Node(i); // calcular valor heuristico aqui e passar no construtor

        }


        this->origin = rooms[originId];
        this->destination = rooms[destinationId];

        calculaXY();

        for(auto& it : rooms)
            it->setHeuristicValue(manhattanDistance(it));

        unsigned int room1, room2;
        char direction;
        while (p != nullptr)
        {
            p = strtok(nullptr, "\n");
            stream.clear();
            stream << p;
            stream >> room1 >> room2;

            addDoor(room1, room2);
            //weightMatrix[room1/mazeColumns][room2%mazeColumns] = 1;
            //weightMatrix[room2/mazeColumns][room1%mazeColumns] = 1;
        }

        delete[] buffer;
        return;
    }
    cout << "\tFalha na leitura do arquivo!" << endl;
    cout << "\tO caminho tentado foi: \"" << path << "\"." << endl;
    cout << "\tVERIFIQUE se digitou o nome do diretorio path corretamente." << endl;
    exit(-1);
}


/**
 * Construtor de labirintos com suas dimensões, pondendo setar para adicionar as portas ou não
 * @param m
 * @param n
 * @param addDoors
 * @param origin
 * @param dest
 */
Maze::Maze(unsigned int m, unsigned int n, bool addDoors, unsigned int origin, unsigned int dest)
{
    mazeLines = m;
    mazeColumns = n;
    numRooms = m*n;
    //rooms = vector<Node*>(numRooms, nullptr);

    for(int i = 0; i < numRooms; ++i)
    {
        //Node* node = new Node(i);
        //rooms[i] = new Node(i);
        rooms.push_back(new Node(i));
    }

    initiateWeightMatrix(HAS_RAND_WEIGHT, VALUE_MAX_RAND_WEIGHT);

    //for(auto i : rooms)
    //cout << i->getId() << ", ";
    cout << endl;

/*    for(unsigned int room1 = 0, room2 = 0; room1 < n-1; ++room1)
    {
        room2 = room1+1;
        addDoor(room1, room2);
        for(unsigned int room2 = room1; room2 < n-1; ++room2)
        {
            room1*=10;
            room2 = room1+10;
            addDoor(room1, room2);
        }

    }*/

    calculaXY();

    // Necessario para o algoritmo de geracao de labirinto (cria todas as portas)
    if(addDoors)
    {
        //Adiciona portas na horizontal
        for (unsigned int i = 0; i < n*m-1; ++i)
        {
            if(i%n != n-1)
                addDoor(i, i+1);

        }
        //Adiciona portas na vertical
        for (unsigned int i = 0; i < (n-1)*m; ++i)
        {
            addDoor(i, i+n);
        }
        /*for (unsigned int room2 = room1; room2 < m; ++room2)
        {
            if(room2/n) //n
                addDoor(room2, room2 + 1);
            //if(room2<=m*n-n) //m
            addDoor(room2, room2 + n);

        }*/
    }
/*    else
    {
        for(auto& it : rooms)
            it->setHeuristicValue(manhattanDistance(it));
    }*/
}


Maze::~Maze()
{
    //liberar memória
    for(int i = 0;i < this->mazeLines; ++i)
        delete [] weightMatrix[i];
    delete [] weightMatrix;
}

void Maze::initiateWeightMatrix(bool randomizedWeight, unsigned int maxRandValue)
{
    this->weightMatrix = new int*[mazeLines];
    for (int i = 0; i < mazeColumns; ++i)
    {
        this->weightMatrix[i] = new int[mazeColumns];
    }

    for(int i = 0;i < mazeLines; ++i)
    {
        for(int j = i;j < mazeColumns; ++j)
        {
            if(randomizedWeight)
            {
                int randValue = rand()%maxRandValue;
                weightMatrix[i][j] = randValue;
                weightMatrix[j][i] = randValue;
            }
            else
            {
                weightMatrix[i][j] = 1;
                weightMatrix[j][i] = 1;
            }

        }
    }


}

const vector<Node *> &Maze::getRooms() const
{
    return rooms;
}


void Maze::calculaXY()
{
/*
    int i, j;

    auto it = rooms.begin();
    */
    for(auto& itRoom: rooms)
    {
        itRoom->setX(itRoom->getId()/mazeColumns);
        itRoom->setY(itRoom->getId()%mazeColumns);
    }
/*
    for(i = 0; i < mazeLines; ++i)
    {

        for(j = 0; j < mazeColumns; ++j)
        {
            (*it)->x = i;
            (*it)->y = j;

            if((i * mazeColumns + j + 1) >= numRooms)
                return;
            ++it;

        }
    }*/
}

// |x2 - x1| + |y2 - y1|
int Maze::manhattanDistance(Node *no1)
{
    return abs(destination->getX() - no1->getX()) + abs(destination->getY() - no1->getY());
}



char Maze::operacao(Node *no1, Node *no2)
{

    int x1 = no1->getX();
    int y1 = no1->getY();

    int x2 = no2->getX();
    int y2 = no2->getY();

    if((x1 == x2) && (y1+1 == y2)) //Verifica se no2 está a direita de no1
    {
        return 'R';
    }
    else if((x1 == x2) && (y2+1 == y1)) //Verifica se no2 está a Esquerda de no1
    {
        return 'L';

    }
    else if((y1 == y2) && (x1 - 1 == x2)) //Verifica se no2 está a acima de no1
    {
        return 'T';
    }
    else if((y1 == y2) && (x1 + 1 == x2)) //Verifica se no2 está a Embaixo de no1
    {
        return 'B';
    }
    else //Erro
    {
        exit(-1);
    }
}

unsigned int Maze::getMazeLines() const
{
    return mazeLines;
}

unsigned int Maze::getMazeColumns() const
{
    return mazeColumns;
}

unsigned int Maze::getNumRooms() const
{
    return numRooms;
}

Node *Maze::getOrigin() const
{
    return origin;
}

Node *Maze::getDestination() const
{
    return destination;
}

Node * Maze::getRoom(int id) const
{
    return rooms[id];
}

void Maze::setVisitedAllFalse()
{
    for(auto& it : rooms)
        it->setNonVisited();
}

void Maze::addDoor(unsigned int room1, unsigned int room2)
{
    switch (operacao(rooms[room1],rooms[room2]))
    {
        case 'R':
        {
            rooms[room1]->setRight(rooms[room2]);
            rooms[room2]->setLeft(rooms[room1]);
            break;
        }
        case 'L':
        {
            rooms[room1]->setLeft(rooms[room2]);
            rooms[room2]->setRight(rooms[room1]);
            break;
        }
        case 'B':
        {
            rooms[room1]->setBotton(rooms[room2]);
            rooms[room2]->setTop(rooms[room1]);
            break;
        }
        case 'T':
        {
            rooms[room1]->setTop(rooms[room2]);
            rooms[room2]->setBotton(rooms[room1]);
            break;
        }
    }
}

void Maze::setDestination(unsigned int id)
{
    destination = rooms[id];
}

void Maze::setOrigin(unsigned int id)
{
    origin = rooms[id];
}



