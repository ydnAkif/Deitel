#include <iostream>
#include <iomanip>
#include <array>

int main(int argc, char const *argv[])
{
    const size_t responseSize = 20;
    const size_t frequencySize = 6;

    const std::array<unsigned int, responseSize> responses = {1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};

    std::array<unsigned int, frequencySize> frequency = {};

    for (size_t answer = 0; answer < responses.size(); ++answer)
    {
        ++frequency[responses[answer]];
    }

    std::cout << "Rating"
              << std::setw(17)
              << "Frequency"
              << std::endl;

    for (size_t rating = 1; rating < frequency.size();++rating) {
        std::cout << std::setw(6)
                  << rating
                  << std::setw(17)
                  << frequency[rating]
                  << std::endl;
    }

        return 0;
}
