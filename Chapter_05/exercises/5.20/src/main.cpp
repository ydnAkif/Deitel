#include <iostream>
#include <iomanip>

bool isPythagoreanTriple(int, int, int);
int main()
{
    int counter{0};
    std::cout << "All Pythagorean Triples up to sides of 500"
              << std::endl;

    std::cout << "Number"
              << std::setw(9)
              << "Side1 "
              << std::setw(9)
              << "Side2"
              << std::setw(9)
              << "Side3"
              << std::endl;

    for (int i = 1; i <= 500; ++i)
    {

        for (int j = i + 1; j <= 500; ++j)
        {
            for (int k = j + 1; k <= 500; ++k)
            {
                if (isPythagoreanTriple(i, j, k))
                {
                    ++counter;
                    std::cout << std::setw(3)
                              << counter
                              << std::setw(9)
                              << i
                              << std::setw(9)
                              << j
                              << std::setw(9)
                              << k
                              << std::endl;
                }
            }
        }
    }
    std::cout << std::endl
              << std::endl
              << "Total "
              << counter
              << " Pythagorean Triples found!!"
              << std::endl;
    return 0;
}

bool isPythagoreanTriple(int a, int b, int c)
{
    int hypotenuse = std::max(a, std::max(b, c));

    if (hypotenuse == a)
    {
        return (b * b + c * c == hypotenuse * hypotenuse);
    }
    else if (hypotenuse == b)
    {
        return (a * a + c * c == hypotenuse * hypotenuse);
    }
    else
    {
        return (a * a + b * b == hypotenuse * hypotenuse);
    }
}