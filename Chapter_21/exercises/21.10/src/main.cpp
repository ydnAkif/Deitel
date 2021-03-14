#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string first;
    std::string last;

    std::cout << "Enter first name: ";
    std::cin >> first;

    std::cout << "Enter last name: ";
    std::cin >> last;

    first.append(" ").append(last);

    std::cout << "The full name is: " << first << std::endl;

    return 0;
}
