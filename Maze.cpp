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

        stream >> this->mazeLines >> this->mazeColumns >> this->rooms >> this->source >> this->destination;

        chambers = vector<Node*>(rooms, nullptr);

        for (int i = 0; i < chambers.size(); ++i)
        {
            chambers[i] = new Node(i,3); // calcular valor heuristico aqui e passar no lugar de 3
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
            if (!chambers[room1])
            {
                //chambers[room1]->id = room1;
                cout << endl << room1 << room2 << direction << "NULL" << endl;
            }
            if(direction == 'R')
            {
                chambers[room1]->right = chambers[room2];
                chambers[room2]->left = chambers[room1];
            }
            else if(direction == 'L')
            {
                chambers[room1]->left = chambers[room2];
                chambers[room2]->right = chambers[room1];
            }
            else if(direction == 'B')
            {
                chambers[room1]->botton = chambers[room2];
                chambers[room2]->top = chambers[room1];
            }
            else if(direction == 'T')
            {
                chambers[room1]->top = chambers[room2];
                chambers[room2]->botton = chambers[room1];
            }

        }
        cout << "artimanha nananidinanda! Titibum!" << endl;
        for(const auto& c : chambers)
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
