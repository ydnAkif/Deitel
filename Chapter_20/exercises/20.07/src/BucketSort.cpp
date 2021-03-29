#include <iostream>
#include <ctime>
#include <random>
#include "BucketSort.hpp"

BucketSort::BucketSort()
{
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);

    for (size_t i = 0; i < arraySize; i++)
        data[i] = randomInt(engine);
}

void BucketSort::displayElements() const
{
    for (size_t i = 0; i < arraySize; ++i)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

void BucketSort::sort()
{
    int totalDigits;
    zeroBucket();

    totalDigits = numberOfDigits();

    for (size_t i = 1; i <= totalDigits; i++)
    {
        distributeElements(i);
        collectElements();

        if (i != totalDigits)
            zeroBucket();
    }
}

void BucketSort::distributeElements(int digit)
{
    int divisor = 10;
    int bucketNumber;
    int elementNumber;

    for (int i = 1; i < digit; ++i)
        divisor *= 10;

    for (size_t k = 0; k < arraySize; ++k)
    {
        bucketNumber = (data[k] % divisor - data[k] % (divisor / 10)) / (divisor / 10);
        elementNumber = ++bucket[bucketNumber][0];
        bucket[bucketNumber][elementNumber] = data[k];
    }
}

void BucketSort::collectElements()
{
    int subscript = 0;

    for (size_t i = 0; i < 10; ++i)
    {
        for (size_t j = 1; j <= bucket[i][0]; j++)
            data[subscript++] = bucket[i][j];
    }
}

int BucketSort::numberOfDigits()
{
    int largest = data[0];
    int digits = 0;

    for (int i = 1; i < arraySize; i++)
    {
        if (data[i] > largest)
            largest = data[i];
    }

    while (largest != 0)
    {
        digits++;
        largest /= 10;
    }

    return digits;
}

void BucketSort::zeroBucket()
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < arraySize; j++)
            bucket[i][j] = 0;
    }
}
