#include <iostream>
#include "DoubleSubscriptedArray.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
     DoubleSubscriptedArray intArray(10, 2);

     intArray(1, 1) = 3;

     cout << "intArray\n"
          << intArray;
     cout << "intArray(1,1): " << intArray(1, 1) << endl;

     DoubleSubscriptedArray intArray2 = intArray;

     intArray2(0, 5) = 15;
     intArray2(1, 9) = 7;

     cout << "intArray2\n"
          << intArray2;

     intArray2 == intArray ? (std::cout << "intArray equal intArray2") : (std::cout << "intArray != intArray2");

     return 0;
}
