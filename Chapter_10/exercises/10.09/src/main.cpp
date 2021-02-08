#include <iostream>
#include "HugeInteger.hpp"

int main(int argc, char const *argv[])
{
    HugeInteger int1("99");
    HugeInteger int2(3);

    std::cout << int1 / int2 << std::endl;

    return 0;
}
