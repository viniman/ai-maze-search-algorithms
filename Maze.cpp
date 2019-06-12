//
// Created by viniman on 10/06/19.
//

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include "Maze.h"


Maze::Maze(string path)
{

    ofstream outFile;
    ifstream inFile;
    string inFileName;
    string outFileName;


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

        string temp;

        stream >> this->mazeLines >> this->mazeColumns >> this->numRooms >> this->source >> this->destination;

        rooms = vector<Node*>(numRooms, nullptr);

        for (int i = 0; i < rooms.size(); ++i)
        {
            rooms[i] = new Node(i,3); // calcular valor heuristico aqui e passar no lugar de 3
        }

        //for (auto c : chambers)
        //cout << c->id << endl;

        int room1, room2;
        char direction;
        while (p != nullptr)
        {
            p = strtok(nullptr, "\n");
            stream.clear();
            stream << p;
            stream >> room1 >> room2 >> direction;
            cout << endl << p << endl;
            cout << "asuhaushudahs" << endl;
            //cout << endl << room1 << room2 << direction << "NULL" << endl;
            if (!rooms[room1])
            {
                //chambers[room1]->id = room1;
                cout << endl << room1 << room2 << direction << "NULL" << endl;
            }
            switch (operacao(&room1,&room2))
            {

                case 'R':
                {
                    rooms[room1]->right = rooms[room2];
                    rooms[room2]->left = rooms[room1];
                    break;
                }
                case 'L':
                {
                    rooms[room1]->left = rooms[room2];
                    rooms[room2]->right = rooms[room1];
                    break;
                }
                case 'B':
                {
                    rooms[room1]->botton = rooms[room2];
                    rooms[room2]->top = rooms[room1];
                    break;
                }
                case 'T':
                {
                    rooms[room1]->top = rooms[room2];
                    rooms[room2]->botton = rooms[room1];
                    break;
                }
            }
        }
        cout << "artimanha nananidinanda! Titibum!" << endl;
        for(const auto& c : rooms)
        {
            cout << c->id << " -> ";
            if(c->right) cout << c->right->id << "(R) ";
            if(c->left) cout << c->left->id << "(L) ";
            if(c->botton) cout << c->botton->id << "(B) ";
            if(c->top) cout << c->top->id << "(T) ";
            cout << endl;
        }
        cout << "artimanha nananidinanda! Titibum!" << endl;


        delete[] buffer;
        return;
    }
    cout << "\tFalha na leitura do arquivo!" << endl;
    cout << "\tO caminho tentado foi: \"" << path << "\"." << endl;
    cout << "\tVERIFIQUE se digitou o nome do diretorio path corretamente." << endl;
    exit(0);
}



char Maze::nextOperation()
{
    //if(directionVisited == 'N')

}

void Maze::calculaXY()
{
    // |x2 - x1| + |y2 - y1|
    int i, j;

    auto it = rooms.begin();

    for(i = 0; i < mazeLines; ++i)
    {

        for(j = 0; j < mazeColumns; ++j)
        {
            (*it)->x = i;
            (*it)->x = j;

            ++it;

        }
    }
}

char operacao(Node *no1, Node *no2)
{

    int x1 = no1->x;
    int y1 = no1->y;

    int x2 = no2->x;
    int y2 = no2->y;

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
