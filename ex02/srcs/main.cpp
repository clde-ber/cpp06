#include "base.hpp"

int main(void)
{
    Base *obj = NULL;
    Base *test = new Base();
    
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        obj = generate();
        std::cout << "identify (ref)" << std::endl;
        identify(*obj);
        std::cout << "identify (pointer)" << std::endl;
        identify(obj);
        delete obj;
    }
    std::cout << "identify (ref)" << std::endl;
    identify(*test);
    std::cout << "identify (pointer)" << std::endl;
    identify(test);
    delete test;
} 