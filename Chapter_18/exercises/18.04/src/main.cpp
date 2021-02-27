#include <iostream>
#include "Array.hpp"

int main(int argc, char const *argv[])
{
    Array<int, 5> intArray;

    std::cout << "Enter " << intArray.getSize() << " integer values:\n";
    intArray.inputArray();

    std::cout << "\nTha values in intArray are:\n";
    intArray.outputArray();

    Array<float, 5> floatArray;

    std::cout << "Enter " << floatArray.getSize() << " floating point values:\n";
    floatArray.inputArray();

    std::cout << "\nThe values in the doubleArray are:\n";
    floatArray.outputArray();

    return 0;
}
