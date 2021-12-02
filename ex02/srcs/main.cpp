#include "base.hpp"

int main(void)
{
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        Base * gen = generate();
        Base& genRef = *gen;
        std::cout << ">>>>>>>>>>    [ " << gen << " ]    <<<<<<<<<<" << std::endl;
        std::cout << "********** explicit downcast -> ptr **********" << std::endl;
        std::cout << ">>>>>>>>>>           *gen           <<<<<<<<<< : [ " << *gen << " ]" << std::endl;
        std::cout << "___________________________________________________________________" << std::endl;
        identify(gen);
        std::cout << "********** explicit downcast -> ref **********" << std::endl;
        std::cout << ">>>>>>>>>>          genRef          <<<<<<<<<< : [ " << genRef << " ]" << std::endl;
        std::cout << "___________________________________________________________________" << std::endl;
        identify(genRef);
        std::cout << std::endl;
        delete gen ;
    }
} 