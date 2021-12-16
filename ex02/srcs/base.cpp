#include "base.hpp"

/*
**  Operator << overload
*/

std::ostream & operator<<(std::ostream & o, Base const & rhs)
{
    o << &rhs;
    return o;
}

/*
**  Base -
*/

Base::~Base()
{

}

/*
**  A : orthodox canonical from
*/

A::A()
{

}

A::A(A const& rhs)
{
    (void)rhs;
    new (this) A();
}

A const & A::operator=(A const & rhs)
{
    new (this) A(rhs);
    return *this;
}

A::~A()
{

}

/*
**  B : orthodox canonical from
*/

B::B()
{

}

B::B(B const& rhs)
{
    (void)rhs;
    new (this) B();
}

B const & B::operator=(B const & rhs)
{
    new (this) B(rhs);
    return *this;
}

B::~B()
{

}

/*
**  C : orthodox canonical from
*/

C::C()
{

}

C::C(C const& rhs)
{
    (void)rhs;
    new (this) C();
}

C const & C::operator=(C const & rhs)
{
    new (this) C(rhs);
    return *this;
}

C::~C()
{

}

/*
**  Base class methods
*/

void identify(Base * p)
{
    Base * tmp(p);
    tmp = dynamic_cast<A *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<A *>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    tmp = p;
    tmp = dynamic_cast<B *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<B *>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    tmp = p;
    tmp = dynamic_cast<C *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<C *>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    std::cout << "impossible cast" << std::endl;
}

void identify( Base & p)
{
    try
    {
        p = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        try
        {
            p = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
            return ;
        }
        catch(std::exception &e)
        {
            try
            {
                p = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
                return ;
            }
            catch(std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

Base * generate(void)
{
    Base * ptr(0);
    int rand(0);

    switch ((rand = std::rand()) % 3)
    {
        case 0:
            ptr = new A();
            break ;
        case 1:
            ptr = new B();
            break ;
        default:
            ptr = new C();
            break ;
    }
    return ptr;
}