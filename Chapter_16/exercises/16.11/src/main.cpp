#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

int main(int argc, char const *argv[])
{
    std::list<int> list1 = {1, 3, 7, 5, 11, 9};
    std::list<int> list2 = {2, 12, 6, 4, 10, 8};
    std::ostream_iterator<int> output(std::cout, " ");

    list1.sort();
    list2.sort();
    std::list<int> list3;

    std::merge(list1.cbegin(), list1.cend(), list2.cbegin(), list2.cend(), std::back_inserter(list3));
    std::copy(list3.begin(), list3.end(), output);

    return 0;
}
