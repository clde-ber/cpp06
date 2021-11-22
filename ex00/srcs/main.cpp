#include "convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    Conv toConvert(av[1]);
    toConvert.printConv();
    return 0;
}