#include "base.hpp"

std::ostream & operator<<(std::ostream & o, Base const & rhs)
{
    o << &rhs;
    return o;
}

void identify(Base * p)
{
    Base * tmp(p);
    tmp = dynamic_cast<A *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<A *>(p);
        std::cout << ">>>>>>>>>>            A             <<<<<<<<<<" << std::endl;
        return ;
    }
    tmp = p;
    tmp = dynamic_cast<B *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<B *>(p);
        std::cout << ">>>>>>>>>>            B             <<<<<<<<<<" << std::endl;
        return ;
    }
    tmp = p;
    tmp = dynamic_cast<C *>(tmp);
    if (p)
    {
        p = dynamic_cast<C *>(p);
        std::cout << ">>>>>>>>>>            C             <<<<<<<<<<" << std::endl;
        return ;
    }
    std::cout << "/!\\ impossible cast /!\\" << std::endl;
}

void identify( Base & p)
{
    std::string error("");

    try
    {
        p = dynamic_cast<A &>(p);
        std::cout << ">>>>>>>>>>            A             <<<<<<<<<<" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        error += e.what();
    }
    try
    {
        p = dynamic_cast<B &>(p);
        std::cout << ">>>>>>>>>>            B             <<<<<<<<<<" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        error += e.what();
    }
    try
    {
        p = dynamic_cast<C &>(p);
        std::cout << ">>>>>>>>>>            C             <<<<<<<<<<" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        error += e.what();
    }
    std::cout << error << std::endl;
}

Base * generate(void)
{
    Base * ptr(0);
    int rand(0);

    switch ((rand = std::rand()) % 3)
    {
        case 0:
            std::cout << ">>>>>>>>>>           rand           <<<<<<<<<< : " << rand << std::endl;
            ptr = new A();
            break ;
        case 1:
            std::cout << ">>>>>>>>>>           rand           <<<<<<<<<< : " << rand << std::endl;
            ptr = new B();
            break ;
        default:
            std::cout << ">>>>>>>>>>           rand           <<<<<<<<<< : " << rand << std::endl;
            ptr = new C();
            break ;
    }
    return ptr;
}