#include <iostream>
#include <cctype>
#include <cstring>
#include "Stack.hpp"

int main(int argc, char const *argv[])
{
    Stack<char> charStack;
    char c, string1[80], string2[80];
    int i = 0;

    std::cout << "Enter a sentence:\n";

    while ((c = static_cast<char>(std::cin.get())) != '\n')
    {
        if (isalpha(c))
        {
            string1[i++] = c;
            charStack.push(c);
        }
    }

    string1[i] = '\0';
    i = 0;

    while (!charStack.isEmpty())
    {
        string2[i++] = charStack.pop();
    }

    string2[i] = '\0';

    if (strcmp(string1, string2) == 0)
        std::cout << "\nThe sentence is a palindrome\n";
    else
        std::cout << "\nThe sentence is not a palindrome\n";

    return 0;
}
