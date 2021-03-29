#include <iostream>

int main()
{
    int x{4};
    int y{8};
    int a{10};
    int b{5};
    int g{2};
    int i{4};
    int j{9};

    std::cout << "Current variable values are:"
              << std::endl
              << "x = "
              << x
              << ", y = "
              << y
              << ", a = "
              << a
              << ", b = "
              << b
              << ", g = "
              << g
              << ", i = "
              << i
              << ", j = "
              << j
              << std::endl
              << std::endl;

    if ((!(x < 5) && !(y >= 7)) == (!((x < 5) || (y >= 7))))
    {
        std::cout << "!(x < 5) && !(y >= 7) is equivalent to"
                  << " !((x < 5) || (y >= 7))"
                  << std::endl
                  << std::endl;
    }

    if ((!(a == b) || !(g != 5)) == (!((a == b) && (g != 5))))
    {
        std::cout << "!(a == b) || !(g != 5) is equivalent to"
                  << " !((a == b) && (g != 5))"
                  << std::endl
                  << std::endl;
    }

    if ((!((x <= 8) && (y > 4))) == (!(x <= 8) || !(y > 4)))
    {
        std::cout << "!((x <= 8) && (y > 4)) is equivalent to"
                  << " !(x <= 8) || !(y > 4)"
                  << std::endl
                  << std::endl;
    }

    if ((!((i > 4) || (j <= 6))) == (!(i > 4) && !(j <= 6)))
    {
        std::cout << "!((i > 4) || (j <= 6)) is equivalent to"
                  << " !(i > 4) && !(j <= 6)"
                  << std::endl
                  << std::endl;
    }

    return 0;
}