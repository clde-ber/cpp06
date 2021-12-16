#include "base.hpp"

int main(void)
{
    Base obj;
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        Base * gen = obj.generate();
        Base& genRef = *gen;
        std::cout << "********** explicit downcast -> ptr **********" << std::endl;
        std::cout << ">>>>>>>>>>     ptr value : *gen     <<<<<<<<<<" << std::endl;
        std::cout << ">>>>>>>>>>    [ " << *gen << " ]    <<<<<<<<<<" << std::endl;
        std::cout << "___________________________________________________________________" << std::endl;
        obj.identify(gen);
        std::cout << "********** explicit downcast -> ref **********" << std::endl;
        std::cout << ">>>>>>>>>>     ref value : genRef   <<<<<<<<<<" << std::endl;
        std::cout << ">>>>>>>>>>    [ " << genRef << " ]    <<<<<<<<<<" << std::endl;
        std::cout << "___________________________________________________________________" << std::endl;
        obj.identify(genRef);
        std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
        std::cout << std::endl;
        delete gen ;
    }
} 