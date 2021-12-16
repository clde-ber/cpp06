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
**  Base : orthodox canonical from
*/

Base::Base()
{

}

Base::Base(Base const& rhs)
{
    (void)rhs;
    new (this) Base();
}

Base const & Base::operator=(Base const & rhs)
{
    new (this) Base(rhs);
    return *this;
}

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

void Base::identify(Base * p)
{
    Base * tmp(p);
    tmp = dynamic_cast<A *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<A *>(p);
        std::cout << ">>>>>>>>>>            A             <<<<<<<<<<" << std::endl;
        return ;
    }
    else
        std::cout << "/!\\ impossible cast /!\\" << std::endl;
    tmp = p;
    tmp = dynamic_cast<B *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<B *>(p);
        std::cout << ">>>>>>>>>>            B             <<<<<<<<<<" << std::endl;
        return ;
    }
    else
        std::cout << "/!\\ impossible cast /!\\" << std::endl;
    tmp = p;
    tmp = dynamic_cast<C *>(tmp);
    if (tmp)
    {
        p = dynamic_cast<C *>(p);
        std::cout << ">>>>>>>>>>            C             <<<<<<<<<<" << std::endl;
        return ;
    }
    else
        std::cout << "/!\\ impossible cast /!\\" << std::endl;
}

void Base::identify( Base & p)
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
        error += '\n';
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
        error += '\n';
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
        error += '\n';
    }
    std::cout << error << std::endl;
}

Base * Base::generate(void)
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