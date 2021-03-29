#include <iostream>
#include <string>
#include "HugeInteger.hpp"

int main(int argc, char const *argv[])
{
    std::string num = "-20";
    std::string num2 = "-180";
    HugeInteger hi;
    hi.input(num);
    hi.output();

    HugeInteger hi2;
    hi2.input(num2);
    hi2.output();

    std::cout << hi2.add(hi).output() << std::endl;
    std::cout << HugeInteger("1000").subtract(HugeInteger("1234")).output() << std::endl;

    HugeInteger("1234").isEqualTo(HugeInteger("+1234")) ? std::cout << "equal" : std::cout << "!equal";
    std::cout << std::endl;

    HugeInteger h("12");
    std::cout << h.add(h).output();

    HugeInteger h5("-111");
    HugeInteger h6("60");

    h5.multiply(h6);
    std::cout << h5.output();

    HugeInteger h7("16");
    HugeInteger h8("-3");

    try
    {
        std::cout << h7.divide(h8).output();
    }
    catch (const char *e)
    {
        std::cout << e << '\n';
    }

    HugeInteger h9("-9000");
    HugeInteger h10("-2");

    try
    {
        std::cout << h9.modulus(h10).output();
    }
    catch (const char *e)
    {
        std::cout << e << '\n';
    }

    return 0;
}
