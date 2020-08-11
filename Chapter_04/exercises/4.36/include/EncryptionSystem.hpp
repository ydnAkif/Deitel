#include <iostream>

class EncryptionSystem
{
private:
    int plainPassCode;
    int encPassCode;

public:
    EncryptionSystem();
    ~EncryptionSystem();

    //Setters
    bool setPlainPassCode(int);
    void setEncPassCode(int);

    //Getters

    int getPlainPassCode();
    int getEncPassCode();

    bool validatePlainPass(int);
    bool encrypt(int);
    int decrypt(int);
    int swapDigits(int);
    void clearPlainPass();
    void clearEncPass();
};
