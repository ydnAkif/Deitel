#include <iostream>

class EncryptionSystem
{
private:
    int data;
    int firstDigit;
    int secondDigit;
    int thirdDigit;
    int fourthDigit;
    void printDecryptedData();
    void printEncryptedData();

public:
    EncryptionSystem(int);

    int getData();
    void splitDigits();
    void swap();
    void encrypt();
    void decrypt();
};
