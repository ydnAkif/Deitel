#include <iostream>

int square(int);
int main()
{
    int a = 10;
    std::cout << a
              << " squared: "
              << square(a)
              << std::endl;
}

int square(int n)
{
    return n * n;
}