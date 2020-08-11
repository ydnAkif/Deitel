#include <iostream>
#include "EncryptionSystem.hpp"

int main()
{
    EncryptionSystem es;
    int passCode{0};

    std::cout << "Welcome to encryption/decryption system"
              << std::endl
              << std::endl;

    std::cout << "Enter a 4 digit passcode to be encrypted: ";
    std::cin >> passCode;

    es.encrypt(passCode);

    std::cout << std::endl
              << "Encrypted passcode: "
              << es.getEncPassCode()
              << std::endl
              << std::endl;

    std::cout << "Decrypted passcode: "
              << es.decrypt(es.getEncPassCode())
              << std::endl;

    return 0;
}
