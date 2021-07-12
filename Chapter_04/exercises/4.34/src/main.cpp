/******************************************************************************
 
 Exercises 4.34
 
 (Factorial) The factorial of a nonnegative integer n is written n! 
 (pronounced “n factorial”) and is defined as follows:
    n!=n·(n–1)·(n–2)·...·1 (forvaluesofngreaterthan1) and
    n!=1 (forn=0orn=1).
 For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120. Use while statements in each 
 of the following:
a) Write a program that reads a nonnegative integer and computes and prints its 
factorial.
b) Write a program that estimates the value of the mathematical constant e by 
using the formula:
  e = 1+(1/1!)+(1/2!)+(1/3!)+...
  Prompt the user for the desired accuracy of e (i.e., the number of terms in 
  the summation).
c) Write a program that computes the value of ex by using the formula
  e^x = 1+(x/1!)+(x^2/2!)+(x^3/3!)+...
  Prompt the user for the desired accuracy of e (i.e., the number of terms in 
  the summation).
  
******************************************************************************/

#include <iostream>

int getFactorial(int);

int main(int argc, char const *argv[])
{
    int number;
    std::cout << "A Program to determine the factorial of nonzero integers"
              << std::endl;
    std::cout << "Enter a nonzero integer: ";
    std::cin >> number;
    std::cout << number
              << "! = "
              << getFactorial(number)
              << std::endl;
    return 0;
}

int getFactorial(int n)
{
    int factorial{1}, counter{1};

    while (n > 0)
    {
        factorial *= n;
        n--;
    }

    return factorial;
}
