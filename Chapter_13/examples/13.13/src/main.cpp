#include <iostream>

int main(int argc, char const *argv[])
{

    std::cout << " Before using showpoint" << std::endl
              << "9.9900 prints as: " << 9.9900 << std::endl
              << "9.9000 prints as: " << 9.9000 << std::endl
              << "9.0000 prints as: " << 9.0000 << std::endl << std::endl;

    std::cout << std::showpoint
              << "After using showpoint" << std::endl
              << "9.9900 prints as: " << 9.9900 << std::endl
              << "9.9000 prints as: " << 9.9000 << std::endl
              << "9.0000 prints as: " << 9.0000 << std::endl;  


    return 0;
}
