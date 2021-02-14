#ifndef PHONE_NUMBER_HPP
#define PHONE_NUMBER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>

class PhoneNumber
{
    friend std::ostream &operator<<(std::ostream &, PhoneNumber &);
    friend std::istream &operator>>(std::istream &, PhoneNumber &);

private:
    char phone[15];
    char areaCode[4];
    char exchange[4];
    char line[5];

public:
    PhoneNumber();
};

#endif