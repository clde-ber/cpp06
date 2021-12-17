#include "convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2 or (ac == 2 and !std::strlen(av[1])))
    {
        std:: cout << "please provide one argument [ char ] or [ int ] or [ float ] or [ double ]" << std::endl;
        return 1;
    }
    try
    {
        Conv toConvert(av[1]);
        Conv toConvertCopy(toConvert);

        toConvertCopy.printConv();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}