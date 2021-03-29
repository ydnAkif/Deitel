#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

template <typename T, size_t size>
void quickSort(std::array<T, size> &, size_t, size_t);

template <typename T, size_t size>
int partition(std::array<T, size> &, size_t, size_t);

void swap(int *const, int *const);

int main(int argc, char const *argv[])
{
    const size_t MAX_NUMBER = 100;
    const size_t arraySize = 10;
    std::array<int, arraySize> arrayToBeSorted;
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);
    int loop;

    for (loop = 0; loop < arraySize; ++loop)
        arrayToBeSorted[loop] = randomInt(engine);

    std::cout << "Initial array values are:\n";

    for (loop = 0; loop < arraySize; ++loop)
        std::cout << std::setw(4) << arrayToBeSorted[loop];

    std::cout << "\n\n";

    if (arraySize == 1)
        std::cout << "Array is sorted: " << arrayToBeSorted[0] << '\n';
    else
    {
        quickSort(arrayToBeSorted, 0, arraySize - 1);
        std::cout << "The sorted vector values are:\n";

        for (loop = 0; loop < arraySize; ++loop)
            std::cout << std::setw(4) << arrayToBeSorted[loop];
        std::cout << std::endl;
    }

    return 0;
}

template <typename T, size_t size>
void quickSort(std::array<T, size> &data, size_t first, size_t last)
{
    int currentLocation;

    if (first >= last)
        return;

    currentLocation = partition(data, first, last);
    quickSort(data, first, currentLocation - 1);
    quickSort(data, currentLocation + 1, last);
}

template <typename T, size_t size>
int partition(std::array<T, size> &data, size_t left, size_t right)
{
    int position = left;

    while (true)
    {
        while (data[position] <= data[right] && position != right)
            right--;

        if (position == right)
            return position;
        if (data[position] > data[right])
        {
            swap(&data[position], &data[right]);
            position = right;
        }

        while (data[left] <= data[position] && left != position)
            left++;

        if (position == left)
            return position;
        if (data[left] > data[position])
        {
            swap(&data[position], &data[left]);
            position = left;
        }
    }
}

void swap(int *const ptr1, int *const ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}