#include <iostream>
#include <string>
#include <array>

const int SIZE = 19;

void output(const std::array<std::string, SIZE>, const int);
void quickSort(std::array<std::string, SIZE> &, int, int);

int main(int argc, char const *argv[])
{
    std::array<std::string, 19> animals = {"Macaw", "Lion", "Tiger",
                                           "Bear", "Toucan", "Zebra",
                                           "Puma", "Cat", "Yak", "Boar",
                                           "Fox", "Ferret", "Crocodile",
                                           "Alligator", "Elk", "Ox",
                                           "Horse", "Eagle", "Hawk"};

    std::cout << "before:";
    output(animals, SIZE);
    quickSort(animals, 0, SIZE - 1);

    std::cout << "\nafter:";
    output(animals, SIZE);

    return 0;
}

void output(const std::array<std::string, SIZE> ani, const int length)
{
    for (int j = 0; j < length; ++j)
        std::cout << (j % 10 ? ' ' : '\n') << ani[j];
    std::cout << std::endl;
}

void quickSort(std::array<std::string, SIZE> &a, int first, int last)
{
    int partition(std::array<std::string, SIZE> &, int, int);
    int currentLocaiton;

    if (first >= last)
        return;

    currentLocaiton = partition(a, first, last);

    quickSort(a, first, currentLocaiton - 1);
    quickSort(a, currentLocaiton + 1, last);
}

int partition(std::array<std::string, 19> &b, int left, int right)
{
    int pos = left;

    while (true)
    {
        while (b[pos] <= b[right] && pos != right)
            --right;

        if (pos == right)
            return pos;

        if (b[pos] > b[right])
        {
            b[pos].swap(b[right]);
            pos = right;
        }

        while (b[left] <= b[pos] && pos != left)
            ++left;

        if (pos == left)
            return pos;

        if (b[left] > b[pos])
        {
            b[pos].swap(b[left]);
            pos = left;
        }
    }
}
