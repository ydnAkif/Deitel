#include <iostream>

long numberOfSeconds(int, int, int);

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;

    std::cout << "A Program to print number of elapsed seconds between two clocks"
              << std::endl
              << std::endl;

    std::cout << "Enter hours minutes seconds (start time) : ";
    std::cin >> h1 >> m1 >> s1;

    std::cout << "Enter hours minutes seconds (finish time) : ";
    std::cin >> h2 >> m2 >> s2;

    std::cout << "Difference : "
              << (numberOfSeconds(h2, m2, s2) - numberOfSeconds(h1, m1, s1))
              << " seconds."
              << std::endl;

    return 0;
}

long numberOfSeconds(int h, int m, int s)
{
    if (h > 12)
    {
        h -= 12;
    }

    return (((h * 60) * 60) + (m * 60) + s);
}