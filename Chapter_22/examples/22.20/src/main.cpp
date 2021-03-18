#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    std::cout << "According to isspace:\nNewline "
              << (isspace('\n') ? "is a" : "is not a")
              << " whitespace character\nHorizontal tab "
              << (isspace('\t') ? "is a" : "is not a")
              << " whitespace character\n"
              << (isspace('%') ? "% is a" : "% is not a")
              << " whitespace character\n";

    std::cout << "\nAccording to iscntrl:\nNewline "
              << (iscntrl('\n') ? "is a" : "is not a")
              << " control character\n"
              << (iscntrl('$') ? "$ is a" : "$ is not a")
              << " control character\n";

    std::cout << "\nAccording to ispunct:\n"
              << (ispunct(';') ? "; is a" : "; is not a")
              << " punctuation character\n"
              << (ispunct('Y') ? "Y is a" : "Y is not a")
              << " punctuation character\n"
              << (ispunct('#') ? "# is a" : "# is not a")
              << " punctuation character\n";

    std::cout << "\nAccording to isprint:\n"
              << (isprint('$') ? "$ is a" : "$ is not a")
              << " printing character\nAlert "
              << (isprint('\a') ? "is a" : "is not a")
              << " printing character\nSpace "
              << (isprint(' ') ? "is a" : "is not a")
              << " printing character\n";

    std::cout << "\nAccording to isgraph:\n"
              << (isgraph('Q') ? "Q is a" : "Q is not a")
              << " printing character other than a space\nSpace "
              << (isgraph(' ') ? "is a" : "is not a")
              << " printing character other than a space" << std::endl;

    return 0;
}
