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
}             Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream & operator<<(std::ostream & o, Data const & rhs);

#endif
