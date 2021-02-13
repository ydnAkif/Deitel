#include <iostream>

std::ostream &bell(std::ostream &);

std::ostream &carriageReturn(std::ostream &);

std::ostream &tab(std::ostream &);
std::ostream &endLine(std::ostream &);

int main(int argc, char const *argv[])
{
    std::cout << "Testing the tab manipulator:" << endLine
              << 'a' << tab << 'b' << tab << 'c' << endLine;
    std::cout << "Testing the carriageReturn and bell manipulators:"
              << endLine << "..........";
    std::cout << bell;
    std::cout << carriageReturn << "-----" << endLine;

    return 0;
}

std::ostream &bell(std::ostream &output)
{
    return output << '\a';
}

std::ostream &carriageReturn(std::ostream &output)
{
    return output << '\r';
}

std::ostream &tab(std::ostream &output)
{
    return output << '\t';
}

std::ostream &endLine(std::ostream &output)
{
    return output << '\n'
                  << std::flush;
}