#include <iostream>
#include "EncryptionSystem.hpp"

int main()
{

    int passCode{0};

    std::cout << "Welcome to encryption/decryption system"
              << std::endl
              << std::endl;

    std::cout << "Enter a 4 digit passcode to be encrypted: ";
    std::cin >> passCode;
    EncryptionSystem es(passCode);
    es.encrypt();

    std::cout << std::endl
              << std::endl;
    std::cout << "Enter a 4 digit passcode to be decrypted: ";
    std::cin >> passCode;
    EncryptionSystem dc(passCode);
    dc.decrypt();

    std::cout << std::endl
              << std::endl;

    return 0;
}
