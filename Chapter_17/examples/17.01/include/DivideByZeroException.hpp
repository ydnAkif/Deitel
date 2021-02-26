#ifndef DIVIDE_BY_ZERO_EXCEPTION_HPP
#define DIVIDE_BY_ZERO_EXCEPTION_HPP

#include <stdexcept>

class DivideByZeroException : public std::runtime_error
{

public:
    DivideByZeroException() : std::runtime_error("attempted to divide by zero")
    {
    }
};

#endif