#include <iostream>
#include <iterator>

int main(int argc, char const *argv[])
{

    std::cout << "Enter two integers: ";

    std::istream_iterator<int> inputInt(std::cin);

    int number1 = *inputInt;
    ++inputInt;
    int number2 = *inputInt;

    std::ostream_iterator<int> outputInt(std::cout);

    std::cout << "The sum is ";
    *outputInt = number1 + number2;
    std::cout << std::endl;

    return 0;
}
