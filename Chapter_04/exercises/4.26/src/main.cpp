#include <iostream>

bool isPalindrome(int num);

int main(int argc, char const *argv[])
{
    int number{0};

    std::cout << "A program to determine if a 5 digit integer is a palindrome\n"
              << std::endl;

    std::cout << "Enter a 5 digit integer: ";
    std::cin >> number;

    if (isPalindrome(number))
    {
        std::cout << number
                  << " is a Palindrome Number"
                  << std::endl;
    }
    else
    {
        std::cout << number
                  << " is not a Palindrome Number"
                  << std::endl;
    }

    return 0;
}

bool isPalindrome(int num)
{
    int temp1, temp2, firstDigit, secondDigit, fourthDigit, fifthDigit;

    temp1 = num;
    firstDigit = temp1 / 10000;
    temp2 = temp1 % 10000;
    secondDigit = temp2 / 1000;
    temp1 = temp2 % 1000;
    temp2 = temp1 % 100;
    fourthDigit = temp2 / 10;
    temp1 = temp2 % 10;
    fifthDigit = temp1;

    if (firstDigit == fifthDigit && secondDigit == fourthDigit)
    {
        return true;
    }

    return false;
}