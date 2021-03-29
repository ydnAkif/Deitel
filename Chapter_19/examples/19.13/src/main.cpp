#include <iostream>
#include "Stack.hpp"

int main(int argc, char const *argv[])
{
    Stack<int> intStack;

    std::cout << "proccessing an integer Stack" << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        intStack.push(i);
        intStack.printStack();
    }

    int popInteger;

    while (!intStack.isStackEmpty())
    {
        intStack.pop(popInteger);
        std::cout << popInteger << " popped from stack" << std::endl;
        intStack.printStack();
    }

    Stack<double> doubleStack;
    double value = 1.1;

    std::cout << "proccessing a double Stack" << std::endl;

    for (int j = 0; j < 3; ++j)
    {
        doubleStack.push(value);
        doubleStack.printStack();
        value += 1.1;
    }

    double popDouble;

    while (!doubleStack.isStackEmpty())
    {
        doubleStack.pop(popDouble);
        std::cout << popDouble << " popped from stack" << std::endl;
        doubleStack.printStack();
    }

    return 0;
}
