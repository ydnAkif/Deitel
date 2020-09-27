#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<unsigned int> randomInt(1, 6);

    const size_t arraySize = 7;

    std::array<int, arraySize> frequency = {};

    for (unsigned int roll = 1; roll <= 6000000; ++roll)
    {
        ++frequency[randomInt(engine)];
    }

    std::cout << "Face"
              << std::setw(13)
              << "Frequency"
              << std::endl;

    for (size_t face = 1; face < frequency.size(); ++face)
    {
        std::cout << std::setw(4)
                  << face
                  << std::setw(13)
                  << frequency[face]
                  << std::endl;
    }

    return 0;
}
