#include <iostream>

int main()
{
    std::cout << std::boolalpha << "Logical AND (&&)"
              << "\nfalse && false: " << (false && false)
              << "\nfalse && true: " << (false && true)
              << "\ntrue && false: " << (true && false)
              << "\ntrue && true: " << (true && true)
              << std::endl
              << std::endl;

    std::cout << "Logical OR (||)"
              << "\nfalse || false: " << (false || false)
              << "\nfalse || true: " << (false || true)
              << "\ntrue || false: " << (true || false)
              << "\ntrue || true: " << (true || true)
              << std::endl
              << std::endl;

    std::cout << "Logical NOT (!)"
              << "\n!false: " << (!false) << "\n!true: " << (!true) << std::endl;
    return 0;
}