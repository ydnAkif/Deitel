#ifndef PHONE_NUMBER_HPP
#define PHONE_NUMBER_HPP

#include <iostream>
#include <string>

class PhoneNumber
{

    friend std::ostream &operator<<(std::ostream &, const PhoneNumber &);
    friend std::istream &operator>>(std::istream &, PhoneNumber &);

private:
    std::string areaCode;
    std::string exchange;
    std::string line;
};

#endif