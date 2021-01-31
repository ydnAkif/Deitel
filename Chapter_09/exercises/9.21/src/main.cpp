#include <iostream>
#include "IntegerSet.hpp"

int main(int argc, char const *argv[])
{
    int a1[3] = {1, 2, 3};
    int a2[3] = {2, 3, 4};

    IntegerSet emptySet;
    emptySet.printSet();

    IntegerSet set1(a1, 3);
    IntegerSet set2(a2, 3);
    set1.printSet();
    set2.printSet() ;

    set1.unionOfSets(set2).printSet();
    set1.interSectionOfSets(set2).printSet();

    set1.insertElement(4);
    set2.insertElement(1);

    set1.isEqualTo(set2) ? std::cout << "equal" : std::cout << " not equal";
    std::cout << std::endl;

    set1.deleteElements(1);
    set1.printSet();

    return 0;
}
