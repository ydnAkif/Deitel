#include <iostream>
#include <stdexcept>

void function3()
{
    std::cout << "In function 3" << std::endl;
    throw std::runtime_error("runtime_error in function 3");
}

void function2()
{

    std::cout << "In function 2" << std::endl;
    function3();
}

void function1()
{
    std::cout << "In function 1" << std::endl;
    function2();
}

int main(int argc, char const *argv[])
{
    try
    {
        std::cout << "function1 is called inside main" << std::endl;
        function1();
    }
    catch (std::runtime_error &error)
    {
        std::cout << "Exception occurred: " << error.what() << std::endl;
        std::cout << "Exception handled in main" << std::endl;
    }

    return 0;
}
