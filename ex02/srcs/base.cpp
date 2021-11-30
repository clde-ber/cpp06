#include "base.hpp"

std::ostream & operator<<(std::ostream & o, Base const & rhs)
{
    o << &rhs;
    return o;
}

void identify(Base * p)
{
    if ((p = dynamic_cast<A *>(p)))
    {
        std::cout << "A" << std::endl;
        return ;
    }
    if ((p = dynamic_cast<B *>(p)))
    {
        std::cout << "B" << std::endl;
        return ;
    }
    if ((p = dynamic_cast<C *>(p)))
    {
        std::cout << "C" << std::endl;
        return ;
    }
    std::cout << "/!\\ impossible cast /!\\" << std::endl;
}

void identify( Base & p)
{
    p = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    p = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    p = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
}

Base * generate(void)
{
    Base * ptr(0);
    int rand(0);

    switch ((rand = std::rand()) % 3)
    {
        case 0:
            std::cout << "rand " << rand << std::endl;
            ptr = new A();
            break ;
        case 1:
            std::cout << "rand " << rand << std::endl;
            ptr = new B();
            break ;
        case 2:
            std::cout << "rand " << rand << std::endl;
            ptr = new C();
            break ;
        default:
            std::cout << "rand " << rand << std::endl;
            ptr = 0;
    }
    return ptr;
}