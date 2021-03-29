#include <iostream>

int qualityPoints(int);
int main()
{
    int average{0};

    std::cout << "Input student average : ";
    std::cin >> average;

    std::cout << "Quality Point: "
              << qualityPoints(average)
              << std::endl;

    return 0;
}

int qualityPoints(int points)
{
    if (points >= 90)
    {
        return 4;
    }
    else if (points >= 80)
    {
        return 3;
    }
    else if (points >= 70)
    {
        return 2;
    }
    else if (points >= 60)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}