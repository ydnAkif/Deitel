#include <iostream>
#include "Stack.hpp"

int main(int argc, char const *argv[])
{
    Stack<char> charStack;
    char c;

    std::cout << "Enter a sentence:\n";

    while ((c = static_cast<char>(std::cin.get())) != '\n')
    {
        charStack.push(c);
    }

    std::cout << "\nThe sentence in reverse is \n";

    while (!charStack.isEmpty())
    {
        std::cout << charStack.pop();
    }

    std::cout << std::endl;

    return 0;
}
