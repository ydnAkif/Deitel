#include <iostream>

int main(int argc, char const *argv[])
{
    const char *const word = "again";

    std::cout << "Value of word is: " << word << std::endl
              << "Value of static_cast<const void * >(word) is: "
              << static_cast<const void *>(word) << std::endl;

    return 0;
}
