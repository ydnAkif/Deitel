#include <iostream>
#include "BucketSort.hpp"

int main()
{

    BucketSort sortArray;

    std::cout << "Array elements in original order:\n";
    sortArray.displayElements();

    sortArray.sort();

    std::cout << "Array elements in sorted order:\n";
    sortArray.displayElements();

    return 0;
}
