#include <iostream>
#include "Array.hpp"
using namespace std;

void outputArray(const Array &); // prototype

int main()
{
   Array integers1(7);     // 7-element Array
   outputArray(integers1); // output Array integers1
   outputArray(3);         // convert 3 to an Array and output Array’s contents
   outputArray(Array(3));  // explicit single-argument constructor call
} // end main

// print Array contents
void outputArray(const Array &arrayToOutput)
{
   cout << "The Array received has " << arrayToOutput.getSize()
        << " elements. The contents are:\n"
        << arrayToOutput << endl;
}