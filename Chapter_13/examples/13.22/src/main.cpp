#include <iostream>

int main(int argc, char const *argv[])
{
    int integerValue;
    std::cout << "Before a bad input operation:"
              << "\ncin.rdstate():" << std::cin.rdstate()
              << "\n  cin.eof()" << std::cin.eof()
              << "\n  cin.fail()" << std::cin.fail()
              << "\n  cin.bad()" << std::cin.bad()
              << "\n  cin.good()" << std::cin.good()
              << "\n\nExpects an integer, but enter a character: ";
    std::cin >> integerValue;

    std::cout << std::endl;

    std::cout << "After a bad input operation:"
              << "\ncin.rdstate():" << std::cin.rdstate()
              << "\n  cin.eof()" << std::cin.eof()
              << "\n  cin.fail()" << std::cin.fail()
              << "\n  cin.bad()" << std::cin.bad()
              << "\n  cin.good()" << std::cin.good() << std::endl
              << std::endl;

    std::cin.clear();

    std::cout << "After cin.clear()"
              << "\ncin.fail(): " << std::cin.fail()
              << "\ncin.good(): " << std::cin.good() << std::endl;

    return 0;
}
