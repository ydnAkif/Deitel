#include <iostream>
#include <exception>

void throwException();

int main(int argc, char const *argv[])
{
    try
    {
        std::cout << "\nmain invokes function throwException()\n";
        throwException();
        std::cout << "This should not print\n";
    }
    catch(std::exception &)
    {
        std::cout << "\n\nException handled in main\n";
    }

    std::cout << "Program control continiues after catch in main\n";

    return 0;
}

void throwException()
{
    try
    {
        std::cout << "   Function throwException() throws an exception\n";
        throw std::exception();
    }
    catch(std::exception& )
    {
        std::cout << "   Exception handled in function throwException()"
                  << "\n   Function throwException() rethrows exception";
        throw;
    }

    std::cout << "This also should not print\n";
}