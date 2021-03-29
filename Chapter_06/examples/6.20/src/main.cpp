#include <iostream>

int squareByValue(int);
void squareByReference(int &);

int main()
{
    int x = 2;
    int z = 4;

    std::cout << "x= "
              << x
              << " before squareByValue"
              << std::endl;
    std::cout << "Value returned by squareByValue: "
              << squareByValue(x)
              << std::endl;
    std::cout << "x= "
              << x
              << " after squareByValue"
              << std::endl;
    std::cout << "z= "
              << z
              << " before squareByReference"
              << std::endl;

    squareByReference(z);

    std::cout << "z= "
              << z
              << " after squareByReference"
              << std::endl;
}

int squareByValue(int number) { return number *= number; }
void squareByReference(int &numberRef) { numberRef *= numberRef; }