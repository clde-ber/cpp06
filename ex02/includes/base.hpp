#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class   Base
{
    public :
        virtual ~Base();
};

class   A : public Base
{
    public :
        A();
        A(A const & rhs);
        A const & operator=(A const & rhs);
        virtual ~A();
};

class   B : public Base
{
    public :
        B();
        B(B const & rhs);
        B const & operator=(B const & rhs);
        virtual ~B();
};

class   C : public Base
{
    public :
        C();
        C(C const & rhs);
        C const & operator=(C const & rhs);
        virtual ~C();
};

Base * generate(void);
void identify(Base * p);
void identify( Base & p);
std::ostream & operator<<(std::ostream & o, Base const & rhs);

#endif