#include <iostream>
#include "Stack.hpp"
#include <string>

template <typename T>
void testStack(Stack<T> &theStack,
               const T &value,
               const T &increment,
               size_t size,
               const std::string &stackName)
{
    std::cout << "\nPushing elements onto " << stackName << '\n';
    T pushValue = value;

    for (size_t i = 0; i < size; ++i)
    {
        theStack.push(pushValue);
        std::cout << pushValue << ' ';
        pushValue += increment;
    }

    std::cout << "\n\nPopping elements from " << stackName << '\n';

    while (!theStack.isEmpty())
    {
        std::cout << theStack.top() << ' ';
        theStack.pop();
    }

    std::cout << "\nStack is empty, cannot pop.\n";
}

int main(int argc, char const *argv[])
{
    Stack<double> doubleStack;
    const size_t doubleStackSize = 5;
    testStack(doubleStack, 1.1, 1.1, doubleStackSize, "doubleStack");

    Stack<int> intStack;
    const size_t intStackSize = 10;
    testStack(intStack, 1, 1, intStackSize, "intStack");

    return 0;
}
