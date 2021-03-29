#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int counter{0};

    std::cout << "N\t"
              << "10*N\t"
              << "100*N\t"
              << "1000*N\n";

    while (counter < 5)
    {
        ++counter;
        std::cout << counter << "\t"
                  << 10 * counter << "\t"
                  << 100 * counter << "\t"
                  << 1000 * counter << "\n";
    }

    return 0;
}
