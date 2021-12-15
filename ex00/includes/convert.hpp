#ifndef CONVERT_H
#define CONVERT_H

#include <ios>
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

class Conv
{
    private:
        const char* _arg;
        char _argC;
        int _argI;
        float _argF;
        double _argD;
        bool isInt();
        bool isChar();
        bool isFloat();
        bool isDouble();
        void whichType();
        int checkValidC();
        int checkValidI();
        int checkValidF();
        int checkValidD();
        int isConstant();
    public:
        Conv( void );
        Conv( char* const arg );
        Conv( Conv const & rhs );
        Conv const operator=(Conv const & rhs);
        virtual ~Conv( void );
        void printConv();
};

#endif