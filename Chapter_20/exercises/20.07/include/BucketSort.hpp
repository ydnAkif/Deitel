#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include <array>

class BucketSort
{
public:
    BucketSort();
    void displayElements() const;
    void sort();

private:
    static const size_t arraySize = 10;
    std::array<int, arraySize> data;
    std::array<std::array<int, arraySize>, arraySize> bucket;

    void distributeElements(int);
    void collectElements();
    int numberOfDigits();
    void zeroBucket();
};

#endif