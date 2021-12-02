#include "Data.hpp"

int main( void )
{
    Data ptr;
    double d1(0.5f);
    double d2(1.2);
    char* chaine(const_cast<char*>("chaine"));

    ptr.a = 'c';
    ptr.b = 17;
    ptr.c = 5.5f;
    ptr.d = chaine;
    ptr.e = "string";
    ptr.f[0] = &d1;
    ptr.f[1] = &d2;
    ptr.ptdr = NULL;
    std::cout << "**********      address of Data ptr      **********" << std::endl;
    std::cout << ptr << std::endl;
    std::cout << "******** address returned by deserialize ********" << std::endl;
    std::cout << *deserialize(serialize(&ptr)) << std::endl;
    return 0;
}