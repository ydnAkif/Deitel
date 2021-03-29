#include <iostream>

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1};

int main()
{
    std::cout << "global x in main is "
              << x
              << std::endl;
    int x = 5;

    std::cout << "local x in main's outer scope is "
              << x
              << std::endl;

    {
        int x = 7;

        std::cout << "local x in main's inner scope is "
                  << x
                  << std::endl;
    }

    std::cout << "local x in main's outer scope is "
              << x
              << std::endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    std::cout << std::endl
              << "local x in main is "
              << x
              << std::endl;
}

void useLocal()
{

    int x = 25;

    std::cout << std::endl
              << "local x is "
              << x
              << " on entering useLocal"
              << std::endl;

    ++x;

    std::cout << std::endl
              << "local x is "
              << x
              << " on exiting useLocal"
              << std::endl;
}
void useStaticLocal()
{

    static int x = 50;

    std::cout << std::endl
              << "local static x is "
              << x
              << " on entering useStaticLocal"
              << std::endl;

    ++x;

    std::cout << std::endl
              << "local static x is "
              << x
              << " on exiting useStaticLocal"
              << std::endl;
}
void useGlobal()
{

    std::cout << std::endl
              << "global x is "
              << x
              << " on entering useGlobal"
              << std::endl;

    x *= 10;

    std::cout << std::endl
              << "global x is "
              << x
              << " on exiting useGlobal"
              << std::endl;
}