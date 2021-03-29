#include <iostream>
#include <array>
#include <ctime>
#include <random>

template <typename T, size_t size>
void bubbleSort(std::array<T, size> &items)
{

    for (size_t i = 1; i < items.size(); ++i)
    {
        bool wasSwapped = false;
        for (size_t j = 0; j < items.size() - i; ++j)
        {
            if (items[j] > items[j + 1])
            {
                T temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
                wasSwapped = true;
            }
        }

        if (!wasSwapped)
            break;
    }
}

int main(int argc, char const *argv[])
{
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);

    const size_t arraySize = 10;
    std::array<int, arraySize> data;

    for (int &item : data)
        item = randomInt(engine);

    std::cout << "Before sorting:\n";

    for (size_t i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    clock_t startTime = clock(), endTime;

    bubbleSort(data);

    endTime = clock();
    std::cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds passed.";
    std::cout << "\nAfter sorting:\n";

    for (size_t i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << ' ';
    }

    return 0;
}
