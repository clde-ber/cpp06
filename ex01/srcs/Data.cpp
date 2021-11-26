#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

std::ostream & operator<<(std::ostream & o, Data const & rhs)
{
    o << &rhs << std::endl;
    o << rhs.a << std::endl;
    o << rhs.b << std::endl;
    o << rhs.c << std::endl;
    o << rhs.d << std::endl;
    o << rhs.e << std::endl;
    o << rhs.f << std::endl;
    o << rhs.ptdr << std::endl;
    return o;
}

Data const & Data::operator=(Data const & rhs)
{
    return rhs;
}
