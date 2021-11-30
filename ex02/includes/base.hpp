#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class   Base
{
    public :
        virtual ~Base() {}
};

class   A : public Base
{
    public :
        A() {}
        ~A() {}
};

class   B : public Base
{
    public :
        B() {}
        ~B() {}
};

class   C : public Base
{
    public :
        C() {}
        ~C() {}
};

Base * generate(void);
void identify(Base * p);
void identify( Base & p);
std::ostream & operator<<(std::ostream & o, Base const & rhs);

#endif