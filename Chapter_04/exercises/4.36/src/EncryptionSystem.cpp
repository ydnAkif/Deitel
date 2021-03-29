#include "EncryptionSystem.hpp"

EncryptionSystem::EncryptionSystem(int data)
{
    this->data = data;
}

//Getters
int EncryptionSystem::getData()
{
    return data;
}

void EncryptionSystem::splitDigits()
{
    firstDigit = ((data % 10000) / 1000);
    secondDigit = ((data % 1000) / 100);
    thirdDigit = ((data % 100) / 10);
    fourthDigit = ((data % 10) / 1);
}

void EncryptionSystem::swap()
{
    int temp;

    temp = firstDigit;
    firstDigit = thirdDigit;
    thirdDigit = temp;

    temp = secondDigit;
    secondDigit = fourthDigit;
    fourthDigit = temp;
}

void EncryptionSystem::encrypt()
{
    splitDigits();

    firstDigit = (firstDigit + 7) % 10;
    secondDigit = (secondDigit + 7) % 10;
    thirdDigit = (thirdDigit + 7) % 10;
    fourthDigit = (fourthDigit + 7) % 10;

    swap();

    printEncryptedData();
}

void EncryptionSystem::decrypt()
{
    splitDigits();
    swap();

    firstDigit = (firstDigit >= 7) ? firstDigit - 7 : (firstDigit + 10) - 7;
    secondDigit = (secondDigit >= 7) ? secondDigit - 7 : (secondDigit + 10) - 7;
    thirdDigit = (thirdDigit >= 7) ? thirdDigit - 7 : (thirdDigit + 10) - 7;
    fourthDigit = (fourthDigit >= 7) ? fourthDigit - 7 : (fourthDigit + 10) - 7;

    printDecryptedData();
}

void EncryptionSystem::printEncryptedData()
{
    std::cout << "Encrypted data is: "
              << firstDigit
              << secondDigit
              << thirdDigit
              << fourthDigit
              << std::endl;
}

void EncryptionSystem::printDecryptedData()
{
    std::cout << "Decrypted data is: "
              << firstDigit
              << secondDigit
              << thirdDigit
              << fourthDigit
              << std::endl;
}