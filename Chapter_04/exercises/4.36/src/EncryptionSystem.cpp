#include "EncryptionSystem.hpp"

EncryptionSystem::EncryptionSystem()
{
    plainPassCode = 0;
    encPassCode = 0;
}

EncryptionSystem::~EncryptionSystem()
{
    clearPlainPass();
    clearEncPass();
}

//Setters

bool EncryptionSystem::setPlainPassCode(int plain)
{
    if (validatePlainPass(plain))
    {
        plainPassCode = plain;
        return true;
    }
    return false;
}

void EncryptionSystem::setEncPassCode(int enc)
{
    encPassCode = enc;
}

//Getters
int EncryptionSystem::getPlainPassCode()
{
    return plainPassCode;
}

int EncryptionSystem::getEncPassCode()
{
    return encPassCode;
}

//Check plain passcode is 4 digits
bool EncryptionSystem::validatePlainPass(int plain)
{
    int counter{0};

    while (plain > 0)
    {
        plain /= 10;
        counter++;
    }

    return (counter == 4) ? true : false;
}

bool EncryptionSystem::encrypt(int plain)
{
    int first, second, third, fourth, digits, temp1, temp2;
    if (setPlainPassCode(plain))
    {
        temp1 = plain;
        first = (temp1 / 1000 + 7) % 10;
        temp2 = temp1 % 1000;
        second = (temp2 / 100 + 7) % 10;
        temp1 = temp2 % 100;
        third = (temp1 / 10 + 7) % 10;
        temp2 = temp1 % 10;
        fourth = (temp2 + 7) % 10;
        temp1 = first;
        first = third * 1000;
        third = temp1 * 10;
        temp1 = second;
        second = fourth * 100;
        fourth = temp1;
        digits = first + second + third + fourth;

        setEncPassCode(digits);
        clearPlainPass();
        return true;
    }
    std::cout << "ERROR: Invalid length. A 4 digit pass code is required"
              << std::endl;
    return false;
}

int EncryptionSystem::decrypt(int enc)
{
    int first, second, third, fourth, digits, temp1, temp2;

    if (enc == 0)

    {
        enc = getEncPassCode();
    }

    temp1 = enc;
    first = (temp1 / 1000);
    temp2 = temp1 % 1000;
    second = (temp2 / 100);
    temp1 = temp2 % 100;
    third = (temp1 / 10);
    temp2 = temp1 % 10;
    fourth = temp2;
    temp1 = (first + 3) % 10;
    first = (third + 3) % 10 * 1000;
    third = temp1 * 10;
    temp1 = (second + 3) % 10;
    second = (fourth + 3) % 10 * 100;
    fourth = temp1;
    digits = first + second + third + fourth;
    clearEncPass();
    setPlainPassCode(digits);

    return digits;
}

int EncryptionSystem::swapDigits(int digits)
{
    int a, b, c, d, temp, swapped = 0;

    d = digits % 10;
    digits /= 10;

    c = digits % 10;
    digits /= 10;

    b = digits % 10;
    digits /= 10;

    temp = digits;
    a = c;
    c = temp;
    temp = b;
    b = d;
    d = temp;

    swapped = (swapped * 10) + a;
    swapped = (swapped * 10) + b;
    swapped = (swapped * 10) + c;
    swapped = (swapped * 10) + d;

    return swapped;
}

void EncryptionSystem::clearPlainPass()
{
    plainPassCode = 0;
}

void EncryptionSystem::clearEncPass()
{
    encPassCode = 0;
}