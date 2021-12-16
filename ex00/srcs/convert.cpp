#include "convert.hpp"

Conv::Conv( void ) : _arg("")
{
    std::cout << "constructor by default called" << std::endl;
    whichType();
}

Conv::Conv( char* const arg ) : _arg(arg)
{
    std::cout << "constructor called" << std::endl;
    whichType();
}

Conv::Conv( Conv const & rhs ) : _arg(rhs._arg)
{
    std::cout << "constructor by copy called" << std::endl;
    whichType();
}

Conv const Conv::operator=(Conv const & rhs)
{
    std::cout << "assignation operator called" << std::endl;
    new (this) Conv(rhs);
    return *this;
}

Conv::~Conv( void )
{
    std::cout << "destructor called" << std::endl;
}

const char* Conv::IncorrectTypeException::what() const throw()
{
    return "type exception : types are [ char ] or [ int ] or [ float ] or [ double ]";
}

bool Conv::isChar()
{
    if (std::strlen(this->_arg) == 1 && this->_arg[0] <= 127 and this->_arg[0] >= 32
    and (!(this->_arg[0] >= '0' and this->_arg[0] <= '9')))
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
    while (i < std::strlen(this->_arg)- 1)
    {
        if (!std::isdigit(this->_arg[i]) and _arg[i] != '.')
            return 0;
        i++;
    }
    if (this->_arg[i] == 'f')
        return 1;
    return 0;  
}

bool Conv::isDouble()
{
    size_t i(0);

    if (this->_arg[i] == '-')
        i++;
    while (i < std::strlen(this->_arg)- 1)
    {
        if (!std::isdigit(this->_arg[i]) and _arg[i] != '.')
            return 0;
        i++;
    }
    if (this->_arg[i] == 'f' or !std::isdigit(this->_arg[i]))
        return 0;
    return 1;
}

void Conv::whichType()
{
    if (isChar())
    {
        _argC = _arg[0];
        _argI = static_cast<int>(std::atof(_arg));
        _argF = static_cast<float>(std::atof(_arg));
        _argD = std::atof(_arg);
    }
    else if (isInt() or isFloat() or isDouble())
    {
        _argC = static_cast<char>(std::atof(_arg));
        _argI = static_cast<int>(std::atof(_arg));
        _argF = static_cast<float>(std::atof(_arg));
        _argD = std::atof(_arg);
    }
    else
        throw IncorrectTypeException();
}

bool Conv::checkValidC()
{
    if (this->_argC >= 32 and this->_argC <= 127)
        return 1;
    std::cout << "Non displayable" << std::endl;
    return 0;
}

bool Conv::checkValidI()
{
    if (this->_argI >= INT_MIN and this->_argI <= INT_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

bool Conv::checkValidF()
{
    if (this->_argF >= -FLT_MAX and this->_argF <= FLT_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

bool Conv::checkValidD()
{
    if (this->_argD >= -DBL_MAX and this->_argD <= DBL_MAX)
        return 1;
    std::cout << "Impossible" << std::endl;
    return 0;
}

bool Conv::isConstant()
{
    if (this->_argD != this->_argD or this->_argF == INFINITY or -this->_argF == INFINITY)
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (this->_argD != this->_argD)
        {
            std::cout << "float: " << "nanf" << std::endl;
            std::cout << "double: " << "nan" << std::endl;
        }
        else if (this->_argF == INFINITY)
        {
            std::cout << "float: " << _argF << "f" << std::endl;
            std::cout << "double: " << _argD <<std::endl;
        }
        else
        {
            std::cout << "float: " << _argF << "f" << std::endl;
            std::cout << "double: " << _argD << std::endl;
        }
        return 1;
    }
    return 0;
}

void Conv::printChar()
{
    if (checkValidC())
        std::cout << "char: '" << this->_argC << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void Conv::printInt()
{
    if (checkValidI() and !isChar())
        std::cout << "int: " << this->_argI << std::endl;
    else
        std::cout << "int: impossible" << std::endl; 
}

void Conv::printFloat()
{
    if (checkValidF() and !isChar())
    {
        std::cout << "float: " << _arg;
        if (!(std::strchr(_arg, '.')))
            std::cout << ".0f" << std::endl;
        else if (!isFloat())
            std::cout << "f" << std::endl;
        else
            std::cout << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;  
}

void Conv::printDouble()
{
    if (checkValidD() and !isChar())
    {
        std::cout << "double: ";
        if (isFloat())
        {
            for (unsigned long i = 0; i < std::strlen(_arg) - 1; i++)
                std::cout << this->_arg[i];
            std::cout << std::endl;
        }
        else if (!(std::strchr(_arg, '.')))
            std::cout << _arg << ".0" << std::endl;
        else
            std::cout << _arg << std::endl;  
    }
    else
        std::cout << "double: impossible" << std::endl;
}

void Conv::printConv()
{
    if (!isConstant())
    {   
        printChar();
        printInt();
        printFloat();
        printDouble();
    }
}
