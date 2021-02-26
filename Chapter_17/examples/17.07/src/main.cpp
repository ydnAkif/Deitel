#include <iostream>
#include <memory>
#include "Integer.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "Creating a unique_ptr object that points to an Integer\n";

    std::unique_ptr<Integer> ptrToInteger(new Integer(7));

    std::cout << "\nUsing the unique_ptr to manipulate the Integer\n";
    ptrToInteger->setInteger(99);

    std::cout << "Integer after setInteger: " << (*ptrToInteger).getInteger()
              << "\n\nTerminating program" << std::endl;

    return 0;
}
