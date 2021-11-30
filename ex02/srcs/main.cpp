#include "base.hpp"

int main(void)
{
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        Base * gen = generate();
        Base & genRef = *gen;
        std::cout << "[ " << gen << " ]"<< std::endl;
        std::cout << "********** explicit downcast -> ptr **********" << std::endl;
        try
        {
            identify(gen);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "********** explicit downcast -> ref **********" << std::endl;
        try
        {
            identify(genRef);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        delete gen ;
    }
}