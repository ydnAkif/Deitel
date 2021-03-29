#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string first("one");
    std::string second("two");

    std::cout << "Before swap:\n first: " << first << "\nsecond: " << second;

    first.swap(second);

    std::cout << "\n\nAfter swap:\n first: " << first << "\nsecond: " << second << std::endl;

    return 0;
}
