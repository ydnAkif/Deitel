#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    std::cout << "According to islower:\n"
              << (islower('p') ? "p is a" : "p is not a") << " lowercase letter\n"
              << (islower('P') ? "P is a" : "P is not a") << " lowercase letter\n"
              << (islower('5') ? "5 is a" : "5 is not a") << " lowercase letter\n"
              << (islower('!') ? "! is a" : "! is not a") << " lowercase letter\n";

    std::cout << "\nAccording to isupper:\n"
              << (isupper('D') ? "D is a" : "d is not a") << " uppercase letter\n"
              << (isupper('d') ? "d is a" : "d is not a") << " uppercase letter\n"
              << (isupper('8') ? "8 is a" : "8 is not a") << " upperrcase letter\n"
              << (isupper('$') ? "$ is a" : "$ is not a") << " uppercase letter\n";

    std::cout << "\nu converted to uppercase is "
              << static_cast<char>(toupper('u'))
              << "\n7 converted to uppercase is "
              << static_cast<char>(toupper('7'))
              << "\n$ converted to uppercase is "
              << static_cast<char>(toupper('$'))
              << "\nL converted to lowercase is "
              << static_cast<char>(tolower('L'));
    return 0;
}
