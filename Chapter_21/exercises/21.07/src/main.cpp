#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string message;
    int key = 13;

    std::cout << "Enter a string: ";
    std::getline(std::cin, message);

    std::string::iterator messageIteretor = message.begin();

    while (messageIteretor != message.end())
    {
        *messageIteretor += key;
        ++messageIteretor;
    }

    std::cout << "\nEncrypted string is: "
              << message << std::endl;

    std::cout << "\n\nEnter encrypted string: ";
    std::getline(std::cin, message);

    messageIteretor = message.begin();
    while (messageIteretor != message.end())
    {
        *messageIteretor -= key;
        ++messageIteretor;
    }

    std::cout << "\nDecrypted string is: "
              << message << std::endl;

    return 0;
}
