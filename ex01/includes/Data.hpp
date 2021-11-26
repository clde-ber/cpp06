#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

typedef void* uintptr_t;

typedef struct Data
{
    char a;
    int b;
    float c;
    char* d;
    std::string e;
    double* f[2];
    void* ptdr;
    Data const & operator=(Data const & rhs);
}             Data;

uintptr_t serialize(Data* ptr); //Cette fonction retour-nera le paramètre sous la forme d’un nombre entier
Data* deserialize(uintptr_t raw); // Cette fonction ren-voie les données brutes que vous avez créées à l’aide de la fonction"serialize"à unestructureData
std::ostream & operator<<(std::ostream & o, Data const & rhs);

#endif
