#include <iostream>
#include "Integer.hpp"

Integer::Integer(int i)
:value(i)
{
    std::cout << "Constructor for Integer " << value << std::endl;
}

Integer::~Integer()
{
    std::cout << "Destructor for Integer " << value << std::endl;
}

void Integer::setInteger(int i)
{
    value = i;
}

int Integer::getInteger() const{
    return value;
}

