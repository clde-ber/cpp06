#include "convert.hpp"

Conv::Conv( void ) : _arg(0), _argC(0), _argI(0), _argF(0), _argD(0)
{
}

Conv::Conv( char* const arg ) : _arg(arg)
{
    whichType();
}

Conv::Conv( Conv const & rhs ) : _arg(rhs._arg), _argC(rhs._argC), _argI(rhs._argI), _argF(rhs._argF), _argD(rhs._argD)
{
}

Conv const Conv::operator=(Conv const & rhs)
{
    return rhs;
}

Conv::~Conv( void )
{
}

bool Conv::isChar()
{
    if (std::strlen(this->_arg) == 1 && this->_arg[0] <= '0' and this->_arg[0] >= '9')
        return 1;
    return 0;
}

bool Conv::isInt()
{
    size_t i(0);

    if (this->_arg[i] == '-')
        i++;
    while (i < std::strlen(this->_arg))
    {
        if (!std::isdigit(this->_arg[i]))
            return 0;
        i++;
    }
    return 1;
}

bool Conv::isFloat()
{
    size_t i(0);

    if (this->_arg[i] == '-')
        i++;
    while (i < std::strlen(this->_arg) - 1)
        i++;
    if (this->_arg[i] == 'f')
        return 1;
    return 0;  
}

void Conv::whichType()
{
    if (this->isInt() == 1)
    {
        this->_argC = static_cast<char>(std::atoi(this->_arg));  
        this->_argI = std::atoi(this->_arg);
        this->_argF = static_cast<float>(std::atoi(this->_arg));
        this->_argD = this->_argF;
    }
    else if (this->isChar() == 1)
    {
        this->_argC = this->_arg[0];
        this->_argI = static_cast<int>(this->_arg[0]);
        this->_argF = static_cast<float>(this->_argI);
        this->_argD = static_cast<double>(this->_argF);
    }
    else
    {
        this->_argC = static_cast<char>(std::atof(this->_arg));
        this->_argI = static_cast<int>(std::atof(this->_arg));
        this->_argF = std::atof(this->_arg);
        this->_argD = std::atof(this->_arg);
    }
}

int Conv::checkValidC()
{
    if (this->_argC >= 32 and this->_argC <= 127)
        return 1;
    std::cout << "Non displayable" << std::endl;
    return 0;
}

int Conv::checkValidI()
{
    if (this->_argI >= INT_MIN and this->_argI <= INT_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

int Conv::checkValidF()
{
    if (this->_argF >= FLT_MIN and this->_argF <= FLT_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

int Conv::checkValidD()
{
    if (this->_argD >= DBL_MIN and this->_argD <= DBL_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

int Conv::isConstant()
{
    if (this->_argD != this->_argD or this->_argF == INFINITY or -this->_argF == INFINITY)
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (this->_argD != this->_argD)
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (this->_argF == INFINITY)
        {
            std::cout << "float: + inff" << std::endl;
            std::cout << "double: + inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return 1;
    }
    return 0;
}

void Conv::printConv()
{
    if (!isConstant())
    {
        if (checkValidC())
            std::cout << "char: '" << this->_argC << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;    
        if (checkValidI())
            std::cout << "int: " << this->_argI << std::endl;
        else
            std::cout << "int: Out of limits" << std::endl;    
        if (checkValidF())
        {
            std::cout << "float: ";
            if (this->_argI != this->_argF)
            {
                std::cout.unsetf ( std::ios::floatfield );
                std::cout.precision(std::strlen(this->_arg));
                std::cout << this->_argF;
                std::cout << "f" << std::endl;
            }
            else
                std::cout << this->_arg << std::endl; 
        }
        else
            std::cout << "float: Out of limits" << std::endl;    
        if (checkValidD())
        {
            std::cout << "double: ";
            if (this->_argI != this->_argF)
            {
                std::cout.precision(std::strlen(this->_arg));
                std::cout << this->_argD;
                std::cout << std::endl;
            }
            else
            {
                for (size_t i = 0; i < std::strlen(this->_arg) - 1; i++)
                    std::cout << this->_arg[i];
                std::cout << std::endl;
            }
        }
        else
            std::cout << "double: Out of limits" << std::endl;    
    }
}
