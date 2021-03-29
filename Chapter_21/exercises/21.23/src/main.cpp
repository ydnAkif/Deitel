#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::string::const_iterator x = alpha.begin();
    std::string::const_iterator x2;

    for (int p = 1; p <= 14; ++p)
    {
        int w;
        int count = 0;

        for (int k = 13; k >= p; --k)
            std::cout << ' ';

        x2 = x;

        for (int c = 1; c <= p; ++c)
        {
            std::cout << *x2;
            ++x2;
            count++;
        }

        for (w = 1, x2 -= 2; w < count; w++)
        {
            std::cout << *x2;
            x2--;
        }

        x++;
        std::cout << '\n';
    }

    return 0;
}
