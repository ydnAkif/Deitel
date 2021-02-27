#include <iostream>
#include "Stack.hpp"

int main(int argc, char const *argv[])
{
    Stack<double> doubleStack;
    const size_t doubleStackSize = 5;
    double doubleValue = 1.1;

    std::cout << "Pushing elements onto doubleStack\n";

    for (size_t i = 0; i < doubleStackSize; ++i)
    {
        doubleStack.push(doubleValue);
        std::cout << doubleValue << ' ';
        doubleValue += 1.1;
    }

    std::cout << "\n\nPopping elements from doubleStack\n";

    while (!doubleStack.isEmpty())
    {
        std::cout << doubleStack.top() << ' ';
        doubleStack.pop();
    }

    std::cout << "\nStack is empty, cannot pop.\n";

    Stack<int> intStack;
    const size_t intStackSize = 10;
    int intValue = 1;

    std::cout << "\nPushing element onto intStack\n";

    for (size_t i = 0; i < intStackSize; ++i)
    {
        intStack.push(intValue);
        std::cout << intValue << ' ';
        intValue += 1;
    }

    std::cout << "\n\nPopping elements from intStack\n";

    while (!intStack.isEmpty())
    {
        std::cout << intStack.top() << ' ';
        intStack.pop();
    }
    std::cout << "\nStack is empty, cannot pop." << std::endl;

    return 0;
}
