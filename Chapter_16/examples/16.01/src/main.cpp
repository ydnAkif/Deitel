#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

char nextLetter();

int main(int argc, char const *argv[])
{
    std::array<char, 10> chars;
    std::ostream_iterator<char> output(std::cout, " ");
    std::fill(chars.begin(), chars.end(), '5');

    std::cout << "chars after filling with 5s:" << std::endl;
    std::copy(chars.cbegin(), chars.cend(), output);

    std::fill_n(chars.begin(), 5, 'A');

    std::cout << std::endl
              << std::endl
              << "chars after filling five elements With As:" << std::endl;
    std::copy(chars.cbegin(), chars.cend(), output);

    std::generate(chars.begin(), chars.end(), nextLetter);

    std::cout << std::endl
              << std::endl
              << "chars after generating letters A-J:" << std::endl;
    std::copy(chars.cbegin(), chars.cend(), output);

    std::generate_n(chars.begin(), 5, nextLetter);

    std::cout << std::endl
              << std::endl
              << "chars after generating K-O for the"
              << " first five elements:" << std::endl;
    std::copy(chars.cbegin(), chars.cend(), output);

    std::cout << std::endl;

    return 0;
}

char nextLetter()
{
    static char letter = 'A';
    return letter++;
}